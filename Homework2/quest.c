#include <stdio.h>
#include <stdlib.h>
#include "quest.h"

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

void printStats(int count[SIZE])
{
    printf("\nCount of Obstacles:\n");
    printf("Safe Zones: %d\n", count[0]);
    printf("Werewolves: %d\n", count[1]);
    printf("Treacherous Swamps: %d\n", count[2]);
    printf("Giant Spiders: %d\n", count[3]);
    printf("Venomous Snakes: %d\n", count[4]);
}

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
