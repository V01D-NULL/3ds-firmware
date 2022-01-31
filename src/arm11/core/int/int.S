@ .extern ud_handler
@ .extern prefetch_abort_handler
@ .extern data_abort_handler
@ .set A11_VECTORS_START, 0x08000000@ ((0x1FF80000) + (0x00080000) - 0x60)
@ pre_mmu_ivt:
@ 	ldr pc, _ud_handler		@ IRQ (Unimplemented)
@ 	ldr pc, _ud_handler		@ FIQ (Unimplemented)
@ 	ldr pc, _ud_handler		@ SVC (Unimplemented)
@ 	ldr pc, _ud_handler  	@ UD
@ 	ldr pc, _prefetch		@ Prefetch abort
@ 	ldr pc, _data			@ Data abort
@ 	_ud_handler:	.word ud_handler
@ 	_prefetch:		.word prefetch_abort_handler
@ 	_data:			.word data_abort_handler


@ _vectorStubs:
@ 	ldr pc, irqHandlerPtr
@ 	irqHandlerPtr:                  .4byte ud_handler
@ 	udf #2
@ 	fiqHandlerPtr:                  .4byte (A11_VECTORS_START + 0x08)
@ 	udf #3
@ 	svcHandlerPtr:                  .4byte (A11_VECTORS_START + 0x10)
@ 	ldr pc, undefInstrHandlerPtr
@ 	undefInstrHandlerPtr:           .4byte ud_handler
@ 	ldr pc, prefetchAbortHandlerPtr
@ 	prefetchAbortHandlerPtr:        .4byte prefetch_abort_handler
@ 	ldr pc, dataAbortHandlerPtr
@ 	dataAbortHandlerPtr:            .4byte data_abort_handler

@ .globl install_arm11_vectors
@ install_arm11_vectors:
@ 	adr r0, _vectorStubs
@ 	@ ldr r1, =((0x1FF80000) + (0x00080000) - 0x60) @ AXI WRAM + AXI WRAM SIZE - 0x60
@ 	ldr r1, =A11_VECTORS_START
@ 	ldmia r0!, {r2-r9}
@ 	stmia r1!, {r2-r9}
@ 	ldm r0, {r2-r5}
@ 	stm r1, {r2-r5}
	
@ 	@ ldr r1, =pre_mmu_ivt
@ 	@ mov r2, #8
@ 	@ 1:
@ 	@ 	str r1, [r0], #4
@ 	@ 	subs r2, r2, #1
@ 	@ 	bne 1b

@ 	bx lr

.extern a11_exception_main

fiq_handler:
	b generic_hander

ud_handler:
	b generic_hander

prefetch_abort_handler:
	b generic_hander

data_abort_handler:
	b generic_hander

.globl a11_ivt
a11_ivt:
	.word 0
	.word fiq_handler
	.word 0
	.word ud_handler
	.word prefetch_abort_handler
	.word data_abort_handler

generic_hander:
	@ mov r1, r0
    @ mov r0, sp
    @ mrs r2, spsr
    @ mrs r3, cpsr
    @ add r6, r0, #(8 * 4)

    orr r3, #0xc0              @ mask interrupts
    msr cpsr_cx, r3

    @ ands r4, r2, #0xf          @ get the mode that triggered the exception
    @ moveq r4, #0xf             @ usr => sys
    @ bic r5, r3, #0xf
    @ orr r5, r4
    @ msr cpsr_c, r5             @ change processor mode
    @ stmia r6!, {r8-lr}
    msr cpsr_c, r3             @ restore processor mode

    @ str lr, [r6], #4
    @ str r2, [r6]

    msr cpsr_cxsf, #0xdf       @ finally, switch to system mode, mask interrupts and clear flags (in case of double faults)
    ldr sp, =0x20004000
	bl a11_exception_main