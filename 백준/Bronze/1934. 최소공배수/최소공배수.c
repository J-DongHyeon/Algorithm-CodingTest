#include <stdio.h>

int main(void)
{
    int test, a, b, max, min, temp, i;
    scanf("%d", &test);
    for (i=0; i<test; i++)
    {
        scanf("%d %d", &a, &b);
        if (a > b)
        {
            max = a;
            min = b;
        } else {
            max = b;
            min = a;
        }
        do {
            temp = max % min;
            max = min;
            min = temp;
        } while (min != 0);
        min = (a * b) / max;
        printf("%d\n", min);
    }
}