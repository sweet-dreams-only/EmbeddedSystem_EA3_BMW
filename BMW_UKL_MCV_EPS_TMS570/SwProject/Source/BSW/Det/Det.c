/* STARTSINGLE_OF_MULTIPLE */


/*****************************************************************************
 * Project Name: AUTOSAR Demonstrator
 *    File Name: Det.c
 *
 *  Description: Implementation of Development Error Tracer
 *
 ******************************************************************************
 *               C O P Y R I G H T
 ******************************************************************************
 * Copyright (c) 2005-2009 by Vctr Informatik GmbH.      All rights reserved.
 *
 *       This software is copyright protected and 
 *       proporietary to Vctr Informatik GmbH.
 *       Vctr Informatik GmbH grants to you only
 *       those rights as set out in the license conditions.
 *       All other rights remain with Vctr Informatik GmbH.
 * 
 *       Diese Software ist urheberrechtlich geschuetzt. 
 *       Vctr Informatik GmbH raeumt Ihnen an dieser Software nur 
 *       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 *       Alle anderen Rechte verbleiben bei Vctr Informatik GmbH.
 *
 ******************************************************************************
 *               A U T H O R   I D E N T I T Y
 ******************************************************************************
 * Initials     Name                      Company
 * ********     *********************     *************************************
 * Om           Oliver Meili              Vctr Informatik GmbH
 * Jk           Joachim Kalmbach          Vctr Informatik GmbH
 * HH           Hartmut Hoerner           Vctr Informatik GmbH
 ******************************************************************************
 *               R E V I S I O N   H I S T O R Y
 ******************************************************************************
 * Date        Version  Author  Description
 * **********  *******  ******  ***********************************************
 * 2005-09-05  0.01.00  Om      Creation
 * 2006-05-18  2.00.00  Om      Update for AUTOSAR Release 2.0
 * 2007-08-08  3.00.00  Jk      Update for AUTOSAR Release 2.1 
 * 2007-09-17  3.01.00  Jk      GetVersionInfo API added 
 * 2007-11-28  3.02.00  HH      Extended debug features added 
 * 2008-01-02  4.00.00  HH      Update for AUTOSAR Release 3.0
 *                              compiler abstraction and memmap added
 * 2008-09-12  4.01.00  HH      ESCAN00023736: DET entry callout
 *                              ESCAN00029923: DET could be called recursively
 * 2008-12-09  4.02.00  HH      ESCAN00030591: compile error if extended version check is disabled
 *                              ESCAN00031617: Compiler warning about sprintf on CANoe emulation platform
 * 2008-12-09  4.03.00  HH      ESCAN00033897: case-sensitive issue: #include "VStdLib.h" instead of "#include "vstdlib.h" in Det.c
 * 2009-05-20  4.03.01  HH      ESCAN00034249: DET entry callout Appl_DetEntryCallout is only called once
 *                              ESCAN00034566: Compiler warnings because of unused parameters in Det_ReportError
 * 2010-07-27  4.03.02  HH      ESCAN00039898: Endless loop on CANoe platform
 *                              ESCAN00042300: support time-stamp for write window messages on CANoe platform
 *****************************************************************************/

#include "Det.h"

#include "v_cfg.h" /* needed for C_COMP_... switch */

#if defined( DET_DEBUG_ENABLED )
#  include "SchM_Det.h"
#endif

/**
 * Version check for AUTOSAR specification consistency
 */
#if (DET_AR_MAJOR_VERSION != 2)
#  error "Source and Header file are inconsistent!"
#endif

#if (DET_AR_MINOR_VERSION != 2)
#  error "Source and Header file are inconsistent!"
#endif

#if (DET_AR_PATCH_VERSION != 0)
#  error "Source and Header file are inconsistent!"
#endif

/**
 * Version check for source and header file consistency
 */
#if (DET_SW_MAJOR_VERSION != 4)
#  error "Source and Header file are inconsistent!"
#endif

#if (DET_SW_MINOR_VERSION != 3)
#  error "Source and Header file are inconsistent!"
#endif

#if (DET_SW_PATCH_VERSION != 2)
#  error "Source and Header file are inconsistent!"
#endif

/**
 * Version check for generator DLL consistency
 */

#if (!defined(V_SUPPRESS_EXTENDED_VERSION_CHECK))

# if (SYSSERVICE_ASRDET_GENTOOL_GENY_MAJOR_VERSION != 0x01u)
#  error "GENy DLL is inconsistent!"
# endif

# if (SYSSERVICE_ASRDET_GENTOOL_GENY_MINOR_VERSION != 0x07u)
#  error "GENy DLL is inconsistent!"
# endif

#endif

#if defined( DET_ENABLED )

# if defined( DET_DEBUG_ENABLED )

