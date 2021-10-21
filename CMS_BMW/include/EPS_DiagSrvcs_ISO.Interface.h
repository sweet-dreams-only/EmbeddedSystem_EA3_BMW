/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Interface.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains the configurations for the ISO services. It should be
* modified for each program as needed.
*
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#41.1.3 %
 * %derived_by:       rzmnk2 %
 * %date_modified:    Tue Jan 28 13:15:13 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/06/12 	1		KS		Initial Component Release
 * 06/14/12 	2		KS		Removed header include for Part_numbers.h
 * 06/15/12		3		KS		Updates applied for new integration of components.
 * 07/19/12		4		JJW		DID enable and trusted function call anomaly corrections
 * 08/06/12		7		KJS		Enabled service FD14
 * 08/21/12		10		KJS		Corrected anomaly 3622 and disabled F007 until FDDs better define the clear procedure.
 * 10/11/12		11		JJW		DiagMgr FDD37B_001.16 Integration
 * 10/16/12		12		JJW		T1 and T2 Sender ports moved to IoHwAb7 during configuraiton of Application 7, Sin1Theta
 *								and Cos1Theta moved to CDDInterface10, which changes the Rte global data store names.
 *								Updated the configuration here accordingly.
 * 10/26/12		13		BDO		Changed ManVehSpd_SCom function to SrlComInput2_SCom_ManualVehSpd 	         CR6650
 * 10/30/12		14		JJW		NonTrusted and Trusted call interfaces used where required, removed extern defs for
 * 								the functions as they are provided in the Os.h and NtWrap.h files.
 *								Integrated CMS_Common 001.12
 * 11/20/12		15		JJW		Updated Rte_IoHwAb7_TemperatureADC_Volt_f32 name per IoHwAb application allocation changes
 * 11/26/12		16		JJW		Support CMS_Common 1.24
 * 12/03/12		17		JJW		MRFMtrVel name change to support integration ofFDD02B_008.0
 * 12/06/12		18		KJS		Corrected trusted call for TrqCmdScl_SCom_Set
 * 12/06/12		19		JJW		Remvoed component specific RTE include from this general include file due to build errors
 * 12/11/12		20		KJS		Removed NtWrap.h calls, and added extern statements for functions using the Ntwrap
 *								functions back in. Similiar to version 13 of this file.
 * 01/09/13		21		KJS		Added extern function for TrqSclCmd (service FD25).
 * 01/27/13		22		KJS		Replaced Rte_CtrldDisShtdn_MRFMtrTrqCmd_MtrNm_f32 with Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32
 * 01/28/13     23      JWJ     Added F0FF and new (disabled) brushed XCP vars                                  7190
 * 01/28/13     24      KJS     Removed Call_ from FOFF service.
 * 02/05/13     25      JJW     Integration of MtrPos FDD06B_004.1 and MtrVel FDD02B_010.0
 * 03/14/13     26      JWJ     Updated to CMS spec 05A
 * 03/18/13     27      JWJ     Updates to include F006/F00F addition and new CMS overhaul                      7626
 * 04/03/13     28      KJS     Added Call_ in 0xF0FF service. 													7778
 * 04/12/13     29      JWJ     Added FEE1 - SVK block read/write
 * 04/12/13     30      JWJ     Added FEE0 - vehicle variant select                                             7884
 * 05/01/13     31      VK		Anomaly 4950 correction 														8202
 * 05/24/13     32      KJS		Anomaly 5080 correction
 * 06/17/13     33      KJS		Anomaly 4178 correction
 * 06/27/13		32.1.1	KJS		Anomaly 5160 correction
 * 09/25/13		32.1.2	KJS		Updates for HWAP support
 * 11/12/13		34		KJS		Merge of the anomaly path and the main dev path, and HWAP updates per SER 13C
 * 01/14/14		35		KJS		LrnEOT moved to trusted application, so the function call now goes through NtWrap.
 * 01/14/14		36		KJS		Added support for FDD98 new services
 * 01/27/14		37		KJS		Added FEE4 support
 * 09/29/14		39		KJS		Added FEE5 support
 * 11/04/14		40		KJS		Added FEE6 support
 * 20/05/15		41		ABS		Added FEE7 support
 * 03/24/15		42		ABS		Added FEE8 support
 * 08/01/16		43		RMV		Added externs to functions/variables which was missing EA#10162
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_ISO_INTERFACE_H
#define EPS_DIAGSRVCS_ISO_INTERFACE_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dcm_types.h"
#include "trustfct.h" /* Os Trusted Function call definitions */
#include "Ap_DiagMgr.h"
#include "omc.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* --- Common Defines --- */
#define CM_DIAGBUFFLEN_CNT_U16              kDescPrimBufferLen
#define NXTR_SESSION						0x7Eu
#define CM_SetNegResp(a)					CM_DiagNegRespCode_u16 = a
#define CM_NumHeaderBytes_Cnt_u16			2u
#define CM_NumRIDHeaderBytes_Cnt_u16		3u
#define CM_NumLIDHeaderBytes_Cnt_u16		CDD_DiagSrvcsUnusedVar_Cnt_M_u16
#define CM_NULL								0x00
#define D_ALLDTC_MASK_CNT_U32 				0xFFFFFFU
#define CM_MsgBufferType					Dcm_MsgType
#define CM_MsgLenType						Dcm_MsgLenType
#define CM_RTE_MODE_StaMd_Mode_OPERATE		RTE_MODE_StaMd_Mode_OPERATE
#define CM_SrlComHwPos_HwDeg_f32			Rte_AbsHwPos_HandwheelPosition_HwDeg_f32

