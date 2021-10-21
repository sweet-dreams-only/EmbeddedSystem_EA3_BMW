/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DemIf.c
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_I501/BMW_UKL_MCV_EPS_TMS570/SwProject/DemIf/autosar/Ap_DemIf.dcf
 *     SW-C Type:  Ap_DemIf
 *  Generated at:  Wed May 29 17:52:44 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DemIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Jun 06 19:43:01 2011
 * %version:          16 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Wed May 29 18:40:28 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/06/11   1        JJW       Initial Version
 * 06/06/11   3        JJW       Correction of voltage masking
 * 01/18/11   5  	   BDO       Updates for Engine Cranks DTC masking and Undervoltage DTC mapping
 * 01/18/11   6        BDO       New NTC numbers - NTC_Num_ExVoltageLow, NTC_Num_ReducedAsstLowVoltage, NTC_Num_ExVoltageHigh
 * 03/23/12   7        BDO       Anomaly 2776 - Re-enable DEM COM DTCs only on CRANK state transition from ACTIVE to INACTIVE
 * 04/25/12   8        BDO       Anomaly 3180, 3203 - Remove Dem_DisableEventStatus() and Dem_EnableStatusUpdate() APIs and SrlComEngCrank_Cnt_M_lgc state variable
 * 03/21/13   10       NRAR      Removed NTC's B1,B4 and updated with B0,B5 as per BVDiag for Anom 4413 and QAC fixes
 * 05/30/13   11       KJS       Added non-trusted function call for DiagMgr_StaCtrl_Shutdown
 * 06/04/14   12       KJS       Added support for Edch interaction with the Dem
 * 06/12/14   13       KJS       A6880 correction where transition function will enable OBD cycle for the Dem as well as the default cycle.
 * 08/26/14   14       KJS       A6959 correction for checking event handled status before checking OBD rel. faults.
 * 04/14/15   15       KJS       Added fault masking for DTCs FR_PHYS_FAILURE and FR_COMM_FAILURE during crank
 * 07/23/15   16       ABS       Added suspend/resume API in Ap_DemIf
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
  ST_ILK_ERRM_FZM
    Automatisch generiert (Migration 2004-10-30)
     
 *********************************************************************************************************************/

#include "Rte_Ap_DemIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "Dem.h"
#include "Ap_DemIf_NxtrAddon.h"
#include "ti_fee.h"

/* Module constants for bits in CTR_ERRM_BN_U since the global bit constants are all incorrectly set to 0 */
#define D_UVNORMMASK_CNT_U08    1U
#define D_UVSTARTMASK_CNT_U08   2U
#define D_OVMASK_CNT_U08        4U

#define D_NETWORKMASK_CNT_U08   1U
#define D_VASTREDMASK_CNT_U08   2U


