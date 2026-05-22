# LSL Compiler Error Tests

This directory contains regression tests that verify each user-visible
compilation error is still detected by the compiler.

## Running

From the project root (after building `lslcomp`):

```
python3 tests/run_tests.py
```

Or pass the compiler path explicitly:

```
python3 tests/run_tests.py /path/to/lslcomp
```

## EXPECT directive

Every `.lsl` file here **must** carry one of these directives on its
**first line**:

```
// EXPECT ERROR: <message text>
// EXPECT WARNING: <message text>
// EXPECT CLEAN
```

The harness (`run_tests.py`) reads the directive, runs the compiler, and
checks stderr for a line containing `ERROR : <message text>` or
`WARNING : <message text>`.  For `EXPECT CLEAN` it verifies that stderr
contains no diagnostics at all.

## Test files

| File | Expected diagnostic | Error code | Source location |
|---|---|---|---|
| `error_syntax.lsl` | `Syntax error` | `LSERROR_SYNTAX_ERROR` | `indra.l.in:234` `yyerror()` |
| `error_no_return.lsl` | `Not all code paths return a value` | `LSERROR_NO_RETURN` | `lscript_tree.cpp:8595` |
| `error_invalid_void_return.lsl` | `Function returns a value but return statement doesn't` | `LSERROR_INVALID_VOID_RETURN` | `lscript_tree.cpp:7380` |
| `error_invalid_return.lsl` | `Return statement type doesn't match function return type` | `LSERROR_INVALID_RETURN` | `lscript_tree.cpp:7373` |
| `error_state_change_in_global.lsl` | `Global functions can't change state` | `LSERROR_STATE_CHANGE_IN_GLOBAL` | `lscript_tree.cpp:7182` |
| `error_duplicate_name.lsl` | `Name previously declared within scope` | `LSERROR_DUPLICATE_NAME` | `lscript_tree.cpp:7928` |
| `error_undefined_name.lsl` | `Name not defined within scope` | `LSERROR_UNDEFINED_NAME` | `lscript_tree.cpp:412` area |
| `error_type_mismatch.lsl` | `Type mismatch` | `LSERROR_TYPE_MISMATCH` | `lscript_tree.cpp:7948` |
| `error_function_type_error.lsl` | `Function call mismatches type or number of arguments` | `LSERROR_FUNCTION_TYPE_ERROR` | `lscript_tree.cpp:6859` |
| `error_vector_method.lsl` | `Use of vector or quaternion method on incorrect type` | `LSERROR_VECTOR_METHOD_ERROR` | `lscript_tree.cpp:4148` |
| `error_need_new_scope.lsl` | `Declaration requires a new scope -- use { and }` | `LSERROR_NEED_NEW_SCOPE` | `lscript_tree.cpp:7923` |
| `clean.lsl` | *(no diagnostics)* | — | — |

## Codes intentionally not reported

| Code | Reason |
|---|---|
| `LSWARN_DEAD_CODE` | Dead code beyond a return is silently accepted — it does not prevent compilation. The warning emission was removed from `lscript_tree.cpp`. |
| `LSERROR_EXPRESSION_ON_LVALUE` | Grammar enforces lvalue where `++`/`--`/`=` appear; the semantic check in `LSCP_TYPE` is unreachable with the current grammar. |
| `LSERROR_NO_LISTS_IN_LISTS` | Defined in enum but never referenced in any source file. |
| `LSERROR_NO_UNITIALIZED_VARIABLES_IN_LISTS` | Defined in enum but never referenced in any source file. |
| `LSERROR_ASSEMBLE_OUT_OF_MEMORY` | Only reachable during bytecode assembly (code generation), which the syntax checker does not run. |
