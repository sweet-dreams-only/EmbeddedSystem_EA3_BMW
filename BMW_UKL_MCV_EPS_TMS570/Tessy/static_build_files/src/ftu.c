/** @file ftu.c 
*   @brief ftu Driver Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*/

/* (c) Texas Instruments 2009, All rights reserved. */

#include "ftu.h"

/** @fn void FTU_Parity(void)
*   @brief FTU memory Parity error creation and check routines.
*/

void FTU_Parity(void)
{
	volatile unsigned int temp;
	
	/** enable TU and parity protection */
	ftuREG->GCS_UN.GCS_UL =  (0xA << 16) 	/* Parity Protection Switched On */
							|(3 << 4)		/* Status and Error Interrupt Enabled */
							|(1 << 0);		/* Transfer Unit Enabled */
	
	/** - Fill up the Transfer Configuration RAM, whos parity will be corrupt */
	ftuMEM->FTUTCR_ST[0].TCR_UN.TCR_UL = 0xFFFFFFFF;//Transfer header and payload to cc

	/** - Fill up the Transfer Configuration RAM, whos parity will be corrupt */
	ftuREG->GCS_UN.GCS_UL |= (1 << 20);	/* Enable access to Parity Locations */
	
	/** - Corrupt Parity bit to generate Parity Error while accessing */
	ftuParMEM->FTUTCRPT_ST[0].TCRPT_UN.TCRPT_UL = ~(ftuParMEM->FTUTCRPT_ST[0].TCRPT_UN.TCRPT_UL);
	
	/** enable TU and parity protection */
	ftuREG->GCS_UN.GCS_UL =  (0 << 20) 		/* Disable direct access to parity locations */
							|(0xA << 16) 	/* Parity Protection Switched On */
							|(3 << 4)		/* Status and Error Interrupt Enabled */
							|(1 << 0);		/* Transfer Unit Enabled */

	/** - Perform Read to cause parity error */ 
	temp = ftuMEM->FTUTCR_ST[0].TCR_UN.TCR_UL;	
	
	/** - Wait for the Parity Error bit to set */
	while(ftuREG->TEIR_UN.TEIR_ST.PE_B1 == 0);
	
	/** - Read Parity Error Address */
	temp = ftuREG->PEADR_UL;
	
	/** Parity Protection Switch Off */
	ftuREG->GCS_UN.GCS_UL = 0x50000;
}

/** @fn void FTU_MPU(void)
*   @brief FTU memory protection Unit access error creation and check routines.
*/

void FTU_MPU(void)
{
	unsigned int buffer[10],i;

	/** - Fill up the buffer */	
	buffer[0]= 0x11111111;  /* header 1 */
	buffer[1]= 0x080000;	/* header 2 */
	buffer[2]= 0x40;
	buffer[3]= 0x40;

	buffer[4]= 0xffff;
	buffer[5]= 0xa5a5;
	buffer[6]= 0xf0f0;
	buffer[7]= 0x5a5a;
	
	/** - Configure transfer base Address */	
	ftuREG->TBA_UL 	= (unsigned long) buffer;
	
	/** - Enable transfer buffer header to the communication controller */
	ftuMEM->FTUTCR_ST[1].TCR_UN.TCR_UL = 0x00008000;
	
	/** - Configure Start Address of Memory Protection */	
	ftuREG->SAMP_UL = (unsigned long) buffer;
	/** - Configure End Address of Memory Protection */	
	ftuREG->EAMP_UL = (unsigned long) &buffer[3];

	/** enable TU and parity protection */
	ftuREG->GCS_UN.GCS_UL =  (0 << 20) 		/* Disable direct access to parity locations */
							|(5 << 16) 		/* Parity Protection Switched Off */
							|(3 << 4)		/* Status and Error Interrupt Enabled */
							|(1 << 0);		/* Transfer Unit Enabled */

	/** Trigger Transfer to communication controller */
	ftuREG->TTCCS1_UL 	= 0x02;
	
	/** Small Dealy */
	for(i=0;i<1000; i++);
	
	/** - Enable transfer of Payload to the communication controller */
	ftuMEM->FTUTCR_ST[1].TCR_UN.TCR_UL = 0x00004000;

	/** - Configure Start Address of Memory Protection */
	ftuREG->SAMP_UL = (unsigned long) buffer;
	
	/** - Configure End Address of Memory Protection */
	ftuREG->EAMP_UL = (unsigned long) &buffer[1];
	
	/** Trigger Transfer to communication controller */
	ftuREG->TTCCS1_UL = 0x02;

	/** Wait untill Memory Protection violation occurs */
	while((ftuREG->TEIR_UN.TEIR_UL & 0xF0000) != 0x20000);
	
	/** Disable FTU*/
	ftuREG->GCS_UN.GCS_UL 	= 0;
	
	/** Clear all Trasfer Requests */
	ftuREG->TTCCS1_UL 		= 0x00;

	/** Clear the Memory Protection violation error Flag */
	ftuREG->TEIR_UN.TEIR_UL = 0x20000;
}

