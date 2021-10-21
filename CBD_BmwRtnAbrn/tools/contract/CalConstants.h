/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Jan  17 16:48:22 2014
* %version:          5 %
* %derived_by:       nz4qtt %
* %date_modified:    Mon Jan 27 18:16:49 2014 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 6/7/2016 4:28:56 PM *******************/
/*************************** BmwRtnArbn - Rev 5.0 ****************************/



extern CONST(boolean, CAL_CONST) k_BmwRA_DampgEnable_Cnt_Lgc;
extern CONST(boolean, CAL_CONST) k_BmwRA_DampgScaEnable_Cnt_Lgc;
extern CONST(float32, CAL_CONST) k_BmwRA_DesVelLPFKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_BmwRA_DrvTrqEnable_Cnt_Lgc;
extern CONST(float32, CAL_CONST) k_BmwRA_HwAuthySlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_HwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_Kb_Uls_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_OffsRng_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_OffsSlew_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_Polarity_Uls_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_ScaLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_SelHwTrqScaSlewDec_UlspS_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_SelHwTrqScaSlewInc_UlspS_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32;
extern CONST(float32, CAL_CONST) k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32;
extern CONST(boolean, CAL_CONST) k_BmwRA_TrqGrdtScaEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_BmwRA_VelErrScaEnable_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t2_BmwRA_DampgTblX_HwDegpS_u10p6[8][9];
extern CONST(uint16, CAL_CONST) t2_BmwRA_DampgTblY_HwNm_u6p10[8][9];
extern CONST(uint16, CAL_CONST) t2_BmwRA_DesVelScaX_HwNm_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_DesVelScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_DesVelX_HwDeg_u12p4[8][12];
extern CONST(uint16, CAL_CONST) t2_BmwRA_DesVelY_HwDegpS_u10p6[8][12];
extern CONST(float32, CAL_CONST) t2_BmwRA_DrvTrqMtrxA_Uls_f32[5][5];
extern CONST(float32, CAL_CONST) t2_BmwRA_DrvTrqMtrxB_Uls_f32[5][4];
extern CONST(uint16, CAL_CONST) t2_BmwRA_HwTrqSca1X_HwNm_u8p8[5][10];
extern CONST(uint16, CAL_CONST) t2_BmwRA_HwTrqSca1Y_Uls_u2p14[5][10];
extern CONST(uint16, CAL_CONST) t2_BmwRA_HwTrqSca2X_HwNm_u8p8[5][10];
extern CONST(uint16, CAL_CONST) t2_BmwRA_HwTrqSca2Y_Uls_u2p14[5][10];
extern CONST(uint16, CAL_CONST) t2_BmwRA_IntgtrLimTblY_HwDeg_u10p6[5][9];
extern CONST(uint16, CAL_CONST) t2_BmwRA_TBarTrqScaX_HwNm_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_TBarTrqScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_TrqGrdtScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_BmwRA_VelErrorScaY_Uls_u2p14[7][8];
extern CONST(float32, CAL_CONST) t_BmwRA_DrvTrqMtrxC_Uls_f32[5];
extern CONST(float32, CAL_CONST) t_BmwRA_DrvTrqMtrxD_Uls_f32[4];
extern CONST(uint16, CAL_CONST) t_BmwRA_HwAuthyScaX_Uls_u2p14[4];
extern CONST(uint16, CAL_CONST) t_BmwRA_HwAuthyScaY_Uls_u2p14[4];
extern CONST(uint16, CAL_CONST) t_BmwRA_Ki_Uls_u8p8[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_Kp_Uls_u4p12[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_OutpLimTblY_MtrNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_PosScaX_HwDeg_u12p4[9];
extern CONST(uint16, CAL_CONST) t_BmwRA_PosScaY_Uls_u2p14[9];
extern CONST(uint16, CAL_CONST) t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_BmwRA_VehSpdTbl_Kph_u9p7[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_VelErrVehSpdScaY_Uls_u2p14[5];
extern CONST(sint16, CAL_CONST) t_BmwRA_VelErrorScaX_HwDegpS_s10p5[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_VelErrorScaZ_HwDeg_u12p4[7];
extern CONST(float32, CAL_CONST) k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;
extern CONST(uint16, CAL_CONST) t_BmwRA_BlendFactorTbl1_Uls_u2p14[8];
extern CONST(uint16, CAL_CONST) t_BmwRA_BlendFactorTbl2_Uls_u2p14[8];
#endif


