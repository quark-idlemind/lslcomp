// Package parse provides LSL script syntax checking via the LSL compiler.
package parse

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
