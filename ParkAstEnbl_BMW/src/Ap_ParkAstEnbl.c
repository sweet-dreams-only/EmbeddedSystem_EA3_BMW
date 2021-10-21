/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ParkAstEnbl.c
 *     Workspace:  C:/SynergyWorkArea/CBD_ParkAsstEnblBMW/ParkAstEnbl_BMW/autosar
 *     SW-C Type:  Ap_ParkAstEnbl
 *  Generated at:  Mon Apr  1 11:46:50 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ParkAstEnbl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 18 18:34:17 2011
 * %version:          27 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Mon Apr  1 13:15:53 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/26/11   5       JJW       Updated template to match MDD
 * 06/02/11   6       JJW       Added NTC C/S Port access and removed HwVel Flt IRV
 * 06/02/11   7       YY        Implemented park-assist enabling state machine                               CR3611
 * 06/16/11   8       YY        Corrected pinion rate condtion.  
 * 12/02/11   9       BG        Updated NTC's to global constants.
 * 12/23/11   14      BG        Implemented changes for Rev003a.
 * 02/13/12   15      BG        updated for reflecting changes for Rev002a.
 * 02/20/12   16      OT        Fixed Integration Issues (calibration naming conflict)
 * 03/19/12   17      VK        Updates to meet FDD#40A v003												 CR5087
 * 03/21/12   18      VK        Anomaly 3047 fix															 CR5112
 * 03/27/12   19      VK        Updates to meet FDD#40A v004												 CR5147
 * 04/01/12   20      SMW       Anomaly 3108 Fix:  Reset PinionRateFaultTimer when entering Active           CR5169
 * 04/13/12   21      SMW       Anomaly 3137
 * 06/19/12   23      BDO       Anomaly 3431 - Update state transition vector 20 per rev 007 of FDD40A       CR5709
 * 10/06/12   24     Selva      Checkpoints added and mempmap macros corrected		                          6468
 * 02/19/13   25     Selva       Updated to FDDv10
 * 03/15/13   26     Srikanth    Changed PosServoHwAngle to module variable to retain previous value.        CR7608
 * 04/01/13   27     NRAR        Anom 4737- HHwVelFlt should be set only if in Active STate                  CR7763
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
  QU_SER_WSTA_EST_FTAX
    Service-Qualifier zur Lenkradvibration


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_ParkAstEnbl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_ParkAstEnbl_Cfg.h"

/* == INCLUDES ================================================= */

#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "CalConstants.h"

/* == EMBEDDED CONSTANTS ======================================= */

/* == DATA TYPES =============================================== */

typedef void (*PrkAstHandler_T)(boolean*pActive_T_lgc);
typedef enum  
{
  PRKAST_STATE_INITIALIZED = 0u,
  PRKAST_STATE_AVAILABLE = 1u, 
  PRKAST_STATE_ACTIVE = 2u, 
  PRKAST_STATE_ERROR = 3u, 
  PRKAST_STATE_FALLBACK_HANDSON = 4u, 
  PRKAST_STATE_FALLBACK_EPSSTATUS = 5u, 
  PRKAST_STATE_FALLBACK_VEHSPDHI = 6u, 
  PRKAST_STATE_STANDBY = 7u, 
  PRKAST_STATE_INVALID = 8u
}ParkAssistState_T;

/* == MODULE LEVEL VARIABLES =============================================== */
#define PARKASTENBL_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint32, AUTOMATIC) FiltHwTrqSV_HwNm_M_s7p24;
STATIC VAR(uint32, AUTOMATIC) HwVelFltStart_mS_M_u32;
STATIC VAR(uint32, AUTOMATIC) PinionRateFltStart_mS_M_u32;
STATIC VAR(uint32, AUTOMATIC) TimeoutHandsOn2Time_mS_M_u32;
STATIC VAR(float32, AUTOMATIC) PrevHwPos_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) PosServoHwAngle_HwDeg_M_f32;
#define PARKASTENBL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define PARKASTENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(ParkAssistState_T, AUTOMATIC) PrkAstState_Cnt_M_enum;
STATIC VAR(ParkAssistState_T, AUTOMATIC) PrevParkAstState_M_enum;
#define PARKASTENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define PARKASTENBL_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) PinionRateFlt_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) PrkAstActive_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) HandsOnThrsh1_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) HandsOnThrsh2_Cnt_M_lgc;
#define PARKASTENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/* == PROTOTYPES =============================================== */

