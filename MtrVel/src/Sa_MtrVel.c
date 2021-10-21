/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrVel.c
 *     Workspace:  C:/Synergy/prep_projects/MtrVel/MtrVel/autosar
 *     SW-C Type:  Sa_MtrVel
 *  Generated at:  Fri Feb 14 14:37:42 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrVel>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Jun 16 14:56:11 2011
 * %version:          17 %
 * %derived_by:       bz1q07 %
 * %date_modified:    Fri Feb 14 13:05:52 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/08/12   1      NRAR      Initial component                                                            6156
 * 10/08/12   2      NRAR      Updated param bits for Diagnostics                                           6156
 * 12/12/12   3      SAH       Update port data types from polarity to direction
 * 02/05/13   4      JJW       Initial implementation of FDD 02B v010
 * 02/06/13   5      JWJ       Cleaned up & simplified code
 * 02/08/13   6      JJW       Increased resolution on Velocity term in regression algorithm to correct truncation error
 *							   Corrected calculation error on B1Num in regression.
 * 02/12/13   7      JJW       Corrected FPM overflows in RegressionFit function
 * 02/13/13   8      JJW       Corrected FPM resolution of Slope in RegressionFit function
 * 02/16/13   10	 Selva     "Global shared init section is changed to cleared. slope_puS,Blnum_us,Bden_uls 
 *								are initialised to 0. D_B1NUMLIMIT_US_S7P24 corrected.s
 * 02/18/13   11	 JJW       Slope B1Num positive saturation threshold correction, remove unecessary init to 0 on 
 *								Slope calc temp vars. 
 * 04/08/13   12	 JJW       Limit placed on HwVel calculation prior to assigning output
 *								Range limit changes for MtrVel and HwVel outputs per latest FDD DD 
 * 06/12/13   13	 KJS       Moved limit defines to Sa_MtrVel.h for anomaly 5139, also added limit for 
 *								anomaly 5048
 * 06/23/13   14	Selva      Added  MtrVel3_PosBuffer_Rev_M_u0p16 delta calculation masked to 16 bits for proper algorithm operation   CR8246
 * 01/14/14   15     VT        Added limits to output MRFMotorVelUnfiltered_MtrRadpS_f32                       11201
 * 01/16/14   16     VT        Updated to ES-02B ver 13. Added LPFs and fault injection point, ICR-4420        11188
 * 02/14/14   17     VT        Swap fault injection after saving module var, rename new struct and display vars
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Sa_MtrVel.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define MTRVEL_C
#include "Sa_MtrVel.h"
#include "Sa_MtrVel_Cfg.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "interpolation.h"

#define D_CORRTERMA0_ULS_F32			0.5240920730306F
#define D_CORRTERMN1P_ULS_F32			0.09361941664774F
#define D_CORRTERMN2P_ULS_F32			1.488737214789F
#define D_CORRTERME1P_ULS_F32			1.27106431778F
#define D_CORRTERME2P_ULS_F32			3.700991517299F
#define D_USECPERSEC_ULS_F32			1000000.0F
#define D_SNAPSHOTBUF_CNT_U08			2u /* number of buffers for holding snapshot data of variable set for data acquisition */
#define D_B1NUMLIMIT_US_S7P24			(FPM_InitFixedPoint_m(0.0625, s7p24_T) - 1L)

#define D_FIXPTMTRVELHILMT_MTRRADPS_F32		2047.9375F
#define D_FIXPTMTRVELLOLMT_MTRRADPS_F32		(-2048.0F)

#define Square_m(x) ((x)*(x))

#define MTRVEL_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) CrsMtrVel_MtrRadpS_D_f32[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) PredDeltaTheta_Uls_D_f32[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) PredDeltaThetaCor_Uls_D_f32[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) WestBlendedMtrVel_MtrRadpS_D_f32[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) WestVelocity_MtrRadpS_D_f32[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(sint32, AP_MTRVEL_VAR_NOINIT) DeltaTheta_Uls_D_s18p13[D_SNAPSHOTBUF_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];

STATIC VAR(float32, AP_MTRVEL_VAR_NOINIT) MtrVel_MtrRadpS_M_f32;
STATIC VAR(float32, AP_MTRVEL_VAR_NOINIT) HwVel_HwRadpS_M_f32;
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) MtrVel_MtrVelCorrLimAbsDiffFilt_MtrRadpS_D_f32;
STATIC volatile VAR(float32, AP_MTRVEL_VAR_NOINIT) MtrVel_HwVelCorrLimAbsDiffFilt_HwRadpS_D_f32;
STATIC VAR(sint32, AP_MTRVEL_VAR_NOINIT) MtrVelFiltSV_MtrRadpS_M_s11p20;

STATIC volatile VAR(sint32, AP_MTRVEL_VAR_NOINIT) MtrVel_DeltaThetaIntercept_Uls_D_s7p24[D_SNAPSHOTBUF_CNT_U08];
STATIC volatile VAR(sint32, AP_MTRVEL_VAR_NOINIT) MtrVel_Slope_puS_D_sm11p42[D_SNAPSHOTBUF_CNT_U08];
#define MTRVEL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */


