/**********************************************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Interrupts.c
* Module Description: Interrupt Enable/Disable Interface
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
**********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          15 %
* %derived_by:       cz7lt6 %
* %date_modified:    Thu Nov  8 10:53:13 2012 % 
*----------------------------------------------------------------------------------------------------------------------
 *   Date      Rev     Author    Change Description                                                            SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/11/10   1        	JJW     Initial file creation
 * 12/19/10   2        	LWW     Changes for EEPROM SPI port change
 * 04/13/11   4        	JJW     Added CrossChk ISR enable/disable
 * 04/15/11   5        	JJW     Added enable FIQ to motor control enable. Replaced register address pointer
 * 								constant access with vim.h structure definitions
 * 04/25/11   6        	JJW     Removed enable FIQ from motor control enable.
 * 05/31/11   7        	LWW     Added FIQ enable function
 * 08/16/11   8        	YY      Added Turns Counter SPI interrupt enable function
 * 09/19/11   9        	JJW     Replaced constants for ISR priority/VIM bit with reference to Os generated
 * 								config table to alleviate the need to manually keep these in sync.
 * 09/23/11  10        	JJW     Modified VIM access to use the Os Privileged Register access API so that
 * 								the enable/disable interrupts can be used by the user mode application.
 * 08/06/12  12			KJS		Added functions for microdiagnostics.
 * 08/15/12   8.1.2.1.3 JJW     osWritePeripheral32 access API's to allow use user applications.
 * 09/23/12   8.1.2.1.4 JJW     Changes for Os 5.04 integration to allow determination of ISR priority.
 * 								Isr priority structure used in Os is no longer visible external to Os
 * 11/08/12	 14			KJS		Added Disable/Enable system tick interrupts.
 * 11/05/14	 15			KJS		Added ClearSysTickInterruptFlg
 */

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "CDD_Const.h"
#include "vim.h"
#include "Os.h"
#include "rti_regs.h"

/* TODO: Generate the ISR priority defines based on the Os Config in the ECUC file.
 *			The priorities must be manually entered in the following set of defines
 *			to match the configuration in the Os.
 */
#define RTI_COMP0_INT       4u
#define FR_LEVEL0_INT       3u
#define FR_LEVEL1_INT       5u
#define ISR_MTRCTRL_INT     (D_MTRISRVIMIDX_CNT_u16)
#define MIBSPI1_LEVEL0_INT  26u
#define MIBSPI1_LEVEL1_INT  12u
#define MIBSPI3_LEVEL0_INT  37u
#define MIBSPI3_LEVEL1_INT  38u
#define ESML_INT    		20u
#define CRC_INT    			19u

/*****************************************************************************
* Local Functions
*****************************************************************************/
void EnableIrq(uint8);
void DisableIrq(uint8);

FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void)
{
	_enable_FIQ();
}
/*****************************************************************************
* Global Interrupt Enable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) EnableFrInterrupt(void)
{
  EnableIrq(FR_LEVEL0_INT);
  EnableIrq(FR_LEVEL1_INT);
}

FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void)
{
  EnableIrq(ISR_MTRCTRL_INT);
}


FUNC(void, INTERRUPT_CODE) EnableEeSpiInterrupt(void)
{
  EnableIrq(MIBSPI1_LEVEL0_INT);
  EnableIrq(MIBSPI1_LEVEL1_INT);
}


FUNC(void, INTERRUPT_CODE) EnableTcSpiInterrupt(void)
{  
  EnableIrq(MIBSPI3_LEVEL0_INT);  
  EnableIrq(MIBSPI3_LEVEL1_INT);
}

FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void)
{  
  EnableIrq(RTI_COMP0_INT);  
}

FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void)
{
EnableIrq(ESML_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void)
{
EnableIrq(CRC_INT);
}

/*****************************************************************************
* Global Interrupt Disable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void)
{
  DisableIrq(ISR_MTRCTRL_INT);
}

FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void)
{
	DisableIrq(RTI_COMP0_INT);
}
/*****************************************************************************
* Local Functions
*****************************************************************************/

/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) EnableIrq(uint8 irqRequest)
{
  if (irqRequest < 32) {  	
	  osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET0), ( ((osuint32)1) << (irqRequest)));
  } else {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET1), ( ((osuint32)1) << (irqRequest)));
  }
}

/*****************************************************************************
  * Name:        DisableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) DisableIrq(uint8 irqRequest)
{
  if (irqRequest < 32) {
	  osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR0), ( ((osuint32)1) << (irqRequest)));
  } else {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR1), ( ((osuint32)1) << (irqRequest)));
  }
}


/*****************************************************************************
  * Name:        ClearSysTickInterruptFlg
  * Description:
  * Inputs:      None
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) ClearSysTickInterruptFlg(void)
{
	osWritePeripheral32(OS_MEM_AREA_RTI, (osuint32)&(rtiREG1->INTFLAG), 0xFFFFFFFFU);
	osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->INTREQ0), 0x00000010U);
}
