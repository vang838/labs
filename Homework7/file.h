#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PATTERN_LENGTH 10
#define MAX_FILES 7
#define MAX_PATH_LENGTH 1024
#define DT_REG 8

void grepPlus(int argc, char *argv[]);