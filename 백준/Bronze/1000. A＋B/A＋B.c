#include <stdio.h>

int main(void)
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    while(a <= 0) scanf("%d", &a);
    while(b >= 10) scanf("%d", &b);
    
    printf("%d", a+b);
    
    return 0;
}