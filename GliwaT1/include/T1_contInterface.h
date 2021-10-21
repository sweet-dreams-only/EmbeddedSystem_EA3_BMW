/*************************************************************************************
*   FILE:           T1_contInterface.h
*
*   DESCRIPTION:    T1.cont interface
*
*   VISIBILITY:     extern
*
*   $Author: nick $
*
*   $Revision: 15885 $
*
*   $URL: https://gliwa.com/svn/repos/T1target/trunk/src/T1.cont/src/all/T1_contInterface.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

#ifndef T1_CONT_INTERFACE_H_
#define T1_CONT_INTERFACE_H_ (1)

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include "T1_baseInterface.h"
#include "T1_scopeInterface.h"

/*----------------------------------------------------------------------------------*/
/*--- macros and inline functions --------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#define T1_CONT_PLUGIN_ID       (5u)

#define T1_ENABLE_CPULOAD_CALC  (1)

#define T1_TASK_STACK_OVERRUNS  (4)

#if defined T1_ENABLE && !defined T1_DISABLE_T1_CONT

#   ifdef T1_USE_LOGIC
#       error T1.cont is not compatible with the logic analyser interface
#   endif /* T1_USE_LOGIC */

#   if defined T1_CONT_SYS_TIME_DOWNCOUNTING
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
#           define T1_contPlugin            (&T1_contPluginStructDirectDC)
#       else /* original */
#           define T1_contPlugin            (&T1_contPluginStructOrigDC)
#       endif /* build variants */
#   else /* !defined T1_CONT_SYS_TIME_DOWNCOUNTING */
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
#           define T1_contPlugin            (&T1_contPluginStructDirect)
#       else /* original */
#           define T1_contPlugin            (&T1_contPluginStructOrig)
#       endif /* build variants */
#   endif /* defined T1_CONT_SYS_TIME_DOWNCOUNTING */

#else
#   define T1_contPlugin                    (T1_DISABLED_PLUGIN)
#endif

#define T1_PERCENT_TO_256THS( percent_ )    ((percent_) * 2.56 + 0.5)

#if defined T1_CONT_DIRECT_ID_MAPPINGS
#   define T1_BACKGROUND_TASK_IDX_CORE0     (T1_BACKGROUND_TASK_ID_CORE0)
#   define T1_BACKGROUND_TASK_IDX_CORE1     (T1_BACKGROUND_TASK_ID_CORE1)
#   define T1_BACKGROUND_TASK_IDX_CORE2     (T1_BACKGROUND_TASK_ID_CORE2)
#endif /* defined T1_CONT_DIRECT_ID_MAPPINGS */

/*---------------------- bits of variable T1_contBgStatus --------------------------*/
/* the lowest bit indicates information ("INF") */
#define T1_INF_OVERHEADS_UPDATED            ((T1_contStatus_t)1<<0)
/* the lower bits indicate warnings ("WRN") */
#define T1_WRN_INCOMPLETE_ANALYSIS          ((T1_contStatus_t)1<<1)
#define T1_WRN_CONSTRAINT_VIOLATED          ((T1_contStatus_t)1<<2)
#define T1_WRN_INVALID_CET_STPW             ((T1_contStatus_t)1<<3)
#define T1_WRN_RESULT_OUT_OF_RANGE          ((T1_contStatus_t)1<<4)
/* the higher bits indicate errors ("ERR") */
#define T1_ERR_FAULTY_TRACE_DATA            ((T1_contStatus_t)1<<5)
#define T1_ERR_STACK_OVERFLOW               ((T1_contStatus_t)1<<6)
#define T1_ERR_OVERRUN                      ((T1_contStatus_t)1<<7)

/*---------------------- bits of variable T1_contHandlerStatus ---------------------*/
/* the lower bits indicate warnings ("WRN") */
#define T1_WRN_ANALYSIS_STOPPED             ((T1_contStatus_t)1<<0)
/* the upper bits give status information */
#define T1_MODE_FOCUS_RUNNING               ((T1_contStatus_t)1<<4)
#define T1_MODE_CONSTRAINTS_ENABLED         ((T1_contStatus_t)1<<5)
#define T1_MODE_TRANSMISSION_ENABLED        ((T1_contStatus_t)1<<6)
#define T1_MODE_ANALYSIS_ENABLED            ((T1_contStatus_t)1<<7)
/*
 * T1_MODE_FOCUS_RUNNING is excluded from T1_MODES_BITMASK because it is set and
 * cleared indirectly through the focus protocol.
 */
#define T1_MODES_BITMASK ((T1_contStatus_t)(T1_MODE_CONSTRAINTS_ENABLED  |  \
                                            T1_MODE_TRANSMISSION_ENABLED |  \
                                            T1_MODE_ANALYSIS_ENABLED))
/*----------------------------------------------------------------------------------*/

/* bits for constraint configuration */
#define T1_CSRN_MAX                 (1u)
#define T1_CSRN_MIN                 (2u)
#define T1_STOPTRIGGER              (T1_STOPTRIGGER_DEPRECATED)
#define T1_CALLBACK                 (T1_CALLBACK_DEPRECATED)
#define T1_MESSAGE                  (T1_MESSAGE_DEPRECATED)
#define T1_CSRN_UNDEF               (T1_CSRN_UNDEF_DEPRECATED)

#define T1_INVALID_TASK_IDX         ((T1_taskIdx_t)-1)
#define T1_INVALID_TASK_ID          T1_INVALID_TASK_IDX
#define T1_INVALID_RESULT_IDX       ((T1_resultsIdx_t)-1)

#define T1_INVALID_STPW_IDX         ((T1_stpwIdx_t)-1)

#define T1_STOPWATCH_ID_FOR_T1_FLEX (&T1_undefined)

