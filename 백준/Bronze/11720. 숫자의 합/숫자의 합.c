#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, i, sum;
    sum = 0;
    char* buf;
    scanf("%d", &num);   
    buf = (char*) malloc(num+1);
    scanf("%s", buf);
    for (i=0; i<num; i++) sum += buf[i] - '0';
    printf("%d", sum);
}