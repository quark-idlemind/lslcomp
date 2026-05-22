#include <stdio.h>
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

    // lscript_compile returns TRUE (1) on success, FALSE (0) on any error.
    // Invert so that exit 0 = clean, exit 1 = errors found.
    return !lscript_compile(src_filename);
}
