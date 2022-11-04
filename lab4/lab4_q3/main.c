#include <stdio.h>
#include <stdlib.h>
//3) C Program to take char and displays if it is "Normal or Extended key" along with its Ascii value.
int main()
{
    char input;
    input = getch();

    if (-32 == (int)input){
        // will getch again to get it's asci
        input = getch();
        printf("this is an extend key.\n");
        printf("It's value is: %d\n", input);
    }
    else{
        printf("this is not an extend key.\n");
        printf("It's value is: %d\n", input);
    }

    return 0;
}
