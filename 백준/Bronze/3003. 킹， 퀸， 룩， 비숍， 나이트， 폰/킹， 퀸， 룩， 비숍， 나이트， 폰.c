#include <stdio.h>

int main(void)
{
    int chess[] = {1, 1, 2, 2, 2, 8};
    int num, i;
    for (i=0; i<6; i++)
    {
        scanf("%d", &num);
        printf("%d ", chess[i] - num);
    }
}