#define T1_CONT_STPW_GET            (0u)    /* Last start to first stop */
#define T1_CONT_STPW_DATA_AGE       (1u)    /* Last start to last stop */
#define T1_CONT_STPW_CET            (2u)    /* Last start to first stop in same task instance */
#define T1_CONT_STPW_NPC            (3u)    /* Last start to first stop with no preemptions */
#define T1_CONT_STPW_REENTRANT0     (4u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT1     (5u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT2     (6u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT3     (7u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT4     (8u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT5     (9u)    /* Used for nesting */
#define T1_CONT_STPW_REENTRANT6     (10u)   /* Used for nesting */
#define T1_CONT_STPW_REENTRANT7     (11u)   /* Used for nesting */
#define T1_CONT_STPW_INVALID_CFG    (255u)

#define T1_CONT_STPW_IS_CET( cfg_ )         ( T1_CONT_STPW_CET <= (cfg_) )

/* See T1_stpwConfig_t */
#ifdef T1_CONT_DIRECT_ID_MAPPINGS
#   define T1_CONT_CET_STOPWATCH( id_ )         { T1_CONT_STPW_CET }
#   define T1_CONT_NPC_STOPWATCH( id_ )         { T1_CONT_STPW_NPC }
#   define T1_CONT_GET_STOPWATCH( id_ )         { T1_CONT_STPW_GET }
#   define T1_CONT_DATA_AGE_STOPWATCH( id_ )    { T1_CONT_STPW_DATA_AGE }
#   define T1_CONT_REENTRANT0_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT0 }
#   define T1_CONT_REENTRANT1_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT1 }
#   define T1_CONT_REENTRANT2_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT2 }
#   define T1_CONT_REENTRANT3_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT3 }
#   define T1_CONT_REENTRANT4_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT4 }
#   define T1_CONT_REENTRANT5_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT5 }
#   define T1_CONT_REENTRANT6_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT6 }
#   define T1_CONT_REENTRANT7_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT7 }
#else /* !T1_CONT_DIRECT_ID_MAPPINGS */
#   define T1_CONT_CET_STOPWATCH( id_ )         { T1_CONT_STPW_CET, (id_) }
#   define T1_CONT_NPC_STOPWATCH( id_ )         { T1_CONT_STPW_NPC, (id_) }
#   define T1_CONT_GET_STOPWATCH( id_ )         { T1_CONT_STPW_GET, (id_) }
#   define T1_CONT_DATA_AGE_STOPWATCH( id_ )    { T1_CONT_STPW_DATA_AGE, (id_) }
#   define T1_CONT_REENTRANT0_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT0, (id_) }
#   define T1_CONT_REENTRANT1_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT1, (id_) }
#   define T1_CONT_REENTRANT2_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT2, (id_) }
#   define T1_CONT_REENTRANT3_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT3, (id_) }
#   define T1_CONT_REENTRANT4_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT4, (id_) }
#   define T1_CONT_REENTRANT5_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT5, (id_) }
#   define T1_CONT_REENTRANT6_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT6, (id_) }
#   define T1_CONT_REENTRANT7_STOPWATCH( id_ )  { T1_CONT_STPW_REENTRANT7, (id_) }
#endif /* T1_CONT_DIRECT_ID_MAPPINGS */

#define T1_NS_TO_TICKS_CORE0( ns_ ) (((ns_) * 1.0) / T1_TICK_DURATION_CORE0_NS)
#define T1_US_TO_TICKS_CORE0( us_ ) (((us_) * 1000.0) / T1_TICK_DURATION_CORE0_NS)
#define T1_MS_TO_TICKS_CORE0( ms_ ) (((ms_) * 1000000.0) / T1_TICK_DURATION_CORE0_NS)

#define T1_NS_TO_TICKS_CORE1( ns_ ) (((ns_) * 1.0) / T1_TICK_DURATION_CORE1_NS)
#define T1_US_TO_TICKS_CORE1( us_ ) (((us_) * 1000.0) / T1_TICK_DURATION_CORE1_NS)
#define T1_MS_TO_TICKS_CORE1( ms_ ) (((ms_) * 1000000.0) / T1_TICK_DURATION_CORE1_NS)

#define T1_NS_TO_TICKS_CORE2( ns_ ) (((ns_) * 1.0) / T1_TICK_DURATION_CORE2_NS)
#define T1_US_TO_TICKS_CORE2( us_ ) (((us_) * 1000.0) / T1_TICK_DURATION_CORE2_NS)
#define T1_MS_TO_TICKS_CORE2( ms_ ) (((ms_) * 1000000.0) / T1_TICK_DURATION_CORE2_NS)

#define T1_NS_TO_TICKS( ns_ )       T1_NS_TO_TICKS_CORE0( ns_ )
#define T1_US_TO_TICKS( us_ )       T1_US_TO_TICKS_CORE0( us_ )
#define T1_MS_TO_TICKS( ms_ )       T1_MS_TO_TICKS_CORE0( ms_ )

#define T1_CONT_CONSTRAINT_TIME( ticks_, config_ )                              \
( ((config_) == T1_CSRN_MAX)                                                    \
  ? ((ticks_) & 0x7FFFFFFFuL)                                                   \
  : ( ((config_) == T1_CSRN_MIN) ? (((ticks_) + 1uL) | 0x80000000uL) : 0uL ) )

