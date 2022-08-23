#include <stdio.h>
#include <math.h>

int main(void)
{
    int num, i, j, res, arr[246913] = {0, };
    arr[0] = arr[1] = 1;
    for (i=2; i<246913; i++)
    {
        if (arr[i] == 0)
        {
            for (j=i+i; j<246913; j+=i) arr[j] = 1;
        }
    }            
    while(1)
    {
        scanf("%d", &num);
        if (num == 0) break;
        res = 0;
        for (i=num+1; i<=2*num; i++)
        {
            if (arr[i] == 0) res++;
        }
        printf("%d\n", res);
    }
}