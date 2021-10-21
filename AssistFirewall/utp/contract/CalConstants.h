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
 * %version:          9 %
 * %derived_by:       lz4p8n %
 * %date_modified:    Tue May 14 14:33:47 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/14/2013 2:21:35 PM *******************/
/************************* Assist Firewall - Rev 15 **************************/



extern CONST(float32, CAL_CONST) k_AsstFWInpLimitHysComp_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitHFA_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitBaseAsst_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_AsstFWFiltKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AsstFWFWActiveLPF_Hz_f32;
extern CONST(uint16, CAL_CONST) t_AsstFWVehSpd_Kph_u9p7[8];
extern CONST(sint16, CAL_CONST) t2_AsstFWUprBoundX_HwNm_s4p11[8][11];
extern CONST(sint16, CAL_CONST) t2_AsstFWUprBoundY_MtrNm_s4p11[8][11];
extern CONST(uint16, CAL_CONST) k_AsstFWPstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AsstFWNstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_AsstFWPstepNstepThresh_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_AsstFWDefltAssistX_HwNm_u8p8[20];
extern CONST(sint16, CAL_CONST) t_AsstFWDefltAssistY_MtrNm_s4p11[20];
extern CONST(float32, CAL_CONST) k_RestoreThresh_MtrNm_f32;
#endif