#define MTRVEL_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint16, AP_MTRVEL_VAR_NOINIT) PosAvg_Rev_M_u0p16;
STATIC VAR(sint16, AP_MTRVEL_VAR_NOINIT) OldMtrVel_MtrRadpS_M_s11p4;
STATIC VAR(uint16, AP_MTRVEL_VAR_NOINIT) MtrVelDelta_MtrRadpS_M_u12p4;
STATIC VAR(uint16, AP_MTRVEL_VAR_NOINIT) MtrVelDiffAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_MTRVEL_VAR_NOINIT) HwVelDiffAcc_Cnt_M_u16;

STATIC volatile  VAR(uint16, AP_MTRVEL_VAR_NOINIT) MtrVel_AvgDeltaT_uS_D_u16p0[D_SNAPSHOTBUF_CNT_U08];
STATIC VAR(uint8, AP_MTRVEL_VAR_NOINIT) MtrVel_OldPosBuf_Cnt_M_u08;
#define MTRVEL_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */

#define MTRVEL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_MTRVEL_VAR_NOINIT) MtrVel_MtrVelCorrLim_Cnt_M_str;
STATIC VAR(LPF32KSV_Str, AP_MTRVEL_VAR_NOINIT) MtrVel_HwVelCorrLim_Cnt_M_str;
#define MTRVEL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED
#include "MemMap.h"/* PRQA S 5087 */
/* Selector to use Set 0 or Set 1 of the Pos buffers.  This allows switching the active buffer set via an Xcp write to "freeze" a "snap shot"
 * of the working set. Not Static to indicate that the value can be update external to this module by XCP in this case */
VAR(uint8, AP_MTRVEL_VAR_NOINIT) MtrVel_SnapShotSet_Cnt_G_u08;
#define MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED
#include "MemMap.h"/* PRQA S 5087 */


#define MTRVEL_START_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */
/* Module internal copy of the inverse of the Snapshot buffer selector which provides a protected, validated, buffered copy of the active working set of buffers */
STATIC VAR(uint8, AP_MTRVEL_VAR_NOINIT) MtrVel_ActiveBufSet_Cnt_M_u08;
volatile VAR(uint8, AUTOMATIC) MtrVel_OsBufSelect_Cnt_M_u08;
#define MTRVEL_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */


STATIC CONST(DT_Array2_u16, AP_MTRVEL_CONST) T_MtrVelBlendTblY_Uls_u2p14 =
															{FPM_InitFixedPoint_m(0.0, u2p14_T),
															FPM_InitFixedPoint_m(1.0, u2p14_T)};

STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) CalcCoarseVel(	VAR(float32, AUTOMATIC) DeltaPos_Rev_T_f32,
															VAR(float32, AUTOMATIC) DeltaTime_uS_T_f32);

STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) CorrectVel(	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32);

STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) MtrVelBlend(	VAR(float32, AUTOMATIC) FinMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) CrsMtrVel_MtrRadpS_T_f32);


STATIC INLINE FUNC(void, AP_MTRVEL_CODE) RegressionFit(CONST(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7,
													   CONSTP2VAR(sint16, AUTOMATIC, AUTOMATIC) PredDeltaThetaPtr_Uls_T_s1p14,
													   CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) PosAvgPtr_Rev_T_u0p16,
													   CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC ) AvgDeltaTPtr_uS_T_u16p0);


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
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
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
 * Float: D_MSECPERSEC_ULS_F32 = 1000
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718
 * SInt8: D_ZERO_CNT_S8 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRVEL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrVel_Init1
 *********************************************************************************************************************/
	/* Initialize the active and previous MtrPos data buffers */
	MtrVel_OsBufSelect_Cnt_M_u08 = 0u;
	MtrVel_OldPosBuf_Cnt_M_u08 = 1u;
	
	/* Initialize the LPF input */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_CorrMtrVelFiltKn_Hz_f32, D_4MS_SEC_F32, &MtrVel_MtrVelCorrLim_Cnt_M_str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_CorrMtrVelFiltKn_Hz_f32, D_4MS_SEC_F32, &MtrVel_HwVelCorrLim_Cnt_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_MtrVel_Per1_AsstAssemPol_Cnt_s08(void)
 *   Float Rte_IRead_MtrVel_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_HandwheelVel_HwRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_HandwheelVel_HwRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_HwVelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrVel_Per1_HwVelValid_Cnt_lgc(void)
 *   void Rte_IWrite_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrVel_Per1
 *********************************************************************************************************************/
	VAR(sint16, AUTOMATIC) PredDeltaTheta_Uls_T_s1p14;
	VAR(float32, AUTOMATIC) PredDeltaTheta_Uls_T_f32;
	VAR(uint16, AUTOMATIC) PosAvg_Rev_T_u0p16;
	VAR(uint16, AUTOMATIC) AvgDeltaT_uS_T_u16p0;
	VAR(sint16, AUTOMATIC) DeltaPos_Rev_T_sm1p16;
	VAR(float32, AUTOMATIC) DeltaTime_uS_T_f32;
	VAR(float32, AUTOMATIC) DeltaPos_Rev_T_f32;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) CrsMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) WestBlendedMtrVel_MtrRadpS_T_f32;
	VAR(sint16, AUTOMATIC) MtrVel_MtrRadpS_T_s11p4;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7;
	VAR(uint16, AUTOMATIC) MtrVelFilt1Kp_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrVelFilt2Kp_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrVelFiltKp_Cnt_T_u16;
	VAR(sint8, AUTOMATIC) AsstAssemPol_Cnt_T_s08;
	VAR(boolean, AUTOMATIC) MtrPosFault1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrPosFault2_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwVelValid_Cnt_T_lgc;

