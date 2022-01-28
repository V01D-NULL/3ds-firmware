#ifndef FMT_H
#define FMT_H

#include <stdarg.h>

int vsnprintf(char *str, int size, const char *fmt, va_list ap);

#endif // FMT_H