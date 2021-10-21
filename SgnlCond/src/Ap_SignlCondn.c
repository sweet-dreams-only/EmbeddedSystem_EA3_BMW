/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SignlCondn.c
 *     Workspace:  C:/SynergyEA3/Working/SgnlCond/autosar
 *     SW-C Type:  Ap_SignlCondn
 *  Generated at:  Fri Jan 29 11:24:58 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SignlCondn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Nov 29 18:34:17 2011
 * %version:          12 %
 * %date_modified:    Thu May 23 11:37:51 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/15/12  1        NRAR      Initial Release for this component. 
 * 05/16/12  2        NRAR      RTE_INIT_IMPLICIT_BUFFERS macro deleted
 * 05/23/12  3        NRAR      Autosar typo update
 * 08/23/12  4        NRAR      FaultInjection point added for SrlComVehSpeed signal                            #6017
 * 09/05/12  5        NRAR      FaultInjection function prototype updated
 * 09/25/12  6        Selva      Checkpoints added and mempmap macros corrected                               6247
 * 05/21/13  7        SP        SF 33 v 003 implementation                                                    8351
 * 04/02/14  8        SB        Anomaly 6343 Limit outputs                                                    11607
 * 05/09/14  9        SB        Updated per Design Review                                                     11607
 * 05/14/14  10       SB        UTP fixes                                                                     11935
 * 02/02/15  11       SB        Implemented SF-33A SignlCondn rev 004                                         12955
 * 01/15/16  12       SB        Implemented SF-33A SignlCondn rev 005                                         EA3#4340
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_SignlCondn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */ 
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 
/* PRQA S 3332 EOF 
* MISRA-C: 2004 Rule 19.11: This deviation is required for fault injection points */ 

#define D_ACCUNITCNVN_KPHPSPMPSECSQ_F32     0.2777779996F
#define D_VEHLATACCELMAXLIM_MPSECSQ_F32     10.0F
#define D_VEHLATACCELMINLIM_MPSECSQ_F32     (-10.0F)
#define D_VEHLONACCELMAXLIM_KPHPS_F32       50.0F
#define D_VEHLONACCELMINLIM_KPHPS_F32       (-50.0F)
#define D_VEHSPDMAXLIM_KPH_F32              511.0F
#define D_VEHSPDMINLIM_KPH_F32              0.0F
#define D_VEHYAWRATEMAXLIM_DEGPS_F32        120.0F
#define D_VEHYAWRATEMINLIM_DEGPS_F32        (-120.0F)
#define D_KPHTOMPSEC_ULS_F32                0.277777777777778F
#define D_ESTIMDLATACCEMINLIM_MPSECSQ_F32   (-10.0F)
#define D_ESTIMDLATACCEMAXLIM_MPSECSQ_F32   10.0F

#define SIGNLCONDN_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_SIGNLCONDN_VAR) SignlCondn_VehSpd_Kph_M_f32;            	/* PRQA S 3218 */
STATIC VAR(float32, AP_SIGNLCONDN_VAR) SignlCondn_VehLonAccel_KphpS_M_f32; 		/* PRQA S 3218 */
STATIC VAR(float32, AP_SIGNLCONDN_VAR) SignlCondn_VehLatAccel_MpSecSq_M_f32;  	/* PRQA S 3218 */
STATIC VAR(float32, AP_SIGNLCONDN_VAR) SignlCondn_VehYawRate_DegpS_M_f32;     	/* PRQA S 3218 */

