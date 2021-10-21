/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_BmwHaptcFb.c
 *     Workspace:  C:/SynergyWorkArea/Working/BmwHaptcFb/autosar
 *     SW-C Type:  Ap_BmwHaptcFb
 *  Generated at:  Thu Jul 28 10:27:51 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_BmwHaptcFb>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*********************************************************************************************************************
* Copyright 2015, 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name: Ap_BmwHaptcFb.c
* Module Description: Implementation of CF020A
* Project           : CBD   
* Author            : Spandana Balani
*********************************************************************************************************************
* Version Control:
* %version:           5 %
* %derived_by:        czmgrw %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                          SCR #
* -------   -------  --------  ---------------------------------------------------------------------------------------
* 12/08/15  1         SB        Initial Version                                                               EA3#3414
* 03/03/16  2         SB        Implemented CF020A FDD v1.1.0                                                 EA3#6443
* 04/12/16  3         SB        Implemented CF020A FDD v1.2.0 and fixed anomalies EA3# 5690 and EA3# 6561     EA3#7365
* 05/26/16  4         JK        Anomaly fix - EA3#8186                                                        EA3#8648
* 07/28/16  5         JK        Implemented CF020A FDD v1.3.0                                                 EA3#9840
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_BmwHaptcFb.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "interpolation.h"
#include "fixmath.h"
#include "filters.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables, state variables, and filter constants because of memory map */ 
/* PRQA S 4395 EOF
 * MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 

    #define D_PATRISNGMAXSLEW_MTRNMPS_F32           10.0F
    #define D_PATRISNGMINSLEW_MTRNMPS_F32           0.1F
    #define D_SECTOMSEC_ULS_F32                     1000.0F
    #define D_EVISTATEAVLVIBNOTACTV_CNT_U08         D_ONE_CNT_U8
    #define D_EVISTATEDI_CNT_U08                    14U
    #define D_EVISTATEAVLVIBACTV_CNT_U08            9U
    #define D_EVISTATENOTAVL_CNT_U08                6U     
    #define D_TRQOSCFREQMIN_HZ_F32                  10.0F
    #define D_TRQOSCFREQMAX_HZ_F32                  50.0F
    #define D_TRQOSCAMPMIN_MTRNM_F32                D_ZERO_ULS_F32
    #define D_TRQOSCAMPMAX_MTRNM_F32                1.2F
    #define D_TRQOSCRISNGRAMPRATEMIN_MTRNMPS_F32    0.1F    
    #define D_TRQOSCRISNGRAMPRATEMAX_MTRNMPS_F32    D_MTRRAMPRATERISE_MTRNMPS_F32
    #define D_TRQOSCFALNGRAMPRATEMIN_MTRNMPS_F32    D_MTRRAMPRATEFALL_MTRNMPS_F32
    #define D_TRQOSCFALNGRAMPRATEMAX_MTRNMPS_F32    (-0.1F)
    #define D_PATTERNONE_CNT_U16                    D_ONE_CNT_U16
#define D_2MS_SEC_F32                           0.002F
#define D_PRELIMTQDEGRADEDTHD_MTRNM_F32         0.25F
    
#define BMWHAPTCFB_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
 STATIC VAR(uint8, AP_BMWHAPTCFB_VAR) BmwHF_EVIState_Cnt_M_u08;                 /* PRQA S 3218 */
#define BMWHAPTCFB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define BMWHAPTCFB_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_PatternNrUsed_Cnt_M_u16;           /* PRQA S 3218 */ 
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_PatNrCurr_Cnt_M_u16;               /* PRQA S 3218 */  
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_IntenNrCurr_Cnt_M_u16;             /* PRQA S 3218 */ 
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_PatNrUsed_Cnt_M_u16;               /* PRQA S 3218 */
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_IntNrUsed_Cnt_M_u16;               /* PRQA S 3218 */ 
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_TrqOscActive_mS_M_u16;                 
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_TrqOscPassive_mS_M_u16;   
 STATIC VAR(uint16, AP_BMWHAPTCFB_VAR) BmwHF_ElapsedTime_mS_M_u16;              /* PRQA S 3218 */ 
#define BMWHAPTCFB_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define BMWHAPTCFB_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
 STATIC VAR(float32, AP_BMWHAPTCFB_VAR) BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32;           
 STATIC VAR(uint32, AP_BMWHAPTCFB_VAR) BmwHF_CurrentTime_mS_M_u32; 
#define BMWHAPTCFB_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define BMWHAPTCFB_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_BMWHAPTCFB_VAR) BmwHF_PatSwtPlsDetd_Cnt_M_lgc;           /* PRQA S 3218 */
 STATIC VAR(boolean, AP_BMWHAPTCFB_VAR) BmwHF_IntenSwtPlsDetd_Cnt_M_lgc;        /* PRQA S 3218 */ 
