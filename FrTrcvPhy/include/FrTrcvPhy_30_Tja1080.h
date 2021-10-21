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
 *  Andreas Herkommer             hr            Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  3.00.00   2008-02-07  hr      Creation for AUTOSAR 3.0
 *  3.00.01   2008-02-12  hr      Minor updates
 *  3.00.02   2008-02-13  hr      No changes
 *  3.00.03   2008-03-12  hr      No changes
 *  3.00.04   2008-03-28  hr      Incorporated Review findings
 *  3.00.05   2008-04-01  hr      No changes
 *  3.00.06   2008-04-18  hr      No changes
 *  3.00.07   2008-06-04  hr      No changes
 *  3.00.08   2008-07-04  hr      ESCAN00027654 Added ICU call-outs to enable/disable WUP Interrupts
 *                                ESCAN00028280 Change to STANDBY ends in 
 *                                SLEEP because the EN signal is delayed by the Tja1080
 *  3.00.09   2008-08-18  hr      ESCAN00029287 Single Channel API incomplete for FrTrcv_30_Tja1080dio_Cbk_WakeupByTransceiver
 *                                ESCAN00029454 Library issue with number of Transceivers
 *  3.01.00   2008-10-01  hr      ESCAN00029735 instanceID by FrTrcv_30_Tja1080dio_GetVersionInfo not set
 *  3.02.00   2008-11-07  hr      ESCAN00031137 ERRN Pin not low for wakeup detection
 *  3.03.00   2008-11-19  hr      ESCAN00030263 PreCompile and Linktime Crc Check
 *  3.04.00   2008-11-27  hr      ESCAN00031637 Remove Support of SWS Req FrTrcv309
 *  3.05.00   2008-12-02  hr      ESCAN00031775 Remove unnecessary MISRA violations
 *  3.05.01   2009-02-25  hr      ESCAN00033397 Missing extern in call-back declaration
 *                                ESCAN00029695 AUTOSAR Dummy Statements
 *                                ESCAN00033495 Wrong MemMap.h sections used
 *                                ESCAN00034964 Single Channel API change for AUTOSAR SWS compliance
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
 *********************************************************************************************************************/

#ifndef FRTRCVPHY_H
#define FRTRCVPHY_H

#include "ComStack_Types.h"
#include "Dio.h"
#include "FrTrcvPhy_30_Tja1080_Cfg.h"


#if !defined ( FRTRCV_WUPINT_CBK )
  #define FRTRCV_WUPINT_CBK STD_OFF
#endif
#if ( FRTRCV_WUPINT_CBK == STD_ON )
  #include "Icu.h"
#endif

#define FRTRCV_STATUS_INVERT_MASK 0xFFFFu

/* This is the Transceiver status word bit description for the TJA1080 */
#define FRTRCV_LOCALWAKEUP          0x1000u /* Local wake up detected */
#define FRTRCV_REMOTEWAKEUP         0x0800u /* Remote wake up detected */
#define FRTRCV_NODE_CONFIG          0x0400u /* Node configuration flag */
#define FRTRCV_PWON                 0x0200u /* Power on detected */
#define FRTRCV_BUSERROR             0x0100u /* Bus error detected */
#define FRTRCV_TEMPHIGH             0x0080u /* Temperature to high detected */
#define FRTRCV_TEMPMEDIUM           0x0040u /* Temperature to low detected */
#define FRTRCV_TXEN_CLAMPED         0x0020u /* TXEN clamped flag */
#define FRTRCV_UVVBAT               0x0010u /* VBAT undervoltage detected */
#define FRTRCV_UVVCC                0x0008u /* VCC undervoltage detected */
#define FRTRCV_UVVIO                0x0004u /* VIO undervoltage detected */
#define FRTRCV_STARLOCKED           0x0002u /* Star-locked state has been entered */
#define FRTRCV_TRXDCOLLISION        0x0001u /* TRXD collision has been detected */

#define FRTRCV_TJA1080_PULSEWIDTHUS  2u
#define FRTRCV_TJA1080_DELAYWIDTHUS 80u

typedef struct
{
  Dio_ChannelType   TrcvPinEN;
  Dio_ChannelType   TrcvPinSTBN;
  Dio_ChannelType   TrcvPinERRN;
#if ( FRTRCV_WUPINT_CBK == STD_ON )
  Icu_ChannelType   TrcvPinInt;
#endif
} FrTrcvChannelType;

typedef uint16 FrTrcv_StatusWordType;


#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CONST_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#if FRTRCV_TRCV_DIAGNOSIS == STD_ON
extern CONST(uint8, FRTRCV_CONST) FrTrcv_StatusMaskTableSize;
extern CONST(FrTrcv_StatusWordType, FRTRCV_CONST) FrTrcv_StatusMaskTable[9];
extern CONST(Dem_EventIdType, FRTRCV_CONST) FrTrcv_DEM_E_Table[9];
#endif

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CONST_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern FUNC(void, FRTRCV_CODE) TrcvPhy_30_Tja1080_TrcvInit( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY );
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_SetMode( FRTRCV_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_TrcvModeType FrTrcv_TrcvMode );
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_GetMode( FRTRCV_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr );
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_ReadStatusWord( FRTRCV_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_StatusWordType *TrcvStatusWord );


#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 4 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
#define TrcvPhy_30_Tja1080_TrcvInit(TrcvIdx)                               TrcvPhy_30_Tja1080_TrcvInit()
#define TrcvPhy_30_Tja1080_SetMode(TrcvIdx, TrcvMode)                      TrcvPhy_30_Tja1080_SetMode(TrcvMode)
#define TrcvPhy_30_Tja1080_GetMode(TrcvIdx, TrcvModePtr)                   TrcvPhy_30_Tja1080_GetMode(TrcvModePtr)
#define TrcvPhy_30_Tja1080_ReadStatusWord(TrcvIdx, TrcvStatusWord)         TrcvPhy_30_Tja1080_ReadStatusWord(TrcvStatusWord)
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

#endif
  /* FRTRCVPHY_H */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
