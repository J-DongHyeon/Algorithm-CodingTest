#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd_fun(int, int);
int compare(const void*, const void*);

int main(void)
{
    int n, i, *data, *m, idx = 0;
    m = (int*) malloc(300 * sizeof(int));
    scanf("%d", &n);
    data = (int*) malloc(n * sizeof(int));
    for (i=0; i<n; i++)    
        scanf("%d", &data[i]);        
    qsort(data, n, sizeof(int), compare);
    int gcd = data[1] - data[0];
    for (i=2; i<n; i++)
    {
        int sub = data[i] - data[i-1];
        gcd = gcd_fun(gcd, sub);
    }
    for (i=2; i<=sqrt((double) gcd); i++)
        if (gcd % i == 0)
        {
            m[idx++] = i;
            if (i != gcd / i)
                m[idx++] = gcd / i;
        }
    qsort(m, idx, sizeof(int), compare);
    for (i=0; i<idx; i++)
        printf("%d ", m[i]);
    printf("%d", gcd);
}

int gcd_fun(int a, int b)
{
    if (b == 0)
        return 0;
    int max, min, temp;
    if (a > b)
    {
        max = a; min = b;
    }
    else
    {
        max = b; min = a;
    }      
    while (min > 0)
    {
        temp = max % min;
        max = min;
        min = temp;
    }
    return max;
}

int compare(const void* a, const void* b)
{
    int n1 = *(int*)a;
    int n2 = *(int*)b;
    if (n1 > n2)
        return 1;
    else if (n2 > n1)
        return -1;
    else
        return 0;
}