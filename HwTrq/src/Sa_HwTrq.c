/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_HwTrq.c
 *     Workspace:  C:/Synergy/01_Components/HwTrq-dzxvzg/HwTrq/autosar
 *     SW-C Type:  Sa_HwTrq
 *  Generated at:  Tue Dec 17 10:15:03 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_HwTrq>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#49 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Fri Dec  6 14:37:17 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11   10       JJW       Cross Check Diag Support Added
 * 06/17/11   11       JJW       FWK Updates
 * 06/17/11   12       LWW       TypeH NVM storage anomaly fix
 * 07/19/11   13       LWW       Removed Cross Check Diag Support
 * 07/22/11   14       LWW       Remove unused temp variable
 * 09/24/11   15       LWW       Added check at init on NvM block
 * 09/26/11	  16       KJS		 Updated diagnostic function calls with 9bit NTC value							4500
 * 11/05/11   17       LWW		 Component template updates for FDD 04 rev008 implementation
 * 11/23/11   17.1.3   JJW       Updated the SWC description
 * 11/15/11   18       VK	     Initial CBD for Hw Trq Analog													3623
 * 11/23/11   19       VK        Changes to the CBD based on FDD 04 rev008 requirements 						3623
 * 12/2/11    19.1     VK		 Changes to Scom functions														3623
 * 12/5/11    20       JJW       Per3 trigger rate moved to 100ms from 128ms
 * 12/5/11    21       VK        QAC error fixes
 * 12/13/11   22       VK        Changed HwTrqScaleStatus, HwTrqTrimStatus to boolean type
 * 12/14/11   23       VK        Match the names of the elements in HwTrqScale_Datatype and
 *								 HwTrqTrim_Datatype as in digital hw torque
 * 12/14/11   24       VK        Corrected Rte read calls for MEC
 * 12/15/11   25       OT        Updated argument to Set Scale to match DigHwTrq
 * 12/15/11   26       OT        Fixed comment
 * 12/16/11   27       OT        Fixed scale validity check logic
 * 02/01/12   28       OT        Fixed NTC_STATUS_PASSED path anomaly, added error acc macros
 * 03/05/12   29       OT        Fixed the NTC_STATUS_PASSED path anomaly fix, changed limit to diff torque   5025,5004
 * 04/20/12   30       VK        Added manual write scomm function for Torque Trim Block, removed MEC			5257
 * 04/21/12   31       VK        Updated NTC's	NTC_Num_TrqSensorScaleInvalid and NTC_Num_EEPROMDiagTrqSnrStr	5257
 *							     with NTC_Num_PriSnsrTrqStorFlt	and logic to clear it
 * 04/23/12   32	   VK        Integration error fixes														5257
 * 04/27/12   33	   LWW       Removal of polarity input
 * 06/05/12   34	   OT        Updated to FDD 04A v005                                                        5592
 * 06/14/12   35       JWJ       Updated to FDD 04A v006                                                        5663
 * 06/17/12	  36	   KJS		 Corrected EOL Trq Step access for Scom and Per1 functions						5693
 * 08/22/12   37       VK        Fixed anomaly 3646(Added Nxtr MEC)											6060
 * 09/04/12   38       VK		 Added double de-reference to EOLTrqStepData pointers in Per1                   6060
 *								 and Scom functions.
 * 09/27/12   39      Selva      Checkpoints added and mempmap macros corrected
 * 10/11/12   40       OT        Implemented FDD 04A v007                                                       6467
 * 10/24/12   41       OT        Anomaly 2824 - T1 vs T2 cal usage                                              6629
 * 10/29/12   42       LWW       Update for Trim and Scale values as sender from this module
 * 02/08/13   43	   SP	     QAC warnings fixed
 * 03/25/13   43.1.1   LWW	     Anomaly 4683 Corrections
 * 07/09/13   44	   Selva      Updated to FDD4V10.2 												      8891
 * 07/11/13   45	   Selva      Updated to FDD4V10.3                                                    8893
 * 08/14/13   46       VT        Updated to FDD4V12, Anomaly 4851 fix                                           9388
 * 11/21/13   47       Jared     Updated to FDD v013 to correct A5725                                           10862
 * 12/12/13   48       RM        A4557 and A5255 fixed                                                    11040, 11045
 * 08/11/15   49       ABS       Update to FDD04A v 014                                                    EA3#2355
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


 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

 *********************************************************************************************************************/

#include "Rte_Sa_HwTrq.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "interpolation.h"
#include "Sa_HwTrq_Cfg.h"


#define D_HWTRQLOLMT_HWNM_F32					(-10.0F)
#define D_HWTRQHILMT_HWNM_F32					10.0F
#define D_DFLTRTRQTRIM_VOLT_F32				    2.5F
#define D_TRQSCALEWNDW_ULS_F32       			0.20F
#define D_SSDIAGNFILTSVLMT_VOLT_S4P27			FPM_Fix_m(((uint32)k_SSDiagLim_Volts_u5p11 + 1U), u21p11_T, s4p27_T)
#define D_NTCFAILED_CNT_U08						0x01U
#define D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08	0x03U
#define D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08	0x40U
#define D_NUMTRQSTEP_CNT_U08					10U


