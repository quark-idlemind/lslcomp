/*
 * lsl_parse.cpp -- C-linkage shims so Go's cgo can call the C++ compiler
 * functions.  C++ functions are name-mangled; wrapping them with extern "C"
 * gives them predictable symbol names for cgo.
 *
 * URL_REQUEST_GRANTED / URL_REQUEST_DENIED are extern const char* values
 * referenced by lscript_library.cpp.  They must be defined exactly once
 * in the link; this file provides that definition for the cgo build.
 */

#include "lsl_parse.h"
#include "indra.l.hpp"

const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED  = "URL_REQUEST_DENIED";

extern "C" const char* lsl_parse(const char* src)
{
    return lscript_compile(src);
}

extern "C" const char* lsl_compile(const char* src,
                                   const char* class_name,
                                   char**      cil_out)
{
    return lscript_compile_cil(src, class_name, cil_out);
}
