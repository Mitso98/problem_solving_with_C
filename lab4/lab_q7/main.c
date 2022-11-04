#include <stdio.h>
#include <stdlib.h>
//6) C Program to Find the Length of a String without Using strlen()
int str_cpy(const char* target);
int main()
{
    char str[50] = "Mostafa";
    printf(">>> %d", str_len(str));
    return 0;
}
int str_len(const char* target){
    int counter = 0;
    while ('\0' != target[counter]){
        counter++;
    }
    return counter;
}
