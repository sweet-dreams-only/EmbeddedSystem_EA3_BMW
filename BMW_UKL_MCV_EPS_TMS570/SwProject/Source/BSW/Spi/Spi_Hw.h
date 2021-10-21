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
 *         File:  Spi_Hw.h
 *      Project:  DrvSpi
 *       Module:  MICROSAR communication DrvSpi module Spi_Hw.h
 *    Generator:  -
 *
 *  Description:  This file implements the Spi_Hw driver, handling of jobs and sequences.
 *
 *********************************************************************************************************************/

#ifndef SPI_HW_H
#define SPI_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SPI_HW_MAJOR_VERSION    (0x05u)
#define SPI_HW_MINOR_VERSION    (0x02u)
#define SPI_HW_PATCH_VERSION    (0x00u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* event definitions of the SPI job state machine */
typedef enum
{
    SPI_HW_EV_INIT = 0,
    SPI_HW_EV_SEQ_START = 1,
    SPI_HW_EV_JOB_START = 2,
    SPI_HW_EV_JOB_FINISHED = 3,
    SPI_HW_EV_CANCEL = 4,
    SPI_HW_EV_FAILED = 5,
    SPI_HW_EV_CONSUMED = 6
} Spi_HwEventDefType;

typedef enum
{
    SPI_HW_UNDEF = 0,
    SPI_HW_SYNC  = 1,
    SPI_HW_ASYNC = 2
} Spi_HwModeType;

/* forward declarations of structure types */
typedef struct Spi_JobSortedType_fd Spi_JobSortedType;
typedef struct Spi_HwEventType_fd   Spi_HwEventType;

/* event object definitions of the spi job state machine */
struct Spi_JobSortedType_fd
{
    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobNext_pt;   /* pointer to next job of a sequence */
    uint8  JobID_u8;     /* used to access job structure */
    uint8  SeqID_u8;     /* marks the job assigned to this sequence */
    uint8  JobStatus_u8; /* job internal status in the sorted priority queue */
};

/* event object definitions of the spi job state machine */
struct Spi_HwEventType_fd
{
    P2VAR(Spi_HwEventType, AUTOMATIC, SPI_VAR_NOINIT) SeqPrev_pt;
    P2VAR(Spi_HwEventType, AUTOMATIC, SPI_VAR_NOINIT) SeqNext_pt;
    volatile uint8 Event_u8;
    uint8  Guard_u8;
    uint8  TaskID_u8;    /* kind of job, sequence to execute, can be used for both */
    uint8  NrOfJobs_u8;  /* number of jobs, sequences */
};

typedef struct
{
    uint8 SeqIdAkt_u8;  /* Id of the sequence, current being processed  */
    uint8 SeqIdPend_u8; /* Id of the sequence, pending                  */
    uint8 SeqIdRep_u8;  /* Id of the sequence, reported by job complete */
    uint8 SeqNrPend_u8; /* number of queued sequences */
} Spi_HwInstType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

/* these structures are generated */
extern VAR(uint8, SPI_VAR_ZERO_INIT) Spi_JobPrioConvTbl_at[];
extern VAR(Spi_JobSortedType, SPI_VAR_ZERO_INIT) Spi_JobsSorted_at[];
extern VAR(Spi_HwEventType, SPI_VAR_ZERO_INIT) Spi_HwSeqEvent_at[];

#define SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* these structures are generated */
extern VAR(Spi_HwEventType, SPI_VAR_NOINIT) Spi_HwSeqEvent_at[];

#define SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_HwSetEvent
(
    P2CONST(Spi_HwEventType, AUTOMATIC, SPI_VAR)Hw_Event_pt
);
FUNC(void, SPI_CODE) Spi_HwInit(void);
FUNC(void, SPI_CODE) Spi_HwDeInit(void);
FUNC(void, SPI_CODE) Spi_HwProcessState(void);
FUNC(void, SPI_CODE) Spi_HwJobComplete(uint16_least Job_u16, uint16_least DLC_u16);

FUNC(void, SPI_CODE) Spi_HwSetMode(Spi_AsyncModeType Mode);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SPI_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Spi_Hw.h
 *********************************************************************************************************************/
