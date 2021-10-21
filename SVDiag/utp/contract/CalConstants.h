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
 * %derived_by:       nzt9hv %
 * %date_modified:    Wed Jun 26 16:31:37 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

typedef struct
{
  uint16 Threshold;
  uint16 PStep;
  uint16 NStep;
} DiagSettings_Str;
/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/26/2013 4:33:23 PM *******************/
/****************************** SVDiag - Rev 7 *******************************/


extern CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_GenGateDrvFltThrsh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_GateDrvInitDwellTime_mS_u16p0;
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32;
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32;
extern CONST(DiagSettings_Str, CAL_CONST) k_LowResPhsReas_Cnt_str;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMaxTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMinTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];
extern CONST(float32, CAL_CONST) k_LRPRCommOffsetMargin_Uls_f32;
#endif
