#include <stdio.h>

int people(int, int);

int main(void) 
{
    int test, i, lv, ho;
    scanf("%d", &test);
    int res[test];
    for (i=0; i<test; i++)
    {
        scanf("%d", &lv);
        scanf("%d", &ho);
        res[i] = people(lv, ho);
    }
    
    for (i=0; i<test; i++) printf("%d\n", res[i]);
}

int people(int lv, int ho)
{
    int i, sum = 0;
    if (lv == 0) return ho;
    else 
    {
        for (i=ho; i>=1; i--) sum += people(lv-1, i);
        return sum;
    }
}

