/** @file nhet.h
*   @brief NHET Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __NHET_H__
#define __NHET_H__

/** @struct nhetBase
*   @brief NHET Base Register Definition
*
*   This structure is used to access the NHET module registers.
*/
typedef volatile struct nhetBase
{
	unsigned GCR;		/* global control register */
	unsigned PFR;		/* prescale factor register */
	unsigned ADDR;		/* current address register */
	unsigned OFF1;		/* offset level 1 register */
	unsigned OFF2;		/* offset level 2 register */
	unsigned INTENAS;
	unsigned INTENAC;
	unsigned EXC1;		/* exceptions interrupt control register 1 */
	unsigned EXC2;		/* exceptions interrupt control register 2 */
	unsigned INTPRY;	/* interrupt priority register */
	unsigned INTFLAG;	/* interrupt flag register */
	unsigned fill1;		/* reserved */
	unsigned fill2;		/* reserved */
	unsigned HRSHARE;	/* HR share control register */
	unsigned XORSHARE;	/* XOR SHARE */
	unsigned HETREQEN;	/* request enable*/
	unsigned HETREQDIS;	/* request Disable*/
	unsigned HETREQDEST;/* request Destination*/
	unsigned fill3;	
	unsigned CCDIR;		/* capture-compare direction register */
	unsigned CCDIN;		/* capture-compare input data register */
	unsigned CCDWR;		/* capture-compare write */
	unsigned CCDSET;	/* capture-compare set */
	unsigned CCDCLR;	/* capture-compare clear */
	unsigned HETPDR;	/* open drain */
	unsigned HETPULDIS;	/* pull disable*/
	unsigned HETPSL;
	unsigned fill4;		/* pull select*/ 
	unsigned fill5;		/* Slew Rate*/
	unsigned HETPCR;	/* parity */
	unsigned HETPAR;	/* parity  address*/
	unsigned HETPPR;	/* parity pin*/
	unsigned HETSFPRLD;	/* suppresion filter*/
	unsigned HETSFENA;	/* suprresion filter enable */
	unsigned fill6;
	unsigned HETLPBSEL;	/* loopback pair */
	unsigned HETLPBDIR;	/* loopback mode direction*/
	unsigned HETPINDIS;
} nhetBASE_t;

/** @def nhetREG
*   @brief NHET Register Frame Pointer
*
*   This pointer is used by the NHET driver to access the nhet module registers.
*/
#define nhetREG   ((nhetBASE_t *)0xFFF7B800U)

#define nhetMEM   0xFF460000U

/* NHET Interface Functions */

void NHET_Parity(void);
void nhetDisable(void);
void nhetInit_htu_MPU(void);
void nhetInit_Pin_Clr(void);

#endif
