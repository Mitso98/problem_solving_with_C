#include <stdio.h>

void print_asci(){
    char input;
    printf("Enter charchter: ");
    scanf("%c", &input);
    printf("%i\n",input);
}

int main() {
    print_asci();
    return 0;
}
