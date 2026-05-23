#ifndef _INDRA__L__HPP_
#define _INDRA__L__HPP_

#include "stdtypes.h"

// Parse src_string (null-terminated LSL source), run the error-checking
// passes (PRUNE, SCOPE_PASS1, SCOPE_PASS2, TYPE), and return all
// diagnostics as a single malloc'd string (one per line in the format
// "(line, col) : ERROR : message"), or NULL if the script is clean.
// The caller is responsible for calling free() on the returned value.
const char* lscript_compile(const char* src_string);

#endif
