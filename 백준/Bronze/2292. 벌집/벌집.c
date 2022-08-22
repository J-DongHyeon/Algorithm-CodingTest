#include <stdio.h>

int main(void)
{
    int num, i, res, ck;
    res = 1;
    ck = 1;
    scanf("%d", &num);
    for (i=0; ;i++)
    {
        if (i == 0) ck++;
        else ck += 6*i;
        if (num >= ck) res++;
        else break;
    }
    printf("%d", res);
}