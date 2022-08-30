#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quickSort(char* [21], int, int);
int partition(char* [21], int, int, int);
int compare(const void*, const void*);

int main(void)
{
    int hear, see, i, idx = 0;
    scanf("%d %d", &hear, &see);
    int* res = (int*)malloc(hear * sizeof(int));
    char** strs = (char**)malloc(hear * sizeof(char*));
    char* buf = (char*)malloc(21);
    for (i = 0; i < hear; i++)
    {
        strs[i] = (char*)malloc(21);
        scanf("%s", strs[i]);        
    }
    quickSort(strs, 0, hear - 1);
    
    for (i = 0; i < see; i++)
    {
        scanf("%s", buf);
        int left = 0, right = hear - 1, mid;        
        while (right >= left)
        {
            mid = (left + right) / 2;
            if (strcmp(buf, strs[mid]) == 0)
            {
                res[idx++] = mid;                
                break;
            }
            else if (strcmp(buf, strs[mid]) > 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    qsort(res, idx, sizeof(int), compare);

    printf("%d\n", idx);
    for (i = 0; i < idx; i++)
        printf("%s\n", strs[res[i]]);
}

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 > num2)
        return 1;
    else if (num2 > num1)
        return -1;
    else
        return 0;
}

void quickSort(char* strs[21], int left, int right)
{
    if (right > left)
    {
        int mid = (left + right) / 2;
        int pivot = partition(strs, left, mid, right);
        quickSort(strs, left, pivot - 1);
        quickSort(strs, pivot + 1, right);
    }
}

int partition(char* strs[21], int left, int mid, int right)
{
    int pivot, i;
    pivot = left;
    char* sub = strs[mid];
    strs[mid] = strs[pivot];
    strs[pivot] = sub;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(strs[left], strs[i]) > 0)
        {
            pivot++;
            sub = strs[i];
            strs[i] = strs[pivot];
            strs[pivot] = sub;
        }
    }
    sub = strs[pivot];
    strs[pivot] = strs[left];
    strs[left] = sub;
    return pivot;
}