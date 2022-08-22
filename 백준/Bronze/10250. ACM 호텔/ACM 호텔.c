#include <stdio.h>

int main(void)
{
    int test, i, h, w, num, den, mol;
    scanf("%d", &test);
    int res[test];
    for (i=0; i<test; i++)
    {
        scanf("%d %d %d", &h, &w, &num);
        den = num / h;
        mol = num % h;
        if (mol == 0) 
        {
            den--;
            mol = h;
        }
        res[i] = (mol*100) + (den+1);
    }
        for (i=0; i<test; i++) printf("%d\n", res[i]);
}