/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Spi_Dlc.h
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr Module Spi_Dlc.h
 *    Generator:  -
 *
 *  Description:  This file implements the Spi_Dlc low level driver, handling of channels and transmission settings.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Arne van Mourik               Va            Vctr Informatik GmbH
 *  Manfred Duschinger            Du            Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.01.00  2009-03-31  Va      ESCAN00026205 first full release of Spi driver.
 *  01.02.00  2010-03-08  Va      ESCAN00033094 TMS570 Spi, ensure post-build abilitiy.
 *                        Va      ESCAN00035114 Add memory section <MSN>_PBCFG_ROOT.
 *                        Va      ESCAN00038868 Assure library ability of the component.
 *                        Va      ESCAN00041173 Spi driver state is not pre-initialized at startup.
 *                        Va      ESCAN00041174 Check and rework findings in compiler Abstraction for the Spi driver
 *                        Va      ESCAN00041175 Spi Sequence queuing fails.
 *                        Va      ESCAN00041177 Data sampling when using Spi Mode 2 or 3 is generated wrong
 *                        Va      ESCAN00041178 A  sequence assignment was overwritten if a job collision was detected.
 *                        Va      ESCAN00041259 Add support for 16-bit frame transfers to the Spi driver.
 *  01.02.01  2010-03-23  Va      ESCAN00041764 Spi - Cs does not work as expected
 *                        Va      ESCAN00041450 BETA version - no series production allowed
 *  01.02.02  2010-04-21  Du      ESCAN00042139 Data Abort Exception occurs during runtime
 *  01.03.00  2010-06-23  Va      ESCAN00041874 Make chip select periods configurable for chip select handling after
 *                                              each word
 *                        Va      ESCAN00041875 Channel buffer size is limited to 255 bytes only
 *                        Va      ESCAN00041877 Transmission groups using 128 words in MibRAM
 *                        Va      ESCAN00042045 Spi - driver does not transmit data if Development error detection is
 *                                              switched off
 *                        Va      ESCAN00043158 Porting TMS570PSFC66 to D62 derivative
 *                        Va      ESCAN00043162 Adding TMS570LS101SPGEQ derivative
 *  1.04.00   2011-01-20  Va      ESCAN00048598 BETA version - no series production allowed
 *                                ESCAN00048222 Spi - add Dma support for standard hardware units
 *                                ESCAN00048221 Spi - add support for standard hardware units units which offer a
 *                                              compatibility mode
 *  1.04.01   2011-09-19  Va      ESCAN00048598 BETA version - no series production allowed
 *                        Va      ESCAN00051817 Using single mode and CS idle timing during DMA transfer - final transfer
 *                                              violates configured time
 *                        Va      ESCAN00052767 Compiler warning: HwUnit_u32 never referenced in Spi_Dlc.c
 *                        Va      ESCAN00052768 Compiler warning: MibData_u16 never used in Spi_Dlc.c
 *                        Va      ESCAN00052769 Compiler warning: DataLoc_u16 never used in Spi_Dlc.c
 *                        Va      ESCAN00052770 Compiler warning: Dma_Channel never referenced in Spi_Dlc.c (Spi_DlcBlockCbk())
 *                        Va      ESCAN00052771 Compiler warning: Dma_Channel never referenced in Spi_Dlc.c (Spi_DlcFrameCbk())
 *                        Va      ESCAN00053497 Spi - MIBRAM mode wrong channel setup during transfer
 *                        Va      ESCAN00053534 Spi - incorrect CS change at the end of a job using Dma mode
 *                        Va      ESCAN00053640 Spi - default data is not updated when switching a channel
 *  1.05.00    2011-12-02 Va      ESCAN00053811 BETA version - no series production allowed
 *                        Va      ESCAN00054001 SPI - Errorhandling of HW unit can cause a data abort exception by calling
 *                                              job complete twice
 *                        Va      ESCAN00054002 SPI - Errorhandling of HW unit can cause a data abort exception by a
 *                                              wrong job assignment
 *                        Va      ESCAN00054733 Usage of OS functions for HW Register Access
 *                        Va      ESCAN00055301 SPI - Errorhandling of HW unit does not perform a clean shutdown of the
 *                                              MIB hardware
 *********************************************************************************************************************/

