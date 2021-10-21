;-------------------------------------------------------------------------------
; sys_core.asm
;
; (c) Texas Instruments 2009, All rights reserved.
;

    .text
    .arm

;-------------------------------------------------------------------------------
; Initialize CPU Registers

    .global  _coreInitRegisters_
    .asmfunc

_coreInitRegisters_:

        mov   r0,         lr
        mov   r1,         #0x03D0
        mov   r2,         #0x0000
        mov   r3,         #0x0000
        mov   r4,         #0x0000
        mov   r5,         #0x0000
        mov   r6,         #0x0000
        mov   r7,         #0x0000
        mov   r8,         #0x0000
        mov   r9,         #0x0000
        mov   r10,        #0x0000
        mov   r11,        #0x0000
        mov   r12,        #0x0000
        orr   r13,        r1,     #0x0001
        msr   cpsr_cxsf,  r13
        msr   spsr_cxsf,  r13
        mov   lr,         r0
        mov   r8,         #0x0000
        mov   r9,         #0x0000
        mov   r10,        #0x0000
        mov   r11,        #0x0000
        mov   r12,        #0x0000
        orr   r13,        r1,     #0x0002
        msr   cpsr_c,     r13
        msr   spsr_cxsf,  r13
        mov   lr,         r0
        orr   r13,        r1,     #0x0007
        msr   cpsr_c,     r13
        msr   spsr_cxsf,  r13
        mov   lr,         r0
        orr   r13,        r1,     #0x000B
        msr   cpsr_c,     r13
        msr   spsr_cxsf,  r13
        mov   lr,         r0
        orr   r13,        r1,     #0x0003
        msr   cpsr_c,     r13
        msr   spsr_cxsf,  r13

	.if __TI_VFPV3D16_SUPPORT__ = 1
        fmdrr d0,        r1,     r1
        fmdrr d1,        r1,     r1
        fmdrr d2,        r1,     r1
        fmdrr d3,        r1,     r1
        fmdrr d4,        r1,     r1
        fmdrr d5,        r1,     r1
        fmdrr d6,        r1,     r1
        fmdrr d7,        r1,     r1
        fmdrr d8,        r1,     r1
        fmdrr d9,        r1,     r1
        fmdrr d10,       r1,     r1
        fmdrr d11,       r1,     r1
        fmdrr d12,       r1,     r1
        fmdrr d13,       r1,     r1
        fmdrr d14,       r1,     r1
        fmdrr d15,       r1,     r1
    .endif

        bl    $+4
        bl    $+4
        bl    $+4
        bl    $+4
        bx    r0

    .endasmfunc


;-------------------------------------------------------------------------------
; Initialize Stack Pointers

    .global  _coreInitStackPointer_
    .asmfunc

_coreInitStackPointer_:

        msr   cpsr_c,   #0xD1
        ldr   sp,       fiq
        msr   cpsr_c,   #0xD2
        ldr   sp,       irq
        msr   cpsr_c,   #0xD7
        ldr   sp,       abort
        msr   cpsr_c,   #0xDB
        ldr   sp,       undef
        msr   cpsr_c,   #0xDF
        ldr   sp,       user
        msr   cpsr_c,   #0xD3
        ldr   sp,       svc
        bx    lr

user:   .word 0x08000000+0x00003000
svc:    .word 0x08000000+0x00003000+0x00000200
fiq:    .word 0x08000000+0x00003000+0x00000200+0x00000200
irq:    .word 0x08000000+0x00003000+0x00000200+0x00000200+0x00000100
abort:  .word 0x08000000+0x00003000+0x00000200+0x00000200+0x00000100+0x00000100
undef:  .word 0x08000000+0x00003000+0x00000200+0x00000200+0x00000100+0x00000100+0x00000100

    .endasmfunc


;-------------------------------------------------------------------------------
; Enable VFP Unit

    .global  _coreEnableVfp_
    .asmfunc

_coreEnableVfp_:

	.if __TI_VFPV3D16_SUPPORT__ = 1
        mrc   p15,     #0x00,      r0,       c1, c0, #0x02
        orr   r0,      r0,         #0xF00000
        mcr   p15,     #0x00,      r0,       c1, c0, #0x02
        mov   r0,      #0x40000000
        fmxr  fpexc,   r0
	.endif

        bx    lr

    .endasmfunc


;-------------------------------------------------------------------------------
; Enable Event Bus Export

    .global  _coreEnableEventBusExport_
    .asmfunc

_coreEnableEventBusExport_:

        mrc   p15, #0x00, r0,         c9, c12, #0x00
        orr   r0,  r0,    #0x10
        mcr   p15, #0x00, r0,         c9, c12, #0x00
        bx    lr

    .endasmfunc


