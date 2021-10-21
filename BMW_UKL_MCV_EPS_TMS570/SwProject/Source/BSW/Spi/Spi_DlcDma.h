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
 *         File:  Spi_DlcDma.h
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr Module Spi_Dlc.h
 *    Generator:  -
 *
 *  Description:  This file implements the Spi Dma support, handling of channels and transmission settings.
 *
 *********************************************************************************************************************/

#ifndef SPI_DLCDMA_H
#define SPI_DLCDMA_H

#define SPI_DLCDMA_SW_MAJOR_VERSION    (0x01)
#define SPI_DLCDMA_SW_MINOR_VERSION    (0x05)
#define SPI_DLCDMA_SW_PATCH_VERSION    (0x00)

/* Interrupt request mask set register 1 */
#define VIM_REQMASKSET1 ((uint32*) 0xFFFFFE34u)
/* Interrupt request mask clear register 1 */
#define VIM_REQMASKCLR1 ((uint32*) 0xFFFFFE44u)

typedef uint8 Dma_HWChannelType;            /* Numeric ID of a hardware channel */
typedef uint8 Dma_ChannelType;              /* Numeric ID of a Channel */
typedef uint8 Dma_TriggerType;              /* Numeric ID of a hardware trigger source */

typedef enum
{
  DMA_UNINIT = 0,
  DMA_IDLE,
  DMA_BUSY
} Dma_StatusType;       /* Current status of the DMA Module. */

typedef enum
{
  DMA_GROUP_IDLE = 0,
  DMA_GROUP_BUSY,
  DMA_GROUP_FRAME_COMPLETE,
  DMA_GROUP_BLOCK_COMPLETE
} Dma_GroupStatusType;  /* Current status of a DMA Group. */

typedef enum
{
    SPI_DLCDMA_ADDR_CONST    = 0,
    DMA_ADDR_POSTINC  = 1,
    DMA_ADDR_RESERVED = 2,
    DMA_ADDR_INDEXED  = 3
} Dma_AddrModeType;     /* addressing mode of the DMA Module. */

typedef enum
{
    DMA_ESIZE_8BIT  = 0,
    DMA_ESIZE_16BIT = 1,
    DMA_ESIZE_32BIT = 2,
    DMA_ESIZE_64BIT = 3
} Dma_ElementSizeType;     /* element size of the DMA Module. */

enum
{
    DMA_TTYPE_FRAME  = 0,
    DMA_TTYPE_BLOCK  = 1
};

typedef enum
{
    DMA0_TXCTRL = 0,
    DMA0_TXDATA = 1,
    DMA1_RXSTAT = 2,
    DMA1_RXDATA = 3
} Dma_ChannelUsedType;

typedef struct
{
    uint32 SrcAddr;
    uint32 DstAddr;
    uint16 FCount;
    uint16 ECount;
    uint16 EISrcInc;
    uint16 EIDstInc;
    uint16 FISrcInc;
    uint16 FIDstInc;
    uint16 ChCtrl;
    Dma_ChannelType Channel;
    uint8  Unit;  /* hardware unit */
    uint8  Dir;   /* direction RX or Tx */
    uint8  ChEn;  /* channel activation */
} Dma_ChannelSetupType;

typedef P2VAR(Dma_ChannelSetupType, AUTOMATIC, SPI_VAR) Dma_ChannelSetupPtrType;

typedef struct
{
    uint8  DmaReq[2];
}Dma_RequestType;

#define DMA_RES(x)    ((uint16)((x) << 14))
#define DMA_WES(x)    ((uint16)((x) << 12))
#define DMA_TTP(x)    ((uint16)((x) << 8))
#define DMA_AMR(x)    ((uint16)((x) << 3))
#define DMA_AWR(x)    ((uint16)((x) << 1))
#define DMA_AIM        (uint16)       (1)

