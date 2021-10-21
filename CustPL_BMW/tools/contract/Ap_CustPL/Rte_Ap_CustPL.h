/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_CustPL.h
 *     Workspace:  C:/SynergyWorkArea/Working/CustPL_BMW/autosar
 *     SW-C Type:  Ap_CustPL
 *  Generated at:  Tue Jun 14 10:15:23 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_CustPL> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CUSTPL_H
# define _RTE_AP_CUSTPL_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_CustPL, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CASSISTMSA_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CBATCURLIMITCUR_Amp_f32 ((Float)0)
# define Rte_InitValue_CCLMSAActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CCLTrqRamp_Uls_f32 ((Float)1)
# define Rte_InitValue_CVEHSPDCURLIMITCURRENT_Amp_f32 ((Float)0)
# define Rte_InitValue_CVEHSPDCURLIMITER_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CVEHSPDCURLIMITSPEED_Kph_f32 ((Float)0)
# define Rte_InitValue_CustCurrLmt_Amp_f32 ((Float)0)
# define Rte_InitValue_MSACommand_MSACmd_enum ((MSA_Cmd_Type)3u)
# define Rte_InitValue_SupplyCurrLmt_Amp_f32 ((Float)166.67)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_CustPL_CASSISTMSA_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_CUSTPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_CustPL_CBATCURLIMITCUR_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_CUSTPL_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_CustPL_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustPL_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_CUSTPL_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_CustPL_Init1_CCLMSAActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_CustPL->CustPL_Init1_CCLMSAActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CustPL_Init1_CCLMSAActive_Cnt_lgc() \
  (&Rte_Inst_Ap_CustPL->CustPL_Init1_CCLMSAActive_Cnt_lgc->value)

# define Rte_IWrite_CustPL_Init1_CCLTrqRamp_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_CustPL->CustPL_Init1_CCLTrqRamp_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CustPL_Init1_CCLTrqRamp_Uls_f32() \
  (&Rte_Inst_Ap_CustPL->CustPL_Init1_CCLTrqRamp_Uls_f32->value)

# define Rte_IRead_CustPL_Per1_CASSISTMSA_Cnt_lgc() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_CASSISTMSA_Cnt_lgc->value)

# define Rte_IRead_CustPL_Per1_CBATCURLIMITCUR_Amp_f32() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_CBATCURLIMITCUR_Amp_f32->value)

# define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32->value)

# define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc->value)

# define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32->value)

# define Rte_IRead_CustPL_Per1_MSACommand_MSACmd_enum() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_MSACommand_MSACmd_enum->value)

# define Rte_IRead_CustPL_Per1_SupplyCurrLmt_Amp_f32() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_SupplyCurrLmt_Amp_f32->value)

# define Rte_IRead_CustPL_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_CustPL->CustPL_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_CustPL_Per1_CCLMSAActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_CustPL->CustPL_Per1_CCLMSAActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CustPL_Per1_CCLMSAActive_Cnt_lgc() \
  (&Rte_Inst_Ap_CustPL->CustPL_Per1_CCLMSAActive_Cnt_lgc->value)

# define Rte_IWrite_CustPL_Per1_CCLTrqRamp_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_CustPL->CustPL_Per1_CCLTrqRamp_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CustPL_Per1_CCLTrqRamp_Uls_f32() \
  (&Rte_Inst_Ap_CustPL->CustPL_Per1_CCLTrqRamp_Uls_f32->value)

# define Rte_IWrite_CustPL_Per1_CustCurrLmt_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_CustPL->CustPL_Per1_CustCurrLmt_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CustPL_Per1_CustCurrLmt_Amp_f32() \
  (&Rte_Inst_Ap_CustPL->CustPL_Per1_CustCurrLmt_Amp_f32->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CASSISTMSA_Cnt_lgc Rte_Read_Ap_CustPL_CASSISTMSA_Cnt_lgc
# define Rte_Read_CBATCURLIMITCUR_Amp_f32 Rte_Read_Ap_CustPL_CBATCURLIMITCUR_Amp_f32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_CustPL_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_CustPL_FaultInjection_SCom_FltInjection




# define RTE_START_SEC_AP_CUSTPL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustPL_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CASSISTMSA_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_CBATCURLIMITCUR_Amp_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CustPL_Init1_CCLMSAActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CustPL_Init1_CCLMSAActive_Cnt_lgc(void)
 *   void Rte_IWrite_CustPL_Init1_CCLTrqRamp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Init1_CCLTrqRamp_Uls_f32(void)
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

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustPL_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_CustPL_Per1_CASSISTMSA_Cnt_lgc(void)
 *   Float Rte_IRead_CustPL_Per1_CBATCURLIMITCUR_Amp_f32(void)
 *   Float Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32(void)
 *   Boolean Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc(void)
 *   Float Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32(void)
 *   MSA_Cmd_Type Rte_IRead_CustPL_Per1_MSACommand_MSACmd_enum(void)
 *   Float Rte_IRead_CustPL_Per1_SupplyCurrLmt_Amp_f32(void)
 *   Float Rte_IRead_CustPL_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CustPL_Per1_CCLMSAActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CustPL_Per1_CCLMSAActive_Cnt_lgc(void)
 *   void Rte_IWrite_CustPL_Per1_CCLTrqRamp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Per1_CCLTrqRamp_Uls_f32(void)
 *   void Rte_IWrite_CustPL_Per1_CustCurrLmt_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Per1_CustCurrLmt_Amp_f32(void)
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

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Per1(void);

# define RTE_STOP_SEC_AP_CUSTPL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1465911370
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/CustPL_BMW/tools/contract/Ap_CustPL/Rte_Ap_CustPL.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1465911370
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CUSTPL_H */