/* Module Internals */
#define HWTRQ_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) AnaDiffHwTrq_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) AnaHwTorque_HwNm_M_f32;
STATIC VAR(sint32,  AUTOMATIC) TDiagFiltSV_Volt_M_s4p27;
STATIC VAR(sint32,  AUTOMATIC) SSDiagFiltSV_Volt_M_s4p27;
STATIC volatile VAR(float32, AUTOMATIC) SysCHwTorqueCh1_HwNm_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) HWTorqCorrLimDiff_HwNm_D_f32;
#define HWTRQ_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define HWTRQ_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint16,  AUTOMATIC) CorrDiagFiltOut_Volt_M_s4p11;
STATIC VAR(uint16,  AUTOMATIC) T1RngErrAcc_Cnt_M_u16;
STATIC VAR(uint16,  AUTOMATIC) T2RngErrAcc_Cnt_M_u16;
STATIC VAR(uint16,  AUTOMATIC) HwTorqCorrLimErrAcc_Cnt_M_u16;
STATIC VAR(sint16,  AUTOMATIC) TDiagFiltOut_Volt_M_s4p11;
STATIC VAR(uint16,  AUTOMATIC) TrqSensorRecDiagAcc_Cnt_M_u16;
STATIC VAR(sint16,  AUTOMATIC) TrqSum_Volt_M_s4p11;
STATIC VAR(uint16,  AUTOMATIC) SumFltOut_Volt_M_u5p11;
STATIC VAR(sint16,  AUTOMATIC) SSDiagFiltOut_Volt_M_s4p11;
#define HWTRQ_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define HWTRQ_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(NvM_RequestResultType, AUTOMATIC) NvMBlkStatus_Cnt_M_u8;
#define HWTRQ_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

/* Type H Data */
#define HWTRQ_START_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint32,  AUTOMATIC) CorrDiagFiltSV_Volt_M_s4p27;
#define HWTRQ_STOP_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */


/* Local Function Prototypes */
STATIC FUNC(boolean, SA_HWTRQ_CODE) IsTrqScaleInRng_lgc(VAR(float32, AUTOMATIC) TrqScale_VoltpDeg_T_f32);
STATIC FUNC(boolean, SA_HWTRQ_CODE) IsTrqScaleInRng_CalCheck_lgc(VAR(float32, AUTOMATIC) TrqScale_VoltpDeg_T_f32);

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
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 * HwTrqStatusType: Enumeration of integer in interval [0...2] with enumerators
 *   HWTRQSTATUS_NONE (0u)
 *   HWTRQSTATUS_ACTIVE (1u)
 *   HWTRQSTATUS_FAULT (2u)
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0u)
 *   ManufacturingMode (1u)
 *   EngineeringMode (2u)
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
 * EOLTrqStepType: Array with 10 element(s) of type Float
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * HwTrqScale_Datatype: Record with elements
 *   HwTrqScale_VoltsPerDeg_f32 of type Float
 *   HwTrqScalePerf_Cnt_lgc of type Boolean
 * HwTrqTrim_Datatype: Record with elements
 *   HwTrqTrim_Volts_f32 of type Float
 *   T1Trim_Volts_f32 of type Float
 *   T2Trim_Volts_f32 of type Float
 *   HwTrqTrimPerf_Cnt_lgc of type Boolean
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
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Float *Rte_Pim_EOLTrqStepData(void)
#else
 *   EOLTrqStepType *Rte_Pim_EOLTrqStepData(void)