#define T1_STPW_IDX_CONSTRAINT( contStpwIdx_, ticks_, config_ )             \
{                                                                           \
    (T1_stpwIdx_t)(contStpwIdx_),                                           \
    0u, 0u,                                                                 \
    T1_CONT_CONSTRAINT_TIME( (T1_longTime_t)(ticks_), (config_) )           \
}
#define T1_TASK_IDX_CONSTRAINT( contTaskIdx_, ticks_, config_ )             \
{                                                                           \
    (T1_stpwIdx_t)(contStpwIdx_),                                           \
    1u, 0u,                                                                 \
    T1_CONT_CONSTRAINT_TIME( (T1_longTime_t)(ticks_), (config_) )           \
}
#define T1_CONT_INVALID_CONSTRAINT  { T1_INVALID_STPW_IDX, 0u, 0u, 0uL }

#ifndef T1_CONT_NOF_VRTL_STPWS
#   define T1_CONT_NOF_VRTL_STPWS   (8)
#endif

#if defined T1_ENABLE && !defined T1_DISABLE_T1_CONT
#   ifndef T1_MAX_TASK_PREEMPTIONS_CORE0
#       define T1_MAX_TASK_PREEMPTIONS_CORE0 \
( 20 < ( 4 + (T1_NOF_TASKS_CORE0 / 4) ) ? 20 : ( 4 + (T1_NOF_TASKS_CORE0 / 4) ) )
#   endif /* T1_MAX_TASK_PREEMPTIONS_CORE0 */
#   ifndef T1_MAX_TASK_PREEMPTIONS_CORE1
#       define T1_MAX_TASK_PREEMPTIONS_CORE1 \
( 20 < ( 4 + (T1_NOF_TASKS_CORE1 / 4) ) ? 20 : ( 4 + (T1_NOF_TASKS_CORE1 / 4) ) )
#   endif /* T1_MAX_TASK_PREEMPTIONS_CORE1 */
#   ifndef T1_MAX_TASK_PREEMPTIONS_CORE2
#       define T1_MAX_TASK_PREEMPTIONS_CORE2 \
( 20 < ( 4 + (T1_NOF_TASKS_CORE2 / 4) ) ? 20 : ( 4 + (T1_NOF_TASKS_CORE2 / 4) ) )
#   endif /* T1_MAX_TASK_PREEMPTIONS_CORE2 */

#   if defined T1_NOF_CORES
#       define T1_VSTPWS_IDX_BASE ( T1_nofStpwsPC[coreId__] - T1_CONT_NOF_VRTL_STPWS )
#       if defined T1_MULTICORE_CLONE
#           define T1_TRACE_EVENT( eventInfo_ ) T1_TraceEventNoSusp_( eventInfo_ )
#           define T1_SCOPE_OH_SEQ( )       T1_ScopeOverheadSequence( )
#       else /* clone */
#           define T1_TRACE_EVENT( eventInfo_ ) T1_TraceEventNoSuspPC[coreId__]( eventInfo_ )
#           define T1_SCOPE_OH_SEQ( )       T1_ScopeOverheadSequencePC( coreId__ )
#       endif /* defined T1_MULTICORE_CLONE */
#       define T1_CONT_CALIBRATE_OVERHEADS_PC( coreId_ )                            \
do                                                                                  \
{                                                                                   \
    const T1_uint8Least_t coreId__ = (coreId_);                                     \
    T1_ConfigEventChainPC(  coreId__,                                               \
                            T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_STOP_START,        \
                                                    T1_OH_SW ),                     \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP_START,         \
                                                   T1_OH_SW ),                      \
                            T1_VSTPWS_IDX_BASE + 3 );                               \
    T1_ConfigEventChainPC(  coreId__,                                               \
                            T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_START,             \
                                                    T1_OH_SW - 1 ),                 \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP,               \
                                                   T1_OH_SW - 1 ),                  \
                            T1_VSTPWS_IDX_BASE + 5 );                               \
    T1_ConfigEventChainPC(  coreId__,                                               \
                            T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_START,             \
                                                    T1_OH_SW - 2 ),                 \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP,               \
                                                   T1_OH_SW - 2 ),                  \
                            T1_VSTPWS_IDX_BASE + 7 );                               \
    T1_SCOPE_OH_SEQ( );                                                             \
    T1_SuspendAllInterrupts( );                                                     \
    T1_TRACE_EVENT( T1_COMBINE_EVENT_INFO( T1_EMPTY, T1_CONT_UPDATE_OH ) );         \
    T1_ResumeAllInterrupts( );                                                      \
}                                                                                   \
while( 0 )
#       define T1_CONT_STOP_CALIBRATION_PC( coreId_ )                               \
do                                                                                  \
{                                                                                   \
    const T1_uint8Least_t coreId__ = (coreId_);                                     \
    T1_DeleteCalibrationEventChainPC( coreId__, T1_VSTPWS_IDX_BASE + 3 );           \
    T1_DeleteCalibrationEventChainPC( coreId__, T1_VSTPWS_IDX_BASE + 5 );           \
    T1_DeleteCalibrationEventChainPC( coreId__, T1_VSTPWS_IDX_BASE + 7 );           \
}                                                                                   \
while( 0 )
#   else /* single core */
#       define T1_VSTPWS_IDX_BASE ( T1_nofStpws - T1_CONT_NOF_VRTL_STPWS )
#       define T1_CONT_CALIBRATE_OVERHEADS( )                                       \
do                                                                                  \
{                                                                                   \
    T1_ConfigEventChain(    T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_STOP_START,        \
                                                    T1_OH_SW ),                     \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP_START,         \
                                                   T1_OH_SW ),                      \
                            T1_VSTPWS_IDX_BASE + 3 );                               \
    T1_ConfigEventChain(    T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_START,             \
                                                    T1_OH_SW - 1 ),                 \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP,               \
                                                   T1_OH_SW - 1 ),                  \
                            T1_VSTPWS_IDX_BASE + 5 );                               \
    T1_ConfigEventChain(    T1_COMBINE_EVENT_INFO(  T1_STOPWATCH_START,             \
                                                    T1_OH_SW - 2 ),                 \
                            T1_COMBINE_EVENT_INFO( T1_STOPWATCH_STOP,               \
                                                   T1_OH_SW - 2 ),                  \
                            T1_VSTPWS_IDX_BASE + 7 );                               \
    T1_ScopeOverheadSequence( );                                                    \
    T1_SuspendAllInterrupts( );                                                     \
    T1_TraceEventNoSusp( T1_EMPTY, T1_CONT_UPDATE_OH );                             \
    T1_ResumeAllInterrupts( );                                                      \
}                                                                                   \
while( 0 )
#       define T1_CONT_STOP_CALIBRATION( )                                          \
do                                                                                  \
{                                                                                   \
    T1_DeleteCalibrationEventChain( T1_VSTPWS_IDX_BASE + 3 );                       \
    T1_DeleteCalibrationEventChain( T1_VSTPWS_IDX_BASE + 5 );                       \
    T1_DeleteCalibrationEventChain( T1_VSTPWS_IDX_BASE + 7 );                       \
}                                                                                   \
while( 0 )
#   endif /* T1_NOF_CORES */

