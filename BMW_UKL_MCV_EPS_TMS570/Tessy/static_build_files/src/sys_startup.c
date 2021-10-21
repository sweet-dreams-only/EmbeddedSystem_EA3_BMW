/** @file startupPSFC66.c 
*   @brief Startup Source File
*   @date 15.July.2009
*   @version 1.00.000
*
*   This file contains:
*   - Include Files
*   - Type Definitions
*   - External Functions
*   - VIM RAM Setup
*   - Startup Routine
*   .
*   which are relevant for the RTI driver.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "sys_common.h"
#include "system.h"
#include "sys_vim.h"
#include "stc.h"

extern void _Continue_after_STC(void);

/* Type Definitions */

typedef void (*handler_fptr)(const unsigned char *in, unsigned char *out);

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* External Functions */

#pragma WEAK(__TI_Handler_Table_Base)
#pragma WEAK(__TI_Handler_Table_Limit)
#pragma WEAK(__TI_CINIT_Base)
#pragma WEAK(__TI_CINIT_Limit)

extern unsigned   __TI_Handler_Table_Base;
extern unsigned   __TI_Handler_Table_Limit;
extern unsigned   __TI_CINIT_Base;
extern unsigned   __TI_CINIT_Limit;
extern unsigned   __TI_PINIT_Base;
extern unsigned   __TI_PINIT_Limit;
extern unsigned * __binit__;

extern void main(void);
extern void exit(void);

extern void _coreInitRegisters_(void);
extern void _coreInitStackPointer_(void);
extern void _coreSetUserModeSync_(void);

#if (__TI_VFPV3D16_SUPPORT__ == 1)
    extern void _coreEnableVfp_(void);
#endif

/* USER CODE BEGIN (3) */
/* USER CODE END */


/* VIM */

#if (VIM_CONFIG == TRUE)
    struct vim_ram
    {
        t_isrFuncPTR ISR[VIM_CHANNELS];
    };

    #define VIM_RAM ((volatile struct vim_ram *)0xFFF82000U)

    static const t_isrFuncPTR s_vim_init[] =
    {
        phantomInterrupt,
        esmHighLevelInterrupt,
        phantomInterrupt,
#if 0x00000004
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000008
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000010
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000020
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000040
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000080
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000100
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000200
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000400
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000800
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00001000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00002000
        sciHighLevelInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00004000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00008000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00010000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00020000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00040000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00080000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00100000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00200000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00400000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00800000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x01000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x02000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x04000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x08000000
        sciLowLevelInterrupt1,
#else
        phantomInterrupt,
#endif
#if 0x10000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x20000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x40000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x80000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000008
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000400
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00002000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        sciHighLevelInterrupt2,
#else
        phantomInterrupt,
#endif
#if 0x00040000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00080000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00800000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x02000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
#if 0x00000000
        phantomInterrupt,
#else
        phantomInterrupt,
#endif
    };
#endif


/* Startup Routine */

/* USER CODE BEGIN (4) */
/* USER CODE END */

#pragma INTERRUPT(_c_int00, RESET)