/* Local Function Prototypes */
STATIC FUNC(boolean, AP_DEMIF_CODE) GlblVNetworkDtcs( VAR(Dem_EventIdType, AUTOMATIC)EventId);
STATIC FUNC(boolean, AP_DEMIF_CODE) RedAssistIsolation( VAR(Dem_EventIdType, AUTOMATIC)EventId);

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
 * NTCNumber: Integer in interval [0...511]
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CTR_ERRM_BN_U: Enumeration of integer in interval [0...63] with enumerators
 *   Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
 *   Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
 *   Cb0xxx1x_Unterspannung_MSA_Start (0U)
 *   Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
 *   Cb0xx1xx_Ueberspannung (0U)
 *   Cb0xx0xx_Keine_Ueberspannung (0U)
 *   Cx3D_nicht_verfuegbar (61U)
 *   Cx3E_Fehler (62U)
 *   Cx3F_Signal_ungueltig (63U)
 * Dem_OperationCycleIdType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_OPCYCLE_DEFAULT (0U)
 *   DEM_OPCYCLE_VSM_OPMODE (1U)
 *   BUS_ACTIVE (2U)
 * Dem_OperationCycleStateType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_CYCLE_STATE_START (1U)
 *   DEM_CYCLE_STATE_END (2U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * NxtrOpCycle: Enumeration of integer in interval [0...0] with enumerators
 *   NxtrDefaultOpCycle (0U)
 * NxtrOpCycleState: Enumeration of integer in interval [1...2] with enumerators
 *   NXTR_CYCLE_STATE_START (1U)
 *   NXTR_CYCLE_STATE_END (2U)
 * ST_ILK_ERRM_FZM: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Fehlerspeicherfreigabe (0U)
 *   Cx1_Fehlerspeichersperre (1U)
 *   Cx2_Reserve (2U)
 *   Cx3_Signal_ungueltig (3U)
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
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */



/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_RestartDem
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestartDem> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_RestartDem(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_RestartDem
 *********************************************************************************************************************/
	/* Added Suspend and resume erase to allow NvM read without any interruption from Nvm erase */
	TWrapC_TI_Fee_SuspendResumeErase(Suspend_Erase);
	Dem_Init();
	TWrapC_TI_Fee_SuspendResumeErase(Resume_Erase);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetEventStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEventStatus> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ErrmBnU_Cnt_u8(CTR_ERRM_BN_U *data)
 *   Std_ReturnType Rte_Read_IlkErrmFzm_Cnt_u8(ST_ILK_ERRM_FZM *data)
 *   Std_ReturnType Rte_Read_SrlComEngCrank_Cnt_lgc(Boolean *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemIf_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetEventStatus (returns application error)
 *********************************************************************************************************************/
	VAR(CTR_ERRM_BN_U, AUTOMATIC)    CtrErrmBnU_Cnt_T_u08;
	VAR(boolean, AUTOMATIC)          EventHandled_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC)          EngCrankActive_Cnt_T_lgc = FALSE;
	VAR(uint8, AUTOMATIC) Idx_Cnt_T_u8;

	(void)Rte_Read_ErrmBnU_Cnt_u8(&CtrErrmBnU_Cnt_T_u08);
	(void)Rte_Read_SrlComEngCrank_Cnt_lgc(&EngCrankActive_Cnt_T_lgc);

	if (EngCrankActive_Cnt_T_lgc == TRUE)
	{   /* MASK VOLTAGE DTCS MAPPED TO LOCAL OV, UV, LVASSTRED WHEN IN CRANK */
		if ( (DEM_EVENT_STATUS_FAILED == EventStatus) &&
			 ((EventId == BATTHIGH) || (EventId == LOW_VOLT_LARGE_ASST_RED) || (EventId == FR_PHYS_FAILURE) || (EventId == FR_COMM_FAILURE)) )
		{
			EventHandled_Cnt_T_lgc = TRUE; 
		}
	}
	else
	{	/* HANDLE NORMAL GLOBAL VOLTAGE MASKING */
		if(DEM_EVENT_STATUS_FAILED == EventStatus)
		{	
		    EventHandled_Cnt_T_lgc = GlblVNetworkDtcs(EventId);
			
			if(FALSE == EventHandled_Cnt_T_lgc)
			{
				EventHandled_Cnt_T_lgc = RedAssistIsolation(EventId);
			}
		}
	}
	
	if(FALSE == EventHandled_Cnt_T_lgc)
	{
		/* Check if fault is EDCH (OBD) relevant, if so send request to Edch */
		for (Idx_Cnt_T_u8 = 0U; Idx_Cnt_T_u8 < D_NUMOFEDCHDIAG_CNT_U8; Idx_Cnt_T_u8++)
		{
			if(t_EdchRelDiagTbl_str[Idx_Cnt_T_u8].DEMEventId == EventId)
			{
				(void)t_EdchRelDiagTbl_str[Idx_Cnt_T_u8].func(Idx_Cnt_T_u8, EventStatus);
				EventHandled_Cnt_T_lgc = TRUE; /* Set event as handled */
			}
		}

		if(FALSE == EventHandled_Cnt_T_lgc) /* Handle all unhandled events by directly passing to Dem */
		{
			(void)Dem_SetEventStatus(EventId, EventStatus);
		}
	}

	/* TODO:  Determine the correct way to handle the pass for the gobal faults, */
	/*Recovery Conditions For Global Under/OverVoltage */
	if(0U == (CtrErrmBnU_Cnt_T_u08 & D_OVMASK_CNT_U08))
	{
		(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_SURGE, DEM_EVENT_STATUS_PASSED);
	}
	
	if(0U == (CtrErrmBnU_Cnt_T_u08 & (D_UVSTARTMASK_CNT_U08 | D_UVNORMMASK_CNT_U08)))
	{
		(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_UNDVOLT, DEM_EVENT_STATUS_PASSED);
	}

	  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_OperationCycle_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetOperationCycleState
 *********************************************************************************************************************/
	
	(void)Dem_SetOperationCycleState(NxtrOperationCycleId, NxtrCycleState);
	/* Added the call below to enable the OBD diagnostics per A6880 */
	(void)Dem_SetOperationCycleState(OBD_CYCLE, NxtrCycleState);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Shutdown
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DemShutdown> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_Shutdown(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Shutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_Shutdown
 *********************************************************************************************************************/
	Dem_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC FUNC(boolean, AP_DEMIF_CODE) GlblVNetworkDtcs( VAR(Dem_EventIdType, AUTOMATIC) EventId)
{
	CTR_ERRM_BN_U    CtrErrmBnU_Cnt_T_u08;
	boolean          EventHandled_Cnt_T_lgc = FALSE;
	
	(void)Rte_Read_ErrmBnU_Cnt_u8(&CtrErrmBnU_Cnt_T_u08);
	
	/*Nxtr ID :  [BMW-SER-SW-17211-4A] - Start*/
	if(0U != (D_NETWORKMASK_CNT_U08 & t_DtcMaskEnbl_Cnt_u08[EventId]))
	{
		if(0U != (D_OVMASK_CNT_U08 & CtrErrmBnU_Cnt_T_u08))
		{
			(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_SURGE, DEM_EVENT_STATUS_FAILED);
			EventHandled_Cnt_T_lgc = TRUE;
		}
		else if(0U != (CtrErrmBnU_Cnt_T_u08 & (D_UVSTARTMASK_CNT_U08 | D_UVNORMMASK_CNT_U08)))
		{
			(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_UNDVOLT, DEM_EVENT_STATUS_FAILED);
			EventHandled_Cnt_T_lgc = TRUE;
		}
		else
		{
			EventHandled_Cnt_T_lgc = FALSE;
		}
	}
	return EventHandled_Cnt_T_lgc;
	/*Nxtr ID :  [BMW-SER-SW-17211-4A] - End*/	
}

STATIC FUNC(boolean, AP_DEMIF_CODE) RedAssistIsolation( VAR(Dem_EventIdType, AUTOMATIC) EventId)
{
	CTR_ERRM_BN_U    CtrErrmBnU_Cnt_T_u08;
	boolean          EventHandled_Cnt_T_lgc = FALSE;
	boolean          LocalOvFailed_Cnt_T_lgc;
	boolean          LocalLgUvFailed_Cnt_T_lgc;
	boolean          LocalSmUvFailed_Cnt_T_lgc;
	
	(void)Rte_Read_ErrmBnU_Cnt_u8(&CtrErrmBnU_Cnt_T_u08);

	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_OpVoltageOvrMax, &LocalOvFailed_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_OpVoltage, &LocalLgUvFailed_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_ReducedAsstLowVoltage, &LocalSmUvFailed_Cnt_T_lgc);
		
	/*Perform Assist Reduction Due to Voltage Isolation*/
	if(0U != (D_VASTREDMASK_CNT_U08 & t_DtcMaskEnbl_Cnt_u08[EventId]))
	{
		if(TRUE == LocalOvFailed_Cnt_T_lgc)
		{
			if(0U != (D_OVMASK_CNT_U08 & CtrErrmBnU_Cnt_T_u08))
			{
				(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_SURGE, DEM_EVENT_STATUS_FAILED);
				EventHandled_Cnt_T_lgc = TRUE;
			}
			else
			{
				/*TODO: Use fault response table lookup to find claibrated event ID*/
				(void)Dem_SetEventStatus(BATTHIGH, DEM_EVENT_STATUS_FAILED);
				EventHandled_Cnt_T_lgc = TRUE;
			}
		}
		else if((TRUE == LocalSmUvFailed_Cnt_T_lgc) || (TRUE == LocalLgUvFailed_Cnt_T_lgc))
		{
			if(0U != (CtrErrmBnU_Cnt_T_u08 & (D_UVSTARTMASK_CNT_U08 | D_UVNORMMASK_CNT_U08)))
			{
				(void)Dem_SetEventStatus(PWRSPLY_GLOBAL_UNDVOLT, DEM_EVENT_STATUS_FAILED);
				EventHandled_Cnt_T_lgc = TRUE;
			}
			else
			{
			    /*TODO: Use fault response table lookup to find claibrated event ID*/
				(void)Dem_SetEventStatus(LOW_VOLT_LARGE_ASST_RED, DEM_EVENT_STATUS_FAILED);
				EventHandled_Cnt_T_lgc = TRUE;
			}
		}
		else
		{
	    	EventHandled_Cnt_T_lgc = FALSE;
		}	
	}
	return EventHandled_Cnt_T_lgc;
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
