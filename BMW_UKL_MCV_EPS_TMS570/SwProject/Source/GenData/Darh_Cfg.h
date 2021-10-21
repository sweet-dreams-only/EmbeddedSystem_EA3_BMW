/**************************************************************************************************
   Project Name:  Diagnostic Active ResponseHandler
   File Name:     Darh_Cfg.h

    Description: 

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (C) BMW  Group 2008. All rights reserved.
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
   2007-11-29   1.0.1    vl      - changed Requirements of SWS V0.6
   2008-01-16   1.0.2    grm     - wrapping to required ports moved to darh.c
   2008-01-21   1.0.3    grm     - Include added: "NvM.h" (VI ISS002)
                                 - DarhTASDcmRxPduId corrected (VI ISS004)
                                 - Macro DarhNvMBlockId cast corrected:
                                   (uint16) --> (NvM_BlockIdType)
                                 - Macros DarhEventIdDeletedError,  DarhEventIdQueueFullError
                                   cast corrected:
                                   (uint16) --> (PduIdType)
   2008-02-06   1.0.4    grm     - Include added: "NvM.h" (VI ISS009)
                                 - DarhEventTimerValue corrected ('0x' removed) (VI ISS008)
                                  - kDarhCountOfElementsPerTx cast uint8 removed (VI ISS011)
   2008-03-17   1.0.5    grm     - Compiler switch DarhRteUsed == 0 used for header
                                   NvM due to RTE use (VI ISS015)
                                 - Macro #define DarhRteUsed moved before #include "NvM.h"
   2008-04-18   1.0.6    grm     - PduIdType replaced by Dem_EventIdType (VI ISS022) for
                                   DarhEventIdDeletedError and DarhEventIdQueueFullError
   2008-04-25   1.0.7    vl      - ISS024: compiler switch values for DarhRteUsed replaced by 
                                   TRUE/FALSE
                                   ISS025: copyright note changed 
   2008-06-20   1.0.8    grm     - Header Std_Types.h added (VI ISS029)
   2008-09-29   1.0.9    grm     - ISS035: #if(DarhRteUsed == TRUE / FALSE) replaced by
                                           (DarhRteUsed == STD_OFF / STD_ON) due to preprocessor error
   2009-11-23   1.0.10   lz      - ISS038: Accept 2 DcmRxPduIds for persistent storage
   2010-11-16   1.0.11   bra     - ISS045: CRQ003 (BMW CR70814): interface added to map
                                   application function to Darh_WaitNvMReady

**************************************************************************************************/
#ifndef _DARH_CFG_H
#define _DARH_CFG_H

/**************************************************************************************************
* Version
**************************************************************************************************/
#define DARH_CFG_MAJOR_VERSION 1
#define DARH_CFG_MINOR_VERSION 0
#define DARH_CFG_PATCH_VERSION 11

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Std_Types.h"

/**************************************************************************************************
* Common Configuration Settings
**************************************************************************************************/
#define DarhRteUsed     STD_OFF

/**************************************************************************************************
* Include files
**************************************************************************************************/
#if (DarhRteUsed == STD_OFF)
#include "NvM.h"
#include "Dem.h"
/* include for declaration of function that is mapped to Darh_WaitNvMReady() */ 
#include <applmain.h>
#endif

/**************************************************************************************************
* Common Configuration Settings Continued
**************************************************************************************************/
/* Max number of Queued errors */
#define DarhMaxQueueSize                                          ((uint8) 3)

/* Data identifier to be used for ResponseOnOneEvent */
#define DarhDataIdentifier                                        ((uint16) 5892)

/* call cycle of DarhMain() function [ms] */
#define DarhMainTaskCycle                                         ((uint8 ) 10)

/* time cycle for next RoeEvent [ms] */
#define DarhEventTimerValue                                       ((uint16) 1000)

/* RxPdu Ids for the physical and functional requests of the Onboard Tester  */
#define DarhTASDcmRxPduIdPhys                                     ((PduIdType) 0)
#define DarhTASDcmRxPduIdFunc                                     ((PduIdType) 1)

/* number of transmission retries */
#define DarhActiveResponseRetryCounter                            ((uint8) 3)

#if(DarhRteUsed == STD_OFF)

/* ID of NV-Data Block used for NvM_ReadBlock / NvM_WriteBlock */  
#define DarhNvMBlockId                                            ((NvM_BlockIdType) NVM_BLOCK_DARH_DATA)

/* Error IDs */
#define DarhEventIdDeletedError                                   ((Dem_EventIdType) DM_Queue_DELETED)
#define DarhEventIdQueueFullError                                 ((Dem_EventIdType) DM_Queue_FULL)
#define Darh_WaitNvMReady()                                       Appl_WaitNvMReady(DarhNvMBlockId, (boolean)TRUE)

#endif


/**************************************************************************************************
* Internal Macro definitions, default values and consistency check
**************************************************************************************************/

#if defined (DarhDataIdentifier)
#else
#define DarhDataIdentifier                                        ((uint16) 0x1704)
#endif

#if defined (DarhEventTimerValue)
#else
#define DarhEventTimerValue                                       ((uint16) 1000)
#endif

#if defined (DarhMaxQueueSize)
#else
#define DarhMaxQueueSize                                           ((uint8) 3)
#endif

#if defined (DarhActiveResponseRetryCounter)
#else
#define DarhActiveResponseRetryCounter                             ((uint8) 3)
#endif

#if defined (kDarhCountOfElementsPerTx)
#else
#define kDarhCountOfElementsPerTx                                  3
#endif


#if !defined(DarhMainTaskCycle)
/* No default Value for DarhMainTaskCycle specified */
#error "DarhMainTaskCycle is undefined"
#endif 

#define kDarhTimerReloadValue   ((uint16)(DarhEventTimerValue / (uint16)DarhMainTaskCycle)) 

#endif /* _DARH_CFG_H */
