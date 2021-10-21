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
 *          File:  Rte_IoHwAb10.h
 *     Workspace:  C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/autosar
 *     SW-C Type:  IoHwAb10
 *  Generated at:  Wed Jan 23 10:15:38 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <IoHwAb10> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB10_H
# define _RTE_IOHWAB10_H

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

typedef P2CONST(struct Rte_CDS_IoHwAb10, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_IOHWAB10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: NHETSigCtrl_GetPhaseDisconnectSignal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetPhaseDisconnectSignal> of PortPrototype <NHETSigCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NHETSigCtrl_GetPhaseDisconnectSignal(UInt8 *Signal_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_GetPhaseDisconnectSignal(P2VAR(UInt8, AUTOMATIC, RTE_IOHWAB10_APPL_VAR) Signal_Cnt_T_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NHETSigCtrl_SetPhaseDisconnectSignal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPhaseDisconnectSignal> of PortPrototype <NHETSigCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc);

# define RTE_STOP_SEC_IOHWAB10_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1358950249
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/utp/contract/IoHwAb10/Rte_IoHwAb10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1358950249
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_IOHWAB10_H */
