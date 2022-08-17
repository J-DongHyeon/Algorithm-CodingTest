#include <stdio.h>

int main(void)
{
    int num, sum, i;
    scanf("%d", &num);
    while(num < 1 || num > 10000) scanf("%d", &num);
    
    sum = 0;
    for(i=1; i<=num; i++)
    {
        sum += i;
    }
    
    printf("%d", sum);
}