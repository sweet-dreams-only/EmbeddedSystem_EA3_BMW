/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrPos.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrPos/autosar
 *     SW-C Type:  Sa_MtrPos
 *  Generated at:  Wed Feb 20 16:17:50 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrPos>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Dec 13 17:36:32 2010
 * %version:          7 %
 * %derived_by:       xz0btk %
 * %date_modified:    Wed Mar 20 13:23:56 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 06/04/12  1        JWJ       Initial component creation                                                       5336
 * 07/31/12  2        BL        Updated atan2 function
 * 10/23/12  3        OT        Implemented FDD 06B v004 (merged MtrPos, MtrPosDiag, and MtrPosSnsrLearning)     6472
 * 02/05/13  4        JJW       Updated Component design methodology ot encapsulate component internal data flow
 *                               outside of the RTE.
 * 02/06/13  5        JJW       Created separate buffer synchronization signal for 1ms CumMtrPos calculation inputs
 * 02/19/13  6        JJW       Corrected double buffer inconsistent access anomaly
 *								Corrected incorrect polarity signal for CumMtrPosMRF calc anomaly
 * 03/20/13  7        JJW       Corrected cum mtr pos tracking algorithm by replacing rev tracking strategy with
 *								delta position accumulation algorithm.
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

 *********************************************************************************************************************/

#include "Rte_Sa_MtrPos.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define MTRPOS_C
#include "Sa_MtrPos.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "Adc2.h"
#include "SystemTime.h"
#include "atan2.h"
#include "Os.h"	/* included for fixed exclusive area implementation in this module that uses Suspend/Resume interrupts */

#define D_ADCREF_VOLTS_F32                      5.0F
#define D_ADCFULLSCALE_CNTS_U16                 4095U

#define D_CNVRTP29TOP13_CNT_U16					16U
#define D_SCALE_VOLTSPERCOUNT_U3P29				(FPM_InitFixedPoint_m((D_ADCREF_VOLTS_F32/(float32)D_ADCFULLSCALE_CNTS_U16), u3p29_T))
#define D_SIGCORRLOLMT_ULS_S5P26				(FPM_InitFixedPoint_m(-3.0, s5p26_T))
#define D_SIGCORRHILMT_ULS_S5P26				(FPM_InitFixedPoint_m(3.0, s5p26_T))
#define D_SINCOSHILMT_ULS_S2P13					(FPM_InitFixedPoint_m(2.0, s2p13_T))
#define D_SINCOSLOLMT_ULS_S2P13					(FPM_InitFixedPoint_m(-2.0, s2p13_T))
#define D_HARPOSROUNDFACTOR_ULS_U0P16   		(FPM_InitFixedPoint_m(0.003472222222, u0p16_T))
#define D_HALFPREC13_CNT_S32					4096L
#define D_SHIFT13_CNT_S16						13U
#define D_SIGNBITSHIFT32_CNT_U16				31U
#define D_HARTBLSIZE_CNT_U16					144U
#define D_PIREV_REV_U1P15						(FPM_InitFixedPoint_m( 0.5, u1p15_T))

#define D_DEGPERREV_ULS_F32						360.0F

#define D_MASK16BITS_CNT_U16					0xFFFFU

#define MTRPOS_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
       VAR(sint16, AUTOMATIC) MtrPos_SinTheta1_Volts_G_s2p13;
       VAR(sint16, AUTOMATIC) MtrPos_CosTheta1_Volts_G_s2p13;
       VAR(uint16, AUTOMATIC) MtrPos_MechMtrPos_Rev_G_u0p16;
	   VAR(uint16, AUTOMATIC) MtrPos_CorrectedMtrPos_Rev_G_u0p16;

	   /* Consistent signal group required by MtrPos2_Per1 at 2ms rate and required to be synchronized with system
	    * Adc group conversions.  Synchronization is accomplished via a module buffer selector input signal.
	    * A typical integration would have IoHwAb provide the buffer selector signal to synchronize the buffer
	    * freeze with the appropriate Adc group conversion start. */
       VAR(uint16, AUTOMATIC) MtrPos_CorrectedMtrPos_Rev_M_u0p16[D_MTRPOSDBLBUFFSZ_CNT_U08];
       VAR(uint16, AUTOMATIC) MtrPos_Cos1Scaled_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
       VAR(uint16, AUTOMATIC) MtrPos_Sin1Scaled_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
       VAR(uint16, AUTOMATIC) MtrPos_MechMtrPos_Rev_M_u0p16[D_MTRPOSDBLBUFFSZ_CNT_U08];


