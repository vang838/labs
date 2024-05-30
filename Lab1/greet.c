/********************************
* Author: vang838@uwm.edu
* Created: 5/29/24 
* This program displays the 3 inputs given by the user: 2 Strings and converts the last string into an integer
********************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if(argc != 4) 
    {
        printf("Usage: %s <name>, <name>, <positive integer>\n", argv[0]);
        return 1;
    }

    int convertStringToInt = atoi(argv[3]); // Convert third argument from string to integer

    printf("Hello %s and %s, I am %d years old today!\n", argv[1], argv[2], convertStringToInt);
    return 0;
}