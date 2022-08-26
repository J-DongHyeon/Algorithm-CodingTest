#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(char* [501], int, int);
int partition(char* [501], int, int);

int main(void)
{
    int num, cmp, i, res = 0;
    scanf("%d %d", &num, &cmp);
    char** strs = (char**) malloc(sizeof(char*) * num);
    for (i = 0; i < num; i++)
    {
        strs[i] = (char*) malloc(501);
        scanf("%s", strs[i]);
    }
    quickSort(strs, 0, num - 1);

    char* buf = (char*)malloc(501);
    for (i = 0; i < cmp; i++)
    {
        scanf("%s", buf);
        int low = 0, high = num - 1;
        while (high >= low)
        {
            int mid = (high + low) / 2;
            if (strcmp(buf, strs[mid]) == 0)
            {
                res++;
                break;
            }
            else if (strcmp(buf, strs[mid]) > 0) low = mid + 1;
            else high = mid - 1;
        }
    }
    printf("%d", res);
}

void quickSort(char* strs[501], int left, int right)
{
    if (left >= right) return;
    int pivot = partition(strs, left, right);
    quickSort(strs, left, pivot - 1);
    quickSort(strs, pivot + 1, right);
}

int partition(char* strs[501], int left, int right)
{
    int mid = (left + right) / 2;
    int i, p_idx = left;
    char* tmp;
    char* pivot = strs[mid];
    strs[mid] = strs[left];
    strs[left] = pivot;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(pivot, strs[i]) > 0)
        {
            p_idx++;
            tmp = strs[i];
            strs[i] = strs[p_idx];
            strs[p_idx] = tmp;
        }
    }
    tmp = strs[p_idx];
    strs[p_idx] = strs[left];
    strs[left] = tmp;
    return p_idx;
}
