#include <core/mm/slab.h>
#include <lib/print.h>
#include <types.h>

void a11_exception_main(void)
{
	print("ARM11: An exception occurred");
	for (;;)
		;
}

extern const u32 a11_ivt[6];
void _start(void)
{
	// slab_init();
	// // print("Nothining left to do, halting...");
	vu32 *dstVeneers = (vu32 *)0x1FFFFFA0;

	for (u32 i = 0; i < 6; i++)
	{
		if (a11_ivt[i] != 0)
		{
			dstVeneers[2 * i] = 0xE51FF004;
			dstVeneers[2 * i + 1] = a11_ivt[i];
		}
	}

	print("Generating #UD");
	asm volatile("udf #2");
	print("After udf?");

	for (;;)
		;
}