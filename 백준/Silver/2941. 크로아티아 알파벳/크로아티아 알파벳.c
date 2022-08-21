#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[101], sub[4];
    int res, i, len;
    res = 0;
    scanf("%s", buf);
    len = strlen(buf);
    for (i=0; i<len; i++)
    {
        if (buf[i] == 'c')
        {
            strncpy(sub, &buf[i], 2);
            sub[2] = '\0';
            if (strcmp(sub, "c=") == 0 || strcmp(sub, "c-") == 0) i++;
            res++;
            continue;
        } else if (buf[i] == 'd')
        {
            if ((i+2) < len) 
            {
                char sub2[3];
                strncpy(sub, &buf[i], 3);
                sub[3] = '\0';
                strncpy(sub2, &buf[i], 2);
                sub2[2] = '\0';
                if (strcmp(sub, "dz=") == 0) i += 2;
                else if (strcmp(sub2, "d-") == 0) i++;
            } else {
                strncpy(sub, &buf[i], 2);
                sub[2] = '\0';
                if (strcmp(sub, "d-") == 0) i++;
            }
            res++;
            continue;
        } else if (buf[i] == 'l')
        {
            strncpy(sub, &buf[i], 2);
            sub[2] = '\0';
            if (strcmp(sub, "lj") == 0) i++;
            res++;
            continue;
        } else if (buf[i] == 'n')
        {
            strncpy(sub, &buf[i], 2);
            sub[2] = '\0';
            if (strcmp(sub, "nj") == 0) i++;
            res++;
            continue;
        } else if (buf[i] == 's')
        {
            strncpy(sub, &buf[i], 2);
            sub[2] = '\0';
            if (strcmp(sub, "s=") == 0) i++;
            res++;
            continue;
        } else if (buf[i] == 'z')
        {
            strncpy(sub, &buf[i], 2);
            sub[2] = '\0';
            if (strcmp(sub, "z=") == 0) i++;
            res++;
            continue;
        }
        
        res++;
        
    }
    
    printf("%d", res);
}