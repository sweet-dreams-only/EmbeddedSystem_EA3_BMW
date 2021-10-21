/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : Cdc_User.c file
* Module Description: This file contains the application interface between
*                     the DCM and EPS Internal diagnostic services
* Product           : Gen II Plus - EA3.0
* Author            : Bobby O'Steen
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thu Jan 17 15:57:01 2008 %
* %version:          EA3#106 %
* %date_modified:    Thu Jan 23 17:34:59 2014 %
*---------------------------------------------------------------------------*/

/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_User.c                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : n.a.                                                          **
**                                                                            **
**  PURPOSE   : Support of DCM diagnostic services corresponding              **
**              to specification for AUTOSAR - user part                      **
**                                                                            **
**  REMARKS   : Implementation of user specific diagnostic services           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** dabu         Daniel Buder               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.2 : 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.1 : 19.03.2009, dabu: CR70162: Rte_DcmCompareKey_User() return of
 *                                     DCM_E_COMPARE_KEY_FAILED by default
 * V1.0.0 : 15.08.2008, dabu: BSCCDC-34: SecurityAccess: make Rte_DcmGetSeed()
 *                                       and Rte_DcmCompareKey() user extendable
 *          17.01.2008, dabu: initial version
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>              /* include AUTOSAR standard types         */
/* -------------------------------------------------------------------------- */
#include <Cdc.h>                    /* Subparameter macros of diagn. services */
/* -------------------------------------------------------------------------- */
#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */
#include <Cdc_User.h>               /* prototypes of the CDC user functions   */

#include "diag_types.h"
#include "Dcm_types.h"
#include "SComm_Func.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "CDD_Data.h"
#include "RTE_GlobalData.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "CalConstants.h"
#include "Rte_type.h"			/* Need for Rte PIM Data Structures */
#include "Rte_Ap_SrlComInput.h"	/* Need for GetEventFailed */
#include "SystemTime.h"
#include "Dem.h"
#include "EcuM.h"				/* Needed for ECU Reset EcuM calls */
#include "float.h"
#include "Com.h"				/* Needed for access to Com_ReceiveSignal APIs */


#include "Ap_DiagMgr.h"

/* NXTR SWT */
#include "Swt_Appl.h"
#include "Swt_Common.h"
#include "Swt_SWData.h"

#include "T1_AppInterface.h"
#include "T1_AppInterface_Cfg.h"
#include "GCP_driverInterface.h"


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*
 * Version check
 */
