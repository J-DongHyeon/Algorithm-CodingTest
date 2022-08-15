#include <stdio.h>

int main(void)
{
    int interval, thai;
    interval = 2541 - 1998;
    
    scanf("%d", &thai);
    
    while(thai < 1000 || thai > 3000) scanf("%d", &thai);
    
    printf("%d", thai - interval);
    
    return 0;
}