#endif
 *   HwTrqScale_Datatype *Rte_Pim_HwTrqScaleData(void)
 *   HwTrqTrim_Datatype *Rte_Pim_HwTrqTrimData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Init
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
 *   void Rte_IWrite_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(void)
 *   void Rte_IWrite_HwTrq_Init_T1TrimVal_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_T1TrimVal_Volt_f32(void)
 *   void Rte_IWrite_HwTrq_Init_T2TrimVal_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_T2TrimVal_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTrqTrim_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_Init
 *********************************************************************************************************************/


	VAR(boolean, AUTOMATIC) TrqScaleInRng_Cnt_T_lgc;

	/* Torque Trim Calibration Failure Diagnostic */
	(void) Rte_Call_HwTrqTrim_GetErrorStatus(&NvMBlkStatus_Cnt_M_u8);

	if (NVM_REQ_OK != NvMBlkStatus_Cnt_M_u8)
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, 0x02U, NTC_STATUS_FAILED);
	}

	/* Torque Sensor Scaling Out of Range Diagnostic */
	if(TRUE == (Rte_Pim_HwTrqScaleData()->HwTrqScalePerf_Cnt_lgc))
	{
		#if (BC_HWTRQ_SENSRANGCHK == STD_ON) /* range limits are defined by embedded constants */
			TrqScaleInRng_Cnt_T_lgc = IsTrqScaleInRng_lgc(Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);
		#else /* range limits are defined by calibration values */
			TrqScaleInRng_Cnt_T_lgc = IsTrqScaleInRng_CalCheck_lgc(Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);
		#endif

	  	if(FALSE == TrqScaleInRng_Cnt_T_lgc)
	  	{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, 0x01U, NTC_STATUS_FAILED);
			Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = k_HwTrqSclNom_VoltspDeg_f32;
	  	}
	  	else
	  	{
			if (NvMBlkStatus_Cnt_M_u8 == NVM_REQ_OK)
			{
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, 0x00U, NTC_STATUS_PASSED);
			}
	  	}
	}
	else
	{
		Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = k_HwTrqSclNom_VoltspDeg_f32;
	}

	(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorRecoveryFlt, 0x01U, NTC_STATUS_PASSED);

	/* Initialize filter output */
	CorrDiagFiltOut_Volt_M_s4p11 = FPM_Fix_m(CorrDiagFiltSV_Volt_M_s4p27, s4p27_T, s4p11_T);

	Rte_IWrite_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);
	Rte_IWrite_HwTrq_Init_T1TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32);
	Rte_IWrite_HwTrq_Init_T2TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per1
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
 *   UInt8 Rte_IRead_HwTrq_Per1_AbsPosStepSignal_Cnt_u08(void)
 *   Float Rte_IRead_HwTrq_Per1_T1ADC_Volt_f32(void)
 *   Float Rte_IRead_HwTrq_Per1_T2ADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(void)
 *   void Rte_IWrite_HwTrq_Per1_AnaHwTorque_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_AnaHwTorque_HwNm_f32(void)
 *   void Rte_IWrite_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(HwTrqStatusType data)
 *   HwTrqStatusType *Rte_IWriteRef_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(void)
 *   void Rte_IWrite_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(void)
 *   void Rte_IWrite_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_Per1
 *********************************************************************************************************************/


	VAR(uint8,   AUTOMATIC) AbsPosStepSignal_Cnt_T_u08;
	VAR(float32, AUTOMATIC) Torque1_Volt_T_f32;
	VAR(float32, AUTOMATIC) Torque2_Volt_T_f32;
	VAR(float32, AUTOMATIC) DiffHwTorque_Volts_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrqComp_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AnaHwTorque_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) SrlComHwTrqValid_Cnt_T_lgc;
	VAR(HwTrqStatusType, AUTOMATIC) ErrorActiveAnalog_Cnt_T_enum;
	VAR(uint8,   AUTOMATIC) DiagTrqRecvStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagT1OutofRangeStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagT2OutofRangeStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagT1vsT2Status_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagTrqTrimNotPerfStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagTrqTrimInvalidStatus_Cnt_T_u08;


	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_HwTrq_Per1_CP0_CheckpointReached();


	AbsPosStepSignal_Cnt_T_u08 = Rte_IRead_HwTrq_Per1_AbsPosStepSignal_Cnt_u08();
	Torque1_Volt_T_f32 = Rte_IRead_HwTrq_Per1_T1ADC_Volt_f32();
	Torque2_Volt_T_f32 = Rte_IRead_HwTrq_Per1_T2ADC_Volt_f32();

	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_TrqSensorRecoveryFlt, &DiagTrqRecvStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T1OutofRange, &DiagT1OutofRangeStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T2OutofRange, &DiagT2OutofRangeStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T1vsT2, &DiagT1vsT2Status_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_TrqSensorNotTrimmed, &DiagTrqTrimNotPerfStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, &DiagTrqTrimInvalidStatus_Cnt_T_u08);

	AbsPosStepSignal_Cnt_T_u08 = Limit_m(AbsPosStepSignal_Cnt_T_u08, D_ZERO_CNT_U8, D_NUMTRQSTEP_CNT_U08 - 1U);


	/*** Handwheel Torque Calculation ***/

	DiffHwTorque_Volts_T_f32 = (Torque1_Volt_T_f32 - Torque2_Volt_T_f32) - Rte_Pim_HwTrqTrimData()->HwTrqTrim_Volts_f32;

	HwTorque_HwNm_T_f32 = ((DiffHwTorque_Volts_T_f32 * k_TbarStiff_NmpDeg_f32) / Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);

	HwTrqComp_HwNm_T_f32 = HwTorque_HwNm_T_f32 - (*Rte_Pim_EOLTrqStepData())[AbsPosStepSignal_Cnt_T_u08];

	AnaHwTorque_HwNm_T_f32 = Limit_m(HwTrqComp_HwNm_T_f32, D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32);


	/*** Generate Serial Com Valid Output ***/

	if( ((DiagTrqRecvStatus_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		((DiagT1OutofRangeStatus_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		((DiagT2OutofRangeStatus_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		((DiagT1vsT2Status_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		((DiagTrqTrimNotPerfStatus_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		((DiagTrqTrimInvalidStatus_Cnt_T_u08 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) )
	{
		SrlComHwTrqValid_Cnt_T_lgc = TRUE;
	}
	else
	{
		SrlComHwTrqValid_Cnt_T_lgc = FALSE;
	}


	/*** Analog Error Active ***/

	if( ((DiagT1OutofRangeStatus_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) ||
		((DiagT2OutofRangeStatus_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) ||
		((DiagT1vsT2Status_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) )
	{
		ErrorActiveAnalog_Cnt_T_enum = HWTRQSTATUS_FAULT;
	}
	else if( ( (SumFltOut_Volt_M_u5p11 >= k_AnaT1T2ErrThreshold_Volts_u5p11) &&
			   (SumFltOut_Volt_M_u5p11 < k_TdiagLim_Volts_u5p11) ) ||
			 (T1RngErrAcc_Cnt_M_u16 != D_ZERO_CNT_U16) ||
			 (T2RngErrAcc_Cnt_M_u16 != D_ZERO_CNT_U16) )
	{
		ErrorActiveAnalog_Cnt_T_enum = HWTRQSTATUS_ACTIVE;
	}
	else
	{
		ErrorActiveAnalog_Cnt_T_enum = HWTRQSTATUS_NONE;
	}


	AnaDiffHwTrq_Volt_M_f32 = DiffHwTorque_Volts_T_f32;

	#if(STD_ON == BC_HWTRQ_FAULTINJECTIONPOINT)
		Rte_Call_FaultInjection_SCom_FltInjection(&AnaHwTorque_HwNm_T_f32,FLTINJ_ANAHWTORQUE);
	#endif

	AnaHwTorque_HwNm_M_f32 = AnaHwTorque_HwNm_T_f32;
	Rte_IWrite_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(DiffHwTorque_Volts_T_f32);
	Rte_IWrite_HwTrq_Per1_AnaHwTorque_HwNm_f32(AnaHwTorque_HwNm_T_f32);
	Rte_IWrite_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(AnaHwTorque_HwNm_T_f32);
	Rte_IWrite_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(ErrorActiveAnalog_Cnt_T_enum);
	Rte_IWrite_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(SrlComHwTrqValid_Cnt_T_lgc);


	/* Configurable End of Runnable Checkpoint */
	Rte_Call_HwTrq_Per1_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per2
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
 *   Boolean Rte_IRead_HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc(void)
 *   Float Rte_IRead_HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32(void)
 *   Float Rte_IRead_HwTrq_Per2_T1ADC_Volt_f32(void)
 *   Float Rte_IRead_HwTrq_Per2_T2ADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_Per2
 *********************************************************************************************************************/


	VAR(boolean, AUTOMATIC) CntrlDisRampComplete_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SysCHwTorqueSqd_HwNmSq_T_f32;
	VAR(float32, AUTOMATIC) Torque1_Volt_T_f32;
	VAR(float32, AUTOMATIC) Torque2_Volt_T_f32;
	VAR(float32, AUTOMATIC) T1Trim_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2Trim_Volt_T_f32;
	VAR(sint16,  AUTOMATIC) CorrDiagFiltOut_Volt_T_s4p11;
	VAR(sint32,  AUTOMATIC) TDiagFiltSV_Volt_T_s4p27;
	VAR(float32, AUTOMATIC) AnaHwTorque_HwNm_T_f32;

	VAR(float32, AUTOMATIC) TrqSum_Volt_T_f32;
	VAR(float32, AUTOMATIC) AbsTrqSum_Volt_T_f32;
	VAR(uint16,  AUTOMATIC) AbsTrqSum_Volt_T_u5p11;
	VAR(sint16,  AUTOMATIC) TrqSum_Volt_T_s4p11;
	VAR(uint16,  AUTOMATIC) TDiagFiltKn_Cnts_T_u16;
	VAR(sint16,  AUTOMATIC) TDiagFiltOut_Volt_T_s4p11;

	VAR(uint8,   AUTOMATIC) DiagT1OutofRangeStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagT2OutofRangeStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagT1vsT2Status_Cnt_T_u08;

	VAR(float32, AUTOMATIC) SignSysCHwTorque_Uls_T_f32;
	VAR(float32, AUTOMATIC) HwTorqCorrLimDiff_HwNm_T_f32;
	VAR(float32, AUTOMATIC) SysCHwTorque_HwNm_T_f32;

	/* Configurable Start of Runnable Checkpoint */
	(void) Rte_Call_HwTrq_Per2_CP0_CheckpointReached();


	CntrlDisRampComplete_Cnt_T_lgc = Rte_IRead_HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc();
	SysCHwTorqueSqd_HwNmSq_T_f32 = Rte_IRead_HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32();
	Torque1_Volt_T_f32 = Rte_IRead_HwTrq_Per2_T1ADC_Volt_f32();
	Torque2_Volt_T_f32 = Rte_IRead_HwTrq_Per2_T2ADC_Volt_f32();
	T1Trim_Volt_T_f32 = Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32;
	T2Trim_Volt_T_f32 = Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32;
	CorrDiagFiltOut_Volt_T_s4p11 = CorrDiagFiltOut_Volt_M_s4p11;
	TDiagFiltSV_Volt_T_s4p27 = TDiagFiltSV_Volt_M_s4p27;
	AnaHwTorque_HwNm_T_f32 = AnaHwTorque_HwNm_M_f32;


	/*** T1 out of Range Diagnostic ***/

	if ( (Torque1_Volt_T_f32 < k_T1LowRange_Volts_f32) ||
		 (Torque1_Volt_T_f32 > k_T1HghRange_Volts_f32) )
	{
		T1RngErrAcc_Cnt_M_u16 = DiagPStep_m(T1RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str);

		if ( DiagFailed_m(T1RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str) == TRUE )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		T1RngErrAcc_Cnt_M_u16 = DiagNStep_m(T1RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str);
	}


	/*** T2 out of Range Diagnostic ***/

	if ( (Torque2_Volt_T_f32 < k_T2LowRange_Volts_f32) ||
		 (Torque2_Volt_T_f32 > k_T2HghRange_Volts_f32) )
	{
		T2RngErrAcc_Cnt_M_u16 = DiagPStep_m(T2RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str);

		if ( DiagFailed_m(T2RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str) == TRUE )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		T2RngErrAcc_Cnt_M_u16 = DiagNStep_m(T2RngErrAcc_Cnt_M_u16, k_AnaRngDiag_Cnt_str);
	}


	/*** T1 vs T2 Comparison Diagnostic ***/

	TrqSum_Volt_T_f32 = (Torque1_Volt_T_f32 - T1Trim_Volt_T_f32) +
						 (Torque2_Volt_T_f32 - T2Trim_Volt_T_f32);

	if ( TrqSum_Volt_T_f32 >= k_MaxTrqSumLmt_Volts_f32 )
	{
		 TrqSum_Volt_T_f32 = k_MaxTrqSumLmt_Volts_f32;
	}
	else
	{
		if( TrqSum_Volt_T_f32 <= (-1.0F * k_MaxTrqSumLmt_Volts_f32) )
		{
			TrqSum_Volt_T_f32 = (-1.0F * k_MaxTrqSumLmt_Volts_f32);
		}
	}

	AbsTrqSum_Volt_T_f32 = Abs_f32_m(TrqSum_Volt_T_f32);
	AbsTrqSum_Volt_T_u5p11 = FPM_FloatToFixed_m(AbsTrqSum_Volt_T_f32, u5p11_T);

	TrqSum_Volt_T_s4p11 = FPM_FloatToFixed_m(TrqSum_Volt_T_f32, s4p11_T);

	TDiagFiltKn_Cnts_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(
									t_TDiagIndptTbl_Volts_u5p11,
									t_TDiagFiltKnTbl_Cnt_u16,
									TableSize_m(t_TDiagIndptTbl_Volts_u5p11),
									AbsTrqSum_Volt_T_u5p11);

	TDiagFiltSV_Volt_T_s4p27 = LPF_SvUpdate_s16InFixKTrunc_m (
								  TrqSum_Volt_T_s4p11,
								  TDiagFiltSV_Volt_T_s4p27,
								  TDiagFiltKn_Cnts_T_u16);

	TDiagFiltSV_Volt_M_s4p27 = TDiagFiltSV_Volt_T_s4p27;

	TDiagFiltOut_Volt_T_s4p11 = LPF_OpUpdate_s16InFixKTrunc_m (
								 TDiagFiltSV_Volt_T_s4p27);

	/* Fault Detection */
	CorrDiagFiltOut_Volt_T_s4p11 = Limit_m(CorrDiagFiltOut_Volt_T_s4p11,
									(-1*(sint16)k_TdiagCorrLim_Volts_u5p11),
									(sint16)k_TdiagCorrLim_Volts_u5p11);

	SumFltOut_Volt_M_u5p11 = Abs_s16_m(TDiagFiltOut_Volt_T_s4p11 - CorrDiagFiltOut_Volt_T_s4p11);


	if ( (SumFltOut_Volt_M_u5p11 > k_TdiagLim_Volts_u5p11) ||
		 ((Abs_s16_m(SSDiagFiltOut_Volt_M_s4p11)) > k_SSDiagLim_Volts_u5p11) )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1vsT2, 0x01U, NTC_STATUS_FAILED);
	}


	/* Torque Sensor Recovery Diagnostic */

	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T1OutofRange, &DiagT1OutofRangeStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T2OutofRange, &DiagT2OutofRangeStatus_Cnt_T_u08);
	(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_T1vsT2, &DiagT1vsT2Status_Cnt_T_u08);

	if( ((DiagT1OutofRangeStatus_Cnt_T_u08 & D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) == D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) &&
		(T1RngErrAcc_Cnt_M_u16 == 0U) )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0x01U, NTC_STATUS_PASSED);
		DiagT1OutofRangeStatus_Cnt_T_u08 = 0U;
	}

	if( ((DiagT2OutofRangeStatus_Cnt_T_u08 & D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) == D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) &&
		(T2RngErrAcc_Cnt_M_u16 == 0U) )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0x01U, NTC_STATUS_PASSED);
		DiagT2OutofRangeStatus_Cnt_T_u08 = 0U;
	}

	if( ((DiagT1vsT2Status_Cnt_T_u08 & D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) == D_TESTNOTCOMPLETEDTHISOPCYCLE_CNT_U08) &&
		(SumFltOut_Volt_M_u5p11 < k_SumFiltRecLim_Volt_u5p11) &&
		(((uint16)(Abs_s16_m(SSDiagFiltOut_Volt_M_s4p11))) < k_SSFiltRecLim_Volt_u5p11) )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1vsT2, 0x01U, NTC_STATUS_PASSED);
		DiagT1vsT2Status_Cnt_T_u08 = 0U;
	}


	if( (CntrlDisRampComplete_Cnt_T_lgc == TRUE) &&
		( ((DiagT1OutofRangeStatus_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) ||
		  ((DiagT2OutofRangeStatus_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) ||
		  ((DiagT1vsT2Status_Cnt_T_u08 & D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) == D_FAILEDANDFAILEDTHISOPCYCLE_CNT_U08) ) )
	{
		if( TrqSensorRecDiagAcc_Cnt_M_u16 >= k_TrqFltRecLim_Cnt_u16 )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorRecoveryFlt, 0x01U, NTC_STATUS_FAILED);
		}
		else
		{
			if( (T1RngErrAcc_Cnt_M_u16 < k_T1AccRecLim_Cnt_u16) &&
				(T2RngErrAcc_Cnt_M_u16 < k_T2AccRecLim_Cnt_u16) &&
				(SumFltOut_Volt_M_u5p11 < k_SumFiltRecLim_Volt_u5p11) &&
				(((uint16)(Abs_s16_m(SSDiagFiltOut_Volt_M_s4p11))) < k_SSFiltRecLim_Volt_u5p11) )
			{
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0x01U, NTC_STATUS_PASSED);
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0x01U, NTC_STATUS_PASSED);
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1vsT2, 0x01U, NTC_STATUS_PASSED);
				TrqSensorRecDiagAcc_Cnt_M_u16++;
			}
		}
	}


	/*** Hw Diff Torque Cross Check ***/

	SignSysCHwTorque_Uls_T_f32 =  (float32) (Sign_f32_m(SysCHwTorqueSqd_HwNmSq_T_f32));

	/* Calculate the SysC_HwTorque using the square root of absolute value and  include the sign of the HwNmSq*/
	SysCHwTorque_HwNm_T_f32 = (sqrtf(Abs_f32_m(SysCHwTorqueSqd_HwNmSq_T_f32))) * SignSysCHwTorque_Uls_T_f32 ;
	/*Display variable to channel 1*/
	SysCHwTorqueCh1_HwNm_D_f32 =SysCHwTorque_HwNm_T_f32;

	/*Absolute value of difference between Analog Handwheel and Sys_Hw_Torque */
	HwTorqCorrLimDiff_HwNm_T_f32 = Abs_f32_m( AnaHwTorque_HwNm_T_f32 - SysCHwTorque_HwNm_T_f32 ) ;

	/*Fault Determination using Lim threshold Cal for HwTorq_CorrLimDiff*/
	if( HwTorqCorrLimDiff_HwNm_T_f32 >= k_HwTorqCorrLimThresh_HwNm_T_f32 )
	{
		HwTorqCorrLimErrAcc_Cnt_M_u16 = DiagPStep_m(HwTorqCorrLimErrAcc_Cnt_M_u16, k_HwTorqCorrLimDiag_Cnt_str);

		if( DiagFailed_m(HwTorqCorrLimErrAcc_Cnt_M_u16, k_HwTorqCorrLimDiag_Cnt_str) == TRUE )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SysFailureForTrqSnsr, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		HwTorqCorrLimErrAcc_Cnt_M_u16 = DiagNStep_m(HwTorqCorrLimErrAcc_Cnt_M_u16, k_HwTorqCorrLimDiag_Cnt_str);

		if( HwTorqCorrLimErrAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SysFailureForTrqSnsr, 0x00U, NTC_STATUS_PASSED);
		}
	}



	CorrDiagFiltOut_Volt_M_s4p11 = CorrDiagFiltOut_Volt_T_s4p11;
	TrqSum_Volt_M_s4p11 = TrqSum_Volt_T_s4p11;
	TDiagFiltOut_Volt_M_s4p11 = TDiagFiltOut_Volt_T_s4p11;

	/*Display variable for HwTorq_CorrLimDiff */
	HWTorqCorrLimDiff_HwNm_D_f32 = HwTorqCorrLimDiff_HwNm_T_f32;



	/* Configurable End of Runnable Checkpoint */
	Rte_Call_HwTrq_Per2_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_HwTrq_Per3_MECCounter_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_Per3
 *********************************************************************************************************************/


	VAR(sint16,  AUTOMATIC) TrqSum_Volt_T_s4p11;
	VAR(sint16,  AUTOMATIC) TDiagFiltOut_Volt_T_s4p11;
	VAR(sint16,  AUTOMATIC) CorrDiagFiltOut_Volt_T_s4p11;
	VAR(sint32,  AUTOMATIC) SSDiagFiltSV_Volt_T_s4p27;
	VAR(float32, AUTOMATIC) HwTrqComp_Volt_T_f32;
	VAR(uint16,  AUTOMATIC) HwTrqComp_Volt_T_u5p11;
	VAR(sint32,  AUTOMATIC) CorrDiagFiltSV_Volt_T_s4p27;
	VAR(ManufModeType, AUTOMATIC) MECCounter_Cnt_T_enum;


	/* Configurable Start of Runnable Checkpoint */
	(void) Rte_Call_HwTrq_Per3_CP0_CheckpointReached();

	MECCounter_Cnt_T_enum = Rte_IRead_HwTrq_Per3_MECCounter_Cnt_enum();

	TDiagFiltOut_Volt_T_s4p11 = TDiagFiltOut_Volt_M_s4p11;
	TrqSum_Volt_T_s4p11 = TrqSum_Volt_M_s4p11;
	CorrDiagFiltOut_Volt_T_s4p11 = CorrDiagFiltOut_Volt_M_s4p11;
	SSDiagFiltSV_Volt_T_s4p27 = SSDiagFiltSV_Volt_M_s4p27;
	HwTrqComp_Volt_T_f32 = AnaDiffHwTrq_Volt_M_f32;
	CorrDiagFiltSV_Volt_T_s4p27 = CorrDiagFiltSV_Volt_M_s4p27;


	/* Steady State Fault Detection */
	SSDiagFiltSV_Volt_T_s4p27 = LPF_SvUpdate_s16InFixKTrunc_m (
								  TDiagFiltOut_Volt_T_s4p11,
								  SSDiagFiltSV_Volt_T_s4p27,
								  k_SSDiagKn_Cnts_u16);

	SSDiagFiltSV_Volt_T_s4p27 = Limit_m(SSDiagFiltSV_Volt_T_s4p27,
									-D_SSDIAGNFILTSVLMT_VOLT_S4P27,
									D_SSDIAGNFILTSVLMT_VOLT_S4P27);

	SSDiagFiltSV_Volt_M_s4p27 = SSDiagFiltSV_Volt_T_s4p27;

	SSDiagFiltOut_Volt_M_s4p11 = LPF_OpUpdate_s16InFixKTrunc_m (
								   SSDiagFiltSV_Volt_T_s4p27);


	/* Common Mode Compensation Function */
	HwTrqComp_Volt_T_f32 = Abs_f32_m(HwTrqComp_Volt_T_f32);
	HwTrqComp_Volt_T_u5p11 = FPM_FloatToFixed_m(HwTrqComp_Volt_T_f32, u5p11_T);

	if ( HwTrqComp_Volt_T_u5p11 < k_CorrDiagFiltActiv_Volts_u5p11 )
	{
		CorrDiagFiltSV_Volt_T_s4p27 = LPF_SvUpdate_s16InFixKTrunc_m (
									   TrqSum_Volt_T_s4p11,
									   CorrDiagFiltSV_Volt_T_s4p27,
									   k_CorrDiagKn_Cnts_u16);

		CorrDiagFiltSV_Volt_M_s4p27 = CorrDiagFiltSV_Volt_T_s4p27;

		CorrDiagFiltOut_Volt_T_s4p11 = LPF_OpUpdate_s16InFixKTrunc_m (
									   CorrDiagFiltSV_Volt_T_s4p27);

	}

	CorrDiagFiltOut_Volt_M_s4p11 = CorrDiagFiltOut_Volt_T_s4p11;


	/* Torque Trim Performed Check */
	if((FALSE == Rte_Pim_HwTrqTrimData()->HwTrqTrimPerf_Cnt_lgc) && (ManufacturingMode != MECCounter_Cnt_T_enum))
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorNotTrimmed, 0x01U, NTC_STATUS_FAILED);
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorNotTrimmed, 0x01U, NTC_STATUS_PASSED);
	}

	/* Torque Scale Performed Check */
	if((FALSE == Rte_Pim_HwTrqScaleData()->HwTrqScalePerf_Cnt_lgc) && (ManufacturingMode != MECCounter_Cnt_T_enum))
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorScaleNotSet, 0x01U, NTC_STATUS_FAILED);
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorScaleNotSet, 0x01U, NTC_STATUS_PASSED);
	}


	/* Configurable End of Runnable Checkpoint */
	Rte_Call_HwTrq_Per3_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ClrHwTrqScale(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ClrHwTrqScale (returns application error)
 *********************************************************************************************************************/
	VAR(Std_ReturnType, AUTOMATIC) RetCode;

	Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = k_HwTrqSclNom_VoltspDeg_f32;
	Rte_Pim_HwTrqScaleData()->HwTrqScalePerf_Cnt_lgc = FALSE;

	if (NvMBlkStatus_Cnt_M_u8 == NVM_REQ_OK)
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, 0x00U, NTC_STATUS_PASSED);
	}

	(void) Rte_Call_HwTrqScale_WriteBlock(NULL_PTR);
	RetCode = RTE_E_OK;

	(void) Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ClrHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ClrHwTrqTrim (returns application error)
 *********************************************************************************************************************/

	VAR(Std_ReturnType, AUTOMATIC) RetCode;

	Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32 = D_DFLTRTRQTRIM_VOLT_F32;
	Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32 = D_DFLTRTRQTRIM_VOLT_F32;

	Rte_Pim_HwTrqTrimData()->HwTrqTrim_Volts_f32 = 0.0F;
	Rte_Pim_HwTrqTrimData()->HwTrqTrimPerf_Cnt_lgc = FALSE;

	(void) Rte_Call_HwTrqTrim_WriteBlock(NULL_PTR);
	RetCode = RTE_E_OK;

	(void) Rte_Write_T1TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32);
	(void) Rte_Write_T2TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32);

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ManualSetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualSetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ManualSetHwTrqTrim(const HwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ManualSetHwTrqTrim (returns application error)
 *********************************************************************************************************************/

	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(float32, AUTOMATIC) HwTrqTrim_Volt_T_f32;

	HwTrqTrim_Volt_T_f32 = (float32)((HwTrqTrimDataPtr->T1Trim_Volts_f32) - (HwTrqTrimDataPtr->T2Trim_Volts_f32));

	if ((Abs_f32_m(HwTrqTrim_Volt_T_f32)) <= k_MaxHwTrqTrim_Volts_f32)
	{
		Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32 = (float32)HwTrqTrimDataPtr->T1Trim_Volts_f32;
		Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32 = (float32)HwTrqTrimDataPtr->T2Trim_Volts_f32;
		Rte_Pim_HwTrqTrimData()->HwTrqTrim_Volts_f32 = HwTrqTrim_Volt_T_f32;
		Rte_Pim_HwTrqTrimData()->HwTrqTrimPerf_Cnt_lgc = (boolean)HwTrqTrimDataPtr->HwTrqTrimPerf_Cnt_lgc;

		(void) Rte_Call_HwTrqTrim_WriteBlock(NULL_PTR);
		RetCode = RTE_E_OK;
	}
	else
	{
		RetCode = RTE_E_HwTrq_SCom_ConditionsNotCorrect;
	}

	(void) Rte_Write_T1TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32);
	(void) Rte_Write_T2TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32);

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadEOLTrqStep
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadEOLTrqStep> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void HwTrq_SCom_ReadEOLTrqStep(Float *TrqStep_HwNm_T_f32)
#else
 *   void HwTrq_SCom_ReadEOLTrqStep(EOLTrqStepType *TrqStep_HwNm_T_f32)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32)
