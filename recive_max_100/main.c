#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int input = 0;
    do{
        printf("Enter Number: ");
        scanf("%d", &input);
        sum += input;
    }while(sum < 100 && sum > 0);

    return 0;
}
