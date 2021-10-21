/**************************************************************************************************
   Project Name:  Diagnostic Active ResponseHandler
   File Name:     Darh.c

    Description: 

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (C) BMW  Group 2009. All rights reserved.
  -------------------------------------------------------------------------------------------------
                 A U T H O R   I D E N T I T Y
  -------------------------------------------------------------------------------------------------
   Initials     Name                      Company
   --------     ---------------------     ---------------------------------------------------------
   Gz           Oliver Garnatz            Vctr Informatik GmbH
   Hrs          Stefan Huebner            Vctr Informatik GmbH
   Sa           Mishel Shishmanyan        Vctr Informatik GmbH
   vl           Martin Viereckel          Vctr Informatik GmbH
   grm          Marcus Grande             Vctr Informatik GmbH
   lz           Rainer Lutz               Vctr Informatik GmbH
   bra          Andre Baur                Vctr Informatik GmbH
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Rev.     Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2007-11-20   1.0.0    vl      - creation
   2007-12-17   1.0.1    grm     - reference to DARH-requirements added
   2007-12-19   1.0.2    grm     - traceability to software specification DARH client
                                   requirements documented
   2007-12-20   1.0.3    grm     - Darh_Init reworked due to implementation:
                                   Data available at RAM-mirror during init
  
   2008-01-15   1.0.4    grm     - Header include for Std_types.h removed
   2008-01-16   1.0.5    grm     - DARH_RTE_USED removed
                                 - DARH_USE_RTE replaced by DarhRteUsed
   2008-01-17   1.0.6    grm     - Version Identification and check added
                                 - MemoryMapping added
   2008-01-21   1.0.7    grm     - Includes added: "NvM.h", "Dem.h", <os.h> (VI ISS003)
                                 - Darh_GetActiveResponsePayload resDataElement
                                   changed to uint16
                                 - Makro _Darh_ResponseOnOneEvent(x,y,z) changed from
                                   Dcm_ResponseOnOneEvent((MessagePtrType)x, (MessageLengthType) y, z)
                                   to Dcm_ResponseOnOneEvent((uint8 *)x, (uint16) y, z) (VI ISS005)
                                 - _STATIC_ removed for darhNvDefaults and darhNvData (VI ISS006)
                                 - typedef uint8* DstPtrType added (VI ISS007)
                                 - DarhInit corrected: FUNC(void,RTE_APPL_CODE) Darh_Init(void) 
   2008-01-23   1.0.8    grm     - _Darh_LockInterrupts, _Darh_UnLockInterrupts renamed to
                                   _Enter_ExclusiveArea and Exit_ExclusiveArea
                                 - store ROEStatus into EEPROM corrected (VI ISS001) -->
                                   variable darhEngineTmp added, DarhInit and SetROESTatus reworked
   2008-02-06   1.0.9    grm     - kDarhCountOfElementsPerTx cast (uint8) added, cause cast was
                                   removed at Darh_cfg.h (VI ISS011)
   2008-03-17   1.0.10   grm     - Compiler switch DarhRteUsed == FALSE used for headers
                                   NvM, Dem and os due to RTE use (VI ISS014)
   2008-03-19   1.0.11   grm     - darhIsRoeProcessingActive init at Darh_Init (VI ISS018)
                                 - Schedule Manager used instead direct use of os.h (VI ISS016)
   2008-03-27   1.0.12   grm     - typedef uint8* DstPtrType removed (VI ISS019)                                 
                                 - Dem_ReportErrorStatus used instead of Dem_SetEventStatus (VI ISS020)
                                 - _Darh_SetQueueFullStatus() and _Darh_SetQueueDeletedStatus()
                                   mapped to Dem_ReportErrorStatus(VI ISS021)
   2008-04-18   1.0.13   grm     - Macros for SchM corrected (VI ISS023)
   2008-04-25   1.0.14   vl      - ISS024: compiler switch values for DarhRteUsed replaced by 
                                   TRUE/FALSE
                                   ISS025: copyright note changed
   2008-06-20   1.0.15   grm     - Two MISRA violations negative intendation removed
   2008-09-29   1.0.16   grm     - ISS032: darhTransmitCounter initialization corrected
                                 - ISS035: #if(DarhRteUsed == TRUE / FALSE) replaced by
                                           (DarhRteUsed == STD_OFF / STD_ON) due to preprocessor error
   2009-11-23   1.0.17   lz      - ISS038: Accept 2 DcmRxPduIds for persistent storage
                                 - ISS039: New typedef Darh_MsgType for compiler abstraction
                                 - ISS040: removed macros IN and OUT of function parameters
   2009-12-04   1.0.18   lz      - ISS041: Changed type of Darh_RoeIsStartedType from enum to uint8
                                           and corresponding defines according to design spec
                                           (enum size depends on compiler options)
                                 - Solved compiler warnings
   2010-05-03   1.0.19   lz      - ISS043: pending Tx request fixed
   2010-11-16   1.0.20   bra     - ISS045: CRQ003 (BMW CR70814, CR70778)
                                   - removed block status check and NvM write block from init function
                                   - removed prototype Darh_WaitNvMReady
                                   - removed unused macros 

**************************************************************************************************/
/* MISRA Information (Lint 766): Header file MemMap.h not used in module ignored *//*lint -e766*/
/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Darh.h"

