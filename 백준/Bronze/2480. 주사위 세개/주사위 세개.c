#include <stdio.h>

int main(void)
{
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    while(a < 1 || a > 6) scanf("%d", &a);
    while(b < 1 || b > 6) scanf("%d", &b);
    while(c < 1 || c > 6) scanf("%d", &c);
    
    if (a > b)
    {
        if (a > c) max = a;
        else max = c;
    } else if (b >= a)
    {
        if (b > c) max = b;
        else max = c;
    }
    
    if (a == b && b == c) printf("%d", 10000 + a*1000);
    else if (a == b || b == c) printf("%d", 1000 + b*100);
    else if (a == c) printf("%d", 1000 + a*100);
    else printf("%d", max*100);
    
}