#define CM_Std_ReturnType					Std_ReturnType
#define CM_RESP_OK							RTE_E_OK


/* offsets for the data buffers for diag request/responses */
#define D_REQMSG_PID_OFFSET_CNT_U16			2U
#define D_REQMSG_RID_OFFSET_CNT_U16			3U
#define D_REQMSG_IOC_OFFSET_CNT_U16			2U
#define D_REQMSG_RESET_OFFSET_CNT_U16		0U
#define D_RESPMSG_OFFSET_CNT_U16			0U

#define D_RETURNDATA_OFFSET_CNT_U16			0U	/* This index to offset the data that is WRITTEN to the diagnostic buffer..typically done in read operations */
#define D_REQUESTDATA_OFFSET_CNT_U16		0U  /* This index to offset the data that is READ from the diagnostic buffer..typically done in write operations */


/* Negative Response Codes */
#define D_EPSNRCNOTNXTRPROD_CNT_U08    D_EPSNRCSERVICENOTSUPPORTED_CNT_U16
#define D_EPSNRCSERVICEMISSING_CNT_U08    D_EPSNRCSERVICENOTSUPPORTED_CNT_U16


/**********************************************************************************************************************
 * --- RTE GLOBAL DATA START ---
 *
 * This section is for variables that are external references to RTE variables. (Formally found in the RTE_GlobalData.h)
 *
 *********************************************************************************************************************/


/* System State*/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
/* Battery Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
/* T1 Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_IoHwAb7_T1ADC_Volt_f32;
/* T2 Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_IoHwAb7_T2ADC_Volt_f32;
/* Hw Trq */
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
/* Final Handwheel Position */
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
/* Motor Trq Limit */
extern VAR(Float, RTE_VAR_NOINIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32;
/* Cumulative Motor Position */
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrPos_CumMtrPosMRF_Deg_f32;
/* Motor Velocity MRF Cord */
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
/* Vehicle Speed */
extern VAR(Float, RTE_VAR_NOINIT) Rte_SignlCondn_VehicleSpeed_Kph_f32;

/* Digital (PWM) T1 Duty Cycle */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1Duty_Uls_f32;
/* Digital (PWM) T1 Volt */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1ADC_Volt_f32;
/* Digital (PWM) T2 Duty Cycle */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2Duty_Uls_f32;
/* Digital (PWM) T2 Volt */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2ADC_Volt_f32;
/* digital Hw Trq */
extern VAR(Float, RTE_VAR_INIT) Rte_DigHwTrq_DigHwTrq_HwNm_f32;
/* Tbar Stiffness */
extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;
/* Hw Trq Scale Analog */
extern CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32;
/* Hw Trq Scale Digital */
extern CONST(float32, CAL_CONST) k_DigHwTrqSensScaleNom_VoltspDeg_f32;
/* T1 Trim Volts Analog, T2 Trim Volts Analog, HwTrqTrim Volts Analog*/
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
/* T1 Trim Volts Digital, T2 Trim Volts Digital, HwTrqTrim Volts Digital*/
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DigHwTrq_DigTrqTrim;
/* ECU Controller Temp */
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
/* Sin1 Amp */
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_SinTheta1_Volt_f32;
/* Cos 1 Amp */
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_CosTheta1_Volt_f32;
/* Est QAX Current */
extern VAR(Float, RTE_VAR_INIT) Rte_ParamComp_ExpIq_Amp_f32;
/* Modulation Index */
extern VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_ModIdx_Uls_f32;
/* Controller Temp (ADC Volts) */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_TemperatureADC_Volt_f32;
/* Mag Temp Estimation */
extern VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_MagTempEst_DegC_f32;
/* Engergy Mode */
extern VAR(EnergyModeStateType, RTE_VAR_INIT) Rte_VehCfg_EnergyModeState_Cnt_enum;
/* Used in other services, such as appdesc */
extern VAR(Boolean, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
/* Default Vehicle Speed */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;
/* Constant to allow use of F0FF */
extern volatile CONST(boolean, AUTOMATIC) EnableTestMode_Cnt_lgc;
/* RawCurrent1 */
extern VAR(float32, RTE_VAR_INIT) Rte_MtrCurr_RawCurrFiltered_Amp_f32;
/* Motor Current Qax */
extern VAR(float32, RTE_VAR_INIT) Rte_MtrCurr_MtrCurrQax_Amp_f32;
/* Motor Current Daq */
extern VAR(float32, RTE_VAR_INIT) Rte_MtrCurr_MtrCurrDax_Amp_f32;
/* Valid Current Sample */
extern VAR(boolean, RTE_VAR_INIT) Rte_MtrCurr_ValidSampleFlag_Cnt_lgc;

#define CM_VehicleSpeed_Kph_f32			Rte_SignlCondn_VehicleSpeed_Kph_f32
#define CM_DiagStsDefVehSpd_Cnt_lgc		Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc
#define CM_HwTrq_HwNm_f32				Rte_HwTrq_AnaHwTorque_HwNm_f32

#define CM_k_TrimVehSpdLimit_Kph_f32    k_CustSrvcVehSpdThres_kph_f32
#define CM_k_TrimHwTrqLimit_HwNm_f32    k_CustSrvcHwTrqThres_HwNm_f32

extern VAR(uint8, NVM_APPL_DATA) Nxtr_FeeInitialized_Cnt_u8[2u]; /* For service FEE6 */



/**********************************************************************************************************************
 * --- RTE GLOBAL DATA END ---
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * --- SERIAL COMM FUNCTION START ---
 *
 * This section is for functions that are external references to system functions. (Formally found in the SComm_Func.h)
 *
 *********************************************************************************************************************/

/* 0x22 and 0x2E Services */
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);
extern FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomL_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomL_Henry_f32, Float NomRmtr_Ohm_f32);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_GetNTCInfo(VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Param_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) AgingCounter_Ptr_T_u08);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ResetNTCStatus(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ReadStrgArray(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ClearBlackBox(void);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_TrqCmdScl_SCom_Set(Float Par_f32);
extern FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_NTWRAP_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearCenterPosition(void);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_CheckpointReached( VAR (WdgM_SupervisedEntityIdType, AUTOMATIC) SEID, VAR (WdgM_CheckpointIdType, AUTOMATIC) CPID);
extern FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void);
extern void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16);
extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_DiagModeChange (Vsm_OperatingModeType mode);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ReadTcEOLCals(P2VAR(EOLTurnsCntrCals_Datatype, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcEOLCalsPtr);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ResetTC(void);
extern FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void);
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
extern FUNC(Std_ReturnType, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_SetVariantSelect(VAR(UInt8, AUTOMATIC) VehicleVariant_Cnt_T_u8);
extern FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_GetVariantSelect(P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) VehicleVariant_Cnt_T_u8);

