#ifndef MMIO_H
#define MMIO_H

#include <clang.h>
#include <types.h>

STATIC_INLINE
void mmio_write8(vu32 io_port, u8 val)
{
	*((vu32 *)io_port) = val;
}

STATIC_INLINE
void mmio_write16(vu32 io_port, u16 val)
{
	*((vu32 *)io_port) = val;
}

STATIC_INLINE
void mmio_write32(vu32 io_port, u32 val)
{
	*((vu32 *)io_port) = val;
}

STATIC_INLINE
u32 mmio_read(vu32 io_port)
{
	return *((vu32 *)io_port);
}

#endif // MMIO_H