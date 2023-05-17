
// #include <shared/lib/print.h>
#include <core/communication/arm11.h>

void _start(void)
{
	// Todo: Assign bottom framebuffer to Arm9. A macro to set the fb_pointer variable would be enough
	// print("Hello world from the ARM9");
	send_message(TEST);

	for (;;)
		;
}
