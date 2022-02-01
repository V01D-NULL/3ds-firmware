### 3ds firmware

A little experiment where I build a toy kernel for the new nintendo 3ds (n3ds).

<img src="https://media.discordapp.net/attachments/834872300561629244/936378762331828224/20220127_152753.jpg?width=881&height=661"></img>

### Building:
I don't really expect anyone to build this so you'll have to change some things I hardcoded if you do want to build and run this:
- Before building, make sure you have the follwing path: /usr/lib/gcc/arm-none-eabi/>version</. (By default, the version is 9.2.1, change this as needed in `flags.mk`)

- The root level makefile (`Makefile`) will attempt to copy boot.firm to `/media/tim/3437-3631/luma/payloads/`, change this as needed.

Building boot.firm:
```
git clone <this_repo> --recursive
make setup	# install/build dependencies
make		# Compile the code and build the boot.firm image
# In order to recompile you have to 'make clean && make'
# I might switch to meson + ninja in the future to make this less of a problem..
```

### Implemented features
- basic printing
- slab allocator (will be improved as I a get a feel for memory management on this device)
- exception handler

### Planned features
- double buffering (bank switching)
- mmu
- scrolling text (maybe idk)
- read files from sd card
- i2c
- gpu driver
- DOOM!

### Resources
https://developer.arm.com/documentation/ddi0201/d

https://www.3dbrew.org/wiki/Memory_layout

DDI0360F_arm11_mpcore_r2p0_trm.pdf 