#else /* T1.cont is disabled */

#   define T1_CONT_CALIBRATE_OVERHEADS_PC( coreId_) ( (void)0 )
#   define T1_CONT_CALIBRATE_OVERHEADS( )           ( (void)0 )

#endif /* defined T1_ENABLE && !defined T1_DISABLE_T1_CONT */


/*----------------------------------------------------------------------------------*/
/*--- type definitions -------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

typedef unsigned long   T1_resultMask_t;
typedef unsigned short  T1_taskId_t;
typedef unsigned char   T1_taskIdx_t;
typedef unsigned short  T1_stpwId_t;
typedef unsigned char   T1_stpwIdx_t;
typedef unsigned char   T1_csrnIdx_t;
typedef unsigned short  T1_resultsIdx_t;
typedef unsigned short  T1_anaCapa_t;
typedef T1_uint8_t      T1_contStatus_t;    /* Two different single-byte values */
typedef T1_uint32_t     T1_longTime_t;
typedef T1_uint8_t      T1_resultKind_t;
typedef T1_uint32_t     T1_resultTime_t;
/*----------------------------------------------------------------------------------*/
typedef const struct
{
    T1_uint8_t          configInit;         /* 0 => net, 1 => gross */
#ifndef T1_CONT_DIRECT_ID_MAPPINGS
    T1_stpwId_t         id;
#endif /* T1_CONT_DIRECT_ID_MAPPINGS */
} T1_stpwConfig_t;
/*----------------------------------------------------------------------------------*/
#if defined T1_CONT_TASK_CONSTRAINTS
typedef
#   if defined T1_CONT_TERMINATING_ECC
struct
{
#   endif /* defined T1_CONT_TERMINATING_ECC */
    T1_csrnIdx_t
#   if defined T1_CONT_TERMINATING_ECC
                        constraintIdx;      /* Constraint index for result */
    T1_uint8_t          unused8;            /* Force alignment */
#       if defined T1_CPU32BIT
    T1_uint16_t         unused16;           /* Force alignment */
#       endif /* defined T1_CPU32BIT */
    /* netAccumulation could just go on the task stack except for ECC tasks. */
    T1_resultTime_t     netAccumulation;    /* Accumulated net time for this task */
}
#   endif /* defined T1_CONT_TERMINATING_ECC */
T1_taskData_t;
#endif /* defined T1_CONT_TASK_CONSTRAINTS */
/*----------------------------------------------------------------------------------*/
typedef struct
{
    /* Convert task net to stopwatch net or absolute to stopwatch gross. */
    T1_resultTime_t     netConversionOrStartTime;
    T1_uint8_t          config;             /* See T1_stpwConfig_t */
    T1_uint8_t          startTaskInstKey;   /* The instance of the starting task */
    /* If the startTaskInstKey is zero, the stopwatch is not running. */
    T1_csrnIdx_t        constraintIdx;      /* Constraint index for result */
    T1_uint8_t          reentrantCount;     /* Count times reentered */
} T1_stpwData_t;
/*----------------------------------------------------------------------------------*/
/* use this structure to freely define a constraint buffer */
typedef struct
{
    /* REVIEWNOTE: T1_stpwIdx_t is used as a T1_taskIdx_t if a task constraint */
    T1_stpwIdx_t        stpwOrTaskIdx;    /* T1_INVALID_STPW_IDX for unused constraint */
    T1_uint8_t          isTaskConstraint;   /* False for an unused constraint */
    T1_uint16_t         unused16;           /* Force alignment */
    T1_longTime_t       threshold;
    /*
     * Threshold is a 32-bit value.
     * If the MSB is set, the value must be GREATER THAN this threshold.
     * If the MSB is clear, the value must be LESS THAN this threshold.
     */
} T1_csrnData_t;

/*----------------------------------------------------------------------------------*/
typedef struct {
    T1_taskIdx_t        idx;
    T1_uint8_t          instanceKey;
#ifdef T1_CPU32BIT
    T1_uint16_t         unused16;           /* Force alignment */
#endif /* T1_CPU32BIT */
    T1_resultTime_t     netAccumulation;    /* Accumulated net time for this task */
} T1_taskStackElem_t;

