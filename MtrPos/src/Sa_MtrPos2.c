/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrPos2.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrPos/autosar
 *     SW-C Type:  Sa_MtrPos2
 *  Generated at:  Mon Feb  4 19:03:05 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrPos2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Oct 19 18:02:18 2012
 * %version:          4 %
 * %derived_by:       xz0btk %
 * %date_modified:    Thu Feb  7 14:27:02 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 10/23/12  1        OT        Implemented FDD 06B v004 (merged MtrPos, MtrPosDiag, and MtrPosSnsrLearning)     6472
 * 02/06/13  3        JJW       Changed D_MAXAMPLITUDE_VOLTS_F32 to 2.5 for support of 5v sensors per verbal
 *								discussion with FDD owner.  The FDD is to be updated.  The software is leading 
 *								the FDD in this case to meet build timing.
 * 02/07/13  4        JJW       Correction of reintroduced FDD anomaly 3999 in the sin^2 + cos^2 check
 * 								Removal of EOL Amp and Offset checks per FDD06B v005
 */
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
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

 *********************************************************************************************************************/

#include "Rte_Sa_MtrPos2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define MTRPOS_C
#include "Sa_MtrPos.h"
#include "Sa_MtrPos2_Cfg.h"
#include "fixmath.h"
#include "interpolation.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "CalConstants.h"


#define D_OFFSETCORRTHRESH_VOLTS_F32			0.02F
#define D_AMPCORRTHRESH_ULS_F32					0.02F
#define D_MAXAMPLITUDE_VOLTS_F32				2.5F
#define D_MINAMPLITUDE_VOLTS_F32				0.25F
#define D_HALF_ULS_F32							0.5F
#define D_TWO_ULS_F32							2.0F
#define D_WORDMASK_CNT_U16						0xFFFFU

#define MTRPOS2_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
volatile VAR(uint8, SA_MTRPOS2_VAR) MtrPos2_LearnedParamBfr_Cnt_M_u08;
#define MTRPOS2_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS2_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16,  SA_MTRPOS2_VAR) MtrPos2_ValidityFltAcc_Cnt_M_u16;
STATIC VAR(uint16,  SA_MTRPOS2_VAR) MtrPos2_CorrFltAcc_Cnt_M_u16;

VAR(uint16, SA_MTRPOS2_VAR) MtrPos2_Sin1RTOffset_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
VAR(uint16, SA_MTRPOS2_VAR) MtrPos2_Cos1RTOffset_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
VAR(uint16, SA_MTRPOS2_VAR) MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
VAR(uint16, SA_MTRPOS2_VAR) MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
#define MTRPOS2_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define MTRPOS2_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_PrevCorrectedMtrPos_Rev_M_f32;
STATIC volatile VAR(float32, SA_MTRPOS2_VAR) MtrPos2_ErrorTerm_Rev_D_f32;
STATIC volatile VAR(float32, SA_MTRPOS2_VAR) MtrPos2_ValidErr_VoltsSqrd_D_f32;
#define MTRPOS2_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define MTRPOS2_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_PrevSin1RTOffset_Volts_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_PrevCos1RTOffset_Volts_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Sin1OffsetCorr_Volts_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Cos1OffsetCorr_Volts_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Sin1GainCorr_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Cos1GainCorr_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_CosSin1NomRatio_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_SinCos1NomRatio_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_RTToNomHighLmt_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_RTToNomLowLmt_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Cos1RTAmpRec_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Cos1RTOffset_Volt_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Sin1RTAmpRec_Uls_M_f32;
STATIC VAR(float32, SA_MTRPOS2_VAR) MtrPos2_Sin1RTOffset_Volt_M_f32;
#define MTRPOS2_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */


#define MTRPOS2_START_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint32, SA_MTRPOS2_VAR) MtrPos2_Cos1MaxSV_Volts_M_s2p29;
STATIC VAR(sint32, SA_MTRPOS2_VAR) MtrPos2_Cos1MinSV_Volts_M_s2p29;
STATIC VAR(sint32, SA_MTRPOS2_VAR) MtrPos2_Sin1MaxSV_Volts_M_s2p29;
STATIC VAR(sint32, SA_MTRPOS2_VAR) MtrPos2_Sin1MinSV_Volts_M_s2p29;
#define MTRPOS2_STOP_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(float32, SA_MTRPOS2_CODE) OffsetInit(VAR(float32, AUTOMATIC) EOLAmpRec_Uls_T_f32,
												 VAR(float32, AUTOMATIC) EOLOffset_Volts_T_f32,
												 CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarMaxPtr_Volts_T_s2p29,
												 CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarMinPtr_Volts_T_s2p29);