/* 0x31 Services */
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);
extern FUNC(Dem_ReturnClearDTCType, 	DEM_CODE) Dem_ClearDTC( Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalGain(void);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalOffset(void);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ClearTcEOLCals(void);
extern VAR(float32, AUTOMATIC) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(float32, AUTOMATIC) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
extern VAR(float32, AUTOMATIC) Rte_AbsHwPos_AlignedHwPos_HwDeg_f32;
extern VAR(boolean, AUTOMATIC) Rte_SrlComInput2_VehSpdValid_Cnt_lgc;
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);

/* 0x2F services */
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_Reset(void);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void);
extern FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_StartPrg(void);


extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);

extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

/* 0x11 Reset services */
extern FUNC(void, RTE_NTWRAP_APPL_CODE) Call_StaMd_SCom_EcuReset(void);

#define CM_GetCurrentDiagnosticMode(SesCtl) Dcm_GetSesCtrlType(SesCtl)

/**********************************************************************************************************************
 * --- SERIAL COMM FUNCTION END ---
 *********************************************************************************************************************/

/* --- Common Manufacturing Services Selection ---
 * This block of defines control which services are to be included for the program at the time of build.
 * Unused or not defined services should be set to D_DIAGSRVC_DISABLED.
 */

/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/
#define D_EPSDIAGSRVPID0000_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0003_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0004_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0005_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0006_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0007_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0008_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0009_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0010_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0011_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0012_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0013_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0014_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0015_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0016_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0017_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0018_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0019_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0020_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0021_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0022_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0023_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0024_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0025_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0026_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0027_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0028_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0029_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0030_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0031_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0032_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0033_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0034_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0035_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0036_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0037_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0038_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0039_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0040_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0041_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0042_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0043_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0044_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0045_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0046_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0100_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0101_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0102_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0103_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0104_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0105_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0106_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0107_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0108_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0109_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRESET1160_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF000_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF003_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF004_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF005_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF006_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF007_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF008_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF009_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF0FF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD01_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD02_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD03_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD04_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD05_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD06_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD07_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD08_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD09_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD0C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD0D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD10_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD11_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD12_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD13_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD14_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD15_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD16_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD17_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD18_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD19_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD1E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD1F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD20_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD21_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD22_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD23_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD24_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD25_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD26_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD27_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD28_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD29_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD30_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD31_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD41_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA4_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA7_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA8_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA9_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDAC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAD_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAE_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB1_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB2_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB3_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB4_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB7_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFEE0_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE4_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE7_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE8_CNT_ENUM	D_DIAGSRVC_ENABLED