#ifndef SPI_DLC_H
#define SPI_DLC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : DRVSPI_TMS570TISPI01ASR CQComponent : Implementation */
#define DRVSPI_TMS570TISPI01ASR_VERSION             (0x0105u)
#define DRVSPI_TMS570TISPI01ASR_RELEASE_VERSION     (0x00u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define SPI_DLC_MIBTXSIZE    128
#define SPI_DLC_MIBRXSIZE    128

/* the register space is addressed as structure pointer */
/* => all registers have to be defined               */
#if (   (defined SPI_DLC_SOURCE)    \
    ||  (defined SPI_HW_SOURCE)     \
    ||  (defined SPI_SOURCE)        \
    ||  (defined SPI_IRQ_SOURCE)    \
    ||  (defined SPI_PBCFG_SOURCE)  \
    ||  (defined SPI_DLCDMA_SOURCE) )
/* => all registers have to be defined               */
typedef union
{
     struct
     {
        volatile uint16 Ctrl_u16;
        volatile uint16 Data_u16;
     } Tx;
     volatile uint32 TxData_u32;
}Spi_TxField;

typedef union
{
    struct
    {
        volatile uint16 Stat_u16;
        volatile uint16 Data_u16;
    } Rx;
    volatile uint32 RxData_u32;
}Spi_RxField;

typedef struct
{
    volatile uint32 Spi_FUN;     /* Offset: 0x14 */
    volatile uint32 Spi_DIR;     /* Offset: 0x18 */
    volatile uint32 Spi_DIN;     /* Offset: 0x1C */
    volatile uint32 Spi_DOUT;    /* Offset: 0x20 */
    volatile uint32 Spi_DSET;    /* Offset: 0x24 */
    volatile uint32 Spi_DCLR;    /* Offset: 0x28 */
    volatile uint32 Spi_PDR;     /* Offset: 0x2C */
    volatile uint32 Spi_PDIS;    /* Offset: 0x30 */
    volatile uint32 Spi_PSEL;    /* Offset: 0x34 */
} Spi_PinCtrlType;

typedef struct
{
    volatile uint32 Spi_FMT[4];
} Spi_FMTRegType;

typedef struct
{
    volatile uint32 Spi_TGITENST;    /* Offset: 0x74 */
    volatile uint32 Spi_TGITENCR;    /* Offset: 0x78 */
    volatile uint32 Spi_TGITLVST;    /* Offset: 0x7C */
    volatile uint32 Spi_TGITLVCR;    /* Offset: 0x80 */
    volatile uint32 Spi_TGINTFLAG;   /* Offset: 0x84 */
    volatile uint32 Spi_Reserved0;   /* Offset: 0x88 */
    volatile uint32 Spi_Reserved1;   /* Offset: 0x8C */
    volatile uint32 Spi_TICKCNT;     /* Offset: 0x90 */
    volatile uint32 Spi_LTGPEND;     /* Offset: 0x94 */
    volatile uint32 Spi_TGCTRL[16];  /* Offset: 0x98 - 0xD4 */
} Spi_TGCTRLRegType;

typedef struct
{
    volatile uint32 Spi_DMACTRL[8];  /* Offset: 0xD8- 0xF8 */
    volatile uint32 Spi_DMACOUNT[8]; /* Offset: 0xFC - 0x114 */
    volatile uint32 Spi_DMACNTLEN;   /* Offset: 0x118 */
} Spi_DMACTRLRegType;