#if ((CDC_H_MAJOR_VERSION != 1u) || \
	 (CDC_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc.h found!!"
#endif
#if ((CDC_CFG_H_MAJOR_VERSION != 1u) || \
	 (CDC_CFG_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_Cfg.h found!!"
#endif
#if ((CDC_USER_H_MAJOR_VERSION != 1u) || \
	 (CDC_USER_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_User.h found!!"
#endif


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/



/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/



/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/
#define D_FAILNFAILTHISOPCYCLE_CNT_U08	    		0x03U

/* RIDs */
#define D_BMWEPSINITPID_CNT_U16						0xAB6CU
#define D_BMWEPSPOSTRIMPID_CNT_U16					0xAB69U
#define D_BMWEPSCLEARRACKCNTRPID_CNT_U16			0xAB7CU
#define D_BMWEPSPARTIALCLRRACKCNTRPID_CNT_U16		0xAB7DU
#define D_BMWEPSTCPICFLASHPID_CNT_U16       		0x1234U

#define D_BMWEPSOSCTRAJPID_CNT_U16					0xAB56U
#define D_BMWEPSGENPOSTRAJPID_CNT_U16				0xAB71U
#define D_BMWEPSLOCKTOLOCKPID_CNT_U16				0xAB72U

#define D_BMWEPSCLRPULLDRIFTPID_CNT_U16				0xA2BBU

/* TODO: D_BMWEPSRESETSWTDATAPID_CNT_U16 service could be removed or modified once requirements are defined to allow
 * SWT FAT to be run multiple times on the same controller. This service resets the SWT
 * NVM RAM blocks back to default values to allow the test to be rerun after the SWT NVM
 * blocks have updated with the status from a previous test run.
 */
#define D_BMWEPSRESETSWTDATAPID_CNT_U16				0xBBBBU

/* DIDs */

#define D_BMWEPSSTATUSCALCVN_CNT_U16				0x2541U

#define D_BMWEPSHWAUTHPID_CNT_U16					0xDB57U
#define D_BMWEPSHWASENSORCALIBPID_CNT_U16			0xDB5AU
#define D_BMWEPSMTRCURRENTPID_CNT_U16				0xDB8BU
#define D_BMWEPSMTRPOSSNSRPID_CNT_U16				0xDB56U
#define D_BMWEPSTRQSNSRPID_CNT_U16					0xDB99U
#define D_BMWEPSLIMITANGLEPID_CNT_U16				0xDB59U
#define D_BMWEPSREADRACKCNTRPID_CNT_U16				0xDC77U
#define D_BMWEPSREADSYSSUPPID_CNT_U16				0xF18AU
#define D_BMWEPSHWAPUPDATESRVC_CNT_U16				0xFEE3U /* Note, this shares the same service ID as CMS FEE3. They are both the same function,
															   but can be called from either control state */
#define D_MTRSUPPLRSERVICE_CNT_U16					0x4444U
#ifdef T1_ENABLE
#define D_T1_RDBI_WDBI_CNT_U16						0xABCDU /* DID for ReadDataByIdentifier and WriteDataByIdentifier for Gliwa */
#endif
#define D_ELTRCLHWINDEX_CNT_U16						0xF152U
#define D_STORDRACKTRVLANDCENTRDATA_CNT_U16			0xDFDDU

/* SNAPSHOT Data */
#define D_SS_VEHSPD_CNT_U16							0x500AU
#define D_SS_ST_DRV_VEH_CNT_U16						0x5004U
#define D_SS_ECU_VOLTS_CNT_U16						0x5006U
#define D_SS_STRWHL_ANGLE_CNT_U16					0x5003U
#define D_SS_CMD_MTR_TRQ_CNT_U16					0x500FU
#define D_SS_HW_TRQ_CNT_U16							0x500EU
#define D_SS_NTC_NUM_CNT_U16						0x5032U
#define D_SS_PSCM_STATUS_CNT_U16					0x500CU


/* NRCs */
#define D_EPSNRCCONDNOTCORRECT_CNT_U08				0x22U
#define D_EPSNRCINVALIDFORMAT_CNT_U08				0x13U
#define D_EPSNRCSUBFUNCNOTSUPRTINSESSION_CNT_U08	0x7EU
#define D_EPSNRCREQSEQERROR_CNT_U08					0x24U
#define D_EPSNRCSUBFUNCTIONNOTSUPPORTED_CNT_U08     0x12U
#define D_EPSNRCREQUESTOUTOFRANGE_CNT_U08           0x31U

/* ROUTINE STATUS */
#define D_RTNACTIVE_CNT_U08							0x01U
#define D_RTNCOMPLETE_CNT_U08						0x02U
#define D_RTNCANCELLED_CNT_U08						0x03U
#define D_RTNFAILURE_CNT_U08						0x04U

/* SERVICE CONDITIONS */
#define D_VEHSPDSESSIONLMT_KPH_F32					10.0F

/* AB6C */
#define D_RTNTIMEOUT_MS_U32							30000L

/* DB8B */
#define D_AVGCURRLOLMT_AMP_F32						(-300.0F)
#define D_AVGCURRHILMT_AMP_F32						300.0F

/* DB56 */
#define D_DEGPERREV_ULS_F32							180.0F
#define D_REVSCALE_ULS_F32							0.5F

/* DB99 */
#define D_HWTRQLOLMT_HWNM_F32						(-10.0F)
#define D_HWTRQHILMT_HWNM_F32						10.0F

/* AB6C */
#define D_FINHWPOSLOLMT_HWDEG_F32					(-1000.0F)
#define D_FINHWPOSHILMT_HWDEG_F32					1000.0F

/* DB59 */
#define D_EOTLEARNED_CNT_U16						0x01U

/* DB5A */
#define D_HWOFFSETSCALE_HWDEGPCNT_U0P16				FPM_InitFixedPoint_m(0.01, u0p16_T)
#define D_HWOFFSETWRITELIMIT_CNT_U16				3000U
#define D_HWOFFSETSCALE_CNTSPHWDEG_F32				100.0F

/* DB57 */
#define D_EOTPOSLOLMT_HWDEGS_F32					(-1024.0F)
#define D_EOTPOSHILMT_HWDEGS_F32					1023.0F
#define D_EOTPOSSCALE_CNTSPHWDEG_F32				100.0F

/* Pinion Sensor Conditions, Used in AB6C and DB57 */
enum PinionSnsrCond {
	CntrNotFound_Cnt_u08 		= 0U,
	RackCntrFound_Cnt_u08 		= 1U,
	VehCntrFound_Cnt_u08		= 2U,
	RackVehCntrFound_Cnt_u08 	= 3U
};



#define D_CONVERTRADTODEG_DEGPRAD_F32				57.2957795F
#define D_HWVELLOLMT_HWDEGS_F32						(-1000.0F)
#define D_HWVELHILMT_HWDEGS_F32						1000.0F
#define D_HWVELSCALE_CNTSPHWDEG_F32					1.0F

/* AB56 */
#define D_OSCTRAJPIDLENGTH_CNT_U08					6U
#define D_OSCFREQSCALE_HZPCNT_U12P4					FPM_InitFixedPoint_m(0.0625, u12p4_T)
#define D_OSCFREQLOLMT_HZ_F32						1.0F
#define D_OSCFREQHILMT_HZ_F32						5.0F
#define D_AMPLITUDELOLMT_DEGS_F32					1.0F
#define D_AMPLITUDEHILMT_DEGS_F32					15.0F
#define D_OSCCYCLESLOLMT_ULS_U08					1U
#define D_OSCCYCLESHILMT_ULS_U08					50U
#define D_SIGNALGENERATED_CNT_U08					2U

/* AB71 */
#define D_GENPOSTRAJPIDLENGTH_CNT_U08				8U
#define D_ABSOLUTEPOS_CNT_U08						0x01U
#define D_RELATIVEPOS_CNT_U08						0x00U
#define D_MAXCONF_ULS_F32							1.0F
#define D_TRGTHWPOSSCALE_HWDEGPCNT_U0P16			FPM_InitFixedPoint_m(0.01, u0p16_T)
#define D_TRGTHWPOSLOLMT_HWDEGS_F32					(-100.0F)
#define D_TRGTHWPOSHILMT_HWDEGS_F32                 100.0F
#define D_TRGTHWVELLOLMT_DEGPS_F32					1.0F
#define D_TRGTHWVELHILMT_DEGPS_F32					100.0F
#define D_TRGTHWACCELSCALE_DEGPSSQRDPCNT_U16		10U
#define D_TRGTHWACCELLOLMT_DEGSPSSQRD_F32			10.0F
#define D_TRGTHWACCELHILMT_DEGSPSSQRD_F32			2000.0F

/* AB72 */
#define D_LOCKTOLOCKPIDLENGTH_CNT_U08         		6U
#define D_LKTOLKTRGTHWVELLOLMT_DEGPS_F32			1.0F
#define D_LKTOLKTRGTHWVELHILMT_DEGPS_F32			100.0F
#define D_LKTOLKTRGTHWACCELLOLMT_DEGSPSSQRD_F32		10.0F
#define D_LKTOLKTRGTHWACCELHILMT_DEGSPSSQRD_F32		2000.0F

#define D_SVCDFTENGINEON_CNT_B32					0x00000001UL
#define D_SVCDFTENGANDTRQRMP_CNT_B32    			0x00000101UL

#define D_NXTRSRLCOMSVCDFTPID_CNT_U16				0xFD02U
#define D_ROUTINETABLESIZE_CNT_U08					5U
#define D_INACTIVE_CNT_U08							0U
#define D_ZERO_HWDEG_F32							(0.0f)

#define D_SESSCHNGVEHSPDLMT_KPH_F32					10.0F
#define D_SESSCHNGVEHSPDLMT_CODING_KPH_F32			6.0F
#define D_MAXHWPOSITION_HWDEG_F32					1440.11F

typedef enum Routine_Control_State {
				DEFAULT = 	  0,
				ACTIVE = 	  0x01,
				SUCCESS = 	  0x02,
				CANCELLED =   0x03,
				ERROR = 	  0x04,
				HWANGORHWVEL =  0x0A,
				VEHSPD = 	  0x0B,
				HANDSON = 	  0x0C,
				OBSTRUCTION = 0x0D
			}ROUTINECNTRLSTATE_Enum;

typedef struct {
				union {
						float32 FloatData_f32;
						uint32  IntData_u32;
					  }DataType;
				} EPS_DiagSrv_DataStruct;

#define CDCUSER_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(ROUTINECNTRLSTATE_Enum, CDD_VAR_NOINIT) OSCTrajRoutineStatus_Cnt_M_enum;
STATIC VAR(ROUTINECNTRLSTATE_Enum, CDD_VAR_NOINIT) LocktoLockRoutineStatus_Cnt_M_enum;
STATIC VAR(ROUTINECNTRLSTATE_Enum, CDD_VAR_NOINIT) GenPosTrajRoutineStatus_Cnt_M_enum;

/* NXTR SWT */
/* query SWT library */
STATIC volatile SwtRC_t SWTStartupChk_Cnt_enum;

#define CDCUSER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */



#define CDCUSER_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) ECUHardResetInProgress_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) DTCSettingOFF_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) AbsPosTrajReq_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) HandsONStart_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) HandsONAbort_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) HwAngleOrHwVelCheckResult_Cnt_M_lgc;
STATIC VAR(boolean, CDC_USER_VAR_NOINIT) OpStatePreStartCheck_Cnt_M_lgc;

#define CDCUSER_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */



#define CDCUSER_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, CDC_USER_VAR_NOINIT) EPSInitRoutineStatus_Cnt_M_u08;
STATIC VAR(uint8, CDD_VAR_NOINIT) TCPicFlashRoutineStatus_Cnt_M_u08;
STATIC VAR(uint8, CDC_USER_VAR_NOINIT) Cycles_Cnt_M_u08;

#define CDCUSER_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */



#define CDCUSER_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, CDC_USER_VAR_NOINIT) ActiveRID_Cnt_M_u16;
#define CDCUSER_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDCUSER_START_SEC_VAR_INIT_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, CDC_USER_VAR_NOINIT) RoutineIDTable_Cnt_M_u16[D_ROUTINETABLESIZE_CNT_U08] =
								{D_BMWEPSINITPID_CNT_U16, D_BMWEPSOSCTRAJPID_CNT_U16,
								 D_BMWEPSGENPOSTRAJPID_CNT_U16, D_BMWEPSLOCKTOLOCKPID_CNT_U16,
								 D_NXTRSRLCOMSVCDFTPID_CNT_U16};
#define CDCUSER_STOP_SEC_VAR_INIT_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDCUSER_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) EPSInitRoutineTime_Cnt_M_u32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) PosTrajTrgtHWPos_HwDeg_M_f32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) Amplitude_HwDeg_M_f32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) Frequency_Hz_M_f32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) TrgtHwVel_DegpS_M_f32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) TrgtHwAccel_DegpSSqrd_M_f32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) PosTrajHoldTime_Cnt_M_u32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) CurrentHwPos_HwDeg_M_f32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) HandsONStartTime_Cnt_M_u32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) HandsONAbortTime_Cnt_M_u32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) OpStateEnableWaitTime_Cnt_M_u32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) HandwheelAngAbortTime_Cnt_M_u32;
STATIC VAR(uint32, CDC_USER_VAR_NOINIT) HandwheelVelAbortTime_Cnt_M_u32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) RoutineHwPosStart_HwDeg_M_f32;
STATIC VAR(float32, CDC_USER_VAR_NOINIT) LrnPnCntrHwTravl_HwDeg_M_f32;
VAR(float32, NVM_APPL_DATA) Rte_AbsHwPos_EOLHwOffsetSnsrCal; /* TODO: Consider adding to PIM and moving write to AbsHwPos_Scom_SetCenterPosition */


#define CDCUSER_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define CDCUSER_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
/* NXTR SWT */
/* query SWT library */
static const uint8 swid[] = { 0x00U, 0xBDU, 0x00U, 0x01U };

#define CDCUSER_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/
STATIC FUNC(ROUTINECNTRLSTATE_Enum, CDC_USER_CODE) CheckRoutineConditions (boolean CheckHwPosAuth, ROUTINECNTRLSTATE_Enum CurrentRoutineStatus);
STATIC FUNC(boolean, CDC_USER_CODE) HandsOnDetection (ROUTINECNTRLSTATE_Enum RoutineStatus);
STATIC FUNC(void, CDC_USER_CODE) HwAngleOrHwVelCheck(ROUTINECNTRLSTATE_Enum RoutineStatus);
STATIC FUNC(boolean, CDC_USER_CODE) OperateStateCheck (void);
STATIC FUNC(uint8, CDC_USER_CODE) SensorConditionChk(void);

/* Snapshot data functions */
STATIC FUNC(uint8, CDC_USER_CODE) SS_VehSpd(void);
STATIC FUNC(uint8, CDC_USER_CODE) SS_StDrvVeh(void);
STATIC FUNC(uint8, CDC_USER_CODE) SS_EcuVolts(void);
STATIC FUNC(sint16, CDC_USER_CODE) SS_StrWhlAng(void);
STATIC FUNC(sint16, CDC_USER_CODE) SS_CmdMtrTrq(void);
STATIC FUNC(sint16, CDC_USER_CODE) SS_HwTrq(void);
STATIC FUNC(void,   CDC_USER_CODE) SS_NTCNum(	P2VAR(NTCNumber, AUTOMATIC, AUTOMATIC) NTCNum_Cnt_Ptr_u16, P2VAR(uint8, AUTOMATIC, AUTOMATIC) ParamData_Ptr_u8);
STATIC FUNC(uint16, CDC_USER_CODE) SS_PSCMStatus(void);
#define D_TESTFAILEDBIT_CNT_B8				0x01U
#define D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8	0x02U
#define D_ACTIVENTCTEST_CNT_B8	(D_TESTFAILEDBIT_CNT_B8 | D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8)



/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/*****************************************************************************
 *
 *	Function Name: 	   CDCUser_Init
 *
 *	Description:       Initialize Internal Variables and the Module Output value
 *
 *	Inputs:		       None
 *
 *	Outputs:	       None
 *
 *****************************************************************************/
FUNC(void, EPSDIAGSRVCS_CODE) CDCUser_Init(void)
{

	VAR(NvM_RequestResultType, AUTOMATIC) nvmRequestResult; /* return value of NvM functions */

	EPSInitRoutineStatus_Cnt_M_u08 = 0U;
	GetSystemTime_mS_u32(&EPSInitRoutineTime_Cnt_M_u32);

	ECUHardResetInProgress_Cnt_M_lgc = FALSE;

	DTCSettingOFF_Cnt_M_lgc = FALSE;

	TCPicFlashRoutineStatus_Cnt_M_u08 = 0U;

	RoutineHwPosStart_HwDeg_M_f32 = 0.0F;

	OSCTrajRoutineStatus_Cnt_M_enum = DEFAULT;
	CDD_OscEnableFlag_Cnt_G_lgc = FALSE;

	GenPosTrajRoutineStatus_Cnt_M_enum = DEFAULT;
	CDD_GenPosTrajEnableFlag_Cnt_G_lgc = FALSE;
	AbsPosTrajReq_Cnt_M_lgc = FALSE;
	PosTrajTrgtHWPos_HwDeg_M_f32 = 0.0f;
	CurrentHwPos_HwDeg_M_f32 = 0.0f;
	GetSystemTime_mS_u32(&PosTrajHoldTime_Cnt_M_u32);

	LocktoLockRoutineStatus_Cnt_M_enum = DEFAULT;
	CDD_LocktoLockEnableFlag_Cnt_G_lgc = FALSE;

	HandsONStart_Cnt_M_lgc = FALSE;
	HandsONAbort_Cnt_M_lgc = FALSE;
	GetSystemTime_mS_u32(&HandsONStartTime_Cnt_M_u32);
	GetSystemTime_mS_u32(&HandsONAbortTime_Cnt_M_u32);

	CDD_SWTEnableFlag_Cnt_G_lgc = FALSE;

	/* Check and init Swt_SWData NV data block.                  */
	NvM_GetErrorStatus(NVM_SWT_SW, &nvmRequestResult);
	if (nvmRequestResult != NVM_REQ_OK)
	{
		/* init Swt_SWData struct with default data */
		Swt_CommonCopy( Swt_SWData, Swt_SWDataDefault, sizeof( Swt_SWDataDefault ) );
		NvM_WriteBlock(NVM_SWT_SW, NULL_PTR);
	}

	/* Check and init Swt_SWSigData NV data block.                  */
	NvM_GetErrorStatus(NVM_SWT_SWSIG, &nvmRequestResult);
	if (nvmRequestResult != NVM_REQ_OK)
	{
		/* init Swt_SWData struct with default data */
		Swt_CommonCopy( Swt_SWSigData, Swt_SWSigDataDefault, sizeof( Swt_SWSigDataDefault ) );
		NvM_WriteBlock(NVM_SWT_SWSIG, NULL_PTR);
	}
}


/*****************************************************************************
 *
 *	Function Name: 	   CDCUser_Task
 *
 *	Description:       Called every 10ms.
 *
 *	Inputs:		       None
 *
 *	Outputs:	       None
 *
 *****************************************************************************/
FUNC(void, EPSDIAGSRVCS_CODE) CDCUser_Task(void)
{

	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

	if (D_RTNACTIVE_CNT_U08 == EPSInitRoutineStatus_Cnt_M_u08)
	{
		DtrmnElapsedTime_mS_u32(EPSInitRoutineTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

		if (ElapsedTime_Cnt_T_u32 > D_RTNTIMEOUT_MS_U32)
		{
			EPSInitRoutineStatus_Cnt_M_u08 = D_RTNCANCELLED_CNT_U08;
			CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGINEON_CNT_B32;
			ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
		}
	}

	if (D_RTNACTIVE_CNT_U08 == TCPicFlashRoutineStatus_Cnt_M_u08)
	{
		if (CDD_TcPrgStatus_Cnt_G_enum == TcPrgCmpl)
		{
			TCPicFlashRoutineStatus_Cnt_M_u08 = 0U;
			/* TODO: Clear new TCPICProgramming NTC */
		}
	}

	/* Customer Services hands on detection */
	if ((OSCTrajRoutineStatus_Cnt_M_enum != ACTIVE) &&
		(GenPosTrajRoutineStatus_Cnt_M_enum != ACTIVE) &&
		(LocktoLockRoutineStatus_Cnt_M_enum != ACTIVE))
	{
		HandsOnDetection (DEFAULT);
		HwAngleOrHwVelCheck(DEFAULT);
	}

	/* AB56 */
	if (OSCTrajRoutineStatus_Cnt_M_enum == ACTIVE)
	{   /* Check conditions to move from ACTIVE/START to STOP state */
		if (Rte_OscTraj_OscTrajState_Cnt_enum == CMD_STATE2)	/* OscTrajCmdStateType */
		{
			OSCTrajRoutineStatus_Cnt_M_enum = SUCCESS;
			CDD_OscEnableFlag_Cnt_G_lgc = FALSE;
			CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
			ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
		}
		else
		{	/* Check Deactivation Conditions */
			HandsOnDetection (ACTIVE);
			HwAngleOrHwVelCheck(ACTIVE);
			OSCTrajRoutineStatus_Cnt_M_enum = CheckRoutineConditions(FALSE, ACTIVE);

			if (OSCTrajRoutineStatus_Cnt_M_enum != ACTIVE)
			{
				CDD_OscEnableFlag_Cnt_G_lgc = FALSE;
			}
		}
	}

	/* AB71 */
	if (GenPosTrajRoutineStatus_Cnt_M_enum == ACTIVE)
	{   /* Check conditions to move from ACTIVE/START to STOP state */
		
		CurrentHwPos_HwDeg_M_f32 = Abs_f32_m(PosTrajTrgtHWPos_HwDeg_M_f32 - Rte_AbsHwPos_SrlComHwPos_HwDeg_f32);

		if (CurrentHwPos_HwDeg_M_f32 < k_CustSrvcPosTrajThres_HwDeg_f32)
		{
			DtrmnElapsedTime_mS_u32(PosTrajHoldTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);
			if (ElapsedTime_Cnt_T_u32 > k_CustSrvcPosTrajHoldTime_mS_u16)
			{
				GenPosTrajRoutineStatus_Cnt_M_enum = SUCCESS;
				CDD_GenPosTrajEnableFlag_Cnt_G_lgc = FALSE;
				CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
				ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
			}
		}
		else
		{
			GetSystemTime_mS_u32(&PosTrajHoldTime_Cnt_M_u32);
		}

		if (GenPosTrajRoutineStatus_Cnt_M_enum == ACTIVE)
		{	/* Check Deactivation Conditions */
			HandsOnDetection (ACTIVE);
			HwAngleOrHwVelCheck(ACTIVE);
			GenPosTrajRoutineStatus_Cnt_M_enum = CheckRoutineConditions(FALSE, ACTIVE);

			if (GenPosTrajRoutineStatus_Cnt_M_enum != ACTIVE)
			{
				CDD_GenPosTrajEnableFlag_Cnt_G_lgc = FALSE;
			}
		}
	}

	/* AB72 */
	if (LocktoLockRoutineStatus_Cnt_M_enum == ACTIVE)
	{	/* Check conditions to move from ACTIVE/START to STOP state */
		if(Rte_LktoLkStr_LrnPnCntrState_Cnt_enum == DONE) 	/*LktoLkStrStateType*/
		{
			LocktoLockRoutineStatus_Cnt_M_enum = SUCCESS;
			CDD_LocktoLockEnableFlag_Cnt_G_lgc = FALSE;
			CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
			ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
		}
		else if(Rte_LktoLkStr_LrnPnCntrState_Cnt_enum == TIMEOUT) 	/*LktoLkStrStateType*/
		{
			LocktoLockRoutineStatus_Cnt_M_enum = OBSTRUCTION;
			CDD_LocktoLockEnableFlag_Cnt_G_lgc = FALSE;
			CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
			ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
		}
		else
		{	/* Check Deactivation Conditions */
			HandsOnDetection (ACTIVE);
			HwAngleOrHwVelCheck(ACTIVE);
			LocktoLockRoutineStatus_Cnt_M_enum = CheckRoutineConditions(FALSE, ACTIVE);

			if (LocktoLockRoutineStatus_Cnt_M_enum != ACTIVE)
			{
				CDD_LocktoLockEnableFlag_Cnt_G_lgc = FALSE;
			}
		}
		if (ACTIVE != LocktoLockRoutineStatus_Cnt_M_enum)
		{
		  /* Disable defeat Stall limit */
			CDD_EOLSrlComSvcDft_Cnt_G_b32 &= 0xFFFFFFDFU;
		}
		if(D_ZERO_HWDEG_F32 != Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32)
		{
			LrnPnCntrHwTravl_HwDeg_M_f32 = Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32;
		}

     }


	/* NXTR SWT */
	if (Swt_RC_OK == Swt_IsSwActivated ( 0x30U, swid ) )
	{
		CDD_SWTEnableFlag_Cnt_G_lgc = TRUE;
	}

}


/*****************************************************************************
 *
 *	Function Name: 	   Dcm_InputOutputControlByIdentifier
 *
 *	Description:       SID: 0x2F - Nxtr/ISO14229 defined service
 *
 *	Inputs:		       pMsgContext
 *
 *	Outputs:
 *
 *****************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Dcm_InputOutputControlByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
	VAR(Dcm_NegativeResponseCodeType, AUTOMATIC) ResponseCode = DCM_E_OK;
	VAR(uint16, AUTOMATIC) IOC;

	VAR(Dcm_MsgLenType, AUTOMATIC) AdjReqLength_Cnt_T_u16;

	CM_SetNegResp(0);

	IOC = CDC_MAKE16BIT(pMsgContext->reqData[0], pMsgContext->reqData[1]);

	/* Diagnostic Service Access */

	/* Strip the RID length off of the request length */
	AdjReqLength_Cnt_T_u16 = pMsgContext->reqDataLen - (Dcm_MsgLenType)D_REQMSG_IOC_OFFSET_CNT_U16 - 1U;

	CM_DiagNegRespCode_u16 = DiagSrvcs_MainHandler(IOC,
												 (pMsgContext->reqData[D_REQMSG_IOC_OFFSET_CNT_U16]),
												 (&pMsgContext->reqData[D_REQMSG_IOC_OFFSET_CNT_U16 + 1U]),
												 AdjReqLength_Cnt_T_u16,
												 (&(pMsgContext->resDataLen)));
	pMsgContext->resData = pMsgContext->reqData;
	pMsgContext->resDataLen = pMsgContext->reqDataLen;
	/* End Service Access */

	if (CM_DiagNegRespCode_u16 != 0u)
	{
		ResponseCode = (Dcm_NegativeResponseCodeType)CM_DiagNegRespCode_u16;
	}


	if (ResponseCode != DCM_E_OK)
	{
		Dcm_SetNegResponse(pMsgContext, ResponseCode);
	}

	Dcm_ProcessingDone(pMsgContext);
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmECUReset_User                                       **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ECUReset (0x11) - user extension part                      **
**                 Trigger a reset. This function implements the first step   **
**                 of the operation: the sending of the positive response.    **
**                 The second step, the trigger of the reset, will be done    **
**                 in function 'Cdc_ConfirmationECUReset_User', to guarantee  **
**                 that the positive response will be sent successfully.      **
**                                                                            **
** PRECONDITIONS : this function will be called by Rte_DcmECUReset            **
**                      in the Cdc_Dispatcher.c                               **
**                                                                            **
** GLOBAL DATA   : pendingDiagContext.SubFunction with the actual             **
**                      SubFunction for this diagnostic serive                **
**                                                                            **
** PARAMETER     : pMsgContext->reqData[0]: reset Mode                        **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic SubFunction exist   **
**                      E_NOT_OK: an user ext. diag. SubFunction don't exist  **
**                                                                            **
** REMARKS       : If a negative response code shall be set, use the parameter**
**                      ResponseCode. The DCM function Dcm_SetNegResponse()   **
**                      shall only be called in the Cdc_Dispatcher.c!         **
**                 Don't change the ResponseCode if no negative Response Code **
**                      shall be set - default is DCM_E_OK !!!                **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmECUReset_User
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
#if (CdcEnableAsyncRequestHandling == STD_OFF)
   ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
#endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
)
{
	VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;
	VAR(uint16, AUTOMATIC) ResetID_Cnt_T_u16;
	VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrl;
	VAR(uint16, AUTOMATIC) AdjReqLength_Cnt_T_u16;

	/*
	 * dispatch between the different SubFunction
	 * (the SubFunction have been extracted in the Cdc_Dispatcher)
	 */

	Dcm_GetSesCtrlType(&SesCtrl);

	if ( SesCtrl == NXTR_SESSION )
	{
		/* Diagnostic Service Access */
		ResetID_Cnt_T_u16 = CDC_MAKE16BIT(0x11, pendingDiagContext.SubFunction);

		AdjReqLength_Cnt_T_u16 = pMsgContext->reqDataLen - 1U;

		CM_DiagNegRespCode_u16 = DiagSrvcs_MainHandler(ResetID_Cnt_T_u16,
										 pendingDiagContext.SubFunction,
										 &pMsgContext->reqData[D_REQMSG_RESET_OFFSET_CNT_U16],
										 AdjReqLength_Cnt_T_u16,
										 (&(pMsgContext->resDataLen)));
		/* End Service Access */

		/* Check the result of the CMS handler function, the response code is sent as a global signal */
		if (CM_DiagNegRespCode_u16 != 0u)
		{
			*ResponseCode = CM_DiagNegRespCode_u16;
			returnCode = E_NOT_OK;

		}
	}
	else
	{
		switch (pendingDiagContext.SubFunction)
		{
			case DIAG_UDS11_01_HARD_RESET:

				if ( (Rte_SrlComInput2_SrlComVehSpd_Kph_f32 < k_CustSrvcVehSpdThres_kph_f32) &&
					 (Abs_f32_m(Rte_HwTrq_AnaHwTorque_HwNm_f32) < k_CustSrvcHwTrqThres_HwNm_f32) )
				{
					ECUHardResetInProgress_Cnt_M_lgc = TRUE;
				}
				else
				{	/* Reject HardReset request - Conditions not correct */
					*ResponseCode = D_EPSNRCCONDNOTCORRECT_CNT_U08;
					returnCode = E_NOT_OK;
				}
			break;

			default:
			/* don't set ResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED; here,
			 * because this will be done in the Cdc_Dispatcher
			 */
				returnCode = E_NOT_OK;
			break;
		}
	}

	return returnCode;
} /* end of function 'Rte_DcmECUReset'                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ConfirmationECUReset_User                              **
**                                                                            **
** DESCRIPTION   : Post handler of 'Cdc_ECUReset' (0x11) - user extension part**
**                 Trigger a reset. This function implements the second step  **
**                 of the operation after the positive response was send.     **
**                 The functions initiates the shutdown (inc. writing         **
**                 data to EEPROM)                                            **
**                                                                            **
** PRECONDITIONS : this function will be called by Cdc_ConfirmationECUReset   **
**                      in the Cdc_XxxMandatory.c                             **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pendingSubFunction: reset Mode                             **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic SubFunction exist   **
**                      E_NOT_OK: an user ext. diag. SubFunction don't exist  **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_CODE) Cdc_ConfirmationECUReset_User
(
   CONST(uint8,AUTOMATIC) pendingSubFunction
)
{
   VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

   /*
	* 'pMsgContext' can not be used here - it is released before call of
	* 'Rte_DcmConfirmation'
	*/

   /*
	* dispatch between the different SubFunction
	* (the SubFunction have been extracted in the Cdc_Dispatcher)
	*/
   switch (pendingSubFunction)
   {
	   case DIAG_UDS11_01_HARD_RESET:
		   /* initiate an ECU reset */
		   EcuM_SelectShutdownTarget(ECUM_STATE_RESET, (uint8)0);

		   EcuM_KillAllRUNRequests();
	   break;
	  default:
		 /* unknown sub parameter                                             */
		 returnCode = E_NOT_OK;
		 break;
   }

   return returnCode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmReadDataByIdentifier_User                           **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) - user extension part          **
**                                                                            **
** PRECONDITIONS : this function will be called by Rte_DcmReadDataByIdentifier**
**                      in the Cdc_Dispatcher.c                               **
**                                                                            **
** GLOBAL DATA   : pendingDiagContext.DataOrRoutineId with the actual         **
**                      DataID for this diagnostic serive                     **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 with activated PagedBuffering:                             **
**                      Rte_DcmUpdatePageType pCurrentUpdatePage              **
**                      boolean isPagedProcessingExecuted                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic DataID exist        **
**                      E_NOT_OK: an user ext. diagnostic DataID don't exist  **
**                                                                            **
** REMARKS       : If a negative response code shall be set, use the parameter**
**                      ResponseCode. The DCM function Dcm_SetNegResponse()   **
**                      shall only be called in the Cdc_Dispatcher.c!         **
**                 If the PagedBuffering shall be used, set the name of the   **
**                      service handler function to pCurrentUpdatePage        **
**                      Additionally set isPagedProcessingExecuted to TRUE to **
**                      prevent a duplicated execution of Dcm_ProcessingDone()**
**                      because this will be done by the PagedBuffering.      **
**                 Don't change the ResponseCode if no negative Response Code **
**                      shall be set - default is DCM_E_OK !!!                **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmReadDataByIdentifier_User
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
#if (CdcEnableAsyncRequestHandling == STD_OFF)
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
#endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   CONSTP2VAR(Rte_DcmUpdatePageType, AUTOMATIC, CDC_VAR_DCMDATA) pCurrentUpdatePage,
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
	VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;
	VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrl;
	VAR(uint16, AUTOMATIC) PID;

	VAR(uint8, AUTOMATIC) SensorCondition_Cnt_T_u08 = 0U;
	VAR(float32, AUTOMATIC) StrWhlAngle_HwDeg_T_f32;
	VAR(sint32, AUTOMATIC) StrWhlAngle_Cnt_T_s32;

	VAR(float32, AUTOMATIC) AvgMtrCurr_Cnt_T_f32;
	VAR(sint32, AUTOMATIC) AvgMtrCurr_Cnt_T_s32;

	VAR(float32, AUTOMATIC) MtrPosMech_Deg_T_f32;
	VAR(sint32, AUTOMATIC) MtrPosMech_Cnt_T_s32;
	VAR(float32, AUTOMATIC) MtrPosMech2_Deg_T_f32;
	VAR(sint32, AUTOMATIC) MtrPosMech2_Cnt_T_s32;
	VAR(boolean, AUTOMATIC) MtrPosFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrPosFault2_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(sint16, AUTOMATIC) HwTrq_Cnt_T_s16;

	VAR(uint8, AUTOMATIC) EOTLearnedStatus_T_u08;
	VAR(float32, AUTOMATIC)EOTCWPosition_HwDeg_T_f32;
	VAR(sint32, AUTOMATIC) EOTCWPosition_Cnt_T_s32;
	VAR(float32, AUTOMATIC)EOTCCWPosition_HwDeg_T_f32;
	VAR(sint32, AUTOMATIC) EOTCCWPosition_Cnt_T_s32;

	VAR(float32, AUTOMATIC) StrWhlVel_HwDegpS_T_f32;
	VAR(sint16, AUTOMATIC) StrWhlVel_Cnt_T_s16;

	VAR(Dcm_MsgLenType, AUTOMATIC) AdjReqLength_Cnt_T_u16;


	VAR(uint8, AUTOMATIC) MtrSuplrService_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) ElctrcalHwIndex_Cnt_T_u16;
	VAR(float32, AUTOMATIC)LrnPnCntrHwTravel_HwDeg_T_f32;
	VAR(float32, AUTOMATIC)StoredRackTravel_HwDeg_T_f32;
	VAR(uint8, AUTOMATIC)StoredRackTrvlValid_Cnt_T_u8;
	VAR(EPS_DiagSrv_DataStruct, AUTOMATIC) StrdRkTvl;
	VAR(EPS_DiagSrv_DataStruct, AUTOMATIC) LrnPnCtrHwTvl;



	/* Snapshot Variables */
	VAR(uint8, AUTOMATIC) VehSpd_Kph_T_u8;
	VAR(uint8, AUTOMATIC) StDrvVeh_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) Vecu_Cnt_T_u8p0;
	VAR(sint16, AUTOMATIC) StrWhlAng_HwDeg_T_s16p0;
	VAR(sint16, AUTOMATIC) CmdMtrTrq_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16;
	VAR(uint8, AUTOMATIC)  NTCParam_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) PSCMStatus_Cnt_T_u16;