/* -----[ Begin XCP Variables ]----- */
#define CM_ModeMachine_StaMd_SystemState_Mode &Rte_ModeMachine_StaMd_SystemState_Mode
#define CM_BatteryVoltage_Vecu_Volts_f32      &Rte_BatteryVoltage_Vecu_Volt_f32
#define CM_Adc_T1                             NULL_PTR
#define CM_Analog_T1_Volts                    &Rte_IoHwAb7_T1ADC_Volt_f32
#define CM_Adc_T2                             NULL_PTR
#define CM_Analog_T2_Volts                    &Rte_IoHwAb7_T2ADC_Volt_f32
#define CM_HwTrqArb_HwTrq_HwNm_f32            &Rte_HwTrq_AnaHwTorque_HwNm_f32
#define CM_FinalHwPos_FinHwPos_HwDeg_f32      &Rte_AbsHwPos_HandwheelPosition_HwDeg_f32
#define CM_ScaledMtrPos_HwDeg_M_f32           NULL_PTR
#define CM_KeFBckTyH_VpRadpS_f32              NULL_PTR
#define CM_RFBckTyH_Ohm_f32                   NULL_PTR
#define CM_Sin1MaxTyH_Volts_f32               NULL_PTR
#define CM_Sin1MinTyH_Volts_f32               NULL_PTR
#define CM_Cos1MaxTyH_Volts_f32               NULL_PTR
#define CM_Cos1MinTyH_Volts_f32               NULL_PTR
#define CM_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32   &Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32
#define CM_MtrPos_MRFCumMtrPos_Deg_f32        &Rte_MtrPos_CumMtrPosMRF_Deg_f32
#define CM_MtrVel_MRFMtrVel_MtrRadpS_f32      &Rte_MtrVel_MRFMotorVel_MtrRadpS_f32
#define CM_VehicleSpeed_VehSpd_Kph_f32        &Rte_SignlCondn_VehicleSpeed_Kph_f32
#define CM_k_TbarStiff_NmpDeg_F32             &k_TbarStiff_NmpDeg_f32
#define CM_k_HwTrqSclNom_VoltspDeg_f32        &k_HwTrqSclNom_VoltspDeg_f32
#define CM_T1_Trim_Volts_Analog               &Rte_HwTrq_HwTrqTrimData.T1Trim_Volts_f32
#define CM_T2_Trim_Volts_Analog               &Rte_HwTrq_HwTrqTrimData.T2Trim_Volts_f32
#define CM_HwTrq_Trim_Volts_Analog            &Rte_HwTrq_HwTrqTrimData.HwTrqTrim_Volts_f32
#define CM_CtrlTemp_FiltMeasTemp_DegC_f32     &Rte_CtrlTemp_FiltMeasTemp_DegC_f32
#define CM_QaxCurrFiltSV_Amp_M_s11p20         NULL_PTR
#define CM_CDDInterface_Sin1Theta_Volts_f32   &Rte_MtrPos2_SinTheta1_Volt_f32
#define CM_CDDInterface_Cos1Theta_Volts_f32   &Rte_MtrPos2_CosTheta1_Volt_f32
#define CM_ParamComp_ExpIq_Amp_f32            &Rte_ParamComp_ExpIq_Amp_f32
#define CM_MtrTempEst_MagTempEst_DegC_f32     &Rte_MtrTempEst_MagTempEst_DegC_f32
#define CM_VltgCtrl_ModIdx_Uls_f32            &Rte_VltgCtrl_ModIdx_Uls_f32
#define CM_TemperatureADC_Volt_f32            &Rte_IoHwAb7_TemperatureADC_Volt_f32
#define CM_RawCurrFiltered1_Amp_f32           &Rte_MtrCurr_RawCurrFiltered_Amp_f32
#define CM_RawCurrFiltered2_Amp_f32           NULL_PTR
#define CM_MtrCurrQax_Amp_f32                 &Rte_MtrCurr_MtrCurrQax_Amp_f32
#define CM_MtrCurrDax_Amp_f32                 &Rte_MtrCurr_MtrCurrDax_Amp_f32
#define CM_ValidSampleFlag_Cnt_lgc            &Rte_MtrCurr_ValidSampleFlag_Cnt_lgc
#define CM_TcSpiBuffer_Cnt_M_str              NULL_PTR
/* -----[ End XCP Variables ]----- */

#if (D_EPSDIAGSRVRESET1160_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_StaMd_SCom_EcuReset                  Call_StaMd_SCom_EcuReset
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define D_EPSRESET_ECURESET			0x60
#endif

