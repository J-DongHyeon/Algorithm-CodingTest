#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    while(a < -10000 || a > 10000) scanf("%d", &a);
    while(b < -10000 || b > 10000) scanf("%d", &b);
    
    if (a>b) printf(">");
    else if (a<b) printf("<");
    else printf("==");
}