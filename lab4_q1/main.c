#include <stdio.h>
#include <stdlib.h>
//1) C Program to swap 2 integer values. (Swap function, calling by address)
int swap(int *x, int *y);
int main()
{
    int x, y;
    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Enter value of y: ");
    scanf("%d", &y);

    swap(&x, &y);
    return 0;
}
int swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
    printf("X is: %d  Y is:%d", *x, *y);
}
