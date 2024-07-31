/******************************************
 * Author: vang838@uwm.edu
 * 
 * Created: 6/11/24
 *****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "quest.h"

/***************************************************************
 * Function: readGrid
 * 
 * Description:
 * 
 * Takes 3 parameters from the user's input
 * 
 * Outer For Loop iterates through the rows
 * Inner For Loop iterates through the columns
 ***************************************************************/
void readGrid(int rows, int columns, int grid[rows][columns])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

/********************************************
 * Function: computeStats
 * 
 * Description:
 * Array count contains the amount of each obstacle in the grid
 ********************************************/
void computeStats(int rows, int columns, int grid[rows][columns], int count[SIZE])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            count[ grid[i][j] ]++;
        }
    }
}

/********************************************
 * Function: printStats
 * 
 * Description:
 * Prints the amount of obstacles contained in the count array
 *******************************************/
void printStats(int count[SIZE])
{
    printf("\nCount of Obstacles:\n");
    printf("Safe Zones: %d\n", count[0]);
    printf("Werewolves: %d\n", count[1]);
    printf("Treacherous Swamps: %d\n", count[2]);
    printf("Giant Spiders: %d\n", count[3]);
    printf("Venomous Snakes: %d\n", count[4]);
}

/**************************************************************
 * Function: findPath
 * 
 * Description:
 * Finds and prints the path from start to the goal in the grid
 * The term "die" is printed at the end if there is no valid path to the goal
 *************************************************************/
void findPath(int rows, int columns, int grid[rows][columns])
{
    int i = 0, j = 0;
    printf("\nPath:\n");
    printf("start ");

    while(i < rows - 1 || j < columns - 1)
    {
        if(j < columns - 1 && grid[i][j + 1] == 0)
        {
            j++;
            printf("right ");
        }

        else if(i < rows - 1 && grid[i+1][j] == 0)
        {
            i++;
            printf("down ");
        }

        else 
        {
            printf("died ");
            return;
        }
    }
}
