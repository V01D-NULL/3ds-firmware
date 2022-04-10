#ifndef I2C_H
#define I2C_H

#include <types.h>

bool i2c_write(u8 device_id, u8 reg, u8 data);

#endif // I2C_H