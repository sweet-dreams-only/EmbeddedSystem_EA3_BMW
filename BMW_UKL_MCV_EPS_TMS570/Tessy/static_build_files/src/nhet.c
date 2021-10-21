/** @file nhet.c 
*   @brief nhet Driver Inmplmentation File
*   @date 11.August.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "nhet.h"
#include "std_het.h"
#include "pulse.h"

/** @fn void NHET_Parity(void)
*   @brief NHET RAM Parity Error creation and check routines.
*/
void NHET_Parity(void)
{
	unsigned int temp;
	unsigned int *RAMBASE = (unsigned int *)nhetMEM;

	/** Enable NHET Parity */
	nhetREG->HETPCR = 0x0000000A;
	
	/** Fill NHET RAM with known Pattern 
	 *  The Parity Gets updated while filling the RAM */	
	for (temp=0;temp<0x080;temp++)
	{
		*RAMBASE = 0xA5A5A5A5;
		RAMBASE++;
	}
	
	/** Enable access to parity RAM */
	nhetREG->HETPCR |= 0x00000100;
	
	/** Corrupt the Parity RAM location to introduce a 
	 *  Single bit error */
	RAMBASE = (unsigned int *) (nhetMEM+0x2000) ;
	*RAMBASE =~(*RAMBASE);

	/** Disable access to parity RAM */
	nhetREG->HETPCR &= ~(0x00000100);

	/** Read NHET RAM location to create Parity Error */
	RAMBASE = (unsigned int *)nhetMEM;
	temp = *RAMBASE;
}

/** @fn void nhetInit_htu_MPU(void)
*   
*   This function is called by HTU MPU test. 
*   A simple Pulse generated and captured on Pin 6 and 7.
* 	Refer pulse.het for more details
*/
void nhetInit_htu_MPU(void) 
{     
    /** - Copy the NHET opcode in opcode.c to NHET memory
     *    Refer pulse.het for more details on the Instructions */
    memcpy((void*) nhetMEM, (void*) HET_INIT0_PST, sizeof(HET_INIT0_PST));
    
    /** - Reset NHET - Turn Off */
    nhetREG->GCR     	= 0x0000000; 
    
    /** - Configure High resolution and Loop resolution 
     *    prescale factors */	
	nhetREG->PFR     	= 0x123;
    
    /** - Configure all pins except Pin 6 as output */    
    nhetREG->CCDIR   	= 0xFFFFFFBF;
    
    /** - Take all pins to level 0 */  	
  	nhetREG->CCDWR   	= 0x00000000;
    
    /** - Clear all Interrupt Flags */    
    nhetREG->INTFLAG 	= 0xFFFFFFFF;
    
    /** - Enable all 8 request lines */	
	nhetREG->HETREQEN 	= 0x000000FF;
    
    /** - Loopback Pin 6 and 7 - used for HTU MPU test */	
	nhetREG->HETLPBSEL  = 8;
    
    /** - Enable I/O DFT and Pin 6/7 HR Structure are internally connected */	
	nhetREG->HETLPBDIR  = 0x000A0008;
    
    /** - NHET is configured as Master 
     *  - NHET is turned On*/    
    nhetREG->GCR     	= 0x00010001; 
}
/** @fn void nhetInit_Pin_Clr(void)
*   
*   This function clears all NHET pins to zero
*/
void nhetInit_Pin_Clr(void) 
{     
   	/** - NHET is configured as Master 
     *  - NHET is turned On */  
   	nhetREG->GCR     	= 0x01000001; 
    
    /** - Configure all pins as output */   	
   	nhetREG->CCDIR   	= 0xFFFFFFFF; 

	/** - Take all pins to level 0  */
	nhetREG->CCDWR   	= 0x00000000;

	/** - PULL functinality is enabled */
	nhetREG->HETPULDIS	= 0x00000000;
}

/** @fn void nhetInit_Pin_Clr(void)
*   
*   This function clears all previous NHET test configurations
*   Take NHET pins[0-5]( LED) to Zero 
*/
void nhetDisable() 
{     
	/** - Reset NHET - Turn Off */
    nhetREG->GCR     	= 0x00000000;
     
    /** - Enable I/O DFT */
	nhetREG->HETLPBDIR  = 0x00050000;

    /** - NHET is configured as Master 
     *  - NHET is turned On */    
  	nhetREG->GCR     	= 0x01000001; 
	
	/** - Configure NHET[0-5] pins as output */
   	nhetREG->CCDIR   	= 0x0000003F; 
	
	/** - Take all pins to level 0 */
	nhetREG->CCDWR   	= 0x00000000;
	
	/** - PULL functinality is enabled */
	nhetREG->HETPULDIS	= 0x00000000;
	
	/** - Reset NHET - Turn Off */
	nhetREG->GCR     	= 0x00000000;
}