/* MotorVel is calculated through Primary function(MtrVel) which has runnables in ASIL D
 appln segment and Diverse function(MtrVel2) which has runnables in ASIL B'(D) appln segment.
 Hence FDD02B Ver 007 is divided to 2 application files. This file has PRIMARY VELOCITY
 SUB FUCNTION implemented (FDD Sec 5)*/

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrVel_Per1_CP0_CheckpointReached();

	/* Set the active buffer to the opposite of the snap shot set (XOR with 1) and limit the snap shot buffer to
	 * its valid range, 0 or 1 (AND with 1).  In order to provide freedom of interference between the QM Xcp driver
	 * and this AISL rated module, it is necessary to not directly use the XCP written signal, but rather provide
	 * limiting logic in this module and buffer the resulting value in protected memmory to ensures the processing
	 * within this module is correct regardless of the value of the QM snapshot signal.
	 */
	MtrVel_ActiveBufSet_Cnt_M_u08 = (MtrVel_SnapShotSet_Cnt_G_u08 ^ 1u) & 1u;

	AsstAssemPol_Cnt_T_s08 = Rte_IRead_MtrVel_Per1_AsstAssemPol_Cnt_s08();
	VehSpd_Kph_T_f32 = Rte_IRead_MtrVel_Per1_VehicleSpeed_Kph_f32();
	VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u9p7_T);

	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriMSB_SinCosCorr,&MtrPosFault1_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriVsSec_SinCosCorr, &MtrPosFault2_Cnt_T_lgc);

	/* Oversample preprocessing and Regression Fit */
	RegressionFit(VehSpd_Kph_T_u9p7, &PredDeltaTheta_Uls_T_s1p14, &PosAvg_Rev_T_u0p16, &AvgDeltaT_uS_T_u16p0);

	/* Finite Difference FDD Ver 007 sec - 5.1.2.2 */
	DeltaPos_Rev_T_sm1p16 = (sint16)((PosAvg_Rev_T_u0p16 - PosAvg_Rev_M_u0p16) & 0xFFFFU);

	PosAvg_Rev_M_u0p16 = PosAvg_Rev_T_u0p16;

	DeltaTime_uS_T_f32 = FPM_FixedToFloat_m(AvgDeltaT_uS_T_u16p0, u16p0_T);
	DeltaPos_Rev_T_f32 = FPM_FixedToFloat_m(DeltaPos_Rev_T_sm1p16, sm1p16_T);

	/* Calculate velocity - FDD Ver 007 - Sec 5.1.2.3 */
	CrsMtrVel_MtrRadpS_T_f32 = CalcCoarseVel(DeltaPos_Rev_T_f32, DeltaTime_uS_T_f32);
	CrsMtrVel_MtrRadpS_D_f32[MtrVel_ActiveBufSet_Cnt_M_u08] = CrsMtrVel_MtrRadpS_T_f32;

	/* ArcSin Correction */
	PredDeltaTheta_Uls_T_f32 = FPM_FixedToFloat_m(PredDeltaTheta_Uls_T_s1p14, s1p14_T);
	PredDeltaTheta_Uls_D_f32[MtrVel_ActiveBufSet_Cnt_M_u08] = PredDeltaTheta_Uls_T_f32;
	PredDeltaTheta_Uls_T_f32 = CorrectVel(PredDeltaTheta_Uls_T_f32);
	PredDeltaThetaCor_Uls_D_f32[MtrVel_ActiveBufSet_Cnt_M_u08] = PredDeltaTheta_Uls_T_f32;

	/* Divide angular change by time to compute angular velocity, multiply by uS per Sec for units conversion  */
	MtrVel_MtrRadpS_T_f32 = (PredDeltaTheta_Uls_T_f32 * D_USECPERSEC_ULS_F32) / DeltaTime_uS_T_f32;
	WestVelocity_MtrRadpS_D_f32[MtrVel_ActiveBufSet_Cnt_M_u08] = MtrVel_MtrRadpS_T_f32;

	MtrVel_MtrRadpS_T_f32 = MtrVelBlend(MtrVel_MtrRadpS_T_f32, CrsMtrVel_MtrRadpS_T_f32);
	WestBlendedMtrVel_MtrRadpS_T_f32 = Limit_m(MtrVel_MtrRadpS_T_f32, D_MTRVELLOLMT_MTRRADPS_F32, D_MTRVELHILMT_MTRRADPS_F32);
	WestBlendedMtrVel_MtrRadpS_D_f32[MtrVel_ActiveBufSet_Cnt_M_u08] = MtrVel_MtrRadpS_T_f32;


	if (TRUE == k_MtrVelFiltEn_Cnt_lgc)
	{
		/* Limit motor velocity to fit within the limits of a s11p4 */
		MtrVel_MtrRadpS_T_f32 = Limit_m(MtrVel_MtrRadpS_T_f32, D_FIXPTMTRVELLOLMT_MTRRADPS_F32, D_FIXPTMTRVELHILMT_MTRRADPS_F32);
		
		MtrVel_MtrRadpS_T_s11p4 = FPM_FloatToFixed_m(MtrVel_MtrRadpS_T_f32, s11p4_T);

		MtrVelFilt1Kp_Cnt_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_MtrVelDeltaKpTblX_MtrRadpS_u12p4,
																t_MtrVelDeltaKpTblY_Cnt_u16,
																TableSize_m(t_MtrVelDeltaKpTblX_MtrRadpS_u12p4),
																MtrVelDelta_MtrRadpS_M_u12p4);

		MtrVelFilt2Kp_Cnt_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_MtrVelFiltKpTblX_Kph_u9p7,
																t_MtrVelFiltKpYTbl_Cnt_u16,
																TableSize_m(t_MtrVelDeltaKpTblX_MtrRadpS_u12p4),
																VehSpd_Kph_T_u9p7);

		MtrVelFiltKp_Cnt_T_u16 = Max_m(MtrVelFilt1Kp_Cnt_T_u16, MtrVelFilt2Kp_Cnt_T_u16);

		MtrVelFiltSV_MtrRadpS_M_s11p20 = LPF_SvUpdate_s16InFixKTrunc_m(	MtrVel_MtrRadpS_T_s11p4,
																		MtrVelFiltSV_MtrRadpS_M_s11p20,
																		MtrVelFiltKp_Cnt_T_u16);
		MtrVelDelta_MtrRadpS_M_u12p4 = Abs_s16_m((OldMtrVel_MtrRadpS_M_s11p4 - MtrVel_MtrRadpS_T_s11p4));

		MtrVel_MtrRadpS_T_s11p4 = LPF_OpUpdate_s16InFixKTrunc_m(MtrVelFiltSV_MtrRadpS_M_s11p20);

		OldMtrVel_MtrRadpS_M_s11p4 = MtrVel_MtrRadpS_T_s11p4;

		MtrVel_MtrRadpS_T_f32 = FPM_FixedToFloat_m(MtrVel_MtrRadpS_T_s11p4, s11p4_T);


	}

	if((TRUE == MtrPosFault1_Cnt_T_lgc) ||( TRUE == MtrPosFault2_Cnt_T_lgc))
	{
		HwVelValid_Cnt_T_lgc = FALSE;
	}
	else
	{
		HwVelValid_Cnt_T_lgc = TRUE;
	}

	MtrVel_MtrRadpS_T_f32 = Limit_m(MtrVel_MtrRadpS_T_f32, D_MTRVELLOLMT_MTRRADPS_F32, D_MTRVELHILMT_MTRRADPS_F32);

	MtrVel_MtrRadpS_M_f32 = MtrVel_MtrRadpS_T_f32;
	
    /* Added fault injection point for motor velocity output */
	#if (STD_ON == BC_MTRVEL_FAULTINJECTIONPOINT)
	    Rte_Call_FaultInjection_SCom_FltInjection(&MtrVel_MtrRadpS_T_f32, FLTINJ_MTRVEL);
	#endif

	Rte_IWrite_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(MtrVel_MtrRadpS_T_f32);

	MtrVel_MtrRadpS_T_f32 = (float32)AsstAssemPol_Cnt_T_s08 * MtrVel_MtrRadpS_T_f32;

	Rte_IWrite_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(MtrVel_MtrRadpS_T_f32);

	HwVel_HwRadpS_T_f32 = MtrVel_MtrRadpS_T_f32 * k_GearRatio_Uls_f32;

	/* Legal Range limit the HwVel prior to assigning to module outputs */
	HwVel_HwRadpS_M_f32 = Limit_m(HwVel_HwRadpS_T_f32, D_HWVELLOLMT_HWRADPS_F32, D_HWVELHILMT_HWRADPS_F32);
	
	Rte_IWrite_MtrVel_Per1_HandwheelVel_HwRadpS_f32(HwVel_HwRadpS_M_f32);
	Rte_IWrite_MtrVel_Per1_HwVelValid_Cnt_lgc(HwVelValid_Cnt_T_lgc);
	Rte_IWrite_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(WestBlendedMtrVel_MtrRadpS_T_f32);

	Rte_IWrite_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(MtrVel_MtrRadpS_M_f32);
	Rte_IWrite_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(HwVel_HwRadpS_M_f32);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrVel_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Per2
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
 *   Float Rte_IRead_MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32(void)
 *   Float Rte_IRead_MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32(void)
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

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrVel_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) SysCDiagHandWheelVel_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) SysCDiagMtrVelMRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrVelCorrLimDiff_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrVelCorrLimDiffFilt_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrVelCorrLimAbsDiffFilt_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwVelCorrLimDiff_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwVelCorrLimDiffFilt_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwVelCorrLimAbsDiffFilt_MtrRadpS_T_f32;

	Rte_Call_MtrVel_Per2_CP0_CheckpointReached();

	SysCDiagMtrVelMRF_MtrRadpS_T_f32 = Rte_IRead_MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32();
	SysCDiagHandWheelVel_HwRadpS_T_f32 = Rte_IRead_MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32();

	/* MtrVel cross check diagnostics */
	MtrVelCorrLimDiff_MtrRadpS_T_f32 = (MtrVel_MtrRadpS_M_f32 - SysCDiagMtrVelMRF_MtrRadpS_T_f32);

		/* MtrVel low pass filter */
	MtrVelCorrLimDiffFilt_MtrRadpS_T_f32 = LPF_OpUpdate_f32_m(MtrVelCorrLimDiff_MtrRadpS_T_f32, &MtrVel_MtrVelCorrLim_Cnt_M_str);
	
	MtrVelCorrLimAbsDiffFilt_MtrRadpS_T_f32 = Abs_f32_m(MtrVelCorrLimDiffFilt_MtrRadpS_T_f32);
	if(MtrVelCorrLimAbsDiffFilt_MtrRadpS_T_f32 > k_MtrVelCorrLim_MtrRadpS_f32)
	{
		MtrVelDiffAcc_Cnt_M_u16 = DiagPStep_m(MtrVelDiffAcc_Cnt_M_u16, k_MtrVelCorrLim_Cnt_Str);
	}
	else
	{
		MtrVelDiffAcc_Cnt_M_u16 = DiagNStep_m(MtrVelDiffAcc_Cnt_M_u16, k_MtrVelCorrLim_Cnt_Str);
	}

	if(DiagFailed_m(MtrVelDiffAcc_Cnt_M_u16,k_MtrVelCorrLim_Cnt_Str) ==  TRUE)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_NUM_SysFailureForRotVel,0x01U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_NUM_SysFailureForRotVel,0x0U, NTC_STATUS_PASSED);
	}

	/* HwVel cross check diagnostics */
	HwVelCorrLimDiff_MtrRadpS_T_f32 = (HwVel_HwRadpS_M_f32 - SysCDiagHandWheelVel_HwRadpS_T_f32);

		/* HwVel low pass filter */
	HwVelCorrLimDiffFilt_MtrRadpS_T_f32 = LPF_OpUpdate_f32_m(HwVelCorrLimDiff_MtrRadpS_T_f32, &MtrVel_HwVelCorrLim_Cnt_M_str);

	HwVelCorrLimAbsDiffFilt_MtrRadpS_T_f32 = Abs_f32_m(HwVelCorrLimDiffFilt_MtrRadpS_T_f32);
	if(HwVelCorrLimAbsDiffFilt_MtrRadpS_T_f32 > k_HwVelCorrLim_HwRadpS_f32)
	{
		HwVelDiffAcc_Cnt_M_u16 = DiagPStep_m(HwVelDiffAcc_Cnt_M_u16, k_HwVelCorrLim_Cnt_Str);
	}
	else
	{
		HwVelDiffAcc_Cnt_M_u16 = DiagNStep_m(HwVelDiffAcc_Cnt_M_u16, k_HwVelCorrLim_Cnt_Str);
	}

	if(DiagFailed_m(HwVelDiffAcc_Cnt_M_u16,k_HwVelCorrLim_Cnt_Str) ==  TRUE)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_NUM_SysFailureForRotVel,0x02U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_NUM_SysFailureForRotVel,0x0U, NTC_STATUS_PASSED);
	}

	MtrVel_MtrVelCorrLimAbsDiffFilt_MtrRadpS_D_f32 = MtrVelCorrLimAbsDiffFilt_MtrRadpS_T_f32;
	MtrVel_HwVelCorrLimAbsDiffFilt_HwRadpS_D_f32 = HwVelCorrLimAbsDiffFilt_MtrRadpS_T_f32;

	Rte_Call_MtrVel_Per2_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRVEL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Name:   CalcCourseVal
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  DeltaPos_Rev_T_f32                  | float32   | -0.2      | 0.2
 *  DeltaTime_uS_T_f32                  | float32   | 900       | 1100
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  MtrVel_MtrRadpS_T_f32               | float32   | -1100     | 1100
 *
 **********************************************************************************************************************/
STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) CalcCoarseVel(	VAR(float32, AUTOMATIC) DeltaPos_Rev_T_f32,
															VAR(float32, AUTOMATIC) DeltaTime_uS_T_f32)
{
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;

	MtrVel_MtrRadpS_T_f32 = (DeltaPos_Rev_T_f32 * D_RADPERREV_ULS_F32 * D_USECPERSEC_ULS_F32) / DeltaTime_uS_T_f32;

	return (MtrVel_MtrRadpS_T_f32);
}


/***********************************************************************************************************************
 *  Name:   CorrectVel
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  MtrVel_MtrRadpS_T_f32               | float32   | -1000     | 1000
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  MtrVel_MtrRadpS_T_f32               | float32   | -1100     | 1100
 *
 **********************************************************************************************************************/
STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) CorrectVel(	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32)
{
	VAR(float32, AUTOMATIC) MtrVelSqrd_Uls_T_f32;
	VAR(float32, AUTOMATIC) CorrFactor_Uls_T_f32;

	MtrVelSqrd_Uls_T_f32 = MtrVel_MtrRadpS_T_f32 * MtrVel_MtrRadpS_T_f32;

	CorrFactor_Uls_T_f32 = 	D_CORRTERMA0_ULS_F32 +
							(D_CORRTERMN1P_ULS_F32 / (D_CORRTERME1P_ULS_F32 - MtrVelSqrd_Uls_T_f32)) +
							(D_CORRTERMN2P_ULS_F32 / (D_CORRTERME2P_ULS_F32 - MtrVelSqrd_Uls_T_f32));

	MtrVel_MtrRadpS_T_f32 = MtrVel_MtrRadpS_T_f32 * CorrFactor_Uls_T_f32;

	return (MtrVel_MtrRadpS_T_f32);
}


