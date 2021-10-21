/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_AbsHwPos.c
 *     Workspace:  C:/ccm_wa/EPS/570/I490/AbsHwPos/autosar
 *     SW-C Type:  Ap_AbsHwPos
 *  Generated at:  Thu Jun 27 17:50:30 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_AbsHwPos>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sat Feb 25 12:00:00 2012
 * %version:          25 %
 * %derived_by:       xz0btk %
 * %date_modified:    Wed Jun 26 14:06:59 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                                SCR #
 * -------   -------  --------  --------------------------------------------------------------------------------  -----
 * 02/29/12  1        OT        Initial Version                                                                   4986
 * 03/01/12  2        OT        Added Common Manufacturing Service SCom Function VehicleSystemStatus              4986
 * 03/15/12  3        JJW       TorqueCmdCRF port prototype correction from HwNm_f32 to MtrNm_f32
 * 04/02/12	 4		  SAH		Removed magic number from Scom function, added local constant. Change authority from percent to unitless
 * 04/16/12	 5		  OT 		Updated to FDD 48 rev 5                                                           5205
 * 05/15/12	 6		  OT 		Fixed UTP Issues (Added limiting)                                                 5205
 * 06/16/12  7        NRAR      Added Loss of AbsHwPos diagnostic
 * 06/19/12	 8		  KJS		Removed Rack to Veh Center Scom function, and integrated its features into Per1	
 * 06/26/12  8		  KJS		Corrections for anomaly 3484 applies to Untrimmed_HwPos()						  5742
 * 06/29/12	 10		  KJS		Anomaly correction for 3503														  5711
 * 08/17/12  11       BDO       Update AbsHwPos to support new RackCentering function (SF-39)			          6034
 * 08/20/12  12       BDO       Update passed parameters in AbsHwPos_SetData_SetRacktoVehCntrOffset
 * 08/29/12  13       BDO       Update range check (D_R2VMAX_CNT_F32) of RacktoVehCntrOffset to include 4094
 * 08/29/12  14       BDO       Changed D_RACKTOVEHCNTRUNLEARNED_CNT_U16 from 4094 to 4095 (template comments updated), QAC updates
 * 08/30/12  15       BDO       Apply polarity inversion, k_SComTrqPosPol_Cnt_s08, to RacktoVehCntrOffset         6143
 * 01/25/13  16       KJS       Updated polarity port def for integration with polarity component. 
 * 03/14/13  17		  KJS		QAC updates and Added reset TC function call per anomaly 3690
 * 04/29/13  18       VK		Updated to FDD 05C v10															  8151
 * 04/29/13  19       VK		Added out of range NRC to SetCenterPosition										  8151
 * 04/30/13  20       VK		Updated to FDD 05C v11															  8172
 * 05/31/13  20,21       NRAR      Updated for Anom 5029                                                               8488
 * 06/01/13	 23		  KJS		Added type case for anomaly 5104 correction
 * 06/07/13	 24		  KJS		Added type case for anomaly 5134 correction
 * 06/27/13	 25		  JJW		Consolidated PIM NVM information
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Ap_AbsHwPos.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_AbsHwPos_Cfg.h"


/* == INCLUDES ================================================= */

#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "interpolation.h"
#include "fixmath.h"


/* == DATA TYPES =============================================== */

typedef enum {
	REVOFFSET_STATE_INIT		= 0U,
	REVOFFSET_STATE_COMPENSATE	= 1U,
	REVOFFSET_STATE_SUBSTITUTE	= 2U,
	REVOFFSET_STATE_TEMPCOMP	= 3U,
	REVOFFSET_STATE_CORRECTION	= 4U,
	REVOFFSET_STATE_INVALID		= 5U
} RevOffsetStateType;


/* == PROTOTYPES =============================================== */

STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) SetRacktoVehCntrOffset(VAR(float32, AUTOMATIC) RackCntrOffset_HwDeg_T_f32, VAR(boolean, AUTOMATIC) LTRckCntrComplete_Cnt_T_lgc);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) DefaultHwPos(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) ClrIncmpHwPosLrn(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) UntrimmedHwPos(void);
STATIC INLINE FUNC(void, AP_TCBASEDHWPOS_CODE) UpdateRevOffset(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Init(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Compensate(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Substitute(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_TempComp(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Correction(void);
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Invalid(void);


/* == CONSTANTS ================================================ */

#define	D_NOAUTH_ULS_F32		0.0f
#define D_360_DEGPREV_F32		360.0f
#define D_R2VRES_HWDEGPCNT_F32	0.04395f
#define D_R2VMSGOFF_CNT_F32		2047.0f
#define D_R2VMIN_CNT_F32		0.0f
#define D_R2VMAX_CNT_F32		4094.0f
#define D_AUTHORITYTOL_ULS_F32	0.00004f
#define D_MAXCONF_ULS_F32		1.0f
#define D_MAXVEHCNTR_HWDEG_F32	1440.0f
#define D_MAXHWPOS_HWDEG_F32	1440.11f
#define D_RACKTOVEHCNTRUNLEARNED_CNT_U16	4095U


#define ABSHWPOS_START_SEC_CONST_8


#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(uint8, AP_TCBASEDHWPOS_CODE) t_RevOffsetStateCode_Cnt_u08[] = 
{
	0x08U,	/* REVOFFSET_STATE_INIT */
	0x02U,	/* REVOFFSET_STATE_COMPENSATE */
	0x04U,	/* REVOFFSET_STATE_SUBSTITUTE */
	0x0AU,	/* REVOFFSET_STATE_TEMPCOMP */
	0x0CU,	/* REVOFFSET_STATE_CORRECTION */
	0x0EU	/* REVOFFSET_STATE_INVALID */
};
#define ABSHWPOS_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */


/* == VARIABLES ================================================ */

#define ABSHWPOS_START_SEC_VAR_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_ABSHWPOS_VAR) AllowCorrectionState_Cnt_M_lgc;
STATIC VAR(sint8,   AP_ABSHWPOS_VAR) Polarity_Cnt_M_s08;
STATIC VAR(boolean, AP_ABSHWPOS_VAR) VehCntrComplete_Cnt_M_lgc;
#define ABSHWPOS_STOP_SEC_VAR_8
#include "MemMap.h" /* PRQA S 5087 */


#define ABSHWPOS_START_SEC_VAR_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint16,  AP_ABSHWPOS_VAR) ICMRevOffsetCRF_Rev_M_s16;
#define ABSHWPOS_STOP_SEC_VAR_16
#include "MemMap.h" /* PRQA S 5087 */


#define ABSHWPOS_START_SEC_VAR_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_ABSHWPOS_VAR) AlignedHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) HandwheelAuthority_Uls_M_f32;
STATIC VAR(sint32,  AP_ABSHWPOS_VAR) HwPositionFiltSV_HwDeg_M_s11p20;
STATIC VAR(float32, AP_ABSHWPOS_VAR) HwTargetAuthority_Uls_M_f32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) ICMAuthority_Uls_M_f32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) ICMMtrPosMRF_Deg_M_f32;
STATIC VAR(uint32,  AP_ABSHWPOS_VAR) InpSigInvldTimer_mS_M_u32;
STATIC VAR(uint32,  AP_ABSHWPOS_VAR) OffCorrTimer_mS_M_u32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) RevOffsetMRF_Deg_M_f32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) SrlComHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOS_VAR) TCMtrPosOffsMRF_Deg_M_f32;
STATIC volatile VAR(float32, AP_ABSHWPOS_VAR) ComplError_HwDeg_D_f32;
#define ABSHWPOS_STOP_SEC_VAR_32
#include "MemMap.h" /* PRQA S 5087 */


