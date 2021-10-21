/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DrvDynCtrl.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynCtrl-nzt9hv/DrvDynCtrl/autosar
 *     SW-C Type:  Ap_DrvDynCtrl
 *  Generated at:  Sat Oct  6 11:34:59 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DrvDynCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue May 31 22:40:44 2011
 * %version:          8 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Fri Apr 26 18:24:52 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/01/11   1       JJW       Initial SWC template
 * 06/03/11   2       YY        Implement driving-dynamics control feature                                   CR3612
 * 06/20/12   3       NRAR      FDD40A Ver 008 updates
 * 06/23/12   4       NRAR      Anom 3469
 * 07/14/12   5       NRAR      Anom 3528
 * 08/21/12   6       NRAR      This component is updated based on SignalConditioning FDDSF33 Ver002         CR6038   
 * 10/06/12   7        Selva      Checkpoints added and mempmap macros corrected		                          6461
 * 04/26/13   8       NRAR      Anom 4222- PrevDrvDynActiveSV_Cnt_M_lgc is not updated
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_DrvDynCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_DrvDynCtrl_Cfg.h"

/* == INCLUDES ================================================= */

#include "GlobalMacro.h"
#include "CalConstants.h"
#include "interpolation.h"
#include <float.h>

/* == EMBEDDED CONSTANTS ======================================= */



/* == PROTOTYPES =============================================== */



/* == CONSTANTS ================================================ */


#define DRVDYNCTRL_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(boolean, AUTOMATIC) AstApplySlewSV_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) RtnApplySlewSV_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) DampApplySlewSV_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC) PrevDrvDynActiveSV_Cnt_M_lgc;

#define DRVDYNCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#define DRVDYNCTRL_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AUTOMATIC) CurrDDAstLimRqst_Uls_M_f32;
STATIC VAR(float32, AUTOMATIC) CurrDDDmpLimRqst_Uls_M_f32;
STATIC VAR(float32, AUTOMATIC) CurrDDRtnLimRqst_Uls_M_f32;
STATIC volatile VAR(float32, AUTOMATIC) DDAstLimRqst_Uls_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) DDDmpLimRqst_Uls_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) DDRtnLimRqst_Uls_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) AstSlewVal_UlspS_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) DmpSlewVal_UlspS_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) RtnSlewVal_UlspS_D_f32;


#define DRVDYNCTRL_STOP_SEC_VAR_CLEARED_32
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 *
 * Enumeration Types:
 * ==================
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DRVDYNCTRL_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DrvDynCtrl_Per1
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
 *   Float Rte_IRead_DrvDynCtrl_Per1_DDAstFactRqst_Uls_f32(void)
 *   Float Rte_IRead_DrvDynCtrl_Per1_DDDmpFactRqst_Uls_f32(void)
 *   Float Rte_IRead_DrvDynCtrl_Per1_DDRtnFactRqst_Uls_f32(void)
 *   Boolean Rte_IRead_DrvDynCtrl_Per1_DrvDynActive_Cnt_lgc(void)
 *   Float Rte_IRead_DrvDynCtrl_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_DrvDynCtrl_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_DrvDynCtrl_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DrvDynCtrl_Per1_AssistDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_DrvDynCtrl_Per1_AssistDDFactor_Uls_f32(void)
 *   void Rte_IWrite_DrvDynCtrl_Per1_DampingDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_DrvDynCtrl_Per1_DampingDDFactor_Uls_f32(void)
 *   void Rte_IWrite_DrvDynCtrl_Per1_ReturnDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_DrvDynCtrl_Per1_ReturnDDFactor_Uls_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DRVDYNCTRL_APPL_CODE) DrvDynCtrl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvDynCtrl_Per1
 *********************************************************************************************************************/

