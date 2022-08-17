#include <stdio.h>

int main(void)
{
    int num, a, b, i;
    scanf("%d", &num);
    
    while(num < 0 || num > 1000000) scanf("%d", &num);
    
    int res[num];
    
    for(i=0; i<num; i++)
    {
        scanf("%d %d", &a, &b);
        res[i] = a+b;
    }
    
    for(i=0; i<num; i++)
    {
        printf("%d\n", res[i]);    
    }
    
}