#define BMWHAPTCFB_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define BMWHAPTCFB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, SA_DIGHWTRQSENT_VAR_NOINIT) BmwHF_SysDegradedDivLPFKn_M_Str; /* PRQA S 3218 */
#define BMWHAPTCFB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Function Prototypes */
STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) FltActv_lgc(VAR(boolean, AUTOMATIC) TrqOscDCExceeded_Cnt_T_lgc,
                                                     VAR(boolean, AUTOMATIC) HaptcFbIntenSigVld_Cnt_T_lgc,
                                                     VAR(boolean, AUTOMATIC) HaptcFbPatSigVld_Cnt_T_lgc,
                                                     VAR(float32, AUTOMATIC) PostLimitTrq_MtrNm_T_f32,
                                                     VAR(float32, AUTOMATIC) PreLimitTrq_MtrNm_T_f32);

  STATIC FUNC(void, AP_BmwHF_APPL_CODE) BmwHFState_u08(VAR(boolean, AUTOMATIC) HaptcFbEnable_Cnt_T_lgc,
                                                       VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc, 
                                                       VAR(boolean, AUTOMATIC) BmwHFFltActv_Cnt_T_lgc,
                                                       VAR(uint16, AUTOMATIC) PatNrCurr_Cnt_T_u16);
                                                      
 STATIC FUNC(void, AP_BmwHF_APPL_CODE) TimeHolding(VAR(uint16, AUTOMATIC) PatNrCurr_Cnt_T_u16,
                                                   VAR(boolean, AUTOMATIC) OscHoldEnable_Cnt_T_lgc, 
                                                   VAR(boolean, AUTOMATIC) AlwaysOnHold_Cnt_T_lgc);
                                                        
 STATIC FUNC(uint16, AP_BmwHF_APPL_CODE) HoldSignal_u16(VAR(uint16, AUTOMATIC) Current_Cnt_T_u16,
                                                        VAR(uint16, AUTOMATIC) PrevNr_Cnt_T_u16, 
                                                        VAR(boolean, AUTOMATIC) HoldSigEna_Cnt_T_lgc);
                                                        
 STATIC FUNC(float32, AP_BmwHF_APPL_CODE) RampSlewHolding_f32(VAR(float32, AUTOMATIC) Current_MtrNmpS_T_f32,
                                                              VAR(float32, AUTOMATIC) PrevSlew_MtrNmpS_T_f32, 
                                                              VAR(boolean, AUTOMATIC) HoldSigEna_Cnt_T_lgc);

 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) ChgPlsDetd_lgc(VAR(boolean, AUTOMATIC) ChgPlsDetd_Cnt_T_lgc,
                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PrevSwtPlsDetd_Cnt_T_lgc);
 
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnOR_lgc(VAR(boolean, AUTOMATIC) InpFlag1_Cnt_T_lgc,
                                                      VAR(boolean, AUTOMATIC) InpFlag2_Cnt_T_lgc);                                                    
                                                      
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnNOTEQL_lgc(VAR(uint16, AUTOMATIC) InpFlag1_Cnt_T_u16,
                                                          VAR(uint16, AUTOMATIC) InpFlag2_Cnt_T_u16);
 
    
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnLESS_lgc(VAR(uint16, AUTOMATIC) InpFlag1_Cnt_T_u16,
                                                        VAR(uint16, AUTOMATIC) InpFlag2_Cnt_T_u16);                                                           

 STATIC FUNC(uint16, AP_BmwHF_APPL_CODE) DtrmnEnaTime(VAR(uint16, AUTOMATIC) RampDownTime_mS_T_u16);

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
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400
 * Float: D_TRQOSCFREQINIT_HZ_F32 = 50
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_ONE_CNT_U8 = 1u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_BMWHAPTCFB_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFb_Init1
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWHAPTCFB_APPL_CODE) BmwHaptcFb_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFb_Init1
 *********************************************************************************************************************/
    (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&BmwHF_CurrentTime_mS_M_u32);
    
    /* Initialize Low Pass Filters */
    LPF_KUpdate_f32_m(k_BmwHF_SysDegradedDivFilFrq_Hz_f32, D_2MS_SEC_F32, &BmwHF_SysDegradedDivLPFKn_M_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFb_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, WARMINIT, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_HaptcFbEnable_Cnt_lgc(void)
 *   UInt16 Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenNr_Cnt_u16(void)
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenSigVld_Cnt_lgc(void)
 *   UInt16 Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatNr_Cnt_u16(void)
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatSigVld_Cnt_lgc(void)
 *   Float Rte_IRead_BmwHaptcFb_Per1_PostLimitTrq_MtrNm_f32(void)
 *   Float Rte_IRead_BmwHaptcFb_Per1_PreLimitTrq_MtrNm_f32(void)
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_TrqOscActv_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_TrqOscDCExceeded_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwHaptcFb_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_BmwHaptcFb_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08(void)
 *   void Rte_IWrite_BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32(void)
 *   void Rte_IWrite_BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc(void)
 *   void Rte_IWrite_BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32(Float data)
 *   Float *Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32(void)
 *   void Rte_IWrite_BmwHaptcFb_Per1_TrqOscFreq_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscFreq_Hz_f32(void)
 *   void Rte_IWrite_BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32(Float data)
 *   Float *Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWHAPTCFB_APPL_CODE) BmwHaptcFb_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFb_Per1
 *********************************************************************************************************************/
    VAR(boolean, AUTOMATIC) HaptcFbEnable_Cnt_T_lgc;   
    VAR(uint16, AUTOMATIC)  IntenNrCurr_Cnt_T_u16; 
    VAR(boolean, AUTOMATIC) HaptcFbIntenSigVld_Cnt_T_lgc; 
    VAR(uint16, AUTOMATIC)  PatNrCurr_Cnt_T_u16;    
    VAR(boolean, AUTOMATIC) HaptcFbPatSigVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TrqOscActv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TrqOscDCExceeded_Cnt_T_lgc; 
    VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32; 
    VAR(float32, AUTOMATIC) PostLimitTrq_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PreLimitTrq_MtrNm_T_f32;
    
    VAR(boolean, AUTOMATIC) BmwHFFltActv_Cnt_T_lgc; 
    VAR(uint16, AUTOMATIC)  PatternNrUsed_Cnt_T_u16;
    VAR(boolean, AUTOMATIC) PatChgPlsDetd_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) IntenChgPlsDetd_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) PatSwtPlsDetd_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) IntenSwtPlsDetd_Cnt_T_lgc; 
    
    VAR(boolean, AUTOMATIC) OscHoldEnable_Cnt_T_lgc; 
    VAR(boolean, AUTOMATIC) AlwaysOnHold_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) PatternHoldRampDown_Cnt_T_lgc;
    
    VAR(uint16, AUTOMATIC)  PatNrUsed_Cnt_T_u16; 
    VAR(boolean, AUTOMATIC) PatternSwitchPulse_Cnt_T_lgc; 
    
    VAR(boolean, AUTOMATIC) IntenHold_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) IntenHoldTrqOscEnaRampDown_Cnt_T_lgc;
    
    VAR(uint16, AUTOMATIC)  IntNrUsed_Cnt_T_u16;
    VAR(boolean, AUTOMATIC) IntenPulse_Cnt_T_lgc;
    
    VAR(uint16, AUTOMATIC)  VehicleSpeed_Kph_T_u11p5;
    VAR(uint16, AUTOMATIC)  TrqOscAmp_MtrNm_T_u2p14; 
    VAR(float32, AUTOMATIC) TrqOscAmp_MtrNm_T_f32;
    VAR(uint16, AUTOMATIC)  TrqOscFreq_Hz_T_u16p0;
    VAR(float32, AUTOMATIC) TrqOscFreq_Hz_T_f32;
    VAR(boolean, AUTOMATIC) PatternPulse_Cnt_T_lgc; 
    
    VAR(float32, AUTOMATIC) TrqOscRisngRampRateLimtd_MtrNmpS_T_f32; 
    VAR(float32, AUTOMATIC)  RampDownTime_mS_T_f32;
    VAR(uint16, AUTOMATIC) EnableTime_Cnt_T_u16;
    VAR(uint16, AUTOMATIC) ResetTime_Cnt_T_u16; 
    VAR(boolean, AUTOMATIC) TrqOscEnableTemp_Cnt_T_lgc; 
    VAR(boolean, AUTOMATIC) TempFlag_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TrqOscEnable_Cnt_T_lgc;
    
    VAR(float32, AUTOMATIC) TrqOscFallingRampRate_MtrNmpS_T_f32;    
    
    /* Read Inputs */
    HaptcFbEnable_Cnt_T_lgc         = Rte_IRead_BmwHaptcFb_Per1_HaptcFbEnable_Cnt_lgc();
    IntenNrCurr_Cnt_T_u16           = Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenNr_Cnt_u16();
    HaptcFbIntenSigVld_Cnt_T_lgc    = Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenSigVld_Cnt_lgc();
    PatNrCurr_Cnt_T_u16             = Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatNr_Cnt_u16();
    HaptcFbPatSigVld_Cnt_T_lgc      = Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatSigVld_Cnt_lgc();
    TrqOscActv_Cnt_T_lgc            = Rte_IRead_BmwHaptcFb_Per1_TrqOscActv_Cnt_lgc();
    TrqOscDCExceeded_Cnt_T_lgc      = Rte_IRead_BmwHaptcFb_Per1_TrqOscDCExceeded_Cnt_lgc();
    VehicleSpeedValid_Cnt_T_lgc     = Rte_IRead_BmwHaptcFb_Per1_VehicleSpeedValid_Cnt_lgc();
    VehicleSpeed_Kph_T_f32          = Rte_IRead_BmwHaptcFb_Per1_VehicleSpeed_Kph_f32(); 
    PostLimitTrq_MtrNm_T_f32        = Rte_IRead_BmwHaptcFb_Per1_PostLimitTrq_MtrNm_f32();
    PreLimitTrq_MtrNm_T_f32         = Rte_IRead_BmwHaptcFb_Per1_PreLimitTrq_MtrNm_f32();
    
    BmwHFFltActv_Cnt_T_lgc = FltActv_lgc(TrqOscDCExceeded_Cnt_T_lgc, HaptcFbIntenSigVld_Cnt_T_lgc, HaptcFbPatSigVld_Cnt_T_lgc,PostLimitTrq_MtrNm_T_f32,PreLimitTrq_MtrNm_T_f32);

    /* Current BmwHF State Determination */
    /* BmwHF_EVIState_Cnt_M_u08 is determined in BmwHFState_u08 function */
    (void)BmwHFState_u08(HaptcFbEnable_Cnt_T_lgc,VehicleSpeedValid_Cnt_T_lgc,BmwHFFltActv_Cnt_T_lgc,PatNrCurr_Cnt_T_u16); 
    
    if((BmwHF_EVIState_Cnt_M_u08 == D_EVISTATEAVLVIBACTV_CNT_U08) ||
       (BmwHF_EVIState_Cnt_M_u08 == D_EVISTATEAVLVIBNOTACTV_CNT_U08))
    {               
        /** Calc Freq RampRate Amp and TrqOscEna  **/
        /* PatternNr Holding While In Actv TrqOsc */        
        PatternNrUsed_Cnt_T_u16 = HoldSignal_u16(PatNrCurr_Cnt_T_u16, BmwHF_PatternNrUsed_Cnt_M_u16, TrqOscActv_Cnt_T_lgc);        
        BmwHF_PatternNrUsed_Cnt_M_u16 = PatternNrUsed_Cnt_T_u16;
        
        PatChgPlsDetd_Cnt_T_lgc = CondnNOTEQL_lgc(PatNrCurr_Cnt_T_u16, BmwHF_PatNrCurr_Cnt_M_u16);        
        BmwHF_PatNrCurr_Cnt_M_u16 = PatNrCurr_Cnt_T_u16;
            
        
        IntenChgPlsDetd_Cnt_T_lgc = CondnNOTEQL_lgc(IntenNrCurr_Cnt_T_u16, BmwHF_IntenNrCurr_Cnt_M_u16);        
        BmwHF_IntenNrCurr_Cnt_M_u16 = IntenNrCurr_Cnt_T_u16;
        
        /* Latch PatSwtPlsDetd and IntenSwtPlsDetd in If, else Set PatSwtPlsDetd and IntenSwtPlsDetd to false */
        if(TrqOscActv_Cnt_T_lgc == TRUE)                    
        {           
            /* Latch PatSwtPlsDetd and IntenSwtPlsDetd */
            PatSwtPlsDetd_Cnt_T_lgc = ChgPlsDetd_lgc(PatChgPlsDetd_Cnt_T_lgc, &BmwHF_PatSwtPlsDetd_Cnt_M_lgc);            
            IntenSwtPlsDetd_Cnt_T_lgc = ChgPlsDetd_lgc(IntenChgPlsDetd_Cnt_T_lgc, &BmwHF_IntenSwtPlsDetd_Cnt_M_lgc);          
        }
        else
        {
            /* Set PatSwtPlsDetd and IntenSwtPlsDetd to false */
            PatSwtPlsDetd_Cnt_T_lgc = FALSE; 
            IntenSwtPlsDetd_Cnt_T_lgc = FALSE;                       
        }
        BmwHF_PatSwtPlsDetd_Cnt_M_lgc = PatSwtPlsDetd_Cnt_T_lgc;
        BmwHF_IntenSwtPlsDetd_Cnt_M_lgc = IntenSwtPlsDetd_Cnt_T_lgc;        
        
        /* TrqOscHold, AlwaysOnHold and AlwaysOnPatternHoldRampDown */
        if(PatternNrUsed_Cnt_T_u16 > 1U)
        {            
            /* Upd TrqOscHold, Set false AlwaysOnHold and AlwaysOnPatternHoldRampDown */
            OscHoldEnable_Cnt_T_lgc = TrqOscActv_Cnt_T_lgc; 
            AlwaysOnHold_Cnt_T_lgc = FALSE;
            PatternHoldRampDown_Cnt_T_lgc = FALSE;          
        }        
        else if(PatternNrUsed_Cnt_T_u16 == 1U)
        {
            /* Set false to TrqOscHold,  Upd AlwaysOnHold and AlwaysOnPatternHoldRampDown */
            OscHoldEnable_Cnt_T_lgc = FALSE;
            AlwaysOnHold_Cnt_T_lgc = TrqOscActv_Cnt_T_lgc;          
            PatternHoldRampDown_Cnt_T_lgc = PatSwtPlsDetd_Cnt_T_lgc; 
        }
        else
        {           
            /* Set false to all three flgs */
            OscHoldEnable_Cnt_T_lgc = FALSE;
            AlwaysOnHold_Cnt_T_lgc = FALSE;          
            PatternHoldRampDown_Cnt_T_lgc = FALSE;            
        }   
        /* PatNrUsed */
        PatNrUsed_Cnt_T_u16 = HoldSignal_u16(PatNrCurr_Cnt_T_u16, 
                                             BmwHF_PatNrUsed_Cnt_M_u16, 
                                             CondnOR_lgc(OscHoldEnable_Cnt_T_lgc, AlwaysOnHold_Cnt_T_lgc));
                                             
        PatternSwitchPulse_Cnt_T_lgc = CondnNOTEQL_lgc(PatNrUsed_Cnt_T_u16,BmwHF_PatNrUsed_Cnt_M_u16);  
        BmwHF_PatNrUsed_Cnt_M_u16 = PatNrUsed_Cnt_T_u16;
        
        /* IntenHold, IntenHoldTrqOscEnaRampDown */
        if(PatNrUsed_Cnt_T_u16 > 1U)
        {
            /* Set true IntenHold, Set false IntenHoldTrqOscEnaRampDown  */
            IntenHold_Cnt_T_lgc = IntenSwtPlsDetd_Cnt_T_lgc;
            IntenHoldTrqOscEnaRampDown_Cnt_T_lgc = FALSE;
        }
        else if(PatNrUsed_Cnt_T_u16 == 1U)
        {
            /*  Set false IntenHold, Set true HoldAndRampDownTrqOscEna */
            IntenHold_Cnt_T_lgc = FALSE;
            IntenHoldTrqOscEnaRampDown_Cnt_T_lgc = IntenSwtPlsDetd_Cnt_T_lgc;
        }
        else
        {
            /* Set false IntenHold and  IntenHoldTrqOscEnaRampDown */
            IntenHold_Cnt_T_lgc = FALSE;
            IntenHoldTrqOscEnaRampDown_Cnt_T_lgc = FALSE;
        }
        /* IntNrUsed */
        IntNrUsed_Cnt_T_u16 = HoldSignal_u16(IntenNrCurr_Cnt_T_u16, 
                                            BmwHF_IntNrUsed_Cnt_M_u16, 
                                            CondnOR_lgc(IntenHold_Cnt_T_lgc, IntenHoldTrqOscEnaRampDown_Cnt_T_lgc));   
                                                     
        IntenPulse_Cnt_T_lgc = CondnNOTEQL_lgc(IntNrUsed_Cnt_T_u16, BmwHF_IntNrUsed_Cnt_M_u16);        
        BmwHF_IntNrUsed_Cnt_M_u16 = IntNrUsed_Cnt_T_u16; 
                                                                
        /* Amplitude */
        VehicleSpeed_Kph_T_u11p5 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u11p5_T);     
        TrqOscAmp_MtrNm_T_u2p14 = BilinearXYM_u16_u16Xu16YM_Cnt(VehicleSpeed_Kph_T_u11p5,
                                                                IntNrUsed_Cnt_T_u16,
                                                                t_BmwHF_VehSpd_Kph_u11p5,
                                                                TableSize_m(t_BmwHF_VehSpd_Kph_u11p5),
                                                                t_BmwHF_Inten_Uls_u16,
                                                                t2_BmwHF_Amp_MtrNm_u2p14[0],
                                                                TableSize_m(t_BmwHF_Inten_Uls_u16));
        TrqOscAmp_MtrNm_T_f32 = FPM_FixedToFloat_m(TrqOscAmp_MtrNm_T_u2p14, u2p14_T);
        /* Frequency */
        TrqOscFreq_Hz_T_u16p0 = BilinearXYM_u16_u16Xu16YM_Cnt(VehicleSpeed_Kph_T_u11p5,
                                                                IntNrUsed_Cnt_T_u16,
                                                                t_BmwHF_VehSpd_Kph_u11p5,
                                                                TableSize_m(t_BmwHF_VehSpd_Kph_u11p5),
                                                                t_BmwHF_Inten_Uls_u16,
                                                                t2_BmwHF_Frq_Hz_u16[0],
                                                                TableSize_m(t_BmwHF_Inten_Uls_u16));
        TrqOscFreq_Hz_T_f32 = FPM_FixedToFloat_m(TrqOscFreq_Hz_T_u16p0, u16p0_T);
        
        /* Determine PatternPulse */      
        PatternPulse_Cnt_T_lgc = CondnOR_lgc(PatternSwitchPulse_Cnt_T_lgc, IntenPulse_Cnt_T_lgc);         
        /* TrqOscActive, TrqOscPassive, EVIRaisingSlew, ActiveTimeHolding, PassiveTimeHolding, RampSlewHolding */
        (void)TimeHolding( PatNrCurr_Cnt_T_u16,OscHoldEnable_Cnt_T_lgc,AlwaysOnHold_Cnt_T_lgc);         
        
        /** RunningPatternNumber **/ 
        /*  Trq Osc Output */
        if(PatNrUsed_Cnt_T_u16 > 1U)
        {           
            /* RampDownTime */
            TrqOscRisngRampRateLimtd_MtrNmpS_T_f32 = Limit_m(BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32, D_PATRISNGMINSLEW_MTRNMPS_F32, D_PATRISNGMAXSLEW_MTRNMPS_F32);
            RampDownTime_mS_T_f32 = (TrqOscAmp_MtrNm_T_f32/TrqOscRisngRampRateLimtd_MtrNmpS_T_f32)*D_SECTOMSEC_ULS_F32;
            EnableTime_Cnt_T_u16 = DtrmnEnaTime((uint16)RampDownTime_mS_T_f32);
            ResetTime_Cnt_T_u16 = BmwHF_TrqOscPassive_mS_M_u16 + BmwHF_TrqOscActive_mS_M_u16;
            if(PatternPulse_Cnt_T_lgc == FALSE)
            {
                (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BmwHF_CurrentTime_mS_M_u32, &BmwHF_ElapsedTime_mS_M_u16);             
            } 
            /* ElapsedTime < Enable Time */
            TrqOscEnableTemp_Cnt_T_lgc = CondnLESS_lgc(BmwHF_ElapsedTime_mS_M_u16, EnableTime_Cnt_T_u16); 
            /* ResetTime < ElapsedTime */
            TempFlag_Cnt_T_lgc = CondnLESS_lgc(ResetTime_Cnt_T_u16,BmwHF_ElapsedTime_mS_M_u16);          
            if((PatternPulse_Cnt_T_lgc == TRUE) || (TempFlag_Cnt_T_lgc == TRUE))
            {
                (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&BmwHF_CurrentTime_mS_M_u32);                                
            }
        }
        /* AlwaysOn Output */
        else if(PatNrUsed_Cnt_T_u16 == 1U)
        {
            TrqOscEnableTemp_Cnt_T_lgc = TRUE;
        }
        /*  Disable Mode */
        else
        {
            TrqOscEnableTemp_Cnt_T_lgc = FALSE;
        }
        /* Set false Ramp Down Immediately */
        if((PatternHoldRampDown_Cnt_T_lgc == TRUE) || (IntenHoldTrqOscEnaRampDown_Cnt_T_lgc == TRUE))
        {           
            TrqOscEnable_Cnt_T_lgc = FALSE;
        }
        /* Instant Output */
        else
        {
            TrqOscEnable_Cnt_T_lgc = TrqOscEnableTemp_Cnt_T_lgc;
        }           
    }
    /* Set TrqOscEnable false, Set Amp zero, and Freq to Init */
    else
    {
        TrqOscEnable_Cnt_T_lgc = FALSE;
        TrqOscAmp_MtrNm_T_f32 = D_ZERO_ULS_F32;
        TrqOscFreq_Hz_T_f32 = D_TRQOSCFREQINIT_HZ_F32;
        BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32 = D_TRQOSCRISNGRAMPRATEMAX_MTRNMPS_F32;
    }
    TrqOscFallingRampRate_MtrNmpS_T_f32 = (-BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32);
    /* Limit Outputs */
    TrqOscFreq_Hz_T_f32 = Limit_m(TrqOscFreq_Hz_T_f32, D_TRQOSCFREQMIN_HZ_F32, D_TRQOSCFREQMAX_HZ_F32);
    TrqOscAmp_MtrNm_T_f32 = Limit_m(TrqOscAmp_MtrNm_T_f32, D_TRQOSCAMPMIN_MTRNM_F32, D_TRQOSCAMPMAX_MTRNM_F32);
    BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32 = Limit_m(BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32, D_TRQOSCRISNGRAMPRATEMIN_MTRNMPS_F32, D_TRQOSCRISNGRAMPRATEMAX_MTRNMPS_F32);
    TrqOscFallingRampRate_MtrNmpS_T_f32 = Limit_m(TrqOscFallingRampRate_MtrNmpS_T_f32, D_TRQOSCFALNGRAMPRATEMIN_MTRNMPS_F32, D_TRQOSCFALNGRAMPRATEMAX_MTRNMPS_F32);
    
    /* Write Outputs */    
    Rte_IWrite_BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08(BmwHF_EVIState_Cnt_M_u08);
    Rte_IWrite_BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32(TrqOscAmp_MtrNm_T_f32);
    Rte_IWrite_BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc(TrqOscEnable_Cnt_T_lgc);
    Rte_IWrite_BmwHaptcFb_Per1_TrqOscFreq_Hz_f32(TrqOscFreq_Hz_T_f32);
    Rte_IWrite_BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32(BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32); 
    Rte_IWrite_BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32(TrqOscFallingRampRate_MtrNmpS_T_f32);
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_BMWHAPTCFB_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
  /* BmwHFFltActv */
