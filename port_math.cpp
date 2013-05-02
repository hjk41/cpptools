#include "port_math.h"
#include <math.h>
#include <stdlib.h>

double erfc(double x)
{
	double t,y;
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x);

    // A&S formula 7.1.26
    t = 1.0/(1.0 + p*x);
    y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return sign*y;
}

void srand48(long int seedval)
{
	srand(seedval);
}

long int lrand48(void)
{
	long r = 0;
	int r1 = rand() & 0xFFFF;
	int r2 = rand() & 0xFFFF;
	r = (r1<<16) | r2;
	return r;
}

double drand48(void)
{
	return (double)rand()/RAND_MAX;
}
