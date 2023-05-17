#include <shared/types.h>
#include <shared/mm/mmio.h>

#define CFG11_SOCINFO 0x10140FFC

// https://www.3dbrew.org/wiki/CONFIG11_Registers#CFG11_SOCINFO
const char *cfg11_get_console_name(void)
{
	switch (mmio_read(CFG11_SOCINFO))
	{
	case 7:
		return "Retail N3DS";

	case 3:
		return "Prototype N3DS";

	case 1:
		return "O3DS";

	default:
		return "???";
	}

	__builtin_unreachable();
}