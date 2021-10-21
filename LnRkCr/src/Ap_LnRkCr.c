/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_LnRkCr.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LnRkCr-nzt9hv/LnRkCr/autosar
 *     SW-C Type:  Ap_LnRkCr
 *  Generated at:  Fri Sep 21 13:52:48 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_LnRkCr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Nov  11 13:31:18 2011
 * %version:          3 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Fri Sep 21 13:13:43 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/17/12  1        BDO  		Initial implementation of SF-39 'Learn Rack Center'							  6030
 * 08/20/12  2        BDO  		Correct PIM references, QAC
 * 09/21/12  3        Selva      Checkpoints added and mempmap macros corrected		                          6233
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

#include "Rte_Ap_LnRkCr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_LnRkCr_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "fpmtype.h"
#include "fixmath.h"


#define D_360_DEGPREV_F32		360.0f

#define LNRKCR_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(boolean, AP_LNRKCR_VAR) RackCntrComplete_Cnt_M_lgc;
STATIC VAR(boolean, AP_LNRKCR_VAR) ManRCMinFound_Cnt_M_lgc;
STATIC VAR(boolean, AP_LNRKCR_VAR) ManRCMaxFound_Cnt_M_lgc;
STATIC VAR(boolean, AP_LNRKCR_VAR) RCMtrAngleError_Cnt_M_lgc;
STATIC VAR(boolean, AP_LNRKCR_VAR) RCMtrAngleFound_Cnt_M_lgc;
#define LNRKCR_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#define LNRKCR_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AP_LNRKCR_VAR) AlignedHandwheelPosition_HwDeg_M_f32;

STATIC VAR(sint32, AP_LNRKCR_VAR) ManRCFilteredHwPosSV_HwDeg_M_s11p20;
STATIC VAR(float32, AP_LNRKCR_VAR) ManRCFilteredHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_LNRKCR_VAR) ManRCMinHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_LNRKCR_VAR) ManRCMaxHwPos_HwDeg_M_f32;

STATIC VAR(uint32, AP_LNRKCR_VAR) ManRCMinTimer_mS_M_u32;
STATIC VAR(uint32, AP_LNRKCR_VAR) ManRCMaxTimer_mS_M_u32;

STATIC VAR(float32, AP_LNRKCR_VAR) ManTotalRackTravel_HwDeg_M_f32;
STATIC VAR(float32, AP_LNRKCR_VAR) ConvHwDegMtrRev_HwDegpMtrRev_M_f32;

STATIC VAR(float32, AP_LNRKCR_VAR) ManRCHwDeg_HwDeg_M_f32;


STATIC VAR(float32, AP_LNRKCR_VAR) RackCenterOutput_HwDeg_M_f32;

STATIC volatile VAR(float32, AP_LNRKCR_VAR) RCMtrRev_MtrRev_D_f32;
#define LNRKCR_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) AdjRCMtrRevToStoredMtrDeg(P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrRev,
		                                                             P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrDeg);

STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) FindRackCenterComponents(VAR(float32, AUTOMATIC) RC_HwDeg,
																	P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrRev,
																	P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrDeg);

STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) ResetCommonRCvars(void);

STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) ConfirmRckCntrFound(VAR(boolean, AUTOMATIC) AutoRckCntr_Cnt_T_lgc,
														            VAR(float32, AUTOMATIC) TotalRackTravel_HwDeg_T_f32,
														            VAR(float32, AUTOMATIC) RCHwDeg_HwDeg_T_f32);

STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) UpdateNewRckCntrValues(VAR(float32, AUTOMATIC) TotalRackTravel_HwDeg_T_f32,
														               VAR(float32, AUTOMATIC) RC_MtrRev,
														               VAR(float32, AUTOMATIC) RC_MtrDeg);



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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * LktoLkStrStateType: Enumeration of integer in interval [0...7] with enumerators
 *   HOLD (0u)
 *   POSANGVEL (1u)
 *   POSMTRTRQ (2u)
 *   NEGANGVEL (3u)
 *   NEGMTRTRQ (4u)
 *   MOVETO (5u)
 *   DONE (6u)
 *   TIMEOUT (7u)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_WhlImbAlgFlt (224u)
 *   NTC_Num_PAHwVelFlt (225u)
 *   NTC_Num_AngleCntrlFltC (226u)
 *   NTC_Num_AngleCntrlFltD (227u)
 *   NTC_Num_AngleCntrlFltFG (228u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * RackCenterType: Record with elements
 *   TotalRackTravel_HwDeg_f32 of type Float
 *   RackCntrMtrDeg_MtrDeg_f32 of type Float
 *   RackCntrMtrRev_MtrRev_f32 of type Float
 *   RackCntrComplete_Cnt_lgc of type Boolean
 *   RackCntrMtrAngleFound_Cnt_lgc of type Boolean
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
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   RackCenterType *Rte_Pim_LearnedRackCntr(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_LNRKCR_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_LnRkCr_Init1_AlignedHwPos_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LnRkCr_Init1_RackCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LnRkCr_Init1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) RCMtrRev_MtrRev_T_f32;
	VAR(float32, AUTOMATIC) RCMtrDeg_MtrDeg_T_f32;

	AlignedHandwheelPosition_HwDeg_M_f32 = Rte_IRead_LnRkCr_Init1_AlignedHwPos_HwDeg_f32();

	ResetCommonRCvars();

	ConvHwDegMtrRev_HwDegpMtrRev_M_f32 = D_360_DEGPREV_F32/k_InvGearRatio_Uls_f32;

	RCMtrAngleFound_Cnt_M_lgc = Rte_Pim_LearnedRackCntr()->RackCntrMtrAngleFound_Cnt_lgc;
	RCMtrRev_MtrRev_T_f32 = Rte_Pim_LearnedRackCntr()->RackCntrMtrRev_MtrRev_f32;
	RCMtrDeg_MtrDeg_T_f32 = Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32;

	RackCenterOutput_HwDeg_M_f32 = ((RCMtrRev_MtrRev_T_f32 * D_360_DEGPREV_F32) + RCMtrDeg_MtrDeg_T_f32) * k_GearRatio_Uls_f32;

	RackCntrComplete_Cnt_M_lgc = FALSE;

	if (RCMtrDeg_MtrDeg_T_f32 > D_360_DEGPREV_F32)
	{
		RCMtrAngleFound_Cnt_M_lgc = FALSE;
		RCMtrAngleError_Cnt_M_lgc = TRUE;	/* TODO: static var used to indicate error, an NTC could be used in the future */
	}
	else
	{
		RCMtrAngleError_Cnt_M_lgc = FALSE; /* TODO: static var used to indicate error, an NTC could be used in the future */
	}

	Rte_IWrite_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(RackCntrComplete_Cnt_M_lgc);
	Rte_IWrite_LnRkCr_Init1_RackCenter_HwDeg_f32(RackCenterOutput_HwDeg_M_f32);
	Rte_IWrite_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc);
	Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(RCMtrAngleFound_Cnt_M_lgc);
	Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(RCMtrAngleError_Cnt_M_lgc);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_LnRkCr_Per1_AlignedHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc(void)
 *   Float Rte_IRead_LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32(void)
 *   Float Rte_IRead_LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32(void)
 *   LktoLkStrStateType Rte_IRead_LnRkCr_Per1_LrnPnCntrState_Cnt_enum(void)
 *   Float Rte_IRead_LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LnRkCr_Per1_RackCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LnRkCr_Per1
 *********************************************************************************************************************/


	VAR(LktoLkStrStateType, AUTOMATIC) LrnPnCntrState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) LrnPnCntrEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) LrnPnCntrHwTravel_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) LrnPnCntrHwCenter_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32;
	VAR(sint16, AUTOMATIC) AlignedHandwheelPosition_HwDeg_T_s11p4;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_LnRkCr_Per1_CP0_CheckpointReached();
	
	AlignedHandwheelPosition_HwDeg_M_f32 = Rte_IRead_LnRkCr_Per1_AlignedHwPos_HwDeg_f32();
	MtrVel_MtrRadpS_T_f32 = Rte_IRead_LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32();
	LrnPnCntrEnable_Cnt_T_lgc = Rte_IRead_LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc();
	LrnPnCntrState_Cnt_T_enum = Rte_IRead_LnRkCr_Per1_LrnPnCntrState_Cnt_enum();
	LrnPnCntrHwTravel_HwDeg_T_f32 = Rte_IRead_LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32();
	LrnPnCntrHwCenter_HwDeg_T_f32 = Rte_IRead_LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32();
	CRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32();

	AbsMtrVel_MtrRadpS_T_f32 = Abs_f32_m(MtrVel_MtrRadpS_T_f32);

	if( Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc == FALSE )
	{
		/* FIND RACK CENTER */
		AlignedHandwheelPosition_HwDeg_T_s11p4 = FPM_FloatToFixed_m(AlignedHandwheelPosition_HwDeg_M_f32, s11p4_T);

		ManRCFilteredHwPosSV_HwDeg_M_s11p20 = LPF_SvUpdate_s16InFixKTrunc_m(
												AlignedHandwheelPosition_HwDeg_T_s11p4,
												ManRCFilteredHwPosSV_HwDeg_M_s11p20,
												k_RCLPFCoeffK_Cnt_u16);

		ManRCFilteredHwPos_HwDeg_M_f32 = FPM_FixedToFloat_m(ManRCFilteredHwPosSV_HwDeg_M_s11p20, s11p20_T);

		if (AbsMtrVel_MtrRadpS_T_f32 > k_RCMtrVel_MtrRadpS_f32)
		{
			ManRCFilteredHwPosSV_HwDeg_M_s11p20 = AlignedHandwheelPosition_HwDeg_T_s11p4;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
			ManRCMaxTimer_mS_M_u32 = ManRCMinTimer_mS_M_u32;
		}
		else if (AlignedHandwheelPosition_HwDeg_M_f32 < (ManRCMinHwPos_HwDeg_M_f32 - k_RCPosChg_HwDeg_f32))
		{
			ManRCMinHwPos_HwDeg_M_f32 = ( ((1 - k_OutlierAdjAmt_Uls_f32) *  ManRCMinHwPos_HwDeg_M_f32) + (k_OutlierAdjAmt_Uls_f32 * AlignedHandwheelPosition_HwDeg_M_f32) );

			ManRCMinFound_Cnt_M_lgc = FALSE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
			ManRCMaxTimer_mS_M_u32 = ManRCMinTimer_mS_M_u32;
		}
		else if (AlignedHandwheelPosition_HwDeg_M_f32 > (ManRCMaxHwPos_HwDeg_M_f32 + k_RCPosChg_HwDeg_f32))
		{
			ManRCMaxHwPos_HwDeg_M_f32 = ( ((1 - k_OutlierAdjAmt_Uls_f32) * ManRCMaxHwPos_HwDeg_M_f32) + (k_OutlierAdjAmt_Uls_f32 * AlignedHandwheelPosition_HwDeg_M_f32) );

			ManRCMaxFound_Cnt_M_lgc = FALSE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
			ManRCMaxTimer_mS_M_u32 = ManRCMinTimer_mS_M_u32;
		}
		else if ( CRFMtrTrqCmd_MtrNm_T_f32 <= (-k_RCMtrTrq_MtrNm_f32) )
		{
			ManRCMinHwPos_HwDeg_M_f32 = Min_m(ManRCMinHwPos_HwDeg_M_f32, ManRCFilteredHwPos_HwDeg_M_f32);

			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMaxTimer_mS_M_u32);
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ManRCMinTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

			if( ElapsedTime_mS_T_u16 > k_RCTimer_mS_u16)
			{
				ManRCMinFound_Cnt_M_lgc = TRUE;
			}
		}
		else if ( CRFMtrTrqCmd_MtrNm_T_f32 >= k_RCMtrTrq_MtrNm_f32 )
		{
			ManRCMaxHwPos_HwDeg_M_f32 = Max_m(ManRCMaxHwPos_HwDeg_M_f32, ManRCFilteredHwPos_HwDeg_M_f32);

			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ManRCMaxTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

			if( ElapsedTime_mS_T_u16 > k_RCTimer_mS_u16)
			{
				ManRCMaxFound_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
			ManRCMaxTimer_mS_M_u32 = ManRCMinTimer_mS_M_u32;
		}

		ManTotalRackTravel_HwDeg_M_f32 = ManRCMaxHwPos_HwDeg_M_f32 - ManRCMinHwPos_HwDeg_M_f32;
		ManRCHwDeg_HwDeg_M_f32 = (ManRCMaxHwPos_HwDeg_M_f32 + ManRCMinHwPos_HwDeg_M_f32)/2;


		/* CHECK RACK CENTER FOUND */
		if (LrnPnCntrState_Cnt_T_enum == DONE)
		{
			ConfirmRckCntrFound(TRUE, LrnPnCntrHwTravel_HwDeg_T_f32, LrnPnCntrHwCenter_HwDeg_T_f32);
		}
		else
		{
			if ((LrnPnCntrEnable_Cnt_T_lgc == FALSE) &&
			    (ManRCMinFound_Cnt_M_lgc == TRUE) &&
			    (ManRCMaxFound_Cnt_M_lgc == TRUE))
			{
				ConfirmRckCntrFound(FALSE, ManTotalRackTravel_HwDeg_M_f32, ManRCHwDeg_HwDeg_M_f32);
			}
		}

	}

	Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(RCMtrAngleFound_Cnt_M_lgc);
	Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(RCMtrAngleError_Cnt_M_lgc);

	Rte_IWrite_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(RackCntrComplete_Cnt_M_lgc);
	Rte_IWrite_LnRkCr_Per1_RackCenter_HwDeg_f32(RackCenterOutput_HwDeg_M_f32);
	Rte_IWrite_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_LnRkCr_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Scom_ResetRckCntrMtrDeg
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetRckCntrMtrDeg> of PortPrototype <LnRkCr_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LnRkCr_Scom_ResetRckCntrMtrDeg(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrDeg(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LnRkCr_Scom_ResetRckCntrMtrDeg
 *********************************************************************************************************************/

	RCMtrAngleFound_Cnt_M_lgc = FALSE;
	Rte_Pim_LearnedRackCntr()->RackCntrMtrAngleFound_Cnt_lgc = FALSE;
	Rte_Pim_LearnedRackCntr()->TotalRackTravel_HwDeg_f32 = 0.0f;
	Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32 = 0.0f;

	Rte_Call_LearnedRackCntrData_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Scom_ResetRckCntrMtrRev
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetRckCntrMtrRev> of PortPrototype <LnRkCr_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LnRkCr_Scom_ResetRckCntrMtrRev
 *********************************************************************************************************************/

	ResetCommonRCvars();

	RackCenterOutput_HwDeg_M_f32 = 0.0f;
	Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc = FALSE;
	Rte_Pim_LearnedRackCntr()->RackCntrMtrRev_MtrRev_f32 = 0.0f;

	Rte_Call_LearnedRackCntrData_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_LNRKCR_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) ResetCommonRCvars(void)
{

	ManRCFilteredHwPosSV_HwDeg_M_s11p20 = FPM_FloatToFixed_m(AlignedHandwheelPosition_HwDeg_M_f32, s11p20_T);
	ManRCFilteredHwPos_HwDeg_M_f32 = AlignedHandwheelPosition_HwDeg_M_f32;
	ManRCMinHwPos_HwDeg_M_f32 = AlignedHandwheelPosition_HwDeg_M_f32;
	ManRCMaxHwPos_HwDeg_M_f32 = AlignedHandwheelPosition_HwDeg_M_f32;
	ManRCMinFound_Cnt_M_lgc = FALSE;
	ManRCMaxFound_Cnt_M_lgc = FALSE;

	Rte_Call_SystemTime_GetSystemTime_mS_u32(&ManRCMinTimer_mS_M_u32);
	ManRCMaxTimer_mS_M_u32 = ManRCMinTimer_mS_M_u32;

	ManTotalRackTravel_HwDeg_M_f32 = 0.0f;
	ManRCHwDeg_HwDeg_M_f32 = 0.0f;
	RackCntrComplete_Cnt_M_lgc = FALSE;
}


STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) ConfirmRckCntrFound(VAR(boolean, AUTOMATIC) AutoRckCntr_Cnt_T_lgc,
		                                                            VAR(float32, AUTOMATIC) TotalRackTravel_HwDeg_T_f32,
														            VAR(float32, AUTOMATIC) RCHwDeg_HwDeg_T_f32)
{
	VAR(float32, AUTOMATIC) RCMtrRev_MtrRev_T_f32;
	VAR(float32, AUTOMATIC) RCMtrDeg_MtrDeg_T_f32;

	if(TotalRackTravel_HwDeg_T_f32 > k_MinRackCntrDisp_HwDeg_f32)
	{
		FindRackCenterComponents(RCHwDeg_HwDeg_T_f32, &RCMtrRev_MtrRev_T_f32, &RCMtrDeg_MtrDeg_T_f32);

		if (RCMtrAngleFound_Cnt_M_lgc == FALSE)
		{
			if( (AutoRckCntr_Cnt_T_lgc == TRUE) || (k_AllowFirstTimeManRC_Cnt_lgc == TRUE) )
			{
				UpdateNewRckCntrValues(TotalRackTravel_HwDeg_T_f32, RCMtrRev_MtrRev_T_f32, RCMtrDeg_MtrDeg_T_f32);
			}
		}
		else
		{
			if ( (Abs_f32_m(TotalRackTravel_HwDeg_T_f32 - (Rte_Pim_LearnedRackCntr()->TotalRackTravel_HwDeg_f32))) < ConvHwDegMtrRev_HwDegpMtrRev_M_f32)
			{
				AdjRCMtrRevToStoredMtrDeg(&RCMtrRev_MtrRev_T_f32, &RCMtrDeg_MtrDeg_T_f32);
				UpdateNewRckCntrValues(TotalRackTravel_HwDeg_T_f32, RCMtrRev_MtrRev_T_f32, RCMtrDeg_MtrDeg_T_f32);
			}
		}
	}
}


