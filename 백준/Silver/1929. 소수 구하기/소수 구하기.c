#include <stdio.h>
#include <math.h>

int main(void)
{
    int up, down, i, j, ck, res;
    scanf("%d %d", &down, &up);
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
        if (ck == 0 && i != 1)
        {
            printf("%d\n", i);
        }
    }
}