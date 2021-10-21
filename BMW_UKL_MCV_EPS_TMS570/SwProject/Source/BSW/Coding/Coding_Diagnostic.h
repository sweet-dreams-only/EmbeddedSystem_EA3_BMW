/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Coding_Diagnostic.h                                           **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file of coding module diagnostic                       **
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
** hauf         Andreas Hauf               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.2: 30.06.2009, hauf: changed module version
 * V1.1.0: 27.03.2009, hauf: CR70090: increased module minor version
 * V1.0.0: 30.11.2007, hauf: ported from SC6.7.2 file version V4.1.0
 */

#ifndef Coding_Diag_H
#define Coding_Diag_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR standard types                   */
#include <Coding.h>               /* Coding header file                       */
#include <Dcm.h>                  /* Diagnostic communication manager         */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CODING_DIAGNOSTIC_H_MAJOR_VERSION   2u
#define CODING_DIAGNOSTIC_H_MINOR_VERSION   2u
#define CODING_DIAGNOSTIC_H_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define CODING_START_SEC_CODE
#include "MemMap.h"

   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_DiagReadDataByIdentifier
               (
                        P2VAR( Dcm_MsgContextType,
                               AUTOMATIC,
                               CODING_VAR_DCMDATA ) pMsgContext,
                        uint16 dataIdentifier
               );

   extern FUNC(Dcm_StatusType, CODING_PUBLIC_CODE)
               Coding_DiagGetSessionStartPermission( void );

   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_DiagWriteDataByIdentifier
               (
                        P2VAR( Dcm_MsgContextType,
                               AUTOMATIC,
                               CODING_VAR_DCMDATA ) pMsgContext,
                        uint16 dataIdentifier
               );

   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_DiagRoutineControlCheckSignature
               (
                        P2VAR( Dcm_MsgContextType,
                               AUTOMATIC,
                               CODING_VAR_DCMDATA ) pMsgContext
               );

   extern FUNC(void, CODING_PUBLIC_CODE) Coding_DiagSessionEndIndication( void );

   extern FUNC(uint16, CODING_PUBLIC_CODE)
               Coding_DiagGetNumberOfCodedAreas( void );

   extern FUNC(uint16, CODING_PUBLIC_CODE)
               Coding_DiagGetCafIdsOfCodedAreas
               (
                        P2VAR( uint8,
                               AUTOMATIC,
                               CODING_VAR_DIAGDATA ) pData
               );

#define CODING_STOP_SEC_CODE
#include "MemMap.h"


#endif /* Coding_Diag_H                                                        */

/*** End of file **************************************************************/
