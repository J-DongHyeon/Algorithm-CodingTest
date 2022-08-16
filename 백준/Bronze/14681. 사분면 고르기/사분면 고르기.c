#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("%d \n%d", &x, &y);
    while(x < -1000 || x > 1000 || x == 0) scanf("%d", &x);
    while(y < -1000 || y > 1000 || y == 0) scanf("%d", &y);
    
    if (x > 0 && y > 0) printf("1");
    else if (x < 0 && y > 0) printf("2");
    else if (x < 0 && y < 0) printf("3");
    else if (x > 0 && y < 0) printf("4");
    
}