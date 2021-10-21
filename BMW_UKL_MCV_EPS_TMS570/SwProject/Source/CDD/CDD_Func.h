/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Func.h
* Module Description: Header file for functions communicated between Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:31:36 2010
* %version:          4 %
* %derived_by:       cz7lt6 %
* %date_modified:    Thu Mar  7 14:59:53 2013 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_FUNC_H
#define CDD_FUNC_H

#include "Std_Types.h"

extern FUNC(void, SA_MTRPOS_CODE) MtrPos_Per1(void);

/* TODO: Determine if the  CalRamInit really needs to execute as a CDD early in init */
/*        if it is determined that RAM cals are only used after RTE Start, then this */
/*        function can be removed from here and scheduled in Developer               */
extern FUNC(void, XCP_CODE) Xcp_CalRamInit(void);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Init1(void);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Init2(void);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Per1(void);

extern FUNC(void, AP_SRLCOMOUTPUT2_CODE) SrlComOutput_MainFunction(void);
#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0      LWW      Initial Creation
12/22/10   2.0      JJW      Added Xcp_CalRamInit
10/11/11   3.0      BDO      Add turns counter flash functions
03/07/13   4.0		KJS		 Added SrlComOuput_MainFunction for build warnings.
******************************************************************************/
