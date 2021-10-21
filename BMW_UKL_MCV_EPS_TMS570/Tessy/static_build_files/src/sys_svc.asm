;-------------------------------------------------------------------------------
; sys_svc.asm
;
; (c) Texas Instruments 2009, All rights reserved.
;

    .text
    .arm


;-------------------------------------------------------------------------------
; SVC Interrupt Handler


    .global _svc
	.global _swi_enable_fiq
	.global _swi_disable_fiq
	.global _swi_enable_irq
	.global _swi_disable_irq	
	.global _swi_enable_fiq_irq
	.global _swi_disable_fiq_irq

HIGHEST_SWI	.equ  0x06
FIQMASK		.equ  0x40
IRQMASK		.equ  0x80

    .asmfunc

_svc:

    stmfd  sp!,  {r0-r12,lr}
	ldr r0,[r14,#-4]		; Get SWI Instruction
	and r0, r0, #0xff		; Look at lower 8 bits of SWI Number Only
	cmp r0, #HIGHEST_SWI		; Check for SWI out of Range
	bhi _swi_exit			; Exit Immediately if SWI out of Range
	mrs r1, spsr			; Get SPSR for SWI's that change PSR

	ldr pc,[pc,r0,lsl#2]		; Dispatch Instruction
	mov r0,r0			; Exactly 1 Word Between Disp. Instr and Table
	.word	_swi_enable_fiq		; SWI 0x00 - Dispatch Table Begins Here  
	.word   _swi_disable_fiq	; SWI 0x01
	.word   _swi_enable_irq		; SWI 0x02
	.word	_swi_disable_irq	; SWI 0x03
	.word   _swi_enable_fiq_irq	; SWI 0x04
	.word	_swi_disable_fiq_irq	; SWI 0x05
	
_swi_disable_fiq
	orr r1, r1, #FIQMASK
	msr spsr_cxsf, r1
	b   _swi_exit
		
_swi_enable_fiq
	bic r1, r1, #FIQMASK
	msr spsr_cxsf, r1
	b   _swi_exit

_swi_disable_irq
	orr r1, r1, #IRQMASK
	msr spsr_cxsf, r1
	b   _swi_exit

_swi_enable_irq
	bic r1, r1, #IRQMASK
	msr spsr_cxsf, r1
	b   _swi_exit

_swi_disable_fiq_irq
	orr r1, r1, #(FIQMASK|IRQMASK)
	msr spsr_cxsf, r1
	b   _swi_exit

_swi_enable_fiq_irq
	bic r1, r1, #(FIQMASK|IRQMASK)
	msr spsr_cxsf, r1
	b   _swi_exit
_swi_exit:
        ldmfd  sp!,  {r0-r12,pc}^

    .endasmfunc