#if (D_EPSDIAGSRVRIDF000_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F000NMEC_CNT_LGC                      TRUE
	#define D_F000IGNCNTR_CNT_LGC                   TRUE
	#define D_F000LEARNEDEOT_CNT_LGC                TRUE
	#define D_F000ACTIVEPULLCOMP_CNT_LGC            TRUE
	#define D_F000NXTRDTCTBL_CNT_LGC                TRUE
	#define D_F000NXTRDTCBLACKBOX_CNT_LGC           TRUE
	#define D_F000CUSTDTCTBL_CNT_LGC                TRUE
	#define D_F000FRICTIONDETECTPARAM_CNT_LGC       TRUE
	#define D_F000INITLRNDTBLS_CNT_LGC              TRUE
	#define CM_Reset_LrnEOT_Scom_ResetEOT           NtWrapC_LrnEOT_Scom_ResetEOT
	#define CM_Reset_ActivePull_SCom_SetLTComp      ActivePull_SCom_SetLTComp
	#define CM_Reset_ClearNTCs_SComm                DiagMgr_SCom_ResetNTCStatus
	#define CM_DiagMgr_SCom_ClearBlackBox           DiagMgr_SCom_ClearBlackBox
	#define CM_Reset_ClearCustDTCs_SComm            Dem_ClearDTC
	#define CM_AvgFricLrn_SCom_ResetToZero          AvgFricLrn_SCom_ResetToZero
	#define CM_AvgFricLrn_SCom_InitLearnedTables    AvgFricLrn_SCom_InitLearnedTables
#endif

#if (D_EPSDIAGSRVRIDF001_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ClearNTCs_SComm                      DiagMgr_SCom_ResetNTCStatus
	#define CM_DiagMgr_SCom_ClearBlackBox           DiagMgr_SCom_ClearBlackBox
	#define CM_ClearCustDTCs_SComm                  Dem_ClearDTC
#endif

#if (D_EPSDIAGSRVRIDF002_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ClrHwTrqTrim              NtWrapC_HwTrq_SCom_ClrHwTrqTrim
	#define CM_HwTrq_SCom_ClrHwTrqScale             NtWrapC_HwTrq_SCom_ClrHwTrqScale
	#define CM_HwTrq_SCom_SetHwTrqTrim              NtWrapC_HwTrq_SCom_SetHwTrqTrim
#endif

#if (D_EPSDIAGSRVRIDF003_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F003CLRTRIMNORET_CNT_LGC              TRUE
	#define D_F003DISABLELRNTRIM_CNT_LGC            TRUE
#endif

#if (D_EPSDIAGSRVRIDF004_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_SENTBASEDSENSOR_CNT_LGC               TRUE
#endif

#if (D_EPSDIAGSRVRIDF005_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVRIDF006_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TcFlshPrg_Scom_StartPrg              TcFlshPrg_Scom_StartPrg
	#define CM_TcFlshPrg_Scom_FlshPrgStatus         TcFlshPrg_Scom_FlshPrgStatus
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#include "Cd_TcFlshPrg.h"
	#define CM_TcFlshPrgMode_T 						TcFlshPrgMode_T
  extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_FlshPrgStatus( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pTcFlashActive, P2VAR(uint16, AUTOMATIC, AUTOMATIC) ptrTcDataCntr,
																	   P2VAR(TcFlshPrgMode_T, AUTOMATIC, AUTOMATIC) ptrTcPrgState);
#endif

#if (D_EPSDIAGSRVRIDF007_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AbsHwPos_Scom_ClearCenterPosition    Call_AbsHwPos_Scom_ClearCenterPosition
	#define CM_AbsHwPos_Scom_ClearRacktoVehCntrOffset Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset
	#define CM_LrnEOT_Scom_ResetEOT                 NtWrapC_LrnEOT_Scom_ResetEOT
	#define CM_LrnEOT_Scom_ResetRckCntrPrf          LnRkCr_Scom_ResetRckCntrMtrRev
	#define CM_TurnsCounter_SCom_ResetTC            NtWrapC_TurnsCounter_SCom_ResetTC
	#define CM_AbsHwPos_Scom_SetCenterPosition      Call_AbsHwPos_Scom_SetCenterPosition
#endif

#if (D_EPSDIAGSRVRIDF008_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F008 */
#endif

#if (D_EPSDIAGSRVRIDF009_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define MtrCurrOffProcessFlag                   boolean
	#define D_RIDF009SVCDFTBITSSET_CNT_U16          0x301
	#define D_RIDF009SVCDFTBITSCLR_CNT_U16          (~D_RIDF009SVCDFTBITSSET_CNT_U16)
#endif

#if (D_EPSDIAGSRVRIDF00A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00A */
#endif

#if (D_EPSDIAGSRVRIDF00B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00B */
#endif

#if (D_EPSDIAGSRVRIDF00C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TcEOLCals_Scom_ClearTcEOLCals        NtWrapC_TurnsCounter_SCom_ClearTcEOLCals
#endif

#if (D_EPSDIAGSRVRIDF00D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrCurr_SCom_CalGain                 NtWrapC_MtrCurr_SCom_CalGain
#endif

