.extern exception_main

fiq_handler:
	b generic_hander

ud_handler:
	b generic_hander

prefetch_abort_handler:
	b generic_hander

data_abort_handler:
	b generic_hander

.globl a9_ivt
a9_ivt:
	.word 0
	.word fiq_handler
	.word 0
	.word ud_handler
	.word prefetch_abort_handler
	.word data_abort_handler

generic_hander:
	mov r1, r0
    mov r0, sp
    mrs r2, spsr
    mrs r3, cpsr
    add r6, r0, #(8 * 4)

    orr r3, #0xc0              @ mask interrupts
    msr cpsr_cx, r3

    ands r4, r2, #0xf          @ get the mode that triggered the exception
    moveq r4, #0xf             @ usr => sys
    bic r5, r3, #0xf
    orr r5, r4
    msr cpsr_c, r5             @ change processor mode
    stmia r6!, {r8-lr}
    msr cpsr_c, r3             @ restore processor mode

    str lr, [r6], #4
    str r2, [r6]

    msr cpsr_cxsf, #0xdf       @ finally, switch to system mode, mask interrupts and clear flags (in case of double faults)
    ldr sp, =0x02000000
	bl exception_main