#define ABSHWPOS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(ST_OFFS_QUAD_EPS, AP_ABSHWPOS_VAR)      ICMRevOffsetStatus_Cnt_M_enum;
STATIC VAR(RevOffsetStateType, AP_ABSHWPOS_VAR)    RevOffsetState_Cnt_M_enum;
STATIC VAR(TurnsCntrValStateType, AP_ABSHWPOS_VAR) TurnsCntrValidity_Cnt_M_enum;
#define ABSHWPOS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * ST_OFFS_QUAD_EPS: Enumeration of integer in interval [0...15] with enumerators
 *   STOFFSQUADEPS_SLEEP (0U)
 *   STOFFSQUADEPS_CALCULATED (1U)
 *   STOFFSQUADEPS_INDEX (2U)
 *   STOFFSQUADEPS_MODELCOMP (3U)
 *   STOFFSQUADEPS_LOCKTOLOCK (4U)
 *   STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
 *   STOFFSQUADEPS_CHECK (6U)
 *   STOFFSQUADEPS_CORRECTION (7U)
 *   STOFFSQUADEPS_INITIALIZATION (8U)
 *   STOFFSQUADEPS_DETERMINED (9U)
 *   STOFFSQUADEPS_APPROXIMATED (11U)
 *   STOFFSQUADEPS_INVALID (15U)
 * TurnsCntrValStateType: Enumeration of integer in interval [0...255] with enumerators
 *   TCV_COMPUTING (0U)
 *   TCV_VALID (100U)
 *   TCV_INVALID (255U)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 * TcPartNumType: Array with 20 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * AbsHwPosTrim_DataType: Record with elements
 *   VehCntrOffset of type Float
 *   R_VehCntrOffset of type UInt32
 *   RacktoVehCntrOffset of type UInt16
 *   R_RacktoVehCntrOffset of type UInt16
 *   LTVehCntrComplete of type Boolean
 *   R_LTVehCntrComplete of type UInt8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_RACKTOVEHCNTRINVALID_CNT_U16 = 4095U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   AbsHwPosTrim_DataType *Rte_Pim_Trim(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(void)
 *   void Rte_IWrite_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Init1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC)	VehCntrOffset_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC)	LTVehCntrComplete_Cnt_T_lgc;
	VAR(uint16,  AUTOMATIC)	RacktoVehCntrOffset_Cnt_T_u16;
	VAR(uint32, AUTOMATIC)	R_VehCntrOffset_Cnt_T_u32;
	VAR(uint8, AUTOMATIC)	R_LTVehCntrComplete_Cnt_T_u8;
	VAR(uint16,  AUTOMATIC)	R_RacktoVehCntrOffset_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) VehCntrOffset_Cnt_T_u32;
	
	
	VehCntrOffset_Cnt_T_u32 = *(uint32 *)&(Rte_Pim_Trim() -> VehCntrOffset);
	R_VehCntrOffset_Cnt_T_u32 = Rte_Pim_Trim() -> R_VehCntrOffset ;
	
	LTVehCntrComplete_Cnt_T_lgc = Rte_Pim_Trim()->LTVehCntrComplete;
	R_LTVehCntrComplete_Cnt_T_u8 = Rte_Pim_Trim()->R_LTVehCntrComplete;
	
	RacktoVehCntrOffset_Cnt_T_u16 = Rte_Pim_Trim()->RacktoVehCntrOffset;
	R_RacktoVehCntrOffset_Cnt_T_u16 = Rte_Pim_Trim()->R_RacktoVehCntrOffset;
	
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InpSigInvldTimer_mS_M_u32);
	OffCorrTimer_mS_M_u32 = InpSigInvldTimer_mS_M_u32;
	
	AllowCorrectionState_Cnt_M_lgc = TRUE;
	

	if((VehCntrOffset_Cnt_T_u32 != (~R_VehCntrOffset_Cnt_T_u32))||
	   ((uint8)LTVehCntrComplete_Cnt_T_lgc != (uint8)(~R_LTVehCntrComplete_Cnt_T_u8)) ||
		(RacktoVehCntrOffset_Cnt_T_u16 != (uint16)(~R_RacktoVehCntrOffset_Cnt_T_u16)))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagPosTrimStr, 1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagPosTrimStr, 1U, NTC_STATUS_PASSED);
	}
	
	
	
	if(( RacktoVehCntrOffset_Cnt_T_u16 > D_RACKTOVEHCNTRINVALID_CNT_U16 )||
       (RacktoVehCntrOffset_Cnt_T_u16 != (uint16)(~R_RacktoVehCntrOffset_Cnt_T_u16)))
	{
		RacktoVehCntrOffset_Cnt_T_u16 = D_RACKTOVEHCNTRINVALID_CNT_U16;
		Rte_Pim_Trim()->RacktoVehCntrOffset = RacktoVehCntrOffset_Cnt_T_u16;
		Rte_Pim_Trim()->R_RacktoVehCntrOffset = ~(Rte_Pim_Trim()->RacktoVehCntrOffset);
	}
	
	Rte_IWrite_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(LTVehCntrComplete_Cnt_T_lgc);
	Rte_IWrite_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(RacktoVehCntrOffset_Cnt_T_u16);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   SInt16 Rte_IRead_AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16(void)
 *   ST_OFFS_QUAD_EPS Rte_IRead_AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc(void)
 *   SInt8 Rte_IRead_AbsHwPos_Per1_Polarity_Cnt_s08(void)
 *   Float Rte_IRead_AbsHwPos_Per1_RackCenter_HwDeg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32(void)
 *   TurnsCntrValStateType Rte_IRead_AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(void)
 *   void Rte_IWrite_AbsHwPos_Per1_RevOffsetState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AbsHwPos_Per1_RevOffsetState_Cnt_u08(void)
 *   void Rte_IWrite_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC)	TorqueCmdCRF_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC)	DiagStsDefHwPos_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	DiagStsHwPosDis_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) AlignedCumMtrPosMRF_Deg_T_f32;
	VAR(float32, AUTOMATIC)	VehCntrOffset_HwDeg_T_f32;
	
	VAR(uint16,  AUTOMATIC) AbsMtrTrqCmd_MtrNm_T_u4p12;
	VAR(uint16,  AUTOMATIC) ComplianceFactor_HwDegpMtrNm_T_u7p9;
	VAR(float32, AUTOMATIC) ComplError_HwDeg_T_f32;
	VAR(sint16,  AUTOMATIC) SrlComHwPos_HwDeg_T_s11p4;
	VAR(float32, AUTOMATIC) PrevHwPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(uint16, AUTOMATIC) RacktoVehCntrOffset_Cnt_T_u16;

	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AbsHwPos_Per1_CP0_CheckpointReached();
	TorqueCmdCRF_MtrNm_T_f32 = Rte_IRead_AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32();
	DiagStsDefHwPos_Cnt_T_lgc = Rte_IRead_AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc();
	DiagStsHwPosDis_Cnt_T_lgc = Rte_IRead_AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc();
	AlignedCumMtrPosMRF_Deg_T_f32 = Rte_IRead_AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32();

	VehCntrOffset_HwDeg_T_f32 = Rte_Pim_Trim() -> VehCntrOffset;
	RacktoVehCntrOffset_Cnt_T_u16 = Rte_Pim_Trim()-> RacktoVehCntrOffset;
	
	TCMtrPosOffsMRF_Deg_M_f32 = Rte_IRead_AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32();
	Polarity_Cnt_M_s08 = Rte_IRead_AbsHwPos_Per1_Polarity_Cnt_s08();
	TurnsCntrValidity_Cnt_M_enum = Rte_IRead_AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum();
	ICMRevOffsetCRF_Rev_M_s16 = Rte_IRead_AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16();
	ICMRevOffsetStatus_Cnt_M_enum = Rte_IRead_AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08();
	
	
	
	/** Compliance Error Calculation **/
	
	AbsMtrTrqCmd_MtrNm_T_u4p12 = FPM_FloatToFixed_m(Abs_f32_m(TorqueCmdCRF_MtrNm_T_f32), u4p12_T);
	
	ComplianceFactor_HwDegpMtrNm_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt(
											t_MtrPosComplTblX_MtrNm_u4p12,
											t_MtrPosComplTblY_HwDegpMtrNm_u7p9,
											TableSize_m(t_MtrPosComplTblX_MtrNm_u4p12),
											AbsMtrTrqCmd_MtrNm_T_u4p12);
	
	ComplError_HwDeg_T_f32 = (FPM_FixedToFloat_m(ComplianceFactor_HwDegpMtrNm_T_u7p9, u7p9_T)) * TorqueCmdCRF_MtrNm_T_f32;
	
	
	
	/** ICM Offset State and Final Position Determination **/
	
	if( TRUE == DiagStsDefHwPos_Cnt_T_lgc )
	{
		DefaultHwPos();
	}
	else
	{
		if( TRUE == DiagStsHwPosDis_Cnt_T_lgc )
		{
			UntrimmedHwPos();
		}
		else if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_INIT )
		{
			RevOff_HdlSt_Init();
		}
		else if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_COMPENSATE )
		{
			RevOff_HdlSt_Compensate();
		}
		else if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_SUBSTITUTE )
		{
			RevOff_HdlSt_Substitute();
		}
		else if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_TEMPCOMP )
		{
			RevOff_HdlSt_TempComp();
		}
		else if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_CORRECTION )
		{
			RevOff_HdlSt_Correction();
		}
		else
		{
			RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_INVALID;
			RevOff_HdlSt_Invalid();
		}
		
		/* Calculate Mtr and Hw Pos */
		ICMMtrPosMRF_Deg_M_f32 = AlignedCumMtrPosMRF_Deg_T_f32 + RevOffsetMRF_Deg_M_f32;
		
		/* Scale and Compensate */
		AlignedHwPos_HwDeg_M_f32 = (((ICMMtrPosMRF_Deg_M_f32 * ((float32)Polarity_Cnt_M_s08)) / k_InvGearRatio_Uls_f32) - ComplError_HwDeg_T_f32) * k_MtrToHwResConv_Uls_f32;
		
		AlignedHwPos_HwDeg_M_f32 = Limit_m(AlignedHwPos_HwDeg_M_f32, -D_MAXHWPOS_HWDEG_F32, D_MAXHWPOS_HWDEG_F32);
	}
	
	
	
	/** Apply Vehicle Center Offset / Generate Serial Comm HwPos **/
	
	SrlComHwPos_HwDeg_M_f32 = AlignedHwPos_HwDeg_M_f32 - VehCntrOffset_HwDeg_T_f32;
	
	SrlComHwPos_HwDeg_M_f32 = Limit_m(SrlComHwPos_HwDeg_M_f32, -D_MAXHWPOS_HWDEG_F32, D_MAXHWPOS_HWDEG_F32);
	
	
	
	/** Output Smoothing Low Pass Filter **/
	
	SrlComHwPos_HwDeg_T_s11p4 = FPM_FloatToFixed_m(SrlComHwPos_HwDeg_M_f32, s11p4_T);
	PrevHwPosition_HwDeg_T_f32 = FPM_FixedToFloat_m(HwPositionFiltSV_HwDeg_M_s11p20, s11p20_T);
	
	if( Abs_f32_m(PrevHwPosition_HwDeg_T_f32 - SrlComHwPos_HwDeg_M_f32) < k_HwPosOutputLPFError_HwDeg_f32)
	{
		HwPositionFiltSV_HwDeg_M_s11p20 = FPM_FloatToFixed_m(SrlComHwPos_HwDeg_M_f32, s11p20_T);
		HandwheelPosition_HwDeg_T_f32 = SrlComHwPos_HwDeg_M_f32;
	}
	else
	{
		HwPositionFiltSV_HwDeg_M_s11p20 = LPF_SvUpdate_s16InFixKTrunc_m(
												SrlComHwPos_HwDeg_T_s11p4,
												HwPositionFiltSV_HwDeg_M_s11p20,
												k_HwPosOutputLPFCoeffK_Cnt_u16);
		
		HandwheelPosition_HwDeg_T_f32 = FPM_FixedToFloat_m(HwPositionFiltSV_HwDeg_M_s11p20, s11p20_T);
	}
	
	
	
	/** Handwheel Pos Authority Ramp **/
	
	HandwheelAuthority_Uls_M_f32 = Limit_m( HwTargetAuthority_Uls_M_f32,
											HandwheelAuthority_Uls_M_f32 - k_HwPosAuthorityStep_Uls_f32,
											HandwheelAuthority_Uls_M_f32 + k_HwPosAuthorityStep_Uls_f32 );
	
	
	ComplError_HwDeg_D_f32 = ComplError_HwDeg_T_f32;
	Rte_IWrite_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(SrlComHwPos_HwDeg_M_f32);
	Rte_IWrite_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(HandwheelPosition_HwDeg_T_f32);
	Rte_IWrite_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(HandwheelAuthority_Uls_M_f32);
	Rte_IWrite_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(HwTargetAuthority_Uls_M_f32);
	Rte_IWrite_AbsHwPos_Per1_RevOffsetState_Cnt_u08(t_RevOffsetStateCode_Cnt_u08[RevOffsetState_Cnt_M_enum]);
	Rte_IWrite_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(ICMMtrPosMRF_Deg_M_f32);
	Rte_IWrite_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(AlignedHwPos_HwDeg_M_f32);
	Rte_IWrite_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(RacktoVehCntrOffset_Cnt_T_u16);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_AbsHwPos_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc(void)
 *   Boolean Rte_IRead_AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPos_Per2_VehicleSpeed_Kph_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Per2
 *********************************************************************************************************************/
	
	
	VAR(boolean, AUTOMATIC)	DefeatKinIntTest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	LTVehCntrComplete_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	VehCntrOffset_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC)	DiagStsDefVehSpd_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AbsHwPos_Per2_CP0_CheckpointReached();
	DefeatKinIntTest_Cnt_T_lgc = Rte_IRead_AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc();
	LTVehCntrComplete_Cnt_T_lgc = Rte_Pim_Trim() -> LTVehCntrComplete;
	VehCntrOffset_HwDeg_T_f32 = Rte_Pim_Trim() -> VehCntrOffset;
	DiagStsDefVehSpd_Cnt_T_lgc = Rte_IRead_AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc();
	VehSpd_Kph_T_f32 = Rte_IRead_AbsHwPos_Per2_VehicleSpeed_Kph_f32();

	/*** Kinematic Integrity Diagnostic ***/
	
	if( FALSE == DefeatKinIntTest_Cnt_T_lgc )
	{
		if( Abs_f32_m(AlignedHwPos_HwDeg_M_f32) > k_KinmIntDiagMaxRackLimit_HwDeg_f32 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_KinematicIntDiag, 1U, NTC_STATUS_FAILED);
		}
		else
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_KinematicIntDiag, 1U, NTC_STATUS_PASSED);
		}
	}
	
	
	/*** Hand Wheel Position Trim Diagnostic ***/
	
	if( (LTVehCntrComplete_Cnt_T_lgc != TRUE) ||
		(VehCntrOffset_HwDeg_T_f32 > D_MAXVEHCNTR_HWDEG_F32) ||
		(VehCntrOffset_HwDeg_T_f32 < -D_MAXVEHCNTR_HWDEG_F32) )
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_PASSED);
	}
	

	/*** Loss Of Absolute HwPosition Diagnostic ***/
	
	if (((RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_INVALID) || (RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_SUBSTITUTE)))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_PosLossNotSpdDep, 1U, NTC_STATUS_FAILED);
		
		if (((TRUE == DiagStsDefVehSpd_Cnt_T_lgc)|| (VehSpd_Kph_T_f32 > k_MinVehSpdReqVldAbsPos_kph_f32)))
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_PosLoss, 1U, NTC_STATUS_FAILED);
		}
		else
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_PosLoss, 1U, NTC_STATUS_PASSED);
		}
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_PosLossNotSpdDep, 1U, NTC_STATUS_PASSED);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_PosLoss, 1U, NTC_STATUS_PASSED);
	}
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_AbsHwPos_Per2_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_VehicleSystemStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehicleSystemStatus> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SCom_VehicleSystemStatus(SInt16 *NCMAbsHwPos_HwDeg_s11p4)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_SCom_VehicleSystemStatus
 *********************************************************************************************************************/
	
	
	VAR(sint16, AUTOMATIC) SrlComHwPos_HwDeg_T_s11p4;
	
	
	if( HwTargetAuthority_Uls_M_f32 < D_MAXCONF_ULS_F32 )
	{
		SrlComHwPos_HwDeg_T_s11p4 = 0;
	}
	else
	{
		SrlComHwPos_HwDeg_T_s11p4 = FPM_FloatToFixed_m(SrlComHwPos_HwDeg_M_f32, s11p4_T);
	}
	
	
	*NCMAbsHwPos_HwDeg_s11p4 = SrlComHwPos_HwDeg_T_s11p4;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_ClearCenterPosition
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TurnsCounter_Scom_ResetTC(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_Scom_ClearCenterPosition(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearCenterPosition(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Scom_ClearCenterPosition
 *********************************************************************************************************************/

	VAR(uint32, AUTOMATIC) VehCntrOffset_Cnt_T_u32;


	/* Clear Vehicle Center Offset */
	
	VehCntrComplete_Cnt_M_lgc = FALSE;
	
	Rte_Pim_Trim()-> LTVehCntrComplete = FALSE;
	Rte_Pim_Trim()-> R_LTVehCntrComplete = ~(uint8)(Rte_Pim_Trim()-> LTVehCntrComplete );
	
	(void)Rte_Write_LTVehCenterComplete_Cnt_lgc(FALSE);
	
	Rte_Pim_Trim()-> VehCntrOffset = D_ZERO_ULS_F32;
	VehCntrOffset_Cnt_T_u32 = *(uint32 *)&(Rte_Pim_Trim()-> VehCntrOffset);
	Rte_Pim_Trim()-> R_VehCntrOffset = ~VehCntrOffset_Cnt_T_u32;
	
	
	(void)Rte_Call_Trim_WriteBlock(NULL_PTR);
	
	/*TODO: When implementing RackCentering SF-39, The following Clear/Reset data function calls were moved to the BMW customer service handler (CDC_User);
	        future updates might be required to accommodate both the Customer and Nxtr Common Mfg services: */

	/* Clear Rack Center Items */
	/* Reset the rack to vehicle center offset */
	/* Reset TC Processor */
	/* Clear CW/CCW EOT Items */
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_ClearRacktoVehCntrOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearRacktoVehCntrOffset> of PortPrototype <RacktoVehCntrOffset_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_Scom_ClearRacktoVehCntrOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Scom_ClearRacktoVehCntrOffset
 *********************************************************************************************************************/
	
	Rte_Pim_Trim()->RacktoVehCntrOffset = D_RACKTOVEHCNTRUNLEARNED_CNT_U16;
	Rte_Pim_Trim()->R_RacktoVehCntrOffset = ~(Rte_Pim_Trim()->RacktoVehCntrOffset);
	(void)Rte_Call_Trim_WriteBlock(NULL_PTR);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_SetCenterPosition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagStsDefHwPos_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_LTRckCntrComplete_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RackCenter_HwDeg_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VehicleCenter_Scom_E_NOT_OK
 *   RTE_E_VehicleCenter_Scom_E_NOT_OK_OUTOFRANGE
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_Scom_SetCenterPosition (returns application error)
 *********************************************************************************************************************/
	
	
	VAR(boolean, AUTOMATIC) DiagStsDefHwPos_Cnt_T_lgc;
	VAR(Std_ReturnType, AUTOMATIC) RetValue_Cnt_T_enum;
	VAR(float32, AUTOMATIC) RackCntrOffset_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) LTRckCntrComplete_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC)VehCntrOffset_Cnt_T_u32;
	
	(void)Rte_Read_DiagStsDefHwPos_Cnt_lgc(&DiagStsDefHwPos_Cnt_T_lgc);
	(void)Rte_Read_RackCenter_HwDeg_f32(&RackCntrOffset_HwDeg_T_f32);
	(void)Rte_Read_LTRckCntrComplete_Cnt_lgc(&LTRckCntrComplete_Cnt_T_lgc);
	
	if( (D_RACKTOVEHCNTRUNLEARNED_CNT_U16 == Rte_Pim_Trim()->RacktoVehCntrOffset) &&
		(FALSE == Rte_Pim_Trim()->LTVehCntrComplete) &&
		(RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_INVALID) &&
		(FALSE == DiagStsDefHwPos_Cnt_T_lgc) )
	{
		if (Abs_f32_m(AlignedHwPos_HwDeg_M_f32 - Offset_HwDeg_P_f32) <= D_MAXVEHCNTR_HWDEG_F32)
		{
			Rte_Pim_Trim() -> VehCntrOffset = AlignedHwPos_HwDeg_M_f32 - Offset_HwDeg_P_f32;
			VehCntrOffset_Cnt_T_u32 = *(uint32 *)&(Rte_Pim_Trim() -> VehCntrOffset);
			Rte_Pim_Trim() -> R_VehCntrOffset = ~VehCntrOffset_Cnt_T_u32;
			
			Rte_Pim_Trim()->LTVehCntrComplete = TRUE;
			Rte_Pim_Trim()->R_LTVehCntrComplete = ~(uint8)Rte_Pim_Trim()->LTVehCntrComplete;
			
			(void)Rte_Call_Trim_WriteBlock(NULL_PTR);
			(void)Rte_Write_LTVehCenterComplete_Cnt_lgc(TRUE);
			
			VehCntrComplete_Cnt_M_lgc = TRUE;
			SetRacktoVehCntrOffset(RackCntrOffset_HwDeg_T_f32, LTRckCntrComplete_Cnt_T_lgc);

			RetValue_Cnt_T_enum = RTE_E_OK;
		}
		else
		{
			RetValue_Cnt_T_enum = RTE_E_VehicleCenter_Scom_E_NOT_OK_OUTOFRANGE;
		}
	}
	else
	{
		RetValue_Cnt_T_enum = RTE_E_VehicleCenter_Scom_E_NOT_OK;
	}
	
	
	return RetValue_Cnt_T_enum;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SetData_SetRacktoVehCntrOffset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRacktoVehCntrOffset> of PortPrototype <AbsHwPos_SetData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPos_SetData_SetRacktoVehCntrOffset
 *********************************************************************************************************************/

	SetRacktoVehCntrOffset(RackCntr_HwDeg_P_f32, LTRckCntrComplete_Cnt_P_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*****************************************************************************
 * Local Fn:	SetRacktoVehCntrOffset
 *
 * Inputs: RackCntrOffset_HwDeg_T_f32
 *
 * Only called until Rack and vehicle center is learned.
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) SetRacktoVehCntrOffset(VAR(float32, AUTOMATIC) RackCntrOffset_HwDeg_T_f32,
		                                                       VAR(boolean, AUTOMATIC) LTRckCntrComplete_Cnt_T_lgc)
{
	/* inputs */
	VAR(boolean, AUTOMATIC)	LTVehCntrComplete_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	VehCntrOffset_HwDeg_T_f32;
	VAR(float32, AUTOMATIC)	RacktoVehCntrOffset_HwDeg_T_f32;

	/* output */
	VAR(uint16,  AUTOMATIC) RacktoVehCntrOffset_Cnt_T_u16;

	RacktoVehCntrOffset_Cnt_T_u16 = Rte_Pim_Trim()->RacktoVehCntrOffset;
	LTVehCntrComplete_Cnt_T_lgc = Rte_Pim_Trim()->LTVehCntrComplete;
	VehCntrOffset_HwDeg_T_f32 = Rte_Pim_Trim() -> VehCntrOffset;
	
	if(D_RACKTOVEHCNTRUNLEARNED_CNT_U16 == RacktoVehCntrOffset_Cnt_T_u16)
	{
		if( (TRUE == LTRckCntrComplete_Cnt_T_lgc) &&
			(TRUE == LTVehCntrComplete_Cnt_T_lgc) &&
			( (REVOFFSET_STATE_COMPENSATE == RevOffsetState_Cnt_M_enum) || (REVOFFSET_STATE_INVALID == RevOffsetState_Cnt_M_enum) ) )
		{
			RacktoVehCntrOffset_HwDeg_T_f32 = RackCntrOffset_HwDeg_T_f32 - VehCntrOffset_HwDeg_T_f32;

			/* Apply customer (BMW) polarity inversion, scaling and offset described in the SER to RacktoVehCntrOffset for transmission on the bus as the OFFS_GRD_MID_EPS signal */
			/* SrlComOutput will read the RacktoVehCntrOffset_Cnt_T_u16 output from this module and transmit the value as is */
			RacktoVehCntrOffset_HwDeg_T_f32 = RacktoVehCntrOffset_HwDeg_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
			RacktoVehCntrOffset_HwDeg_T_f32 = ((RacktoVehCntrOffset_HwDeg_T_f32/D_R2VRES_HWDEGPCNT_F32) + D_R2VMSGOFF_CNT_F32);

       		if ( (RacktoVehCntrOffset_HwDeg_T_f32 < D_R2VMIN_CNT_F32) || (RacktoVehCntrOffset_HwDeg_T_f32 > D_R2VMAX_CNT_F32) )
			{
				RacktoVehCntrOffset_Cnt_T_u16 = D_RACKTOVEHCNTRINVALID_CNT_U16;
			}
			else
			{
				RacktoVehCntrOffset_Cnt_T_u16 = (uint16)RacktoVehCntrOffset_HwDeg_T_f32;
			}
		
			Rte_Pim_Trim()->RacktoVehCntrOffset = RacktoVehCntrOffset_Cnt_T_u16;
			Rte_Pim_Trim()->R_RacktoVehCntrOffset = ~(Rte_Pim_Trim()->RacktoVehCntrOffset);
			(void)Rte_Call_Trim_WriteBlock(NULL_PTR);
		}
	}
}


/*****************************************************************************
 * Local Fn:	Default_HwPos()
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) DefaultHwPos( void )
{
	
	RevOffsetMRF_Deg_M_f32 = D_ZERO_ULS_F32;
	ICMMtrPosMRF_Deg_M_f32 = D_ZERO_ULS_F32;
	AlignedHwPos_HwDeg_M_f32 = D_ZERO_ULS_F32;
	ICMAuthority_Uls_M_f32 = D_NOAUTH_ULS_F32;
	HwTargetAuthority_Uls_M_f32 = D_NOAUTH_ULS_F32;
	RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_INVALID;
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InpSigInvldTimer_mS_M_u32);
	ClrIncmpHwPosLrn();
	
}


/*****************************************************************************
 * Local Fn:	Clear Incomplete Handwheel Position Learned Items
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) ClrIncmpHwPosLrn( void )
{
	VAR(boolean, AUTOMATIC)	LTRckCntrComplete_Cnt_T_lgc;

	LTRckCntrComplete_Cnt_T_lgc = Rte_IRead_AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc(); 

	if( (D_RACKTOVEHCNTRUNLEARNED_CNT_U16 == Rte_Pim_Trim()->RacktoVehCntrOffset) &&
		(LTRckCntrComplete_Cnt_T_lgc != Rte_Pim_Trim()-> LTVehCntrComplete) )
	{
		AbsHwPos_Scom_ClearCenterPosition();

		(void)Rte_Call_TurnsCounter_Scom_ResetTC();
		(void)Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev();
		(void)Rte_Call_LrnEOT_Scom_ResetEOT();

	}
	
}


/*****************************************************************************
 * Local Fn:	Untrimmed_HwPos()
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) UntrimmedHwPos( void )
{
	if( TurnsCntrValidity_Cnt_M_enum != TCV_COMPUTING )
	{
		if( TurnsCntrValidity_Cnt_M_enum == TCV_VALID )
		{
			RevOffsetMRF_Deg_M_f32 = TCMtrPosOffsMRF_Deg_M_f32;
		}
		else
		{
			RevOffsetMRF_Deg_M_f32 = D_ZERO_ULS_F32;
			if( RevOffsetState_Cnt_M_enum == REVOFFSET_STATE_INIT )
			{
				ClrIncmpHwPosLrn();
			}
		}
		
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_INVALID;
	}

	ICMAuthority_Uls_M_f32 = D_NOAUTH_ULS_F32;
	HwTargetAuthority_Uls_M_f32 = D_NOAUTH_ULS_F32;
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InpSigInvldTimer_mS_M_u32);
}


/*****************************************************************************
 * Local Fn:	Update RevOffset()
 *****************************************************************************/
STATIC INLINE FUNC(void, AP_TCBASEDHWPOS_CODE) UpdateRevOffset( void )
{
	
	RevOffsetMRF_Deg_M_f32 += ((float32)Polarity_Cnt_M_s08) * ((float32)ICMRevOffsetCRF_Rev_M_s16) * D_360_DEGPREV_F32;
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_INIT
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Init(void)
{
	
	if( TCV_VALID == TurnsCntrValidity_Cnt_M_enum )
	{
		RevOffsetMRF_Deg_M_f32 = TCMtrPosOffsMRF_Deg_M_f32;
		HwTargetAuthority_Uls_M_f32 = k_TurnsCntrAuthority_Uls_f32;
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
		AllowCorrectionState_Cnt_M_lgc = TRUE;
	}
	else if( TCV_COMPUTING != TurnsCntrValidity_Cnt_M_enum )
	{
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_SUBSTITUTE;
		ClrIncmpHwPosLrn();
	}
	else
	{
		/* Do Nothing */
	}
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_COMPENSATE
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Compensate(void)
{
	VAR(uint16, AUTOMATIC)	ElapsedTime_mS_T_u16;
	
	if( (Abs_f32_m(ICMAuthority_Uls_M_f32 - k_ICMAuthority_Uls_f32) < D_AUTHORITYTOL_ULS_F32) ||
		(TCV_VALID == TurnsCntrValidity_Cnt_M_enum) )
	{
		if (STOFFSQUADEPS_CORRECTION == ICMRevOffsetStatus_Cnt_M_enum)
		{
			if (AllowCorrectionState_Cnt_M_lgc == TRUE)
			{
				UpdateRevOffset();
				ICMAuthority_Uls_M_f32 = k_OffCorrAuthority_Uls_f32;
				HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
				RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_CORRECTION;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&OffCorrTimer_mS_M_u32);
				(void)Rte_Call_TurnsCounter_Scom_ResetTC();
			}
		}
		else
		{
			if (STOFFSQUADEPS_INVALID != ICMRevOffsetStatus_Cnt_M_enum)
			{
				AllowCorrectionState_Cnt_M_lgc = TRUE;
			}
		}
		
	}
	else
	{
		DefaultHwPos();
	}
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_SUBSTITUTE
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Substitute(void)
{
	
	if( (STOFFSQUADEPS_MODELCOMP == ICMRevOffsetStatus_Cnt_M_enum) ||
		(STOFFSQUADEPS_LOCKTOLOCK == ICMRevOffsetStatus_Cnt_M_enum) ||
		(STOFFSQUADEPS_SUMSTEERINGANGLE == ICMRevOffsetStatus_Cnt_M_enum) )
	{
		UpdateRevOffset();
		ICMAuthority_Uls_M_f32 = k_ICMAuthority_Uls_f32;
		HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
		AllowCorrectionState_Cnt_M_lgc = TRUE;
	}
	else if( STOFFSQUADEPS_APPROXIMATED == ICMRevOffsetStatus_Cnt_M_enum )
	{
		UpdateRevOffset();
		ICMAuthority_Uls_M_f32 = k_TmpCompAuthority_Uls_f32;
		HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_TEMPCOMP;
	}
	else
	{
		/* Do Nothing */
	}
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_TEMPCOMP
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_TempComp(void)
{
	
	if( (STOFFSQUADEPS_MODELCOMP == ICMRevOffsetStatus_Cnt_M_enum) ||
		(STOFFSQUADEPS_LOCKTOLOCK == ICMRevOffsetStatus_Cnt_M_enum) ||
		(STOFFSQUADEPS_SUMSTEERINGANGLE == ICMRevOffsetStatus_Cnt_M_enum) )
	{
		UpdateRevOffset();
		ICMAuthority_Uls_M_f32 = k_ICMAuthority_Uls_f32;
		HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
		AllowCorrectionState_Cnt_M_lgc = TRUE;
	}
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_CORRECTION
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Correction(void)
{
	VAR(uint16, AUTOMATIC) 	ElapsedTime_mS_T_u16;
	
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(OffCorrTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
	
	if( ElapsedTime_mS_T_u16 >= k_OffsCorrectionTimer_mS_u16 )
	{
		ICMAuthority_Uls_M_f32 = k_ICMAuthority_Uls_f32;
		HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
		RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
		AllowCorrectionState_Cnt_M_lgc = FALSE;
	}
	
}


/*****************************************************************************
 * Handle State:	REVOFFSET_STATE_INVALID
 *****************************************************************************/
STATIC FUNC(void, AP_TCBASEDHWPOS_CODE) RevOff_HdlSt_Invalid(void)
{
	VAR(uint16, AUTOMATIC) 	ElapsedTime_mS_T_u16;
	
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(InpSigInvldTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
	
	if( ElapsedTime_mS_T_u16 >= k_InpSignalInvalidTimer_mS_u16 )
	{
		if( VehCntrComplete_Cnt_M_lgc == TRUE )
		{
			ICMAuthority_Uls_M_f32 = k_ICMAuthority_Uls_f32;
			HwTargetAuthority_Uls_M_f32 = ICMAuthority_Uls_M_f32;
			RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
			AllowCorrectionState_Cnt_M_lgc = TRUE;
		}
		else if( TCV_VALID == TurnsCntrValidity_Cnt_M_enum )
		{
			RevOffsetMRF_Deg_M_f32 = TCMtrPosOffsMRF_Deg_M_f32;
			HwTargetAuthority_Uls_M_f32 = k_TurnsCntrAuthority_Uls_f32;
			RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_COMPENSATE;
			AllowCorrectionState_Cnt_M_lgc = TRUE;
		}
		else
		{
			RevOffsetMRF_Deg_M_f32 = D_ZERO_ULS_F32;
			RevOffsetState_Cnt_M_enum = REVOFFSET_STATE_SUBSTITUTE;
		}
	}
	
}



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
