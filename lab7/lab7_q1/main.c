#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
/*
1. int* IncrementArray()
	- try to return fixed Array first, see what happened.
	- then rerun dynamically allocated array.
*/
void get_user_data(int length, int *arr);
int *incrementArr(int length);
void print_arr(int *arr, int length);
int main()
{
    int length;
    do
    {
        printf("Enter array length: ");
        scanf("%d", &length);
    }
    while(0 >= length);// only accept positive numbers

    // allocate memory space for the array
    int *arr = incrementArr(length);
    // get user data and store it at the arr
    get_user_data(length, arr);
    print_arr(arr, length);

    return 0;
}
void get_user_data(int length, int *arr)
{
    int input;
    for(int i = 0; i < length; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &input);
        *(arr + i) = input;
    }
}
int *incrementArr(int length)
{
    int *arr = malloc(length * sizeof(int));
    if(!arr)
        return NULL;

    return arr;
}
void print_arr(int *arr, int length)
{
    printf("-----------------------\n");
    for (int i = 0; i < length; i++)
    {
        printf("arr[%d] = %d\n",i, *(arr + i));
    }
}
