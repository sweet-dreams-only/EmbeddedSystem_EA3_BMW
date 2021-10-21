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
 * %version:          6 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Mon Mar 19 13:43:51 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 3/16/2012 12:34:50 PM ******************/
/*********** Trq Ovrly Interfaces and Park Assist Function - Rev 6 ***********/


extern CONST(uint16, CAL_CONST) k_HandsOnLPFCutoff_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PrkAstHwVelFltThrsh_HwRadpS_f32;
extern CONST(uint32, CAL_CONST) k_PrkAstHwVelFltTime_mS_u32;
extern CONST(float32, CAL_CONST) k_PrkAstHwDeltaMax_HwDeg_f32;
extern CONST(uint32, CAL_CONST) k_PrkAstHwDeltaMaxTime_mS_u32;
extern CONST(float32, CAL_CONST) k_PrkAstTrgtDeltaMin_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_PrkAstHandsOnTrq1_HwNm_u8p8;
extern CONST(uint16, CAL_CONST) k_PrkAstHandsOnTrq2_HwNm_u8p8;
extern CONST(float32, CAL_CONST) k_TcHwPosAuth_Uls_f32;
extern CONST(uint32, CAL_CONST) k_PrkAstHandsOn2Time_mS_u32;
#endif
