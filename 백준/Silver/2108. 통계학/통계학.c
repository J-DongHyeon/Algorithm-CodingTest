#include <stdio.h>
#include <math.h>

int main(void)
{
    int num, i, cnt[8001] ={0, }, ck = 0;
    int avg, sub1, sub2, sub3, max = 0;
    double sum = 0;
    scanf("%d", &num);
    int arr[num], sorted[num];
    for (i=0; i<num; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (int) floor((sum / num) + 0.5);
    for (i=0; i<num; i++) cnt[arr[i] + 4000]++;    
    for (i=0; i<8001; i++) 
    {
        if (max < cnt[i]) 
        {
            max = cnt[i];
            ck = 1;
            sub2 = i - 4000;
        } else if (max == cnt[i] && ck == 1)
        {
            ck = 2;
            sub2 = i - 4000;
        }
    }
    for (i=1; i<8001; i++) cnt[i] += cnt[i-1];
    for (i=0; i<num; i++)
    {
        sorted[cnt[arr[i] + 4000] - 1] = arr[i];
        cnt[arr[i] + 4000]--;
    }
    sub1 = sorted[num / 2];
    sub3 = sorted[num-1] - sorted[0];
    printf("%d\n%d\n%d\n%d", avg, sub1, sub2, sub3);
}