typedef struct
{
    volatile uint32 Spi_GCRO;           /* Offset: 0x00 */
    volatile uint32 Spi_GCR1;           /* Offset: 0x04 */
    volatile uint32 Spi_INT0;           /* Offset: 0x08 */
    volatile uint32 Spi_LVL;            /* Offset: 0x0C */
    volatile uint32 Spi_FLG;            /* Offset: 0x10 */
    Spi_PinCtrlType Spi_PC;             /* Offset: 0x14 - 0x34 */
    volatile Spi_TxField Spi_DAT0;      /* Offset: 0x38 */
    volatile Spi_TxField Spi_DAT1;      /* Offset: 0x3C */
    volatile Spi_RxField Spi_BUF;       /* Offset: 0x40 */
    volatile uint32 Spi_EMU;            /* Offset: 0x44 */
    volatile uint16 Spi_DELAY[2];       /* Offset: 0x48 */
    volatile uint32 Spi_DEF;            /* Offset: 0x4C */
    volatile uint32 Spi_FMT[4];         /* Offset: 0x50 - 0x5C */
    volatile uint32 Spi_TGINTVECT[2];   /* Offset: 0x60 -0x64 */
    volatile uint32 Spi_SRSEL;          /* Offset: 0x68 */
    volatile uint32 Spi_PMCTRL;         /* Offset: 0x6C */
    volatile uint32 Spi_EN;             /* Offset: 0x70 */
    Spi_TGCTRLRegType Spi_RegTGCTL;     /* Offset: 0x74 - 0xD4 */
    Spi_DMACTRLRegType Spi_RegDMACTRL;  /* Offset: 0xD8 - 0x118 */
    volatile uint32 Spi_Reserved2;      /* Offset: 0x11C */
    volatile uint32 Spi_UERRCTRL;       /* Offset: 0x120 */
    volatile uint32 Spi_UERRSTAT;       /* Offset: 0x124 */
    volatile uint32 Spi_UERRADDR1;      /* Offset: 0x128 */
    volatile uint32 Spi_UERRADDR0;      /* Offset: 0x12C */
    volatile uint32 Spi_RXOVRN_ADDR;    /* Offset: 0x130 */
    volatile uint32 Spi_IOLPBTSTCR;     /* Offset: 0x134 */
}Spi_RegisterType;

typedef struct
{
    volatile Spi_TxField Spi_TxBank[SPI_DLC_MIBTXSIZE]; /* TxBank constists of 16bit control and 16bit txdata */
    volatile Spi_RxField Spi_RxBank[SPI_DLC_MIBRXSIZE]; /* RxBank constists of 16bit status  and 16bit rxdata */
}Spi_RamBufferType;

typedef P2VAR(volatile Spi_RegisterType,  AUTOMATIC, MSR_REGSPACE) Spi_RegisterPtrType;
typedef P2VAR(volatile Spi_RamBufferType, AUTOMATIC, MSR_REGSPACE) Spi_RamBufferPtrType;

typedef struct
{
    uint8 Spi_RamUsed;  /* 0 = Std, 1 = Ram, 2 = Std with Dma */
    uint8 Spi_UnitID;
    uint16 Spi_RegArea; /* register area for OS Safety context */
    uint16 Spi_RamArea; /* ram area for OS Safety context */
}Spi_HWUnitPropertyType;

typedef P2CONST(Spi_HWUnitPropertyType, AUTOMATIC, SPI_CONST) Spi_HWUnitPropertyPtrType;

typedef struct
{
    Spi_RegisterPtrType Reg_pt;        /* pointer to unit registers */
    Spi_RamBufferPtrType Ram_pt;       /* pointer to unit ram (NULL_PTR) if unit has no ram */
    Spi_HWUnitPropertyPtrType Prop_pt; /* pointer to unit properties */
}Spi_HWUnitMapType;

typedef P2VAR(Spi_HWUnitMapType, AUTOMATIC, SPI_VAR_NOINIT) Spi_HWUnitMapPtrType;


#define SPI_REGISTER_BASE_0 (Spi_RegisterPtrType) (0xFFF7F400u)
#define SPI_REGISTER_BASE_1 (Spi_RegisterPtrType) (0xFFF7F600u)
#define SPI_REGISTER_BASE_2 (Spi_RegisterPtrType) (0xFFF7F800u)
#define SPI_REGISTER_BASE_3 (Spi_RegisterPtrType) (0xFFF7FA00u)
#define SPI_REGISTER_BASE_4 (Spi_RegisterPtrType) (0xFFF7FC00u)

