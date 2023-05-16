-include flags.mk

SD_MOUNTPOINT = /media/tim/NO\ NAME/luma/payloads/

# boot.firm is what boot9strap loads after doing it's thing, the name must not be changed (unless it's chainloaded by luma)
all: boot.firm
	@printf "Build complete :^)\n";

setup:
	$(MAKE) -C submodules/ all

boot.firm:
	@$(MAKE) --no-print-directory -C src/ all
	firmtool build $@ -D build/arm11.elf build/arm9.elf -C XDMA NDMA -A 0x20000000 -i
	cp $@ $(SD_MOUNTPOINT)

verify:
	firmtool parse boot.firm

# Misc #
OBJECTS = $(shell find ./ -name '*.o' -type f)
clean:
	rm $(OBJECTS) build/* boot.firm