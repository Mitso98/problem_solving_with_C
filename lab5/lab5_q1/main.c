#include <stdio.h>
#include <stdlib.h>
/*
    1- C Program to take single Employee's information(ID, Name, Salary, Bonus, Deduction)
    , and display his code, name along with his net salary. (Emp_Struct)
*/
typedef struct Employee{
        int id, salary, bounus,deduction;
        char name[50];
}Employee;

int main()
{
    // Initialize the struct
    Employee emp;

    //get user data
    printf("Employee ID: ");
    scanf("%d", &emp.id);

    printf("Employee Salary: ");
    scanf("%d", &emp.salary);

    printf("Employee Bonus: ");
    scanf("%d", &emp.bounus);

    printf("Employee Deduction: ");
    scanf("%d", &emp.deduction);

    printf("Employee Name: ");
    scanf("%s", emp.name);

    //print user data
    int net_salary = emp.salary + emp.bounus - emp.deduction ;
    printf("\nID: %d, \n Name: %s, \nNet Salary: %d", emp.id, emp.name, net_salary);

    return 0;
}
