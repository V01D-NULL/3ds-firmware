-include ../../flags.mk

BUILDDIR += ../../build
INCLUDES += -I./ -I../

SOURCES = $(shell find ./ -name '*.c' -type f)
OBJECTS = $(SOURCES:.c=.c.o)
TARGET  = arm9.elf

all: $(TARGET)
	@printf "[ARM9] Built $(TARGET)\n";

$(TARGET): $(OBJECTS)
	@printf "[ARM9] Linking $(TARGET)\n";
	@$(LD) -T linker.ld  $^ -o $(BUILDDIR)/$(TARGET)

%.c.o: %.c
	@printf "[ARM9] CC $<\n";
	@$(CC) $(ARM9_CFLAGS) $< -o $@