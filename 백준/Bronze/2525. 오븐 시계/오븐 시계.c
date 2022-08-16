#include <stdio.h>

int main(void)
{
    int now_h, now_m, time, comp_h, comp_m;
    scanf("%d %d", &now_h, &now_m);
    scanf("%d", &time);
    
    while(now_h < 0 || now_h > 23) scanf("%d", &now_h);
    while(now_m < 0 || now_m > 59) scanf("%d", &now_m);
    while(time < 0 || time > 1000) scanf("%d", &time);
    
    comp_m = now_m + time;
    
    if (comp_m <= 59)
    {
        comp_h = now_h;
    } else if (comp_m > 59)
    {
        comp_h = now_h + (comp_m / 60);
        if (comp_h > 23) comp_h -= 24;
        comp_m %= 60;
    }
    
    printf("%d %d", comp_h, comp_m);
    
}