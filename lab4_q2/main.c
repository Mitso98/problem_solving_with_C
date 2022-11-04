#include <stdio.h>
#include <stdlib.h>
//1) Receive character by character and then place the string terminator upon pressing enter, then display the string.
int main()
{

    char arr[100];
    char input;
    int counter = 0;
    printf("Enter a value:");
    do{

        scanf("%c", &input);
        if (10 != (int) input){
            arr[counter] = input;
            counter++;
        }
    }while(10 != (int) input);

    arr[counter] = '\0';



    for (int i = 0; i < counter; i++){
        printf("%c\n", arr[i]);
    }

    return 0;
}