#define SPI_RAM_BASE_0      (Spi_RamBufferPtrType) (0xFF0E0000u)
#define SPI_RAM_BASE_1      (Spi_RamBufferPtrType) (0xFF0C0000u)
#define SPI_RAM_BASE_2      (Spi_RamBufferPtrType) (0xFF0C0000u)
#define SPI_RAM_BASE_3      (Spi_RamBufferPtrType) (0xFF0C0000u)
#define SPI_RAM_BASE_4      (Spi_RamBufferPtrType) (0xFF0A0000u)

/*---------------------------------------------------*/
/* Register bit mask definitions for MIB registers   */
/*---------------------------------------------------*/
/* naming of the macros is: [REGISTERNAME]_[REGISTERFLAG] */
/* val is the value to be set, bit if available is the bit to set */
/* i.e. TICKCNT_TICKVALUE_SET: set a the TICKCNT register with the TICKVALUE */

/* define for SPIFLG */
#define SPI_DLC_BUFINIT          ((uint32)1u << 24)
/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_TICKCNT register masks, RW */
/*---------------------------------------------------*/
/* set: set a value to the specified register bit */
#define SPI_DLC_TICKCNT_TICKVALUE(val)    ((uint32)(val) << 0)       /* bit 0:15  */
#define SPI_DLC_TICKCNT_CLKCTRL(val)      ((uint32)(val) << 28)      /* bit 28:29 */
#define SPI_DLC_TICKCNT_RELOAD(val)       ((uint32)(val) << 30)      /* bit 30    */
#define SPI_DLC_TICKCNT_TICKENA(val)      ((uint32)(val) << 31)      /* bit 31    */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_LTGPEND register masks, RW       */
/*---------------------------------------------------*/
#define SPI_DLC_LTGPEND_LPEND(val)        ((uint32)(val) << 8)       /* bit 8:14   */
#define SPI_DLC_LTGPEND_TGINSERVICE(val)  ((uint32)(val) << 24)      /* bit 24:28  */

/*---------------------------------------------------*/
/* Spi_TGINTVECT[x] register masks, read only        */
/*---------------------------------------------------*/
#define SPI_DLC_TGINTVECT_SUSPEND(val)    ((uint32)(val) << 0)       /* bit 0     */
#define SPI_DLC_TGINTVECT_INTVEC(val)     ((uint32)(val) << 1)       /* bit 1:5   */

/*---------------------------------------------------*/
/* Spi_EN register masks, RW                         */
/*---------------------------------------------------*/
#define SPI_DLC_MIBSPIE_EN(val)           ((uint32)(val) << 0)       /* bit 0     */

/*---------------------------------------------------*/
/* Spi_GCR1 register masks, RW                       */
/*---------------------------------------------------*/
#define SPI_DLC_MIBSPIEGCR1_MASTER(val)   ((uint32)(val)<< 0)       /* bit 0     */
#define SPI_DLC_MIBSPIEGCR1_CLKMOD(val)   ((uint32)(val)<< 1)       /* bit 1     */
#define SPI_DLC_MIBSPIEGCR1_SPIEN(val)    ((uint32)(val)<< 24)      /* bit 24    */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_TGITENST register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_TGITENST_SETINTENRDY(val, bit)    ((uint32)(val) << (bit))      /* bit y from 0:31 */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_TGITENCR register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_TGITENCR_CLRINTENRDY(val, bit)    ((uint32)(val) << (bit))      /* bit y from 0:31 */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_TGITLVST register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_TGITLVST_SETINTLEVEL(val, bit)    ((uint32)(val) << (bit))     /* bit y from 0:31 */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.Spi_TGITLVCR register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_TGITLVCR_SETINTLEVEL(val, bit)    ((uint32)(val) << (bit))      /* bit y from 0:31 */

/*---------------------------------------------------*/
/* Spi_RegTGCTL.TGCTRL register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_TGCTRL_PCURRENT(val)    (uint32)((val) << 0)     /* bit 0:6   */
#define SPI_DLC_TGCTRL_PSTART(val)      (uint32)((val) << 8)     /* bit 8:14  */
#define SPI_DLC_TGCTRL_TRIGSRC(val)     (uint32)((val) << 16)    /* bit 16:19 */
#define SPI_DLC_TGCTRL_TRIGEVT(val)     (uint32)((val) << 20)    /* bit 20:23 */
#define SPI_DLC_TGCTRL_TGTD(val)        (uint32)((val) << 28)    /* bit 28    */
#define SPI_DLC_TGCTRL_PRST(val)        (uint32)((val) << 29)    /* bit 29    */
#define SPI_DLC_TGCTRL_TGONESHOT(val)   (uint32)((val) << 30)    /* bit 30    */
#define SPI_DLC_TGCTRL_TGENA(val)       (uint32)((val) << 31)    /* bit 31    */

