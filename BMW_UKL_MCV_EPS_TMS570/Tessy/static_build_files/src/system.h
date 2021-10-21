/** @file system.h
*   @brief System Driver Header File
*   @date 23.July.2009
*   @version 1.00.000
*   
*   This file contains:
*   - Definitions
*   - Types
*   .
*   which are relevant for the System driver.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

#ifndef __SYS_SYSTEM_H__
#define __SYS_SYSTEM_H__

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* System General Definitions */

/** @enum systemInterrupt
*   @brief Alias names for clock sources
*
*   This enumeration is used to provide alias names for the clock sources:
*     - IRQ
*     - FIQ
*/

enum systemInterrupt
{
    SYS_IRQ, /**< Alias for IRQ interrupt */
    SYS_FIQ  /**< Alias for FIQ interrupt */
};

/** @enum systemClockSource
*   @brief Alias names for clock sources
*
*   This enumeration is used to provide alias names for the clock sources:
*     - Oscillator
*     - Pll
*     - 32 kHz Oscillator
*     - External
*     - Low Power Oscillator Low
*     - Low Power Oscillator High
*     - Flexray Pll
*     - Synchronous VCLK1
*/

enum systemClockSource
{
    SYS_OSC      = 0, /**< Alias for oscillator clock Source                */
    SYS_PLL      = 1, /**< Alias for Pll clock Source                       */
    SYS_O32      = 2, /**< Alias for 32 kHz oscillator clock Source         */
    SYS_EXTERNAL = 3, /**< Alias for external clock Source                  */
    SYS_LPO_LOW  = 4, /**< Alias for low power oscillator low clock Source  */
    SYS_LPO_HIGH = 5, /**< Alias for low power oscillator high clock Source */
    SYS_FR_PLL   = 6, /**< Alias for flexray pll clock Source               */
    SYS_VCLK     = 9  /**< Alias for synchronous VCLK1 clock Source         */
};

/** @def PRE1
*   @brief Alias name for RTI1CLK PRE clock source
*
*   This is an alias name for the RTI1CLK pre clock source.
*   This can be either:
*     - Oscillator
*     - Pll
*     - 32 kHz Oscillator
*     - External
*     - Low Power Oscillator Low
*     - Low Power Oscillator High
*     - Flexray Pll
*/
#define PRE1 SYS_PLL

/** @def PRE2
*   @brief Alias name for RTI2CLK pre clock source
*
*   This is an alias name for the RTI2CLK pre clock source.
*   This can be either:
*     - Oscillator
*     - Pll
*     - 32 kHz Oscillator
*     - External
*     - Low Power Oscillator Low
*     - Low Power Oscillator High
*     - Flexray Pll
*/
#define PRE2 SYS_PLL

/* USER CODE BEGIN (1) */
/* USER CODE END */


/* System Register Frame 1 Definition */

