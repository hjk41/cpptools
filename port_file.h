#ifndef PORT_FILE_H
#define PORT_FILE_H

#include <stdio.h>

//--------------------------
#ifdef __cplusplus
extern "C"
{
#endif
//--------------------------

#define portable_fseek _fseeki64
#define portable_ftell _ftelli64

//--------------------------
#ifdef __cplusplus
}
#endif
//--------------------------

#endif