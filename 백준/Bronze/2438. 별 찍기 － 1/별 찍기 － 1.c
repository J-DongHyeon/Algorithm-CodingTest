#include <stdio.h>

int main(void)
{
    int num, i, j;
    scanf("%d", &num);
    while(num < 1 || num > 100) scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}