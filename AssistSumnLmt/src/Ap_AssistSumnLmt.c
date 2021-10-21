/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_AssistSumnLmt.c
 *     Workspace:  C:/EA3 Component/AssistSumnLmt/autosar
 *     SW-C Type:  Ap_AssistSumnLmt
 *  Generated at:  Thu May 11 10:26:27 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_AssistSumnLmt>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /*****************************************************************************
 * Copyright 2011, 2012, 2013, 2014, 2017 Nxtr 
 * Nxtr Confidential
 *
 * Module File Name: Ap_AssistSumnLmt.c
 * Module Description: Implements SF004A Assist Summation Limit
 * Project           : CBD   
 * Author            : Kevin Smith
 **********************************************************************************************************************
 * Version Control:
 * Date Created:      Mon Nov 29 18:34:17 2011
 * %version:          30 %
 * %date_modified:    Sat Feb  1 09:51:49 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/10/11  3        KJS       Initial Release for this component. 
 * 11/11/11  4        KJS       Unit test corrections
 * 01/10/12  6        M. Story  Updated for signal cross check and SF 04 002a
 * 01/27/12  8        LWW       Updated ranges on outputs, use of global constants
 * 02/24/12  9        JWJ       Requirement change: DmapingCmd and Compensation combined limit                #4985
 * 03/19/12  10       VK        Updates to meet FDD SF#04 v004                                                #5085
 * 03/23/12  11       OT        Added inputs per SFD-20                                                       #5130 
 * 06/16/12  14       KJS       Updated Scom ManualTrqCmd input for Vehicle Speed
 * 07/29/12  15       NRAR      AstVehSpdLmt is replaced with VehSpd input for MtrTrqCmd calculation 
 * 08/16/12  16       NRAR      OpTrqOverlay signal is removed from FDD40A and placed in this component. 
 *                              And also Anom#3676 is fixed                                                   #6027
 * 08/27/12  17       NRAR      Unnecessary temp to temp Assignment is removed 
 * 08/28/12  18       NRAR      Updated to FDD ver 008
 * 09/16/12  19       BWL       Added watchdog checkpoints.                                                   #6213
 * 10/22/12  21       JWJ       Anomaly 3942 fix - removed local copy of RTE_E_OK                             #6590
 * 10/23/12  22       JWJ       Removed SCom return as redundant                                              #6590
 * 11/14/12  23       LWW       Moved ManualTrqCmd into new memmap area      
 * 02/21/13  24,25    Selva     Implemented SF-04 v09
 * 04/01/13  26       NRAR      ANOM- 4608, Wrong function call used for FaultInjection                       #7775
 * 01/29/14  27       KJS       Implemented SF-04 v10                                                         #11328
 * 02/01/14  28       KJS       Implemented SF-04 v11 - Anomaly 6292                                          #11358
 * 01/12/14  29       SB        Implemented SF-04 v12                                                         EA3#4232
 * 05/11/17  30       ML        Removed Inputs, Constants, and Cals. Added Init1. Renamed Input.              EA3#15366 
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_AssistSumnLmt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GlobalMacro.h"
#include "fpmtype.h"
#include "CalConstants.h"
#include <float.h>

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */ 

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 

#define ASSISTSUMNLMT_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC volatile VAR(float32, AP_ASSISTSUMNLMT_VAR) LrnPnCntrTCmd_MtrNm_D_f32;               /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_ASSISTSUMNLMT_VAR) PrkAstCmd_MtrNm_D_f32;                   /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_ASSISTSUMNLMT_VAR) CondPullComp_MtrNm_D_f32;                /* PRQA S 3218 */
#define ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

#define ASSISTSUMNLMT_START_SEC_VAR_CLEAREDGS_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32, AP_ASSISTSUMNLMT_VAR) ManualTrqCmd_MtrNm_M_f32;

#define ASSISTSUMNLMT_STOP_SEC_VAR_CLEAREDGS_32
#include "MemMap.h"/* PRQA S 5087 */

