/* STARTSINGLE_OF_MULTIPLE */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \file         FrIf_Types.h
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Types definition header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 3.0
 **********************************************************************************************************************

 **********************************************************************************************************************
 *  \author AUTHOR IDENTITY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Name                          Initials      Company
 -  -------------------------------------------------------------------------------------------------------------------
 -  Klaus Bergdolt                ber           Vctr Informatik GmbH
 -  Oliver Reineke                ore           Vctr Informatik GmbH
 -  -------------------------------------------------------------------------------------------------------------------
 *  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  3.0.0     2007-12-12  ber     -             release of version 3.0.0 
 -  3.0.1     2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-20  ber     ESCAN00025115 No changes here
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-18  ber     ESCAN00025799 Tx call back functions called with wrong PDU-ID in case some PDUs are 
 *                                              configured for immediate transmission
 -            2008-04-18  ber     ESCAN00026131 Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     ESCAN00026130 No changes here
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 No changes here
 -            2008-04-28  ore     ESCAN00026445 No changes here
 -            2008-04-29  ore     ESCAN00026447 FrIf_ConfigType is missing in implementation
 -            2008-04-28  ore     ESCAN00026449 No changes here
 -            2008-05-15  ore     ESCAN00026651 Extension for MSR3.0 generator version checks
 -            2008-05-19  ore     ESCAN00026973 No changes here
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     ESCAN00026972 No changes here
 -            2008-06-09  ore     ESCAN00026341 No changes here
 -            2008-07-08  ore     ESCAN00027356 Integrate Post-Build Feature
 -            2008-07-09  ore     ESCAN00028155 No changes here
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 Improve Interaction with FrNm- and FrTp-MainFunction
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 No changes here
 -            2008-07-24  ore     ESCAN00027210 No changes here
 -            2008-07-28  ore     ESCAN00028772 No changes here
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 No changes here
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-15  ore     -             added Frif_Cfg.h include
 -            2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     -             Apdapted TxConf-Handling to support configurable task times
 -            2008-10-01  ore     ESCAN00030038 No changes here
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 No changes here
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 PreCompile and Linktime Crc Check
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     ESCAN00031026 FrIf header file structure differs from AUTOSAR specification 
 -            2008-11-24  ore     ESCAN00031360 No changes here
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 Compiler warning on TMS570
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 No changes here
 -            2009-02-18  ore     ESCAN00032895 No changes here
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 No changes here
 -            2009-02-25  ore     ESCAN00033399 No changes here
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 No changes here
 -            2009-03-06  ore     ESCAN00033665 No changes here
 -            2009-03-18  ore     ESCAN00033669 No changes here
 -            2009-03-10  ore     ESCAN00033732 No changes here
 -            2009-03-23  ore     ESCAN00034040 No changes here
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component
 -            2009-05-28  ore     ESCAN00035398 The FrIf supports only a maximum of 8 Pdus per frame. Extend the 
 *                                              maximum to 32 pdus per frame.
 -            2009-05-28  ore     ESCAN00035048 No changes here
 -            2009-06-29  ore     ESCAN00035991 No changes here
 -            2009-07-06  ore     ESCAN00036053 No changes here
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration
 -            2009-07-14  ore     ESCAN00035399 No changes here
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 No changes here
 -            2009-07-15  ore     ESCAN00036429 No changes here
 -            2009-07-15  ore     ESCAN00036451 No changes here
 -            2009-07-16  ore     ESCAN00036471 No changes here
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component.
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 No changes here
 -            2009-09-21  ore     ESCAN00036013 No changes here
 -            2009-10-27  ore     ESCAN00038513 No changes here
 -            2009-11-02  ore     ESCAN00038914 No changes here
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 No changes here
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 Add code-size optimization for configurations with uniform update byte usage
 -            2009-12-07  ore     ESCAN00039609 Add code-size optimization for configurations with less than 256 rx or 
 *                                              tx mapped PDUs
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-01-11  ore     -             Added additional code-size and runtime optimizations
 -            2010-02-01  ore     ESCAN00040508 Add feature to support FreeOp-Callbacks
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 No changes here
 -            2010-03-30  ore     ESCAN00041966 No changes here
 -            2010-04-22  ore     ESCAN00042422 No changes here
 -            2010-05-05  ore     ESCAN00041396 No changes here 
 -            2010-05-05  ore     -             release of version 3.5.0 
 -  3.6.0     2010-05-19  ore     ESCAN00042989 The FlexRay Interface shall support ReconfigLPdu and DisableLPdu (Asr 4.0)
 -            2010-05-28  ore     ESCAN00043268 No changes here 
 -            2010-06-24  ore     ESCAN00043567 No changes here 
 -            2010-06-24  ore     ESCAN00043569 No changes here 
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 Add feature to support a delayed TxConfirmation for a FrIf Tx Job
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 No changes here 
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 No changes here 
 -            2010-09-22  ore     ESCAN00045547 No changes here 
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 No changes here 
 -            2010-11-02  ore     ESCAN00046417 No changes here 
 -            2010-11-02  ore     ESCAN00046257 No changes here 
 -            2010-11-05  ore     ESCAN00046607 Add DualChannelRedundancy support according to Bugzillla 42025.
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-05-02  ore     -             All component specific MISRA deviations are now justified in FrIf.c
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

