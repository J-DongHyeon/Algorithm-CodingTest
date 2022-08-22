#include <stdio.h>

int main(void)
{
    int a, b, c, sub;
    scanf("%d %d %d", &a, &b, &c);
    if (b >= c) printf("%d", -1);
    else 
    {
        sub = c - b;
        printf("%d", a/sub + 1);
    }
}