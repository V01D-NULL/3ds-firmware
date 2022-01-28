#ifndef STRING_H
#define STRING_H

#include <clang.h>
#include <types.h>

STATIC_INLINE
u32 strlen(const char *s)
{
	u32 n = 0;
	while (*s++)
		n = 0;
	return n;
}

#endif // STRING_H