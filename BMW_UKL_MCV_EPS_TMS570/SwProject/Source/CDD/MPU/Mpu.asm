
;******************************************************************************
; FUNCTION INFO
;NAME:
; CP15_ENABLE_MPU
;
;DESCRIPTION:
;
; Arguments:
; REG - register to use as scratch pad
;
;******************************************************************************
CP15_ENABLE_MPU: .macro REG
	mrc P15, #0, REG, C1, C0, #$C1C0_SCTRL
	orr REG, REG, #$C1C0_SCTLR_M_MASK
	dmb
	mcr P15, #0, REG, C1, C0, #$C1C0_SCTRL
	isb
	.endm

;******************************************************************************
; FUNCTION INFO
;NAME:
; CP15_DISABLE_MPU
;
;DESCRIPTION:
;
; Arguments:
; REG - register to use as scratch pad
;
;******************************************************************************
CP15_DISABLE_MPU: .macro REG
	mrc p15, #0, REG, C1, C0, #$C1C0_SCTRL ; read CP15
	BIC REG, REG, #0x1
	DSB
	mcr P15, #0, REG, C1, C0, #$C1C0_SCTRL ; disable MPU
	isb
	.endm

;******************************************************************************
; FUNCTION INFO
;NAME:
; CP15_SET_MPU_REGION
;
;DESCRIPTION:
;
; Arguments:
; r0_NUM - region number
; r1_ADDR - region base address
; r2_SIZE - region size and control bits
; r3_CTRL - region access control
;
;******************************************************************************
CP15_SET_MPU_REGION: .macro r0_NUM, r1_ADDR, r2_SIZE, r3_CTRL
	mcr P15, #0, r0_NUM, C6, C2, #$C6C2_MPU_REGION_NUMBER
	mcr P15, #0, r1_ADDR, C6, C1, #$C6C1_MPU_BASE_REGION_ADDR
	mcr P15, #0, r2_SIZE, C6, C1, #$C6C1_MPU_SIZE_AND_ENABLE
	mcr P15, #0, r3_CTRL, C6, C1, #$C6C1_MPU_ACCESS_CNTRL

	.endm

$C1C0_SCTRL .equ 0
$C1C0_SCTLR_M_MASK .equ (1 << 0)

;******************************************************************************
;
; PRIVATE VARIABLE DECLARATIONS
;
;******************************************************************************
$MEM_FRAME_SIZE .equ $C6C1_MPU_SIZE_4G
$ITCM_FRAME_SIZE .equ $C6C1_MPU_SIZE_2M
$DTCM_FRAME_SIZE .equ $C6C1_MPU_SIZE_2M
$HPI_FRAME_SIZE .equ $C6C1_MPU_SIZE_8M
$PERIPHERAL_FRAME_SIZE .equ $C6C1_MPU_SIZE_32M

$MEM_MPU_REGION .equ 0
$ITCM_MPU_REGION .equ 1
$DTCM_MPU_REGION .equ 2
$HPI_MPU_REGION .equ 4
$PERIPHERAL_MPU_REGION .equ 3
$ADVANCED_TEST_REGION .equ 5

$Dtcm_Frame_Start .long 0x08000000
$Hpi_Frame_Start .long 0xFD000000
$Periph_Frame_Start .long 0xFE000000


;******************************************************************************
;
; PRIVATE DEFINITIONS
;
;******************************************************************************
; CP15 C6 MPU REGION PROGRAMMING REGISTERS
$C6C1_MPU_BASE_REGION_ADDR .equ 0
$C6C1_MPU_SIZE_AND_ENABLE .equ 2
$C6C1_MPU_ACCESS_CNTRL .equ 4
$C6C2_MPU_REGION_NUMBER .equ 0

$MPU_NUM_OF_REGIONS .equ 8

; CP15 C6 MPU PROGRAMMING DEFINITIONS
; C6C1_MPU_SIZE_AND_ENABLE:
; MPU sub-region enable control
$C6C1_MPU_EN_ALL_SUBREG .equ 0
$C6C1_MPU_DIS_ALL_SUBREG .equ 0x0000F0

;Here an individual configuration of enabled/disabled subregions can be added

