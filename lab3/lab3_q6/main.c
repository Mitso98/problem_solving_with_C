#include <stdio.h>
#include <stdlib.h>
//6- Write C Function that converts the any letter from lowercase to uppercase.
int lower_to_upper(int input);
int main()
{
    char input;
    printf("Enter charchter: ");
    scanf("%c", &input);

    printf("%c", lower_to_upper(input));
    return 0;
}

int lower_to_upper(int input){
    int asci = input - 32;
    // 32  is differance between lower and upper
    return  asci;
}
