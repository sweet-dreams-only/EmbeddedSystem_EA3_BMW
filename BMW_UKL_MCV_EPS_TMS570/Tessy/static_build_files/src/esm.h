/** @file esm.h
*   @brief ESM Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __ESM_H__
#define __ESM_H__

/** @struct esmBase
*   @brief ESM Base Register Definition
*
*   This structure is used to access the ESM module registers.
*/
typedef volatile struct esmBase
{
	
	unsigned ESMIEPSR1;	/*0x00*/
	unsigned ESMIEPCR1;	/*0x04*/
	unsigned ESMIESR1;	/*0x08*/
	unsigned ESMIECR1;	/*0x0C*/
	unsigned ESMILSR1;	/*0x10*/
	unsigned ESMILCR1;	/*0x14*/
	unsigned ESMSR1;	/*0x18*/
	unsigned ESMSR2;	/*0x1C*/
	unsigned ESMSR3;	/*0x20*/
	unsigned ESMEPSR;	/*0x24*/
	unsigned ESMIOFFHR;	/*0x28*/
	unsigned ESMIOFFLR;	/*0x2C*/
	unsigned ESMLTCR;	/*0x30*/
	unsigned ESMLTCPR;	/*0x34*/
	unsigned ESMEKR;	/*0x38*/
	unsigned ESMSSR2;	/*0x3C*/
  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	
} esmBASE_t;

/** @def esmREG
*   @brief ESM Register Frame Pointer
*
*   This pointer is used by the ESM driver to access the esm module registers.
*/
#define esmREG   ((esmBASE_t *)0xFFFFF500U)

/* ESM Interface Functions */

void esmInit(void);
unsigned esmStartSelfTest();
void esmDisableSelfTest();

#define MibADC2_parity_ESM_Channel				1
#define DMA_MPU_ESM_Channel						2
#define DMA_parity_ESM_Channel					3
#define ATCM_correctable_error_ESM_Channel		6
#define NHET_parity_ESM_Channel					7
#define HETTU_parity_ESM_Channel				8
#define HETTU_MPU_ESM_Channel					9
#define Flexray_parity_ESM_Channel				12
#define FTU_parity_ESM_Channel					14
#define VIM_RAM_parity_ESM_Channel				15
#define FTU_MPU_ESM_Channel						16
#define MibSPI1_parity_ESM_Channel				17
#define MibSPI3_parity_ESM_Channel				18
#define MibADC1_parity_ESM_Channel				19
#define DCAN1_parity_ESM_Channel				21
#define DCAN3_parity_ESM_Channel				22
#define DCAN2_parity_ESM_Channel				23
#define MibSPIP5_parity_ESM_Channel				24
#define CCM_R4_compare_ESM_Channel				2


void esm_test(void);
void esmClearErrPin(void);
#endif