/*---------------------------------------------------*/
/* Spi_RegFMT register masks, RW      */
/*---------------------------------------------------*/
#define SPI_DLC_SPIFMT_CHARLEN(val)    (uint32)((val) << 0)     /* bit 0:4   */
#define SPI_DLC_SPIFMT_PRESCALE(val)   (uint32)((val) << 8)     /* bit 8:15  */
#define SPI_DLC_SPIFMT_PHASE(val)      (uint32)((val) << 16)    /* bit 16    */
#define SPI_DLC_SPIFMT_POLARITY(val)   (uint32)((val) << 17)    /* bit 17    */
#define SPI_DLC_SPIFMT_DISCSTIMER(val) (uint32)((val) << 18)    /* bit 18    */
#define SPI_DLC_SPIFMT_SHIFTDIR(val)   (uint32)((val) << 20)    /* bit 20    */
#define SPI_DLC_SPIFMT_WAITENA(val)    (uint32)((val) << 21)    /* bit 21    */
#define SPI_DLC_SPIFMT_PARITYENA(val)  (uint32)((val) << 22)    /* bit 22    */
#define SPI_DLC_SPIFMT_PARPOL(val)     (uint32)((val) << 23)    /* bit 23    */
#define SPI_DLC_SPIFMT_WDELAY(val)     (uint32)((val) << 24)    /* bit 24:29 */

#define SPI_DLC_SPIFMT_CHARLEN_MASK    (0x1Fu)
#define SPI_DLC_SPIFMT_WDELAY_MASK     (0x3Fu)
#define SPI_DLC_DMA_EN_MASK            (1u << 16)
/*---------------------------------------------------*/
/* MIBRAM Registers */
/*---------------------------------------------------*/
/* Spi_TXRAM register masks, RW                      */
/*---------------------------------------------------*/
#define SPI_DLC_TXRAMCTRL_DATA        (uint16)(0x0000u)  /* bit 0-7  */    /* bit 0:15  */
#define SPI_DLC_TXRAMCTRL_CSNR        (uint16)(0x0100u)  /* bit 8    */     /* bit 16:23 */
#define SPI_DLC_TXRAMCTRL_DFSEL       (uint16)(0x0200u)  /* bit 9    */     /* bit 24:25 */
#define SPI_DLC_TXRAMCTRL_WDEL        (uint16)(0x0400u)  /* bit 10   */    /* bit 26    */
#define SPI_DLC_TXRAMCTRL_LOCK        (uint16)(0x0800u)  /* bit 11   */    /* bit 27    */
#define SPI_DLC_TXRAMCTRL_CSHOLD      (uint16)(0x1000u)  /* bit 12   */    /* bit 28    */
#define SPI_DLC_TXRAMCTRL_BUFMODE     (uint16)(0x2000u)  /* bit 13   */    /* bit 29:31 */
/*
 * Spi_RXRAM register masks, R with auto clear
 */
#define SPI_DLC_RXRAMCTRL_LCSNR       (uint16)(0x0000u)  /* bit 0-7  */
#define SPI_DLC_RXRAMCTRL_DLENERR     (uint16)(0x0100u)  /* bit 8    */
#define SPI_DLC_RXRAMCTRL_TIMEOUT     (uint16)(0x0200u)  /* bit 9    */
#define SPI_DLC_RXRAMCTRL_PARITYERR   (uint16)(0x0400u)  /* bit 10   */
#define SPI_DLC_RXRAMCTRL_DESYNC      (uint16)(0x0800u)  /* bit 11   */
#define SPI_DLC_RXRAMCTRL_BITERR      (uint16)(0x1000u)  /* bit 12   */
#define SPI_DLC_RXRAMCTRL_TXFULL      (uint16)(0x2000u)  /* bit 13   */
#define SPI_DLC_RXRAMCTRL_RXOVR       (uint16)(0x4000u)  /* bit 14   */
#define SPI_DLC_RXRAMCTRL_RXEMPTY     (uint16)(0x8000u)  /* bit 15   */

