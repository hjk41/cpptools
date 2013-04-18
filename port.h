#ifndef PORT_H
#define PORT_H

#define WINDOWS_PORT


#ifdef WINDOWS_PORT

#include "port_time.h"
#include "port_math.h"
#include "port_file.h"
#include "port_getopt.h"
#include "port_string.h"
#include "port_pthread.h"

#define myinline __inline
#undef __func__
#define __func__ __FUNCTION__

typedef unsigned int u_int32_t;

#else

#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

#define myinline inline

#define portable_fseek fseek
#define portable_ftell ftell

#endif





#endif