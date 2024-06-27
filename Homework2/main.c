/*******************************************************************
* Author: Sadia Nowrin
*
* Description: reads grid size and calls all the functions necessary for the quest program.
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "quest.h"

int main() {
    int rows, columns;
    int count[SIZE] = {0};

    //read rows and columns from keyboard
    printf("Enter rows and Columns between 2 and 10 (inclusive)\n");
    scanf("%d %d", &rows, &columns); //See the spacing here. 
    
    printf("\nEnter the grid:\n");
    int grid[rows][columns];

    // Read the terrain grid
    readGrid(rows, columns, grid);

    //Compute stats of the obstacles
    computeStats(rows, columns, grid, count);

    //print stats of the obstacles
    printStats(count);
    
    //find and print the path from start to goal
    findPath(rows, columns, grid);

    return 0;
}