#include <lib/print.h>
#include <types.h>

#define FAR_JUMP 0xE51FF004 // LDR PC, [PC, #-4]

extern void asm_exception_stub(void);

u32 jump_table[6] = {[0 ... 5] = (u32)&asm_exception_stub};

void a11_exception_main(void)
{
	print("ARM11: An exeption occurred.");
	for (;;)
		;
}

void ivt_init(void)
{
	// The bootrom vectors are stored at the end of AXI WRAM
	// Nintendo's IVT layout must be used until the mmu is enabled.
	vu32 *a11_bootrom_vectors = (vu32 *)0x1FFFFFA0;
	a11_bootrom_vectors[0] = FAR_JUMP;
	a11_bootrom_vectors[1] = jump_table[0];

	a11_bootrom_vectors[2] = FAR_JUMP;
	a11_bootrom_vectors[3] = jump_table[1];

	a11_bootrom_vectors[4] = FAR_JUMP;
	a11_bootrom_vectors[5] = jump_table[2];

	a11_bootrom_vectors[6] = FAR_JUMP;
	a11_bootrom_vectors[7] = jump_table[3];

	a11_bootrom_vectors[8] = FAR_JUMP;
	a11_bootrom_vectors[9] = jump_table[4];

	a11_bootrom_vectors[10] = FAR_JUMP;
	a11_bootrom_vectors[11] = jump_table[5];
	print("IVT: ok");
}