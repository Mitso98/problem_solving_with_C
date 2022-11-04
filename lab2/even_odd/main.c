#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    if (2 % input == 0){
        printf("This is an even number.");
    }
    else{
        printf("This is an odd number.");
    }
    return 0;
}
