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
}

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
// CILMethodSize.CodeSize matches the "// Code size N" values reported by
// "monodis --show-tokens".  CILMethodSize.BodySize is the number of bytes the
// method occupies in the assembled PE image.
func CILSizes(cil string) ([]CILMethodSize, error) {
	var results []CILMethodSize

	scanner := bufio.NewScanner(strings.NewReader(cil))

	inMethod := false
	depth := 0
	var methodName string
	codeSize := 0

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
			inMethod = true
			depth = 0
			codeSize = 0
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
				// End of method body.
				bodySize := (12 + codeSize + 3) &^ 3
				results = append(results, CILMethodSize{
					Name:     methodName,
					CodeSize: codeSize,
					BodySize: bodySize,
				})
				inMethod = false
			}
			continue
		}

		// Only process instruction lines when inside a method body.
		if depth < 1 {
			continue
		}

		// Skip directives (.maxstack, .locals, .line, .custom, etc.).
		if strings.HasPrefix(line, ".") {
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
			// switch opcode: 1 byte + 4-byte count + n*4-byte offsets
			codeSize += 1 + 4 + n*4
			continue
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

// cilMethodName extracts the method name from a .method declaration line.
// Single-quoted names like 'gadd' are returned without quotes.
func cilMethodName(line string) string {
	// Find the first '(' -- the method name immediately precedes it.
	paren := strings.Index(line, "(")
	if paren < 0 {
		return line
	}
	before := strings.TrimRight(line[:paren], " \t")

	// Quoted name ends with '  (e.g. 'gadd' or '.ctor')
	if strings.HasSuffix(before, "'") {
		closeQ := len(before) - 1
		openQ := strings.LastIndex(before[:closeQ], "'")
		if openQ >= 0 {
			return before[openQ+1 : closeQ]
		}
	}

	// Plain identifier: last whitespace-separated token.
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
