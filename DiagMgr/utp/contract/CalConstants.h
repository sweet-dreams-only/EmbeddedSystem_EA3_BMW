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
* %version:          2 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Sep 18 15:56:14 2012 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"
#include "Ap_DiagMgr_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 9/18/2012 3:56:33 PM *******************/
/****************************** DiagMgr - Rev 8 ******************************/



extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];
#endif
