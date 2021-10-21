/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_BmwTqOvrlCdng.c
 *     Workspace:  C:/Synergy_EA3/working/BmwTqOvrlCdng/autosar
 *     SW-C Type:  Ap_BmwTqOvrlCdng
 *  Generated at:  Fri Jun  2 16:24:21 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_BmwTqOvrlCdng>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /******************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name     : Ap_BmwTqOvrlCdng.c
 * Module Description   : Implementation of CF040
 * Project              : CBD
 * Author               : Krishna Anne
 ******************************************************************************
 * %version:          3 %
 * %derived_by:       nz4qtt %
 *--------------------------------------------------------------------------------------------------------------------
 * Date         Rev      Author   Change Description                                                           SCR #
 * ---------  -------   --------  ------------------------------------------------------------------------  ----------
 * 05/10/17     1        KK       Initial version                                                            EA3#15781
 * 05/30/17     2        KK       Fixes for anomaly EA3#16051					                             EA3#16202
 * 05/30/17     3        KK       Fixes for anomaly EA3#16051					                             EA3#16207
 *--------------------------------------------------------------------------------------------------------------------
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_BmwTqOvrlCdng.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "fixmath.h"
#include "interpolation.h"
#include "SystemTime.h"

/* MISRA-C:2004 Rule 8.1: Deviation required, Library Exception */

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* MISRA-C:2004 Rule 10.1: Deviation required, Library Exception */

/* MISRA-C:2004 Rule 10.2: Deviation required, Library Exception */

/* PRQA S 4395 EOF 
 * MISRA-C:2004 Rule 10.4: Deviation required, Library Exception, File Level Comment */
 
/* MISRA-C:2004 Rule 12.4: Careful analysis needs to be done and all possible combinations needs to be analyzed for desired results. 
   Warning can be suppressed after careful analysis. We will keep this warning ON.*/

/* MISRA-C:2004 Rule 19.1: Required for AutoSAR compliance so deviation is taken. : PRQA S 5087:  */

/* MISRA-C:2004 Rule 19.11: No deviation comment required for FltInj Implementation */

#define D_3MSGCYCTI_ULS_U32 			(30U)
#define D_BMWTOCBIGSLEW_MTRNMPS_F32 	(4400.0F)
#define D_DRVGDYNIFST225_ULS_U08 		(225U)
#define D_DRVGDYNIFST32_ULS_U08 		(32U)
#define D_DRVGDYNIFST33_ULS_U08 		(33U)
#define D_DRVGDYNIFST34_ULS_U08 		(34U)
#define D_DRVGDYNIFST35_ULS_U08 		(35U)
#define D_DRVGDYNIFST96_ULS_U08 		(96U)
#define D_FLTEPSILON_ULS_F32 			(0.0000001192092896F)
#define D_OUTPTQOVRLMAXLIM_MTRNM_F32 	(8.8F)
#define D_OUTPTQOVRLMINLIM_MTRNM_F32 	(-8.8F)

