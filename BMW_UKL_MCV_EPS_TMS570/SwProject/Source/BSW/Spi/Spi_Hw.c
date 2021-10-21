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
 *         File:  Spi_Hw.c
 *      Project:  DrvSpi
 *       Module:  MICROSAR Communication DrvSpi
 *    Generator:  -
 *
 *  Description:  This file implements the Spi_Hw driver, handling of jobs and sequences.
 *
 *********************************************************************************************************************/

#define SPI_HW_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Spi.h"
#include "Spi_Hw.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (SPI_HW_MAJOR_VERSION != 0x05u) \
    || (SPI_HW_MINOR_VERSION != 0x02u))
#error "Software Version Numbers of Spi_Hw.c and Spi_Hw.h are different"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* static structures */
static VAR(Spi_HwInstType, SPI_VAR_NOINIT) Spi_HwSeqIdInst_t;
/* job event structure, for actual job */
static VAR(Spi_HwEventType, SPI_VAR_NOINIT) Spi_HwJobEvent_at;
/* data structure for Spi_Dlc.c */
static VAR(Spi_DlcEventType, SPI_VAR_NOINIT)Spi_DlcSetEvent_t;

/* mode variable */
static VAR(Spi_AsyncModeType, SPI_VAR_NOINIT) Spi_HwMode_t;

#define SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"

static FUNC(void, SPI_CODE) Spi_HwJobConsumeEvent(void);
static FUNC(void, SPI_CODE) Spi_HwSeqConsumeEvent(void);
static FUNC(void, SPI_CODE) Spi_HwSeqNext(void);
static FUNC(void, SPI_CODE) Spi_HwSeqComplete(void);
static FUNC(void, SPI_CODE) Spi_HwSeqCleanUp(void);
static FUNC(void, SPI_CODE) Spi_HwSeqAdjust(uint16_least SequenceID);

static FUNC(void, SPI_CODE) Spi_HwJobsSort(void);
static FUNC (void, SPI_CODE)Spi_HwJobTransmit(void);
static FUNC (void, SPI_CODE)Spi_HwJobClear(uint16_least SequenceID);
static FUNC (Std_ReturnType, SPI_CODE)Spi_HwJobQueue(uint16_least SequenceID);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSeqConsumeEvent
 **********************************************************************************************************************/
/*! \brief      This method consumes pending sequence events.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module event handling
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwSeqConsumeEvent(void)
{
    uint16_least SeqId_u16;
    Spi_HwEventDefType ev_loc_t;

    SeqId_u16  = Spi_HwSeqIdInst_t.SeqIdAkt_u8;

    Spi_GlobalSuspend();
    /* back it up */
    ev_loc_t = (Spi_HwEventDefType) Spi_HwSeqEvent_at[SeqId_u16].Event_u8;
    /* consume event in global structure */
    Spi_HwSeqEvent_at[SeqId_u16].Event_u8 = SPI_HW_EV_CONSUMED;
    Spi_GlobalRestore();

    switch (ev_loc_t)
    {
        case SPI_HW_EV_INIT:
        break;

        case SPI_HW_EV_SEQ_START:
        Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_START;  /* start first job */
        Spi_HwJobConsumeEvent();
        break;

        case SPI_HW_EV_CANCEL:
        break;

        case SPI_HW_EV_FAILED:
        /* if a job fails, a sequence also fails ! See Spi_HwJobConsumeEvent() */
        break;

        default:
        break;
    }
    return;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_JobConsumeEvent
 **********************************************************************************************************************/