#ifdef T1_ENABLE
	VAR(uint8, AUTOMATIC) i;
#endif /* T1_ENABLE */


	CM_SetNegResp(0);

	PID = pendingDiagContext.DataOrRoutineId;
	/*
	  * get DataIdentifier (DId) of the pending 'ReadDataByIdentifier' request.
	  * store global for possible use in post handler
	*/
	Dcm_GetSesCtrlType(&SesCtrl);

	if ( SesCtrl == NXTR_SESSION )
	{
		/* Diagnostic Service Access */
		AdjReqLength_Cnt_T_u16 = pMsgContext->reqDataLen - ((Dcm_MsgLenType)D_REQMSG_PID_OFFSET_CNT_U16);
		CM_DiagNegRespCode_u16 = DiagSrvcs_MainHandler(PID,
													 D_SRVCREQTYPEREAD_CNT_U16,
													 (&pMsgContext->reqData[D_REQMSG_PID_OFFSET_CNT_U16]),
													 AdjReqLength_Cnt_T_u16,
													 (&(pMsgContext->resDataLen)));
		pMsgContext->resData = pMsgContext->reqData;
		/* End Service Access */

		if (CM_DiagNegRespCode_u16 != 0u)
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)CM_DiagNegRespCode_u16;
		}
		else
		{
			/* Assign the PID ID back into the first two bytes of the response data. */
			pMsgContext->resDataLen += 2u;
			pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
			pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		}

	}
	else if (PID == D_BMWEPSHWAUTHPID_CNT_U16) /* HW POS AUTHORITY */
	{
		pMsgContext->resDataLen = 9u;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

	    StrWhlAngle_HwDeg_T_f32 = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		StrWhlAngle_HwDeg_T_f32 = Limit_m(StrWhlAngle_HwDeg_T_f32, D_EOTPOSLOLMT_HWDEGS_F32, D_EOTPOSHILMT_HWDEGS_F32);
		StrWhlAngle_Cnt_T_s32 = (sint32)(StrWhlAngle_HwDeg_T_f32 * D_EOTPOSSCALE_CNTSPHWDEG_F32);
		pMsgContext->resData[2] = CDC_GETHIHIBYTE(StrWhlAngle_Cnt_T_s32); /*PinionAngleValue bytes 0-3 */
		pMsgContext->resData[3] = CDC_GETHILOBYTE(StrWhlAngle_Cnt_T_s32);
		pMsgContext->resData[4] = CDC_GETLOHIBYTE(StrWhlAngle_Cnt_T_s32);
		pMsgContext->resData[5] = CDC_GETLOLOBYTE(StrWhlAngle_Cnt_T_s32);

		StrWhlVel_HwDegpS_T_f32 = Rte_MtrVel_HandwheelVel_HwRadpS_f32 * D_CONVERTRADTODEG_DEGPRAD_F32 * (float32)k_SComTrqPosPol_Cnt_s08;
		StrWhlVel_HwDegpS_T_f32 = Limit_m(StrWhlVel_HwDegpS_T_f32, D_HWVELLOLMT_HWDEGS_F32, D_HWVELHILMT_HWDEGS_F32);
		StrWhlVel_Cnt_T_s16 = (sint16)(StrWhlVel_HwDegpS_T_f32 * D_HWVELSCALE_CNTSPHWDEG_F32);
		pMsgContext->resData[6] = CDC_GETHIBYTE(StrWhlVel_Cnt_T_s16); /*PinionAngleSpeed bytes 4-5 */
		pMsgContext->resData[7] = CDC_GETLOBYTE(StrWhlVel_Cnt_T_s16);

		pMsgContext->resData[8] = SensorConditionChk();

	}
	else if (PID == D_BMWEPSREADRACKCNTRPID_CNT_U16)
	{
		pMsgContext->resDataLen = 3u;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		pMsgContext->resData[2] = (uint8)Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc;
	}

	else if (PID == D_BMWEPSMTRCURRENTPID_CNT_U16)
	{
		AvgMtrCurr_Cnt_T_f32 = Limit_m(0.0f /*TODO: Place appropriate signal for average current here when SER is updated to specify the signal */,
		                       D_AVGCURRLOLMT_AMP_F32, D_AVGCURRHILMT_AMP_F32);
		AvgMtrCurr_Cnt_T_s32 = FPM_FloatToFixed_m(AvgMtrCurr_Cnt_T_f32, s24p7_T);

		pMsgContext->resDataLen = 11u;

		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		pMsgContext->resData[2] = CDC_GETHILOBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[3] = CDC_GETLOHIBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[4] = CDC_GETLOLOBYTE(AvgMtrCurr_Cnt_T_s32);

		pMsgContext->resData[5] = CDC_GETHILOBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[6] = CDC_GETLOHIBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[7] = CDC_GETLOLOBYTE(AvgMtrCurr_Cnt_T_s32);

		pMsgContext->resData[8] = CDC_GETHILOBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[9] = CDC_GETLOHIBYTE(AvgMtrCurr_Cnt_T_s32);
		pMsgContext->resData[10] = CDC_GETLOLOBYTE(AvgMtrCurr_Cnt_T_s32);
	}

	else if (PID == D_BMWEPSMTRPOSSNSRPID_CNT_U16)
	{
		MtrPosMech_Deg_T_f32 =
		  	(Rte_MtrPos2_MechMtrPos_Rev_f32 - D_REVSCALE_ULS_F32) * D_DEGPERREV_ULS_F32;
		MtrPosMech_Cnt_T_s32 = FPM_FloatToFixed_m(MtrPosMech_Deg_T_f32, s24p7_T);

		MtrPosMech2_Deg_T_f32 =
			(MtrPos3_DiagMechMtrPos_Rev_M_f32 - D_REVSCALE_ULS_F32) * D_DEGPERREV_ULS_F32;
		MtrPosMech2_Cnt_T_s32 = FPM_FloatToFixed_m(MtrPosMech2_Deg_T_f32, s24p7_T);

		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriMSB_SinCosCorr, &MtrPosFault_Cnt_T_lgc);
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriVsSec_SinCosCorr, &MtrPosFault2_Cnt_T_lgc);

		if ( (TRUE == MtrPosFault_Cnt_T_lgc) ||
			 (TRUE == MtrPosFault2_Cnt_T_lgc) )
		{
			SensorCondition_Cnt_T_u08 = 1U;
		}

		pMsgContext->resDataLen = 9u;

		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		pMsgContext->resData[2] = CDC_GETHILOBYTE(MtrPosMech_Cnt_T_s32);
		pMsgContext->resData[3] = CDC_GETLOHIBYTE(MtrPosMech_Cnt_T_s32);
		pMsgContext->resData[4] = CDC_GETLOLOBYTE(MtrPosMech_Cnt_T_s32);

		pMsgContext->resData[5] = CDC_GETHILOBYTE(MtrPosMech2_Cnt_T_s32);
		pMsgContext->resData[6] = CDC_GETLOHIBYTE(MtrPosMech2_Cnt_T_s32);
		pMsgContext->resData[7] = CDC_GETLOLOBYTE(MtrPosMech2_Cnt_T_s32);

		pMsgContext->resData[8] = SensorCondition_Cnt_T_u08;
	}
	else if (PID == D_BMWEPSTRQSNSRPID_CNT_U16)
	{

		HwTrq_HwNm_T_f32 = Rte_HwTrq_AnaHwTorque_HwNm_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		HwTrq_HwNm_T_f32 = Limit_m(HwTrq_HwNm_T_f32,
			  D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32);

		HwTrq_Cnt_T_s16 = FPM_FloatToFixed_m(HwTrq_HwNm_T_f32, s8p7_T);

		if (FALSE == Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc)
		{
			SensorCondition_Cnt_T_u08 = 1u;
		}

		pMsgContext->resDataLen = 5u;

		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		pMsgContext->resData[2] = CDC_GETHIBYTE(HwTrq_Cnt_T_s16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(HwTrq_Cnt_T_s16);

		pMsgContext->resData[4] = SensorCondition_Cnt_T_u08;
	}
	else if (PID == D_BMWEPSLIMITANGLEPID_CNT_U16) /*Limit Angle*/
	{
		pMsgContext->resDataLen = 10u;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		EOTLearnedStatus_T_u08 = 0U;

		if ( (TRUE == Rte_LrnEOT_CWFound_Cnt_lgc) &&
			 (TRUE == Rte_LrnEOT_CCWFound_Cnt_lgc) )
		{
			EOTLearnedStatus_T_u08 = D_EOTLEARNED_CNT_U16;
		}

		/* CCWPosition */
		EOTCCWPosition_HwDeg_T_f32 = Rte_LrnEOT_CCWPosition_HwDeg_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		EOTCCWPosition_HwDeg_T_f32 = Limit_m(EOTCCWPosition_HwDeg_T_f32,
		                                     D_EOTPOSLOLMT_HWDEGS_F32, D_EOTPOSHILMT_HWDEGS_F32);

		EOTCCWPosition_Cnt_T_s32 = (sint32)(EOTCCWPosition_HwDeg_T_f32 * D_EOTPOSSCALE_CNTSPHWDEG_F32);

		/* CWPosition */
		EOTCCWPosition_HwDeg_T_f32 = Rte_LrnEOT_CWPosition_HwDeg_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		EOTCWPosition_HwDeg_T_f32 = Limit_m(EOTCCWPosition_HwDeg_T_f32,
		                                    D_EOTPOSLOLMT_HWDEGS_F32, D_EOTPOSHILMT_HWDEGS_F32);

		EOTCWPosition_Cnt_T_s32 = (sint32)(EOTCWPosition_HwDeg_T_f32 * D_EOTPOSSCALE_CNTSPHWDEG_F32);

		pMsgContext->resData[2] = CDC_GETHILOBYTE(EOTCCWPosition_Cnt_T_s32);
		pMsgContext->resData[3] = CDC_GETLOHIBYTE(EOTCCWPosition_Cnt_T_s32);
		pMsgContext->resData[4] = CDC_GETLOLOBYTE(EOTCCWPosition_Cnt_T_s32);

		pMsgContext->resData[5] = CDC_GETHILOBYTE(EOTCWPosition_Cnt_T_s32);
		pMsgContext->resData[6] = CDC_GETLOHIBYTE(EOTCWPosition_Cnt_T_s32);
		pMsgContext->resData[7] = CDC_GETLOLOBYTE(EOTCWPosition_Cnt_T_s32);

		pMsgContext->resData[8] = 0u;
		pMsgContext->resData[9] = EOTLearnedStatus_T_u08;
	}
	else if (PID == D_BMWEPSHWASENSORCALIBPID_CNT_U16)		/* Turns Counter Vehicle Center Offset */
	{
		/* Anomaly 3751: This correction changes this service read/write information. The READ service now
		 * reports the value of the rack to vehicle center offset value (same that is sent on FlexRay in SrlComOutput)
		 * The WRITE routine does not change for vehicle center position....so the read/write do not access the same data
		 */
		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16);
	}
	else if (PID == D_SS_VEHSPD_CNT_U16)
	{
		VehSpd_Kph_T_u8 = SS_VehSpd();

		pMsgContext->resDataLen = 3U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = VehSpd_Kph_T_u8;
	}
	else if (PID == D_SS_ST_DRV_VEH_CNT_U16)
	{
		StDrvVeh_Cnt_T_u8 = SS_StDrvVeh();

		pMsgContext->resDataLen = 3U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = StDrvVeh_Cnt_T_u8;
	}
	else if (PID == D_SS_ECU_VOLTS_CNT_U16)
	{
		Vecu_Cnt_T_u8p0 = SS_EcuVolts();

		pMsgContext->resDataLen = 3U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = Vecu_Cnt_T_u8p0;
	}
	else if (PID == D_SS_STRWHL_ANGLE_CNT_U16)
	{
		StrWhlAng_HwDeg_T_s16p0 = SS_StrWhlAng();

		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(StrWhlAng_HwDeg_T_s16p0);
		pMsgContext->resData[3] = CDC_GETLOBYTE(StrWhlAng_HwDeg_T_s16p0);
	}
	else if (PID == D_SS_CMD_MTR_TRQ_CNT_U16)
	{
		CmdMtrTrq_Cnt_T_s16 = SS_CmdMtrTrq();

		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(CmdMtrTrq_Cnt_T_s16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(CmdMtrTrq_Cnt_T_s16);
	}
	else if (PID == D_SS_HW_TRQ_CNT_U16)
	{
		HwTrq_Cnt_T_s16 = SS_HwTrq();

		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(HwTrq_Cnt_T_s16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(HwTrq_Cnt_T_s16);
	}
	else if (PID == D_SS_NTC_NUM_CNT_U16)
	{
		SS_NTCNum(&NTCNum_Cnt_T_u16, &NTCParam_Cnt_T_u8);

		pMsgContext->resDataLen = 6U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(NTCNum_Cnt_T_u16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(NTCNum_Cnt_T_u16);
		pMsgContext->resData[4] = NTCParam_Cnt_T_u8;
		pMsgContext->resData[5] = 0u; /* Per ICR 4017 */
	}
	else if (PID == D_SS_PSCM_STATUS_CNT_U16)
	{
		PSCMStatus_Cnt_T_u16 = SS_PSCMStatus();

		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(PSCMStatus_Cnt_T_u16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(PSCMStatus_Cnt_T_u16);
	}
	else if (PID == D_BMWEPSREADSYSSUPPID_CNT_U16)
	{
		pMsgContext->resDataLen = 5U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = k_SysSupplierID[0];
	    pMsgContext->resData[3] = k_SysSupplierID[1];
		pMsgContext->resData[4] = k_SysSupplierID[2];
	}
	else if (PID == D_BMWEPSHWAPUPDATESRVC_CNT_U16)
	{
		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[D_HWAPSGBMNUM_CNT_U8];
		pMsgContext->resData[1] = HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 1U)];
		pMsgContext->resData[2] = HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 2U)];
		pMsgContext->resData[3] = HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 3U)];
	}
	else if (PID == D_BMWEPSSTATUSCALCVN_CNT_U16)
	{
		pMsgContext->resDataLen = 22U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		(void)Edch_DataServicePort_Read((Dcm_Data_CALID_CVN_ArrayType *)(&pMsgContext->resData[2]));
	}

	#ifdef T1_ENABLE /* Only if Gliwa is enabled */
	else if (PID == D_T1_RDBI_WDBI_CNT_U16)
	{

		if(txFrameLength > 0u)
		{
			pMsgContext->resDataLen = (2u + txFrameLength);
			pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
			pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
			for(i = 0; i < txFrameLength; i++)
			{
				pMsgContext->resData[i+2] = txFrameBuffer.u8[i];
			}
			txFrameLength = 0u;
		}
		else
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)DCM_NRC_CONDITIONSNOTCORRECT;
		}
	}
	#endif

	else if (PID == D_MTRSUPPLRSERVICE_CNT_U16)
	{
		if ((Nvm_MtrSuplrByte_Cnt_u8 == D_MTRSUPLRSERV_DEFAULT_CNT_U08) || (Nvm_MtrSuplrByte_Cnt_u8 == D_MTRSUPLRSERV_LETRIKA_CNT_U08))
		{
			MtrSuplrService_Cnt_T_u8 = D_MTRSUPLRSERV_LETRIKA_CNT_U08;
		}
		else if (Nvm_MtrSuplrByte_Cnt_u8 == D_MTRSUPLRSERV_TAIGENE_CNT_U08)
		{
			MtrSuplrService_Cnt_T_u8 = D_MTRSUPLRSERV_TAIGENE_CNT_U08;
		}
		else
		{
			MtrSuplrService_Cnt_T_u8 = D_MTRSUPLRSERV_DEFAULT_CNT_U08;
		}

		pMsgContext->resDataLen = 3U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = MtrSuplrService_Cnt_T_u8;
	}
	else if (PID == D_ELTRCLHWINDEX_CNT_U16)
	{
		ElctrcalHwIndex_Cnt_T_u16 = Nvm_ElecHwIndex_Cnt_u16;
		pMsgContext->resDataLen = 4U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);
		pMsgContext->resData[2] = CDC_GETHIBYTE(ElctrcalHwIndex_Cnt_T_u16);
		pMsgContext->resData[3] = CDC_GETLOBYTE(ElctrcalHwIndex_Cnt_T_u16);
	}
	else if (PID == D_STORDRACKTRVLANDCENTRDATA_CNT_U16)
	{
		/* Stored rack travel data */
		(void) NvM_GetErrorStatus(Rte_NvmBlock_LnRkCtr_RackCntrData, &StoredRackTrvlValid_Cnt_T_u8);

		if((NVM_REQ_NOT_OK != StoredRackTrvlValid_Cnt_T_u8) && (NVM_REQ_INTEGRITY_FAILED != StoredRackTrvlValid_Cnt_T_u8) && (NVM_REQ_NV_INVALIDATED != StoredRackTrvlValid_Cnt_T_u8))
		{
			StoredRackTravel_HwDeg_T_f32 = Rte_Pim_LearnedRackCntr()->TotalRackTravel_HwDeg_f32;
		}
		else
		{
			StoredRackTravel_HwDeg_T_f32 = D_ZERO_ULS_F32;
		}

		/* most recent rack travel data */
		LrnPnCntrHwTravel_HwDeg_T_f32 = LrnPnCntrHwTravl_HwDeg_M_f32;

		pMsgContext->resDataLen = 10U;
		pMsgContext->resData[0] = CDC_GETHIBYTE(PID);
		pMsgContext->resData[1] = CDC_GETLOBYTE(PID);

		/* Managing Float data to be read as Uint data */
		StrdRkTvl.DataType.FloatData_f32 = StoredRackTravel_HwDeg_T_f32;
		pMsgContext->resData[2] = CDC_GETHIHIBYTE(StrdRkTvl.DataType.IntData_u32);
		pMsgContext->resData[3] = CDC_GETHILOBYTE(StrdRkTvl.DataType.IntData_u32);
		pMsgContext->resData[4] = CDC_GETLOHIBYTE(StrdRkTvl.DataType.IntData_u32);
		pMsgContext->resData[5] = CDC_GETLOLOBYTE(StrdRkTvl.DataType.IntData_u32);

		LrnPnCtrHwTvl.DataType.FloatData_f32 = LrnPnCntrHwTravel_HwDeg_T_f32;
		pMsgContext->resData[6] = CDC_GETHIHIBYTE(LrnPnCtrHwTvl.DataType.IntData_u32);
		pMsgContext->resData[7] = CDC_GETHILOBYTE(LrnPnCtrHwTvl.DataType.IntData_u32);
		pMsgContext->resData[8] = CDC_GETLOHIBYTE(LrnPnCtrHwTvl.DataType.IntData_u32);
		pMsgContext->resData[9] = CDC_GETLOLOBYTE(LrnPnCtrHwTvl.DataType.IntData_u32);

	}
	else
	{
		 /* don't set ResponseCode = DCM_E_REQUESTOUTOFRANGE; here, because
		  * this will be done in the Cdc_Dispatcher
		  */
		 returnCode = E_NOT_OK;
	}

   return returnCode;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_PostProcessReadDataByIdentifier_User                   **
