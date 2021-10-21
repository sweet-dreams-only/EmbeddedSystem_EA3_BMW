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
 *          File:  Rte_Ap_Polarity.h
 *     Workspace:  C:/Workspace/Polarity-CBD_Polarity/FDD25_003.0/Polarity/autosar
 *     SW-C Type:  Ap_Polarity
 *  Generated at:  Mon Nov 12 16:08:32 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_Polarity> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_POLARITY_H
# define _RTE_AP_POLARITY_H

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

typedef P2CONST(struct Rte_CDS_Ap_Polarity, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistAssyPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HwPosPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HwTrqPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_MtrPosPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_MtrVelPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_SysC_MtrElecMechPolarity_Cnt_s32 ((SInt32)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_AssistAssyPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_HwPosPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_HwTrqPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_MtrElecMechPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_MtrPosPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_MtrVelPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32(SInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Polarity_CtrlPolEOL_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) ErrorStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Polarity_CtrlPolEOL_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_POLARITY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Polarity_CtrlPolEOL_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_POLARITY_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Polarity_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_Polarity_Init1_AssistAssyPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_AssistAssyPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_AssistAssyPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_AssistAssyPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_HwPosPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_HwPosPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_HwPosPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_HwPosPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_HwTrqPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_HwTrqPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_HwTrqPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_HwTrqPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_MtrElecMechPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_MtrElecMechPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_MtrElecMechPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_MtrPosPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_MtrPosPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_MtrPosPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_MtrPosPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_MtrVelPolarity_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_MtrVelPolarity_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_MtrVelPolarity_Cnt_s08() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_MtrVelPolarity_Cnt_s08->value)

# define Rte_IWrite_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32(data) \
  ( \
  Rte_Inst_Ap_Polarity->Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32->value = (data) \
  )

# define Rte_IWriteRef_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32() \
  (&Rte_Inst_Ap_Polarity->Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32->value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AssistAssyPolarity_Cnt_s08 Rte_Write_Ap_Polarity_AssistAssyPolarity_Cnt_s08
# define Rte_Write_HwPosPolarity_Cnt_s08 Rte_Write_Ap_Polarity_HwPosPolarity_Cnt_s08
# define Rte_Write_HwTrqPolarity_Cnt_s08 Rte_Write_Ap_Polarity_HwTrqPolarity_Cnt_s08
# define Rte_Write_MtrElecMechPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrElecMechPolarity_Cnt_s08
# define Rte_Write_MtrPosPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrPosPolarity_Cnt_s08
# define Rte_Write_MtrVelPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrVelPolarity_Cnt_s08
# define Rte_Write_SysC_MtrElecMechPolarity_Cnt_s32 Rte_Write_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CtrlPolEOL_GetErrorStatus Rte_Call_Ap_Polarity_CtrlPolEOL_GetErrorStatus
# define Rte_Call_CtrlPolEOL_WriteBlock Rte_Call_Ap_Polarity_CtrlPolEOL_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_Polarity_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_k_SystemPolarity_Cnt_b16() (Rte_Inst_Ap_Polarity->Pim_k_SystemPolarity_Cnt_b16)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt16 *Rte_Pim_k_SystemPolarity_Cnt_b16(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_POLARITY_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Polarity_Init1_AssistAssyPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_AssistAssyPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_HwPosPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_HwPosPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_HwTrqPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_HwTrqPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_MtrElecMechPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_MtrPosPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_MtrPosPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_MtrVelPolarity_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_Polarity_Init1_MtrVelPolarity_Cnt_s08(void)
 *   void Rte_IWrite_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32(SInt32 data)
 *   SInt32 *Rte_IWriteRef_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CtrlPolEOL_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_ReadPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Polarity_SCom_ReadPolarity(UInt16 *Polarity_Cnt_b16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AssistAssyPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTrqPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MtrElecMechPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MtrPosPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MtrVelPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_SysC_MtrElecMechPolarity_Cnt_s32(SInt32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_CtrlPolEOL_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_CtrlPolEOL_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Polarity_SCom_RequestOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);

# define RTE_STOP_SEC_AP_POLARITY_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# define RTE_E_Polarity_SCom_RequestOutOfRange (49u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1352758523
#    error "The magic number of the generated file <C:/Workspace/Polarity-CBD_Polarity/FDD25_003.0/Polarity/utp/contract/Ap_Polarity/Rte_Ap_Polarity.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1352758523
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_POLARITY_H */
