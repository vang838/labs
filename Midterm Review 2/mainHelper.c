#include "function.h"

// Section 5 Question 1
// void swap(int* a, int* b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// Section 5 Question 2
// int findMax(int arr[], int size)
// {
//     if(size < 1)
//     {
//         printf("Invalid Size");
//         return 1;
//     }

//     int maxVal = arr[0];
//     for(int i = 1; i < size; i++)
//     {
//         if(maxVal < arr[i])
//         {
//             maxVal = arr[i];
//         }
//     }

//     return maxVal;
// }

// Section 5 Question 3
// int findMax(int* arr, int size)
// {
//     if(size < 1)
//     {
//         printf("Invalid Size");
//         return 1;
//     }

//     int maxVal = arr[0];
//     for(int i = 1; i < size; i++)
//     {
//         if(maxVal < arr[i])
//         {
//             maxVal = arr[i];
//         }
//     }

//     return maxVal;
// }

// // Section 5 Question 4
// void reverseArray(int arr[], int size)
// {
//     int temp = arr[0];
//     for(int i = 0; i < size / 2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }

// Section 5 Question 5
// void reverseArray(int *arr, int size)
// {
//     int temp = arr[0];
//     for(int i = 0; i < size / 2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }

// Section 5 Question 6
int sum2DArray(int rows, int columns, int grid[rows][columns])
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

    int sum = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            sum += grid[i][j];
        }
    }

    return sum;
}

// Section 5 Question 8
void convertToLowerCase(char *string)
{
    while (*string != '\0')
    {
        if(*string > 'A' && *string < 'Z')
        {
            *string = *string + ('a' - 'A');
        }
        string++;
    }
}