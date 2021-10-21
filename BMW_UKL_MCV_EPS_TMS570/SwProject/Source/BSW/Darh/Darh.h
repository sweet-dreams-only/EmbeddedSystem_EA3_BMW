/**************************************************************************************************
   Project Name:  Diagnostic Active ResponseHandler
   File Name:     Darh.h

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
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Rev.     Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2007-11-20   1.0.0    vl      - creation
   2007-12-17   1.0.1    grm     - reference to DARH-requirements added
   2008-01-16   1.0.2    grm     - Header include for Std_types.h removed
   2008-01-16   1.0.3    grm     - DARH_RTE_USED removed
                                 - DARH_USE_RTE replaced by DarhRteUsed
   2008-01-17   1.0.4    grm     - Version Identification added
                                 - MemoryMapping added
                                 - Module ID added
   2008-01-21   1.0.5    grm     - Includes added: "Dcm.h" (VI ISS002)
                                 - Include Darh_types renamed to Darh_Types.h (VI ISS003)
                                 - darhNvDefaults and darhNvData made public (VI ISS006)
                                 - VENDOR ID added
                                 - Compiler_Cfg Makros DARH_APPL_XXX corrected to DARH_XXX
   2008-03-17   1.0.6    grm     - Compiler switch DarhRteUsed == 0 used for headers
                                   NvM, Dem and os due to RTE use (VI ISS015)
   2008-04-25   1.0.7    vl      - ISS024: compiler switch values for DarhRteUsed replaced by 
                                   TRUE/FALSE
                                   ISS025: copyright note changed
   2008-09-29   1.0.8    grm     - ISS035: #if(DarhRteUsed == TRUE / FALSE) replaced by
                                           (DarhRteUsed == STD_OFF / STD_ON) due to preprocessor error
   2009-11-23   1.0.9    lz      - ISS039: new memory sections to improve compiler abstraction
                                 - ISS040: removed macros IN and OUT of function parameters
**************************************************************************************************/
#ifndef _DARH_H
#define _DARH_H

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Darh_Cfg.h"
#include "Darh_Types.h"

#if (DarhRteUsed == STD_OFF)
#include "Dcm.h"
#endif

/**************************************************************************************************
* Version
**************************************************************************************************/
/* Version identification */
#define DARH_MAJOR_VERSION    1
#define DARH_MINOR_VERSION    0
#define DARH_PATCH_VERSION    9

/* Autosar Module ID */
#define DARH_MODULE_ID  38

/* Autosar Vendor ID */
#define DARH_VENDOR_ID  30

/**************************************************************************************************
* Global defines
**************************************************************************************************/

/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/
#define DARH_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Darh_RoeEngineType, DARH_NV_CONST)  darhNvDefaults;

#define DARH_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DARH_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern VAR(Darh_RoeEngineType, DARH_NV_DATA)     darhNvData;

#define DARH_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

/* Providing Ports */

#if (DarhRteUsed == STD_ON)

/* Providing ports are defined by RTE */
   
#else

#define DARH_START_SEC_CODE
#include "MemMap.h"

/* Darh024: ClientServerInterface */
extern FUNC(void,DARH_CODE)           Darh_Init(void);
extern FUNC(void,DARH_CODE)           Darh_Main(void);
extern FUNC(Std_ReturnType,DARH_CODE) Darh_SetRoeStatus(P2VAR(Darh_RoeEngineType, AUTOMATIC, DARH_APPL_DATA) roeEngine);
extern FUNC(Std_ReturnType,DARH_CODE) Darh_GetRoeStatus(P2VAR(Darh_RoeEngineType, AUTOMATIC, DARH_APPL_DATA) roeEngine);

extern FUNC(Std_ReturnType,DARH_CODE) Darh_TriggerOnErrorEntry(uint32 dtc,uint32 timestamp);
extern FUNC(Std_ReturnType,DARH_CODE) Darh_GetActiveResponsePayload(P2VAR(uint8, AUTOMATIC, DARH_APPL_DATA) responseDataPtr, P2VAR(uint16, AUTOMATIC, DARH_APPL_DATA) dataLength);
extern FUNC(Std_ReturnType,DARH_CODE) Darh_ReadDataByIdTransmission(Dcm_ConfirmationStatusType status);

#define DARH_STOP_SEC_CODE
#include "MemMap.h"

#endif

/***** end of header file ************************************************************************/
#endif /* ifndef _DARH_H */