#else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ReadEOLTrqStep
 *********************************************************************************************************************/


	VAR(uint16, AUTOMATIC) i;

	for( i = 0U; i < D_NUMTRQSTEP_CNT_U08; i++ )
	{
		(*TrqStep_HwNm_T_f32)[i] = (*Rte_Pim_EOLTrqStepData())[i];
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrq_SCom_ReadHwTrqScale(HwTrqScale_Datatype *HwTrqScaleDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ReadHwTrqScale
 *********************************************************************************************************************/

	*HwTrqScaleDataPtr = *Rte_Pim_HwTrqScaleData();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrq_SCom_ReadHwTrqTrim(HwTrqTrim_Datatype *HwTrqTrimDatPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_ReadHwTrqTrim
 *********************************************************************************************************************/

	*HwTrqTrimDatPtr = *Rte_Pim_HwTrqTrimData();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetEOLTrqStep
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLTrqStep> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTrqStep_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLTrqStep_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void HwTrq_SCom_SetEOLTrqStep(const Float *TrqStep_HwNm_T_f32)
#else
 *   void HwTrq_SCom_SetEOLTrqStep(const EOLTrqStepType *TrqStep_HwNm_T_f32)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32)
#else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_SetEOLTrqStep
 *********************************************************************************************************************/


	VAR(uint16, AUTOMATIC) i;

	for( i = 0U; i < D_NUMTRQSTEP_CNT_U08; i++ )
	{
		(*Rte_Pim_EOLTrqStepData())[i] = (*TrqStep_HwNm_T_f32)[i];
	}

	(void) Rte_Call_EOLTrqStep_WriteBlock(NULL_PTR);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_SetHwTrqScale (returns application error)
 *********************************************************************************************************************/
	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(boolean, AUTOMATIC) TrqScaleInRng_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) NewTrqScale_VoltpDeg_f32;

	NewTrqScale_VoltpDeg_f32 = ScaleValue;

#if (BC_HWTRQ_SENSRANGCHK == STD_ON) /* range limits are defined by embedded constants */
	TrqScaleInRng_Cnt_T_lgc = IsTrqScaleInRng_lgc(NewTrqScale_VoltpDeg_f32);
#else /* range limits are defined by calibration values */
	TrqScaleInRng_Cnt_T_lgc = IsTrqScaleInRng_CalCheck_lgc(NewTrqScale_VoltpDeg_f32);
#endif

	if (TRUE == TrqScaleInRng_Cnt_T_lgc)
	{
		Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = NewTrqScale_VoltpDeg_f32;
		Rte_Pim_HwTrqScaleData()->HwTrqScalePerf_Cnt_lgc = TRUE;

		if (NvMBlkStatus_Cnt_M_u8 == NVM_REQ_OK)
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriSnsrTrqStorFlt, 0x00U, NTC_STATUS_PASSED);
		}

		(void) Rte_Call_HwTrqScale_WriteBlock(NULL_PTR);
		RetCode = RTE_E_OK;
	}
	else
	{
		RetCode = RTE_E_HwTrq_SCom_ConditionsNotCorrect;
	}

	(void) Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Rte_Pim_HwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32);

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_T1ADC_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_T2ADC_Volt_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_SetHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTrq_SCom_SetHwTrqTrim (returns application error)
 *********************************************************************************************************************/
	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(float32, AUTOMATIC) Torque1_Volt_T_f32;
	VAR(float32, AUTOMATIC) Torque2_Volt_T_f32;
	VAR(float32, AUTOMATIC) HwTrqTrim_Volt_T_f32 = 0.0F;

	(void) Rte_Read_T1ADC_Volt_f32(&Torque1_Volt_T_f32);
	(void) Rte_Read_T2ADC_Volt_f32(&Torque2_Volt_T_f32);

	HwTrqTrim_Volt_T_f32 = Torque1_Volt_T_f32 - Torque2_Volt_T_f32;

	if ((Abs_f32_m(HwTrqTrim_Volt_T_f32)) <= k_MaxHwTrqTrim_Volts_f32)
	{
		Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32 = Torque1_Volt_T_f32;
		Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32 = Torque2_Volt_T_f32;

		Rte_Pim_HwTrqTrimData()->HwTrqTrim_Volts_f32 = HwTrqTrim_Volt_T_f32;
		Rte_Pim_HwTrqTrimData()->HwTrqTrimPerf_Cnt_lgc = TRUE;

		(void) Rte_Call_HwTrqTrim_WriteBlock(NULL_PTR);
		RetCode = RTE_E_OK;
	}
	else
	{
		RetCode = RTE_E_HwTrq_SCom_ConditionsNotCorrect;
	}

	(void) Rte_Write_T1TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T1Trim_Volts_f32);
	(void) Rte_Write_T2TrimVal_Volt_f32(Rte_Pim_HwTrqTrimData()->T2Trim_Volts_f32);

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
  * Name:        IsTrqScaleInRng_lgc
  * Description: Range Validity Check for Torque Scale EOL value
  * Inputs:      TrqScale_VltspDeg_f32
  * Outputs:     TrqSclInRng_Cnt_T_lgc
  ****************************************************************************/