/*********************************************************************************************************************
  * Name        :   FltActv_lgc
  * Description :   BmwHFFltActv_Cnt_T_lgc is determined in the function based on the 
  *                 TrqOscDCExceeded_Cnt_T_lgc, HaptcFbIntenSigVld_Cnt_T_lgc, HaptcFbPatSigVld_Cnt_T_lgc
  * Inputs      :   TrqOscDCExceeded_Cnt_T_lgc, HaptcFbIntenSigVld_Cnt_T_lgc, HaptcFbPatSigVld_Cnt_T_lgc
  * Outputs     :   BmwHFFltActv_Cnt_T_lgc
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) FltActv_lgc(VAR(boolean, AUTOMATIC) TrqOscDCExceeded_Cnt_T_lgc,
                                                      VAR(boolean, AUTOMATIC) HaptcFbIntenSigVld_Cnt_T_lgc, 
                                                      VAR(boolean, AUTOMATIC) HaptcFbPatSigVld_Cnt_T_lgc,
                                                      VAR(float32, AUTOMATIC) PostLimitTrq_MtrNm_T_f32,
                                                      VAR(float32, AUTOMATIC) PreLimitTrq_MtrNm_T_f32)
{
    VAR(boolean, AUTOMATIC) BmwHFFltActv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) SysDegradedChk_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) AbsPreLimitTrq_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AbsPostLimitTrq_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) SysDegradedFild_Uls_T_f32;

    /* SysDegradedChk */
    AbsPreLimitTrq_MtrNm_T_f32 = Abs_f32_m(PreLimitTrq_MtrNm_T_f32);
    AbsPostLimitTrq_MtrNm_T_f32 = Abs_f32_m(PostLimitTrq_MtrNm_T_f32);

    if(AbsPreLimitTrq_MtrNm_T_f32 > D_PRELIMTQDEGRADEDTHD_MTRNM_F32)
    {
    	/* ChkSysDegraded */
    	SysDegradedFild_Uls_T_f32 = LPF_OpUpdate_f32_m((AbsPostLimitTrq_MtrNm_T_f32/AbsPreLimitTrq_MtrNm_T_f32), &BmwHF_SysDegradedDivLPFKn_M_Str);
    	if(SysDegradedFild_Uls_T_f32 < k_BmwHF_EPSDegradedFltThd_Uls_f32)
    	{
    		SysDegradedChk_Cnt_T_lgc = TRUE;
    	}
    	else
    	{
    		SysDegradedChk_Cnt_T_lgc = FALSE;
    	}
    }
    else
    {
    	/* NoChk */
    	SysDegradedChk_Cnt_T_lgc = FALSE;
    }


    if((TrqOscDCExceeded_Cnt_T_lgc == TRUE) ||
        (HaptcFbIntenSigVld_Cnt_T_lgc == FALSE) || 
        (HaptcFbPatSigVld_Cnt_T_lgc == FALSE) ||
        (SysDegradedChk_Cnt_T_lgc == TRUE))
    {
        BmwHFFltActv_Cnt_T_lgc = TRUE;
    }
    else
    {
        BmwHFFltActv_Cnt_T_lgc = FALSE;
    }
     return(BmwHFFltActv_Cnt_T_lgc);
 }  

 /* Current BmwHF State Determination */ 
