#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    for (int i = 1; i <= input; i++){
        printf("%d * %d = %d\n", i, input, i * input);
    }
    return 0;
}
