/**
 * @file test_leak.cpp
 * @brief Memory-leak stress test for lscript_compile().
 *
 * Calls lscript_compile() 100 times with three different scripts
 * (clean, type-error, syntax-error) and asserts the expected result
 * each time.  The repetition lets a memory checker accumulate signal
 * across iterations.
 *
 * Test output (PASS/FAIL lines) goes to stdout.
 * Compiler diagnostics (the normal error messages) go to stderr; the
 * run_leak_test.py runner redirects those to /dev/null.
 *
 * Usage:
 *     make LSLK=... test_leak
 *     ./test_leak                       # correctness only
 *     leaks --atExit -- ./test_leak     # macOS leak check
 *     valgrind --leak-check=full ./test_leak   # Linux leak check
 */

#include <stdio.h>
#include "indra.l.hpp"

// URL constants referenced by lscript_library but normally defined in
// lslcomp.cpp.  Re-declare here for the standalone test binary.
const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED  = "URL_REQUEST_DENIED";

// --- Test scripts --------------------------------------------------------

// Clean: syntactically and semantically correct -- must return TRUE.
static const char CLEAN[] =
    "integer add(integer a, integer b)\n"
    "{\n"
    "    return a + b;\n"
    "}\n"
    "default\n"
    "{\n"
    "    state_entry()\n"
    "    {\n"
    "        integer r = add(3, 4);\n"
    "    }\n"
    "}\n";

// Semantic error (type mismatch: string literal to integer) -- must return FALSE.
static const char TYPE_ERR[] =
    "default\n"
    "{\n"
    "    state_entry()\n"
    "    {\n"
    "        integer x = \"wrong type\";\n"
    "    }\n"
    "}\n";

// Syntax error (missing semicolon) -- must return FALSE.
static const char SYNTAX_ERR[] =
    "default\n"
    "{\n"
    "    state_entry()\n"
    "    {\n"
    "        integer x = 5\n"
    "    }\n"
    "}\n";

// -------------------------------------------------------------------------

int main()
{
    const int N = 100;
    int failures = 0;

    for (int i = 0; i < N; ++i)
    {
        BOOL ok;

        ok = lscript_compile(CLEAN);
        if (!ok)
        {
            printf("FAIL [iter %d]: clean script failed unexpectedly\n", i);
            ++failures;
        }

        ok = lscript_compile(TYPE_ERR);
        if (ok)
        {
            printf("FAIL [iter %d]: type-error script succeeded unexpectedly\n", i);
            ++failures;
        }

        ok = lscript_compile(SYNTAX_ERR);
        if (ok)
        {
            printf("FAIL [iter %d]: syntax-error script succeeded unexpectedly\n", i);
            ++failures;
        }
    }

    if (failures == 0)
        printf("PASS: %d iterations x 3 scripts = %d compilations, "
               "all returned expected result\n", N, N * 3);
    else
        printf("FAIL: %d unexpected results across %d compilations\n",
               failures, N * 3);

    return failures > 0 ? 1 : 0;
}
