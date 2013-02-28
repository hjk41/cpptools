#pragma once

#include <Windows.h>

class WindowsTimer {
public:
	WindowsTimer(void);
	void start_timer(void);
	double stop_timer(void);
private:
	double get_frequency(void);
private:
	LARGE_INTEGER _start;
	LARGE_INTEGER _stop;
	double _frequency;
};

inline double gettimeofday()
{
	LARGE_INTEGER t;
	::QueryPerformanceCounter(&t);
	LARGE_INTEGER f;
	::QueryPerformanceFrequency(&f);
	return (double)(t.QuadPart/f.QuadPart);
}