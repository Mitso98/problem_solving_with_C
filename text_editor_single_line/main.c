#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
#define SIZE 1000
#define ROW 0
void push(int *col, int *max_col, int str[], int input);
void remove_ch(int *col, int *max_col, int str[]);
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
        }
        else if(input == 8)
        {
            //manage backspace
            remove_ch( &col, &max_col, str);
        }
        else if (32 <= input && 126 >= input)
        {
            // do not accept enter as an inout
            push( &col, &max_col, str, input);
        }
        print_all(str);
        gotoxy(50, 20);
        printf("max_col: %d, col: %d", max_col, col);
        gotoxy(col, ROW);
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
    // increase maximum column only if col will be higher than it
    *max_col = *col > *max_col? *col: *max_col;
}
void remove_ch(int *col, int * max_col, int str[])
{
    if (0 == *col)
    {
        return;
    }
    if (*col == *max_col)
    {
        *col -= 1;
        str[*col] = '\0';
        *max_col -= 1;
    }
    else
    {
        int i;
        for (i = *col - 1; i <= *max_col; i++)
        {
            str[i] = str[i + 1];
        }
        str[i + 1] = '\0';
        *max_col -= 1;
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
void control_extended_keys(int *col, int input, int max_col)
{
    if (77 == input && *col < max_col) // 77 right arrow
    {
        *col += 1;

    }
    else if (75 == input && 0 < *col) // 75 left arrow
    {
        *col -= 1;

    }
    else if (71 == input)
    {
        // 71 == home key go to first element
        *col = 0;

    }
    else if (82 == input)
    {
        // 82 == insert key go last element
        *col = max_col;
    }
    gotoxy(*col, ROW);
}
void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#include <stdio.h>
#include <stdlib.h>
/*
3. C Program to calculate sum of student degrees, and average of each subject, asks the user for
    students and subject numbers. (Dynamic Allocation of 2D Array - Pointer to Pointer)
*/
typedef struct score
{
    int score;
    struct score * next;
} Score;
typedef struct student
{
    int student_id;
    struct student* next;
    struct score* next_score;
} Student;
void get_students(Student * head, int students_no);
void fill_data(Student * head);
void print_all(Student* head);
int main()
{
    int students_no = 2;

    Student* student = (Student*)malloc(sizeof(Student));
    student->next_score = (Score*)malloc(sizeof(Score));
    student->next = NULL;
    student->next_score->next = NULL;


    //get_students(student, students_no);
    fill_data(student);
    print_all(student);


    return 0;
}
void get_students(Student * head, int students_no)
{
    Student* student = head;

    for (int i = 0; i < students_no; i++)
    {
        student->next = (Student*)malloc(sizeof(Student));
        student = student->next;
    }
    student->next = NULL;
}
void get_score(Score * head, int subject_no)
{
    Score* score = head;

    for (int i = 0; i < subject_no; i++)
    {
        score->next = (Score*)malloc(sizeof(Score));
        score = score->next;
    }
    score->next = NULL;
}
void fill_data(Student * head)
{
    Student * current = head;
    //Score * score = current->next_score;

    
    int input = 1;
    // fill students

        printf("Enter student name: ");
 

        if (9348 == input)
        {
            //current->next = NULL;
            return;
        }

            current->next = (Student*)malloc(sizeof(Student));
            //prev = current;
            current = current->next;
            Score * score = (Score*)malloc(sizeof(Score));
            current->next_score = score;
            current->student_id = input;
    
   
            printf("Enter student score, press ESC to exit: ");
            input = 2;
            if (9348 != input)
            {

                score->score = input;
               score->next = (Score*)malloc(sizeof(Score));
                score->next->next = NULL;
                score = score->next;
            }
            input = 3;
            if (9348 != input)
            {
                score->score = input;
                score->next = (Score*)malloc(sizeof(Score));
                score->next->next = NULL;
                score = score->next;
            }
        //current->next_score = score;
        current->next = NULL;
  
}
void print_all(Student* head)
{
    Student * current = head->next;
    //printf(">> %d", current->next->student_id);
    printf(">> %d", current->next_score->score);


}