struct system_1
{
    unsigned SYSPC1;                 /* 0x0000 */
    unsigned SYSPC2;                 /* 0x0004 */
    unsigned SYSPC3;                 /* 0x0008 */
    unsigned SYSPC4;                 /* 0x000C */
    unsigned SYSPC5;                 /* 0x0010 */
    unsigned SYSPC6;                 /* 0x0014 */
    unsigned SYSPC7;                 /* 0x0018 */
    unsigned SYSPC8;                 /* 0x001C */
    unsigned SYSPC9;                 /* 0x0020 */
    unsigned SSWPLL1;                /* 0x0024 */
    unsigned SSWPLL2;                /* 0x0028 */
    unsigned SSWPLL3;                /* 0x002C */
    unsigned CSDIS;                  /* 0x0030 */
    unsigned CSDISSET;               /* 0x0034 */
    unsigned CSDISCLR;               /* 0x0038 */
    unsigned CSDDIS;                 /* 0x003C */
    unsigned CSDDISSET;              /* 0x0040 */
    unsigned CSDDISCLR;              /* 0x0044 */
    unsigned GHVSRC;                 /* 0x0048 */
    unsigned VCLKASRC;               /* 0x004C */
    unsigned RCLKSRC;                /* 0x0050 */
    unsigned CSVSTAT;                /* 0x0054 */
    unsigned MSTGCR;                 /* 0x0058 */
    unsigned MINITGCR;               /* 0x005C */
    unsigned MSINENA;                /* 0x0060 */
    unsigned MSTFAIL;                /* 0x0064 */
    unsigned MSTCGSTAT;              /* 0x0068 */
    unsigned MINISTAT;               /* 0x006C */
    unsigned PLLCTL1;                /* 0x0070 */
    unsigned PLLCTL2;                /* 0x0074 */
    unsigned UERFLAG;                /* 0x0078 */
    unsigned DIEIDL;                 /* 0x007C */
    unsigned DIEIDH;                 /* 0x0080 */
    unsigned VRCTL;                  /* 0x0084 */
    unsigned LPOMONCTL;              /* 0x0088 */
    unsigned CLKTEST;                /* 0x008C */
    unsigned DFTCTRLREG1;            /* 0x0090 */
    unsigned DFTCTRLREG2;            /* 0x0094 */
    unsigned : 32U;                  /* 0x0098 */
    unsigned : 32U;                  /* 0x009C */
    unsigned GPREG1;                 /* 0x00A0 */
    unsigned BTRMSEL;                /* 0x00A4 */
    unsigned IMPFASTS;               /* 0x00A8 */
    unsigned IMPFTADD;               /* 0x00AC */
    unsigned SSISR1;                 /* 0x00B0 */
    unsigned SSISR2;                 /* 0x00B4 */
    unsigned SSISR3;                 /* 0x00B8 */
    unsigned SSISR4;                 /* 0x00BC */
    unsigned RAMGCR;                 /* 0x00C0 */
    unsigned BMMCR1;                 /* 0x00C4 */
    unsigned BMMCR2;                 /* 0x00C8 */
    unsigned MMUGCR;                 /* 0x00CC */
#ifdef _little_endian__
    unsigned        : 8U;            /* 0x00D0 */
    unsigned PENA   : 1U;            /* 0x00D0 */
    unsigned        : 7U;            /* 0x00D0 */
    unsigned VCLKR  : 4U;            /* 0x00D0 */
    unsigned        : 4U;            /* 0x00D0 */
    unsigned VCLK2R : 4U;            /* 0x00D0 */
    unsigned        : 4U;            /* 0x00D0 */
#else
    unsigned        : 4U;            /* 0x00D0 */
    unsigned VCLK2R : 4U;            /* 0x00D0 */
    unsigned        : 4U;            /* 0x00D0 */
    unsigned VCLKR  : 4U;            /* 0x00D0 */
    unsigned        : 7U;            /* 0x00D0 */
    unsigned PENA   : 1U;            /* 0x00D0 */
    unsigned        : 8U;            /* 0x00D0 */
#endif
    unsigned : 32U;                  /* 0x00D4 */
    unsigned DSPGCR;                 /* 0x00D8 */
    unsigned DEVCR1;                 /* 0x00DC */
    unsigned SYSECR;                 /* 0x00E0 */
    unsigned SYSESR;                 /* 0x00E4 */
    unsigned ITIFLAG;                /* 0x00E8 */
    unsigned GBLSTAT;                /* 0x00EC */
    unsigned DEV;                    /* 0x00F0 */
    unsigned SSIVEC;                 /* 0x00F4 */
    unsigned SSIF;                   /* 0x00F8 */
};

/** @def SYSTEM_1
*   @brief System Register Frame 1 Pointer
*
*   This pointer is used by the system driver to access the system frame 1 registers.
*/

#define SYSTEM_1 ((volatile struct system_1 *)0xFFFFFF00U)

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* System Register Frame 2 Definition */

