#ifndef _INDRA__L__HPP_
#define _INDRA__L__HPP_

#include "stdtypes.h"

// Parse src_filename, run the error-checking passes (PRUNE, SCOPE_PASS1,
// SCOPE_PASS2, TYPE), write any diagnostics to stderr, and return TRUE if
// the script is clean (no errors).
BOOL lscript_compile(const char* src_filename);

#endif
