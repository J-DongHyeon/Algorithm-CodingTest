#include <stdio.h>

int main(void)
{
    int go, back, fin, res, sub1, sub2;
    scanf("%d %d %d", &go, &back, &fin);
    sub1 = fin - go;
    sub2 = sub1 / (go-back);
    
    res = 1 + sub2;
    if (sub1 % (go-back) != 0) res++;
    
    printf("%d", res);
}