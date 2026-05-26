package lslcomp

import (
	"bufio"
	"fmt"
	"regexp"
	"strings"
)

// CILMethodSize reports the computed byte sizes of a single CIL method body.
type CILMethodSize struct {
	// Name is the method name extracted from the .method declaration.
	// Single-quoted names have the quotes stripped (e.g. 'gadd' -> "gadd").
	Name string
	// CodeSize is the number of IL instruction bytes in the method body.
	// This matches the value reported by "monodis --show-tokens" as
	// "// Code size N".
	CodeSize int
	// BodySize is the number of bytes the method body occupies in the PE
	// image: fat header (12 bytes) + CodeSize, rounded up to a 4-byte
	// boundary.  This matches the gap between consecutive method RVAs
	// reported by monodis.
	BodySize int
	// RuntimeBytes is the estimated Mono heap cost of this method in a
	// running Second Life script, in the same units as llGetUsedMemory().
	//
	// Formula (all terms calibrated with autobench on 2026-05-25):
	//
	//   RuntimeBytes = 16                           // fixed PE metadata per method
	//                + len(Name)                    // method name in #Strings heap
	//                + BodySize                     // fat header + code, 4-aligned
	//                + N_params * 6                 // PE Param table row per param
	//                + (HasCalls ? 297 : 0)         // Linden migration base
	//                + (HasCalls ? sum(LocalMigCost[type_i]) : 0)
	//
	// HasCalls is true when the method body contains any call or callvirt.
	// Param name length does NOT add cost (only the count matters).
	// LocalMigCost is the per-variable migration state-save overhead; see
	// localMigrationCost table.  Note: .ctor is included but not meaningful
	// for optimizer use since it cannot be inlined or moved.
	RuntimeBytes int
}

// cilLocalType classifies an LSL-to-.NET local variable type for the runtime
// cost model.
type cilLocalType uint8

const (
	cilInteger  cilLocalType = iota // int32
	cilFloat                        // float32
	cilString                       // string
	cilKey                          // valuetype LindenLab.SecondLife.Key
	cilVector                       // class LindenLab.SecondLife.Vector
	cilRotation                     // class LindenLab.SecondLife.Quaternion
	cilList                         // class System.Collections.ArrayList
	cilUnknownType                  // unrecognised; uses conservative cost
)

// localMigrationCost[t] is the extra runtime bytes added per local variable of
// type t when the method makes any call.  It represents the Linden migration
// checkpoint infrastructure's cost to save and restore that variable.
// Measured with autobench 2026-05-25; uncertainties are +-4 bytes.
var localMigrationCost = [cilUnknownType + 1]int{
	cilInteger:     37,
	cilFloat:       40,
	cilString:      36,
	cilKey:         40,
	cilVector:      40,
	cilRotation:    40,
	cilList:        36,
	cilUnknownType: 40, // conservative fallback
}

const (
	// cilNameBase is the fixed per-method PE metadata overhead that does not
	// depend on the method name length.  Add len(Name) separately.
	// Calibrated: f(n) = cilNameBase + n + BodySize → f(5)=37, f(25)=57.
	cilNameBase      = 16
	cilMigrationBase = 297 // migration checkpoint base when any call is present
	cilParamCost     = 6   // PE Param table row cost per explicit parameter
)

