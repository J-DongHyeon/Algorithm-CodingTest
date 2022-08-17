#include <stdio.h>
#include <string.h>

char sorted[20000][51];

void merge(char [][51], int, int);
void merge_sort(char [][51], int, int, int);

int main(void)
{
    int num, i;
    scanf("%d", &num);
    char arr[num][51];
    for (i=0; i<num; i++) scanf("%s", arr[i]);
    merge(arr, 0, num-1);
    for (i=0; i<num; i++) 
    {
        if (strlen(arr[i]) == 0) continue;
        else printf("%s\n", arr[i]);
    }
}

void merge(char arr[][51], int left, int right)
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

void merge_sort(char arr[][51], int left, int mid, int right)
{
    int i, j, k, l, len_1, len_2;
    i = left;
    j = mid + 1;
    k = left;    
    while (i <= mid && j <= right)
    {
        len_1 = strlen(arr[i]);
        len_2 = strlen(arr[j]);
        if (len_1 == len_2)
        {
            for (l=0; l<len_1; l++)
            {
                if (arr[i][l] == arr[j][l]) continue;
                else if (arr[i][l] > arr[j][l])
                {
                    strcpy(sorted[k++], arr[j++]);
                    break;
                } else {
                    strcpy(sorted[k++], arr[i++]);
                    break;
                }
            }
            if (l == len_1)
            {
                strcpy(sorted[k], arr[i]);
                sorted[k+1][0] = '\0';
                i++; j++; k += 2;
            }
        }
        else if (len_1 > len_2) strcpy(sorted[k++], arr[j++]);
        else strcpy(sorted[k++], arr[i++]);
    }
    if (i > mid)
    {
        for (l=j; l<=right; l++) strcpy(sorted[k++], arr[l]);
    } else {
        for (l=i; l<=mid; l++) strcpy(sorted[k++], arr[l]);
    }
    for (l=left; l<=right; l++) strcpy(arr[l], sorted[l]);
}