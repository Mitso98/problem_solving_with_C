#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>


typedef struct score
{
    int pos;
    int player;
} Score;

void determine_player(int *player1, int *player2);
void draw_playground(int player1, int player2, Score arr[]);
int winner(Score *arr);
void gotoxy(int x, int y);

int main()
{
    int player1, player2;
    Score arr[9];

    determine_player(&player1, &player2);
    draw_playground(player1, player2, arr);

    return 0;
}

void determine_player(int *player1, int *player2)
{
    do
    {
        printf("Player 1 will take X or Y: \n");
        *player1 = getch();
    }
    while (88 != *player1 && 89 != *player1);
    // 120 and 88 for x capital and small

    // for the user
    printf("%c\n", *player1);

    // check for x
    if (*player1 == 88)
    {
        *player2 = 89;
    }
    else
    {
        *player2 = 88;
    }
}
void draw_playground(int player1, int player2, Score arr[])
{
    char current_player;
    int is_valid = 1;
    int input;
    int toggle_player = 1;


    for (int i = 0; i < 9; i++)
    {
        arr[i].pos = 0;
        arr[i].player = 0;
    }
    system("cls");
    int counter = 0;
    do
    {
        // toggle the player
        if (toggle_player % 2 == 0)
        {
            current_player = player2;
        }
        else
        {
            current_player = player1;
        }

        do
        {

            gotoxy(0, 0);
            printf("Enter position: \n");
            scanf("%i", &input);
            is_valid = 1;
            for (int i = 0; i < 9; i++)
            {
                if (arr[i].pos == input)
                {
                    is_valid = 0;
                    break;
                }
            }
            if (is_valid == 1)
            {
                arr[input - 1].player = current_player;
                arr[input - 1].pos = input;
            }
        }
        while (counter != 9 && is_valid == 0);
        counter++;

        if (input >= 1 && input <= 9)
        {
            // first row
            if (1 == input || 2 == input || 3 == input)
            {
                gotoxy(input * 3, 10);
                printf("%c", current_player);
            }
            // second row
            else if (4 == input || 5 == input || 6 == input)
            {
                switch (input)
                {
                case 4:
                    gotoxy(1 * 3, 15);
                    printf("%c", current_player);
                    break;
                case 5:
                    gotoxy(2 * 3, 15);
                    printf("%c", current_player);
                    break;
                case 6:
                    gotoxy(3 * 3, 15);
                    printf("%c", current_player);
                    break;
                }
            }
            // third row
            else
            {
                switch (input)
                {
                case 7:
                    gotoxy(1 * 3, 20);
                    printf("%c", current_player);
                    break;
                case 8:
                    gotoxy(2 * 3, 20);
                    printf("%c", current_player);
                    break;
                case 9:
                    gotoxy(3 * 3, 20);
                    printf("%c", current_player);
                    break;
                }
            }
        }
        toggle_player++;

        int win = winner(arr);

        if(win == 88)
        {
            gotoxy(50,10);
            printf("The winner is X");
            gotoxy(0,30);
            return;
        }
        else if(win == 89)
        {

            gotoxy(50,10);
            printf("The winner is Y");
            gotoxy(0,30);
            return;
        }
    }
    while (input >= 1 && input <= 9 && counter != 9);
    gotoxy(50,10);
    printf("Tie");
}
int winner(Score arr[])
{
    // 15, 6, 24
    int x;
    int counter_x = 0;
    int y;
    int counter_y = 0;
    int i;
    int current_winner = 0;
    int prev_winner = 0;

    // horizontal check
    for (i = 0; i < 9; i+= 3)
    {
        if (arr[i].player == arr[i + 1].player && arr[i].player == arr[i + 2].player)
            return arr[i].player;
    }

    // vertical check
    for (i = 0; i < 3; i++)
    {
        if(arr[i].player == arr[i + 3].player && arr[i + 6].player)
            return arr[i].player;
    }

    // diagonal check
    for (i = 0; i <= 2; i+= 2)
    {
        if (i == 0)
        {
            if(arr[i].player == arr[i + 4].player && arr[i].player == arr[i + 8].player)
                return arr[i].player;
        }
        else
        {
            if(arr[i].player == arr[i + 2].player && arr[i].player == arr[i + 4].player)
                return arr[i].player;
        }
    }
    // still can take values
    return 0;

}
void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
