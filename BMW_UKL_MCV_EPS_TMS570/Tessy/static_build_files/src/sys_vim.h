/** @file sys_vim.h
*   @brief Vectored Interrupt Module Header File
*   @date 22.July.2009
*   @version 1.00.000
*   
*   This file contains:
*   - VIM Type Definitions
*   - VIM General Definitions
*   .
*   which are relevant for system driver.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

#ifndef __SYS_VIM_H__
#define __SYS_VIM_H__

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* VIM Type Definitions */

typedef void (*t_isrFuncPTR)();

/* USER CODE BEGIN (1) */
/* USER CODE END */


/* VIM General Configuration */

#define VIM_CHANNELS 64U
#define VIM_CONFIG   TRUE

/* USER CODE BEGIN (2) */
/* USER CODE END */

/* Interrupt Handlers */

#if (VIM_CONFIG == TRUE)
    extern void phantomInterrupt(void);
    extern void esmHighLevelInterrupt(void); // prathap
#if 0x00000004
    extern void rtiCompare0Interrupt(void);
#endif
#if 0x00000008
    extern void rtiCompare1Interrupt(void);
#endif
#if 0x00000010
    extern void rtiCompare2Interrupt(void);
#endif
#if 0x00000020
    extern void rtiCompare3Interrupt(void);
#endif
#if 0x00000040
    extern void rtiOverflow5Interrupt(void);
#endif
#if 0x00000080
    extern void rtiOverflow1Interrupt(void);
#endif
#if 0x00000100
    extern void rtiTimebaseInterrupt(void);
#endif
#if 0x00000200
    extern void gioHighLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel0_1(void);
#endif
#if 0x00002000
    extern void sciHighLevelInterrupt(void);
#endif
#if 0x00004000
    extern void adc1Group0Interrupt(void);
#endif
#if 0x00008000
    extern void adc1Group1Interrupt(void);
#endif
#if 0x00010000
    extern void can1HighLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00800000
    extern void gioLowLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel1_1(void);
#endif
#if 0x10000000
    extern void sciLowLevelInterrupt1(void);
#endif
#if 0x10000000
    extern void adc1Group2Interrupt(void);
#endif
#if 0x20000000
    extern void can1LowLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000008
    extern void can2HighLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel0_3(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel1_3(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000400
    extern void can2LowLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00002000
    extern void can3HighLevelInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void sciHighLevelInterrupt2(void);
#endif
#if 0x00040000
    extern void adc2Group0Interrupt(void);
#endif
#if 0x00080000
    extern void adc2Group1Interrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel0_5(void);
#endif
#if 0x00000000
    extern void sciLowLevelInterrupt2(void);
#endif
#if 0x00800000
    extern void can3LowLevelInterrupt(void);
#endif
#if 0x00000000
    extern void spiInterruptLevel1_5(void);
#endif
#if 0x02000000
    extern void adc2Group2Interrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#if 0x00000000
    extern void phantomInterrupt(void);
#endif
#endif


/* VIM Register Definition */

struct vim
{
    unsigned              : 24U;    /* 0x0000        */
    unsigned      IRQIVEC :  8U;    /* 0x0000        */
    unsigned              : 24U;    /* 0x0004        */
    unsigned      FIQIVEC :  8U;    /* 0x0004        */
    unsigned      : 32U;            /* 0x0008        */
    unsigned      : 32U;            /* 0x000C        */
    unsigned      FIRQPR0;          /* 0x0010        */
    unsigned      FIRQPR1;          /* 0x0014        */
    unsigned      FIRQPR2;          /* 0x0018        */
    unsigned      FIRQPR3;          /* 0x001C        */
    unsigned      INTREQ0;          /* 0x0020        */
    unsigned      INTREQ1;          /* 0x0024        */
    unsigned      INTREQ2;          /* 0x0028        */
    unsigned      INTREQ3;          /* 0x002C        */
    unsigned      REQMASKSET0;      /* 0x0030        */
    unsigned      REQMASKSET1;      /* 0x0034        */
    unsigned      REQMASKSET2;      /* 0x0038        */
    unsigned      REQMASKSET3;      /* 0x003C        */
    unsigned      REQMASKCLR0;      /* 0x0040        */
    unsigned      REQMASKCLR1;      /* 0x0044        */
    unsigned      REQMASKCLR2;      /* 0x0048        */
    unsigned      REQMASKCLR3;      /* 0x004C        */
    unsigned      WAKEMASKSET0;     /* 0x0050        */
    unsigned      WAKEMASKSET1;     /* 0x0054        */
    unsigned      WAKEMASKSET2;     /* 0x0058        */
    unsigned      WAKEMASKSET3;     /* 0x005C        */
    unsigned      WAKEMASKCLR0;     /* 0x0060        */
    unsigned      WAKEMASKCLR1;     /* 0x0064        */
    unsigned      WAKEMASKCLR2;     /* 0x0068        */
    unsigned      WAKEMASKCLR3;     /* 0x006C        */
    unsigned      IRQVECREG;        /* 0x0070        */
    unsigned      FIQVECREQ;        /* 0x0074        */
    unsigned                 :  9U; /* 0x0078        */
    unsigned      CAPEVTSRC1 :  7U; /* 0x0078        */
    unsigned                 :  9U; /* 0x0078        */
    unsigned      CAPEVTSRC0 :  7U; /* 0x0078        */
    unsigned      : 32U;            /* 0x007C        */
    unsigned char CHANMAP[64U];     /* 0x0080-0x017C */
};

#define VIM ((volatile struct vim *)0xFFFFFE00U)

/* USER CODE BEGIN (3) */

struct vim_parity
{
	unsigned int PARFLG;
	unsigned int PARCTL;
	unsigned int ADDERR;
	unsigned int FBPAERR;
};

#define VIM_PARITY ((volatile struct vim_parity *)0xFFFFFDECU)


/* USER CODE END */
void VIMRAM_Parity(void);

#endif
