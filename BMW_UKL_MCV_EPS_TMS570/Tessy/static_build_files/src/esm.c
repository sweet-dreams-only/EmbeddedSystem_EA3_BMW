/** @file esm.c 
*   @brief ESM Driver Implementation File
*   @date 14.September.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "system.h"
#include "sci.h"
#include "ftu.h"
#include "dma.h"
#include "esm.h"
#include "adc.h"
#include "can.h"
#include "ccmr4.h"
#include "fray.h"
#include "gio.h"
#include "htu.h"
#include "nhet.h"
#include "spi.h"
#include "sys_vim.h"


/* External Variables */
extern unsigned int SubTask_Number;

/* Global Variables */
unsigned int ESM_High_Int_Flag = 0;

/** @fn void esmInit(void)
*   @brief Initializes the ESM Driver
*
*   This function initializes the ESM module.
*/
void esmInit(void)
{
	/** - Enable the Influence on Error Pin on ESM error*/
	esmREG->ESMIEPSR1 	= 0xFFFFFFFF;		
	
	/** - Disable Group1 ESM interrupt */
	esmREG->ESMIESR1	= 0x00000000;		
	
	/** - 10 VCLK to reset the Pin( to bring it high) */
	esmREG->ESMLTCR		= 0x10;				
}

/** @fn void esmClearErrPin(void)
*   @brief function clears the ESM error pin 
*/
void esmClearErrPin(void)
{
	/** - clear only when the error PIN are set	  	*/
	if(!esmREG->ESMEPSR)					

	/** - clear the error using Error Key Register  */	
	esmREG->ESMEKR  	= 0x5;			

	/** - Wait till the error pin is reset		 	*/
 	while(!esmREG->ESMEPSR);			
}


/** @fn void esmLowLevelInterrupt(void)
*   @breif Low Level Interrupt for ESM
*/
#pragma INTERRUPT(esmLowLevelInterrupt, IRQ)

void esmLowLevelInterrupt(void)
{
	/** - Read the ESM interrupt Offset LOW Register.  */
    volatile unsigned vec = esmREG->ESMIOFFLR;
}

/** @fn void esmHighLevelInterrupt(void)
*   @breif High Level Interrupt for ESM
*/
#pragma INTERRUPT(esmHighLevelInterrupt, FIQ)

void esmHighLevelInterrupt(void)
{
    volatile unsigned vec;
	/** - Read the ESM interrupt Offset High Register.  */
    vec = esmREG->ESMIOFFHR;
	/** - Capture the ESM High Interrupt flag  */
	ESM_High_Int_Flag = vec;

	/** - Clear the Error Status Register  */
	esmREG->ESMSR1 = 0xffffffff;
}


/** @fn esmCheckstatus(unsigned int channel)
 *  @breif Check ESM channel status 
 *   
 */
void esmCheckstatus(unsigned int channel)
{

	if(esmREG->ESMSR1 == (1 << channel))
	{
		/** - Clear the corresponding channel Group 1 ESM  error */
		esmREG->ESMSR1 =  (1 << channel);
		
		sciSend_32bitdata(sciREG1, PASS);
	}
	else if(esmREG->ESMSSR2 == (1 << channel)) // For CCMR4 compare
	{
		/** - Clear the corresponding channel Group 2 ESM  error */
		esmREG->ESMSSR2 = (1 << channel);
		
		sciSend_32bitdata(sciREG1, PASS);
	} 
	else
	{
		sciSend_32bitdata(sciREG1, FAIL);
	}

}

/** @fn void esm_test(void)
 *   
 *   This function is called when a ESM test command is received. 
 * 	 In ESM, required channel test is selected based on the sub task   
 *  
 */
void esm_test(void)
{
	switch(SubTask_Number)
	{
		case 0:
				break;
		case 1:
				/** - DCAN 1 Parity error Test */
				DCAN1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DCAN1_parity_ESM_Channel);
				break;
		case 2:
				/** - DCAN 2 Parity error Test */
				DCAN2_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DCAN2_parity_ESM_Channel);
				break;
		case 3:
				/** - DCAN 3 Parity error Test */
				DCAN3_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DCAN3_parity_ESM_Channel);
				break;
		case 4:
				/** - HTU Parity error Test */
				HTU_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(HETTU_parity_ESM_Channel);
				break;
		case 5:
				/** - MIBSPI 1 Parity error Test */
				MIBSPI1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibSPI1_parity_ESM_Channel);
				break;
		case 6:
				/** - MIBSPI 3 Parity error Test */
				MIBSPI3_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibSPI3_parity_ESM_Channel);
				break;
		case 7:
				/** - MIBSPI 5 Parity error Test */
				MIBSPIP5_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibSPIP5_parity_ESM_Channel);
				break;
		case 8:
				/** - MIBADC 1 Parity error Test */
				MIBADC1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibADC1_parity_ESM_Channel);
				break;
		case 9:
				/** - MIBADC 2 Parity error Test */
				MIBADC2_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibADC2_parity_ESM_Channel);
				break;
		case 10:
				/** - NHET Memory Parity error Test */
				NHET_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(NHET_parity_ESM_Channel);
				break;
		case 11:
				/** - VIM RAM Parity error Test */
				VIMRAM_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(VIM_RAM_parity_ESM_Channel);
				break;
		case 12:
				/** - Flexray Message RAM Parity error Test */
				FRAY_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(Flexray_parity_ESM_Channel);
				break;
		case 13:
				/** - FTU Parity error Test */
				FTU_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(FTU_parity_ESM_Channel);
				break;
		case 14:
				/** - Core Compare Module Compare fail error Test */
				CCM_R4_Compare();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(CCM_R4_compare_ESM_Channel);
				break;
		case 15:
				/** - DMA Parity error Test */
				DMA_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DMA_parity_ESM_Channel);
				break;
		case 16:
				/** - DMA MPU Violation error Test */
				DMA_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DMA_MPU_ESM_Channel);
				break;
		case 17:
				/** - FTU MPU Violation error Test */
				FTU_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(FTU_MPU_ESM_Channel);
				break;
		case 18:
				/** - HTU MPU Violation error Test */
				HTU_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(HETTU_MPU_ESM_Channel);
				break;
		case 19:
				/** - Flash Single Bit Error detection Test */
				ATCM_Correctable_Error();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(ATCM_correctable_error_ESM_Channel);
				break;
	}

}	

