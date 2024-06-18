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
            printf("%d\n", grid[i][j]);
        }
    }
}

void findMax(int rows, int columns, int grid[rows][columns], int *max)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j])
            {

            }
        }
    }
}
