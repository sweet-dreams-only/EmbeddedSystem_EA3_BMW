/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrPos3.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrPos/autosar
 *     SW-C Type:  Sa_MtrPos3
 *  Generated at:  Wed Feb 20 16:18:08 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrPos3>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Oct 19 18:02:18 2012
 * %version:          4 %
 * %derived_by:       xz0btk %
 * %date_modified:    Wed Feb 20 16:21:21 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 10/23/12  1        OT        Implemented FDD 06B v004                                                         6472
 * 02/07/13  2        JJW       Correction of reintroduced FDD anomaly 3999 in the sin^2 + cos^2 check
 *								Correction of sin2 and cos2 swap in DiagMech MtrPos Calc 
 *								Addition of MtrPos3_DiagCorrectedMtrPos_Rev_M_f32 modulo 1 operation
 *								Switch from BEMFCal to R_BEMFCal use in MtrPos3_DiagCorrectedMtrPos_Rev_M_f32 calc per
 *									FDD requirements.
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

#include "Rte_Sa_MtrPos3.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define MTRPOS_C
#include "Sa_MtrPos.h"
#include "Sa_MtrPos3_Cfg.h"
#include "fixmath.h"

#include "CalConstants.h"
#include "GlobalMacro.h"


#define NUMOCTANTS_CNT_u16  8U
#define D_HALF_ULS_F32		0.5f
#define D_THREE_ULS_F32		3.0f
#define D_ELECREVPMECHREV_ULS_U16	3u
#define D_MASK16BITS_CNT_U32		0x0000FFFFUL

typedef struct {
	float32        offset_f32;
	sint8          slope_s08;
	boolean        SinMinVal_lgc;
} TaylorATanTblType;


#define MTRPOS3_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(TaylorATanTblType, RTE_SA_MTRPOSCH2_APPL_CODE) TaylorATanTbl[NUMOCTANTS_CNT_u16] = {
		{0.0f,                   1, TRUE},
		{(0.5f * D_PI_ULS_F32), -1, FALSE},
		{(0.5f * D_PI_ULS_F32),  1, FALSE},
		{D_PI_ULS_F32,          -1, TRUE},
		{D_PI_ULS_F32,           1, TRUE},
		{(1.5f * D_PI_ULS_F32), -1, FALSE},
		{(1.5f * D_PI_ULS_F32),  1, FALSE},
		{(2.0f * D_PI_ULS_F32), -1, TRUE}
	};
#define MTRPOS3_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


/* Module Level Variables */
#define MTRPOS3_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, SA_MTRPOS3_VAR) MtrPos3_SysCValidityFltAcc_Cnt_M_u16;
STATIC VAR(uint16, SA_MTRPOS3_VAR) MtrPos3_SysCCorrFltAcc_Cnt_M_u16;
#define MTRPOS3_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define MTRPOS3_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
				VAR(float32, SA_MTRPOS3_VAR) MtrPos3_DiagCorrectedMtrPos_Rev_M_f32;
				VAR(float32, SA_MTRPOS3_VAR) MtrPos3_DiagMechMtrPos_Rev_M_f32;
