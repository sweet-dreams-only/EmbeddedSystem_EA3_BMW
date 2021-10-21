/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_HystAdd.c
 *     Workspace:  C:/ccm_wa/CBD/HystAdd/autosar/Ap_HystAdd.dcf
 *     SW-C Type:  Ap_HystAdd
 *  Generated at:  Tue Nov 15 15:33:13 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_HystAdd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Nov 15 15:41:24 2011
 * %version:          2 %
 * %derived_by:       tzj9qy %
 * %date_modified:    Tue Nov 22 10:06:56 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/15/11  1        LWW       Initial component stub
 * 11/21/11  1        BG        Initial Implementation
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_HystAdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"


#define   D_MINHYSADDPRECISION_ULS_F32     0.00390625F
#define   D_HALF_ULS_F32     0.5F 
#define   D_NEGATIVESIGN_ULS_F32     -1.0F
#define   D_MINFRACTION_ULS_F32     0.0F
#define   D_MAXFRACTION_ULS_F32     1.0F
#define   D_MINHYSPOSITION_ULS_F32     -1.0F
#define   D_MAXHYSPOSITION_ULS_F32     1.0F
#define   D_MINCORRTRQ_HWNM_F32     0.0F
#define   D_MAXCORRTRQ_HWNM_F32     1.0F
#define   D_MINSLOPEMULFAC_ULS_F32     0.1F
#define   D_MAXSLOPEMULFAC_ULS_F32     1.0F
#define   D_MINAVAILHYS_HWNM_F32     0.0F
#define   D_MAXAVAILHYS_HWNM_F32     10.0F
#define   D_INVFPRANGETRQCHG_ULS_F32     0.03125F

STATIC volatile VAR(float32, AP_HYSTADD_VAR_NOINIT) AvailHyst_HwNm_D_f32;
STATIC volatile VAR(float32, AP_HYSTADD_VAR_NOINIT) Fraction_Uls_D_f32;
STATIC volatile VAR(sint16, AP_HYSTADD_VAR_NOINIT) FiltHwTrq_HwNm_D_s7p8;

STATIC VAR(float32, AP_HYSTADD_VAR_NOINIT) PrevHysAddHwTrq_HwNm_M_f32;
STATIC VAR(float32, AP_HYSTADD_VAR_NOINIT) PrevHwTrq_HwNm_M_f32;
STATIC VAR(sint16, AP_HYSTADD_VAR_NOINIT) PrevFiltHwTrq_HwNm_M_s7p8;
STATIC VAR(float32, AP_HYSTADD_VAR_NOINIT) PrevHysPos_Uls_M_f32;
STATIC VAR(sint32, AP_HYSTADD_VAR_NOINIT) HwTrqFiltSV_HwNm_M_s7p24;

STATIC FUNC(float32, AP_HYSTADD_CODE) AvailableHyst(VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4, 
                                                        VAR(float32, AUTOMATIC) ModifiedTrq_HwNm_T_f32);
