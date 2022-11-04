#include <stdio.h>
#include <stdlib.h>

void calc(){
    int operation;
    int sum;
    int a;
    int b;
    // determine the operation
    printf("enter add: 1, subtract: 2, multiply: 3, divid: 4\n");
    scanf("%d", &operation);

    // get numbers
    printf("Enter First Number: ");
    scanf("%d", &a);
    printf("Enter Second Number: ");
    scanf("%d", &b);

    if (operation == 1){
        sum = a + b;
        printf("%d", sum);
    }
    else if (operation == 2){
        sum = a - b;
        printf("%d", sum);
    }
    else if (operation == 3){
        sum = a * b;
        printf("%d", sum);
    }
    else if (operation == 4){
        sum = a / b;
        printf("%d", sum);
    }
}
int main()
{
    calc();
    return 0;
}
