/** @file dma.c 
*   @brief DMA Driver Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*   This file contains:
*   - API Funcions
*   - Interrupt Handlers
*   .
*   which are relevant for the DMA driver.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "dma.h"

/** @fn void DMA_MPU(void)
*   @brief DMA Memory Protection Unit Error creation and check routines.
*/
 
void DMA_MPU(void)
{
	unsigned int Source_address[10],Destination_address[10];
	
	/** - Reset DMA*/
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_RESET=1;
	
    /** - Enable DMA */
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_EN=1;

    /** - Immediately stop at an DMA arbitration boundary and continue after 
	 *    suspend */
	dmaREG->GCTRL_UN.GCTRL_ST.DEBUG_MODE =0x3;
	
	/** - Configure the Start addresss for MPU the Region */
	dmaREG->DMAMPR3S_UL = (unsigned int) &Destination_address[0];

	/** - Configure the End addresss for MPU the Region */
	dmaREG->DMAMPR3E_UL = (unsigned int) (&Destination_address[0] + 0xF0);

	/** - Configure the End addresss for MPU the Region 
	*     Enable Region 3
	*     Configure Region 3 as Write protected
	*     Enable Interrupt on Memory Protection Violation, this is hooked up to ESM channel.
	*/
	dmaREG->DMAMPCTRL_UN.DMAMPCTRL_ST.REG3ENA 	= 1;
	dmaREG->DMAMPCTRL_UN.DMAMPCTRL_ST.REG3AP 	= 1;
	dmaREG->DMAMPCTRL_UN.DMAMPCTRL_ST.INT3ENA 	= 1;

	/** - Configure the DMA Control Packet 
	*   	-Configure Source Address 
	*   	-Configure Destination Address 
	*   	-Configured as 1 Frame with 5 Elements 
	*   	-Read = Write access = 64 bit 
	*   	-Configure Block Transfer
	*   	-Address Increment on Read and Write access.
	*   	-AutoInitialization OFF
	*   	-Data Chaining and Offset control not configured.
	*/
	dmaMEM->PCP_ST[3].ISADDR_UL = (unsigned int)&Source_address[0];
  	dmaMEM->PCP_ST[3].IDADDR_UL = (unsigned int)&Destination_address[0];
  	dmaMEM->PCP_ST[3].ITCOUNT_UN.ITCOUNT_ST.IFTCOUNT = 1;
  	dmaMEM->PCP_ST[3].ITCOUNT_UN.ITCOUNT_ST.IETCOUNT = 5;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.RES = ACCESS_64_BIT;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.WES = ACCESS_64_BIT;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.TTYPE = BLOCK_TRANSFER;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.ADDMR = ADDR_INC1;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.ADDMW = ADDR_INC1;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.AIM = AUTOINIT_OFF;
  	dmaMEM->PCP_ST[3].CHCTRL_UN.CHCTRL_ST.CHAIN = 0;
  	dmaMEM->PCP_ST[3].EIOFF_UN.EIOFF_ST.EIDXD = 0;
  	dmaMEM->PCP_ST[3].EIOFF_UN.EIOFF_ST.EIDXS = 0;
  	dmaMEM->PCP_ST[3].FIOFF_UN.FIOFF_ST.FIDXD = 0;
  	dmaMEM->PCP_ST[3].FIOFF_UN.FIOFF_ST.FIDXS = 0;

    /** - Port B is assigned for the Data Transfer */
	dmaREG->PAR_UL[0] = 0x00040000;

    /** - Start DMA transfer, Enable Channel 3 */
	dmaREG->SWCHENAS_UL = (1 << 3);

    /** - Wait till the Memory Protection Status register reflect the MPU error on Region 3 */
	while(dmaREG->DMAMPST_UN.DMAMPST_ST.REG3FT == 0);

   	/** - Reset DMA*/
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_RESET = 0;
}

