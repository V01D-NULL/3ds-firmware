-include ../../flags.mk

BUILDDIR += ../../build
INCLUDES += -I./ -I../

CSOURCES = $(shell find ./ -name '*.c' -type f)
ASSOURCES = $(shell find ./ -name '*.S' -type f)

COBJECTS = $(CSOURCES:.c=.c.o)
ASOBJECTS = $(ASSOURCES:.S=.S.o)
OBJECTS = $(ASOBJECTS) $(COBJECTS)
TARGET  = arm9.elf

all: $(TARGET)
	@printf "[ARM9] Built $(TARGET)\n";

$(TARGET): $(OBJECTS)
	@printf "[ARM9] Linking $(TARGET)\n";
	@$(LD) -T linker.ld $^ -L$(GCC_LIB_PATH) -lgcc -o $(BUILDDIR)/$(TARGET)

%.c.o: %.c
	@printf "[ARM9] CC $<\n";
	@$(CC) $(ARM9_CFLAGS) $< -o $@

%.S.o: %.S
	@printf "[ARM9] AS $<\n";
	@$(AS) $(ARM9_ASFLAGS) $< -o $@