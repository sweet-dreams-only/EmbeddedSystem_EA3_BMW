/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  IoHwAb7.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/autosar
 *     SW-C Type:  IoHwAb7
 *  Generated at:  Mon Feb  4 11:22:42 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <IoHwAb7>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sun Nov 14 12:00:00 2010
 * %version:          11 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Thu Jun 20 18:48:59 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * -------   -------  --------  -------------------------------------------------------------------------------  ------
 * 11/21/12   3	    JJW		 Added CDD_CDDMtrPosAccessBfr_Cnt_G_u16 management to
 *								provide synchronization with Adc1 conversion start.
 * 12/21/12   4     Selva    Add brazen noise
 * 01/21/13   5     JJW    	 Integration of Nxtr Adc BSW
 * 01/25/13   7     KJS		 Integration of Battery Voltage, added support for Vswitched ADC reads. 
 * 02/05/13   8     JJW		 Integration of MtrPos FDD06B_004.1.  Removal of deprecated and unused ports. 
 * 02/06/13   9     JJW		 Removed incorrect synchronization comment. 
 * 05/01/13   10    KJS		 Changed _Init() function for the correction to anomaly 4861.
 * 06/20/13	  11	KJS		 QAC corrections.
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

#include "Rte_IoHwAb7.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "adc_regs.h"	/* register definitions in order to perform adc cal procedure */
#include "Adc.h"
#include "Adc_Cfg.h"
#include "Adc2.h"
#include "CDD_Const.h"
#include "CalConstants.h"
#include "CDD_Data.h"
#include "Os.h"
#include "IoHwAbstractionUsr.h"
#include "GlobalMacro.h"

#define D_NUMFWDPTHCH_CNT_U16   2U
#define D_NUMFDBKPTHCH_CNT_U16  10U

#define D_T1CHN_CNT_U16  				0U
#define D_T2CHN_CNT_U16  				1U

#define D_TEMPSNSRCHN_CNT_U16  			0U
#define D_PDSUPLFDBKCHN_CNT_U16 		1U
#define D_BATTCHN_CNT_U16  				2U
#define D_PDCHRGPMPFDBKCHN_CNT_U16 		3U
#define D_VREFCHN_CNT_U16  				4U
#define D_COS1CHN_CNT_U16  				5U
#define D_SIN1CHN_CNT_U16  				6U
#define D_SIN2CHN_CNT_U16  				7U
#define D_COS2CHN_CNT_U16  				8U
#define D_BATTSWITCHEDCHN_CNT_U16  		9U
#define D_ADCVOLTSPERCNT_ULS_F32		(5.0F /4095.0F)
#define D_ADCHILMT_VOLT_F32           5.0F
#define D_ADCLOLMT_VOLT_F32           0.0F


#define D_NTCPARMBIT0_CNT_U8			1U
#define D_NTCPARMBIT1_CNT_U8			2U
#define D_NTCPARMBIT2_CNT_U8			4U
#define D_BUFFERMASK_CNT_U16            7U
#define D_OVRSMPLBUFFSIZE_CNT_U16		8U
#define D_BASECONFIG_CNT_U16            0U

#define D_IOHWAB7DBLBUFFSZ_CNT_U08		2u

#define IOHWAB7_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(Adc_ValueGroupType, IOHWAB_NOINIT_16BIT) IO_FwdPthAdcBufRslt_M_Cnt[D_NUMFWDPTHCH_CNT_U16];
STATIC VAR(Adc_ValueGroupType, IOHWAB_NOINIT_16BIT) IO_FwdPthAdcBufRead_M_Cnt[D_NUMFWDPTHCH_CNT_U16];

STATIC VAR(Adc_ValueGroupType, IOHWAB_NOINIT_16BIT) IO_FdbkPthAdcBufRead_M_Cnt[D_NUMFDBKPTHCH_CNT_U16];
STATIC VAR(Adc_ValueGroupType, IOHWAB_NOINIT_16BIT) IO_FdbkPthAdcBufRslt_M_Cnt[D_NUMFDBKPTHCH_CNT_U16];

#define IOHWAB7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define IOHWAB7_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) T1AdcBuffer_Volt_M_f32[D_OVRSMPLBUFFSIZE_CNT_U16];
STATIC VAR(float32, AUTOMATIC) T2AdcBuffer_Volt_M_f32[D_OVRSMPLBUFFSIZE_CNT_U16];
STATIC VAR(float32, AUTOMATIC) ADCVrefScaled_Volt_M_f32;
#define IOHWAB7_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define IOHWAB7_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) ADCVrefErrorAcc_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC) BufferPosition_Cnt_M_u16;
	   volatile VAR(uint8, AUTOMATIC) IoHwAb7_ActvDblBuf_Cnt_G_u08;
