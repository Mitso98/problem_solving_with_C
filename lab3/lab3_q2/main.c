#include <stdio.h>
#include <stdlib.h>

int print_form();
//2- Simple Menu with 3 choices.
int main()
{
    int toggle = 1;
    int choice;
    do{

        if (toggle){
            printf("1- Good Morning.\n");
            printf("2- Good Night.\n");
            printf("3- Good bye.\n");
            scanf("%d", &choice);
            toggle = 0;

        }else{
            system("cls");
            switch(choice){
            case 1:
                printf("Good Morning.\n");
                scanf("%d");
                toggle = 1;
                system("cls");
                break;
            case 2:
                printf("Good Night.\n");
                scanf("%d");
                toggle = 1;
                system("cls");
                break;
            case 3:
                return 0;
            }
        }

    }while(choice > 0 && choice <= 3);

    return 0;
}

