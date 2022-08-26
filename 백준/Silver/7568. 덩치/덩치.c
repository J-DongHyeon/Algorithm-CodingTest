#include <stdio.h>

int main(void)
{
    int num, i, j;
    scanf("%d", &num);
    int people[num][2], rank[num];
    for (i=0; i<num; i++) 
    {
        scanf("%d %d", &people[i][0], &people[i][1]);
        rank[i] = 1;
    }
    for (i=0; i<num-1; i++)
    {
        for (j=i+1; j<num; j++)
        {
            if (people[i][0] > people[j][0] && people[i][1] > people[j][1]) rank[j]++;
            else if (people[i][0] < people[j][0] && people[i][1] < people[j][1]) rank[i]++;
        }        
    }
    for (i=0; i<num; i++) printf("%d ", rank[i]);
}