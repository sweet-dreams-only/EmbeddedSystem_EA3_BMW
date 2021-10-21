/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PwrLmtFunc.c
 *     Workspace:  C:/SynergyWorkArea/Working/PwrLmtFunc-czmgrw/PwrLmtFunc/autosar
 *     SW-C Type:  Ap_PwrLmtFunc
 *  Generated at:  Thu Jan 29 13:58:55 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PwrLmtFunc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          12 %
 * %derived_by:       czmgrw %
 * %date_modified:    Thu Mar  7 11:20:50 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        M. Story  Initial CBD Synergy Version
 * 06/15/12  2        NRAR      Updated as per FDD SF19A ver006 and removed ManualTrqCmd calculation
 * 06/16/12  3        NRAR      Changed PowerLimitPerc units from PCT to Uls
 * 08/06/12  5        LWW       Added back in init function functionaly for anomaly correction
 * 08/31/12  6        JWJ       Removed Min_m call in per2                                                   6077
 * 09/21/12  7        Selva      Checkpoints added and mempmap macros corrected		                         6241
 * 10/25/12  8		  KJS		Updates for SF version 7
 * 10/25/12  9		  KJS		Error during integration caused two variables not to be declared. 
 * 10/29/12	 10       Selva 	SF-19A Pwr Limit: Anomaly 3991 Fixed										 6675
 * 03/07/13  11       Selva     Updates for SF version 8
 * 01/29/15  12       JK        Anomaly Correction :Added logic to reset TrqLmt_Uls to zero during MSA      12957
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_PwrLmtFunc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_PwrLmtFunc_Cfg.h"
#include "filters.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "interpolation.h"
#include "CalConstants.h"

/* PRQA S 4393 EOF 
* MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* PRQA S 4395 EOF 
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

#define D_MTRENVSPDLOLMT_MTRRADPS_U12P4					FPM_InitFixedPoint_m(0.0, u12p4_T)
#define D_MTRENVSPDHILMT_MTRRADPS_U12P4					FPM_InitFixedPoint_m(1143.0, u12p4_T)
#define D_MTRENVSPDHILMT_MTRRADPS_F32					1118.0F
#define D_TESTNOTCOMPLETETHISOPCYCLEBIT_CNT_B8			0x40U
#define D_10MS_SEC_F32	0.01F

#define PWRLMTFUNC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_PWRLMTFUNC_VAR) TrqLmtKSV_M_str; 
#define PWRLMTFUNC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define PWRLMTFUNC_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint16, AP_PWRLMTFUNC_VAR) SpdAdj_MtrRadpS_M_s11p4; /* PRQA S 3218 */
#define PWRLMTFUNC_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define PWRLMTFUNC_START_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_PWRLMTFUNC_VAR) MinStdOpLmt_MtrNm_M_u5p11; 
STATIC VAR(sint16, AP_PWRLMTFUNC_VAR) LimitDiff_MtrNm_M_s4p11; /* PRQA S 3218 */
STATIC VAR(uint16, AP_PWRLMTFUNC_VAR) TrqLmt_MtrNm_M_u5p11;
STATIC volatile VAR(sint16, AP_PWRLMTFUNC_VAR) OPVelOffset_MtrRadpS_D_s11p4; /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PWRLMTFUNC_VAR) TLmtMaxCurr_MtrNm_D_u5p11; /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PWRLMTFUNC_VAR) TrqEnvLmt_MtrNm_D_u5p11; /* PRQA S 3218 */
#define PWRLMTFUNC_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

#define PWRLMTFUNC_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_PWRLMTFUNC_VAR) LowVltAstTime_mS_M_u32p0; /* PRQA S 3218 */
#define PWRLMTFUNC_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define PWRLMTFUNC_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_PWRLMTFUNC_VAR) InvKeStdTemp_RadpSpV_M_f32;
STATIC volatile VAR(float32, AP_PWRLMTFUNC_VAR) FltTrqLmt_Uls_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PWRLMTFUNC_VAR) TrqLmt_Uls_D_f32; /* PRQA S 3218 */
#define PWRLMTFUNC_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
	
