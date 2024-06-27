/*******************************************************************
* Author: Sadia Nowrin
*
* Description: reads grid size and calls all the functions necessary for the quest program.
*******************************************************************/

#include "questv2.h"

int main() {
    int seedValue = 123;
    srand(seedValue);

    // reads rows and columns from keyboard
    int rows, columns;
    printf("\nEnter rows and Columns between 2 and 10 (inclusive)\n");
    scanf(" %d %d", &rows, &columns); 
    
    // generate the grid and display
    int grid[rows][columns];
    generateNDisplayGrid(rows, columns, grid);

    // find the maximum number in the grid
    int max;
    findMax(rows, columns, grid, &max);
    
    // Compute count of each number in the grid
    int* counts = computeStatsV2(rows, columns, grid, max); 

    printStats(counts, max);
    
    // Free dynamically allocated memory for count array
    freeStats(counts);
    return 0;
}