; MPU region esizes
$C6C1_MPU_SIZE_32 .equ (00100B << 1)
$C6C1_MPU_SIZE_64 .equ (00101B << 1)
$C6C1_MPU_SIZE_128 .equ (00110B << 1)
$C6C1_MPU_SIZE_256 .equ (00111B << 1)
$C6C1_MPU_SIZE_512 .equ (01000B << 1)
$C6C1_MPU_SIZE_1K .equ (01001B << 1)
$C6C1_MPU_SIZE_2K .equ (01010B << 1)
$C6C1_MPU_SIZE_4K .equ (01011B << 1)
$C6C1_MPU_SIZE_8K .equ (01100B << 1)
$C6C1_MPU_SIZE_16K .equ (01101B << 1)
$C6C1_MPU_SIZE_32K .equ (01110B << 1)
$C6C1_MPU_SIZE_64K .equ (01111B << 1)
$C6C1_MPU_SIZE_128K .equ (10000B << 1)
$C6C1_MPU_SIZE_256K .equ (10001B << 1)
$C6C1_MPU_SIZE_512K .equ (10010B << 1)
$C6C1_MPU_SIZE_1M .equ (10011B << 1)
$C6C1_MPU_SIZE_2M .equ (10100B << 1)
$C6C1_MPU_SIZE_4M .equ (10101B << 1)
$C6C1_MPU_SIZE_8M .equ (10110B << 1)
$C6C1_MPU_SIZE_16M .equ (10111B << 1)
$C6C1_MPU_SIZE_32M .equ (11000B << 1)
$C6C1_MPU_SIZE_64M .equ (11001B << 1)
$C6C1_MPU_SIZE_128M .equ (11010B << 1)
$C6C1_MPU_SIZE_256M .equ (11011B << 1)
$C6C1_MPU_SIZE_512M .equ (11100B << 1)
$C6C1_MPU_SIZE_1G .equ (11101B << 1)
$C6C1_MPU_SIZE_2G .equ (11110B << 1)
$C6C1_MPU_SIZE_4G .equ (11111B << 1)
; MPU region enable control
$C6C1_MPU_EN_REG .equ 1
$C6C1_MPU_DIS_REG .equ 0

; C6C1_MPU_ACCESS_CNTRL
; XN: Execution control

$C6C1_MPU_EXE_ALWAYS .equ 0
$C6C1_MPU_EXE_NEVER .equ (1 << 12)
; AP: Privileged/User Read/Write control
$C6C1_MPU_NO_ACCESS .equ (000B << 8)
$C6C1_MPU_RP_WP .equ (001B << 8)
$C6C1_MPU_RPU_WP .equ (010B << 8)
$C6C1_MPU_RPU_WPU .equ (011B << 8)
$C6C1_MPU_RP .equ (101B << 8)
$C6C1_MPU_RPU .equ (110B << 8)
; S: Sharability
$C6C1_MPU_NON_SHARED .equ 0
$C6C1_MPU_SHARED .equ (1 << 2)
; C: Cacheability
$C6C1_MPU_NON_CACHED .equ 0
$C6C1_MPU_CACHED .equ (1 << 1)
; B: Bufferability
$C6C1_MPU_NON_BUFFERED .equ 0
$C6C1_MPU_BUFFERED .equ 1

; The Region Access Control Registers use five bits to encode the memory
; region type.These are TEX[2:0], and the C and B bits.
; Additionally, the Region Access Control Registers contain
; the shared bit, S. This bit only applies to Normal memory, and determines
; if the memory region is Shared (1), or Non-Shared (0).

; Normal, non-cachable, non-shared
$C6C1_MPU_NORMAL .equ ((001B << 3) | ($C6C1_MPU_NON_CACHED | $C6C1_MPU_NON_BUFFERED | $C6C1_MPU_NON_SHARED))
; Device, non-cachable, non-shared
$C6C1_MPU_DEVICE .equ ((000B << 3) | ($C6C1_MPU_NON_CACHED | $C6C1_MPU_NON_BUFFERED | $C6C1_MPU_NON_SHARED))


	.text
	.arm

	.global Mpu_Disable
	.global Mpu_Enable

	.asmfunc
Mpu_Enable:
	; Enable MPU
	CP15_ENABLE_MPU r0
	bx lr
	.endasmfunc

	.asmfunc
Mpu_Disable:
	; Disable MPU
	CP15_DISABLE_MPU r0
	bx lr
	.endasmfunc
	
	