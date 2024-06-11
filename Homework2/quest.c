#include <stdio.h>
#include <stdlib.h>
#include "quest.h"

void readGrid(int rows, int columns, int grid[rows][columns])
{
    if(rows < 2 || rows >> 10 || columns < 2 || columns > 10)
    {
        printf("Invalid Inputs!\n");
        printf("Inputs must be > 2 || < 10\n");
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

void computeStats(int rows, int columns, int grid[rows][columns])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            count[ grid[i][j] ]++;
        }
    }
}

void printStats(int count[SIZE])
{
    printf("Count of Obstacles:\n");
    printf("Safe Zones: %d\n", count[0]);
    printf("Werewolves: %d\n", count[1]);
    printf("Treacherous Swamps: %d\n", count[2]);
    printf("Giant Spiders: %d\n", count[3]);
    printf("Venomous Snakes: %d\n", count[4]);
}

void findPath(int rows, int columns, int grid[rows][columns])
{
    int i, j = 0;
    printf("Correct Path:\n")

    while(i < rows - 1 || j < columns -1)
    {
        if(j < columns - 1 && grid[i][j + 1] == 0)
        {
            printf("right\n")
        }

        if(i < rows - 1 && grid[i+1][j] == 0)
        {
            printf("down\n");
        }

        else printf("You died!\n");
    }
}
