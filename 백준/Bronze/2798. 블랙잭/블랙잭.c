#include <stdio.h>

int main(void)
{
    int num, score, i, j, k, res = 0;
    scanf("%d %d", &num, &score);
    int scores[num], sub;
    for (i=0; i<num; i++) scanf("%d", &scores[i]);
    for (i=0; i<num-2; i++)
    {
        for (j=i+1; j<num-1; j++)
        {
            sub = scores[i] + scores[j];
            for (k=j+1; k<num; k++)
            {
                if (sub + scores[k] <= score && (score-res) > (score-(sub+scores[k])))
                    res = sub + scores[k];
            }
        }
    }
    printf("%d", res);
}