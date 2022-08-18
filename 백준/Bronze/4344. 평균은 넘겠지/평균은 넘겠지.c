#include <stdio.h>

int main(void)
{
    int num, i, j, cnt;
    double avg;
    scanf("%d", &num);
    double res[num];
    
    for (i=0; i<num; i++)
    {
        cnt = 0; avg = 0;
        int stu;
        scanf("%d", &stu);
        int stus[stu];
        for(j=0; j<stu; j++) 
        {
            scanf("%d", &stus[j]);
            avg += stus[j];
        }
        avg /= stu;
        for(j=0; j<stu; j++)
        {
            if (stus[j] > avg) cnt++;
        }
        
        res[i] = ((double) cnt / stu) * 100;
    }
    
    for(i=0; i<num; i++) printf("%.3lf%\n", res[i]);
    
}