STATIC FUNC(float32, AP_HYSTADD_CODE) HystLoop(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32);
STATIC FUNC(float32, AP_HYSTADD_CODE) HystLoopConv(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(float32, AUTOMATIC) HysPosition_Uls_T_f32);	
STATIC FUNC(float32, AP_HYSTADD_CODE) GeometricCorrection(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4,
														VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32, 
                                                        VAR(float32, AUTOMATIC) ModifiedTrq_HwNm_T_f32);

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
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_HYSTADD_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HystAdd_Per1
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
 *   Float Rte_IRead_HystAdd_Per1_HwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_HystAdd_Per1_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_HystAdd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HystAdd_Per1_HysAddHwTrq_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HystAdd_Per1_HysAddHwTrq_HwNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HYSTADD_APPL_CODE) HystAdd_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HystAdd_Per1
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4;
	VAR(boolean, AUTOMATIC) HysAddSrlComSvcDft_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ModifiedTrq_HwNm_T_f32;
	VAR(sint16, AUTOMATIC) HwTrq_HwNm_T_s7p8;
	VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8;
	VAR(float32, AUTOMATIC) HysPosition_Uls_T_f32;
	VAR(float32, AUTOMATIC) Fraction_Uls_T_f32;
	VAR(float32, AUTOMATIC) CorrectionTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HysAddHwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32;

    VehSpd_Kph_T_u12p4 = FPM_FloatToFixed_m((Rte_IRead_HystAdd_Per1_VehSpd_Kph_f32()), u12p4_T);
	HysAddSrlComSvcDft_Cnt_T_lgc = Rte_IRead_HystAdd_Per1_HysAddSrlComSvcDft_Cnt_lgc();
	HwTrq_HwNm_T_f32 = Rte_IRead_HystAdd_Per1_HwTrq_HwNm_f32();
	HwTrq_HwNm_T_s7p8 = FPM_FloatToFixed_m(HwTrq_HwNm_T_f32, s7p8_T);

    ModifiedTrq_HwNm_T_f32 = PrevHysAddHwTrq_HwNm_M_f32 + PrevHwTrq_HwNm_M_f32;
	PrevHwTrq_HwNm_M_f32 = HwTrq_HwNm_T_f32;
	HwTrqFiltSV_HwNm_M_s7p24 = LPF_SvUpdate_s16InFixKTrunc_m(HwTrq_HwNm_T_s7p8, HwTrqFiltSV_HwNm_M_s7p24, k_HysAddHwTrqLPFKn_Cnt_u16);
	FiltHwTrq_HwNm_T_s7p8 = LPF_OpUpdate_s16InFixKTrunc_m(HwTrqFiltSV_HwNm_M_s7p24);
	FiltHwTrq_HwNm_D_s7p8 = FiltHwTrq_HwNm_T_s7p8;

	/* Calculate available hysteresis */
	AvailHyst_HwNm_T_f32 = AvailableHyst(VehSpd_Kph_T_u12p4, ModifiedTrq_HwNm_T_f32);
	AvailHyst_HwNm_D_f32 = AvailHyst_HwNm_T_f32;

	/* Hysteresis Loop */
	HysPosition_Uls_T_f32 = HystLoop(FiltHwTrq_HwNm_T_s7p8, AvailHyst_HwNm_T_f32);
	/* required for next HystLoop calculations */
	PrevFiltHwTrq_HwNm_M_s7p8 = FiltHwTrq_HwNm_T_s7p8; 

	/* Hysteresis Loop Conversion */
	Fraction_Uls_T_f32 = HystLoopConv(FiltHwTrq_HwNm_T_s7p8, HysPosition_Uls_T_f32);
	Fraction_Uls_D_f32 = Fraction_Uls_T_f32;

	/* Geometric Correction */
	CorrectionTrq_HwNm_T_f32 = GeometricCorrection(FiltHwTrq_HwNm_T_s7p8, VehSpd_Kph_T_u12p4, AvailHyst_HwNm_T_f32, ModifiedTrq_HwNm_T_f32);

	HysAddHwTrq_HwNm_T_f32 = (float32)Sign_s16_m(FiltHwTrq_HwNm_T_s7p8) * ((AvailHyst_HwNm_T_f32 * Fraction_Uls_T_f32) - CorrectionTrq_HwNm_T_f32);

	if(TRUE == HysAddSrlComSvcDft_Cnt_T_lgc)
	{
		HysAddHwTrq_HwNm_T_f32 = D_ZERO_ULS_F32;
	}

	PrevHysAddHwTrq_HwNm_M_f32 = HysAddHwTrq_HwNm_T_f32;
	Rte_IWrite_HystAdd_Per1_HysAddHwTrq_HwNm_f32(HysAddHwTrq_HwNm_T_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_HYSTADD_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_HYSTADD_CODE) AvailableHyst(VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4, 
                                                        VAR(float32, AUTOMATIC) ModifiedTrq_HwNm_T_f32)
{
	VAR(uint16, AUTOMATIC) HysAddSlope_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) HysAddOffset_HwNm_T_u4p12;
	VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32;
	VAR(float32, AUTOMATIC) OffsetHys_HwNm_T_f32;
	
	HysAddSlope_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                    t_HysAddVehSpdTblX_Kph_u12p4,  
                                    t_HysAddSlopeTblY_Uls_u2p14,
                                    TableSize_m(t_HysAddVehSpdTblX_Kph_u12p4),
                                    VehSpd_Kph_T_u12p4);
	
	HysAddOffset_HwNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                    t_HysAddVehSpdTblX_Kph_u12p4,  
                                    t_HysAddOffsetTblY_HwNm_u4p12,
                                    TableSize_m(t_HysAddVehSpdTblX_Kph_u12p4),
                                    VehSpd_Kph_T_u12p4);

	OffsetHys_HwNm_T_f32 = Abs_f32_m(ModifiedTrq_HwNm_T_f32) - FPM_FixedToFloat_m(HysAddOffset_HwNm_T_u4p12, u4p12_T);

    if (OffsetHys_HwNm_T_f32 > D_ZERO_ULS_F32)
     {
		/* Do Nothing */
     }
	 else
	{
		OffsetHys_HwNm_T_f32 = D_ZERO_ULS_F32;
	}
	AvailHyst_HwNm_T_f32 =  (FPM_FixedToFloat_m(HysAddSlope_Uls_T_u2p14, u2p14_T)) * OffsetHys_HwNm_T_f32;
    AvailHyst_HwNm_T_f32 =  Limit_m(AvailHyst_HwNm_T_f32, D_MINAVAILHYS_HWNM_F32 , D_MAXAVAILHYS_HWNM_F32);

    return (AvailHyst_HwNm_T_f32);
}