#if (DarhRteUsed == STD_OFF)
/*MISRA repeated include file NvM.h and Dem.h used for integration (see VI ISS003, ISS009)*/ 
#include "NvM.h"  /*lint !e537*/
#include "Dem.h"  /*lint !e537*/
#include "SchM_Darh.h"
#endif

/**************************************************************************************************
* Version
**************************************************************************************************/
#define DARH_C_MAJOR_VERSION 1
#define DARH_C_MINOR_VERSION 0
#define DARH_C_PATCH_VERSION 20

/* Perform version checking */
#if (     (DARH_MAJOR_VERSION != DARH_C_MAJOR_VERSION) \
       || (DARH_MINOR_VERSION != DARH_C_MINOR_VERSION) )
#error "Version numbers of Darh.h and Darh.c are inconsistent!"
#endif

#if (     (DARH_MAJOR_VERSION != DARH_CFG_MAJOR_VERSION) \
       || (DARH_MINOR_VERSION != DARH_CFG_MINOR_VERSION) )
#error "Version numbers of Darh.h and Darh_Cfg.h are inconsistent!"
#endif

/* satisfy misra: Info 750 local macro 'DARH_C_PATCH_VERSION' not referenced */
#if ( DARH_C_PATCH_VERSION != DARH_C_PATCH_VERSION )
#endif

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

/**************************************************************************************************
* Macros
**************************************************************************************************/
#define Darh_GetHiByte(x)       ((uint8)(x>>8u))
#define Darh_GetLoByte(x)       ((uint8)(x&0x00FFu))
#define Darh_GetHiHiByte(x)     ((uint8)(x>>24u))
#define Darh_GetHiLoByte(x)     ((uint8)(x>>16u))
#define Darh_GetLoHiByte(x)     ((uint8)(x>>8u))
#define Darh_GetLoLoByte(x)     ((uint8)(x))

/**************************************************************************************************
* RTE is used
**************************************************************************************************/
# if ( DarhRteUsed == STD_ON)

/* Wrapper of internal Functions to Port Operations */
#  define _Darh_NvMWriteBlock(x)            Rte_Call_NvM_WriteBlock(x)
  
#  define _Darh_SetQueueFullStatus(x)       Rte_Call_DemQF_SetEventStatus( x )
#  define _Darh_SetQueueDeletedStatus(x)    Rte_Call_DemDel_SetEventStatus( x )

/* Active Response Message */
#  define _Darh_ResponseOnOneEvent(x,y,z)   Rte_Call_Dcm_ResponseOnOneEvent(x,y,z)

/* RTE Services */
#  define _Darh_Enter_ExclusiveArea()       Rte_Enter_ExclusiveArea()
#  define _Darh_Exit_ExclusiveArea()        Rte_Exit_ExclusiveArea()


/**************************************************************************************************
* RTE is not used
**************************************************************************************************/   
# else /* DarhRteUsed == STD_OFF */
      
/* RTE is not used, wrapper for Require Ports are implemented here... */
#  define _Darh_NvMWriteBlock(x)            NvM_WriteBlock( DarhNvMBlockId, x)

/* Queue management status notifications */
#  define _Darh_SetQueueFullStatus(x)       Dem_ReportErrorStatus(DarhEventIdQueueFullError, x )
#  define _Darh_SetQueueDeletedStatus(x)    Dem_ReportErrorStatus(DarhEventIdDeletedError, x )

/* Active Response Message */
#  define _Darh_ResponseOnOneEvent(x,y,z)   (Std_ReturnType)Dcm_ResponseOnOneEvent((Darh_MsgType)x, (uint16) y, z)

/* RTE and OS Services */
#  define _Darh_Enter_ExclusiveArea()       SchM_Enter_Darh(SCHM_DARH_INSTANCE_0, SCHM_DARH_EXCLUSIVE_AREA_0)
#  define _Darh_Exit_ExclusiveArea()        SchM_Exit_Darh(SCHM_DARH_INSTANCE_0, SCHM_DARH_EXCLUSIVE_AREA_0)

