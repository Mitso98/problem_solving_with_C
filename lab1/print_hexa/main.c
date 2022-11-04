#include <stdio.h>
#include <stdlib.h>

void print_hexa(){
    int number;
    printf("Enter Number: ");
    scanf("%d", &number);
    printf("%x", number);
}
int main()
{
    print_hexa();
    return 0;
}
