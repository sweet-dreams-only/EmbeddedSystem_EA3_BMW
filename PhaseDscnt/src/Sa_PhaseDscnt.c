/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_PhaseDscnt.c
 *     Workspace:  C:/Synergy/PhaseDscnt-zz4r1x/PhaseDscnt/autosar
 *     SW-C Type:  Sa_PhaseDscnt
 *  Generated at:  Mon Mar 18 16:03:32 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_PhaseDscnt>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          13 %
 * %date_modified:    Wed Jun 26 14:29:34 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/12/11  2        JJW       New generation of Davinci template
 * 01/12/11  3        JJW       Added WARM INIT Request and Release
 * 04/11/11  4        LWW       Updated for states and modes design changes
 * 10/12/12  5        OT        Implemented FDD 47 v005              3685
 * 01/16/12  6        Selva     Clearing of motor current filter is removed
 * 03/02/13	 8 		  KJS		Corrected Anomalies 4484, 4360, and 4358. QAC Updates and updated to 
 *								revision 8 of FDD.  
 * 03/05/13	 9 		  Selva	    Corrected Anomalies 4358. FDD V9 updated 
 * 03/17/13  10 & 11  BWL       Updated per FDD v10.
 * 03/18/13  12       BWL       Remove start bit per change to hardware power up.
 * 06/26/13  13       NRAR      Fixed for Anomaly 4792, 5180
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


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_PhaseDscnt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Sa_PhaseDscnt_Cfg.h"


#include "GlobalMacro.h"
#include "filters.h"
#include "CalConstants.h"


#define D_2MS_MS_U16	2u


typedef enum {
	PHSDISC_CLOSEINPROGRESS = 0u,
	PHSDISC_CLOSED = 1u,
	PHSDISC_OPENINPROGRESS = 2u,
	PHSDISC_OPEN = 3u
} PhaseDisconStatType;


typedef enum {
	PHSDISCINIT_START = 0u,
	PHSDISCINIT_STAGE1,
	PHSDISCINIT_STAGE2,
	PHSDISCINIT_STAGE3,
	PHSDISCINIT_COMPLETE
} PhaseDiscInitDiagStateType;


#define PHASEDSCNT_START_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(sint16, SA_PHASEDSCNT_CONST) T_PHASEADVSELECT_CNT_S16[5] = {   0,
																			-1536, /* Stage 1 */
																		  0, /* Stage 2 */
																		  1536, /* Stage 3 */
																			0 };
#define PHASEDSCNT_STOP_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */


