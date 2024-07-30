#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>                           
#include <termios.h>       

#define readEND 0
#define writeEND 1

void pipe_commands(int argc, char *argv[]);

void error_exit(const char *message);