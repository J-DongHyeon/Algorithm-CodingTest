#include <stdio.h>

int cnt(int);

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d", cnt(num));
}

int cnt(int num)
{
    if(num < 100) return num;
    else if (100 <= num <= 1000)
    {
        int a, b, c, sub1, sub2, i, res;
        res = 99;
        for (i=100; i<=num; i++)
        {
            if (i == 1000) break;
            a = i / 100;
            b = (i % 100) / 10;
            c = i % 10;
            sub1 = b-a;
            sub2 = c-b;
            if (sub1 == sub2) res++;
        }
        return res; 
    }
}