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
 *          File:  Components/Rte_Coding.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Fri Apr 28 16:52:11 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CODING_H
# define _RTE_CODING_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# endif
#  define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CbkBlock_Receive(arg1, arg2, arg3) (CbkBlock_Receive(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# endif
#  define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CbkBlockValid_Check(arg1, arg2, arg3, arg4) (CbkBlockValid_Check(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_EndNotification(Coding_DataStatusType dataStatus);
#  define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CbkDataChange_EndNotification(arg1) (CbkDataChange_EndNotification(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_StartNotification(void);
#  define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CbkDataChange_StartNotification() (CbkDataChange_StartNotification(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkPreConditions_Check(P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
#  define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CbkPreConditions_Check(arg1) (CbkPreConditions_Check(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODING_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CODING_APPL_CODE) Coding_Init(void);

FUNC(void, RTE_CODING_APPL_CODE) Coding_GetBlockSize(Coding_BlockIdType blockId, P2VAR(UInt8, AUTOMATIC, RTE_CODING_APPL_VAR) blockSize);

FUNC(void, RTE_CODING_APPL_CODE) Coding_GetDataStatus(P2VAR(Coding_DataStatusType, AUTOMATIC, RTE_CODING_APPL_VAR) dataStatus);

FUNC(void, RTE_CODING_APPL_CODE) Coding_GetVinCpsComparisonResult(P2VAR(Coding_ErrorType, AUTOMATIC, RTE_CODING_APPL_VAR) comparisonResult);

FUNC(void, RTE_CODING_APPL_CODE) Coding_MainFunction(void);

FUNC(void, RTE_CODING_APPL_CODE) Coding_RequestBlock(Coding_BlockIdType blockId);

FUNC(void, RTE_CODING_APPL_CODE) Coding_SetBlockProtection(Coding_BlockIdType blockId, Coding_ProtectionType protection, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_CODING_APPL_VAR) error);

# define RTE_STOP_SEC_CODING_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Coding.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CODING_H */