/*----------------------------------------------------------------------------------*/
/*--- external declarations for global variables -----------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined T1_ENABLE && !defined T1_DISABLE_T1_CONT

#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
#   if defined T1_CONT_SYS_TIME_DOWNCOUNTING
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
T1_DeclarePlugin( T1_contPluginStructDirectDC );
#       else /* original */
T1_DeclarePlugin( T1_contPluginStructOrigDC );
#       endif /* build variants */
#   else /* !defined T1_SYS_TIME_DOWNCOUNTING */
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
T1_DeclarePlugin( T1_contPluginStructDirect );
#       else /* original */
T1_DeclarePlugin( T1_contPluginStructOrig );
#       endif /* build variants */
#   endif /* defined T1_SYS_TIME_DOWNCOUNTING */
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"

#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN const T1_longTime_t T1_bgCallbackPeriod T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN const T1_longTime_t T1_bgCallbackPeriodPC[] T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"

/* const data */
#   define T1_START_SEC_CONST_8
#   include "T1_MemMap.h"
T1_EXTERN const T1_taskIdx_t        T1_bgTaskIdx T1_SEC_CONST_8;
T1_EXTERN const T1_taskIdx_t        T1_bgTaskIdxPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_cpuLoadThreshold T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_cpuLoadThresholdPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_avgCPULoadSamples T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_avgCPULoadSamplesPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_nofPreemptionsPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_uint8_t          T1_nofPreemptions T1_SEC_CONST_8;
T1_EXTERN const T1_taskIdx_t        T1_nofTasksPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_taskIdx_t        T1_nofTasks T1_SEC_CONST_8;
T1_EXTERN const T1_stpwIdx_t        T1_nofStpwsPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_stpwIdx_t        T1_nofStpws T1_SEC_CONST_8;
T1_EXTERN const T1_stpwIdx_t        T1_nofUserStpwsPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_stpwIdx_t        T1_nofUserStpws T1_SEC_CONST_8;
T1_EXTERN const T1_csrnIdx_t        T1_nofCsrnsPC[] T1_SEC_CONST_8;
T1_EXTERN const T1_csrnIdx_t        T1_nofCsrns T1_SEC_CONST_8;
T1_EXTERN T1_stpwConfig_t           T1_stpwConfig[] T1_SEC_CONST_8;
#   define T1_STOP_SEC_CONST_8
#   include "T1_MemMap.h"

#   define T1_START_SEC_CONST_16
#   include "T1_MemMap.h"
#   if ! defined T1_32BIT_TRACE_TIME
T1_EXTERN const T1_tick_t           T1_overhead T1_SEC_CONST_16;
T1_EXTERN const T1_tick_t           T1_flexOverhead T1_SEC_CONST_16;
#   endif /* defined T1_32BIT_TRACE_TIME */
#   define T1_STOP_SEC_CONST_16
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_16
#   include "T1_MemMap.h"
#   if ! defined T1_32BIT_TRACE_TIME
T1_EXTERN const T1_tick_t           T1_overheadPC[] T1_SEC_CONST_16;
T1_EXTERN const T1_tick_t           T1_flexOverheadPC[] T1_SEC_CONST_16;
#   endif /* defined T1_32BIT_TRACE_TIME */
T1_EXTERN const T1_uint16_t         T1_cpuLoadTxPeriod T1_SEC_CONST_16;
T1_EXTERN const T1_uint16_t         T1_startOfFrameEvent T1_SEC_CONST_16;
T1_EXTERN const T1_uint16_t         T1_startOfFrameEventPC[] T1_SEC_CONST_16;
T1_EXTERN const T1_uint16_t         T1_cpuLoadTxPeriodPC[] T1_SEC_CONST_16;
T1_EXTERN const T1_anaCapa_t        T1_defaultAnalysisCapacity T1_SEC_CONST_16;
T1_EXTERN const T1_anaCapa_t        T1_defaultAnalysisCapacityPC[] T1_SEC_CONST_16;
T1_EXTERN const T1_resultsIdx_t     T1_nofResultsPC[] T1_SEC_CONST_16;
T1_EXTERN const T1_resultsIdx_t     T1_nofResults T1_SEC_CONST_16;
#   define T1_STOP_SEC_CONST_16
#   include "T1_MemMap.h"

#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN const T1_csrnData_t       T1_csrnConfig[] T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN T1_stpwConfig_t   * const T1_stpwConfigPC[] T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN const T1_csrnData_t * const T1_csrnConfigPC[] T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN void             (* const T1_pCpuLoadCallback)( T1_uint16Least_t to, T1_uint16Least_t te ) T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN void             (* const T1_pCpuLoadCallbackPC[])( T1_uint16Least_t to, T1_uint16Least_t te ) T1_SEC_CONST_32;
#   ifdef T1_CONT_TASK_CONSTRAINTS
T1_EXTERN T1_taskData_t     * const T1_taskDataPC[] T1_SEC_CONST_32;
#   endif /* T1_CONT_TASK_CONSTRAINTS */
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN T1_stpwData_t     * const T1_stpwDataPC[] T1_SEC_CONST_32;
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"
#   define T1_START_SEC_CONST_32
#   include "T1_MemMap.h"
T1_EXTERN T1_csrnData_t     * const T1_csrnDataPC[] T1_SEC_CONST_32;
T1_EXTERN T1_resultTime_t   * const T1_resultBufferPC[] T1_SEC_CONST_32;
T1_EXTERN T1_taskStackElem_t* const T1_taskStackPC[] T1_SEC_CONST_32;
#   if defined T1_32BIT_TRACE_TIME
#       define T1_STOP_SEC_CONST_32
#       include "T1_MemMap.h"
#       define T1_START_SEC_CONST_32
#       include "T1_MemMap.h"
T1_EXTERN const T1_tick_t           T1_overhead T1_SEC_CONST_32;
T1_EXTERN const T1_tick_t           T1_flexOverhead T1_SEC_CONST_32;
#       define T1_STOP_SEC_CONST_32
#       include "T1_MemMap.h"
#       define T1_START_SEC_CONST_32
#       include "T1_MemMap.h"
T1_EXTERN const T1_tick_t           T1_overheadPC[] T1_SEC_CONST_32;
T1_EXTERN const T1_tick_t           T1_flexOverheadPC[] T1_SEC_CONST_32;
#   endif /* defined T1_32BIT_TRACE_TIME */
#   define T1_STOP_SEC_CONST_32
#   include "T1_MemMap.h"

