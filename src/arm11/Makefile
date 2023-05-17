-include ../../flags.mk

BUILDDIR += ../../build
INCLUDES += -I./ -I../ -I../shared/

CSOURCES = $(shell find ./ -name '*.c' -type f) $(shell find ../shared/ -name '*.c' -type f)
ASSOURCES = $(shell find ./ -name '*.S' -type f)

COBJECTS = $(CSOURCES:.c=.c.o)
ASOBJECTS = $(ASSOURCES:.S=.S.o)
OBJECTS = $(ASOBJECTS) $(COBJECTS)
TARGET  = arm11.elf

all: $(TARGET)
	@printf "[ARM11] Built $(TARGET)\n";

$(TARGET): $(OBJECTS)
	@printf "[ARM11] Linking $(TARGET)\n";
	@$(LD) -T linker.ld $^ -L$(GCC_LIB_PATH) -lgcc -o $(BUILDDIR)/$(TARGET)

%.c.o: %.c
	@printf "[ARM11] CC $<\n";
	@$(CC) $(ARM11_CFLAGS) $< -o $@

%.S.o: %.S
	@printf "[ARM11] AS $<\n";
	@$(AS) $(ARM11_ASFLAGS) $< -o $@