**                                                                            **
** DESCRIPTION   : Post handler of ReadDataByIdentifier (0x22) -              **
**                 user extension part                                        **
**                                                                            **
** PRECONDITIONS : this function will be called by                            **
**                      Cdc_PostProcessReadDataByIdentifier in the            **
**                      Cdc_XxxMandatory.c                                    **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint16 pendingDataIdentifier                               **
**                 Dcm_ConfirmationStatusType status                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic DataId exist        **
**                      E_NOT_OK: an user ext. diag. DataId don't exist       **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_CODE) Cdc_PostProcessReadDataByIdentifier_User
(
   CONST(uint16,AUTOMATIC) pendingDataIdentifier,
   Dcm_ConfirmationStatusType status
)
{
   VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

   /*
	* 'pMsgContext' can not be used here - it is released before call of
	* 'Rte_DcmConfirmation'
	*/

   /*
	* dispatch between the different DataIdentifier)
	* (the pendingDataIdentifier have been extracted in the Cdc_Dispatcher)
	*/
   switch (pendingDataIdentifier)
   {
	  default:
		 /* no post handler for 'pendingDataIdentifier' available             */
		 returnCode = E_NOT_OK;
		 break;
   }

   return returnCode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmWriteDataByIdentifier_User                          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 WriteDataByIdentifier (0x2E) - user extension part         **
**                                                                            **
** PRECONDITIONS : this function will be called by                            **
**                      Rte_DcmWriteDataByIdentifier in the Cdc_Dispatcher.c  **
**                                                                            **
** GLOBAL DATA   : pendingDiagContext.DataOrRoutineId with the actual         **
**                      DataID for this diagnostic serive                     **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic DataID exist        **
**                      E_NOT_OK: an user ext. diagnostic DataID don't exist  **
**                                                                            **
** REMARKS       : If a negative response code shall be set, use the parameter**
**                      ResponseCode. The DCM function Dcm_SetNegResponse()   **
**                      shall only be called in the Cdc_Dispatcher.c!         **
**                 Don't change the ResponseCode if no negative Response Code **
**                      shall be set - default is DCM_E_OK !!!                **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmWriteDataByIdentifier_User
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
   #if (CdcEnableAsyncRequestHandling == STD_OFF)
   ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
   #endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
)
{
	VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;
	VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrl;
	VAR(uint16, AUTOMATIC) PID;
	VAR(sint16, AUTOMATIC) HwOffset_Cnt_T_s16;
	VAR(s15p16_T, AUTOMATIC) HwOffset_Cnt_T_s15p16;
	VAR(float32, CDC_USER_VAR_NOINIT) CustHwOffsetSnsrCal_Deg_T_f32;
	VAR(float32, CDC_USER_VAR_NOINIT) EPSHwOffsetSnsrCal_Deg_T_f32;

	VAR(Dcm_MsgLenType, AUTOMATIC) AdjReqLength_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) HWAPDiagData_Cnt_T_u32;
	VAR(uint16, AUTOMATIC) ElctrcalHwIndex_Cnt_T_u16;

	CM_SetNegResp(0);
	PID = pendingDiagContext.DataOrRoutineId;
   /*
	* dispatch between the different DataIdentifiers
	* (the DataOrRoutineId have been extracted in the Cdc_Dispatcher)
	*/
	Dcm_GetSesCtrlType(&SesCtrl);
	if ( SesCtrl == NXTR_SESSION )
	{
		/* Diagnostic Service Access */

		/* Strip the PID length off of the request length */
		AdjReqLength_Cnt_T_u16 = pMsgContext->reqDataLen - (Dcm_MsgLenType)D_REQMSG_PID_OFFSET_CNT_U16;

		CM_DiagNegRespCode_u16 = DiagSrvcs_MainHandler(PID,
													 D_SRVCREQTYPEWRITE_CNT_U16,
													 (&pMsgContext->reqData[D_REQMSG_PID_OFFSET_CNT_U16]),
													 AdjReqLength_Cnt_T_u16,
													 (&(pMsgContext->resDataLen)));
		pMsgContext->resData = pMsgContext->reqData;
		/* End Service Access */

		if (CM_DiagNegRespCode_u16 != 0u)
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)CM_DiagNegRespCode_u16;
		}
		else
		{

			/* Add the PID information back into the response */
			pMsgContext->resData[0u] = CDC_GETHIBYTE(PID);
			pMsgContext->resData[1u] = CDC_GETLOBYTE(PID);
			pMsgContext->resDataLen = 2u;

			if (PID == D_NXTRSRLCOMSVCDFTPID_CNT_U16)
			{   /* Positive response to write SVCDFT BITFIELD */
				if (CDD_EOLSrlComSvcDft_Cnt_G_b32 != 0)
				{
					ActiveRID_Cnt_M_u16 = D_NXTRSRLCOMSVCDFTPID_CNT_U16;
				}
				else
				{
					if(ActiveRID_Cnt_M_u16 == D_NXTRSRLCOMSVCDFTPID_CNT_U16 )
					{
						ActiveRID_Cnt_M_u16 = 0U;
					}
				}
			}
		}
	}
	else if (PID == D_BMWEPSHWASENSORCALIBPID_CNT_U16) 		/* Turns Counter Vehicle Center Offset */
	{
		if (pMsgContext->reqDataLen == 4U)
		{
			HwOffset_Cnt_T_s16 = (sint16)(CDC_MAKE16BIT(pMsgContext->reqData[2], pMsgContext->reqData[3]));

			if ( Abs_f32_m(HwOffset_Cnt_T_s16) <= D_HWOFFSETWRITELIMIT_CNT_U16 )
			{
				HwOffset_Cnt_T_s15p16 = (sint32)HwOffset_Cnt_T_s16 * (sint32)D_HWOFFSETSCALE_HWDEGPCNT_U0P16;
				CustHwOffsetSnsrCal_Deg_T_f32 = FPM_FixedToFloat_m(HwOffset_Cnt_T_s15p16, s15p16_T);

				/* Convert VehCenterOffset from customer to EPS reference frame for processing */
				EPSHwOffsetSnsrCal_Deg_T_f32 = CustHwOffsetSnsrCal_Deg_T_f32 *	(float32)k_SComTrqPosPol_Cnt_s08;

				pMsgContext->resDataLen = 2U;

				CM_DiagNegRespCode_u16 = Call_AbsHwPos_Scom_SetCenterPosition(EPSHwOffsetSnsrCal_Deg_T_f32);

				if(CM_DiagNegRespCode_u16 == E_NOT_OK)
				{
					*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
				}
				else if(CM_DiagNegRespCode_u16 == D_EPSNRCREQUESTOUTOFRANGE_CNT_U08)
				{
					*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQUESTOUTOFRANGE_CNT_U08;
				}
				else
				{
					/* BMW required the HwOffset SnsrCalibration written to DID DB5A to be available to be read back after ignition cycle,
					 * however, this no longer appears to be the case due to teh current implemntation of the DB5A req service.  The data 
					 * stored in this blcok appears to be unused in the design and should be condered for removal from the design.
					 */

					/* Store VehCenterOffset in customer reference frame */
					Rte_AbsHwPos_EOLHwOffsetSnsrCal = CustHwOffsetSnsrCal_Deg_T_f32;
					NvM_WriteBlock(Rte_NvmBlock_AbsHwPos_EOLHwOffsetSnsrCal, NULL_PTR);
				}
			}
			else
			{
				*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQUESTOUTOFRANGE_CNT_U08;
			}
		}
		else
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
		}
	}
	else if ( PID == DIAG_DID_F190_VIN )		/* SWT VIN WRITE */
	{
		Swt_DcmWriteDataByIdentifierVin(pMsgContext);
	}
	else if ( PID == D_BMWEPSHWAPUPDATESRVC_CNT_U16)
	{
		if((pMsgContext->reqDataLen - 2u) == 4u) /* Remove 2 from the offset */
		{
			/* Note: This is the same service definition as CMS_BMW FEE3. If any changes are made, please update both files. */

        	/* Read in data from service */
        	HWAPDiagData_Cnt_T_u32  = (uint32)((uint32)(pMsgContext->reqData[2]) << 24u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(pMsgContext->reqData[3]) << 16u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(pMsgContext->reqData[4]) << 8u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(pMsgContext->reqData[5]));

        	/* Update HwDesc */
    		(void)memcpy( (uint8 *)&(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[D_HWAPSGBMNUM_CNT_U8]), (uint8 *)&(HWAPDiagData_Cnt_T_u32), D_HWAPSGBMNUMLEN_CNT_U8);
    		(void)NvM_WriteBlock(NVM_BLOCK_HWDESCDATA, NULL_PTR);
		}
		else
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
		}
	}
	#ifdef T1_ENABLE /* Only if Gliwa is enabled */
	else if ( PID == D_T1_RDBI_WDBI_CNT_U16)
	{
		/* Add the PID information back into the response */
			pMsgContext->resData[0u] = CDC_GETHIBYTE(PID);
			pMsgContext->resData[1u] = CDC_GETLOBYTE(PID);
			pMsgContext->resDataLen = 2u;

     		(void) GCP_RxHandler( (GCP_rxFrame_t const *)&pMsgContext->reqData[2], (GCP_dataLength_t)pMsgContext->reqDataLen - 2);

	}
    #endif
	else if (PID == D_ELTRCLHWINDEX_CNT_U16)
	{
		if(pMsgContext->reqDataLen == 4u)
		{
			if (Rte_CDDInterface9_NxtrMEC_Cnt_enum != 0u)
			{
				ElctrcalHwIndex_Cnt_T_u16  = (uint16)((uint16)pMsgContext->reqData[2] << 8u);
				ElctrcalHwIndex_Cnt_T_u16 |= (uint16)pMsgContext->reqData[3];

				Nvm_ElecHwIndex_Cnt_u16 = ElctrcalHwIndex_Cnt_T_u16;
				NvM_WriteBlock(NVM_BLOCK_ELEC_HW_INDEX, NULL_PTR);

			}
			else
			{
						*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCSERVICENOTSUPPORTED_CNT_U16;
			}
		}
		else
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
		}

	}
	else
	{
		/* don't set ResponseCode = DCM_E_REQUESTOUTOFRANGE; here, because
		  * this will be done in the Cdc_Dispatcher */
		  returnCode = E_NOT_OK;
	}

	return returnCode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmRoutineControl_User                                 **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) - user extension part                **