#define BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_BMWTQOVRLCDNG_VAR)  BmwTqOvrlCdng_TarSteerTqDrvrActrLPF_M_str;   			/* PRQA S 3218 */
#define BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32;							/* PRQA S 3218 */
STATIC VAR(float32, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_DDOpTrqOvRqst_MtrNm_M_f32;						/* PRQA S 3218 */
STATIC VAR(float32, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_FrznSerlComTarSteerTqDrvrActr_MtrNm_M_f32;		/* PRQA S 3218 */
STATIC VAR(uint32,  AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_MsgCycTmr_mS_M_u32;								/* PRQA S 3218 */
#define BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08;						/* PRQA S 3218 */
#define BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_OpTrqRmpComplete_Cnt_M_lgc;						/* PRQA S 3218 */
STATIC VAR(boolean, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_FrznSigActv_Cnt_M_lgc;							/* PRQA S 3218 */
STATIC VAR(boolean, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc;						/* PRQA S 3218 */
STATIC VAR(boolean, AP_BMWTQOVRLCDNG_VAR) BmwTqOvrlCdng_OutpRstTrig_Cnt_M_lgc;							/* PRQA S 3218 */
#define BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/*** Local functions prototypes ***/

STATIC FUNC(float32, AP_BMWTQOVRLCDNG_CODE) StTranDetn(VAR(float32, AUTOMATIC) SerlComTarSteerTqDrvrActr_MtrNm_T_f32,
													   VAR(uint8, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum);


STATIC FUNC(float32, AP_BMWTQOVRLCDNG_CODE) CalcCdndTqOvrl(VAR(boolean, AUTOMATIC) DrvgDynErrIfActv_Cnt_T_lgc,
														   VAR(float32, AUTOMATIC) FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32,
														   VAR(float32, AUTOMATIC) SerlComTarSteerTqDrvrActr_MtrNm_T_f32);

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
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_ANAHWTRQT1 (39u)
 *   FLTINJ_ANAHWTRQT2 (40u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_IMCARBCROLLGCNTR (44u)
 *   FLTINJ_IMCARBRCRC (45u)
 *   FLTINJ_IMCARBRDATA (46u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_IMCARBRPATIDN (47u)
 *   FLTINJ_CMMTRCURR1 (48u)
 *   FLTINJ_CMMTRCURR2 (49u)
 *   FLTINJ_NHET1CFGANDUSE1 (50u)
 *   FLTINJ_NHET1CFGANDUSE2 (51u)
 *   FLTINJ_EPWM_UP1 (52u)
 *   FLTINJ_EPWM_UP2 (53u)
 *   FLTINJ_EPWM_UP3 (54u)
 *   FLTINJ_IMCARBROPENCAN (65u)
 *   FLTINJ_IMCARBROPENCANSCI (66u)
 *   FLTINJ_IMCARBROPENSCI (67u)
 *   FLTINJ_BMWTOC (68u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
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
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
 * QU_SER_STMOM_STMOM_DV_ACT: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
 *   Cx21_Schnittstelle_aktiv (33u)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96u)
 *   Cx80_Schnittstelle_wird_initialisiert (128u)
 *   CxE0_Service_nicht_verfuegbar___Standby___PMA (224u)
 *   CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225u)
 *   CxFF_Signal_ungueltig (255u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_BMWTQOVRLCDNG_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdng_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWTQOVRLCDNG_APPL_CODE) BmwTqOvrlCdng_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdng_Init1
 *********************************************************************************************************************/

 LPF_KUpdate_f32_m(k_BmwTOC_TarSteerTqDrvrActrLPFFrq_Hz_f32, D_2MS_SEC_F32, &BmwTqOvrlCdng_TarSteerTqDrvrActrLPF_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdng_Per1
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
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc(void)
 *   QU_SER_STMOM_STMOM_DV_ACT Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08(void)
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc(void)
 *   Float Rte_IRead_BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32(void)
 *   Float Rte_IRead_BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWTQOVRLCDNG_APPL_CODE) BmwTqOvrlCdng_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdng_Per1
 *********************************************************************************************************************/

 VAR(float32, AUTOMATIC) SerlComTarSteerTqDrvrActr_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) CdndTqOvrl_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
 VAR(float32, AUTOMATIC) OutpTqOvrl_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) TarSteerTqDrvrActrMax_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) DDOpTrqOvRqst_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) Delta_MtrNm_T_f32;
 VAR(float32, AUTOMATIC) OpTrqCmdLocal_MtrNm_T_f32;
 
 VAR(boolean, AUTOMATIC) DrvDynActive_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) DrvgDynErrIfActv_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) OpTrqOvRmpInEnable_Cnt_T_lgc;
 
 VAR(uint16, AUTOMATIC) TarSteerTqDrvrActrMax_MtrNm_T_u4p12;
 
 VAR(QU_SER_STMOM_STMOM_DV_ACT, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum;
 
 
 /*** Read global inputs from RTE ***/
 DrvDynActive_Cnt_T_lgc 				 = Rte_IRead_BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc();					/* REQ: CF040A #54 I */
 DrvgDynErrIfActv_Cnt_T_lgc				 = Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc();				/* REQ: CF040A #53 I */
 DrvgDynIfSt_Cnt_T_enum					 = Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08();                  /* REQ: CF040A #55 I */
 OpTrqOvRmpInEnable_Cnt_T_lgc			 = Rte_IRead_BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc();           /* REQ: CF040A #56 I */
 SerlComTarSteerTqDrvrActr_MtrNm_T_f32	 = Rte_IRead_BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32();  /* REQ: CF040A #10 I */
 VehicleSpeed_Kph_T_f32					 = Rte_IRead_BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32();                 /* REQ: CF040A #74 I */

 
 /* CalcTqReq */
 FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32 = StTranDetn(SerlComTarSteerTqDrvrActr_MtrNm_T_f32, DrvgDynIfSt_Cnt_T_enum);
 CdndTqOvrl_MtrNm_T_f32 = CalcCdndTqOvrl(DrvgDynErrIfActv_Cnt_T_lgc, FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32, SerlComTarSteerTqDrvrActr_MtrNm_T_f32);
  
 /* REQ: CF040A #60 I */ /* REQ: CF040A #61 I */ /* REQ: CF040A #67 I */
 TarSteerTqDrvrActrMax_MtrNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwTOC_TarSteerTqDrvrActrSpdX_Kph_u9p7,
																   t_BmwTOC_TarSteerTqDrvrActrMaxY_MtrNm_u4p12,
																   TableSize_m(t_BmwTOC_TarSteerTqDrvrActrSpdX_Kph_u9p7),
																   FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T));
 TarSteerTqDrvrActrMax_MtrNm_T_f32 = FPM_FixedToFloat_m(TarSteerTqDrvrActrMax_MtrNm_T_u4p12, u4p12_T);
 DDOpTrqOvRqst_MtrNm_T_f32 = Limit_m(CdndTqOvrl_MtrNm_T_f32, -TarSteerTqDrvrActrMax_MtrNm_T_f32, TarSteerTqDrvrActrMax_MtrNm_T_f32);
 BmwTqOvrlCdng_DDOpTrqOvRqst_MtrNm_M_f32 = DDOpTrqOvRqst_MtrNm_T_f32;
 /* ENDREQ: CF040A #60 */ /* ENDREQ: CF040A #61 */ /* ENDREQ: CF040A #67 */
 
 
 
 /* REQ: CF040A #72 I */ /* REQ: CF040A #73 I */ /* REQ: CF040A #83 I */ /* REQ: CF040A #84 I */
 /* BypassCdndTqOvrl */
 if((DrvgDynErrIfActv_Cnt_T_lgc == D_TRUE_CNT_LGC) || (BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc == D_TRUE_CNT_LGC))
 {
	OutpTqOvrl_MtrNm_T_f32 = DDOpTrqOvRqst_MtrNm_T_f32;
 }
 /* OutputZero */
 else if(BmwTqOvrlCdng_OutpRstTrig_Cnt_M_lgc == D_TRUE_CNT_LGC)
 {
	OutpTqOvrl_MtrNm_T_f32 = D_ZERO_ULS_F32; 
 }
 /* NormalMode */
 else
 {
	/* CalcOutp */
	if(DrvDynActive_Cnt_T_lgc == D_TRUE_CNT_LGC)
	{
		/* CalSlewRate */
		if((OpTrqOvRmpInEnable_Cnt_T_lgc == D_TRUE_CNT_LGC) && (BmwTqOvrlCdng_OpTrqRmpComplete_Cnt_M_lgc == D_FALSE_CNT_LGC))
		{
			Delta_MtrNm_T_f32 = k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32 * D_2MS_SEC_F32;
		}
		/* ConSlewRate */
		else
		{
			Delta_MtrNm_T_f32 = D_BMWTOCBIGSLEW_MTRNMPS_F32 * D_2MS_SEC_F32;
		}
		OpTrqCmdLocal_MtrNm_T_f32 = Limit_m(DDOpTrqOvRqst_MtrNm_T_f32,
											(BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 - Delta_MtrNm_T_f32),
											(BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 + Delta_MtrNm_T_f32));
											
		OutpTqOvrl_MtrNm_T_f32 = OpTrqCmdLocal_MtrNm_T_f32;
		/* CmplTrue */
		if(Abs_f32_m(BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 - OpTrqCmdLocal_MtrNm_T_f32) <= D_FLTEPSILON_ULS_F32)
		{
			BmwTqOvrlCdng_OpTrqRmpComplete_Cnt_M_lgc = D_TRUE_CNT_LGC;
		}
		/* CmplFalse */
		else
		{
			BmwTqOvrlCdng_OpTrqRmpComplete_Cnt_M_lgc = D_FALSE_CNT_LGC;
		}
	}
	/* OutpZero */
	else
	{
		OutpTqOvrl_MtrNm_T_f32 = Limit_m(D_ZERO_ULS_F32, 
										 (BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 - (k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32*D_2MS_SEC_F32)), 
										 (BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 + (k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32*D_2MS_SEC_F32)) );
		BmwTqOvrlCdng_OpTrqRmpComplete_Cnt_M_lgc = D_FALSE_CNT_LGC;								 
	}
	
 }
 /* ENDREQ: CF040A #72 */ /* ENDREQ: CF040A #73 */ /* ENDREQ: CF040A #83 */ /* ENDREQ: CF040A #84 */
 
 BmwTqOvrlCdng_OpTrqOvSV_MtrNm_M_f32 = OutpTqOvrl_MtrNm_T_f32; /* REQ: CF040A #80 I */ /* REQ: CF040A #81 I */
  
 /*** Range Limit and Write global outputs to RTE ***/
 OutpTqOvrl_MtrNm_T_f32 = Limit_m(OutpTqOvrl_MtrNm_T_f32, D_OUTPTQOVRLMINLIM_MTRNM_F32, D_OUTPTQOVRLMAXLIM_MTRNM_F32);
 Rte_IWrite_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(OutpTqOvrl_MtrNm_T_f32); /* REQ: CF040A #16 I */ /* REQ: CF040A #59 I */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_BMWTQOVRLCDNG_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Function     : StTranDetn
 * Inputs       : SerlComTarSteerTqDrvrActr_MtrNm_T_f32, DrvgDynIfSt_Cnt_T_enum.
 * Outputs      : FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32.
 * Description  : This function (StTranDetn block in FDD) is split from Per1 to handle the 
 *              : cyclomatic complexity and path count.
 *              : Path : CF040A_BmwTqOvrlCdng/BmwTqOvrlCdng/BmwTqOvrlCdng_Per1/CalcTqReq/StTranDetn
 * Usage Notes  : NA.
 **********************************************************************************************************************/
