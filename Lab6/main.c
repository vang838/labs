#include "navigate.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Improper Usage!\n");
        printf("Correct Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    countDir(argv[1]);

    return 0;
}