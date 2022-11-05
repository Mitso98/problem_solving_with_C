#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include<windows.h>
#define SIZE 50
//4- Employee with functions and Highlight Menu: Menu of Array_Of_Struct

void get_data(int);
void print_data(int);
void print_data_header(int, int);
void move_pos(int, int*, int);
void gotoxy(int x,int y);
void SetColor(int ForgC);
typedef struct Employee
{
    int id, salary;
    char name[48];
} Employee;
Employee emp_array[SIZE];

int main()
{
    int length;
    printf("How many employees do you have? ");
    scanf("%d", &length);

    int pos = 1;
    int input;

    get_data(length);

    while(1)
    {
        print_data_header(pos, length);
        input = getche();
        move_pos(input, &pos, length);
        if (13 == input && length + 1 != pos)
        {
            print_data(pos);
            input = getche();
        }
        else if ((13 == input && length + 1 == pos))
        {
            return 0;
        }
    }
}

void get_data(int length)
{
    // get data
    for (int i = 0; i < length; ++i)
    {
        // to know which position we are at
        printf("Employee %d data\n", i + 1);
        //get user data
        printf("Employee ID: ");
        scanf("%d", &emp_array[i].id);

        printf("Employee Salary: ");
        scanf("%d", &emp_array[i].salary);

        printf("Employee Name: ");
        scanf("%s", emp_array[i].name);
    }
}
void print_data(int pos)
{
    // this function will print data of only one employee
    // we will decrease position by one to start from 0 like the index
    pos--;
    system("cls");

    //show user data
    gotoxy(50,10);
    SetColor(7);
    printf("Employee ID: %d\n", emp_array[pos].id);
    gotoxy(50,11);
    SetColor(7);
    printf("Employee Salary: %d\n", emp_array[pos].salary);
    gotoxy(50,12);
    SetColor(7);
    printf("Employee Name: %s\n", emp_array[pos].name);
}
void print_data_header(int pos,int length)
{
    system("cls");
    //print data
    for (int i = 0; i < length; ++i)
    {
        gotoxy(50,i*5);
        SetColor(i + 1 == pos? 5 : 7);
        printf("Employee Name: %s\n", emp_array[i].name);
    }
    // EXIT will always be printed
    gotoxy(50, length*5);
    SetColor((length + 1) == pos ? 5 : 7);
    printf("EXIT");
}
move_pos(int input, int *pos, int length)
{
    if (80 == input && (length + 1) > *pos)
    {
        *pos += 1;// go up
    }
    else if (72 == input && 1 < *pos)
    {
        *pos -= 1;// go down
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