# endif /* DarhRteUsed */

/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/

/**************************************************************************************************
* Data definitions
**************************************************************************************************/
#define DARH_START_SEC_CONST_UNSPECIFIED
/*MISRA Rule 19.1, only preprocessor statements and comments before '#include' accepted. Memory mapping defined by AUTOSAR */
#include "MemMap.h" /*lint !e537 !e961*/
CONST(Darh_RoeEngineType, DARH_NV_CONST)  darhNvDefaults = { ROE_IS_STOPPED, 0u, 0u };
#define DARH_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /*lint !e537 !e961*/

#define DARH_START_SEC_CONST_8BIT
#include "MemMap.h" /*lint !e537 !e961*/
_STATIC_ CONST(uint8,DARH_CONST) darhServiceToRespondTo[3] = {
                                                  0x22u,
                                                  Darh_GetHiByte(DarhDataIdentifier),
                                                  Darh_GetLoByte(DarhDataIdentifier)
                                                 };
#define DARH_STOP_SEC_CONST_8BIT
#include "MemMap.h" /*lint !e537 !e961*/

#define DARH_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /*lint !e537 !e961*/
VAR(Darh_RoeEngineType,DARH_NV_DATA)           darhNvData;                 /* Configuration Data. This is used by NVM as Mirror Block */                                                                                                  
_STATIC_ VAR(Darh_RoeEngineType,DARH_DATA)     darhEngine;                 /* current active ROE state */
_STATIC_ VAR(Darh_RoeEngineType,DARH_DATA)     darhEngineTmp;              /* temporary current active ROE state (ISS001) */
_STATIC_ VAR(Darh_QueueElementType,DARH_DATA)  darhQueueElements[DarhMaxQueueSize]; 
_STATIC_ VAR(Darh_QueueInfoType,DARH_DATA)     darhQueueInfo;


_STATIC_ VAR(boolean,DARH_DATA)                darhIsSuspended;            /* current state is suspended! */
_STATIC_ VAR(boolean,DARH_DATA)                darhEventUpdate;            /* Update the active configuration from configuration Block */
_STATIC_ VAR(boolean,DARH_DATA)                darhIsRoeProcessingActive;
#define DARH_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /*lint !e537 !e961*/

#define DARH_START_SEC_VAR_8BIT
#include "MemMap.h" /*lint !e537 !e961*/
_STATIC_ VAR(uint8,DARH_DATA)                  darhTransmitCounter;
_STATIC_ VAR(uint8,DARH_DATA)                  darhDcmRoeTxRequest;
#define DARH_STOP_SEC_VAR_8BIT
#include "MemMap.h" /*lint !e537 !e961*/

#define DARH_START_SEC_VAR_16BIT
#include "MemMap.h" /*lint !e537 !e961*/
_STATIC_ VAR(uint16,DARH_DATA)                 darhTimer;
#define DARH_STOP_SEC_VAR_16BIT
#include "MemMap.h" /*lint !e537 !e961*/

/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
#define DARH_START_SEC_CODE
#include "MemMap.h" /*lint !e537 !e961*/

_STATIC_ FUNC(void,DARH_CODE)                  Darh_InitQueue(void);

/*******************************************************************************
* NAME:              DarhInit
*
* CALLED BY:         Application
* PRECONDITIONS:
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       The internal states will be reset.
*
*                    The function should be called to re-initialize this component.
*
*                    This Function is blocking! Do not call from an high prio Task 
*                    or with disabled Interrupts!
*
*******************************************************************************/
/* Darh039 */
#if (DarhRteUsed == STD_ON)
FUNC(void,RTE_CODE) Darh_Init(void)
#else
FUNC(void,DARH_CODE) Darh_Init(void)
#endif
{

  /* Darh001: Initialize Queue */
  Darh_InitQueue();

  darhTimer = kDarhTimerReloadValue;
  
  /* Darh002 */
  darhIsSuspended = (boolean)FALSE;

  /* ISS032 */
  /* Reset counter */
  darhTransmitCounter = DarhActiveResponseRetryCounter;
      
  /* After init, no update from configuration Block necessary cause done at DarhInit */
  darhEventUpdate = (boolean)FALSE;

  darhIsRoeProcessingActive = (boolean)FALSE;

  /* Darh002: Read the current ROE-State from NV-RAM */
  if ( darhNvData.RoeIsStarted >= ROE_START_SUSPENDED )
  {
    /* A block read error has occured or invalid Data are read from NvRam, restore defaults */
    darhNvData = darhNvDefaults;
    
    /* Do not wait on write-Job to be finished. If an error occures, the defaults are still active in RAM */
  }

  /* init working and temporary data from RAM mirror */
  darhEngine = darhNvData;
  darhEngineTmp = darhNvData;
}


