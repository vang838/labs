/*******************************************************************
* Author: Sadia Nowrin
* Date: April 23, 2024

* Description: 
* This C program implements the following piped unix commands: 
* cat file | wc -l
* cat file | wc -w
* cat file | wc -c 
* cat file | sort

Usage:
* Compile it using a C compiler and run the executable from the command line with appropriate arguments.
*    - To search for a pattern in text files: ./main cat filename | wc -l/-c/-w or sort
*******************************************************************/

#include "file.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s cat filename '|' wc -l/-c/-w or sort \n", argv[0]);
        return 1;

    }
    pipe_commands(argc, argv);

    return 0;
}
