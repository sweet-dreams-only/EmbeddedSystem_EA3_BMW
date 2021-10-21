/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Spi.h
 *      Project:  DrvSpi
 *       Module:  MICROSAR communication platform DrvSpi
 *    Generator:  -
 *
 *  Description:  This file implements the Spi Api for the Spi communication driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Arne van Mourik               Va            Vctr Informatik GmbH
 *  Stefan Lang                   Sla           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  05.00.00  2010-07-30  Va      ESCAN00043798 Add synchronous transmit feature to Spi driver
 *            2010-08-19          ESCAN00044651 Possible loss of data in Spi_Hw.c: uint16 variable is copied into a
 *                                              uint8 variable
 *            2010-08-19          ESCAN00044650 Possible loss of data in Spi_Hw.c: uint16 variable is copied into a
 *                                              uint8 variable
 *            2010-08-19          ESCAN00044648 Possible loss of data in Spi_Hw.c: uint16 variable is copied into a
 *                                              uint8 variable
 *            2010-08-19          ESCAN00044646 Possible loss of data in Spi_WriteIB(): uint16 variable is copied into a
 *                                              uint8 variable
 *            2010-08-25          ESCAN00044834 Compiler warning "Invalid pointer cast" might occur
 *  05.00.01  2010-09-10          ESCAN00044419 Spi_SynchTransmit depends on calling Spi_MainFunction_Driving
 *                                ESCAN00045190 Spi.h does not include Spi_Dlc.h
 *                                ESCAN00045191 Undefined Macro: Generation of SPI_HARDWAREUNITX_ACTIVE defines from
 *                                              unused Hw-Units are missing
 *  05.00.02  2010-09-10          ESCAN00045568 Spi - fix header revision
 *  05.01.00  2010-11-30  Va            -       Spi - Sort Jobs in Generation Tool, please refer to identifier.xml
 *  05.01.01  2011-01-27  Va      ESCAN00048220 Spi - a job transmission can stop and driver stays pending
 *                        Va            -       Merge of S12 (current revision history) and Tmsx70 core platforms
 *                                              for better maintainability.
 *  05.02.00  2011-09-09  Va      ESCAN00050776 Spi - Spi_SyncTransmit throws a wrong error id.
 *                                ESCAN00051768 Calling Spi_synctransmit from ISR context causes a transmission hang up.
 *                                ESCAN00053355 [BR:011] Implementation of Spi_InitMemory()
 *
 *********************************************************************************************************************/

#ifndef SPI_H
#define SPI_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Spi_Dlc.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : DrvSpi__coreAsr CQComponent : <Implementation> */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
#define DRVSPI__COREASR_VERSION          (0x0502u)
#define DRVSPI__COREASR_RELEASE_VERSION  (0x00u)

/* AutoSar module version */
#define SPI_SW_MAJOR_VERSION    ((DRVSPI_TMS570TISPI01ASR_VERSION & 0xFF00u) >> 8)
#define SPI_SW_MINOR_VERSION     (DRVSPI_TMS570TISPI01ASR_VERSION & 0x00FFu)
#if (DRVSPI__COREASR_RELEASE_VERSION == 0xFFu)
/* This is a develop version and should not be deliverd */
# define SPI_SW_PATCH_VERSION  0xFFu
#else
# define SPI_SW_PATCH_VERSION  (DRVSPI_TMS570TISPI01ASR_RELEASE_VERSION & 0xFFu)
#endif

#define SPI_AR_MAJOR_VERSION       (2u)
#define SPI_AR_MINOR_VERSION       (3u)
#define SPI_AR_PATCH_VERSION       (0u)

/* Spi transfer mode */
#define SPI_SYNCONLY     (0u)
#define SPI_ASYNCONLY    (1u)
#define SPI_SYNC_ASYNC   (2u)