#if (D_EPSDIAGSRVRIDF00E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrCurr_SCom_CalOffset               NtWrapC_MtrCurr_SCom_CalOffset
	#define D_RIDF00ESVCDFTBITSSET_CNT_U16          0x301
#endif

#if (D_EPSDIAGSRVRIDF00F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_k_SComTrqPosPol_Cnt_s08              k_SComTrqPosPol_Cnt_s08
	#define CM_Rte_AbsHwPos_SrlComHwPos_HwDeg_f32   Rte_AbsHwPos_SrlComHwPos_HwDeg_f32
	#define CM_HandwheelAuthority_Uls_f32           Rte_AbsHwPos_HandwheelAuthority_Uls_f32
	#define CM_VehSpdValid_Cnt_lgc                  Rte_SrlComInput2_VehSpdValid_Cnt_lgc
	#define CM_GenPosTraj_SCom_SetInputParam        NtWrapC_GenPosTraj_SCom_SetInputParam
#endif

#if (D_EPSDIAGSRVRIDF0FF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EnableTestMode_Cnt_lgc               EnableTestMode_Cnt_lgc
	#define CM_ProcessF0FF                          Call_ProcessF0FF
	#define CM_WdgM_CheckpointReached               WdgM_CheckpointReached
	#define CM_DisableSysTickInterrupt              DisableSysTickInterrupt
	#define CM_EnableSysTickInterrupt               EnableSysTickInterrupt
	#define CM_GetAlarm                             GetAlarm
	#define CM_CancelAlarm                          CancelAlarm
	#define CM_SetRelAlarm                          SetRelAlarm
#endif

#if (D_EPSDIAGSRVPIDFD01_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SwRelNum_Cnt_u08                     k_SWRelNum_Cnt_u8
	#define CM_CalRelNum_Cnt_u08                    k_CalRelNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFD02_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SrlComSvcDft_Cnt_b32                 CDD_EOLSrlComSvcDft_Cnt_G_b32
#endif

#if (D_EPSDIAGSRVPIDFD03_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD03 */
#endif

#if (D_EPSDIAGSRVPIDFD04_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrPosCal_DataType                   MtrPosCal_DataType
	#define CM_MtrPos_SCom_SetEOLMtrCals            Call_MtrPos_SCom_SetEOLMtrCals
	#define CM_MtrPos_SCom_ReadEOLMtrCals           MtrPos_SCom_ReadEOLMtrCals
	#define D_HARTBLSIZE_CNT_U16                    144
#endif

#if (D_EPSDIAGSRVPIDFD05_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ManualSetHwTrqTrim        NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim
	#define CM_HwTrq_SCom_ReadHwTrqTrim             HwTrq_SCom_ReadHwTrqTrim
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_HwTrqTrim_Datatype                   HwTrqTrim_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD06_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD06 */
#endif

#if (D_EPSDIAGSRVPIDFD07_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Polarity_SCom_SetPolarity            Call_Polarity_SCom_SetPolarity
	#define CM_Polarity_SCom_ReadPolarity           Polarity_SCom_ReadPolarity
#endif

#if (D_EPSDIAGSRVPIDFD08_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_SetHwTrqScale             NtWrapC_HwTrq_SCom_SetHwTrqScale
	#define CM_HwTrq_SCom_ReadHwTrqScale            HwTrq_SCom_ReadHwTrqScale
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_HwTrqScale_Datatype                  HwTrqScale_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD09_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SCom_KeIntgSVParam_Set               Call_SCom_KeIntgSVParam_Set
	#define CM_SCom_KeIntgSVParam_Get               SCom_KeIntgSVParam_Get
#endif

#if (D_EPSDIAGSRVPIDFD0A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SCom_RIntgSVParam_Set                Call_SCom_RIntgSVParam_Set
	#define CM_SCom_RIntgSVParam_Get                SCom_RIntgSVParam_Get
#endif

#if (D_EPSDIAGSRVPIDFD0B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0B */
#endif

#if (D_EPSDIAGSRVPIDFD0C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SCom_EOLNomMtrParam_Set              Call_SCom_EOLNomMtrParam_Set
	#define CM_SCom_EOLNomMtrParam_Get              SCom_EOLNomMtrParam_Get
#endif

#if (D_EPSDIAGSRVIOCFD0D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqLmt_SCom_ManualTrqCmd          Call_AssistLmtFunc_Scom_ManualTrqCmd
#endif

#if (D_EPSDIAGSRVPIDFD0E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqCmd_MtrNm_f32                  Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32
	#define CM_CumMtrPos_Deg_f32                    Rte_MtrPos_CumMtrPosMRF_Deg_f32
#endif

#if (D_EPSDIAGSRVPIDFD0F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define d_HardwareDescTblPIDSize_Cnt_u16	59u
#endif

#if (D_EPSDIAGSRVPIDFD10_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD10 */
#endif

