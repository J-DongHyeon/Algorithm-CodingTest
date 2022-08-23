#include <stdio.h>
#include <math.h>

int main(void)
{
    int num, sub, res = 0, i, j, ck;
    scanf("%d", &num);
    for (i=0; i<num; i++) 
    {
        scanf("%d", &sub);
        ck = 0;
        for (j=2; j<=sqrt(sub); j++)
        {
            if (sub % j == 0) 
            {
                ck = 1;
                break;
            }
        }
        if (sub != 1 && ck == 0) res++;
    }
    printf("%d", res);
}