#include <stdio.h>

int main(void)
{
    int arr[9], i, max, idx;
    for(i=0; i<9; i++) scanf("%d", &arr[i]);
    max = arr[0];
    idx = 0;
    for(i=0; i<9; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            idx = i;
        }
    }
    
    printf("%d\n%d", max, idx+1);
    
}