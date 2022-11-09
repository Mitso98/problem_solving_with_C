#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include<windows.h>

typedef struct node
{
    char val;
    struct node * next;
} Node;

typedef struct column_size
{
    // to store how many columns are at each row
    int row_num;
    int size;
    struct column_size * next;
} Col_size;

void push(Node * head, int val, int * max_col, int * max_row, int *col, int * row, Col_size * head_col_count);
void print_char(Node * head, int col, int row, int is_all);
void print_all(Node * head);
void control_extended_keys(int input, int *col, int *row, int max_col, int max_row, Col_size * head_col_size);
void remove_node(int * col, int * row, int * max_col, int * max_row, Node * head);
void gotoxy(int x,int y);

int main()
{
    int input;
    int col = 0;
    int row = 0;
    int max_col = 0;
    int max_row = 0;

    Col_size * head_col_count = (Col_size *) malloc(sizeof(Col_size));
    head_col_count->next = NULL;
    Node * head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    do
    {
        input = getch();
        if (224 == input)
        {
            input = getch();
            control_extended_keys(input, &col, &row, max_col, max_row, head_col_count);
        }
        else
        {
            if (8 == input)
            {
                remove_node(&col, &row, &max_col, &max_row, head);
                print_char(head, col, row, 1);
            }
            else
            {

                push(head, input, &max_col, &max_row, &col, &row, head_col_count);
                print_char(head, col, row, 0);
            }
        }

        gotoxy(50,20);
        printf("col: %d row: %d\n", col, row);
        printf("max_col: %d max_row: %d\n", max_col, max_row);
        gotoxy(col,row);
    }
    while(27 != input);

    print_all(head);
    return 0;
}
void push(Node * head, int val, int * max_col, int * max_row, int *col, int * row, Col_size * head_col_count)
{
    if (13 == val)
    {
        Col_size * current_col_count = head_col_count;
        while (current_col_count->row_num != *row && current_col_count->next != NULL)
        {
            current_col_count = current_col_count->next;
        }
        current_col_count->next = (Col_size *) malloc(sizeof(Col_size));
        current_col_count->next->size = *col;
        current_col_count->next->row_num = *row;
        current_col_count->next->next= NULL;

        *max_row += 1;
        *row += 1;
        *col = 0;
        val = '\n';
    }
    else
    {
        *col += 1;
    }
    Node * current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    // now we can add a new variable
    current->next = (Node *) malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;

    *max_col = *col > *max_col? *col: *max_col;
}
void print_char(Node * head, int col, int row, int is_all)
{
    Node * current = head;
    system("cls");
    while (current->next != NULL)
    {
        current = current->next;
        printf("%c", current->val);
    }

}
void print_all(Node * head)
{
    system("cls");
    Node * current = head;
    while (current->next != NULL)
    {


        current = current->next;
        printf("%c", current->val);
    }

}
int get_col_size(int row, Col_size * head_col_size)
{
    Col_size * current = head_col_size;
    while(current->row_num != row && current->next != NULL)
    {
        current = current->next;
    }
    return current->size;
}
void control_extended_keys(int input, int *col, int *row, int max_col, int max_row, Col_size * head_col_size)
{
    // 72 up arrow
    if (72 == input && 0 < *row)
    {
        *row -= 1;
        *col = get_col_size(*row, head_col_size);
        gotoxy(*col, *row);
    }
    else if (80 == input && *row < max_row)// 80 down arrow
    {
        *row += 1;
        *col = get_col_size(*row, head_col_size);
        gotoxy(*col, *row);
    }
    else if (77 == input && *col < max_col)// 77 right arrow
    {
        *col += 1;
        gotoxy(*col, *row);
    }
    else if (75 == input && 0 < *col)     // 75 left arrow
    {
        *col -= 1;
        gotoxy(*col, *row);
    }
    else if (71 == input)
    {
        // 71 == home key go to first element
        *col = 0;
        *row = 0;
        gotoxy(*col, *row);
    }
    else if(82 == input)
    {
        // 82 == insert key go last element
        *col = max_col;
        *row = max_row;
        gotoxy(*col, *row);
    }
}
void remove_node(int * col, int * row, int * max_col, int * max_row, Node * head)
{
    // this function will remove last element
    Node * end = head;
    Node * prev = NULL;
    Node * prev_prev = prev;
    while(end->next != NULL)
    {
        prev_prev = prev;
        prev = end;
        end = end->next;
    }

    prev->next = NULL;

    *col -= 1;
    free(end);
    // to remove the character and th new line to move the cursor up
    if(prev->val == '\n')
    {
        prev_prev->next = NULL;
        free(prev);
        *row -= 1;
        *max_row -= 1;
    }
    gotoxy(*col, *row);
}
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}





