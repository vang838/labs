#include "arrays.h"
/*****************************************************
 * Search Function
 * Searches for an element in a given 2D array
 * Outer For Loop iterates over the rows
 * Inner For Loop iterates over the columns
 * 
******************************************************/
int search(int arr[][COLS], int searchValue)
{
    int count = 0;
    
    for(int i = 0; i < ROWS; i++)           // Outer For Loop iterates over rows
    {
        for(int j = 0; j < COLS; j++)       // Inner For Loop iterates over columns
        {
            if(arr[i][j] == searchValue)    // Element found at index [i][j]
            {
                count++;
            }
        }
    }
    return count;
}
