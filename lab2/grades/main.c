#include <stdio.h>
#include <stdlib.h>
/*
    Write a program that reads a student grade percentage and prints "Excellent"
    if his grade is greater than or equal 85,
    "Very Good" for 75 or greater; "Good" for 65,
    "Pass" for 50, "Fail" for less than 50
*/
int main()
{
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if (score >= 85 && score <= 100){
        printf("Excelent");
    }
    else if (score >= 75 && score < 85){
        printf("Very Good");
    }
    else if (score >= 65 && score < 75){
        printf("Good");
    }
    else if (score >= 50 && score < 65){
        printf("Pass");
    }
    else{
        printf("Fail");
    }
    return 0;
}
