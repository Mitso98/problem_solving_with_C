#include <stdio.h>
#include <stdlib.h>
#define SIZE 45
//4) C Program to Find the Frequency of Characters in a String
int get_input(char arr[]);
void find_similarity(int, char arr[]);

int main()
{
    char arr[SIZE];
    // store input length. take input from user then store it at arr.
    int length = get_input(arr);
    // find similar chars
    find_similarity(length, arr);

    return 0;
}

int get_input(char arr[])
{
    int counter = 0;
    char input;

    printf("Enter a string: ");
    do
    {
        //get character by character from user
        scanf("%c", &input);
        //make sure to insert only alphabets
        if(10 != input && ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)))
        {
            arr[counter] = input;
            counter++;
        }
    }
    while(10 != (int) input && SIZE > counter);//exit if enter is pressed or user entered more than 99 char

    //show warning if user entered more than 45 chars
    if (counter == SIZE)
    {
        printf("you exceeded the limit, the program will only count first 45 similar chars.");
    }
    return counter;
}
void find_similarity(int counter, char arr[])
{
    // counter for identical values
    int same = 0;
    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            if ((int)arr[i] == (int)arr[j])
            {
                same++;
            }
        }
    }
    printf("Number of repeated char is: %d", same);
}
