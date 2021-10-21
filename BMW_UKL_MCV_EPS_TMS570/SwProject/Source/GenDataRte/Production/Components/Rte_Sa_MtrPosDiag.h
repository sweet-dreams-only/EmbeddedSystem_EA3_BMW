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
 *          File:  Components/Rte_Sa_MtrPosDiag.h
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Sun Jan 27 10:44:12 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRPOSDIAG_H
# define _RTE_SA_MTRPOSDIAG_H

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

#  define Rte_InitValue_Cos1RTOffset_Volts_f32 (0.0F)
#  define Rte_InitValue_MtrPosMech_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrPosMech2_Rev_f32 (0.0F)
#  define Rte_InitValue_Sin1RTOffset_Volts_f32 (0.0F)
# endif


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

#  define Rte_IRead_MtrPosDiag_Per1_Cos1RTOffset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosDiag_MtrPosDiag_Per1.Rte_Cos1RTOffset_Volts_f32.value)

#  define Rte_IRead_MtrPosDiag_Per1_Sin1RTOffset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosDiag_MtrPosDiag_Per1.Rte_Sin1RTOffset_Volts_f32.value)

#  define Rte_IRead_MtrPosDiag_Per2_MtrPosMech2_Rev_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosDiag_MtrPosDiag_Per2.Rte_MtrPosMech2_Rev_f32.value)

#  define Rte_IRead_MtrPosDiag_Per2_MtrPosMech_Rev_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosDiag_MtrPosDiag_Per2.Rte_MtrPosMech_Rev_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWAB7_APPL_CODE) IoHwAb_InputCosTheta1_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MtrPos_CosTheta1_V_f32 IoHwAb_InputCosTheta1_V_f32
#  define RTE_START_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWAB7_APPL_CODE) IoHwAb_InputSinTheta1_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MtrPos_SinTheta1_V_f32 IoHwAb_InputSinTheta1_V_f32
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr7_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRPOSDIAG_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOSDIAG_APPL_CODE) MtrPosDiag_Per1(void);

FUNC(void, RTE_SA_MTRPOSDIAG_APPL_CODE) MtrPosDiag_Per2(void);

# define RTE_STOP_SEC_SA_MTRPOSDIAG_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_MtrPos_deprecated_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359305166
#    error "The magic number of the generated file <C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_MtrPosDiag.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359305166
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRPOSDIAG_H */
