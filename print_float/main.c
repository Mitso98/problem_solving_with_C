#include <stdio.h>
#include <stdlib.h>

void get_float(){
    float user_input;
    printf("enter float: ");
    scanf("%f", &user_input);
    printf("%f", user_input);
}

int main()
{
    get_float();
    return 0;
}
