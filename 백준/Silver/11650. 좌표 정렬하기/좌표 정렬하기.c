#include <stdio.h>

int sorted[100000][2];
void merge_sort(int[][2], int, int, int);
void merge(int[][2], int, int);

int main(void)
{
    int num, i;
    scanf("%d", &num);
    int arr[num][2];
    for (i=0; i<num; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
    merge(arr, 0, num-1);
    for (i=0; i<num; i++) printf("%d %d\n", arr[i][0], arr[i][1]);
}

void merge_sort(int arr[][2], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i][0] == arr[j][0])
        {
            if (arr[i][1] > arr[j][1]) 
            {
                sorted[k][0] = arr[j][0];
                sorted[k++][1] = arr[j++][1];
            } else
            {
                sorted[k][0] = arr[i][0];
                sorted[k++][1] = arr[i++][1];
            }
        } else
        {
            if (arr[i][0] > arr[j][0]) 
            {
                sorted[k][0] = arr[j][0];
                sorted[k++][1] = arr[j++][1];
            } else
            {
                sorted[k][0] = arr[i][0];
                sorted[k++][1] = arr[i++][1];
            }
        }
    }    
    if (i > mid)
        for (l=j; l<=right; l++) 
        {
            sorted[k][0] = arr[l][0];
            sorted[k++][1] = arr[l][1];
        }
    else
        for (l=i; l<=mid; l++) 
        {
            sorted[k][0] = arr[l][0];
            sorted[k++][1] = arr[l][1];
        }
    for (l=left; l<=right; l++)
    {
        arr[l][0] = sorted[l][0];
        arr[l][1] = sorted[l][1];
    }
}

void merge(int arr[][2], int left, int right)
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