/*! \brief      This method consumes pending job events.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       module event handling
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwJobConsumeEvent(void)
{
    volatile uint8 ev_loc;

    Spi_GlobalSuspend();
    ev_loc = Spi_HwJobEvent_at.Event_u8;
    /* consume event in global structure */
    Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_CONSUMED;
    Spi_GlobalRestore();

    switch (ev_loc)
    {
        case SPI_HW_EV_INIT:
        break;

        case SPI_HW_EV_JOB_START:
        /* start a job. If this job is synchronous it has to be decoupled from the ISR context */
        if(Spi_DlcSetEvent_t.Event_u8 == SPI_DLC_EV_SYNCTX)
        {
            if(Spi_DlcSetEvent(&Spi_DlcSetEvent_t) == E_NOT_OK)
            {
                /* job transfer request was declined */
                Spi_JobsSorted_at[Spi_HwJobEvent_at.TaskID_u8].JobStatus_u8 = SPI_JOB_PENDING;
                Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_START;
                Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_SYNCTX;
            }
            else
            {
                /* no action */
            }
        }
        else
        {
            Spi_HwJobTransmit();
        }
        break;

        case SPI_HW_EV_JOB_FINISHED:
        /* check if a sequence has completed */
        Spi_HwSeqComplete();
        /* transmit a new job if it is pending */
        Spi_HwJobTransmit();
        break;

        case SPI_HW_EV_CANCEL:
        break;

        case SPI_HW_EV_FAILED:
        /* clean up the failed sequence */
        Spi_HwSeqCleanUp();
        /* transmit a new job if it is pending */
        Spi_HwJobTransmit();
        break;

        default:
        break;
    }
    return;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwJobsSort
 **********************************************************************************************************************/
/*! \brief      This method sorts all jobs by priority.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module job handling
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwJobsSort(void)
{
    uint16_least JobIdx_u16;    /* job Id index for loop  */
    uint16_least SortedIdx_u16; /* Sorted index for priority array */
    uint16_least PrioIdx_u16;   /* priority index for loop*/
    uint16_least Prio_u16;      /* priority of a job */
    uint8_least  JobId;

    /* sort jobs by priority */
    /* sorting looks like this:
     *  Id             prio             ->  Id          prio
     * Job0             1          ------>  Job1         3
     * Job1             3  -------/         Job2         2
     * Job2             2                   Job4         2
     * Job3             0                   Job0         1
     * Job4             2                   Job3         0*/

    /* this loop decreases the priority from max to min */
    Prio_u16 = SPI_MAX_JOB_PRIO;
    SortedIdx_u16 = 0;
    for(PrioIdx_u16 = 0; PrioIdx_u16 <= SPI_MAX_JOB_PRIO; PrioIdx_u16++)
    {
        /* this loop searches for all jobs with the same priority */
        for(JobIdx_u16 = 0; JobIdx_u16 < Spi_ConfigPtr_pt->Spi_MaxJobs; JobIdx_u16++)
        {
            /* scan for actual priority */
            if(Spi_ConfigPtr_pt->Spi_JobCfg[JobIdx_u16].Spi_JobPrio == Prio_u16)
            {
                JobId = Spi_ConfigPtr_pt->Spi_JobCfg[JobIdx_u16].Spi_JobID;
                /* assign first job with highest priority [3,2,1,0] */
                Spi_JobsSorted_at[SortedIdx_u16].JobID_u8 = (uint8)JobId;
                Spi_JobPrioConvTbl_at[JobId] = (uint8)SortedIdx_u16;
                SortedIdx_u16++;
                /* job assigned, scan for next */
            }
            else
            {
                /* no action */
            }
            Spi_JobsSorted_at[JobIdx_u16].SeqID_u8  = 0xFF;
        }
        /* scan all jobs for next lower priority */
        Prio_u16--;
    }
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwJobQueue
 **********************************************************************************************************************/
/*! \brief      This method queues jobs by priority.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module job handling
 **********************************************************************************************************************/