#define SPI_DLC_RXBUFCTRL_RXEMPTY     (uint32)(0x80000000u)  /* bit 31   */
#define SPI_DLC_RXBUFCTRL_TXFULL      (uint32)(0x20000000u)  /* bit 29   */

/* special case , if (value & error mask) = 0, everything is fine */
#define RXRAMCTRL_ERRORMASK     0x5F000000u
/* TG interrupt flag status */
#define SPI_DLC_TGCTRL_INTFLAG(val)   ((uint32)1 << ((val) | 16))
/*
 * Spi INT0 register defines
 */
#define SPI_DLC_INT0_TXIENA    (1u << 9)
#define SPI_DLC_INT0_RXIENA    (1u << 8)
#define SPI_DLC_INT0_RXOVR     (1u << 6)
#define SPI_DLC_INT0_BITERR    (1u << 4)
#define SPI_DLC_INT0_TOERR     (1u << 1)
#define SPI_DLC_INT0_DLENERR   (1u << 0)

/*
 * Spi FLG register defines
 */
#define SPI_DLC_FLG_TXIF       (1u << 9)
#define SPI_DLC_FLG_RXIF       (1u << 8)
#define SPI_DLC_FLG_RXOVR      (1u << 6)
#define SPI_DLC_FLG_BITERR     (1u << 4)
#define SPI_DLC_FLG_TOERR      (1u << 1)
#define SPI_DLC_FLG_DLENERR    (1u << 0)

/*
 * Spi flag register defines
 */
#define SPI_DLC_TXINTFLG     (0x0200u)
#define SPI_DLC_RXINTFLG     (0x0100u)
/* only one TG is in use */
#define SPI_DLC_TG0_INTFLG   (1u << 16)

/*---------------------------------------------------*/
/* get, set: low/high word of a uint32               */
/*---------------------------------------------------*/
#define SPI_DLC_LOWWORD_SET(val)     (((uint32)(val) & 0x0000FFFFu) << 0)   /* bit 0:15   */
#define SPI_DLC_HIGHWORD_SET(val)    (((uint32)(val) & 0x0000FFFFu) << 16)  /* bit 16:31  */

#define SPI_DLC_LOWWORD_GET(val)     (uint16)(((uint32)(val) & 0x0000FFFFu))   /* bit 0:15   */
#define SPI_DLC_HIGHWORD_GET(val)    (uint16)(((uint32)(val) & 0xFFFF0000u) >> 16)  /* bit 16:31  */

/*---------------------------------------------------*/
/* for tx control field                              */
/*---------------------------------------------------*/
#define SPI_DLC_TXCTRL_BUFMOD(val)    (uint16) ((val) << 13)
#define SPI_DLC_TXCTRL_CSHOLD(val)    (uint16) ((val) << 12)
#define SPI_DLC_TXCTRL_DFSEL(val)     (uint16) ((val) << 8)

/*---------------------------------------------------*/
/* get, set: low/high byte of a uint16               */
/*---------------------------------------------------*/
#define SPI_DLC_LOWBYTE_SET(val)     (uint16)(((uint32)(val) & 0x00FFu) << 0)    /* bit 0:7   */
#define SPI_DLC_HIGHBYTE_SET(val)    (uint16)(((uint32)(val) & 0x00FFu) << 8)    /* bit 8:15  */

#define SPI_DLC_LOWBYTE_GET(val)     ((uint8)(((uint32)(val) & 0x00FFu)))         /* bit 0:8   */
#define SPI_DLC_HIGHBYTE_GET(val)    ((uint8)(((uint32)(val) & 0xFF00u) >> 8))    /* bit 8:15  */