STATIC FUNC(float32, SA_MTRPOS2_CODE) RunTimeFilter(VAR(float32, AUTOMATIC) SigEst_Uls_T_f32,
													VAR(float32, AUTOMATIC) SigCorr_Volts_T_f32,
													VAR(float32, AUTOMATIC) OffsetDelta_Volts_T_f32,
													CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarPtr_Volts_T_s2p29);

STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcOffsetFromMinMax(VAR(float32, AUTOMATIC) Min_Volts_T_f32,
														   VAR(float32, AUTOMATIC) Max_Volts_T_f32,
														   VAR(float32, AUTOMATIC) EOLOffset_Volts_T_f32);

STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcSinAmpRec(VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) EOLSinAmpRec_Uls_T_f32);

STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcCosAmpRec(VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) TotCosAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) SinRTAmpRec_Uls_T_f32,
													VAR(float32, AUTOMATIC) SinCosNomRatio_Uls_T_f32,
													VAR(float32, AUTOMATIC) CosSinNomRatio_Uls_T_f32,
													VAR(float32, AUTOMATIC) RTToNomLowLmt_Uls_T_f32,
													VAR(float32, AUTOMATIC) RTToNomHighLmt_Uls_T_f32);


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
 * SInt8: Integer in interval [-128...127] (standard type)
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
 * Float: D_ZERO_ULS_F32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRPOS2_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos2_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS2_APPL_CODE) MtrPos2_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos2_Init1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) EOLCos1AmpRec_Uls_T_f32;
	VAR(float32, AUTOMATIC) EOLSin1AmpRec_Uls_T_f32;
	VAR(float32, AUTOMATIC) EOLSin1Offset_Volts_T_f32;
	VAR(float32, AUTOMATIC) EOLCos1Offset_Volts_T_f32;
	VAR(float32, AUTOMATIC) RTOffset_Volts_T_f32;
	VAR(float32, AUTOMATIC) Min_Volts_T_f32;
	VAR(float32, AUTOMATIC) Max_Volts_T_f32;
	VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32;
	VAR(float32, AUTOMATIC) TotCosAmp_Volts_T_f32;
	VAR(float32, AUTOMATIC) RTAmpRec_Uls_T_f32;
	
	
	
	/** Learning Init **/
	
	/* Calculate Ratios */
	EOLCos1AmpRec_Uls_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Cos1AmpRec_Uls_u3p13, u3p13_T);
	EOLSin1AmpRec_Uls_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1AmpRec_Uls_u3p13, u3p13_T);
	
	MtrPos2_SinCos1NomRatio_Uls_M_f32 = EOLCos1AmpRec_Uls_T_f32 / EOLSin1AmpRec_Uls_T_f32;
	MtrPos2_CosSin1NomRatio_Uls_M_f32 = EOLSin1AmpRec_Uls_T_f32 / EOLCos1AmpRec_Uls_T_f32;
	
	/* Init Correction Terms from EOL data */
	MtrPos2_Sin1GainCorr_Uls_M_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1GainCorr_Uls_u1p15, u1p15_T);
	MtrPos2_Cos1GainCorr_Uls_M_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Cos1GainCorr_Uls_u1p15, u1p15_T);
	MtrPos2_Sin1OffsetCorr_Volts_M_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1OffCorr_Volts_s2p13, s2p13_T);
	MtrPos2_Cos1OffsetCorr_Volts_M_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Cos1OffCorr_Volts_s2p13, s2p13_T);
		
	/* Calculate Limits */
	MtrPos2_RTToNomLowLmt_Uls_M_f32 = D_ONE_ULS_F32 - k_RTToNomRatioVar_Uls_f32;
	MtrPos2_RTToNomHighLmt_Uls_M_f32 = D_ONE_ULS_F32 + k_RTToNomRatioVar_Uls_f32;
	
	/* Initialize RT Offsets */
	EOLSin1Offset_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1Offset_Volts_u3p13, u3p13_T);
	EOLCos1Offset_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Cos1Offset_Volts_u3p13, u3p13_T);
	
	RTOffset_Volts_T_f32 = OffsetInit(EOLSin1AmpRec_Uls_T_f32, EOLSin1Offset_Volts_T_f32, &MtrPos2_Sin1MaxSV_Volts_M_s2p29, &MtrPos2_Sin1MinSV_Volts_M_s2p29);
	MtrPos2_Sin1RTOffset_Volt_M_f32 = RTOffset_Volts_T_f32 + MtrPos2_Sin1OffsetCorr_Volts_M_f32;
	MtrPos2_Sin1RTOffset_Volts_M_u3p13[0] = FPM_FloatToFixed_m(MtrPos2_Sin1RTOffset_Volt_M_f32, u3p13_T);
	MtrPos2_Sin1RTOffset_Volts_M_u3p13[1] = MtrPos2_Sin1RTOffset_Volts_M_u3p13[0];
	MtrPos2_PrevSin1RTOffset_Volts_M_f32 = MtrPos2_Sin1RTOffset_Volt_M_f32;
	
	RTOffset_Volts_T_f32 = OffsetInit(EOLCos1AmpRec_Uls_T_f32, EOLCos1Offset_Volts_T_f32, &MtrPos2_Cos1MaxSV_Volts_M_s2p29, &MtrPos2_Cos1MinSV_Volts_M_s2p29);
	MtrPos2_Cos1RTOffset_Volt_M_f32 = RTOffset_Volts_T_f32 + MtrPos2_Cos1OffsetCorr_Volts_M_f32;
	MtrPos2_Cos1RTOffset_Volts_M_u3p13[0] = FPM_FloatToFixed_m(MtrPos2_Cos1RTOffset_Volt_M_f32, u3p13_T);
	MtrPos2_Cos1RTOffset_Volts_M_u3p13[1] = MtrPos2_Cos1RTOffset_Volts_M_u3p13[0];
	MtrPos2_PrevCos1RTOffset_Volts_M_f32 = MtrPos2_Cos1RTOffset_Volt_M_f32;
	
	/* Initialize RT AmpRec */
	Min_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos2_Sin1MinSV_Volts_M_s2p29, s2p29_T);
	Max_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos2_Sin1MaxSV_Volts_M_s2p29, s2p29_T);
	TotSinAmp_Volts_T_f32 = Max_Volts_T_f32 - Min_Volts_T_f32;
	
	Min_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos2_Cos1MinSV_Volts_M_s2p29, s2p29_T);
	Max_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos2_Cos1MaxSV_Volts_M_s2p29, s2p29_T);
	TotCosAmp_Volts_T_f32 = Max_Volts_T_f32 - Min_Volts_T_f32;
	
	RTAmpRec_Uls_T_f32 = CalcSinAmpRec(TotSinAmp_Volts_T_f32, EOLSin1AmpRec_Uls_T_f32);
	MtrPos2_Sin1RTAmpRec_Uls_M_f32 = RTAmpRec_Uls_T_f32 * MtrPos2_Sin1GainCorr_Uls_M_f32;
	MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[0] = FPM_FloatToFixed_m(MtrPos2_Sin1RTAmpRec_Uls_M_f32, u3p13_T);
	MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[1] = MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[0];
	
	RTAmpRec_Uls_T_f32 = CalcCosAmpRec(	TotSinAmp_Volts_T_f32, 
										TotCosAmp_Volts_T_f32, 
										MtrPos2_Sin1RTAmpRec_Uls_M_f32,
										MtrPos2_SinCos1NomRatio_Uls_M_f32,
										MtrPos2_CosSin1NomRatio_Uls_M_f32,
										MtrPos2_RTToNomLowLmt_Uls_M_f32,
										MtrPos2_RTToNomHighLmt_Uls_M_f32);
										
	MtrPos2_Cos1RTAmpRec_Uls_M_f32 = RTAmpRec_Uls_T_f32 * MtrPos2_Cos1GainCorr_Uls_M_f32;
	MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[0] = FPM_FloatToFixed_m(MtrPos2_Cos1RTAmpRec_Uls_M_f32, u3p13_T);
	MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[1] = MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[0];
		
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos2_Per1
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
 *   Float Rte_IRead_MtrPos2_Per1_MotorVelMRF_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrPos2_Per1_CorrectedMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_CorrectedMtrPos_Rev_f32(void)
 *   void Rte_IWrite_MtrPos2_Per1_CosTheta1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_CosTheta1_Volt_f32(void)
 *   void Rte_IWrite_MtrPos2_Per1_MechMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_MechMtrPos_Rev_f32(void)
 *   void Rte_IWrite_MtrPos2_Per1_SinTheta1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_SinTheta1_Volt_f32(void)
 *   void Rte_IWrite_MtrPos2_Per1_SysCCorrectedMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_SysCCorrectedMtrPos_Rev_f32(void)
 *   void Rte_IWrite_MtrPos2_Per1_SysCMechMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos2_Per1_SysCMechMtrPos_Rev_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS2_APPL_CODE) MtrPos2_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos2_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) CorrectedMtrPos_Rev_T_f32;
	VAR(float32, AUTOMATIC) Cos1Scaled_Volt_T_f32;
	VAR(float32, AUTOMATIC) DiagCorrectedMtrPos_Rev_T_f32;
	VAR(float32, AUTOMATIC) MechMtrPos_Rev_T_f32;
	VAR(float32, AUTOMATIC) MotorVelMRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) Sin1Scaled_Volt_T_f32;
	VAR(boolean, AUTOMATIC) MtrPosFault1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrPosFault2_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Sin1Offset_Volts_T_f32;
	VAR(float32, AUTOMATIC) Cos1Offset_Volts_T_f32;
	VAR(float32, AUTOMATIC) Sin1AmpRec_Uls_T_f32;
	
	VAR(float32, AUTOMATIC) SinCorr_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosCorr_Volts_T_f32;
	VAR(float32, AUTOMATIC) MechMtrPos_Rad_T_f32;
	VAR(float32, AUTOMATIC) SinEst_Uls_T_f32;
	VAR(float32, AUTOMATIC) CosEst_Uls_T_f32;
	VAR(float32, AUTOMATIC) SinOffsetDelta_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosOffsetDelta_Volts_T_f32;
	VAR(float32, AUTOMATIC) SinMin_Volts_T_f32;
	VAR(float32, AUTOMATIC) SinMax_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosMin_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosMax_Volts_T_f32;
	VAR(float32, AUTOMATIC) SinRTOffset_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosRTOffset_Volts_T_f32;
	VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32;
	VAR(float32, AUTOMATIC) TotCosAmp_Volts_T_f32;
	VAR(float32, AUTOMATIC) SinRTAmpRec_Uls_T_f32;
	VAR(float32, AUTOMATIC) CosRTAmpRec_Uls_T_f32;
	
	VAR(float32, AUTOMATIC) ErrorTerm_Rev_T_f32;
	VAR(float32, AUTOMATIC) ValidErr_VoltsSqrd_T_f32;
	
	VAR(uint8, AUTOMATIC) IdleDblBuf_Cnt_T_u08;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrPos2_Per1_CP0_CheckpointReached();
	
	/* Get the idle dual buffer.  The active motor position buffer determination is made at a system level
	 * in order to synchronize signals from multiple modules. The idle buffer is the inverse of the active buffer.
	 * Limit buffer index between 0 and 1 with bitwise AND then Toggle the active buffer with XOR.
	 */
	CDD_Read_MtrPos_ActvDblBuf_Cnt_u08(&IdleDblBuf_Cnt_T_u08);
	IdleDblBuf_Cnt_T_u08 = (IdleDblBuf_Cnt_T_u08 & 1u)^1u;
	
	CorrectedMtrPos_Rev_T_f32 = FPM_FixedToFloat_m(MtrPos_CorrectedMtrPos_Rev_M_u0p16[IdleDblBuf_Cnt_T_u08], u0p16_T);
	Cos1Scaled_Volt_T_f32 = FPM_FixedToFloat_m(MtrPos_Cos1Scaled_Volts_M_u3p13[IdleDblBuf_Cnt_T_u08], u3p13_T);
	Sin1Scaled_Volt_T_f32 = FPM_FixedToFloat_m(MtrPos_Sin1Scaled_Volts_M_u3p13[IdleDblBuf_Cnt_T_u08], u3p13_T);;
	MechMtrPos_Rev_T_f32 = FPM_FixedToFloat_m(MtrPos_MechMtrPos_Rev_M_u0p16[IdleDblBuf_Cnt_T_u08], u0p16_T);

	DiagCorrectedMtrPos_Rev_T_f32 = MtrPos3_DiagCorrectedMtrPos_Rev_M_f32;
	MotorVelMRF_MtrRadpS_T_f32 = Rte_IRead_MtrPos2_Per1_MotorVelMRF_MtrRadpS_f32();

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriMSB_SinCosCorr, &MtrPosFault1_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriVsSec_SinCosCorr, &MtrPosFault2_Cnt_T_lgc);

	Sin1Offset_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1Offset_Volts_u3p13, u3p13_T);
	Cos1Offset_Volts_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Cos1Offset_Volts_u3p13, u3p13_T);
	Sin1AmpRec_Uls_T_f32 = FPM_FixedToFloat_m(MtrPos_EOLDataPtr_Cnt_M_Str->Sin1AmpRec_Uls_u3p13, u3p13_T);
	
	
	/*** Run Time Learn ***/
	
	if( (Abs_f32_m(MotorVelMRF_MtrRadpS_T_f32) > k_RTOffVelThr_MtrRadpS_f32) &&
		(FALSE == MtrPosFault1_Cnt_T_lgc) &&
		(FALSE == MtrPosFault2_Cnt_T_lgc) )
	{
		SinCorr_Volts_T_f32 = Sin1Scaled_Volt_T_f32 - MtrPos2_PrevSin1RTOffset_Volts_M_f32;
		CosCorr_Volts_T_f32 = Cos1Scaled_Volt_T_f32 - MtrPos2_PrevCos1RTOffset_Volts_M_f32;
		
		MechMtrPos_Rad_T_f32 = MechMtrPos_Rev_T_f32 * D_2PI_ULS_F32;
		SinEst_Uls_T_f32 = sinf(MechMtrPos_Rad_T_f32);
		CosEst_Uls_T_f32 = cosf(MechMtrPos_Rad_T_f32);
		
		SinOffsetDelta_Volts_T_f32 = MtrPos2_PrevSin1RTOffset_Volts_M_f32 - Sin1Offset_Volts_T_f32;
		CosOffsetDelta_Volts_T_f32 = MtrPos2_PrevCos1RTOffset_Volts_M_f32 - Cos1Offset_Volts_T_f32;
		
		SinMin_Volts_T_f32 = RunTimeFilter(-SinEst_Uls_T_f32, SinCorr_Volts_T_f32, SinOffsetDelta_Volts_T_f32, &MtrPos2_Sin1MinSV_Volts_M_s2p29);
		SinMax_Volts_T_f32 = RunTimeFilter(SinEst_Uls_T_f32, SinCorr_Volts_T_f32, SinOffsetDelta_Volts_T_f32, &MtrPos2_Sin1MaxSV_Volts_M_s2p29);
		CosMin_Volts_T_f32 = RunTimeFilter(-CosEst_Uls_T_f32, CosCorr_Volts_T_f32, CosOffsetDelta_Volts_T_f32, &MtrPos2_Cos1MinSV_Volts_M_s2p29);
		CosMax_Volts_T_f32 = RunTimeFilter(CosEst_Uls_T_f32, CosCorr_Volts_T_f32, CosOffsetDelta_Volts_T_f32, &MtrPos2_Cos1MaxSV_Volts_M_s2p29);
		
		SinRTOffset_Volts_T_f32 = CalcOffsetFromMinMax(SinMin_Volts_T_f32, SinMax_Volts_T_f32, Sin1Offset_Volts_T_f32);
		CosRTOffset_Volts_T_f32 = CalcOffsetFromMinMax(CosMin_Volts_T_f32, CosMax_Volts_T_f32, Cos1Offset_Volts_T_f32);
		MtrPos2_Sin1RTOffset_Volt_M_f32 = SinRTOffset_Volts_T_f32 + MtrPos2_Sin1OffsetCorr_Volts_M_f32;
		MtrPos2_Cos1RTOffset_Volt_M_f32 = CosRTOffset_Volts_T_f32 + MtrPos2_Cos1OffsetCorr_Volts_M_f32;
		
		TotSinAmp_Volts_T_f32 = SinMax_Volts_T_f32 - SinMin_Volts_T_f32;
		TotCosAmp_Volts_T_f32 = CosMax_Volts_T_f32 - CosMin_Volts_T_f32;
		
		SinRTAmpRec_Uls_T_f32 = CalcSinAmpRec(TotSinAmp_Volts_T_f32, Sin1AmpRec_Uls_T_f32);
		CosRTAmpRec_Uls_T_f32 = CalcCosAmpRec(TotSinAmp_Volts_T_f32,
											  TotCosAmp_Volts_T_f32,
											  SinRTAmpRec_Uls_T_f32,
											  MtrPos2_SinCos1NomRatio_Uls_M_f32,
											  MtrPos2_CosSin1NomRatio_Uls_M_f32,
											  MtrPos2_RTToNomLowLmt_Uls_M_f32,
											  MtrPos2_RTToNomHighLmt_Uls_M_f32);
		
		MtrPos2_Sin1RTAmpRec_Uls_M_f32 = SinRTAmpRec_Uls_T_f32 * MtrPos2_Sin1GainCorr_Uls_M_f32;
		MtrPos2_Cos1RTAmpRec_Uls_M_f32 = CosRTAmpRec_Uls_T_f32 * MtrPos2_Cos1GainCorr_Uls_M_f32;
	}
	
	
	
	/*** Motor Position Sensor Diagnostics ***/
	
	/** Motor Back EMF Calibration Failure Determination **/
	
	if( (MtrPos_EOLDataPtr_Cnt_M_Str->BEMFCal_Rev_u0p16 + MtrPos_EOLDataPtr_Cnt_M_Str->R_BEMFCal_Rev_u0p16) != D_WORDMASK_CNT_U16 )
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagMtrStr, 0x01, NTC_STATUS_FAILED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagMtrStr, 0x01, NTC_STATUS_PASSED);
	}
	
	
	/** Motor Position Cross Correlation Failure Determination **/
	
	ErrorTerm_Rev_T_f32 = Abs_f32_m(MtrPos2_PrevCorrectedMtrPos_Rev_M_f32 - DiagCorrectedMtrPos_Rev_T_f32);
	
	if( ErrorTerm_Rev_T_f32 > D_HALF_ULS_F32 )
	{
		ErrorTerm_Rev_T_f32 = Abs_f32_m(ErrorTerm_Rev_T_f32 - D_ONE_ULS_F32);
	}
	
	if( ErrorTerm_Rev_T_f32 > k_CorrelationError_Rev_f32 )
	{
		MtrPos2_CorrFltAcc_Cnt_M_u16 = DiagPStep_m(MtrPos2_CorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str);
		
		if( DiagFailed_m(MtrPos2_CorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str) == TRUE )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriVsSec_SinCosCorr, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		MtrPos2_CorrFltAcc_Cnt_M_u16 = DiagNStep_m(MtrPos2_CorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str);
		
		if( MtrPos2_CorrFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriVsSec_SinCosCorr, 0x01, NTC_STATUS_PASSED);
		}
	}
	
	
	/** Motor Position Signal Validity Failure Determination **/
	SinCorr_Volts_T_f32 = Sin1Scaled_Volt_T_f32 - MtrPos2_Sin1RTOffset_Volt_M_f32;
	CosCorr_Volts_T_f32 = Cos1Scaled_Volt_T_f32 - MtrPos2_Cos1RTOffset_Volt_M_f32;
	ValidErr_VoltsSqrd_T_f32 = (SinCorr_Volts_T_f32 * SinCorr_Volts_T_f32) + (CosCorr_Volts_T_f32 * CosCorr_Volts_T_f32);
	
	if( (ValidErr_VoltsSqrd_T_f32 < k_ValMinError_VoltsSqrd_f32) ||
	    (ValidErr_VoltsSqrd_T_f32 > k_ValMaxError_VoltsSqrd_f32) )
	{
		MtrPos2_ValidityFltAcc_Cnt_M_u16 = DiagPStep_m(MtrPos2_ValidityFltAcc_Cnt_M_u16, k_MtrPosValDiag_Cnt_str);
		
		if( DiagFailed_m(MtrPos2_ValidityFltAcc_Cnt_M_u16, k_MtrPosValDiag_Cnt_str) == TRUE )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriMSB_SinCosCorr, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		MtrPos2_ValidityFltAcc_Cnt_M_u16 = DiagNStep_m(MtrPos2_ValidityFltAcc_Cnt_M_u16, k_MtrPosValDiag_Cnt_str);
		
		if( MtrPos2_ValidityFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriMSB_SinCosCorr, 0x01, NTC_STATUS_PASSED);
		}
	}
	
	
	
	MtrPos2_PrevCorrectedMtrPos_Rev_M_f32 = CorrectedMtrPos_Rev_T_f32;
	MtrPos2_ErrorTerm_Rev_D_f32 = ErrorTerm_Rev_T_f32;
	MtrPos2_ValidErr_VoltsSqrd_D_f32 = ValidErr_VoltsSqrd_T_f32;
	
	Rte_IWrite_MtrPos2_Per1_CorrectedMtrPos_Rev_f32(CorrectedMtrPos_Rev_T_f32);
	Rte_IWrite_MtrPos2_Per1_SysCCorrectedMtrPos_Rev_f32(CorrectedMtrPos_Rev_T_f32);
	Rte_IWrite_MtrPos2_Per1_MechMtrPos_Rev_f32(MechMtrPos_Rev_T_f32);
	Rte_IWrite_MtrPos2_Per1_SysCMechMtrPos_Rev_f32(MechMtrPos_Rev_T_f32);
	
	/* Outputs for use in the Diagnostic service handler, No FDD requirement to provde these signals to the Rte components
	 * Signal consistency between the sample time of Cos and Sin is not guaranteed.
	 * The signals are rescaled in this module to provide appropriate signals for the 
	 * diagnostic service interface.  When an alternate solution is devised, they can 
	 * be removed from this module.
	 */
	Rte_IWrite_MtrPos2_Per1_CosTheta1_Volt_f32(FPM_FixedToFloat_m(MtrPos_CosTheta1_Volts_G_s2p13, s2p13_T));
	Rte_IWrite_MtrPos2_Per1_SinTheta1_Volt_f32(FPM_FixedToFloat_m(MtrPos_SinTheta1_Volts_G_s2p13, s2p13_T));
	
	/* Update the idle module internal dual buffer to provide a consistent data set to
	 * MtrPos runnables executing in ISR context
	 */
	IdleDblBuf_Cnt_T_u08 = (MtrPos2_LearnedParamBfr_Cnt_M_u08 & 1)^1;

	MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[IdleDblBuf_Cnt_T_u08] = FPM_FloatToFixed_m(MtrPos2_Cos1RTAmpRec_Uls_M_f32, u3p13_T);
	MtrPos2_Cos1RTOffset_Volts_M_u3p13[IdleDblBuf_Cnt_T_u08] = FPM_FloatToFixed_m(MtrPos2_Cos1RTOffset_Volt_M_f32, u3p13_T);
	MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[IdleDblBuf_Cnt_T_u08] = FPM_FloatToFixed_m(MtrPos2_Sin1RTAmpRec_Uls_M_f32, u3p13_T);
	MtrPos2_Sin1RTOffset_Volts_M_u3p13[IdleDblBuf_Cnt_T_u08] = FPM_FloatToFixed_m(MtrPos2_Sin1RTOffset_Volt_M_f32, u3p13_T);

	/* Switch the Active Learned Param Buffer to the buffer which was just updated */
	MtrPos2_LearnedParamBfr_Cnt_M_u08 = IdleDblBuf_Cnt_T_u08;

	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrPos2_Per1_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRPOS2_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


