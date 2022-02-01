.extern a11_exception_main

@ TODO: I might use this for more sophisticated exception handling as oppose to the jump_table array
@
@ fiq_handler:
@ 	b asm_exception_stub

@ ud_handler:
@ 	b asm_exception_stub

@ prefetch_abort_handler:
@ 	b asm_exception_stub

@ data_abort_handler:
@ 	b asm_exception_stub

@ .globl a11_ivt
@ a11_ivt:
@ 	b ud_handler @ IRQ
@ 	b fiq_handler @ FIQ
@ 	b ud_handler @ UD
@ 	b ud_handler @ ???
@ 	b prefetch_abort_handler @ P-abort
@ 	b data_abort_handler @ D-abort

.globl asm_exception_stub
asm_exception_stub:
	ldr sp, =0x1FFFE000 @ TODO: Is this stack placement okay?
	bl a11_exception_main
