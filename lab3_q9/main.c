#include <stdio.h>
#include <stdlib.h>
//C Program to count number of Alphabets & number of words in a sentence. (word count)

int main()
{
    char input;
    int toggle = 0;
    int word_counter = 0;
    int alphabet_counter = 0;

    printf("Enter a sentence: ");
    while(10 != input)
    {
        scanf("%c", &input);
        // make sure input is a char, then count char
        if (((input >= 65 && input <= 90) || (input >= 97 && input <= 122)))
        {
            alphabet_counter++;
            toggle = 1;

        }else if (32 == input && 1 == toggle){// count words after space and make sure spaces are not spamed
            word_counter++;
            toggle = 0;
        }else if (10 == input && 1 == toggle){ // count last word
            word_counter++;
        }

    }
    printf("Number of words: %d, Number of characters: %d\n", word_counter, alphabet_counter);
    return 0;
}
