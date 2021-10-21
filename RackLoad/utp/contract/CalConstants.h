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
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          1 %
* %derived_by:       rz3h1n %
* %date_modified:    Mon Nov 21 15:04:28 2011 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H


/*********************** Start of Auto Generated Code ************************/

/***************** File Generated on 11/21/2011 11:01:46 AM ******************/
/********************* **COMPONENT NAME** - Rev **REV#** *********************/



/********************************* Rack Load *********************************/
extern CONST(float32, CAL_CONST) k_MotorEffQ1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MotorEffQ2_Uls_f32;
extern CONST(float32, CAL_CONST) k_MechEffQ1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MechEffQ2_Uls_f32;
extern CONST(uint16, CAL_CONST) k_MtrAccelLPF_Cnt_u16;
extern CONST(float32, CAL_CONST) k_TrnsFcnFs_Hz_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnTn_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaD_RadpS_f32;
extern CONST(uint16, CAL_CONST) k_LumpSysInertia_Kgm2_u6p10;
extern CONST(float32, CAL_CONST) k_RackDamp_NmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_RackFriction_HwNm_f32;
extern CONST(sint8, CAL_CONST) k_TrqPolGain_Uls_s8;
extern CONST(float32, CAL_CONST) k_MtrNmtoHwNm_Uls_f32;
extern CONST(uint16, CAL_CONST) k_RackLoadLPF_Cnt_u16;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaN_RadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaD2_RadpS_f32;
extern CONST(uint16, CAL_CONST) t_CfactorTblY_MmpRev_u10p6[18];
extern CONST(uint16, CAL_CONST) t_CfactorTblX_HwDeg_u10p6[18];
extern CONST(float32, CAL_CONST) k_MtrVelDband_MtrRadpS_f32;
#endif
