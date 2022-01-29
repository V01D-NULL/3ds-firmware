#include <lib/print.h>
#include <lib/libcore/fmt.h>
#include <lib/libcore/string.h>
#include <core/fb.h>

static int x = 1;
static int y = 1;
static char buff[512];

void print(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int len = vsnprintf((char *)&buff, 512, format, ap);
	va_end(ap);
	
	for (u32 i = 0; i < len; i++, x += 8)
	{
		putc(true, x, y, 0, buff[i]);
	}

	x = 0;
	y += 9;
}