#include <stdio.h>

int main(void)
{
    int num, i = 0, j = 0, ck = 0, sub, cmp;
    scanf("%d", &num);
    while (ck != num)
    {
        cmp = i * 1000 + 666;
        if ((cmp / 1000) % 1000 == 666)
        {
            sub = 1;
            for (j = 0; j < 1000; j++)
            {                    
                ck++;
                if (ck == num) break;
            }
        }
        else if ((cmp / 100) % 1000 == 666)
        {
            sub = 2;
            for (j = 0; j < 100; j++)
            {
                ck++;
                if (ck == num) break;
            }
        }
        else if ((cmp / 10) % 1000 == 666)
        {
            sub = 3;
            for (j = 0; j < 10; j++)
            {
                ck++;
                if (ck == num) break;
            }
        }
        else
        {
            sub = 0;
            ck++;
        }
        i++;
    }
    i--;
    switch (sub)
    {
        case 0:
            printf("%d", i * 1000 + 666);
            break;
        case 1:
            printf("%d", i * 1000 + j);
            break;
        case 2:
            printf("%d", i * 1000 + 600 + j);
            break;
        case 3:
            printf("%d", i * 1000 + 660 + j);
            break;
    }
}