// instrSizes maps a CIL instruction mnemonic (lower-case) to its total encoded
// byte count: opcode bytes + operand bytes.  "switch" is handled separately.
var instrSizes = map[string]int{

	// ---- 1-byte no-operand ----
	"nop": 1, "break": 1,
	"ldarg.0": 1, "ldarg.1": 1, "ldarg.2": 1, "ldarg.3": 1,
	"ldloc.0": 1, "ldloc.1": 1, "ldloc.2": 1, "ldloc.3": 1,
	"stloc.0": 1, "stloc.1": 1, "stloc.2": 1, "stloc.3": 1,
	"ldnull": 1,
	"ldc.i4.m1": 1,
	"ldc.i4.0": 1, "ldc.i4.1": 1, "ldc.i4.2": 1, "ldc.i4.3": 1,
	"ldc.i4.4": 1, "ldc.i4.5": 1, "ldc.i4.6": 1, "ldc.i4.7": 1, "ldc.i4.8": 1,
	"dup": 1, "pop": 1, "ret": 1,
	"add": 1, "sub": 1, "mul": 1, "div": 1, "div.un": 1, "rem": 1, "rem.un": 1,
	"and": 1, "or": 1, "xor": 1, "not": 1, "neg": 1,
	"shl": 1, "shr": 1, "shr.un": 1,
	"conv.i1": 1, "conv.i2": 1, "conv.i4": 1, "conv.i8": 1,
	"conv.r4": 1, "conv.r8": 1, "conv.r.un": 1,
	"conv.u1": 1, "conv.u2": 1, "conv.u4": 1, "conv.u8": 1,
	"conv.i": 1, "conv.u": 1,
	"conv.ovf.i1": 1, "conv.ovf.i2": 1, "conv.ovf.i4": 1, "conv.ovf.i8": 1,
	"conv.ovf.u1": 1, "conv.ovf.u2": 1, "conv.ovf.u4": 1, "conv.ovf.u8": 1,
	"conv.ovf.i1.un": 1, "conv.ovf.i2.un": 1, "conv.ovf.i4.un": 1, "conv.ovf.i8.un": 1,
	"conv.ovf.u1.un": 1, "conv.ovf.u2.un": 1, "conv.ovf.u4.un": 1, "conv.ovf.u8.un": 1,
	"conv.ovf.i.un": 1, "conv.ovf.u.un": 1, "conv.ovf.i": 1, "conv.ovf.u": 1,
	"add.ovf": 1, "add.ovf.un": 1, "sub.ovf": 1, "sub.ovf.un": 1,
	"mul.ovf": 1, "mul.ovf.un": 1,
	"endfinally": 1, "endfault": 1,
	"ldind.i1": 1, "ldind.u1": 1, "ldind.i2": 1, "ldind.u2": 1,
	"ldind.i4": 1, "ldind.u4": 1, "ldind.i8": 1, "ldind.i": 1,
	"ldind.r4": 1, "ldind.r8": 1, "ldind.ref": 1,
	"stind.ref": 1, "stind.i1": 1, "stind.i2": 1, "stind.i4": 1,
	"stind.i8": 1, "stind.r4": 1, "stind.r8": 1, "stind.i": 1,
	"ldelem.i1": 1, "ldelem.u1": 1, "ldelem.i2": 1, "ldelem.u2": 1,
	"ldelem.i4": 1, "ldelem.u4": 1, "ldelem.i8": 1, "ldelem.i": 1,
	"ldelem.r4": 1, "ldelem.r8": 1, "ldelem.ref": 1,
	"stelem.i": 1, "stelem.i1": 1, "stelem.i2": 1, "stelem.i4": 1,
	"stelem.i8": 1, "stelem.r4": 1, "stelem.r8": 1, "stelem.ref": 1,
	"ldlen": 1, "throw": 1, "ckfinite": 1,

	// ---- 2-byte no-operand (0xFE prefix) ----
	"arglist": 2, "ceq": 2, "cgt": 2, "cgt.un": 2, "clt": 2, "clt.un": 2,
	"localloc": 2, "endfilter": 2, "cpblk": 2, "initblk": 2,
	"rethrow": 2, "refanytype": 2,
	"volatile.": 2, "tail.": 2, "readonly.": 2,

	// ---- 1-byte opcode + 1-byte operand = 2 total ----
	"ldarg.s": 2, "ldarga.s": 2, "starg.s": 2,
	"ldloc.s": 2, "ldloca.s": 2, "stloc.s": 2,
	"ldc.i4.s": 2,

	// ---- 2-byte opcode + 1-byte operand = 3 total ----
	"unaligned.": 3, "no.": 3,

	// ---- 2-byte opcode + 2-byte operand = 4 total (wide arg/loc) ----
	"ldarg": 4, "ldarga": 4, "starg": 4,
	"ldloc": 4, "ldloca": 4, "stloc": 4,

	// ---- 1-byte opcode + 4-byte operand = 5 total ----
	"ldc.i4": 5, "ldc.r4": 5,
	"ldstr": 5, "call": 5, "callvirt": 5, "newobj": 5,
	"castclass": 5, "isinst": 5, "ldtoken": 5, "jmp": 5,
	"ldfld": 5, "ldflda": 5, "stfld": 5,
	"ldsfld": 5, "ldsflda": 5, "stsfld": 5,
	"unbox": 5, "unbox.any": 5, "box": 5, "newarr": 5,
	"ldobj": 5, "stobj": 5, "cpobj": 5,
	"refanyval": 5, "mkrefany": 5,
	// long-form branches (int32 target offset)
	"br": 5, "brfalse": 5, "brnull": 5, "brzero": 5,
	"brtrue": 5, "brinst": 5,
	"beq": 5, "bge": 5, "bgt": 5, "ble": 5, "blt": 5,
	"bne.un": 5, "bge.un": 5, "bgt.un": 5, "ble.un": 5, "blt.un": 5,
	"leave": 5,

	// ---- 1-byte opcode + 1-byte offset = 2 total (short branches) ----
	"br.s": 2,
	"brfalse.s": 2, "brnull.s": 2, "brzero.s": 2,
	"brtrue.s": 2, "brinst.s": 2,
	"beq.s": 2, "bge.s": 2, "bgt.s": 2, "ble.s": 2, "blt.s": 2,
	"bne.un.s": 2, "bge.un.s": 2, "bgt.un.s": 2, "ble.un.s": 2, "blt.un.s": 2,
	"leave.s": 2,

	// ---- 1-byte opcode + 8-byte operand = 9 total ----
	"ldc.i8": 9, "ldc.r8": 9,

	// ---- 2-byte opcode + 4-byte operand = 6 total ----
	"ldftn": 6, "ldvirtftn": 6, "initobj": 6,
	"constrained.": 6, "sizeof": 6,
}

