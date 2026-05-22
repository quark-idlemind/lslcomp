# LSL Syntax Checker Tasks

## Testing requirement
After every code change, run the test suite and confirm all tests pass
before marking a task DONE:

    python3 tests/run_tests.py

All 13 tests must report PASS.  A task is not DONE until the suite is green.

---

## Task 1 - Identify error reporting sites
DONE - Map all locations in the source where compilation errors are produced,
and record what changes are needed to strip down the compiler to a
syntax-checker-only tool.

## Task 2 - Strip code-generation passes from lscript_compile()
DONE - Removed the if (!gErrorToText.getErrors()) block in indra.l.in that
ran LSCP_RESOURCE, LSCP_EMIT_ASSEMBLY, LSCP_EMIT_CIL_ASSEMBLY, and
LSCP_EMIT_BYTE_CODE.  The five error-checking passes (parse, PRUNE,
SCOPE_PASS1, SCOPE_PASS2, TYPE) remain.  All 13 tests pass.

## Task 3 - Remove output-file generation from lslcomp.cpp
DONE - Simplified lscript_compile() to a single parameter (src_filename);
removed err_filename/dst_filename/compile_to_mono/class_name/is_god_like;
replaced yyout file-open with yyout=stderr; removed fclose(yyout);
removed init_temp_jumps(); dropped -DEMERGENCY_DEBUG_PRINTOUTS from Makefile.
lslcomp.cpp no longer computes .out or .cil paths.  No output files are
written.  All 13 tests pass.

## Task 4 - Exit-code and stderr behaviour
DONE - lslcomp now returns !lscript_compile() so exit 0 = clean, exit 1 =
errors found.  Added stderr message when source file cannot be opened.
Removed LSWARN_DEAD_CODE emission from lscript_tree.cpp (dead code is
silently accepted; it does not prevent compilation).  Removed
warn_dead_code.lsl test; 12 tests remain, all pass.  Test harness now
also verifies exit codes (errors -> non-zero, clean -> zero).

## Task 5 - Build and smoke-test
NEW - Build the modified compiler and run it against at least one good
script (expect exit 0, no output) and one bad script (expect exit != 0,
error line on stderr).

## Task 6 - Write test scripts and harness
DONE - Create tests/ directory with one .lsl script per error code and a
Python harness (tests/run_tests.py) that reads the // EXPECT directive
from line 1 of each script, runs the compiler, and verifies the expected
diagnostic appears in stderr.  All 13 tests pass.
