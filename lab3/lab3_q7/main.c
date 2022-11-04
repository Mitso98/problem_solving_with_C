#include <stdio.h>
#include <stdlib.h>
//7-Write a C Function that prints the cube of any number.

int cube(int);
int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    printf("%d", cube(input));
    return 0;
}
int cube(int input){
    return input * input * input;
}
