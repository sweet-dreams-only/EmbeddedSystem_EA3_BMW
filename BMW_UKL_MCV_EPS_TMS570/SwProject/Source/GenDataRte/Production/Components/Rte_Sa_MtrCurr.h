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
 *          File:  Components/Rte_Sa_MtrCurr.h
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
#ifndef _RTE_SA_MTRCURR_H
# define _RTE_SA_MTRCURR_H

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

#  define Rte_InitValue_ADCMtrCurr1_Volt_f32 (0.0F)
#  define Rte_InitValue_CorrectedMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_DutyCycleSmall_Cnt_u16 (0U)
#  define Rte_InitValue_InstantaneousMotorDirection_Cnt_s08 (0)
#  define Rte_InitValue_MtrCurrDax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_PADelta1_Cnt_u16 (0U)
#  define Rte_InitValue_RawCurrFiltered_Amp_f32 (0.0F)
#  define Rte_InitValue_ValidSampleFlag_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd7_SystemState7_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_7, RTE_VAR_NOINIT) Rte_Task_2ms_7;

#  define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_MtrCurr_Per1_ADCMtrCurr1_Volt_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_ADCMtrCurr1_Volt_f32.value)

#  define Rte_IRead_MtrCurr_Per1_CorrectedMtrPos_Rev_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_CorrectedMtrPos_Rev_f32.value)

#  define Rte_IRead_MtrCurr_Per1_DutyCycleSmall_Cnt_u16() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_DutyCycleSmall_Cnt_u16.value)

#  define Rte_IRead_MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_InstantaneousMotorDirection_Cnt_s08.value)

#  define Rte_IRead_MtrCurr_Per1_PADelta1_Cnt_u16() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_PADelta1_Cnt_u16.value)

#  define Rte_IWrite_MtrCurr_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrDax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrCurr_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrDax_Amp_f32.value)

#  define Rte_IWrite_MtrCurr_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrQax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrCurr_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrQax_Amp_f32.value)

#  define Rte_IWrite_MtrCurr_Per1_RawCurrFiltered_Amp_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_RawCurrFiltered_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrCurr_Per1_RawCurrFiltered_Amp_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_RawCurrFiltered_Amp_f32.value)

#  define Rte_IWrite_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_ValidSampleFlag_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_ValidSampleFlag_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd7_SystemState7_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLShCurrCal_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)2, arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(ShCurrCal_DataType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_MtrCurr_ShCurrCal;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_ShCurrCal() \
  (&Rte_MtrCurr_ShCurrCal)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRCURR_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Init1(void);

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Per1(void);

FUNC(Std_ReturnType, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalGain(void);

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalOffset(void);

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);

# define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_MtrCurr_SCom_CurrentOutOfRange (34U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_MtrCurr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRCURR_H */
