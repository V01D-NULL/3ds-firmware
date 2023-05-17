#ifndef MMIO_H
#define MMIO_H

#include <shared/clang.h>
#include <shared/types.h>

STATIC_INLINE
void mmio_write8(u32 io_port, u8 val)
{
	*((vu8 *)io_port) = val;
}

STATIC_INLINE
void mmio_write16(u32 io_port, u16 val)
{
	*((vu16 *)io_port) = val;
}

STATIC_INLINE
void mmio_write32(u32 io_port, u32 val)
{
	*((vu32 *)io_port) = val;
}

STATIC_INLINE
u32 mmio_read(u32 io_port)
{
	return *((vu32 *)io_port);
}

#endif // MMIO_H