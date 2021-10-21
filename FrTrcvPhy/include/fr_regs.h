/*****************************************************************************
* Copyright 2011 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : fr_regs.h
* Module Description: FR (FlexRay) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Jared Julien
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:19 2011
* %version:          1 %
* %derived_by:       kzdyfh %
* %date_modified:    Fri Oct 26 12:59:53 2012 % 
*---------------------------------------------------------------------------*/

#ifndef FR_REGS_H
#define FR_REGS_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct frturegs
{
    uint32 GSN0;    /* 0x0000 */
    uint32 GSN1;    /* 0x0004 */
    uint32 : 32U;   /* 0x0008 */
    uint32 : 32U;   /* 0x000C */
    uint32 GCS;     /* 0x0010 */
    uint32 GCR;     /* 0x0014 */
    uint32 TSCB;    /* 0x0018 */
    uint32 LTBCC;   /* 0x001C */
    uint32 LTBSM;   /* 0x0020 */
    uint32 TBA;     /* 0x0024 */
    uint32 NTBA;    /* 0x0028 */
    uint32 BAMS;    /* 0x002C */
    uint32 SAMP;    /* 0x0030 */
    uint32 EAMP;    /* 0x0034 */
    uint32 : 32U;   /* 0x0038 */
    uint32 : 32U;   /* 0x003C */
    uint32 TSMO1;   /* 0x0040 */
    uint32 TSMO2;   /* 0x0044 */
    uint32 TSMO3;   /* 0x0048 */
    uint32 TSMO4;   /* 0x004C */
    uint32 TCCO1;   /* 0x0050 */
    uint32 TCCO2;   /* 0x0054 */
    uint32 TCCO3;   /* 0x0058 */
    uint32 TCCO4;   /* 0x005C */
    uint32 TOOFF;   /* 0x0060 */
    uint32 : 32U;   /* 0x0064 */
    uint32 : 32U;   /* 0x0068 */
    uint32 : 32U;   /* 0x006C */
    uint32 PEADR;   /* 0x0070 */
    uint32 TEIF;    /* 0x0074 */
    uint32 TEIRES;  /* 0x0078 */
    uint32 TEIRER;  /* 0x007C */
    uint32 TTSMS1;  /* 0x0080 */
    uint32 TTSMR1;  /* 0x0084 */
    uint32 TTSMS2;  /* 0x0088 */
    uint32 TTSMR2;  /* 0x008C */
    uint32 TTSMS3;  /* 0x0090 */
    uint32 TTSMR3;  /* 0x0094 */
    uint32 TTSMS4;  /* 0x0098 */
    uint32 TTSMR4;  /* 0x009C */
    uint32 TTCCS1;  /* 0x00A0 */
    uint32 TTCCR1;  /* 0x00A4 */
    uint32 TTCCS2;  /* 0x00A8 */
    uint32 TTCCR2;  /* 0x00AC */
    uint32 TTCCS3;  /* 0x00B0 */
    uint32 TTCCR3;  /* 0x00B4 */
    uint32 TTCCS4;  /* 0x00B8 */
    uint32 TTCCR4;  /* 0x00BC */
    uint32 ETESMS1; /* 0x00C0 */
    uint32 ETESMR1; /* 0x00C4 */
    uint32 ETESMS2; /* 0x00C8 */
    uint32 ETESMR2; /* 0x00CC */
    uint32 ETESMS3; /* 0x00D0 */
    uint32 ETESMR3; /* 0x00D4 */
    uint32 ETESMS4; /* 0x00D8 */
    uint32 ETESMR4; /* 0x00DC */
    uint32 CESMS1;  /* 0x00E0 */
    uint32 CESMR1;  /* 0x00E4 */
    uint32 CESMS2;  /* 0x00E8 */
    uint32 CESMR2;  /* 0x00EC */
    uint32 CESMS3;  /* 0x00F0 */
    uint32 CESMR3;  /* 0x00F4 */
    uint32 CESMS4;  /* 0x00F8 */
    uint32 CESMR4;  /* 0x00FC */
    uint32 TSMIES1; /* 0x0100 */
    uint32 TSMIER1; /* 0x0104 */
    uint32 TSMIES2; /* 0x0108 */
    uint32 TSMIER2; /* 0x010C */
    uint32 TSMIES3; /* 0x0110 */
    uint32 TSMIER3; /* 0x0114 */
    uint32 TSMIES4; /* 0x0118 */
    uint32 TSMIER4; /* 0x011C */
    uint32 TCCIES1; /* 0x0120 */
    uint32 TCCIER1; /* 0x0124 */
    uint32 TCCIES2; /* 0x0128 */
    uint32 TCCIER2; /* 0x012C */
    uint32 TCCIES3; /* 0x0130 */
    uint32 TCCIER3; /* 0x0134 */
    uint32 TCCIES4; /* 0x0138 */
    uint32 TCCIER4; /* 0x013C */
    
} fresmregs_t;

