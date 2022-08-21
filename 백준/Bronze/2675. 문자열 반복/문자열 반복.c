#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int num, repeat, i, j, k;
    char buf[21];
    scanf("%d", &num);
    char* res[num];
    
    for(i=0; i<num; i++)
    {
        scanf("%d %s", &repeat, buf);
        int len = strlen(buf);
        res[i] = (char *) malloc(len*repeat + 1);
        for (j=0; j<len; j++)
        {
            for(k=0; k<repeat; k++) res[i][repeat*j + k] = buf[j];
        }
    }
    for(i=0; i<num; i++)
    {
        printf("%s\n", res[i]);
    }
}