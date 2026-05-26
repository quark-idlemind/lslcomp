package lslcomp_test

import (
	"strings"
	"testing"

	lslcomp "github.com/quark-idlemind/lslcomp"
)

// cleanScript is a syntactically and semantically correct LSL program.
const cleanScript = `integer add(integer a, integer b)
{
    return a + b;
}

default
{
    state_entry()
    {
        integer r = add(3, 4);
    }
}
`

// typeErrScript has a semantic error: string literal assigned to integer.
const typeErrScript = `default
{
    state_entry()
    {
        integer x = "wrong type";
    }
}
`

// syntaxErrScript has a syntax error: missing semicolon.
const syntaxErrScript = `default
{
    state_entry()
    {
        integer x = 5
    }
}
`

// --- Parse tests (unchanged from lslcomp2) ---

func TestParseCleanScript(t *testing.T) {
	if err := lslcomp.Parse(cleanScript); err != nil {
		t.Errorf("expected no error for clean script, got: %v", err)
	}
}

func TestParseTypeError(t *testing.T) {
	err := lslcomp.Parse(typeErrScript)
	if err == nil {
		t.Fatal("expected error for type-mismatch script, got nil")
	}
	const want = "Type mismatch"
	if !strings.Contains(err.Error(), want) {
		t.Errorf("expected %q in error message, got: %v", want, err)
	}
}

func TestParseSyntaxError(t *testing.T) {
	err := lslcomp.Parse(syntaxErrScript)
	if err == nil {
		t.Fatal("expected error for syntax-error script, got nil")
	}
	const want = "Syntax error"
	if !strings.Contains(err.Error(), want) {
		t.Errorf("expected %q in error message, got: %v", want, err)
	}
}

// --- Compile tests ---

// TestCompileClean verifies that a clean script produces non-empty CIL
// beginning with the expected .assembly extern header lines.
func TestCompileClean(t *testing.T) {
	cil, err := lslcomp.Compile(cleanScript, "")
	if err != nil {
		t.Fatalf("Compile returned error for clean script: %v", err)
	}
	if cil == "" {
		t.Fatal("Compile returned empty CIL for clean script")
	}
	const want = ".assembly extern mscorlib"
	if !strings.Contains(cil, want) {
		t.Errorf("expected CIL to contain %q; got:\n%s", want, cil)
	}
}

// TestCompileError verifies that a script with a type error returns an
// error and no CIL.
func TestCompileError(t *testing.T) {
	cil, err := lslcomp.Compile(typeErrScript, "")
	if err == nil {
		t.Fatal("expected error for type-mismatch script, got nil")
	}
	const want = "Type mismatch"
	if !strings.Contains(err.Error(), want) {
		t.Errorf("expected %q in error message, got: %v", want, err)
	}
	if cil != "" {
		t.Errorf("expected empty CIL on error, got: %s", cil)
	}
}

// TestCompileClassName verifies that a supplied className appears in both
// the .assembly and .class directives of the generated CIL.
func TestCompileClassName(t *testing.T) {
	const name = "MyTestScript"
	cil, err := lslcomp.Compile(cleanScript, name)
	if err != nil {
		t.Fatalf("Compile returned error: %v", err)
	}
	// to_class_name prefixes with "LSL-" then mangles; our name is alnum so
	// the result is "LSL-MyTestScript" with '-' converted to '_': "LSL_MyTestScript"
	const want = "LSL_MyTestScript"
	if !strings.Contains(cil, want) {
		t.Errorf("expected class name %q in CIL; got:\n%s", want, cil)
	}
}

// TestCompileDefaultClassName verifies that an empty className produces the
// default class name "LSL_script" in the CIL output.
func TestCompileDefaultClassName(t *testing.T) {
	cil, err := lslcomp.Compile(cleanScript, "")
	if err != nil {
		t.Fatalf("Compile returned error: %v", err)
	}
	const want = "LSL_script"
	if !strings.Contains(cil, want) {
		t.Errorf("expected default class name %q in CIL; got:\n%s", want, cil)
	}
}

// TestCompileSyntaxError verifies that a syntax error returns a proper
// error message and no CIL.
func TestCompileSyntaxError(t *testing.T) {
	cil, err := lslcomp.Compile(syntaxErrScript, "")
	if err == nil {
		t.Fatal("expected error for syntax-error script, got nil")
	}
	const want = "Syntax error"
	if !strings.Contains(err.Error(), want) {
		t.Errorf("expected %q in error message, got: %v", want, err)
	}
	if cil != "" {
		t.Errorf("expected empty CIL on error, got: %s", cil)
	}
}