#define SPI_DLC_RXUNIT0    (0u)   /* MIBSPI1_RX, DREQ[0] */
#define SPI_DLC_TXUNIT0    (1u)   /* MIBSPI1_RX, DREQ[1] */

#define SPI_DLC_RXUNIT1    (2u)   /* SPI2_RX   , DREQ[2] */
#define SPI_DLC_TXUNIT1    (3u)   /* SPI2_RX   , DREQ[3] */

#define SPI_DLC_RXUNIT2    (14u)  /* MIBSPI3_RX, DREQ[14] */
#define SPI_DLC_TXUNIT2    (15u)  /* MIBSPI3_RX, DREQ[15] */

#define SPI_DLC_RXUNIT3    (24u)  /* SPI4_RX   , DREQ[24] */
#define SPI_DLC_TXUNIT3    (25u)  /* SPI4_RX 1 , DREQ[25] */

#define SPI_DLC_RXUNIT4    (30u)  /* MIBSPI5_RX, DREQ[30] */
#define SPI_DLC_TXUNIT4    (31u)  /* MIBSPI5_RX, DREQ[31] */

/* definitions for channel control (MIB unit and STD unit) */
/*  RES WES 11:9 TTYPE 7:5  ADDMR ADDMW AIM (Autoinitiation mode)
 *  xx  xx  000   x    000   xx     xx   x
 * ->  x x x x 0 0 0 x 0 0 0 x x x x x
 */
/*  for MIB we use TXCTRL : SRC const
 *                        : DST inc by 2 (indexed)
 *                 TXDATA : SRC inc by 1 (8bit) or 2 (16bit)
 *                        : DST inc by 2 (indexed)
 *                 RXSTAT : SRC inc by 2 (indexed)
 *                        : DST const
 *                 RXDATA : SRC inc by 2 (indexed)
 *                        : DST inc by 1 (8bit) or 2 (16bit)
 */

#define DMA_ELEMENT_64         (uint16)0x0003u
#define DMA_ELEMENT_32         (uint16)0x0002u
#define DMA_ELEMENT_16         (uint16)0x0001u
#define DMA_ELEMENT_08         (uint16)0x0000u

#define DMA_ADDR_MODE_INDEX    (uint16)0x0003u
#define DMA_ADDR_MODE_RES      (uint16)0x0002u
#define DMA_ADDR_MODE_PINC     (uint16)0x0001u
#define DMA_ADDR_MODE_CONST    (uint16)0x0000u

#define DMA_BTC                (uint16)0x1u
#define DMA_FTC                (uint16)0x0u

#define DMA_RW08           (uint16)((DMA_ELEMENT_08 << 14) | (DMA_ELEMENT_08 << 12))
#define DMA_RW16           (uint16)((DMA_ELEMENT_16 << 14) | (DMA_ELEMENT_16 << 12))
#define DMA_RW32           (uint16)((DMA_ELEMENT_32 << 14) | (DMA_ELEMENT_32 << 12))

/* Tx handling: read from buffer, write to register
 * register is constant. If sending default data, source is also constant
 * - no increment
 * - inc source only
 * - inc source and destination
 */
/*                               RES,WES:0000, TType:0,  Read increment,              write increment,   AIM:0 */
#define DMA_TX08_CONST    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX08_INCSO    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX08_INCSD    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_PINC  << 1)
/*                               RES,WES:0101, TType:0,  Read increment,              write increment,   AIM:0 */
#define DMA_TX16_CONST    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX16_INCSO    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX16_INCSD    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_PINC  << 1)

/*                               RES,WES:0202, TType:0,  Read increment,              write increment,   AIM:0 */
#define DMA_TX32_CONST    (uint16)(DMA_RW32) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX32_INCSO    (uint16)(DMA_RW32) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_TX32_INCSD    (uint16)(DMA_RW32) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_PINC  << 1)