STATIC FUNC(float32, AP_HYSTADD_CODE) HystLoop(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32)
{
	VAR(sint16, AUTOMATIC) DeltaHwTrq_HwNm_T_s7p8;
	VAR(float32, AUTOMATIC) DeltaHwTrq_HwNm_T_f32;
	VAR(sint16, AUTOMATIC) AvailHyst_HwNm_T_s7p8;
	VAR(float32, AUTOMATIC) TrqChange_Uls_T_f32;
	VAR(uint16, AUTOMATIC) RiseYVal_Uls_T_u6p10;
	VAR(uint16, AUTOMATIC) FallYVal_Uls_T_u6p10;
	VAR(uint16, AUTOMATIC) PrevHysPos_Uls_T_u6p10;
	VAR(uint16, AUTOMATIC) CalcHyst_Uls_T_u6p10;
	VAR(uint16, AUTOMATIC) RiseXYSumTable_Uls_T_u6p10[6];
	VAR(uint16, AUTOMATIC) FallXYSumTable_Uls_T_u6p10[6];
	VAR(uint16, AUTOMATIC) i;
	VAR(float32, AUTOMATIC) NewHysPosVal_Uls_T_f32;
	VAR(sint16, AUTOMATIC) HysY_Uls_T_s5p10;
	VAR(sint16, AUTOMATIC) PrevHysPosSign_Uls_T_s16;
	VAR(float32, AUTOMATIC) HysPosition_Uls_T_f32;

	PrevHysPosSign_Uls_T_s16 = Sign_f32_m(PrevHysPos_Uls_M_f32);
	PrevHysPos_Uls_T_u6p10 = FPM_FloatToFixed_m(Abs_f32_m(PrevHysPos_Uls_M_f32), u6p10_T);
	DeltaHwTrq_HwNm_T_s7p8 = FiltHwTrq_HwNm_T_s7p8 - PrevFiltHwTrq_HwNm_M_s7p8;

	/* Calculate Torque Change */
	if(D_ZERO_CNT_S16 == DeltaHwTrq_HwNm_T_s7p8)
	{
		TrqChange_Uls_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{
		DeltaHwTrq_HwNm_T_f32 = FPM_FixedToFloat_m(Abs_s16_m(DeltaHwTrq_HwNm_T_s7p8),s7p8_T) * D_INVFPRANGETRQCHG_ULS_F32;
		/*  Set the denomonator to minimum resolution used for Avail Hysteresis */
		if(DeltaHwTrq_HwNm_T_f32 < D_MINHYSADDPRECISION_ULS_F32)
		{
			DeltaHwTrq_HwNm_T_f32 = D_MINHYSADDPRECISION_ULS_F32;
		}
				
		/* Calculate avail hysteresis for division */
		AvailHyst_HwNm_T_f32 = AvailHyst_HwNm_T_f32 * D_HALF_ULS_F32 ;
		AvailHyst_HwNm_T_f32 = Max_m(AvailHyst_HwNm_T_f32, DeltaHwTrq_HwNm_T_f32);
		AvailHyst_HwNm_T_s7p8 = FPM_FloatToFixed_m(AvailHyst_HwNm_T_f32, s7p8_T);

		TrqChange_Uls_T_f32 = (float32) DeltaHwTrq_HwNm_T_s7p8 / (float32) AvailHyst_HwNm_T_s7p8;
	}

	if(((PrevHysPos_Uls_M_f32 >= D_ZERO_ULS_F32) && (TrqChange_Uls_T_f32 >= D_ZERO_ULS_F32)) || ((PrevHysPos_Uls_M_f32 < D_ZERO_ULS_F32) && (TrqChange_Uls_T_f32 < D_ZERO_ULS_F32)))
	{
		/*  Same Direction calculations */
		RiseYVal_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( t_HysAddRiseTblX_Uls_u6p10,  
															   t_HysAddRiseTblY_Uls_u6p10,
														      TableSize_m(t_HysAddRiseTblX_Uls_u6p10),
											                   PrevHysPos_Uls_T_u6p10);
		CalcHyst_Uls_T_u6p10 = RiseYVal_Uls_T_u6p10 + PrevHysPos_Uls_T_u6p10 + FPM_FloatToFixed_m(Abs_f32_m(TrqChange_Uls_T_f32), u6p10_T);
		
		for(i=D_ZERO_CNT_U16; i<TableSize_m(t_HysAddRiseTblX_Uls_u6p10); i++)
		{
			RiseXYSumTable_Uls_T_u6p10[i] = t_HysAddRiseTblX_Uls_u6p10[i] + t_HysAddRiseTblY_Uls_u6p10[i];
		}

		CalcHyst_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( RiseXYSumTable_Uls_T_u6p10,  
															   t_HysAddRiseTblX_Uls_u6p10,
														      TableSize_m(RiseXYSumTable_Uls_T_u6p10),
											                   CalcHyst_Uls_T_u6p10);
		NewHysPosVal_Uls_T_f32 = (float32) PrevHysPosSign_Uls_T_s16 * FPM_FixedToFloat_m(CalcHyst_Uls_T_u6p10, u6p10_T);
	}
    else
	{
		/*  Opposite Direction calculations */
		FallYVal_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( t_HysAddFallTblX_Uls_u6p10,  
															   t_HysAddFallTblY_Uls_u6p10,
														      TableSize_m(t_HysAddFallTblX_Uls_u6p10),
											                   PrevHysPos_Uls_T_u6p10);
		HysY_Uls_T_s5p10 = (sint16) (FPM_FloatToFixed_m(Abs_f32_m(TrqChange_Uls_T_f32),u6p10_T) - FallYVal_Uls_T_u6p10 - PrevHysPos_Uls_T_u6p10 );

		for(i=D_ZERO_CNT_U16; i<TableSize_m(t_HysAddFallTblX_Uls_u6p10); i++)
		{
			FallXYSumTable_Uls_T_u6p10[i] = t_HysAddFallTblX_Uls_u6p10[i] + t_HysAddFallTblY_Uls_u6p10[i];
		}

		CalcHyst_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( FallXYSumTable_Uls_T_u6p10,  
															   t_HysAddFallTblX_Uls_u6p10,
														      TableSize_m(FallXYSumTable_Uls_T_u6p10),
											                   Abs_s16_m(HysY_Uls_T_s5p10));
		if (HysY_Uls_T_s5p10 < D_ZERO_CNT_S16)
		{
			NewHysPosVal_Uls_T_f32 = FPM_FixedToFloat_m(CalcHyst_Uls_T_u6p10, u6p10_T) * (float32) PrevHysPosSign_Uls_T_s16;
		}
		else
		{
			NewHysPosVal_Uls_T_f32 = FPM_FixedToFloat_m(CalcHyst_Uls_T_u6p10, u6p10_T) * ( D_NEGATIVESIGN_ULS_F32 * (float32) PrevHysPosSign_Uls_T_s16);
		}

	}
	
	HysPosition_Uls_T_f32 = Limit_m(NewHysPosVal_Uls_T_f32, D_MINHYSPOSITION_ULS_F32, D_MAXHYSPOSITION_ULS_F32);
	PrevHysPos_Uls_M_f32 = HysPosition_Uls_T_f32;

	return(HysPosition_Uls_T_f32);
}


STATIC FUNC(float32, AP_HYSTADD_CODE) HystLoopConv(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(float32, AUTOMATIC) HysPosition_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) Fraction_Uls_T_f32;

	Fraction_Uls_T_f32 = (float32)Sign_s16_m(FiltHwTrq_HwNm_T_s7p8) - HysPosition_Uls_T_f32;
	Fraction_Uls_T_f32 = Abs_f32_m(Fraction_Uls_T_f32 * D_HALF_ULS_F32);
	Fraction_Uls_T_f32 = Limit_m(Fraction_Uls_T_f32 , D_MINFRACTION_ULS_F32, D_MAXFRACTION_ULS_F32);
	
	return (Fraction_Uls_T_f32);
}