#endif
static FUNC (Std_ReturnType, SPI_CODE)Spi_HwJobQueue(uint16_least SequenceID)
{
    uint16_least JobCnt_u16; /* loop over the number of jobs in a sequence */
    uint16_least JobIdx_u16; /* index to loop over the max number of jobs */
    uint16_least JobId_u16;  /* ID of a job*/
    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobChain_pt; /* pointer for a sequence chain of jobs */

    /* first check all jobs if they are allowed to be queued */
    for(JobCnt_u16 = 1; JobCnt_u16 <= Spi_ConfigPtr_pt->Spi_SeqCfg[SequenceID].Spi_JobList[0]; JobCnt_u16++)
    {
        /* get first assigned job of a sequence, starts a index 1 */
        JobId_u16  = Spi_ConfigPtr_pt->Spi_SeqCfg[SequenceID].Spi_JobList[JobCnt_u16];
        JobIdx_u16 = Spi_JobPrioConvTbl_at[JobId_u16];
        /* check the job for collision  */
        if(  (Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 == SPI_JOB_PENDING)
          || (Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 == SPI_JOB_ACTIVE))
        {
            /* the sequence is rejected due to common used jobs */
            return(E_NOT_OK);
        }
    }
    /* checking passed, continue to queue
     * clear last index marker
     */
    JobChain_pt = (P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT))NULL_PTR;
    /* loop over all jobs sorted by priority */
    for(JobCnt_u16 = 1; JobCnt_u16 <= Spi_ConfigPtr_pt->Spi_SeqCfg[SequenceID].Spi_JobList[0]; JobCnt_u16++)
    {
        /* get first assigned job of a sequence, starts a index 1 */
        JobId_u16  = Spi_ConfigPtr_pt->Spi_SeqCfg[SequenceID].Spi_JobList[JobCnt_u16];
        JobIdx_u16 = Spi_JobPrioConvTbl_at[JobId_u16];
        /* assign the first job with highest priority in a sequence */
        Spi_JobsSorted_at[JobIdx_u16].SeqID_u8   = (uint8)SequenceID;
        /* job is marked for transfer */
        Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_PENDING;
        /* now build up job chain */
        if(JobChain_pt != NULL_PTR)
        {
            /* set next pointer to second assigned job */
            JobChain_pt->JobNext_pt = &Spi_JobsSorted_at[JobIdx_u16];
        }
        else
        {
            /* no action */
        }
        /* set global job status*/
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[JobId_u16] = SPI_JOB_PENDING;
        /* save actual pointer to chain pointer for later use */
        JobChain_pt = &Spi_JobsSorted_at[JobIdx_u16];
    }
    /* all jobs accepted and queued,
     * sequence successfully added
     */
    Spi_HwSeqIdInst_t.SeqNrPend_u8++;
    return(E_OK);
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwJobClear
 **********************************************************************************************************************/
/*! \brief      This method clears queued jobs.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module job handling
 **********************************************************************************************************************/
