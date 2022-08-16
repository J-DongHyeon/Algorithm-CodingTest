#include <stdio.h>

int main(void)
{
    int s_h, s_m, c_h, c_m;
    scanf("%d %d", &s_h, &s_m);
    while(s_h < 0 || s_h > 23) scanf("%d", &s_h);
    while(s_m < 0 || s_m > 59) scanf("%d", &s_m);
    
    c_m = s_m - 45;
    
    if (c_m >= 0)
    {
        c_h = s_h;
    }
    else
    {
        c_h = s_h - 1;
        if (c_h < 0) c_h += 24; 
        c_m += 60;
    }
    
    printf("%d %d", c_h, c_m);
    
    return 0;
    
}