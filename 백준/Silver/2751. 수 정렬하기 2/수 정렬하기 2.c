#include <stdio.h>

int sorted[1000000];
void merge(int*, int, int, int);
void merge_sort(int*, int, int);

int main(void)
{
    int num, i;
    scanf("%d", &num);
    int nums[num];
    for (i=0; i<num; i++) scanf("%d", &nums[i]);
    merge_sort(nums, 0, num-1);
    for (i=0; i<num; i++) printf("%d\n", nums[i]);
}

void merge(int nums[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;
    while (i<=mid && j<=right)
    {
        if (nums[i] <= nums[j]) sorted[k++] = nums[i++];
        else sorted[k++] = nums[j++];
    }
    if (i>mid)
        for (l=j; l<=right; l++) sorted[k++] = nums[l];
    else
        for (l=i; l<=mid; l++) sorted[k++] = nums[l];
    for (l=left; l<=right; l++) nums[l] = sorted[l];
}

void merge_sort(int nums[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
}