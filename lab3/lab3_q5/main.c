#include <stdio.h>
#include <stdlib.h>
//5- Write a C Function that takes one character and checks if it alphabet or not.
int is_alphabet(int input);
int main()
{
    char input;
    printf("Enter a value: ");
    scanf("%c", &input);

    if(is_alphabet((int)input)){
        printf("This an Alphabet.");
    }
    else{
        printf("This not an alphabet");
    }


    return 0;
}

int is_alphabet(int input){
    if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)){
        return 1;
    }
    else{
        return 0;
    }
}