STATIC volatile VAR(float32, SA_MTRPOS3_VAR) MtrPos3_SysCErrorTerm_Rev_D_f32;
STATIC volatile VAR(float32, SA_MTRPOS2_VAR) MtrPos3_SysCValidErr_VoltsSqrd_D_f32;
#define MTRPOS3_STOP_SEC_VAR_CLEARED_32
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
 * SInt8: Integer in interval [-128...127] (standard type)
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
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_ZERO_ULS_F32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRPOS3_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3_Per1
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
 *   Float Rte_IRead_MtrPos3_Per1_InvCos2Scaled_Volt_f32(void)
 *   Float Rte_IRead_MtrPos3_Per1_InvSin2Scaled_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS3_APPL_CODE) MtrPos3_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) InvCos2_Volts_T_f32;
	VAR(float32, AUTOMATIC) InvSin2_Volts_T_f32;
	VAR(float32, AUTOMATIC) Sin2_Volts_T_f32;
	VAR(float32, AUTOMATIC) Cos2_Volts_T_f32;
	VAR(float32, AUTOMATIC) AbsSin2_Volts_T_f32;
	VAR(float32, AUTOMATIC) AbsCos2_Volts_T_f32;
	VAR(uint8,   AUTOMATIC) Octant_Cnt_T_u08;
	VAR(float32, AUTOMATIC) TanTheta_Uls_T_f32;
	VAR(float32, AUTOMATIC) DiagMechMtrPos_Rev_T_f32;
	VAR(uint16, AUTOMATIC) DiagCorrectedMtrPos_Rev_T_u0p16;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrPos3_Per1_CP0_CheckpointReached();
	
	InvCos2_Volts_T_f32 = Rte_IRead_MtrPos3_Per1_InvCos2Scaled_Volt_f32();
	InvSin2_Volts_T_f32 = Rte_IRead_MtrPos3_Per1_InvSin2Scaled_Volt_f32();
	
	
	
	/*** Compute Alternate Motor Position ***/
	
	Sin2_Volts_T_f32 = k_NominalOffset_Volts_f32 - InvSin2_Volts_T_f32;
	Cos2_Volts_T_f32 = k_NominalOffset_Volts_f32 - InvCos2_Volts_T_f32;
	
	AbsSin2_Volts_T_f32 = Abs_f32_m(Sin2_Volts_T_f32);
	AbsCos2_Volts_T_f32 = Abs_f32_m(Cos2_Volts_T_f32);
	
	if( Sin2_Volts_T_f32 >= D_ZERO_ULS_F32 )
	{
		if( Cos2_Volts_T_f32 >= D_ZERO_ULS_F32 )
		{
			if( AbsSin2_Volts_T_f32 <= AbsCos2_Volts_T_f32 )
			{
				Octant_Cnt_T_u08 = 0U;
			}
			else
			{
				Octant_Cnt_T_u08 = 1U;
			}
		}
		else
		{
			if( AbsSin2_Volts_T_f32 >= AbsCos2_Volts_T_f32 )
			{
				Octant_Cnt_T_u08 = 2U;
			}
			else
			{
				Octant_Cnt_T_u08 = 3U;
			}
		}
	}
	else
	{
		if( Cos2_Volts_T_f32 <= D_ZERO_ULS_F32 )
		{
			if( AbsSin2_Volts_T_f32 <= AbsCos2_Volts_T_f32 )
			{
				Octant_Cnt_T_u08 = 4U;
			}
			else
			{
				Octant_Cnt_T_u08 = 5U;
			}
		}
		else
		{
			if( AbsSin2_Volts_T_f32 >= AbsCos2_Volts_T_f32 )
			{
				Octant_Cnt_T_u08 = 6U;
			}
			else
			{
				Octant_Cnt_T_u08 = 7U;
			}
		}
	}
	
	if( TRUE == TaylorATanTbl[Octant_Cnt_T_u08].SinMinVal_lgc )
	{
		TanTheta_Uls_T_f32 = AbsSin2_Volts_T_f32 / AbsCos2_Volts_T_f32;
	}
	else
	{
		TanTheta_Uls_T_f32 = AbsCos2_Volts_T_f32 / AbsSin2_Volts_T_f32;
	}
	
	DiagMechMtrPos_Rev_T_f32 = ( ( (((float32)TaylorATanTbl[Octant_Cnt_T_u08].slope_s08) * D_THREE_ULS_F32 * TanTheta_Uls_T_f32) /
								   (D_THREE_ULS_F32 + (TanTheta_Uls_T_f32 * TanTheta_Uls_T_f32)) ) +
								 TaylorATanTbl[Octant_Cnt_T_u08].offset_f32 ) /
							   D_2PI_ULS_F32;
	
	/* Performing calculation in fixed point to provide an easy and efficient modulo 1 algorithm (i.e. the roll-over for a 0 to 0.99
	 * number can be accomplished by simply masking out the integer portion of the result and keeping the fractional portions.
	 * Which is can be realized for a u0p16 number by the compiled code as simply saving the lower 16 bits of the accumulator.)
	 * In the following expression an explicit mask is used even though use of 16 bit math will provide the correct result naturally.
	 * The explicit mask with 0xFFFF explicitly indicates to the compiler that only the lower 16 bits of the result are to be used in
	 * subsequent calculations.  Without this explicit definition an optimizer algorithm could choose to use a 32 bit result in subsequent
	 * calculations which in this case would result in an incorrect computation. */
	DiagCorrectedMtrPos_Rev_T_u0p16 = (((FPM_FloatToFixed_m(DiagMechMtrPos_Rev_T_f32, u16p16_T) * (uint32)D_ELECREVPMECHREV_ULS_U16) -
									(uint32)(~MtrPos_EOLDataPtr_Cnt_M_Str->R_BEMFCal_Rev_u0p16)) & D_MASK16BITS_CNT_U32);

	MtrPos3_DiagCorrectedMtrPos_Rev_M_f32 = FPM_FixedToFloat_m(DiagCorrectedMtrPos_Rev_T_u0p16, u0p16_T);
	MtrPos3_DiagMechMtrPos_Rev_M_f32 = DiagMechMtrPos_Rev_T_f32;
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrPos3_Per1_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3_Per2
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
 *   Float Rte_IRead_MtrPos3_Per2_InvCos2Scaled_Volt_f32(void)
 *   Float Rte_IRead_MtrPos3_Per2_InvSin2Scaled_Volt_f32(void)
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

