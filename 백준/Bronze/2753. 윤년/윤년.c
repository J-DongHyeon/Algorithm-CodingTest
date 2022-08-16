#include <stdio.h>

int main(void)
{
    int year;
    scanf("%d", &year);
    while(year < 1 || year > 4000) scanf("%d", &year);
    
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) printf("1");
    else printf("0");
    
}