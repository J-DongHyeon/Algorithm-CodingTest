#include <stdio.h>
#include <math.h>

void fun(int, int, int);

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d\n", ((int) pow(2, num)) - 1);
    fun(num, 1, 3);
}

void fun(int lv, int from, int to)
{
    int sub;
    if (from < 3 && to < 3) sub = 3;
    else if (from > 1 && to > 1) sub = 1;
    else sub = 2;
    
    if (lv == 1)
    {
        printf("%d %d\n", from, to);
    } else 
    {
        fun(lv-1, from, sub);
        printf("%d %d\n", from, to);
        fun(lv-1, sub, to);
    }
}