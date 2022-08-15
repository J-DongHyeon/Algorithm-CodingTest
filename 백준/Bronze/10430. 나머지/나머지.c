#include <stdio.h>

int main(void)
{
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    while(a < 2 || a > 10000) scanf("%d", &a);
    while(b < 2 || b > 10000) scanf("%d", &b);
    while(c < 2 || c > 10000) scanf("%d", &c);
    
    printf("%d\n", (a+b)%c);
    printf("%d\n", ((a%c) + (b%c))%c ) ;
    printf("%d\n", (a*b)%c);
    printf("%d\n", ((a%c) * (b%c))%c );
    
}