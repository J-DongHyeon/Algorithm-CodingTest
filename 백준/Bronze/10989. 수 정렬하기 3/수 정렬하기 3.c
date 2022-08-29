#include <stdio.h>

int main(void)
{
    int num, i, j, count[10001]={0, }, buf;
    scanf("%d", &num);
    for (i=0; i<num; i++) 
    {
        scanf("%d", &buf);
        count[buf]++;
    }
    for (i=1; i<10001; i++)
        for (j=0; j<count[i]; j++)
            printf("%d\n", i);
}