STATIC FUNC(void, AP_PARKASTENBL_CODE) DetectedHandsOn(P2VAR(boolean, AUTOMATIC, AUTOMATIC)HandsOnThrsh1_Cnt_T_lgc, 
															P2VAR(boolean, AUTOMATIC, AUTOMATIC)HandsOnThrsh2_Cnt_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) DetectedHwVelFlt(void);
STATIC FUNC(boolean, AP_PARKASTENBL_CODE) DetectedPinionRateFlt(void);

STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Default(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Initialized(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Available(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Active(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_HandsOn(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_EpsStatus(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_VehSpdHi(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Standby(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc);

/* == CONSTANTS ================================================ */

STATIC CONST(QU_SER_WSTA_EST_FTAX, AP_PARKASTENBL_CODE) t_PrkAstStateCode_Cnt_enum[] = 
{
	Cx80_Schnittstelle_wird_initialisiert,
	Cx20_Schnittstelle_verfuegbar___funktionsbereit,
	Cx21_Schnittstelle_aktiv,
	Cx60_Service_nicht_verfuegbar___Fehler,
	CxE2_Funktion_in_Rueckfallebene___Hands_On,
	CxE3_Funktion_in_Rueckfallebene___EPS_Status,
	CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen,
	CxE7_Schnittstelle_aktiv_degradiert,
	CxFF_Signal_ungueltig
};

STATIC CONST(PrkAstHandler_T, AP_PARKASTENBL_CODE) t_PrkAstStateHandler_Cnt_Fn[] = 
{
	&PrkAst_HdlSt_Initialized,	/* PRKAST_STATE_INITIALIZED */
	&PrkAst_HdlSt_Available,		/* PRKAST_STATE_AVAILABLE */
	&PrkAst_HdlSt_Active,		/* PRKAST_STATE_ACTIVE */
	&PrkAst_HdlSt_Default,		/* PRKAST_STATE_ERROR */
	&PrkAst_HdlSt_HandsOn,		/* PRKAST_STATE_FALLBACK_HANDSON */
	&PrkAst_HdlSt_EpsStatus,		/* PRKAST_STATE_FALLBACK_EPSSTATUS */
	&PrkAst_HdlSt_VehSpdHi,		/* PRKAST_STATE_FALLBACK_VEHSPDHI */
	&PrkAst_HdlSt_Standby,		/* PRKAST_STATE_STANDBY */
	&PrkAst_HdlSt_Default		/* PRKAST_STATE_INVALID */
};

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
 * DVCO_VEH: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Fahrzeug_steht (0u)
 *   Cx1_Fahrzeug_faehrt_vorwaerts (1u)
 *   Cx2_Fahrzeug_faehrt_rueckwaerts (2u)
 *   Cx3_Fahrzeug_faehrt (3u)
 *   Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt (4u)
 *   Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt (5u)
 *   Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt (6u)
 *   Cx7_Signal_ungueltig (7u)
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
 * QU_SER_WSTA_EST_FTAX: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
 *   Cx21_Schnittstelle_aktiv (33u)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96u)
 *   Cx80_Schnittstelle_wird_initialisiert (128u)
 *   CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224u)
 *   CxE2_Funktion_in_Rueckfallebene___Hands_On (226u)
 *   CxE3_Funktion_in_Rueckfallebene___EPS_Status (227u)
 *   CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228u)
 *   CxE7_Schnittstelle_aktiv_degradiert (231u)
 *   CxFF_Signal_ungueltig (255u)
 * ST_V_VEH_NSS: Enumeration of integer in interval [0...15] with enumerators
 *   CxC_Fahrzeug_im_stillstandsnahen_Bereich (12u)
 *   CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich (13u)
 *   CxF_Signal_ungueltig (15u)
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


#define RTE_START_SEC_AP_PARKASTENBL_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParkAstEnbl_Per1
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
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32(void)
 *   ST_V_VEH_NSS Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08(void)
 *   DVCO_VEH Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PendEnable_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(void)
 *   void Rte_IWrite_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(QU_SER_WSTA_EST_FTAX data)
 *   QU_SER_WSTA_EST_FTAX *Rte_IWriteRef_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARKASTENBL_APPL_CODE) ParkAstEnbl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkAstEnbl_Per1
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC)	Active_Cnt_T_lgc;
	VAR(QU_SER_WSTA_EST_FTAX, AUTOMATIC) State_Cnt_T_u08;
	VAR(boolean, AUTOMATIC)	HandsOnThrsh1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	HandsOnThrsh2_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	PinionRateFlt_Cnt_T_lgc;
	VAR(ParkAssistState_T, AUTOMATIC) PrkAstState_Cnt_T_enum; 
	VAR(float32, AUTOMATIC)	OscTrajHwAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC)	PosTrajHwAngle_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC)	OscTrajEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	PosTrajEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	PosServoEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	HwAngRqst_HwDeg_T_f32;
	
	/* capture module level inputs */
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ParkAstEnbl_Per1_CP0_CheckpointReached();
	Active_Cnt_T_lgc = PrkAstActive_Cnt_M_lgc;
	PrkAstState_Cnt_T_enum = PrkAstState_Cnt_M_enum;
	OscTrajHwAngle_HwDeg_T_f32 = Rte_IRead_ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32();
	PosTrajHwAngle_HwDeg_T_f32 = Rte_IRead_ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32();
	OscTrajEnable_Cnt_T_lgc = Rte_IRead_ParkAstEnbl_Per1_PendEnable_Cnt_lgc();
	PosTrajEnable_Cnt_T_lgc = Rte_IRead_ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc();
	HwAngRqst_HwDeg_T_f32 = Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32();
	
	/* update module signals: handson, handwheel velocity fault, and pinion-rate fault */
	DetectedHandsOn(&HandsOnThrsh1_Cnt_T_lgc, &HandsOnThrsh2_Cnt_T_lgc);
	HandsOnThrsh1_Cnt_M_lgc = HandsOnThrsh1_Cnt_T_lgc;
	HandsOnThrsh2_Cnt_M_lgc = HandsOnThrsh2_Cnt_T_lgc;
	DetectedHwVelFlt();
	PinionRateFlt_Cnt_T_lgc = DetectedPinionRateFlt();
	PinionRateFlt_Cnt_M_lgc = PinionRateFlt_Cnt_T_lgc;
	
	
	/* determine the next state and active flag */
	if((uint8)PrkAstState_Cnt_T_enum < (uint8)TableSize_m(t_PrkAstStateHandler_Cnt_Fn))
	{
		t_PrkAstStateHandler_Cnt_Fn[PrkAstState_Cnt_T_enum](&Active_Cnt_T_lgc);
	}
	else /* corrupted state should be handled gracefully */
	{
		/* Misra-C rule 14.1 Violation: Condition added to check for corrupted state*/
		PrkAstState_Cnt_M_enum = PRKAST_STATE_INVALID;
		Active_Cnt_T_lgc = FALSE;
	}
	
	PrkAstState_Cnt_T_enum = PrkAstState_Cnt_M_enum;
	State_Cnt_T_u08 = t_PrkAstStateCode_Cnt_enum[PrkAstState_Cnt_T_enum];
	
	/* Output required Handwheel Position */
	if (TRUE == Active_Cnt_T_lgc)
	{
		PosServoEnable_Cnt_T_lgc = TRUE;
		PosServoHwAngle_HwDeg_M_f32 = HwAngRqst_HwDeg_T_f32;
	}
	else if (TRUE == PosTrajEnable_Cnt_T_lgc)
	{
		PosServoEnable_Cnt_T_lgc = TRUE;
		PosServoHwAngle_HwDeg_M_f32 = PosTrajHwAngle_HwDeg_T_f32;
	}
	else if (TRUE == OscTrajEnable_Cnt_T_lgc)
	{
		PosServoEnable_Cnt_T_lgc = TRUE;
		PosServoHwAngle_HwDeg_M_f32 = OscTrajHwAngle_HwDeg_T_f32;
	}
	else
	{
		PosServoEnable_Cnt_T_lgc = FALSE;
	}

	/* update outputs */
	PrkAstActive_Cnt_M_lgc = Active_Cnt_T_lgc;
	Rte_IWrite_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(PosServoHwAngle_HwDeg_M_f32);
	Rte_IWrite_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(PosServoEnable_Cnt_T_lgc);
	Rte_IWrite_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(State_Cnt_T_u08);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_ParkAstEnbl_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PARKASTENBL_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_PARKASTENBL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/* == LOCAL FUNCTIONS ========================================== */

