 #include "malloc.h"
 #include <stdio.h>

 int main() 
 {
    int size1 = 0, size2 = 0;
    // TODO: Prompt the user to enter the size1 and size2
    printf("Enter size of array 1: ");
    scanf("%d", &size1);

    printf("\nEnter size of array 2: ");
    scanf("%d", &size2);

    // Create the first array using createArrayWithMalloc
    int *arr1 = createArrayWithMalloc(size1);


    // Create the second array using createArrayWithCalloc
    int *arr2 = createArrayWithCalloc(size2);

    // Concatenate the arrays using concatenateDynamicArrays
    int *ptr = concatenateArrays(arr1, size1, arr2, size2);

    // TODO: Print the contents of the concatenatedArrays that ptr is pointing to
    printf("\nArray 1 & Array 2 Combined:\n");
    printf("{");
    for(int i = 0; i < size1 + size2; i++)
    {
        printf(" %d ", ptr[i]);
    }
    printf("}\n");
    
    // TODO: Free the memory allocated for all three arrays. first one is done for you.
    freeSpace(arr1);
    freeSpace(arr2);
    freeSpace(ptr);

    return 0;
 }