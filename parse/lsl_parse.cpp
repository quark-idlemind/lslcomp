/*
 * lsl_parse.cpp -- C-linkage shim so Go's cgo can call lscript_compile.
 *
 * lscript_compile is a C++ function (name-mangled).  Wrapping it with
 * extern "C" gives it C linkage and a predictable symbol name that cgo
 * can call directly from the lsl_parse.h declaration.
 */

#include "lsl_parse.h"
#include "indra.l.hpp"  /* declares lscript_compile(const char*) */

extern "C" const char* lsl_parse(const char* src)
{
    return lscript_compile(src);
}
