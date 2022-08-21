#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[16];
    int len, i, res;
    res = 0;
    scanf("%s", buf);
    len = strlen(buf);
    for (i=0; i<len; i++)
    {
        if ('A' <= buf[i] && 'C' >= buf[i]) res += 3;
        else if ('D' <= buf[i] && 'F' >= buf[i]) res += 4;
        else if ('G' <= buf[i] && 'I' >= buf[i]) res += 5;
        else if ('J' <= buf[i] && 'L' >= buf[i]) res += 6;
        else if ('M' <= buf[i] && 'O' >= buf[i]) res += 7;
        else if ('P' <= buf[i] && 'S' >= buf[i]) res += 8;
        else if ('T' <= buf[i] && 'V' >= buf[i]) res += 9;
        else if ('W' <= buf[i] && 'Z' >= buf[i]) res += 10;
    }
    printf("%d", res);
}