/***********************************************************************************************************************
 *  Name:   MtrVelBlend
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  FinMtrVel_MtrRadpS_T_f32            | float32   | -1118     | 1118
 *  CrsMtrVel_MtrRadpS_T_f32            | float32   | -1118     | 1118
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  MtrVel_MtrRadpS_T_f32               | float32   | -1118     | 1118
 *
 **********************************************************************************************************************/
STATIC INLINE FUNC(float32, AP_MTRVEL_CODE) MtrVelBlend(	VAR(float32, AUTOMATIC) FinMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) CrsMtrVel_MtrRadpS_T_f32)
{
	VAR(sint16, AUTOMATIC) CrsMtrVel_MtrRadpS_T_s11p4;
	VAR(uint16, AUTOMATIC) MtrVelBlendPct_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) MtrVelBlendPct_Uls_T_f32;
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;

	CrsMtrVel_MtrRadpS_T_s11p4 = FPM_FloatToFixed_m(CrsMtrVel_MtrRadpS_T_f32, s11p4_T);

	MtrVelBlendPct_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_MtrVelBlendTblX_MtrRadpS_u12p4,
																T_MtrVelBlendTblY_Uls_u2p14,
																TableSize_m(t_MtrVelBlendTblX_MtrRadpS_u12p4),
																Abs_s16_m(CrsMtrVel_MtrRadpS_T_s11p4));

	MtrVelBlendPct_Uls_T_f32 = FPM_FixedToFloat_m(MtrVelBlendPct_Uls_T_u2p14, u2p14_T);

	MtrVel_MtrRadpS_T_f32 = 	(CrsMtrVel_MtrRadpS_T_f32 * MtrVelBlendPct_Uls_T_f32) +
								(FinMtrVel_MtrRadpS_T_f32 * (1.0F - MtrVelBlendPct_Uls_T_f32));

	return (MtrVel_MtrRadpS_T_f32);
}


