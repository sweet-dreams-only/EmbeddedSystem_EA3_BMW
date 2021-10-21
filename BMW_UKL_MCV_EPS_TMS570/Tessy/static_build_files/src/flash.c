/** @file flash.c 
*   @brief flash Driver Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*/

/* (c) Texas Instruments 2009, All rights reserved. */

/* USER CODE BEGIN (0) */
extern void _coreEnableFlashEcc_(void);
extern void _coreDisableFlashEcc_(void);
/* USER CODE END */


/* Include Files */

#include "system.h"
#include "sci.h"

/** @fn void ATCM_Correctable_Error(void)
*   @brief Flash Single Bit ECC error creation and check routines.
*/

void ATCM_Correctable_Error(void)
{
	unsigned int Single_Bit_Err_Loc;

    /** - 0x604204 is TI OTP location which has corrupted data "0x9ABCDEF1" */
	unsigned int * Single_Bit_Err_Loc_ptr = (unsigned int *)(0x0604204);
	
    /** - Setup Flash ECC  
    *     - Error Detection / Correction Enable
    *     - Erros from OTP memory regions unblocked
    *     - Correctable Interrupt Enabled
    */
	FLASHW->FEDACCTRL1 = 0x20D;

    /** Enable Flash ECC in Cortex R4*/
	_coreEnableFlashEcc_();

    /** - Read data from the Single Bit Error location 
	 *	  - ESM error will be triggered after this read
	 *	  - Data will be corrected and stored in the variable Single_Bit_Err_Loc
	 */
	Single_Bit_Err_Loc = * Single_Bit_Err_Loc_ptr;

    /** - Verify that corrected data is stored in the variable
     *  - Transmit back 0x0000000 to PC incase of failure
     */
	if(Single_Bit_Err_Loc != 0x9ABCDEF0)
	{
		sciSend_32bitdata(sciREG1, FAIL);
	}

    /** - Clear the Flash Single Bit error Flag */
	FLASHW->FEDACSTATUS = 2;

    /** - Disable Flash Error Detection / Correction */
	FLASHW->FEDACCTRL1 = 0x005;

    /** Disable Flash ECC in Cortex R4*/
	_coreDisableFlashEcc_();

}
