#include "arrays.h"
/*****************************************************
 * Display Function
 * Description: Displays each element at index [i][j]
 * 
 * Outer For Loop iterates over the rows
 * Inner For Loop iterates over the columns
 * 
******************************************************/
void display(int arr[][COLS])
{
    for(int i = 0; i < ROWS; i++)       // outer for loop iterates over the rows
    {
        for(int j = 0; j < COLS; j++)   // inner for loop iterates over the columns
        {
            printf("%d ", arr[i][j]);   // prints element at index [i][j]
        }
        printf("\n");
    }
}