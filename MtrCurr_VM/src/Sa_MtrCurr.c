/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrCurr.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrCurr_VM/autosar
 *     SW-C Type:  Sa_MtrCurr
 *  Generated at:  Mon Feb  4 10:19:03 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrCurr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Jun  3 08:20:17 2011
 * %version:          9 %
 * %derived_by:       xz0btk %
 * %date_modified:    Mon Feb  4 10:12:48 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/03/11   6       LWW       Fixed access macro in MtrCurr_SCom_CalGain,
 *                              Added mode disabling to meet requirements, added version log
 * 01/04/12   7       JJW       InstMtrDir Port changed to standard port definition for integration of CBD QuadDet
 *                               SF99_002.0
 * 10/16/12   8       OT        Initial component version (FDD 01B v008)
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_MtrCurr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Sa_MtrCurr_Cfg.h"


#include "fixmath.h"
#include "interpolation.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include <math.h>


#define D_30DEGREES_REV_F32				0.08333333333F
#define D_120DEGREES_REV_F32			0.33333333333F
#define D_150DEGREES_REV_F32			0.41666666666F
#define D_180DEGREES_REV_F32			0.5F
#define D_CURRENTLOWLIMIT_AMP_F32		0.0F
#define D_MEASDAXCURRHILMT_AMP_F32		255.0F
#define D_MEASQAXCURRHILMT_AMP_F32		255.0F
#define D_MTRCURRGAINMIN_ULS_F32		0.7F
#define D_MTRCURRGAINMAX_ULS_F32		1.3F


