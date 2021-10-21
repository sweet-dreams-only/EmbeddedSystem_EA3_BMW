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
 *          File:  Rte_Ap_TJADamp.h
 *     Workspace:  C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ESG_Dev_65/TJADamp-1/TJADamp/autosar
 *     SW-C Type:  Ap_TJADamp
 *  Generated at:  Wed Jan 15 15:56:59 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TJADamp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TJADAMP_H
# define _RTE_AP_TJADAMP_H

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

typedef P2CONST(struct Rte_CDS_Ap_TJADamp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CustomDamp_MtrNm_f32 ((Float)0)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_TJADampSclRqst_Uls_f32 ((Float)0)
# define Rte_InitValue_TJAState_Cnt_enum ((TJAStateType)1u)
# define Rte_InitValue_TJAStateRqst_Cnt_enum ((TJAStateType)1u)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TJADamp_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_TJADAMP_APPL_VAR) NTCFailed_Ptr_T_lgc);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_TJADamp_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_TJADamp->TJADamp_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_TJADamp_Per1_TJADampSclRqst_Uls_f32() \
  (Rte_Inst_Ap_TJADamp->TJADamp_Per1_TJADampSclRqst_Uls_f32->value)

# define Rte_IRead_TJADamp_Per1_TJAStateRqst_Cnt_enum() \
  (Rte_Inst_Ap_TJADamp->TJADamp_Per1_TJAStateRqst_Cnt_enum->value)

# define Rte_IRead_TJADamp_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_TJADamp->TJADamp_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_TJADamp_Per1_CustomDamp_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TJADamp->TJADamp_Per1_CustomDamp_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_TJADamp_Per1_CustomDamp_MtrNm_f32() \
  (&Rte_Inst_Ap_TJADamp->TJADamp_Per1_CustomDamp_MtrNm_f32->value)

# define Rte_IWrite_TJADamp_Per1_TJAState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_TJADamp->TJADamp_Per1_TJAState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_TJADamp_Per1_TJAState_Cnt_enum() \
  (&Rte_Inst_Ap_TJADamp->TJADamp_Per1_TJAState_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_TJADamp_NxtrDiagMgr_GetNTCFailed




# define RTE_START_SEC_AP_TJADAMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TJADamp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TJADamp_Per1
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
 *   Float Rte_IRead_TJADamp_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_TJADamp_Per1_TJADampSclRqst_Uls_f32(void)
 *   TJAStateType Rte_IRead_TJADamp_Per1_TJAStateRqst_Cnt_enum(void)
 *   Float Rte_IRead_TJADamp_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TJADamp_Per1_CustomDamp_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TJADamp_Per1_CustomDamp_MtrNm_f32(void)
 *   void Rte_IWrite_TJADamp_Per1_TJAState_Cnt_enum(TJAStateType data)
 *   TJAStateType *Rte_IWriteRef_TJADamp_Per1_TJAState_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Per1(void);

# define RTE_STOP_SEC_AP_TJADAMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1389820955
#    error "The magic number of the generated file <C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ESG_Dev_65/TJADamp-1/TJADamp/utp/contract/Ap_TJADamp/Rte_Ap_TJADamp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1389820955
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TJADAMP_H */
