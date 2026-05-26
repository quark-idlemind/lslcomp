# LSL Syntax Checker Tasks

## Testing requirement
After every code change, run the test suite and confirm all tests pass
before marking a task DONE:

    python3 tests/run_tests.py

All 12 tests must report PASS.  A task is not DONE until the suite is green.

---

## Task 1 - Identify error reporting sites
DONE - Map all locations in the source where compilation errors are produced,
and record what changes are needed to strip down the compiler to a
syntax-checker-only tool.

## Task 2 - Strip code-generation passes from lscript_compile()
DONE - Removed the if (!gErrorToText.getErrors()) block in indra.l.in that
ran LSCP_RESOURCE, LSCP_EMIT_ASSEMBLY, LSCP_EMIT_CIL_ASSEMBLY, and
LSCP_EMIT_BYTE_CODE.  The five error-checking passes (parse, PRUNE,
SCOPE_PASS1, SCOPE_PASS2, TYPE) remain.  All 12 tests pass.

## Task 3 - Remove output-file generation from lslcomp.cpp
DONE - Simplified lscript_compile() to a single parameter (src_filename);
removed err_filename/dst_filename/compile_to_mono/class_name/is_god_like;
replaced yyout file-open with yyout=stderr; removed fclose(yyout);
removed init_temp_jumps(); dropped -DEMERGENCY_DEBUG_PRINTOUTS from Makefile.
lslcomp.cpp no longer computes .out or .cil paths.  No output files are
written.  All 12 tests pass.

## Task 4 - Exit-code and stderr behaviour
DONE - lslcomp now returns !lscript_compile() so exit 0 = clean, exit 1 =
errors found.  Added stderr message when source file cannot be opened.
Removed LSWARN_DEAD_CODE emission from lscript_tree.cpp (dead code is
silently accepted; it does not prevent compilation).  Removed
warn_dead_code.lsl test; 12 tests remain, all pass.  Test harness now
also verifies exit codes (errors -> non-zero, clean -> zero).

## Task 5 - Build and smoke-test
DONE - Built the compiler; all 12 regression tests pass.  lslcomp exits 0
for clean scripts and 1 for scripts with errors.  macOS leak test (100
iterations x 3 scripts = 300 compilations) reports 0 leaks.

## Task 6 - Write test scripts and harness
DONE - Created tests/ directory with one .lsl script per error code and a
Python harness (tests/run_tests.py) that reads the // EXPECT directive
from line 1 of each script, runs the compiler, and verifies the expected
diagnostic appears in stderr.  12 tests pass.

## Task 7 - Remove lscript_resource and clean up dead code
DONE - Deleted lscript_resource.cpp/.h (only provided gTempJumpCount used
in removed EMIT_ASSEMBLY cases).  Removed 3345 lines of dead case blocks
from lscript_tree.cpp (LSCP_PRETTY_PRINT, LSCP_EMIT_ASSEMBLY,
LSCP_EMIT_BYTE_CODE, LSCP_EMIT_CIL_ASSEMBLY, LSCP_RESOURCE,
LSCP_TO_STACK, LSCP_LIST_BUILD_SIMPLE, LSCP_DETERMINE_HANDLERS).
Removed 36 dead helper functions (all print_cil_*, print_return,
print_exit_pops, get_type, is_parameter, to_class_name, setClassName,
setBytecodeDest, etc.).  lscript_tree.cpp reduced from 9170 to 4820 lines.
NOTE: Tasks 12-13 below restore the CIL pass to add Compile() support.

## Task 8 - Collect diagnostics; change lscript_compile return type
DONE - LLScriptGenerateErrorText now collects diagnostics into a
std::vector<LLScriptDiagnostic> instead of printing immediately.
printDiagnostics(FILE*) emits them; new formatDiagnostics() returns a
malloc'd string (NULL if clean).  lscript_compile() changed from BOOL to
const char* -- returns NULL if clean, or a malloc'd error string the
caller must free().  lslcomp.cpp fputs the string to stderr and frees it.

## Task 9 - Reentrant lexer; compile from string
DONE - Added %option reentrant to flex; lscript_compile() now takes the
source as a const char* string (not a filename), uses yylex_init/
yy_scan_string/yyparse/yylex_destroy.  %lex-param/%parse-param thread the
scanner through bison.  lslcomp.cpp reads the file into memory and passes
the contents.  Helper functions (_count, _line_comment, etc.) take an
explicit yyscan_t.  All 12 tests pass.

## Task 10 - Memory leak audit and fixes
DONE - Stress test (tests/test_leak.cpp, tests/run_leak_test.py) calls
lscript_compile() 300 times (100 x 3 scripts).  Two leaks found and fixed:
(1) ~LLScriptState() was empty -- added delete mStateScope.
(2) Token strings (IDENTIFIER, STATE_DEFAULT, STRING_CONSTANT) leaked on
parse failure -- added %destructor { delete[] $$; } to indra.y.
leaks --atExit now reports "0 leaks for 0 total leaked bytes".

## Task 11 - Go parse package
DONE - Created parse/ Go package (module github.com/quark-idlemind/
LSL-compiler/parse) with CGo binding.  parse/lsl_parse.h declares C-linkage
lsl_parse(); parse/lsl_parse.cpp is a thin shim over lscript_compile().
parse/parse.go exposes Parse(string) error -- returns nil if clean, or an
error with all diagnostic lines.  Makefile builds libLSLCompiler.a (ar
from COMPILER_OBJS) which the Go package links against.  Three Go tests
(clean, type-error, syntax-error) all pass.

## Task 12 - Restore CIL code generation pass
DONE - Restored lscript_resource.cpp/.h (needed for gTempJumpCount and
init_temp_jumps() used by the CIL pass).  Restored full lscript_tree.cpp
(9178 lines) containing all LSCP_EMIT_CIL_ASSEMBLY case blocks and CIL
helper functions (print_cil_box, print_cil_type, print_cil_member, etc.).
Modified LLScriptScript::recurse LSCP_EMIT_CIL_ASSEMBLY case to use the
passed fp argument instead of opening mBytecodeDest, so the caller
controls where output goes.  All 12 existing tests pass.

## Task 13 - Add Compile() returning CIL assembly as a string
DONE - Added lscript_compile_cil() to indra.l.cpp: runs PRUNE,
SCOPE_PASS1, SCOPE_PASS2, TYPE, RESOURCE, EMIT_CIL_ASSEMBLY passes;
captures CIL output via open_memstream(); suppresses RESOURCE debug spew
to /dev/null.  Added lsl_compile() C-linkage shim to lsl_parse.cpp.
Updated lsl_parse.h with lsl_compile() declaration.  Added
Compile(input, className string) (string, error) to lslcomp.go.
className defaults to "script" (producing class "LSL_script") when empty.
Added 5 new Go tests: clean compile, error propagation, custom class name,
default class name, syntax error.  All 8 Go tests pass.
