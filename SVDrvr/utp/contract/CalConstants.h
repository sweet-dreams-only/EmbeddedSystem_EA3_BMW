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
* %derived_by:       nzt9hv %
* %date_modified:    Fri Oct 12 10:58:23 2012 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H


#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 10/12/2012 1:20:38 PM ******************/
/****************************** PwmCdd - Rev 2 *******************************/


extern CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16;
extern CONST(sint16, CAL_CONST) k_ADCTrig2Offset_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16;

/**************************** GM_K2XX_EPS_TMS570 *****************************/
extern CONST(float32, CAL_CONST) k_MinDiodeCondCurr_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_DTCompTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_DTCompTblY_Uls_u8p8[2];
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];
#endif
