#include <stdio.h>
#include <stdlib.h>
//5) C Program to Copy String Without Using strcpy()
void str_cpy(char* destination, const char* source);
int main()
{
    char str1[50] = "Mostafa";
    char str2[50];
    str_cpy(str2,str1);
    printf(">>> %s", str2);
    return 0;
}
void str_cpy(char* destination, const char* source){
    int counter = 0;
    while ('\0' != source[counter]){
        destination[counter] = source[counter];
        counter++;
    }
}
