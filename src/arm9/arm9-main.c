
// #include <shared/lib/print.h>
#include <core/communication/arm11.h>
#include <shared/drivers/i2c.h>

void _start(void)
{
	// Todo: Assign bottom framebuffer to Arm9. A macro to set the fb_pointer variable would be enough
	// print("Hello world from the ARM9");
	send_message(TEST);

	i2c_write(3, 0x20, 1 << 0); // shutdown

	for (;;)
		;
}