#define SIGNLCONDN_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define SIGNLCONDN_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_SIGNLCONDN_VAR) SignlCondn_VehSpdVld_Cnt_M_lgc;  		/* PRQA S 3218 */
STATIC VAR(boolean, AP_SIGNLCONDN_VAR) SignlCondn_VehLonAccelValid_Cnt_M_lgc; 	/* PRQA S 3218 */
STATIC VAR(boolean, AP_SIGNLCONDN_VAR) SignlCondn_VehLatAccelValid_Cnt_M_lgc; 	/* PRQA S 3218 */
STATIC VAR(boolean, AP_SIGNLCONDN_VAR) SignlCondn_VehYawRateValid_Cnt_M_lgc;  	/* PRQA S 3218 */
#define SIGNLCONDN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define SIGNLCONDN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC  VAR(LPF32KSV_Str, AP_SIGNLCONDN_VAR) SignlCondn_LatAccelSV_MpSecSq_M_Str;

#define SIGNLCONDN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehSpdVld_lgc(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
                                                        VAR(float32, AUTOMATIC) SrlComVehSpeed_Kph_T_f32, 
                                                        VAR(float32, AUTOMATIC) DiffThresh_Kph_T_f32,
                                                        VAR(boolean, AUTOMATIC) SrlComVehSpeedValid_Cnt_T_lgc);
                                                        
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehLonAccelVld_lgc(VAR(float32, AUTOMATIC) VehLonAccel_KphpS_T_f32,
                                                             VAR(float32, AUTOMATIC) SrlComVehLonAccel_KphpS_T_f32, 
                                                             VAR(float32, AUTOMATIC) DiffThresh_KphpS_T_f32,
                                                             VAR(boolean, AUTOMATIC) SrlComVehLonAccelValid_Cnt_T_lgc); 

 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehLatAccelVld_lgc(VAR(float32, AUTOMATIC) VehLatAccel_MpSecSq_T_f32,
                                                             VAR(float32, AUTOMATIC) SrlComVehLatAccel_MpSecSq_T_f32, 
                                                             VAR(float32, AUTOMATIC) DiffThresh_MpSecSq_T_f32,
                                                             VAR(boolean, AUTOMATIC) SrlComVehLatAccelValid_Cnt_T_lgc); 
                                                             
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehYawRateVld_lgc(VAR(float32, AUTOMATIC) VehYawRate_DegpS_T_f32,
                                                            VAR(float32, AUTOMATIC) SrlComVehYawRate_DegpS_T_f32, 
                                                            VAR(float32, AUTOMATIC) DiffThresh_DegpS_T_f32,
                                                            VAR(boolean, AUTOMATIC) SrlComVehYawRateValid_Cnt_T_lgc);

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
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
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
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SIGNLCONDN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SignlCondn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SIGNLCONDN_APPL_CODE) SignlCondn_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SignlCondn_Init1
 *********************************************************************************************************************/
    LPF_KUpdate_f32_m(k_SigCon_LatAccFiltFrq_Hz_f32, D_2MS_SEC_F32, &SignlCondn_LatAccelSV_MpSecSq_M_Str); /* REQ: SF033A #66 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SignlCondn_Per1
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
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehLatAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehLatAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehLonAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehLonAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehSpeed_Kph_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehYawRateValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehYawRate_DegpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleSpeed_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleSpeed_Kph_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleYawRate_DegpS_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleYawRate_DegpS_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SIGNLCONDN_APPL_CODE) SignlCondn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SignlCondn_Per1
 *********************************************************************************************************************/
    VAR(boolean, AUTOMATIC) SrlComVehLatAccelValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) SrlComVehLatAccel_MpSecSq_T_f32;
    VAR(boolean, AUTOMATIC) SrlComVehLonAccelValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) SrlComVehLonAccel_MpSecSq_T_f32;
    VAR(boolean, AUTOMATIC) SrlComVehSpeedValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) SrlComVehSpeed_Kph_T_f32;
    VAR(boolean, AUTOMATIC) SrlComVehYawRateValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) SrlComVehYawRate_DegpS_T_f32;

    VAR(float32, AUTOMATIC) SrlComVehLonAccel_KphpS_T_f32;

    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32; 
    VAR(float32, AUTOMATIC) VehLonAccel_KphpS_T_f32;
    VAR(float32, AUTOMATIC) VehLatAccel_MpSecSq_T_f32;
    VAR(float32, AUTOMATIC) VehYawRate_DegpS_T_f32;
    VAR(float32, AUTOMATIC) EstimdLatAcce_MpSecSq_T_f32;

    VAR(boolean, AUTOMATIC) VehSpeedValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehLonAccelValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehLatAccelValid_Cnt_T_lgc; 
    VAR(boolean, AUTOMATIC) VehYawRateValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EstimdLatAcceValid_Cnt_T_lgc;
 
    /* Read Inputs */
    SrlComVehLatAccelValid_Cnt_T_lgc    = Rte_IRead_SignlCondn_Per1_SrlComVehLatAccelValid_Cnt_lgc();   /* REQ: SF033A #75 I */
    SrlComVehLatAccel_MpSecSq_T_f32     = Rte_IRead_SignlCondn_Per1_SrlComVehLatAccel_MpSecSq_f32();    /* REQ: SF033A #55 I */
    SrlComVehLonAccelValid_Cnt_T_lgc    = Rte_IRead_SignlCondn_Per1_SrlComVehLonAccelValid_Cnt_lgc();   /* REQ: SF033A #74 I */
    SrlComVehLonAccel_MpSecSq_T_f32     = Rte_IRead_SignlCondn_Per1_SrlComVehLonAccel_MpSecSq_f32();    /* REQ: SF033A #34 I */
    SrlComVehSpeedValid_Cnt_T_lgc       = Rte_IRead_SignlCondn_Per1_SrlComVehSpeedValid_Cnt_lgc();      /* REQ: SF033A #9 I */
    SrlComVehSpeed_Kph_T_f32            = Rte_IRead_SignlCondn_Per1_SrlComVehSpeed_Kph_f32();           /* REQ: SF033A #33 I */
    SrlComVehYawRateValid_Cnt_T_lgc     = Rte_IRead_SignlCondn_Per1_SrlComVehYawRateValid_Cnt_lgc();    /* REQ: SF033A #79 I */
    SrlComVehYawRate_DegpS_T_f32        = Rte_IRead_SignlCondn_Per1_SrlComVehYawRate_DegpS_f32();       /* REQ: SF033A #78 I */

    /** Vehicle Speed **/   
    #if (STD_ON == BC_SIGNLCONDN_FAULTINJECTIONPOINT)
    Rte_Call_FaultInjection_SCom_FltInjection(&SrlComVehSpeed_Kph_T_f32, FLTINJ_SRLCOMVEHSPD_SGNLCOND); /* REQ: SF033A #72 I */
    #endif
    
    /* REQ: SF033A #110 I */
    if(SrlComVehSpeedValid_Cnt_T_lgc == TRUE)
    {
        SrlComVehSpeed_Kph_T_f32 = SrlComVehSpeed_Kph_T_f32;
    }
    else
    {
        SrlComVehSpeed_Kph_T_f32 = k_SigCon_DefaultVehSpd_Kph_f32;                                      /* REQ: SF033A #110 I */
    }
    /* ENDREQ: SF033A #110 I */
    /* REQ: SF033A #60 I */
    VehSpd_Kph_T_f32 = Limit_m( SrlComVehSpeed_Kph_T_f32, 
                                (SignlCondn_VehSpd_Kph_M_f32 - (k_SigCon_VehSpdSlewRate_KphpS_f32*D_2MS_SEC_F32)),  /* REQ: SF033A #62 I */
                                (SignlCondn_VehSpd_Kph_M_f32 + (k_SigCon_VehSpdSlewRate_KphpS_f32*D_2MS_SEC_F32))); /* REQ: SF033A #62 I */ 
    SignlCondn_VehSpd_Kph_M_f32 = VehSpd_Kph_T_f32;
    /* ENDREQ: SF033A #60 I */ 
    VehSpd_Kph_T_f32 = Limit_m(VehSpd_Kph_T_f32, D_VEHSPDMINLIM_KPH_F32, D_VEHSPDMAXLIM_KPH_F32);   
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleSpeed_Kph_f32(VehSpd_Kph_T_f32);                                  /* REQ: SF033A #11 I */
    
    /** Vehicle Speed Valid **/
    VehSpeedValid_Cnt_T_lgc = VehSpdVld_lgc( VehSpd_Kph_T_f32, 
                                             SrlComVehSpeed_Kph_T_f32, 
                                             k_SigCon_VehSpdDiffThresh_Kph_f32,
                                             SrlComVehSpeedValid_Cnt_T_lgc);    
    SignlCondn_VehSpdVld_Cnt_M_lgc = VehSpeedValid_Cnt_T_lgc;   
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(VehSpeedValid_Cnt_T_lgc);                      /* REQ: SF033A #61 I */

    /** Vehicle Longitudinal Acceleration **/
    /* REQ: SF033A #73 I */
    #if (STD_ON == BC_SIGNLCONDN_FAULTINJECTIONPOINT)
    Rte_Call_FaultInjection_SCom_FltInjection(&SrlComVehLonAccel_MpSecSq_T_f32, FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND);
    #endif
    /* ENDREQ: SF033A #73 I */
    /* REQ: SF033A #111 I */
    if(SrlComVehLonAccelValid_Cnt_T_lgc == TRUE)
    {
    SrlComVehLonAccel_KphpS_T_f32 = SrlComVehLonAccel_MpSecSq_T_f32 * D_ACCUNITCNVN_KPHPSPMPSECSQ_F32;
    }
    else
    {
    SrlComVehLonAccel_KphpS_T_f32 = k_SigCon_DefaultLonAccel_KphpS_f32;                                 /* REQ: SF033A #111 I */
    }
    /* ENDREQ: SF033A #111 I */
    /* REQ: SF033A #63 I */
    VehLonAccel_KphpS_T_f32  = Limit_m(SrlComVehLonAccel_KphpS_T_f32, 
                                      (SignlCondn_VehLonAccel_KphpS_M_f32 -(k_SigCon_LonAccelSlewRate_KphpSecSq_f32 *D_2MS_SEC_F32 )),  /* REQ: SF033A #64 I */
                                      (SignlCondn_VehLonAccel_KphpS_M_f32 +(k_SigCon_LonAccelSlewRate_KphpSecSq_f32*D_2MS_SEC_F32 )));  /* REQ: SF033A #64 I */
    SignlCondn_VehLonAccel_KphpS_M_f32 = VehLonAccel_KphpS_T_f32;
    /* ENDREQ: SF033A #63 I */
    VehLonAccel_KphpS_T_f32 = Limit_m(VehLonAccel_KphpS_T_f32, D_VEHLONACCELMINLIM_KPHPS_F32, D_VEHLONACCELMAXLIM_KPHPS_F32);
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(VehLonAccel_KphpS_T_f32);                      /* REQ: SF033A #39 I */
    
    /** Vehicle Longitudinal Acceleration Valid **/
    VehLonAccelValid_Cnt_T_lgc = VehLonAccelVld_lgc( VehLonAccel_KphpS_T_f32, 
                                                     SrlComVehLonAccel_KphpS_T_f32, 
                                                     k_SigCon_LonAccelDiffThresh_KphpS_f32,
                                                     SrlComVehLonAccelValid_Cnt_T_lgc); 
    SignlCondn_VehLonAccelValid_Cnt_M_lgc = VehLonAccelValid_Cnt_T_lgc;
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(VehLonAccelValid_Cnt_T_lgc);                /* REQ: SF033A #80 I */

    /** Vehicle Lateral Acceleration **/
    /* REQ: SF033A #103 I */
    #if (STD_ON == BC_SIGNLCONDN_FAULTINJECTIONPOINT)
    Rte_Call_FaultInjection_SCom_FltInjection(&SrlComVehLatAccel_MpSecSq_T_f32, FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND);
    #endif
    /* ENDREQ: SF033A #103 I */
    /* REQ: SF033A #112 I */
    LPF_OpUpdate_f32_m(SrlComVehLatAccel_MpSecSq_T_f32, &SignlCondn_LatAccelSV_MpSecSq_M_Str);
    if(SrlComVehLatAccelValid_Cnt_T_lgc == TRUE)
    {
        SrlComVehLatAccel_MpSecSq_T_f32 = SignlCondn_LatAccelSV_MpSecSq_M_Str.SV_Uls_f32;
    }
    else
    {
        SrlComVehLatAccel_MpSecSq_T_f32 = k_SigCon_DefaultLatAccel_MpSecSq_f32;                         /* REQ: SF033A #112 I */ 
    }
    /* ENDREQ: SF033A #112 I */
    /* REQ: SF033A #65 I */
    VehLatAccel_MpSecSq_T_f32  = Limit_m(SrlComVehLatAccel_MpSecSq_T_f32, 
                                        (SignlCondn_VehLatAccel_MpSecSq_M_f32 -(k_SigCon_LatAccelSlewRate_MpSecSq_f32 *D_2MS_SEC_F32 )),  /* REQ: SF033A #85 I */
                                        (SignlCondn_VehLatAccel_MpSecSq_M_f32 +(k_SigCon_LatAccelSlewRate_MpSecSq_f32*D_2MS_SEC_F32 )));  /* REQ: SF033A #85 I */
    SignlCondn_VehLatAccel_MpSecSq_M_f32 = VehLatAccel_MpSecSq_T_f32;                                                                      
    /* ENDREQ: SF033A #65 I */
    VehLatAccel_MpSecSq_T_f32 = Limit_m(VehLatAccel_MpSecSq_T_f32, D_VEHLATACCELMINLIM_MPSECSQ_F32, D_VEHLATACCELMAXLIM_MPSECSQ_F32);
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(VehLatAccel_MpSecSq_T_f32);                  /* REQ: SF033A #56 I */
    
    /** Vehicle Lateral Acceleration Valid**/
     VehLatAccelValid_Cnt_T_lgc = VehLatAccelVld_lgc(VehLatAccel_MpSecSq_T_f32, 
                                                     SrlComVehLatAccel_MpSecSq_T_f32,
                                                     k_SigCon_LatAccelDiffThresh_MpSecSq_f32,
                                                     SrlComVehLatAccelValid_Cnt_T_lgc); 
    SignlCondn_VehLatAccelValid_Cnt_M_lgc = VehLatAccelValid_Cnt_T_lgc;
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(VehLatAccelValid_Cnt_T_lgc);                 /* REQ: SF033A #81 I */

    /** Vehicle Yaw Rate **/
    /* REQ: SF033A #104 I */
    #if (STD_ON == BC_SIGNLCONDN_FAULTINJECTIONPOINT)
    Rte_Call_FaultInjection_SCom_FltInjection(&SrlComVehYawRate_DegpS_T_f32, FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND);
    #endif
    /* ENDREQ: SF033A #104 I */
    /* REQ: SF033A #113 I */
    if(SrlComVehYawRateValid_Cnt_T_lgc == TRUE)
    {
    SrlComVehYawRate_DegpS_T_f32 = SrlComVehYawRate_DegpS_T_f32;
    }
    else
    {
    SrlComVehYawRate_DegpS_T_f32 = k_SigCon_DefaultYawRate_DegpS_f32;
    }
    /* ENDREQ: SF033A #113 I */
    /* REQ: SF033A #84 I */
    VehYawRate_DegpS_T_f32  = Limit_m(SrlComVehYawRate_DegpS_T_f32, 
                                    (SignlCondn_VehYawRate_DegpS_M_f32 -(k_VehYawRateSlew_DegpSecSq_f32*D_2MS_SEC_F32)),  /* REQ: SF033A #85 I */
                                    (SignlCondn_VehYawRate_DegpS_M_f32 +(k_VehYawRateSlew_DegpSecSq_f32*D_2MS_SEC_F32))); /* REQ: SF033A #85 I */
    SignlCondn_VehYawRate_DegpS_M_f32 = VehYawRate_DegpS_T_f32;                                                                     
    /* REQ: SF033A #84 I */
    VehYawRate_DegpS_T_f32 = Limit_m(VehYawRate_DegpS_T_f32, D_VEHYAWRATEMINLIM_DEGPS_F32, D_VEHYAWRATEMAXLIM_DEGPS_F32);
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleYawRate_DegpS_f32(VehYawRate_DegpS_T_f32);                        /* REQ: SF033A #82 I */
    
    /** Vehicle Yaw Rate Valid **/
     VehYawRateValid_Cnt_T_lgc = VehYawRateVld_lgc(VehYawRate_DegpS_T_f32, 
                                                   SrlComVehYawRate_DegpS_T_f32,
                                                   k_SigCon_YawRateDiffThresh_DegpS_f32,
                                                   SrlComVehYawRateValid_Cnt_T_lgc);
    SignlCondn_VehYawRateValid_Cnt_M_lgc = VehYawRateValid_Cnt_T_lgc;
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(VehYawRateValid_Cnt_T_lgc);                  /* REQ: SF033A #83 I */

    /** Estimated Lateral Acceleration **/
    EstimdLatAcce_MpSecSq_T_f32 = ((VehSpd_Kph_T_f32 * D_KPHTOMPSEC_ULS_F32) * 
                                   (VehYawRate_DegpS_T_f32 / D_180OVRPI_ULS_F32));                  /* REQ: SF033A #108 I */  
    EstimdLatAcce_MpSecSq_T_f32 = Limit_m(EstimdLatAcce_MpSecSq_T_f32, D_ESTIMDLATACCEMINLIM_MPSECSQ_F32, 
                                          D_ESTIMDLATACCEMAXLIM_MPSECSQ_F32);                           /* REQ: SF033A #108 I */ 
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(EstimdLatAcce_MpSecSq_T_f32);
    
    /** Estimated Lateral Acceleration Valid **/
    if((VehSpeedValid_Cnt_T_lgc == TRUE) && (VehYawRateValid_Cnt_T_lgc == TRUE))                        /* REQ: SF033A #118 I */ 
    {
        EstimdLatAcceValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        EstimdLatAcceValid_Cnt_T_lgc = FALSE;
    }
    /* Write Output */
    Rte_IWrite_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(EstimdLatAcceValid_Cnt_T_lgc); 
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SIGNLCONDN_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /** Vehicle Speed Valid **/ 
/*******************************************************************************
  * Name        :   VehSpdVld_lgc
  * Description :   Implementation of "Vehicle Speed Valid" logic.
  * Inputs      :   VehSpd_Kph_T_f32, SrlComVehSpeed_Kph_T_f32, 
  *                 DiffThresh_Kph_T_f32, SrlComVehSpeedValid_Cnt_T_lgc
  * Outputs     :   VehSpeedValid_Cnt_T_lgc
  * Usage Notes :   None
  *****************************************************************************/
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehSpdVld_lgc(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
                                                        VAR(float32, AUTOMATIC) SrlComVehSpeed_Kph_T_f32, 
                                                        VAR(float32, AUTOMATIC) DiffThresh_Kph_T_f32,
                                                        VAR(boolean, AUTOMATIC) SrlComVehSpeedValid_Cnt_T_lgc)  
 {
    VAR(float32, AUTOMATIC) AbsVehSpd_Kph_T_f32;
    VAR(boolean, AUTOMATIC) CurrSrlComVehSpeedValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehSpeedValid_Cnt_T_lgc;

    AbsVehSpd_Kph_T_f32 = Abs_f32_m(VehSpd_Kph_T_f32 - SrlComVehSpeed_Kph_T_f32);
    if(AbsVehSpd_Kph_T_f32 < DiffThresh_Kph_T_f32)
    {
        CurrSrlComVehSpeedValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        CurrSrlComVehSpeedValid_Cnt_T_lgc = FALSE;
    }
    if(((SignlCondn_VehSpdVld_Cnt_M_lgc == TRUE) ||
        (CurrSrlComVehSpeedValid_Cnt_T_lgc == TRUE)) &&
        (SrlComVehSpeedValid_Cnt_T_lgc == TRUE))
    {
        VehSpeedValid_Cnt_T_lgc = TRUE;
    }
    else 
    {
        VehSpeedValid_Cnt_T_lgc = FALSE;
    }       
    return VehSpeedValid_Cnt_T_lgc;
 }  
 /** Vehicle Longitudinal Acceleration Valid **/ 
