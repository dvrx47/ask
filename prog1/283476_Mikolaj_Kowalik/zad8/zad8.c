#include <stdio.h>
#include <stdlib.h>

double approx_sqrt(double x, double epsilon);

int main(int argc, char **argv)
{
    double arg = atof(argv[1]);
    double epsilon = atof(argv[2]);
    printf("%f\n", approx_sqrt(arg, epsilon));
    return 0;
}