struct system_2
{
    unsigned PLLCTL3;        /* 0x0000 */
    unsigned : 32U;          /* 0x0004 */
    unsigned STCCLKDIV;      /* 0x0008 */
    unsigned CLKHB_GLBREG;   /* 0x000C */
    unsigned CLKHB_RTIDREG;  /* 0x0010 */
    unsigned HBCD_STAT;      /* 0x0014 */
    unsigned : 32U;          /* 0x0018 */
    unsigned : 32U;          /* 0x001C */
    unsigned CLKTRMI1;       /* 0x0020 */
    unsigned ECPCNTRL0;      /* 0x0024 */
    unsigned ECPCNTRL1;      /* 0x0028 */
    unsigned ECPCNTRL2;      /* 0x002C */
    unsigned ECPCNTRL3;      /* 0x0030 */
};

/** @def SYSTEM_2
*   @brief System Register Frame 2 Pointer
*
*   This pointer is used by the system driver to access the system frame 2 registers.
*/

#define SYSTEM_2 ((volatile struct system_2 *)0xFFFFE100U)

/* USER CODE BEGIN (3) */
/* USER CODE END */


/* PCR Register Definition */

struct pcr
{
    unsigned PMPROTSET0;    /* 0x0000 */
    unsigned PMPROTSET1;    /* 0x0004 */
    unsigned : 32U;         /* 0x0008 */
    unsigned : 32U;         /* 0x000C */
    unsigned PMPROTCLR0;    /* 0x0010 */
    unsigned PMPROTCLR1;    /* 0x0014 */
    unsigned : 32U;         /* 0x0018 */
    unsigned : 32U;         /* 0x001C */
    unsigned PPROTSET0;     /* 0x0020 */
    unsigned PPROTSET1;     /* 0x0024 */
    unsigned PPROTSET2;     /* 0x0028 */
    unsigned PPROTSET3;     /* 0x002C */
    unsigned : 32U;         /* 0x0030 */
    unsigned : 32U;         /* 0x0034 */
    unsigned : 32U;         /* 0x0038 */
    unsigned : 32U;         /* 0x003C */
    unsigned PPROTCLR0;     /* 0x0040 */
    unsigned PPROTCLR1;     /* 0x0044 */
    unsigned PPROTCLR2;     /* 0x0048 */
    unsigned PPROTCLR3;     /* 0x004C */
    unsigned : 32U;         /* 0x0050 */
    unsigned : 32U;         /* 0x0054 */
    unsigned : 32U;         /* 0x0058 */
    unsigned : 32U;         /* 0x005C */
    unsigned PCSPWRDWNSET0; /* 0x0060 */
    unsigned PCSPWRDWNSET1; /* 0x0064 */
    unsigned : 32U;         /* 0x0068 */
    unsigned : 32U;         /* 0x006C */
    unsigned PCSPWRDWNCLR0; /* 0x0070 */
    unsigned PCSPWRDWNCLR1; /* 0x0074 */
    unsigned : 32U;         /* 0x0078 */
    unsigned : 32U;         /* 0x007C */
    unsigned PSPWRDWNSET0;  /* 0x0080 */
    unsigned PSPWRDWNSET1;  /* 0x0084 */
    unsigned PSPWRDWNSET2;  /* 0x0088 */
    unsigned PSPWRDWNSET3;  /* 0x008C */
    unsigned : 32U;         /* 0x0090 */
    unsigned : 32U;         /* 0x0094 */
    unsigned : 32U;         /* 0x0098 */
    unsigned : 32U;         /* 0x009C */
    unsigned PSPWRDWNCLR0;  /* 0x00A0 */
    unsigned PSPWRDWNCLR1;  /* 0x00A4 */
    unsigned PSPWRDWNCLR2;  /* 0x00A8 */
    unsigned PSPWRDWNCLR3;  /* 0x00AC */
};