/*******************************************************************************
  * Name        :   VehLonAccelVld_lgc
  * Description :   Implementation of "Vehicle Longitudinal Acceleration Valid" logic.
  * Inputs      :   VehLonAccel_KphpS_T_f32, SrlComVehLonAccel_KphpS_T_f32, 
  *                 DiffThresh_KphpS_T_f32, SrlComVehLonAccelValid_Cnt_T_lgc
  * Outputs     :   VehLonAccelValid_Cnt_T_lgc
  * Usage Notes :   None
  *****************************************************************************/
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehLonAccelVld_lgc(VAR(float32, AUTOMATIC) VehLonAccel_KphpS_T_f32,
                                                             VAR(float32, AUTOMATIC) SrlComVehLonAccel_KphpS_T_f32, 
                                                             VAR(float32, AUTOMATIC) DiffThresh_KphpS_T_f32,
                                                             VAR(boolean, AUTOMATIC) SrlComVehLonAccelValid_Cnt_T_lgc)  
 {
    VAR(float32, AUTOMATIC) AbsVehLonAccel_KphpS_T_f32;
    VAR(boolean, AUTOMATIC) CurrSrlComVehLonAccelValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehLonAccelValid_Cnt_T_lgc;
     
    AbsVehLonAccel_KphpS_T_f32 = Abs_f32_m(VehLonAccel_KphpS_T_f32 - SrlComVehLonAccel_KphpS_T_f32);
    if(AbsVehLonAccel_KphpS_T_f32 < DiffThresh_KphpS_T_f32)
    {
        CurrSrlComVehLonAccelValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        CurrSrlComVehLonAccelValid_Cnt_T_lgc = FALSE;
    }
    if(((SignlCondn_VehLonAccelValid_Cnt_M_lgc == TRUE) ||
        (CurrSrlComVehLonAccelValid_Cnt_T_lgc == TRUE)) &&
        (SrlComVehLonAccelValid_Cnt_T_lgc == TRUE))
    {
        VehLonAccelValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        VehLonAccelValid_Cnt_T_lgc = FALSE;
    }
    return VehLonAccelValid_Cnt_T_lgc;
 }  
 /** Vehicle Lateral Acceleration Valid **/ 