#define PHASEDSCNT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(Rte_ModeType_StaMd_Mode,    SA_PHASEDSCNT_VAR) PrevSystemStatePer1_Cnt_M_enum;
STATIC VAR(Rte_ModeType_StaMd_Mode,    SA_PHASEDSCNT_VAR) PrevSystemStatePer2_Cnt_M_enum;
STATIC VAR(PhaseDisconStatType,        SA_PHASEDSCNT_VAR) PhaseDisconStat_Cnt_M_enum;
STATIC VAR(PhaseDiscInitDiagStateType, SA_PHASEDSCNT_VAR) PhaseDiscInitDiagState_Cnt_M_enum;
STATIC VAR(LPF32KSV_Str,               SA_PHASEDSCNT_VAR) PDTestKSV_Cnt_M_str;
STATIC VAR(LPF32KSV_Str,               SA_PHASEDSCNT_VAR) IMeasLPFKSV_Cnt_M_str;
STATIC VAR(boolean,                    SA_PHASEDSCNT_VAR) PDSupplyHiLatched_Cnt_M_lgc;
STATIC VAR(boolean,                    SA_PHASEDSCNT_VAR) PDSupplyHiComplete_Cnt_M_lgc;
STATIC VAR(boolean,                    SA_PHASEDSCNT_VAR) IMeasTestDone_Cnt_M_lgc;
STATIC VAR(boolean,                    SA_PHASEDSCNT_VAR) PDActivateTest_Cnt_M_lgc;
#define PHASEDSCNT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define PHASEDSCNT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, SA_PHASEDSCNT_VAR) PDCloseTimer_mS_M_u32;
STATIC VAR(uint32, SA_PHASEDSCNT_VAR) PDOpenTimer_mS_M_u32;
STATIC VAR(uint32, SA_PHASEDSCNT_VAR) PDTestFailCurrTimer_mS_M_u32;
STATIC VAR(uint32, SA_PHASEDSCNT_VAR) InitialTime_mS_M_u32;
STATIC VAR(float32, SA_PHASEDSCNT_VAR) PDTestModIndex_Uls_M_f32;
#define PHASEDSCNT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define PHASEDSCNT_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) PDTestScansCtr_Cnt_M_u16;
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) ChrgPmpHiFltAcc_Cnt_M_u16;
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) ChrgPmpLowFltAcc_Cnt_M_u16;
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) PDSuplHighFltAcc_Cnt_M_u16;
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) IMeasAcuTime_mS_M_u16;
STATIC VAR(uint16, SA_PHASEDSCNT_VAR) IMeasNullFltAcc_Cnt_M_u16;
STATIC VAR(sint16, SA_PHASEDSCNT_VAR) PDPhaseAdvSelect_Cnt_M_s16;
#define PHASEDSCNT_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define PHASEDSCNT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(uint8,   SA_PHASEDSCNT_VAR) PDControlStat_Cnt_D_u08;
#define PHASEDSCNT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define PHASEDSCNT_START_SEC_VAR_SAVED_ZONEH_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, SA_PHASEDSCNT_VAR) SavedPrevPDSuplCnt_Cnt_M_u08;
STATIC VAR(uint8, SA_PHASEDSCNT_VAR) SavedPDSuplHiCnt_Cnt_M_u08;
STATIC VAR(uint8, SA_PHASEDSCNT_VAR) SavedPrevIMeasNullCnt_Cnt_M_u08;
STATIC VAR(uint8, SA_PHASEDSCNT_VAR) SavedIMeasNullCnt_Cnt_M_u08;
#define PHASEDSCNT_STOP_SEC_VAR_SAVED_ZONEH_8
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
 * SInt16: Integer in interval [-32768...32767] (standard type)
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
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_QUADRANT1_CNT_U8 = 1u
 * UInt8: D_QUADRANT2_CNT_U8 = 2u
 * UInt8: D_QUADRANT3_CNT_U8 = 3u
 * UInt8: D_QUADRANT4_CNT_U8 = 4u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_PHASEDSCNT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaseDscnt_Init1
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaseDscnt_Init1
 *********************************************************************************************************************/
	
	
	PrevSystemStatePer1_Cnt_M_enum = RTE_MODE_StaMd_Mode_OFF;
	PrevSystemStatePer2_Cnt_M_enum = RTE_MODE_StaMd_Mode_OFF;
	PhaseDisconStat_Cnt_M_enum = PHSDISC_OPEN;
	LPF_KUpdate_f32_m(k_IMeasLPFfc_Hz_f32, D_2MS_SEC_F32, &IMeasLPFKSV_Cnt_M_str);
	LPF_KUpdate_f32_m(k_PDTestFltrCurrLPFKn_Hz_f32, D_2MS_SEC_F32, &PDTestKSV_Cnt_M_str);
	
	/*These variables are inteded to latch the last value written to them.*/
	PDActivateTest_Cnt_M_lgc = Rte_InitValue_PDActivateTest_Cnt_lgc;
	PDPhaseAdvSelect_Cnt_M_s16 = Rte_InitValue_PDPhaseAdvSelect_Cnt_s16;
	PDTestModIndex_Uls_M_f32 = Rte_InitValue_PDTestModIndex_Uls_f32;
	
	
	
	/** Current Measurement Null Count Checking & Clearing **/
	
	if( SavedIMeasNullCnt_Cnt_M_u08 <= SavedPrevIMeasNullCnt_Cnt_M_u08 )
	{
		SavedIMeasNullCnt_Cnt_M_u08 = D_ZERO_CNT_U8;
	}
	
	SavedPrevIMeasNullCnt_Cnt_M_u08 = SavedIMeasNullCnt_Cnt_M_u08;
	
	if( SavedIMeasNullCnt_Cnt_M_u08 >= k_IMeasNullCntsToFlt_Cnt_u08 )
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CurrentMeas1, 0x04U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CurrentMeas1, 0x04U, NTC_STATUS_PASSED);
	}
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaseDscnt_Per1
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
 *   UInt8 Rte_IRead_PhaseDscnt_Per1_MotorQuadrant_Cnt_u08(void)
 *   Float Rte_IRead_PhaseDscnt_Per1_MotorVelMRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_PhaseDscnt_Per1_RawCurrFiltered_Amp_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PhaseDscnt_Per1_PDActivateTest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PhaseDscnt_Per1_PDActivateTest_Cnt_lgc(void)
 *   void Rte_IWrite_PhaseDscnt_Per1_PDPhaseAdvSelect_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_PhaseDscnt_Per1_PDPhaseAdvSelect_Cnt_s16(void)
 *   void Rte_IWrite_PhaseDscnt_Per1_PDTestModIndex_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PhaseDscnt_Per1_PDTestModIndex_Uls_f32(void)
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

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaseDscnt_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint8,   AUTOMATIC) MotorQuadrant_Cnt_T_u08;
	VAR(float32, AUTOMATIC) MotorVelMRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) RawCurrFiltered_Amp_T_f32;
	VAR(float32, AUTOMATIC) AbsMotorVelMRF_MtrRadpS_T_f32;
	
	VAR(float32, AUTOMATIC) PDTestFiltCurr_Amp_T_f32;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) IMeasLPF_Amp_T_f32;
	
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) CurrentSysState_Cnt_T_enum;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PhaseDscnt_Per1_CP0_CheckpointReached();
	
	
	MotorQuadrant_Cnt_T_u08 = Rte_IRead_PhaseDscnt_Per1_MotorQuadrant_Cnt_u08();
	MotorVelMRF_MtrRadpS_T_f32 = Rte_IRead_PhaseDscnt_Per1_MotorVelMRF_MtrRadpS_f32();
	RawCurrFiltered_Amp_T_f32 = Rte_IRead_PhaseDscnt_Per1_RawCurrFiltered_Amp_f32();
	AbsMotorVelMRF_MtrRadpS_T_f32 = Abs_f32_m(MotorVelMRF_MtrRadpS_T_f32);
	CurrentSysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	
	/*** Phase Disconnect Failed Closed (At INIT) ***/
	
	/* The FDD 47 has flag "StartPDInittest" to activate this loop
	   But 	actual implementation varies from FDD47 due to HW powerup */
	/* Refer the note in "Closing the phase disconnect" in FDD 47 */   
	if( CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE )
	{
		if(PhaseDiscInitDiagState_Cnt_M_enum < PHSDISCINIT_COMPLETE)
		{
			if( PhaseDiscInitDiagState_Cnt_M_enum == PHSDISCINIT_START )
			{
				PDActivateTest_Cnt_M_lgc = TRUE;
				PDTestModIndex_Uls_M_f32 = k_PDTestModIdx_Uls_f32;
				
				PhaseDiscInitDiagState_Cnt_M_enum = PHSDISCINIT_STAGE1;
				PDTestScansCtr_Cnt_M_u16 = D_ZERO_CNT_U16;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDTestFailCurrTimer_mS_M_u32);
				PDTestKSV_Cnt_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
			}
			else
			{
				PDTestScansCtr_Cnt_M_u16++;
				
				PDTestFiltCurr_Amp_T_f32 = LPF_OpUpdate_f32_m(RawCurrFiltered_Amp_T_f32, &PDTestKSV_Cnt_M_str);
				
				if( PDTestScansCtr_Cnt_M_u16 >= k_PDTestMinScans_Cnt_u16 )
				{
					if( PDTestFiltCurr_Amp_T_f32 <= k_PDTestFailCurr_Amp_f32 )
					{
						(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDTestFailCurrTimer_mS_M_u32);
						ElapsedTime_mS_T_u16 = D_ZERO_CNT_U16;
					}
					else
					{
						(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PDTestFailCurrTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					}
					
					if( ElapsedTime_mS_T_u16 >= k_PDTestMinFail_mS_u16 )
					{
						PDTestModIndex_Uls_M_f32 = D_ZERO_ULS_F32;
						PDPhaseAdvSelect_Cnt_M_s16 = D_ZERO_CNT_S16;
						PDActivateTest_Cnt_M_lgc = TRUE;
						
						PhaseDiscInitDiagState_Cnt_M_enum = PHSDISCINIT_COMPLETE;
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseDscnt, 0x01U, NTC_STATUS_FAILED);
					}
					else if( PDTestScansCtr_Cnt_M_u16 >= k_PDTestMaxScans_Cnt_u16 )
					{
						PhaseDiscInitDiagState_Cnt_M_enum++;
						PDTestScansCtr_Cnt_M_u16 = D_ZERO_CNT_U16;
						(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDTestFailCurrTimer_mS_M_u32);
						
						
						if( PhaseDiscInitDiagState_Cnt_M_enum == PHSDISCINIT_COMPLETE )
						{
							PDTestModIndex_Uls_M_f32 = D_ZERO_ULS_F32;
							PDPhaseAdvSelect_Cnt_M_s16 = D_ZERO_CNT_S16;
							PDActivateTest_Cnt_M_lgc = TRUE;
							
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseDscnt, 0x01U, NTC_STATUS_PASSED);
						}
					}
					else
					{
						/* do nothing */
					}
				}
				else
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDTestFailCurrTimer_mS_M_u32);
				}
			}
			
			PDPhaseAdvSelect_Cnt_M_s16 = T_PHASEADVSELECT_CNT_S16[PhaseDiscInitDiagState_Cnt_M_enum];
		}
	}
	
	
	
	
	
	/*** Current Measurement Diagnostic Null Value ***/
	
	if( CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE )
	{
		if( IMeasTestDone_Cnt_M_lgc == FALSE )
		{
			if( PrevSystemStatePer1_Cnt_M_enum != RTE_MODE_StaMd_Mode_OPERATE )
			{
				IMeasAcuTime_mS_M_u16 = D_ZERO_CNT_U16;
				IMeasNullFltAcc_Cnt_M_u16 = D_ZERO_CNT_U16;
			}
			
			IMeasLPF_Amp_T_f32 = LPF_OpUpdate_f32_m(RawCurrFiltered_Amp_T_f32, &IMeasLPFKSV_Cnt_M_str);
			
			if( (AbsMotorVelMRF_MtrRadpS_T_f32 > k_IMeasNullDetectMtrVel_MtrRadpS_f32) &&
				( (MotorQuadrant_Cnt_T_u08 == D_QUADRANT1_CNT_U8) ||
				  (MotorQuadrant_Cnt_T_u08 == D_QUADRANT3_CNT_U8) ) )
			{
				if( (Abs_f32_m(IMeasLPF_Amp_T_f32)) > k_IMeasNotNull_Amp_f32 )
				{
					IMeasNullFltAcc_Cnt_M_u16 = DiagPStep_m(IMeasNullFltAcc_Cnt_M_u16, k_IMeasNull_Cnt_str);
					
					if( DiagFailed_m(IMeasNullFltAcc_Cnt_M_u16, k_IMeasNull_Cnt_str) == TRUE )
					{
						IMeasTestDone_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					IMeasNullFltAcc_Cnt_M_u16 = DiagNStep_m(IMeasNullFltAcc_Cnt_M_u16, k_IMeasNull_Cnt_str);
				}
				
				if( IMeasAcuTime_mS_M_u16 > k_IMeasTestDur_mS_u16 )
				{
					IMeasTestDone_Cnt_M_lgc = TRUE;
					
					if( SavedIMeasNullCnt_Cnt_M_u08 < 255u )
					{
						SavedIMeasNullCnt_Cnt_M_u08++;
					}
					else
					{
						SavedPrevIMeasNullCnt_Cnt_M_u08 = 254u;
					}
				}
				else
				{
					IMeasAcuTime_mS_M_u16 += D_2MS_MS_U16;
				}
			}
			else
			{
				IMeasNullFltAcc_Cnt_M_u16 = DiagNStep_m(IMeasNullFltAcc_Cnt_M_u16, k_IMeasNull_Cnt_str);
			}
		}
	}
	
	PrevSystemStatePer1_Cnt_M_enum = CurrentSysState_Cnt_T_enum;
	/* Refer the note in "Operations for forcing the Mod Index and phase advance" in FDD 47 */
	Rte_IWrite_PhaseDscnt_Per1_PDActivateTest_Cnt_lgc(PDActivateTest_Cnt_M_lgc);
	Rte_IWrite_PhaseDscnt_Per1_PDPhaseAdvSelect_Cnt_s16(PDPhaseAdvSelect_Cnt_M_s16);
	Rte_IWrite_PhaseDscnt_Per1_PDTestModIndex_Uls_f32(PDTestModIndex_Uls_M_f32);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_PhaseDscnt_Per1_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaseDscnt_Per2
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
 *   Float Rte_IRead_PhaseDscnt_Per2_PDChrgPmpFdbkADC_Volt_f32(void)
 *   Float Rte_IRead_PhaseDscnt_Per2_PDSuplFdbkADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PhaseDscnt_Per2_PDActivateTest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PhaseDscnt_Per2_PDActivateTest_Cnt_lgc(void)
 *   void Rte_IWrite_PhaseDscnt_Per2_PDPhaseAdvSelect_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_PhaseDscnt_Per2_PDPhaseAdvSelect_Cnt_s16(void)
 *   void Rte_IWrite_PhaseDscnt_Per2_PDTestModIndex_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PhaseDscnt_Per2_PDTestModIndex_Uls_f32(void)
 *   void Rte_IWrite_PhaseDscnt_Per2_PhsDiscTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PhaseDscnt_Per2_PhsDiscTestComplete_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NHETSigCtrl_GetPhaseDisconnectSignal(UInt8 *Signal_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
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

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaseDscnt_Per2
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) PDChrgPmpFdbkADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) PDSuplFdbkADC_Volt_T_f32;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) PhsDiscTestComplete_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) PDControlStat_Cnt_T_u08;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) CurrentSysState_Cnt_T_enum;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PhaseDscnt_Per2_CP0_CheckpointReached();
	
	
	PDChrgPmpFdbkADC_Volt_T_f32 = Rte_IRead_PhaseDscnt_Per2_PDChrgPmpFdbkADC_Volt_f32();
	PDSuplFdbkADC_Volt_T_f32 = Rte_IRead_PhaseDscnt_Per2_PDSuplFdbkADC_Volt_f32();
	CurrentSysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	
	
	
	/*** Startup and Diagnostic Coordination ***/
	
	if( CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE )
	{
		
		/** Closing the Phase Disconnect **/
		
		if( (PhaseDisconStat_Cnt_M_enum != PHSDISC_CLOSED) &&
			(PhaseDiscInitDiagState_Cnt_M_enum == PHSDISCINIT_COMPLETE) )
		{
			if( PhaseDisconStat_Cnt_M_enum == PHSDISC_CLOSEINPROGRESS )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PDCloseTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				if( ElapsedTime_mS_T_u16 > k_PhDiscStartTime_mS_u16 )
				{
					PhaseDisconStat_Cnt_M_enum = PHSDISC_CLOSED;
					
					PDActivateTest_Cnt_M_lgc = FALSE;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDCloseTimer_mS_M_u32);
				(void)Rte_Call_NHETSigCtrl_SetPhaseDisconnectSignal(TRUE);
				PhaseDisconStat_Cnt_M_enum = PHSDISC_CLOSEINPROGRESS;
				
				PDTestModIndex_Uls_M_f32 = D_ZERO_ULS_F32;
				PDPhaseAdvSelect_Cnt_M_s16 = D_ZERO_CNT_S16;
				PDActivateTest_Cnt_M_lgc = TRUE;
			}
		}
		
	}
	
	
	/** Phase Disconnect Status for Testing **/
	
	(void)Rte_Call_NHETSigCtrl_GetPhaseDisconnectSignal(&PDControlStat_Cnt_T_u08);
	
	
	 /* "PhsDiscTestComplete_Cnt_T_lgc" implementation has equal to FDD 47 but does not follow the same flow chart sequence */
	 
	if( (PhaseDiscInitDiagState_Cnt_M_enum == PHSDISCINIT_COMPLETE) &&
		(PhaseDisconStat_Cnt_M_enum == PHSDISC_CLOSED) )
	{
		PhsDiscTestComplete_Cnt_T_lgc = TRUE;
	}
	else
	{
		PhsDiscTestComplete_Cnt_T_lgc = FALSE;
	}
	
	
	
	
	if( CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE )
	{
		
		/*** Open Operations at Disable ***/
		
		PDActivateTest_Cnt_M_lgc = FALSE;
		
		if( PhaseDisconStat_Cnt_M_enum != PHSDISC_OPEN )
		{
			if( PhaseDisconStat_Cnt_M_enum == PHSDISC_OPENINPROGRESS )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PDOpenTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				if( ElapsedTime_mS_T_u16 > k_PhDiscOpenTime_mS_u16 )
				{
					PhaseDisconStat_Cnt_M_enum = PHSDISC_OPEN;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PDOpenTimer_mS_M_u32);
				(void)Rte_Call_NHETSigCtrl_SetPhaseDisconnectSignal(FALSE);
				PhaseDisconStat_Cnt_M_enum = PHSDISC_OPENINPROGRESS;
			}
		}
		
		
		
		/*** Phase Disconnect Failed Closed (At Disable) ***/
		
		if( (PhaseDisconStat_Cnt_M_enum == PHSDISC_OPEN) &&
			(PDChrgPmpFdbkADC_Volt_T_f32 > k_ChrgPmpHiDetect_Volt_f32) )
		{
			ChrgPmpHiFltAcc_Cnt_M_u16 = DiagPStep_m(ChrgPmpHiFltAcc_Cnt_M_u16, k_ChrgPmpHi_Cnt_str);
			
			if( DiagFailed_m(ChrgPmpHiFltAcc_Cnt_M_u16, k_ChrgPmpHi_Cnt_str) == TRUE )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseDscntFailedDisable, 0x01U, NTC_STATUS_FAILED);
			}
		}
		else
		{
			ChrgPmpHiFltAcc_Cnt_M_u16 = DiagNStep_m(ChrgPmpHiFltAcc_Cnt_M_u16, k_ChrgPmpHi_Cnt_str);
			
			if( ChrgPmpHiFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseDscntFailedDisable, 0x01U, NTC_STATUS_PASSED);
			}
		}
	}
	
	
	
	
	if( (CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_WARMINIT) ||
		(CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE) )
	{
		
		/*** Charge Pump Under-Voltage Diagnostic ***/
		
		if( (PhaseDisconStat_Cnt_M_enum == PHSDISC_CLOSED) &&
			(PDChrgPmpFdbkADC_Volt_T_f32 < k_ChrgPmpLowDetect_Volt_f32) )
		{
			ChrgPmpLowFltAcc_Cnt_M_u16 = DiagPStep_m(ChrgPmpLowFltAcc_Cnt_M_u16, k_ChrgPmpLow_Cnt_str);
			
			if( DiagFailed_m(ChrgPmpLowFltAcc_Cnt_M_u16, k_ChrgPmpLow_Cnt_str) == TRUE )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_ChargePumpUnderVoltage, 0x01U, NTC_STATUS_FAILED);
			}
		}
		else
		{
			ChrgPmpLowFltAcc_Cnt_M_u16 = DiagNStep_m(ChrgPmpLowFltAcc_Cnt_M_u16, k_ChrgPmpLow_Cnt_str);
			
			if( ChrgPmpLowFltAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_ChargePumpUnderVoltage, 0x01U, NTC_STATUS_PASSED);
			}
		}
		
		
		
		/*** PD Supply Regulator Over-Voltage ***/
		
		if( (PDSupplyHiLatched_Cnt_M_lgc == FALSE) && 
			(PDSuplFdbkADC_Volt_T_f32 > k_PDSuplHighDetect_Volt_f32) )
		{
			PDSuplHighFltAcc_Cnt_M_u16 = DiagPStep_m(PDSuplHighFltAcc_Cnt_M_u16, k_PDSuplHigh_Cnt_str);
			
			if( DiagFailed_m(PDSuplHighFltAcc_Cnt_M_u16, k_PDSuplHigh_Cnt_str) == TRUE )
			{
				PDSupplyHiLatched_Cnt_M_lgc = TRUE;
				
				if( SavedPDSuplHiCnt_Cnt_M_u08 < 255u )
				{
					SavedPDSuplHiCnt_Cnt_M_u08++;
				}
				else
				{
					SavedPrevPDSuplCnt_Cnt_M_u08 = 254u;
				}
			}
		}
		else
		{
			PDSuplHighFltAcc_Cnt_M_u16 = DiagNStep_m(PDSuplHighFltAcc_Cnt_M_u16, k_PDSuplHigh_Cnt_str);
		}
		
		if( CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_WARMINIT )
		{
			/** Supply Regulator Count Checking & Clearing **/
			
			if( PDSupplyHiComplete_Cnt_M_lgc == FALSE )
			{
				if( PrevSystemStatePer2_Cnt_M_enum != RTE_MODE_StaMd_Mode_WARMINIT )
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InitialTime_mS_M_u32);
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(InitialTime_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( ElapsedTime_mS_T_u16 > k_PDSuplHiInit_mS_u16 )
					{
						PDSupplyHiComplete_Cnt_M_lgc = TRUE;
						
						if( SavedPDSuplHiCnt_Cnt_M_u08 <= SavedPrevPDSuplCnt_Cnt_M_u08 )
						{
							SavedPDSuplHiCnt_Cnt_M_u08 = D_ZERO_CNT_U8;
						}
						
						SavedPrevPDSuplCnt_Cnt_M_u08 = SavedPDSuplHiCnt_Cnt_M_u08;
						
						if( SavedPDSuplHiCnt_Cnt_M_u08 >= k_PDSuplHiCntsToFlt_Cnt_u08 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PDSupplyOverVoltage, 0x01U, NTC_STATUS_FAILED);
						}
						else
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PDSupplyOverVoltage, 0x01U, NTC_STATUS_PASSED);
						}
					}
				}
			}
		}
		
	}
	
	
	
	PrevSystemStatePer2_Cnt_M_enum = CurrentSysState_Cnt_T_enum;
	PDControlStat_Cnt_D_u08 = PDControlStat_Cnt_T_u08;
	Rte_IWrite_PhaseDscnt_Per2_PhsDiscTestComplete_Cnt_lgc(PhsDiscTestComplete_Cnt_T_lgc);
	Rte_IWrite_PhaseDscnt_Per2_PDActivateTest_Cnt_lgc(PDActivateTest_Cnt_M_lgc);
	Rte_IWrite_PhaseDscnt_Per2_PDPhaseAdvSelect_Cnt_s16(PDPhaseAdvSelect_Cnt_M_s16);
	Rte_IWrite_PhaseDscnt_Per2_PDTestModIndex_Uls_f32(PDTestModIndex_Uls_M_f32);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_PhaseDscnt_Per2_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_PHASEDSCNT_APPL_CODE
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
