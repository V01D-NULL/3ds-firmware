#include "arm9.h"

extern volatile Arm9Message __a11_core_messaging__;

Arm9Message handle_message(void)
{
	const Arm9Message message = __a11_core_messaging__;
	switch (message)
	{
	case TEST:
		return TEST;

	default:
		return NONE;
	}
}
