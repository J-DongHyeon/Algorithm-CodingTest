#include <stdio.h>

int main(void)
{
    int i, j, num, arr[10001] = {0, }, test, part[5000][2], idx;
    arr[0] = arr[1] = 1;
    for (i=2; i<10001; i++)
    {
        if (arr[i] == 0)
        {
            for (j=i+i; j<10001; j+=i) arr[j] = 1;
        }
    }    
    scanf("%d", &test);
    for (i=0; i<test; i++)
    {
        scanf("%d", &num);
        idx = 0;
        for (j=2; j<=num/2; j++)
        {
            if (arr[j] == 0 && arr[num-j] == 0)
            {
                part[idx][0] = j;
                part[idx++][1] = num - j;
            }
        }
        if (idx > 1)
        {
            int sub = part[0][1] - part[0][0];
            int sub_idx = 0;
            for (j=1; j<idx; j++)
            {
                if (sub > part[j][1] - part[j][0])
                {
                    sub = part[j][1] - part[j][0];
                    sub_idx = j;
                }
            }
            printf("%d %d\n", part[sub_idx][0], part[sub_idx][1]);
        } else
        {
            printf("%d %d\n", part[0][0], part[0][1]);
        }
    }
}