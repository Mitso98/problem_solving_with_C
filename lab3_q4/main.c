#include <stdio.h>
#include <stdlib.h>
//4- Write a function takes 3 numbers as parameter, and returns the largest one among them... write a program to test it.
int largest(int first, int second, int third);
int main()
{
    int first, second, third;

    printf("Enter first number: ");
    scanf("%d", &first);

    printf("Enter second number: ");
    scanf("%d", &second);

    printf("Enter third number: ");
    scanf("%d", &third);

    printf("%d", largest(first, second, third));
    return 0;
}

int largest(int first, int second, int third){


    if  (first >  second && first > third){
        return first;
    }
    else if  (second >  first && second > third){
        return second;
    }
    else{
        return third;
    }
}
