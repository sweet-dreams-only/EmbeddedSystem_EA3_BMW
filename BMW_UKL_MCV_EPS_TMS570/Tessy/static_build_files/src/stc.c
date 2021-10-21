/** @file stc.c 
*   @brief STC Driver Implmentation File
*   @date 14.September.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "stc.h"
#include "system.h"
#include "sci.h"
asm("	.global  _Continue_after_STC");

extern void _coreBackupStackPointer_(void);
extern void _coreRestoreStackPointer_(void);

/** @fn void stcInit(void)
*   @brief Initializes the STC Driver
*
*   This function initializes the STC module.
*/
void stcInit(void)
{

	/* Clear CPU RST bit in Exception Status Register in Sys module */	
	SYSTEM_1->SYSESR = 0x20U; 

	/* clock rate for STC/LBIST = 12.5MHz when HCLK=100MHz 
	 * 100 / 8 = 12.5 MHz */	
	SYSTEM_2->STCCLKDIV = 7U;
	
  	/* Select the Test interval for Max coverage, 32 Interval for 90.84 */
  	stcREG->STCGCR0 = (32 << 16);

  	/* Restart the Test from Interval 0 */
  	stcREG->STCGCR0 |= 1;

  	/* Configure the SelfTest Run Time out counter preload Register */
  	stcREG->STCTPRL = 0xFFFFFFFF;
}

/** @fn void stcStartSelfTest(void)
*   @brief Function used to start the STC self test
*
*   Note : Reset occurs once the STC is triggered and completed. 
*/
void stcStartSelfTest(void)
{
	/** - Backup Stack pointers before stating STC test */
	_coreBackupStackPointer_();

  	/** - Enable the STC Self Test */
  	stcREG->STCGCR1 = 0xA;

  	/** - Enter ARM IDLE state to start the test  */
  	asm("	WFI");
    asm("	nop");
  	asm("	nop");
  	asm("	nop");
  	/** - When STC test completes a CPU reset occurs. 
  	 *  - After checking whether the reset is caused by STC 
  	 *    the code will brach here to continue the reset of the code	 */
  	asm("_Continue_after_STC:	nop");
  	asm("	nop");
  	asm("	nop");
  	asm("	nop");
  	asm("	nop");
	
	/** - Restore Stack pointers after STC test */
 	_coreRestoreStackPointer_();

	if((SYSTEM_1->SYSESR & 0x20) == 0x20U)
	{	//return TRUE;
		sciSend_32bitdata(sciREG1, 1);
	}
	else
	{
		//return FALSE;
		sciSend_32bitdata(sciREG1, 0);
	}

	/** - Clear the Status register after STC complete */
	stcREG->STCGSTAT =  0x3;

	/** - Disable the Self Test */  	
   	stcREG->STCGCR1 = 0x5;
}

/** @fn void stc_test(void)
*   @brief Function used to perform STC self test.
*/
void stc_test(void)
{
	/** - Initialize STC module */
	stcInit();
	
	/** - Start STC Self Test */
	stcStartSelfTest();
}	

