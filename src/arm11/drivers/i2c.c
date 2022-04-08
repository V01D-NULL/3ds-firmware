#include "i2c.h"
#include <types.h>
#include <arm11/core/mmio.h>
#include <lib/print.h>

#define CNT_OFFSET 1

enum I2C_BASE
{
	I2C1_BASE = 0x10161000,
	I2C2_BASE = 0x10144000,
	I2C3_BASE = 0x10148000
};

enum I2C_CNT
{
	CNT_STOP = (1 << 0),
	CNT_START = (1 << 1),
	CNT_PAUSE = (1 << 2),
	CNT_ACK = (1 << 4),
	CNT_DATA_DIR = (1 << 5),
	CNT_INT_ENABLE = (1 << 6),
	CNT_CHECK_START_OR_BUSY = (1 << 7)
};

#define IS_BUSY(i2c_base) (mmio_read(i2c_base + CNT_OFFSET) & CNT_CHECK_START_OR_BUSY)

// Wait for the busy bit to be cleared
void i2c_wait(enum I2C_BASE i2c_base)
{
	do
	{
		asm("nop");
	} while (IS_BUSY(i2c_base));
}

// https://www.3dbrew.org/wiki/I2C_Registers#I2C_SCL
// https://www.3dbrew.org/wiki/I2C_Registers#I2C_CNTEX
void i2c_init(void)
{
	// Initialize I2C buses 1-3
	i2c_wait(I2C1_BASE);
	mmio_write16(I2C1_BASE, mmio_read(I2C1_BASE) | ((0b10100000000 << 8) | 0b00000010));

	i2c_wait(I2C2_BASE);
	mmio_write16(I2C2_BASE, mmio_read(I2C2_BASE) | ((0b10100000000 << 8) | 0b00000010));

	i2c_wait(I2C3_BASE);
	mmio_write16(I2C3_BASE, mmio_read(I2C3_BASE) | ((0b10100000000 << 8) | 0b00000010));
	print("i2c: ok");
}