/* HWUnit Index */
#define SPI_UNIT0    (0u)
#define SPI_UNIT1    (1u)
#define SPI_UNIT2    (2u)
#define SPI_UNIT3    (3u)
#define SPI_UNIT4    (4u)

/* Buffer definitions IB=internal, EB=external buffers  */
#define SPI_IB      (0u)
#define SPI_EB      (1u)
#define SPI_IB_EB   (2u)

#define SPI_VENDOR_ID              (30u)         /* Vctr Informatik GmbH */
#define SPI_MODULE_ID              (83u)         /* Module ID (ASR bswmd description) */
#define SPI_INSTANCE_ID            (0u)          /* Instance ID */

#define SPI_E_PARAM_CHANNEL         (0x0Au) /* wrong channel  parameter given */
#define SPI_E_PARAM_JOB             (0x0Bu) /* wrong job      parameter given */
#define SPI_E_PARAM_SEQ             (0x0Cu) /* wrong sequence parameter given */
#define SPI_E_PARAM_LENGTH          (0x0Du) /* wrong length   parameter given */
#define SPI_E_PARAM_UNIT            (0x0Eu) /* wrong HWUnit   parameter given */
#define SPI_E_PARAM_CONFIG          (0x0Fu) /* wrong configuration parameter given (configuration pointer) */
#define SPI_E_PARAM_FRAME_LENGTH    (0x10u) /* SetupEB called with unaligned length if 16bit frame transfer is chosen */
#define SPI_E_PARAM_FRAME_BUFFER    (0x11u) /* SetupEB called with unaligned buffer if 16bit frame transfer is chosen */
#define SPI_E_PARAM_VERSIONINFO     (0x12u) /* wrong version  parameter given (version info pointer) */

#define SPI_E_UNINIT                (0x1Au) /* Error code for not initialized module */
#define SPI_E_SEQ_PENDING           (0x2Au) /* Error code if service called in a wrong sequence */
#define SPI_E_SEQ_IN_PROGRESS       (0x3Au) /* transmission of sync. sequence in progress */
#define SPI_E_ALREADY_INITIALIZED   (0x4Au) /* Init() service called twice without DeInit() */

/* these are the service IDs of the functions in the ASR SWS specification                                           */
#define SPI_SID_INIT                  (0x00u)
#define SPI_SID_DEINIT                (0x01u)
#define SPI_SID_WRITE_IB              (0x02u)
#define SPI_SID_ASYNC_TRANSMIT        (0x03u)
#define SPI_SID_READ_IB               (0x04u)
#define SPI_SID_SETUP_EB              (0x05u)
#define SPI_SID_GET_STATUS            (0x06u)
#define SPI_SID_GET_JOB_RESULT        (0x07u)
#define SPI_SID_GET_SEQ_RESULT        (0x08u)
#define SPI_SID_GETVERSION_INFO       (0x09u)
#define SPI_SID_SYNC_TRANSMIT         (0x0Au)
#define SPI_SID_GET_UNIT_STATUS       (0x0Bu)
#define SPI_SID_CANCEL                (0x0Cu)
#define SPI_SID_SET_ASYNC_MODE        (0x0Du)
#define SPI_SID_MAINFUNCTION_HANDLING (0x10u)
#define SPI_SID_MAINFUNCTION_DRIVING  (0x11u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Driver status enumerations */
typedef enum
{
    SPI_UNINIT = 0,
    SPI_IDLE = 1,
    SPI_BUSY = 2
}   Spi_StatusType;

typedef enum
{
    SPI_JOB_OK = 0,
    SPI_JOB_PENDING = 1,
    SPI_JOB_ACTIVE = 2,    /* this is an internal state */
    SPI_JOB_FAILED = 3
} Spi_JobResultType;

typedef enum
{
    SPI_DLC_OK = 0,
    SPI_DLC_PENDING = 1,
    SPI_DLC_FAILED = 2
}Spi_HwUnitResultType;

