/*******************************************************************************
**                                                                            **
**  SRC-MODULE: applmain.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : This module performs initialization and scheduling of all     **
**              Standard Core modules in application mode                     **
**              The scheduling functions of the Standard Core modules are     **
**              called from cyclic OS tasks.                                  **
**              Overall sequence (see also BMW SWS Startup & Scheduling):     **
**              1.   StartupHook                                              **
**              2.   StarupSequence() called from BackgroundTask              **
**              3.   Normal operation mode (cyclic scheduling of tasks        **
**                   - Task_Cyclic2                                           **
**                   - BackgroundTask                                         **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** mazw         Markus Zwickl              MB-technology GmbH                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.0: 25.11.2008, mazw: deleted wraper for FrIf
 *         24.11.2008, mazw: deleted wraper for MemIf
 * V1.0.0: 15.11.2007, miwe: ported from SC6.7.2 file version V3.0.0
 */

#ifndef APPLMAIN_H
#define APPLMAIN_H

#include <Std_Types.h>         /* AUTOSAR Standard Types                      */
//#include "EcuM_RteApi_Stc.h"   /* Rte function EcuM_RequestRUN                */
//#include "Mcu_Der.h"           /* include Mcu_Init functions                  */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define MEMIF_DEVICE_ID      0u  /*
                                  * Device Id for the underlying memory driver
                                  */
#define FRIF_CTRL_IDX 0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef enum
{
   NV_WRITE_OPERATION,
   NV_READ_OPERATION
} NvOperationType;


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define APPLMAIN_START_SEC_CODE
#include "MemMap.h"


extern boolean Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode);
extern void Appl_SchM_BackgroundActivity(void);
extern void Appl_SchM_ScheduleNvStack(void);
extern void Appl_SchM_SyncScheduleTable(void);


#if ( SC_DEV_ERROR_DETECT == ON )
extern void Det_ErrorIndication
(
   const uint16 ModuleId,
   const uint8  InstanceId,
   const uint8  ApiId,
   const uint8  ErrorId
);
#endif /* ( SC_DEV_ERROR_DETECT == ON ) */

#define APPLMAIN_STOP_SEC_CODE
#include "MemMap.h"

#endif /* APPLMAIN_H                                                          */

/*** end of file 'applmain.h' *************************************************/