#if (!defined FRIF_TYPES_H_)
# define FRIF_TYPES_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "FrIf_Cfg.h"

/*******************************************************************************************************************/
/*  VERSION CHECK AR3-F1155 (external modules)                                                                     */
/*******************************************************************************************************************/

/* Version check for COMSTACKTYPE_AR_MAJOR_VERSION and COMSTACKTYPE_AR_MINOR_VERSION is implemented in FrIf.h */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* AUTOSAR FlexRay Interface version */
# define FRIF_TYPES_VERSION            0x0307u /*!< BCD coded FrIf Types Header version number */
# define FRIF_TYPES_RELEASE_VERSION    0x04u   /*!< BCD coded FrIf Types Header release version number */

/* Production errors */
# define FRIF_NO_ACCESS                  19
# define FRIF_NOT_SYNC                   20
# define FRIF_TIMER_IN_USE               21
# define FRIF_RATE_CORRECTION_EXCEEDED   22
# define FRIF_OFFSET_CORRECTION_EXCEEDED 23
# define FRIF_CORRECTION_EXCEEDED        24
# define FRIF_COV_ERROR                  25

 /* PRQA S 3453 8 *//* MD_MSR_19.7 */
# if ((!defined FRIF_CONFIG_VARIANT) || (3u==FRIF_CONFIG_VARIANT))
#  define FRIF_P2CONSTCFGROOT(Type)  P2CONST(Type, AUTOMATIC, FRIF_PBCFG_ROOT)
#  define FRIF_P2CONSTCFG(Type)      P2CONST(Type, AUTOMATIC, FRIF_PBCFG)
# else
#  define FRIF_P2CONSTCFGROOT(Type)  P2CONST(Type, AUTOMATIC, FRIF_CONST)
#  define FRIF_P2CONSTCFG(Type)      P2CONST(Type, AUTOMATIC, FRIF_CONST)
# endif
# define  FRIF_P2CONSTAPPLDATA(Type) P2CONST(Type, AUTOMATIC, FRIF_APPL_DATA)

/* JobConfigMasks */
# define FrIf_FreeOpCbk                        0x03u
# define FrIf_JobDataIsRxTask                  0x04u
# define FrIf_JobDataIsLastFrIfRxTaskForNm     0x08u
# define FrIf_JobDataIsLastFrIfRxTaskForTp     0x10u
# define FrIf_JobIsConfirmedBeforeTx           0x20u

/* TxPduConfigMasks */
# define FrIf_TxPduOwner                       0x0Fu
# define FrIf_TxPduIsTxConfirmation            0x10u
# define FrIf_TxPduIsImmediateTx               0x20u
# define FrIf_TxPduIsTransmitAlways            0x40u
# define FrIf_TxPduHasTxRequestCounter         0x80u

