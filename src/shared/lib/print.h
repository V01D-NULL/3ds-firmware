#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>

#ifdef VERBOSE
#define printv(...) print(__VA_ARGS__)
#else
#define printv(...)
#endif

void print(const char *fmt, ...);

#endif // PRINT_H