#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdarg.h>
#include <assert.h>



enum LogLevel
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

inline void OctopusLog(LogLevel level,
    const char * component,
    const char * filename,
    int lineNum,
    const char * format, ...) 
{
    va_list args;
    switch (level)
    {
    case LOG_INFO:
        fprintf(stdout, "OctopusLog[%s][%s:%d]: ", component, filename, lineNum);
        break;
    case LOG_WARNING:
        fprintf(stdout, "OctopusWarn[%s][%s:%d]: ", component, filename, lineNum);
        break;
    case LOG_ERROR:
        fprintf(stdout, "OctopusErr[%s][%s:%d]: ", component, filename, lineNum);
        break;
    }    
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fprintf(stdout, "\n");
    fflush(stdout);
    if (level == LogLevel::LOG_ERROR)
    {
        std::abort();
    }
}

#define LOG(format, ...) \
do{ OctopusLog(LOG_INFO, LOGGING_COMPONENT, __FILE__, __LINE__, (format), ##__VA_ARGS__); } while (0)

#define WARN(level, format, ...) \
do{ OctopusLog(LOG_WARNING, LOGGING_COMPONENT, __FILE__, __LINE__, (format), ##__VA_ARGS__); } while (0)

#define ABORT(level, format, ...) \
do{ OctopusLog(LOG_ERROR, LOGGING_COMPONENT, __FILE__, __LINE__, (format), ##__VA_ARGS__); } while (0)

#define ASSERT(pred, ...) \
do{ if (!(pred)) ABORT(##__VA_ARGS__); } while (0)