#   define Det_EnterCritical() SchM_Enter_Det(DET_EXCLUSIVE_AREA_0)
#   define Det_LeaveCritical() SchM_Exit_Det(DET_EXCLUSIVE_AREA_0)

# define DET_START_SEC_VAR_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */

/* global variables, should be put in a watch window */
# if DET_GLOBALFILTERSIZE > 0
volatile VAR(DetInfoType,DET_VAR) detGlobalFilter[DET_GLOBALFILTERSIZE]; /* ##### use this variable to configure global filters */ /* PRQA S 1504 */ /* PRQA S 850 */
# endif
# if DET_BREAKFILTERSIZE > 0
volatile VAR(DetInfoType,DET_VAR) detBreakFilter[DET_BREAKFILTERSIZE];   /* ##### use this variable to configure break filters */ /* PRQA S 1504 */ /* PRQA S 850 */
# endif
# if DET_LOGBUFFERSIZE > 0
volatile VAR(DetInfoType,DET_VAR) detLogBuffer[DET_LOGBUFFERSIZE];       /* ##### use this variable to view log buffer */ /* PRQA S 1504 */ /* PRQA S 850 */
STATIC volatile VAR(uint8,DET_VAR) detLock1;                                     /* used to resolve ESCAN00029923 */ /* PRQA S 1504 */ /* PRQA S 850 */
# endif
volatile VAR(DetStatusType,DET_VAR) detStatus;                           /* ##### use this variable to configure DET debug operation */ /* PRQA S 1504 */ /* PRQA S 850 */

# define DET_STOP_SEC_VAR_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */

# endif /* DET_DEBUG_ENABLED */

#if defined( DET_ENTRY_CALLOUT_ENABLED )
# define DET_START_SEC_VAR_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(uint8,DET_VAR) detLock2;                                     /* used to resolve ESCAN00029923 */ /* PRQA S 1504 */ /* PRQA S 850 */
# define DET_STOP_SEC_VAR_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */
#endif


#define DET_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

/*******************************************************************************
 * Global functions as an interface from EcuM to DET for initialization
 * and start
 *******************************************************************************/

FUNC(void, DET_CODE) Det_Init( void ) /* PRQA S 1503 */ /* PRQA S 850 */
{
#if defined( DET_DEBUG_ENABLED )
# if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0) || (DET_LOGBUFFERSIZE > 0)
  VAR(uint8,AUTOMATIC) i; /* PRQA S 850 */
# endif
  detStatus.globalFilterActive=0;
  detStatus.logActive=0;
  detStatus.logIndex=0;
  detStatus.breakOnLogOverrun=0;
  detStatus.breakFilterActive=0;
  detStatus.unlockBreak=0;
# if DET_GLOBALFILTERSIZE > 0
  for(i=0;i<DET_GLOBALFILTERSIZE;i++)
  {
    detGlobalFilter[i].moduleId=0;
    detGlobalFilter[i].instanceId=0;
    detGlobalFilter[i].apiId=0;
    detGlobalFilter[i].errorId=0;
  }
# endif
# if DET_BREAKFILTERSIZE > 0
  for(i=0;i<DET_BREAKFILTERSIZE;i++)
  {
    detBreakFilter[i].moduleId=0;
    detBreakFilter[i].instanceId=0;
    detBreakFilter[i].apiId=0;
    detBreakFilter[i].errorId=0;
  }
# endif
# if DET_LOGBUFFERSIZE > 0
  for(i=0;i<DET_LOGBUFFERSIZE;i++)
  {
    detLogBuffer[i].moduleId=0;
    detLogBuffer[i].instanceId=0;
    detLogBuffer[i].apiId=0;
    detLogBuffer[i].errorId=0;
  }
  detLock1=0;
# endif
#endif
#if defined( DET_ENTRY_CALLOUT_ENABLED )
  detLock2=0;
#endif
}

FUNC(void, DET_CODE) Det_Start( void ) /* PRQA S 1503 */ /* PRQA S 850 */
{
}

/*******************************************************************************
 * Global function for BSW-Modules to report errors to the DET
 *******************************************************************************/
FUNC(void, DET_CODE) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ) /* PRQA S 1503 */ /* PRQA S 850 */
{
#if defined( DET_DEBUG_ENABLED )
# if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0)
  VAR(uint8,AUTOMATIC) i; /* PRQA S 850 */
# endif
# if DET_LOGBUFFERSIZE > 0
  VAR(uint8,AUTOMATIC) forceBreakHandler=0; /* PRQA S 850 */
# endif
#endif

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
#  if ! defined( DET_ENTRY_CALLOUT_ENABLED ) && ((!defined(DET_DEBUG_ENABLED) || \
   (defined(DET_DEBUG_ENABLED) && (DET_GLOBALFILTERSIZE==0) && (DET_LOGBUFFERSIZE==0) && (DET_BREAKFILTERSIZE==0))))
  ModuleId = ModuleId;
  InstanceId = InstanceId;
  ApiId = ApiId; 
  ErrorId = ErrorId;
