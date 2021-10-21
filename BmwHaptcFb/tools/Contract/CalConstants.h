/*****************************************************************************
* Copyright 2015 Nxtr Automotive, All Rights Reserved.
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
* %version:          2 %
* %derived_by:       gzkys7 %
* %date_modified:    Fri Mar 27 10:43:00 2015 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"
#include "fixmath.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/28/2016 5:06:14 PM *******************/
/**************************** BmwHaptcFb  - Rev 5 ****************************/



extern CONST(uint16, CAL_CONST) t2_BmwHF_Amp_MtrNm_u2p14[10][13];
extern CONST(uint16, CAL_CONST) t2_BmwHF_Frq_Hz_u16[10][13];
extern CONST(uint16, CAL_CONST) t_BmwHF_Inten_Uls_u16[13];
extern CONST(uint16, CAL_CONST) t_BmwHF_PatActvTi_mS_u16[11];
extern CONST(uint16, CAL_CONST) t_BmwHF_PatPasTi_mS_u16[11];
extern CONST(uint16, CAL_CONST) t_BmwHF_PatRisngSlew_MtrNmpS_u11p5[11];
extern CONST(uint16, CAL_CONST) t_BmwHF_Pat_Cnt_u16[11];
extern CONST(uint16, CAL_CONST) t_BmwHF_VehSpd_Kph_u11p5[10];
extern CONST(float32, CAL_CONST) k_BmwHF_SysDegradedDivFilFrq_Hz_f32;
extern CONST(float32, CAL_CONST) k_BmwHF_EPSDegradedFltThd_Uls_f32;
#endif


