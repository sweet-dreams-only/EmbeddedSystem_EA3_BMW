/**********************************************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupts external definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
**********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Apr 12 14:52:50 2011
* %version:          9 %
* %derived_by:       cz7lt6 %
* %date_modified:    Thu Nov  8 10:53:17 2012 % 
*----------------------------------------------------------------------------------------------------------------------
 *   Date      Rev     Author    Change Description                                                            SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11   1        JJW      Initial Creation
 * 05/31/11   2        LWW      Added FIQ enable function
 * 08/16/11   3        YY       Added Turns Counter SPI interrupt enable function
 * 09/19/11   4        JJW      Added SysTick interrupt enable function
 * 10/14/11   5        LWW      Added extern of Isr_ESMH
 * 11/01/12   7		   KJS		Added disable system tick routine
 * 11/08/12	  8		   KJS		Merged i350/i390 paths, cleaned up rev log. 
 * 11/05/14	 15			KJS		Added ClearSysTickInterruptFlg
 */
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

extern FUNC(void, EXCEPTION_HANDLER_CODE) Isr_ESMH(void);
extern FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);

extern FUNC(void, INTERRUPT_CODE) EnableFrInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableCrossChkInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableEeSpiInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableTcSpiInterrupt(void);

extern FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) DisableCrossChkInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void);

extern FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void);

extern FUNC(void, INTERRUPT_CODE) ClearSysTickInterruptFlg(void);
#endif


