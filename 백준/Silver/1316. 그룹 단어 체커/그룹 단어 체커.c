#include <stdio.h>
#include <string.h>

int main(void)
{
    int num, i, j, k, len, ck, res;
    res = 0;
    char str[101], buf;
    scanf("%d", &num);
    for (i=0; i<num; i++)
    {
        ck = 0;
        scanf("%s", str);
        len = strlen(str);
        for (j=0; j<len; j++)
        {
            buf = str[j];
            while (buf == str[j+1]) j++;            
            for (k=j+1; k<len; k++)
            {
                if (buf == str[k])
                {
                    ck = 1;
                    break;
                }
            }
            if (ck == 1) break;            
        }
        if (ck == 0) res++;
    }
    
    printf("%d", res);
}