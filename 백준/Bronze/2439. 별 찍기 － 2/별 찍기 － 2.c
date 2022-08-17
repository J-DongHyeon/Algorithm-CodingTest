#include <stdio.h>

int main(void)
{
    int num, i, j, k;
    scanf("%d", &num);
    while(num < 1 || num > 100) scanf("%d", &num);
    
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if (j < num-i-1) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
}