/* RxPduConfigMasks */
# define FrIf_RxPduOwner                       0x0Fu
# define FrIf_RxPduIsNullRxIndication          0x10u

/* FrameConfigMasks */
# define FrIf_FrameIsTxConfirmation            0x01u
# define FrIf_FrameIsImmediateTx               0x02u
# define FrIf_FrameIsTransmitAlways            0x04u
# define FrIf_FrameIsNullRxIndication          0x08u
# define FrIf_FrameIsDynamicLSduLength         0x10u
# define FrIf_FrameIsInterruptMode             0x20u
# define FrIf_FrameHasPduWithUpdateBit         0x40u

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 **********************************************************************************************************************/

typedef unsigned int FrIf_BitType;

/*! \typedef Variables of this type are used to represent the FrIf state of a FlexRay cluster */
typedef enum
{
  /** The FlexRay CC is not ready for communication, the FlexRay cluster is not synchronized. */
  FRIF_STATE_OFFLINE = 0,
  /** The FlexRay CC is ready for communication, the FlexRay cluster is synchronized. */
  FRIF_STATE_ONLINE
} FrIf_StateType;

/*! \typedef Variables of this type are used to represent the FrIf transition state (requested by the FrSM) of a FlexRay cluster */
typedef enum
{
  /* Literal for requesting transition into FRIF_STATE_OFFLINE */
  FRIF_GOTO_OFFLINE = 0,
  /* Literal for requesting transition into FRIF_STATE_ONLINE */
  FRIF_GOTO_ONLINE
} FrIf_StateTransitionType;

/*! \typedef Variables of this type are used to represent the DET Error IDs reported by the FlexRay Interface */
typedef enum
{
  /* Invalid pointer  */
  FRIF_E_INV_POINTER = 0x01,
  /* Invalid Controller index  */
  FRIF_E_INV_CTRL_IDX = 0x02,
  /* Invalid Cluster index  */
  FRIF_E_INV_CLST_IDX = 0x03,
  /* Invalid Channel index  */
  FRIF_E_INV_CHNL_IDX = 0x04,
  /* Invalid timer index  */
  FRIF_E_INV_TIMER_IDX = 0x05,
  /* Invalid FrIf_TxPdu Index  */
  FRIF_E_INV_TXPDUID = 0x06,
  /* Invalid configuration index  */
  FRIF_E_INV_FRIFCONF_IDX = 0x07,
  /* FrIf not initialized  */
  FRIF_E_NOT_INITIALIZED = 0x08,
  /* Invalid Cycle */
  FRIF_E_INV_CYCLE = 0x09u,  
    /** Invalid Macrotick value */
  FRIF_E_INV_MACROTICK = 0x10u,
    /** FrIf invalid post build config */
  FRIF_E_INVALID_PB_CONFIG = 0x25u,
    /** FrIf_TxTask_0 returned E_NOT_OK */
  FRIF_E_TXTASK_RET_E_NOT_OK = 0x26u,
    /** FrIf_TxTask_0 returned E_NOT_OK */
  FRIF_E_INVALID_PDU_OWNER = 0x27u
} FrIf_ErrorCodes;


# if defined (FRIF_LARGE_RX_HANDLES) && (STD_ON == FRIF_LARGE_RX_HANDLES)
typedef uint16 FrIf_RxHandleType;
# else
typedef uint8 FrIf_RxHandleType;
# endif

# if defined (FRIF_LARGE_TX_HANDLES) && (STD_ON == FRIF_LARGE_TX_HANDLES)
typedef uint16 FrIf_TxHandleType;
# else
typedef uint8 FrIf_TxHandleType;
# endif

typedef FRIF_P2CONSTCFG(FrIf_RxHandleType) FrIf_RxHandleTypePtr;
typedef FRIF_P2CONSTCFG(FrIf_TxHandleType) FrIf_TxHandleTypePtr;

