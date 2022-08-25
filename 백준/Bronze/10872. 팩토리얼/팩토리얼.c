#include <stdio.h>

int fac(int );

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", fac(n));
}

int fac(int num)
{
    if (num <= 1) return 1;
    else return num * fac(num-1);
}