/* Public for debugger interface */
#   define T1_START_SEC_NO_INIT_8
#   include "T1_MemMap.h"
T1_EXTERN T1_contStatus_t          T1_contBgStatusPC[] T1_SEC_NO_INIT_32;
T1_EXTERN T1_contStatus_t          T1_contHandlerStatusPC[] T1_SEC_NO_INIT_32;
#   define T1_STOP_SEC_NO_INIT_8
#   include "T1_MemMap.h"

#   ifdef T1_MULTICORE_CLONE
#       define T1_START_SEC_NO_INIT_8_CLONE
#       include "T1_MemMap.h"
T1_EXTERN T1_contStatus_t          T1_contBgStatus T1_SEC_NO_INIT_32_CLONE;
T1_EXTERN T1_contStatus_t          T1_contHandlerStatus T1_SEC_NO_INIT_32_CLONE;
#       define T1_STOP_SEC_NO_INIT_8_CLONE
#       include "T1_MemMap.h"
#   else /* !T1_MULTICORE_CLONE */
#       define T1_START_SEC_NO_INIT_8
#       include "T1_MemMap.h"
T1_EXTERN T1_contStatus_t          T1_contBgStatus T1_SEC_NO_INIT_32;
T1_EXTERN T1_contStatus_t          T1_contHandlerStatus T1_SEC_NO_INIT_32;
#       define T1_STOP_SEC_NO_INIT_8
#       include "T1_MemMap.h"
#   endif /* T1_MULTICORE_CLONE */

#   define T1_START_SEC_NO_INIT_32
#   include "T1_MemMap.h"
#   ifdef T1_CONT_TASK_CONSTRAINTS
T1_EXTERN T1_taskData_t             T1_taskData[] T1_SEC_NO_INIT_32;
#   endif /* T1_CONT_TASK_CONSTRAINTS */
T1_EXTERN T1_stpwData_t             T1_stpwData[] T1_SEC_NO_INIT_32;
T1_EXTERN T1_csrnData_t             T1_csrnData[] T1_SEC_NO_INIT_32;
T1_EXTERN T1_resultTime_t           T1_resultBuffer[] T1_SEC_NO_INIT_32;
T1_EXTERN T1_taskStackElem_t        T1_taskStack[] T1_SEC_NO_INIT_32;
#   define T1_STOP_SEC_NO_INIT_32
#   include "T1_MemMap.h"

#endif /* defined T1_ENABLE && !defined T1_DISABLE_T1_CONT */

