package lslcomp_test

import (
	"strings"
	"testing"

	lslcomp "github.com/quark-idlemind/LSL-compiler"
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