/***********************************************************************************************************************
 *  Name:   RegressionFit
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  VehSpd_Kph_T_u9p7                   | sint16    | 0         | 511
 *  PredDeltaThetaPtr_Uls_T_s1p14       | *sint16   | FULL      | FULL
 *  PosAvgPtr_Rev_T_u0p16               | *uint16   | 0         | 1
 *  AvgDeltaTPtr_uS_T_u16p0             | *uint16   | FULL      | FULL
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  None                                |           |           |
 *
 **********************************************************************************************************************/
STATIC INLINE FUNC(void, AP_MTRVEL_CODE) RegressionFit(	CONST(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7,
														CONSTP2VAR(sint16, AUTOMATIC, AUTOMATIC) PredDeltaThetaPtr_Uls_T_s1p14,
														CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC ) PosAvgPtr_Rev_T_u0p16,
														CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC ) AvgDeltaTPtr_uS_T_u16p0)
{
	VAR(sint32, AUTOMATIC) PosSum_Rev_T_s15p16 = 0;
	VAR(uint16, AUTOMATIC) i;
	VAR(uint16, AUTOMATIC) i_old;
	VAR(sint16, AUTOMATIC) PosDiff_Rev_T_sm1p16;
	VAR(uint16, AUTOMATIC) AvgDeltaT_uS_T_u16p0;

	VAR(uint8, AUTOMATIC)  NewBufIdx_Cnt_T_u08;
	VAR(sint32, AUTOMATIC) DeltaTheta_Uls_T_s5p26;
	VAR(sint32, AUTOMATIC) DeltaTheta_Uls_T_s18p13;
	VAR(sint32, AUTOMATIC) Velocity_Uls_T_s7p24;
	VAR(sint32, AUTOMATIC) SumVelocity_Uls_T_s7p24 = 0;
	VAR(sint32, AUTOMATIC) SumDeltaT_uS_T_s32 = 0;
	VAR(sint32, AUTOMATIC) DeltaT_uS_T_s32;
	VAR(sint32, AUTOMATIC) term2t_uS_T_s32;
	VAR(uint16, AUTOMATIC) RelativeTnew_uS_T_u16;
	VAR(uint16, AUTOMATIC) RelativeTold_uS_T_u16;
	VAR(sint32, AUTOMATIC) Sum2tXvelocity_uS_T_s7p24 = 0;
	VAR(sint32, AUTOMATIC) Sum2t_uS_T_s32 = 0;
	VAR(sint32, AUTOMATIC) Sum2tSqr_uS2_T_s32 = 0;
	VAR(sint32, AUTOMATIC) Slope_puS_T_sm11p42;
	VAR(sint32, AUTOMATIC) B1num_uS_T_s7p24;
	VAR(sint32, AUTOMATIC) Bden_uS2_T_s31p0;
	VAR(sint32, AUTOMATIC) DeltaThetaIntercept_Uls_T_s7p24;
	VAR(uint16, AUTOMATIC) TimeOffset_uS_T_u16;
	VAR(sint32, AUTOMATIC) PredictedDeltaTheta_Uls_T_s7p24;
	VAR(uint16, AUTOMATIC) OffsetTime_uS_T_u16;


	 /* Current vs Previous buffer management */
	NewBufIdx_Cnt_T_u08 = MtrVel_OsBufSelect_Cnt_M_u08;

	/* Set the index greater than the buffer to indicate to the motor control scheduled ISR process that updates to the OS buffer should be halted.
	 * Note that it is IMPERATIVE that the MtrVel_OsBufSelect_Cnt_M_u08 write is performed exactly in the order written in this portion of
	 * of the algorithm.  In order to ensure the compiler optimizer does not alter the order of processing, MtrVel_OsBufSelect_Cnt_M_u08 must be
	 * declared as a "volatile" variable.
	 */
	MtrVel_OsBufSelect_Cnt_M_u08 = D_MTRVELOSBUFNUM_CNT_U08;

	/* Synchronize the buffer indexers, since order does not matter, the base iterrator i is used for the new sample set and the old is initialized
	 * to the difference between the sample set positions */
	i_old = (uint16)(MtrVel3_OsBufPos_Cnt_M_u08[MtrVel_OldPosBuf_Cnt_M_u08] - MtrVel3_OsBufPos_Cnt_M_u08[NewBufIdx_Cnt_T_u08]) & (D_MTRVELOSBUFSZ_CNT_U08 - 1U);

	/* Select the Min overall timestamp which is the Prev Buffer position SV + 1, since it is a circular buffer */
	OffsetTime_uS_T_u16 = MtrVel3_TimeBuffer_uS_M_u16p0[MtrVel_OldPosBuf_Cnt_M_u08][(MtrVel3_OsBufPos_Cnt_M_u08[MtrVel_OldPosBuf_Cnt_M_u08]+ 1u) & (D_MTRVELOSBUFSZ_CNT_U08 - 1U)];

	for (i = 0u; i < D_MTRVELOSBUFSZ_CNT_U08; i++)
	{
		/* Finite Difference FDD 02B v010 Sec 5.1.2.2. */
		PosDiff_Rev_T_sm1p16 = (sint16)((MtrVel3_PosBuffer_Rev_M_u0p16[NewBufIdx_Cnt_T_u08][i] - MtrVel3_PosBuffer_Rev_M_u0p16[NewBufIdx_Cnt_T_u08][0]) & 0xFFFFu);
		PosSum_Rev_T_s15p16 = PosSum_Rev_T_s15p16 +(sint32) MtrVel3_PosBuffer_Rev_M_u0p16[NewBufIdx_Cnt_T_u08][0] + (sint32) PosDiff_Rev_T_sm1p16;

		/* DeltaTheta Calculation FDD 02B v010 Sec 5.1.2.3.1.1 */
		DeltaTheta_Uls_T_s5p26 = ((sint32)MtrVel3_SinBuffer_Uls_M_s2p13[NewBufIdx_Cnt_T_u08][i] * (sint32)MtrVel3_CosBuffer_Uls_M_s2p13[MtrVel_OldPosBuf_Cnt_M_u08][i_old]) -
								 ((sint32)MtrVel3_SinBuffer_Uls_M_s2p13[MtrVel_OldPosBuf_Cnt_M_u08][i_old] * (sint32)MtrVel3_CosBuffer_Uls_M_s2p13[NewBufIdx_Cnt_T_u08][i]);
		DeltaTheta_Uls_T_s18p13 = DeltaTheta_Uls_T_s5p26 / FPM_Fix_m(Square_m((sint32)MtrVel3_SinBuffer_Uls_M_s2p13[NewBufIdx_Cnt_T_u08][i]) + Square_m((sint32)MtrVel3_CosBuffer_Uls_M_s2p13[NewBufIdx_Cnt_T_u08][i]), s5p26_T, s18p13_T);
		DeltaTheta_Uls_D_s18p13[MtrVel_ActiveBufSet_Cnt_M_u08][i] = DeltaTheta_Uls_T_s18p13;

		/* Regression Fit Function FDD 02B v010 Sec 5.1.2.3.1.2 */
		/* Calcualte relative time signals to limit the magnitude of the calculations and accumulators */
		/* AND both relative times with 0xFFFF in event that optimizer atempts to turn into 32 bit operation */
		RelativeTnew_uS_T_u16 = (MtrVel3_TimeBuffer_uS_M_u16p0[NewBufIdx_Cnt_T_u08][i] - OffsetTime_uS_T_u16) & 0xFFFFu;
		RelativeTold_uS_T_u16 = (MtrVel3_TimeBuffer_uS_M_u16p0[MtrVel_OldPosBuf_Cnt_M_u08][i_old] - OffsetTime_uS_T_u16) & 0xFFFFu;
		DeltaT_uS_T_s32 = (sint32)(RelativeTnew_uS_T_u16 - RelativeTold_uS_T_u16);

		Velocity_Uls_T_s7p24 = FPM_Fix_m(DeltaTheta_Uls_T_s18p13, s18p13_T, s7p24_T )/ DeltaT_uS_T_s32;

		/* Perform summation computations required in regression algorithm */
		term2t_uS_T_s32 = (sint32)(RelativeTnew_uS_T_u16 + RelativeTold_uS_T_u16);
		Sum2tSqr_uS2_T_s32 += Square_m(term2t_uS_T_s32);
		Sum2t_uS_T_s32 += term2t_uS_T_s32;
		Sum2tXvelocity_uS_T_s7p24 += (term2t_uS_T_s32 * Velocity_Uls_T_s7p24);
		SumDeltaT_uS_T_s32 += DeltaT_uS_T_s32;
		SumVelocity_Uls_T_s7p24 += Velocity_Uls_T_s7p24;

		/* Update the old sample indexer, the operation assumes the sample size is a power of 2 (e.g. 2, 4, 8, 16...) */
		i_old = (i_old + 1u) & (D_MTRVELOSBUFSZ_CNT_U08 - 1u);
	}

	/* Determine what the next new buffer should be and set the Write enable to this value to activate the buffer */
	MtrVel_OsBufSelect_Cnt_M_u08 = (((NewBufIdx_Cnt_T_u08 & 1u) ^ 1u) + (MtrVel_ActiveBufSet_Cnt_M_u08 * D_SNAPSHOTBUF_CNT_U08)) & 3u; /* AND 1 then XOR1 is to toggle between 0 and 1, then add the buffer set offset, AND with 3 is to limit the buffer index to the valid range */
	MtrVel_OldPosBuf_Cnt_M_u08 = NewBufIdx_Cnt_T_u08; /* Store the newest buffer index in the Old buff index for next execution */

	B1num_uS_T_s7p24 = (Sum2tXvelocity_uS_T_s7p24 * (sint32)D_MTRVELOSBUFSZ_CNT_U08) -
						(SumVelocity_Uls_T_s7p24 * Sum2t_uS_T_s32);
						
	/* B1num must be limited to prevent an overflow when upscaling the term in the division to attain the proper resolution.
	 * The FDD has not been clarified to provide a required range and resolution at any node, but per verbal conversations and e-mails
	 * the desired minimum acceleration range is 4,000 rad/s^2, this implementation provides 10,000 rad/s^2
	 * The desired resolution is 0.25 rad/s^2, but 5 rad/s^2 would be acceptable, this implementation provides 0.25 rad/s^2
	 */
	B1num_uS_T_s7p24 = Limit_m(B1num_uS_T_s7p24, -D_B1NUMLIMIT_US_S7P24, D_B1NUMLIMIT_US_S7P24);
	Bden_uS2_T_s31p0 = (sint32)(Sum2tSqr_uS2_T_s32 * D_MTRVELOSBUFSZ_CNT_U08) - Square_m(Sum2t_uS_T_s32);

	/* Resolution and Range of Slope are not specified in the FDD requirements, following division scaling is a SWAG */
	Slope_puS_T_sm11p42 = FPM_Fix_m(B1num_uS_T_s7p24, s7p24_T, sm4p35_T) / FPM_Fix_m(Bden_uS2_T_s31p0, s31p0_T, s38pm7_T);
	DeltaThetaIntercept_Uls_T_s7p24 = SumVelocity_Uls_T_s7p24 /(sint32)D_MTRVELOSBUFSZ_CNT_U08;

	/* Look-up time offset for prediction */
	TimeOffset_uS_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_MtrVelTimeOffsetTblX_Kph_u9p7,
														t_MtrVelTimeOffsetYTbl_uS_u16,
														TableSize_m(t_MtrVelTimeOffsetTblX_Kph_u9p7),
														VehSpd_Kph_T_u9p7);

	AvgDeltaT_uS_T_u16p0 = (uint16)(SumDeltaT_uS_T_s32/(sint32)D_MTRVELOSBUFSZ_CNT_U08);
	PredictedDeltaTheta_Uls_T_s7p24 = (FPM_Fix_m(((sint32)TimeOffset_uS_T_u16 * Slope_puS_T_sm11p42), sm11p42_T, s7p24_T) + DeltaThetaIntercept_Uls_T_s7p24) *
										AvgDeltaT_uS_T_u16p0;

	/* Display variables */
	MtrVel_DeltaThetaIntercept_Uls_D_s7p24[MtrVel_ActiveBufSet_Cnt_M_u08] = DeltaThetaIntercept_Uls_T_s7p24;
	MtrVel_Slope_puS_D_sm11p42[MtrVel_ActiveBufSet_Cnt_M_u08] = Slope_puS_T_sm11p42;
	MtrVel_AvgDeltaT_uS_D_u16p0[MtrVel_ActiveBufSet_Cnt_M_u08] = AvgDeltaT_uS_T_u16p0;

	/* Update Function return buffers */
	*PosAvgPtr_Rev_T_u0p16 = (uint16)(PosSum_Rev_T_s15p16/(sint32)D_MTRVELOSBUFSZ_CNT_U08);
	*PredDeltaThetaPtr_Uls_T_s1p14 = (sint16)FPM_Fix_m(PredictedDeltaTheta_Uls_T_s7p24, s7p24_T, s1p14_T);
	*AvgDeltaTPtr_uS_T_u16p0 = AvgDeltaT_uS_T_u16p0;
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
