#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int* wh = (int*) malloc(2 * sizeof(int));
    int* xy = (int*) malloc(2 * sizeof(int));
    int* man_xy = (int*) malloc(2 * sizeof(int));
    int num, i, res = 0;
    double dist_o1, dist_o2;
    scanf("%d %d %d %d %d", &wh[0], &wh[1], &xy[0], &xy[1], &num);
    for (i=0; i<num; i++)
    {
        scanf("%d %d", &man_xy[0], &man_xy[1]);
        dist_o1 = sqrt(pow( (double) xy[0] - man_xy[0], 2) + pow( (double) (xy[1] + wh[1]/2) - man_xy[1], 2));
        dist_o2 = sqrt(pow( (double) (xy[0] + wh[0]) - man_xy[0], 2) + pow( (double) (xy[1] + wh[1]/2) - man_xy[1], 2));
        if ((man_xy[0] >= xy[0] && man_xy[0] <= xy[0]+wh[0] && man_xy[1] >= xy[1] && man_xy[1] <= xy[1]+wh[1])
            || dist_o1 <= wh[1]/2 || dist_o2 <= wh[1]/2)
            res++;
    }
    printf("%d", res);
}