#if (D_EPSDIAGSRVIOCFD11_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DFTASSTTBL_CNT_LGC                   CDD_DftAsstTbl_Cnt_G_lgc
	#define CM_DWNLDASSTGAIN_ULS_F32                CDD_DwnldAsstGain_Uls_G_f32
#endif

#if (D_EPSDIAGSRVPIDFD12_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_PhaseCurrCal_DataType                PhaseCurrCal_DataType
	#define D_PIDFD12IGNOREOFFSETDIFF_CNT_LGC       TRUE
	#define D_PIDFD12IGNOREVCALCMD_CNT_LGC          TRUE
	#define D_PIDFD1216BITDATASTRG_CNT_LGC          TRUE
#endif

#if (D_EPSDIAGSRVPIDFD13_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_ReadStrgArray           DiagMgr_SCom_ReadStrgArray
	#define CM_DTCMaxStorage_Cnt_u16                D_MAXDTCSTORAGE_CNT_U16
	#define CM_NTCStrgArray_Type                    NTCStrgArray
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVPIDFD14_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AbsHwPos_SCom_VehicleSystemStatus    Call_AbsHwPos_SCom_VehicleSystemStatus
#endif

#if (D_EPSDIAGSRVPIDFD15_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrqTrim_Datatype                   CM_HwTrqTrim_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD16_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_HwTrqScale_Datatype	HwTrqScale_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD17_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD17 */
#endif

#if (D_EPSDIAGSRVPIDFD18_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD18 */
#endif

#if (D_EPSDIAGSRVPIDFD19_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_NxtrMEC_Cnt_G_u8                     Nvm_NMEC_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFD1A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Rte_ModeType_StaMd_Mode              Rte_ModeType_StaMd_Mode
	#define CM_SystemState_Cnt_enum                 Rte_ModeMachine_StaMd_SystemState_Mode
#endif

#if (D_EPSDIAGSRVPIDFD1B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ManualVehSpd_SCom                    Call_SrlComInput2_SCom_ManualVehSpd
#endif

#if (D_EPSDIAGSRVPIDFD1C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1C */
#endif

#if (D_EPSDIAGSRVPIDFD1D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1D */
#endif

#if (D_EPSDIAGSRVPIDFD1E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1E */
#endif

#if (D_EPSDIAGSRVPIDFD1F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1F */
#endif

#if (D_EPSDIAGSRVPIDFD20_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_BatteryVoltage_SCom_ReadTransOvData  NULL_PTR
	#define CM_BatteryVoltage_SCom_WriteTransOvData NULL_PTR
#endif

#if (D_EPSDIAGSRVPIDFD21_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD21 */
#endif

#if (D_EPSDIAGSRVPIDFD22_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TcPartNumType                        TcPartNumType
	#define CM_TurnsCounter_Scom_PartNumSvc         TurnsCounter_Scom_PartNumSvc
	#define D_PIDFD22STRLEN_CNT_U08                 D_TcPNArraySize_Cnt_U16
#endif

#if (D_EPSDIAGSRVPIDFD23_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Vsm_Scom_SetOperatingMode            Vsm_DiagModeChange
	#define CM_Vsm_OperatingModeType                Vsm_OperatingModeType
	#define CM_Rte_VehCfg_EnergyModeState_Cnt_enum  Rte_VehCfg_EnergyModeState_Cnt_enum
#endif

#if (D_EPSDIAGSRVPIDFD24_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EOLTurnsCntrCals_Datatype            EOLTurnsCntrCals_Datatype
	#define CM_TcEOLCals_Scom_SetTcEOLCals          NtWrapC_TurnsCounter_Scom_SetTcEOLCals
	#define CM_TcEOLCals_Scom_ReadTcEOLCals         TcEOLCals_Scom_ReadTcEOLCals
#endif

#if (D_EPSDIAGSRVPIDFD25_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TrqCmdScl_SCom_Set                   Call_TrqCmdScl_SCom_Set
	#define CM_TrqCmdScl_SCom_Get                   TrqCmdScl_SCom_Get
#endif

#if (D_EPSDIAGSRVPIDFD26_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetSelect            AvgFricLrn_SCom_SetSelect
	#define CM_AvgFricLrn_SCom_GetSelect            AvgFricLrn_SCom_GetSelect
#endif

#if (D_EPSDIAGSRVPIDFD27_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetOffsetOutputDefeat AvgFricLrn_SCom_SetOffsetOutputDefeat
	#define CM_AvgFricLrn_SCom_GetOffsetOutputDefeat AvgFricLrn_SCom_GetOffsetOutputDefeat
#endif

#if (D_EPSDIAGSRVPIDFD28_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TurnsCounter_Scom_GetFlashTraceabilityID TcFlshPrg_Scom_TcFlashTraceability
	#define CM_TcFlashIDType                        TcFlshTraceabilityType
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_TcFlshPrg_Scom_TcFlashTraceability		TcFlshPrg_Scom_TcFlashTraceability
	#define CM_TcFlshTraceabilityType                   TcFlshTraceabilityType
  extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_TcFlashTraceability(P2VAR(TcFlshTraceabilityType, AUTOMATIC, AUTOMATIC) pTcFlshTraceabilityData);