#endif
static FUNC (void, SPI_CODE)Spi_HwJobClear(uint16_least SequenceID)
{
    uint16_least JobIdx_u16; /* index to loop over the max number of jobs */
    uint16_least JobId_u16;  /* ID of a job*/
    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobChain_pt; /* pointer for a sequence chain of jobs */
    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobAkt_pt;   /* pointer for a job chain in a sequence */

    /* get first assigned job of a sequence, starts a index 1 */
    JobId_u16   = Spi_ConfigPtr_pt->Spi_SeqCfg[SequenceID].Spi_JobList[1];
    JobIdx_u16  = Spi_JobPrioConvTbl_at[JobId_u16];
    JobChain_pt = &Spi_JobsSorted_at[JobIdx_u16];

    /* now clean up the remaining chained jobs */
    while(JobChain_pt != NULL_PTR)
    {
        /* clear all pending jobs belonging to this sequence */
        JobId_u16 = JobChain_pt->JobID_u8;
        if(  (JobChain_pt->JobStatus_u8 == SPI_JOB_PENDING)
          || (JobChain_pt->JobStatus_u8 == SPI_JOB_ACTIVE))
        {
            /* set job state */
            JobChain_pt->JobStatus_u8  = SPI_JOB_OK;
            Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[JobId_u16] = SPI_JOB_OK;
        }
        /* save current job */
        JobAkt_pt   = JobChain_pt;
        /* get next job */
        JobChain_pt = JobAkt_pt->JobNext_pt;
        /* and remove the reference */
        JobAkt_pt->JobNext_pt = NULL_PTR;
    }
    /* clear number of jobs */
    Spi_HwSeqEvent_at[SequenceID].NrOfJobs_u8 = 0;
    return;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwJobTransmit
 **********************************************************************************************************************/
/*! \brief      This method transmits queued jobs.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module job handling
 **********************************************************************************************************************/
#endif
static FUNC (void, SPI_CODE)Spi_HwJobTransmit(void)
{
    uint16_least JobIdx_u16;    /* index to loop over the max number of jobs */
    uint16_least SeqId_u16;     /* ID of a sequence */
    uint16_least SeqIdAt_u16;   /* ID of a sequence attached to a job */
    uint16_least SeqIdRep_u16;  /* ID of a sequence reported by a job complete */

    /* skip the remaining code, if no sequence has been queued */
    if(Spi_HwSeqIdInst_t.SeqNrPend_u8 == 0)
    {
        return;
    }
    /* get actual sequence ID */
    SeqId_u16    = Spi_HwSeqIdInst_t.SeqIdAkt_u8;
    /* get reported sequence ID, but beware of the init value */
    SeqIdRep_u16 = Spi_HwSeqIdInst_t.SeqIdRep_u8;

    /* if a synchronous sequence was reported, finish the complete sequence regardless of job priority */
    if(  (SeqIdRep_u16 != 0x00FF)
      && (Spi_HwSeqEvent_at[SeqIdRep_u16].Guard_u8 == SPI_HW_SYNC) )
    {
        JobIdx_u16 =  Spi_JobPrioConvTbl_at[Spi_HwJobEvent_at.TaskID_u8];
        Spi_JobsSorted_at[JobIdx_u16].JobNext_pt->JobStatus_u8 = SPI_JOB_ACTIVE;
        /* now prepare job transmission ! */
        Spi_DlcSetEvent_t.JobID_u8 = Spi_JobsSorted_at[JobIdx_u16].JobNext_pt->JobID_u8;
        Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_SYNCTX;
        Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_START;
    }
    else
    {
        /* search for serviceable jobs */
        for(JobIdx_u16 = 0; JobIdx_u16 < Spi_ConfigPtr_pt->Spi_MaxJobs; JobIdx_u16++)
        {
            /* check all jobs if they are marked for transmission     */
            /* one of these jobs will be transmitted, done by queuing */
            if(  (Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 == SPI_JOB_PENDING)
              || (Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 == SPI_JOB_ACTIVE ))
            {
                /* if a job is marked for transmission, but belongs not to the actual
                 * sequence, it can be transmitted because the JobIdx_u16 loop goes from highest to lowest priority
                 * get Job ID
                 */
                Spi_DlcSetEvent_t.JobID_u8 = Spi_JobsSorted_at[JobIdx_u16].JobID_u8;
                SeqIdAt_u16                = Spi_JobsSorted_at[JobIdx_u16].SeqID_u8;
                /* if a sequence is synchronous, handle this first. This also includes a reported sequence
                 * If a job starts a sync sequence, this sequence must be transmitted completely regardless
                 * of the job priority
                 */
                if(   (Spi_HwSeqEvent_at[SeqId_u16].Guard_u8    == SPI_HW_SYNC)
                   || (Spi_HwSeqEvent_at[SeqIdAt_u16].Guard_u8  == SPI_HW_SYNC))
                {
                    /* now prepare job transmission ! */
                    Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_SYNCTX;
                    Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_START;
                    /* the transmission should not take place in an ISR context, so break here and schedule again */
                    break;
                }
                else
                {
                    Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_ASYNCTX;
                }
                /* if the sequence interruptible and a job is not attached to this sequence */
                if(  (Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_SeqInt == TRUE)
                  && (SeqIdAt_u16 != SeqId_u16))
                {
                    /* prepare job transmission ! */
                    Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_ACTIVE;
                }
                /* sequence is not interruptible */
                else
                {
                    if(SeqIdAt_u16 == SeqId_u16)
                    {
                        /* job transmission is asynchronous */
                        Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_ACTIVE;
                    }
                    else
                    {
                        /* no action */
                    }
                }
                if(Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 == SPI_JOB_ACTIVE)
                {
                    if(Spi_DlcSetEvent(&Spi_DlcSetEvent_t) == E_NOT_OK)
                    {
                        /* job transfer request was declined */
                        Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_PENDING;
                        Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_START;
                        Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_CONSUMED;
                    }
                    else
                    {
                        /* no action */
                    }
                    break;
                }
            }
            else
            {
                /* no action */
            }
        }
    }
    return;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSeqAdjust
 **********************************************************************************************************************/
/*! \brief      This method reassigns the pointers for pending sequences
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        none
 *  \context    Function is called from task or interrupt level
 *  \note       called from: Spi_HwSeqNext or Spi_HwSetEvent
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwSeqAdjust(uint16_least SequenceID)
{
    if(Spi_HwSeqEvent_at[SequenceID].SeqPrev_pt != NULL_PTR)
    {
        /* adjust pointer to prev sequence */
        if(Spi_HwSeqEvent_at[SequenceID].SeqNext_pt != NULL_PTR)
        {
            Spi_HwSeqEvent_at[SequenceID].SeqNext_pt->SeqPrev_pt = Spi_HwSeqEvent_at[SequenceID].SeqPrev_pt;
        }
    }
    if(Spi_HwSeqEvent_at[SequenceID].SeqNext_pt != NULL_PTR)
    {
        /* adjust pointer to next sequence */
        if(Spi_HwSeqEvent_at[SequenceID].SeqPrev_pt != NULL_PTR)
        {
            Spi_HwSeqEvent_at[SequenceID].SeqPrev_pt->SeqNext_pt = Spi_HwSeqEvent_at[SequenceID].SeqNext_pt;
        }
    }
    /* clear pointer's */
    Spi_HwSeqEvent_at[SequenceID].SeqNext_pt = NULL_PTR;
    Spi_HwSeqEvent_at[SequenceID].SeqPrev_pt = NULL_PTR;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSeqNext
 **********************************************************************************************************************/
/*! \brief      This method checks for a pending sequence
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       called from: Spi_HwSeqCleanUp, Spi_HwSeqComplete
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwSeqNext(void)
{
    uint16_least SeqId_u16;    /* Id of a sequence */

    /* this sequence was reported as finished */
    SeqId_u16 = Spi_HwSeqIdInst_t.SeqIdRep_u8;
    /* we need to check the sequence which was reported by JobComplete */
    if(Spi_HwSeqIdInst_t.SeqNrPend_u8 == 0)
    {
        /* all sequences were executed, set global status to IDLE */
        /* clear pointer's */
        Spi_HwSeqEvent_at[SeqId_u16].SeqNext_pt = NULL_PTR;
        Spi_HwSeqEvent_at[SeqId_u16].SeqPrev_pt = NULL_PTR;
        Spi_HwSeqIdInst_t.SeqIdAkt_u8  = 0xFF;
        Spi_HwSeqIdInst_t.SeqIdPend_u8 = 0xFF;
        Spi_HwSeqIdInst_t.SeqIdRep_u8  = 0xFF;
        Spi_DrvResult_t = SPI_IDLE;
    }
    else
    {
        /* check if this sequence is the one actually being exectuted */
        if(Spi_HwSeqIdInst_t.SeqIdAkt_u8 == SeqId_u16)
        {
            /* set next sequence to execute */
            Spi_HwSeqIdInst_t.SeqIdAkt_u8 = Spi_HwSeqEvent_at[SeqId_u16].SeqNext_pt->TaskID_u8;
        }
        else
        {
            /* no action */
        }
        /* due to the priority of the jobs, any sequence may be reported as finished */
        /* so the pointers need to be adjusted and the next sequence in line has to be executed */
        Spi_HwSeqAdjust(SeqId_u16);
    }
}


