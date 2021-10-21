/** @file ccmr4.c 
*   @brief CCMR4 Driver Source File to check CCMR4 compare error
*   @date 10.August.2009
*   @version 1.00.000
*.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

#include "ccmr4.h"

extern unsigned int ESM_High_Int_Flag;

/** @fn void CCM_R4_Compare(void)
*   @brief CCMR4 Compare fail Error creation and check routines.
*/
void CCM_R4_Compare(void)
{
	/* Setting the Error forcing mode   */	
	CCMR4REG->CCMKEYR_UN.CCMKEYR_ST.MKEY = 0x09; 

    /* Waiting for interrupt ESM Interrupt flag */
	while(!ESM_High_Int_Flag);				

 	/* Clear the Interrupt Flag */
 	ESM_High_Int_Flag=0;						

}

