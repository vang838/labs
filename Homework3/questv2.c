/******************************************
 * Author: vang838@uwm.edu
 * 
 * Created: 6/18/24
 *****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "questv2.h"

void generateNDisplayGrid(int rows, int columns, int grid[rows][columns])
{
    if(rows < 1 || rows > 11)
    {
        printf("Invalid Row Input!\n");
        printf("Valid Inputs: 2 =< Input <= 10 \n");
        return 1;
    }

        if(columns < 1 || columns > 11)
    {
        printf("Invalid Column Input!\n");
        printf("Valid Inputs: 2 =< Input <= 10 \n");
        return 1;
    }

    srand(time(NULL));
    //srand(123);
    int randomNum = rand() % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE + 1) + MIN_RANDOM_VALUE;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            grid[i][j] = randomNum;
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void findMax(int rows, int columns, int grid[rows][columns], int *max)
{
    *max = grid[i][j];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j] > *max )
            {
                *max = grid[i][j];
            }
        }
    }
}

int* computeStatsV2(int rows, int columns, int grid[rows][columns], int max)
{
    int *count = (int*)calloc(max +1, sizeof(int));
    if(count == NULL)
    {
        printf(stderr, "Memory Allocation Failed\n");
        exit(1);
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            count[ grid[i][j] ]++;
        }
    }
    return count;
}

void printStats(int *counts, int max)
{
    int frequency = 0;
    for(;;)
    {
        printf("Please enter a frequency greater than 0: ");
        scanf("%d", &frequency);

        if(frequency > 0) break;
    }

    int result = 0;
    for(int i = 0; i < max; i++)
    {
        if(counts[i] >= frequency)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) printf("No obstacles found!\n");
}

void freeStats(int *count)
{
    free(counts);
}