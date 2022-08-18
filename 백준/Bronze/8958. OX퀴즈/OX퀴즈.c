#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int num, i, j, cnt, res;
    cnt = 0; res = 0;
    char buf[80];
    scanf("%d", &num);
    char* arr[num];
    for(i=0; i<num; i++)
    {
        scanf("%s", buf);
        arr[i] = (char *) malloc(strlen(buf) + 1);
        strcpy(arr[i], buf);
    }
    for(i=0; i<num; i++)
    {
        for(j=0; j<strlen(arr[i]); j++)
        {
            if (arr[i][j] == 'O')
            {
                cnt++; res += cnt;
            } else
            {
                cnt = 0;
            }
        }
        printf("%d\n", res);
        cnt = 0; res = 0;
    }
    
}