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
 * %version:          1 %
 * %derived_by:       czmgrw %
 * %date_modified:    Wed Mar 20 16:11:22 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/27/2016 11:53:24 AM ******************/
/*************************** TurnsCounter - Rev 20 ***************************/



extern CONST(float32, CAL_CONST) k_MinBemfActive_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_MtrPosToTcMechOffset_Deg_f32;
extern CONST(float32, CAL_CONST) t_TcToAcmpMin_Deg_f32[8];
extern CONST(float32, CAL_CONST) t_TcToAcmpMax_Deg_f32[8];
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSpiComDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSpiDataDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcMOSIErr_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TCvsMtrPosErr_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_RTBemfErr_Cnt_str;
extern CONST(uint8, CAL_CONST) k_TcActivePNvldChks_Cnt_u08;
extern CONST(uint16, CAL_CONST) k_TcResetTimeout_mS_u16;
extern CONST(uint8, CAL_CONST) k_TcEolOffsetDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSin2CosGainDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSinVsCosMinDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSinVsCosMaxDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolCalChksmDef_Cnt_u08;
extern CONST(float32, CAL_CONST) k_MaxBemfActive_MtrRadpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSCMnMxErr_Cnt_str;
extern CONST(uint16, CAL_CONST) t_TcPrgMemory_Cnt_u16[8192];
extern CONST(float32, CAL_CONST) k_MaxBemfDeActive_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) k_MinTotHighSampleCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinTotLowSampleCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinLowMtrVelLowCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinHighMtrVelHighCnt_Cnt_u16;
#endif


