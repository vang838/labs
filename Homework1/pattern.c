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
 * Triangle Function
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
 * Reverse Function
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
 * Pyramid Function
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

/*******************************************************************
 * main 
 * User is asked for 3 pattern types (patternType) labeled 0 to 3
 * 0 = Quit, 1 = Triangle, 2 = Reverse Triangle, 3 = Pyramid
 * 
 * User is then asked for how many lines (numOfLines) to print
 * numOfLines must be a positive integer
********************************************************************/
int main() 
{
    int patternType;

    while(1) // Used to repeat the prompt if the pattern input is invalid
    {
        printf("\nValid Pattern Inputs: \n");
        printf("    0: Quit\n");
        printf("    1: Triangle \n");
        printf("    2: Reverse Triangle \n");
        printf("    3: Pyramid \n");
        printf("Input: ");
        scanf("%d", &patternType);

        if(patternType < 0 || patternType > 3) 
        {
            printf("\n\n\n\nInvalid Pattern Input!\n");
            continue;
        }

        if(patternType == 0)
        {
            printf("You have chosen to quit\n");
            break;
        }

        while(1) // while loop to repeatedly print lines based on user input unless user inputs 0 which exits the inner loop and repeats the outer loop
        {
            int numOfLines;
            printf("\nEnter the number of lines to print (0 to change pattern): ");
            scanf("%d", &numOfLines);

            if(numOfLines < 0)
            {
                printf("Invalid Input: Only positive integers are accepted\n");
                continue;
            }

            if(numOfLines == 0)
            {
                break;
            }

            // Triangle Pattern
            if (patternType == 1) 
            {
                printTriangle(numOfLines);
            } 

            //Reverse Triangle Pattern
            if (patternType == 2) 
            {
                printReverseTriangle(numOfLines);
            } 

            // Pyramid Pattern
            if (patternType == 3) 
            {
                printPyramid(numOfLines);
            }
        }
    }

    return 0;
}