/*
 * lsl_parse.cpp -- C-linkage shim so Go's cgo can call lscript_compile.
 *
 * lscript_compile is a C++ function (name-mangled).  Wrapping it with
 * extern "C" gives it C linkage and a predictable symbol name that cgo
 * can call directly from the lsl_parse.h declaration.
 *
 * URL_REQUEST_GRANTED / URL_REQUEST_DENIED are extern const char* values
 * referenced by lscript_library.cpp.  They must be defined exactly once
 * in the link; this file provides the definition for the cgo build.
 * (lslcomp.cpp provides its own definition for the lslcomp binary, and
 * tests/test_leak.cpp provides one for the leak-test binary.)
 */

#include "lsl_parse.h"
#include "indra.l.hpp"

const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED  = "URL_REQUEST_DENIED";

extern "C" const char* lsl_parse(const char* src)
{
    return lscript_compile(src);
}