/* Find the RC motor rev in HwPos coordinates */
STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) FindRackCenterComponents(VAR(float32, AUTOMATIC) RC_HwDeg,
																	     P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrRev,
																	     P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrDeg)
{
	VAR(float32, AUTOMATIC) TempRCMtrRev_MtrRev_T_f32;
	VAR(sint16, AUTOMATIC) RCMtrRev_MtrRev_T_s15p0;

	TempRCMtrRev_MtrRev_T_f32 = (RC_HwDeg / ConvHwDegMtrRev_HwDegpMtrRev_M_f32);

	RCMtrRev_MtrRev_T_s15p0 = FPM_FloatToFixed_m(TempRCMtrRev_MtrRev_T_f32, s15p0_T);
	*RC_MtrRev = FPM_FixedToFloat_m(RCMtrRev_MtrRev_T_s15p0, s15p0_T);

	RCMtrRev_MtrRev_D_f32 = *RC_MtrRev; /* Display only */

	if (RC_HwDeg < 0.0f)
	{
		*RC_MtrRev = *RC_MtrRev - 1;
	}

	/* Find the RC motor angle in HwPos coordinates */
	*RC_MtrDeg = (RC_HwDeg - (*RC_MtrRev * ConvHwDegMtrRev_HwDegpMtrRev_M_f32)) * k_InvGearRatio_Uls_f32;
}


