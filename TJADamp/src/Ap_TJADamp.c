/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TJADamp.c
 *     Workspace:  C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ESG_Dev_65/TJADamp-1/TJADamp/autosar
 *     SW-C Type:  Ap_TJADamp
 *  Generated at:  Wed Jan 15 15:56:54 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TJADamp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Oct  3 14:23:51 2013
 * %version:          2 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Wed Jan 15 15:15:18 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/29/13  1        Selva       Initial version                                                            10273 
 * 01/14/13  2        Selva       Update to v2 of FDD CF11													 11088
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TJADamp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_TJADamp_Cfg.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "interpolation.h"

#define D_MINDENOM_MTRNM_F32  0.1f 
#define D_DAMPINGCMDMIN_MTRNM_F32			(-8.8F)
#define D_DAMPINGCMDMAX_MTRNM_F32			  8.8F



#define TJADAMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(TJAStateType, AUTOMATIC) TJADamp_TJAState_Cnt_M_enum;
#define TJADAMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define TJADAMP_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) TJADamp_LimitViolation_Cnt_M_lgc;
STATIC volatile VAR(boolean, AUTOMATIC) TJADamp_ErrorActive_Cnt_D_lgc;
#define TJADAMP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TJADAMP_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) TJADamp_ErrAcc_Cnt_M_u16;
#define TJADAMP_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define TJADAMP_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) TJADamp_FinalScaling_Uls_M_f32;
STATIC volatile VAR(float32, AUTOMATIC) TJADamp_BaseDamping_MtrNm_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) TJADamp_ScaleDamp_MtrNm_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) TJADamp_UpperLimitedDamp_MtrNm_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) TJADamp_TJATargetScale_Uls_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) TJADamp_Downslew_Uls_D_f32;
#define TJADAMP_STOP_SEC_VAR_CLEARED_32
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
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
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
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
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
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
 *   NTC_Num_BattTransOverVolt (182u)
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
 *   NTC_Num_DataOther2FltMsg_M (295u)
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
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
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
 * TJAStateType: Enumeration of integer in interval [1...3] with enumerators
 *   TJA_Inactive (1u)
 *   TJA_Active (2u)
 *   TJA_Error (3u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TJADAMP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TJADamp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TJADamp_Init
 *********************************************************************************************************************/
	
	TJADamp_TJAState_Cnt_M_enum = TJA_Inactive;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TJADamp_Per1
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
 *   Float Rte_IRead_TJADamp_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_TJADamp_Per1_TJADampSclRqst_Uls_f32(void)
 *   TJAStateType Rte_IRead_TJADamp_Per1_TJAStateRqst_Cnt_enum(void)
 *   Float Rte_IRead_TJADamp_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TJADamp_Per1_CustomDamp_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TJADamp_Per1_CustomDamp_MtrNm_f32(void)
 *   void Rte_IWrite_TJADamp_Per1_TJAState_Cnt_enum(TJAStateType data)
 *   TJAStateType *Rte_IWriteRef_TJADamp_Per1_TJAState_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TJADamp_Per1
 *********************************************************************************************************************/
		VAR(float32, AUTOMATIC)  MotorVelCRF_MtrRadpS_T_f32;
		VAR(float32, AUTOMATIC)  TJADampSclRqst_Uls_T_f32;
		VAR(TJAStateType, AUTOMATIC) TJAStateRqst_Cnt_T_enum;
		VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
		VAR(boolean, AUTOMATIC) DampingFWFltMode_Cnt_T_lgc;
		VAR(boolean, AUTOMATIC) DampingFWReached_Cnt_T_lgc;
		VAR(boolean, AUTOMATIC) TJAErrorActive_Cnt_T_lgc;
		VAR(uint16, AUTOMATIC) 	AbsMotorVelCRFFilt_MtrRadpS_T_u12p4;
		VAR(uint16, AUTOMATIC) 	AbsMtrVelCRF_MtrRadpS_T_u12p4;
		VAR(uint16, AUTOMATIC) 	TJAUpperLimitedDamp_MtrNm_T_u4p12;
		VAR(uint16, AUTOMATIC) 	TJABaseDamping_MtrNm_T_u4p12;
		VAR(float32, AUTOMATIC) TJABaseDamping_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) CustomDamp_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) TJAScaleDamp_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) TJALimitedDamp_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) TJADampRatio_Uls_T_f32;
		VAR(uint16, AUTOMATIC) 	VehSpd_Kph_T_u9p7;
		VAR(float32, AUTOMATIC) TJAUpperLimitedDamp_MtrNm_T_f32;

		/* Configurable Start of Runnable Checkpoint */
		Rte_Call_TJADamp_Per1_CP0_CheckpointReached();
		
		MotorVelCRF_MtrRadpS_T_f32 = Rte_IRead_TJADamp_Per1_MtrVelCRF_MtrRadpS_f32();
		TJADampSclRqst_Uls_T_f32 = Rte_IRead_TJADamp_Per1_TJADampSclRqst_Uls_f32();
		TJAStateRqst_Cnt_T_enum = Rte_IRead_TJADamp_Per1_TJAStateRqst_Cnt_enum();
		VehicleSpeed_Kph_T_f32 = Rte_IRead_TJADamp_Per1_VehicleSpeed_Kph_f32();
		
        /*** NTC failure Read   ***/ 
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DampingFWFltMode, &DampingFWFltMode_Cnt_T_lgc );
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DampingFWReached, &DampingFWReached_Cnt_T_lgc );
		
		/*** State flow ***/
		
		
		if (((TJAStateRqst_Cnt_T_enum != TJA_Inactive) && (TJAStateRqst_Cnt_T_enum != TJA_Active)) ||(DampingFWFltMode_Cnt_T_lgc == TRUE)
				|| (DampingFWReached_Cnt_T_lgc == TRUE)	||(TJADamp_LimitViolation_Cnt_M_lgc == TRUE))
			{
			     TJAErrorActive_Cnt_T_lgc = TRUE;
			}
		else	
			{
			     TJAErrorActive_Cnt_T_lgc = FALSE;			
			}

		TJADamp_ErrorActive_Cnt_D_lgc = TJAErrorActive_Cnt_T_lgc;

		
		if ((TJAErrorActive_Cnt_T_lgc ==TRUE) && (TJADamp_TJAState_Cnt_M_enum == TJA_Inactive))
			{
				TJADamp_TJAState_Cnt_M_enum = TJA_Error;
			}
		else if ((TJAStateRqst_Cnt_T_enum == TJA_Active) && (TJADamp_TJAState_Cnt_M_enum == TJA_Inactive))
			{
				TJADamp_TJAState_Cnt_M_enum = TJA_Active;
			}		
		else if ((TJAErrorActive_Cnt_T_lgc == TRUE) && (TJADamp_TJAState_Cnt_M_enum == TJA_Active)) 
			{
				TJADamp_TJAState_Cnt_M_enum = TJA_Error;
			}
		else if ((TJAStateRqst_Cnt_T_enum == TJA_Inactive) && (TJADamp_TJAState_Cnt_M_enum == TJA_Active))
			{
				TJADamp_TJAState_Cnt_M_enum = TJA_Inactive;
			}
		else if ((TJAStateRqst_Cnt_T_enum == TJA_Inactive) && (TJAErrorActive_Cnt_T_lgc ==FALSE) && (TJADamp_TJAState_Cnt_M_enum == TJA_Error))
			{
			    TJADamp_TJAState_Cnt_M_enum = TJA_Inactive;
			}	
		else
			{
			 /*** Do nothing ***/
			}
			
		
		
		/*** TJABaseDamping***/

		/***Damping based on Motor Velocity only**/
		AbsMotorVelCRFFilt_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32), u12p4_T);
		
		
		TJABaseDamping_MtrNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt( t_TJADampX_MtrRadpS_u12p4,
																	t_TJADampY_MtrNm_u4p12,
																	TableSize_m(t_TJADampX_MtrRadpS_u12p4 ),
																	AbsMotorVelCRFFilt_MtrRadpS_T_u12p4);
																	
																	
		TJABaseDamping_MtrNm_T_f32 =FPM_FixedToFloat_m(TJABaseDamping_MtrNm_T_u4p12, u4p12_T)	;		
		
		/***TJAScaleFactor***/	
		
		/**Slews requested scale factor at appropriate rate**/
		
		/** Override requested scale factor with zero if appropriate.
			Choose appropriate scale factor slew rate. Head toward target scale factor (original requested value, or zero) at a
			fixed slew rate upward or a dynamically chosen slew rate downward **/
				
		if (TJADamp_TJAState_Cnt_M_enum == TJA_Inactive)
			
			{
			 
				TJADamp_FinalScaling_Uls_M_f32 = Limit_m(D_ZERO_ULS_F32, (TJADamp_FinalScaling_Uls_M_f32-(k_TJADwnSlewInAct_UlspS_f32* D_2MS_SEC_F32)), (TJADamp_FinalScaling_Uls_M_f32+(k_TJAUpSlew_UlspS_f32* D_2MS_SEC_F32)));
				TJADamp_TJATargetScale_Uls_D_f32= D_ZERO_ULS_F32;
				TJADamp_Downslew_Uls_D_f32 = k_TJADwnSlewInAct_UlspS_f32;
			}
		
		else if (TJADamp_TJAState_Cnt_M_enum ==TJA_Error)
			{
				TJADamp_FinalScaling_Uls_M_f32 = Limit_m(D_ZERO_ULS_F32, (TJADamp_FinalScaling_Uls_M_f32-(k_TJADwnSlewInVald_UlspS_f32* D_2MS_SEC_F32)), (TJADamp_FinalScaling_Uls_M_f32+(k_TJAUpSlew_UlspS_f32* D_2MS_SEC_F32)));
				TJADamp_TJATargetScale_Uls_D_f32= D_ZERO_ULS_F32;
				TJADamp_Downslew_Uls_D_f32 = k_TJADwnSlewInVald_UlspS_f32;
				
			}
		else
			{
				TJADamp_FinalScaling_Uls_M_f32 = Limit_m(TJADampSclRqst_Uls_T_f32, (TJADamp_FinalScaling_Uls_M_f32-(k_TJADwnSlewActive_UlspS_f32* D_2MS_SEC_F32)), (TJADamp_FinalScaling_Uls_M_f32+(k_TJAUpSlew_UlspS_f32* D_2MS_SEC_F32)));
				TJADamp_TJATargetScale_Uls_D_f32= TJADampSclRqst_Uls_T_f32;
				TJADamp_Downslew_Uls_D_f32 = k_TJADwnSlewActive_UlspS_f32;
			}
			
		/*Apply the limited & ramped scale factor to base damping value.   */	
		
		TJAScaleDamp_MtrNm_T_f32 = TJABaseDamping_MtrNm_T_f32 *  TJADamp_FinalScaling_Uls_M_f32;
		
		TJADamp_BaseDamping_MtrNm_D_f32 =TJABaseDamping_MtrNm_T_f32;
		TJADamp_ScaleDamp_MtrNm_D_f32 = TJAScaleDamp_MtrNm_T_f32;
		
		/***Limit TJA damp***/
		/**Apply Limit to Incoming (unsigned) Command**/
		AbsMtrVelCRF_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32), u12p4_T);
		VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
		/*Applies vehicle speed and motor velocity dependant limit to the TJA damping command*/
		TJAUpperLimitedDamp_MtrNm_T_u4p12 = BilinearXYM_u16_u16Xu16YM_Cnt(VehSpd_Kph_T_u9p7, 
																AbsMtrVelCRF_MtrRadpS_T_u12p4, 
																t_TJAVehSpd_Kph_u9p7, 
																TableSize_m(t_TJAVehSpd_Kph_u9p7), 
																t_TJABoundX_MtrRadpS_u12p4, 
																(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_TJABoundY_MtrNm_u4p12[0], 
																TableSize_m(t_TJABoundX_MtrRadpS_u12p4));
		
		TJAUpperLimitedDamp_MtrNm_T_f32 =FPM_FixedToFloat_m(TJAUpperLimitedDamp_MtrNm_T_u4p12,u4p12_T);
		TJALimitedDamp_MtrNm_T_f32 = Limit_m(TJAScaleDamp_MtrNm_T_f32, D_ZERO_ULS_F32, TJAUpperLimitedDamp_MtrNm_T_f32 );
		TJADamp_UpperLimitedDamp_MtrNm_D_f32 = TJAUpperLimitedDamp_MtrNm_T_f32;
		
		/**Create (signed) Command Output**/
		CustomDamp_MtrNm_T_f32 = TJALimitedDamp_MtrNm_T_f32 * (float32)(Sign_f32_m(MotorVelCRF_MtrRadpS_T_f32));
		
		/**Determine TJA Disable Flag**/
		if ( TJAScaleDamp_MtrNm_T_f32 > D_MINDENOM_MTRNM_F32)
		{
		 TJADampRatio_Uls_T_f32 =  TJALimitedDamp_MtrNm_T_f32/TJAScaleDamp_MtrNm_T_f32;
		}
		else
		{
			TJADampRatio_Uls_T_f32 = D_ONE_ULS_F32;
		}
		
		/*Calculates if TJA damping command is being over-limited*/
		if (TJADampRatio_Uls_T_f32 <= k_TJADampRatioThresh_Uls_f32)
		{
			TJADamp_ErrAcc_Cnt_M_u16 = DiagPStep_m(TJADamp_ErrAcc_Cnt_M_u16, k_TJADampErrAcc_Cnt_Str);
			if(DiagFailed_m(TJADamp_ErrAcc_Cnt_M_u16, k_TJADampErrAcc_Cnt_Str) ==  TRUE)
				{
					TJADamp_LimitViolation_Cnt_M_lgc = TRUE;
				}
		}
		else
		{
			TJADamp_ErrAcc_Cnt_M_u16 = DiagNStep_m(TJADamp_ErrAcc_Cnt_M_u16, k_TJADampErrAcc_Cnt_Str);
			if(TJADamp_ErrAcc_Cnt_M_u16 == 0U)
				{
					TJADamp_LimitViolation_Cnt_M_lgc = FALSE;
				}
		}
		
		CustomDamp_MtrNm_T_f32 =  Limit_m(CustomDamp_MtrNm_T_f32, D_DAMPINGCMDMIN_MTRNM_F32, D_DAMPINGCMDMAX_MTRNM_F32);
		/* Write Outputs back to RTE*/
		Rte_IWrite_TJADamp_Per1_CustomDamp_MtrNm_f32(CustomDamp_MtrNm_T_f32);
		Rte_IWrite_TJADamp_Per1_TJAState_Cnt_enum(TJADamp_TJAState_Cnt_M_enum);
		

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_TJADamp_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TJADAMP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
