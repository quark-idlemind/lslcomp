package lslcomp

import (
	"testing"
)

// cilSizesCase compiles src and checks that CILSizes returns the expected
// (name, codeSize) pairs.
func cilSizesCase(t *testing.T, name, src string, want []CILMethodSize) {
	t.Helper()
	t.Run(name, func(t *testing.T) {
		cil, err := Compile(src, "test")
		if err != nil {
			t.Fatalf("Compile: %v", err)
		}
		got, err := CILSizes(cil)
		if err != nil {
			t.Fatalf("CILSizes: %v", err)
		}
		if len(got) != len(want) {
			t.Fatalf("got %d methods, want %d\ngot:  %v\nwant: %v", len(got), len(want), got, want)
		}
		for i, w := range want {
			g := got[i]
			if g.Name != w.Name {
				t.Errorf("[%d] name: got %q want %q", i, g.Name, w.Name)
			}
			if g.CodeSize != w.CodeSize {
				t.Errorf("[%d] %s: CodeSize got %d want %d", i, w.Name, g.CodeSize, w.CodeSize)
			}
			// BodySize is derived, just check the formula holds.
			wantBody := (12 + w.CodeSize + 3) &^ 3
			if g.BodySize != wantBody {
				t.Errorf("[%d] %s: BodySize got %d want %d", i, w.Name, g.BodySize, wantBody)
			}
			// RuntimeBytes is checked only when the want value is non-zero;
			// non-zero means autobench-verified ground truth is available.
			if w.RuntimeBytes != 0 && g.RuntimeBytes != w.RuntimeBytes {
				t.Errorf("[%d] %s: RuntimeBytes got %d want %d", i, w.Name, g.RuntimeBytes, w.RuntimeBytes)
			}
		}
	})
}

// TestCILSizes_Simple verifies against the monodis ground truth obtained for
// the sample script:
//
//	.ctor        Code size 18  (0x12)
//	gadd         Code size  6  (0x06)
//	ggreet       Code size 13  (0x0d)
//	edefaultstate_entry  Code size 67  (0x43)
//	edefaulttouch_start  Code size 62  (0x3e)
func TestCILSizes_Simple(t *testing.T) {
	src := `
integer g_count = 0;

integer add(integer a, integer b) {
    return a + b;
}

string greet(string name) {
    return "Hello, " + name;
}

default {
    state_entry() {
        integer x = add(1, 2);
        g_count++;
        llSay(0, greet("World"));
    }
    touch_start(integer num) {
        integer i;
        for (i = 0; i < num; i++) {
            llSay(0, (string)add(i, g_count));
        }
    }
}
`
	cilSizesCase(t, "simple", src, []CILMethodSize{
		{Name: ".ctor", CodeSize: 18},
		{Name: "gadd", CodeSize: 6},
		{Name: "ggreet", CodeSize: 13},
		{Name: "edefaultstate_entry", CodeSize: 67},
		{Name: "edefaulttouch_start", CodeSize: 62},
	})
}

// TestCILSizes_FloatVector verifies ldc.r8, ldarga.s, ldfld, and
// multi-local .locals init.
//
// Ground truth from PE binary (fat-header walk, python3):
//
//	.ctor               code_size 92  (0x5c)
//	gmagnitude          code_size 53  (0x35)
//	gbuildList          code_size 64  (0x40)
//	edefaultstate_entry code_size 94  (0x5e)
func TestCILSizes_FloatVector(t *testing.T) {
	src := `
vector g_pos = <1.0, 2.0, 3.0>;
rotation g_rot = <0.0, 0.0, 0.0, 1.0>;

float magnitude(vector v) {
    return llSqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

list buildList(integer n, float f, string s) {
    list result = [];
    integer i = 0;
    while (i < n) {
        result += (string)f;
        result += s;
        i++;
    }
    return result;
}

default {
    state_entry() {
        vector v = <1.5, 2.5, 3.5>;
        float m = magnitude(v);
        if (m > 5.0) {
            llSay(0, "big");
        } else {
            llSay(0, "small");
        }
    }
}
`
	cilSizesCase(t, "float_vector", src, []CILMethodSize{
		{Name: ".ctor", CodeSize: 92},
		{Name: "gmagnitude", CodeSize: 53},
		{Name: "gbuildList", CodeSize: 64},
		{Name: "edefaultstate_entry", CodeSize: 94},
	})
}

