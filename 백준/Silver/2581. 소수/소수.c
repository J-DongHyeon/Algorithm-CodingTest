#include <stdio.h>
#include <math.h>

int main(void)
{
    int up, down, i, j, min_val, sum = 0, ck;
    scanf("%d", &down);
    scanf("%d", &up);
    for (i=down; i<=up; i++)
    {
        ck = 0;
        for (j=2; j<=sqrt(i); j++)
        {
            if (i % j == 0)
            {
                ck = 1;
                break;
            }
        }
        if (i != 1 && ck == 0)
        {
            if (sum == 0) min_val = i;
            sum += i;
        }
    }
    if (sum == 0) printf("%d", -1);
    else printf("%d\n%d", sum, min_val);
}