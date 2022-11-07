#include <stdio.h>
#include <stdlib.h>
//2) Recursive: Power.
int sum(int, int);

int main()
{
    int input;
    int power;
    printf("Enter a number: ");
    scanf("%d", &input);
    printf("Enter power: ");
    scanf("%d", &power);

    int result = sum(input, power);
    printf("%d", result);

    return 0;
}

int sum(int k, int power)
{
    if (power > 0)
    {
        return k * sum(k, power - 1);
    }
    else
    {
        return 1;
    }
}