/*********************************************************************************************************************
  * Name        :   BmwHFState_u08
  * Description :   Implementation of "Current BmwHF State Determination" block.
  * Inputs      :   HaptcFbEnable_Cnt_T_lgc, VehicleSpeedValid_Cnt_T_lgc, 
  *                 BmwHFFltActv_Cnt_T_lgc, PatNrCurr_Cnt_T_u16
  * Outputs     :   BmwHF_EVIState_Cnt_M_u08
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(void, AP_BmwHF_APPL_CODE) BmwHFState_u08(VAR(boolean, AUTOMATIC) HaptcFbEnable_Cnt_T_lgc,
                                                      VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc, 
                                                      VAR(boolean, AUTOMATIC) BmwHFFltActv_Cnt_T_lgc,
                                                      VAR(uint16, AUTOMATIC) PatNrCurr_Cnt_T_u16)
{                                                       
    /* Disable */           
    if(HaptcFbEnable_Cnt_T_lgc == FALSE)
    {
        BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEDI_CNT_U08; 
    }
    else
    {       
        /* Enable */
        switch(BmwHF_EVIState_Cnt_M_u08)
        {
            /* 1 - Available-vibration not active */
            case D_EVISTATEAVLVIBNOTACTV_CNT_U08:
            {
                if((VehicleSpeedValid_Cnt_T_lgc == FALSE) ||
                    (BmwHFFltActv_Cnt_T_lgc == TRUE))                
                {
                    BmwHF_EVIState_Cnt_M_u08 = D_EVISTATENOTAVL_CNT_U08;
                }
                else if(PatNrCurr_Cnt_T_u16 != 0U)
                {
                    BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEAVLVIBACTV_CNT_U08;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            break;
            /* 9 - Available-vibration active */
            case D_EVISTATEAVLVIBACTV_CNT_U08:
            { 
                if((VehicleSpeedValid_Cnt_T_lgc == FALSE) ||
                    (BmwHFFltActv_Cnt_T_lgc == TRUE))
                
                {
                    BmwHF_EVIState_Cnt_M_u08 = D_EVISTATENOTAVL_CNT_U08;
                }
                else if(PatNrCurr_Cnt_T_u16 == 0U)
                {
                    BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEAVLVIBNOTACTV_CNT_U08;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            break;
			/* 6 - Not available */             
            case D_EVISTATENOTAVL_CNT_U08:
            {            
                if( (BmwHFFltActv_Cnt_T_lgc == FALSE) &&
                     (VehicleSpeedValid_Cnt_T_lgc == TRUE) )
                {
                    BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEAVLVIBNOTACTV_CNT_U08;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            break;
            
			/* 14 - Disable */
            case(D_EVISTATEDI_CNT_U08):            
                BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEAVLVIBNOTACTV_CNT_U08;             
            break;          
            default:
                BmwHF_EVIState_Cnt_M_u08 = D_EVISTATEAVLVIBNOTACTV_CNT_U08;
            break;          
        }
    }
    BmwHF_EVIState_Cnt_M_u08 = Limit_m(BmwHF_EVIState_Cnt_M_u08, D_EVISTATEAVLVIBNOTACTV_CNT_U08, D_EVISTATEDI_CNT_U08); 
}
 /* Pattern Holding */
/*********************************************************************************************************************
  * Name        :   TimeHolding
  * Description :   Implementation of "TrqOscActive, TrqOscPassive, EVIRaisingSlew,
  *                 ActiveTimeHolding, PassiveTimeHolding, RampSlewHolding" blocks.
  * Inputs      :   PatNrCurr_Cnt_T_u16, OscHoldEnable_Cnt_T_lgc, AlwaysOnHold_Cnt_T_lgc
  * Outputs     :   None
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(void, AP_BmwHF_APPL_CODE) TimeHolding(VAR(uint16, AUTOMATIC) PatNrCurr_Cnt_T_u16,
                                                    VAR(boolean, AUTOMATIC) OscHoldEnable_Cnt_T_lgc, 
                                                    VAR(boolean, AUTOMATIC) AlwaysOnHold_Cnt_T_lgc)
{
    VAR(uint16, AUTOMATIC) TrqOscActiveTemp_mS_T_u16;
    VAR(uint16, AUTOMATIC) TrqOscPassiveTemp_mS_T_u16;
    VAR(uint16, AUTOMATIC) TrqOscActive_mS_T_u16;
    VAR(uint16, AUTOMATIC) TrqOscPassive_mS_T_u16;
    VAR(uint16, AUTOMATIC) EVIRaisingSlew_MtrNmpS_T_u11p5;
    VAR(float32, AUTOMATIC) EVIRaisingSlewTemp_MtrNmpS_T_f32;
    VAR(float32, AUTOMATIC) TrqOscRisingRampRate_MtrNmpS_T_f32;
    
    /* TrqOscActive */
    TrqOscActiveTemp_mS_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwHF_Pat_Cnt_u16,
                                                            t_BmwHF_PatActvTi_mS_u16,
                                                            TableSize_m(t_BmwHF_Pat_Cnt_u16),
                                                            PatNrCurr_Cnt_T_u16);
    /* TrqOscPassive */
    TrqOscPassiveTemp_mS_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwHF_Pat_Cnt_u16,
                                                             t_BmwHF_PatPasTi_mS_u16,
                                                             TableSize_m(t_BmwHF_Pat_Cnt_u16),
                                                             PatNrCurr_Cnt_T_u16);
    /* EVIRaisingSlew */
    EVIRaisingSlew_MtrNmpS_T_u11p5 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwHF_Pat_Cnt_u16,
                                                                 t_BmwHF_PatRisngSlew_MtrNmpS_u11p5,
                                                                 TableSize_m(t_BmwHF_Pat_Cnt_u16),
                                                                 PatNrCurr_Cnt_T_u16);
    EVIRaisingSlewTemp_MtrNmpS_T_f32 = FPM_FixedToFloat_m(EVIRaisingSlew_MtrNmpS_T_u11p5, u11p5_T);    
    /* ActiveTimeHolding */
    TrqOscActive_mS_T_u16 = HoldSignal_u16(TrqOscActiveTemp_mS_T_u16, BmwHF_TrqOscActive_mS_M_u16, OscHoldEnable_Cnt_T_lgc);    
    BmwHF_TrqOscActive_mS_M_u16 = TrqOscActive_mS_T_u16;
    /* PassiveTimeHolding */
    TrqOscPassive_mS_T_u16 = HoldSignal_u16(TrqOscPassiveTemp_mS_T_u16, BmwHF_TrqOscPassive_mS_M_u16, OscHoldEnable_Cnt_T_lgc);    
    BmwHF_TrqOscPassive_mS_M_u16 = TrqOscPassive_mS_T_u16;
    /* RampSlewHolding */       
    TrqOscRisingRampRate_MtrNmpS_T_f32 = RampSlewHolding_f32(EVIRaisingSlewTemp_MtrNmpS_T_f32, 
                                                             BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32, 
                                                             CondnOR_lgc(OscHoldEnable_Cnt_T_lgc,AlwaysOnHold_Cnt_T_lgc));    
    BmwHF_TrqOscRisingRampRate_MtrNmpS_M_f32 = TrqOscRisingRampRate_MtrNmpS_T_f32;  
}
    
 /* Pattern Holding */
/*********************************************************************************************************************
  * Name        :   HoldSignal_u16
  * Description :   Implementation of "PatternNr Holding While In Actv TrqOsc" block and/or holding logic
  * Inputs      :   Current_Cnt_T_u16, PrevNr_Cnt_T_u16, HoldSigEna_Cnt_T_lgc
  * Outputs     :   CurrentSignal_Cnt_T_u16
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(uint16, AP_BmwHF_APPL_CODE) HoldSignal_u16(VAR(uint16, AUTOMATIC) Current_Cnt_T_u16,
                                                        VAR(uint16, AUTOMATIC) PrevNr_Cnt_T_u16, 
                                                        VAR(boolean, AUTOMATIC) HoldSigEna_Cnt_T_lgc)
{
    VAR(uint16, AUTOMATIC) CurrentSignal_Cnt_T_u16;
    if(HoldSigEna_Cnt_T_lgc == FALSE)
    {
        /* Update Curr Pat */
        CurrentSignal_Cnt_T_u16 = Current_Cnt_T_u16;
    }
    else
    {
        /* Reuse Prev Pat Nr */       
       CurrentSignal_Cnt_T_u16 = PrevNr_Cnt_T_u16;
    }
    return(CurrentSignal_Cnt_T_u16);
 }
 
