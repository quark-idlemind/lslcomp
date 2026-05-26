/*
 * lsl_parse.h -- C-linkage wrappers around lscript_compile and
 * lscript_compile_cil for use from Go via cgo.
 */

#ifndef LSL_PARSE_H
#define LSL_PARSE_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * lsl_parse -- syntax-check src.
 * Returns NULL if the script is clean, or a malloc'd diagnostic string
 * (one line per error/warning, format "(line, col) : ERROR : message").
 * Caller must free() a non-NULL result.
 */
const char* lsl_parse(const char* src);

/*
 * lsl_compile -- compile src to CIL (Mono/CLR) assembly text.
 *
 * On success: sets *cil_out to a malloc'd NUL-terminated CIL string and
 *   returns NULL.  Caller must free(*cil_out).
 * On error: sets *cil_out to NULL and returns a malloc'd diagnostic string.
 *   Caller must free the return value.
 *
 * class_name is embedded in the .assembly and .class directives.
 * If NULL or empty, "script" is used (producing class name "LSL_script").
 */
const char* lsl_compile(const char* src,
                        const char* class_name,
                        char**      cil_out);

#ifdef __cplusplus
}
#endif

#endif /* LSL_PARSE_H */
