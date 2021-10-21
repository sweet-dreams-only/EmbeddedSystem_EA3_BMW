/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_VehPwrMd.c
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/VehPwrMd/autosar
 *     SW-C Type:  Ap_VehPwrMd
 *  Generated at:  Fri Apr 28 11:27:40 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VehPwrMd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#49 %
 * %derived_by:       nz2378 %
 * %date_modified:    Tue Sep 17 16:04:25 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/12/11  1        JJW       Initial generation of Davinci template
 *                               initial implementation of runnable content
 * 01/13/11  2        JJW       Corrected combustion engine state definitions
 * 01/14/11  3        JJW       Added defeats for eng on and ramping
 * 01/14/11  4        JJW       Corrected EngRun defeat implementation
 * 01/14/11  5        JJW       Corrected Defeat Ramp Logic Inversion
 * 01/20/11  6        JJW       Implement based on SER requirements
 * 01/21/11  7        JJW       Added initial implmentation of DEM Operation Cycle Start
 * 02/07/11  8        JJW       Added Ignition stuck on diagnostic
 * 02/11/11  10       LWW       Removed StartOpCycle call until use better defined
 * 02/15/11  11       LWW       Added call to Ea_Setmode
 * 02/28/11  12       LWW       Removed call to Ea_Setmode
 * 03/26/11  13       JJW       System Framework Update
 * 04/11/11  14       LWW       Updated for states and modes design changes
 * 05/03/11  15       LWW       Added A Term over-ride of ramp command
 * 12/14/11  15.1.1   KJS       Implemented ICR 3111 on C term.
 * 01/11/12  18       NRAR      Changed to match the StateOutputCtrl requirement, Updated NTC to global constants, ANOM 2770 fixed. (No continuity on version numbers as merge performed on parallel versions
 * 01/19/12  19       LWW       Updates to support new A, C, and Ramping logic 
 * 01/20/12  20       JJW       Add declarations for StDrvVehMissing_Cnt_T_lgc and KL15NMissing_Cnt_T_lgc
 * 03/21/12  21       VK        Changes driven by States and Modes FDD10C v006								 5081
 * 07/10/12	 23		  KJS		Added DecodedStDrvVeh output												 5816
 * 07/18/12	 24		  BDO		Remove DecodedStDrvVeh output - anomaly 3539 								 5866
 * 10/25/12	 25		  KJS		Updated for new SER requirements and MSA 
 * 10/30/12	 26		  KJS		Anomaly 3992 correction
 * 10/30/12	 27		  KJS		
 * 10/31/12	 28		  KJS		Anomaly 3992 correction: Corrected MSA start / stop command
 * 01/07/13	 30		  KJS		Anomaly 4131 correction to MSA.
 * 02/15/13	 31		  KJS		Anomaly 4422 correction Init1 for MSA, and QAC corrections
 * 03/06/13	 32		  KJS		SER updates and QAC corrections.
 * 03/22/13	 33		  KJS		Corrections for anomaly 4672 for learn center service. 
 * 04/12/13	 34		  KJS		Corrections for anomaly 4705 for MSA transitions near stand still. 			 7876
 * 09/17/13	 35		  KJS		Corrections for anomaly 5634 for MSA.
 * 07/09/14	 36		  KJS		Updates for SER 14B for ST_DRV_VEH handling.
 * 04/01/15  37		  KJS		Updates for NvM fast write flag handling.
 * 02/08/16  39       KJS       Updated file for changes based on F40 serial comm requirements and new states and modes.
 * 02/28/16  40       KJS       Updated for anomaly 6327.
 * 03/07/16  41       KJS       Clean up of source file for QAC and design reviews
 * 05/26/16  42       ABS       Updated for SCIR 002a														EA3#7977
 * 06/17/16  43       ABS       Updated for SCIR 002A	- Bug fix											EA3#7977
 * 06/29/16  44       ABS       Updated for SCIR 002A	- Bug fix											EA3#7977
 * 07/17/16  45       ABS       Updated for SCIR 002C and removal of global variables for missing and invalid CON_VEH msg	EA3#7617
 * 08/08/16  46       RMV       Updated for anomalies EA3#6591, EA3#8804
 * 04/28/17  47		  ABS		State Machine update for SCIR 0020											EA3#11850
 * 05/05/17  48		  ABS		Correction in implementation for State Machine								EA3#11850
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_VehPwrMd.h"
#include "Appl_ComCbk.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"

/* Internal Combustion Drivetrain States */

/* Full Assist Values */
#define D_MCVFULLASSIST_CNT_U8			0x00U
#define D_MCVFULLASSIST_MASK_CNT_U8		0xE0U
#define D_FULLASSIST_CNT_U8				0x82U

/* Assist value based on MSA */
#define D_MSAASSISTSEL_CNT_U8		0x88U

/* MSA Values */
#define D_MSASTOPANNOUN_CNT_U8		0x8EU
#define D_MSASTOPCMD_CNT_U8			0x9AU
#define D_STARTANNOUN2_CNT_U8		0x9EU
#define D_STARTANNOUN_CNT_U8		0x8CU

/* ST_CENG_DRV Enumerated Values */
#define D_ENGINERUNNING_CNT_U8		0x02U
#define D_ENGINEINOUTLET_CNT_U8		0x03U
#define D_ENGINESTANDS_CNT_U8		0x00U

/* ST_ANO_MSA_ENG_STOP Enumerated Values */
#define D_MSAENGSTOP_CNT_U8			0x01U
#define D_NOANNOUNCEMENT_CNT_U8		0x00U

/* ST_UDP Enumerated Values */
#define D_NOVOLTAGEDROP_CNT_U8		0x00U
#define D_STARTVLTGDROP1_CNT_U8		0x01U
#define D_STARTVLTGDROP2_CNT_U8		0x02U

/* ST_ENERG_SUPY Enumerated Values */
#define D_VLTGDIPSUPPPATH1_CNT_U8	0x01U
#define D_VLTGDIPPATHMASK_CNT_U8	0x81U

/* ST_MOT_DRV Enumerated Values */
#define D_EMACHINEACTIVE_CNT_U8		0x01U
#define D_NOEMACHINEAVAILABLE_CNT_U8	0x0U

#define D_IGNSTUCKON_MS_U32     	3600000UL   /*60min * 60 sec/min * 1000 ms/sec = 3600000ms */


#define D_STDRVVEH136_TRGTVAL_ULS_F32	0.0001F /* SER14B -- "Assist percentage negligible value is to prevent system going to disable state." */


typedef enum
{
	ASSIST_NONE			= 0U,
	ASSIST_FULL			= 1U,
	ASSIST_OTHER		= 2U,
	ASSIST_STDRVVEH_136	= 3U
} DecStDrvVeh;


typedef enum
{
	VEHNSS_NEAR_STANDSTILL 		= CxC_Fahrzeug_im_stillstandsnahen_Bereich,
	VEHNSS_NOTNEAR_STANDSTILL 	= CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich,
	VEHNSS_INVALID				= CxF_Signal_ungueltig
} VehNssEnum;

#define VEHPWRMD_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32,  VEHPWRMD_VAR_NOINIT) Rate_XpmS_M_f32;
STATIC VAR(float32,  VEHPWRMD_VAR_NOINIT) Target_Uls_M_f32;
STATIC VAR(uint32,  VEHPWRMD_VAR_NOINIT) IgnStuckStart_mS_M_u32;
#define VEHPWRMD_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(MSA_Cmd_Type, VEHPWRMD_VAR_NOINIT) PrevMSACommand_Uls_M_enum;
#define VEHPWRMD_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean,  VEHPWRMD_VAR_NOINIT) PrevCBitActive_Cnt_M_lgc;
STATIC VAR(boolean,  VEHPWRMD_VAR_NOINIT) PrevABitActive_Cnt_M_lgc;
#define VEHPWRMD_STOP_SEC_VAR_NOINIT_BOOLEAN
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
 * CD_0x04: Integer in interval [0...15]
 * CD_0x16: Integer in interval [0...4194303]
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * New_Coding_101: Integer in interval [0...255]
 * New_Coding_102: Integer in interval [0...14]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * MSA_Cmd_Type: Enumeration of integer in interval [0...3] with enumerators
 *   MSA_STOP_ANNOUNCEMENT (0U)
 *   MSA_STOP_COMMAND (1U)
 *   MSA_START_ANNOUNCEMENT (2U)
 *   MSA_ENGINE_RUN (3U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
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
 *   NTC_Num_PeripheralStartupFlt (55U)
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
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
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
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
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
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
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
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
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
 *   NTC_Num_DataOther2FltMsg_M (295U)
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
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * New_Coding_103: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Kein_Spannungseinbruch (0U)
 *   Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1 (1U)
 *   Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2 (2U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_104: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Motor_steht (0U)
 *   Cx1_Motor_startet (1U)
 *   Cx2_Motor_laeuft (2U)
 *   Cx3_Motor_im_Auslauf (3U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_105: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Kein_Spannungseinbruch (0U)
 *   Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1 (0U)
 *   Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2 (0U)
 *   Cb0xxxx1xx_Spannungsversorgung_48_Volt (0U)
 *   CxFD_Reserviert (253U)
 *   CxFE_Reserviert (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_106: Enumeration of integer in interval [0...15] with enumerators
 *   Cb0xx1_Selbstlaufgrenze_unterschritten (0U)
 *   Cb0xx0_Selbstlaufgrenze_nicht_unterschritten (0U)
 *   Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten (0U)
 *   Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar (0U)
 *   Cb01xx_Retry_Anforderung_Fahrzeug_halten (0U)
 *   Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten (0U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_107: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_Ankuendigung (0U)
 *   Cx1_Ankuendigung_MSA_Motorstopp (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_108: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_E_Maschine_verfuegbar (0U)
 *   Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_109: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_ausschalten (0U)
 *   Cx1_einschalten (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_64: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_reserviert (0U)
 *   Cx1_Parken_BN_niO (1U)
 *   Cx2_Parken_BN_iO (2U)
 *   Cx3_Standfunktionen_Kunde_nicht_im_FZG (3U)
 *   Cx5_Wohnen (5U)
 *   Cx7_Pruefen_Analyse_Diagnose (7U)
 *   Cx8_Fahrbereitschaft_herstellen (8U)
 *   CxA_Fahren (10U)
 *   CxC_Fahrbereitschaft_beenden (12U)
 *   CxD_reserviert (13U)
 *   CxE_reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * ST_V_VEH_NSS: Enumeration of integer in interval [0...15] with enumerators
 *   CxC_Fahrzeug_im_stillstandsnahen_Bereich (12U)
 *   CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich (13U)
 *   CxF_Signal_ungueltig (15U)
 *
 * Record Types:
 * =============
 * SG_ST_CENG: Record with elements
 *   CRC_ST_CENG of type New_Coding_101
 *   ST_ANO_MSA_ENG_STOP of type New_Coding_107
 *   CTR_LED_PUBU_MSA of type New_Coding_109
 *   ST_CENG_0x2A_0x16 of type CD_0x16
 *   ST_ENERG_SUPY of type New_Coding_105
 *   ST_MOT_DRV of type New_Coding_108
 *   ST_UDP of type New_Coding_103
 *   ST_CENG_DRV of type New_Coding_104
 *   ALIV_ST_CENG of type New_Coding_102
 *   TR_HHASS_MSA of type New_Coding_106
 *   ST_CENG_0x0C_0x04 of type CD_0x04
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
 * Float: D_ZERO_ULS_F32 = 0.0F
 * MSA_Cmd_Type: D_MSA_CMD_INIT = 3U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_VEHPWRMD_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Init1
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
 *   void Rte_IWrite_VehPwrMd_Init1_MSACommand_MSACmd_enum(MSA_Cmd_Type data)
 *   MSA_Cmd_Type *Rte_IWriteRef_VehPwrMd_Init1_MSACommand_MSACmd_enum(void)
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32(void)
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

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Init1
 *********************************************************************************************************************/
	VAR(MSA_Cmd_Type, AUTOMATIC) MSACmd_Cnt_T_enum;

	Rate_XpmS_M_f32 = k_RampDnRt_UlspmS_f32;
	Target_Uls_M_f32 = D_ZERO_ULS_F32;
	MSACmd_Cnt_T_enum = MSA_ENGINE_RUN;

	/* Update previous for non-MSA vehicles to use engine run */
	PrevMSACommand_Uls_M_enum = MSACmd_Cnt_T_enum;

	PrevCBitActive_Cnt_M_lgc = FALSE;

	PrevABitActive_Cnt_M_lgc = TRUE;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&IgnStuckStart_mS_M_u32);

	Rte_IWrite_VehPwrMd_Init1_MSACommand_MSACmd_enum(MSACmd_Cnt_T_enum);
	Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(Rate_XpmS_M_f32);
	Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(Target_Uls_M_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Per1
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
 *   Boolean Rte_IRead_VehPwrMd_Per1_CASSISTMSA_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   SG_ST_CENG *Rte_IRead_VehPwrMd_Per1_SrlComEngDrvStatus_ST_CENG(void)
 *   New_Coding_64 Rte_IRead_VehPwrMd_Per1_SrlComVehCdnStatus_VehCdnStatus(void)
 *   ST_V_VEH_NSS Rte_IRead_VehPwrMd_Per1_SrlComVehNearStandstill_Cnt_u08(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_VehPwrMd_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_MSACommand_MSACmd_enum(MSA_Cmd_Type data)
 *   MSA_Cmd_Type *Rte_IWriteRef_VehPwrMd_Per1_MSACommand_MSACmd_enum(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32(void)
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
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
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

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Per1
 *********************************************************************************************************************/
	VAR(New_Coding_64, AUTOMATIC)StConVeh_Cnt_T_u8;

	VAR(IoHwAb_BoolType, AUTOMATIC) EPSEn_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC)ElapsedTime_mS_T_u32;
	VAR(boolean, AUTOMATIC)CTermActive_Cnt_T_lgc = PrevCBitActive_Cnt_M_lgc;
	VAR(boolean, AUTOMATIC)ATermActive_Cnt_T_lgc = PrevABitActive_Cnt_M_lgc;
	VAR(boolean, AUTOMATIC)EngOnSrlSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)ConVehMissing_Cnt_T_lgc;
	VAR(MSA_Cmd_Type, AUTOMATIC)MSACommand_Uls_T_enum = PrevMSACommand_Uls_M_enum;

	VAR(SG_ST_CENG, AUTOMATIC)RxStCeng_T_Str;
	VAR(New_Coding_104, AUTOMATIC)StCengDrv_Cnt_T_u08;
	VAR(New_Coding_103, AUTOMATIC)StUdp_Cnt_T_u08;
	VAR(New_Coding_105, AUTOMATIC)StEnergSupy_Cnt_T_u08;
    VAR(New_Coding_108, AUTOMATIC)StMotDrv_Cnt_T_u08;
	VAR(New_Coding_107, AUTOMATIC)StMsaEngStop_Cnt_T_u08;

	VAR(ST_V_VEH_NSS, AUTOMATIC)VehNSSValue_Cnt_T_enum;

	VAR(float32, AUTOMATIC)VehSpd_Kph_T_f32;
	VAR(uint16, AUTOMATIC)VehSpd_Kph_T_u12p4;
	VAR(boolean, AUTOMATIC)VehicleSpeedValid_T_Cnt_lgc;

	VAR(boolean, AUTOMATIC)RampDownCond_Cnt_T_lgc = FALSE;

	VAR(boolean, AUTOMATIC)VehNSSMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)VehCogErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)QuVehCogErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)StCengMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)StCengInvalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)StCengUndef_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)VehNSSInvalid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC)StVVehInvalid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC)StVVehCRCError_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC)StVVehAliveError_Cnt_T_lgc;

    VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_enum;
    VAR(boolean, AUTOMATIC)RampHoldCond_Cnt_T_lgc = FALSE;

	VehSpd_Kph_T_f32 = Rte_IRead_VehPwrMd_Per1_VehicleSpeed_Kph_f32();
	VehSpd_Kph_T_u12p4 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u12p4_T);

	VehicleSpeedValid_T_Cnt_lgc = Rte_IRead_VehPwrMd_Per1_VehicleSpeedValid_Cnt_lgc();

	RxStCeng_T_Str = *Rte_IRead_VehPwrMd_Per1_SrlComEngDrvStatus_ST_CENG();
	StCengDrv_Cnt_T_u08 = RxStCeng_T_Str.ST_CENG_DRV;
	StUdp_Cnt_T_u08 = RxStCeng_T_Str.ST_UDP;
	StEnergSupy_Cnt_T_u08 = RxStCeng_T_Str.ST_ENERG_SUPY;
	StMotDrv_Cnt_T_u08 = RxStCeng_T_Str.ST_MOT_DRV;
	StMsaEngStop_Cnt_T_u08 = RxStCeng_T_Str.ST_ANO_MSA_ENG_STOP;

	VehNSSValue_Cnt_T_enum = Rte_IRead_VehPwrMd_Per1_SrlComVehNearStandstill_Cnt_u08();
			
	(void)Rte_Call_EpsEn_OP_GET(&EPSEn_Cnt_T_lgc);
	EngOnSrlSvcDft_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc();

	StConVeh_Cnt_T_u8 = Rte_IRead_VehPwrMd_Per1_SrlComVehCdnStatus_VehCdnStatus();

	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_AD, &ConVehMissing_Cnt_T_lgc);
	
	if (TRUE == EngOnSrlSvcDft_Cnt_T_lgc)
	{
		CTermActive_Cnt_T_lgc = TRUE;
		ATermActive_Cnt_T_lgc = TRUE;
		
		Rate_XpmS_M_f32 = k_RampUpRtLoSpd_UlspmS_f32;
		Target_Uls_M_f32 = D_ONE_ULS_F32;

		/* Force MSA command to engine run */
		MSACommand_Uls_T_enum = MSA_ENGINE_RUN;
	}
	else /* Execute the OEM State Machine criteria */
	{
		/* Obtain the time for Alternator Diagnostic */
		if(CDD_InitialTimeLockout_Cnt_G_lgc == FALSE)
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CDD_InitialTime_mS_G_u32);
			CDD_InitialTimeLockout_Cnt_G_lgc = TRUE;
		}


		/* Update Previous MSA Command */
		PrevMSACommand_Uls_M_enum = MSACommand_Uls_T_enum;

		/* Determine if VehNSS is valid */
		if(VehNSSValue_Cnt_T_enum == (ST_V_VEH_NSS)VEHNSS_INVALID)
		{
			VehNSSInvalid_Cnt_T_lgc = TRUE;
		}
		else
		{
			VehNSSInvalid_Cnt_T_lgc = FALSE;
		}

		/* Determine MSA command */
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &VehNSSMissing_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_P, &VehCogErr_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_P, &QuVehCogErr_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_AC, &StCengMissing_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_AC, &StCengInvalid_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_AC, &StCengUndef_Cnt_T_lgc);

		if((VehNSSInvalid_Cnt_T_lgc == TRUE) ||
		   (VehNSSMissing_Cnt_T_lgc == TRUE) ||
		   (VehCogErr_Cnt_T_lgc == TRUE) ||
		   (QuVehCogErr_Cnt_T_lgc == TRUE) ||
		   (StCengMissing_Cnt_T_lgc == TRUE) ||
		   (StCengInvalid_Cnt_T_lgc == TRUE) ||
		   (StCengUndef_Cnt_T_lgc == TRUE) ||
		   (StMotDrv_Cnt_T_u08 == D_EMACHINEACTIVE_CNT_U8)
		  )
		{
			MSACommand_Uls_T_enum = MSA_ENGINE_RUN;
		}
		else if( ((StConVeh_Cnt_T_u8 == CxA_Fahren) && (StMotDrv_Cnt_T_u08 == D_NOEMACHINEAVAILABLE_CNT_U8)) &&
				 ((VehNSSMissing_Cnt_T_lgc == FALSE) && (VehNSSValue_Cnt_T_enum == (ST_V_VEH_NSS)VEHNSS_NEAR_STANDSTILL))
			   )
		{
			/* MSA Transitions -- start-- */
			if((StEnergSupy_Cnt_T_u08 & D_VLTGDIPPATHMASK_CNT_U8) == D_VLTGDIPSUPPPATH1_CNT_U8)
			{/* power supply status --start-- */
				if((StUdp_Cnt_T_u08 == D_STARTVLTGDROP1_CNT_U8) || (StUdp_Cnt_T_u08 == D_STARTVLTGDROP2_CNT_U8))
				{ /* start voltage drop --start-- */
					if(((StMsaEngStop_Cnt_T_u08 == D_NOANNOUNCEMENT_CNT_U8) || (StMsaEngStop_Cnt_T_u08 == D_MSAENGSTOP_CNT_U8)) &&
					   ((StCengDrv_Cnt_T_u08 == D_ENGINESTANDS_CNT_U8) || (StCengDrv_Cnt_T_u08 == D_ENGINEINOUTLET_CNT_U8))
					  )
					{
						MSACommand_Uls_T_enum = MSA_START_ANNOUNCEMENT;
					}
				} /* start voltage drop --end-- */
				else if (StUdp_Cnt_T_u08 == D_NOVOLTAGEDROP_CNT_U8)
				{ /* no voltage drop --start-- */
					if(StMsaEngStop_Cnt_T_u08 == D_MSAENGSTOP_CNT_U8)
					{
						if(StCengDrv_Cnt_T_u08 == D_ENGINERUNNING_CNT_U8)
						{
							MSACommand_Uls_T_enum = MSA_STOP_ANNOUNCEMENT;
						}
						else if (StCengDrv_Cnt_T_u08 == D_ENGINEINOUTLET_CNT_U8)
						{
							MSACommand_Uls_T_enum = MSA_STOP_COMMAND;
						}
					}
					else if (StMsaEngStop_Cnt_T_u08 == D_NOANNOUNCEMENT_CNT_U8)
					{
						if(StCengDrv_Cnt_T_u08 == D_ENGINERUNNING_CNT_U8)
						{
							MSACommand_Uls_T_enum = MSA_ENGINE_RUN;
						}
						else if (StCengDrv_Cnt_T_u08 == D_ENGINESTANDS_CNT_U8)
						{
							MSACommand_Uls_T_enum = MSA_STOP_COMMAND;
						}
					}
				} /* no voltage drop --end-- */
			} /* power supply status --end-- */
		} /* MSA Transitions -- end-- */
		else
		{
			/* Do Nothing */
		}

		/* C-Term Logic to start providing assist */
		if(((ConVehMissing_Cnt_T_lgc == TRUE) && (TRUE == PrevCBitActive_Cnt_M_lgc)) ||
		   (CxA_Fahren == StConVeh_Cnt_T_u8)
		  )
		{
			CTermActive_Cnt_T_lgc = TRUE;
			CDD_NvMFastWriteEnable_Cnt_G_lgc = FALSE;
		}

		/* V_VEH is considered invalid if Alive NTC or CRC NTC exist for this signal */
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_O, &StVVehCRCError_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_O, &StVVehAliveError_Cnt_T_lgc);

		if ((StVVehCRCError_Cnt_T_lgc == FALSE) && (StVVehAliveError_Cnt_T_lgc == FALSE))
		{
			StVVehInvalid_Cnt_T_lgc = FALSE;
		}
		else
		{
			StVVehInvalid_Cnt_T_lgc = TRUE;
		}

		/* C-Term start ramp down of assist first part of conditions */
		if(((VehSpd_Kph_T_u12p4 < k_VehSpdRampDwn_kph_u12p4) && (VehicleSpeedValid_T_Cnt_lgc == TRUE)) ||
		   ((FALSE == VehicleSpeedValid_T_Cnt_lgc) && (FALSE == StVVehInvalid_Cnt_T_lgc) &&
			((ST_V_VEH_NSS)VEHNSS_NEAR_STANDSTILL == VehNSSValue_Cnt_T_enum)
		   )
		  )
		{
			RampDownCond_Cnt_T_lgc = TRUE;
		}

		/* C-Term start ramp down of assist last part of conditions */
		if(((Cx1_Parken_BN_niO == StConVeh_Cnt_T_u8) ||
		    (Cx2_Parken_BN_iO == StConVeh_Cnt_T_u8) ||
		    (Cx3_Standfunktionen_Kunde_nicht_im_FZG == StConVeh_Cnt_T_u8) ||
		    (Cx5_Wohnen == StConVeh_Cnt_T_u8) ||
		    (Cx7_Pruefen_Analyse_Diagnose == StConVeh_Cnt_T_u8) ||
		    (Cx8_Fahrbereitschaft_herstellen == StConVeh_Cnt_T_u8) ||
		    (CxC_Fahrbereitschaft_beenden == StConVeh_Cnt_T_u8)
		   ) &&
		   (RampDownCond_Cnt_T_lgc == TRUE)
		  )
		{
			CTermActive_Cnt_T_lgc = FALSE;
		}

		/* A-Term power up conditions */
		if ((Cx7_Pruefen_Analyse_Diagnose == StConVeh_Cnt_T_u8) ||
			(Cx8_Fahrbereitschaft_herstellen == StConVeh_Cnt_T_u8) ||
			(CxA_Fahren == StConVeh_Cnt_T_u8) ||
			(CxC_Fahrbereitschaft_beenden == StConVeh_Cnt_T_u8) )
		{
			ATermActive_Cnt_T_lgc = TRUE;
		}

		/* A-Term start power down conditions */
		if ((Cx1_Parken_BN_niO == StConVeh_Cnt_T_u8) ||
			(Cx2_Parken_BN_iO == StConVeh_Cnt_T_u8) ||
			(Cx3_Standfunktionen_Kunde_nicht_im_FZG == StConVeh_Cnt_T_u8) ||
			(Cx5_Wohnen == StConVeh_Cnt_T_u8) )
		{
			ATermActive_Cnt_T_lgc = FALSE;
		}

		SysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();

		if((SysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) &&
		   ((Cx7_Pruefen_Analyse_Diagnose == StConVeh_Cnt_T_u8) ||
		    (Cx8_Fahrbereitschaft_herstellen == StConVeh_Cnt_T_u8) ||
		    (CxA_Fahren == StConVeh_Cnt_T_u8) ||
		    (CxC_Fahrbereitschaft_beenden == StConVeh_Cnt_T_u8))
		  )
		{
			CTermActive_Cnt_T_lgc = TRUE;
			RampHoldCond_Cnt_T_lgc = TRUE;
		}

		if (FALSE == CTermActive_Cnt_T_lgc)
		{
			Rate_XpmS_M_f32 = k_RampDnRt_UlspmS_f32;
			Target_Uls_M_f32 = D_ZERO_ULS_F32;
		}
		else if (RampHoldCond_Cnt_T_lgc == TRUE)
		{
			/* Do Nothing */
		}
		else
		{
			Rate_XpmS_M_f32 = k_RampUpRtLoSpd_UlspmS_f32;
			Target_Uls_M_f32 = D_ONE_ULS_F32;
		}
	}

	/* Perform Ignition stuck On Diagnostic Check*/

	/* NXTR PATCH START
	 * Added 08Feb16
	 * Purpose: Stkl15 is no longer available. Changing logic to A-bit = false until requirements are clarified */
	if ((STD_ON == EPSEn_Cnt_T_lgc) && (FALSE == ATermActive_Cnt_T_lgc))
	/* NXTR PATCH END */
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(IgnStuckStart_mS_M_u32, &ElapsedTime_mS_T_u32);
		if(ElapsedTime_mS_T_u32 > D_IGNSTUCKON_MS_U32)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IgnConfDiag, 0U, NTC_STATUS_FAILED);
		}
	}
	else /* Reset Ignition stuck On time, diagnostic is passing */
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&IgnStuckStart_mS_M_u32);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IgnConfDiag, 0U, NTC_STATUS_PASSED);
	}
	
	PrevCBitActive_Cnt_M_lgc = CTermActive_Cnt_T_lgc;
	PrevABitActive_Cnt_M_lgc = ATermActive_Cnt_T_lgc;
	Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(CTermActive_Cnt_T_lgc);
	Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(ATermActive_Cnt_T_lgc);

	Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(Rate_XpmS_M_f32);
	Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(Target_Uls_M_f32);

	Rte_IWrite_VehPwrMd_Per1_MSACommand_MSACmd_enum(MSACommand_Uls_T_enum);
  
  /* Invoke the VSM function to indicate that Klemmen is being received continuously */
  Vsm_OpStateRxNotification();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VEHPWRMD_APPL_CODE
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