/** @def PCR
*   @brief PCR Register Frame Pointer
*
*   This pointer is used by the system driver to access the PCR registers.
*/

#define PCR ((volatile struct pcr *)0xFFFFE000U)

/* USER CODE BEGIN (4) */
/* USER CODE END */


/* FlashW General Definitions */


/** @enum flashWPowerModes
*   @brief Alias names for flash bank power modes
*
*   This enumeration is used to provide alias names for the flash bank power modes:
*     - sleep
*     - standby
*     - active
*/

enum flashWPowerModes
{
    SYS_SLEEP   = 0U, /**< Alias for flash bank power mode sleep   */
    SYS_STANDBY = 1U, /**< Alias for flash bank power mode standby */
    SYS_ACTIVE  = 3U  /**< Alias for flash bank power mode active  */
};

/* USER CODE BEGIN (5) */
/* USER CODE END */


/* FlashW Register Definition */

#ifdef _little_endian__
struct flashW
{
    unsigned FRDCNTL       : 16U; /* 0x0000 */
    unsigned               : 16U; /* 0x0000 */
    unsigned FSPRD         : 16U; /* 0x0004 */
    unsigned               : 16U; /* 0x0004 */
    unsigned FEDACCTRL1    : 16U; /* 0x0008 */
    unsigned               : 16U; /* 0x0008 */
    unsigned FEDACCTRL2    : 16U; /* 0x000C */
    unsigned               : 16U; /* 0x000C */
    unsigned FEDACCNT      : 16U; /* 0x0010 */
    unsigned               : 16U; /* 0x0010 */
    unsigned FCERADDR;            /* 0x0014 */
    unsigned FCERRPOSITION : 16U; /* 0x0018 */
    unsigned               : 16U; /* 0x0018 */
    unsigned FEDACSTATUS   : 16U; /* 0x001C */
    unsigned               : 16U; /* 0x001C */
    unsigned FUERRADDR;           /* 0x0020 */
    unsigned FEDACSDIS;           /* 0x0024 */
    unsigned : 32U;               /* 0x0028 */
    unsigned : 32U;               /* 0x002C */
    unsigned FBPROT        : 16U; /* 0x0030 */
    unsigned               : 16U; /* 0x0030 */
    unsigned FBSE          : 16U; /* 0x0034 */
    unsigned               : 16U; /* 0x0034 */
    unsigned FBBUSY        : 16U; /* 0x0038 */
    unsigned               : 16U; /* 0x0038 */
    unsigned VREADST       :  8U; /* 0x003C */
    unsigned BAGP          :  8U; /* 0x003C */
    unsigned OTPPROTDIS    :  8U; /* 0x003C */
    unsigned               :  8U; /* 0x003C */
    unsigned FBFALLBACK    : 16U; /* 0x0040 */
    unsigned               : 16U; /* 0x0040 */
    unsigned FBPRDY        : 16U; /* 0x0044 */
    unsigned               : 16U; /* 0x0044 */
    unsigned PUMPPWR       :  1U; /* 0x0048 */
    unsigned               : 15U; /* 0x0048 */
    unsigned PSLEEP        : 10U; /* 0x0048 */
    unsigned               :  6U; /* 0x0048 */
    unsigned FPAC2         : 16U; /* 0x004C */
    unsigned               : 16U; /* 0x004C */
    unsigned FMAC          : 16U; /* 0x0050 */
    unsigned               : 16U; /* 0x0050 */
    unsigned FMSTAT        : 16U; /* 0x0054 */
    unsigned               : 16U; /* 0x0054 */
    unsigned FEMUDLSW;            /* 0x005C */
    unsigned FEMUDMSW;            /* 0x0058 */
    unsigned FEMUECC       : 16U; /* 0x0060 */
    unsigned               : 16U; /* 0x0060 */
    unsigned FLOCK         : 16U; /* 0x0064 */
    unsigned               : 16U; /* 0x0064 */
    unsigned FENUADDR;            /* 0x0068 */
    unsigned FDIAGCTRL;           /* 0x006C */
    unsigned FRAWDATAH;           /* 0x0070 */
    unsigned FRAWDATAL;           /* 0x0074 */
    unsigned FRAWECC;             /* 0x0078 */
    unsigned FPRIMADDTAG;         /* 0x007C */
    unsigned FVREADCT      : 16U; /* 0x0080 */
    unsigned               : 16U; /* 0x0080 */
    unsigned FVHVCT1;             /* 0x0084 */
    unsigned FVHVCT2       : 16U; /* 0x0088 */
    unsigned               : 16U; /* 0x0088 */
    unsigned FVNVCT        : 16U; /* 0x008C */
    unsigned               : 16U; /* 0x008C */
    unsigned FVPPCT        : 16U; /* 0x0090 */
    unsigned               : 16U; /* 0x0090 */
    unsigned FVWLCT        : 16U; /* 0x0094 */
    unsigned               : 16U; /* 0x0094 */
    unsigned : 32U;               /* 0x0098 */
    unsigned : 32U;               /* 0x009C */
    unsigned FBSTROBES;           /* 0x0100 */
    unsigned FPSTROBES     : 16U; /* 0x0104 */
    unsigned               : 16U; /* 0x0104 */
    unsigned FBMODE        : 16U; /* 0x0108 */
    unsigned               : 16U; /* 0x0108 */
    unsigned FTCR          : 16U; /* 0x010C */
    unsigned               : 16U; /* 0x010C */
    unsigned FADDR;               /* 0x0110 */
    unsigned FWRITE        : 16U; /* 0x0114 */
    unsigned               : 16U; /* 0x0114 */
    unsigned FCBIT_SEL     : 16U; /* 0x0118 */
    unsigned               : 16U; /* 0x0118 */
    unsigned FTCTRL        : 16U; /* 0x011C */
    unsigned               : 16U; /* 0x011C */
    unsigned FWPWRITE0;           /* 0x0120 */
    unsigned FWPWRITE1;           /* 0x0124 */
    unsigned FWPWRITE2;           /* 0x0128 */
    unsigned FWPWRITE3;           /* 0x012C */
    unsigned FWPWRITE4;           /* 0x0130 */
};
#else
struct flashW
{
    unsigned               : 16U; /* 0x0000 */
    unsigned FRDCNTL       : 16U; /* 0x0000 */
    unsigned               : 16U; /* 0x0004 */
    unsigned FSPRD         : 16U; /* 0x0004 */
    unsigned               : 16U; /* 0x0008 */
    unsigned FEDACCTRL1    : 16U; /* 0x0008 */
    unsigned               : 16U; /* 0x000C */
    unsigned FEDACCTRL2    : 16U; /* 0x000C */
    unsigned               : 16U; /* 0x0010 */
    unsigned FEDACCNT      : 16U; /* 0x0010 */
    unsigned FCERADDR;            /* 0x0014 */
    unsigned               : 16U; /* 0x0018 */
    unsigned FCERRPOSITION : 16U; /* 0x0018 */
    unsigned               : 16U; /* 0x001C */
    unsigned FEDACSTATUS   : 16U; /* 0x001C */
    unsigned FUERRADDR;           /* 0x0020 */
    unsigned FEDACSDIS;           /* 0x0024 */
    unsigned : 32U;               /* 0x0028 */
    unsigned : 32U;               /* 0x002C */
    unsigned               : 16U; /* 0x0030 */
    unsigned FBPROT        : 16U; /* 0x0030 */
    unsigned               : 16U; /* 0x0034 */
    unsigned FBSE          : 16U; /* 0x0034 */
    unsigned               : 16U; /* 0x0038 */
    unsigned FBBUSY        : 16U; /* 0x0038 */
    unsigned               :  8U; /* 0x003C */
    unsigned OTPPROTDIS    :  8U; /* 0x003C */
    unsigned BAGP          :  8U; /* 0x003C */
    unsigned VREADST       :  8U; /* 0x003C */
    unsigned               : 16U; /* 0x0040 */
    unsigned FBFALLBACK    : 16U; /* 0x0040 */
    unsigned               : 16U; /* 0x0044 */
    unsigned FBPRDY        : 16U; /* 0x0044 */
    unsigned               :  6U; /* 0x0048 */
    unsigned PSLEEP        : 10U; /* 0x0048 */
    unsigned               : 15U; /* 0x0048 */
    unsigned PUMPPWR       :  1U; /* 0x0048 */
    unsigned               : 16U; /* 0x004C */
    unsigned FPAC2         : 16U; /* 0x004C */
    unsigned               : 16U; /* 0x0050 */
    unsigned FMAC          : 16U; /* 0x0050 */
    unsigned               : 16U; /* 0x0054 */
    unsigned FMSTAT        : 16U; /* 0x0054 */
    unsigned FEMUDMSW;            /* 0x0058 */
    unsigned FEMUDLSW;            /* 0x005C */
    unsigned               : 16U; /* 0x0060 */
    unsigned FEMUECC       : 16U; /* 0x0060 */
    unsigned               : 16U; /* 0x0064 */
    unsigned FLOCK         : 16U; /* 0x0064 */
    unsigned FENUADDR;            /* 0x0068 */
    unsigned FDIAGCTRL;           /* 0x006C */
    unsigned FRAWDATAH;           /* 0x0070 */
    unsigned FRAWDATAL;           /* 0x0074 */
    unsigned FRAWECC;             /* 0x0078 */
    unsigned FPRIMADDTAG;         /* 0x007C */
    unsigned               : 16U; /* 0x0080 */
    unsigned FVREADCT      : 16U; /* 0x0080 */
    unsigned FVHVCT1;             /* 0x0084 */
    unsigned               : 16U; /* 0x0088 */
    unsigned FVHVCT2       : 16U; /* 0x0088 */
    unsigned               : 16U; /* 0x008C */
    unsigned FVNVCT        : 16U; /* 0x008C */
    unsigned               : 16U; /* 0x0090 */
    unsigned FVPPCT        : 16U; /* 0x0090 */
    unsigned               : 16U; /* 0x0094 */
    unsigned FVWLCT        : 16U; /* 0x0094 */
    unsigned : 32U;               /* 0x0098 */
    unsigned : 32U;               /* 0x009C */
    unsigned FBSTROBES;           /* 0x0100 */
    unsigned               : 16U; /* 0x0104 */
    unsigned FPSTROBES     : 16U; /* 0x0104 */
    unsigned               : 16U; /* 0x0108 */
    unsigned FBMODE        : 16U; /* 0x0108 */
    unsigned               : 16U; /* 0x010C */
    unsigned FTCR          : 16U; /* 0x010C */
    unsigned FADDR;               /* 0x0110 */
    unsigned               : 16U; /* 0x0114 */
    unsigned FWRITE        : 16U; /* 0x0114 */
    unsigned               : 16U; /* 0x0118 */
    unsigned FCBIT_SEL     : 16U; /* 0x0118 */
    unsigned               : 16U; /* 0x011C */
    unsigned FTCTRL        : 16U; /* 0x011C */
    unsigned FWPWRITE0;           /* 0x0120 */
    unsigned FWPWRITE1;           /* 0x0124 */
    unsigned FWPWRITE2;           /* 0x0128 */
    unsigned FWPWRITE3;           /* 0x012C */
    unsigned FWPWRITE4;           /* 0x0130 */
};
#endif

