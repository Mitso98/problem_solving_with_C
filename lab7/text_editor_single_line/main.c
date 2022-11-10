#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
#define SIZE 1000
#define ROW 20
void push(int *col, int *max_col, int str[], int input);
void remove_ch(int *col, int str[]);
void control_extended_keys(int *col, int input, int max_col);
void print_all(int str[]);
void gotoxy(int x, int y);
int main()
{
    int input;
    int col = 0;
    int max_col = 0;
    int str[SIZE];

    do
    {
        input = getch();
        // first value of an extended key
        if (224 == input)
        {
            // take second value of the extended key
            input = getch();
            control_extended_keys(&col, input, max_col);
            gotoxy(col, ROW);
        }
        else if(input == 8)
        {
            //manage backspace
            gotoxy(col, ROW);
            printf("%c", '\0');
            remove_ch( &col, str);
            gotoxy(col, ROW);
        }
        else
        {
            push( &col, &max_col, str, input);
            gotoxy(col, ROW);
            printf("%c", input);
        }
    }
    while(13 != input);
    print_all(str);
    return 0;
}
void push(int *col, int *max_col, int str[], int input)
{
    str[*col] = input;
    str[*col + 1] = '\0';
    *col += 1;
    *max_col += 1;
}
void remove_ch(int *col, int str[])
{
    if (0 == *col)
    {
        return;
    }

    str[*col] = '\0';
    *col -= 1;


}
void control_extended_keys(int *col, int input, int max_col)
{
    if (77 == input && *col < max_col) // 77 right arrow
    {
        *col += 1;
        gotoxy(*col, ROW);
    }
    else if (75 == input && 0 < *col) // 75 left arrow
    {
        *col -= 1;
        gotoxy(*col, ROW);
    }
    else if (71 == input)
    {
        // 71 == home key go to first element
        *col = 0;
        gotoxy(*col, ROW);
    }
    else if (82 == input)
    {
        // 82 == insert key go last element
        *col = max_col;
        gotoxy(*col, ROW);
    }
}
void print_all(int str[])
{
    system("cls");

    int counter = 0;
    while(str[counter] != '\0')
    {
        printf("%c", str[counter]);
        counter++;
    }
}
void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
