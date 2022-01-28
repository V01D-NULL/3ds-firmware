-include ../../flags.mk

BUILDDIR += ../../build
INCLUDES += -I./ -I../

SOURCES = $(shell find ./ -name '*.c' -type f)
OBJECTS = $(SOURCES:.c=.c.o)
TARGET  = arm11.elf

all: $(TARGET)
	@printf "[ARM11] Built $(TARGET)\n";

$(TARGET): $(OBJECTS)
	@printf "[ARM11] Linking $(TARGET)\n";
	@$(LD) -T linker.ld $^ -L$(GCC_LIB_PATH) -lgcc -o $(BUILDDIR)/$(TARGET)

%.c.o: %.c
	@printf "[ARM11] CC $<\n";
	@$(CC) $(ARM11_CFLAGS) $< -o $@