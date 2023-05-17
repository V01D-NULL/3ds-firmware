#include <lib/print.h>
#include <shared/types.h>

#define FAR_JUMP 0xE51FF004 // LDR PC, [PC, #-4]

extern void asm_exception_stub(void);
extern void fiq_handler();
extern void data_abort_handler();
extern void prefetch_abort_handler();
extern void unknown_handler();
extern void ud_handler();
extern void irq_handler();

u32 jump_table[6] = {
	(u32)&irq_handler,
	(u32)&fiq_handler,
	(u32)&ud_handler,
	(u32)&ud_handler,
	(u32)&prefetch_abort_handler,
	(u32)&data_abort_handler};

const char *str_table[6] = {
	"IRQ",
	"FIQ",
	"UD",
	"???",
	"Prefetch abort",
	"Data abort"};

void a11_exception_main(int arg0)
{
	print("ARM11: An exception occurred (%s)", str_table[arg0]);
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