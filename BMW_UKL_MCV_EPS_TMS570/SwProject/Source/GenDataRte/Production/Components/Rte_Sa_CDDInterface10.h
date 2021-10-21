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
 *          File:  Components/Rte_Sa_CDDInterface10.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:20 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE10_H
# define _RTE_SA_CDDINTERFACE10_H

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

#  define Rte_InitValue_CommOffset_Cnt_u16 (0U)
#  define Rte_InitValue_DeadTimeComp_Uls_f32 (0.0F)
#  define Rte_InitValue_DutyCycleSmall_Cnt_u16 (0U)
#  define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_FETFaultPhase_Cnt_enum (0U)
#  define Rte_InitValue_FETFaultType_Cnt_enum (0U)
#  define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
#  define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrTrqCmdSign_Cnt_s16 (0)
#  define Rte_InitValue_PhaseAdvFinal_Cnt_u16 (0U)
#  define Rte_InitValue_SWDutyCycleA_Uls_f32 (0.0F)
#  define Rte_InitValue_SWDutyCycleB_Uls_f32 (0.0F)
#  define Rte_InitValue_SWDutyCycleC_Uls_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_10, RTE_VAR_NOINIT) Rte_Task_InitB_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

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

#  define Rte_IRead_CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_InitB_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_DutyCycleSmall_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_DutyCycleSmall_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleA_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_SWDutyCycleA_Uls_f32.value)

#  define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleB_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_SWDutyCycleB_Uls_f32.value)

#  define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleC_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_SWDutyCycleC_Uls_f32.value)

#  define Rte_IRead_CDDInterface10_Per2_CommOffset_Cnt_u16() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_CommutationOffset_Cnt_u16.value)

#  define Rte_IRead_CDDInterface10_Per2_DeadTimeComp_Uls_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_DeadTimeComp_Uls_f32.value)

#  define Rte_IRead_CDDInterface10_Per2_ModIdxFinal_Uls_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32.value)

#  define Rte_IRead_CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16.value)

#  define Rte_IRead_CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16.value)

#  define Rte_IRead_CDDInterface10_Per3_FETFaultPhase_Cnt_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per3.Rte_FETFaultPhase_Cnt_enum.value)

#  define Rte_IRead_CDDInterface10_Per3_FETFaultType_Cnt_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per3.Rte_FETFaultType_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDD_ApplyPWMMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ApplyMtrElecMechPol(arg1) (CDD_ApplyPWMMtrElecMechPol(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ClearPhsReasSum(arg1) (CDDPorts_ClearPhsReasSum(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void);

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per2(void);

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per3(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_CDDInterface10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE10_H */
