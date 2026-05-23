#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indra.l.hpp"

// http_request string constants
const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED = "URL_REQUEST_DENIED";
#define MAX_STRING 255

int main(int argc, char *argv[])
{
    char src_filename[MAX_STRING];
    int len;
    char *dot;
    if (argc < 2)
    {
        fputs("Usage: lslcomp <filename>\n", stderr);
        return 1;
    }
    len = strlen(argv[1]);
    // leave room for ".lsl\0" (length 5)
    if (len > MAX_STRING - 5)
    {
        fputs("Input filename too long.\n", stderr);
        return 1;
    }
    dot = strrchr(argv[1], '.');
    if (dot != NULL)
        strncpy(src_filename, argv[1], MAX_STRING - 1);
    else
        snprintf(src_filename, MAX_STRING, "%s.lsl", argv[1]);
    src_filename[MAX_STRING - 1] = '\0';

    // Read the entire source file into memory, then pass the string to
    // the compiler so the lexer can run from a buffer rather than a file.
    FILE *f = fopen(src_filename, "r");
    if (!f)
    {
        fprintf(stderr, "ERROR: cannot open '%s'\n", src_filename);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *content = (char *)malloc(file_size + 1);
    if (!content)
    {
        fclose(f);
        fputs("Out of memory.\n", stderr);
        return 1;
    }
    fread(content, 1, file_size, f);
    content[file_size] = '\0';
    fclose(f);

    // lscript_compile returns TRUE (1) on success, FALSE (0) on any error.
    // Invert so that exit 0 = clean, exit 1 = errors found.
    int result = !lscript_compile(content);
    free(content);
    return result;
}