typedef enum
{
    SPI_SEQ_OK = 0,
    SPI_SEQ_PENDING = 1,
    SPI_SEQ_FAILED = 2,
    SPI_SEQ_CANCELLED = 3
} Spi_SeqResultType;

typedef enum
{
    SPI_MSB = 0,
    SPI_LSB = 1
} Spi_TransferType;

/* type for SpiCsPolarity and SpiShiftClockIdleLevel */
typedef enum
{
    SPI_LOW = STD_LOW,
    SPI_HIGH
} Spi_LevelType;

/* type for  SpiCsIdentifier */
typedef enum
{
    SPI_PCS0 = 0,
    SPI_PCS1,
    SPI_PCS2,
    SPI_PCS3,
    SPI_PCS4,
    SPI_PCS5,
    SPI_PCS6,
    SPI_PCS7
} Spi_PCsType;

/* type for SpiCsMode */
typedef enum
{
    SPI_SINGLE = 0,
    SPI_CONTINOUS = 1
} Spi_CsModeType;

/* enums end */

/* Driver, job, sequence status types */

typedef uint16 Spi_NumberOfDataType;
typedef uint16 Spi_JobType;

typedef uint8  Spi_DataType;
typedef uint8  Spi_ChannelType;
typedef uint8  Spi_SequenceType;
typedef uint8  Spi_HWUnitType;
typedef uint8  Spi_ExternalDeviceType;

/* spi external device structure */
typedef struct
{
    uint32 Spi_DioPin;       /* holds the configured Dio pin for toggling CS */
    uint16 Spi_CsProperty;   /* low byte the CS idle level, high byte res. */
    uint8  Spi_Baudrate;
    uint8  Spi_Mode;         /* Mode 0 = {0=CPOL,0=CPHA}; Mode 1={0,1}; Mode 2={1,0} Mode 3={1,1} */
    uint16 Spi_ClkDelays[2]; /* includes CS2Clk, Clk2Cs, Clk2Ena, Ena2Clk */
    uint16 Spi_CsIdleTime;   /* CS idle time if single mode is chosen */
    uint8  Spi_CsMode;       /* select single or continuous mode*/
}Spi_ExternalDeviceConfigType;

/* descriptor type definition for buffers */
typedef struct
{
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) Spi_Tx_pt;  /* Transmit buffer pointer */
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) Spi_Rx_pt;  /* Receive buffer pointer */
    uint16 Spi_TxRxLength;    /* length to send and receive */
} Spi_BufferDescriptorType;

/* spi channel configuration structure */
typedef struct
{
    P2VAR(Spi_BufferDescriptorType, AUTOMATIC, SPI_VAR_INIT) Spi_Descriptor;
    Spi_ChannelType      Spi_ChannelId;
    uint8                Spi_ChannelBuf;     /* Buffer Type IB/EB */
    uint8                Spi_DataWidth;      /* width of clock frame in bits */
    uint16               Spi_DefaultTxData;  /* Default Transmit Value */
    Spi_NumberOfDataType Spi_BufLength;      /* max Data length external or internal buffer */
    uint8                Spi_TxStart;        /* start with MSB or LSB */
} Spi_ChannelConfigType;

/* spi job configuration structure */
typedef struct
{
    P2FUNC(void, SPI_APPL_CODE, Spi_JobEndNotification)(void);            /* Job notification */
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_PBCFG) Spi_ChannelList;       /* Channel index list */
    Spi_ExternalDeviceType Spi_ExDev;           /* external device assigned to a job */
    uint8          Spi_JobID;                   /* job ID */
    uint8          Spi_JobPrio;                 /* job priority */
    Spi_HWUnitType Spi_HWUnitID;                /* HWUnit */
} Spi_JobConfigType;

