### 3ds firmware

A little experiment where I build a toy kernel for the new nintendo 3ds (n3ds).

I don't really expect anyone to build this so you'll have to change some things I hardcoded if you do want to build and run this:
- Before building make sure you the path /usr/lib/gcc/arm-none-eabi/>version</. (By default, the version is 9.2.1, change this as needed)

- The rootlevel makefile (`Makefile`) will attempt to copy boot.firm to `/media/tim/3437-3631/luma/payloads/`, change this as needed.

Building:
```
git clone <this_repo> --recursive
make setup	# install/build dependencies
make		# Compile the code and build the boot.firm image
# In order to recompile you have to 'make clean && make'
# I might switch to meson + ninja in the future to make this less of a problem..
```

### Resources
https://developer.arm.com/documentation/ddi0201/d

https://www.3dbrew.org/wiki/Memory_layout

DDI0360F_arm11_mpcore_r2p0_trm.pdf 