#endif

#if (D_EPSDIAGSRVPIDFD29_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetEOLFric           AvgFricLrn_SCom_SetEOLFric
	#define CM_AvgFricLrn_SCom_GetEOLFric           AvgFricLrn_SCom_GetEOLFric
#endif

#if (D_EPSDIAGSRVPIDFD30_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD30 */
#endif

#if (D_EPSDIAGSRVPIDFD31_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD31 */
#endif

#if (D_EPSDIAGSRVPIDFD41_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 Rte_IoHwAb7_T1ADC_Volt_f32
	#define CM_Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 Rte_IoHwAb7_T2ADC_Volt_f32
#endif

#if (D_EPSDIAGSRVPIDFDA0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA0 */
#endif

#if (D_EPSDIAGSRVPIDFDA1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUSerialNumber                      Nvm_EcuSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EPSSerialNumber                      Nvm_EpsSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUHardwarePN                        Nvm_EcuHwPn_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA4 */
#endif

#if (D_EPSDIAGSRVPIDFDA5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ShCurrCal_DataType                   ShCurrCal_DataType
	#define CM_MtrCurr_SCom_SetMtrCurrCals          NtWrapC_MtrCurr_SCom_SetMtrCurrCals
	#define CM_MtrCurr_SCom_ReadMtrCurrCals         MtrCurr_SCom_ReadMtrCurrCals
#endif

#if (D_EPSDIAGSRVPIDFDA7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwPosRelCal_DataType                 HwPosRelCal_DataType
#endif

#if (D_EPSDIAGSRVPIDFDA8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA8 */
#endif

#if (D_EPSDIAGSRVPIDFDA9_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA9 */
#endif

#if (D_EPSDIAGSRVPIDFDAC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MfgScratchPad_Cnt_G_u8               Nvm_NxtrManfScrpd_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDAD_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_ReadParam            ActivePull_SCom_ReadParam
#endif

#if (D_EPSDIAGSRVPIDFDAE_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDAE */
#endif

#if (D_EPSDIAGSRVPIDFDAF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDAF */
#endif

#if (D_EPSDIAGSRVPIDFDB0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB0 */
#endif

#if (D_EPSDIAGSRVPIDFDB1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB1 */
#endif

#if (D_EPSDIAGSRVPIDFDB2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB2 */
#endif

#if (D_EPSDIAGSRVPIDFDB3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB3 */
#endif

#if (D_EPSDIAGSRVPIDFDB4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_RANDKESUPPORTONLY_CNT_LGC             TRUE
#endif

#if (D_EPSDIAGSRVPIDFDB5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetSTComp            ActivePull_SCom_SetSTComp
	#define CM_ActivePull_SCom_ReadParam	ActivePull_SCom_ReadParam
#endif

#if (D_EPSDIAGSRVPIDFDB6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetLTComp            ActivePull_SCom_SetLTComp
#endif

#if (D_EPSDIAGSRVPIDFDB7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB7 */
#endif

#if (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_VehCfg_Scom_GetVariantSelect 	VehCfg_Scom_GetVariantSelect
	#define CM_VehCfg_Scom_SetVariantSelect 	VehCfg_Scom_SetVariantSelect
#endif

#if (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define D_SVKBLOCKLEN_CNT_U16   65U
#endif

#if (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#include "DataLogistic.h"
	#define D_HARDWAREDESCTBLPIDSIZE_CNT_U16	59U
#endif

#if (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define D_HWAPDESCINDEX_CNT_U8			1U	/* This should match Ap_VehCfg.c */
	#define D_HWAPSGBMNUM_CNT_U8			1U	/* This should match Ap_VehCfg.c */
	#define D_HWAPSGBMNUMLEN_CNT_U8			4U	/* This should match Ap_VehCfg.c */
#endif

#if (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE4 */
	#include "sc_ee_data.h"
	#define D_FINGERPRINTSIZE_CNT_U8	sizeof(BootProgData.FingerPrint)
#endif

#if (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE5 */
	#define D_REQSIZEFLSHSEGSTATUS_CNT_U8	sizeof(BootProgStatus.FlashSegmentStatus)
	#define D_NUMBEROFALLSWES_CNT_U8		sizeof(BootProgStatus.SWEProgrammingStatus)
#endif

#if (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE6 */
#endif

#if (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE7 */
	#include "sc_ee_data.h"
	#define D_SVKLOCKMAXVALUE_CNT_U08			2U
#endif

#if (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE8 */
	#define D_MTRSUPLRSERV_DEFAULT_CNT_U08		0U
	#define D_MTRSUPLRSERV_LETRIKA_CNT_U08		0x58U
	#define D_MTRSUPLRSERV_TAIGENE_CNT_U08		0x4CU
#endif

/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_INTERFACE_H */