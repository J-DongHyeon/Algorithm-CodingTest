#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int test, i;
    double dist, r_plus, r_minus;
    int* o1 = (int*) malloc(sizeof(int) * 3);
    int* o2 = (int*) malloc(sizeof(int) * 3);
    scanf("%d", &test);
    for (i=0; i<test; i++)
    {
        scanf("%d %d %d %d %d %d", &o1[0], &o1[1], &o1[2], &o2[0], &o2[1], &o2[2]);
        if (o1[0] == o2[0] && o1[1] == o2[1] && o1[2] == o2[2])
        {
            printf("-1\n");
            continue;
        }
        dist = sqrt(pow((double) o1[0] - o2[0], 2) + pow((double) o1[1] - o2[1], 2));
        r_plus = (double) o1[2] + o2[2]; r_minus = fabs((double) o1[2] - o2[2]);
        if (dist > r_minus && dist < r_plus)
            printf("2\n");
        else if (dist == r_minus || dist == r_plus)
            printf("1\n");
        else
            printf("0\n");
    }
}