/* Rx handling: read from register, write to buffer
 * register is constant. If reading unused data, destination is constant
 * modes are:
 * - no increment
 * - inc destination only
 * - inc destination and source
 */
/*                               RES,WES:0000, TType:1,  Read increment,              write increment,   AIM:0 */
#define DMA_RX08_CONST    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_RX08_INCDO    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_PINC  << 1)
#define DMA_RX08_INCDS    (uint16)(DMA_RW08) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_PINC  << 1)
/*                               RES,WES:0101, TType:1,  Read increment,              write increment,   AIM:0 */
#define DMA_RX16_CONST    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_CONST << 1)
#define DMA_RX16_INCDO    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_CONST << 3) | (DMA_ADDR_MODE_PINC  << 1)
#define DMA_RX16_INCDS    (uint16)(DMA_RW16) | (DMA_FTC << 8) | (DMA_ADDR_MODE_PINC  << 3) | (DMA_ADDR_MODE_PINC  << 1)

/* This struct type is intended to be an easier way of accessing the Primary Control Packet of each DMA channel.
 * Use a pointer to this type which points to the base address of Primary Control Packet 0.
 * The Primary Control Packets 1 - 31 can be accessed by using the pointer like an array where
 * the index identifies the number of the Primary Control Packet.
 */
typedef struct   /* Values can be changed by hardware and by software */
{
    volatile uint32 ISADDR;            /* Control Packet base address + Channel offset;  INITIAL SOURCE ADDRESS */
    volatile uint32 IDADDR;            /* Offset: 0x004;   INITIAL DESTINATION ADDRESS */
    volatile uint16 IFTCOUNT;          /* Offset: 0x008;   INITIAL FRAME COUNT */
    volatile uint16 IETCOUNT;          /* Offset: 0x00A;   INITIAL ELEMENT COUNT */
    volatile uint32 Reserved_0x00C;    /* Offset: 0x00C;   Reserved */
    volatile uint16 CHCTRL_CHAIN;      /* Offset: 0x010;   CHANNEL CONTROL: Next Channel to be triggered (0x000000 = no channel) */
    volatile uint16 CHCTRL;            /* Offset: 0x012;   CHANNEL CONTROL: Trigger Type, Read and Write Element Size, Address modes */
    volatile uint16 EIDXD;             /* Offset: 0x014;   Destination Address Element Offset */
    volatile uint16 EIDXS;             /* Offset: 0x016;   Source Address Element Offset */
    volatile uint16 FIDXD;             /* Offset: 0x018;   Destination Address Frame Offset */
    volatile uint16 FIDXS;             /* Offset: 0x01A;   Source Address Frame Offset */
    volatile uint32 Reserved_0x01C;    /* Offset: 0x01C;   Reserved */
} Dma_ChannelControlPacketType;

typedef struct
{
        uint32 CSADDR;                 /* Control Packet status base address + Channel offset; CURRENT SOURCE ADDRESS */
        uint32 CDADDR;                 /* Offset: 0x004;   CURRENT DESTINATION ADDRESS */
        uint16 CFTCOUNT;               /* Offset: 0x008;   CURRENT FRAME COUNT */
        uint16 CETCOUNT;               /* Offset: 0x00A;   CURRENT ELEMENT COUNT */
        uint32 Reserved_0x00C;         /* Offset: 0x00C;   Reserved */
}Dma_ChannelControlPacketStatusType;

typedef struct
{
    Dma_ChannelControlPacketType DMA_CHCTRL[32];
}Dma_ChanCtrlType;

typedef struct
{
    Dma_ChannelControlPacketStatusType DMA_CHSTATUS[32];
}Dma_ChanCtrlStatusType;

