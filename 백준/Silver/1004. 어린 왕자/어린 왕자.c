#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int test, i, j, o_num, res;
    double dist_s, dist_e;
    int* start = (int*) malloc(2 * sizeof(int));
    int* end = (int*) malloc(2 * sizeof(int));
    int* o_xyr = (int*) malloc(3 * sizeof(int));
    scanf("%d", &test);
    for (i=0; i<test; i++)
    {
        res = 0;
        scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]);
        scanf("%d", &o_num);
        for (j=0; j<o_num; j++)
        {
            scanf("%d %d %d", &o_xyr[0], &o_xyr[1], &o_xyr[2]);
            dist_s = sqrt(pow((double) o_xyr[0] - start[0], 2) + pow((double) o_xyr[1] - start[1], 2));
            dist_e = sqrt(pow((double) o_xyr[0] - end[0], 2) + pow((double) o_xyr[1] - end[1], 2));
            if (dist_s < o_xyr[2] && dist_e < o_xyr[2])
                continue;
            else if (dist_s < o_xyr[2] || dist_e < o_xyr[2])
                res++;
        }
        printf("%d\n", res);        
    }
}