STATIC VAR(uint16, AUTOMATIC) IoHwAb7_ADCMtrCurr1_Cnt_M_u16[D_IOHWAB7DBLBUFFSZ_CNT_U08];
#define IOHWAB7_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define IOHWAB7_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, IOHWAB_NOINIT_8BIT) IO_InitComplete_M_Cnt_lgc;
STATIC VAR(boolean, IOHWAB_NOINIT_8BIT) OvrSmplTAdcBfrWriteEn_Cnt_M_lgc;

#define IOHWAB7_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FwdPathConv( void );
STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FdbkPathConv( void );


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
 *   NTC_Num_PAHwVelFlt (225u)
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
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_IOHWAB7_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_FdbkPathAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_FdbkPathAdc(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb7_FdbkPathAdc
 *********************************************************************************************************************/
    /* Perform the feedback path conversion steps */
    FdbkPathConv();

	/* Update Sender port signals for completed analog conversions*/
    Rte_IWrite_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTSWITCHEDCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32);
    Rte_IWrite_IoHwAb7_FdbkPathAdc_Batt_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattScaling_Uls_f32);
    Rte_IWrite_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(((float32)Adc2_GetVswitched_Cnt_u16_m) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32); /* TODO: Verify this value */

	Rte_IWrite_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_TEMPSNSRCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCTempSnsrScaling_Uls_f32) + k_ADCTempSnsrOffset_Uls_f32);
	Rte_IWrite_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_PDSUPLFDBKCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_PDScaling_Uls_f32));
	Rte_IWrite_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_PDCHRGPMPFDBKCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ChrgPumpScaling_Uls_f32));
	Rte_IWrite_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_COS2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCMtrPosScaling_Uls_f32);
	Rte_IWrite_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_SIN2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCMtrPosScaling_Uls_f32);

	ADCVrefScaled_Volt_M_f32 = (float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_VREFCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVrefScaling_Uls_f32);

	if(ADCVrefScaled_Volt_M_f32 > k_VrefMax_Volts_f32)
	{
		ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (DiagFailed_m( ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_FAILED);
		}
	}
	else if(ADCVrefScaled_Volt_M_f32 < k_VrefMin_Volts_f32)
	{
		ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (DiagFailed_m( ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
		}
	}
	else
	{
		ADCVrefErrorAcc_Cnt_M_u16 = DiagNStep_m(ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
		if (ADCVrefErrorAcc_Cnt_M_u16 == D_ZERO_CNT_U16)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_PASSED);
		}
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_FwdPathAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_FwdPathAdc(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb7_FwdPathAdc
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) T1ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T1SysADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2SysADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T1ADCSum_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2ADCSum_Volt_T_f32;
	VAR(float32, AUTOMATIC) ADCMtrCurr1_Volt_T_f32;
	VAR(uint8, AUTOMATIC) IdleDblBuf_Cnt_T_u08;
	VAR(uint16, AUTOMATIC ) i;

    /* Perform the forward path conversion steps */
    FwdPathConv();
	
	/* Switch the Global Active Double Buffer Control signal, then update outputs owned by this module */
	IdleDblBuf_Cnt_T_u08 = IoHwAb7_ActvDblBuf_Cnt_G_u08;
	IoHwAb7_ActvDblBuf_Cnt_G_u08 = (IoHwAb7_ActvDblBuf_Cnt_G_u08 ^ 1u) & 1u;
	ADCMtrCurr1_Volt_T_f32 = IoHwAb7_ADCMtrCurr1_Cnt_M_u16[IdleDblBuf_Cnt_T_u08] * D_ADCVOLTSPERCNT_ULS_F32;
	
	OvrSmplTAdcBfrWriteEn_Cnt_M_lgc = FALSE;

	if (k_T1T2AvgFilterEnable_Uls_lgc == TRUE)
	{
		T1ADCSum_Volt_T_f32 = T1AdcBuffer_Volt_M_f32[0];
		T2ADCSum_Volt_T_f32 = T2AdcBuffer_Volt_M_f32[0];

		for (i = 1U; i < D_OVRSMPLBUFFSIZE_CNT_U16; i++)
			{
				T1ADCSum_Volt_T_f32 += T1AdcBuffer_Volt_M_f32[i];
				T2ADCSum_Volt_T_f32 += T2AdcBuffer_Volt_M_f32[i];
			}
		OvrSmplTAdcBfrWriteEn_Cnt_M_lgc = TRUE;
		T1ADC_Volt_T_f32 = (T1ADCSum_Volt_T_f32/D_OVRSMPLBUFFSIZE_CNT_U16);
		T2ADC_Volt_T_f32 = (T2ADCSum_Volt_T_f32/D_OVRSMPLBUFFSIZE_CNT_U16);
		T1SysADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
		T2SysADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;


	}
	else
	{
	T1ADC_Volt_T_f32 = T1AdcBuffer_Volt_M_f32[D_BASECONFIG_CNT_U16];
	T2ADC_Volt_T_f32 = T2AdcBuffer_Volt_M_f32[D_BASECONFIG_CNT_U16];

	OvrSmplTAdcBfrWriteEn_Cnt_M_lgc = TRUE;
	T1SysADC_Volt_T_f32 = Adc2_GetT1_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
	T2SysADC_Volt_T_f32 = Adc2_GetT2_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;




	}
	/* Standardize the conversion values and update the Sender Port Interfaces */
    T1ADC_Volt_T_f32 = 		Limit_m(T1ADC_Volt_T_f32,	D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T2ADC_Volt_T_f32 = 		Limit_m(T2ADC_Volt_T_f32,	D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T1SysADC_Volt_T_f32 = 	Limit_m(T1SysADC_Volt_T_f32,D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T2SysADC_Volt_T_f32 = 	Limit_m(T2SysADC_Volt_T_f32,D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    ADCMtrCurr1_Volt_T_f32 = Limit_m(ADCMtrCurr1_Volt_T_f32,D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
	Rte_IWrite_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(T1ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(T2ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(T1SysADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(T2SysADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(ADCMtrCurr1_Volt_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_Init
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
 *   void Rte_IWrite_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_InvCos2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_InvCos2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_InvSin2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_InvSin2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_T2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_TemperatureADC_Volt_f32(void)
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

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb7_Init
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) i;
	VAR(float32, AUTOMATIC) T1ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T1SysADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2SysADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) ADCMtrCurr1_Volt_T_f32;
	VAR(uint8, AUTOMATIC) IdleDblBuf_Cnt_T_u08;


    Adc_SetupResultBuffer( AdcFwdPath, IO_FwdPthAdcBufRslt_M_Cnt );
    Adc_SetupResultBuffer( AdcFdbkPath, IO_FdbkPthAdcBufRslt_M_Cnt );

    /* Start the first conversions and update the sender ports with the results */
    FwdPathConv();
    FdbkPathConv();

	/* Switch the Global Active Double Buffer Control signal, then update outputs owned by this module */
	IdleDblBuf_Cnt_T_u08 = IoHwAb7_ActvDblBuf_Cnt_G_u08;
	IoHwAb7_ActvDblBuf_Cnt_G_u08 = (IoHwAb7_ActvDblBuf_Cnt_G_u08 ^ 1u) & 1u;
	ADCMtrCurr1_Volt_T_f32 = IoHwAb7_ADCMtrCurr1_Cnt_M_u16[IdleDblBuf_Cnt_T_u08] * D_ADCVOLTSPERCNT_ULS_F32;
	
	OvrSmplTAdcBfrWriteEn_Cnt_M_lgc = TRUE;

    if (k_T1T2AvgFilterEnable_Uls_lgc == TRUE)
   	{
       BufferPosition_Cnt_M_u16 = D_OVRSMPLBUFFSIZE_CNT_U16-1U;
    	IoHwAb_Per1();

    	for (i = 1U; i < D_OVRSMPLBUFFSIZE_CNT_U16; i++)
    	{
    		T1AdcBuffer_Volt_M_f32[i] = T1AdcBuffer_Volt_M_f32[0];
    		T2AdcBuffer_Volt_M_f32[i] = T2AdcBuffer_Volt_M_f32[0];
    	}
   	}
    else
       {
       IoHwAb_Per1();
       }

    IO_InitComplete_M_Cnt_lgc = TRUE;

	/* Update Sender port signals for completed analog conversions*/
    Rte_IWrite_IoHwAb7_Init_BattSwitched_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTSWITCHEDCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32);
    Rte_IWrite_IoHwAb7_Init_Batt_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_BATTCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattScaling_Uls_f32);
    Rte_IWrite_IoHwAb7_Init_SysCVSwitch_Volt_f32(((float32)Adc2_GetVswitched_Cnt_u16_m) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32);

	Rte_IWrite_IoHwAb7_Init_TemperatureADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_TEMPSNSRCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCTempSnsrScaling_Uls_f32) + k_ADCTempSnsrOffset_Uls_f32);
	Rte_IWrite_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_PDSUPLFDBKCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_PDScaling_Uls_f32));
	Rte_IWrite_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32((float32)(IO_FdbkPthAdcBufRead_M_Cnt[D_PDCHRGPMPFDBKCHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ChrgPumpScaling_Uls_f32));
	Rte_IWrite_IoHwAb7_Init_InvCos2Scaled_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_COS2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCMtrPosScaling_Uls_f32);
	Rte_IWrite_IoHwAb7_Init_InvSin2Scaled_Volt_f32((float32)IO_FdbkPthAdcBufRead_M_Cnt[D_SIN2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCMtrPosScaling_Uls_f32);
	Rte_IWrite_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(ADCMtrCurr1_Volt_T_f32);

    if (k_T1T2AvgFilterEnable_Uls_lgc == TRUE)
	{
    	T1ADC_Volt_T_f32= Adc2_GetT1_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
        T2ADC_Volt_T_f32 = Adc2_GetT2_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
	    T1SysADC_Volt_T_f32 = (float32)IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32 ;
	    T2SysADC_Volt_T_f32 = (float32)IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;


	}
    else
    {
    	T1SysADC_Volt_T_f32= Adc2_GetT1_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
        T2SysADC_Volt_T_f32 = Adc2_GetT2_Cnt_u16_m * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
	    T1ADC_Volt_T_f32 = (float32)IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32 ;
	    T2ADC_Volt_T_f32 = (float32)IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;


    }
    T1ADC_Volt_T_f32 = 		Limit_m(T1ADC_Volt_T_f32,	D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T2ADC_Volt_T_f32 = 		Limit_m(T2ADC_Volt_T_f32,	D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T1SysADC_Volt_T_f32 = 	Limit_m(T1SysADC_Volt_T_f32,D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
    T2SysADC_Volt_T_f32 = 	Limit_m(T2SysADC_Volt_T_f32,D_ADCLOLMT_VOLT_F32,D_ADCHILMT_VOLT_F32	);
	Rte_IWrite_IoHwAb7_Init_T1ADC_Volt_f32(T1ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_Init_T2ADC_Volt_f32(T2ADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_Init_SysCT1ADC_Volt_f32(T1SysADC_Volt_T_f32);
	Rte_IWrite_IoHwAb7_Init_SysCT2ADC_Volt_f32(T2SysADC_Volt_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_IOHWAB7_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
  * Name:        IoHwAb_Per1
  * Description:
  * Inputs:
  * Outputs:
  ****************************************************************************/

FUNC(void, SA_IoHwAb_CODE) IoHwAb_Per1(void)
{


	VAR(float32, AUTOMATIC) T1ADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) T2ADC_Volt_T_f32;

    if (k_T1T2AvgFilterEnable_Uls_lgc == TRUE)
    {
	T1ADC_Volt_T_f32 = Adc2_GetT1_Cnt_u16_m;
	T2ADC_Volt_T_f32 = Adc2_GetT2_Cnt_u16_m;
	T1ADC_Volt_T_f32 = T1ADC_Volt_T_f32 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
	T2ADC_Volt_T_f32= T2ADC_Volt_T_f32 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;


	if (TRUE == OvrSmplTAdcBfrWriteEn_Cnt_M_lgc)
	{
		BufferPosition_Cnt_M_u16 = (BufferPosition_Cnt_M_u16 + 1U) & D_BUFFERMASK_CNT_U16;

		T1AdcBuffer_Volt_M_f32[BufferPosition_Cnt_M_u16] = T1ADC_Volt_T_f32;
		T2AdcBuffer_Volt_M_f32[BufferPosition_Cnt_M_u16] = T2ADC_Volt_T_f32;

	}
    }
	else
	{
		if (TRUE == OvrSmplTAdcBfrWriteEn_Cnt_M_lgc)
			{
			T1ADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T1CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
			T2ADC_Volt_T_f32 = IO_FwdPthAdcBufRead_M_Cnt[D_T2CHN_CNT_U16] * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCHwTrqScaling_Uls_f32;
			}
	T1AdcBuffer_Volt_M_f32[D_BASECONFIG_CNT_U16] = T1ADC_Volt_T_f32;
	T2AdcBuffer_Volt_M_f32[D_BASECONFIG_CNT_U16] = T2ADC_Volt_T_f32;
	}

	/* Double buffering of motor control ISR signals that require global synchronization */
	IoHwAb7_ADCMtrCurr1_Cnt_M_u16[IoHwAb7_ActvDblBuf_Cnt_G_u08] = Adc2_GetShcurr_Cnt_u16_m;
}
/*****************************************************************************
 * Name:        FwdPathConv
 * Description: Perform the ADC conversion management required during the
 *               forward path conversion.
 * Inputs:      None
 * Outputs:     Forward path ADC results buffer
*****************************************************************************/
STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FwdPathConv( void )
{
	 VAR(boolean, AUTOMATIC)  TimeOut_Cnt_T_lgc = D_FALSE_CNT_LGC;
	 VAR(uint32, AUTOMATIC)  StartTime_uS_T_u32;
	 VAR(uint16, AUTOMATIC)  ElapsedTime_uS_T_u16;

	/* InitComplete flag required since the motor control ISR may not be started
	   and the ECU will be held in an infinite loop */
	if( (CDD_Adc_ConvFlag_Uls_u08 == 0U) && (IO_InitComplete_M_Cnt_lgc == TRUE))
	{
		/* Set flag for first conversion. */
		CDD_Adc_ConvFlag_Uls_u08 = 0x01U;

		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for Motor Control ISR routine to start conversion */
		while ((CDD_Adc_ConvFlag_Uls_u08 != 0U) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_GenMaxADCWaitTime_uS_u16 )
			{
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}

		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for hardware to indicate End of Conversion */
		while((Adc_GetGroupStatus(AdcFwdPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
			{
				/* Set ADC End of Conversion fault and exit loop */
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}

		(void)Adc_ReadGroup ( AdcFwdPath, IO_FwdPthAdcBufRead_M_Cnt );

		/* Set flag to allow next group to start. */
		CDD_Adc_ConvFlag_Uls_u08 = 0x10U;
		
	}
	else if (IO_InitComplete_M_Cnt_lgc == FALSE)
	{
		if(Adc_GetGroupStatus(AdcFwdPath)!= ADC_BUSY)
		{
			Adc_StartGroupConversion ( AdcFwdPath );
		}

		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		/* Wait for hardware to indicate End of Conversion */
		while((Adc_GetGroupStatus(AdcFwdPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
			{
				/* Set ADC End of Conversion fault and exit loop */
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}

		/* Get the results buffer data from the T1/T2 Conversion */
		(void)Adc_ReadGroup ( AdcFwdPath, IO_FwdPthAdcBufRead_M_Cnt );

		/* Trigger the Feedback Path ADC conversion */
		if(Adc_GetGroupStatus(AdcFdbkPath)!= ADC_BUSY)
		{
			Adc_StartGroupConversion ( AdcFdbkPath );
		}
		else
		{
			/* TODO: Determine what to do in the case of an unexpected conversion in progress at this point */
		}
	}
	else
	{
		/* Do nothing */
	}
}

/*****************************************************************************
  * Name:        FdbkPathConv
  * Description: Perform the ADC conversion management required during the 
  *               feedback path conversion.
  * Inputs:      None 
  * Outputs:     Feedback path ADC results buffer
*****************************************************************************/ 
STATIC FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) FdbkPathConv( void )
{
	VAR(boolean, AUTOMATIC)  TimeOut_Cnt_T_lgc = D_FALSE_CNT_LGC;
	VAR(uint32, AUTOMATIC)  StartTime_uS_T_u32;
	VAR(uint16, AUTOMATIC)  ElapsedTime_uS_T_u16;

	if (IO_InitComplete_M_Cnt_lgc == TRUE)
	{
		/* Get start time for wait period */
		(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

		while((CDD_Adc_ConvFlag_Uls_u08 != 0U) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

			if( ElapsedTime_uS_T_u16 >= k_GenMaxADCWaitTime_uS_u16 )
			{
				TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
			}
		}
	} 

	/* Get start time for wait period */
	(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_uS_T_u32);

	/* Get the results buffer data from the feedback path conversion */
	while((Adc_GetGroupStatus(AdcFdbkPath)== ADC_BUSY) && (TimeOut_Cnt_T_lgc == D_FALSE_CNT_LGC))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_uS_T_u32, &ElapsedTime_uS_T_u16);

		if( ElapsedTime_uS_T_u16 >= k_MaxADCConvTime_uS_u16 )
		{
			/* Set ADC End of Conversion fault and exit loop */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
			TimeOut_Cnt_T_lgc = D_TRUE_CNT_LGC;
		}
	}

	(void)Adc_ReadGroup ( AdcFdbkPath, IO_FdbkPthAdcBufRead_M_Cnt );
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
