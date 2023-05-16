CC = /usr/bin/clang
AS = /usr/bin/arm-none-eabi-as
LD = /usr/bin/ld.lld
PY = /usr/bin/python3
GCC_LIB_PATH = /usr/lib/gcc/arm-none-eabi/10.3.1/

# Overriden by whoever includes flags.mk
BUILDDIR =
INCLUDES =

# Kernel & cpu specific compiler flags
KERN_CFLAGS   = $(INCLUDES) -ffreestanding -g -O2 -c -D VERBOSE
ARM9_CFLAGS   = $(KERN_CFLAGS) --target=armv5-none-eabi -mcpu=arm946e-s
ARM9_ASFLAGS  = -g -march=armv5  -mcpu=arm946e-s

ARM11_CFLAGS  = $(KERN_CFLAGS) --target=armv6k-none-eabi -mtune=mpcore -mfloat-abi=hard -mtp=soft
ARM11_ASFLAGS = -g -march=armv6k -mfloat-abi=hard
