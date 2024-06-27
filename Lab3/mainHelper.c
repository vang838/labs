#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>

int* createArrayWithMalloc(int size)
{
    int *arr1 = (int*)malloc(size * sizeof(int));

    if(arr1 == NULL)
    {
        printf("Memory allocation failed for Array 1\n");
        exit(1);
    }

    // Temporary For Loop to fill in array 1
    for(int i = 0; i < size; i++)
    {
       arr1[i] = 0;
    }
    return arr1;
}

int* createArrayWithCalloc(int size)
{
    int *arr2 = (int*)calloc(size, sizeof(int));

    if(arr2 == NULL)
    {
        printf("Memory allocation failed for Array 2\n");
        exit(1);
    }

    // Temporary For Loop to fill in array 2
    for(int i = 0; i < size; i++)
    {
        arr2[i] = 0;
    }
    return arr2;
}

int* concatenateArrays(int *arr1, int size1, int *arr2, int size2)
{
    int *combinedArrays = (int*)malloc((size1 + size2) * sizeof(int));

    if(combinedArrays == NULL)
    {
        printf("Memory allocation failed for combinedArrays\n");
        exit(1);
    }

    // Copy arr1 indices to combinedArrays
    for(int i = 0; i < size1; i++)
    {
        combinedArrays[i] = arr1[i];
    }

    // Copy arr2 indices to combinedArrays
    for(int i = 0; i < size2; i++)
    {
        combinedArrays[size1 + i] = arr2[i];
    }
    return combinedArrays;
}

void freeSpace(int* arr)
{
    free(arr);
}
