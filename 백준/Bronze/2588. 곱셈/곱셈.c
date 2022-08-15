#include <stdio.h>

int main(void)
{
    int a, b, sub1, sub2, sub3;
    
    scanf("%d \n%d", &a, &b);
    while(a <= 0 || a > 999) scanf("%d", &a);
    while(b <= 0 || b > 999) scanf("%d", &b);
    
    sub1 = (b % 100) % 10;
    sub2 = ((b % 100) - sub1) / 10;
    sub3 = ((b - (sub2 * 10)) - sub1) / 100;
    
    printf("%d\n", sub1*a);
    printf("%d\n", sub2*a);
    printf("%d\n", sub3*a);
    printf("%d\n", a*b);
    
    return 0;
}