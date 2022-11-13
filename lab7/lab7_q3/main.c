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
    int subjects_count;
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
    Score * score;
    int input = 1;
    // fill students
    do
    {
        printf("Enter student id: ");
        scanf("%d", &input);

        if (9348 == input)
        {
            //current->next = NULL;
            return;
        }
        else
        {
            current->next = (Student*)malloc(sizeof(Student));
            //prev = current;
            current = current->next;
            score = (Score*)malloc(sizeof(Score));
            current->next_score = score;
            current->student_id = input;
        }
        do
        {
            printf("Enter student %d score: ", current->student_id);
            scanf("%d", &input);
            score->score = input;
            score->next = (Score*)malloc(sizeof(Score));
            score->next->next = NULL;
            score = score->next;

            printf("Enter 1 to exit, or any key to continue: ");
            scanf("%d", &input);
        }
        while(1 != input);
        printf("Enter 1 to exit, or any key to continue: ");
        scanf("%d", &input);

        current->next = NULL;
    }
    while(current->next != NULL || 1 != input);
}
void print_all(Student* head)
{
    Student * current = head;
    Score * score;
    int sum = 0;
    int std_ctr = 0;
    int subj_ctr = 0;
    int count_max = 0;
    while(current->next != NULL)
    {
        current = current->next;
        score = current->next_score;
        std_ctr++;
        do
        {
            // sum of degrees for each student
            sum += score->score;
            score = score->next;
            count_max++;
        }
        while(score->next != NULL);
        subj_ctr = subj_ctr < count_max ? count_max + subj_ctr:   subj_ctr;
        count_max = 0;
        printf("Student %d scored %d\n", current->student_id, sum);
        sum = 0;
    }
    int avg_ctr = 0;
    int counter = 0;
    int loop = 0;
    sum = 0;
    for (int i = 0; i < subj_ctr; i++)
    {
        current = head;
        for (int j = 0; j < std_ctr; j++)
        {
            current = current->next;
            score = current->next_score;
            while(score->next->next != NULL && counter < loop)
            {
                score = score->next;
                counter++;
            }
            sum = counter == loop ? sum + score->score: sum;
            counter = 0;
            avg_ctr++;
        }
        loop++;
        printf("AVG: %d\n", sum / avg_ctr);
        sum = 0;
        avg_ctr = 0;
    }
}

