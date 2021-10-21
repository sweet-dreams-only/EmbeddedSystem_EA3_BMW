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
 * %version:          5 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Thu Mar  7 16:19:16 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 3/7/2013 4:03:58 PM *******************/
/*************************** PwrLmtFunc - Rev 5.0 ****************************/


extern CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32;
extern CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTh_Volts_u8p8;
extern CONST(uint16, CAL_CONST) t_DLVTblX_Volts_u8p8[10];
extern CONST(sint16, CAL_CONST) t_DLVTblY_MtrRadpS_s11p4[10];
extern CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_SpdAdjSlewDec_MtrRadpSpL_u12p4;
extern CONST(uint16, CAL_CONST) k_SpdAdjSlewInc_MtrRadpSpL_u12p4;
extern CONST(float32, CAL_CONST) k_KeStdTemp_VpRadpS_f32;
extern CONST(uint16, CAL_CONST) t_MtrEnvTblX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_MtrEnvTblY_MtrNm_u5p11[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblY_MtrNm_u5p11[6];
extern CONST(uint16, CAL_CONST) t_APAMtrEnvTblX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_APAMtrEnvTblY_MtrNm_u5p11[6];
extern CONST(uint16, CAL_CONST) t_CustCurrentLmtTblX_Amps_u12p4[10];
extern CONST(uint16, CAL_CONST) t_CustCurrentLmtTblY_MtrRadpS_u12p4[10];
extern CONST(uint16, CAL_CONST) t_MSADLVTblX_Volts_u8p8[10];
extern CONST(sint16, CAL_CONST) t_MSADLVTblY_MtrRadpS_s11p4[10];
#endif
