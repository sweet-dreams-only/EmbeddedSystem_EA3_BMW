/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Sa_MtrPos.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:21 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRPOS_H
# define _RTE_SA_MTRPOS_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_AssistAssemblyPolarity_Cnt_s08 (0)
#  define Rte_InitValue_CumMtrPosCRF_Deg_f32 (0.0F)
#  define Rte_InitValue_CumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_SysCCumMtrPosCRF_Deg_f32 (0.0F)
#  define Rte_InitValue_SysCCumMtrPosMRF_Deg_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_1ms_10, RTE_VAR_NOINIT) Rte_Task_1ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_MtrPos_Per2_AssistAssemblyPolarity_Cnt_s08() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_Polarity_AssistAssyPolarity_Cnt_s08.value)

#  define Rte_IWrite_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_AlignedCumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos_Per2_AlignedCumMtrPosMRF_Deg_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_AlignedCumMtrPosMRF_Deg_f32.value)

#  define Rte_IWrite_MtrPos_Per2_CumMtrPosCRF_Deg_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_CumMtrPosCRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos_Per2_CumMtrPosCRF_Deg_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_CumMtrPosCRF_Deg_f32.value)

#  define Rte_IWrite_MtrPos_Per2_CumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_MtrPos_CumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos_Per2_CumMtrPosMRF_Deg_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrPos_CumMtrPosMRF_Deg_f32.value)

#  define Rte_IWrite_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosCRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosCRF_Deg_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosCRF_Deg_f32.value)

#  define Rte_IWrite_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos_Per2_SysCCumMtrPosMRF_Deg_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosMRF_Deg_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLMtrCals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)1, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPos_MtrPosSnsr_EOLData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_MtrPosSnsr_EOLData() \
  (&Rte_MtrPos_MtrPosSnsr_EOLData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRPOS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Init1(void);

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_Per2(void);

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);

FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);

# define RTE_STOP_SEC_SA_MTRPOS_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_MtrPos.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRPOS_H */
