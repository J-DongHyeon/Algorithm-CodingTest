#include <stdio.h>
#include <stdlib.h>

int is_self_num(int);

int main(void)
{
    int i, idx, arr[10000];    
    idx = 0;
    for (i=1; i<=10000; i++)
    {
        if (is_self_num(i)) arr[idx++] = i;
    }
    for (i=0; i<idx; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int is_self_num(int num)
{
    int i, ck;
    ck = 1;
    for (i=1; i<num; i++)
    {
        int sub;
        sub = i + (i/10000) + ((i%10000)/1000) + ((i%1000)/100) + ((i%100/10)) + (i%10);
        if (num == sub) 
        {
            ck = 0;
            break;
        }
    }
    return ck;
}