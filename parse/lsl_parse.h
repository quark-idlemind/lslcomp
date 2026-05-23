/*
 * lsl_parse.h -- C-linkage wrapper around lscript_compile for use from Go.
 *
 * lsl_parse() parses the LSL source code in src.
 * Returns NULL if the script has no errors, or a malloc'd string
 * containing all diagnostic messages (one per line, in the format
 * "(line, col) : ERROR : message").
 * The caller is responsible for calling free() on a non-NULL result.
 */

#ifndef LSL_PARSE_H
#define LSL_PARSE_H

#ifdef __cplusplus
extern "C" {
#endif

const char* lsl_parse(const char* src);

#ifdef __cplusplus
}
#endif

#endif /* LSL_PARSE_H */