STATIC FUNC(float32, SA_MTRPOS2_CODE) OffsetInit(VAR(float32, AUTOMATIC) EOLAmpRec_Uls_T_f32,
												 VAR(float32, AUTOMATIC) EOLOffset_Volts_T_f32,
												 CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarMaxPtr_Volts_T_s2p29,
												 CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarMinPtr_Volts_T_s2p29)
{
	
	VAR(float32, AUTOMATIC) EOLAmp_Volts_T_f32;
	VAR(float32, AUTOMATIC) StoredMax_Volts_T_f32;
	VAR(float32, AUTOMATIC) StoredMin_Volts_T_f32;
	VAR(float32, AUTOMATIC) StoredOffset_Volts_T_f32;
	VAR(float32, AUTOMATIC) RTOffset_Volts_T_f32;
	
	EOLAmp_Volts_T_f32 = D_ONE_ULS_F32 / EOLAmpRec_Uls_T_f32;
	StoredMax_Volts_T_f32 = FPM_FixedToFloat_m(*StateVarMaxPtr_Volts_T_s2p29, s2p29_T);
	StoredMin_Volts_T_f32 = FPM_FixedToFloat_m(*StateVarMinPtr_Volts_T_s2p29, s2p29_T);
	StoredOffset_Volts_T_f32 = (StoredMax_Volts_T_f32 + StoredMin_Volts_T_f32) * D_HALF_ULS_F32;
	
	if( (Abs_f32_m(StoredOffset_Volts_T_f32) > k_RTOffsetLmt_Volts_f32) ||
		(StoredMax_Volts_T_f32 < D_MINAMPLITUDE_VOLTS_F32) ||
		(-StoredMin_Volts_T_f32 < D_MINAMPLITUDE_VOLTS_F32) ||
		(StoredMax_Volts_T_f32 > D_MAXAMPLITUDE_VOLTS_F32) ||
		(-StoredMin_Volts_T_f32 > D_MAXAMPLITUDE_VOLTS_F32) )
	{
		*StateVarMaxPtr_Volts_T_s2p29 = FPM_FloatToFixed_m(EOLAmp_Volts_T_f32, s2p29_T);
		*StateVarMinPtr_Volts_T_s2p29 = -FPM_FloatToFixed_m(EOLAmp_Volts_T_f32, s2p29_T);
		RTOffset_Volts_T_f32 = EOLOffset_Volts_T_f32;
	}
	else
	{
		RTOffset_Volts_T_f32 = EOLOffset_Volts_T_f32 + StoredOffset_Volts_T_f32;
	}
	
	return(RTOffset_Volts_T_f32);
	
}


