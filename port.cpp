#include <string.h>
#include "port.h"


#ifdef WINDOWS_PORT

#include <Windows.h>

extern char * optarg = NULL;
extern int optind = 0;
extern int opterr = 0;
extern int optopt = 0;

static timeval __start_time;
static int __junk_value = gettimeofday(&__start_time, NULL);

int getrusage(int who, struct rusage * usage)
{
	timeval t2;
	gettimeofday(&t2, NULL);
	usage->ru_utime.tv_sec = t2.tv_sec - __start_time.tv_sec;
	usage->ru_utime.tv_usec = t2.tv_usec - __start_time.tv_usec;
	usage->ru_stime.tv_sec = 0;
	usage->ru_stime.tv_usec = 0;
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

int getopt(int argc, char * const argv[], const char *optstring)
{
	static char *next = NULL;
	if (optind == 0)
		next = NULL;

	optarg = NULL;

	if (next == NULL || *next == '\0')
	{
		if (optind == 0)
			optind++;

		if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0')
		{
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		if (strcmp(argv[optind], "--") == 0)
		{
			optind++;
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		next = argv[optind];
		next++;		// skip past -
		optind++;
	}

	char c = *next++;
	const char *cp = strchr(optstring, c);

	if (cp == NULL || c == ':')
		return '?';

	cp++;
	if (*cp == ':')
	{
		if (*next != '\0')
		{
			optarg = next;
			next = NULL;
		}
		else if (optind < argc)
		{
			optarg = argv[optind];
			optind++;
		}
		else
		{
			return '?';
		}
	}

	return c;
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
	double r = 0;
	r = (double)(rand() & 0xFFFF)/0xFFFF;
	return 0;
}

#endif