/*******************************************************************************
* NAME:              Darh_Main
*
* CALLED BY:         Application
* PRECONDITIONS:     Darh_Init() 
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Timebase of DARH and cyclic actions. Do not call in ISR context. 
*
*                    The function has to be called periodically.
*******************************************************************************/
/* Darh043: offer Darh_Main */
#if (DarhRteUsed == STD_ON)
FUNC(void, RTE_CODE) Darh_Main(void)
#else
FUNC(void, DARH_CODE) Darh_Main(void)
#endif
{
  if(darhTimer != 0u)
  {
    darhTimer--;
        
    /* Darh012: The setRoeActive event should only be evaluated, if currently no ROE processing is ongoing */
    if( (darhEventUpdate == (boolean)TRUE) && (darhIsRoeProcessingActive == (boolean)FALSE) )
    {
      /* Darh011: EventUpdate */
      _Darh_Enter_ExclusiveArea();
      darhEventUpdate = (boolean)FALSE;
      _Darh_Exit_ExclusiveArea();
      
      /* Accept only the States ROE_IS_STARTED and ROE_IS_STOPPED */
      if (darhEngineTmp.RoeIsStarted <= ROE_IS_STARTED)
      {
        /* load the current state from NV-Data */
        _Darh_Enter_ExclusiveArea();
        darhEngine = darhEngineTmp;
        _Darh_Exit_ExclusiveArea();
                
        if (darhEngineTmp.RoeIsStarted == ROE_IS_STOPPED)
        {
          /* Darh011 ROE_IS_STOPPED discard all queue entries */
          Darh_InitQueue();
          darhDcmRoeTxRequest = 0u;
        }
      }
    }

    if(darhTimer == 0u)
    {
      darhTimer = kDarhTimerReloadValue;

      /* Lock in case the Darh_setRoeActiveStatus == (boolean)FALSE is called from higher PRIO task */
      _Darh_Enter_ExclusiveArea();
      if(   (darhQueueInfo.QueueCount != 0u)              /* There is something to be sent */
         && (darhIsRoeProcessingActive == (boolean)FALSE) /* Darh012 There is currently no ongoing processing */ 
         && (darhIsSuspended != (boolean)TRUE)            /* Darh027 Darh028: If ROE is not suspended */
        )
      {
        darhDcmRoeTxRequest = 1u;
      }
      _Darh_Exit_ExclusiveArea();
    }

    /* Darh013: check wether queue entries have to be sent */
    if(  (darhDcmRoeTxRequest == (uint8)1)            /* If time to send again */
       &&(darhEngine.RoeIsStarted == ROE_IS_STARTED)  /* If ROE active at all */
      )
    {
      Std_ReturnType result;

      result = _Darh_ResponseOnOneEvent(&darhServiceToRespondTo[0], 3u, darhEngine.DcmRxPduId);

      if(result == (Std_ReturnType)E_OK)
      { 
        /* reset transmission request */
        darhDcmRoeTxRequest = 0u;
        
        /* Mark beginning of the ROE processing */
        darhIsRoeProcessingActive = (boolean)TRUE;
        
        /* Darh015: restart interval timer */        
        /* restart event timer (CR60119) */
        darhTimer = kDarhTimerReloadValue; 
      }
    }
  }  /* !if(darhTimer != 0u) */
  else
  {
    /* Darh015: restart interval timer */
    /* Safety Statement --> timer may never be stopped, reload */
    darhTimer = kDarhTimerReloadValue;
  }    
}



