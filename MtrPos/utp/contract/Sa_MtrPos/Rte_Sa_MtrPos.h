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
 *          File:  Rte_Sa_MtrPos.h
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrPos/autosar
 *     SW-C Type:  Sa_MtrPos
 *  Generated at:  Wed Feb 20 16:17:54 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_MtrPos> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRPOS_H
# define _RTE_SA_MTRPOS_H

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

typedef P2CONST(struct Rte_CDS_Sa_MtrPos, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_AssistAssemblyPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_CumMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_CumMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_SysCCumMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_SysCCumMtrPosMRF_Deg_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrPos_EOLMtrCals_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrPos_EOLMtrCals_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) DstPtr);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08() \
  (Rte_Inst_Sa_MtrPos->MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08->value)

# define Rte_IWrite_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_MtrPos->MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_MtrPos->MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32->value)

# define Rte_IWrite_MtrPos_Per2_CumMtrPosCRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_MtrPos->MtrPos_Per2_CumMtrPosCRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrPos_Per2_CumMtrPosCRF_Deg_f32() \
  (&Rte_Inst_Sa_MtrPos->MtrPos_Per2_CumMtrPosCRF_Deg_f32->value)

# define Rte_IWrite_MtrPos_Per2_CumMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_MtrPos->MtrPos_Per2_CumMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrPos_Per2_CumMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_MtrPos->MtrPos_Per2_CumMtrPosMRF_Deg_f32->value)

# define Rte_IWrite_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_MtrPos->MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32() \
  (&Rte_Inst_Sa_MtrPos->MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32->value)

# define Rte_IWrite_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_MtrPos->MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_MtrPos->MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLMtrCals_WriteBlock Rte_Call_Sa_MtrPos_EOLMtrCals_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MtrPosSnsr_EOLData() (Rte_Inst_Sa_MtrPos->Pim_MtrPosSnsr_EOLData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   MtrPosCal_DataType *Rte_Pim_MtrPosSnsr_EOLData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_MTRPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_CumMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_CumMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_CumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_CumMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_SCom_ReadEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadEOLMtrCals> of PortPrototype <MtrPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrPos_SCom_ReadEOLMtrCals(MtrPosCal_DataType *MtrCalDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_SCom_SetEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLMtrCals> of PortPrototype <MtrPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLMtrCals_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLMtrCals_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrPos_SCom_SetEOLMtrCals(const MtrPosCal_DataType *MtrCalDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);

# define RTE_STOP_SEC_SA_MTRPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1360027620
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/MtrPos/utp/contract/Sa_MtrPos/Rte_Sa_MtrPos.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1360027620
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRPOS_H */
