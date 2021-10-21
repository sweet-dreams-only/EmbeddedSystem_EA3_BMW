/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Kevin Smith
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          4 %
 * %derived_by:       nz63rn %
 * %date_modified:    Tue Sep 17 17:05:26 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"


/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 9/17/2013 10:45:37 AM ******************/
/***************************** CtrlTemp - Rev 14 *****************************/


extern CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32;
extern CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32;
extern CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc;
#endif