STATIC FUNC(void, AP_PARKASTENBL_CODE) DetectedHandsOn( P2VAR(boolean, AUTOMATIC, AUTOMATIC)HandsOnThrsh1_Cnt_T_lgc,
															P2VAR(boolean, AUTOMATIC, AUTOMATIC)HandsOnThrsh2_Cnt_T_lgc)
{
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(s7p8_T, AUTOMATIC) HwTrq_HwNm_T_s7p8;
	VAR(s7p24_T, AUTOMATIC) FiltHwTrqSV_HwNm_T_s7p24;
	VAR(s7p8_T, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8;
	VAR(uint32, AUTOMATIC) HandsOn2ElapsedTime_mS_T_u32;
	
	/* capture inputs */
	HwTrq_HwNm_T_f32 = Rte_IRead_ParkAstEnbl_Per1_HwTorque_HwNm_f32();
	FiltHwTrqSV_HwNm_T_s7p24 = FiltHwTrqSV_HwNm_M_s7p24;
	
	/* filter handwheel torque */
	HwTrq_HwNm_T_s7p8 = FPM_FloatToFixed_m(HwTrq_HwNm_T_f32, s7p8_T);
	FiltHwTrqSV_HwNm_T_s7p24 = LPF_SvUpdate_s16InFixKTrunc_m(
									HwTrq_HwNm_T_s7p8, 
									FiltHwTrqSV_HwNm_T_s7p24,
									k_HandsOnLPFCutoff_Cnt_u16);
	FiltHwTrqSV_HwNm_M_s7p24 = FiltHwTrqSV_HwNm_T_s7p24;
	
	FiltHwTrq_HwNm_T_s7p8 = LPF_OpUpdate_s16InFixKTrunc_m(FiltHwTrqSV_HwNm_T_s7p24);
	
	/* determine and return result */
	if(Abs_s16_m(FiltHwTrq_HwNm_T_s7p8) > k_PrkAstHandsOnTrq1_HwNm_u8p8)
	{
		*HandsOnThrsh1_Cnt_T_lgc = TRUE;
	}
	else
	{
		*HandsOnThrsh1_Cnt_T_lgc = FALSE;
	}
	
	if(Abs_s16_m(HwTrq_HwNm_T_s7p8) >= k_PrkAstHandsOnTrq2_HwNm_u8p8)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutHandsOn2Time_mS_M_u32, &HandsOn2ElapsedTime_mS_T_u32);
		if (HandsOn2ElapsedTime_mS_T_u32 >= k_PrkAstHandsOn2Time_mS_u32)
		{
			*HandsOnThrsh2_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		*HandsOnThrsh2_Cnt_T_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutHandsOn2Time_mS_M_u32));
	}
}

