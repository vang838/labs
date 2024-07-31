#include "navigate.h"

void countDir(const char *basePath)
{
    int directoryCount = 0;
    struct dirent *entry;
    DIR *dir = opendir(basePath);

    if(dir == NULL)
    {
        perror(basePath);
        return;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if( strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 )
        {
            continue;
        }

        char path[1000];
        strcpy(path, basePath);
        strcat(path, "/");
        strcat(path, entry->d_name);

        DIR *subdir = opendir(path);
        if(subdir)
        {
            directoryCount++;
            closedir(subdir);
        }
    }
    closedir(dir);

    printf("Number of directories inside %s: %d\n", basePath, directoryCount);
}