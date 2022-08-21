#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[101];
    int len, arr[26], i;
    for (i=0; i<26; i++) arr[i] = -1;
    scanf("%s", buf);
    len = strlen(buf);
    for (i=0; i<len; i++)
    {
        if (arr[buf[i] - 'a'] == -1) arr[buf[i] - 'a'] = i;
    }
    
    for (i=0; i<26; i++) printf("%d ", arr[i]);
}