STATIC volatile VAR(sint16,  SA_MTRPOS_VAR) SinTheta2_Uls_D_s2p13;
#define MTRPOS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
       CONSTP2VAR(MtrPosCal_DataType,  SA_MTRPOS_VAR, AUTOMATIC) MtrPos_EOLDataPtr_Cnt_M_Str = Rte_Pim_MtrPosSnsr_EOLData();
#define MTRPOS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, SA_MTRPOS_VAR) MtrPos_CumMtrPosOff_Deg_M_f32;

/* Individual atomically accessible data required by MtrPos_Per2 at 1ms rate. No consistency required with other signals, thus no double buffering */
STATIC VAR(sint32, AUTOMATIC) tempAlignedCumMtrPosMRF_Rev_M_s15p16;

VAR(uint32, AUTOMATIC) MtrPos_SampleTime_uS_G_u32;
#define MTRPOS_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, SA_MTRPOS_VAR) MtrPos_CumMtrPosOffComplete_Cnt_M_lgc;
#define MTRPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

FUNC(void, SA_MTRPOS_CODE) MtrPos_Per1(void);


STATIC INLINE FUNC(sint16, SA_MTRPOS_CODE) SignalCorrect(VAR(uint16, AUTOMATIC) Signal_Volts_T_u3p13,
														 VAR(uint16, AUTOMATIC) Offset_Volts_T_u3p13,
														 VAR(uint16, AUTOMATIC) AmpRec_Uls_T_u3p13);

STATIC INLINE FUNC(sint16, SA_MTRPOS_CODE) QuadCorrect(VAR(sint16, AUTOMATIC) CorrSin_Uls_T_s2p13,
													   VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13,
													   VAR(sint16, AUTOMATIC) SinDelta_Uls_T_s2p13);