/* spi sequence configuration structure */
typedef struct
{
    P2FUNC(void, SPI_APPL_CODE, Spi_SequenceEndNotification)(void);  /* sequence end notification */
    P2CONST(Spi_JobType, AUTOMATIC, SPI_PBCFG) Spi_JobList;      /* job index list */
    Spi_SequenceType Spi_SeqId;                    /* sequence id */
    uint8            Spi_SeqInt;                   /* sequence interruptible */
} Spi_SequenceConfigType;

typedef struct
{
    P2VAR(Spi_JobResultType, AUTOMATIC, SPI_VAR_ZERO_INIT) Spi_JobResult;      /* job result      */
    P2VAR(Spi_SeqResultType, AUTOMATIC, SPI_VAR_ZERO_INIT) Spi_SeqResult;      /* sequence result */
    P2VAR(Spi_HwUnitResultType, AUTOMATIC, SPI_VAR_ZERO_INIT) Spi_DlcResult;   /* hardware result */
} Spi_ResultType;

/* spi runtime structure */
typedef struct
{
    #ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
    uint32 Spi_GeneratorVersion;    /* Contains major, minor and patch version */
    #endif
    P2CONST(Spi_ExternalDeviceConfigType, AUTOMATIC, SPI_PBCFG) Spi_DevCfg;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_PBCFG) Spi_ChannelCfg;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PBCFG) Spi_JobCfg;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_PBCFG) Spi_SeqCfg;
    P2CONST(Spi_ResultType, AUTOMATIC, SPI_VAR_INIT) Spi_GlobalStatus_pt;
    uint8 Spi_MaxExtDevs;      /* maximum number of external devices */
    uint8 Spi_MaxChannels;     /* maximum number of channels */
    uint8 Spi_MaxJobs;         /* maximum number of jobs */
    uint8 Spi_MaxSequences;    /* maximum number of sequences */
    uint8 Spi_MaxDlcs;         /* maximum number of dlc's */
} Spi_ConfigType;

#include "Spi_Cfg.h"

typedef enum
{
    SPI_POLLING_MODE = 0,
    SPI_INTERRUPT_MODE = 1
} Spi_AsyncModeType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2CONST(Spi_ConfigType, SPI_VAR_ZERO_INIT, SPI_PBCFG) Spi_ConfigPtr_pt;
extern volatile VAR(Spi_StatusType, SPI_VAR_ZERO_INIT) Spi_DrvResult_t;

#define SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"

FUNC(void, SPI_CODE) Spi_Init
(
    P2CONST(Spi_ConfigType, AUTOMATIC, SPI_PBCFG) ConfigPtr
);
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void);
#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB
(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr
);
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB
(
    Spi_ChannelType Channel,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr
);
#endif
#if ((SPI_CHANNELBUFFERS == SPI_EB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB
(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    Spi_NumberOfDataType Length
);
#endif
#if ((SPI_SCALEABILITY == SPI_ASYNCONLY) || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit
(
    Spi_SequenceType Sequence
);
#endif
#if ((SPI_SCALEABILITY == SPI_SYNCONLY)  || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit
(
    Spi_SequenceType Sequence
);
#endif
#if (SPI_CANCEL_API == STD_ON)
FUNC(void, SPI_CODE) Spi_Cancel
(
    Spi_SequenceType Sequence
);
#endif
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void);
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult
(
    Spi_JobType Job
);
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult
(
    Spi_SequenceType Seq
);
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus
(
    Spi_HWUnitType HWUnit
);

#if (SPI_VERSION_INFO_API == STD_ON)
FUNC(void, SPI_CODE) Spi_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) VersioninfoPtr
);
#endif

#if ((SPI_SCALEABILITY == SPI_ASYNCONLY) || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode
(
    Spi_AsyncModeType Mode
);
#endif

FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void);
FUNC(void, SPI_CODE) Spi_MainFunction_Driving(void);

FUNC(void, SPI_CODE) Spi_InitMemory(void);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* SPI_H */
/**********************************************************************************************************************
 *  END OF FILE: Spi.h
 *********************************************************************************************************************/