typedef struct   /* Values can be changed by hardware and by software */
{
    volatile uint32 DMA_GCTRL;             /* Register base address;   GLOBAL CONTROL */
    volatile uint32 DMA_PEND;              /* Offset: 0x004;       CHANNEL PENDING */
    volatile uint32 DMA_FBREG;             /* Offset: 0x008;       FALL BACK */
    volatile uint32 DMA_DMASTAT;           /* Offset: 0x00C;       DMA STATUS */
    volatile uint32 DMA_Reserved_0x010;    /* Offset: 0x010;       Reserved */
    volatile uint32 DMA_HWCHENAS;          /* Offset: 0x014;       HW CHANNEL ENABLE SET */
    volatile uint32 DMA_Reserved_0x018;    /* Offset: 0x018;       Reserved */
    volatile uint32 DMA_HWCHENAR;          /* Offset: 0x01C;       HW CHANNEL ENABLE RESET */
    volatile uint32 DMA_Reserved_0x020;    /* Offset: 0x020;       Reserved */
    volatile uint32 DMA_SWCHENAS;          /* Offset: 0x024;       SW CHANNEL ENABLE SET */
    volatile uint32 DMA_Reserved_0x028;    /* Offset: 0x028;       Reserved */
    volatile uint32 DMA_SWCHENAR;          /* Offset: 0x02C;       SW CHANNEL ENABLE RESET */
    volatile uint32 DMA_Reserved_0x030;    /* Offset: 0x030;       Reserved */
    volatile uint32 DMA_CHPRIOS;           /* Offset: 0x034;       CHANNEL PRIORITY SET */
    volatile uint32 DMA_Reserved_0x038;    /* Offset: 0x038;       Reserved */
    volatile uint32 DMA_CHPRIOR;           /* Offset: 0x03C;       CHANNEL PRIORITY RESET */
    volatile uint32 DMA_Reserved_0x040;    /* Offset: 0x040;       Reserved */
    volatile uint32 DMA_GCHIENAS;          /* Offset: 0x044;       GLOBAL CHANNEL INTERRUPT ENABLE SET */
    volatile uint32 DMA_Reserved_0x048;    /* Offset: 0x048;       Reserved */
    volatile uint32 DMA_GCHIENAR;          /* Offset: 0x04C;       GLOBAL CHANNEL INTERRUPT ENABLE RESET */
    volatile uint32 DMA_Reserved_0x050;    /* Offset: 0x050;       Reserved */
    volatile uint8  DMA_DREQASI[32];       /* Offset: 0x054-0x70;  DMA request assignment [32] for channel */
    volatile uint32 DMA_Reserved_0x074;    /* Offset: 0x074;       Reserved */
    volatile uint32 DMA_Reserved_0x078;    /* Offset: 0x078;       Reserved */
    volatile uint32 DMA_Reserved_0x07C;    /* Offset: 0x07C;       Reserved */
    volatile uint32 DMA_Reserved_0x080;    /* Offset: 0x080;       Reserved */
    volatile uint32 DMA_Reserved_0x084;    /* Offset: 0x084;       Reserved */
    volatile uint32 DMA_Reserved_0x088;    /* Offset: 0x088;       Reserved */
    volatile uint32 DMA_Reserved_0x08C;    /* Offset: 0x08C;       Reserved */
    volatile uint32 DMA_Reserved_0x090;    /* Offset: 0x090;       Reserved */
    volatile uint32 DMA_PAR[4];            /* Offset: 0x094-0xA0;  PORT ASSIGNMENT Register 0-3 */
    volatile uint32 DMA_Reserved_0x0A4;    /* Offset: 0x0A4;       Reserved */
    volatile uint32 DMA_Reserved_0x0A8;    /* Offset: 0x0A8;       Reserved */
    volatile uint32 DMA_Reserved_0x0AC;    /* Offset: 0x0AC;       Reserved */
    volatile uint32 DMA_Reserved_0x0B0;    /* Offset: 0x0B0;       Reserved */
    volatile uint32 DMA_FTCMAP;            /* Offset: 0x0B4;       FTC INTERRUPT MAPPING */
    volatile uint32 DMA_Reserved_0x0B8;    /* Offset: 0x0B8;       Reserved */
    volatile uint32 DMA_LFSMAP;            /* Offset: 0x0BC;       LFS INTERRUPT MAPPING */
    volatile uint32 DMA_Reserved_0x0C0;    /* Offset: 0x0C0;       Reserved */
    volatile uint32 DMA_HBCMAP;            /* Offset: 0x0C4;       HBC INTERRUPT MAPPING */
    volatile uint32 DMA_Reserved_0x0C8;    /* Offset: 0x0C8;       Reserved */
    volatile uint32 DMA_BTCMAP;            /* Offset: 0x0CC;       BTC INTERRUPT MAPPING */
    volatile uint32 DMA_Reserved_0x0D0;    /* Offset: 0x0D0;       Reserved */
    volatile uint32 DMA_BERMAP;            /* Offset: 0x0D4;       BER INTERRUPT MAPPING */
    volatile uint32 DMA_Reserved_0x0D8;    /* Offset: 0x0D8;       Reserved */
    volatile uint32 DMA_FTCINTENAS;        /* Offset: 0x0DC;       FTC INTERRUPT ENABLE SET */
    volatile uint32 DMA_Reserved_0x0E0;    /* Offset: 0x0E0;       Reserved */
    volatile uint32 DMA_FTCINTENAR;        /* Offset: 0x0E4;       FTC INTERRUPT ENABLE RESET */
    volatile uint32 DMA_Reserved_0x0E8;    /* Offset: 0x0E8;       Reserved */
    volatile uint32 DMA_LFSINTENAS;        /* Offset: 0x0EC;       LFS INTERRUPT ENABLE SET */
    volatile uint32 DMA_Reserved_0x0F0;    /* Offset: 0x0F0;       Reserved */
    volatile uint32 DMA_LFSINTENAR;        /* Offset: 0x0F4;       LFS INTERRUPT ENABLE RESET */
    volatile uint32 DMA_Reserved_0x0F8;    /* Offset: 0x0F8;       Reserved */
    volatile uint32 DMA_HBCINTENAS;        /* Offset: 0x0FC;       HBC INTERRUPT ENABLE SET */
    volatile uint32 DMA_Reserved_0x100;    /* Offset: 0x100;       Reserved */
    volatile uint32 DMA_HBCINTENAR;        /* Offset: 0x104;       HBC INTERRUPT ENABLE RESET */
    volatile uint32 DMA_Reserved_0x108;    /* Offset: 0x108;       Reserved */
    volatile uint32 DMA_BTCINTENAS;        /* Offset: 0x10C;       BTC INTERRUPT ENABLE SET */
    volatile uint32 DMA_Reserved_0x110;    /* Offset: 0x110;       Reserved */
    volatile uint32 DMA_BTCINTENAR;        /* Offset: 0x114;       BTC INTERRUPT ENABLE RESET */
    volatile uint32 DMA_Reserved_0x118;    /* Offset: 0x118;       Reserved */
    volatile uint32 DMA_GINTFLAG;          /* Offset: 0x11C;       GLOBAL INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x120;    /* Offset: 0x120;       Reserved */
    volatile uint32 DMA_FTCFLAG;           /* Offset: 0x124;       FTC INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x128;    /* Offset: 0x128;       Reserved */
    volatile uint32 DMA_LFSFLAG;           /* Offset: 0x12C;       LFS INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x130;    /* Offset: 0x130;       Reserved */
    volatile uint32 DMA_HBCFLAG;           /* Offset: 0x134;       HBC INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x138;    /* Offset: 0x138;       Reserved */
    volatile uint32 DMA_BTCFLAG;           /* Offset: 0x13C;       BTC INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x140;    /* Offset: 0x140;       Reserved */
    volatile uint32 DMA_BERFLAG;           /* Offset: 0x144;       BER INTERRUPT FLAG */
    volatile uint32 DMA_Reserved_0x148;    /* Offset: 0x148;       Reserved */
    volatile uint32 DMA_FTCAOFFSET;        /* Offset: 0x14C;       FTCA INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_LFSAOFFSET;        /* Offset: 0x150;       LFSA INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_HBCAOFFSET;        /* Offset: 0x154;       HBCA INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_BTCAOFFSET;        /* Offset: 0x158;       BTCA INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_BERAOFFSET;        /* Offset: 0x15C;       BERA INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_FTCBOFFSET;        /* Offset: 0x160;       FTCB INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_LFSBOFFSET;        /* Offset: 0x164;       LFSB INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_HBCBOFFSET;        /* Offset: 0x168;       HBCB INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_BTCBOFFSET;        /* Offset: 0x16C;       BTCB INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_BERBOFFSET;        /* Offset: 0x170;       BERB INTERRUPT CHANNEL OFFSET */
    volatile uint32 DMA_Reserved_0x174;    /* Offset: 0x174;       Reserved */
    volatile uint8  DMA_PTCRL_PENDB;       /* Offset: 0x178;       PORT CONTROL Transactions Pending for Port B */
    volatile uint8  DMA_PTCRL_BYB_PRIO;    /* Offset: 0x179;       PORT CONTROL Bypassing of FIFO and Priority Scheme for Port B */
    volatile uint8  DMA_PTCRL_PENDA;       /* Offset: 0x17A;       PORT CONTROL Transactions Pending for Port A */
    volatile uint8  DMA_PTCRL_BYA_PRIO;    /* Offset: 0x17B;       PORT CONTROL Bypassing of FIFO and Priority Scheme for Port A */
    volatile uint32 DMA_RTCTRL;            /* Offset: 0x17C;       RAM TEST CONTROL */
    volatile uint32 DMA_DCTRL;             /* Offset: 0x180;       DEBUG CONTROL */
    volatile uint32 DMA_WPR;               /* Offset: 0x184;       WATCH POINT */
    volatile uint32 DMA_WMR;               /* Offset: 0x188;       WATCH MASK */
    volatile uint32 DMA_PAACSADDR;         /* Offset: 0x18C;       PORT A ACTIVE CHANNEL SOURCE ADDRESS */
    volatile uint32 DMA_PAACDADDR;         /* Offset: 0x190;       PORT A ACTIVE CHANNEL DESTINATION ADDRESS */
    volatile uint32 DMA_PAACTC;            /* Offset: 0x194;       PORT A ACTIVE CHANNEL TRANSFER COUNT */
    volatile uint32 DMA_PBACSADDR;         /* Offset: 0x198;       PORT B ACTIVE CHANNEL SOURCE ADDRESS */
    volatile uint32 DMA_PBACDADDR;         /* Offset: 0x19C;       PORT B ACTIVE CHANNEL DESTINATION ADDRESS */
    volatile uint32 DMA_PBACTC;            /* Offset: 0x1A0;       PORT B ACTIVE CHANNEL TRANSFER COUNT */
    volatile uint32 DMA_Reserved_0x1A4;    /* Offset: 0x1A4;       Reserved */
    volatile uint32 DMA_DMAPCR;            /* Offset: 0x1A8;       PARITY CONTROL */
    volatile uint32 DMA_DMAPAR;            /* Offset: 0x1AC;       PARITY ERROR ADDRESS */
    volatile uint32 DMA_DMAMPCTRL;         /* Offset: 0x1B0;       MEMORY PROTECTION CONTROL */
    volatile uint32 DMA_DMAMPST;           /* Offset: 0x1B4;       MEMORY PROTECTION STATUS */
    volatile uint32 DMA_DMAMPR0S;          /* Offset: 0x1B8;       MEMORY PROTECTION REGION 0 START ADDRESS */
    volatile uint32 DMA_DMAMPR0E;          /* Offset: 0x1BC;       MEMORY PROTECTION REGION 0 END ADDRESS */
    volatile uint32 DMA_DMAMPR1S;          /* Offset: 0x1C0;       MEMORY PROTECTION REGION 1 START ADDRESS */
    volatile uint32 DMA_DMAMPR1E;          /* Offset: 0x1C4;       MEMORY PROTECTION REGION 1 END ADDRESS */
    volatile uint32 DMA_DMAMPR2S;          /* Offset: 0x1C8;       MEMORY PROTECTION REGION 2 START ADDRESS */
    volatile uint32 DMA_DMAMPR2E;          /* Offset: 0x1CC;       MEMORY PROTECTION REGION 2 END ADDRESS */
    volatile uint32 DMA_DMAMPR3S;          /* Offset: 0x1D0;       MEMORY PROTECTION REGION 3 START ADDRESS */
    volatile uint32 DMA_DMAMPR3E;          /* Offset: 0x1D4;       MEMORY PROTECTION REGION 3 END ADDRESS */
} Dma_GlobalRegisterType;

