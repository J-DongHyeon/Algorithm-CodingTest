#include <stdio.h>

int main(void)
{
    int num, i, j, x, temp;
    scanf("%d", &num);
    int nums[num];
    for (i=0; i<num; i++) scanf("%d", &nums[i]);
    for (i=0; i<num-1; i++)
    {
        x = i;
        for (j=i+1; j<num; j++)
            if (nums[x] > nums[j]) x = j;
        temp = nums[i];
        nums[i] = nums[x];
        nums[x] = temp;
    }
    for (i=0; i<num; i++) printf("%d\n", nums[i]);
}