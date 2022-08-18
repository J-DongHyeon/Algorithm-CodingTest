#include <stdio.h>

int sorted[1000000];

void merge(int*, int, int);
void merge_sort(int*, int, int, int);

int main(void)
{
    int num, i, j;
    scanf("%d", &num);
    int arr[num], origin[num], arr_press[num], origin_press[num];
    for (i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
        origin[i] = arr[i];
        arr_press[i] = 0;
        origin_press[i] = 0;
    }
    merge(arr, 0, num-1);
    
    int cnt = 0;
    for (i=0; i<num; i++)
    {
        if (i != 0 && arr[i-1] == arr[i]) cnt++;
        arr_press[i] = i - cnt;
    }
    
    for (i=0; i<num; i++)
    {
        int low = 0, high = num-1, mid;
        while (high >= low)
        {
            mid = (low + high) / 2;
            if (origin[i] == arr[mid]) 
            {
                origin_press[i] = arr_press[mid];
                break;
            }
            else if (origin[i] > arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        printf("%d ", origin_press[i]);
    }
}

void merge(int* arr, int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (left + right) / 2;
        merge(arr, left, mid);
        merge(arr, mid+1, right);
        merge_sort(arr, left, mid, right);
    }
}

void merge_sort(int* arr, int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j]) sorted[k++] = arr[j++];
        else sorted[k++] = arr[i++];
    }
    if (i > mid)     
        for (l=j; l<=right; l++) sorted[k++] = arr[l];
    else
        for (l=i; l<=mid; l++) sorted[k++] = arr[l];
    for (l=left; l<=right; l++) arr[l] = sorted[l];
}