void _c_int00()
{
    /* Enable VFP Unit */
#if (__TI_VFPV3D16_SUPPORT__ == 1)
    _coreEnableVfp_();
#endif

    /* Initialize Core Registers */
    _coreInitRegisters_();

	if((stcREG->STCGSTAT & 0x3) == 1)
	{
		_Continue_after_STC();
	}

    /* Initialize Stack Pointers */
    _coreInitStackPointer_();

    /* Initialize System */
    systemInit();

#if (VIM_CONFIG == TRUE)
    /* Initialize VIM table */
    {
        unsigned i;

        for (i = 0; i < 64U; i++)
        {
            VIM_RAM->ISR[i] = s_vim_init[i];
        }
    }
    /* set IRQ/FIQ priorities */
    VIM->FIRQPR0 =  SYS_FIQ
                 | (SYS_FIQ <<  1U)
                 | (SYS_FIQ <<  2U)
                 | (SYS_IRQ <<  3U)
                 | (SYS_IRQ <<  4U)
                 | (SYS_IRQ <<  5U)
                 | (SYS_IRQ <<  6U)
                 | (SYS_IRQ <<  7U)
                 | (SYS_IRQ <<  8U)
                 | (SYS_IRQ <<  9U)
                 | (SYS_IRQ << 10U)
                 | (SYS_IRQ << 11U)
                 | (SYS_IRQ << 12U)
                 | (SYS_IRQ << 13U)
                 | (SYS_IRQ << 14U)
                 | (SYS_IRQ << 15U)
                 | (SYS_IRQ << 16U)
                 | (SYS_IRQ << 17U)
                 | (SYS_IRQ << 18U)
                 | (SYS_IRQ << 19U)
                 | (SYS_IRQ << 20U)
                 | (SYS_IRQ << 21U)
                 | (SYS_IRQ << 22U)
                 | (SYS_IRQ << 23U)
                 | (SYS_IRQ << 24U)
                 | (SYS_IRQ << 25U)
                 | (SYS_IRQ << 26U)
                 | (SYS_IRQ << 27U)
                 | (SYS_IRQ << 28U)
                 | (SYS_IRQ << 29U)
                 | (SYS_IRQ << 30U)
                 | (SYS_IRQ << 31U);

    VIM->FIRQPR1 =  SYS_IRQ
                 | (SYS_IRQ <<  1U)
                 | (SYS_IRQ <<  2U)
                 | (SYS_IRQ <<  3U)
                 | (SYS_IRQ <<  4U)
                 | (SYS_IRQ <<  5U)
                 | (SYS_IRQ <<  6U)
                 | (SYS_IRQ <<  7U)
                 | (SYS_IRQ <<  8U)
                 | (SYS_IRQ <<  9U)
                 | (SYS_IRQ << 10U)
                 | (SYS_IRQ << 11U)
                 | (SYS_IRQ << 12U)
                 | (SYS_IRQ << 13U)
                 | (SYS_IRQ << 14U)
                 | (SYS_IRQ << 15U)
                 | (SYS_IRQ << 16U)
                 | (SYS_IRQ << 17U)
                 | (SYS_IRQ << 18U)
                 | (SYS_IRQ << 19U)
                 | (SYS_IRQ << 20U)
                 | (SYS_IRQ << 21U)
                 | (SYS_IRQ << 22U)
                 | (SYS_IRQ << 23U)
                 | (SYS_IRQ << 24U)
                 | (SYS_IRQ << 25U)
                 | (SYS_IRQ << 26U)
                 | (SYS_IRQ << 27U)
                 | (SYS_IRQ << 28U)
                 | (SYS_IRQ << 29U)
                 | (SYS_IRQ << 30U);

    /* enable interrupts */
    VIM->REQMASKSET0 = 0x00000001U
                     | 0x00000000U
                     | 0x00000004U
                     | 0x00000008U
                     | 0x00000010U
                     | 0x00000020U
                     | 0x00000040U
                     | 0x00000080U
                     | 0x00000100U
                     | 0x00000200U
                     | 0x00000400U
                     | 0x00000800U
                     | 0x00001000U
                     | 0x00002000U
                     | 0x00004000U
                     | 0x00008000U
                     | 0x00010000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00800000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x10000000U
                     | 0x20000000U
                     | 0x00000000U
                     | 0x00000000U;

    VIM->REQMASKSET1 = 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000008U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000400U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00002000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00040000U
                     | 0x00080000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00800000U
                     | 0x00000000U
                     | 0x02000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U
                     | 0x00000000U;

#endif

    /* initalise copy table */
    if ((unsigned *)&__binit__ != (unsigned *)0xFFFFFFFF)
    {
        extern void copy_in(void *binit);
        copy_in((void *)&__binit__);
    }

    /* initalise the C global variables */
    if (&__TI_Handler_Table_Base < &__TI_Handler_Table_Limit)
    {
        unsigned char **tablePtr   = (unsigned char **)&__TI_CINIT_Base;
        unsigned char **tableLimit = (unsigned char **)&__TI_CINIT_Limit;

        while (tablePtr < tableLimit)
        {
            unsigned char *loadAdr = *tablePtr++;
            unsigned char *runAdr  = *tablePtr++;
            unsigned char  idx     = *loadAdr++;
            handler_fptr   handler = (handler_fptr)(&__TI_Handler_Table_Base)[idx];

            (*handler)((const unsigned char *)loadAdr, runAdr);
        }
    }

    /* initalise contructors */
    if (__TI_PINIT_Base < __TI_PINIT_Limit)
    {
        void (**p0)() = (void *)__TI_PINIT_Base;

        while ((unsigned)p0 < __TI_PINIT_Limit)
        {
            void (*p)() = *p0++;
            p();
        }
    }

    /* call the application */
    main();
    exit();
}
