#include <stdio.h>

int main(void)
{
    int num, i, lv, ck, den, mol;
    lv = 1;
    ck = 1;
    scanf("%d", &num);
    if (num == 1) 
    {
        printf("1/1");
        return 0;
    }
    for (i=1; ;i++)
    {
        if (num >= (ck + i)) 
        {
            ck += i;
            lv++;
        } else break;
    }
    if (lv % 2 == 0)
    {
        den = 1 + (num - ck);
        mol = lv - (num - ck);
    } else 
    {
        den = lv - (num - ck);
        mol = 1 + (num - ck);
    }
    
    printf("%d/%d", den, mol);
}