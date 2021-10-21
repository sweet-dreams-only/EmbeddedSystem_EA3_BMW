/** @file fray.c 
*   @brief fray Driver Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*/

/* (c) Texas Instruments 2009, All rights reserved. */

#include "fray.h"

/** @fn void FRAY_Parity(void)
*   @brief Fray Parity error creation and check routines.
*/

void FRAY_Parity(void)
{
	
	unsigned int temp,error;

	/** - Wait for CLEAR_RAMS commando to be finished */
	while((frayREG->SUCC1_UN.SUCC1_UL & 0x00000080) != 0);

	/** - Fill the FRAY Buffer */
	for(temp=0;temp<64;temp++)
	{
		frayREG->WRDS[temp] = 0xFFFFFFFF;
	}

	/** - Enter test Mode Key Sequence to wrie to WRTEN bit */
	frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x75;
	frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x8A;
	frayREG->TEST1_UN.TEST1_ST.wrten_B1 = 0x01;
	
	/** - Enable the RAM test mode */
	frayREG->TEST1_UN.TEST1_ST.tmc_B2   = 0x01;
	
	/** - Enable Access to memory RAM - (0 to 0x3FF) */
	frayREG->TEST2_UN.TEST2_ST.ssel_B3  = 0x0;
	
	/** - Memory Map Input Buffer RAM 1 */
	frayREG->TEST2_UN.TEST2_ST.rs_B3    = 0x00;
    
	/** - Corrupt Parity bit to generate Parity Error while accessing */
    frayREG->TEST2_UN.TEST2_ST.wrpb_B1  = ~(frayREG->TEST2_UN.TEST2_ST.wrpb_B1);

	/** - Write Data section with some new data */
	frayREG->WRDS[0] = 0xFFFFFF33;
	frayREG->WRDS[1] = 0xFFFFFF44;
	
	/** - Perform Read to cause parity error */
	temp = frayREG->WRDS[0];
	
	/** - Clear the Parity Bit location, undo corruption */
    frayREG->TEST2_UN.TEST2_ST.wrpb_B1 = 0x0;
	
	/** - Enter test Mode Key Sequence to wrie to WRTEN bit */
  	frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x75;
  	frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x8A;
  	frayREG->TEST1_UN.TEST1_ST.wrten_B1 = 1;
	
	/** - Sequence to get out of CONFIG_STATE */
  	frayREG->LCK_UN.LCK_ST.clk_B8 = 0xCE;
  	frayREG->LCK_UN.LCK_ST.clk_B8 = 0x31;
  	
  	/** - Issue CLEAR_RAMS Command to clear FRAY RAM Contents */
  	frayREG->SUCC1_UN.SUCC1_UL = ((frayREG->SUCC1_UN.SUCC1_UL & 0xFFFFFFF0) | 0xC);
	
	/** - Wait for CLEAR_RAMS commando to be finished */
	while((frayREG->SUCC1_UN.SUCC1_UL & 0x00000080) != 0);

	/** - Set error Flag if parity error is not set */
	if( frayREG->EIR_UN.EIR_ST.perr_B1 != 0x1)
	error = 1;
	
	/** - Clear the Parity Error Flag */
	frayREG->EIR_UN.EIR_ST.perr_B1 = 0x1;
	
	/** - Set error Flag if parity error bit is not cleared */
	if( frayREG->EIR_UN.EIR_ST.perr_B1 != 0x0)
	error = ((error <<1 ) | 1);
	
	/** - Enter test Mode Key Sequence to wrie to WRTEN bit */
    frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x75;
    frayREG->LCK_UN.LCK_ST.tmk_B8 		= 0x8A;
    frayREG->TEST1_UN.TEST1_ST.wrten_B1 = 0x01;
	
	/** - Disable the RAM test mode */
    frayREG->TEST1_UN.TEST1_ST.tmc_B2 	= 0x00;
    frayREG->TEST2_UN.TEST2_UL			= 0x00;
	
}
