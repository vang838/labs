#include "function.h"
#include "stdbool.h"
#include <time.h>

// Section 5 Question 1
// int main()
// {
//     int char1, char2;

//     printf("Enter the first integer: ");
//     scanf("%d", &char1);

//     printf("Enter the second integer: ");
//     scanf("%d", &char2);

//     printf("Before Swap: %d %d\n", char1, char2);
//     swap(&char1, &char2);
//     printf("After Swap: %d %d\n", char1, char2);
// }

// Section 5 Question 2 
// int main()
// {
//     int arr[] = {91, 33, 5, 7, 9, 12};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int max = findMax(arr, size);

//     printf("Array:\n");
//     printf("{ ");

//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     printf("}");

//     printf("\nMax Value: %d\n", max);

//     return 0;
// }

// Section 5 Question 3
// int main()
// {
//     int size = 0;
//     for(;;)
//     {
//         printf("Enter number of elements in the array: ");
//         scanf("%d", &size);

//         if(size > 0) break;

//         printf("Number of elements must be a positive integer\n\n");
//     }

//     int* arr = (int*)calloc(size * sizeof(int));

//     if(arr == NULL)
//     {
//         printf("Memory Allocation Failed\n");
//         return 1;
//     }

//     printf("\nEnter the elements of the array: ");
//     for(int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     int maxValue = findMax(arr, size);

//     printf("Array: ");
//     printf("{ ");

//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     printf("}");

//     printf("\nMax Value: %d\n", maxValue);

//     free(arr);

//     return 0;
// }

// Section 5 Question 4 & 5
// int main()
// {
//     int arr[] = {55, 11, 5, 2, 3, 99, 108};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Before Swap: ");
//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     reverseArray(arr, size);

//     printf("\nAfter Swap: ");
//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

// Section 5 Question 6
// int main()
// {
//     int rows, cols;

//     printf("Enter the number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter the number of columns: ");
//     scanf("%d", &cols);

//     int arr[rows][cols];
//     int randomNum = (rand() % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE +1)) + MIN_RANDOM_VALUE;

//     for (int i = 0; i < rows; i++) 
//     {
//         for (int j = 0; j < cols; j++) 
//         {
//             arr[i][j] = randomNum;
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     int sum = sum2DArray(rows, cols, arr);

//     printf("\n\nThe sum of all elements in the 2D array is: %d\n", sum);

//     return 0;
// }

// Section 5 Question 8
int main()
{
    char string[100];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    printf("Before Conversion: %s", string);

    convertToLowerCase(string);

    printf("\nAfter conversion: %s", string);

    return 0;
}