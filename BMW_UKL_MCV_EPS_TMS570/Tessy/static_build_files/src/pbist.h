/** @file pbist.h
*   @brief PBIST Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __PBIST_H__
#define __PBIST_H__

/** @struct pbistBase
*   @brief PBIST Base Register Definition
*
*   This structure is used to access the PBIST module registers.
*/
typedef volatile struct pbistBase
{
	unsigned VAR0;
    unsigned VAR1;
	unsigned VAR2;
	unsigned VAR3;
    unsigned VLCR0;
	unsigned VLCR1;
    unsigned VLCR00;
	unsigned VLCR11;
	unsigned DD0D1;
	unsigned DE0E1;
	unsigned int:32;
	unsigned int:32;
	unsigned CARA0;
	unsigned CARA1;
	unsigned CARA2;
	unsigned CARA3;
	unsigned CLCRL0;
	unsigned CLCRL1;
	unsigned CLCRL2;
	unsigned CLCRL3;
	unsigned CIRIO;
	unsigned CIRI1;
	unsigned CIRI2;
	unsigned CIRI3;
	unsigned RAM;
	unsigned DLR;
	unsigned CMS;
	unsigned STR;
	unsigned int:32;
	unsigned int:32;
	unsigned CSR;
	unsigned FDLY;
	unsigned PACT;
	unsigned PBISTID;
	unsigned PBISTOVERRRIDE;
	unsigned int:32;
	unsigned FSRFO;
	unsigned FSRF1;
	unsigned FSRC0;
	unsigned FSRC1;
	unsigned FSRA0;
	unsigned FSRA1;
	unsigned FSRDL0;
	unsigned int:32;
	unsigned FSRDL1;
	unsigned int:32;
	unsigned int:32;
	unsigned int:32;
	unsigned ROM;
	unsigned ALGO;
	unsigned RINFOL;
	unsigned RINFOU;  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	
} pbistBASE_t;

/** @def pbistREG
*   @brief PBIST Register Frame Pointer
*
*   This pointer is used by the PBIST driver to access the pbist module registers.
*/
#define pbistREG   ((pbistBASE_t *)0xFFFFE500U) /* Actual Frame starts from 400 but 400 to 500 we do not have header definition */

/* PBIST Interface Functions */
void pbistInit(unsigned int RAM_GRP_SEL);
void pbistStartSelfTest(void);
void pbistDisableSelfTest(void);
void pbist_test(void);



/* PBIST RAM Algo select */
unsigned const int RAM_GRP_ALGO_SEL[16]=
					{
						0x0000FFFF,			/* ALL RAM SELCTED TOGETHER */
						0x00000003,			/* PBIST ROM */
						0x00000003,			/* STC ROM */
						0x00001554,			/* DCAN1 RAM */ 
						0x00001554,			/* DCAN2 RAM */
						0x00001554,			/* DCAN3 RAM */
						0x00001554,			/* ESRAM */
						0x00001554,			/* MIBSPI RAM */
						0x00001554,			/* VIM RAM */
						0x00002AA8,			/* MIBADC RAM */
						0x0000CAA8,			/* DMA RAM */
						0x00002AA8,			/* NHET RAM */
						0x00002AA8,			/* HTU RAM */
						0x00002AA8,			/* RTP RAM */
						0x00001554,			/* FLEXRAY RAM */
						0x00002AA8			/* ESRAM */
					};

enum RAM_GRP
{
	RAM_GRP_ALL = 0,
	RAM_GRP1 = 1,
	RAM_GRP2 = 2,
	RAM_GRP3 = 3,
	RAM_GRP4 = 4,
	RAM_GRP5 = 5,
	RAM_GRP6 = 6,
	RAM_GRP7 = 7,
	RAM_GRP8 = 8,
	RAM_GRP9 = 9,
	RAM_GRP10 = 10,
	RAM_GRP11 = 11,
	RAM_GRP12 = 12,
	RAM_GRP13 = 13,
	RAM_GRP14 = 14,
	RAM_GRP15 = 15
};

#define ALGO_SEL_RAM_GRP1	0x00000003			/* PBIST ROM */
#define ALGO_SEL_RAM_GRP2	0x00000003			/* STC ROM */
#define ALGO_SEL_RAM_GRP3	0x00001554			/* DCAN1 RAM */ 
#define ALGO_SEL_RAM_GRP4	0x00001554			/* DCAN2 RAM */
#define ALGO_SEL_RAM_GRP5	0x00001554			/* DCAN3 RAM */
#define ALGO_SEL_RAM_GRP6	0x00001554			/* ESRAM */
#define ALGO_SEL_RAM_GRP7	0x00001554			/* MIBSPI RAM */
#define ALGO_SEL_RAM_GRP8	0x00001554			/* VIM RAM */
#define ALGO_SEL_RAM_GRP9	0x00002AA8			/* MIBADC RAM */
#define ALGO_SEL_RAM_GRP10	0x0000CAA8			/* DMA RAM */
#define ALGO_SEL_RAM_GRP11	0x00002AA8			/* NHET RAM */
#define ALGO_SEL_RAM_GRP12	0x00002AA8			/* HTU RAM */
#define ALGO_SEL_RAM_GRP13	0x00002AA8			/* RTP RAM */
#define ALGO_SEL_RAM_GRP14	0x00001554			/* FLEXRAY RAM */
#define ALGO_SEL_RAM_GRP15	0x00002AA8			/* ESRAM */

#endif
