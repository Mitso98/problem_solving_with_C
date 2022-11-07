#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char val;
    struct node * next;
} Node;
void push(Node * head, char val);
int main()
{
    char input;
    Node * head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    do{
        scanf("%c",  &input);
        push(head, input);

    }while(10 != input);

    while (head->next != NULL) {
        head = head->next;
        printf("%c", head->val);
    }
    return 0;
}
void push(Node * head, char val) {

    Node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // now we can add a new variable
    current->next = (Node *) malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;
}





