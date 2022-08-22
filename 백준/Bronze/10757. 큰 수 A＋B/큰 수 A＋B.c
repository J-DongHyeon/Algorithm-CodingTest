#include <stdio.h>
#include <string.h>

int main(void)
{
    int len_a, len_b, i, up=0, sub;
    char a[10002], b[10002];
    scanf("%s %s", a, b);
    len_a = strlen(a);
    len_b = strlen(b);
    if (len_a >= len_b)
    {
        for (i=0; i<len_b; i++)
        {
            sub = (a[len_a-1-i]-'0') + (b[len_b-1-i]-'0') + up;
            if (sub >= 10)
            {
                up = 1;
                sub -= 10;
            } else up = 0;
            a[len_a-1-i] = sub + '0';
        }
        if (up == 1)
        {
            if (len_a == len_b) printf("%d%s", 1, a);
            else
            {
                for (;i<len_a; i++)
                {
                    sub = (a[len_a-1-i]-'0') + up;
                    if (sub >= 10)
                    {
                        up = 1;
                        a[len_a-1-i] = (sub - 10) + '0';
                    } else 
                    {
                        up = 0;
                        a[len_a-1-i] = sub + '0';
                        break;
                    }
                }
                if (up == 1) printf("%d%s", 1, a);
                else printf("%s", a);
            }
        } else printf("%s", a);
    } else
    {
        for (i=0; i<len_a; i++)
        {
            sub = (a[len_a-1-i]-'0') + (b[len_b-1-i]-'0') + up;
            if (sub >= 10)
            {
                up = 1;
                sub -= 10;
            } else up = 0;
            b[len_b-1-i] = sub + '0';
        }
        if (up == 1)
        {            
            for (;i<len_b; i++)
            {
                sub = (b[len_b-1-i]-'0') + up;
                if (sub >= 10)
                {
                    up = 1;
                    b[len_b-1-i] = (sub - 10) + '0';
                } else 
                {
                    up = 0;
                    b[len_b-1-i] = sub + '0';
                    break;
                }
            }
            if (up == 1) printf("%d%s", 1, b);
            else printf("%s", b);
            
        } else printf("%s", b);
    }
}