/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : AppStartupCallout.c
* Module Description: Application Startup Sequence Callout Functions
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri May 11 12:17:00 2012
 * %version:          1 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Mon Aug  6 15:26:05 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/14/12  1        LWW       Initial Version
 * 08/31/16  2        RMV       In AppStartupCallout1 function DMA parity is disabled since the parity is enabled by 
                                bootloader
 */
#include "Std_Types.h"

#include "sys_memory.h"
#include "Lnk_Symbols.h"
/* To get the DMA parity reigster macro, to disable the parity of DMA */
#include "dma_regs.h"

void AppStartupCallout1(void)
{
	/* Enable CPU ECC checking for ATCM (flash accesses) */
	asm("	mrc   p15, #0x00, r0,         c1, c0,  #0x01");
	asm("	orr   r0,  r0,    #0x1<<25");
	asm("	dmb");
	asm("	mcr   p15, #0x00, r0,         c1, c0,  #0x01");
	asm("	isb");
  
  /* Disable the parity of the DMA since in the Bootmanager - memInitialization function the DMA parity is enabled before 
     initializing the hardware memory, but since BMW program parity is used only for the Flash test there is no safety 
     requirement to enable the parity of the DMA. But if DMA is used for other than only flash test DMA parity should be 
     enabled */
     DMACTRLREG->DMAPCR = 0x00000005ul;	/* disable parity */
}

void AppStartupCallout2(void)
{
	uint32* Address;

	/* Initialize BSS section to 0 */
	for (Address = (uint32*)&Lnk_BSS_Start; Address <= (uint32*)&Lnk_BSS_End; Address++)
	{
		*Address = 0U;
	}
}