/* RampSlewHolding */
/*********************************************************************************************************************
  * Name        :   RampSlewHolding_f32
  * Description :   Implementation of "RampSlewHolding" block.
  * Inputs      :   Current_MtrNmpS_T_f32, PrevSlew_MtrNmpS_T_f32, HoldSigEna_Cnt_T_lgc
  * Outputs     :   CurrentSignal_MtrNmpS_T_f32
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(float32, AP_BmwHF_APPL_CODE) RampSlewHolding_f32(VAR(float32, AUTOMATIC) Current_MtrNmpS_T_f32,
                                                              VAR(float32, AUTOMATIC) PrevSlew_MtrNmpS_T_f32, 
                                                              VAR(boolean, AUTOMATIC) HoldSigEna_Cnt_T_lgc)
{
    VAR(float32, AUTOMATIC) CurrentSignal_MtrNmpS_T_f32;
    if(HoldSigEna_Cnt_T_lgc == FALSE)
    {
        CurrentSignal_MtrNmpS_T_f32 = Current_MtrNmpS_T_f32;
    }
    else
    {
        CurrentSignal_MtrNmpS_T_f32 = PrevSlew_MtrNmpS_T_f32;
    }
    return(CurrentSignal_MtrNmpS_T_f32);
 }  
 
 /* Intensity, Pattern Switch Detected*/