// labelRE matches a pure label line: an identifier ending with ':'.
var labelRE = regexp.MustCompile(`^[A-Za-z_][A-Za-z0-9_.]*:$`)

// CILSizes parses a CIL assembly text (as returned by Compile) and returns the
// computed sizes for each method body.
//
// CodeSize and BodySize match monodis ground truth.  RuntimeBytes is the
// estimated Mono heap cost in llGetUsedMemory() units; see CILMethodSize for
// the formula and calibration notes.
func CILSizes(cil string) ([]CILMethodSize, error) {
	var results []CILMethodSize

	scanner := bufio.NewScanner(strings.NewReader(cil))

	inMethod := false
	depth := 0
	var methodName string
	codeSize := 0
	nParams := 0
	hasCalls := false
	var locals []cilLocalType

	for scanner.Scan() {
		raw := scanner.Text()
		line := strings.TrimSpace(raw)

		// Skip blank lines and comments everywhere.
		if line == "" || strings.HasPrefix(line, "//") {
			continue
		}

		// .method declaration: start collecting a new method.
		if strings.HasPrefix(line, ".method ") {
			methodName = cilMethodName(line)
			nParams = cilCountParams(line)
			inMethod = true
			depth = 0
			codeSize = 0
			hasCalls = false
			locals = nil
			// Handle rare case where { appears on the same line as .method.
			if strings.Contains(line, "{") {
				depth++
			}
			continue
		}

		if !inMethod {
			continue
		}

		if line == "{" {
			depth++
			continue
		}

		if line == "}" {
			depth--
			if depth == 0 {
				bodySize := (12 + codeSize + 3) &^ 3
				migration := 0
				if hasCalls {
					migration = cilMigrationBase
					for _, lt := range locals {
						migration += localMigrationCost[lt]
					}
				}
				results = append(results, CILMethodSize{
					Name:         methodName,
					CodeSize:     codeSize,
					BodySize:     bodySize,
					RuntimeBytes: cilNameBase + len(methodName) + bodySize + nParams*cilParamCost + migration,
				})
				inMethod = false
			}
			continue
		}

		// Only process instruction lines when inside a method body.
		if depth < 1 {
			continue
		}

		// Directives: parse .locals init; skip everything else.
		if strings.HasPrefix(line, ".") {
			if strings.HasPrefix(line, ".locals ") {
				locals = cilParseLocals(line)
			}
			continue
		}

		// Skip pure label lines (e.g. "LabelTempJump0:").
		if labelRE.MatchString(line) {
			continue
		}

		// Handle "Label: instruction" on a single line.
		if idx := strings.Index(line, ":"); idx > 0 {
			before := line[:idx]
			if !strings.ContainsAny(before, " \t()") {
				line = strings.TrimSpace(line[idx+1:])
				if line == "" {
					continue // label only
				}
			}
		}

		// Extract the mnemonic: first whitespace-delimited token, lower-cased.
		mnemonic := line
		if sp := strings.IndexAny(line, " \t"); sp >= 0 {
			mnemonic = line[:sp]
		}
		mnemonic = strings.ToLower(mnemonic)

		if mnemonic == "switch" {
			n := cilSwitchTargets(line)
			codeSize += 1 + 4 + n*4
			continue
		}

		// Any call or callvirt triggers the migration checkpoint overhead.
		if mnemonic == "call" || mnemonic == "callvirt" {
			hasCalls = true
		}

		sz, ok := instrSizes[mnemonic]
		if !ok {
			return nil, fmt.Errorf("CILSizes: unknown instruction %q in method %q",
				mnemonic, methodName)
		}
		codeSize += sz
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}
	return results, nil
}