/* ------------------------------------------------------------- */

STATIC FUNC(void, AP_PARKASTENBL_CODE) DetectedHwVelFlt( void )
{
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;
	VAR(float32, AUTOMATIC) HwVel_HwRadpS_T_f32;
	
	/* capture inputs */
	HwVel_HwRadpS_T_f32 = Rte_IRead_ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32();
	
	/* determine whether fault was detected */
	if((Abs_f32_m(HwVel_HwRadpS_T_f32) > k_PrkAstHwVelFltThrsh_HwRadpS_f32) && (PrkAstState_Cnt_M_enum == PRKAST_STATE_ACTIVE))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(HwVelFltStart_mS_M_u32, &ElapsedTime_Cnt_T_u32);
		if(ElapsedTime_Cnt_T_u32 > k_PrkAstHwVelFltTime_mS_u32)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_01, 0x00U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwVelFltStart_mS_M_u32);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_01, 0x00U, NTC_STATUS_PASSED);
	}
}

/* ------------------------------------------------------------- */

STATIC FUNC(boolean, AP_PARKASTENBL_CODE) DetectedPinionRateFlt( void )
{
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;
	VAR(float32, AUTOMATIC) HwPos_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) FltPsnt_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PinionChange_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) PrevHwPos_HwDeg_T_f32;
	VAR(ParkAssistState_T, AUTOMATIC) NextParkAstState_T_enum;

	
	/* capture inputs */
	HwPos_HwDeg_T_f32 = Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32();
	FltPsnt_Cnt_T_lgc = PinionRateFlt_Cnt_M_lgc;
	PrevHwPos_HwDeg_T_f32 = PrevHwPos_HwDeg_M_f32;
	NextParkAstState_T_enum = PrkAstState_Cnt_M_enum;
	

	/* Upon entrance into the PRKAST_STATE_ACTIVE State reset the timer Per FDD 40A Section 5.2.2.2 Vector #7*/
	if((NextParkAstState_T_enum != PrevParkAstState_M_enum) && (NextParkAstState_T_enum == PRKAST_STATE_ACTIVE))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PinionRateFltStart_mS_M_u32);
		FltPsnt_Cnt_T_lgc = FALSE;
	}
	else
	{

		/* determine whether fault was detected */
		PinionChange_HwDeg_T_f32 = HwPos_HwDeg_T_f32 - PrevHwPos_HwDeg_T_f32;

		if(Abs_f32_m(PinionChange_HwDeg_T_f32) < k_PrkAstHwDeltaMax_HwDeg_f32)
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(PinionRateFltStart_mS_M_u32, &ElapsedTime_Cnt_T_u32);
			if(ElapsedTime_Cnt_T_u32 > k_PrkAstHwDeltaMaxTime_mS_u32)
			{
				FltPsnt_Cnt_T_lgc = TRUE;
			}
		}
		else
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PinionRateFltStart_mS_M_u32);
			FltPsnt_Cnt_T_lgc = FALSE;
		}
	}
	/* update value of previous position and return result */
	PrevHwPos_HwDeg_M_f32 = HwPos_HwDeg_T_f32;
	PrevParkAstState_M_enum = NextParkAstState_T_enum;
	
	return FltPsnt_Cnt_T_lgc;
}