STATIC FUNC(boolean, SA_HWTRQ_CODE) IsTrqScaleInRng_lgc(VAR(float32, AUTOMATIC)TrqScale_VoltpDeg_T_f32)
{
	VAR(boolean, AUTOMATIC) TrqSclInRng_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Limit_VoltpDeg_T_f32;

	Limit_VoltpDeg_T_f32 = k_HwTrqSclNom_VoltspDeg_f32 * D_TRQSCALEWNDW_ULS_F32;

	if( (TrqScale_VoltpDeg_T_f32 >= (k_HwTrqSclNom_VoltspDeg_f32 - Limit_VoltpDeg_T_f32)) &&
		(TrqScale_VoltpDeg_T_f32 <= (k_HwTrqSclNom_VoltspDeg_f32 + Limit_VoltpDeg_T_f32)))
	{
		TrqSclInRng_Cnt_T_lgc = TRUE;
	}
	else
	{
		TrqSclInRng_Cnt_T_lgc = FALSE;
	}

	return(TrqSclInRng_Cnt_T_lgc);
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
  * Name:        IsTrqScaleInRng_CalCheck_lgc
  * Description: Range Validity Check using Calibration for Torque Scale EOL value
  * Inputs:      TrqScale_VltspDeg_f32
  * Outputs:     TrqSclInRng_Cnt_T_lgc
  ****************************************************************************/
STATIC FUNC(boolean, SA_HWTRQ_CODE) IsTrqScaleInRng_CalCheck_lgc(VAR(float32, AUTOMATIC)TrqScale_VoltpDeg_T_f32)
{
    VAR(boolean, AUTOMATIC) TrqSclInRngCalChk_Cnt_T_lgc;

    if( (TrqScale_VoltpDeg_T_f32 >= k_TrqSensScaleMin_VoltspDeg_f32) &&
		(TrqScale_VoltpDeg_T_f32 <= k_TrqSensScaleMax_VoltspDeg_f32) )
    {
    	TrqSclInRngCalChk_Cnt_T_lgc = TRUE;
    }
    else
    {
    	TrqSclInRngCalChk_Cnt_T_lgc = FALSE;
    }

    return(TrqSclInRngCalChk_Cnt_T_lgc);
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
