#ifndef PORT_PTHREAD_H
#define PORT_PTHREAD_H

//--------------------------
#ifdef __cplusplus
extern "C"
{
#endif
//--------------------------
#define PTHREAD_CREATE_JOINABLE 0
#define PTHREAD_CANCELED -1

typedef struct __pthread_t
{
	void * handler;
	void * retval;
}pthread_t;

typedef struct __pthread_attr_t
{
	char dummy;
}pthread_attr_t;

int pthread_attr_init(pthread_attr_t * attr);
int pthread_attr_destroy(pthread_attr_t * attr);
int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void *(*routine)(void*), void * arg);
int pthread_join(pthread_t thread, void ** retval);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);

//--------------------------
#ifdef __cplusplus
}
#endif
//--------------------------

#endif