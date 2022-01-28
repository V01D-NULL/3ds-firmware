CC = /usr/bin/clang
AS = 
LD = arm-none-eabi-ld
PY = /usr/bin/python3
GCC_LIB_PATH = /usr/lib/gcc/arm-none-eabi/9.2.1/

# Overriden by whoever includes flags.mk
BUILDDIR =
INCLUDES =

# Kernel & cpu specific compiler flags
KERN_CFLAGS  = $(INCLUDES) -ffreestanding -g -O2 -c 
ARM9_CFLAGS  = $(KERN_CFLAGS) --target=armv5-none-eabi -mcpu=arm946e-s
ARM11_CFLAGS = $(KERN_CFLAGS) --target=armv6k-none-eabi -mtune=mpcore -mfloat-abi=hard -mtp=soft