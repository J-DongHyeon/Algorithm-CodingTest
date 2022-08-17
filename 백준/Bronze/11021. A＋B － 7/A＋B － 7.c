#include <stdio.h>

int main(void)
{
    int num, a, b, i;
    scanf("%d", &num);
    int res[num];
    
    for(i=0; i<num; i++)
    {
        scanf("%d %d", &a, &b);
        while(a <= 0 || a >= 10) scanf("%d", &a);
        while(b <= 0 || b >= 10) scanf("%d", &b);
        res[i] = a+b;
    }
    
    for(i=1; i<=num; i++)
    {
        printf("Case #%d: %d\n", i, res[i-1]);
    }
}