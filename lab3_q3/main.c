#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>

void gotoxy(int x,int y);
void delay(int number_of_seconds);

int main()
{
    int size;
    do{
        printf("Enter box size: ");
        scanf("%d", &size);
    }while(size % 2 == 0);

    int row = 1;
    int column = (size + 1) / 2;

    for (int i = 1; i <= size * size; i++){
        gotoxy(column * 5,row );
        printf("%d",i);

        if (0 == (i  % size)){
            row++; //go down
        }else{
            // go up left
            column--;
            row--;
        }
        if (0 == row){
            row = size;
        }
        if (0 == column){
            column = size;
        }

        delay(1);

    }
    return 0;
}

void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

