/* Original Header copied from TI file */
/*
 * errata_SSWF021_45_defs.h
 *
 *  Created on: May 12, 2016
 *      Author: a0319960
 */
 /*****************************************************************************
* Module File Name  : errata_SSWF021_45_defs.h
* Module Description: This file contains the function definitions for the errata for PLL provided by TI
					  as per the erratum SSWF021#45
* Product           : Gen II Plus EA3.0
* Author            : Avinash James
*****************************************************************************/
/* Version Control:
 * Date Created:      Sat Jun 04 12:17:00 2016
 * %version:          1 %
 * %derived_by:       rzk04c %
 * %date_modified:    Fri Feb 15 16:29:22 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/23/16  1        AJM        Initial version for PLL errata functions									 EA3#9142
 * 08/24/16  2        AJM        Updated the header information												 EA3#10463
 */

#ifndef INCLUDE_ERRATA_SSWF021_45_DEFS_H_
#define INCLUDE_ERRATA_SSWF021_45_DEFS_H_

typedef volatile struct esmBase
{
    uint32 EEPAPR1;           /* 0x0000                 */
    uint32 DEPAPR1;           /* 0x0004                 */
    uint32 IESR1;             /* 0x0008                 */
    uint32 IECR1;             /* 0x000C                 */
    uint32 ILSR1;             /* 0x0010                 */
    uint32 ILCR1;             /* 0x0014                 */
    uint32 SR1[3U];           /* 0x0018, 0x001C, 0x0020 */
    uint32 EPSR;              /* 0x0024                 */
    uint32 IOFFHR;            /* 0x0028                 */
    uint32 IOFFLR;            /* 0x002C                 */
    uint32 LTCR;              /* 0x0030                 */
    uint32 LTCPR;             /* 0x0034                 */
    uint32 EKR;               /* 0x0038                 */
    uint32 SSR2;              /* 0x003C                 */
    uint32 IEPSR4;            /* 0x0040                 */
    uint32 IEPCR4;            /* 0x0044                 */
    uint32 IESR4;             /* 0x0048                 */
    uint32 IECR4;             /* 0x004C                 */
    uint32 ILSR4;             /* 0x0050                 */
    uint32 ILCR4;             /* 0x0054                 */
    uint32 SR4[3U];           /* 0x0058, 0x005C, 0x0060 */
} esmBASE_t;

typedef volatile struct dccBase
{
    uint32 GCTRL;      	    /**< 0x0000: DCC Control Register		*/
    uint32 REV;      		/**< 0x0004: DCC Revision Id Register 	*/
    uint32 CNT0SEED;    	/**< 0x0008: DCC Counter0 Seed Register	*/
    uint32 VALID0SEED;      /**< 0x000C: DCC Valid0 Seed Register 	*/
    uint32 CNT1SEED;		/**< 0x0010: DCC Counter1 Seed Register 	*/
    uint32 STAT; 			/**< 0x0014: DCC Status Register 		*/
    uint32 CNT0;    		/**< 0x0018: DCC Counter0 Value Register 	*/
    uint32 VALID0;    	    /**< 0x001C: DCC Valid0 Value Register 	*/
    uint32 CNT1;      	    /**< 0x0020: DCC Counter1 Value Register	*/
    uint32 CNT1CLKSRC;   	/**< 0x0024: DCC Counter1 Clock Source Selection Register 	*/
    uint32 CNT0CLKSRC;   	/**< 0x0028: DCC Counter0 Clock Source Selection Register 	*/
} dccBASE_t;

enum dcc1clocksource
{
    DCC1_CNT0_HF_LPO    = 0x5U,    /**< Alias for DCC1 CNT 0 CLOCK SOURCE 0*/
    DCC1_CNT0_TCK       = 0xAU,    /**< Alias for DCC1 CNT 0 CLOCK SOURCE 1*/
    DCC1_CNT0_OSCIN     = 0xFU,    /**< Alias for DCC1 CNT 0 CLOCK SOURCE 2*/

    DCC1_CNT1_PLL1      = 0x0U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 0*/
    DCC1_CNT1_PLL2      = 0x1U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 1*/
    DCC1_CNT1_LF_LPO    = 0x2U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 2*/
    DCC1_CNT1_HF_LPO    = 0x3U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 3*/
    DCC1_CNT1_EXTCLKIN1 = 0x5U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 4*/
    DCC1_CNT1_EXTCLKIN2 = 0x6U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 6*/
    DCC1_CNT1_VCLK      = 0x8U,    /**< Alias for DCC1 CNT 1 CLOCK SOURCE 8*/
    DCC1_CNT1_N2HET1_31 = 0xAU     /**< Alias for DCC1 CNT 1 CLOCK SOURCE 9*/
};

#define SYS_CLKSRC_PLL1 0x00000002U
#define SYS_CLKSRC_PLL2 0x00000040U
#define SYS_CLKCNTRL_PENA 0x00000100U
#define ESM_SR1_PLL1SLIP 0x400U
#define ESM_SR4_PLL2SLIP 0x400U
#define PLL1 0x08
#define PLL2 0x80
#define dcc1CNT1_CLKSRC_PLL1 0x0000A000U
#define dcc1CNT1_CLKSRC_PLL2 0x0000A001U

#define esmREG ((esmBASE_t *)0xFFFFF500U)
#define dccREG1   ((dccBASE_t *)0xFFFFEC00U)


#endif /* INCLUDE_ERRATA_SSWF021_45_DEFS_H_ */
