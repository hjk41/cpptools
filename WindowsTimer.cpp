#include "WindowsTimer.h"



WindowsTimer::WindowsTimer(void)
: _start(), _stop()
{
	_frequency = this->get_frequency();
}

double WindowsTimer::get_frequency(void)
{
	LARGE_INTEGER proc_freq;
	if (!::QueryPerformanceFrequency(&proc_freq))
		return -1;
	return (double)proc_freq.QuadPart;
}

void WindowsTimer::start_timer(void)
{
	DWORD_PTR oldmask = ::SetThreadAffinityMask(::GetCurrentThread(), 0);
	::QueryPerformanceCounter(&_start);
	::SetThreadAffinityMask(::GetCurrentThread(), oldmask);
}

double WindowsTimer::stop_timer(void)
{
	DWORD_PTR oldmask = ::SetThreadAffinityMask(::GetCurrentThread(), 0);
	::QueryPerformanceCounter(&_stop);
	::SetThreadAffinityMask(::GetCurrentThread(), oldmask);
	return ((_stop.QuadPart - _start.QuadPart) / _frequency);
}


