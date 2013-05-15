#include "port_time.h"
#include <Windows.h>
#include <assert.h>

static timeval FileTime2TimeVal(FILETIME ft)
{
	ULARGE_INTEGER u;
	u.HighPart = ft.dwHighDateTime;
	u.LowPart = ft.dwLowDateTime;
	timeval tv;
	tv.tv_sec = u.QuadPart/10000000;
	tv.tv_usec = (u.QuadPart%10000000)/10;
	return tv;
}

int getrusage(int who, struct rusage * usage)
{
	FILETIME ct, et, kt, ut;
	BOOL r = GetProcessTimes(GetCurrentProcess(), &ct, &et, &kt, &ut);
	assert(r);
	usage->ru_stime = FileTime2TimeVal(kt);
	usage->ru_utime = FileTime2TimeVal(ut);
	return 0;
}

int gettimeofday(struct timeval * tv, struct timezone * tz)
{
	LARGE_INTEGER t;
	::QueryPerformanceCounter(&t);
	LARGE_INTEGER f;
	::QueryPerformanceFrequency(&f);
	double dt = (double)(t.QuadPart/f.QuadPart);
	tv->tv_sec = (time_t)dt;
	tv->tv_usec = (dt - tv->tv_sec) * 1000000;
	return 0;
}

double gettime()
{
	LARGE_INTEGER t;
	::QueryPerformanceCounter(&t);
	LARGE_INTEGER f;
	::QueryPerformanceFrequency(&f);
	double dt = (double)t.QuadPart/f.QuadPart;
	return dt;
}
