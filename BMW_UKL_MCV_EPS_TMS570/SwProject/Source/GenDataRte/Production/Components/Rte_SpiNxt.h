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
 *          File:  Components/Rte_SpiNxt.h
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
#ifndef _RTE_SPINXT_H
# define _RTE_SPINXT_H

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

# include "Rte_Hook.h"


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/


# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_SPINXT_EXCLUSIVE_AREA_0() \
  { \
    Rte_EnterHook_SpiNxt_SPINXT_EXCLUSIVE_AREA_0_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_SpiNxt_SPINXT_EXCLUSIVE_AREA_0_Return(); \
  }

#  define Rte_Exit_SPINXT_EXCLUSIVE_AREA_0() \
  { \
    Rte_ExitHook_SpiNxt_SPINXT_EXCLUSIVE_AREA_0_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_SpiNxt_SPINXT_EXCLUSIVE_AREA_0_Return(); \
  }


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SPINXT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_AsyncTransmit(Spi_SequenceType parg0);

FUNC(Std_ReturnType, RTE_SPINXT_APPL_CODE) SpiNxt_GetSequenceResult(Spi_SequenceType parg0);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_SetupEB(Spi_ChannelType parg0, P2CONST(Spi_DataType, AUTOMATIC, RTE_SPINXT_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataType, AUTOMATIC, RTE_SPINXT_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# else
FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_SetupEB(Spi_ChannelType parg0, P2CONST(Spi_DataPtr, AUTOMATIC, RTE_SPINXT_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataPtr, AUTOMATIC, RTE_SPINXT_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# endif

FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_Init(void);

# define RTE_STOP_SEC_SPINXT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Spi_Seq_SPI_SEQ_CANCELLED (3U)

#  define RTE_E_Spi_Seq_SPI_SEQ_FAILED (2U)

#  define RTE_E_Spi_Seq_SPI_SEQ_PENDING (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_SpiNxt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SPINXT_H */
