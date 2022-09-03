#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, i, max, min;
    scanf("%d", &num);
    int* data = (int*) malloc(num * sizeof(int));    
    for (i=0; i<num; i++)
        scanf("%d", &data[i]);
    max = min = data[0];
    for (i=1; i<num; i++)
    {
        if (max < data[i])
            max = data[i];
        if (min > data[i])
            min = data[i];
    }
    printf("%d", max*min);
}