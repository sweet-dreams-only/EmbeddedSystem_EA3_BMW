/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: Header file for data communicated between Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          1.1.4 %
* %derived_by:       cz7lt6 %
* %date_modified:    Fri Jan 24 09:54:01 2014 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
//#include "CDD_Const.h"
#include "Rte_Type.h"
//#include "Metrics.h"

#define  D_OVRSMPLBUFFSIZE_CNT_U16     8U
#define  D_APPCDDBFRSIZE_CNT_U16       2U
typedef uint16 NvM_BlockIdType;

/* Data Native to MtrCtrl Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosMech_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosElec_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrRevCntr_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_SinTheta1_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CosTheta1_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Shcurr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasA_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasB_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(sint16, CDD_VAR_NOINIT) CDD_SinBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_CosBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PosBuffer_Rev_G_u0p16[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_TimeBuffer_uS_G_u16p0[D_OVRSMPLBUFFSIZE_CNT_U16];

/* Data Native to Application Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Sin1RTOffset_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Cos1RTOffset_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Sin1RTAmpRec_Uls_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Cos1RTAmpRec_Uls_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETFAULTTYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultType_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETPHASETYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultPhase_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];

/* Data Consistancy Buffer Access Variables */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_OvrSmplBfrWriteEn_Cnt_G_lgc;

/* EOL Global Data */
extern VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_OscEnableFlag_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_GenPosTrajEnableFlag_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_LocktoLockEnableFlag_Cnt_G_lgc;

extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashActive_Cnt_G_lgc;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_CustEOLSrlComSvcDft_Cnt_G_b32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashVerify_Cnt_G_lgc;

extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePNVldCnt_Cnt_G_u32;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePN_Cnt_G_u32;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashErrors_Cnt_G_u08;


extern FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
extern FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              	 	  SCR #
-------   -------  --------  -----------------------------------  		----------
12/07/10   1.0      JJW      Initial Creation
12/13/10   2.0      LWW      Added initial CDD interface data
12/16/10   3.0      OSteen   Add CDD_EOLSrlComSvcDft_Cnt_G_b32     		CR3639
                             and CM_DiagNegRespCode_u16
12/17/10   4.0      LWW      Changed DeadTimeComp to u8p8
12/19/10   5.0      JJW      Corrected _T_ typo on global vars
12/19/10   6.0      JJW      Added PwmCdd Vars
12/20/10   7.0      LWW      Added Shcurr signal, fixed datatypes
01/13/11   8.0      LWW      Removed Gate Drive Fault boolean
02/08/11   9.0      LWW      Added Phase Resonableness data
03/15/11   10.0     JJW      Initial metrics
04/03/11   11.0     BDO		 Added CDD_EPSInitRoutineStatus_Cnt_G_u16 	
10/11/11   12.0     BDO      Add CDD_TcPrgStatus and CDD_TcReflashActive
10/28/11   13.0		KJS		 Added CDD_Adc_ConvFlag_Uls_u08				#4601
11/23/11   14.0		BDO      Add CDD_DftAsstTbl_Cnt_lgc and CDD_DwnldAsstGain_Uls_f32
02/15/12   14.0     BDO      Add CDD_OscEnableFlag_Cnt_G_lgc, CDD_GenPosTrajEnableFlag_Cnt_G_lgc, CDD_LocktoLockEnableFlag_Cnt_G_lgc
******************************************************************************/