#  endif
# endif

#if defined( DET_ENTRY_CALLOUT_ENABLED )
  if(detLock2==0) /* avoid recursion by potential DET calls in the callout */
  {
    detLock2=1;
    if(Appl_DetEntryCallout(ModuleId, InstanceId, ApiId, ErrorId)!=0)
    {
        detLock2=0;
        return; /* handling is completely done in callout, abandon further processing */
    }
    detLock2=0;
  }
#endif

#if defined( DET_DEBUG_ENABLED )
  /* check for global filter match, in case of match discard error */
#if DET_GLOBALFILTERSIZE > 0
  if(detStatus.globalFilterActive!=0)
  {
    for(i=0;i<DET_GLOBALFILTERSIZE;i++)
    {
      if(
        ((detGlobalFilter[i].moduleId==ModuleId) || (detGlobalFilter[i].moduleId==0xffffu)) &&
        ((detGlobalFilter[i].instanceId==InstanceId) || (detGlobalFilter[i].instanceId==0xff)) &&
        ((detGlobalFilter[i].apiId==ApiId) || (detGlobalFilter[i].apiId==0xff)) &&
        ((detGlobalFilter[i].errorId==ErrorId) || (detGlobalFilter[i].errorId==0xff))
        )
      {
        return;
      }
    }
  }
#endif
#if DET_LOGBUFFERSIZE > 0
  if(detStatus.logActive!=0)
  {
    if(detLock1==0) /* avoid recursion by potential DET calls in enter / leave critical calls */
    {
      detLock1=1;
      Det_EnterCritical();
      detStatus.logIndex++;
      if(detStatus.logIndex>=DET_LOGBUFFERSIZE)
      {
        detStatus.logIndex=0;
        if(detStatus.breakOnLogOverrun!=0)
        {
          forceBreakHandler=1;
        }
      }
      detLogBuffer[detStatus.logIndex].moduleId=ModuleId;
      detLogBuffer[detStatus.logIndex].instanceId=InstanceId;
      detLogBuffer[detStatus.logIndex].apiId=ApiId;
      detLogBuffer[detStatus.logIndex].errorId=ErrorId;
      Det_LeaveCritical();
      detLock1=0;
    }
  }
#endif
  /* check for break filter match, in case of match discard error */
#if DET_BREAKFILTERSIZE > 0
# if DET_LOGBUFFERSIZE > 0
  if(forceBreakHandler==0)
  {
# endif
    if(detStatus.breakFilterActive!=0)
    {
      for(i=0;i<DET_BREAKFILTERSIZE;i++)
      {
        if(
          ((detBreakFilter[i].moduleId==ModuleId) || (detBreakFilter[i].moduleId==0xffffu)) &&
          ((detBreakFilter[i].instanceId==InstanceId) || (detBreakFilter[i].instanceId==0xff)) &&
          ((detBreakFilter[i].apiId==ApiId) || (detBreakFilter[i].apiId==0xff)) &&
          ((detBreakFilter[i].errorId==ErrorId) || (detBreakFilter[i].errorId==0xff))
          )
        {
          return;
        }
      }
    }
# if DET_LOGBUFFERSIZE > 0
  }
# endif
#endif
  while(detStatus.unlockBreak==0) /* set this variable to 0 to unlock breakpoint */
  {
    ; /* ##### typical place for a breakpoint if extended debugging support is enabled*/
  }
  detStatus.unlockBreak=0; /* PRQA S 3201 */ 
#else /* DET_DEBUG_ENABLED */
  /* Endless loop for breakpoint in case of development error */
  while(1) 
  {
    ; /* ##### typical place for a breakpoint if extended debugging support is disabled*/
  }
#endif /* DET_DEBUG_ENABLED */

} /* PRQA S 2006 */

/*******************************************************************************
 * Global function for BSW-Modules to get the Version of Det
 *******************************************************************************/
#if (DET_VERSION_INFO_API == STD_ON)
FUNC(void, DET_CODE) Det_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA ) versioninfo ) /* PRQA S 1503 */ /* PRQA S 850 */
{
  versioninfo->vendorID           = DET_VENDOR_ID;
  versioninfo->moduleID           = DET_MODULE_ID;
  versioninfo->sw_major_version   = DET_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version   = DET_SW_MINOR_VERSION;
  versioninfo->sw_patch_version   = DET_SW_PATCH_VERSION;
}
#endif

#define DET_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

#endif /* DET_ENABLED */

/* STOPSINGLE_OF_MULTIPLE */
