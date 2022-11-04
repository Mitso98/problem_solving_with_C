#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    if(0 < input){
        printf("\nThis is a positive number");
    }
    else if(0 == input){
        printf("\nYou entered 0 neither positive nor negative");
    }
    else {
        printf("\nThis is a negative number");
    }

    return 0;
}