// cilClassifyLocalType maps a .NET type token (from a .locals init directive,
// lower-cased and trimmed) to a cilLocalType.
func cilClassifyLocalType(tok string) cilLocalType {
	t := strings.ToLower(tok)
	switch {
	case strings.Contains(t, "arraylist"):
		return cilList
	case strings.Contains(t, "quaternion"):
		return cilRotation
	case strings.Contains(t, "vector"):
		return cilVector
	case strings.Contains(t, ".key"):
		return cilKey
	case strings.HasPrefix(t, "string"):
		return cilString
	case strings.Contains(t, "float32"):
		return cilFloat
	case strings.Contains(t, "int32"):
		return cilInteger
	default:
		return cilUnknownType
	}
}

// cilParseLocals extracts the ordered list of local variable types from a
// ".locals init (...)" directive line.
func cilParseLocals(line string) []cilLocalType {
	open := strings.Index(line, "(")
	if open < 0 {
		return nil
	}
	close := strings.LastIndex(line, ")")
	if close <= open {
		return nil
	}
	inner := strings.TrimSpace(line[open+1 : close])
	if inner == "" {
		return nil
	}
	parts := strings.Split(inner, ",")
	out := make([]cilLocalType, 0, len(parts))
	for _, p := range parts {
		out = append(out, cilClassifyLocalType(strings.TrimSpace(p)))
	}
	return out
}

// cilCountParams returns the number of explicit parameters in a .method line
// by counting comma-delimited items inside the (...) suffix.
func cilCountParams(methodLine string) int {
	open := strings.Index(methodLine, "(")
	if open < 0 {
		return 0
	}
	close := strings.LastIndex(methodLine, ")")
	if close <= open {
		return 0
	}
	inner := strings.TrimSpace(methodLine[open+1 : close])
	if inner == "" {
		return 0
	}
	return strings.Count(inner, ",") + 1
}

// cilMethodName extracts the method name from a .method declaration line.
// Single-quoted names like 'gadd' are returned without quotes.
func cilMethodName(line string) string {
	paren := strings.Index(line, "(")
	if paren < 0 {
		return line
	}
	before := strings.TrimRight(line[:paren], " \t")

	if strings.HasSuffix(before, "'") {
		closeQ := len(before) - 1
		openQ := strings.LastIndex(before[:closeQ], "'")
		if openQ >= 0 {
			return before[openQ+1 : closeQ]
		}
	}

	fields := strings.Fields(before)
	if len(fields) > 0 {
		return fields[len(fields)-1]
	}
	return ""
}

// cilSwitchTargets counts the number of branch targets in a "switch (...)"
// instruction line.
func cilSwitchTargets(line string) int {
	open := strings.Index(line, "(")
	if open < 0 {
		return 0
	}
	inner := line[open+1:]
	if close := strings.LastIndex(inner, ")"); close >= 0 {
		inner = inner[:close]
	}
	inner = strings.TrimSpace(inner)
	if inner == "" {
		return 0
	}
	return strings.Count(inner, ",") + 1
}