STATIC INLINE FUNC(sint32, SA_MTRPOS_CODE) RoundAndShift13_s32(VAR(sint32, AUTOMATIC) x);


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
 * DT_Array144_s8: Array with 144 element(s) of type SInt8
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * MtrPosCal_DataType: Record with elements
 *   BEMFCal_Rev_u0p16 of type UInt16
 *   R_BEMFCal_Rev_u0p16 of type UInt16
 *   Sin1Offset_Volts_u3p13 of type UInt16
 *   Sin1AmpRec_Uls_u3p13 of type UInt16
 *   Cos1Offset_Volts_u3p13 of type UInt16
 *   Cos1AmpRec_Uls_u3p13 of type UInt16
 *   SinDelta1_Uls_s2p13 of type SInt16
 *   CosDelta1Rec_Uls_u3p13 of type UInt16
 *   Sin1OffCorr_Volts_s2p13 of type SInt16
 *   Sin1GainCorr_Uls_u1p15 of type UInt16
 *   Cos1OffCorr_Volts_s2p13 of type SInt16
 *   Cos1GainCorr_Uls_u1p15 of type UInt16
 *   SinHarTbl_Cnt_sm6p13 of type DT_Array144_s8
 *   CosHarTbl_Cnt_sm6p13 of type DT_Array144_s8
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   MtrPosCal_DataType *Rte_Pim_MtrPosSnsr_EOLData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRPOS_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos_Init1
 *********************************************************************************************************************/
	
	MtrPos_Per1();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_Per2
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
 *   SInt8 Rte_IRead_MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_CumMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_CumMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_CumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_CumMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) AlignedCumMtrPosMRF_Deg_T_f32;
	VAR(float32, AUTOMATIC) CumMtrPosMRF_Deg_T_f32;
	VAR(float32, AUTOMATIC) tempAlignedCumMtrPosMRF_Rev_T_f32;
	VAR(float32, AUTOMATIC) AssistAsmPolarity_T_f32;

	AssistAsmPolarity_T_f32 = (float32)Rte_IRead_MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08();

	tempAlignedCumMtrPosMRF_Rev_T_f32 = FPM_FixedToFloat_m(tempAlignedCumMtrPosMRF_Rev_M_s15p16, s15p16_T);
 
	if( MtrPos_CumMtrPosOffComplete_Cnt_M_lgc == FALSE )
	{
		MtrPos_CumMtrPosOffComplete_Cnt_M_lgc = TRUE;
		MtrPos_CumMtrPosOff_Deg_M_f32 = tempAlignedCumMtrPosMRF_Rev_T_f32 * D_DEGPERREV_ULS_F32;
	}
	
	AlignedCumMtrPosMRF_Deg_T_f32 = tempAlignedCumMtrPosMRF_Rev_T_f32 * D_DEGPERREV_ULS_F32;
	CumMtrPosMRF_Deg_T_f32 = AlignedCumMtrPosMRF_Deg_T_f32 - MtrPos_CumMtrPosOff_Deg_M_f32;

	Rte_IWrite_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(AlignedCumMtrPosMRF_Deg_T_f32);
	Rte_IWrite_MtrPos_Per2_CumMtrPosMRF_Deg_f32(CumMtrPosMRF_Deg_T_f32);
	Rte_IWrite_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(CumMtrPosMRF_Deg_T_f32);
	Rte_IWrite_MtrPos_Per2_CumMtrPosCRF_Deg_f32(CumMtrPosMRF_Deg_T_f32 * AssistAsmPolarity_T_f32);
	Rte_IWrite_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(CumMtrPosMRF_Deg_T_f32 * AssistAsmPolarity_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_SCom_ReadEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadEOLMtrCals> of PortPrototype <MtrPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrPos_SCom_ReadEOLMtrCals(MtrPosCal_DataType *MtrCalDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos_SCom_ReadEOLMtrCals
 *********************************************************************************************************************/

 *MtrCalDataPtr = *Rte_Pim_MtrPosSnsr_EOLData();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_SCom_SetEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLMtrCals> of PortPrototype <MtrPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLMtrCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLMtrCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrPos_SCom_SetEOLMtrCals(const MtrPosCal_DataType *MtrCalDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos_SCom_SetEOLMtrCals
 *********************************************************************************************************************/

	/* Provide exclusive area around EOL Data update to ensure the data stays consistent.  If the BEMF R/C check, for 
	 * example, pre-empts this update while the BEMF and R_BEMF values are inconsistent, a false failure will be detected.
	 * For simplicity, this implementation of the exclusive area protection does not provide a configurable type of 
	 * protection, but rather always uses Suspend/Resume interrupts.  If the need arises in the future this design can 
	 * be updated.
	 */
	 
	SuspendAllInterrupts(); /* Enter exclusive area */
	*Rte_Pim_MtrPosSnsr_EOLData() = *MtrCalDataPtr;
	Rte_Pim_MtrPosSnsr_EOLData()->R_BEMFCal_Rev_u0p16 = ~(Rte_Pim_MtrPosSnsr_EOLData()->BEMFCal_Rev_u0p16);
	ResumeAllInterrupts(); /* Exit exclusive area */
	
	(void)Rte_Call_EOLMtrCals_WriteBlock(NULL_PTR);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRPOS_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


FUNC(void, SA_MTRPOS_CODE) MtrPos_Per1(void)
{
	
	VAR(uint8, AUTOMATIC) ActvDblBuf_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) LrnParamBfr_Cnt_T_u08;
	VAR(sint16, AUTOMATIC) SinTheta2_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) CosTheta2_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) SinTheta1_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) CosTheta1_Uls_T_s2p13;
	VAR(uint16, AUTOMATIC) HarLkpPos_Rev_T_u0p16;
	VAR(uint16, AUTOMATIC) HarLkpIndex_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrPosMech_Rev_T_u0p16;
	VAR(uint16, AUTOMATIC) OldMtrPosMech_Rev_T_u0p16;
	VAR(uint16, AUTOMATIC) CorrMtrPosElec_Rev_T_u0p16;
	VAR(uint16, AUTOMATIC) Sin1Scaled_Volts_T_u3p13;
	VAR(uint16, AUTOMATIC) Cos1Scaled_Volts_T_u3p13;
	VAR(uint32, AUTOMATIC) SampleTime_uS_T_u32;
	VAR(sint32, AUTOMATIC) MtrPosMech_Rev_T_s26p15;
	
	OldMtrPosMech_Rev_T_u0p16 = MtrPos_MechMtrPos_Rev_G_u0p16; /* Capture the previous output for use in this runnable processing */
	CDD_Read_MtrPos_ActvDblBuf_Cnt_u08(&ActvDblBuf_Cnt_T_u08);
	LrnParamBfr_Cnt_T_u08 = MtrPos2_LearnedParamBfr_Cnt_M_u08;
	GetSystemTime_uS_u32(&SampleTime_uS_T_u32);
	Sin1Scaled_Volts_T_u3p13 = (uint16)(((uint32)Adc2_GetSinTheta1_Cnt_u16_m * D_SCALE_VOLTSPERCOUNT_U3P29)>>D_CNVRTP29TOP13_CNT_U16);
	SinTheta2_Uls_T_s2p13 = SignalCorrect(Sin1Scaled_Volts_T_u3p13, MtrPos2_Sin1RTOffset_Volts_M_u3p13[LrnParamBfr_Cnt_T_u08], MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[LrnParamBfr_Cnt_T_u08]);
   	Cos1Scaled_Volts_T_u3p13 = (uint16)(((uint32)Adc2_GetCosTheta1_Cnt_u16_m * D_SCALE_VOLTSPERCOUNT_U3P29)>>D_CNVRTP29TOP13_CNT_U16);
   	CorrCos_Uls_T_s2p13 = SignalCorrect(Cos1Scaled_Volts_T_u3p13, MtrPos2_Cos1RTOffset_Volts_M_u3p13[LrnParamBfr_Cnt_T_u08], MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[LrnParamBfr_Cnt_T_u08]);
	CosTheta2_Uls_T_s2p13 = QuadCorrect(SinTheta2_Uls_T_s2p13, CorrCos_Uls_T_s2p13, (Rte_Pim_MtrPosSnsr_EOLData()->SinDelta1_Uls_s2p13));
	
	HarLkpPos_Rev_T_u0p16 = OldMtrPosMech_Rev_T_u0p16 + D_HARPOSROUNDFACTOR_ULS_U0P16;
	HarLkpIndex_Cnt_T_u16 = (uint16)(((uint32)HarLkpPos_Rev_T_u0p16*(uint32)D_HARTBLSIZE_CNT_U16)>>16);
	SinTheta1_Uls_T_s2p13 = SinTheta2_Uls_T_s2p13 - (sint16)(Rte_Pim_MtrPosSnsr_EOLData()->SinHarTbl_Cnt_sm6p13[HarLkpIndex_Cnt_T_u16]);
	CosTheta1_Uls_T_s2p13 = CosTheta2_Uls_T_s2p13 - (sint16)(Rte_Pim_MtrPosSnsr_EOLData()->CosHarTbl_Cnt_sm6p13[HarLkpIndex_Cnt_T_u16]);
	
	MtrPosMech_Rev_T_s26p15 = _atan2_asm_(SinTheta1_Uls_T_s2p13, CosTheta1_Uls_T_s2p13);
	if (MtrPosMech_Rev_T_s26p15 < 0UL)
	{
		MtrPosMech_Rev_T_s26p15 = MtrPosMech_Rev_T_s26p15 + (sint32)D_PIREV_REV_U1P15;
	}
	
	MtrPosMech_Rev_T_u0p16 = (uint16)MtrPosMech_Rev_T_s26p15 << 1U;
	
	/* Explicitly apply a mask(D_MASK16BITS_CNT_U16) to mask all bits above bit 15 out after the subtraction.  It is expected that the compiler will optimize 
	 * the masking operation out when appropriate 16 bit operations are available.  Additionally, the mask provides an explicit
	 * specification of operation for the unit test.
	 */
   	CorrMtrPosElec_Rev_T_u0p16 = ((MtrPosMech_Rev_T_u0p16 * 3U) - (Rte_Pim_MtrPosSnsr_EOLData()->BEMFCal_Rev_u0p16)) & D_MASK16BITS_CNT_U16;
	
	SinTheta2_Uls_D_s2p13 = SinTheta2_Uls_T_s2p13;
   	
	SinTheta1_Uls_T_s2p13 = Limit_m(SinTheta1_Uls_T_s2p13, D_SINCOSLOLMT_ULS_S2P13, D_SINCOSHILMT_ULS_S2P13);
	CosTheta1_Uls_T_s2p13 = Limit_m(CosTheta1_Uls_T_s2p13, D_SINCOSLOLMT_ULS_S2P13, D_SINCOSHILMT_ULS_S2P13);

	/* Update internally shared CumMtrPos calculation signal consumed by the 1ms Per2 runnable */
	/* Explicitly apply a mask(D_MASK16BITS_CNT_U16) to mask all bits above bit 15 out after the subtraction.  It is expected that the compiler will optimize
	 * the masking operation out when appropriate 16 bit operations are available.  Additionally, the mask provides an explicit
	 * specification of operation for the unit test.
	 */
	 /* MISRA-C:2004 Rule 10.3 exception: The following line violates a MISRA rule intentionally because the wrap-around functionality is required */
	tempAlignedCumMtrPosMRF_Rev_M_s15p16 += (sint32)((sint16)((MtrPosMech_Rev_T_u0p16 - OldMtrPosMech_Rev_T_u0p16) & D_MASK16BITS_CNT_U16));

	/* Update externally synchronized signal group */
	MtrPos_Sin1Scaled_Volts_M_u3p13[ActvDblBuf_Cnt_T_u08] = Sin1Scaled_Volts_T_u3p13;
	MtrPos_Cos1Scaled_Volts_M_u3p13[ActvDblBuf_Cnt_T_u08] = Cos1Scaled_Volts_T_u3p13;
	MtrPos_MechMtrPos_Rev_M_u0p16[ActvDblBuf_Cnt_T_u08] = MtrPosMech_Rev_T_u0p16;
	MtrPos_CorrectedMtrPos_Rev_M_u0p16[ActvDblBuf_Cnt_T_u08] = CorrMtrPosElec_Rev_T_u0p16;

	/* Update Global Outputs for use in the Mtr Ctrl ISR */
	MtrPos_SampleTime_uS_G_u32 = SampleTime_uS_T_u32;
	MtrPos_SinTheta1_Volts_G_s2p13 = SinTheta1_Uls_T_s2p13;
	MtrPos_CosTheta1_Volts_G_s2p13 = CosTheta1_Uls_T_s2p13;	
	MtrPos_CorrectedMtrPos_Rev_G_u0p16 = CorrMtrPosElec_Rev_T_u0p16;
	MtrPos_MechMtrPos_Rev_G_u0p16 = MtrPosMech_Rev_T_u0p16;
}


