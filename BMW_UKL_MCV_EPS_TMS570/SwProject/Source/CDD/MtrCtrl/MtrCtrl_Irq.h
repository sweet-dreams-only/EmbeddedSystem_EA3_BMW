/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : MtrCtrl_Irq.h
* Module Description: Motor Control Interupt 
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          1 %
* %derived_by:       xz0btk %
* %date_modified:    Tue Dec 14 14:58:07 2010 % 
*---------------------------------------------------------------------------*/

#ifndef MTRCTRL_IRQ_H
#define MTRCTRL_IRQ_H

/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************************************************************/
#define MTRCTRL_COMPILER_ISR    interrupt

/*****************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************/
MTRCTRL_COMPILER_ISR void Isr_MtrCtrl(void);


#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0      JJW      Initial Creation
******************************************************************************/