/*******************************************************************************
* NAME:              Darh_SetRoeStatus
*
* CALLED BY:         RTE(application)
* PRECONDITIONS:     Darh_Init() 
*
* PARAMETER:         roeEngine: Current ROE state and persistent Storage state 
* RETURN VALUE:      none
* DESCRIPTION:       If Roe will be started, DARH will accep further DEM events. 
*                    If Roe will be stopped, the queue will be emptied and no 
*                    further DEM events will be accepted.
*                    If Roe will be suspended, the queue will not be emptied but
*                    no further DEM events will be accepted.
*                    If Roe supension will be stopped, the previous State 
*                    (started or stopped) will be recovered.
*
*                    This Function is blocking! Do not call from an high prio Task
*                    or with disabled Interrupts!
*
*******************************************************************************/
/*lint -e818
MISRA Rule 81: Note:   roeEngine could be declared as pointing to const
               Reason: API Darh_SetRoeStatus defined by OEM
*/
/* Darh005: provide Darh_SetRoeStatus */
#if (DarhRteUsed == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Darh_SetRoeStatus(P2VAR(RoeEngineType, AUTOMATIC, RTE_APPL_DATA) roeEngine)
#else
FUNC(Std_ReturnType,DARH_CODE) Darh_SetRoeStatus(P2VAR(Darh_RoeEngineType, AUTOMATIC, DARH_APPL_DATA) roeEngine)
#endif
{
  Std_ReturnType ret;
  boolean bNoCopy;

  ret     = (Std_ReturnType)E_OK;
  bNoCopy = (boolean)FALSE;
  
  /* Common Failure */
  if ( roeEngine->RoeStoreBit == (boolean)TRUE )
  {
    if (  (roeEngine->DcmRxPduId != DarhTASDcmRxPduIdPhys)
        &&(roeEngine->DcmRxPduId != DarhTASDcmRxPduIdFunc)
       )
    {
      /* Darh007: refuse the request */
      ret = (Std_ReturnType)E_NOT_OK;
    }
    
    if (  (roeEngine->RoeIsStarted != ROE_IS_STARTED)
        &&(roeEngine->RoeIsStarted != ROE_IS_STOPPED) 
       )
    {
      /* Darh008: refuse the request */
      ret = (Std_ReturnType)E_NOT_OK;
    }
  }

  if ( (Std_ReturnType)E_OK == ret )
  {
    /* general checks have passed */

    /* Lock in case the Darh_triggerOnErrorEntry is called from higher PRIO task */
    switch( roeEngine->RoeIsStarted )
    {
      default: /* NO BREAK */
      
      case ROE_IS_INVALID:
        /* Darh026: never has value ROE_IS_INVALID */
        ret = (Std_ReturnType)E_NOT_OK;
        
        break;
    
      /*
      *************************************************************************
      * ROE_IS_STARTED
      *************************************************************************
      */
      case ROE_IS_STARTED:
      {
        switch (darhEngineTmp.RoeIsStarted)
        {
          default: /* NO BREAK */
            /* this should never happen: asume that ROE is stopped */
          
          case ROE_IS_STOPPED:
            /* start ROE from stopped state */
            /* allowed */
            ret =(Std_ReturnType) E_OK;
            
            break;
            
          case ROE_IS_STARTED:
            if (roeEngine->DcmRxPduId != darhEngineTmp.DcmRxPduId)
            {
               /* Darh006: denied */
              ret = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
              /* DMA_PA_8412: allowed */
              ret = (Std_ReturnType)E_OK;
            }
            
            break;
            
          case ROE_START_SUSPENDED:
            /* This State transision should never happen because the actual */
            /* Configuration may never stay in a "START- or STOP_SUSPENDED" State */
            /* Allow transition to prevent DARH from being locked in invalid State */
            ret = (Std_ReturnType)E_OK;
            
            break;
            
          case ROE_STOP_SUSPENDED:
            /* This State transision should never happen because the actual */
            /* Configuration may never stay in a "START- or STOP_SUSPENDED" State */
            /* Allow transition to prevent DARH from being locked in invalid State */
            ret = (Std_ReturnType)E_OK;
            
            break;
        }
        break;
      }
      
      /*
      *************************************************************************
      * ROE_IS_STOPPED
      *************************************************************************
      */      
      case ROE_IS_STOPPED:
      {
        switch (darhEngineTmp.RoeIsStarted)
        {
          default: /* NO BREAK */
            /* this should never happen: asume that ROE is stopped */
            
          case ROE_IS_STOPPED:
            /* stop ROE from stopped state */
            /* DMA_PA_8414: allowed? */
            ret = (Std_ReturnType)E_OK;
            
            break;
            
          case ROE_IS_STARTED:
            /* allowed? */
            ret = (Std_ReturnType)E_OK;
            
            break;
            
          case ROE_START_SUSPENDED:
            /* This State transision should never happen because the actual */
            /* Configuration may never stay in a "START- or STOP_SUSPENDED" State */
            /* Allow transition to prevent DARH from being locked in invalid State */
            ret = (Std_ReturnType)E_OK;
            
            break;
            
          case ROE_STOP_SUSPENDED:
            /* This State transision should never happen because the actual */
            /* Configuration may never stay in a "START- or STOP_SUSPENDED" State */
            /* Allow transition to prevent DARH from being locked in invalid State */
            ret = (Std_ReturnType)E_OK;
            
            break;
        }
        break;
      }
      
      /*
      *************************************************************************
      * ROE_START_SUSPENDED
      *************************************************************************
      */            
      case ROE_START_SUSPENDED:
        /* Start suspended shall be allowed in any case */
        /* If the current state shall be suspended, remain in the current state */
        /* and set an internal supression flag */
        /* In case the DARH will be suspended, the current configuration */
        /* shall not be changed! */
        bNoCopy = (boolean)TRUE;
        
        /* Darh027: isSuspended */ 
        darhIsSuspended = (boolean)TRUE;
        ret = (Std_ReturnType)E_OK;
        
        break;

      /*
      *************************************************************************
      * ROE_STOP_SUSPENDED
      *************************************************************************
      */              
      case ROE_STOP_SUSPENDED: 
        /* if ROE is not in suspended state, is it allowed to stop the suspending? */
        bNoCopy = (boolean)TRUE; /* In case the DARH will be re-activated, */
        
        /* the current configuration shall not be changed! */
        /* Darh028: isSuspended */
        darhIsSuspended = (boolean)FALSE;
        ret = (Std_ReturnType)E_OK;
        
        break;
    }
  }

  if ( (Std_ReturnType)E_OK == ret )
  {   
    /* check for Persistant storage */
    if (bNoCopy == (boolean)FALSE)
    {  
      /* Darh009: ROE request accepted */
      /* State switch is allowed */
      _Darh_Enter_ExclusiveArea();  
      darhEngineTmp = *roeEngine;
      _Darh_Exit_ExclusiveArea();
            
      if (roeEngine->RoeStoreBit == (boolean)TRUE)
      {
        darhNvData = darhEngineTmp;
        /* Darh009: storage bit is set */
        /* Persistant storage requested */
        ret = _Darh_NvMWriteBlock((uint8*)NULL_PTR);        
        if ( (Std_ReturnType)E_OK == ret)
        {
          /* wait for storage to be finished */
          if((boolean)TRUE == (boolean)Darh_WaitNvMReady())
          {
            ret = (Std_ReturnType)E_OK;
          }
          else
          {
            ret = (Std_ReturnType)E_NOT_OK;
          }          
        }     

        if ( (Std_ReturnType)E_OK != ret )
        {
          /* Darh010: write NvM block failed */
          /* An error occured during storage, restore the old configuration */
          _Darh_Enter_ExclusiveArea();  
          darhNvData = darhEngine;
          darhEngineTmp = darhEngine;
          _Darh_Exit_ExclusiveArea();
        }
      }
      
      /* No Error occured during storage */
      if ( (Std_ReturnType)E_OK == ret)
      {
        /* Darh009: flag for main function */
        darhEventUpdate = (boolean)TRUE;
      }
    }
  }
  
  return ( ret );
}
/*lint +e818 */