#define ASSISTSUMNLMT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(boolean, AP_ASSISTSUMNLMT_VAR) ManualTrqCmdEn_Cnt_M_lgc;
#define ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */

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
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
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
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ASSISTSUMNLMT_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistLmtFunc_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AssistLmtFunc_Scom>
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
 *   void AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistLmtFunc_Scom_ManualTrqCmd
 *********************************************************************************************************************/
    
    if (TRUE == EnableManualCtrl)
    {
        ManualTrqCmdEn_Cnt_M_lgc = TRUE;
        ManualTrqCmd_MtrNm_M_f32 = MtrTrqCmd_MtrNm_f32;
    }
    else
    {
        ManualTrqCmdEn_Cnt_M_lgc = FALSE;
        ManualTrqCmd_MtrNm_M_f32 = 0.0F;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Init1
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

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistSumnLmt_Init1
 *********************************************************************************************************************/

 /* Empty Init Function */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AssistSumnLmt_Per1_AssistCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTGainLtd_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_VehicleSpeed_Kph_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(void)
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
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistSumnLmt_Per1
 *********************************************************************************************************************/
    
    VAR(float32, AUTOMATIC) AssistCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) CombinedDamping_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) LimitedReturn_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PullComp_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PrkAstCmd_MtrNm_T_f32;
    VAR(boolean, AUTOMATIC) PrkAssistDisable_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AstVehSpdLimit_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AstStallLimit_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AstEOTLimit_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) ThermalLimit_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AstEOTGain_Uls_T_f32;
    VAR(float32, AUTOMATIC) AstEOTDampingCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) AstPowerLimit_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
    VAR(float32, AUTOMATIC) PostLimitTorqueSign_Uls_T_f32;
    VAR(float32, AUTOMATIC) TrqOscCmd_MtrNm_T_f32;
    
    VAR(boolean, AUTOMATIC) LimitSrlComSvcDft_Cnt_T_lgc;
    
    VAR(float32, AUTOMATIC) PostLimitTorque_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PreLimitTorque_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PreLimitForStall_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PreLimitForPwr_MtrNm_T_f32;
    
    VAR(boolean, AUTOMATIC) LrnPnCntrEnable_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) LrnPnCntrTCmd_MtrNm_T_f32;
    VAR(boolean, AUTOMATIC) LrnPnCntrDisable_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) CondPullComp_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(float32, AUTOMATIC) OutpTqOvrl_MtrNm_T_f32;
    
    /* stare inputs to local copies */
    AssistCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_AssistCmd_MtrNm_f32();
    CombinedDamping_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32();
    LimitedReturn_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32();
    PullComp_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32();
    PrkAstCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32();
    PrkAssistDisable_Cnt_T_lgc = Rte_IRead_AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc();
    WhlImbRejCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32();
    AstVehSpdLimit_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32();
    AstStallLimit_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32();
    AstEOTLimit_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32();
    ThermalLimit_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32();
    AstEOTGain_Uls_T_f32 = Rte_IRead_AssistSumnLmt_Per1_EOTGainLtd_Uls_f32();
    AstEOTDampingCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32();
    AstPowerLimit_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32();
    OutputRampMult_Uls_T_f32 = Rte_IRead_AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32();
    LimitSrlComSvcDft_Cnt_T_lgc = Rte_IRead_AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc();
    TrqOscCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32();
    LrnPnCntrEnable_Cnt_T_lgc = Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc();
    LrnPnCntrTCmd_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32();
    LrnPnCntrDisable_Cnt_T_lgc = Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc();
    VehSpd_Kph_T_f32 = Rte_IRead_AssistSumnLmt_Per1_VehicleSpeed_Kph_f32();
    OutpTqOvrl_MtrNm_T_f32 = Rte_IRead_AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32();
    
    /* Pre Conditioning */
    CondPullComp_MtrNm_T_f32 = Limit_m(PullComp_MtrNm_T_f32, -k_SnLPullCmpFwLmt_MtrNm_f32, k_SnLPullCmpFwLmt_MtrNm_f32);
    
    if(PrkAssistDisable_Cnt_T_lgc == TRUE)
    {
        PrkAstCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
    }
    
    if(LrnPnCntrDisable_Cnt_T_lgc == TRUE)
    {
        LrnPnCntrTCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
    }
    
    /* Command Summation */
    
    if (LrnPnCntrEnable_Cnt_T_lgc == TRUE)
    {
        PreLimitTorque_MtrNm_T_f32 = LrnPnCntrTCmd_MtrNm_T_f32;
    }
    else
    {
        PreLimitTorque_MtrNm_T_f32 = (AstEOTGain_Uls_T_f32 * AssistCmd_MtrNm_T_f32) + (-CombinedDamping_MtrNm_T_f32) +
                                     (-LimitedReturn_MtrNm_T_f32) + OutpTqOvrl_MtrNm_T_f32 + CondPullComp_MtrNm_T_f32 +
                                     PrkAstCmd_MtrNm_T_f32 + WhlImbRejCmd_MtrNm_T_f32 + (-AstEOTDampingCmd_MtrNm_T_f32) + TrqOscCmd_MtrNm_T_f32;
    }

    if ((TRUE == ManualTrqCmdEn_Cnt_M_lgc) && ( VehSpd_Kph_T_f32 < FLT_EPSILON))
    {
        PreLimitTorque_MtrNm_T_f32 = ManualTrqCmd_MtrNm_M_f32;
    }
    
    /* Apply Gain and Limit */
    PostLimitTorqueSign_Uls_T_f32 = (float32)Sign_f32_m(PreLimitTorque_MtrNm_T_f32);
    PostLimitTorque_MtrNm_T_f32 = Abs_f32_m(PreLimitTorque_MtrNm_T_f32);

    /* -- Calc PreLimitForStall -- */
    PreLimitForStall_MtrNm_T_f32 = Max_m(PostLimitTorque_MtrNm_T_f32, Abs_f32_m(AssistCmd_MtrNm_T_f32));
    
    if ( LimitSrlComSvcDft_Cnt_T_lgc != TRUE )
    {
        /* Defeat is NOT active */
        PostLimitTorque_MtrNm_T_f32 = Min_m(PostLimitTorque_MtrNm_T_f32, AstEOTLimit_MtrNm_T_f32);
        PostLimitTorque_MtrNm_T_f32 = Min_m(PostLimitTorque_MtrNm_T_f32, AstVehSpdLimit_MtrNm_T_f32);
        PostLimitTorque_MtrNm_T_f32 = Min_m(PostLimitTorque_MtrNm_T_f32, AstStallLimit_MtrNm_T_f32);
        PostLimitTorque_MtrNm_T_f32 = Min_m(PostLimitTorque_MtrNm_T_f32, ThermalLimit_MtrNm_T_f32);
    }
    else
    {
        /* Do nothing, defeat is active and the post limit torque value is correct in this case. */
    }

    
    PostLimitTorque_MtrNm_T_f32 = PostLimitTorque_MtrNm_T_f32 * OutputRampMult_Uls_T_f32;
    PreLimitForPwr_MtrNm_T_f32 = PostLimitTorque_MtrNm_T_f32; 
    PostLimitTorque_MtrNm_T_f32 = Min_m(PostLimitTorque_MtrNm_T_f32, AstPowerLimit_MtrNm_T_f32);
    PostLimitTorque_MtrNm_T_f32 = PostLimitTorque_MtrNm_T_f32 * PostLimitTorqueSign_Uls_T_f32;
    
    /* apply limit checks */
    PreLimitTorque_MtrNm_T_f32 = Limit_m(PreLimitTorque_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
    PostLimitTorque_MtrNm_T_f32 = Limit_m(PostLimitTorque_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
    PreLimitForPwr_MtrNm_T_f32 = Limit_m(PreLimitForPwr_MtrNm_T_f32, D_ZERO_ULS_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
    PreLimitForStall_MtrNm_T_f32 = Limit_m(PreLimitForStall_MtrNm_T_f32, D_ZERO_ULS_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
    
    #if(STD_ON == BC_ASSTSUMNLMT_FAULTINJECTIONPOINT)
        Rte_Call_FaultInjection_SCom_FltInjection(&PostLimitTorque_MtrNm_T_f32, FLTINJ_ASSTSUMNLMT);
    #endif
    
    Rte_IWrite_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(PostLimitTorque_MtrNm_T_f32);
    Rte_IWrite_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(PreLimitForPwr_MtrNm_T_f32);
    Rte_IWrite_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(PreLimitForStall_MtrNm_T_f32);
    Rte_IWrite_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(PreLimitTorque_MtrNm_T_f32);
    LrnPnCntrTCmd_MtrNm_D_f32 = LrnPnCntrTCmd_MtrNm_T_f32;
    PrkAstCmd_MtrNm_D_f32 = PrkAstCmd_MtrNm_T_f32;
    CondPullComp_MtrNm_D_f32 = CondPullComp_MtrNm_T_f32;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(void)
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

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistSumnLmt_Per2
 *********************************************************************************************************************/
    VAR(float32, AUTOMATIC) ThermalLimitPerc_Uls_T_f32;
    VAR(float32, AUTOMATIC) PowerLimitPerc_Uls_T_f32;
    VAR(float32, AUTOMATIC) LimitPercFilt_Uls_T_f32; 
    
    /* store inputs to local copies */
    PowerLimitPerc_Uls_T_f32 = Rte_IRead_AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32();
    ThermalLimitPerc_Uls_T_f32 = Rte_IRead_AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32();

    /* process function */
    LimitPercFilt_Uls_T_f32 = Max_m(ThermalLimitPerc_Uls_T_f32, PowerLimitPerc_Uls_T_f32);
    LimitPercFilt_Uls_T_f32 = Limit_m(LimitPercFilt_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
    
    /* store values for output */
    Rte_IWrite_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(LimitPercFilt_Uls_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ASSISTSUMNLMT_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


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