#define FRTUREGS ((frturegs_t *)0xFFF7A000)

typedef volatile struct frccregs
{
    uint32 : 32U;       /* 0x0000 */
    uint32 : 32U;       /* 0x0004 */
    uint32 : 32U;       /* 0x0008 */
    uint32 : 32U;       /* 0x000c */
    uint32 TEST1;       /* 0x0010 */
    uint32 TEST2;       /* 0x0014 */
    uint32 : 32U;       /* 0x0018 */
    uint32 LCK;         /* 0x001C */
    uint32 EIR;         /* 0x0020 */
    uint32 SIR;         /* 0x0024 */
    uint32 EILS;        /* 0x0028 */
    uint32 SILS;        /* 0x002C */
    uint32 EIES;        /* 0x0030 */
    uint32 EIER;        /* 0x0034 */
    uint32 SIES;        /* 0x0038 */
    uint32 SIER;        /* 0x003C */
    uint32 ILE;         /* 0x0040 */
    uint32 T0C;         /* 0x0044 */
    uint32 T1C;         /* 0x0048 */
    uint32 STPW1;       /* 0x004C */
    uint32 STPW2;       /* 0x0050 */
    uint32 : 32U;       /* 0x0054 */
    uint32 : 32U;       /* 0x0058 */
    uint32 : 32U;       /* 0x005C */
    uint32 : 32U;       /* 0x0060 */
    uint32 : 32U;       /* 0x0064 */
    uint32 : 32U;       /* 0x0068 */
    uint32 : 32U;       /* 0x006C */
    uint32 : 32U;       /* 0x0070 */
    uint32 : 32U;       /* 0x0074 */
    uint32 : 32U;       /* 0x0078 */
    uint32 : 32U;       /* 0x007C */
    /* Communication Controller Control Registers */
    uint32 SUCC1;       /* 0x0080 */
    uint32 SUCC2;       /* 0x0084 */
    uint32 SUCC3;       /* 0x0088 */
    uint32 NEMC;        /* 0x008C */
    uint32 PRTC1;       /* 0x0090 */
    uint32 PRTC2;       /* 0x0094 */
    uint32 MHDC;        /* 0x0098 */
    uint32 : 32U;       /* 0x009C */
    uint32 GTUC1;       /* 0x00A0 */
    uint32 GTUC2;       /* 0x00A4 */
    uint32 GTUC3;       /* 0x00A8 */
    uint32 GTUC4;       /* 0x00AC */
    uint32 GTUC5;       /* 0x00B0 */
    uint32 GTUC6;       /* 0x00B4 */
    uint32 GTUC7;       /* 0x00B8 */
    uint32 GTUC8;       /* 0x00BC */
    uint32 GTUC9;       /* 0x00C0 */
    uint32 GTUC10;      /* 0x00C4 */
    uint32 GTUC11;      /* 0x00C8 */
    uint32 : 32U;       /* 0x00CC */
    uint32 : 32U;       /* 0x00D0 */
    uint32 : 32U;       /* 0x00D4 */
    uint32 : 32U;       /* 0x00D8 */
    uint32 : 32U;       /* 0x00DC */
    uint32 : 32U;       /* 0x00E0 */
    uint32 : 32U;       /* 0x00E4 */
    uint32 : 32U;       /* 0x00E8 */
    uint32 : 32U;       /* 0x00EC */
    uint32 : 32U;       /* 0x00F0 */
    uint32 : 32U;       /* 0x00F4 */
    uint32 : 32U;       /* 0x00F8 */
    uint32 : 32U;       /* 0x00FC */
    /* Communication Controller Status Registers */
    uint32 CCSV;        /* 0x0100 */
    uint32 CCEV;        /* 0x0104 */
    uint32 : 32U;       /* 0x0108 */
    uint32 : 32U;       /* 0x010C */
    uint32 SCV;         /* 0x0110 */
    uint32 MTCCV;       /* 0x0114 */
    uint32 RCV;         /* 0x0118 */
    uint32 OCV;         /* 0x011C */
    uint32 SFS;         /* 0x0120 */
    uint32 SWNIT;       /* 0x0124 */
    uint32 ACS;         /* 0x0128 */
    uint32 : 32U;       /* 0x012C */
    uint32 ESID[15];    /* 0x0130 - 0X0168 */
    uint32 : 32U;       /* 0x016C */
    uint32 OSID[15];    /* 0x0170 - 0X01A8 */
    uint32 : 32U;       /* 0x01AC */
    uint32 NMV[3];      /* 0x01B0 - 0X01B8 */
    uint32 : 32U;       /* 0x01BC */
    uint32 : 32U;       /* 0x01C0 */
    uint32 : 32U;       /* 0x01C4 */
    uint32 : 32U;       /* 0x01C8 */
    uint32 : 32U;       /* 0x01CC */
    uint32 : 32U;       /* 0x01D0 */
    uint32 : 32U;       /* 0x01D4 */
    uint32 : 32U;       /* 0x01D8 */
    uint32 : 32U;       /* 0x01DC */
    uint32 : 32U;       /* 0x01E0 */
    uint32 : 32U;       /* 0x01E4 */
    uint32 : 32U;       /* 0x01E8 */
    uint32 : 32U;       /* 0x01EC */
    uint32 : 32U;       /* 0x01F0 */
    uint32 : 32U;       /* 0x01F4 */
    uint32 : 32U;       /* 0x01F8 */
    uint32 : 32U;       /* 0x01FC */
    uint32 : 32U;       /* 0x0200 */
    uint32 : 32U;       /* 0x0204 */
    uint32 : 32U;       /* 0x0208 */
    uint32 : 32U;       /* 0x020C */
    uint32 : 32U;       /* 0x0210 */
    uint32 : 32U;       /* 0x0214 */
    uint32 : 32U;       /* 0x0218 */
    uint32 : 32U;       /* 0x021C */
    uint32 : 32U;       /* 0x0220 */
    uint32 : 32U;       /* 0x0224 */
    uint32 : 32U;       /* 0x0228 */
    uint32 : 32U;       /* 0x022C */
    uint32 : 32U;       /* 0x0230 */
    uint32 : 32U;       /* 0x0234 */
    uint32 : 32U;       /* 0x0238 */
    uint32 : 32U;       /* 0x023C */
    uint32 : 32U;       /* 0x0240 */
    uint32 : 32U;       /* 0x0244 */
    uint32 : 32U;       /* 0x0248 */
    uint32 : 32U;       /* 0x024C */
    uint32 : 32U;       /* 0x0250 */
    uint32 : 32U;       /* 0x0254 */
    uint32 : 32U;       /* 0x0258 */
    uint32 : 32U;       /* 0x025C */
    uint32 : 32U;       /* 0x0260 */
    uint32 : 32U;       /* 0x0264 */
    uint32 : 32U;       /* 0x0268 */
    uint32 : 32U;       /* 0x026C */
    uint32 : 32U;       /* 0x0270 */
    uint32 : 32U;       /* 0x0274 */
    uint32 : 32U;       /* 0x0278 */
    uint32 : 32U;       /* 0x027C */
    uint32 : 32U;       /* 0x0280 */
    uint32 : 32U;       /* 0x0284 */
    uint32 : 32U;       /* 0x0288 */
    uint32 : 32U;       /* 0x028C */
    uint32 : 32U;       /* 0x0290 */
    uint32 : 32U;       /* 0x0294 */
    uint32 : 32U;       /* 0x0298 */
    uint32 : 32U;       /* 0x029C */
    uint32 : 32U;       /* 0x02A0 */
    uint32 : 32U;       /* 0x02A4 */
    uint32 : 32U;       /* 0x02A8 */
    uint32 : 32U;       /* 0x02AC */
    uint32 : 32U;       /* 0x02B0 */
    uint32 : 32U;       /* 0x02B4 */
    uint32 : 32U;       /* 0x02B8 */
    uint32 : 32U;       /* 0x02BC */
    uint32 : 32U;       /* 0x02C0 */
    uint32 : 32U;       /* 0x02C4 */
    uint32 : 32U;       /* 0x02C8 */
    uint32 : 32U;       /* 0x02CC */
    uint32 : 32U;       /* 0x02D0 */
    uint32 : 32U;       /* 0x02D4 */
    uint32 : 32U;       /* 0x02D8 */
    uint32 : 32U;       /* 0x02DC */
    uint32 : 32U;       /* 0x02E0 */
    uint32 : 32U;       /* 0x02E4 */
    uint32 : 32U;       /* 0x02E8 */
    uint32 : 32U;       /* 0x02EC */
    uint32 : 32U;       /* 0x02F0 */
    uint32 : 32U;       /* 0x02F4 */
    uint32 : 32U;       /* 0x02F8 */
    uint32 : 32U;       /* 0x02FC */
    /* Message Buffer Control Registers */
    uint32 MRC;         /* 0x0300 */
    uint32 FRF;         /* 0x0304 */
    uint32 FRFM;        /* 0x0308 */
    uint32 FCL;         /* 0x030C */
    /* Message Buffer Status Registers */
    uint32 MHDS;        /* 0x0310 */
    uint32 LDTS;        /* 0x0314 */
    uint32 FSR;         /* 0x0318 */
    uint32 MHDF;        /* 0x031C */
    uint32 TXRQ1;       /* 0x0320 */
    uint32 TXRQ2;       /* 0x0324 */
    uint32 TXRQ3;       /* 0x0328 */
    uint32 TXRQ4;       /* 0x032C */
    uint32 NDAT1;       /* 0x0330 */
    uint32 NDAT2;       /* 0x0334 */
    uint32 NDAT3;       /* 0x0338 */
    uint32 NDAT4;       /* 0x033C */
    uint32 MBSC1;       /* 0x0340 */
    uint32 MBSC2;       /* 0x0344 */
    uint32 MBSC3;       /* 0x0348 */
    uint32 MBSC4;       /* 0x034C */
    uint32 : 32U;       /* 0x0350 */
    uint32 : 32U;       /* 0x0354 */
    uint32 : 32U;       /* 0x0358 */
    uint32 : 32U;       /* 0x035C */
    uint32 : 32U;       /* 0x0360 */
    uint32 : 32U;       /* 0x0364 */
    uint32 : 32U;       /* 0x0368 */
    uint32 : 32U;       /* 0x036C */
    uint32 : 32U;       /* 0x0370 */
    uint32 : 32U;       /* 0x0374 */
    uint32 : 32U;       /* 0x0378 */
    uint32 : 32U;       /* 0x037C */
    uint32 : 32U;       /* 0x0380 */
    uint32 : 32U;       /* 0x0384 */
    uint32 : 32U;       /* 0x0388 */
    uint32 : 32U;       /* 0x038C */
    uint32 : 32U;       /* 0x0390 */
    uint32 : 32U;       /* 0x0394 */
    uint32 : 32U;       /* 0x0398 */
    uint32 : 32U;       /* 0x039C */
    uint32 : 32U;       /* 0x03A0 */
    uint32 : 32U;       /* 0x03A4 */
    uint32 : 32U;       /* 0x03A8 */
    uint32 : 32U;       /* 0x03AC */
    uint32 : 32U;       /* 0x03B0 */
    uint32 : 32U;       /* 0x03B4 */
    uint32 : 32U;       /* 0x03B8 */
    uint32 : 32U;       /* 0x03BC */
    uint32 : 32U;       /* 0x03C0 */
    uint32 : 32U;       /* 0x03C4 */
    uint32 : 32U;       /* 0x03C8 */
    uint32 : 32U;       /* 0x03CC */
    uint32 : 32U;       /* 0x03D0 */
    uint32 : 32U;       /* 0x03D4 */
    uint32 : 32U;       /* 0x03D8 */
    uint32 : 32U;       /* 0x03DC */
    uint32 : 32U;       /* 0x03E0 */
    uint32 : 32U;       /* 0x03E4 */
    uint32 : 32U;       /* 0x03E8 */
    uint32 : 32U;       /* 0x03EC */
    /* Identification Registers */
    uint32 CREL;        /* 0x03F0 */
    uint32 ENDN;        /* 0x03F4 */
    uint32 : 32U;       /* 0x03F8 */
    uint32 : 32U;       /* 0x03FC */
    /* Input Buffer */
    uint32 WRDS[64];    /* 0x0400 - 0x04FC */
    uint32 WRHS1;       /* 0x0500 */
    uint32 WRHS2;       /* 0x0504 */
    uint32 WRHS3;       /* 0x0508 */
    uint32 : 32U;       /* 0x050C */
    uint32 IBCM;        /* 0x0510 */
    uint32 IBCR;        /* 0x0514 */
    uint32 : 32U;       /* 0x0518 */
    uint32 : 32U;       /* 0x051C */
    uint32 : 32U;       /* 0x0520 */
    uint32 : 32U;       /* 0x0524 */
    uint32 : 32U;       /* 0x0528 */
    uint32 : 32U;       /* 0x052C */
    uint32 : 32U;       /* 0x0530 */
    uint32 : 32U;       /* 0x0534 */
    uint32 : 32U;       /* 0x0538 */
    uint32 : 32U;       /* 0x053C */
    uint32 : 32U;       /* 0x0540 */
    uint32 : 32U;       /* 0x0544 */
    uint32 : 32U;       /* 0x0548 */
    uint32 : 32U;       /* 0x054C */
    uint32 : 32U;       /* 0x0550 */
    uint32 : 32U;       /* 0x0554 */
    uint32 : 32U;       /* 0x0558 */
    uint32 : 32U;       /* 0x055C */
    uint32 : 32U;       /* 0x0560 */
    uint32 : 32U;       /* 0x0564 */
    uint32 : 32U;       /* 0x0568 */
    uint32 : 32U;       /* 0x056C */
    uint32 : 32U;       /* 0x0570 */
    uint32 : 32U;       /* 0x0574 */
    uint32 : 32U;       /* 0x0578 */
    uint32 : 32U;       /* 0x057C */
    uint32 : 32U;       /* 0x0580 */
    uint32 : 32U;       /* 0x0584 */
    uint32 : 32U;       /* 0x0588 */
    uint32 : 32U;       /* 0x058C */
    uint32 : 32U;       /* 0x0590 */
    uint32 : 32U;       /* 0x0594 */
    uint32 : 32U;       /* 0x0598 */
    uint32 : 32U;       /* 0x059C */
    uint32 : 32U;       /* 0x05A0 */
    uint32 : 32U;       /* 0x05A4 */
    uint32 : 32U;       /* 0x05A8 */
    uint32 : 32U;       /* 0x05AC */
    uint32 : 32U;       /* 0x05B0 */
    uint32 : 32U;       /* 0x05B4 */
    uint32 : 32U;       /* 0x05B8 */
    uint32 : 32U;       /* 0x05BC */
    uint32 : 32U;       /* 0x05C0 */
    uint32 : 32U;       /* 0x05C4 */
    uint32 : 32U;       /* 0x05C8 */
    uint32 : 32U;       /* 0x05CC */
    uint32 : 32U;       /* 0x05D0 */
    uint32 : 32U;       /* 0x05D4 */
    uint32 : 32U;       /* 0x05D8 */
    uint32 : 32U;       /* 0x05DC */
    uint32 : 32U;       /* 0x05E0 */
    uint32 : 32U;       /* 0x05E4 */
    uint32 : 32U;       /* 0x05E8 */
    uint32 : 32U;       /* 0x05EC */
    uint32 : 32U;       /* 0x05F0 */
    uint32 : 32U;       /* 0x05F4 */
    uint32 : 32U;       /* 0x05F8 */
    uint32 : 32U;       /* 0x05FC */
    /* Output Buffer */
    uint32 RDDS[64];    /* 0x0600 - 0x06FC */
    uint32 RDHS1;       /* 0x0700 */
    uint32 RDHS2;       /* 0x0704 */
    uint32 RDHS3;       /* 0x0708 */
    uint32 MBS;         /* 0x070C */
    uint32 OBCM;        /* 0x0710 */
    uint32 OBCR;        /* 0x0714 */
    
} frccregs_t;

#define FRCCREGS ((frccregs_t *)0xFFF7C800)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
05/31/11   1.0      LWW      Initial Creation
******************************************************************************/