/*******************************************************************************
* NAME:              Darh_GetRoeStatus
*
* CALLED BY:         RTE(application)
* PRECONDITIONS:     DarhInit() 
*
* PARAMETER:         roeEngine: current ROE-Status
* RETURN VALUE:      E_OK: status read out correctly
* DESCRIPTION:       get the current ROE active state 
*
*******************************************************************************/
#if (DarhRteUsed == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Darh_GetRoeStatus(P2VAR(RoeEngineType, AUTOMATIC, RTE_APPL_DATA) roeEngine)
#else
FUNC(Std_ReturnType, DARH_CODE) Darh_GetRoeStatus(P2VAR(Darh_RoeEngineType, AUTOMATIC, DARH_APPL_DATA) roeEngine)
#endif
{
  _Darh_Enter_ExclusiveArea();  
  *roeEngine = darhEngineTmp;
  _Darh_Exit_ExclusiveArea();
  
  return (Std_ReturnType)E_OK;
}

/*******************************************************************************
* NAME:              Darh_TriggerOnErrorEntry
*
* CALLED BY:         DEM
* PRECONDITIONS:     Darh_Init() 
*
* PARAMETER:         DTC number; timestamp of storage 
* RETURN VALUE:      E_OK: Error added to queue
*                    E_NOT_OK: queue overflow
* DESCRIPTION:       Has to be called, if a DTC is stored in the fault memory
*
*******************************************************************************/
#if (DarhRteUsed == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Darh_TriggerOnErrorEntry(uint32 dtc, uint32 timestamp)
#else
FUNC(Std_ReturnType, DARH_CODE) Darh_TriggerOnErrorEntry(uint32 dtc, uint32 timestamp)
#endif
{  
  Std_ReturnType ret = (Std_ReturnType)E_OK;
  
  /*    Darh004: queue DTC if ROE status is active */
  /* && Darh004: queue DTC if ROE is not suspended */
  if(  (darhEngine.RoeIsStarted == ROE_IS_STARTED)
     &&(darhIsSuspended == (boolean)FALSE)
    )
  {
    /* Darh004: queue DTC if queue is not full */
    if(darhQueueInfo.QueueCount == (uint16)(DarhMaxQueueSize))
    {
      /* it is full - ignore new element but notify application */
      _Darh_SetQueueFullStatus(DEM_EVENT_STATUS_FAILED);
      ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* Lock in case the Darh_setRoeActiveStatus == (boolean)FALSE is called from higher PRIO task */
      _Darh_Enter_ExclusiveArea();
      
      /* add new element to the queue */
      darhQueueElements[darhQueueInfo.QueueWriteIndex].darhDtc = dtc;
      darhQueueElements[darhQueueInfo.QueueWriteIndex].darhTimeStamp = timestamp;

      darhQueueInfo.QueueCount++;

      if(darhQueueInfo.QueueWriteIndex == ((uint16)DarhMaxQueueSize - (uint16)1))
      {
        darhQueueInfo.QueueWriteIndex = 0u;
      }
      else
      {
        darhQueueInfo.QueueWriteIndex++;
      }
      _Darh_Exit_ExclusiveArea();
      ret = (Std_ReturnType)E_OK;
    }
  }
  
  return (ret);
}


