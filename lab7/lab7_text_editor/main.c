#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
// TODO fix max column and backspace bug
typedef struct node
{
    char val;
    int col_pos;
    int row_pos;
    struct node *next;
} Node;

typedef struct column_size
{
    // to store how many columns are at each row
    int row_num;
    int size;
    struct column_size *next;
} Col_size;

void push(Node *head, int val, int *max_col, int *max_row, int *col, int *row);
void print_char(Node *head);
// void print_all(Node *head);
void control_extended_keys(int input, int *col, int *row, int max_col, int max_row);
void remove_node(int *col, int *row, int *max_col, int *max_row, Node *head);
void gotoxy(int x, int y);

int main()
{
    int input;
    int col = 0;
    int row = 0;
    int max_col = 0;
    int max_row = 0;

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    do
    {
        input = getch();
        if (224 == input)
        {
            input = getch();
            control_extended_keys(input, &col, &row, max_col, max_row);
        }
        else
        {
            // 8 is the back space
            if (8 == input && 0 <= col)
            {
                remove_node(&col, &row, &max_col, &max_row, head);
                print_char(head);
            }
            else
            {
                push(head, input, &max_col, &max_row, &col, &row);
                print_char(head);
            }
        }
        gotoxy(50, 20);
        printf("col: %d row: %d\n", col, row);
        printf("max_col: %d max_row: %d\n", max_col, max_row);
        gotoxy(col, row);
    } while (27 != input);

    print_char(head);
    return 0;
}
void push(Node *head, int val, int *max_col, int *max_row, int *col, int *row)
{
    Node *current = head;
    // push to the end of the list.
    while (current->next != NULL)
    {
        current = current->next;
    }
    // instructions if new line is entered
    if (13 == val)
    {
        current->next = (Node *)malloc(sizeof(Node));
        current->next->val = '\n';
        *max_row += 1;
        *row += 1;
        current->next->row_pos = *max_row;
        *col = 0;
        current->next->col_pos = *col;
        current->next->next = NULL;
    }
    else
    {
        // instructions for any other value
        current->next = (Node *)malloc(sizeof(Node));
        current->next->val = val;
        current->next->row_pos = *max_row;
        *col += 1;
        current->next->col_pos = *col;
        current->next->next = NULL;
    }
    // increase max_col only if col exceded it
    *max_col = *col > *max_col ? *col : *max_col;
    gotoxy(*col, *row);
}
void print_char(Node *head)
{
    Node *current = head;
    system("cls");
    while (current->next != NULL)
    {
        current = current->next;
        printf("%c", current->val);
    }
}
/*

void print_all(Node *head)
{
    system("cls");
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
        printf("%c", current->val);
    }
}
*/
/*

int get_col_size(int row, Node *head)
{
    Col_size *current = head_col_size;
    while (current->row_num != row && current->next != NULL)
    {
        current = current->next;
    }
    return current->size;
}
*/
void control_extended_keys(int input, int *col, int *row, int max_col, int max_row)
{
    // 72 up arrow
    if (72 == input && 0 < *row)
    {
        *row -= 1;
        gotoxy(*col, *row);
    }
    else if (80 == input && *row < max_row) // 80 down arrow
    {
        *row += 1;
        gotoxy(*col, *row);
    }
    else if (77 == input && *col < max_col) // 77 right arrow
    {
        *col += 1;
        gotoxy(*col, *row);
    }
    else if (75 == input && 0 < *col) // 75 left arrow
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
    else if (82 == input)
    {
        // 82 == insert key go last element
        *col = max_col;
        *row = max_row;
        gotoxy(*col, *row);
    }
}
void remove_node(int *col, int *row, int *max_col, int *max_row, Node *head)
{
    if (0 == *row && 0 == *col)
    {
        return;
    }
    // this function will remove last element
    Node *end = head;
    Node *prev = NULL;
    Node *prev_prev = prev;
    while (end->next != NULL)
    {
        prev_prev = prev;
        prev = end;
        end = end->next;
    }

    prev->next = NULL;

    free(end);
    // to remove the character and th new line to move the cursor up
    *max_col = *max_col == *col ? *col - 1 : *max_col;
    if (prev->val == '\n')
    {
        prev_prev->next = NULL;
        free(prev);
        *row -= 1;
        *max_row -= 1;
        *col = prev_prev->col_pos;
    }
    else
    {

        *col -= 1;
    }
    gotoxy(*col, *row);
}

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