#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSeqCleanUp
 **********************************************************************************************************************/
/*! \brief      This method cleans up the remaining jobs of a failed sequence.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module sequence handling
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwSeqCleanUp(void)
{
    uint16_least JobIdx_u16;    /* Index of a job   */
    uint16_least JobId_u16;     /* ID of a job      */
    uint16_least SeqId_u16;    /* Id of a sequence */

    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobChain_pt; /* pointer for a job chain in a sequence */
    P2VAR(Spi_JobSortedType, AUTOMATIC, SPI_VAR_NOINIT) JobAkt_pt;   /* pointer for a job chain in a sequence */

    /* this sequence was reported as finished */
    SeqId_u16 = Spi_HwSeqIdInst_t.SeqIdRep_u8;
    /* this is set by the DLC module, every time a job has completed */
    JobId_u16   = Spi_HwJobEvent_at.TaskID_u8;
    JobIdx_u16  = Spi_JobPrioConvTbl_at[JobId_u16];
    /* set chain pointer */
    JobChain_pt = &Spi_JobsSorted_at[JobIdx_u16];

    Spi_GlobalSuspend();
    /* next seek all jobs belonging to this sequence  and clear these jobs */
    while(JobChain_pt != NULL_PTR)
    {
        JobId_u16 = JobChain_pt->JobID_u8;
        /* set jobstate */
        JobChain_pt->JobStatus_u8  = SPI_JOB_FAILED;
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[JobId_u16] = SPI_JOB_FAILED;
        /* save current job */
        JobAkt_pt = JobChain_pt;
        /* get next job */
        JobChain_pt = JobAkt_pt->JobNext_pt;
        /* and remove the reference */
        JobAkt_pt->JobNext_pt = NULL_PTR;
    }
    /* clear number of jobs */
    Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8 = 0;
    /* clear transmission mode */
    Spi_HwSeqEvent_at[SeqId_u16].Guard_u8    = SPI_HW_UNDEF;

    Spi_HwSeqIdInst_t.SeqNrPend_u8--;
    /* set sequence result */
    Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] = SPI_SEQ_FAILED;
    Spi_GlobalRestore();
    /* goto next sequence */
    Spi_HwSeqNext();
    /* now call configured sequence error notification */
    if(Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_SequenceEndNotification != NULL_PTR)
    {
        Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_SequenceEndNotification();
    }
}
#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSeqComplete
 **********************************************************************************************************************/