STATIC INLINE FUNC(sint16, SA_MTRPOS_CODE) QuadCorrect(VAR(sint16, AUTOMATIC) CorrSin_Uls_T_s2p13,
													   VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13,
													   VAR(sint16, AUTOMATIC) SinDelta_Uls_T_s2p13)
{
	
	VAR(sint32, AUTOMATIC) CosAdjust_Uls_T_s5p26;
	VAR(sint16, AUTOMATIC) CosAdjust_Uls_T_s2p13;
	
	CosAdjust_Uls_T_s5p26 = (sint32)CorrSin_Uls_T_s2p13 * (sint32)SinDelta_Uls_T_s2p13;
	CosAdjust_Uls_T_s2p13 = (sint16)RoundAndShift13_s32(CosAdjust_Uls_T_s5p26);
	CorrCos_Uls_T_s2p13 = CorrCos_Uls_T_s2p13 + CosAdjust_Uls_T_s2p13;
	
	return(CorrCos_Uls_T_s2p13);
	
}


STATIC INLINE FUNC(sint16, SA_MTRPOS_CODE) SignalCorrect(VAR(uint16, AUTOMATIC) Signal_Volts_T_u3p13,
														 VAR(uint16, AUTOMATIC) Offset_Volts_T_u3p13,
														 VAR(uint16, AUTOMATIC) AmpRec_Uls_T_u3p13)
{
	
	VAR(sint16, AUTOMATIC) Signal_Volts_T_s2p13;
	VAR(sint32, AUTOMATIC) Signal_Uls_T_s5p26;
	VAR(sint16, AUTOMATIC) Signal_Uls_T_s2p13;
	
	Signal_Volts_T_s2p13 = (sint16)Signal_Volts_T_u3p13 - (sint16)Offset_Volts_T_u3p13;
	Signal_Uls_T_s5p26 = (sint32)Signal_Volts_T_s2p13 * (sint32)AmpRec_Uls_T_u3p13;
	Signal_Uls_T_s5p26 = Limit_m(Signal_Uls_T_s5p26, D_SIGCORRLOLMT_ULS_S5P26, D_SIGCORRHILMT_ULS_S5P26);
	Signal_Uls_T_s2p13 = (sint16)RoundAndShift13_s32(Signal_Uls_T_s5p26);
	
	return(Signal_Uls_T_s2p13);
	
}


STATIC INLINE FUNC(sint32, SA_MTRPOS_CODE) RoundAndShift13_s32(VAR(sint32, AUTOMATIC) x)
{
	return(((x)+(D_HALFPREC13_CNT_S32-(sint32)((uint32)(x)>>D_SIGNBITSHIFT32_CNT_U16)))>>D_SHIFT13_CNT_S16);
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