/* define bit masks */
#define SPI_DLC_BITCLR    0x00000000
#define SPI_DLC_CHECK_HEX08(val, bval) ((uint8) (val) & (bval)) == (bval)   /* check if the bit is set, hex value */
#define SPI_DLC_CHECK_HEX16(val, bval) ((uint16)(val) & (bval)) == (bval)   /* check if the bit is set, hex value */
#define SPI_DLC_CHECK_HEX32(val, bval) ((uint32)(val) & (bval)) == (bval)   /* check if the bit is set, hex value */

#define SPI_DLC_CHECK_NOT_HEX08(val, bval) ((val) & (bval)) != (bval)   /* check if the bit is not set, hex value */
#define SPI_DLC_CHECK_NOT_HEX16(val, bval) ((val) & (bval)) != (bval)   /* check if the bit is not set, hex value */
#define SPI_DLC_CHECK_NOT_HEX32(val, bval) ((val) & (bval)) != (bval)   /* check if the bit is not set, hex value */

/* define access macros */
#define SPI_DLC_WRITEVAL32(reg, val)     ((reg) = (uint32)(val))
#define SPI_DLC_READVAL32(var, reg)      ((var) = (uint32)(reg))

#define SPI_DLC_WRITEVAL16(reg, val)     ((reg) = (uint16)(val))
#define SPI_DLC_READVAL16(var, reg)      ((var) = (uint16)(reg))

#define SPI_DLC_SETVAL16(reg, val)       ((reg) |= (uint16)(val))
#define SPI_DLC_GETVAL16(var, reg, mask) ((var)  = (uint16)((reg) & (uint32)(mask)))
#define SPI_DLC_CLRVAL16(reg, val)       ((reg) &= (~(uint16)(val)))

#define SPI_DLC_SETVAL32(reg, val)       ((reg) |= (uint32)(val))
#define SPI_DLC_GETVAL32(var, reg, mask) ((var)  = (uint32)((reg) & (uint32)(mask)))
#define SPI_DLC_CLRVAL32(reg, val)       ((reg) &= (~(uint32)(val)))

/* maximum number of bytes for one transfer group */
#define SPI_DLC_TX_RAM_SHIFT    (7u)
/* number of available transfer groups */
#define SPI_DLC_TG_NUM          (1u)

#define SPI_DLC_TG_LEN          ((uint16) 1u << SPI_DLC_TX_RAM_SHIFT)
/* oneshot mode = 0, time triggered mode = 1 */
#define SPI_DLC_MODE            (STD_OFF)
/* max priority of a job (ASR conform) */
#define SPI_MAX_JOB_PRIO        (3u)
#define SPI_DLC_MAXHWUNIT       (5u)

#define SPI_DLC_STD             (0u)
#define SPI_DLC_RAM             (1u)
#define SPI_DLC_STD_DMA         (2u)
#define SPI_DLC_RAM_DMA         (3u)

typedef P2VAR(uint8, AUTOMATIC, SPI_VAR)  Spi_JobResPtrType;
typedef P2VAR(uint8, AUTOMATIC, SPI_VAR)  Spi_DlcResPtrType;
typedef P2VAR(volatile uint16, AUTOMATIC, SPI_VAR)  Spi_DlcVU16PtrType;

/* event object definitions of the spi job state machine */
typedef struct
{
    /* the first three entries are part of the Interface and shall not be changed */
    volatile uint8 Event_u8;
    volatile uint8 Guard_u8;  /* used for fill status of buffer */
    uint8  JobID_u8;          /* ID of the job */
    uint8  ChState_u8;        /* channel state BUSY or DONE */

    Spi_JobResPtrType    JobResult_t; /* pointer to the Job result array */
    Spi_DlcResPtrType    DlcResult_t; /* pointer to the Dlc result array */
    Spi_HWUnitMapPtrType MUnit_pt;
    uint32 ChProp_u32;                /* holds the Channel properties */

    uint16 Pos_u16[2];        /* position in a channel [Tx, Rx] */
    uint16 Lgt_u16[2];         /* length of curren transfer [Tx, Rx] */
    uint8  ID_u8[2];          /* ID of the Channel [Tx, Rx] */
    uint8  Num_u8[2];         /* number of Channels [Tx, Rx] */

    Spi_TxField TxProp_t;   /* for transmit data and control */
    Spi_TxField TxEProp_t;  /* for transmit end data and control */
    Spi_RxField RxStat_t;   /* for receive data and status   */

    uint16 Default_u16[2];    /* default data */
    uint8  DFSel_u8[2];       /* data format word [0=CS_ID ,1=ExtDev]*/
} Spi_DlcEventType;

