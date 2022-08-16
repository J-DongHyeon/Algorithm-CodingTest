#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 11

int main(void)
{
    char buf[N];
    char* sorted;
    int len, cnt[10] = {0, }, i;
    scanf("%s", buf);
    len = strlen(buf);
    sorted = (char*) malloc(len+1);
    for (i=0; i<len; i++) cnt[buf[i] - '0']++;
    for (i=8; i>=0; i--) cnt[i] += cnt[i+1];
    for (i=0; i<len; i++) 
    {
        sorted[cnt[buf[i] - '0'] - 1] = buf[i];
        cnt[buf[i] - '0']--;
    }
    sorted[i] = '\0';
    printf("%s", sorted);
}