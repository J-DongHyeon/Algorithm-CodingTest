#include <stdio.h>
#include <math.h>

int main(void)
{
    int num, res, i, ck;
    scanf("%d", &num);
    if (num == 1) return 0;
    while(1)
    {
        ck = 0;
        for (i=2; i<=sqrt(num); i++)
        {
            if (num % i == 0)
            {
                ck = 1;
                printf("%d\n", i);
                num /= i;
                break;
            }
        }
        if (ck == 0)
        {
            printf("%d", num);
            break;
        }
    }
}