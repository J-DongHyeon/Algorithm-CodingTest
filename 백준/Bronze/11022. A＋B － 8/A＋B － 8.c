#include <stdio.h>

int main(void)
{
    int num, i;
    scanf("%d", &num);
    int res[num][3];
    for(i=0; i<num; i++)
    {
        scanf("%d %d", &res[i][0], &res[i][1]);
        while(res[i][0] <= 0 || res[i][0] >= 10) scanf("%d", &res[i][0]);
        while(res[i][1] <= 0 || res[i][1] >= 10) scanf("%d", &res[i][1]);
        res[i][2] = res[i][0] + res[i][1];
    }
    for(i=0; i<num; i++)
    {
        printf("Case #%d: %d + %d = %d\n", i+1, res[i][0], res[i][1], res[i][2]);
    }
}