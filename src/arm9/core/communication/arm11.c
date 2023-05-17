#include "arm11.h"
#include <shared/mm/mmio.h>

void send_message(Arm9Message msg)
{
	mmio_write32(ARM11_COMMUNICATION_REGION, 1);
}
