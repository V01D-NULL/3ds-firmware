#include <lib/print.h>
#include <core/fb.h>
#include <types.h>

void _start(void)
{
	print("Hello, world");

	for (;;)
		;
}