/*! \brief      This method checks and reports a completed sequence.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module sequence handling
 **********************************************************************************************************************/
#endif
static FUNC(void, SPI_CODE) Spi_HwSeqComplete(void)
{
    uint16_least SeqId_u16;    /* Id of a sequence */

    /* this sequence was reported as finished */
    SeqId_u16 = Spi_HwSeqIdInst_t.SeqIdRep_u8;

    /* now check if a sequence has completed */
    if(Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8 == 0)
    {
        /* check if sequence has been canceled */
        if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] != SPI_SEQ_CANCELLED)
        {
            /* this part has already been done in the cancel part */
            Spi_HwSeqIdInst_t.SeqNrPend_u8--;
            Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] = SPI_SEQ_OK;
        }
        /* clear transmission mode */
        Spi_HwSeqEvent_at[SeqId_u16].Guard_u8 = SPI_HW_UNDEF;
        /* goto next sequence, handled in the Processing function */
        Spi_HwSeqNext();
        /* call configured sequence end notification */
        if(Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_SequenceEndNotification != NULL_PTR )
        {
            Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_SequenceEndNotification();
        }
    }
    else
    {
        /* no action */
    }
    return;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwJobComplete
 **********************************************************************************************************************/
/*! \brief      This method handles the job completition.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note        Specification of module job transfer
 **********************************************************************************************************************/
#endif
FUNC(void, SPI_CODE) Spi_HwJobComplete(uint16_least Job_u16, uint16_least DLC_u16)
{
    uint16_least JobIdx_u16;    /* Index of a job*/
    uint16_least SeqId_u16;     /* ID of a sequence */

    /* this is set by the DLC module, every time a job has completed */
    JobIdx_u16 = Spi_JobPrioConvTbl_at[Job_u16];
    /* reset job in priority queue */
    /* backup sequence ID */
    SeqId_u16 = Spi_JobsSorted_at[JobIdx_u16].SeqID_u8;

    Spi_HwSeqIdInst_t.SeqIdRep_u8 = (uint8)SeqId_u16;
    Spi_HwJobEvent_at.TaskID_u8   = (uint8)Job_u16;
    /* reset sequence ID */
    Spi_JobsSorted_at[JobIdx_u16].SeqID_u8 = 0xFF;

    /* one job less remaining in this sequence */
    if(Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8 > 0)
    {
        Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8--;
    }
    /* call notification */
    if(Spi_ConfigPtr_pt->Spi_JobCfg[Job_u16].Spi_JobEndNotification != NULL_PTR)
    {
        /* call job end notification */
        Spi_ConfigPtr_pt->Spi_JobCfg[Job_u16].Spi_JobEndNotification();
    }
    /* set result of the JobID */
    /* this is important to do this after the callback notification */
    /* otherwise if a sequence is queued with the same job, the job is reloaded endless */
    /* Now check if an error was detected and update the status */
    if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_DlcResult[DLC_u16] == SPI_DLC_FAILED)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[Job_u16] = SPI_JOB_FAILED;
        Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_FAILED;
        Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_FAILED;
    }
    else
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[Job_u16] = SPI_JOB_OK;
        Spi_JobsSorted_at[JobIdx_u16].JobStatus_u8 = SPI_JOB_OK;
        Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_JOB_FINISHED;
    }
    /* job was serviced */
    Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_CONSUMED;

