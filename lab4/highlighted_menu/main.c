#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include<windows.h>

//10) Highlight Menu: New Colored Menu "with Arrows"
void gotoxy(int x,int y);
void SetColor(int ForgC);
void draw_line_number(int);
void draw_option_one(int);
void draw_option_two(int);
void draw_exit(int);
void move(int *pos, int input);
int main()
{
    int pos = 1;
    int input;

    draw_line_number(pos);
    draw_option_one(pos);
    draw_option_two(pos);
    draw_exit(pos);

    while(1)
    {
        input = getche();
        move(&pos, input);

        system("cls");
        draw_line_number(pos);
        draw_option_one(pos);
        draw_option_two(pos);
        draw_exit(pos);

        // if enter is pressed
        if(13 == input)
        {
            system("cls");
            switch(pos)
            {
            case 3:
                draw_option_one(pos);
                break;
            case 2:
                draw_option_two(pos);
                break;
            case 1:
                return 0;
            }
        }
    }

}
void draw_line_number(int pos)
{
    gotoxy(50,0);
    SetColor(7);
    printf("Line Number : %d", pos);
}
void draw_option_one(int pos)
{
    gotoxy(50,5);
    SetColor(pos == 3 ? 5 : 7);
    printf("Option One");
}
void draw_option_two(int pos)
{
    gotoxy(50,10);
    SetColor(pos == 2 ? 5 : 7);
    printf("Option Two");
}
void draw_exit(int pos)
{
    gotoxy(50,15);
    SetColor(pos == 1 ? 5 : 7);
    printf("EXIT");
}
void move(int *pos, int input){
        if (72 == input && 3 > *pos)
        {
            *pos+= 1;
        }
        else if (80 == input && 1 < *pos)
        {
            *pos-= 1;
        }
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

