// Package lslcomp provides LSL script compilation via the LSL compiler.
package lslcomp

/*
#cgo CPPFLAGS: -I${SRCDIR} -I${SRCDIR}/llcommon -I${SRCDIR}/lscript -DLINUX=1

#include <stdlib.h>
#include "lsl_parse.h"
*/
import "C"
import (
	"errors"
	"unsafe"
)

// Parse parses the LSL script contained in input and returns nil if there
// were no errors, or an error whose message contains all the diagnostic
// lines produced by the compiler (one per line, each in the format
// "(line, col) : ERROR : message").
func Parse(input string) error {
	cs := C.CString(input)
	defer C.free(unsafe.Pointer(cs))

	errs := C.lsl_parse(cs)
	if errs == nil {
		return nil
	}
	defer C.free(unsafe.Pointer(errs))

	return errors.New(C.GoString(errs))
}

// Compile compiles the LSL script contained in input to CIL (Mono/CLR)
// assembly text.
//
// className is embedded in the .assembly and .class directives of the
// generated CIL.  If empty, "script" is used (producing class "LSL_script").
//
// On success Compile returns (cil, nil) where cil is the full CIL text.
// On error it returns ("", err) where err contains the diagnostic messages.
func Compile(input, className string) (string, error) {
	cs := C.CString(input)
	defer C.free(unsafe.Pointer(cs))

	var cn *C.char
	if className != "" {
		cn = C.CString(className)
		defer C.free(unsafe.Pointer(cn))
	}

	var cilOut *C.char
	errs := C.lsl_compile(cs, cn, &cilOut)

	if errs != nil {
		defer C.free(unsafe.Pointer(errs))
		return "", errors.New(C.GoString(errs))
	}
	if cilOut != nil {
		cil := C.GoString(cilOut)
		C.free(unsafe.Pointer(cilOut))
		return cil, nil
	}
	return "", nil
}
