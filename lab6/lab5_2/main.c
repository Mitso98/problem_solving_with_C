#include <stdio.h>
#include <stdlib.h>
//2) Recursive: Power.
int sum(int k);

int main()
{
    int input;
    printf("Enter a number: ");
    //scanf("%d", &input);

    int result = sum(2);
    printf("%d", result);
    return 0;
}

int sum(int k)
{
    if (k > 0)
    {
        return k + sum(k - 1);
    }
    else
    {
        return 0;
    }
}

