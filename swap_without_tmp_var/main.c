#include <stdio.h>
#include <stdlib.h>
int sum(int x, int y);

int main()
{
    int x , y;
    printf("enter two numbers:  ");
    scanf("%d ", &x);
    scanf("%d", &y);

    sum(x,y);

    return 0;
}
// swap without temporary variable
int sum(int x, int y){
    x = x + y;
    y = x - y;
    x = x - y;
    printf("%d, %d", x,y);
}
