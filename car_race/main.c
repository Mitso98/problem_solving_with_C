#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
#include <time.h>

#define SPEED 3
#define CAR_LENGTH 3
#define CAR_WIDTH 3
#define TRACK_LENGTH 20
#define TRACK_WIDTH 30
#define START_ROW 3
#define START_COL 20

void show_start_message(char *is_start_message);
void draw_square(int col, int row, int length, int width);
void gotoxy(int x, int y);
void control_extended_keys(int input, int* col, int* row);
void opponent(int *random_col, int *change_row, int *score, int* col);
int detect_lose(int counter, int col, int row, int random_col);
void hidecursor();
void SetColor(int ForgC);


int main()
{
    // Initialization for rand function, should only be called once.
    srand(time(NULL));
    hidecursor();

    char is_start_message = 't';
    int input;
    int col = START_COL + 1;
    int row = TRACK_LENGTH + START_ROW - CAR_LENGTH - 1;
    int random_col = rand() % START_COL + (TRACK_WIDTH - CAR_WIDTH);
    int change_row = 1;
    int score = 0;


    do
    {
        system("cls");

        gotoxy(30, 1);
        printf("Your score is %d", score);
        // TRACK
        draw_square(START_COL, START_ROW, TRACK_LENGTH, TRACK_WIDTH);

        // OPONENT
        opponent(&random_col, &change_row, &score, &col);

        // CAR
        draw_square(col, row, CAR_LENGTH, CAR_WIDTH);

        show_start_message(&is_start_message);


        if (detect_lose(change_row, col, row, random_col) == 1)
            break;

        if(kbhit())
        {
            input =  getch();
        }

        if (224 == input)
        {
            input = getch();
            control_extended_keys(input, &col, &row);
        }

    }
    while(input != 27);

    // push the cursor away
    gotoxy(0,30);

    return 0;
}

void show_start_message(char *is_start_message)
{
    if ('t' == *is_start_message)
    {
        gotoxy(TRACK_WIDTH / 2 + 1, TRACK_LENGTH / 2);
        printf("Press any key to start!");
        getch();
        *is_start_message = 'f';
    }
}
void draw_square(int col, int row, int length, int width)
{
    // front
    gotoxy( col,row);
    for (int i = 0; i <= width; i++)
    {
        printf(".");
    }
    //right edge
    for (int i = 0; i <= length; i++)
    {
        gotoxy( col + width, row + i);
        printf(".");
    }

    // back
    gotoxy( col, row + length);
    for (int i = 0; i < width; i++)
    {
        printf(".");
    }

    //left edge
    for (int i = 0; i < length; i++)
    {
        gotoxy( col, row + i);
        printf(".");
    }
}

void control_extended_keys(int input, int* col, int* row)
{

    // 72 up arrow
    if (72 == input && *row > START_ROW + SPEED)
    {
        *row -= SPEED;
    }
    // 80 down arrow
    else if (80 == input && *row < TRACK_LENGTH - SPEED)
    {
        *row += SPEED;
    }
    // 77 right arrow
    else if (77 == input && *col < TRACK_WIDTH + START_COL - CAR_WIDTH - SPEED)
    {
        *col += SPEED;
    }
    // 75 left arrow
    else if (75 == input && *col > START_COL + SPEED)
    {
        *col -= SPEED;
    }
}
void opponent(int *random_col, int *change_row, int *score, int *col)
{
    // each 3 times try to hit the player
    if (20 == *score && *change_row > 3)
    {
        *random_col = *col;
    }

    // each 3 times try to hit the player
    if (*score % 3 == 0 && *change_row == 1)
    {
        *random_col = *col;
    }

    SetColor(4);
    draw_square(*random_col, START_ROW + *change_row, CAR_LENGTH, CAR_WIDTH);
    SetColor(7);

    if(*change_row > (TRACK_LENGTH- CAR_LENGTH - 1))
    {
        *change_row = 1;
        *random_col = rand() % START_COL + (TRACK_WIDTH - CAR_WIDTH);
        *score += 1;
    }
    else
    {
        *change_row += 1;
    }

}
int detect_lose(int counter, int col, int row, int random_col)
{
    if (
        // if the left part touched any point of the other car
        (col  == random_col && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col  == random_col + 1 && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col  == random_col + 2 && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col  == random_col + 3 && row == START_ROW + CAR_LENGTH + counter - 1)||
        // if the right part touched any point of the other car
        (col + CAR_WIDTH  == random_col && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col + CAR_WIDTH  == random_col + 1 && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col + CAR_WIDTH  == random_col + 2 && row == START_ROW + CAR_LENGTH + counter - 1) ||
        (col + CAR_WIDTH  == random_col + 3 && row == START_ROW + CAR_LENGTH + counter - 1)
    )
    {
        return 1;
    }
    return 0;
}
void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
