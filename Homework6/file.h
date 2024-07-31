#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define PATH_MAX 4096

void findPermissions(mode_t mode, char *perms);
void printFileDetails(char *path, struct stat *fileStat, char *filename);
void listDirectory(char *dirPath, int displayAll, int deets);
void lsExtended(int argc, char *argv[]);
