/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupts external definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Apr 12 14:52:50 2011
* %version:          1 %
* %derived_by:       nz63rn %
* %date_modified:    Thu Jun  6 12:28:09 2013 % 
*---------------------------------------------------------------------------*/
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

extern FUNC(void, EXCEPTION_HANDLER_CODE) Isr_ESMH(void);
extern FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);

FUNC(void, INTERRUPT_CODE) EnableCanInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableEeSpiInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableTcSpiInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void);
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void);

extern FUNC(void, INTERRUPT_CODE) EnableVFPInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) DisableVFPInterrupt(void);
#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
04/13/11   1        JJW      Initial Creation
05/31/11   2        LWW      Added FIQ enable function
08/16/11   3        YY       Added Turns Counter SPI interrupt enable function
09/21/11   3.1.1    LWW      Removed BMW specific interrupts, added CAN interrupts
01/10/12   3.1.2    LWW      Added externs
03/12/12   3.1.3    JJW      Added EnableTcSpiInterrupt() extern
02/12/13   3.1.4    OT       Added interrupt externs for uDiag integration
******************************************************************************/