/** @def FLASHW
*   @brief Flash Wrapper Register Frame Pointer
*
*   This pointer is used by the system driver to access the flash wrapper registers.
*/

#define FLASHW ((volatile struct flashW *)(0xFFF87000U))

/* USER CODE BEGIN (6) */
/* USER CODE END */


/* RamW Register Definition */

#ifdef _little_endian__
struct ramW
{
    unsigned CTRL;              /* 0x0000 */
    unsigned THRES : 16U;       /* 0x0004 */
    unsigned       : 16U;       /* 0x0004 */
    unsigned OCCUR : 16U;       /* 0x0008 */
    unsigned       : 16U;       /* 0x0008 */
    unsigned INTCTRL :  1U;     /* 0x000C */
    unsigned         : 31U;     /* 0x000C */
    unsigned ERRSTATUS : 16U;   /* 0x0010 */
    unsigned           : 16U;   /* 0x0010 */
    unsigned          :  3U;    /* 0x0014 */
    unsigned SERRADDR : 15U;    /* 0x0014 */
    unsigned          : 14U;    /* 0x0014 */
    unsigned : 32U;             /* 0x0018 */
    unsigned          :  3U;    /* 0x001C */
    unsigned UERRADDR : 20U;    /* 0x001C */
    unsigned          :  9U;    /* 0x001C */
    unsigned : 32U;             /* 0x0020 */
    unsigned : 32U;             /* 0x0024 */
    unsigned : 32U;             /* 0x0028 */
    unsigned TEST : 16U;        /* 0x0030 */
    unsigned      : 16U;        /* 0x0030 */
    unsigned : 32U;             /* 0x0034 */
    unsigned ADDRDECU;          /* 0x0038 */
    unsigned          :  3U;    /* 0x003C */
    unsigned PERRADDR : 20U;    /* 0x003C */
    unsigned          :  9U;    /* 0x003C */
};
#else
struct ramW
{
    unsigned CTRL;              /* 0x0000 */
    unsigned       : 16U;       /* 0x0004 */
    unsigned THRES : 16U;       /* 0x0004 */
    unsigned       : 16U;       /* 0x0008 */
    unsigned OCCUR : 16U;       /* 0x0008 */
    unsigned         : 31U;     /* 0x000C */
    unsigned INTCTRL :  1U;     /* 0x000C */
    unsigned           : 16U;   /* 0x0010 */
    unsigned ERRSTATUS : 16U;   /* 0x0010 */
    unsigned          : 14U;    /* 0x0014 */
    unsigned SERRADDR : 15U;    /* 0x0014 */
    unsigned          :  3U;    /* 0x0014 */
    unsigned : 32U;             /* 0x0018 */
    unsigned          :  9U;    /* 0x001C */
    unsigned UERRADDR : 20U;    /* 0x001C */
    unsigned          :  3U;    /* 0x001C */
    unsigned : 32U;             /* 0x0020 */
    unsigned : 32U;             /* 0x0024 */
    unsigned : 32U;             /* 0x0028 */
    unsigned      : 16U;        /* 0x0030 */
    unsigned TEST : 16U;        /* 0x0030 */
    unsigned : 32U;             /* 0x0034 */
    unsigned ADDRDECU;          /* 0x0038 */
    unsigned          :  9U;    /* 0x003C */
    unsigned PERRADDR : 20U;    /* 0x003C */
    unsigned          :  3U;    /* 0x003C */
};
#endif

/** @def RAMW_0
*   @brief RAM Wrapper Even Register Frame Pointer
*
*   This pointer is used by the system driver to access the RAM wrapper even registers.
*/

#define RAMW_0 ((volatile struct ramW *)(0xFFFFF800U))

/** @def RAMW_1
*   @brief RAM Wrapper Odd Register Frame Pointer
*
*   This pointer is used by the system driver to access the RAM wrapper odd registers.
*/

#define RAMW_1 ((volatile struct ramW *)(0xFFFFF900U))

/* USER CODE BEGIN (7) */
/* USER CODE END */


/* System Interface Functions */

extern void systemInit(void);
void ATCM_Correctable_Error(void);
/* USER CODE BEGIN (8) */
/* USER CODE END */


#endif
