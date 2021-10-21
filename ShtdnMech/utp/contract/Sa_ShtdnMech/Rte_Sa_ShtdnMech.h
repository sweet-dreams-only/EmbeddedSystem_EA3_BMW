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
 *          File:  Rte_Sa_ShtdnMech.h
 *     Workspace:  C:/SynergyProjects/CBD/ShtdnMech/autosar/Sa_ShtdnMech.dcf
 *     SW-C Type:  Sa_ShtdnMech
 *  Generated at:  Wed Oct 17 10:14:44 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_ShtdnMech> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_SHTDNMECH_H
# define _RTE_SA_SHTDNMECH_H

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

typedef P2CONST(struct Rte_CDS_Sa_ShtdnMech, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_ShtdnMech_FetDrvReset_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_ShtdnMech_SysFault2_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_ShtdnMech_SysFault3_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FetDrvReset_OP_GET Rte_Call_Sa_ShtdnMech_FetDrvReset_OP_GET
# define Rte_Call_SysFault2_OP_GET Rte_Call_Sa_ShtdnMech_SysFault2_OP_GET
# define Rte_Call_SysFault3_OP_GET Rte_Call_Sa_ShtdnMech_SysFault3_OP_GET




# define RTE_START_SEC_SA_SHTDNMECH_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ShtdnMech_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FetDrvReset_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_SysFault2_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault2_E_NOT_OK
 *   Std_ReturnType Rte_Call_SysFault3_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault3_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_SHTDNMECH_APPL_CODE) ShtdnMech_Per1(void);

# define RTE_STOP_SEC_SA_SHTDNMECH_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_FetDrvReset_E_NOT_OK (1U)

# define RTE_E_SysFault2_E_NOT_OK (1U)

# define RTE_E_SysFault3_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1350479524
#    error "The magic number of the generated file <C:/Documents and Settings/nzx5jd/Desktop/DVOutput/Sa_ShtdnMech/Rte_Sa_ShtdnMech.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1350479524
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_SHTDNMECH_H */