;-------------------------------------------------------------------------------
; Enable RAM ECC Support

    .global  _coreEnableRamEcc_
    .asmfunc

_coreEnableRamEcc_:

        mrc   p15, #0x00, r0,         c1, c0,  #0x01
        orr   r0,  r0,    #0x0C000000
        mcr   p15, #0x00, r0,         c1, c0,  #0x01
        bx    lr

    .endasmfunc


;-------------------------------------------------------------------------------
; Enable Flash ECC Support

    .global  _coreEnableFlashEcc_
    .asmfunc

_coreEnableFlashEcc_:

	MRC p15,#0,r1,c9,c12,#0		;Enabling Event monitor states
	ORR r1, r1, #0x00000010	
	MCR p15,#0,r1,c9,c12,#0		;LDR R3, =0x00000010     ; (set 4th bit of PMNC register)
	MRC p15,#0,r1,c9,c12,#0

	MRC p15, #0, r1, c1, c0, #1	;Enable ATCM
	ORR r1, r1, #0x1 <<25
	DMB
	MCR p15, #0, r1, c1, c0, #1
	ISB
		
   	MOV PC, lr

    .endasmfunc

;-------------------------------------------------------------------------------
; Disable Flash ECC Support

    .global  _coreDisableFlashEcc_
    .asmfunc

_coreDisableFlashEcc_:

	
	MRC p15, #0, r1, c1, c0, #1		;disable ATCM PARECCENRAM[0]
	MVN R0,#0x1 <<25
   	AND R1 ,R1, R0
	DMB
	MCR p15, #0, r1, c1, c0, #1
	ISB

	MRC p15, #0, r1, c1, c0, #1		;disable ATCM ERRENRAM[0]
	MVN R0,#0x1 <<0
   	AND R1 ,R1, R0
	DMB
	MCR p15, #0, r1, c1, c0, #1
	ISB

	MOV PC, lr


    .endasmfunc

;-------------------------------------------------------------------------------
; Switch to User Mode

    .global  _coreSetUserModeSync_
    .asmfunc

_coreSetUserModeSync_:

        mov   r0,       lr
        mov   r1,       #0xD0
        msr   cpsr_c,   r1
        bx    r0

    .endasmfunc
    

;-------------------------------------------------------------------------------
; Initialize Stack Pointers

    .global  _coreBackupStackPointer_
    .global  _coreRestoreStackPointer_
    .asmfunc

_coreBackupStackPointer_:

        ldr   r0,       r1_bkup        
        str   r1,       [r0]
        ldr   r0,       r2_bkup        
        str   r2,       [r0]

        msr   cpsr_c,   #0xD1
        ldr   r0,       fiq_bkup        
        str   sp,       [r0]
        msr   cpsr_c,   #0xD2
        ldr   r0,       irq_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xD7
        ldr   r0,       abort_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xDB
        ldr   r0,       undef_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xDF
        ldr   r0,       user_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xD3
        ldr   r0,       svc_bkup
        str   sp,       [r0]
        bx    lr

;    .endasmfunc

;-------------------------------------------------------------------------------
; Recover Stack Pointers

;    .global  _coreRestoreStackPointer_
;    .asmfunc

_coreRestoreStackPointer_:

        ldr   r0,       r1_bkup        
        ldr   r1,       [r0]
        ldr   r0,       r2_bkup        
        ldr   r2,       [r0]

        msr   cpsr_c,   #0xD1
        ldr   r0,       fiq_bkup        
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD2
        ldr   r0,       irq_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD7
        ldr   r0,       abort_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xDB
        ldr   r0,       undef_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xDF
        ldr   r0,       user_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD3
        ldr   r0,       svc_bkup
        ldr   sp,       [r0]
;
        bx    lr

user_bkup:   .word 0x08001000
svc_bkup:    .word 0x08001004
fiq_bkup:    .word 0x08001008
irq_bkup:    .word 0x0800100C
abort_bkup:  .word 0x08001010
undef_bkup:  .word 0x08001014
r0_bkup:   	 .word 0x08001018
r1_bkup:     .word 0x0800101C
r2_bkup:     .word 0x08001020


    .endasmfunc    
;-------------------------------------------------------------------------------
; C++ construct table pointers

    .global __TI_PINIT_Base, __TI_PINIT_Limit
    .weak   SHT$$INIT_ARRAY$$Base, SHT$$INIT_ARRAY$$Limit

__TI_PINIT_Base:  .long SHT$$INIT_ARRAY$$Base
__TI_PINIT_Limit: .long SHT$$INIT_ARRAY$$Limit

;-------------------------------------------------------------------------------