#if ((SPI_SCALEABILITY == SPI_ASYNCONLY)  || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
    if(Spi_HwMode_t == SPI_POLLING_MODE)
    {
        /* reload the next transmission in the Spi_MainFunctionDriving() */
    }
    else
    {
        /* reload the next transmission in the current context (interrupt) */
        Spi_HwJobConsumeEvent();
    }
#endif
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwInit
 **********************************************************************************************************************/
/*! \brief      This method handles the initialization.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
#endif
FUNC(void, SPI_CODE) Spi_HwInit(void)
{
    uint16_least SeqIdx_u16;

    /* reset global data variables */

    /* reset the working index of current processed sequence in the sequence event array */
    Spi_HwSeqIdInst_t.SeqIdAkt_u8  = 0xFF;
    /* reset the working index of a pending sequence in the sequence event array */
    Spi_HwSeqIdInst_t.SeqIdPend_u8 = 0xFF;
    /* reset the number of current queued sequences */
    Spi_HwSeqIdInst_t.SeqNrPend_u8 = 0;
    /* reset the number of reported sequences */
    Spi_HwSeqIdInst_t.SeqIdRep_u8 = 0xFF;

#if (SPI_SCALEABILITY == SPI_ASYNCONLY)
    Spi_HwMode_t = SPI_INTERRUPT_MODE;
#else
    Spi_HwMode_t = SPI_POLLING_MODE;
#endif
    Spi_HwJobEvent_at.Event_u8 = SPI_HW_EV_CONSUMED;
    Spi_DlcSetEvent_t.Event_u8 = SPI_DLC_EV_CONSUMED;
    for(SeqIdx_u16 = 0; SeqIdx_u16 < Spi_ConfigPtr_pt->Spi_MaxSequences; SeqIdx_u16++)
    {
        Spi_HwSeqEvent_at[SeqIdx_u16].Event_u8 = SPI_HW_EV_CONSUMED;
        Spi_HwSeqEvent_at[SeqIdx_u16].Guard_u8 = SPI_HW_UNDEF;
    }
    Spi_HwJobsSort();
    Spi_DlcInit();
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwDeInit
 **********************************************************************************************************************/
/*! \brief      This method handles the de-initialization.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
#endif
FUNC(void, SPI_CODE) Spi_HwDeInit(void)
{
    Spi_DlcClose();
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwSetEvent
 **********************************************************************************************************************/
/*! \brief      This method handles incoming events.
 *  \param[in]  Spi_HwEventType           Hw_Event_pt, event structure
 *  \param[out] none
 *  \return     E_OK                      event accpeted
 *  \return     E_NOT_OK                  event rejected
 *  \pre        Input parameter must not be NULL.
 *  \context    Function is called from task level
 *  \note       Specification of module event handling
 **********************************************************************************************************************/
