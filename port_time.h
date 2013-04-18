#ifndef PORT_TIME_H
#define PORT_TIME_H

#include <time.h>
#include <Windows.h>

//--------------------------
#ifdef __cplusplus
extern "C"
{
#endif
//--------------------------

#define RUSAGE_SELF 0

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

int getrusage(int who, struct rusage * usage);
int gettimeofday(struct timeval * tv, struct timezone * tz);
double gettime();


//--------------------------
#ifdef __cplusplus
}
#endif
//--------------------------

#endif