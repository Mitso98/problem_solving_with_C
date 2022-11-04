#include <stdio.h>
#include <stdlib.h>
void reminder_quotient(){
    int operation;
    int sum;
    int a;
    int b;
    // determine the operation
    printf("enter reminder: 1, quotient : 2 \n");
    scanf("%d", &operation);

    // get numbers
    printf("Enter First Number: ");
    scanf("%d", &a);
    printf("Enter Second Number: ");
    scanf("%d", &b);

    if (operation == 1){
        sum = a % b;
        printf("%d", sum);
    }
    else if (operation == 2){
        sum = a / b;
        printf("%d", sum);
    }

}
int main()
{
    reminder_quotient();
    return 0;
}
