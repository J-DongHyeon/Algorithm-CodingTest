#include <stdio.h>

int main(void)
{
    int len, i, max;
    double res;
    scanf("%d", &len);
    int scores[len];
    for(i=0; i<len; i++) scanf("%d", &scores[i]);
    max = scores[0];
    res = 0;
    for(i=1; i<len; i++)
    {
        if (max < scores[i]) max = scores[i];
    }
    for(i=0; i<len; i++)
    {
        res += ((double) scores[i] / max) * 100;
    }
    res /= len;
    printf("%.6lf", res);
}