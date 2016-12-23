#ifndef _LOGGER_H_
#define _LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3

#define LOG_LEVEL_CHARS "DIWEF"
#define LOG_MAX_MSG_LEN 1024

struct _Logger {
    int level;
    char *datetime_format;
    FILE *fp;
};

typedef struct _Logger Logger;

Logger * Logger_create( void );
void Logger_free(Logger *l);
void log_add(Logger *l, int level, const char *msg);
void log_debug(Logger *l, const char *fmt, ...);
void log_info(Logger *l, const char *fmt, ...);
void log_warn(Logger *l, const char *fmt, ...);
void log_error(Logger *l, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
