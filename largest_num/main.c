#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length;
    printf("Enter length: ");
    scanf("%d", &length);

    int nums[20];
    int largest = 0;

    //fill the array
    for (int i = 0; i < length; i++){
        printf("Enter number: ");
        scanf("%d", &nums[i]);
    }

    // linear search for largest
    for (int i = 0; i < length; i++){
        if (largest < nums[i]){
            largest = nums[i];
        }
    }

    printf("Largest Number Is: %d", largest);
    return 0;
}
