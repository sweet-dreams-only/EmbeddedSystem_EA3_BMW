 /*****************************************************************************
* Copyright 2010 Nxtr, Inc., All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_DiagMgr_Types.h
* Module Description: This file contains diagmgr type definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Dec  2 07:36:54 2011
* %version:          2 %
* %derived_by:       czgng4 %
* %date_modified:    Tue Sep 18 15:41:12 2012 %
*---------------------------------------------------------------------------*/
#ifndef AP_DIAGMGR_TYPES_H
#define AP_DIAGMGR_TYPES_H

#include "Std_Types.h" 

/* Type Defines for DiagMgr Data Structures */
typedef struct
{
    uint32 Response : 24;
    uint32 DEMEventID : 8;
} FltRsp_Str;

typedef struct
{
  UInt8 NTC_Cnt_u08;
  UInt8 Param_Cnt_u08;
  UInt8 SystemState_Cnt_u08;
  UInt8 VehSpd_Kph_u8p0;
  UInt32 BlkBoxCfgData1;
  UInt32 BlkBoxCfgData2;
  UInt32 BlkBoxCfgData3;
  SInt16 HwTrq_HwNm_s4p11;
  SInt16 MtrTrq_MtrNm_s4p11;
  UInt16 IgnCtr_Cnt_u16;
} NTCBlkBoxType;

typedef NTCBlkBoxType NTCBlkBoxData[8];

typedef struct
{
  NTCNumber NTC;
  uint8 Status;
  uint8 AgingCounter;
} NTCStrg;

typedef NTCStrg NTCStrgArray[15];

#endif


/******************************************************************************
CHANGE HISTORY:

 Date      Rev      Author 			Change Description              SCR #
 				  					 (MDD Rev & Date) 		
-------   -------   --------  -----------------------------------  ----------
12/02/2011	1	    JJW       Initial Version
******************************************************************************/