FUNC(void, RTE_SA_MTRPOS3_APPL_CODE) MtrPos3_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3_Per2
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) CorrectedMtrPos_Rev_T_f32;
	VAR(float32, AUTOMATIC) InvCos2_Volts_T_f32;
	VAR(float32, AUTOMATIC) InvSin2_Volts_T_f32;
	VAR(float32, AUTOMATIC) SysCErrorTerm_Rev_T_f32;
	VAR(float32, AUTOMATIC) SinCorr_Volts_T_f32;
	VAR(float32, AUTOMATIC) CosCorr_Volts_T_f32;
	VAR(float32, AUTOMATIC) SysCValidErr_VoltsSqrd_T_f32;
	VAR(uint8, AUTOMATIC) IdleDblBuf_Cnt_T_u08;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrPos3_Per2_CP0_CheckpointReached();
	
	/* Active buffer switching is managed external to the MtrPos Component */
	CDD_Read_MtrPos_ActvDblBuf_Cnt_u08(&IdleDblBuf_Cnt_T_u08);
	IdleDblBuf_Cnt_T_u08 = (IdleDblBuf_Cnt_T_u08 & 1)^1;
	
	CorrectedMtrPos_Rev_T_f32 = FPM_FixedToFloat_m(MtrPos_CorrectedMtrPos_Rev_M_u0p16[IdleDblBuf_Cnt_T_u08], u0p16_T);
	InvCos2_Volts_T_f32 = Rte_IRead_MtrPos3_Per2_InvCos2Scaled_Volt_f32();
	InvSin2_Volts_T_f32 = Rte_IRead_MtrPos3_Per2_InvSin2Scaled_Volt_f32();
	
	
	
	/*** Motor Position Cross Check Correlation Failure Determination ***/
	
	SysCErrorTerm_Rev_T_f32 = Abs_f32_m(CorrectedMtrPos_Rev_T_f32 - MtrPos3_DiagCorrectedMtrPos_Rev_M_f32);
	
	if( SysCErrorTerm_Rev_T_f32 > D_HALF_ULS_F32 )
	{
		SysCErrorTerm_Rev_T_f32 = Abs_f32_m(SysCErrorTerm_Rev_T_f32 - D_ONE_ULS_F32);
	}
	
	if( SysCErrorTerm_Rev_T_f32 > k_CorrelationError_Rev_f32 )
	{
		MtrPos3_SysCCorrFltAcc_Cnt_M_u16 = DiagPStep_m(MtrPos3_SysCCorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str);
		
		if( DiagFailed_m(MtrPos3_SysCCorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str) == TRUE )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RedPriVsSec_SinCosCorr, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		MtrPos3_SysCCorrFltAcc_Cnt_M_u16 = DiagNStep_m(MtrPos3_SysCCorrFltAcc_Cnt_M_u16, k_MtrPosCorrDiag_Cnt_str);
		
		if( MtrPos3_SysCCorrFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RedPriVsSec_SinCosCorr, 0x01, NTC_STATUS_PASSED);
		}
	}
	
	
	
	/*** Secondary Motor Position Sensor Validity Diagnostic ***/
	SinCorr_Volts_T_f32 = InvSin2_Volts_T_f32 - k_NominalOffset_Volts_f32;
	CosCorr_Volts_T_f32 = InvCos2_Volts_T_f32 - k_NominalOffset_Volts_f32;
	SysCValidErr_VoltsSqrd_T_f32 = (SinCorr_Volts_T_f32 * SinCorr_Volts_T_f32) + (CosCorr_Volts_T_f32 * CosCorr_Volts_T_f32);
	
	if( (SysCValidErr_VoltsSqrd_T_f32 < k_SysCValMinError_VoltsSqrd_f32) ||
	    (SysCValidErr_VoltsSqrd_T_f32 > k_SysCValMaxError_VoltsSqrd_f32) )
	{
		MtrPos3_SysCValidityFltAcc_Cnt_M_u16 = DiagPStep_m(MtrPos3_SysCValidityFltAcc_Cnt_M_u16, k_SysCMtrPosValDiag_Cnt_str);
		
		if( DiagFailed_m(MtrPos3_SysCValidityFltAcc_Cnt_M_u16, k_SysCMtrPosValDiag_Cnt_str) == TRUE )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SecMSB_SinCosCorr, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		MtrPos3_SysCValidityFltAcc_Cnt_M_u16 = DiagNStep_m(MtrPos3_SysCValidityFltAcc_Cnt_M_u16, k_SysCMtrPosValDiag_Cnt_str);
		
		if( MtrPos3_SysCValidityFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SecMSB_SinCosCorr, 0x01, NTC_STATUS_PASSED);
		}
	}
	
	
	
	MtrPos3_SysCErrorTerm_Rev_D_f32 = SysCErrorTerm_Rev_T_f32;
	MtrPos3_SysCValidErr_VoltsSqrd_D_f32 = SysCValidErr_VoltsSqrd_T_f32;
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrPos3_Per2_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRPOS3_APPL_CODE
#include "MemMap.h"


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