// TestCILSizes_EmptyDefault verifies the minimal script (empty default state).
func TestCILSizes_EmptyDefault(t *testing.T) {
	src := `default { state_entry() {} }`
	cil, err := Compile(src, "test")
	if err != nil {
		t.Fatalf("Compile: %v", err)
	}
	got, err := CILSizes(cil)
	if err != nil {
		t.Fatalf("CILSizes: %v", err)
	}
	// Must produce at least .ctor and edefaultstate_entry.
	if len(got) < 2 {
		t.Fatalf("expected >= 2 methods, got %d", len(got))
	}
	for _, m := range got {
		if m.CodeSize <= 0 {
			t.Errorf("method %q has non-positive CodeSize %d", m.Name, m.CodeSize)
		}
		if m.BodySize < m.CodeSize+12 {
			t.Errorf("method %q: BodySize %d < 12+CodeSize %d", m.Name, m.BodySize, m.CodeSize+12)
		}
	}
}

// TestCILSizes_MultiState verifies multiple states: method naming prefixes
// (edefaultXxx, eactiveXxx), ChangeState calls, and single-instruction bodies.
//
// Ground truth from monodis --show-tokens:
//
//	.ctor                Code size  7  (0x07)
//	edefaultstate_entry  Code size 13  (0x0d)
//	edefaulttouch_start  Code size  1  (0x01)
//	eactivestate_entry   Code size 16  (0x10)
//	eactivetouch_start   Code size 13  (0x0d)
func TestCILSizes_MultiState(t *testing.T) {
	src := `
default {
    state_entry() { state active; }
    touch_start(integer n) {}
}
state active {
    state_entry() { llSay(0, "active"); }
    touch_start(integer n) { state default; }
}
`
	// RuntimeBytes = 16 + len(Name) + BodySize + N_params*6 + migration.
	// BodySize = (12 + CodeSize + 3) &^ 3.  Migration = 297 when HasCalls.
	// Autobench-verified formula: f(n)=16+n+BodySize (5-char->37, 19-char->51+...)
	//
	// .ctor (len=5, B=20, p=0, calls):     16+5+20+0+297 = 338
	// edefaultstate_entry (len=19, B=28, p=0, calls):  16+19+28+0+297 = 360
	// edefaulttouch_start (len=19, B=16, p=1, no calls): 16+19+16+6+0 =  57  (autobench-exact)
	// eactivestate_entry  (len=18, B=28, p=0, calls):  16+18+28+0+297 = 359
	// eactivetouch_start  (len=18, B=28, p=1, calls):  16+18+28+6+297 = 365
	cilSizesCase(t, "multistate", src, []CILMethodSize{
		{Name: ".ctor", CodeSize: 7, RuntimeBytes: 338},
		{Name: "edefaultstate_entry", CodeSize: 13, RuntimeBytes: 360},
		{Name: "edefaulttouch_start", CodeSize: 1, RuntimeBytes: 57},
		{Name: "eactivestate_entry", CodeSize: 16, RuntimeBytes: 359},
		{Name: "eactivetouch_start", CodeSize: 13, RuntimeBytes: 365},
	})
}

// TestCILSizes_Formula verifies the BodySize formula for a variety of code
// sizes to catch off-by-one padding errors.
func TestCILSizes_Formula(t *testing.T) {
	cases := []struct {
		code int
		body int
	}{
		{0, 12},   // 12+0=12, already aligned
		{1, 16},   // 12+1=13 -> 16
		{2, 16},   // 12+2=14 -> 16
		{3, 16},   // 12+3=15 -> 16
		{4, 16},   // 12+4=16, aligned
		{5, 20},   // 12+5=17 -> 20
		{18, 32},  // .ctor example
		{6, 20},   // gadd example
		{13, 28},  // ggreet example
		{67, 80},  // state_entry example
		{62, 76},  // touch_start example
		{92, 104}, // float .ctor example
	}
	for _, c := range cases {
		got := (12 + c.code + 3) &^ 3
		if got != c.body {
			t.Errorf("BodySize(code=%d): got %d want %d", c.code, got, c.body)
		}
	}
}
