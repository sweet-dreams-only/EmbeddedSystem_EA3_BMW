/** @file stc.h
*   @brief STC Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __STC_H__
#define __STC_H__

/** @struct stcBase
*   @brief STC Base Register Definition
*
*   This structure is used to access the STC module registers.
*/

typedef volatile struct stcBase
{
	unsigned STCGCR0;
	unsigned STCGCR1;
	unsigned STCTPRL;
	unsigned STC_CADDR;
	unsigned STCCICR;
	unsigned STCGSTAT;
	unsigned STCFSTAT;
	unsigned CPU1_CURMISR;
	unsigned CPU2_CURMISR;
} stcBASE_t;

/** @def stcREG
*   @brief STC Register Frame Pointer
*
*   This pointer is used by the STC driver to access the stc module registers.
*/
#define stcREG   ((stcBASE_t *)0xFFFFE600U)

/* PBIST Interface Functions */
void stcInit(void);
void stc_test(void);
void stcStartSelfTest(void);

#endif
