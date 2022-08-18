#include <stdio.h>

int main(void)
{
    int num, i, max, min;
    scanf("%d", &num);
    int arr[num];
    
    for(i=0; i<num; i++) scanf("%d", &arr[i]);
    max = min = arr[0];
    for(i=0; i<num; i++)
    {
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];
    }
    
    printf("%d %d", min, max);
}