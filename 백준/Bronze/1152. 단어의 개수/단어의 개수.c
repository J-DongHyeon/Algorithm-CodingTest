#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1000001];
    int i, len, ck = 0, cnt = 0;
    scanf("%[^\n]s", buf);
    len = strlen(buf);
    for(i=0; i<len; i++)
    {
        if (ck == 0 && buf[i] != ' ')
        {
            ck = 1;
            cnt++;
        }
        if (buf[i] == ' ') ck = 0;
    }
    
    printf("%d", cnt);
    
    return 0;
}