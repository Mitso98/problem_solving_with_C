#include <stdio.h>
#include <stdlib.h>

void add_two_int(){
    // get numbers
    int a,b;
    printf("Enter First Number: ");
    scanf("%d", &a);
    printf("Enter Second Number: ");
    scanf("%d", &b);

    int sum = a + b;
    printf("%d", sum);
}

int main()
{
    add_two_int();
    return 0;
}
