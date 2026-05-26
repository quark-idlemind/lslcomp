#ifndef _INDRA__L__HPP_
#define _INDRA__L__HPP_

#include "stdtypes.h"

// lscript_compile -- syntax-check src_string.
// Returns NULL if the script is clean, or a malloc'd diagnostic string
// (one line per error/warning, format "(line, col) : ERROR : message").
// Caller must free the returned value.
const char* lscript_compile(const char* src_string);

// lscript_compile_cil -- compile src_string to CIL assembly.
// On success: sets *cil_out to a malloc'd NUL-terminated CIL string and
//   returns NULL.  Caller must free(*cil_out).
// On error: sets *cil_out to NULL and returns a malloc'd diagnostic string.
//   Caller must free the return value.
// class_name is used in .assembly and .class directives; if NULL or empty,
// "script" is used.
const char* lscript_compile_cil(const char* src_string,
                                const char* class_name,
                                char**      cil_out);

#endif
