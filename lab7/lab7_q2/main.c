#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include<windows.h>
#define SIZE 50
//4- Employee with functions and Highlight Menu: Menu of Array_Of_Struct

void get_data();
int print_data(int length);
void front_page(int);
void move_pos(int, int*, int);
void gotoxy(int x,int y);
void SetColor(int ForgC);
typedef struct Employee
{
    int id, salary;
    char name[50];
} Employee;
Employee emp_array[SIZE];

int main()
{
    int pos = 1; // our position at the terminal
    int input; // input from user
    const int length = 3; //length of front page items
    int employees_number = 0; // number of employees we have


    while(1)
    {
        front_page(pos);
        input = getche();
        move_pos(input, &pos, length);
        if (13 == input && 1 == pos)
        {
            get_data(&employees_number);
            input = getche();
        }
        else if (13 == input && 2 == pos)
        {
            print_data(employees_number);
            input = getche();
        }
        else if (13 == input && 3 == pos)
        {
            return 0;
        }
    }
}

void get_data(int * employees_number)
{
    system("cls");
    int length;
    printf("How many employees you want to enter?");
    scanf("%d", &length);

    int i = *employees_number;
    *employees_number += length;

    for (; i < *employees_number; i++)
    {
        //get user data
        printf("Employee ID: ");
        scanf("%d", &emp_array[i].id);

        printf("Employee Salary: ");
        scanf("%d", &emp_array[i].salary);

        printf("Employee Name: ");
        scanf("%s", emp_array[i].name);
    }


}
int print_data(int length)
{
    system("cls");
    // this function will print data of all employees
    if (0 == length)
    {
        printf("No data to be shown");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        printf("ID: %d\n", emp_array[i].id);
        printf("Name: %s\n", emp_array[i].name);
        printf("Salary: %d\n", emp_array[i].salary);
        printf("---------------------------------------\n");
    }
    return 0;
}
void front_page(int pos)
{
    system("cls");

    gotoxy(50,0*5);
    SetColor(1 == pos? 5 : 7);
    printf("Add Employee");

    gotoxy(50,1*5);
    SetColor(2 == pos? 5 : 7);
    printf("Display Employees");

    // EXIT
    gotoxy(50, 2*5);
    SetColor(3 == pos ? 5 : 7);
    printf("EXIT");
}
void move_pos(int input, int *pos, int length)
{
    if (80 == input && length > *pos)
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
