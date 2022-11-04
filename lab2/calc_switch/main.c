#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    switch(operation){
        case 1:
            sum = a + b;
            printf("%d", sum);
            break;
        case 2:
            sum = a - b;
            printf("%d", sum);
            break;
        case 3:
            sum = a * b;
            printf("%d", sum);
            break;
        case 4:
            sum = a / b;
            printf("%d", sum);
            break;
        default:
            printf("Please enter valid input");
            break;
    }
    return 0;
}