typedef struct
{
  uint16 StartTimeInMakroTicks;
  uint16 StartTimeProtectedRange;
  uint16 EndTimeProtectedRange;
  uint16 MaxDelay;
  uint16 MinColumnNumber;
  uint16 MaxColumnNumber;
  uint8 MinTxConfJobNo;
  uint8 MaxTxConfJobNo;
  uint8 JobConfig;
} FrIf_TaskScheduleDataType;

typedef struct
{
# if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
  PduIdType TxRequestCounterIndex;
# endif
  PduIdType UpperLayerPduId;
  uint8 PduLength;
  uint8 PduConfig;
} FrIf_TxPduDescriptorType;

typedef struct
{
  PduIdType Id;
# if defined(FRIF_USEPDUINFOTYPE) && ( FRIF_USEPDUINFOTYPE == STD_ON ) || defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON )
  uint8 PduLength;
# endif
  uint8 PduConfig;
} FrIf_RxPduDescriptorType;

typedef struct
{
  PduIdType PduHandle;
  uint8 ByteOffsetInFrame;
#if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_OFF )
  uint8 UpdateBitBytePos;
#endif
  uint8 UpdateBitMask;
} FrIf_FrameLayoutElementType;

typedef struct
{
  FrIf_FLEIdxType FirstFrameLayoutElementHandle;
  FrIf_NumberOfPduType NumberOfPdus; /* Without update pdu */
# if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
  FrIf_TxHandleType FrameHandle; /* FrIf_TxHandleType can be used for Rx FrameHandles too because GENy ensures that both handle types are equal if DualChannelRedundacy support is enabled. */
# endif
  uint8 FrameLength;
# if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) && (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_OFF)
  uint8 UpdateBitBytePos;
# endif
  uint8 FrameConfig;
} FrIf_FrameDescriptorType;

# if defined(FRIF_CONFIG_VARIANT) && (3u == FRIF_CONFIG_VARIANT)
  typedef struct
  {
  FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) pJobData;
  FRIF_P2CONSTCFG(FrIf_RxHandleTypePtr) pRxHandles;
  FRIF_P2CONSTCFG(uint8) pRxCycleNumberMasks;
  FRIF_P2CONSTCFG(FrIf_TxHandleTypePtr) pTxHandles;
  FRIF_P2CONSTCFG(uint8) pTxCycleNumberMasks;
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pRxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pRxFrameDescriptors;
  FRIF_P2CONSTCFG(FrIf_RxPduDescriptorType) pRxPduDescriptors;
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pTxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pTxFrameDescriptors;
  FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) pTxPduDescriptors;
  uint16 NumberOfRxColumns;
  uint16 NumberOfTxColumns;
  uint16 MacroTicksPerCycle;
  uint16 MacroTicksLengthInNanoSeconds;
  uint16 RxRotation;
  uint16 TxRotation;
  uint16 NumberOfRxPDUs;
  uint16 NumberOfTxPDUs;
  uint16 NumberOfTxFLEs;
  uint16 NumberOfTxFrames;
  uint16 MaxFrameLengthInBytes;
  uint16 NumberOfTxRequestCounters;
  FrIf_RxHandleType InvalidRxHandle;
  FrIf_TxHandleType InvalidTxHandle;
  uint8 NumberOfJobs;
  uint8 NumberOfChannels;
#  if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) && (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
  uint8 UpdateBitBytePos;
#  endif
#  if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
  uint32 FrIf_GeneratorVersion;
#  endif
#  if ( STD_ON == FRIF_CRC_CHECK )
  uint32 FrIf_PrecompileCRC;
  uint32 FrIf_LinkCRC;
#  endif
} FrIf_PostBuildConfigType;

typedef FrIf_PostBuildConfigType FrIf_ConfigType;
# else
typedef uint8 FrIf_ConfigType;
# endif

#endif
/* FRIF_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Types.h
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
