#include <stdio.h>

int main(void)
{
    int num, x, i;
    scanf("%d %d", &num, &x);
    int arr[num];
    for(i=0; i<num; i++) scanf("%d", &arr[i]);
    
    for(i=0; i<num; i++)
    {
        if(x > arr[i]) printf("%d ", arr[i]);
    }
}