STATIC FUNC(float32, AP_BMWTQOVRLCDNG_CODE) StTranDetn(VAR(float32, AUTOMATIC) SerlComTarSteerTqDrvrActr_MtrNm_T_f32,
													   VAR(uint8, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum)

{
	/* REQ: CF040A #68 I */ /* REQ: CF040A #69 I */ /* REQ: CF040A #83 I */ /* REQ: CF040A #26 I */ /* REQ: CF040A #70 I */
	
	VAR(float32, AUTOMATIC) FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32;
	
	VAR(boolean, AUTOMATIC) FromCdnVld_Cnt_T_lgc = D_FALSE_CNT_LGC;
	VAR(boolean, AUTOMATIC) Prev33Or35_Cnt_T_lgc = D_FALSE_CNT_LGC;
	VAR(boolean, AUTOMATIC) Curr33Or35_Cnt_T_lgc = D_FALSE_CNT_LGC;
	
	if((BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08 == D_DRVGDYNIFST32_ULS_U08) || (BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08 == D_DRVGDYNIFST34_ULS_U08))
	{
		FromCdnVld_Cnt_T_lgc = 	D_TRUE_CNT_LGC;
	}
	if((BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08 == D_DRVGDYNIFST33_ULS_U08) || (BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08 == D_DRVGDYNIFST35_ULS_U08))
	{
		Prev33Or35_Cnt_T_lgc = 	D_TRUE_CNT_LGC;
	}
	if((DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST33_ULS_U08) || (DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST35_ULS_U08))
	{
		Curr33Or35_Cnt_T_lgc = 	D_TRUE_CNT_LGC;
	}
	if((FromCdnVld_Cnt_T_lgc == D_TRUE_CNT_LGC) && (Curr33Or35_Cnt_T_lgc == D_TRUE_CNT_LGC))
	{
		/* RstFildSerlComTarSteerTqDrvrActr_MtrNm_T_f32 */
		FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32 = D_ZERO_ULS_F32;	
	}
	else
	{
		/* Fault Injection Input */
		#if (STD_ON == BC_BMWTOC_FAULTINJECTIONPOINT)
		Rte_Call_FaultInjection_SCom_FltInjection(&SerlComTarSteerTqDrvrActr_MtrNm_T_f32, FLTINJ_BMWTOC);
		#endif
				
		/* LoPassFil */ /* UseNormalValue */
		FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32 = LPF_OpUpdate_f32_m(SerlComTarSteerTqDrvrActr_MtrNm_T_f32, &BmwTqOvrlCdng_TarSteerTqDrvrActrLPF_M_str);
	}
	
	if( ((Curr33Or35_Cnt_T_lgc == D_TRUE_CNT_LGC) || 
		 (DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST225_ULS_U08) || 
		 (DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST96_ULS_U08)) &&
	    (FromCdnVld_Cnt_T_lgc == D_TRUE_CNT_LGC) )
	{
		/* RstFrznSerlComTarSteerTqDrvrActr */
		BmwTqOvrlCdng_FrznSerlComTarSteerTqDrvrActr_MtrNm_M_f32 = D_ZERO_ULS_F32;
	}
	if( ((DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST32_ULS_U08) || 
		 (DrvgDynIfSt_Cnt_T_enum == D_DRVGDYNIFST34_ULS_U08)) &&
		 (Prev33Or35_Cnt_T_lgc == D_TRUE_CNT_LGC) )
	{
		BmwTqOvrlCdng_OutpRstTrig_Cnt_M_lgc = D_TRUE_CNT_LGC;
	}
	else
	{
		BmwTqOvrlCdng_OutpRstTrig_Cnt_M_lgc = D_FALSE_CNT_LGC;
	}
	
	BmwTqOvrlCdng_PrevDrvgDynIfSt_Cnt_M_u08 = DrvgDynIfSt_Cnt_T_enum;	
	
	return(FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32);
	/* ENDREQ: CF040A #68 */ /* ENDREQ: CF040A #69 */ /* ENDREQ: CF040A #83 */ /* ENDREQ: CF040A #26 */ /* ENDREQ: CF040A #70 */
}

/**********************************************************************************************************************
 * Function     : CalcCdndTqOvrl
 * Inputs       : None.
 * Outputs      : CdndTqOvrl_MtrNm_T_f32 - Conditioned Torque Overlay.
 * Description  : This function (CalcCdndTqOvrl block in FDD) is split from Per1 to handle the 
 *              : cyclomatic complexity and path count.
 *              : Path : CF040A_BmwTqOvrlCdng/BmwTqOvrlCdng/BmwTqOvrlCdng_Per1/CalcTqReq/CalcCdndTqOvrl
 * Usage Notes  : NA.
 **********************************************************************************************************************/
STATIC FUNC(float32, AP_BMWTQOVRLCDNG_CODE) CalcCdndTqOvrl(VAR(boolean, AUTOMATIC) DrvgDynErrIfActv_Cnt_T_lgc,
														   VAR(float32, AUTOMATIC) FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32,
														   VAR(float32, AUTOMATIC) SerlComTarSteerTqDrvrActr_MtrNm_T_f32)
{
	/* REQ: CF040A #60 I */ /* REQ: CF040A #61 I */ /* REQ: CF040A #84 I */
	
	VAR(uint32,  AUTOMATIC) ElapsedTime_mS_T_u32;
	VAR(float32, AUTOMATIC) CdndTqOvrl_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) DrvgDynErrIfActvtmp_Cnt_T_lgc;
	
	/* New Value */
	if(BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc == D_FALSE_CNT_LGC)
	{
		DrvgDynErrIfActvtmp_Cnt_T_lgc = DrvgDynErrIfActv_Cnt_T_lgc;
	}
	/* Old Value */
	else
	{
		DrvgDynErrIfActvtmp_Cnt_T_lgc = D_TRUE_CNT_LGC;
	}
	
	/* UseFildSig */
	if(DrvgDynErrIfActvtmp_Cnt_T_lgc == D_TRUE_CNT_LGC)
	{
		/* LatchFildVal */
		if(BmwTqOvrlCdng_FrznSigActv_Cnt_M_lgc == D_FALSE_CNT_LGC)
		{
			BmwTqOvrlCdng_FrznSerlComTarSteerTqDrvrActr_MtrNm_M_f32 = FildSerlComTarSteerTqDrvrActr_MtrNm_T_f32;
			BmwTqOvrlCdng_FrznSigActv_Cnt_M_lgc = D_TRUE_CNT_LGC;
		}
		/* Do nothing */
		else
		{
			/* Do nothing */
		}
		
		DtrmnElapsedTime_mS_u32(BmwTqOvrlCdng_MsgCycTmr_mS_M_u32, &ElapsedTime_mS_T_u32);
		/* Wait */
		if(ElapsedTime_mS_T_u32 <= D_3MSGCYCTI_ULS_U32)
		{
			CdndTqOvrl_MtrNm_T_f32 = BmwTqOvrlCdng_FrznSerlComTarSteerTqDrvrActr_MtrNm_M_f32;
			BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc = D_FALSE_CNT_LGC;
		}
		/* RampDownOutput */
		else
		{
			CdndTqOvrl_MtrNm_T_f32 = Limit_m( D_ZERO_ULS_F32, 
											 (BmwTqOvrlCdng_DDOpTrqOvRqst_MtrNm_M_f32 - (k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32*D_2MS_SEC_F32)), 
											 (BmwTqOvrlCdng_DDOpTrqOvRqst_MtrNm_M_f32 + (k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32*D_2MS_SEC_F32)) );
											 
			/* EnbldFalse */
			if(Abs_f32_m(D_ZERO_ULS_F32 - CdndTqOvrl_MtrNm_T_f32) <= D_FLTEPSILON_ULS_F32)								 
			{
				BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc = D_FALSE_CNT_LGC;
			}
			/* EnbldTrue */
			else
			{
				BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc = D_TRUE_CNT_LGC;
			}
		}
	}
	/* PassInpSig */
	else
	{
		CdndTqOvrl_MtrNm_T_f32 = SerlComTarSteerTqDrvrActr_MtrNm_T_f32;
		BmwTqOvrlCdng_FrznSigActv_Cnt_M_lgc = D_FALSE_CNT_LGC;
		BmwTqOvrlCdng_RampToZeroEnbld_Cnt_M_lgc = D_FALSE_CNT_LGC;
		GetSystemTime_mS_u32(&BmwTqOvrlCdng_MsgCycTmr_mS_M_u32);
	}
	
	return(CdndTqOvrl_MtrNm_T_f32);
	/* ENDREQ: CF040A #60 */ /* ENDREQ: CF040A #61 */ /* ENDREQ: CF040A #84 */
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
