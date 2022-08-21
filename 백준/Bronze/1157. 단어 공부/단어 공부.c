#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1000000];
    scanf("%s", buf);
    int len, i, res[26] = {0};
    int max = 0, ck = 0, idx;
    len = strlen(buf);
    for(i=0; i<len; i++)
    {
        char sub = buf[i];
        if (sub >= 'a' && sub <= 'z') res[sub - 'a']++;
        else if (sub >= 'A' && sub <= 'Z') res[sub - 'A']++;
    }
    for(i=0; i<26; i++)
    {
        if (max < res[i])
        {
            max = res[i];
            idx = i;
        }
    }
    for(i=0; i<26; i++)
    {
        if (max == res[i]) ck++;
    }
    if (ck == 1) printf("%c", 'A' + idx);
    else printf("?");
}