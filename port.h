#ifndef PORT_H
#define PORT_H

#define WINDOWS_PORT


#ifdef WINDOWS_PORT

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <Windows.h>

#define myinline __inline
#undef __func__
#define __func__ __FUNCTION__

#ifdef __cplusplus
extern "C"
{
#endif
#define RUSAGE_SELF 0

typedef unsigned int u_int32_t;

extern char * optarg;
extern int optind, opterr, optopt;

struct timezone
{
	int tz_minuteswest;
	int tz_dsttime;
};

struct rusage
{
	struct timeval ru_utime;
	struct timeval ru_stime;
};

myinline double erfc(double x)
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
#define index(x,y) strchr(x,y)

#ifndef __cplusplus
#define isnan(x) ((x) != (x))
#endif

int getrusage(int who, struct rusage * usage);

int gettimeofday(struct timeval * tv, struct timezone * tz);

int getopt(int argc, char * const argv[], const char * optstring);

void srand48(long int seedval);

long int lrand48(void);

double drand48(void);

#ifdef __cplusplus
}
#endif
#else

#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
#define myinline inline

#endif





#endif