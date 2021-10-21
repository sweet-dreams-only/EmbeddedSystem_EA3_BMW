/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Data.c
* Module Description: Definition file for data communicated between Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          EA3#33 %
* %date_modified:    Sat Jan 18 14:19:32 2014 % 
*---------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 12/07/10   1.0    JJW     	Initial Creation
* 12/13/10   2.0    LWW      	Added initial CDD interface data
* 12/16/10   3.0    OSteen   	Add CDD_EOLSrlComSvcDft_Cnt_G_b32 and CM_DiagNegRespCode_u16					CR3639
* 12/17/10   4.0    LWW      	Changed DeadTimeComp to u8p8
* 12/19/10   5.0    JJW      	Corrected _T_ typo on global vars
* 12/19/10   6.0    JJW      	Added PwmCdd Vars
* 12/20/10   7.0    LWW      	Added Shcurr signal, fixed datatypes
* 01/13/11   8.0    LWW      	Removed Gate Drive Fault boolean
* 02/08/11   9.0    LWW      	Added Phase Resonableness data
* 04/03/11   10.0   BDO		  	Added CDD_EPSInitRoutineStatus_Cnt_G_u16
* 10/11/11   11.0   BDO      	Add CDD_TcPrgStatus and CDD_TcReflashActive
* 10/28/11   12.0	KJS			Added CDD_Adc_ConvFlag_Uls_u08       											#4601
* 11/23/11   13.0	BDO     	Add CDD_DftAsstTbl_Cnt_lgc and CDD_DwnldAsstGain_Uls_f32
* 02/15/12   14.0   BDO      	Add CDD_OscEnableFlag_Cnt_G_lgc, CDD_GenPosTrajEnableFlag_Cnt_G_lgc,
* 								CDD_LocktoLockEnableFlag_Cnt_G_lgc
* 09/13/12   14.0   KJS      	Add CDD_FirstActvNTC_Cnt_G_u16
* 09/30/12   18.0   KJS      	Added CDD_CdcAuthLevel_Cnt_G_u8
* 10/19/12   19     JJW			Added MemMap statements															6059
* 11/08/12	 20		KJS			Merged i350/i390 paths. Updated Revision tracking.
* 11/21/11   21     JJW       	Added CDD_CDDMtrPosAccessBfr_Cnt_G_u16 to decuple the MtrPos buffer from the 
* 								Phase Reasonableness data in order to provide freedom for synchronizing 
*                               the data buffers appropriately.
* 11/21/11   22     JJW       	MemMap correction for CDDMtrPosAccessBfr to be in Ap_7
* 11/28/11   24     KJS       	MemMap correction for CDD_TcPrgStatus_Cnt_G_enum to be in Ap_9
* 12/06/12   25     JJW       	PwmCdd FDD34B_001.3 integration.  Removal of unused Analog phase reasonableness signals
* 02/07/13   27 	DD			Change request 7247 Add CDD_DemIdSnapshot_Cnt_G_u8 variable
* 02/18/13   28 	KJS			Added shared buffers for FDD15C integration between PwmCdd and Nhet components.
* 03/14/13   29 	KJS			Added new variables for turns counter and flash programmer communications.
* 04/01/15   31 	KJS			Added variable CDD_NvMFastWriteEnable_Cnt_G_lgc
* 02/19/15   32 	ABS			Added variable CDD_TxSUEPS_Cnt_G_lgc
* 06/29/15   34 	ABS			Added variables CDD_TxSUEPSSendMsg_Cnt_G_lgc, CDD_StConVehMissing_Cnt_G_lgc and CDD_StConVehInvalid_Cnt_G_lgc
* 07/17/16   35 	ABS			Removed variables CDD_StConVehMissing_Cnt_G_lgc and CDD_StConVehInvalid_Cnt_G_lgc
* 07/29/16   36 	RMV			Added CDD_TxSTEPSSendMSg_Cnt_G_lgc variable - (Anomaly - EA3#9635)
* 08/01/16   37   RMV     Added FrCycleSwitchOddEven_Cnt_G_u08 variables - (Anomaly - EA3#9011)
*/

#include "Std_Types.h"
#include "CDD_Const.h"
#include "CDD_Data.h"

/**********************************************************************************************************************
 *  Ap_7
 *********************************************************************************************************************/
#define CDDDATA7_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */

volatile VAR(uint8, IOHWAB_NOINIT_8BIT) CDD_Adc_ConvFlag_Uls_u08;
VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashStatus_Cnt_G_u08;

#define CDDDATA7_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA7_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

VAR(boolean, CDD_VAR_NOINIT) CDD_TCprocessing_Cnt_G_lgc;

#define CDDDATA7_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 *  Ap_9
 *********************************************************************************************************************/
#define CDDDATA9_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;		/* EOL Global Data */
VAR(uint32, CDD_VAR_NOINIT) CDD_CustEOLSrlComSvcDft_Cnt_G_b32;
VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;

VAR(TcFlshPrgStatus_T, CDD_VAR_NOINIT) CDD_TcPrgStatus_Cnt_G_enum; /* Turns Counter Programming */
VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePNVldCnt_Cnt_G_u32;
VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePN_Cnt_G_u32;

VAR(uint32, CDD_VAR_NOINIT) CDD_InitialTime_mS_G_u32;

#define CDDDATA9_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA9_START_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

VAR(uint16, CDD_VAR_NOINIT) CDD_FirstActvNTC_Cnt_G_u16; /* NTC Number for DBG Frame */
VAR(uint16, CDD_VAR_NOINIT) CM_DiagNegRespCode_u16;

#define CDDDATA9_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA9_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */

VAR(Dem_EventIdType, CDD_VAR_NOINIT) CDD_DemIdSnapshot_Cnt_G_u8; /* DEM EventId for Snapshot Data (DID$5030) */
VAR(uint8, CDD_VAR_NOINIT) CDD_CdcAuthLevel_Cnt_G_u8;
VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashErrors_Cnt_G_u08; /* Turns Counter Programming */
VAR(uint8, CDD_VAR_NOINIT) FrCycleSwitchOddEven_Cnt_G_u08; /* Flexray Cycle info - Odd or Even */
VAR(uint8, CDD_VAR_NOINIT) CDD_DispCC_Per_Cnt_G_u08; /* Controlling the DISP_CC_EPS message */

#define CDDDATA9_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashActive_Cnt_G_lgc; /* Data Native to Application Loop */
VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashVerify_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_OscEnableFlag_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_GenPosTrajEnableFlag_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_LocktoLockEnableFlag_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_SWTEnableFlag_Cnt_G_lgc; /* NXTR SWT */
VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_NvMFastWriteEnable_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_TxSUEPS_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_TxSUEPSSendMsg_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_InitialTimeLockout_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_TxSTEPSSendMSg_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_TxDispSendMsg_Cnt_G_lgc;
#define CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *  Ap_10
 *********************************************************************************************************************/
#define CDDDATA10_START_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */
/* Data Native to MtrCtrl Loop */
VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

/* Data Native to Application Loop */
VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

/* SVDrvr and NHET variables */
VAR(uint16, CDD_VAR_NOINIT) CDD_DCPhsComp_Cnt_G_u16[3];
VAR(uint16, CDD_VAR_NOINIT) CDD_PWMPeriod_Cnt_G_u16;

#define CDDDATA10_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA10_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
/* Data Native to MtrCtrl Loop */
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
/* Data Native to Application Loop */
VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(FETFAULTTYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultType_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
VAR(FETPHASETYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultPhase_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];

/* Data Consistancy Buffer Access Variables */
VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;

#define CDDDATA10_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */


#define CDDDATA10_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
/* Data Native to Application Loop */
VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];

#define CDDDATA10_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