**                                                                            **
** PRECONDITIONS : this function will be called by Rte_DcmRoutineControl      **
**                      in the Cdc_Dispatcher.c                               **
**                                                                            **
** GLOBAL DATA   : pendingDiagContext.DataOrRoutineId with the actual         **
**                      SubFunction and RoutineID for this diagnostic serive  **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic RoutineID exist     **
**                      E_NOT_OK: an user ext. diag. RoutineID don't exist    **
**                                                                            **
** REMARKS       : If a negative response code shall be set, use the parameter**
**                      ResponseCode. The DCM function Dcm_SetNegResponse()   **
**                      shall only be called in the Cdc_Dispatcher.c!         **
**                 Don't change the ResponseCode if no negative Response Code **
**                      shall be set - default is DCM_E_OK !!!                **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmRoutineControl_User
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
   #if (CdcEnableAsyncRequestHandling == STD_OFF)
   ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
   #endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
)
{
	VAR(Std_ReturnType, AUTOMATIC)  returnCode = E_OK;
	VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrl;
	VAR(uint16, AUTOMATIC) RID;
	VAR(float32, AUTOMATIC) StrWhlAngle_HwDeg_T_f32;
	VAR(sint16, AUTOMATIC) StrWhlAngle_HwDeg_T_s15p0;

	VAR(uint16, AUTOMATIC) Frequency_Hz_T_u16;
	VAR(uint16, AUTOMATIC) Amplitude_HwDeg_T_u16;
	VAR(uint8, AUTOMATIC) Cycles_Cnt_T_u08;
	VAR(float32, AUTOMATIC) Amplitude_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) Frequency_Hz_T_f32;

	VAR(sint16, AUTOMATIC) TrgtHwPos_Cnt_T_s16;
	VAR(s15p16_T, AUTOMATIC) TrgtHwPos_HwDeg_T_s15p16;
	VAR(float32, AUTOMATIC) TrgtHwPos_HwDeg_T_f32;
	VAR(uint16, AUTOMATIC)TrgtHwVel_DegpS_T_u16p0;
	VAR(float32, AUTOMATIC) TrgtHwVel_DegpS_T_f32;
	VAR(uint32, AUTOMATIC) TrgtHwAccel_Cnt_T_u16p0;
	VAR(u16p16_T, AUTOMATIC) TrgtHwAccel_DegpSSqrd_T_u16p0;
	VAR(float32, AUTOMATIC) TrgtHwAccel_DegpSSqrd_T_f32;

	VAR(Dcm_MsgLenType, AUTOMATIC) AdjReqLength_Cnt_T_u16;

	VAR(uint8, AUTOMATIC) FuncRespCode_Cnt_T_u8;

	CM_SetNegResp(0);

	RID = CDC_MAKE16BIT(pMsgContext->reqData[1], pMsgContext->reqData[2]);
	/*
	 * dispatch between the different SubFunctions and RoutineIdentifiers
	 * (the SubFunction and DataOrRoutineId have been extracted in the Cdc_Dispatcher)
	 */
	Dcm_GetSesCtrlType(&SesCtrl);
	if ( SesCtrl== NXTR_SESSION )
	{
		/* Diagnostic Service Access */

		/* Strip the RID length off of the request length */
		AdjReqLength_Cnt_T_u16 = pMsgContext->reqDataLen - (Dcm_MsgLenType)D_REQMSG_RID_OFFSET_CNT_U16;

		CM_DiagNegRespCode_u16 = DiagSrvcs_MainHandler(RID,
											 (pendingDiagContext.SubFunction),
											 (&pMsgContext->reqData[D_REQMSG_RID_OFFSET_CNT_U16]),
											 AdjReqLength_Cnt_T_u16,
											 (&(pMsgContext->resDataLen)));
		pMsgContext->resData = pMsgContext->reqData; /* + (2*(sizeof(pMsgContext->reqData[0]))) */
		pMsgContext->resDataLen = pMsgContext->resDataLen + D_REQMSG_RID_OFFSET_CNT_U16;
		/* pMsgContext->resData[0u] = pMsgContext->reqData[0u];
		   pMsgContext->resData[1u] = CDC_GETHIBYTE(RID);
		   pMsgContext->resData[2u] = CDC_GETLOBYTE(RID); */
		/* End Service Access */

		if (CM_DiagNegRespCode_u16 != 0u)
		{
			*ResponseCode = (Dcm_NegativeResponseCodeType)CM_DiagNegRespCode_u16;
		}
	}
	else
	{
		switch (pendingDiagContext.SubFunction)
		{
			/******************************************************** START ROUTINE */
			case DIAG_UDS31_01_START_ROUTINE:
				switch (RID)
				{
					case D_BMWEPSINITPID_CNT_U16:  /* EPS Init (Go to Run) */
						EPSInitRoutineStatus_Cnt_M_u08 = D_RTNACTIVE_CNT_U08;
						CDD_CustEOLSrlComSvcDft_Cnt_G_b32 |= D_SVCDFTENGINEON_CNT_B32;
						ActiveRID_Cnt_M_u16 = D_BMWEPSINITPID_CNT_U16;
						pMsgContext->resDataLen = 3u;
						break;

					case D_BMWEPSPOSTRIMPID_CNT_U16:  /*EPS Steering Angle Sensor Calibration Reset*/
						if ( SesCtrl == GARAGE_SESSION )
						{
							if (Rte_SignlCondn_VehicleSpeed_Kph_f32 < k_CustPosTrimVehSpdThres_kph_f32)
							{
								/* Clear Center position */
								Call_AbsHwPos_Scom_ClearCenterPosition();

								/* Reset the rack to vehicle center offset */
								Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset();

								/*Reset EOT values*/
								NtWrapC_LrnEOT_Scom_ResetEOT();

								/* Clear CW/CCW EOT Items */
								if ((Rte_AbsHwPos_RevOffsetState_Cnt_u08== 0x4U) ||
									(Rte_AbsHwPos_RevOffsetState_Cnt_u08 == 0x0AU))
								{
									LnRkCr_Scom_ResetRckCntrMtrRev();
									NtWrapC_TurnsCounter_SCom_ResetTC();
								}

								if(Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc==FALSE)
								{
									NtWrapC_TurnsCounter_SCom_ResetTC();
								}

								pMsgContext->resDataLen = 3u;
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
						}
						break;

					case D_BMWEPSTCPICFLASHPID_CNT_U16:  /* Flash PIC with Turns Counter SW */
						if ( SesCtrl== GARAGE_SESSION )
						{
							if ( (Rte_SignlCondn_VehicleSpeed_Kph_f32 < k_CustPosTrimVehSpdThres_kph_f32) &&
								 (TCPicFlashRoutineStatus_Cnt_M_u08 == 0U) )
							{
								TCPicFlashRoutineStatus_Cnt_M_u08 = D_RTNACTIVE_CNT_U08;
								/* TODO: Set new TCPICProgramming NTC*/
								FuncRespCode_Cnt_T_u8 = TcFlshPrg_Scom_StartPrg();
								if(FuncRespCode_Cnt_T_u8 == D_EPSNRCCONDNOTCORRECT_CNT_U08)
								{
									*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
								}
								else
								{
									/* positive response */
									pMsgContext->resDataLen = 3u;
								}
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
						}
						break;

					case D_BMWEPSOSCTRAJPID_CNT_U16:  /* EPS COMMUTE - HwPos Oscillation Routine */
						if (pMsgContext->reqDataLen >= D_OSCTRAJPIDLENGTH_CNT_U08)
						{
							if (OSCTrajRoutineStatus_Cnt_M_enum != ACTIVE)
							{
								if ((ACTIVE == CheckRoutineConditions(FALSE, OSCTrajRoutineStatus_Cnt_M_enum)) && (SesCtrl == GARAGE_SESSION))
								{
									Frequency_Hz_T_u16 = (uint16)pMsgContext->reqData[3];
									Frequency_Hz_T_u16 = Frequency_Hz_T_u16 * D_OSCFREQSCALE_HZPCNT_U12P4;
									Frequency_Hz_T_f32 = FPM_FixedToFloat_m(Frequency_Hz_T_u16, u12p4_T);
									Frequency_Hz_M_f32 = Limit_m(Frequency_Hz_T_f32, D_OSCFREQLOLMT_HZ_F32, D_OSCFREQHILMT_HZ_F32);

									Amplitude_HwDeg_T_u16 = (uint16)pMsgContext->reqData[4];
									Amplitude_HwDeg_T_f32 = FPM_FixedToFloat_m(Amplitude_HwDeg_T_u16, u16p0_T);
									Amplitude_HwDeg_M_f32 = Limit_m(Amplitude_HwDeg_T_f32, D_AMPLITUDELOLMT_DEGS_F32, D_AMPLITUDEHILMT_DEGS_F32);

									Cycles_Cnt_T_u08 = pMsgContext->reqData[5];
									Cycles_Cnt_M_u08 = Limit_m(Cycles_Cnt_T_u08, D_OSCCYCLESLOLMT_ULS_U08, D_OSCCYCLESHILMT_ULS_U08);

									/* Save present position per the SER */
									RoutineHwPosStart_HwDeg_M_f32 = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;

									OSCTrajRoutineStatus_Cnt_M_enum = ACTIVE;
									GetSystemTime_mS_u32(&HandsONAbortTime_Cnt_M_u32);
									ActiveRID_Cnt_M_u16 = D_BMWEPSOSCTRAJPID_CNT_U16;
									pMsgContext->resDataLen = 3u;
								}
								else
								{
									*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
								}
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
						}

						break;

					case D_BMWEPSGENPOSTRAJPID_CNT_U16:  /* EPS PROCESS - Abs/Rel Generate/GoTo Position command service */
						if (pMsgContext->reqDataLen >= D_GENPOSTRAJPIDLENGTH_CNT_U08)
						{
							if ((pMsgContext->reqData[7] == D_ABSOLUTEPOS_CNT_U08) ||
								(pMsgContext->reqData[7] == D_RELATIVEPOS_CNT_U08))
							{
								if (GenPosTrajRoutineStatus_Cnt_M_enum != ACTIVE)
								{
									AbsPosTrajReq_Cnt_M_lgc = (boolean)(pMsgContext->reqData[7]);

									if ((ACTIVE == CheckRoutineConditions(AbsPosTrajReq_Cnt_M_lgc, GenPosTrajRoutineStatus_Cnt_M_enum)) && (SesCtrl == GARAGE_SESSION))
									{
										TrgtHwPos_Cnt_T_s16 = (sint16)(CDC_MAKE16BIT(pMsgContext->reqData[3], pMsgContext->reqData[4]));
										TrgtHwPos_Cnt_T_s16 = TrgtHwPos_Cnt_T_s16 * k_SComTrqPosPol_Cnt_s08;
										TrgtHwPos_HwDeg_T_s15p16 = (sint32)TrgtHwPos_Cnt_T_s16 * (sint32)D_TRGTHWPOSSCALE_HWDEGPCNT_U0P16;
										TrgtHwPos_HwDeg_T_f32 = FPM_FixedToFloat_m(TrgtHwPos_HwDeg_T_s15p16, s15p16_T);
										
										PosTrajTrgtHWPos_HwDeg_M_f32 = Limit_m(TrgtHwPos_HwDeg_T_f32,
																			   D_TRGTHWPOSLOLMT_HWDEGS_F32,
																			   D_TRGTHWPOSHILMT_HWDEGS_F32);
																			   
										if ((pMsgContext->reqData[7]) == 0U) /* If the service requested is relative */
										{
											PosTrajTrgtHWPos_HwDeg_M_f32 = Limit_m((Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 + TrgtHwPos_HwDeg_T_f32), -D_MAXHWPOSITION_HWDEG_F32, D_MAXHWPOSITION_HWDEG_F32);
										}

										TrgtHwVel_DegpS_T_u16p0 = (uint16)pMsgContext->reqData[5];
										TrgtHwVel_DegpS_T_f32 = FPM_FixedToFloat_m(TrgtHwVel_DegpS_T_u16p0, u16p0_T);
										TrgtHwVel_DegpS_M_f32 = Limit_m(TrgtHwVel_DegpS_T_f32,
																		D_TRGTHWVELLOLMT_DEGPS_F32,
																		D_TRGTHWVELHILMT_DEGPS_F32);

										TrgtHwAccel_Cnt_T_u16p0 = (uint16)pMsgContext->reqData[6];
										TrgtHwAccel_DegpSSqrd_T_u16p0 = TrgtHwAccel_Cnt_T_u16p0 * D_TRGTHWACCELSCALE_DEGPSSQRDPCNT_U16;
										TrgtHwAccel_DegpSSqrd_T_f32 = FPM_FixedToFloat_m(TrgtHwAccel_DegpSSqrd_T_u16p0, u16p0_T);
										TrgtHwAccel_DegpSSqrd_M_f32 = Limit_m(TrgtHwAccel_DegpSSqrd_T_f32,
																			  D_TRGTHWACCELLOLMT_DEGSPSSQRD_F32,
																			  D_TRGTHWACCELHILMT_DEGSPSSQRD_F32);

										GenPosTrajRoutineStatus_Cnt_M_enum = ACTIVE;
										GetSystemTime_mS_u32(&HandsONAbortTime_Cnt_M_u32);
										ActiveRID_Cnt_M_u16 = D_BMWEPSGENPOSTRAJPID_CNT_U16;
										pMsgContext->resDataLen = 3u;
									}
									else
									{
										*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
									}
								}
								else
								{
									*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
								}
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQUESTOUTOFRANGE_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
						}
						break;

					case D_BMWEPSLOCKTOLOCKPID_CNT_U16:  /* EPS FACTORY INITIALIZATION - Lock to Lock steering rouinte */
						if (pMsgContext->reqDataLen >= D_LOCKTOLOCKPIDLENGTH_CNT_U08)
						{
							if (Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc == FALSE)
							{
								if (LocktoLockRoutineStatus_Cnt_M_enum != ACTIVE)
								{
									if ((ACTIVE == CheckRoutineConditions(FALSE, LocktoLockRoutineStatus_Cnt_M_enum)) && (SesCtrl == GARAGE_SESSION))
									{
										/* The TargetAngle in request byte reqData[3] are unused for EPS per SER */
										TrgtHwVel_DegpS_T_u16p0 = (uint16)pMsgContext->reqData[4];
										TrgtHwVel_DegpS_T_f32 = FPM_FixedToFloat_m(TrgtHwVel_DegpS_T_u16p0, u16p0_T);
										TrgtHwVel_DegpS_M_f32 = Limit_m(TrgtHwVel_DegpS_T_f32,
																			D_LKTOLKTRGTHWVELLOLMT_DEGPS_F32,
																			D_LKTOLKTRGTHWVELHILMT_DEGPS_F32);

										TrgtHwAccel_Cnt_T_u16p0 = (uint16)pMsgContext->reqData[5];
										TrgtHwAccel_DegpSSqrd_T_u16p0 = TrgtHwAccel_Cnt_T_u16p0 * D_TRGTHWACCELSCALE_DEGPSSQRDPCNT_U16;
										TrgtHwAccel_DegpSSqrd_T_f32 = FPM_FixedToFloat_m(TrgtHwAccel_DegpSSqrd_T_u16p0, u16p0_T);
										TrgtHwAccel_DegpSSqrd_M_f32 = Limit_m(TrgtHwAccel_DegpSSqrd_T_f32,
																				  D_LKTOLKTRGTHWACCELLOLMT_DEGSPSSQRD_F32,
																				  D_LKTOLKTRGTHWACCELHILMT_DEGSPSSQRD_F32);

										LocktoLockRoutineStatus_Cnt_M_enum = ACTIVE;
										GetSystemTime_mS_u32(&HandsONAbortTime_Cnt_M_u32);
										ActiveRID_Cnt_M_u16 = D_BMWEPSLOCKTOLOCKPID_CNT_U16;
										pMsgContext->resDataLen = 3u;

										CDD_EOLSrlComSvcDft_Cnt_G_b32 |= 0x00000020U;

									}
									else
									{
										*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
									}
								}
								else
								{
									*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
								}
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCINVALIDFORMAT_CNT_U08;
						}
						break;

					case D_BMWEPSCLEARRACKCNTRPID_CNT_U16:
						if ( SesCtrl == GARAGE_SESSION )
						{
							if (Rte_SignlCondn_VehicleSpeed_Kph_f32 < k_CustPosTrimVehSpdThres_kph_f32)
							{
								if ((Rte_AbsHwPos_RevOffsetState_Cnt_u08 != 0x02U) &&
									(Rte_AbsHwPos_RevOffsetState_Cnt_u08 != 0x0EU))
								{
									*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
								}
								else
								{
									LnRkCr_Scom_ResetRckCntrMtrRev();
									LnRkCr_Scom_ResetRckCntrMtrDeg();
									Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset();

									pMsgContext->resDataLen = 3u;
								}
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
						}
						break;
					/* TODO: D_BMWEPSRESETSWTDATAPID_CNT_U16 service could be removed or modified once requirements are defined to allow
					 * SWT FAT to be run multiple times on the same controller. This service resets the SWT
					 * NVM RAM blocks back to default values to allow the test to be rerun after the SWT NVM
					 * blocks have updated with the status from a previous test run.
					 */

					case  D_BMWEPSPARTIALCLRRACKCNTRPID_CNT_U16:
						if ( SesCtrl == GARAGE_SESSION )
						{
							if (Rte_SignlCondn_VehicleSpeed_Kph_f32 < k_CustPosTrimVehSpdThres_kph_f32)
							{
									/* Clear Center position */
										Call_AbsHwPos_Scom_ClearCenterPosition();
									/* Clear rack to Vehicle center offset */
										Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset();
									/* Clear EOT values*/
										NtWrapC_LrnEOT_Scom_ResetEOT();
									/* Clear rack center motor revolution values */
										LnRkCr_Scom_ResetRckCntrMtrRev();
									/* Clear turns counter tracked position */
										NtWrapC_TurnsCounter_SCom_ResetTC();

									pMsgContext->resDataLen = 3u;
							}
							else
							{
								*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
							}
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
						}
						break;

					case  D_BMWEPSCLRPULLDRIFTPID_CNT_U16:
						if ( SesCtrl == GARAGE_SESSION )
						{
     						/* Clear short term pull comp, long term pull comp and pull comp command */
							(void)ActivePull_SCom_Reset();

							pMsgContext->resDataLen = 3u;
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCCONDNOTCORRECT_CNT_U08;
						}
						break;

					case D_BMWEPSRESETSWTDATAPID_CNT_U16:
						if ( SesCtrl == SWT_SESSION )
						{
							/* Load Swt_SWData and Swt_SWSigData RAM with ROM defaults */
							Swt_CommonCopy( Swt_SWData, Swt_SWDataDefault, sizeof( Swt_SWDataDefault ) );
							Swt_CommonCopy( Swt_SWSigData, Swt_SWSigDataDefault, sizeof( Swt_SWSigDataDefault ) );
							SWTStartupChk_Cnt_enum = Swt_PeriodicalChecks(0x30U, swid);
							
							/* Added for anomaly 5706. During the newest version of the FAT test, a reset is performed 
							   before the test begins, clearing the RAM of the default data. The fix is to write the EEPROM
							   to the default values */
							NvM_WriteBlock(NVM_SWT_SWSIG, NULL_PTR);
							NvM_WriteBlock(NVM_SWT_SW, NULL_PTR);

							pMsgContext->resDataLen = 3u;
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQUESTOUTOFRANGE_CNT_U08;
						}
						break;

					default:
						/* don't set ResponseCode = DCM_E_REQUESTOUTOFRANGE; here, because
						* this will be done in the Cdc_Dispatcher
						*/
					   returnCode = E_NOT_OK;
						break;
				} /* BMW RID Switch */
				break; /* DIAG_UDS31_01_START_ROUTINE*/

			/********************************************************* STOP ROUTINE */
			case DIAG_UDS31_02_STOP_ROUTINE:
				switch (pendingDiagContext.DataOrRoutineId)
				{
					case D_BMWEPSINITPID_CNT_U16:

					if (EPSInitRoutineStatus_Cnt_M_u08 != 0U)
					{
						EPSInitRoutineStatus_Cnt_M_u08 = D_RTNCANCELLED_CNT_U08;
						CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGINEON_CNT_B32;
						ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
					}
					else
					{
						*ResponseCode = D_EPSNRCREQSEQERROR_CNT_U08; /* request sequence error */
					}
					pMsgContext->resDataLen = 3u;

					break;

				case D_BMWEPSOSCTRAJPID_CNT_U16:  /* EPS COMMUTE - HwPos Oscillation Routine */

					if (OSCTrajRoutineStatus_Cnt_M_enum == ACTIVE)
					{
						CDD_OscEnableFlag_Cnt_G_lgc = FALSE;
						OSCTrajRoutineStatus_Cnt_M_enum = CANCELLED;
						CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
						ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
					}
					else
					{
						*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
					}
					pMsgContext->resDataLen = 3u;

					break;

				case D_BMWEPSLOCKTOLOCKPID_CNT_U16:  /* EPS FACTORY INITIALIZATION - Lock to Lock steering rouinte */

					if (LocktoLockRoutineStatus_Cnt_M_enum == ACTIVE)
					{
						CDD_LocktoLockEnableFlag_Cnt_G_lgc = FALSE;
						LocktoLockRoutineStatus_Cnt_M_enum = CANCELLED;
						CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
						ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
						/* Disable defeat Stall limit */
						 CDD_EOLSrlComSvcDft_Cnt_G_b32 &= 0xFFFFFFDFU;
					}
					else
					{
						*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
					}
					pMsgContext->resDataLen = 3u;

					break;

				default:
				   /* don't set ResponseCode = DCM_E_REQUESTOUTOFRANGE; here, because
					* this will be done in the Cdc_Dispatcher
					*/
				   returnCode = E_NOT_OK;
				   break;
			}  /* switch(pendingDiagContext.DataOrRoutineId)                     */
			break; /* DIAG_UDS31_02_STOP_ROUTINE */

			/******************************************************* REQUEST RESULT */
			case DIAG_UDS31_03_REQUEST_RESULT:
				switch (pendingDiagContext.DataOrRoutineId)
				{
					case D_BMWEPSINITPID_CNT_U16:
						if (EPSInitRoutineStatus_Cnt_M_u08 != 0U)
						{

							pMsgContext->reqData[3] = EPSInitRoutineStatus_Cnt_M_u08;

							StrWhlAngle_HwDeg_T_f32 = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
							StrWhlAngle_HwDeg_T_f32 = Limit_m(StrWhlAngle_HwDeg_T_f32,
														D_FINHWPOSLOLMT_HWDEG_F32, D_FINHWPOSHILMT_HWDEG_F32);

							StrWhlAngle_HwDeg_T_s15p0 = FPM_FloatToFixed_m(StrWhlAngle_HwDeg_T_f32, s15p0_T);


							pMsgContext->reqData[4] = CDC_GETHIBYTE(StrWhlAngle_HwDeg_T_s15p0);
							pMsgContext->reqData[5] = CDC_GETLOBYTE(StrWhlAngle_HwDeg_T_s15p0);

							pMsgContext->reqData[6] = SensorConditionChk(); /* Pinion Angle Sensor Condition */


							pMsgContext->resDataLen = 7u;
						}
						else
						{
							*ResponseCode = D_EPSNRCREQSEQERROR_CNT_U08; /* request sequence error */
							pMsgContext->resDataLen = 3u;
						}
						break;

					case D_BMWEPSTCPICFLASHPID_CNT_U16:
							pMsgContext->reqData[3] = TCPicFlashRoutineStatus_Cnt_M_u08;
							pMsgContext->reqData[4] = CDD_TcPrgStatus_Cnt_G_enum;
							/* TODO: Complete return of version and status info defined in SER
							      when we are able to read version info from PIC.
							pMsgContext->reqData[5] = PIC16 VersionInformation;
							pMsgContext->reqData[6] = TMS570 VersionInformation;
							pMsgContext->reqData[7] = Status to indicate if PIC or TMS version is older */

							pMsgContext->resDataLen = 5u;
						break;

					case D_BMWEPSOSCTRAJPID_CNT_U16:  /* EPS COMMUTE - HwPos Oscillation Routine */
						if (OSCTrajRoutineStatus_Cnt_M_enum != DEFAULT)
						{
							pMsgContext->reqData[3] = OSCTrajRoutineStatus_Cnt_M_enum;
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
						}
						pMsgContext->resDataLen = 4u;

						break;

					case D_BMWEPSGENPOSTRAJPID_CNT_U16:  /* EPS PROCESS - Abs/Rel Position command service */
						if (GenPosTrajRoutineStatus_Cnt_M_enum != DEFAULT)
						{
							pMsgContext->reqData[3] = GenPosTrajRoutineStatus_Cnt_M_enum;
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
						}
						pMsgContext->resDataLen = 4u;

						break;

					case D_BMWEPSLOCKTOLOCKPID_CNT_U16:  /* EPS FACTORY INITIALIZATION - Lock to Lock steering rouinte */
						if (LocktoLockRoutineStatus_Cnt_M_enum != DEFAULT)
						{
							pMsgContext->reqData[3] = LocktoLockRoutineStatus_Cnt_M_enum;
						}
						else
						{
							*ResponseCode = (Dcm_NegativeResponseCodeType)D_EPSNRCREQSEQERROR_CNT_U08;
						}
						pMsgContext->resDataLen = 4u;

						break;

					default:
					   /* don't set ResponseCode = DCM_E_REQUESTOUTOFRANGE; here, because
						* this will be done in the Cdc_Dispatcher
						*/
						returnCode = E_NOT_OK;
						break;
				}  /* switch(pendingDiagContext.DataOrRoutineId)                     */
				break; /*DIAG_UDS31_03_REQUEST_RESULT */

			/************************************************************************/
			default:
			 /* this case should never appear, because
			  * this will be handled in the Cdc_Dispatcher
			  */
				returnCode = E_NOT_OK;
			break;
		} /* SubFunction switch                                                    */

	}

   return returnCode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ConfirmationRoutineControl_User                        **
**                                                                            **
** DESCRIPTION   : Post handler of 'RoutineControl' (0x31) -                  **
**                 user extension part                                        **
**                                                                            **
** PRECONDITIONS : this function will be called by                            **
**                      Cdc_ConfirmationRoutineControl in the                 **
**                      Cdc_XxxMandatory.c                                    **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : const uint16 pendingRoutineIdentifier                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : Std_ReturnType with the returnCode                         **
**                      E_OK: an user extended diagnostic RoutineId exist     **
**                      E_NOT_OK: an user ext. diag. RoutineId don't exist    **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_CODE) Cdc_ConfirmationRoutineControl_User
(
   CONST(uint16,AUTOMATIC) pendingRoutineIdentifier
)
{
   VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

   /*
	* 'pMsgContext' can not be used here - it is released before call of
	* 'Rte_DcmConfirmation'
	*/

   /*
	* dispatch between the different RoutineIdentifier
	* (the pendingRoutineIdentifier have been extracted in the Cdc_Dispatcher)
	*/
   switch (pendingRoutineIdentifier)
   {
	  default:
		 /* no post handler for 'pendingDataIdentifier' available             */
		 returnCode = E_NOT_OK;
		 break;
   }

   return returnCode;
} /* Cdc_ConfirmationRoutineControl_User                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSesChgPermission_User                            **
**                                                                            **
** DESCRIPTION   : Check if the given session transition is allowed or your   **
**                 ECU is currently not able to perform it.                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeActive:                                       **
**                    - Contains the current session state which the state    **
**                      group will left.                                      **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - Contains the new session state in which the state     **
**                      group will be set.                                    **
**                    - Access type: read                                     **
**                 - dcmSessionChangePermission:                              **
**                    - set to DCM_E_OK to allow a session change             **
**                    - set to DCM_E_SESSION_NOT_ALLOWED (default) to reject  **
**                             the session change                             **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_SetNegResponse" may not be called.     **
**                 - The function "Dcm_ProcessingDone" may not be called.     **
**                 - Don't change dcmSessionChangePermission if a session     **
**                   change shall be rejected because it is                   **
**                   DCM_E_SESSION_NOT_ALLOWED per default !!!                **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmGetSesChgPermission_User
(
   CONST(uint8,AUTOMATIC)  SesCtrlTypeActive,
   CONST(uint8,AUTOMATIC)  SesCtrlTypeNew,
   CONSTP2VAR(Dcm_StatusType, AUTOMATIC, CDC_VAR_DCMDATA) dcmSessionChangePermission
)
{
   /* user extension                                                          */
	VAR(Dcm_StatusType, AUTOMATIC) TempStatus = DCM_E_SESSION_NOT_ALLOWED;
	VAR(boolean, AUTOMATIC) InvalidVehSpdChngAllowed_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgPgrsCntFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgCRCFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgDataRngFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgInvalidMsg_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdMsgDataOtherFlt_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) SrlComVehSpd_Kph_T_f32 = Rte_SrlComInput2_SrlComVehSpd_Kph_f32;
	VAR(QU_V_VEH_COG, RTE_VAR_INIT) SrlComVehSpdQual_Cnt_T_u08 = Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08;

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &VehSpdMsgMissing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_O, &VehSpdMsgCRCFlt_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_O, &VehSpdMsgPgrsCntFlt_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_P, &VehSpdMsgDataRngFlt_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_P, &VehSpdMsgInvalidMsg_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_P, &VehSpdMsgDataOtherFlt_Cnt_T_lgc);

	if( (SrlComVehSpdQual_Cnt_T_u08 == CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) ||
		(SrlComVehSpdQual_Cnt_T_u08 == CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) ||
		(SrlComVehSpdQual_Cnt_T_u08 == Cx8_Initialisierung) ||
		(VehSpdMsgMissing_Cnt_T_lgc == TRUE) ||
		(VehSpdMsgCRCFlt_Cnt_T_lgc == TRUE) ||
		(VehSpdMsgPgrsCntFlt_Cnt_T_lgc == TRUE) ||
		(VehSpdMsgDataRngFlt_Cnt_T_lgc == TRUE) ||
		(VehSpdMsgInvalidMsg_Cnt_T_lgc == TRUE) ||
		(VehSpdMsgDataOtherFlt_Cnt_T_lgc == TRUE) )
	{
		InvalidVehSpdChngAllowed_Cnt_T_lgc = TRUE;
	}
	else
	{
		InvalidVehSpdChngAllowed_Cnt_T_lgc = FALSE;
	}

	/* If the previous checks return OK, then check vehicle speed */
	if((*dcmSessionChangePermission) == DCM_E_OK)
	{
		switch(SesCtrlTypeNew)
		{
			case GARAGE_SESSION:
				if (SrlComVehSpd_Kph_T_f32 < k_GarageModeVehSpdThres_kph_f32)
				{
					TempStatus = DCM_E_OK;
				}
			break;
			case PROGRAMMING_SESSION: /* no break */
			case EXTENDED_DIAGNOSTIC_SESSION: /* no break */
				if((SrlComVehSpd_Kph_T_f32 <= D_SESSCHNGVEHSPDLMT_KPH_F32) || (InvalidVehSpdChngAllowed_Cnt_T_lgc == TRUE))
				{
					TempStatus = DCM_E_OK;
				}
			break;
			case CODING_SESSION:
				if(SrlComVehSpd_Kph_T_f32 <= D_SESSCHNGVEHSPDLMT_CODING_KPH_F32)
				{
					TempStatus = DCM_E_OK;
				}
			break;
			case NXTR_SESSION: /* no break */
			case DEFAULT_SESSION: /* no break */
			case SWT_SESSION: /* no break */
			default:
				/* Ignore change, since the session is not required to be checked */
				TempStatus = DCM_E_OK;
			break;
		}

		*dcmSessionChangePermission = TempStatus;
	}
	else
	{
		/* BAC checks returned NOK, additional checks are required to allow entry to Nxtr Session, Garage Mode,
		 * and session changes from those modes. BAC software does not consider these and will report NOK */

		switch(SesCtrlTypeNew)
		{
			case DEFAULT_SESSION:
				if((SesCtrlTypeActive == NXTR_SESSION) || (SesCtrlTypeActive == GARAGE_SESSION))
				{
					TempStatus = DCM_E_OK;
				}
			break;
			case GARAGE_SESSION:
				switch(SesCtrlTypeActive)
				{
					case EXTENDED_DIAGNOSTIC_SESSION: /* no break */
					case GARAGE_SESSION: /* no break */
					case DEFAULT_SESSION: /* no break */
					case NXTR_SESSION: /* no break */
						if (SrlComVehSpd_Kph_T_f32 < k_GarageModeVehSpdThres_kph_f32)
						{
							TempStatus = DCM_E_OK;
						}
					break;
					default:
						/* Session change not allowed */
						TempStatus = DCM_E_SESSION_NOT_ALLOWED;
					break;
				}
			break;
			case NXTR_SESSION:
				TempStatus = DCM_E_OK;
			break;
			default:
				/* Session change not allowed */
				TempStatus = DCM_E_SESSION_NOT_ALLOWED;
			break;
		}

		*dcmSessionChangePermission = TempStatus;
	}

}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSesChgPermissionProgramming_User                 **
**                                                                            **
** DESCRIPTION   : Check if the given session transition is allowed or your   **
**                 ECU is currently not able to perform it.                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeActive:                                       **
**                    - Contains the current session state which the state    **
**                      group will left.                                      **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - Contains the new session state in which the state     **
**                      group will be set.                                    **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : E_OK     - if the session change is allowed                **
**                 E_NOT_OK - if the session change is not allowed            **
**                                                                            **
** REMARKS       : - The function "Dcm_SetNegResponse" may not be called.     **
**                 - The function "Dcm_ProcessingDone" may not be called.     **
**                 - Don't change dcmSessionChangePermission if a session     **
**                   change shall be rejected because it is                   **
**                   DCM_E_SESSION_NOT_ALLOWED per default !!!                **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmGetSesChgPermissionProgramming_User
(
   CONST(uint8,AUTOMATIC)  SesCtrlTypeActive,
   CONST(uint8,AUTOMATIC)  SesCtrlTypeNew
)
{
   /* user extension                                                          */
   return E_OK;                   /* CR70962 */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmSesCtrlChangeIndication_User                        **
**                                                                            **
** DESCRIPTION   : Notification function for state change of the given        **
**                 state group, defined by CANdelaStudio.                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeOld:                                          **
**                    - The old state which will be left.                     **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - The new state which will be set.                      **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmSesCtrlChangeIndication_User
(
   CONST(uint8,AUTOMATIC) SesCtrlTypeOld,
   CONST(uint8,AUTOMATIC) SesCtrlTypeNew
)
{

   VAR(Dem_ReturnControlEventUpdateType, AUTOMATIC) result;
   /* user extension */
	EPS_DiagSessionChangeIndicator(SesCtrlTypeOld, SesCtrlTypeNew);

	if ( (DTCSettingOFF_Cnt_M_lgc == TRUE) &&
		 (SesCtrlTypeNew != SesCtrlTypeOld) )
	{
		result = Dem_EnableEventStatusUpdate
				  (DEM_DTC_GROUP_ALL_DTCS,
				   DEM_DTC_KIND_ALL_DTCS);

		DTCSettingOFF_Cnt_M_lgc = FALSE;
	}

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmSesCtrlChangeIndicationProgramming_User             **
**                                                                            **
** DESCRIPTION   : Notification function for state change of the given        **
**                 state group, defined by CANdelaStudio.                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - pendingSubFunction                                       **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmSesCtrlChangeIndicationProgramming_User
(
	CONST(uint8,AUTOMATIC) pendingSubFunction
)
{
	/* user extension                                                          */
	/* initiate an ECU reset                                                   */
	(void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, (uint8)0);      /* CR70962 */

	EcuM_KillAllRUNRequests();
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmIndication_User                                     **
**                                                                            **
** DESCRIPTION   : not available                                              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 uint8 SID                                                  **
**                 Dcm_StatusType returnValue: to reject a request            **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : The feature must be enabled in the GENy configuration      **
**                 Don't change the returnValue if no other request shall     **
**                 be rejected - default is DCM_E_OK !!!                      **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmIndication_User
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONST(uint8,AUTOMATIC)  SID,
   CONSTP2VAR(Dcm_StatusType, AUTOMATIC, CDC_VAR_DCMDATA) returnValue
)
{
	VAR(uint16, AUTOMATIC) ReqLength;
	VAR(uint8, AUTOMATIC) CurrentSession;
	VAR(Dem_ReturnControlEventUpdateType, AUTOMATIC) result;
	VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrl;
	VAR(uint16, AUTOMATIC) RequestID;
	VAR(uint16, AUTOMATIC) DataID;
	VAR(boolean, AUTOMATIC) RejectRequest = FALSE;
	VAR(uint16, AUTOMATIC) i;

	Dcm_GetSesCtrlType(&SesCtrl);
	CurrentSession = SesCtrl;

   /* user extension */
	if (ECUHardResetInProgress_Cnt_M_lgc == FALSE)
	{
		GetSystemTime_mS_u32(&EPSInitRoutineTime_Cnt_M_u32);

		if ( (SID == DIAG_UDS85_SERVICE_CONTROL_DTC_SETTING) &&
			 ((CurrentSession == EXTENDED_DIAGNOSTIC_SESSION) ||
			  (CurrentSession == NXTR_SESSION)) )
		{
			pendingDiagContext.SubFunction = pMsgContext->reqData[0];
			ReqLength = (uint16)pMsgContext->reqDataLen;

			if ( (pendingDiagContext.SubFunction == DIAG_UDS85_02_OFF) &&
				 (ReqLength == 1U) )
			{
				result = Dem_DisableEventStatusUpdate
				         (DEM_DTC_GROUP_ALL_DTCS,
						  DEM_DTC_KIND_ALL_DTCS);

				DTCSettingOFF_Cnt_M_lgc = TRUE;
			}
			else
			{
				if ( (pendingDiagContext.SubFunction == DIAG_UDS85_01_ON) &&
			 	 	 (ReqLength == 1U) )
				{
					result = Dem_EnableEventStatusUpdate
					         (DEM_DTC_GROUP_ALL_DTCS,
							  DEM_DTC_KIND_ALL_DTCS);

					DTCSettingOFF_Cnt_M_lgc = FALSE;
				}
			}
		}

		RequestID = CDC_MAKE16BIT(pMsgContext->reqData[1], pMsgContext->reqData[2]);
		DataID = CDC_MAKE16BIT(pMsgContext->reqData[0], pMsgContext->reqData[1]);

		if ( ((SID == DIAG_UDS31_SERVICE_ROUTINE_CONTROL) &&
			  (DIAG_UDS31_01_START_ROUTINE == pMsgContext->reqData[0])) ||
			 ((SID == DIAG_UDS2E_SERVICE_WRITE_DATA_BY_IDENTIFIER) &&
			  (D_NXTRSRLCOMSVCDFTPID_CNT_U16 == DataID)) )
		{
			if (D_NXTRSRLCOMSVCDFTPID_CNT_U16 == DataID)
			{
				RequestID = DataID;
			}

			for(i =0U; (i < D_ROUTINETABLESIZE_CNT_U08) && (RejectRequest == FALSE); i++)
			{
				if ( (RoutineIDTable_Cnt_M_u16[i] == ActiveRID_Cnt_M_u16) &&
					 (RequestID != ActiveRID_Cnt_M_u16) )
				{
					/* Reject Routine Start request - Conditions not correct */
					RejectRequest = TRUE;
					*returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
				}
			}
		}
	}
	else
	{	/* Reject all service requests if HardReset is in progress */
		*returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
	}
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmConfirmation_User (Service request header:0xff )    **
**                                                                            **
** DESCRIPTION   : Post handler for all diag services                         **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - idContext:                                               **
**                   - An identfier of the dcm instance.                      **
**                   - Access type: read                                      **
**                 - dcmRxPduId:                                              **
**                   - The PduId on which the request has been received.      **
**                   - Access type: read                                      **
**                 - status:                                                  **
**                   - Shows the status of the process accomplishment.        **
**                   - Can be:                                                **
**                     + DCM_RES_POS_OK                                       **
**                     + DCM_RES_POS_NOT_OK                                   **
**                     + DCM_RES_NEG_OK                                       **
**                     + DCM_RES_NEG_NOT_OK                                   **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : pendingDiagContext.SubFunction                             **
**                 pendingDiagContext.DataOrRoutineId                         **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                 - 'pMsgContext' can not be used here - it is released      **
**                   before call of 'Rte_DcmCondirmation'.                    **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmConfirmation_User
(
   Dcm_ConfirmationStatusType idContext,
   PduIdType dcmRxPduId,
   Dcm_StatusType status
)
{
   /* user extension                                                          */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSeed_User                                        **
**                                                                            **
** DESCRIPTION   : Request for a security level based seed sequence           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - SeedLen:                                                 **
**                   - The seed sequence length.                              **
**                   - Access type: read                                      **
**                 - Seed:                                                    **
**                   - Pointer to the seed sequence buffer.                   **
**                   - Access type: write                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Rte_DcmGetSeed_User
(
   uint8 SecurityLevel,
   uint8 SeedLen,
   CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
)
{
   /* user extension                                                          */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmCompareKey_User                                     **
**                                                                            **
** DESCRIPTION   : Request for a security level based key sequence            **
**                 comparision                                                **
**                                                                            **
** PRECONDITIONS : successful SeedRequest                                     **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - KeyLen:                                                  **
**                   - The key sequence length.                               **
**                   - Access type: read                                      **
**                 - Key:                                                     **
**                   - Pointer to the key sequence buffer.                    **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : DCM_E_OK : return value doesn't matter                     **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Dcm_StatusType, CDC_CODE) Rte_DcmCompareKey_User
(
   uint8 SecurityLevel,
   uint8 KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
)
{
   VAR(Dcm_StatusType, AUTOMATIC) retVal = DCM_E_COMPARE_KEY_FAILED;

   /* user extension                                                          */

   return retVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemGetDataValueByDataId_User                           **
**                                                                            **
** DESCRIPTION   : Mandatory callback functions for the DEM                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint16 DataID                                              **
**                 uint8 * DemDataValueByDataIdBuffer                         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : E_OK     - if the DID have been found in the user extension**
**                 E_NOT_OK - if the DID havn't been found in the user        **
**                            extension                                       **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetDataValueByDataId_User (uint16 DataID, P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) DemDataValueByDataIdBuffer)
{
	VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;
	VAR(uint8, AUTOMATIC) VehSpd_Kph_T_u8;
	VAR(uint8, AUTOMATIC) StDrvVeh_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) Vecu_Cnt_T_u8p0;
	VAR(sint16, AUTOMATIC) StrWhlAng_HwDeg_T_s16p0;
	VAR(sint16, AUTOMATIC) CmdMtrTrq_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) HwTrq_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) NTCParam_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) PSCMStatus_Cnt_T_u16;


	/* dispatch between the different DataIdentifiers */
	switch (DataID)
	{
		case D_SS_VEHSPD_CNT_U16:
			VehSpd_Kph_T_u8 = SS_VehSpd();
			DemDataValueByDataIdBuffer[0u] = VehSpd_Kph_T_u8;
		break;
		case D_SS_ST_DRV_VEH_CNT_U16:
			StDrvVeh_Cnt_T_u8 = SS_StDrvVeh();
			DemDataValueByDataIdBuffer[0u] = StDrvVeh_Cnt_T_u8;
		break;
		case D_SS_ECU_VOLTS_CNT_U16:
			Vecu_Cnt_T_u8p0 = SS_EcuVolts();
			DemDataValueByDataIdBuffer[0u] = Vecu_Cnt_T_u8p0;
		break;
		case D_SS_STRWHL_ANGLE_CNT_U16:
			StrWhlAng_HwDeg_T_s16p0 = SS_StrWhlAng();
			DemDataValueByDataIdBuffer[0u] = CDC_GETHIBYTE(StrWhlAng_HwDeg_T_s16p0);
			DemDataValueByDataIdBuffer[1u] = CDC_GETLOBYTE(StrWhlAng_HwDeg_T_s16p0);
		break;
		case D_SS_CMD_MTR_TRQ_CNT_U16:
			CmdMtrTrq_Cnt_T_s16 = SS_CmdMtrTrq();
			DemDataValueByDataIdBuffer[0u] = CDC_GETHIBYTE(CmdMtrTrq_Cnt_T_s16);
			DemDataValueByDataIdBuffer[1u] = CDC_GETLOBYTE(CmdMtrTrq_Cnt_T_s16);
		break;
		case D_SS_HW_TRQ_CNT_U16:
			HwTrq_Cnt_T_s16 = SS_HwTrq();
			DemDataValueByDataIdBuffer[0u] = CDC_GETHIBYTE(HwTrq_Cnt_T_s16);
			DemDataValueByDataIdBuffer[1u] = CDC_GETLOBYTE(HwTrq_Cnt_T_s16);
		break;
		case D_SS_NTC_NUM_CNT_U16:
			SS_NTCNum(&NTCNum_Cnt_T_u16, &NTCParam_Cnt_T_u8);
			DemDataValueByDataIdBuffer[0u] = CDC_GETHIBYTE(NTCNum_Cnt_T_u16);
			DemDataValueByDataIdBuffer[1u] = CDC_GETLOBYTE(NTCNum_Cnt_T_u16);
			DemDataValueByDataIdBuffer[2u] = NTCParam_Cnt_T_u8;
			DemDataValueByDataIdBuffer[3u] = 0U; /* Per ICR 4017 */
		break;
		case D_SS_PSCM_STATUS_CNT_U16:
			PSCMStatus_Cnt_T_u16 = SS_PSCMStatus();
			DemDataValueByDataIdBuffer[0u] = CDC_GETHIBYTE(PSCMStatus_Cnt_T_u16);
			DemDataValueByDataIdBuffer[1u] = CDC_GETLOBYTE(PSCMStatus_Cnt_T_u16);
		break;
		default:
			/* unknown DID */
			returnCode = E_NOT_OK;
		break;
   }  /* end of switch case */

   return returnCode;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemGetExtendedDataRecord_User                          **
**                                                                            **
** DESCRIPTION   : Mandatory callback functions for the DEM                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint8 ExtendedDataRecordNumber                             **
**                 uint8 * ExtendedDataRecord                                 **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : uint8 * ExtendedDataRecord                                 **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetExtendedDataRecord_User
(
   uint8 ExtendedDataRecordNumber,
   P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) ExtendedDataRecord
)
{
   VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

   /* user extension                                                          */

   return returnCode;
}


/*************************************************************************************
** FUNC-NAME     : CheckRoutineConditions                          			  		**
** DESCRIPTION   : Updates the routine status based on the start/stop conditions    **
**************************************************************************************/
STATIC FUNC(ROUTINECNTRLSTATE_Enum, CDC_USER_CODE) CheckRoutineConditions (boolean CheckHwPosAuth, ROUTINECNTRLSTATE_Enum CurrentRoutineStatus)
{
	VAR(Dcm_SesCtrlType, AUTOMATIC) CurrentSession;
	VAR(boolean, AUTOMATIC) HwPosCkFailed_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) OpStateEnableCkFailed_Cnt_T_lgc = FALSE;
	VAR(ROUTINECNTRLSTATE_Enum, AUTOMATIC) RoutineStatus_Cnt_T_Enum;
	VAR(boolean, AUTOMATIC) HandsOnDetected_Cnt_T_lgc;

	Dcm_GetSesCtrlType(&CurrentSession);

	if (CurrentRoutineStatus == ACTIVE)
	{
		HandsOnDetected_Cnt_T_lgc = HandsONAbort_Cnt_M_lgc;

		OpStateEnableCkFailed_Cnt_T_lgc = OperateStateCheck();
	}
	else
	{   /* Initialize routine start parameters */
		HandsOnDetected_Cnt_T_lgc = HandsONStart_Cnt_M_lgc;

		CDD_CustEOLSrlComSvcDft_Cnt_G_b32 |= D_SVCDFTENGANDTRQRMP_CNT_B32;
		GetSystemTime_mS_u32(&OpStateEnableWaitTime_Cnt_M_u32);
		OpStatePreStartCheck_Cnt_M_lgc = TRUE;
	}

	if ((TRUE == CheckHwPosAuth) &&
	    (Rte_AbsHwPos_HandwheelAuthority_Uls_f32 < D_MAXCONF_ULS_F32) )
	{
		HwPosCkFailed_Cnt_T_lgc = TRUE;
	}

	/* Update Routine Status based on EPS conditions */
	if (OpStateEnableCkFailed_Cnt_T_lgc == TRUE)
	{
		RoutineStatus_Cnt_T_Enum = ERROR;
	}
	else if (HwAngleOrHwVelCheckResult_Cnt_M_lgc == TRUE)
	{
		RoutineStatus_Cnt_T_Enum = HWANGORHWVEL;
	}
	else if ((Rte_SignlCondn_VehicleSpeed_Kph_f32 >= k_GarageModeVehSpdThres_kph_f32) ||
	         (Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc == TRUE)||
	         (Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc == TRUE))
	{
		RoutineStatus_Cnt_T_Enum = VEHSPD;
	}
	else if (HandsOnDetected_Cnt_T_lgc == TRUE)
	{
		RoutineStatus_Cnt_T_Enum = HANDSON;
	}
	else if (TRUE == HwPosCkFailed_Cnt_T_lgc)
	{
		RoutineStatus_Cnt_T_Enum = DEFAULT;
	}
	else
	{
		RoutineStatus_Cnt_T_Enum = ACTIVE;
	}

	if (RoutineStatus_Cnt_T_Enum != ACTIVE)
	{
		CDD_CustEOLSrlComSvcDft_Cnt_G_b32 &= ~D_SVCDFTENGANDTRQRMP_CNT_B32;
		ActiveRID_Cnt_M_u16 = D_INACTIVE_CNT_U08;
	}

	return 	RoutineStatus_Cnt_T_Enum;
}


/*************************************************************************************
** FUNC-NAME     : HandsOnDetection                          			  			**
** DESCRIPTION   : Check for torque input from Handwheel  							**
**************************************************************************************/
STATIC FUNC(boolean, CDC_USER_CODE) HandsOnDetection (ROUTINECNTRLSTATE_Enum RoutineStatus)
{
	VAR(boolean, AUTOMATIC) HandsOnDetected_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

	if (RoutineStatus == ACTIVE)
	{	/* Hands ON Abort Deactivation Conditions */
		HandsOnDetected_Cnt_T_lgc = FALSE;

		if ( (Abs_f32_m(Rte_HwTrq_AnaHwTorque_HwNm_f32)) >= k_CustSrvcHandsOnThres_HwNm_f32 )
		{
			DtrmnElapsedTime_mS_u32(HandsONAbortTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

			if (ElapsedTime_Cnt_T_u32 > k_CustSrvcHandsOnTime_mS_u16)
			{
				HandsOnDetected_Cnt_T_lgc = TRUE;
			}
		}
		else
		{
			GetSystemTime_mS_u32(&HandsONAbortTime_Cnt_M_u32);
		}

		HandsONAbort_Cnt_M_lgc = HandsOnDetected_Cnt_T_lgc;

	}
	else
	{	/* Hands OFF Start Activation Conditions */
		HandsOnDetected_Cnt_T_lgc = TRUE;

		if ( Abs_f32_m(Rte_HwTrq_AnaHwTorque_HwNm_f32) < k_CustSrvcHandsOnThres_HwNm_f32 )
		{
			DtrmnElapsedTime_mS_u32(HandsONStartTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

			if (ElapsedTime_Cnt_T_u32 > k_CustSrvcHandsOnTime_mS_u16)
			{
				HandsOnDetected_Cnt_T_lgc = FALSE;
			}
		}
		else
		{
			GetSystemTime_mS_u32(&HandsONStartTime_Cnt_M_u32);
		}

		HandsONStart_Cnt_M_lgc = HandsOnDetected_Cnt_T_lgc;
	}

	return HandsOnDetected_Cnt_T_lgc;
}

/*************************************************************************************
** FUNC-NAME     : HwAngleOrHwVelCheck                          			  			**
** DESCRIPTION   : Check for transition to operate state after EngOn defeat			**
**************************************************************************************/
STATIC FUNC(void, CDC_USER_CODE) HwAngleOrHwVelCheck(ROUTINECNTRLSTATE_Enum RoutineStatus)
{
	VAR(boolean, AUTOMATIC) CheckResult_Cnt_T_lgc = FALSE;
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

	if(RoutineStatus == ACTIVE)
	{
		if(ActiveRID_Cnt_M_u16 == D_BMWEPSOSCTRAJPID_CNT_U16)
		{
			/* HwAngle Check */
			if( (Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 > (k_CustSrvcHandwheelAngDelta_HwDeg_f32 + RoutineHwPosStart_HwDeg_M_f32)) ||
			    (Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 < (RoutineHwPosStart_HwDeg_M_f32 - k_CustSrvcHandwheelAngDelta_HwDeg_f32)) )
			{
				DtrmnElapsedTime_mS_u32(HandwheelAngAbortTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

				if(ElapsedTime_Cnt_T_u32 > k_CustSrvcHandwheelAngTime_mS_u16)
				{
					CheckResult_Cnt_T_lgc = TRUE;
				}
			}
			else
			{
				GetSystemTime_mS_u32(&HandwheelAngAbortTime_Cnt_M_u32);
			}
		}
		else
		{
			/* HwVel Check */
			if(Abs_f32_m(Rte_MtrVel_HandwheelVel_HwRadpS_f32) >= k_CustSrvcHandwheelVelThres_HwRadpS_f32)
			{
				DtrmnElapsedTime_mS_u32(HandwheelVelAbortTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

				if(ElapsedTime_Cnt_T_u32 > k_CustSrvcHandwheelVelTime_mS_u16)
				{
					CheckResult_Cnt_T_lgc = TRUE;
				}
			}
			else
			{
				GetSystemTime_mS_u32(&HandwheelVelAbortTime_Cnt_M_u32);
			}
		}
	}

	/* Update state variable */
	HwAngleOrHwVelCheckResult_Cnt_M_lgc = CheckResult_Cnt_T_lgc;

}

/*************************************************************************************
** FUNC-NAME     : OperateStateCheck                          			  			**
** DESCRIPTION   : Check for transition to operate state after EngOn defeat			**
**************************************************************************************/
STATIC FUNC(boolean, CDC_USER_CODE) OperateStateCheck (void)
{
	VAR(boolean, AUTOMATIC) OpStateEnableCkFailed_Cnt_T_lgc = FALSE;
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

	if (OpStatePreStartCheck_Cnt_M_lgc == FALSE)
	{
		if (RTE_MODE_StaMd_Mode_OPERATE != Rte_ModeMachine_StaMd_SystemState_Mode)
		{   /* STATE TRANSITION FROM OPERATE AFTER STARTING ROUTINE */
			OpStateEnableCkFailed_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		if (RTE_MODE_StaMd_Mode_OPERATE != Rte_ModeMachine_StaMd_SystemState_Mode)
		{
			DtrmnElapsedTime_mS_u32(OpStateEnableWaitTime_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

			if (ElapsedTime_Cnt_T_u32 > k_CustSrvcOpStateWaitTime_mS_u16)
			{
				OpStateEnableCkFailed_Cnt_T_lgc = TRUE;
			}
		}
		else
		{
			 switch (ActiveRID_Cnt_M_u16)
			 {
			 	 case D_BMWEPSOSCTRAJPID_CNT_U16:	/* EPS COMMUTE - HwPos Oscillation Routine */
					NtWrapC_OscTraj_SCom_SetInputParams (Amplitude_HwDeg_M_f32, Cycles_Cnt_M_u08, Frequency_Hz_M_f32);
					CDD_OscEnableFlag_Cnt_G_lgc = TRUE;
					OpStatePreStartCheck_Cnt_M_lgc = FALSE;
					break;

			 	 case D_BMWEPSGENPOSTRAJPID_CNT_U16:  /* EPS PROCESS - Abs/Rel Generate/GoTo Position command service */
			 		NtWrapC_GenPosTraj_SCom_SetInputParam(PosTrajTrgtHWPos_HwDeg_M_f32, TrgtHwVel_DegpS_M_f32, TrgtHwAccel_DegpSSqrd_M_f32);
			 		CDD_GenPosTrajEnableFlag_Cnt_G_lgc = TRUE;
			 		GetSystemTime_mS_u32(&PosTrajHoldTime_Cnt_M_u32);
			 		OpStatePreStartCheck_Cnt_M_lgc = FALSE;
			 		break;

			 	 case D_BMWEPSLOCKTOLOCKPID_CNT_U16:  /* EPS FACTORY INITIALIZATION - Lock to Lock steering rouinte */
			 		NtWrapC_LktoLkStr_SCom_SetInputParam(TrgtHwVel_DegpS_M_f32, TrgtHwAccel_DegpSSqrd_M_f32);
			 		CDD_LocktoLockEnableFlag_Cnt_G_lgc = TRUE;
			 		OpStatePreStartCheck_Cnt_M_lgc = FALSE;
					break;

			 	 default:
			 		 /* should never get here */
			        break;
			 }

		}
	}

	return OpStateEnableCkFailed_Cnt_T_lgc;
}

/*************************************************************************************
** FUNC-NAME     : SensorConditionChk                          			  			**
** DESCRIPTION   : Returns the Pinion Angle Sensor Condition. Used in RIDs 0xAB6C	**
** 				   and 0xDB57														**
**************************************************************************************/
STATIC FUNC(uint8, CDC_USER_CODE) SensorConditionChk(void)
{
	VAR(uint8, AUTOMATIC) SensorCondition_Cnt_T_u08;

	if(Rte_AbsHwPos_Trim.LTVehCntrComplete == TRUE)
	{
		if((Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc == TRUE) &&
		   (Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum == TCV_VALID))
		{
			SensorCondition_Cnt_T_u08 = RackVehCntrFound_Cnt_u08; /* Rack & Vehicle Center Found */
		}
		else
		{
			SensorCondition_Cnt_T_u08 = VehCntrFound_Cnt_u08;     /* Vehicle Center Found */
		}
	}
	else
	{
		if(Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc == TRUE)
		{
			SensorCondition_Cnt_T_u08 = RackCntrFound_Cnt_u08;	  /* Rack Center Found */
		}
		else
		{
			SensorCondition_Cnt_T_u08 = CntrNotFound_Cnt_u08;     /* Rack & Vehicle Center Not Found */
		}
	}

	return SensorCondition_Cnt_T_u08;
}


/*************************************************************************************
** SNAP SHOT DATA FUNCTIONS															**
**************************************************************************************/

/*************************************************************************************
** FUNC-NAME     : SS_VehSpd                          			  					**
** DESCRIPTION   : Returns the vehicle speed in a single byte (0 to 255 range)		**
**************************************************************************************/
STATIC FUNC(uint8, CDC_USER_CODE) SS_VehSpd(void)
{
	VAR(uint8, AUTOMATIC) VehSpd_Kph_T_u8;
	VAR(uint16, AUTOMATIC) VehSpdTmp_Kph_T_u16p0;

	/* Anomaly 3788, replaced signal conditioning vehicle speed output, with the FlexRay value that is updated
	 * only on a valid frame, otherwise last known value is used */
	VehSpdTmp_Kph_T_u16p0 = FPM_FloatToFixed_m(Rte_SrlComInput2_FRVldVehSpd_Kph_f32, u16p0_T);
	if(VehSpdTmp_Kph_T_u16p0 >= 255u)
	{
		VehSpd_Kph_T_u8 = 255u;
	}
	else
	{
		VehSpd_Kph_T_u8 = (uint8)(VehSpdTmp_Kph_T_u16p0 & 0xFFU);
	}

	return VehSpd_Kph_T_u8;
}

/*************************************************************************************
** FUNC-NAME     : SS_StDrvVeh                         			  					**
** DESCRIPTION   : Returns value of ST_DRV_VEH recieved over FlexRay				**
**************************************************************************************/
STATIC FUNC(uint8, CDC_USER_CODE) SS_StDrvVeh(void)
{
	VAR(uint8, AUTOMATIC) StDrvVeh_Cnt_T_u8;
	/* For F40_UKL_MCV, ST_DRV_VEH message no longer exists. So hard coded to 0 */
	StDrvVeh_Cnt_T_u8 = 0u;

	return StDrvVeh_Cnt_T_u8;
}

/*************************************************************************************
** FUNC-NAME     : SS_EcuVolts                         			  					**
** DESCRIPTION   : Returns measured battery voltage at the PSCM						**
** 				 : Resolution = 0.08 per SER, range = 0 to 20.4						**
**************************************************************************************/
STATIC FUNC(uint8, CDC_USER_CODE) SS_EcuVolts(void)
{
	VAR(uint8, AUTOMATIC) Vecu_Cnt_T_u8p0;
	VAR(float32, AUTOMATIC) ScaledVecu_Cnt_T_f32;

	if(Rte_BatteryVoltage_Vecu_Volt_f32 >= 20.4F)
	{
		ScaledVecu_Cnt_T_f32 = 255.0F;
	}
	else
	{
		ScaledVecu_Cnt_T_f32 = Rte_BatteryVoltage_Vecu_Volt_f32 * 12.5f; /* 12.5 = 1 / 0.08 */
	}

	Vecu_Cnt_T_u8p0 = (uint8)ScaledVecu_Cnt_T_f32;

	return Vecu_Cnt_T_u8p0;
}

/*************************************************************************************
** FUNC-NAME     : SS_StrWhlAng                       			  					**
** DESCRIPTION   : Returns steering wheel angle sent on FlexRay 					**
** 				 : Resolution = 1 cnt per HwDeg										**
**************************************************************************************/
STATIC FUNC(sint16, CDC_USER_CODE) SS_StrWhlAng(void)
{
	VAR(sint16, AUTOMATIC) StrWhlAng_HwDeg_T_s16p0;
	VAR(float32, AUTOMATIC) StrWhlAngle_HwDeg_T_f32;

	StrWhlAngle_HwDeg_T_f32 = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
	StrWhlAng_HwDeg_T_s16p0 = FPM_FloatToFixed_m(StrWhlAngle_HwDeg_T_f32, s15p0_T);

	return StrWhlAng_HwDeg_T_s16p0;
}

/*************************************************************************************
** FUNC-NAME     : SS_CmdMtrTrq                       			  					**
** DESCRIPTION   : Returns command motor torque					 					**
** 				 : Resolution = 0.1 per cnt	 										**
** 				 : Note - precision is not a typical value, so s16 is used			**
**************************************************************************************/
STATIC FUNC(sint16, CDC_USER_CODE) SS_CmdMtrTrq(void)
{
	VAR(sint16, AUTOMATIC) CmdMtrTrq_Cnt_T_s16;
	VAR(float32, AUTOMATIC) ScaledCmdMtrTrq_Cnt_T_f32;

	ScaledCmdMtrTrq_Cnt_T_f32 = Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32 * 10.0F; /* 10 = 1 / 0.1 */
	CmdMtrTrq_Cnt_T_s16 = (sint16)ScaledCmdMtrTrq_Cnt_T_f32;

	return CmdMtrTrq_Cnt_T_s16;
}

/*************************************************************************************
** FUNC-NAME     : SS_HwTrq                     	  			  					**
** DESCRIPTION   : Returns handwheel torque						 					**
** 				 : Resolution = 0.01 per cnt	 									**
** 				 : Note - precision is not a typical value, so s16 is used			**
**************************************************************************************/
STATIC FUNC(sint16, CDC_USER_CODE) SS_HwTrq(void)
{
	VAR(sint16, AUTOMATIC) HwTrq_Cnt_T_s16;
	VAR(float32, AUTOMATIC) ScaledHwTrq_Cnt_T_f32;

	ScaledHwTrq_Cnt_T_f32 = Rte_HwTrq_AnaHwTorque_HwNm_f32 * 100.0F; /* 100 = 1 / 0.01 */
	HwTrq_Cnt_T_s16 = (sint16)ScaledHwTrq_Cnt_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;

	return HwTrq_Cnt_T_s16;
}

/*************************************************************************************
** FUNC-NAME     : SS_NTCNum                     	  			  					**
** DESCRIPTION   : Returns the NTC number and NTC param byte in the stack			**
**************************************************************************************/

STATIC FUNC(void, CDC_USER_CODE) SS_NTCNum(	P2VAR(NTCNumber, AUTOMATIC, AUTOMATIC) NTCNum_Cnt_Ptr_u16,
												P2VAR(uint8, AUTOMATIC, AUTOMATIC) ParamData_Ptr_u8
											)
{
	VAR(NTCNumber, AUTOMATIC) NTCIndex_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) ParamData_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) Status_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) AgingCounter_Cnt_T_u8;

	*NTCNum_Cnt_Ptr_u16 = 0U;
	*ParamData_Ptr_u8 = 0U;

	for(NTCIndex_Cnt_T_u16 = 1U;NTCIndex_Cnt_T_u16<TableSize_m(k_FltRspTbl_Cnt_str);NTCIndex_Cnt_T_u16++)
	{
		/* Corresponding CTCs */
		if (CDD_DemIdSnapshot_Cnt_G_u8 == k_FltRspTbl_Cnt_str[NTCIndex_Cnt_T_u16].DEMEventID)
		{
			DiagMgr_SCom_GetNTCInfo( NTCIndex_Cnt_T_u16, &ParamData_Cnt_T_u8, &Status_Cnt_T_u8, &AgingCounter_Cnt_T_u8);
			if ( D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8 == (D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8 & Status_Cnt_T_u8))
			{
				/* Update the value used in the Debug Frame with last NTC recorded to snapshot. SER 11C (3/Mar/13) still requires
				 * the first NTC on the fault statck, instead giving them the last NTC recorded to snapshot. */
				CDD_FirstActvNTC_Cnt_G_u16 = NTCIndex_Cnt_T_u16;

				*NTCNum_Cnt_Ptr_u16 = NTCIndex_Cnt_T_u16;
				*ParamData_Ptr_u8 = ParamData_Cnt_T_u8;
				break; /*return */
			}
		}
	}
}

/*************************************************************************************
** FUNC-NAME     : SS_PSCMStatus                     			  					**
** DESCRIPTION   : Returns various status bits on the status of the PSCM			**
**************************************************************************************/
STATIC FUNC(uint16, CDC_USER_CODE) SS_PSCMStatus(void)
{
	VAR(uint16, AUTOMATIC) PSCMStatus_Cnt_T_u16 = 0u;
	VAR(uint8, AUTOMATIC) TempValue_Cnt_T_u8;
	VAR(boolean, AUTOMATIC) GlobalUnderTest_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) GlobalOverTest_Cnt_T_lgc = FALSE;
	VAR(CTR_ERRM_BN_U, AUTOMATIC) CtrErrm_Cnt_T_u08;

	/* System State */
	switch(Rte_ModeMachine_StaMd_SystemState_Mode)
	{
		case RTE_MODE_StaMd_Mode_DISABLE:
		case RTE_MODE_StaMd_Mode_OFF:
		case RTE_MODE_StaMd_Mode_OPERATE:
		case RTE_MODE_StaMd_Mode_WARMINIT:
		case RTE_TRANSITION_StaMd_Mode:
			TempValue_Cnt_T_u8 = Rte_ModeMachine_StaMd_SystemState_Mode;
		break;
		default:
			TempValue_Cnt_T_u8 = 7U; /* Max value for invalid state */
		break;
	}
	PSCMStatus_Cnt_T_u16 |= (TempValue_Cnt_T_u8 << 13u);

	/* Park Assist */
	/* For F40_UKL_MCV, Park Assist no longer exists */
	PSCMStatus_Cnt_T_u16 |= (0u << 12u);


	/* Torque Overlay */
	if(RTE_CONST_Cx21_Schnittstelle_aktiv == Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08)
	{
		PSCMStatus_Cnt_T_u16 |= (1u << 11u);
	}


	/* Global Under / Over Voltage */
	/* The following implementation does not strictly match the implementation required by SER EPS24102912 Rev 010A Sec. 3.1.4.2.6.2.1.1.3.43 DID 0x500C -PSCM Status
	 * NTC 0xBA and 0xBB are not implemented in the sw design.  Since they are customer specific and informational only, they are reported directly to the customer Dem.
	 * Therefore, rather the status of the Dem events must be checked to achieve the SER required functionality  */
	(void)Dem_GetEventFailed(PWRSPLY_GLOBAL_UNDVOLT, &GlobalUnderTest_Cnt_T_lgc);
	(void)Dem_GetEventFailed(PWRSPLY_GLOBAL_SURGE, &GlobalOverTest_Cnt_T_lgc);
	if((GlobalUnderTest_Cnt_T_lgc == TRUE) || (GlobalOverTest_Cnt_T_lgc == TRUE))
	{
		PSCMStatus_Cnt_T_u16 |= (1u << 10u);
	}

	/* Position Confidence */
	if (Abs_f32_m(Rte_AbsHwPos_HandwheelAuthority_Uls_f32 - D_ONE_ULS_F32) > FLT_EPSILON)
	{
		PSCMStatus_Cnt_T_u16 |= (1u << 9u);
	}

	/* Cold Start */
	/* For F40_UKL_MCV, ST_VEH_CON no longer exists */
	PSCMStatus_Cnt_T_u16 |= (0u << 8u);

	/* Global Voltage Message Status */
	(void)Com_ReceiveSignal(Com_CTR_ERRM_BN_U__ERRM_BN_U, (&CtrErrm_Cnt_T_u08));
	if( (Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar == CtrErrm_Cnt_T_u08) ||
		(Cx3E_Funktion_meldet_Fehler == CtrErrm_Cnt_T_u08) ||
		(Cx3F_Signal_ungueltig == CtrErrm_Cnt_T_u08) )
	{
		PSCMStatus_Cnt_T_u16 |= (1u << 7u);
	}

	/* bits 6 to 0 are reserved */

	return PSCMStatus_Cnt_T_u16;
}

/*** End of file **************************************************************/

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              				 					SCR #
-------   -------  --------  -----------------------------------  			   	  			  	  	----------
12/14/10   1.0      BDO		    Initial version - Nxtr Diagnositc		   						CR3728
								Services. Read SW part no.
12/16/10   2.0      BDO		    Added Write, Routine and I/O Ctrl 			   						CR3639, 3644, 3731
12/16/10   3.0      BDO  		Changed session check to allow Nxtr
								only.
12/16/10   4.0      BDO 		Removed Rev. 3.0 change above to allow
								default session access to Nxtr services
12/16/10   5.0      BDO 		Changed session check to allow Nxtr only
02/11/11   6.0      BDO 		Added BMW Jobs DID DB57 and RID 0xAB6C
02/24/11   7.0      LWW 		Passed sessions to session change function
03/16/11   8.0      BDO  		Added Garage Mode session
03/26/11   9.0      BDO         Anomaly 2010-updated Rte_DcmIndication_User()  						CR3959
03/30/11   10.0     BDO         Remove Transport mode conditions BMW RID 0xAB6C 					CR3924
03/30/11   11.0     BDO         Add BMW Job DID DB8B												CR3968
03/30/11   12.0     BDO         Add BMW Job DID DB56												CR3969
03/30/11   13.0     BDO         Add BMW Job DID DB99												CR3970
03/30/11   14.0     BDO         Change res and pol of StrWhlAngle in RID 0xAB6C 					CR3924
03/31/11   15.0     BDO         Update ECU reset check in Rte_DcmIndication_User()  				CR3959
04/03/11   16.0     BDO  		Added CDCUser_Init() and CDCUser_Task() to support RID AB6C.
04/13/11   17.0     BDO 		Correct failure for DM test 2.2.4 - anomaly 2027
05/16/11   18.0     BDO			Add RID 0xAB69 and DID 0xDB59 										CR4711
05/16/11   19.0     BDO			Correct Data Bytes and Polarity in DID 0xDB59 						CR4711
18/01/11   20       JJW         BAC3.0 integration changes made by Vector
08/11/11   21.0     BDO     	Updates for TurnsCounter changes
09/08/11   23.0     BDO      	Set pMsgContext->resDataLen to 2 for write DID 0xDB5A
10/11/11   24.0     BDO      	Add PIC Turns Counter flash routine
10/29/11   26       LWW         Anomaly fixes
10/29/11   27       LWW         Swap RACKVEHCNTRFOUND and RACKCNTRFOUND in DID 0xDB57
12/01/11   28		BDO		    Add NVM write to 0xDB5A and RTN 0xAB69, Add 0xDB5A read, QAC fix.		CR4716
12/03/11   28.1.1	JJW         Change to use Rte_Call_NxtrDiagMgr_GetNTCFailed
12/06/11   28.1.2   JJW         Renamed HwTrq to Rte_HwTrq_AnaHwTorque_HwNm_f32
12/12/11   28.1.3   JJW         Removed the QAX current global signal from the Average Current PID due to
								 to removal of the signal during integration of CurrentEst SF99_002.0 and
								 the lack of an updated SER to specify the appropriate signal to use.
12/13/11   28.1.4   OKT         Updated NTC hard-coded values to NTC_Num constants
12/22/11   28.1.5	BDO      	Change to use Rte_Call_NxtrDiagMgr_GetNTCFailed
02/08/12   29.0     BDO			Updates for BMW Factory Routines 0xAB71, 0xAB72, 0xAB56
02/29/12   30.0     BDO			Update req length and scaling for BMW Factory Routines 0xAB71, 0xAB72, 0xAB56 - CR5007
02/29/12   31.0     BDO			Correct req byte access of Absolute A parameter for Routine 0xAB72 - CR5007
03/14/12   32       JJW         Renamed TurnsCounter_SCom_ResetTC for CBD FDD20C_003.3 integration
03/22/12   33       BDO         Add GarageMode condition and FinalHwPos_Scom_ResetEOT() to routine 0xAB69 	 CR5119, CR5127
04/13/12   36       BDO         Transition to Operate (defeat EngOn) for 0xAB71, 0xAB72, 0xAB56 - Anomaly 3051
04/25/12   37       BDO         BAC 3.0 integration anomaly 3179 and 3200, Update DID DB57 per SER requirement anomaly 3156
06/01/12   38       BDO         Update ECUReset handling to support BAC 3.0 integration changes - anomaly 3281
06/20/12   41       BDO         Updates to DID/RIDs DB57, AB6C, AB69 and AB71 for anomaly 2749, FDDs 5C, 20C and SF-11 changes - CR5712, CR5685, CR5700
06/20/12   43       KJS         Updates for snapshot data	CR5931
08/18/12   44       BDO         Updates for Learn Rack Center FDD 39 and anomaly 3188
08/21/12   46		KJS			Updates for 0x22 service for eading DIDs.
08/29/12   47       BDO         Updates to read/write of DID DB5A - anomalies 3495, 3691
08/31/12   48       BDO         Update write of DID DB5A - anomalies 3736
09/13/12   49		KJS			Added global for first NTC set in snap shot function for debug frame.
09/13/12   50		KJS			Anomaly 3752 correction.
09/11/12   51		KJS			Signal name change for new Assist Sum and Limit Comp.
09/29/12   52       BDO         SWT updates - anomaly 3782
		   52.1.1   JJW         DiagMgr FDD37B_001.16 integration
		   53		KJS			Anomaly correction for 3181
		   54		KJS			Anomaly correction 3788 and 3751. See code for details.
		   55		KJS			Added support for DID F18A.
		   56		KJS			Removed SWT check in INIT..Anomaly 3891 correction				CR6542
10/16/12   57		KJS			Merged of i350 and i390 paths. Revs starting at 52.1.1 start the merge.
10/22/12   58	    JJW			MtrPosMech moved to CDDInterface10, name updated accordingly.
10/26/12   59       BDO         Rename vars Rte_SrlComInput2_FRVldVehSpd_Kph_f32 and Rte_SrlComInput2_SrlComVehSpd_Kph_f32 for new SrlComInput2
10/26/12   60       JJW         NonTrusted and Trussted Scom function calls added.  Removed Suspend/Resume interrupts to support
								use of NonTrusted funciton calls whihc require interrupts to be enabled per the Os design.
11/03/12   61       JJW         SID 0x11 Ecu Reset processing in Nxtr Session anomaly correction.
11/08/12   62       JJW         Replacement of Invalid Ntc get event failed with Dem Api for global over voltage and undervoltage status.
12/06/12   63       KJS         Updates to RID routines for CMS servives that return data.
01/10/13   65		KJS			Anomaly 4207 correction. Also removed unused variables causing warnings, and corrected the pointer type used in the reset CM service.
02/07/13   67		KJS			Anomaly 3828 correction for service 0xAB71
02/07/13   69		DD			Change request 7247 Update DID 0x5030 to add NTC Param byte and grab NTC number
02/19/13   70		KJS			Anomaly 7324 correction for SS_StrWhlAng
03/03/13   71		KJS			SER updates, corrected debug frame reading of NTC.
03/15/13   72		KJS			Updates for FDD 05C Rev 8 RID 0xAB69 added ResetTC
03/21/13   74		KJS			Removed snapshot DID 0x5030, and replaced it with the 4-byte variant of 0x5032
03/26/13   75		KJS			Removed vehicle speed checks for short term fix for anomaly 4724
04/11/13   76		KJS			Added vehicle speed checks for anomaly 4581. FAT tests verified this correction works.
04/14/13   77		KJS			Anomaly 4796 correction. 
05/22/13   83		KJS			Updates for anoamly 5033 correction.
05/31/13   84       NRAR        Update for Anomaly 5029 correction
05/31/13   85       NRAR        Added support for new SER requirements for service 0xAB56
09/25/13   87       KJS         Corrected anoamly 5706
01/24/14   91       KJS         Corrected anomaly 6246
06/04/14   92       KJS         Added support for Edch data read service
09/29/14   93       KJS         Memmap statements added around global variables for *.data section cleanup
11/07/14   94       KJS         Corrected anomaly 7594
12/09/14   95       AS          GliwaT1 component integration
03/25/15   96       ABS         EA3#259 Taigene/Letrika Motor Service
04/14/15   97       ABS         EA3#726 Added support for bits 8 and 7 for DID 500C
08/13/15   98		ABS			EA3#2390 Electrical HW Index Service and Stored Rack travel and center data
08/21/15   101      ABS			EA3#2644 Errors in 0xDFDD
08/27/15   102      ABS			EA3#2783 Updated the condition to evaluate stored rack travel for service 0xDFDD
08/15/15   103      ABS			EA3#2821 Updated DID 0xDB99 to report a Sensor condition of "NOT OK" when a Torque fault is set.
02/09/16   104      ABS			Updates for Srlcom Changes - SCIR Rev 001A
09/09/16   105		ABS			Added new service for Clear Pull Comp
04/28/17   106      ABS 		Anomaly correction for Session Entry criteria								EA3#15305
******************************************************************************/
