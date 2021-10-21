/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqBasedInrtCmp.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/TrqBasedInrtCmp-nzt9hv/TrqBasedInrtCmp/autosar
 *     SW-C Type:  Ap_TrqBasedInrtCmp
 *  Generated at:  Mon Nov  5 13:35:42 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqBasedInrtCmp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Nov 15 15:41:24 2011
 * %version:          11 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Tue Nov 27 17:38:04 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/15/11  1        LWW       Initial component stub
 * 11/21/11  1.0      BG        Initial Implementation
 * 12/2/11   2.0      BG        Updated declaration for "HwTrq_HwNm_T_s7p8" local variable in "TrqBasedInrtCmp_Per1"
 *								function.	
 * 12/9/11   3.0      BG		changed truncation to rounding in calculation of Counts
 * 05/02/12  4.0      NRAR      FaultInjectionPoint is added
 * 08/29/12  5.0      JWJ       Changed filters to floating point to correct anomaly #3642
 * 09/23/12  8        Selva      Checkpoints added and mempmap macros corrected		                          6251 
 * 11/4/12   9		  Selva		Corrected for FDD version 3. "Added lookup table for filter#2 cutoff fre.	  
 *								Corrected calibration table for naming convention."	
 * 11/26/12  10       NRAR      Change the argument t2_TBICGain_Uls_u0p16[0] in bilinear to the               6879
 *								typical implementation found in other invocations
 * 11/27/12  11       KJS      	Updated data dictionary for calibration gain table and HwTrq input resolution 6893
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TrqBasedInrtCmp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_TrqBasedInrtCmp_Cfg.h"
#define   D_PRECISION16BIT_ULS_F32     65536.0F 

#define TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

STATIC volatile VAR(float32, AP_TRQBASEDINRTCMP_VAR_NOINIT) HP1FiltHwTrq_HwNm_D_f32;
STATIC volatile VAR(float32, AP_TRQBASEDINRTCMP_VAR_NOINIT) HP2FiltHwTrq_HwNm_D_f32;
STATIC volatile VAR(float32, AP_TRQBASEDINRTCMP_VAR_NOINIT) FinalGain_Uls_D_f32;
#define TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


