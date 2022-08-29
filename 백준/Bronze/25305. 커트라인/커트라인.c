#include <stdio.h>

void counting_sort(int*, int);

int main(void)
{
    int men, men_cut, i;
    scanf("%d %d", &men, &men_cut);
    int scores[men];
    for (i=0; i<men; i++) scanf("%d", &scores[i]);
    counting_sort(scores, men);
    printf("%d", scores[men_cut - 1]);
}

void counting_sort(int* scores, int men)
{
    int count[10001] = {0, }, i;
    int sorted[men];
    for (i=0; i<men; i++) count[scores[i]]++;
    for (i=9999; i>=0; i--) count[i] += count[i+1];
    for (i=0; i<men; i++) 
    {
        sorted[count[scores[i]] - 1] = scores[i];
        count[scores[i]]--;
    }
    for (i=0; i<men; i++) scores[i] = sorted[i];
}