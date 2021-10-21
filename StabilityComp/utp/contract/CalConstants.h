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
 * %derived_by:       lz4p8n %
 * %date_modified:    Sat Apr 13 15:12:47 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 4/13/2013 2:03:18 PM *******************/
/************************** StabilityComp - Rev 13 ***************************/



extern CONST(uint16, CAL_CONST) t_StCmpADDFBlendX_Uls_u2p14[2];
extern CONST(uint16, CAL_CONST) t_StCmpADDFBlendY_Uls_u2p14[2];
extern CONST(uint16, CAL_CONST) t_StCmpBlendSpdBS_Kph_u9p7[6];
extern CONST(uint16, CAL_CONST) t_StCmpBlend12Trq_HwNm_u8p8[5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend12TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend02TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t_StCmpBlend34Trq_HwNm_u8p8[5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend34TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend04TblY_Uls_u2p14[6][5];
extern CONST(NotchFiltK_Str, CAL_CONST) t_StCmpNFK_Str[4];
extern CONST(float32, CAL_CONST) k_StCmpHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_StCmpSysCorrThresh_MtrNm_f32;
extern CONST(boolean, CAL_CONST) k_StCmpCrosChkEnbl_Uls_lgc;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpNstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPNThresh_Cnt_u16;
#endif


