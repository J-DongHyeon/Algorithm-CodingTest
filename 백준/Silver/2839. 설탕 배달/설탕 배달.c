#include <stdio.h>

int bag(int);

int main(void)
{
    int kg, res;
    scanf("%d", &kg);
    res = bag(kg);
    printf("%d", res);
}

int bag(int kg)
{
    int ck, i=0, mol;
    do 
    {
        mol = (kg % 5) + (i*5);
        if (mol > kg) return -1;
        if (mol % 3 == 0) ck = 0;
        else 
        {
            i++;
            ck = 1;
        }
    } while (ck);
    return ((kg/5)-i) + (((kg%5)+(i*5))/3);
}