/*********************************************************************************************************************
  * Name        :   ChgPlsDetd_lgc
  * Description :   Implementation of block with IntenSwtPlsDetd OR PatSwtPlsDetd output 
  * Inputs      :   DetectPulse_Cnt_T_lgc
  * Outputs     :   SwtPlsDetd_Cnt_T_lgc
  * Usage Notes :   None
  *******************************************************************************************************************/
STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) ChgPlsDetd_lgc(VAR(boolean, AUTOMATIC) ChgPlsDetd_Cnt_T_lgc,
                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PrevSwtPlsDetd_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) SwtPlsDetd_Cnt_T_lgc;
    if( *PrevSwtPlsDetd_Cnt_T_lgc == FALSE)
    {
        SwtPlsDetd_Cnt_T_lgc = ChgPlsDetd_Cnt_T_lgc;
    }
    else
    {
        SwtPlsDetd_Cnt_T_lgc = *PrevSwtPlsDetd_Cnt_T_lgc;
    }           
    *PrevSwtPlsDetd_Cnt_T_lgc = SwtPlsDetd_Cnt_T_lgc;
    return(SwtPlsDetd_Cnt_T_lgc);     
 }
 
 /*********************************************************************************************************************
  * Name        :   CondnOR_lgc
  * Description :   Logical OR is applied on inputs and outputs the result
  * Inputs      :   InpFlag1_Cnt_T_lgc, InpFlag2_Cnt_T_lgc
  * Outputs     :   OutpFlag_Cnt_T_lgc
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnOR_lgc(VAR(boolean, AUTOMATIC) InpFlag1_Cnt_T_lgc,
                                                      VAR(boolean, AUTOMATIC) InpFlag2_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) OutpFlag_Cnt_T_lgc;
    if((InpFlag1_Cnt_T_lgc == TRUE) || (InpFlag2_Cnt_T_lgc == TRUE))
    {
        OutpFlag_Cnt_T_lgc = TRUE;
    }
    else
    {
        OutpFlag_Cnt_T_lgc = FALSE;
    }
    return(OutpFlag_Cnt_T_lgc);
 } 
 
 /*********************************************************************************************************************
  * Name        :   CondnNOTEQL_lgc
  * Description :   Checks if Input 1 is not equal Input 2 and outputs the result
  * Inputs      :   InpFlag1_Cnt_T_u16, InpFlag2_Cnt_T_u16
  * Outputs     :   OutpFlag_Cnt_T_lgc
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnNOTEQL_lgc(VAR(uint16, AUTOMATIC) InpFlag1_Cnt_T_u16,
                                                          VAR(uint16, AUTOMATIC) InpFlag2_Cnt_T_u16)
{
    VAR(boolean, AUTOMATIC) OutpFlag_Cnt_T_lgc;
    if(InpFlag1_Cnt_T_u16 != InpFlag2_Cnt_T_u16)
    {
        OutpFlag_Cnt_T_lgc = TRUE;
    }
    else
    {
        OutpFlag_Cnt_T_lgc = FALSE;
    }
    return(OutpFlag_Cnt_T_lgc);
 }
 
  /*********************************************************************************************************************
  * Name        :   CondnLESS_lgc
  * Description :   Checks if Input 1 is less than Input 2 and outputs the result
  * Inputs      :   InpFlag1_Cnt_T_u16, InpFlag2_Cnt_T_u16
  * Outputs     :   OutpFlag_Cnt_T_lgc
  * Usage Notes :   None
  *******************************************************************************************************************/
 STATIC FUNC(boolean, AP_BmwHF_APPL_CODE) CondnLESS_lgc(VAR(uint16, AUTOMATIC) InpFlag1_Cnt_T_u16,
                                                        VAR(uint16, AUTOMATIC) InpFlag2_Cnt_T_u16)
{
    VAR(boolean, AUTOMATIC) OutpFlag_Cnt_T_lgc;
    if(InpFlag1_Cnt_T_u16 < InpFlag2_Cnt_T_u16)
    {
        OutpFlag_Cnt_T_lgc = TRUE;
    }
    else
    {
        OutpFlag_Cnt_T_lgc = FALSE;
    }
    return(OutpFlag_Cnt_T_lgc);
 }
 
/*********************************************************************************************************************
* Name        :   DtrmnEnaTime
* Description :   Determine the enable time
* Inputs      :   RampDownTime_mS_T_u16
* Outputs     :   EnableTime_mS_T_u16
* Usage Notes :   None
*******************************************************************************************************************/
STATIC FUNC(uint16, AP_BmwHF_APPL_CODE) DtrmnEnaTime(VAR(uint16, AUTOMATIC) RampDownTime_mS_T_u16)
{
	VAR(uint16, AUTOMATIC) EnableTime_mS_T_u16;

	if(BmwHF_TrqOscActive_mS_M_u16 > RampDownTime_mS_T_u16)
	{
		EnableTime_mS_T_u16 = (BmwHF_TrqOscActive_mS_M_u16 - RampDownTime_mS_T_u16);
	}
	else
    {
		EnableTime_mS_T_u16 = 0U;
    }

	return EnableTime_mS_T_u16;
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
