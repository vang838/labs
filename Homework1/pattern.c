/************************************
 * Author: vang838@uwm.edu
 * Created: 5/30/24
 * Completed: 6/3/24
 * Displays a specific pattern of asterisk based on command line arguments based on the valid pattern types
 * Valid Pattern Types:
 *      1 = Triangle
 *      2 = Reverse Triangle
 *      3 = Pyramid
 * **********************************/

#include <stdio.h>
#include <stdlib.h>

/******************************************************
 * 
 * Prints the basic triangle pattern if user inputs 1 
 * Outer for loop iterates through each line given from user input
 * Inner loop prints i amount of stars on the i'th line
 * 
******************************************************/
void printTriangle(int lines)
{
    for(int i = 1; i <= lines; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

/****************************************************
 * 
 * Prints reverse triangle pattern if user inputs 2
 * Outer for loops iterates from total number of lines down to 1
 * Inner for loop prints i amount of stars on the i'th line
 * 
 ***************************************************/
void printReverseTriangle(int lines)
{
    for(int i = lines; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

/*******************************************
 * 
 * Prints pyramid pattern if user inputs 3
 * Outer for loop iterates through each line given by user input
 * First inner loop prints spaces to center the asterisks on the i'th line
 * Second inner for loop prints (2 * i - 1) amount of asterisks on the i'th line
 * 
*******************************************/
void printPyramid(int lines)
{
    for(int i = 1; i <= lines; i++)
    {
        for (int j = i; j <= lines; j++) // for loop for printing leading spaces
        {
            printf(" ");
        }

        for (int k = 1; k <= (2 * i - 1); k++) // for loop to print stars
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) 
{
    if(argc != 3) // Checker for correct number of arguments
    {
        printf("Invalid number of arguments: %s %s %s\n", argv[0], argv[1], argv[2]);
        printf("Correct Usage: ./pattern <valid pattern input> <number of lines>\n");
        return 1;
    }

    int userPatternInput = atoi(argv[1]);
    if(userPatternInput < 1 || userPatternInput > 3) // Check for valid pattern input
    {
        printf("%d is not a valid pattern input ( Valid inputs are 1 for triangle, 2 for reverse triangle, 3 for pyramid )\n", userPatternInput);
        return 1;
    }

    int numOfLines = atoi(argv[2]);
    if(numOfLines < 1 || numOfLines > 10) // Check for valid number of line input
    {
        printf("Integers less than 1 or greater than 10 are not allowed!\n");
    }  

    if(userPatternInput == 1) printTriangle(numOfLines); 

    if(userPatternInput == 2) printReverseTriangle(numOfLines);

    else printPyramid(numOfLines);
}