/*----------------------------------------------------------------------------------*/
/*--- forward declarations for global functions ------------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined T1_ENABLE && !defined T1_DISABLE_T1_CONT

#   define T1_START_SEC_CODE
#   include "T1_MemMap.h"

#   if defined T1_CONT_SYS_TIME_DOWNCOUNTING
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
#           if defined T1_NOF_CORES
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerDirectDCPC( T1_uint8Least_t coreId );
T1_EXTERN void T1_CODE T1_ContResetDirectDCPC( T1_uint8Least_t coreId, T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsDirectDCPC( T1_uint8Least_t coreId );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainDirectDCPC
                                            (   T1_uint8Least_t coreId,
                                                T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainDirectDCPC( T1_uint8Least_t coreId, T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandlerPC( coreId_ ) T1_ContBgHandlerDirectDCPC( coreId_ )
#               define T1_ContResetPC( coreId_ ) T1_ContResetDirectDCPC( coreId_, T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskIdPC( coreId_, bgTaskId_ ) T1_ContResetDirectDCPC( coreId_, bgTaskId_ )
#               define T1_ContResetResultsPC( coreId_ ) T1_ContResetResultsDirectDCPC( coreId_ )
#               define T1_ConfigEventChainPC( coreId_, e1_, e2_, swIdx_ ) T1_ConfigEventChainDirectDCPC( coreId_, e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChainPC( coreId_, swIdx_ ) T1_DeleteCalibrationEventChainDirectDCPC( coreId_, swIdx_ )
#           else /* single core */
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerDirectDC( void );
T1_EXTERN void T1_CODE T1_ContResetDirectDC( T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsDirectDC( void );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainDirectDC
                                            (   T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainDirectDC( T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandler( ) T1_ContBgHandlerDirectDC( )
#               define T1_ContReset( ) T1_ContResetDirectDC( T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskId( bgTaskId_ ) T1_ContResetDirectDC( bgTaskId_ )
#               define T1_ContResetResults( ) T1_ContResetResultsDirectDC( )
#               define T1_ConfigEventChain( e1_, e2_, swIdx_ ) T1_ConfigEventChainDirectDC( e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChain( swIdx_ ) T1_DeleteCalibrationEventChainDirectDC( swIdx_ )
#           endif /* T1_NOF_CORES */
#       else /* original */
#           if defined T1_NOF_CORES
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerOrigDCPC( T1_uint8Least_t coreId );
T1_EXTERN void T1_CODE T1_ContResetOrigDCPC( T1_uint8Least_t coreId, T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsOrigDCPC( T1_uint8Least_t coreId );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainOrigDCPC
                                            (   T1_uint8Least_t coreId,
                                                T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainOrigDCPC( T1_uint8Least_t coreId, T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandlerPC( coreId_ ) T1_ContBgHandlerOrigDCPC( coreId_ )
#               define T1_ContResetPC( coreId_ ) T1_ContResetOrigDCPC( coreId_, T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskIdPC( coreId_, bgTaskId_ ) T1_ContResetOrigDCPC( coreId_, bgTaskId_ )
#               define T1_ContResetResultsPC( coreId_ ) T1_ContResetResultsOrigDCPC( coreId_ )
#               define T1_ConfigEventChainPC( coreId_, e1_, e2_, swIdx_ ) T1_ConfigEventChainOrigDCPC( coreId_, e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChainPC( coreId_, swIdx_ ) T1_DeleteCalibrationEventChainOrigDCPC( coreId_, swIdx_ )
T1_EXTERN T1_taskIdx_t T1_CODE T1_GetTaskIdxByIdPC( T1_uint8Least_t coreId, T1_uint16Least_t taskId );
T1_EXTERN T1_uint16Least_t T1_CODE T1_GetTaskIdByIdxPC( T1_uint8Least_t coreId, T1_taskIdx_t taskIdx );
#           else /* single core */
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerOrigDC( void );
T1_EXTERN void T1_CODE T1_ContResetOrigDC( T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsOrigDC( void );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainOrigDC
                                            (   T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainOrigDC( T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandler( ) T1_ContBgHandlerOrigDC( )
#               define T1_ContReset( ) T1_ContResetOrigDC( T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskId( bgTaskId_ ) T1_ContResetOrigDC( bgTaskId_ )
#               define T1_ContResetResults( ) T1_ContResetResultsOrigDC( )
#               define T1_ConfigEventChain( e1_, e2_, swIdx_ ) T1_ConfigEventChainOrigDC( e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChain( swIdx_ ) T1_DeleteCalibrationEventChainOrigDC( swIdx_ )
T1_EXTERN T1_taskIdx_t T1_CODE T1_GetTaskIdxById( T1_uint16Least_t taskId );
T1_EXTERN T1_uint16Least_t T1_CODE T1_GetTaskIdByIdx( T1_taskIdx_t taskIdx );
#           endif /* T1_NOF_CORES */
#       endif /* build variants */
#   else /* !defined T1_CONT_SYS_TIME_DOWNCOUNTING */
#       if defined T1_CONT_DIRECT_ID_MAPPINGS
#           if defined T1_NOF_CORES
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerDirectPC( T1_uint8Least_t coreId );
T1_EXTERN void T1_CODE T1_ContResetDirectPC( T1_uint8Least_t coreId, T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsDirectPC( T1_uint8Least_t coreId );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainDirectPC
                                            (   T1_uint8Least_t coreId,
                                                T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainDirectPC( T1_uint8Least_t coreId, T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandlerPC( coreId_ ) T1_ContBgHandlerDirectPC( coreId_ )
#               define T1_ContResetPC( coreId_ ) T1_ContResetDirectPC( coreId_, T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskIdPC( coreId_, bgTaskId_ ) T1_ContResetDirectPC( coreId_, bgTaskId_ )
#               define T1_ContResetResultsPC( coreId_ ) T1_ContResetResultsDirectPC( coreId_ )
#               define T1_ConfigEventChainPC( coreId_, e1_, e2_, swIdx_ ) T1_ConfigEventChainDirectPC( coreId_, e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChainPC( coreId_, swIdx_ ) T1_DeleteCalibrationEventChainDirectPC( coreId_, swIdx_ )
#           else /* single core */
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerDirect( void );
T1_EXTERN void T1_CODE T1_ContResetDirect( T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsDirect( void );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainDirect
                                            (   T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainDirect( T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandler( ) T1_ContBgHandlerDirect( )
#               define T1_ContReset( ) T1_ContResetDirect( T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskId( bgTaskId_ ) T1_ContResetDirect( bgTaskId_ )
#               define T1_ContResetResults( ) T1_ContResetResultsDirect( )
#               define T1_ConfigEventChain( e1_, e2_, swIdx_ ) T1_ConfigEventChainDirect( e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChain( swIdx_ ) T1_DeleteCalibrationEventChainDirect( swIdx_ )
#           endif /* T1_NOF_CORES */
#       else /* original */
#           if defined T1_NOF_CORES
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerOrigPC( T1_uint8Least_t coreId );
T1_EXTERN void T1_CODE T1_ContResetOrigPC( T1_uint8Least_t coreId, T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsOrigPC( T1_uint8Least_t coreId );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainOrigPC
                                            (   T1_uint8Least_t coreId,
                                                T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainOrigPC( T1_uint8Least_t coreId, T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandlerPC( coreId_ ) T1_ContBgHandlerOrigPC( coreId_ )
#               define T1_ContResetPC( coreId_ ) T1_ContResetOrigPC( coreId_, T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskIdPC( coreId_, bgTaskId_ ) T1_ContResetOrigPC( coreId_, bgTaskId_ )
#               define T1_ContResetResultsPC( coreId_ ) T1_ContResetResultsOrigPC( coreId_ )
#               define T1_ConfigEventChainPC( coreId_, e1_, e2_, swIdx_ ) T1_ConfigEventChainOrigPC( coreId_, e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChainPC( coreId_, swIdx_ ) T1_DeleteCalibrationEventChainOrigPC( coreId_, swIdx_ )
T1_EXTERN T1_taskIdx_t T1_CODE T1_GetTaskIdxByIdPC( T1_uint8Least_t coreId, T1_uint16Least_t taskId );
T1_EXTERN T1_uint16Least_t T1_CODE T1_GetTaskIdByIdxPC( T1_uint8Least_t coreId, T1_taskIdx_t taskIdx );
#           else /* single core */
T1_EXTERN T1_status_t T1_CODE T1_ContBgHandlerOrig( void );
T1_EXTERN void T1_CODE T1_ContResetOrig( T1_uint16Least_t bgTaskId );
T1_EXTERN void T1_CODE T1_ContResetResultsOrig( void );
T1_EXTERN T1_status_t T1_CODE T1_ConfigEventChainOrig
                                            (   T1_uint16_t startEventInfo,
                                                T1_uint16_t stopEventInfo,
                                                T1_stpwIdx_t stpwIdx        );
T1_EXTERN void T1_CODE T1_DeleteCalibrationEventChainOrig( T1_stpwIdx_t stpwIdx );
#               define T1_ContBgHandler( ) T1_ContBgHandlerOrig( )
#               define T1_ContReset( ) T1_ContResetOrig( T1_INVALID_TASK_IDX )
#               define T1_ContResetBgTaskId( bgTaskId_ ) T1_ContResetOrig( bgTaskId_ )
#               define T1_ContResetResults( ) T1_ContResetResultsOrig( )
#               define T1_ConfigEventChain( e1_, e2_, swIdx_ ) T1_ConfigEventChainOrig( e1_, e2_, swIdx_ )
#               define T1_DeleteCalibrationEventChain( swIdx_ ) T1_DeleteCalibrationEventChainOrig( swIdx_ )
T1_EXTERN T1_taskIdx_t T1_CODE T1_GetTaskIdxById( T1_uint16Least_t taskId );
T1_EXTERN T1_uint16Least_t T1_CODE T1_GetTaskIdByIdx( T1_taskIdx_t taskIdx );
#           endif /* T1_NOF_CORES */
#       endif /* build variants */
#   endif /* defined T1_CONT_SYS_TIME_DOWNCOUNTING */

#if defined T1_NOF_CORES
#   define T1_ContBgHandler( ) T1_ContBgHandlerPC( T1_GetCoreIdOffset( ) )
#   define T1_ContReset( ) T1_ContResetPC( T1_GetCoreIdOffset( ) )
#   define T1_ContResetBgTaskId( bgTaskId_ ) T1_ContResetBgTaskIdPC( T1_GetCoreIdOffset( ), bgTaskId_ )
#   define T1_ContResetResults( coreId_ ) T1_ContResetResultsPC( T1_GetCoreIdOffset( ) )
#   define T1_ConfigEventChain( e1_, e2_, swIdx_ ) T1_ConfigEventChainPC( T1_GetCoreIdOffset( ), e1_, e2_, swIdx_ )
#   define T1_ContDisableAnalysis( ) T1_ContDisableAnalysisPC( T1_GetCoreIdOffset( ) )
T1_EXTERN void T1_CODE T1_ContDisableAnalysisPC( T1_uint8Least_t coreId );
T1_EXTERN void T1_CODE T1_ContErrCallbackPC( T1_uint8Least_t coreId, T1_uint8Least_t errMask );
T1_EXTERN void T1_CODE T1_ContCsrnCallbackPC( T1_uint8Least_t coreId, T1_resultTime_t result, T1_csrnIdx_t idx );
T1_EXTERN void T1_CODE T1_ContOHCallbackPC( T1_uint8Least_t coreId, T1_uint8Least_t errMask );
T1_EXTERN T1_resultTime_t T1_CODE T1_ContStartStopCETPC( T1_uint8Least_t coreId, T1_taskIdx_t taskIdx );
#else /* single core */
T1_EXTERN void T1_CODE T1_ContDisableAnalysis( void );
T1_EXTERN void T1_CODE T1_ContErrCallback( T1_uint8Least_t errMask );
T1_EXTERN void T1_CODE T1_ContCsrnCallback( T1_resultTime_t result, T1_csrnIdx_t idx );
T1_EXTERN void T1_CODE T1_ContOHCallback( T1_uint8Least_t errMask );
T1_EXTERN T1_resultTime_t T1_CODE T1_ContStartStopCET( T1_taskIdx_t taskIdx );
#endif /* defined T1_NOF_CORES */

T1_EXTERN void T1_CODE T1_TaskCETCallback( T1_taskIdx_t taskIdx, T1_resultTime_t taskCET );
T1_EXTERN void T1_CODE T1_PeriodicBgCallback( T1_longTime_t now );

#   define T1_STOP_SEC_CODE
#   include "T1_MemMap.h"

#else /* ! defined T1_ENABLE || defined T1_DISABLE_T1_CONT */

#   if defined T1_NOF_CORES
#       define T1_ContBgHandlerPC( coreId_ )                        (T1_NOFUNC)
#       define T1_ContResetPC( coreId_ )                            ((void)0)
#       define T1_ContResetBgTaskIdPC( coreId_, bgTaskId_ )         ((void)0)
#       define T1_ContResetResultsPC( coreId_ )                     ((void)0)
#       define T1_ContDisableAnalysisPC( coreId_ )                  ((void)0)
#       define T1_ConfigEventChainPC( coreId_, e1_, e2_, swIdx_ )   (T1_NOFUNC)
#   endif /* T1_NOF_CORES */
#   define T1_ContBgHandler( )                                      (T1_NOFUNC)
#   define T1_ContReset( )                                          ((void)0)
#   define T1_ContResetBgTaskId( bgTaskId_ )                        ((void)0)
#   define T1_ContResetResults( )                                   ((void)0)
#   define T1_ContDisableAnalysis( )                                ((void)0)
#   define T1_ConfigEventChain( e1_, e2_, swIdx_ )                  (T1_NOFUNC)

#endif /* defined T1_ENABLE && !defined T1_DISABLE_T1_CONT */

#endif /* T1_CONT_INTERFACE_H_ */
