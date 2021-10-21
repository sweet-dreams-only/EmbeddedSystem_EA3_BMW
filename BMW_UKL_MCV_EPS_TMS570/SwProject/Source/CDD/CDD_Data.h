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
* %version:          EA3#38 %
* %derived_by:       pzswj8 %
* %date_modified:    Sat Jan 18 14:19:32 2014 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Rte_Type.h"



typedef enum {
	TcPrgInit	= 				0,
	TcPrgInPrcs =				1,
	TcPrgCmpl	=	 			2
} TcFlshPrgStatus_T;

#define D_TcPNArraySize_Cnt_U16 	20U


/* Data Native to MtrCtrl Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
/* Data Native to Application Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETFAULTTYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultType_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETPHASETYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultPhase_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(TcFlshPrgStatus_T, CDD_VAR_NOINIT) CDD_TcPrgStatus_Cnt_G_enum;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashVerify_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashActive_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TCprocessing_Cnt_G_lgc;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashStatus_Cnt_G_u08;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePNVldCnt_Cnt_G_u32;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePN_Cnt_G_u32;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashErrors_Cnt_G_u08;

/* Data Consistancy Buffer Access Variables */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;

/* EOL Global Data */
extern VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_CustEOLSrlComSvcDft_Cnt_G_b32;
extern VAR(uint16, CDD_VAR_NOINIT) CM_DiagNegRespCode_u16;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_OscEnableFlag_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_GenPosTrajEnableFlag_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_LocktoLockEnableFlag_Cnt_G_lgc;

/* SrlComOutput Global Data */
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TxSUEPS_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TxSUEPSSendMsg_Cnt_G_lgc;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_InitialTime_mS_G_u32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_InitialTimeLockout_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TxSTEPSSendMSg_Cnt_G_lgc;

/* HwOffsetSnsrCal - Customer required that data stored be available via read diagnostic service over multiple ignition cycles */
extern VAR(float32, NVM_APPL_DATA) Rte_AbsHwPos_EOLHwOffsetSnsrCal;

extern volatile VAR(uint8, CDD_VAR_NOINIT) CDD_Adc_ConvFlag_Uls_u08;

/* NXTR SWT */
extern VAR(boolean, CDD_VAR_NOINIT) CDD_SWTEnableFlag_Cnt_G_lgc;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_CdcAuthLevel_Cnt_G_u8;

/* NTC Number for DBG Frame */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_FirstActvNTC_Cnt_G_u16;

/* DEM EventId for Snapshot Data (DID$5030) */
extern VAR(Dem_EventIdType, CDD_VAR_NOINIT) CDD_DemIdSnapshot_Cnt_G_u8;

/* SVDrvr and NHET variables */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DCPhsComp_Cnt_G_u16[3];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PWMPeriod_Cnt_G_u16;

/* NVM Fast Write */
extern VAR(boolean, CDD_VAR_NOINIT) CDD_NvMFastWriteEnable_Cnt_G_lgc;

/* Flexray Cycle info - Odd or Even */
extern VAR(uint8, CDD_VAR_NOINIT) FrCycleSwitchOddEven_Cnt_G_u08; 

/* Controlling the DISP_CC_EPS message */
extern VAR(uint8, CDD_VAR_NOINIT) CDD_DispCC_Per_Cnt_G_u08; 

extern VAR(boolean, CDD_VAR_NOINIT) CDD_TxDispSendMsg_Cnt_G_lgc;

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
03/28/12   16.0     JJW      Removed Metrics Global signals for new Metrics module integration
08/18/12   18.0     BDO      Updates for Learn Rack Center FDD 39 and anomaly 3188
08/18/12   19.0     BDO      Add enable flag for SweepingTechnologies
08/29/12   20.0     BDO      Correct defn of Rte_AbsHwPos_EOLHwOffsetSnsrCal - anomaly 3691
09/13/12   21.0     KJS      Added CDD_FirstActvNTC_Cnt_G_u16
09/30/12   22.0     KJS      Added CDD_CdcAuthLevel_Cnt_G_u8
11/21/11   25       JJW      Added CDD_CDDMtrPosAccessBfr_Cnt_G_u16 to decouple the MtrPos buffer from the 
 								Phase Reasonableness data in order to provide freedom for synchronizing 
                               the data buffers appropriately.
12/06/12   27     	JJW      PwmCdd FDD34B_001.3 integration.  Removal of unused Analog phase reasonableness signals		
02/07/13   29	 	DD			Change request 7247 Add CDD_DemIdSnapshot_Cnt_G_u8 variable					   
03/14/13   31	 	DD		 Added variables for turns counter and flash programmer communication.
04/01/15   33		KJS		 Added variable CDD_NvMFastWriteEnable_Cnt_G_lgc
06/29/16   37		ABS		 Added variables CDD_TxSUEPSSendMsg_Cnt_G_lgc, CDD_StConVehMissing_Cnt_G_lgc and CDD_StConVehInvalid_Cnt_G_lgc
07/17/16   38		ABS		 Removed variables CDD_StConVehMissing_Cnt_G_lgc and CDD_StConVehInvalid_Cnt_G_lgc
07/29/16   39 	RMV			     Added CDD_TxSTEPSSendMSg_Cnt_G_lgc variable - (Anomaly - EA3#9635)
08/01/16   40   RMV     Added FrCycleSwitchOddEven_Cnt_G_u08 variable - (Anomaly - EA3#9011)
******************************************************************************/
