#include <core/int/int.h>
#include <core/mm/slab.h>
#include <lib/print.h>
#include <types.h>

void main(void)
{
	ivt_init();
	slab_init();

	print("Generating #UD");
	asm volatile("udf #2");

	for (;;)
		;
}