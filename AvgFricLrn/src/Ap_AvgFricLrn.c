/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_AvgFricLrn.c
 *     Workspace:  C:/SynergyWorkArea/Working/AvgFricLrn/autosar
 *     SW-C Type:  Ap_AvgFricLrn
 *  Generated at:  Thu Feb 25 13:40:33 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_AvgFricLrn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri May  4 15:00:00 2012
 * %version:          EA3#17 %
 * %derived_by:       czmgrw %
 * %date_modified:    Mon Dec  9 15:57:47 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                                SCR #
 * -------   -------  --------  --------------------------------------------------------------------------------  -----
 * 05/24/12  1        OT        Initial Version                                                                   5379
 * 06/08/12  2        OT        Fixed UTP Issues (cal FPM type)                                                   5379
 * 06/26/12  3        OT        Anomaly 3399 and init issue                                                       5748
 * 09/13/12  5        JWJ       Updated for SF-07 v002                                                            6189
 * 09/24/12  6        BWL       Added watchdog checkpoints                                                        6210
 * 10/02/12  7        JWJ       Anomaly 3872 - moved DefeatFricOffsetOutput from NvM to MI                        
 * 10/24/12  8        JWJ       Added GET SCom functions for EOLFric, OffsetOutputDefeat and Select               
 * 07/08/13  9        BWL       Set PrevOpMode in SetSelect per anom 4679                                         8776
 * 10/23/13  10       VK		Updated to SF-07 v003															  10181
 * 12/10/13  11       RM        Anomaly 4634                                                                      11048
 * 04/02/14  12       SB		Anomaly 6297 Limit Outputs														  11714
 * 05/09/14	13-14	  SB		Updated per Design Review														  11714
 * 05/15/15	 15	  	  SB		Updated to SF-07 v007 and fixed Anom 7524										  12372
 * 02/01/16  16       JK        Changed unit of LatAcc input from g to MpSecSq - Anomaly EA3#4980              EA3#5306
 * 02/25/16	 17		  JK        Updated to SF-07 v008														   EA3#6308
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_AvgFricLrn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "interpolation.h"
#include "Ap_AvgFricLrn_Cfg.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */ 
/* PRQA S 4395 EOF 
 * MISRA-C:2004 Rule 10.4: This deviation is required for library macros. The rule is suppressed for the entire file */
/* PRQA S 492 EOF 
 * MISRA-C:2004 Rule 17.4: Required violation based on how the array is passed. The rule is suppressed for the entire file */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 
/* PRQA S 3332 EOF 
 * MISRA-C:2004 Rule 19.11: This deviation is required for fault injection points. The rule is suppressed for the entire file */ 


#define D_10MS_SEC_F32                	0.01f
#define D_FRICOFFSETOUTLOLIM_HWNM_F32 	(-5.0f)
#define D_FRICOFFSETOUTHILIM_HWNM_F32 	5.0F
#define D_ESTFRICLOLIM_HWNM_F32 		0.0F
#define D_ESTFRICHILIM_HWNM_F32			20.0F
#define D_SATESTFRICLOLIM_HWNM_F32		0.0F
#define D_SATESTFRICHILIM_HWNM_F32		20.0F
#define D_LRNCNSTRTIME_MS_U32        	120U /* 12 * 10ms */
#define D_VEHSPDPTNUM_CNT_U16        	(TableSize_m(t2_VehSpd_Kph_f32))
#define D_VEHSPDPTNUMX2_CNT_U16        (D_VEHSPDPTNUM_CNT_U16*2U)
#define D_HWPTNUM_CNT_U16            	(TableSize_m(t_FrHystHwAPts_HwDeg_f32))
#define D_HWPTNUMSUB1_CNT_U16        	(D_HWPTNUM_CNT_U16 - D_ONE_CNT_U16)
#define D_BUFSIZE_CNT_U16            	12U
#define D_PHASESHIFTCNT_CNT_U16        	6U
#define D_TWO_CNT_U16                	2U
#define D_TEN_CNT_U16                	10U
#define D_QUARTER_CNT_f32            	0.25f
#define D_VEHSPDLOIDX_CNT_U16        	0U
#define D_VEHSPDHIIDX_CNT_U16        	1U
#define D_FRICOFFSETMAX_HWNM_F32     	5.0f
#define D_VEHLRNDFRICHILIM_HWNM_F32		127.0F

typedef enum {
    FRICLRN_CALIBRATION = 0U,
    FRICLRN_NORMAL = 1U,
    FRICLRN_CLEAR = 2U,
    FRICLRN_IDLE = 3U,
    FRICLRN_BASELINE = 4U
} FricLrnModeType;


#define AVGFRICLRN_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_RawAvgFric_HwNm_M_f32[D_VEHSPDPTNUM_CNT_U16];
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_FiltAvgFric_HwNm_M_f32[D_VEHSPDPTNUM_CNT_U16];
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_SatAvgFric_HwNm_M_f32[D_VEHSPDPTNUM_CNT_U16];
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_VehBaselineFric_HwNm_M_f32[D_VEHSPDPTNUM_CNT_U16];
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_HwAngBuf_HwDeg_M_f32[D_BUFSIZE_CNT_U16]; 			/* PRQA S 3218 */
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_HwVelBuf_HwDegpS_M_f32[D_BUFSIZE_CNT_U16]; 		/* PRQA S 3218 */
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_ColTrqBuf_HwNm_M_f32[D_PHASESHIFTCNT_CNT_U16]; 	/* PRQA S 3218 */
STATIC VAR(uint32,  AP_AVGFRICLRN_VAR) AvgFricLrn_LearnConstTimer_mS_M_u32;
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_EstFric_HwNm_M_f32;
STATIC VAR(float32, AP_AVGFRICLRN_VAR) AvgFricLrn_SatEstFric_HwNm_M_f32;
STATIC VAR(uint32, AP_AVGFRICLRN_VAR) AvgFricLrn_FrictionDiagThreshTimer_mS_M_u32; 					/* PRQA S 3218 */
#define AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_AVGFRICLRN_VAR) AvgFricLrn_RunOnce_Cnt_M_lgc;
STATIC VAR(boolean, AP_AVGFRICLRN_VAR) AvgFricLrn_DefeatFricOffsetOutput_Cnt_M_lgc;
#define AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_HwVelKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_LatAccKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_HwPosAuthorityKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_VehSpdKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_TemperatureKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_HwAngKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_ColTrqKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_FiltAvgKSV_M_str[D_VEHSPDPTNUM_CNT_U16];
STATIC VAR(LPF32KSV_Str, AP_AVGFRICLRN_VAR) AvgFricLrn_AvgFricChgKSV_M_str;
STATIC VAR(FricLrnModeType, AP_AVGFRICLRN_VAR) AvgFricLrn_PrevOpMode_Cnt_M_enum;
#define AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */



STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) LoadBuffer(    VAR(float32, AUTOMATIC) Input_Uls_T_f32,
                                                                    P2VAR(float32, AUTOMATIC, AUTOMATIC) Buffer_Uls_T_f32,
                                                                    VAR(uint16, AUTOMATIC) BufferSize_Cnt_T_u16);


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) HwAngConstraint(    VAR(float32, AUTOMATIC) HwAng_HwDeg_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwAngOK_Cnt_T_lgc,
                                                                        P2VAR(float32, AUTOMATIC, AUTOMATIC) SelHwAng_HwDeg_T_f32);

STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) HwVelConstraint(     VAR(float32, AUTOMATIC) HwVel_HwDegpS_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwVelOK_Cnt_T_lgc,
                                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) Direction_Cnt_T_u16);

STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) VehSpdConstraint(    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) VehSpdOK_Cnt_T_lgc,
                                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) VehSpdIndex_Cnt_T_u16);

STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) FricLearning( VAR(float32, AUTOMATIC) HwAng_HwDeg_T_f32,
                                                                    VAR(float32, AUTOMATIC) ColTrq_HwNm_T_f32,
                                                                    VAR(uint16,  AUTOMATIC) VehSpdIndex_Cnt_T_u16,
                                                                    VAR(uint16,  AUTOMATIC) Direction_Cnt_T_u16);


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) BaselineMode(void);

STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) ClearMode(void);


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
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 *   FLTINJ_MTRVEL (160u)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
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
 *   NTC_Num_PeripheralStartupFlt (55u)
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
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73u)
 *   NTC_Num_IvtrPwrDiscnctFailr (74u)
 *   NTC_Num_PowerRelayInit2Flt (75u)
 *   NTC_Num_GateDrvFltInProcess (76u)
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
 *   NTC_Num_Inv2GateDrvFltInProcess (92u)
 *   NTC_Num_Inv2GateDrvFlt (93u)
 *   NTC_Num_Inv2OnStateSingleFET (94u)
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
 *   NTC_Num_LoaRpdShutdn (170u)
 *   NTC_Num_LoaCtrldShutdn (171u)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172u)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173u)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174u)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175u)
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
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
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
 * AvgFricLrnRangeCounterSubType: Array with 3 element(s) of type UInt16
 * AvgFricLrnRangeCounterType: Array with 8 element(s) of type AvgFricLrnRangeCounterSubType
 * AvgFricLrnThetaSubType: Array with 4 element(s) of type Float
 * AvgFricLrnThetaType: Array with 8 element(s) of type AvgFricLrnThetaSubType
 * AvgFricLrnVehLearnedFricType: Array with 4 element(s) of type Float
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * AvgFricLrnType: Record with elements
 *   FricOffset_HwNm_f32 of type Float
 *   EOLFric_HwNm_f32 of type Float
 *   EnableFricOffsetOutput_Cnt_lgc of type Boolean
 *   EnableFricLearning_Cnt_lgc of type Boolean
 *   OpMode_Cnt_enum of type UInt8
 *   RangeCounter_Cnt_u16 of type AvgFricLrnRangeCounterType
 *   Theta_HwNm_f32 of type AvgFricLrnThetaType
 *   VehLearnedFric_HwNm_f32 of type AvgFricLrnVehLearnedFricType
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
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   AvgFricLrnType *Rte_Pim_AvgFricLrnData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Init1
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
 *   void Rte_IWrite_AvgFricLrn_Init1_FricOffset_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Init1_FricOffset_HwNm_f32(void)
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

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_Init1
 *********************************************************************************************************************/
    
    
    VAR(uint16,  AUTOMATIC) i;
    
    AvgFricLrn_PrevOpMode_Cnt_M_enum = (FricLrnModeType)Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum;
    
    for( i = 0U; i < D_VEHSPDPTNUM_CNT_U16; i++ )
    {
        AvgFricLrn_VehBaselineFric_HwNm_M_f32[i] = t_BaselineFric_HwNm_f32[i];
        AvgFricLrn_RawAvgFric_HwNm_M_f32[i] = Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i];
        AvgFricLrn_FiltAvgFric_HwNm_M_f32[i] = Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i];
        AvgFricLrn_SatAvgFric_HwNm_M_f32[i] = Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i];
        LPF_Init_f32_m(Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i],
                       k_AvgFricLPFKn_Hz_f32,
                       D_10MS_SEC_F32,
                       &AvgFricLrn_FiltAvgKSV_M_str[i]);
    }
    
    LPF_Init_f32_m(Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32, k_FricOffsetLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_AvgFricChgKSV_M_str);
    
    
    (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AvgFricLrn_LearnConstTimer_mS_M_u32);
    
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_HwVelKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_LatAccKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_HwPosAuthorityKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_VehSpdKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_TemperatureKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_HwAngKSV_M_str);
    LPF_KUpdate_f32_m(k_DataPrepLPFKn_Hz_f32, D_10MS_SEC_F32, &AvgFricLrn_ColTrqKSV_M_str);
    
    
    Rte_IWrite_AvgFricLrn_Init1_FricOffset_HwNm_f32(Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32);
    
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF, WARMINIT, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AvgFricLrn_Per1_CRFMtrTrq_MtrNm_f32(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_DefeatFricLearning_Cnt_lgc(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_FricLrnCustEna_Cnt_lgc(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwAng_HwDeg_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwPosAuthority_Uls_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwVel_HwRadpS_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_LatAcc_MpSecSq_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_Temperature_DegC_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_VehSpd_Kph_f32(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AvgFricLrn_Per1_EstFric_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_EstFric_HwNm_f32(void)
 *   void Rte_IWrite_AvgFricLrn_Per1_FricOffset_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_FricOffset_HwNm_f32(void)
 *   void Rte_IWrite_AvgFricLrn_Per1_SatEstFric_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_SatEstFric_HwNm_f32(void)
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
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_Per1
 *********************************************************************************************************************/
    
    
    VAR(float32, AUTOMATIC) HwAngUnfilt_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwPosAuthorityUnfilt_Uls_T_f32;
    VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) HwVelUnfilt_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) LatAccUnfilt_MpSecSq_T_f32;
    VAR(float32, AUTOMATIC) MtrTrq_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) TemperatureUnfilt_DegC_T_f32;
    VAR(float32, AUTOMATIC) VehSpdUnfilt_Kph_T_f32;
    VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DefeatFricLearning_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) FricLrnCustEna_Cnt_T_lgc;
    
    VAR(float32, AUTOMATIC) HwVelUnfilt_HwDegpS_T_f32;
    VAR(FricLrnModeType, AP_AVGFRICLRN_VAR) OpMode_Cnt_T_enum;
    VAR(float32, AUTOMATIC) FricOffsetOut_HwNm_T_f32;
    
    /* PrepData */
    VAR(float32, AUTOMATIC) HwVel_HwDegpS_T_f32;
    VAR(float32, AUTOMATIC) LatAcc_MpSecSqrd_T_f32;
    VAR(float32, AUTOMATIC) HwPosAuthority_Uls_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(float32, AUTOMATIC) Temperature_DegC_T_f32;
    VAR(float32, AUTOMATIC) HwAng_HwDeg_T_f32;
    VAR(uint16,  AUTOMATIC) AbsHwAngUnfilt_HwDeg_T_u11p5;
    VAR(uint16,  AUTOMATIC) Ratio_HwNmpMtrNm_T_u6p10;
    VAR(float32, AUTOMATIC) Ratio_HwNmpMtrNm_T_f32;
    VAR(float32, AUTOMATIC) ColTrqUnfilt_HwNm_T_f32;
    VAR(float32, AUTOMATIC) ColTrq_HwNm_T_f32;
    
    /* LearningConstraint */
    VAR(boolean, AUTOMATIC) HwAngOK_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) SelHwAng_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) HwVelOK_Cnt_T_lgc;
    VAR(uint16,  AUTOMATIC) Direction_Cnt_T_u16;
    VAR(boolean, AUTOMATIC) VehSpdOK_Cnt_T_lgc;
    VAR(uint16,  AUTOMATIC) VehSpdIndex_Cnt_T_u16;
    VAR(float32, AUTOMATIC) SelColTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) AbsLatAcc_MpSecSqrd_T_f32;
    VAR(uint32,  AUTOMATIC) ElapsedTime_mS_T_u32;
    VAR(boolean, AUTOMATIC) LearningEnable_Cnt_T_lgc;
    
    VAR(float32, AUTOMATIC) AvgFricChg_HwNm_T_f32;
    
    VAR(uint16, AUTOMATIC) i;
    
    /* Configurable Start of Runnable Checkpoint */
    Rte_Call_AvgFricLrn_Per1_CP0_CheckpointReached();
    
    HwAngUnfilt_HwDeg_T_f32          = Rte_IRead_AvgFricLrn_Per1_HwAng_HwDeg_f32();
    HwPosAuthorityUnfilt_Uls_T_f32   = Rte_IRead_AvgFricLrn_Per1_HwPosAuthority_Uls_f32();
    HwTrq_HwNm_T_f32                 = Rte_IRead_AvgFricLrn_Per1_HwTrq_HwNm_f32();
    HwVelUnfilt_HwRadpS_T_f32        = Rte_IRead_AvgFricLrn_Per1_HwVel_HwRadpS_f32();
    LatAccUnfilt_MpSecSq_T_f32       = Rte_IRead_AvgFricLrn_Per1_LatAcc_MpSecSq_f32();
    MtrTrq_MtrNm_T_f32               = Rte_IRead_AvgFricLrn_Per1_CRFMtrTrq_MtrNm_f32();
    TemperatureUnfilt_DegC_T_f32     = Rte_IRead_AvgFricLrn_Per1_Temperature_DegC_f32();
    VehSpdUnfilt_Kph_T_f32           = Rte_IRead_AvgFricLrn_Per1_VehSpd_Kph_f32();
    VehicleSpeedValid_Cnt_T_lgc      = Rte_IRead_AvgFricLrn_Per1_VehicleSpeedValid_Cnt_lgc();
    DefeatFricLearning_Cnt_T_lgc     = Rte_IRead_AvgFricLrn_Per1_DefeatFricLearning_Cnt_lgc();
    FricLrnCustEna_Cnt_T_lgc		 = Rte_IRead_AvgFricLrn_Per1_FricLrnCustEna_Cnt_lgc();
    
    HwVelUnfilt_HwDegpS_T_f32 = HwVelUnfilt_HwRadpS_T_f32 * D_180OVRPI_ULS_F32;
    OpMode_Cnt_T_enum = (FricLrnModeType)Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum;
    
    AvgFricLrn_RunOnce_Cnt_M_lgc = D_TRUE_CNT_LGC;
    
    if( (OpMode_Cnt_T_enum == FRICLRN_CALIBRATION) ||
        (OpMode_Cnt_T_enum == FRICLRN_NORMAL) )
    {
        /*** RunningAndCalibrationModes ***/
        
        /** PrepData **/
        
        HwVel_HwDegpS_T_f32 = LPF_OpUpdate_f32_m(HwVelUnfilt_HwDegpS_T_f32, &AvgFricLrn_HwVelKSV_M_str);
        LatAcc_MpSecSqrd_T_f32 = LPF_OpUpdate_f32_m(LatAccUnfilt_MpSecSq_T_f32, &AvgFricLrn_LatAccKSV_M_str);
        HwPosAuthority_Uls_T_f32 = LPF_OpUpdate_f32_m(HwPosAuthorityUnfilt_Uls_T_f32, &AvgFricLrn_HwPosAuthorityKSV_M_str);
        VehSpd_Kph_T_f32 = LPF_OpUpdate_f32_m(VehSpdUnfilt_Kph_T_f32, &AvgFricLrn_VehSpdKSV_M_str);
        Temperature_DegC_T_f32 = LPF_OpUpdate_f32_m(TemperatureUnfilt_DegC_T_f32, &AvgFricLrn_TemperatureKSV_M_str);
        HwAng_HwDeg_T_f32 = LPF_OpUpdate_f32_m(HwAngUnfilt_HwDeg_T_f32, &AvgFricLrn_HwAngKSV_M_str);
        
        AbsHwAngUnfilt_HwDeg_T_u11p5 = FPM_FloatToFixed_m(Abs_f32_m(HwAngUnfilt_HwDeg_T_f32), u11p5_T);
        
        Ratio_HwNmpMtrNm_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( t_InvRatioX_HwDeg_u11p5,
                                                                t_InvRatioY_HwNmpMtrNm_u6p10,
                                                                TableSize_m(t_InvRatioX_HwDeg_u11p5),
                                                                AbsHwAngUnfilt_HwDeg_T_u11p5);
        
        Ratio_HwNmpMtrNm_T_f32 = FPM_FixedToFloat_m(Ratio_HwNmpMtrNm_T_u6p10, u6p10_T);
        
        ColTrqUnfilt_HwNm_T_f32 = (MtrTrq_MtrNm_T_f32 * Ratio_HwNmpMtrNm_T_f32) + HwTrq_HwNm_T_f32;
        
        ColTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(ColTrqUnfilt_HwNm_T_f32, &AvgFricLrn_ColTrqKSV_M_str);
        
        
        
        /** LearningConstraint **/
        
        HwAngConstraint(HwAng_HwDeg_T_f32, &HwAngOK_Cnt_T_lgc, &SelHwAng_HwDeg_T_f32);
        
        HwVelConstraint(HwVel_HwDegpS_T_f32, &HwVelOK_Cnt_T_lgc, &Direction_Cnt_T_u16);
        
        VehSpdConstraint(VehSpd_Kph_T_f32, &VehSpdOK_Cnt_T_lgc, &VehSpdIndex_Cnt_T_u16);
        
        SelColTrq_HwNm_T_f32 = AvgFricLrn_ColTrqBuf_HwNm_M_f32[D_PHASESHIFTCNT_CNT_U16 - D_ONE_CNT_U16];
        LoadBuffer(ColTrq_HwNm_T_f32, AvgFricLrn_ColTrqBuf_HwNm_M_f32, D_PHASESHIFTCNT_CNT_U16);
        
        
        AbsLatAcc_MpSecSqrd_T_f32 = Abs_f32_m(LatAcc_MpSecSqrd_T_f32);
        
        if( (AbsLatAcc_MpSecSqrd_T_f32 > k_LatAccMax_MpSecSqrd_f32) ||
            (AbsLatAcc_MpSecSqrd_T_f32 < k_LatAccMin_MpSecSqrd_f32) ||
            (HwPosAuthority_Uls_T_f32 < k_HwPosAuthMin_Uls_f32) ||
            (Temperature_DegC_T_f32 > k_TempMax_DegC_f32) ||
            (Temperature_DegC_T_f32 < k_TempMin_DegC_f32) ||
            (VehicleSpeedValid_Cnt_T_lgc == FALSE) )
        {
            (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AvgFricLrn_LearnConstTimer_mS_M_u32);
        }
        
        (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(AvgFricLrn_LearnConstTimer_mS_M_u32, &ElapsedTime_mS_T_u32);
        
        if( (ElapsedTime_mS_T_u32 > D_LRNCNSTRTIME_MS_U32) &&
            (HwAngOK_Cnt_T_lgc == TRUE) &&
            (HwVelOK_Cnt_T_lgc == TRUE) &&
            (VehSpdOK_Cnt_T_lgc == TRUE) )
        {
            LearningEnable_Cnt_T_lgc = TRUE;
        }
        else
        {
            LearningEnable_Cnt_T_lgc = FALSE;
        }
        
        /* added in v4 - left separate from above because of separation in SFD */
        if( (DefeatFricLearning_Cnt_T_lgc != D_FALSE_CNT_LGC) ||
            (Rte_Pim_AvgFricLrnData()->EnableFricLearning_Cnt_lgc != D_TRUE_CNT_LGC) ||
            (FricLrnCustEna_Cnt_T_lgc != D_TRUE_CNT_LGC))
        {
            LearningEnable_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }
        
        
        /** FricLearning **/
        
        if( LearningEnable_Cnt_T_lgc == TRUE )
        {
            FricLearning(SelHwAng_HwDeg_T_f32, SelColTrq_HwNm_T_f32, VehSpdIndex_Cnt_T_u16, Direction_Cnt_T_u16);
        }
        
        
        
        if( OpMode_Cnt_T_enum == FRICLRN_CALIBRATION )
        {
            /** CalMode **/
            
            AvgFricLrn_AvgFricChgKSV_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
            
            for( i = D_ZERO_CNT_U16; i < D_VEHSPDPTNUM_CNT_U16; i++ )
            {
                AvgFricLrn_VehBaselineFric_HwNm_M_f32[i] = AvgFricLrn_SatAvgFric_HwNm_M_f32[i];
            }
            
            Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32 = D_ZERO_ULS_F32;
        }
        else if( LearningEnable_Cnt_T_lgc == TRUE )
        {
            /** RunningMode **/
            
            if( t_MskVehSpd_Cnt_lgc[VehSpdIndex_Cnt_T_u16] == TRUE )
            {
                AvgFricChg_HwNm_T_f32 = (AvgFricLrn_SatAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16] - AvgFricLrn_VehBaselineFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16]) * t_FricChgWeight_Uls_f32[VehSpdIndex_Cnt_T_u16];
                
                Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32 = LPF_OpUpdate_f32_m(AvgFricChg_HwNm_T_f32, &AvgFricLrn_AvgFricChgKSV_M_str);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else if( OpMode_Cnt_T_enum == FRICLRN_BASELINE )
    {
        /*** BaselineMode ***/
        
        BaselineMode();
    }
    else if( OpMode_Cnt_T_enum == FRICLRN_CLEAR )
    {
        /*** ClearMode ***/
        
        ClearMode();
    }
    else
    {
        /*** IdleMode (do nothing) ***/
    }
    
    
    /*** Fault Injection Point ***/
    #if (STD_ON == BC_AVGFRICLRN_FAULTINJECTIONPOINT)
    Rte_Call_FltInjection_SCom_FltInjection(&Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32, FLTINJ_AVGFRICLRN);
    #endif
    
    Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32 = Limit_m(Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32, k_FricOffsetLimitLow_HwNm_f32, k_FricOffsetLimitHigh_HwNm_f32);
    
    /* Defeat - Added in v4 - JWJ */
    if( (AvgFricLrn_DefeatFricOffsetOutput_Cnt_M_lgc != D_FALSE_CNT_LGC) ||
        (Rte_Pim_AvgFricLrnData()->EnableFricOffsetOutput_Cnt_lgc != D_TRUE_CNT_LGC) )
    {
        FricOffsetOut_HwNm_T_f32 = D_ZERO_ULS_F32;
    }
    else
    {
        FricOffsetOut_HwNm_T_f32 = Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32;
    }
	
	
    FricOffsetOut_HwNm_T_f32 = Limit_m(FricOffsetOut_HwNm_T_f32, D_FRICOFFSETOUTLOLIM_HWNM_F32, D_FRICOFFSETOUTHILIM_HWNM_F32);
			
    Rte_IWrite_AvgFricLrn_Per1_FricOffset_HwNm_f32(FricOffsetOut_HwNm_T_f32);
    Rte_IWrite_AvgFricLrn_Per1_EstFric_HwNm_f32(AvgFricLrn_EstFric_HwNm_M_f32);
    Rte_IWrite_AvgFricLrn_Per1_SatEstFric_HwNm_f32(AvgFricLrn_SatEstFric_HwNm_M_f32);
    
    /* SCom Service Complete Handling - added in v4 - JWJ */
    if( (AvgFricLrn_PrevOpMode_Cnt_M_enum != (FricLrnModeType)Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum) &&
        (AvgFricLrn_RunOnce_Cnt_M_lgc == D_TRUE_CNT_LGC) )
    {
        (void)Rte_Call_AvgFricLrnData_WriteBlock(NULL_PTR);
        Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum = (uint8)AvgFricLrn_PrevOpMode_Cnt_M_enum;
    }
 
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_AvgFricLrn_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEOLFric> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetEOLFric(Float *EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_GetEOLFric
 *********************************************************************************************************************/

    *EOLFric_HwNm_f32 = Rte_Pim_AvgFricLrnData()->EOLFric_HwNm_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetOffsetOutputDefeat(Boolean *DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_GetOffsetOutputDefeat
 *********************************************************************************************************************/

    *DefeatOffsetOutput_Cnt_lgc = AvgFricLrn_DefeatFricOffsetOutput_Cnt_M_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSelect> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetSelect(Boolean *EnableFricLearning_Cnt_lgc, Boolean *EnableOffsetOutput_Cnt_lgc, UInt8 *OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_GetSelect
 *********************************************************************************************************************/

    *EnableFricLearning_Cnt_lgc = Rte_Pim_AvgFricLrnData()->EnableFricLearning_Cnt_lgc;
    *EnableOffsetOutput_Cnt_lgc = Rte_Pim_AvgFricLrnData()->EnableFricOffsetOutput_Cnt_lgc;
    *OpMode_Uls_u08             = Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_InitLearnedTables
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitLearnedTables> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_InitLearnedTables(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_InitLearnedTables
 *********************************************************************************************************************/

    AvgFricLrn_PrevOpMode_Cnt_M_enum = (FricLrnModeType)Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum;
    Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum = (uint8)FRICLRN_BASELINE;
    AvgFricLrn_RunOnce_Cnt_M_lgc = D_FALSE_CNT_LGC;	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_ResetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToZero> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_ResetToZero(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_ResetToZero
 *********************************************************************************************************************/

    AvgFricLrn_PrevOpMode_Cnt_M_enum = (FricLrnModeType)Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum;
    Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum = (uint8)FRICLRN_CLEAR;
    AvgFricLrn_RunOnce_Cnt_M_lgc = D_FALSE_CNT_LGC;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLFric> of PortPrototype <AvgFricLrn_SCom>
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_SetEOLFric
 *********************************************************************************************************************/

    Rte_Pim_AvgFricLrnData()->EOLFric_HwNm_f32 = EOLFric_HwNm_f32;
    (void)Rte_Call_AvgFricLrnData_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_SetOffsetOutputDefeat
 *********************************************************************************************************************/

    AvgFricLrn_DefeatFricOffsetOutput_Cnt_M_lgc = DefeatOffsetOutput_Cnt_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSelect> of PortPrototype <AvgFricLrn_SCom>
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_SCom_SetSelect
 *********************************************************************************************************************/

    Rte_Pim_AvgFricLrnData()->EnableFricLearning_Cnt_lgc     = EnableFricLearning_Cnt_lgc;
    Rte_Pim_AvgFricLrnData()->EnableFricOffsetOutput_Cnt_lgc = EnableOffsetOutput_Cnt_lgc;
    Rte_Pim_AvgFricLrnData()->OpMode_Cnt_enum                = OpMode_Uls_u08;
    (void)Rte_Call_AvgFricLrnData_WriteBlock(NULL_PTR);
    AvgFricLrn_PrevOpMode_Cnt_M_enum = (FricLrnModeType)OpMode_Uls_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AvgFricLrn_Trns1
 *********************************************************************************************************************/
    
    
    VAR(uint16, AUTOMATIC) i;
    
    
    for( i = 0U; i < D_VEHSPDPTNUM_CNT_U16; i++ )
    {
        Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i] = Limit_m(AvgFricLrn_SatAvgFric_HwNm_M_f32[i],
																		Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i] - k_IgnCycleFricChgLim_HwNm_f32,
																		Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i] + k_IgnCycleFricChgLim_HwNm_f32);
		Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i] = Limit_m(Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i], D_ZERO_ULS_F32, D_VEHLRNDFRICHILIM_HWNM_F32);	
			
    }
    
    (void)Rte_Call_AvgFricLrnData_WriteBlock(NULL_PTR);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) LoadBuffer(    VAR(float32, AUTOMATIC) Input_Uls_T_f32,
                                                                    P2VAR(float32, AUTOMATIC, AUTOMATIC) Buffer_Uls_T_f32,
                                                                    VAR(uint16, AUTOMATIC) BufferSize_Cnt_T_u16)
{
    VAR(uint16, AUTOMATIC) i;
    
    
    for( i = BufferSize_Cnt_T_u16 - 1U; i >= 1U; i-- )
    {
        Buffer_Uls_T_f32[i] = Buffer_Uls_T_f32[i - 1U];
    }
    
    Buffer_Uls_T_f32[0] = Input_Uls_T_f32;
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) HwAngConstraint(    VAR(float32, AUTOMATIC) HwAng_HwDeg_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwAngOK_Cnt_T_lgc,
                                                                        P2VAR(float32, AUTOMATIC, AUTOMATIC) SelHwAng_HwDeg_T_f32)
{
    VAR(uint16, AUTOMATIC) i;
    VAR(boolean, AUTOMATIC) AllInRange_Cnt_T_lgc;
    
    
    AllInRange_Cnt_T_lgc = TRUE;
    
    for( i = 0U; (i < D_BUFSIZE_CNT_U16) && (AllInRange_Cnt_T_lgc == TRUE); i++ )
    {
        if( (AvgFricLrn_HwAngBuf_HwDeg_M_f32[i] > t_FrHystHwAPts_HwDeg_f32[D_HWPTNUMSUB1_CNT_U16]) ||
            (AvgFricLrn_HwAngBuf_HwDeg_M_f32[i] < t_FrHystHwAPts_HwDeg_f32[0]) )
        {
            AllInRange_Cnt_T_lgc = FALSE;
        }
    }
    
    *HwAngOK_Cnt_T_lgc = AllInRange_Cnt_T_lgc;
    
    *SelHwAng_HwDeg_T_f32 = AvgFricLrn_HwAngBuf_HwDeg_M_f32[D_PHASESHIFTCNT_CNT_U16 - 1U];
    
    LoadBuffer(HwAng_HwDeg_T_f32, AvgFricLrn_HwAngBuf_HwDeg_M_f32, D_BUFSIZE_CNT_U16);
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) HwVelConstraint(     VAR(float32, AUTOMATIC) HwVel_HwDegpS_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwVelOK_Cnt_T_lgc,
                                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) Direction_Cnt_T_u16)
{
    VAR(uint16,  AUTOMATIC) i;
    VAR(float32, AUTOMATIC) HwVelMin_HwDegpS_T_f32;
    VAR(float32, AUTOMATIC) HwVelMax_HwDegpS_T_f32;
    VAR(float32, AUTOMATIC) HwVelSum_HwDegpS_T_f32;
    VAR(float32, AUTOMATIC) AbsHwVelMean_HwDegpS_T_f32;
    VAR(boolean, AUTOMATIC) AllLTZ_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) AllGTZ_Cnt_T_lgc;
    
    
    HwVelMin_HwDegpS_T_f32 = AvgFricLrn_HwVelBuf_HwDegpS_M_f32[0];
    HwVelMax_HwDegpS_T_f32 = AvgFricLrn_HwVelBuf_HwDegpS_M_f32[0];
    HwVelSum_HwDegpS_T_f32 = D_ZERO_ULS_F32;
    AllLTZ_Cnt_T_lgc = TRUE;
    AllGTZ_Cnt_T_lgc = TRUE;
    
    for( i = 0U; i < D_BUFSIZE_CNT_U16; i++ )
    {
        HwVelMin_HwDegpS_T_f32 = Min_m(HwVelMin_HwDegpS_T_f32, AvgFricLrn_HwVelBuf_HwDegpS_M_f32[i]);
        HwVelMax_HwDegpS_T_f32 = Max_m(HwVelMax_HwDegpS_T_f32, AvgFricLrn_HwVelBuf_HwDegpS_M_f32[i]);
        HwVelSum_HwDegpS_T_f32 += AvgFricLrn_HwVelBuf_HwDegpS_M_f32[i];
        
        if( AvgFricLrn_HwVelBuf_HwDegpS_M_f32[i] > D_ZERO_ULS_F32 )
        {
            AllLTZ_Cnt_T_lgc = FALSE;
        }
        
        if( AvgFricLrn_HwVelBuf_HwDegpS_M_f32[i] < D_ZERO_ULS_F32 )
        {
            AllGTZ_Cnt_T_lgc = FALSE;
        }
    }
    
    AbsHwVelMean_HwDegpS_T_f32 = Abs_f32_m(HwVelSum_HwDegpS_T_f32 / (float32)D_BUFSIZE_CNT_U16);
    
    if( (AbsHwVelMean_HwDegpS_T_f32 >= k_HwVelMin_HwDegpS_f32) &&
        (AbsHwVelMean_HwDegpS_T_f32 <= k_HwVelMax_HwDegpS_f32) &&
        ((HwVelMax_HwDegpS_T_f32 - HwVelMin_HwDegpS_T_f32) <= k_HwVelConstLimit_HwDegpS_f32) &&
        ( (AllLTZ_Cnt_T_lgc == TRUE) ||
          (AllGTZ_Cnt_T_lgc == TRUE) ) )
    {
        *HwVelOK_Cnt_T_lgc = TRUE;
    }
    else
    {
        *HwVelOK_Cnt_T_lgc = FALSE;
    }
    
    if( AllGTZ_Cnt_T_lgc == TRUE )
    {
        *Direction_Cnt_T_u16 = D_ZERO_CNT_U16;
    }
    else if( AllLTZ_Cnt_T_lgc == TRUE )
    {
        *Direction_Cnt_T_u16 = D_ONE_CNT_U16;
    }
    else
    {
        *Direction_Cnt_T_u16 = D_ZERO_CNT_U16;
    }
    
    LoadBuffer(HwVel_HwDegpS_T_f32, AvgFricLrn_HwVelBuf_HwDegpS_M_f32, D_BUFSIZE_CNT_U16);
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) VehSpdConstraint(    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
                                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) VehSpdOK_Cnt_T_lgc,
                                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) VehSpdIndex_Cnt_T_u16)
{
    VAR(uint16,  AUTOMATIC) i;
    VAR(boolean, AUTOMATIC) VehSpdFound_Cnt_T_lgc;
    VAR(uint16,  AUTOMATIC) Index_Cnt_T_u16;
    
    
    VehSpdFound_Cnt_T_lgc = FALSE;
    Index_Cnt_T_u16 = D_VEHSPDPTNUM_CNT_U16;
    
    for( i = 0U; (i < D_VEHSPDPTNUM_CNT_U16) && (VehSpdFound_Cnt_T_lgc == FALSE); i++ )
    {
        if( (VehSpd_Kph_T_f32 >= t2_VehSpd_Kph_f32[i][D_VEHSPDLOIDX_CNT_U16]) &&
            (VehSpd_Kph_T_f32 < t2_VehSpd_Kph_f32[i][D_VEHSPDHIIDX_CNT_U16]) )
        {
            VehSpdFound_Cnt_T_lgc = TRUE;
            Index_Cnt_T_u16 = i;
        }
    }
    
    *VehSpdOK_Cnt_T_lgc = VehSpdFound_Cnt_T_lgc;
    *VehSpdIndex_Cnt_T_u16 = Index_Cnt_T_u16;
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) FricLearning( VAR(float32, AUTOMATIC) HwAng_HwDeg_T_f32,
                                                                    VAR(float32, AUTOMATIC) ColTrq_HwNm_T_f32,
                                                                    VAR(uint16,  AUTOMATIC) VehSpdIndex_Cnt_T_u16,
                                                                    VAR(uint16,  AUTOMATIC) Direction_Cnt_T_u16)
{
    VAR(uint16,  AUTOMATIC) i;
    VAR(uint16,  AUTOMATIC) IndexOffsetInc_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) IndexOffsetDec_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) IndexOffset_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) Gate_Cnt_T_u16;
    VAR(float32, AUTOMATIC) Phi_Uls_T_f32;
    VAR(float32, AUTOMATIC) PLFMultFactor_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) RangeCounterThreshExceeded_Cnt_T_lgc;
    VAR(uint32,  AUTOMATIC) TotalCounter_Cnt_T_u32;
    VAR(float32, AUTOMATIC) RawAvg_HwNm_T_f32;
	VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32;
	VAR(float32, AUTOMATIC) MaxRawAvgFric_HwNm_T_f32 = 0.0F;
    
    
    /* CalcIndices */
    IndexOffsetInc_Cnt_T_u16 = VehSpdIndex_Cnt_T_u16 * D_TWO_CNT_U16;
    IndexOffsetDec_Cnt_T_u16 = IndexOffsetInc_Cnt_T_u16 + D_ONE_CNT_U16;
    IndexOffset_Cnt_T_u16 = IndexOffsetInc_Cnt_T_u16 + Direction_Cnt_T_u16;
    
    /* Gate */
    Gate_Cnt_T_u16 = D_ZERO_CNT_U16;
	while((Gate_Cnt_T_u16 < D_HWPTNUMSUB1_CNT_U16) &&
            ( (HwAng_HwDeg_T_f32 < t_FrHystHwAPts_HwDeg_f32[Gate_Cnt_T_u16]) ||
              (HwAng_HwDeg_T_f32 >= t_FrHystHwAPts_HwDeg_f32[Gate_Cnt_T_u16 + D_ONE_CNT_U16])))
	{		
		Gate_Cnt_T_u16++;
	}
	    
    if( Gate_Cnt_T_u16 < D_HWPTNUMSUB1_CNT_U16 )
    {
        /* Calc_phi */
        Phi_Uls_T_f32 = (HwAng_HwDeg_T_f32 - t_FrHystHwAPts_HwDeg_f32[Gate_Cnt_T_u16]) / (t_FrHystHwAPts_HwDeg_f32[Gate_Cnt_T_u16 + D_ONE_CNT_U16] - t_FrHystHwAPts_HwDeg_f32[Gate_Cnt_T_u16]);
        
        /* PLF */
        PLFMultFactor_HwNm_T_f32 = (ColTrq_HwNm_T_f32 - ((Phi_Uls_T_f32 * Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffset_Cnt_T_u16][Gate_Cnt_T_u16 + D_ONE_CNT_U16]) +
                                    ((D_ONE_ULS_F32 - Phi_Uls_T_f32) * Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffset_Cnt_T_u16][Gate_Cnt_T_u16]))) * k_LearningGain_Uls_f32;
        
        Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffset_Cnt_T_u16][Gate_Cnt_T_u16 + D_ONE_CNT_U16] += Phi_Uls_T_f32 * PLFMultFactor_HwNm_T_f32;
        Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffset_Cnt_T_u16][Gate_Cnt_T_u16] += (D_ONE_ULS_F32 - Phi_Uls_T_f32) * PLFMultFactor_HwNm_T_f32;
        
    }
    
    
    /* RangeCounterMgr */
    
    RangeCounterThreshExceeded_Cnt_T_lgc = FALSE;
    for( i = D_ZERO_CNT_U16; i < D_HWPTNUMSUB1_CNT_U16; i++ )
    {
        if( Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffset_Cnt_T_u16][i] >= k_RangeCounterLimit_Cnt_u16 )
        {
            RangeCounterThreshExceeded_Cnt_T_lgc = TRUE;
        }
    }
    
    if( Gate_Cnt_T_u16 < D_HWPTNUMSUB1_CNT_U16 )
    {
        Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffset_Cnt_T_u16][Gate_Cnt_T_u16]++;
    }
    
    if( RangeCounterThreshExceeded_Cnt_T_lgc == TRUE )
    {
        for( i = D_ZERO_CNT_U16; i < D_HWPTNUMSUB1_CNT_U16; i++ )
        {
            Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetDec_Cnt_T_u16][i] /= D_TEN_CNT_U16;
            Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetInc_Cnt_T_u16][i] /= D_TEN_CNT_U16;
        }
    }
    
    
    /* CalcAvgFric */
    
    TotalCounter_Cnt_T_u32 = D_ZERO_CNT_U32;
    for( i = D_ZERO_CNT_U16; i < D_HWPTNUMSUB1_CNT_U16; i++ )
    {
        TotalCounter_Cnt_T_u32 += (uint32)Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetDec_Cnt_T_u16][i];
        TotalCounter_Cnt_T_u32 += (uint32)Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetInc_Cnt_T_u16][i];
    }
    
    if( TotalCounter_Cnt_T_u32 >= k_LearningThreshold_Cnt_u32 )
    {
        RawAvg_HwNm_T_f32 = D_ZERO_ULS_F32;
        for( i = D_ZERO_CNT_U16; i < D_HWPTNUMSUB1_CNT_U16; i++ )
        {
            RawAvg_HwNm_T_f32 +=  ( (Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffsetInc_Cnt_T_u16][i] - Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffsetDec_Cnt_T_u16][i]) + 
                                    (Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffsetInc_Cnt_T_u16][i + D_ONE_CNT_U16] - Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[IndexOffsetDec_Cnt_T_u16][i + D_ONE_CNT_U16]) ) *
                                  ( ((float32)Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetInc_Cnt_T_u16][i] + (float32)Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[IndexOffsetDec_Cnt_T_u16][i]) /
                                    ((float32)TotalCounter_Cnt_T_u32) );
        }
        RawAvg_HwNm_T_f32 *= D_QUARTER_CNT_f32;
        
        AvgFricLrn_RawAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16] = RawAvg_HwNm_T_f32;
        
        AvgFricLrn_FiltAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16] = LPF_OpUpdate_f32_m(RawAvg_HwNm_T_f32, &AvgFricLrn_FiltAvgKSV_M_str[VehSpdIndex_Cnt_T_u16]);
        
        AvgFricLrn_SatAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16] = Limit_m( AvgFricLrn_FiltAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16],
																			Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[VehSpdIndex_Cnt_T_u16] - k_SatFricChgLim_HwNm_f32,
																			Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[VehSpdIndex_Cnt_T_u16] + k_SatFricChgLim_HwNm_f32);
        
        AvgFricLrn_EstFric_HwNm_M_f32 = Limit_m(RawAvg_HwNm_T_f32,D_ESTFRICLOLIM_HWNM_F32,D_ESTFRICHILIM_HWNM_F32);
		AvgFricLrn_SatEstFric_HwNm_M_f32 = Limit_m(AvgFricLrn_SatAvgFric_HwNm_M_f32[VehSpdIndex_Cnt_T_u16],D_SATESTFRICLOLIM_HWNM_F32,D_SATESTFRICHILIM_HWNM_F32);
    }
	
	for(i=0U; i < D_VEHSPDPTNUM_CNT_U16; i++)
	{		
		if(AvgFricLrn_RawAvgFric_HwNm_M_f32[i] > MaxRawAvgFric_HwNm_T_f32)
		{
			MaxRawAvgFric_HwNm_T_f32 = AvgFricLrn_RawAvgFric_HwNm_M_f32[i];
		}
	}
	
	if((Abs_f32_m(MaxRawAvgFric_HwNm_T_f32)) >= k_FrictionDiagThreshold_HwNm_f32)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(AvgFricLrn_FrictionDiagThreshTimer_mS_M_u32, &ElapsedTime_mS_T_u32);
		if(ElapsedTime_mS_T_u32 >= k_FrictionDiagTimer_mS_u32)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HighFriction, 1U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AvgFricLrn_FrictionDiagThreshTimer_mS_M_u32);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HighFriction, 0U, NTC_STATUS_PASSED);
	}
    
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) BaselineMode( void )
{
    VAR(uint16, AUTOMATIC) i;
    VAR(uint16, AUTOMATIC) j;
    VAR(float32, AUTOMATIC) EOLFricDiff_HwNm_T_f32;
    
    AvgFricLrn_AvgFricChgKSV_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
    
    EOLFricDiff_HwNm_T_f32 = (Rte_Pim_AvgFricLrnData()->EOLFric_HwNm_f32 - k_BaselineEOLFric_HwNm_f32) * k_EOLFricDiffScalingFactor_Uls_f32;
    EOLFricDiff_HwNm_T_f32 = Limit_m(EOLFricDiff_HwNm_T_f32, k_EOLFricDiffLimitLow_HwNm_f32, k_EOLFricDiffLimitHigh_HwNm_f32);
    
    for( i = D_ZERO_CNT_U16; i < D_VEHSPDPTNUM_CNT_U16; i++ )
    {
        AvgFricLrn_VehBaselineFric_HwNm_M_f32[i]  = t_BaselineFric_HwNm_f32[i];
        Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i]   = t_BaselineFric_HwNm_f32[i] + EOLFricDiff_HwNm_T_f32;
		Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i]   = Limit_m(Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i], D_ZERO_ULS_F32, D_VEHLRNDFRICHILIM_HWNM_F32);	
        AvgFricLrn_RawAvgFric_HwNm_M_f32[i]       = t_BaselineFric_HwNm_f32[i] + EOLFricDiff_HwNm_T_f32;
        AvgFricLrn_FiltAvgFric_HwNm_M_f32[i]      = t_BaselineFric_HwNm_f32[i] + EOLFricDiff_HwNm_T_f32;
        AvgFricLrn_SatAvgFric_HwNm_M_f32[i]       = t_BaselineFric_HwNm_f32[i] + EOLFricDiff_HwNm_T_f32;
        AvgFricLrn_FiltAvgKSV_M_str[i].SV_Uls_f32 = t_BaselineFric_HwNm_f32[i] + EOLFricDiff_HwNm_T_f32;
    }
    
    for( i = D_ZERO_CNT_U16; i < D_VEHSPDPTNUMX2_CNT_U16; i++ )
    {
        for( j = D_ZERO_CNT_U16; j < D_HWPTNUM_CNT_U16; j++ )
        {
            if( (i & D_ONE_CNT_U16) == D_ONE_CNT_U16 )
            {
                /* odd rows */
                Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[i][j] = t2_BaselineTheta_HwNm_f32[i][j] - EOLFricDiff_HwNm_T_f32;
            }
            else
            {
                /* even rows */
                Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[i][j] = t2_BaselineTheta_HwNm_f32[i][j] + EOLFricDiff_HwNm_T_f32;
            }
        }
        
        for( j = D_ZERO_CNT_U16; j < D_HWPTNUMSUB1_CNT_U16; j++ )
        {
            Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[i][j] = t2_BaselineRangeCounter_Cnt_u16[i][j];
        }
    }
    
    Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32 = EOLFricDiff_HwNm_T_f32;
}


