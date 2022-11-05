#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
//2- C Program to take information of Array of 5 Employees, then display their data. (EmpArr_of_Struct)
/*
    3- Employee with Functions (try to divide Ass#2 into 2 functions):
        struct Employee AddNewEmployee();
        void DisplayEmployee(struct Employee);
*/

void get_data();
void print_data(int);

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

    get_data(length);
    print_data(length);

    return 0;
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
void print_data(int length)
{
    //print data
    for (int i = 0; i < length; ++i)
    {
        // print new line to separate input from output
        printf("\n");
        //get user data
        printf("Employee ID: %d\n", emp_array[i].id);

        printf("Employee Salary: %d\n", emp_array[i].salary);

        printf("Employee Name: %s\n", emp_array[i].name);
    }
}
