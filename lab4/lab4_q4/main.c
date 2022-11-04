#include <stdio.h>
#include <stdlib.h>
#define NAME_NO 2
#define NAME_LENGTH 50

//3) C Program to take firstName and lastName from user, then displays fullName.
int get_name(int name_position, char full_name[NAME_NO][NAME_LENGTH]);
void print_name(int counter, int counter2, char full_name[NAME_NO][NAME_LENGTH]);
int main()
{
    // array to store the full name.
    char full_name[NAME_NO][NAME_LENGTH];


    printf("Enter your first name: ");
    int counter = get_name(0, full_name);
    printf("Enter your second name: ");
    int counter2 = get_name(1, full_name);
    //print full name
    print_name(counter, counter2, full_name);

    return 0;
}
int get_name(int name_position, char full_name[NAME_NO][NAME_LENGTH])
{
    int counter = 0;
    char input;
    do
    {
        //get character by character from user
        scanf("%c", &input);
        //make sure to insert only alphabets
        if(10 != input && ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)))
        {
            full_name[name_position][counter] = input;
            counter++;
        }

    }
    while(10 != (int) input);//exit if enter is pressed

    //return array length
    return counter;
}

void print_name(int counter, int counter2, char full_name[NAME_NO][NAME_LENGTH])
{
    //print first name
    printf("Good day, ");
    for(int i = 0; i < counter; i++)
    {
        printf("%c",full_name[0][i]);
    }
    printf(" ");
    //print second name
    for(int i = 0; i < counter2; i++)
    {
        printf("%c",full_name[1][i]);
    }
}