/*******************************************************************************
* NAME:              Darh_ReadDataByIdTransmission
*
* CALLED BY:         DCM Application
* PRECONDITIONS:     Darh_getActiveResponsePayload() 
*
* PARAMETER:         DCM_RES_POS_OK: transmission of DTCs was successful
*                    DCM_RES_POS_NOT_OK: transmission of DTCs was NOT successful
*                    DCM_RES_NEG_OK: transmission of DTCs was NOT successful
                     DCM_RES_NEG_NOT_OK: transmission of DTCs was NOT successful
* RETURN VALUE:      E_OK: API call successful
* DESCRIPTION:       Clear successfully sent events from the FIFO.
*
*******************************************************************************/
/* Darh017: provide Darh_ReadDataByIdTransmission */
#if (DarhRteUsed == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Darh_ReadDataByIdTransmission(Dcm_ConfirmationStatusType status)
#else
FUNC(Std_ReturnType, DARH_CODE) Darh_ReadDataByIdTransmission(Dcm_ConfirmationStatusType status)
#endif
{
  if(darhQueueInfo.OngoingSendCount != 0u)
  {
    /* Darh030: retry DarhActiveResponseRetryCounter */
    if(status != DCM_RES_POS_OK) 
    {
      /* Darh018: send confirmation negative */
      /* Decrement the transmit counter if not zero */
      if(darhTransmitCounter != (uint8)0)
      {
        darhTransmitCounter--;
      }
    }
    else
    {
      /* Reset counter */
      darhTransmitCounter = DarhActiveResponseRetryCounter;
    }

    if (   (status == DCM_RES_POS_OK)                  /* Everything sent */
        || (darhTransmitCounter == (uint8)0)           /* No more tries */
        || (darhEngineTmp.RoeIsStarted != ROE_IS_STARTED) /* Queued request for stopping the ROE */
       )
    {

      /* Notify only in error case, where the maximum retry count is exceeded */
      if(darhTransmitCounter == (uint8)0)
      {
        /* Darh018: report error to DEM */
        /* Reset counter */
        darhTransmitCounter = DarhActiveResponseRetryCounter;
        _Darh_SetQueueDeletedStatus(DEM_EVENT_STATUS_FAILED);
      }

      _Darh_Enter_ExclusiveArea();
      /* Darh018 Darh019 */
      darhQueueInfo.QueueCount -= darhQueueInfo.OngoingSendCount;
      _Darh_Exit_ExclusiveArea();

      /* case differentiation to circumvent overflows and underruns in calculation */
      if(darhQueueInfo.QueueReadIndex < ((uint16)DarhMaxQueueSize - darhQueueInfo.OngoingSendCount))
      {
        darhQueueInfo.QueueReadIndex = darhQueueInfo.QueueReadIndex + darhQueueInfo.OngoingSendCount;
      }
      else
      {
        darhQueueInfo.QueueReadIndex = darhQueueInfo.QueueReadIndex - ((uint16)DarhMaxQueueSize - darhQueueInfo.OngoingSendCount);
      }

      darhQueueInfo.OngoingSendCount = 0u;
    }
  }
  
  /* End of the processing */
  darhIsRoeProcessingActive = (boolean)FALSE;
  
  return (Std_ReturnType)E_OK;
}


