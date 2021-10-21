/**************************************************************************************************
   Project Name:  Diagnostic Active ResponseHandler
   File Name:     DARH.h

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
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Rev.     Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2007-11-20   1.0.0    vl      - creation
   2008-01-16   1.0.1    grm     - DARH_RTE_USED replaced by DarhRteUsed
   2008-01-21   1.0.2    grm     - Include added: <ComStack_Types.h> (VI ISS003)
                                 - Include "Std_types.h" renamed to "Std_Types.h" (VI ISS002)
   2008-04-25   1.0.3    vl      - ISS024: compiler switch values for DarhRteUsed replaced by 
                                   TRUE/FALSE
                                   ISS025: copyright note changed
   2008-09-29   1.0.4    grm     - ISS035: #if(DarhRteUsed == TRUE / FALSE) replaced by
                                           (DarhRteUsed == STD_OFF / STD_ON) due to preprocessor error
   2009-11-23   1.0.5    lz      - ISS039: New typedef Darh_MsgType for compiler abstraction
                                 - ISS040: removed macros IN and OUT of function parameters
   2009-12-04   1.0.6    lz      - ISS041: Changed type of Darh_RoeIsStartedType from enum to uint8
                                           and corresponding defines according to design spec
                                           (enum size depends on compiler options)

**************************************************************************************************/

#ifndef _DARH_TYPES_H
#define _DARH_TYPES_H

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"	/* for PduIdType */

/**************************************************************************************************
* Global defines
**************************************************************************************************/

/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/

#if (DarhRteUsed == STD_ON)

#include "Rte_Darh.h"

typedef RoeEngineType     Darh_RoeEngineType; 
typedef RoeIsStartedType  Darh_RoeIsStartedType;

#else

typedef uint8 Darh_RoeIsStartedType;
#define ROE_IS_STOPPED      ((Darh_RoeIsStartedType)0x00)
#define ROE_IS_STARTED      ((Darh_RoeIsStartedType)0x01)
#define ROE_START_SUSPENDED ((Darh_RoeIsStartedType)0x02)
#define ROE_STOP_SUSPENDED  ((Darh_RoeIsStartedType)0x03)
#define ROE_IS_INVALID      ((Darh_RoeIsStartedType)0xFF)

typedef boolean Darh_RoeStoreBitType;
typedef P2VAR(uint8,AUTOMATIC,DARH_DCM_DATA) Darh_MsgType;

typedef struct
{
  VAR(Darh_RoeIsStartedType,DARH_DATA) RoeIsStarted;
  VAR(Darh_RoeStoreBitType,DARH_DATA)  RoeStoreBit;
  VAR(PduIdType,DARH_DATA)             DcmRxPduId;
} Darh_RoeEngineType;

#endif

typedef struct QueueTag
{
  VAR(uint32,DARH_DATA) darhDtc;
  VAR(uint32,DARH_DATA) darhTimeStamp;
} Darh_QueueElementType;

typedef struct ChannelTag
{
  /* current fill grade of the queue */
  volatile VAR(uint16,DARH_DATA) QueueCount;
  /* current write index in the queue */
  volatile VAR(uint16,DARH_DATA) QueueWriteIndex;
  /* current read index from the queue */
  volatile VAR(uint16,DARH_DATA) QueueReadIndex;
  /* ongoing send for (some) queue elements */
  volatile VAR(uint16,DARH_DATA) OngoingSendCount;
} Darh_QueueInfoType;

 
/***** end of header file ************************************************************************/
#endif /* ifndef _DARH_TYPES_H */