STATIC FUNC(float32, SA_MTRPOS2_CODE) RunTimeFilter(VAR(float32, AUTOMATIC) SigEst_Uls_T_f32,
													VAR(float32, AUTOMATIC) SigCorr_Volts_T_f32,
													VAR(float32, AUTOMATIC) OffsetDelta_Volts_T_f32,
													CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) StateVarPtr_Volts_T_s2p29)
{
	
	VAR(float32, AUTOMATIC) FilterInput_Volts_T_f32;
	VAR(sint16, AUTOMATIC) FilterInput_Volts_T_s2p13;
	VAR(float32, AUTOMATIC) Output_Volts_T_f32;
	
	if (SigEst_Uls_T_f32 > k_RTFiltEnThresh_Uls_f32)
	{
		FilterInput_Volts_T_f32 = (SigCorr_Volts_T_f32 / SigEst_Uls_T_f32) + OffsetDelta_Volts_T_f32;
		FilterInput_Volts_T_s2p13 = FPM_FloatToFixed_m(FilterInput_Volts_T_f32, s2p13_T);
		*StateVarPtr_Volts_T_s2p29 = LPF_SvUpdate_s16InFixKTrunc_m(FilterInput_Volts_T_s2p13, *StateVarPtr_Volts_T_s2p29, k_RTOffFiltKn_Cnt_u16);
	}
	
	Output_Volts_T_f32 = FPM_FixedToFloat_m(*StateVarPtr_Volts_T_s2p29, s2p29_T);
	
	return(Output_Volts_T_f32);
	
}


STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcOffsetFromMinMax(VAR(float32, AUTOMATIC) Min_Volts_T_f32,
														   VAR(float32, AUTOMATIC) Max_Volts_T_f32,
														   VAR(float32, AUTOMATIC) EOLOffset_Volts_T_f32)
{
	
	VAR(float32, AUTOMATIC) RTOffset_Volts_T_f32;
  	
  	RTOffset_Volts_T_f32 = (Max_Volts_T_f32 + Min_Volts_T_f32) / D_TWO_ULS_F32;
  	RTOffset_Volts_T_f32 = Limit_m(RTOffset_Volts_T_f32, -k_RTOffsetLmt_Volts_f32, k_RTOffsetLmt_Volts_f32);
  	RTOffset_Volts_T_f32 = RTOffset_Volts_T_f32 + EOLOffset_Volts_T_f32;
  	
  	return(RTOffset_Volts_T_f32);
	
}


STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcSinAmpRec(VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) EOLSinAmpRec_Uls_T_f32)
{
	
	VAR(float32, AUTOMATIC) SinRTAmpRec_Uls_T_f32;
	VAR(float32, AUTOMATIC) SinAmpRecVari_Uls_T_f32;
	
	SinRTAmpRec_Uls_T_f32 = D_TWO_ULS_F32 / TotSinAmp_Volts_T_f32;
	SinAmpRecVari_Uls_T_f32 = SinRTAmpRec_Uls_T_f32 - EOLSinAmpRec_Uls_T_f32;
	SinAmpRecVari_Uls_T_f32 = Limit_m(SinAmpRecVari_Uls_T_f32, -k_AmpRecVarLmt_Uls_f32, k_AmpRecVarLmt_Uls_f32);
	SinRTAmpRec_Uls_T_f32 = EOLSinAmpRec_Uls_T_f32 + SinAmpRecVari_Uls_T_f32;
	
	return(SinRTAmpRec_Uls_T_f32);
	
}


