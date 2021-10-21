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
 * %version:          4 %
 * %derived_by:       bz1q07 %
 * %date_modified:    Fri Feb 14 13:06:04 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 2/6/2013 1:22:50 PM *******************/
/*************************** MotorVelocity - Rev 5 ***************************/


extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];
extern CONST(Boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32;
extern CONST(float32, CAL_CONST) k_CorrMtrVelFiltKn_Hz_f32;

/********************************** MtrVel ***********************************/
extern CONST(uint16, CAL_CONST) t_MtrVelTimeOffsetTblX_Kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t_MtrVelTimeOffsetYTbl_uS_u16[3];
#endif