/*******************************************************************************
  * Name        :   VehLatAccelVld_lgc
  * Description :   Implementation of "Vehicle Lateral Acceleration Valid" logic.
  * Inputs      :   VehLatAccel_MpSecSq_T_f32, SrlComVehLatAccel_MpSecSq_T_f32, 
  *                 DiffThresh_MpSecSq_T_f32, SrlComVehLatAccelValid_Cnt_T_lgc
  * Outputs     :   VehLatAccelValid_Cnt_T_lgc
  * Usage Notes :   None
  *****************************************************************************/
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehLatAccelVld_lgc(VAR(float32, AUTOMATIC) VehLatAccel_MpSecSq_T_f32,
                                                             VAR(float32, AUTOMATIC) SrlComVehLatAccel_MpSecSq_T_f32, 
                                                             VAR(float32, AUTOMATIC) DiffThresh_MpSecSq_T_f32,
                                                             VAR(boolean, AUTOMATIC) SrlComVehLatAccelValid_Cnt_T_lgc)
 {
    VAR(float32, AUTOMATIC) AbsVehLatAccel_MpSecSq_T_f32;
    VAR(boolean, AUTOMATIC) CurrSrlComVehLatAccelValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehLatAccelValid_Cnt_T_lgc;
    
    AbsVehLatAccel_MpSecSq_T_f32 =  Abs_f32_m(VehLatAccel_MpSecSq_T_f32 - SrlComVehLatAccel_MpSecSq_T_f32);
    if(AbsVehLatAccel_MpSecSq_T_f32 < DiffThresh_MpSecSq_T_f32)
    {
        CurrSrlComVehLatAccelValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        CurrSrlComVehLatAccelValid_Cnt_T_lgc = FALSE;
    }
    if(((SignlCondn_VehLatAccelValid_Cnt_M_lgc == TRUE) ||
        (CurrSrlComVehLatAccelValid_Cnt_T_lgc == TRUE)) &&
        (SrlComVehLatAccelValid_Cnt_T_lgc == TRUE))
    {
        VehLatAccelValid_Cnt_T_lgc = TRUE;
    }
    else 
    {
        VehLatAccelValid_Cnt_T_lgc = FALSE;
    }       
    return VehLatAccelValid_Cnt_T_lgc;
 }  
 /** Vehicle Yaw Rate Valid **/ 