#endif
FUNC(Std_ReturnType, SPI_CODE) Spi_HwSetEvent
(
    P2CONST(Spi_HwEventType, AUTOMATIC, SPI_VAR) Hw_Event_pt
)
{
    uint16_least SeqId_u16;   /* id of a sequence, used as index of the sequence array */
    uint16_least JobNr_u16;   /* number of jobs in a configuration */
    Std_ReturnType Ret_loc;

    SeqId_u16 = (uint16_least)Hw_Event_pt->TaskID_u8;
    if (Hw_Event_pt->Event_u8 == SPI_HW_EV_CANCEL)
    {
        /* start critical section */
        Spi_GlobalSuspend();
        /* only a pending sequence can be cancelled */
        if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] == SPI_SEQ_PENDING)
        {
            /* only a pending sequence can be canceled */
            /* adjust pointers to next and previous sequence */
            Spi_HwSeqAdjust(SeqId_u16);
            Spi_HwSeqEvent_at[SeqId_u16].Event_u8 = SPI_HW_EV_CANCEL;
            Spi_HwSeqEvent_at[SeqId_u16].Guard_u8 = 0;
            Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8 = 0;
            Spi_HwSeqIdInst_t.SeqNrPend_u8--;
            /* clear all jobs belonging to this sequence */
            Spi_HwJobClear(SeqId_u16);
            Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] = SPI_SEQ_CANCELLED;
        }
        else
        {
            /* no action */
        }
        /* stop critical section */
         Spi_GlobalRestore();
    }
    else
    {
        /* start critical section */
        Spi_GlobalSuspend();
        /* add a pending sequence ? */
        if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] != SPI_SEQ_PENDING) /* sequence pending ? */
        {
            /* sequence ID is the index of this array Spi_HwSeqEvent_at[] */
            /* try to queue the jobs, if a job belonging to a sequence is still pending, the check fails */
            Ret_loc = Spi_HwJobQueue(SeqId_u16);
            if(Ret_loc == E_OK)
            {
                /* set event ID */
                Spi_HwSeqEvent_at[SeqId_u16].Event_u8  = Hw_Event_pt->Event_u8;
                /* set sequence ID */
                Spi_HwSeqEvent_at[SeqId_u16].TaskID_u8 = (uint8)SeqId_u16;
                /* set sequence to pending */
                Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[SeqId_u16] = SPI_SEQ_PENDING;
                Spi_DrvResult_t = SPI_BUSY;
                /* guard is used for sync or async tx */
                Spi_HwSeqEvent_at[SeqId_u16].Guard_u8 = Hw_Event_pt->Guard_u8;
                /* get number of jobs from the configuration */
                JobNr_u16 = Spi_ConfigPtr_pt->Spi_SeqCfg[SeqId_u16].Spi_JobList[0];
                Spi_HwSeqEvent_at[SeqId_u16].NrOfJobs_u8 = (uint8)JobNr_u16;
                /* assign a queue number to this sequence */
                if(Spi_HwSeqIdInst_t.SeqNrPend_u8 == 1)
                {
                    /* start transmit if no sequence was pending  -> Spi_HwSeqConsumeEvent */
                    Spi_HwSeqIdInst_t.SeqIdAkt_u8  = (uint8)SeqId_u16;
                    Spi_HwSeqIdInst_t.SeqIdPend_u8 = (uint8)SeqId_u16;
                    /* stop critical section */
                    Spi_GlobalRestore();
                    Spi_HwSeqConsumeEvent(); /* consume event */
                }
                else
                {
                    /* assign pointer to next sequence */
                    Spi_HwSeqEvent_at[Spi_HwSeqIdInst_t.SeqIdPend_u8].SeqNext_pt = &Spi_HwSeqEvent_at[SeqId_u16];
                    /* assign last queued sequence to prev pointer */
                    Spi_HwSeqEvent_at[SeqId_u16].SeqPrev_pt = &Spi_HwSeqEvent_at[Spi_HwSeqIdInst_t.SeqIdPend_u8];
                    /* stop critical section */
                    Spi_GlobalRestore();
                    /* any other transmit is done by the queued sequences, the queue */
                    /* is checked any time a job has completed */
                }
                /* all settings done, now update pending variable */
                Spi_HwSeqIdInst_t.SeqIdPend_u8 = (uint8)SeqId_u16;
            }
            else
            {
                /* stop critical section */
                Spi_GlobalRestore();
                /* shared job still pending !*/
                return(E_NOT_OK);
            }
        }
        else
        {
            /* sequence is pending! */
            /* stop critical section */
            Spi_GlobalRestore();
           return(E_NOT_OK);
        }
    }
    return (E_OK);
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwProcessState
 **********************************************************************************************************************/
/*! \brief      This method handles the internal states.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from task level
 *  \note       Specification of module event handling
 **********************************************************************************************************************/
#endif
FUNC(void, SPI_CODE) Spi_HwSetMode(Spi_AsyncModeType Mode)
{
    Spi_HwMode_t = Mode;
}

#if defined (C_COMMENT_VECTOR)
/***********************************************************************************************************************
 *  Spi_HwProcessState
 **********************************************************************************************************************/
/*! \brief      This method handles the internal states.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from task level
 *  \note       Specification of module event handling
 **********************************************************************************************************************/
#endif
FUNC(void, SPI_CODE) Spi_HwProcessState(void)
{
    /* schedule the event, check if a sequence has completed */
    Spi_HwJobConsumeEvent();
}

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *  END OF FILE: Spi_Hw.c
 *********************************************************************************************************************/