STATIC FUNC(float32, AP_HYSTADD_CODE) GeometricCorrection(VAR(sint16, AUTOMATIC) FiltHwTrq_HwNm_T_s7p8, 
                                                        VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u12p4,
														VAR(float32, AUTOMATIC) AvailHyst_HwNm_T_f32, 
                                                        VAR(float32, AUTOMATIC) ModifiedTrq_HwNm_T_f32)
{
	VAR(float32, AUTOMATIC) ReleaseTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) FiltHwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) CorrTrq_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) HysAddSlope_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) HysAddOffset_HwNm_T_u4p12;
	VAR(float32, AUTOMATIC) HysAddSlope_Uls_T_f32;
	VAR(float32, AUTOMATIC) HysAddOffset_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsReleaseTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsFiltHwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) SlopeMulFactors_Uls_T_f32;

	FiltHwTrq_HwNm_T_f32 = FPM_FixedToFloat_m(FiltHwTrq_HwNm_T_s7p8, s7p8_T);
	ReleaseTrq_HwNm_T_f32 = (float32)Sign_f32_m(ModifiedTrq_HwNm_T_f32) * (Abs_f32_m(ModifiedTrq_HwNm_T_f32) - AvailHyst_HwNm_T_f32);
	AbsReleaseTrq_HwNm_T_f32 = Abs_f32_m(ReleaseTrq_HwNm_T_f32);
	AbsFiltHwTrq_HwNm_T_f32 = Abs_f32_m(FiltHwTrq_HwNm_T_f32);

	if((AbsReleaseTrq_HwNm_T_f32 > AbsFiltHwTrq_HwNm_T_f32) && (Sign_f32_m(ReleaseTrq_HwNm_T_f32) == Sign_f32_m(FiltHwTrq_HwNm_T_f32)))
	{
			HysAddSlope_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                    t_HysAddVehSpdTblX_Kph_u12p4,  
                                    t_HysAddSlopeTblY_Uls_u2p14,
                                    TableSize_m(t_HysAddVehSpdTblX_Kph_u12p4),
                                    VehSpd_Kph_T_u12p4);
	
			HysAddOffset_HwNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                    t_HysAddVehSpdTblX_Kph_u12p4,  
                                    t_HysAddOffsetTblY_HwNm_u4p12,
                                    TableSize_m(t_HysAddVehSpdTblX_Kph_u12p4),
                                    VehSpd_Kph_T_u12p4);

			HysAddSlope_Uls_T_f32 = FPM_FixedToFloat_m(HysAddSlope_Uls_T_u2p14, u2p14_T);
			HysAddOffset_HwNm_T_f32 = FPM_FixedToFloat_m(HysAddOffset_HwNm_T_u4p12, u4p12_T);

			CorrTrq_HwNm_T_f32 = Max_m(AbsReleaseTrq_HwNm_T_f32,HysAddOffset_HwNm_T_f32) - Max_m(AbsFiltHwTrq_HwNm_T_f32,HysAddOffset_HwNm_T_f32);
			SlopeMulFactors_Uls_T_f32 = HysAddSlope_Uls_T_f32 / ( Limit_m ( (D_ONE_ULS_F32 - HysAddSlope_Uls_T_f32 ), D_MINSLOPEMULFAC_ULS_F32 , D_MAXSLOPEMULFAC_ULS_F32 ));
			CorrTrq_HwNm_T_f32 = CorrTrq_HwNm_T_f32 * SlopeMulFactors_Uls_T_f32;
			CorrTrq_HwNm_T_f32 = Limit_m(CorrTrq_HwNm_T_f32, D_MINCORRTRQ_HWNM_F32, D_MAXCORRTRQ_HWNM_F32);
	}
	else
	{
		CorrTrq_HwNm_T_f32 = D_ZERO_ULS_F32;
	}

	return (CorrTrq_HwNm_T_f32);
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
