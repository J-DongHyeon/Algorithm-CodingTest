#include <stdio.h>
#include <math.h>

int main(void)
{    
    double u, deu, radius;
    scanf("%lf", &radius);
    u = pow(radius, 2) * M_PI;
    deu = pow(radius*2, 2) - (pow(radius, 2) * 2);
    printf("%.6lf\n%.6lf", u, deu);
}