/** @file htu.c 
*   @brief htu Driver Implementation File
*   @date 11.August.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "htu.h"
#include "nhet.h"

/** @fn void HTU_Parity(void)
*   @brief HTU memory Parity error creation and check routines.
*/
void HTU_Parity(void)
{

	unsigned int temp;
	
	/** Pointer assigned to the HTU memory */
	unsigned int *RAMBASE = (unsigned int *)htuMEM;

	/** Enable HTU RAM Parity */
	htuREG->HTUPCR = 0x0000000AU;
	
	/** Fill NHET RAM with known Pattern 
	 *  The Parity Gets updated while filling the RAM 
	 */	
	for (temp=0;temp<0x080;temp++)
	{
		*RAMBASE = 0xA5A5A5A5;
		RAMBASE++;
	}
	
	/** Enable access to parity RAM */
	htuREG->HTUPCR |= 0x00000100U;
	
	/** Corrupt the Parity RAM location to introduce bit error */
	RAMBASE = (unsigned int *) (htuMEM+0x200);
	*RAMBASE =~(*RAMBASE);

	/** Disable access to parity RAM*/
	htuREG->HTUPCR &= 0xFFFFFEFFU;

	/** Read HTU RAM location to create Parity Error */
	RAMBASE = (unsigned int *)htuMEM;
	temp = *RAMBASE;
}

/** @fn void HTU_MPU(void)
*   @brief HTU memory Parity error creation and check routines.
*/
void HTU_MPU(void)
{
	unsigned int dest_buffer[20];
	
	/** - Configure Initial Address of the Buffer A */
	htuDCBCP->DCBCP_ST[0].IFADDRA =  (unsigned int) dest_buffer; 
	/** - Configure Initial Element Count */
	htuDCBCP->DCBCP_ST[0].IETCOUNT = 3;
	/** - Configure Initial Frame Count */	
	htuDCBCP->DCBCP_ST[0].IFTCOUNT = 4;
	/** - Initial NHET address ( Address of PCNT Instruction ) */
	htuDCBCP->DCBCP_ST[0].IHADDR = 0x00000030;
	
	/** - Disable HTU */
	htuREG->GC = 0;
		
	/** - Configure Memory Protection Registers */
	htuREG->MPCS = 	 (1 << 2)	/* Error Signalling is Enabled */
					|(1 << 1)	/* Any access to the region is forbidden */
					| 1;		/* Enable Region 0 */
	/** - Configure Start Address */
	htuREG->MPS = (unsigned long) dest_buffer; 

	/** - Configure End Address */
	htuREG->MPE = (unsigned long) dest_buffer + 8; 

	/** - Enable Control Packet */
	htuREG->CPENA = 0x01;

	/** - HTU makes atleast 12 address (frame*ele = 4*3 = 12)
	* 	  MPE allows only 8 access so MPU generates memory protection error
	*/
	/** - Enable HTU */			
	htuREG->GC = 0x00010000;  //Enable the HTU

	/** configure NHET and Start*/
	nhetInit_htu_MPU();
		
	/** Wait for the Memory Protection Error Fault flag to get set */
	while ((htuREG->MPCS &0x000F0000) == 0);

	/** - Reset MPU region Configurations */
	htuREG->MPCS= 0x00;
	
	/** - Disable HTU */
	htuREG->GC = 0;

	/** Stop NHET*/
	nhetDisable();
}
