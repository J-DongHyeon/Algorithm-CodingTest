#include <stdio.h>

int main(void) 
{
    int prime, num, sub, cnt, ones_1, ones_2;
    scanf("%d", &prime);
    sub = prime;
    num = -1;
    cnt = 0;
    
    while(prime != num)
    {
        cnt++;
        if(sub < 10) 
        {
            sub = (sub*10) + sub;
        } else
        {
            ones_1 = sub % 10;
            ones_2 = ((sub / 10) + (ones_1)) % 10;
            sub = (ones_1*10) + ones_2;
        }
        num = sub;
    }
    
    printf("%d", cnt);
    
}