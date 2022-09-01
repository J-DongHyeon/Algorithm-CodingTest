#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int fruit, i, small, big, res;
    int** direct_len = (int**) malloc(6 * sizeof(int*));
    char* buf = (char*) malloc(4);
    char* sub = (char*) malloc(4);
    scanf("%d", &fruit);
    for (i=0; i<6; i++)
    {
        direct_len[i] = (int*) malloc(2 * sizeof(int));
        scanf("%d %d", &direct_len[i][0], &direct_len[i][1]);        
    }
    for (i=0; i<6; i++)
    {
        buf[0] = direct_len[i][0] + '0'; buf[1] = direct_len[((i+1)%6)][0] + '0';
        buf[2] = direct_len[((i+2)%6)][0] + '0'; buf[3] = '\0';
        sub[0] = direct_len[((i+3)%6)][0] + '0'; sub[1] = direct_len[((i+4)%6)][0] + '0';
        sub[2] = direct_len[((i+5)%6)][0] + '0'; sub[3] = '\0';
        if (strcmp(buf, "314") == 0)
            break;
    }
    if (strcmp(sub, "231") == 0)
    {
        small = direct_len[i][1] * direct_len[((i+5)%6)][1];
        big = direct_len[((i+2)%6)][1] * direct_len[((i+3)%6)][1];
    }
    else if (strcmp(sub, "142") == 0)
    {
        small = direct_len[((i+2)%6)][1] * direct_len[((i+3)%6)][1];
        big = direct_len[i][1] * direct_len[((i+5)%6)][1];
    }
    else if (strcmp(sub, "242") == 0)
    {
        small = direct_len[((i+3)%6)][1] * direct_len[((i+4)%6)][1];
        big = direct_len[i][1] * direct_len[((i+1)%6)][1];
    }
    else
    {
        small = direct_len[((i+4)%6)][1] * direct_len[((i+5)%6)][1];
        big = direct_len[((i+1)%6)][1] * direct_len[((i+2)%6)][1];
    }
    
    res = (big - small) * fruit;
    printf("%d", res);    
}