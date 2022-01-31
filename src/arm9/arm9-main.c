#include "print.h"
#include <types.h>

void exception_main(void)
{
	print("ARM9: An interrupt occurred");
	for(;;)
		;
}

extern const u32 a9_ivt[6];
void _start(void)
{
	vu32 *dstVeneers = (vu32 *)0x08000000;

    for(u32 i = 0; i < 6; i++)
    {
        if(a9_ivt[i] != 0)
        {
            dstVeneers[2 * i] = 0xE51FF004;
            dstVeneers[2 * i + 1] = a9_ivt[i];
        }
    }


	// print("Generating #UD...");
	// asm volatile("udf #2");
	// print("After #UD (?)");
	for (;;)
		;
}