#define TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(LPF32KSV_Str, AP_TRQBASEDINRTCMP_VAR_NOINIT) HwTrqFilt1SV_HwNm_M_str;
STATIC VAR(LPF32KSV_Str, AP_TRQBASEDINRTCMP_VAR_NOINIT) HwTrqFilt2SV_HwNm_M_str;
#define TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

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
 * Double: Real in interval ]-DBL_MAX...DBL_MAX[ with double precision including NaN (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
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
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt32: D_ZERO_CNT_U32 = 0u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQBASEDINRTCMP_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqBasedInrtCmp_Per1
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
 *   Float Rte_IRead_TrqBasedInrtCmp_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_TrqBasedInrtCmp_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqBasedInrtCmp_Per1_HighFreqAssist_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqBasedInrtCmp_Per1_HighFreqAssist_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQBASEDINRTCMP_APPL_CODE) TrqBasedInrtCmp_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqBasedInrtCmp_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4;
	VAR(float32, AUTOMATIC) Filt1HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) Filt2HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HP1FiltHwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HP2FiltHwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HighFreqAssist_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) FinalGain_Uls_T_f32;
	VAR(float32, AUTOMATIC) TBICFc1LPF_Hz_T_f32;
	VAR(float32, AUTOMATIC) TBICFc2LPF_Hz_T_f32;
	VAR(uint16, AUTOMATIC) TBICFc1LPF_Hz_T_u8p8;
	VAR(uint16, AUTOMATIC) TBICGain_Uls_T_u0p16;
    VAR(uint16, AUTOMATIC) TBICFc2LPF_Hz_T_u8p8;
	VAR(uint16, AUTOMATIC) AbsHwTrq_HwNm_T_u4p12;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_TrqBasedInrtCmp_Per1_CP0_CheckpointReached();

	/* Store Inputs in Local Copies*/
	VehSpd_Kph_T_u12p4 = FPM_FloatToFixed_m((Rte_IRead_TrqBasedInrtCmp_Per1_VehicleSpeed_Kph_f32()), u12p4_T);
	HwTrq_HwNm_T_f32 = Rte_IRead_TrqBasedInrtCmp_Per1_HwTorque_HwNm_f32();
	AbsHwTrq_HwNm_T_u4p12 = FPM_FloatToFixed_m(Abs_f32_m(HwTrq_HwNm_T_f32), u4p12_T);
	/** Calculate FC1 for Filter-1*/
	TBICFc1LPF_Hz_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt( t_TBICVehSpd_Kph_u12p4,  
															   t_TBICFc1LPFKn_Hz_u8p8 ,
														      TableSize_m(t_TBICVehSpd_Kph_u12p4),
											                   VehSpd_Kph_T_u12p4);
	/** Calculate FC1 for Filter-2*/
	TBICFc2LPF_Hz_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt( t_TBICVehSpd_Kph_u12p4,  
															   t_TBICFc2LPFKn_Hz_u8p8 ,
														      TableSize_m(t_TBICVehSpd_Kph_u12p4),
											                   VehSpd_Kph_T_u12p4);															

	/** Calculate Frequencies in Hz */
	TBICFc1LPF_Hz_T_f32 = FPM_FixedToFloat_m(TBICFc1LPF_Hz_T_u8p8, u8p8_T);
	TBICFc2LPF_Hz_T_f32 = FPM_FixedToFloat_m(TBICFc2LPF_Hz_T_u8p8, u8p8_T);
	
	/** Calculate TBIC Gain Factor for Filter-1 */
	TBICGain_Uls_T_u0p16 = BilinearXYM_u16_u16Xu16YM_Cnt(
								VehSpd_Kph_T_u12p4,
								AbsHwTrq_HwNm_T_u4p12,
								t_TBICVehSpd_Kph_u12p4, 
								TableSize_m(t_TBICVehSpd_Kph_u12p4),
								t_TBICHwTrq_HwNm_u4p12,
								(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_TBICGain_Uls_u0p16,
								TableSize_m(t_TBICHwTrq_HwNm_u4p12));
	
	/** Filter-1 */
    LPF_KUpdate_f32_m(TBICFc1LPF_Hz_T_f32, D_2MS_SEC_F32, &HwTrqFilt1SV_HwNm_M_str);
    Filt1HwTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTrq_HwNm_T_f32, &HwTrqFilt1SV_HwNm_M_str);
	HP1FiltHwTrq_HwNm_T_f32 = HwTrq_HwNm_T_f32 - Filt1HwTrq_HwNm_T_f32;
	HP1FiltHwTrq_HwNm_D_f32 = HP1FiltHwTrq_HwNm_T_f32;

	/** Filter-2 */
    LPF_KUpdate_f32_m(TBICFc2LPF_Hz_T_f32, D_2MS_SEC_F32, &HwTrqFilt2SV_HwNm_M_str);
    Filt2HwTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(HP1FiltHwTrq_HwNm_T_f32, &HwTrqFilt2SV_HwNm_M_str);
	HP2FiltHwTrq_HwNm_T_f32 = HP1FiltHwTrq_HwNm_T_f32 - Filt2HwTrq_HwNm_T_f32;
	HP2FiltHwTrq_HwNm_D_f32 = HP2FiltHwTrq_HwNm_T_f32;

   /** Calculate Gain MultFactor for Multiplication */
    FinalGain_Uls_T_f32 = ( D_2PI_ULS_F32 * TBICFc1LPF_Hz_T_f32) *  ( D_2PI_ULS_F32 * TBICFc2LPF_Hz_T_f32) * FPM_FixedToFloat_m(TBICGain_Uls_T_u0p16, u0p16_T);
	FinalGain_Uls_D_f32 = FinalGain_Uls_T_f32;

   /** Convert "HwNm" to "MtrNm" */
    HighFreqAssist_MtrNm_T_f32 = HP2FiltHwTrq_HwNm_T_f32 * FinalGain_Uls_T_f32 ;
   

	/** Fault Injection Point */
	#if(STD_ON == BC_TRQBASEDINRTCMP_FAULTINJECTIONPOINT)
	Rte_Call_FltInjection_SCom_FltInjection(&HighFreqAssist_MtrNm_T_f32,FLTINJ_TRQBASEDINRTCOMP);
	#endif

   /* Update Output */
	Rte_IWrite_TrqBasedInrtCmp_Per1_HighFreqAssist_MtrNm_f32(HighFreqAssist_MtrNm_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_TrqBasedInrtCmp_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQBASEDINRTCMP_APPL_CODE
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
