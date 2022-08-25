#include <stdio.h>

void fun(int, int, int);

int main(void)
{
    int num, i, j;
    scanf("%d", &num);
    for (i=0; i<num; i++)
    {
        for (j=0; j<num; j++) fun(i, j, num);
        printf("\n");
    }
}

void fun(int i, int j, int num)
{
    if ((i/num)%3 == 1 && (j/num)%3 == 1) printf(" ");
    else 
    {
        if (num == 1) printf("*");
        else fun(i, j, num/3);
    }
}