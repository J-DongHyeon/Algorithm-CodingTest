#include <stdio.h>
#include <string.h>

int sorted_age[100000];
char sorted_name[100000][101];

void merge(int*, char[][101], int, int);
void merge_sort(int*, char[][101], int, int, int);

int main(void)
{
    int num, i;
    scanf("%d", &num);
    int arr_age[num];
    char arr_name[num][101];
    for (i=0; i<num; i++) scanf("%d %s", &arr_age[i], arr_name[i]);
    merge(arr_age, arr_name, 0, num-1);
    for (i=0; i<num; i++) printf("%d %s\n", arr_age[i], arr_name[i]);
}

void merge(int* arr_age, char arr_name[][101], int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (left + right) / 2;
        merge(arr_age, arr_name, left, mid);
        merge(arr_age, arr_name, mid+1, right);
        merge_sort(arr_age, arr_name, left, mid, right);
    }
}

void merge_sort(int* arr_age, char arr_name[][101], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (arr_age[i] <= arr_age[j])
        {
            sorted_age[k] = arr_age[i];
            strcpy(sorted_name[k++], arr_name[i++]);
        } else {
            sorted_age[k] = arr_age[j];
            strcpy(sorted_name[k++], arr_name[j++]);
        }
    }
    if (i > mid)    
        for (l=j; l<=right; l++)
        {
            sorted_age[k] = arr_age[l];
            strcpy(sorted_name[k++], arr_name[l]);   
        }        
    else
        for (l=i; l<=mid; l++)
        {
            sorted_age[k] = arr_age[l];
            strcpy(sorted_name[k++], arr_name[l]);   
        }  
    for (l=left; l<=right; l++)
    {
        arr_age[l] = sorted_age[l];
        strcpy(arr_name[l], sorted_name[l]);
    }
}