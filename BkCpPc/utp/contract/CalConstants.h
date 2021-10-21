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
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Thu Feb 28 10:17:28 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2/28/2013 1:21:48 PM *******************/
/********************* Bulk Capacitor Precharge - Rev 4 **********************/


extern CONST(float32, CAL_CONST) k_MtrMotionThresh_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32;
extern CONST(float32, CAL_CONST) k_PwrDiscOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_PMOSDIAGOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_OVERRIDESIGDIAGOpenThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscOpenThresh_mS_u16;
extern CONST(uint16, CAL_CONST) k_WaitForSqrWaveThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_PwrDiscCloseThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PrechargeThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_PMOSVError_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PMOSTError_mS_u16;
extern CONST(float32, CAL_CONST) k_MaxDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_MinDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_VswitchDeltaThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscCloseThresh_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChargePumpDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshNonExt_Volt_f32;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshExNorm_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNonOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaExtOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNormlOp_Volt_f32;
#endif
