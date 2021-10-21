/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Feb 10 14:30:00 2012
 * %version:          1 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Tue Oct  9 14:09:01 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/***************** File Generated on 2012-10-12 11:17:38 AM ******************/
/**************************** PhaseDscnt - Rev 2 *****************************/


extern CONST(uint16, CAL_CONST) k_PhDiscStartTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PhDiscOpenTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PDTestMinScans_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PDTestMaxScans_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PDTestFailCurr_Amp_f32;
extern CONST(uint16, CAL_CONST) k_PDTestMinFail_mS_u16;
extern CONST(float32, CAL_CONST) k_PDTestFltrCurrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_PDTestModIdx_Uls_f32;
extern CONST(float32, CAL_CONST) k_ChrgPmpHiDetect_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpHi_Cnt_str;
extern CONST(float32, CAL_CONST) k_ChrgPmpLowDetect_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpLow_Cnt_str;
extern CONST(float32, CAL_CONST) k_PDSuplHighDetect_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PDSuplHigh_Cnt_str;
extern CONST(uint16, CAL_CONST) k_PDSuplHiInit_mS_u16;
extern CONST(uint8, CAL_CONST) k_PDSuplHiCntsToFlt_Cnt_u08;
extern CONST(float32, CAL_CONST) k_IMeasNullDetectMtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_IMeasNotNull_Amp_f32;
extern CONST(float32, CAL_CONST) k_IMeasLPFfc_Hz_f32;
extern CONST(uint16, CAL_CONST) k_IMeasTestDur_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_IMeasNull_Cnt_str;
extern CONST(uint8, CAL_CONST) k_IMeasNullCntsToFlt_Cnt_u08;
#endif
