#include <stdio.h>

int main(void)
{
    int cmp, num, i, buf1, buf2, sum = 0;
    scanf("%d", &cmp);
    scanf("%d", &num);
    for (i=0; i<num; i++)
    {
        scanf("%d %d", &buf1, &buf2);
        sum += buf1 * buf2;
    }
    if (sum == cmp) printf("Yes");
    else printf("No");
}