VAR(boolean, AUTOMATIC) DrvDynActive_Cnt_T_lgc;
VAR(float32, AUTOMATIC) AbsHwTrq_HwNm_T_f32;
VAR(float32, AUTOMATIC) AbsMtrVelCRF_MtrRadpS_T_f32;
VAR(float32, AUTOMATIC) DDAstFactRqst_Uls_T_f32;
VAR(float32, AUTOMATIC) DDDmpFactRqst_Uls_T_f32;
VAR(float32, AUTOMATIC) DDRtnFactRqst_Uls_T_f32;
VAR(boolean, AUTOMATIC) StateChg_Cnt_T_lgc;
VAR(uint16, AUTOMATIC) HwTrqDDFctrAstLim_Uls_T_u8p8;
VAR(uint16, AUTOMATIC) MtrVelDDFctrDmpLim_Uls_T_u8p8;
VAR(uint16, AUTOMATIC) AbsMtrVelCRF_MtrRadpS_T_u12p4;
VAR(uint16, AUTOMATIC) AbsHwTrq_HwNm_T_u8p8;
VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7;
VAR(float32, AUTOMATIC) HwTrqDDFctrAstLim_Uls_T_f32;
VAR(float32, AUTOMATIC) MtrVelDDFctrDmpLim_Uls_T_f32;
VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
VAR(float32, AUTOMATIC) AstSlewVal_UlspS_T_f32;
VAR(boolean, AUTOMATIC) AstApplySlew_Cnt_T_lgc;
VAR(float32, AUTOMATIC) DDAstLimRqst_Uls_T_f32;
VAR(boolean, AUTOMATIC) RtnApplySlew_Cnt_T_lgc;
VAR(float32, AUTOMATIC) DDDmpLimRqst_Uls_T_f32;
VAR(float32, AUTOMATIC) DmpSlewVal_UlspS_T_f32;
VAR(float32, AUTOMATIC) DDRtnLimRqst_Uls_T_f32;
VAR(float32, AUTOMATIC) RtnSlewVal_UlspS_T_f32;
VAR(boolean, AUTOMATIC) DmpApplySlew_Cnt_T_lgc;
	/* capture inputs */

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_DrvDynCtrl_Per1_CP0_CheckpointReached();
DrvDynActive_Cnt_T_lgc = Rte_IRead_DrvDynCtrl_Per1_DrvDynActive_Cnt_lgc();
VehSpd_Kph_T_f32 = Rte_IRead_DrvDynCtrl_Per1_VehSpd_Kph_f32();

AbsHwTrq_HwNm_T_f32 = Abs_f32_m(Rte_IRead_DrvDynCtrl_Per1_HwTrq_HwNm_f32());
AbsMtrVelCRF_MtrRadpS_T_f32 = Abs_f32_m(Rte_IRead_DrvDynCtrl_Per1_MtrVelCRF_MtrRadpS_f32());

/* Check for DDFactor state change */
if(DrvDynActive_Cnt_T_lgc != PrevDrvDynActiveSV_Cnt_M_lgc)
{
	StateChg_Cnt_T_lgc = TRUE;
}
else
{
	StateChg_Cnt_T_lgc = FALSE;
}
PrevDrvDynActiveSV_Cnt_M_lgc = DrvDynActive_Cnt_T_lgc;

/* Decide whether to allow incoming requested values */
if(TRUE == DrvDynActive_Cnt_T_lgc )
{
	DDAstFactRqst_Uls_T_f32 = Rte_IRead_DrvDynCtrl_Per1_DDAstFactRqst_Uls_f32();
	DDDmpFactRqst_Uls_T_f32 = Rte_IRead_DrvDynCtrl_Per1_DDDmpFactRqst_Uls_f32();
	DDRtnFactRqst_Uls_T_f32 = Rte_IRead_DrvDynCtrl_Per1_DDRtnFactRqst_Uls_f32();

	#if (STD_ON == BC_DRVDYNCTRL_FAULTINJECTIONPOINT)
	Rte_Call_FltInjection_SCom_FltInjection(&DDAstFactRqst_Uls_T_f32, FLTINJ_DDASTFACTRQST_DRVDYNCTRL);
	Rte_Call_FltInjection_SCom_FltInjection(&DDDmpFactRqst_Uls_T_f32, FLTINJ_DDDMPFACTRQST_DRVDYNCTRL);
	Rte_Call_FltInjection_SCom_FltInjection(&DDRtnFactRqst_Uls_T_f32, FLTINJ_DDRTNFACTRQST_DRVDYNCTRL);
	#endif


}
else
{
	DDAstFactRqst_Uls_T_f32 = D_ONE_ULS_F32;
	DDDmpFactRqst_Uls_T_f32 = D_ONE_ULS_F32;
	DDRtnFactRqst_Uls_T_f32 = D_ONE_ULS_F32;
}

VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u9p7_T);
AbsHwTrq_HwNm_T_u8p8 = FPM_FloatToFixed_m(AbsHwTrq_HwNm_T_f32,u8p8_T);
AbsMtrVelCRF_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(AbsMtrVelCRF_MtrRadpS_T_f32,u12p4_T);

HwTrqDDFctrAstLim_Uls_T_u8p8 = BilinearXYM_u16_u16Xu16YM_Cnt(VehSpd_Kph_T_u9p7, 
																AbsHwTrq_HwNm_T_u8p8, 
																t_DDFctrVehSpdBS_Kph_u9p7, 
																TableSize_m(t_DDFctrVehSpdBS_Kph_u9p7), 
																t_DDFctrHwTrqX_HwNm_u8p8, 
																(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_DDCFctrAstLimYM_Uls_u8p8, 
																TableSize_m(t_DDFctrHwTrqX_HwNm_u8p8));

HwTrqDDFctrAstLim_Uls_T_f32= FPM_FixedToFloat_m(HwTrqDDFctrAstLim_Uls_T_u8p8,u8p8_T);


MtrVelDDFctrDmpLim_Uls_T_u8p8 = BilinearXYM_u16_u16Xu16YM_Cnt(VehSpd_Kph_T_u9p7, 
																AbsMtrVelCRF_MtrRadpS_T_u12p4, 
																t_DDFctrVehSpdBS_Kph_u9p7, 
																TableSize_m(t_DDFctrVehSpdBS_Kph_u9p7), 
																t_DDFctrMtrVelX_MtrRadpS_u12p4, 
																(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_DDCFctrDmpLimYM_Uls_u8p8, 
																TableSize_m(t_DDFctrMtrVelX_MtrRadpS_u12p4));

MtrVelDDFctrDmpLim_Uls_T_f32 = FPM_FixedToFloat_m(MtrVelDDFctrDmpLim_Uls_T_u8p8,u8p8_T);

DDAstLimRqst_Uls_T_f32 = Limit_m(DDAstFactRqst_Uls_T_f32, D_ONE_ULS_F32, HwTrqDDFctrAstLim_Uls_T_f32);
DDDmpLimRqst_Uls_T_f32 = Limit_m(DDDmpFactRqst_Uls_T_f32, MtrVelDDFctrDmpLim_Uls_T_f32, D_ONE_ULS_F32);
DDRtnLimRqst_Uls_T_f32 = Limit_m(DDRtnFactRqst_Uls_T_f32, k_DDFctrRtnLim_Uls_f32, D_ONE_ULS_F32);


/* Choose and apply slew rate to each DDFactor */
/* AssistDDFactor */
if((TRUE == StateChg_Cnt_T_lgc) ||  (TRUE == AstApplySlewSV_Cnt_M_lgc))
{
	if(TRUE == DrvDynActive_Cnt_T_lgc)
	{
		AstSlewVal_UlspS_T_f32 = k_DDActAstSlew_UlspS_f32;
	}
	else
	{
		AstSlewVal_UlspS_T_f32 = k_DDInActAstSlew_UlspS_f32;
	}

	AstApplySlew_Cnt_T_lgc = TRUE;
}
else
{
	AstSlewVal_UlspS_T_f32 = 1 / D_2MS_SEC_F32;
	AstApplySlew_Cnt_T_lgc = FALSE;
}


CurrDDAstLimRqst_Uls_M_f32 = Limit_m(DDAstLimRqst_Uls_T_f32, (CurrDDAstLimRqst_Uls_M_f32 - (AstSlewVal_UlspS_T_f32* D_2MS_SEC_F32)), (CurrDDAstLimRqst_Uls_M_f32 + (AstSlewVal_UlspS_T_f32*D_2MS_SEC_F32)));

if(Abs_f32_m(CurrDDAstLimRqst_Uls_M_f32 - DDAstLimRqst_Uls_T_f32) > FLT_EPSILON)
{	
	AstApplySlewSV_Cnt_M_lgc = 	AstApplySlew_Cnt_T_lgc;
}
else
{
	AstApplySlewSV_Cnt_M_lgc = FALSE;
}
/*AssistDDFactor End */

/*Damping DDFactor */
if((TRUE == StateChg_Cnt_T_lgc) ||  (TRUE == DampApplySlewSV_Cnt_M_lgc))
{
	if(TRUE == DrvDynActive_Cnt_T_lgc)
	{
		DmpSlewVal_UlspS_T_f32 = k_DDActDmpSlew_UlspS_f32;
	}
	else
	{
		DmpSlewVal_UlspS_T_f32 = k_DDInActDmpSlew_UlspS_f32;
	}
	DmpApplySlew_Cnt_T_lgc = TRUE;
}
else
{
	DmpSlewVal_UlspS_T_f32 = 1 / D_2MS_SEC_F32;
	DmpApplySlew_Cnt_T_lgc = FALSE;
}


CurrDDDmpLimRqst_Uls_M_f32 = Limit_m(DDDmpLimRqst_Uls_T_f32, (CurrDDDmpLimRqst_Uls_M_f32 - (DmpSlewVal_UlspS_T_f32*D_2MS_SEC_F32)), (CurrDDDmpLimRqst_Uls_M_f32 + (DmpSlewVal_UlspS_T_f32*D_2MS_SEC_F32)));

if(Abs_f32_m(CurrDDDmpLimRqst_Uls_M_f32 - DDDmpLimRqst_Uls_T_f32) > FLT_EPSILON)
{	
	DampApplySlewSV_Cnt_M_lgc = DmpApplySlew_Cnt_T_lgc;
}
else
{
	DampApplySlewSV_Cnt_M_lgc = FALSE;
}
/*Damping DDFactor END*/



/*ReturnDDFactor */
if((TRUE == StateChg_Cnt_T_lgc) ||  (TRUE == RtnApplySlewSV_Cnt_M_lgc))
{
	if(TRUE == DrvDynActive_Cnt_T_lgc)
	{
		RtnSlewVal_UlspS_T_f32 = k_DDActRtnSlew_UlspS_f32;
	}
	else
	{
		RtnSlewVal_UlspS_T_f32 = k_DDInActRtnSlew_UlspS_f32;
	}
	RtnApplySlew_Cnt_T_lgc = TRUE;
}
else
{
	RtnSlewVal_UlspS_T_f32 = 1 / D_2MS_SEC_F32;
	RtnApplySlew_Cnt_T_lgc = FALSE;
}


CurrDDRtnLimRqst_Uls_M_f32 = Limit_m(DDRtnLimRqst_Uls_T_f32, (CurrDDRtnLimRqst_Uls_M_f32 - (RtnSlewVal_UlspS_T_f32*D_2MS_SEC_F32)), (CurrDDRtnLimRqst_Uls_M_f32 + (RtnSlewVal_UlspS_T_f32*D_2MS_SEC_F32)));

if(Abs_f32_m(CurrDDRtnLimRqst_Uls_M_f32 - DDRtnLimRqst_Uls_T_f32) > FLT_EPSILON)
{	
	RtnApplySlewSV_Cnt_M_lgc = 	RtnApplySlew_Cnt_T_lgc;
}
else
{
	RtnApplySlewSV_Cnt_M_lgc = FALSE;
}
/*ReturnDDFactor END*/

	/* update outputs */

	DDAstLimRqst_Uls_D_f32 = DDAstLimRqst_Uls_T_f32;
	DDDmpLimRqst_Uls_D_f32 = DDDmpLimRqst_Uls_T_f32;
	DDRtnLimRqst_Uls_D_f32 = DDRtnLimRqst_Uls_T_f32;
	AstSlewVal_UlspS_D_f32 = AstSlewVal_UlspS_T_f32;
	DmpSlewVal_UlspS_D_f32 = DmpSlewVal_UlspS_T_f32;
	RtnSlewVal_UlspS_D_f32 = RtnSlewVal_UlspS_T_f32;


	Rte_IWrite_DrvDynCtrl_Per1_AssistDDFactor_Uls_f32(CurrDDAstLimRqst_Uls_M_f32);
	Rte_IWrite_DrvDynCtrl_Per1_DampingDDFactor_Uls_f32(CurrDDDmpLimRqst_Uls_M_f32);
	Rte_IWrite_DrvDynCtrl_Per1_ReturnDDFactor_Uls_f32(CurrDDRtnLimRqst_Uls_M_f32);
	


	/* Configurable End of Runnable Checkpoint */
	Rte_Call_DrvDynCtrl_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DRVDYNCTRL_APPL_CODE
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