/* == STATE HANDLERS =========================================== */

/*****************************************************************************
 * Handle State:	(generic)
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Default( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	/* do nothing */
	pActive_T_lgc = pActive_T_lgc;
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_INITIALIZED
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Initialized( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(float32, AUTOMATIC) HwPosAuth_Uls_T_f32;
	
	/* capture inputs */
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	HwPosAuth_Uls_T_f32 = Rte_IRead_ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32();
	
	/* determine which state transition to make if any */
	if( (RTE_MODE_StaMd_Mode_OPERATE == SystemState_Cnt_T_enum) &&
		(HwPosAuth_Uls_T_f32 >= k_TcHwPosAuth_Uls_f32) )
	{
		PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
	}
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_AVAILABLE
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Available( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC)	DiagStatusNRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	DiagStatusRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwVelFlt_Cnt_T_lgc;
	VAR(ST_V_VEH_NSS, AUTOMATIC) Vnss_Cnt_T_enum;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	
	/* capture inputs */
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	DiagStatusNRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc();
	DiagStatusRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc();
	Invalid_Cnt_T_lgc 			= Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc();
	Enable_Cnt_T_lgc			= Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	Vnss_Cnt_T_enum				= Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_01, &HwVelFlt_Cnt_T_lgc);
	
	/* determine which state transition to make if any */
	if((TRUE == DiagStatusNRError_Cnt_T_lgc))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_ERROR;
	}
	else if((TRUE == Invalid_Cnt_T_lgc) || ((RTE_MODE_StaMd_Mode_DISABLE == SystemState_Cnt_T_enum) && (TRUE == DiagStatusRError_Cnt_T_lgc)))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_EPSSTATUS;
	}
	else if ((CxC_Fahrzeug_im_stillstandsnahen_Bereich != Vnss_Cnt_T_enum) && (TRUE == Enable_Cnt_T_lgc))
	{
	   (*pActive_T_lgc) = FALSE;
       PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_VEHSPDHI;
	}
	else if((TRUE == Enable_Cnt_T_lgc) && (CxC_Fahrzeug_im_stillstandsnahen_Bereich == Vnss_Cnt_T_enum))
	{    if (FALSE == HandsOnThrsh1_Cnt_M_lgc)
			{
				(*pActive_T_lgc) = TRUE;
				PrkAstState_Cnt_M_enum = PRKAST_STATE_ACTIVE;
			}
			else
			{
			(*pActive_T_lgc) = FALSE;
			PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_HANDSON;
			}
	}
	else { }
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_ACTIVE
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Active( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC)	DiagStatusNRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	DiagStatusRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(DVCO_VEH, AUTOMATIC) Dvco_Cnt_T_enum;
	VAR(ST_V_VEH_NSS, AUTOMATIC) Vnss_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) HwVelFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PinionRateFlt_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

	VAR(float32, AUTOMATIC) HwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) TrgtPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) TrgtHwDiff_HwDeg_T_f32;
	
	/* capture inputs */
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	DiagStatusNRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc();
	DiagStatusRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc();
	Invalid_Cnt_T_lgc 			= Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc();
	Enable_Cnt_T_lgc			= Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	Dvco_Cnt_T_enum				= Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08();
	Vnss_Cnt_T_enum				= Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_01, &HwVelFlt_Cnt_T_lgc);
	PinionRateFlt_Cnt_T_lgc	    = PinionRateFlt_Cnt_M_lgc;
	
	
	HwPos_HwDeg_T_f32 			= Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32();
	TrgtPos_HwDeg_T_f32			= Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32();
	
	
	/* determine which state transition to make if any */
	TrgtHwDiff_HwDeg_T_f32 = TrgtPos_HwDeg_T_f32 - HwPos_HwDeg_T_f32;
	
	if((TRUE == DiagStatusNRError_Cnt_T_lgc) || (TRUE == HwVelFlt_Cnt_T_lgc))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_ERROR;
	}
	else if((TRUE == Invalid_Cnt_T_lgc) || ((RTE_MODE_StaMd_Mode_DISABLE == SystemState_Cnt_T_enum) && (TRUE == DiagStatusRError_Cnt_T_lgc)))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_EPSSTATUS;
	}
	else if(CxC_Fahrzeug_im_stillstandsnahen_Bereich != Vnss_Cnt_T_enum)
	{
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_VEHSPDHI;
		(*pActive_T_lgc) = FALSE;
	}
	else if(((Abs_f32_m(TrgtHwDiff_HwDeg_T_f32) > k_PrkAstTrgtDeltaMin_HwDeg_f32) 
	&& (TRUE == PinionRateFlt_Cnt_T_lgc) && (Cx0_Fahrzeug_steht == Dvco_Cnt_T_enum) && (TRUE == Enable_Cnt_T_lgc)))
	{	
         (*pActive_T_lgc) = FALSE;
		 PrkAstState_Cnt_M_enum = PRKAST_STATE_STANDBY;
    }
	else if(TRUE == HandsOnThrsh2_Cnt_M_lgc)
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_HANDSON;
	}
	else if(TRUE != Enable_Cnt_T_lgc)
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE;
	}
	else { }
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_STANDBY
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_Standby( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC)	DiagStatusNRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	DiagStatusRError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwVelFlt_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(DVCO_VEH, AUTOMATIC) Dvco_Cnt_T_enum;
	
	/* capture inputs */
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	DiagStatusNRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc();
	DiagStatusRError_Cnt_T_lgc	= Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc();
	Invalid_Cnt_T_lgc 			= Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc();
	Enable_Cnt_T_lgc			= Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	Dvco_Cnt_T_enum				= Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_01, &HwVelFlt_Cnt_T_lgc);
	
	/* determine which state transition to make if any */
	if((TRUE == DiagStatusNRError_Cnt_T_lgc))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_ERROR;
	}
	else if((TRUE == Invalid_Cnt_T_lgc) || ((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) && (TRUE == DiagStatusRError_Cnt_T_lgc)))
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_EPSSTATUS;
	}
	else if(TRUE == HandsOnThrsh2_Cnt_M_lgc)
	{
		(*pActive_T_lgc) = FALSE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_FALLBACK_HANDSON;
	}
	else if ((TRUE == Enable_Cnt_T_lgc) && (Cx0_Fahrzeug_steht != Dvco_Cnt_T_enum))
	{
		(*pActive_T_lgc) = TRUE;
		PrkAstState_Cnt_M_enum = PRKAST_STATE_ACTIVE;
	}
	else if((FALSE == Enable_Cnt_T_lgc))
	{
	(*pActive_T_lgc) = FALSE;
	PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE; 
	}
	else
	{
	/* Do nothing*/
	}
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_FALLBACK_HANDSON
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_HandsOn( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	
	/* capture inputs */
	Enable_Cnt_T_lgc = Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	
	/* determine which state transition to make if any */
	if(FALSE == Enable_Cnt_T_lgc)
	{
		PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
	}
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_FALLBACK_EPSSTATUS
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_EpsStatus( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	
	/* capture inputs */
	Invalid_Cnt_T_lgc 			= Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc();
	Enable_Cnt_T_lgc			= Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	/* determine which state transition to make if any */
	if( (FALSE == Enable_Cnt_T_lgc) && (FALSE == Invalid_Cnt_T_lgc) && (RTE_MODE_StaMd_Mode_DISABLE != SystemState_Cnt_T_enum))
	{
		PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
	}
}

/*****************************************************************************
 * Handle State:	PRKAST_STATE_FALLBACK_VEHSPDHI
 *****************************************************************************/
STATIC FUNC(void, AP_PARKASTENBL_CODE) PrkAst_HdlSt_VehSpdHi( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc )
{
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	
	/* capture inputs */
	Enable_Cnt_T_lgc = Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc();
	
	/* determine which state transition to make if any */
	if(FALSE == Enable_Cnt_T_lgc)
	{
		PrkAstState_Cnt_M_enum = PRKAST_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
	}
}

#define RTE_STOP_SEC_AP_PARKASTENBL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
