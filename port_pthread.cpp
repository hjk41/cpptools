#include "port_pthread.h"

#include <thread>

int pthread_attr_init(pthread_attr_t * attr)
{
	return 0;
}

int pthread_attr_destroy(pthread_attr_t * attr)
{
	return 0;
}

int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)
{
	return 0;
}

static void thread_wrapper(void *(*routine)(void*), void * arg, void * retval)
{
	retval = routine(arg);
}

int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void *(*routine)(void*), void * arg)
{
	thread->handler = new std::thread(thread_wrapper, routine, arg, thread->retval);
	return 0;
}

int pthread_join(pthread_t thread, void ** retval)
{
	((std::thread*)(thread.handler))->join();
	if (retval)
		*retval = thread.retval;
	delete thread.handler;
	return 0;
}