typedef P2VAR(Spi_DlcEventType, AUTOMATIC, SPI_VAR) Spi_DlcEventPtrType;

typedef struct
{
    P2FUNC(void, SPI_CODE, Init)      (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, Close)     (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, EnIsr)     (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, DeIsr)     (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, FillData)  (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, DrainData) (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, Trigger)   (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, Transmit)  (Spi_DlcEventPtrType DlcEv_pt);
    P2FUNC(void, SPI_CODE, Error)     (Spi_DlcEventPtrType DlcEv_pt);
}Spi_DlcFunctionType;

#define SPI_REG(op, mode, width)    SPI_REG_##op##mode##width

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Spi_RegisterPtrType, SPI_CONST) Spi_HWUnit_at[];
extern CONST(Spi_RamBufferPtrType, SPI_CONST) Spi_RamUnit_at[];
extern CONST(Spi_HWUnitPropertyType, SPI_CONST) Spi_UnitProperty_at[];

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* state for guard operations */
enum
{
    SPI_DLC_G_IDLE = 0,
    SPI_DLC_G_PENDING = 1,
    SPI_DLC_G_ACTIVE = 2,
    SPI_DLC_G_FINISHED = 3
};

typedef enum
{
    SPI_DLC_RX = 0,
    SPI_DLC_TX = 1
}Spi_DlcTxRxDefType;

typedef enum
{
    SPI_DLC_FRAME08 = 0,
    SPI_DLC_FRAME16 = 1
}Spi_DlcFrameDefType;

typedef enum
{
    SPI_DLC_STDUNIT = 0,
    SPI_DLC_MIBUNIT = 1
}Spi_DlcOptionDefType;

/* event definitions of the spi job state machine */
typedef enum
{
    SPI_DLC_EV_SYNCTX = 0,
    SPI_DLC_EV_ASYNCTX = 1,
    SPI_DLC_EV_CONSUMED = 2
} Spi_DlcEventDefType;

typedef enum
{
    SPI_DLC_ST_OK = 0,
    SPI_DLC_ST_PENDING = 1,
    SPI_DLC_ST_FINISHED = 2
}Spi_DlcChannelStateType;

typedef uint32 Spi_DlcInstType;
typedef uint32 Spi_DlcIsrType;

/* driver uses no chip select */
#define SPI_NO_CHIP_SELECT    255

/* pointer types for 8, 16 bit frame transfer */
typedef P2VAR(uint8, AUTOMATIC,  SPI_APPL_DATA) Spi_DlcFrame8PtrType;
typedef P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) Spi_DlcFrame16PtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"

/* common platform interface */
FUNC(void, SPI_CODE) Spi_DlcInit(void);
FUNC(void, SPI_CODE) Spi_DlcClose(void);
FUNC(Std_ReturnType, SPI_CODE) Spi_DlcSetEvent
(
    P2CONST(Spi_DlcEventType, AUTOMATIC, SPI_VAR_NOINIT) Dlc_Event_pt
);
FUNC(void, SPI_CODE) Spi_IrqTxRxERR(uint32 HwUnit_u32);
FUNC(void, SPI_CODE) Spi_DlcInitMemory(void);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#define SPI_START_SEC_CODE_ISR
#include "MemMap.h"

FUNC(void, SPI_CODE_ISR) Spi_IrqTxRx(uint32 HwUnit_u32);
FUNC(void, SPI_CODE_ISR) Spi_DlcBlockCbk(void);

#define SPI_STOP_SEC_CODE_ISR
#include "MemMap.h"

#endif /* module outside inclusion protection */
#endif /* SPI_DLC_H */

/**********************************************************************************************************************
 *  END OF FILE: Spi_Dlc.h
 *********************************************************************************************************************/
