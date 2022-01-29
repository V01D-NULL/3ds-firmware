#include <core/mm/slab.h>
#include <lib/print.h>
#include <types.h>

void _start(void)
{
	slab_init();
	print("Nothining left to do, halting...");
	
	for (;;)
		;
}