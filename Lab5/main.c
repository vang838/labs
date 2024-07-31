#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Improper Usage: %s -flag -filename", argv[0]);
        printf("\nFlags:\n");
        printf("1: w ( number of words )\n");
        printf("2: l ( number of lines )\n");
        printf("3: m ( number of characters )\n");
        return 1;
    }

    char *flag = argv[1];
    char *fileToOpen = argv[2];

    FILE *openedFile = fopen(fileToOpen, "r");

    if(openedFile == NULL)
    {
        printf("File %s does not exist\n", fileToOpen);
        return 1;
    }

    printf("File %s opened successfully\n", fileToOpen);

    if(strcmp(flag, "-l") == 0) 
    {
        int lines = countLines(openedFile);
        printf("\nNumber of lines: %d\n", lines);
    }

    else if(strcmp(flag, "-w") == 0) 
    {
        int words = countWords(openedFile);
        printf("\nNumber of words: %d\n", words);
    }

    else if(strcmp(flag, "-m") == 0) 
    {
        int characters = countCharacters(openedFile);
        printf("\nNumber of words: %d\n", characters);
    }

    else 
    {
        printf("\nInvalid Flag:\n");
        printf("1: -l ( number of lines )\n");
        printf("2: -w ( number of words )\n");
        printf("3: -m ( number of characters )\n");

        fclose(openedFile);
        return 1;
    }

    fclose(openedFile);
    return 0;

}