#define MTRCURR_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, SA_MTRCURR_VAR_NOINIT) InvldRgnHi_Rev_M_f32;
STATIC VAR(float32, SA_MTRCURR_VAR_NOINIT) InvldRgnLo_Rev_M_f32;
STATIC VAR(float32, SA_MTRCURR_VAR_NOINIT) FiltShcur_Volts_M_f32;
STATIC VAR(float32, SA_MTRCURR_VAR_NOINIT) MtrCurrDax_Amp_M_f32;
STATIC VAR(float32, SA_MTRCURR_VAR_NOINIT) MtrCurrQax_Amp_M_f32;
#define MTRCURR_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define MTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, SA_MTRCURR_VAR_NOINIT) ShCurLpFltrKSV_Cnt_M_str;
#define MTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * ShCurrCal_DataType: Record with elements
 *   EOLShcurrOffset_Volts_f32 of type Float
 *   EOLShcurrGain_Uls_f32 of type Float
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
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   ShCurrCal_DataType *Rte_Pim_ShCurrCal(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRCURR_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_Init1
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_Init1
 *********************************************************************************************************************/
	
	
	InvldRgnLo_Rev_M_f32 = D_30DEGREES_REV_F32 + k_PosTrnsInvldRgn_Rev_f32;
	InvldRgnHi_Rev_M_f32 = D_150DEGREES_REV_F32 - k_PosTrnsInvldRgn_Rev_f32;
	LPF_KUpdate_f32_m(k_MtrCurrFltrKn_Hz_f32, D_2MS_SEC_F32, &ShCurLpFltrKSV_Cnt_M_str);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_MtrCurr_Per1_ADCMtrCurr1_Volt_f32(void)
 *   Float Rte_IRead_MtrCurr_Per1_CorrectedMtrPos_Rev_f32(void)
 *   UInt16 Rte_IRead_MtrCurr_Per1_DutyCycleSmall_Cnt_u16(void)
 *   SInt8 Rte_IRead_MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08(void)
 *   UInt16 Rte_IRead_MtrCurr_Per1_PADelta1_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrCurr_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_RawCurrFiltered_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_RawCurrFiltered_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_Per1
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) ADCMtrCurr1_Volts_T_f32;
	VAR(sint8,   AUTOMATIC) InstMtrDir_Cnt_T_s08;
	VAR(float32, AUTOMATIC) CorrectedMtrPos_Rev_T_f32;
	VAR(uint16,  AUTOMATIC) DutyCycleSmall_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) PADelta1_Cnt_T_u16;
	VAR(float32, AUTOMATIC) RawCurrFiltered_Volts_T_f32;
	VAR(float32, AUTOMATIC) PosTrans_Rev_T_f32;
	VAR(sint16,  AUTOMATIC) ShcurOffCorr_Volts_T_s2p13;
	VAR(float32, AUTOMATIC) ShcurOffCorr_Volts_T_f32;
	VAR(float32, AUTOMATIC) Shcur_Volt_T_f32;
	VAR(float32, AUTOMATIC) Shcur_Amp_T_f32;
	VAR(float32, AUTOMATIC) SinPosTrans_Uls_T_f32;
	VAR(float32, AUTOMATIC) PeakPhaseCurr_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrDax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax_Amp_T_f32;
	VAR(float32, AUTOMATIC) RawCurrFiltered_Amp_T_f32;
	VAR(boolean, AUTOMATIC) ValidCurrSample_Cnt_T_lgc;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrCurr_Per1_CP0_CheckpointReached();
	
	
	ADCMtrCurr1_Volts_T_f32 = Rte_IRead_MtrCurr_Per1_ADCMtrCurr1_Volt_f32();
	InstMtrDir_Cnt_T_s08 = Rte_IRead_MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08();
	CorrectedMtrPos_Rev_T_f32 = Rte_IRead_MtrCurr_Per1_CorrectedMtrPos_Rev_f32();
	DutyCycleSmall_Cnt_T_u16 = Rte_IRead_MtrCurr_Per1_DutyCycleSmall_Cnt_u16();
	PADelta1_Cnt_T_u16 = Rte_IRead_MtrCurr_Per1_PADelta1_Cnt_u16();
	PADelta1_Cnt_T_u16 = Limit_m(PADelta1_Cnt_T_u16, D_ZERO_CNT_U16, TableSize_m(T_SINELKPTBL_ULS_F32) - D_ONE_CNT_U16);
	
	
	
	FiltShcur_Volts_M_f32 = LPF_OpUpdate_f32_m(ADCMtrCurr1_Volts_T_f32, &ShCurLpFltrKSV_Cnt_M_str);
	
	RawCurrFiltered_Volts_T_f32 = (ADCMtrCurr1_Volts_T_f32 - (Rte_Pim_ShCurrCal()->EOLShcurrOffset_Volts_f32)) *
								  (Rte_Pim_ShCurrCal()->EOLShcurrGain_Uls_f32);
	RawCurrFiltered_Amp_T_f32 = RawCurrFiltered_Volts_T_f32 * k_CurrentScale_AmpspVolt_f32;
	
	
	
	/** Motor Position Transform **/
	
	if (((sint16)InstMtrDir_Cnt_T_s08 * k_MtrCurrPolarity_Cnt_s16) == D_NEGONE_CNT_S16)
	{
		if (CorrectedMtrPos_Rev_T_f32 >= D_180DEGREES_REV_F32)
		{
			PosTrans_Rev_T_f32 = CorrectedMtrPos_Rev_T_f32 - D_180DEGREES_REV_F32;
		}
		else
		{
			PosTrans_Rev_T_f32 = CorrectedMtrPos_Rev_T_f32 + D_180DEGREES_REV_F32;
		}
	}
	else
	{
		PosTrans_Rev_T_f32 = CorrectedMtrPos_Rev_T_f32;
	}
	
	while (PosTrans_Rev_T_f32 >= D_120DEGREES_REV_F32)
	{
		PosTrans_Rev_T_f32 = PosTrans_Rev_T_f32 - D_120DEGREES_REV_F32;
	}
	
	PosTrans_Rev_T_f32 = PosTrans_Rev_T_f32 + D_30DEGREES_REV_F32;
	
	if ((PosTrans_Rev_T_f32 > InvldRgnLo_Rev_M_f32) && (PosTrans_Rev_T_f32 < InvldRgnHi_Rev_M_f32))
	{
		ValidCurrSample_Cnt_T_lgc = TRUE;
	}
	else
	{
		ValidCurrSample_Cnt_T_lgc = FALSE;
	}
	
	
	
	ShcurOffCorr_Volts_T_s2p13 = IntplVarXY_s16_u16Xs16Y_Cnt(	t_WidthDutySmallTblX_Cnt_u16,
                                                      			t_ShcurOffCorrTblY_Volts_s2p13,
                                                      			TableSize_m(t_WidthDutySmallTblX_Cnt_u16),
                                                      			DutyCycleSmall_Cnt_T_u16);
	
	ShcurOffCorr_Volts_T_f32 = FPM_FixedToFloat_m(ShcurOffCorr_Volts_T_s2p13, s2p13_T);
	
	Shcur_Volt_T_f32 = RawCurrFiltered_Volts_T_f32 + ShcurOffCorr_Volts_T_f32;
	
	Shcur_Volt_T_f32 = Max_m(Shcur_Volt_T_f32, D_ZERO_ULS_F32);
	
	Shcur_Amp_T_f32 = Shcur_Volt_T_f32 * k_CurrentScale_AmpspVolt_f32;
	
	
	SinPosTrans_Uls_T_f32 = sinf((PosTrans_Rev_T_f32 * D_2PI_ULS_F32));
	PeakPhaseCurr_Amp_T_f32 = Shcur_Amp_T_f32 / SinPosTrans_Uls_T_f32;
	
	
	MtrCurrDax_Amp_T_f32 = PeakPhaseCurr_Amp_T_f32 * T_SINELKPTBL_ULS_F32[PADelta1_Cnt_T_u16];
	MtrCurrQax_Amp_T_f32 = PeakPhaseCurr_Amp_T_f32 * T_SINELKPTBL_ULS_F32[(TableSize_m(T_SINELKPTBL_ULS_F32)-1U) - PADelta1_Cnt_T_u16];
	
	MtrCurrDax_Amp_T_f32 = Limit_m(MtrCurrDax_Amp_T_f32, D_CURRENTLOWLIMIT_AMP_F32, D_MEASDAXCURRHILMT_AMP_F32);
	MtrCurrQax_Amp_T_f32 = Limit_m(MtrCurrQax_Amp_T_f32, D_CURRENTLOWLIMIT_AMP_F32, D_MEASQAXCURRHILMT_AMP_F32);
	
	if( ValidCurrSample_Cnt_T_lgc == TRUE )
	{
		MtrCurrDax_Amp_M_f32 = MtrCurrDax_Amp_T_f32;
		MtrCurrQax_Amp_M_f32 = MtrCurrQax_Amp_T_f32;
	}
	
	
	
	Rte_IWrite_MtrCurr_Per1_MtrCurrDax_Amp_f32(MtrCurrDax_Amp_M_f32);
	Rte_IWrite_MtrCurr_Per1_MtrCurrQax_Amp_f32(MtrCurrQax_Amp_M_f32);
	Rte_IWrite_MtrCurr_Per1_RawCurrFiltered_Amp_f32(RawCurrFiltered_Amp_T_f32);
	Rte_IWrite_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(ValidCurrSample_Cnt_T_lgc);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrCurr_Per1_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <MtrCurr_SCom>
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
 *   Std_ReturnType Rte_Call_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MtrCurr_SCom_CurrentOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalGain(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_SCom_CalGain (returns application error)
 *********************************************************************************************************************/
	
	
	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(float32, AUTOMATIC) FiltShcur_Volts_T_f32;
	VAR(float32, AUTOMATIC) ShcurOff_Volts_T_f32;
	VAR(float32, AUTOMATIC) ShcurGain_Uls_T_f32;
	
	
	FiltShcur_Volts_T_f32 = FiltShcur_Volts_M_f32;
	ShcurOff_Volts_T_f32 = Rte_Pim_ShCurrCal()->EOLShcurrOffset_Volts_f32;
	
	
	if (FiltShcur_Volts_T_f32 > ShcurOff_Volts_T_f32)
	{
		ShcurGain_Uls_T_f32 = k_CurrGainNumerator_Volts_f32 / (FiltShcur_Volts_T_f32 - ShcurOff_Volts_T_f32);
		
		if ((ShcurGain_Uls_T_f32 > D_MTRCURRGAINMIN_ULS_F32) && (ShcurGain_Uls_T_f32 < D_MTRCURRGAINMAX_ULS_F32))
		{
			Rte_Pim_ShCurrCal()->EOLShcurrGain_Uls_f32 = ShcurGain_Uls_T_f32;
			Rte_Call_EOLShCurrCal_SetRamBlockStatus(TRUE);
			RetCode = RTE_E_OK;
		}
		else
		{
			RetCode = RTE_E_MtrCurr_SCom_CurrentOutOfRange;
		}
	}
	else
	{
		RetCode = RTE_E_MtrCurr_SCom_CurrentOutOfRange;
	}
	
	
	return(RetCode);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <MtrCurr_SCom>
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
 *   void MtrCurr_SCom_CalOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_SCom_CalOffset
 *********************************************************************************************************************/
	
	
	Rte_Pim_ShCurrCal()->EOLShcurrOffset_Volts_f32 = FiltShcur_Volts_M_f32;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_ReadMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadMtrCurrCals> of PortPrototype <MtrCurr_SCom>
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
 *   void MtrCurr_SCom_ReadMtrCurrCals(ShCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_SCom_ReadMtrCurrCals
 *********************************************************************************************************************/
	
	
	*ShCurrCalPtr = *Rte_Pim_ShCurrCal();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <MtrCurr_SCom>
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
 *   void MtrCurr_SCom_SetMtrCurrCals(const ShCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCurr_SCom_SetMtrCurrCals
 *********************************************************************************************************************/
	
	
	*Rte_Pim_ShCurrCal() = *ShCurrCalPtr;
	Rte_Call_EOLShCurrCal_SetRamBlockStatus(TRUE);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
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