typedef P2VAR(Dma_GlobalRegisterType, AUTOMATIC, SPI_CONST) Dma_GlobalRegisterPtrType;
typedef P2VAR(Dma_ChanCtrlType, AUTOMATIC, SPI_CONST) Dma_ChanCtrlPtrType;
typedef P2VAR(Dma_ChanCtrlStatusType, AUTOMATIC, SPI_CONST) Dma_ChanCtrlStatusPtrType;

#define DMA_BIT(BitPos)      (((uint32)0x1) << (BitPos))

/* hardware trigger sources for LS1xx, LS2xx triggers DMA in compatibility mode */
#define DMA_REQ_SPI2_RX         ((Dma_TriggerType)2u)
#define DMA_REQ_SPI2_TX         ((Dma_TriggerType)3u)
#define DMA_REQ_SPI4_RX         ((Dma_TriggerType)24u)
#define DMA_REQ_SPI4_TX         ((Dma_TriggerType)25u)

#define DMA_REQ_SPI1_RX         ((Dma_TriggerType)0u)
#define DMA_REQ_SPI1_TX         ((Dma_TriggerType)1u)
#define DMA_REQ_SPI3_RX         ((Dma_TriggerType)14u)
#define DMA_REQ_SPI3_TX         ((Dma_TriggerType)15u)
#define DMA_REQ_SPI5_RX         ((Dma_TriggerType)30u)
#define DMA_REQ_SPI5_TX         ((Dma_TriggerType)31u)