/* Adjust RC motor rev to align the new calculated RC motor angle with the stored RC motor angle */
STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) AdjRCMtrRevToStoredMtrDeg(P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrRev,
		                                                                  P2VAR(float32, AUTOMATIC, AUTOMATIC) RC_MtrDeg)
{
	if (*RC_MtrDeg < (Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32 - 180.0f))
	{
		*RC_MtrRev = *RC_MtrRev - 1;
	}
	else
	{
		if (*RC_MtrDeg > (Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32 + 180.0f))
		{
			*RC_MtrRev = *RC_MtrRev + 1;
		}
	}

	 *RC_MtrDeg = Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32;
}


/* Update Rack Center output */
STATIC FUNC(void, RTE_AP_LNRKCR_APPL_CODE) UpdateNewRckCntrValues(VAR(float32, AUTOMATIC) TotalRackTravel_HwDeg_T_f32,
														               VAR(float32, AUTOMATIC) RC_MtrRev,
														               VAR(float32, AUTOMATIC) RC_MtrDeg)
{

	RackCenterOutput_HwDeg_M_f32 = ((RC_MtrRev * D_360_DEGPREV_F32) + RC_MtrDeg) * k_GearRatio_Uls_f32;
	RackCntrComplete_Cnt_M_lgc = TRUE;

	if (RCMtrAngleFound_Cnt_M_lgc == FALSE)
	{
		RCMtrAngleFound_Cnt_M_lgc = TRUE;
		Rte_Pim_LearnedRackCntr()->TotalRackTravel_HwDeg_f32 = TotalRackTravel_HwDeg_T_f32;
		Rte_Pim_LearnedRackCntr()->RackCntrMtrDeg_MtrDeg_f32 = RC_MtrDeg;
		Rte_Pim_LearnedRackCntr()->RackCntrMtrAngleFound_Cnt_lgc = TRUE;
	}

	Rte_Pim_LearnedRackCntr()->RackCntrMtrRev_MtrRev_f32 = RC_MtrRev;
	Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc = TRUE;
	Rte_Call_LearnedRackCntrData_WriteBlock(NULL_PTR);

	Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(RackCenterOutput_HwDeg_M_f32,  Rte_Pim_LearnedRackCntr()->RackCntrComplete_Cnt_lgc);
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
