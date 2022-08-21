#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[4], b[4], buf1[4], buf2[4];
    int i, a_i, b_i;
    scanf("%s %s", a, b);
    for (i=0; i<3; i++)
    {
        buf1[i] = a[2-i];
        buf2[i] = b[2-i];
    }
    a_i = atoi(buf1);
    b_i = atoi(buf2);
    if (a_i > b_i) printf("%d", a_i);
    else printf("%d", b_i);
}