STATIC FUNC(float32, SA_MTRPOS2_CODE) CalcCosAmpRec(VAR(float32, AUTOMATIC) TotSinAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) TotCosAmp_Volts_T_f32,
													VAR(float32, AUTOMATIC) SinRTAmpRec_Uls_T_f32,
													VAR(float32, AUTOMATIC) SinCosNomRatio_Uls_T_f32,
													VAR(float32, AUTOMATIC) CosSinNomRatio_Uls_T_f32,
													VAR(float32, AUTOMATIC) RTToNomLowLmt_Uls_T_f32,
													VAR(float32, AUTOMATIC) RTToNomHighLmt_Uls_T_f32)
{
	
	VAR(float32, AUTOMATIC) SinCosRTRatio_Uls_T_f32;
	VAR(float32, AUTOMATIC) SinCosRTToNomRatio_Uls_T_f32;
	VAR(float32, AUTOMATIC) CosRTAmpRec_Uls_T_f32;
	
	SinCosRTRatio_Uls_T_f32 = TotSinAmp_Volts_T_f32 / TotCosAmp_Volts_T_f32;
	SinCosRTToNomRatio_Uls_T_f32 = SinCosRTRatio_Uls_T_f32 * CosSinNomRatio_Uls_T_f32;
	SinCosRTToNomRatio_Uls_T_f32 = Limit_m(SinCosRTToNomRatio_Uls_T_f32, RTToNomLowLmt_Uls_T_f32, RTToNomHighLmt_Uls_T_f32);
	SinCosRTRatio_Uls_T_f32 = SinCosRTToNomRatio_Uls_T_f32 * SinCosNomRatio_Uls_T_f32;
	CosRTAmpRec_Uls_T_f32 = SinCosRTRatio_Uls_T_f32 * SinRTAmpRec_Uls_T_f32;
	
	return(CosRTAmpRec_Uls_T_f32);
	
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