STATIC INLINE FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) ClearMode( void )
{
    VAR(uint16, AUTOMATIC) i;
    VAR(uint16, AUTOMATIC) j;
    
    
    AvgFricLrn_AvgFricChgKSV_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
    
    for( i = D_ZERO_CNT_U16; i < D_VEHSPDPTNUM_CNT_U16; i++ )
    {
        AvgFricLrn_VehBaselineFric_HwNm_M_f32[i] = D_ZERO_ULS_F32;
        Rte_Pim_AvgFricLrnData()->VehLearnedFric_HwNm_f32[i] = D_ZERO_ULS_F32;
        AvgFricLrn_RawAvgFric_HwNm_M_f32[i] = D_ZERO_ULS_F32;
        AvgFricLrn_FiltAvgFric_HwNm_M_f32[i] = D_ZERO_ULS_F32;
        AvgFricLrn_SatAvgFric_HwNm_M_f32[i] = D_ZERO_ULS_F32;
        AvgFricLrn_FiltAvgKSV_M_str[i].SV_Uls_f32 = D_ZERO_ULS_F32;
    }
    
    for( i = D_ZERO_CNT_U16; i < D_VEHSPDPTNUMX2_CNT_U16; i++ )
    {
        for( j = D_ZERO_CNT_U16; j < D_HWPTNUM_CNT_U16; j++ )
        {
            Rte_Pim_AvgFricLrnData()->Theta_HwNm_f32[i][j] = D_ZERO_ULS_F32;
        }
        
        for( j = D_ZERO_CNT_U16; j < D_HWPTNUMSUB1_CNT_U16; j++ )
        {
            Rte_Pim_AvgFricLrnData()->RangeCounter_Cnt_u16[i][j] = D_ZERO_CNT_U16;
        }
    }
    
    Rte_Pim_AvgFricLrnData()->FricOffset_HwNm_f32 = D_ZERO_ULS_F32;
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
