#include <core/config11/cfg11.h>
#include <core/int/int.h>
#include <core/mm/slab.h>
#include <lib/print.h>
#include <types.h>

void main(void)
{
	ivt_init();
	slab_init();
	print("Booted on a %s", cfg11_get_console_name());

	for (;;)
		;
}