/*******************************************************************************
  * Name        :   VehYawRateVld_lgc
  * Description :   Implementation of "Vehicle Yaw Rate Valid" logic.
  * Inputs      :   VehYawRate_DegpS_T_f32, SrlComVehYawRate_DegpS_T_f32, 
  *                 DiffThresh_DegpS_T_f32, SrlComVehYawRateValid_Cnt_T_lgc
  * Outputs     :   VehYawRateValid_Cnt_T_lgc
  * Usage Notes :   None
  *****************************************************************************/
 STATIC FUNC(boolean, AP_SIGNLCONDN_CODE) VehYawRateVld_lgc(VAR(float32, AUTOMATIC) VehYawRate_DegpS_T_f32,
                                                            VAR(float32, AUTOMATIC) SrlComVehYawRate_DegpS_T_f32, 
                                                            VAR(float32, AUTOMATIC) DiffThresh_DegpS_T_f32,
                                                            VAR(boolean, AUTOMATIC) SrlComVehYawRateValid_Cnt_T_lgc)    
 {
    VAR(float32, AUTOMATIC) AbsVehYawRate_DegpS_T_f32;
    VAR(boolean, AUTOMATIC) CurrSrlComVehYawRateValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehYawRateValid_Cnt_T_lgc;
     
    AbsVehYawRate_DegpS_T_f32 = Abs_f32_m(VehYawRate_DegpS_T_f32 - SrlComVehYawRate_DegpS_T_f32);
    if(AbsVehYawRate_DegpS_T_f32 < DiffThresh_DegpS_T_f32)
    {
        CurrSrlComVehYawRateValid_Cnt_T_lgc = TRUE;
    }
    else
    {
        CurrSrlComVehYawRateValid_Cnt_T_lgc = FALSE;
    }
    if(((SignlCondn_VehYawRateValid_Cnt_M_lgc == TRUE) ||
        (CurrSrlComVehYawRateValid_Cnt_T_lgc == TRUE)) &&
        (SrlComVehYawRateValid_Cnt_T_lgc == TRUE))
    {
        VehYawRateValid_Cnt_T_lgc = TRUE;
    }
    else 
    {
        VehYawRateValid_Cnt_T_lgc = FALSE;
    } 
    return VehYawRateValid_Cnt_T_lgc;
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
