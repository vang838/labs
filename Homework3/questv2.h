#include <stdio.h>
#include <stdlib.h>

#define MIN_RANDOM_VALUE 0
#define MAX_RANDOM_VALUE 50

void generateNDisplayGrid(int rows, int columns, int grid[rows][columns]);
void findMax(int rows, int columns, int grid[rows][columns], int *max);
int* computeStatsV2(int rows, int columns, int grid[rows][columns], int max);
void printStats(int *counts, int max);
void freeStats(int* counts);