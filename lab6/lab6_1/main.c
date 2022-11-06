#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
/*
1) Input and Output from Array using pointers:
  C Program that have an Array of integers, read array data from user, Ptr -> Arr, print that array using Ptr.
 (try to use "Array Notation while reading data" and "Pointer notation while printing data")
*/

int main()
{
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++){
        printf("Enter a number ");
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;

    for (int i = 0; i < SIZE; i++){
        printf("%d", *ptr);
        ptr++;
    }
    return 0;
}
