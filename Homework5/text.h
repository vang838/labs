#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define MAX_PATTERN_LENGTH 10

void grepLite(int argc, char *argv[]);
void grepLiteHelper(const char *pattern, const char *fileName, int caseInsensitive, int printLineNum, const char *outputFileInput);