#define DMA_GLOBAL_REGISTER_BASE_ADDRESS                  ((Dma_GlobalRegisterPtrType) 0xFFFFF000u)
/* Base address where the Primary Control Packets of the DMA hardware channels begin */
#define DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS           ((Dma_ChanCtrlPtrType) 0xFFF80000u)
#define DMA_PRIMARY_CONTROL_PACKET_STATUS_BASE_ADDRESS    ((Dma_ChanCtrlStatusPtrType) 0xFFF80800u)

typedef struct
{
    P2FUNC(void, SPI_CODE, NotificationFrame)(void);
    P2FUNC(void, SPI_CODE, NotificationBlock)(void);
    uint32 HWUnit;
}Dma_NotificationType;

#define SPI_START_SEC_CODE
#include "MemMap.h"

FUNC(void, SPI_CODE) Dma_Init( void );
FUNC(void, SPI_CODE) Dma_DeInit( void );
FUNC(void, SPI_CODE) Dma_Setup
(
    P2CONST(Dma_ChannelSetupType, AUTOMATIC, SPI_VAR) Setup
);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#define SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

extern P2VAR(Dma_GlobalRegisterType, AUTOMATIC, SPI_CONST) Dma_GlobalRegister;

#define SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#endif /* SPI_DLCDMA_H */
