 /*************************************************
  * Lab 2 Assignment
  * Author: vang838@uwm.edu
  * Created: 6/5/24
*************************************************/
 
 #include "arrays.h"
 #include <stdio.h>

 int main() 
 {
    int arr[ROWS][COLS], itemtoSearch, count;
    printf("Enter %d elements: ", ROWS * COLS);

    // Reading input for a 2D array
    // TODO
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nArray:\n");
    display(arr);

    printf("\nWhat element would you like to find: ");
    scanf("%d", &itemtoSearch);

    // call search() function with your array and itemToSearch as arguments. Save the
    // returned value in the count variable. If the item is found print the count
    // otherwise print "item not found".
    // TODO
    count = search(arr, itemtoSearch);

    if(count > 0) printf("Item found %d times within the array\n", count);

    else printf("\nItem not found\n");

    return 0;
}