/** @fn void DMA_Parity(void)
*   @brief DMA Parity Error creation and check routines.
*/
void DMA_Parity(void)
{
	unsigned int Source_address[10],Destination_address[10];
	unsigned int *ptr=(unsigned int *)(0xFFF80A00U); 

	/** - Reset DMA */
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_RESET=1;
	
    /** - Enable DMA */
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_EN=1;

    /** - Immediately stop at an DMA arbitration boundary and continue after 
	 *    suspend */
	dmaREG->GCTRL_UN.GCTRL_ST.DEBUG_MODE =0x3;

    /** - Enable DMA Parity feature*/	
	dmaREG->DMAPCR_UN.DMAPCR_ST.PARITY_ENA = 0xA;

	/** - Configure the DMA Control Packet 
	*   	-Configure Source Address 
	*   	-Configure Destination Address 
	*   	-Configured as 1 Frame with 5 Elements 
	*   	-Read = Write access = 64 bit 
	*   	-Configure Block Transfer
	*   	-Address Increment on Read and Write access.
	*   	-AutoInitialization OFF
	*   	-Data Chaining and Offset control not configured.
	*/
  	dmaMEM->PCP_ST[0].ISADDR_UL = (unsigned int)&Source_address[0];
  	dmaMEM->PCP_ST[0].IDADDR_UL = (unsigned int)&Destination_address[0];
  	dmaMEM->PCP_ST[0].ITCOUNT_UN.ITCOUNT_ST.IFTCOUNT = 1;
  	dmaMEM->PCP_ST[0].ITCOUNT_UN.ITCOUNT_ST.IETCOUNT = 5;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.RES = ACCESS_64_BIT;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.WES = ACCESS_64_BIT;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.TTYPE = BLOCK_TRANSFER;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.ADDMR = ADDR_INC1;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.ADDMW = ADDR_INC1;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.AIM = AUTOINIT_OFF;
  	dmaMEM->PCP_ST[0].CHCTRL_UN.CHCTRL_ST.CHAIN = 0;
  	dmaMEM->PCP_ST[0].EIOFF_UN.EIOFF_ST.EIDXD = 0;
  	dmaMEM->PCP_ST[0].EIOFF_UN.EIOFF_ST.EIDXS = 0;
  	dmaMEM->PCP_ST[0].FIOFF_UN.FIOFF_ST.FIDXD = 0;
  	dmaMEM->PCP_ST[0].FIOFF_UN.FIOFF_ST.FIDXS = 0;

    /** - Port B is assigned for the Data Transfer */
	dmaREG->PAR_UL[0] = 0x00040000;

    /** - Disable DMA Parity feature*/	
	dmaREG->DMAPCR_UN.DMAPCR_ST.PARITY_ENA = 0x5;

	/** - On Parity error disable the DMA controller immediately */
	dmaREG->DMAPCR_UN.DMAPCR_ST.ERRA = 1;

	/** - Memory Map Parity bits to access directly*/
	dmaREG->DMAPCR_UN.DMAPCR_ST.TEST=1;

	/** - Corrupt the Parity Location to generate Parity error */
	*ptr =(*ptr-1);

	/** - Disable Parity bits Memory Map */
	dmaREG->DMAPCR_UN.DMAPCR_ST.TEST=0;

    /** - Enable DMA Parity feature*/	
	dmaREG->DMAPCR_UN.DMAPCR_ST.PARITY_ENA = 0xA;

    /** - Start/ software trigger DMA transfer, Enable Channel 1 */
	dmaREG->SWCHENAS_UL = 1;

    /** - Wait for Parity Error Detection Flag to get Set. */
    while(dmaREG->DMAPAR_UN.DMAPAR_ST.EDFLG == 0x00);

    /** - Disable DMA Parity feature*/	
	dmaREG->DMAPCR_UN.DMAPCR_ST.PARITY_ENA = 0x5;

	/** - Reset DMA */
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_RESET=1;
	dmaREG->GCTRL_UN.GCTRL_ST.DMA_RESET=0;
}