STATIC INLINE FUNC(float32, RTE_AP_PWRLMTFUNC_APPL_CODE) AssistReducDiag(	VAR(sint16, AUTOMATIC) LimitDiff_MtrNm_T_s4p11,
																			VAR(uint16, AUTOMATIC) AbsPreLimitForPwr_MtrNm_T_u5p11,
																			VAR(uint16, AUTOMATIC) MtrTrqCmd_MtrNm_T_u5p11,
																			VAR(uint16, AUTOMATIC) MinStdOpLmt_MtrNm_T_u5p11, 
																			VAR(uint16, AUTOMATIC) Vecu_Volts_T_u8p8,
																			VAR(boolean, AUTOMATIC) MSAActive_Cnt_T_lgc);


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
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
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
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
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
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
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
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
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
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
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
 *   NTC_Num_DSTXORActive (399u)
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
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PWRLMTFUNC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrLmtFunc_Init
 *********************************************************************************************************************/

	InvKeStdTemp_RadpSpV_M_f32 = 1.0F / k_KeStdTemp_VpRadpS_f32;

	LPF_Init_f32_m(D_ZERO_ULS_F32, k_AsstReducLPFKn_Hz_f32, D_10MS_SEC_F32, &TrqLmtKSV_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PwrLmtFunc_Per1_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_CustCurrLmt_Amp_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_KeEstimate_VpRadpS_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_MotorVelocityMRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_PwrLmtFunc_Per1_PosServEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(void)
 *   void Rte_IWrite_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrLmtFunc_Per1
 *********************************************************************************************************************/


	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) EstKe_VpRadpS_T_f32;
	VAR(uint16, AUTOMATIC) Vecu_Volts_T_u8p8;
	VAR(float32, AUTOMATIC) Vecu_Volts_T_f32;
	VAR(sint16, AUTOMATIC) MtrVel_MtrRadpS_T_s11p4;
	VAR(uint16, AUTOMATIC) AbsMtrVel_MtrRadpS_T_u12p4;
	VAR(sint32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_s27p4;
	VAR(uint16, AUTOMATIC) TrqEnvLmt_MtrNm_T_u5p11;
	VAR(uint16, AUTOMATIC) TrqStallLmt_MtrNm_T_u5p11;
	VAR(uint16, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_u12p4;
	VAR(sint16, AUTOMATIC) OPVelOffset_MtrRadpS_T_s11p4;
	VAR(boolean, AUTOMATIC) PosServEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MSAActive_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) CustCurrLimit_Amp_T_f32;
	VAR(uint16, AUTOMATIC) CustCurrLimit_Amp_T_u12p4;
	VAR(float32, AUTOMATIC) TrqLmt_MtrNm_T_f32;
	VAR(uint16, AUTOMATIC) VelOffset_MtrRadpS_T_u12p4;
	VAR(float32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_f32;
	
    /* Configurable Start of Runnable Checkpoint */
	Rte_Call_PwrLmtFunc_Per1_CP0_CheckpointReached();

	MtrVel_MtrRadpS_T_f32 = Rte_IRead_PwrLmtFunc_Per1_MotorVelocityMRF_MtrRadpS_f32();
	EstKe_VpRadpS_T_f32 = Rte_IRead_PwrLmtFunc_Per1_KeEstimate_VpRadpS_f32();
	Vecu_Volts_T_f32 = Rte_IRead_PwrLmtFunc_Per1_Vecu_Volt_f32();
	CustCurrLimit_Amp_T_f32 = Rte_IRead_PwrLmtFunc_Per1_CustCurrLmt_Amp_f32();
	PosServEnable_Cnt_T_lgc = Rte_IRead_PwrLmtFunc_Per1_PosServEnable_Cnt_lgc();
	MSAActive_Cnt_T_lgc 	= Rte_IRead_PwrLmtFunc_Per1_CCLMSAActive_Cnt_lgc();
	Vecu_Volts_T_u8p8 = FPM_FloatToFixed_m(Vecu_Volts_T_f32 , u8p8_T);
	MtrVel_MtrRadpS_T_s11p4 = FPM_FloatToFixed_m(MtrVel_MtrRadpS_T_f32, s11p4_T);
	AbsMtrVel_MtrRadpS_T_u12p4 = Abs_s16_m(MtrVel_MtrRadpS_T_s11p4);
	

	/*Reduced performance Customer Current Limit */
	CustCurrLimit_Amp_T_u12p4 = FPM_FloatToFixed_m(CustCurrLimit_Amp_T_f32, u12p4_T);

	VelOffset_MtrRadpS_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_CustCurrentLmtTblX_Amps_u12p4,
	                                                         	t_CustCurrentLmtTblY_MtrRadpS_u12p4,
																TableSize_m(t_CustCurrentLmtTblX_Amps_u12p4),
																CustCurrLimit_Amp_T_u12p4);
	if (MSAActive_Cnt_T_lgc ==TRUE)
		{
		OPVelOffset_MtrRadpS_T_s11p4 = IntplVarXY_s16_u16Xs16Y_Cnt(t_MSADLVTblX_Volts_u8p8,
								                             t_MSADLVTblY_MtrRadpS_s11p4,
								                             TableSize_m(t_MSADLVTblX_Volts_u8p8), 
								                             Vecu_Volts_T_u8p8);
		}
	else
		{
		OPVelOffset_MtrRadpS_T_s11p4 = IntplVarXY_s16_u16Xs16Y_Cnt(t_DLVTblX_Volts_u8p8,
								                             t_DLVTblY_MtrRadpS_s11p4,
								                             TableSize_m(t_DLVTblX_Volts_u8p8), 
								                             Vecu_Volts_T_u8p8);
		}

	OPVelOffset_MtrRadpS_D_s11p4 = OPVelOffset_MtrRadpS_T_s11p4;
	OPVelOffset_MtrRadpS_T_s11p4 = OPVelOffset_MtrRadpS_T_s11p4 + (sint16)(VelOffset_MtrRadpS_T_u12p4);

	if (TRUE == k_SpdAdjSlewEnable_Cnt_lgc)
	{
		SpdAdj_MtrRadpS_M_s11p4 = (sint16)Limit_m((sint32)OPVelOffset_MtrRadpS_T_s11p4, 
		                                          ((sint32)SpdAdj_MtrRadpS_M_s11p4 - (sint32)k_SpdAdjSlewDec_MtrRadpSpL_u12p4), 
		                                          ((sint32)SpdAdj_MtrRadpS_M_s11p4 + (sint32)k_SpdAdjSlewInc_MtrRadpSpL_u12p4));
	}
	else
	{
		SpdAdj_MtrRadpS_M_s11p4 = OPVelOffset_MtrRadpS_T_s11p4;
	}

	MtrEnvSpd_MtrRadpS_T_s27p4 = (sint32)AbsMtrVel_MtrRadpS_T_u12p4 + (sint32)SpdAdj_MtrRadpS_M_s11p4;

	MtrEnvSpd_MtrRadpS_T_u12p4 = (uint16)Limit_m(MtrEnvSpd_MtrRadpS_T_s27p4,
									         (sint32)D_MTRENVSPDLOLMT_MTRRADPS_U12P4,
									         (sint32)D_MTRENVSPDHILMT_MTRRADPS_U12P4);

	if (TRUE == PosServEnable_Cnt_T_lgc)
	{
		TrqEnvLmt_MtrNm_T_u5p11 = IntplVarXY_u16_u16Xu16Y_Cnt(t_APAMtrEnvTblX_MtrRadpS_u12p4,
									  					      t_APAMtrEnvTblY_MtrNm_u5p11,
									                          TableSize_m(t_APAMtrEnvTblX_MtrRadpS_u12p4),
									                          MtrEnvSpd_MtrRadpS_T_u12p4);
	}
	else
	{
	TrqEnvLmt_MtrNm_T_u5p11 = IntplVarXY_u16_u16Xu16Y_Cnt(t_MtrEnvTblX_MtrRadpS_u12p4,
								  					      t_MtrEnvTblY_MtrNm_u5p11, 
								                          TableSize_m(t_MtrEnvTblX_MtrRadpS_u12p4), 
								                          MtrEnvSpd_MtrRadpS_T_u12p4);
	}

	TrqEnvLmt_MtrNm_D_u5p11 = TrqEnvLmt_MtrNm_T_u5p11;

 	if(EstKe_VpRadpS_T_f32 < k_KeStdTemp_VpRadpS_f32)
	{
	 	TrqStallLmt_MtrNm_T_u5p11 = (uint16)((float32)t_MtrEnvTblY_MtrNm_u5p11[0] * EstKe_VpRadpS_T_f32 * InvKeStdTemp_RadpSpV_M_f32);
    }
    else
    {
	 	TrqStallLmt_MtrNm_T_u5p11 = t_MtrEnvTblY_MtrNm_u5p11[0];
    }
 
 	TLmtMaxCurr_MtrNm_D_u5p11 = TrqStallLmt_MtrNm_T_u5p11;

 
	TrqLmt_MtrNm_M_u5p11 = Min_m(TrqStallLmt_MtrNm_T_u5p11, TrqEnvLmt_MtrNm_T_u5p11);
	

	MinStdOpLmt_MtrNm_M_u5p11 = IntplVarXY_u16_u16Xu16Y_Cnt (t_StdOpMtrEnvTblX_MtrRadpS_u12p4,
																t_StdOpMtrEnvTblY_MtrNm_u5p11, 
																TableSize_m(t_MtrEnvTblX_MtrRadpS_u12p4), 
																AbsMtrVel_MtrRadpS_T_u12p4);

	LimitDiff_MtrNm_M_s4p11 = (sint16)TrqEnvLmt_MtrNm_T_u5p11 - (sint16)MinStdOpLmt_MtrNm_M_u5p11;

	MtrEnvSpd_MtrRadpS_T_f32 = FPM_FixedToFloat_m(MtrEnvSpd_MtrRadpS_T_u12p4, u12p4_T);
	MtrEnvSpd_MtrRadpS_T_f32 = Limit_m(MtrEnvSpd_MtrRadpS_T_f32, D_ZERO_ULS_F32, D_MTRENVSPDHILMT_MTRRADPS_F32);

	TrqLmt_MtrNm_T_f32 = FPM_FixedToFloat_m(TrqLmt_MtrNm_M_u5p11, u5p11_T); 
	TrqLmt_MtrNm_T_f32 = Limit_m(TrqLmt_MtrNm_T_f32, D_ZERO_ULS_F32, D_MTRTRQCMDHILMT_MTRNM_F32);

	Rte_IWrite_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(MtrEnvSpd_MtrRadpS_T_f32);
	Rte_IWrite_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(TrqLmt_MtrNm_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_PwrLmtFunc_Per1_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PwrLmtFunc_Per2_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per2_PreLimitForPwr_MtrNm_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per2_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
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

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrLmtFunc_Per2
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) PreLimitForPwr_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AbsPreLimitForPwr_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) Vecu_Volts_T_f32;
	VAR(uint16, AUTOMATIC) Vecu_Volts_T_u8p8;
	VAR(float32, AUTOMATIC) TrqLmt_Uls_T_f32;
	VAR(boolean, AUTOMATIC) MSAActive_Cnt_T_lgc;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PwrLmtFunc_Per2_CP0_CheckpointReached();
	
	MSAActive_Cnt_T_lgc 	= Rte_IRead_PwrLmtFunc_Per2_CCLMSAActive_Cnt_lgc();
	Vecu_Volts_T_f32 = Rte_IRead_PwrLmtFunc_Per2_Vecu_Volt_f32();
	PreLimitForPwr_MtrNm_T_f32 = Rte_IRead_PwrLmtFunc_Per2_PreLimitForPwr_MtrNm_f32();

	Vecu_Volts_T_u8p8 = FPM_FloatToFixed_m(Vecu_Volts_T_f32 , u8p8_T);

	AbsPreLimitForPwr_MtrNm_T_f32 = Abs_f32_m(PreLimitForPwr_MtrNm_T_f32);
	
	TrqLmt_Uls_T_f32 = AssistReducDiag(	LimitDiff_MtrNm_M_s4p11,
										FPM_FloatToFixed_m(AbsPreLimitForPwr_MtrNm_T_f32, u5p11_T),
										TrqLmt_MtrNm_M_u5p11, 
										MinStdOpLmt_MtrNm_M_u5p11,
										Vecu_Volts_T_u8p8,
										MSAActive_Cnt_T_lgc);

	TrqLmt_Uls_T_f32 = Limit_m(TrqLmt_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);

	Rte_IWrite_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(TrqLmt_Uls_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_PwrLmtFunc_Per2_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PWRLMTFUNC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_PWRLMTFUNC_APPL_CODE) AssistReducDiag(	VAR(sint16, AUTOMATIC) LimitDiff_MtrNm_T_s4p11,
																			VAR(uint16, AUTOMATIC) AbsPreLimitForPwr_MtrNm_T_u5p11,
																			VAR(uint16, AUTOMATIC) MtrTrqCmd_MtrNm_T_u5p11,
																			VAR(uint16, AUTOMATIC) MinStdOpLmt_MtrNm_T_u5p11, 
																			VAR(uint16, AUTOMATIC) Vecu_Volts_T_u8p8,
																			VAR(boolean, AUTOMATIC) MSAActive_Cnt_T_lgc)
{
	VAR(uint16, AUTOMATIC) AsstReduc_MtrNm_T_u5p11;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(float32, AUTOMATIC) TrqLmt_Uls_T_f32;
	VAR(uint8, AUTOMATIC) LVAsstNTCStatus_Cnt_T_u08;
	
	if ((LimitDiff_MtrNm_T_s4p11 < 0) && (AbsPreLimitForPwr_MtrNm_T_u5p11  > MtrTrqCmd_MtrNm_T_u5p11) && (MSAActive_Cnt_T_lgc == 0U))
    {
		AsstReduc_MtrNm_T_u5p11 = (uint16)-LimitDiff_MtrNm_T_s4p11;

		if (MinStdOpLmt_MtrNm_T_u5p11 > AsstReduc_MtrNm_T_u5p11)
		{
			TrqLmt_Uls_T_f32 = (float32)AsstReduc_MtrNm_T_u5p11 / (float32)MinStdOpLmt_MtrNm_T_u5p11;
		}
		else
		{
			TrqLmt_Uls_T_f32 = D_ONE_ULS_F32;
		}
		
	}
	else
	{
		AsstReduc_MtrNm_T_u5p11 = 0U; /* PRQA S 2983 */
		TrqLmt_Uls_T_f32 = D_ZERO_ULS_F32;
	}
	

	TrqLmt_Uls_D_f32 = TrqLmt_Uls_T_f32;

	TrqLmt_Uls_T_f32 = LPF_OpUpdate_f32_m(TrqLmt_Uls_T_f32, &TrqLmtKSV_M_str);

	FltTrqLmt_Uls_D_f32 = TrqLmt_Uls_T_f32;

	if (TrqLmt_Uls_T_f32 > k_FiltAsstReducTh_Uls_f32)
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&LowVltAstTime_mS_M_u32p0);
		
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_ReducedAsstLowVoltage, 0x01U, NTC_STATUS_FAILED);
	}
   	else
	{   
		(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_ReducedAsstLowVoltage, &LVAsstNTCStatus_Cnt_T_u08);
		
		if (D_TESTNOTCOMPLETETHISOPCYCLEBIT_CNT_B8 == (D_TESTNOTCOMPLETETHISOPCYCLEBIT_CNT_B8 & LVAsstNTCStatus_Cnt_T_u08))
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_ReducedAsstLowVoltage, 0x01U, NTC_STATUS_PASSED);	
		}
		
		if (Vecu_Volts_T_u8p8 >= k_LowVltAstRecTh_Volts_u8p8)
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(LowVltAstTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
			
			if(ElapsedTime_mS_T_u16p0 >= k_LowVltAstRecTime_mS_u16p0)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_ReducedAsstLowVoltage, 0x01U, NTC_STATUS_PASSED); 
			}
		}
		else
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&LowVltAstTime_mS_M_u32p0);
		}
	}
	
	return (TrqLmt_Uls_T_f32);
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
