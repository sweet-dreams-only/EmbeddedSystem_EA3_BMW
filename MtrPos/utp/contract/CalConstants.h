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
 * %version:          3 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Fri Oct 19 18:02:30 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2012-10-22 3:08:01 PM ******************/
/************************** Motor Position - Rev 3 ***************************/


extern CONST(float32, CAL_CONST) k_RTOffVelThr_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_RTFiltEnThresh_Uls_f32;
extern CONST(uint16, CAL_CONST) k_RTOffFiltKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_RTOffsetLmt_Volts_f32;
extern CONST(float32, CAL_CONST) k_AmpRecVarLmt_Uls_f32;
extern CONST(float32, CAL_CONST) k_RTToNomRatioVar_Uls_f32;
extern CONST(float32, CAL_CONST) k_CorrelationError_Rev_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosCorrDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_ValMinError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_ValMaxError_VoltsSqrd_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosValDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_NominalOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_SysCValMinError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_SysCValMaxError_VoltsSqrd_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_SysCMtrPosValDiag_Cnt_str;
#endif
