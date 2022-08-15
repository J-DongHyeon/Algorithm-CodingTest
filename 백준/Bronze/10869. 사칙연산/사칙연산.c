#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    while(a < 1) scanf("%d", &a);
    while(b <= 0 || b > 10000) scanf("%d", &b);
    
    printf("%d\n%d\n%d\n%d\n%d", a+b, a-b, a*b, a/b, a%b);
}