/*******************************************************************************
* NAME:              Darh_GetActiveResponsePayload
*
* CALLED BY:         DCM Application
* PRECONDITIONS:     DarhInit() 
*
* PARAMETER:         pointer to DCM response buffer, amount of copied data
* RETURN VALUE:      E_OK: Data was successfully copied
* DESCRIPTION:       Get elements from DARH FIFO.
*
*******************************************************************************/
/* Darh016: provide Darh_GetActiveResponsePayload */
#if (DarhRteUsed == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Darh_GetActiveResponsePayload(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) responseDataPtr, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) dataLength)
#else
FUNC(Std_ReturnType, DARH_CODE) Darh_GetActiveResponsePayload(P2VAR(uint8, AUTOMATIC, DARH_APPL_DATA) responseDataPtr, P2VAR(uint16, AUTOMATIC, DARH_APPL_DATA) dataLength)
#endif
{
  uint16 resDataElement = 0u;
  uint16 queueReadIndex = darhQueueInfo.QueueReadIndex;
  uint16 queueCount     = darhQueueInfo.QueueCount;
  
  /* Darh029: limit the count of elements per transmission */
  if(queueCount > (uint8) kDarhCountOfElementsPerTx)
  {
    queueCount = (uint8) kDarhCountOfElementsPerTx;
  }

  *dataLength = 0u;
  darhQueueInfo.OngoingSendCount = queueCount;
  
  while(queueCount != 0u)
  {
    responseDataPtr[resDataElement + (uint16) 0] = Darh_GetHiLoByte(darhQueueElements[queueReadIndex].darhDtc);
    responseDataPtr[resDataElement + (uint16) 1] = Darh_GetLoHiByte(darhQueueElements[queueReadIndex].darhDtc);
    responseDataPtr[resDataElement + (uint16) 2] = Darh_GetLoLoByte(darhQueueElements[queueReadIndex].darhDtc);

    responseDataPtr[resDataElement + (uint16) 3] = Darh_GetHiHiByte(darhQueueElements[queueReadIndex].darhTimeStamp);
    responseDataPtr[resDataElement + (uint16) 4] = Darh_GetHiLoByte(darhQueueElements[queueReadIndex].darhTimeStamp);
    responseDataPtr[resDataElement + (uint16) 5] = Darh_GetLoHiByte(darhQueueElements[queueReadIndex].darhTimeStamp);
    responseDataPtr[resDataElement + (uint16) 6] = Darh_GetLoLoByte(darhQueueElements[queueReadIndex].darhTimeStamp);
    
    resDataElement = resDataElement + (uint16) 7;
    *dataLength    = *dataLength    + (uint16) 7;
    
    if(queueReadIndex == ((uint16)DarhMaxQueueSize-(uint16)1))
    {
      queueReadIndex = 0u;
    }
    else
    {
      queueReadIndex++;
    }

    queueCount--;
  }

  return (Std_ReturnType)E_OK;
}



/**************************************************************************************************
*  Private Functions 
**************************************************************************************************/

/*******************************************************************************
* NAME:           Darh_InitQueue   
*
* CALLED BY:      Darh_Init, Darh_Main   
* PRECONDITIONS:     
*
* PARAMETER:      none   
* RETURN VALUE:   none   
* DESCRIPTION:    initializes the queue   
*
*******************************************************************************/

_STATIC_ FUNC(void,DARH_CODE) Darh_InitQueue(void)
{
  /* local Variables */
  uint8 ucIndex;
 
  _Darh_Enter_ExclusiveArea(); 
 
  /* Init the internal structures */
  darhQueueInfo.QueueCount       = 0u; /* Deactivate queue - count to zero */
  darhQueueInfo.QueueWriteIndex  = 0u;
  darhQueueInfo.QueueReadIndex   = 0u;
  darhQueueInfo.OngoingSendCount = 0u;

 
  /* Initialize Queue */ 
  for (ucIndex = (uint8)0; ucIndex < DarhMaxQueueSize; ucIndex++)
  {
    darhQueueElements[ucIndex].darhDtc = (uint32)0u;
    darhQueueElements[ucIndex].darhTimeStamp = (uint32)0u;
  }
  
  _Darh_Exit_ExclusiveArea(); 
}



#define DARH_STOP_SEC_CODE
#include "MemMap.h" /*lint !e537 !e961*/
