#include <stdio.h>

int main(void)
{
    int num, i, sub = 0;
    scanf("%d", &num);
    for (i=1; i<num; i++)
    {
        sub = (i%10) + (i%100/10) + (i%1000/100) + (i%10000/1000) + (i%100000/10000) + (i%1000000/100000);
        sub += i;
        if (sub == num) break;
        sub = 0;
    }
    if (sub == 0) printf("%d", 0);
    else printf("%d", i);    
}