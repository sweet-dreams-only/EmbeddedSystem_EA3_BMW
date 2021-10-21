/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : MtrCtrl_Irq.c
* Module Description: Motor Control Interrupt Request Service
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          16 %
* %derived_by:       zz4r1x %
* %date_modified:    Fri Mar 22 11:33:43 2013 % 
*---------------------------------------------------------------------------*/


/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "MtrCtrl_Irq.h"
#include "Os.h"
#include "Adc2.h"
#include "vim.h"
#include "CDD_Const.h"
#include "PwmCdd.h"
#include "CDD_Func.h"
#include "Mpu.h"
#include "IoHwAbstractionUsr.h"
#include "Nhet.h"

#include "Adc.h"
#include "CDD_Data.h"
#define D_ADC_FWDPATH_FLAGCLR_U08	0xFE
#define D_ADC_FDBKPATH_FLAGCLR_U08	0xEF




/* TODO: Determine if this INTERRUPT pragma is required when using the  */
/*        interrupt keyword.                                            */
#pragma INTERRUPT(Isr_MtrCtrl, IRQ);

/*****************************************************************************
* Local Functions
*****************************************************************************/
FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void);


/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
MTRCTRL_COMPILER_ISR void Isr_MtrCtrl(void){


	
	if( CDD_Adc_ConvFlag_Uls_u08 == 0x01 )
	{
		Adc_StartGroupConversion ( AdcFwdPath );
		CDD_Adc_ConvFlag_Uls_u08 &= D_ADC_FWDPATH_FLAGCLR_U08;	/* Clear Flag */
	}
	else if( CDD_Adc_ConvFlag_Uls_u08 == 0x10) 
	{
   		Adc_StartGroupConversion ( AdcFdbkPath );
		CDD_Adc_ConvFlag_Uls_u08 &= D_ADC_FDBKPATH_FLAGCLR_U08; /* Clear Flag */
	}
		

	Mpu_Disable();
	MtrCtrlTaskList();
	
	/* ADC2 Event (Group 0) EOC Interrupt Flag Clear */
	adcREG2->GxINTFLG[adcGROUP0] = (1 << 3U);

	Mpu_Enable();


	}

FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void)
{
	MtrPos_Per1();
	MtrVel3_Per1();
	PwmCdd_Per1();
	Nhet_Per1();
	MicroDiag_Per1();
	IoHwAb_Per1();
}


/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0      JJW      Initial Creation
12/19/10   2.0      JJW      Added motor contorl functions
03/14/10   4.0      LWW      Removed ISR context switching patch
03/15/11   5.0      JJW      Added Metrics Hooks
04/15/11   6        JJW      Changed to FIQ definion
04/25/11   7        JJW      Changed to IRQ definion
09/17/11   8        JJW      Added Mpu handling for SafeContext Os Integration
09/18/11   9        JJW      Removed unecessary VIM write, the reg was read only
10/28/11   10		KJS		 Added software patch for ADC1 glitches. #4601 
11/02/11   11		JJW		 Removed unecessary metrics ifdef statements
08/06/12   12	    KJS		 Added MicoDiag_Per1 call.
01/01/13   13       Selva	 Added ADC Torque Macro
02/18/13   14       KJS		 Added Nhet Per1 for FDD15C integration.
******************************************************************************/
