
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  FrTrcv.c
 *    Component:  MICROSAR FR Transceiver Driver
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  FlexRay transceiver driver implementation, according to:
 *                AUTOSAR FlexRay Transceiver Driver, AUTOSAR Release 3.0
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Knut Winkelbach               wnk           Vctr Informatik GmbH
 *  Andreas Herkommer             hr            Vctr Informatik GmbH
 *  Klaus Bergdolt                ber           Vctr Informatik GmbH
 *  Sebastian Schmar              ssr           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2005-05-24  hr      -             Creation
 *  1.02.00   2006-05-22  ber     -             Adaptation to AUTOSAR 2.0
 *  2.00.00   2006-08-24  hr      -             Complete rework for Gen2
 *  2.01.00   2006-12-15  ber     -             Import wakeup source definition from EcuM.h
 *  2.02.00   2007-07-26  ssr     -             Initialize FrTrcv_Status word with zero, 
 *                                              delete readout of status word within init phase
 *  2.03.00   2007-08-31  hr      -             Minor Updates, Memory Mapping
 *  2.03.01   2007-12-16  hr      -             ESCAN00023747 Development Error Tracer was triggered by wrong compares
 *  3.00.00   2008-02-05  hr      -             Complete rework for AUTOSAR Release 3.0
 *  3.00.01   2008-02-12  hr      -             Minor updates
 *  3.00.02   2008-02-13  hr      -             Editorial changes
 *  3.00.03   2008-03-12  hr      -             Compiler Abstraction
 *            2008-03-12  hr      -             New configuration parameters
 *            2008-03-12  hr      -             MISRA checks
 *  3.00.04   2008-03-28  hr      -             Incorporated Review findings
 *  3.00.05   2008-04-01  hr      ESCAN00025654 Clear Transceiver Wakeup
 *  3.00.06   2008-04-18  hr      ESCAN00025971 DEM events wrapper
 *            2008-04-18  hr      ESCAN00025640 Version check of GENy component against implementation
 *            2008-04-18  hr      ESCAN00026133 Support of InitMemory service
 *            2008-04-18  hr      ESCAN00026286 Wakeup detected init
 *            2008-04-18  hr      ESCAN00026287 interrupt & polling in CB
 *            2008-04-18  hr      -             Lib version check
 *  3.00.07   2008-06-04  hr      ESCAN00027346 Removed FRTRCV_WU_POWER_ON and FRTRCV_LOCALWAKEUP detection
 *  3.00.08   2008-07-04  hr      ESCAN00026625 Extension for MSR3.0 generator version checks
 *  3.00.09   2008-08-18  hr      ESCAN00029287 Single Channel API incomplete for FrTrcv_30_Tja1080dio_Cbk_WakeupByTransceiver
 *            2008-08-18  hr      ESCAN00029454 Library issue with number of Transceivers
 *  3.01.00   2008-10-01  hr      ESCAN00029735 instanceID by FrTrcv_30_Tja1080dio_GetVersionInfo not set
 *  3.02.00   2008-11-07  hr      ESCAN00031137 ERRN Pin not low for wakeup detection
 *  3.03.00   2008-11-19  hr      ESCAN00030263 PreCompile and Linktime Crc Check
 *  3.04.00   2008-11-27  hr      ESCAN00031637 Remove Support of SWS Req FrTrcv309
 *  3.05.00   2008-12-02  hr      ESCAN00031775 Remove unnecessary MISRA violations
 *  3.05.01   2009-02-25  hr      ESCAN00033397 Missing extern in call-back declaration
 *            2009-02-25  hr      ESCAN00029695 AUTOSAR Dummy Statements
 *            2009-02-25  hr      ESCAN00033495 Wrong MemMap.h sections used
 *            2009-02-25  hr      ESCAN00034964 Single Channel API change for AUTOSAR SWS compliance
 *  3.05.02   2009-05-05  hr      ESCAN00034905 Wrong MemMap.h Stop section defines
 *  3.05.03   2009-05-06  hr      ESCAN00034037 Compile warnings by extended version checks
 *  3.05.04   2009-07-30  hr      ESCAN00036155 pre-processor checks for building the library
 *  3.05.05   2009-10-29  hr      ESCAN00038804 Support Vendor Id and vendor api infix in file and API names
 *  3.05.06   2010-01-19  hr      ESCAN00040215 Extended Version Check causes compile error
 *            2010-02-08  hr      ESCAN00040646 Remove dio in naming
 *  3.05.07   2010-03-26  hr      ESCAN00041864 EcuM_SetWakeupEvent call with active interrupt locks
 *            2010-04-21  hr      ESCAN00040839 Move FrTrcv_TrcvModeType and FrTrcv_TrcvWUReasonType to Fr_GeneralTypes.h
 *  3.05.08   2010-05-18  hr      ESCAN00042990 Missing MISRA2004 justifications
 *                                ESCAN00043289 Interrupts are enabled to early in FrTrcv_Phy
 *  3.05.09   2010-07-15  hr      ESCAN00044081 Transceiver might hang in Goto-Sleep Mode
 *  3.06.00   2011-02-22  hr      ESCAN00047306 Adapt MainFunction for usage with IdentityManagerConfig
 *********************************************************************************************************************/
#ifndef FRTRCV_CBK_H
#define FRTRCV_CBK_H

#include "FrTrcv_30_Tja1080.h"

#define FRTRCV_CBK_MAJOR_VERSION  0x03
#define FRTRCV_CBK_MINOR_VERSION  0x06
#define FRTRCV_CBK_PATCH_VERSION  0x00

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CODE
  #include "MemMap.h"
#endif

/* wakeup notification */
extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
#define FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver(TrcvIdx)   FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

#endif
  /* FRTRCV_CBK_H */
