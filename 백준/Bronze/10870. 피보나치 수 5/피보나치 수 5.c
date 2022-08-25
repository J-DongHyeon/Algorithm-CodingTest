#include <stdio.h>

int fibo(int );

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}

int fibo(int num)
{
    if (num <= 1) return num;
    else return fibo(num-1) + fibo(num-2);
}