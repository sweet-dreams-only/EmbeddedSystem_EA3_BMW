/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2006-2009 by Vctr Informatik GmbH, all rights reserved
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EcuM.c
 *    Component:  SysService_AsrEcuM
 *       Module:  EcuM
 *    Generator:  -
 *
 *  Description:  The ECU State Manager is responsible for
 *                  - initialization of the entire BSW Modules (including OS and RTE
 *                  - configuration of the entire ECU for sleep mode
 *                  - fast and systematic wakeup behavior
 *                  - shutdown of the ECU
 *
 *                To be very independent of different system designs e.g. different Modules to initialize,
 *                external/internal Watchdog, etc., the ECU State Manager provides over a mechanism named "callouts"
 *                a way to adapt the startup and shutdown behavior. The system designer must fill the proper code into
 *                the callouts.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Christian Marchl              Chm           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  03.00.01  2007-09-17  Chm     ESCAN00022372 Quality assurance activities necessary for Component
 *                                              SysService_EcuM
 *  03.00.02  2007-12-05  Chm     ESCAN00023500 Corrected the range checking of the channel passed to service
 *                                              EcuM_ComM_HasRequestedRUN()
 *                                ESCAN00023529 Added the same handling to the last shutdown target as the
 *                                              it is done with the default application mode.
 *                                ESCAN00022623 Implemented EcuM_GetStateWrapper() as function
 *                                -             rework of code review issues
 *  04.00.00  2008-03-03  Chm     ESCAN00022498 rework of wakeup validation mechanism
 *                                -             Implementation of AUTOSAR 3.0 features.
 *  04.00.01  2008-04-17  Chm     ESCAN00026230 Added sip delivery check
 *                                -             Added EcuM_GetStateWrapper()
 *                                -             Removed uninit check from EcuM_GetVersionInfo()
 *                                ESCAN00026333 Removed compiler errors
 *  04.01.00  2008-05-15  Chm     -             No changes here
 *  04.01.01  2008-06-06  Chm     ESCAN00027458 Used compiler abstraction for type cast
 *  04.01.02  2008-06-16  Chm     -             Removed check of Std_Types.h versions, because of incompatibilities
 *                                              with AUTOSAR 2.1 drivers.
 *  04.02.00  2008-06-26  Chm     ESCAN00027917 Changed behavior of EcuM_ActPerformWakeSleepOp()
 *                                ESCAN00027637 Added generator library check
 *                                ESCAN00026668 Extension for MSR3.0 generator version checks
 *  04.03.00  2008-07-15  Chm     ESCAN00028254 Changed correct return value of  EcuM_GetShutdownTarget()
 *                                ESCAN00028366 Added support for customized ComM according to ASR 2.1
 *  04.03.01  2008-09-24  Chm     ESCAN00030196 Added support for EcuM_GetState() API according to ASR 2.1
 *                                ESCAN00029718 Added preprocessor switch for CANOE
 *  04.04.00  2008-10-22  Chm     ESCAN00030470 Added PreCompile Variant support
 *  05.00.00  2008-11-28  Chm     ESCAN00031236 Added EcuM_PrivateCfg.h include
 *                                ESCAN00030956 Added mode management support
 *                                ESCAN00030909 Added boottarget selection through callouts
 *                                ESCAN00030031 Added transition from startup to wakeup validation state
 *                                ESCAN00029870 Added preprocessor switch V_USE_DUMMY_STATEMENT
 *  05.00.01  2009-02-18  Chm     ESCAN00031908 No changes here
 *            2009-02-19  Chm     ESCAN00032309 Fixed typing
 *            2009-02-23  Chm     ESCAN00030139 No changes here
 *            2009-02-25  Chm     ESCAN00031790 Add ECUM_WKSOURCE_ALL_SOURCES as parameter of EcuM_EnableWakeupSources() if shutdown target is ECUM_STATE_OFF
 *            2009-03-10  Chm     ESCAN00033728 Add support for CANoeEmu integration testsuite
 *            2009-03-16  Chm     ESCAN00033852 Add POLYSPACE support
 *  05.01.00  2009-05-15  Chm     ESCAN00035148 Add support for vendor specific parameter to support multiple identity ECUs support
 *  05.02.00  2009-07-14  Chm     ESCAN00035006 EcuM_GetState() reports the wrong ECUM state in ECUM_STATE_GO_OFF_TWO
 *            2009-07-14  Chm     ESCAN00035914 API EcuM_KillAllRUNRequests() does not perform an RESET if a communication channel is active.
 *            2009-07-15  Chm     ESCAN00035987 Mode switch notification ECUM_MODE_SLEEP occurs two times instead of once
 *            2009-07-15  Chm     ESCAN00034791 Correct behavior of Requesting/Releasing RUN shall always be ensured.
 *            2009-07-15  Chm     ESCAN00034696 No changes here
 *            2009-07-15  Chm     ESCAN00036111 pre-processor checks for building the library
 *            2009-07-17  Chm     ESCAN00036325 MainFunction shall be preemptive
 *            2009-07-21  Chm     ESCAN00036576 Change compiler abstraction keyword from AUTOMATIC to TYPEDEF
 *  05.02.01  2009-11-24  Chm     ESCAN00039346 EcuM might not leave RUN state if run request is executed preemptive with the same user id.
 *  05.02.02  2009-12-11  Chm     ESCAN00039057 Added PRQA misra justifications.
 *            2009-12-11  Chm     ESCAN00039414 Justified or resolved misra violations.
 *            2009-12-15  Chm     ESCAN00039778 No changes here
 *  05.02.03  2010-04-14  Chm     ESCAN00042313 No changes here
 *            2010-04-24  Chm     ESCAN00041361 Removed Compiler warnings
 *            2010-04-24  Chm     ESCAN00042504 Added EcuM_PreMcuSetModeHook() and EcuM_PostMcuSetModeHook()
 *  05.02.04  2010-07-29  Bmz     ESCAN00043949 EcuM_DisableWakupSources added in EcuM_ActEnterRunState in case
 *                                              a vaid wakeup exists and EcuM was in POST_RUN before
 *  05.02.05  2010-09-21  Bmz     ESCAN00045256 Add call of Mcu_PerformReset() after calling EcuM_AL_SwitchOff()
 *                                              also for the case that no DET is enabled
 *  05.03.00  2010-10-18  Bmz     ESCAN00044913 EcuM_PreMcuSetModeHook and EcuM_PostMcuSetModeHook replaced by a callout
 *  05.05.00  2010-11-12  Bmz     ESCAN00045114 Add a new transition for ECUM_INT_STATE_WAKEUP_REACTION
 *            2010-11-18  Bmz     ESCAN00046994 modified the state transitions for SLEEP state
 *            2010-11-24  Bmz     ESCAN00046158 added wait mechanism for Rte mode switch notification
 *  05.05.01  2011-02-15  Bmz     ESCAN00048574 add a check before RTE nofication is done to prevent RTE queue overflows
 *  05.06.00  2011-04-06  Bmz     ESCAN00048423 add DEM usage during Wake-Up validation with power control in STARTUP period
 *                                ESCAN00049111 version check updated fpr cfg files
 *  05.06.01  2011-04-26  Bmz     ESCAN00052144 EcuM_MainFunction is NOT left until the NvmCancelWriteAllTimeout_u32 is not expired
 *********************************************************************************************************************/
#define ECUM
#define ECUM_C

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
#include "EcuM.h"
#include "EcuM_Cbk.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MISRA-C:2004 Rule 19.6: The #undef keyword is required to verify that the header file EcuM_PrivateCfg.h is only included in the expected sources. */

#if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
# include "v_ver.h"
#endif /* V_SUPPRESS_EXTENDED_VERSION_CHECK */


/*********************************************************************************************************************
    VERSION CHECK
 *********************************************************************************************************************/
#if ((ECUM_SW_MAJOR_VERSION != (5u))   \
    || (ECUM_SW_MINOR_VERSION != (6u)) \
    || (ECUM_AR_MAJOR_VERSION != (1u)) \
    || (ECUM_AR_MINOR_VERSION != (2u)))
# error "Version numbers of EcuM.c and EcuM.h are inconsistent!"
#endif

#if (ECUM_CFG_MAJOR_VERSION != (5u))
# error "Incompatible ECUM_CFG_MAJOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_CFG_MINOR_VERSION != (7u))
# error "Incompatible ECUM_CFG_MINOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_GENERATED_TYPES_MAJOR_VERSION != (5u))
# error "Incompatible ECUM_GENERATED_TYPES_MAJOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_GENERATED_TYPES_MINOR_VERSION != (7u))
# error "Incompatible ECUM_GENERATED_TYPES_MINOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_CBK_MAJOR_VERSION != (5u))
# error "Incompatible ECUM_CBK_MAJOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_CBK_MINOR_VERSION != (7u))
# error "Incompatible ECUM_CBK_MINOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_PRIVATE_CFG_MAJOR_VERSION != (5u))
# error "Incompatible ECUM_PRIVATE_CFG_MAJOR_VERSION with this EcuM Implementation!"
#endif

#if (ECUM_PRIVATE_CFG_MINOR_VERSION != (7u))
# error "Incompatible ECUM_PRIVATE_CFG_MINOR_VERSION with this EcuM Implementation!"
#endif

#if !defined (V_USE_DUMMY_STATEMENT)
# error "The define V_USE_DUMMY_STATEMENT shall be defined either in Compiler_Cfg.h or as parameter for the Compiler"
#endif

#if defined (V_EXTENDED_BUILD_LIB_CHECK)
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
#  error "Consistency check in EcuM.c failed! You can not use EcuM Variant #1 PRE-COMPILE for building a library."
# endif
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Bitmasks for Flagvariable */
#define ECUM_FLAG_KILLALL_IN_PROGRESS                                 (0x02u)

/* MAGIC Numbers to determine whether the restart was intended or not */
#define ECUM_MAGIC_ONE                                                (0x5Au)
#define ECUM_MAGIC_TWO                                                (0xA5u)

/* Defines for organization of the state machine */
#define ECUM_NO_OF_QRY_AND                                            (2u)
#define ECUM_NO_OF_STATE_CONDITIONS                                   (3u)

/* EcuM User number for self run request */
#define ECUM_OWN_USER_NUMBER                                          (0u)

/* indicates that no timeout is active */
#define ECUM_NO_TIMEOUT_SET                                           (0xFFFFu)

/* Invalid Index of an wakeup source */
#define ECUM_INVALID_WKSOURCE_INDEX                                   (255u)

/* Defines for RUN/POST RUN request handling  */
#define ECUM_COMM_CH_REQUEST_RUN_MASK                                 (0x80u)
#define ECUM_USER_REQUEST_RUN_MASK                                    (0x01u)
#define ECUM_USER_REQUEST_POST_RUN_MASK                               (0x02u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* Calling Macros to avoid "unreferenced parameter" compiler error, if compiled without DEV_ERROR_DETECT */
#if ((STD_ON == ECUM_CHECK_UNINIT) || (STD_ON == ECUM_CHECK_USER_PARAMETER))
# define ECUM_FUNC_CALL_REQUEST_RUN(ApiId, User, mask)                (EcuM_InternalRequestRUN((ApiId),(User),(mask))) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
# define ECUM_FUNC_CALL_RELEASE_RUN(ApiId, User, mask)                (EcuM_InternalReleaseRUN((ApiId),(User),(mask))) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
#else
# define ECUM_FUNC_CALL_REQUEST_RUN(ApiId, User, mask)                (EcuM_InternalRequestRUN((User),(mask))) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
# define ECUM_FUNC_CALL_RELEASE_RUN(ApiId, User, mask)                (EcuM_InternalReleaseRUN((User),(mask))) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
#endif

/*********************************************************************************************************************
    INTERNAL TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type which describes the internal state of the EcuM_MainFunction()*/
typedef enum
{
   ECUM_INT_STATE_RUN
  ,ECUM_INT_STATE_POST_RUN
  ,ECUM_INT_STATE_PREP_SHUTDOWN
  ,ECUM_INT_STATE_GO_OFF_ONE

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_INT_STATE_GO_SLEEP
#endif

  ,ECUM_INT_STATE_FORCE_RESET

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_INT_STATE_SLEEP
#endif
  ,ECUM_INT_STATE_WAKEUP_WITH_POWERCTRL_VALIDATION
  ,ECUM_INT_STATE_WAKEUP_VALIDATION

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
    /* will be set before calling ShutdownOS */
    ,ECUM_INT_STATE_ERROR
#endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/

  ,ECUM_INT_STATE_WAKEUP_REACTION
} EcuM_InternalStateIdType;

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
  typedef EcuM_InternalStateIdType EcuM_InternalStateType;
#else
  typedef uint8 EcuM_InternalStateType;
#endif

/* Enumeration of Query IDs */
typedef enum
{
  ECUM_QRY_ID_RUN_REQUESTED,
  ECUM_QRY_ID_PENDING_WAKEUP,
  ECUM_QRY_ID_POST_RUN_REQUESTED,
  ECUM_QRY_ID_IS_SHTDNTRGT_SLEEP,

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    ECUM_QRY_ID_NVM_PENDING,
    ECUM_QRY_ID_IS_NVM_WRITE_ALL_RUNNING,
    ECUM_QRY_ID_IS_NVM_OR_WKUP_PENDING,
#endif

  ECUM_QRY_ID_NEW_VALID_WAKEUP,
  ECUM_QRY_ID_IS_WKACT_RUN,
  ECUM_QRY_ID_RTEWAITONFEEDBACK,
  ECUM_QRY_ID_RUN_REQUEST_OR_NEW_VALID_WAKEUP,
  ECUM_QRY_ID_TRUE,
  ECUM_QRY_ID_IS_SHTDNTRGT_OFF
} EcuM_StateQueryIdType;

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
  typedef EcuM_StateQueryIdType EcuM_StateQueryType;
#else
  typedef uint8 EcuM_StateQueryType;
#endif

/* Enumeration of Action handler IDs */
typedef enum
{
   ECUM_ACT_ID_ENTER_RUN_STATE
  ,ECUM_ACT_ID_EXIT_RUN_STATE
  ,ECUM_ACT_ID_EXIT_POST_RUN_STATE

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_ACT_ID_GO_TO_SLEEP
#endif

  ,ECUM_ACT_ID_PERFORM_PREP_SHUTDOWN

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_ACT_ID_ENTER_GO_SLEEP
#endif

  ,ECUM_ACT_ID_ENTER_GO_OFF_ONE
  ,ECUM_ACT_ID_SHUTDOWN_SYSTEM

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_ACT_ID_PERFORM_WAKEUP_ONE
#endif

  ,ECUM_ACT_ID_PERFORM_WAKEUP_ONE_2

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_ACT_ID_CANCEL_SLEEP_PROCESS
#endif
  ,ECUM_ACT_ID_PERFORM_WAKEUP_REACTION_FROM_STARTUP
  ,ECUM_ACT_ID_PERFORM_WAKEUP_REACTION
  ,ECUM_ACT_ID_WAIT_ON_NVMCANCELWRITEALL
  ,ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP
  ,ECUM_ACT_ID_PERFORM_WAKEUP_TWO
  ,ECUM_ACT_ID_NOP_WITH_EXIT

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,ECUM_ACT_ID_ENTER_SLEEP_STATE
#endif

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
    ,ECUM_ACT_ID_ECUM_ERROR
#endif
}EcuM_StateActionIdType;

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
  typedef EcuM_StateActionIdType EcuM_StateActionType;
#else
  typedef uint8 EcuM_StateActionType;
#endif

/* Type for Action functions */
typedef P2FUNC (void, ECUM_CODE, EcuM_StateChangeActionType)(void);
/* Type for Query functions */
typedef P2FUNC (boolean, ECUM_CODE, EcuM_StateQueryFuncType)(void);

/* pointer to query table */
typedef CONSTP2CONST(EcuM_StateQueryType, TYPEDEF, ECUM_CONST) EcuM_StateQueryPtrType;

typedef struct
{
  EcuM_StateQueryType       Queries_at[ECUM_NO_OF_QRY_AND];
  EcuM_StateActionType      Action_t;
  EcuM_InternalStateType    NextState_t;
} EcuM_StateChangeIfDescrType;

typedef struct
{
  EcuM_StateActionType        Action_t;
  EcuM_InternalStateType      NextState_t;
} EcuM_StateChangeElseDescrType;

/* describe a state with it's possible change conditions */
typedef struct
{
  EcuM_StateChangeIfDescrType   ChangeConditions_at[ECUM_NO_OF_STATE_CONDITIONS];
  EcuM_StateChangeElseDescrType FinalCondition_t;
} EcuM_StateDescrType;

/*********************************************************************************************************************
    INTERNAL FUNCTION DECLARATION
 *********************************************************************************************************************/
/*************** QUERY FUNCTION FORWARD DECLARATION ******************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRunRequested(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryPendingWakeup(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryPostRunRequested(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsShutdownTargetSleep(void);
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryNvmPending(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsNvMWriteAllRunning(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsNvMOrWkUpPending(void);
#endif
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryNewValidWakeup(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsWKACTRun(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRteWaitOnFeedback(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRunRequestedOrNewValidWakeup(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryTrue(void);
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsShutdownTargetOff(void);

/* *************** ACTION FUNCTION FORWARD DECLARATION ***************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterRunState(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActExitRunState(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActExitPostRunState(void);

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  STATIC FUNC(void, ECUM_CODE) EcuM_ActGoToSleep(void);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_ActShutdownSystem(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformPrepShutdown(void);

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterGoSleep(void);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterGoOffOne(void);

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupOne(void);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupOne2(void);

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  STATIC FUNC(void, ECUM_CODE) EcuM_ActCancelSleepProcess(void);
#endif
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupReactionFromStartup(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupReaction(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeSleepOp(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupTwo(void);
STATIC FUNC(void, ECUM_CODE) EcuM_ActNopWithExit(void);

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterSleepState(void);
#endif

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
STATIC FUNC(void, ECUM_CODE) EcuM_ActEcuMError(void);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_ActWaitOnNvMCancelWriteAll(void);

/* *************** FUNCTIONS FOR MAINE STATEMACHINE ******************************************************************/
STATIC FUNC(EcuM_InternalStateType, ECUM_CODE) EcuM_Fsm(EcuM_InternalStateType InternalState_t);
STATIC FUNC(boolean, ECUM_CODE) EcuM_FsmQuery(EcuM_StateQueryPtrType EcuM_Query_at);

/* *************** SOME HELPER FUNCTIONS *****************************************************************************/
STATIC FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount_u8(EcuM_WakeupSourceType x);
#if (STD_ON == ECUM_GET_STATUS_OF_WAKEUP_SOURCE_API)
STATIC FUNC(EcuM_WakeupStatusType, ECUM_CODE) EcuM_GetSumStatusOfWakeupSource(void);
#endif /*(STD_ON == ECUM_GET_STATUS_OF_WAKEUP_SOURCE_API)*/

#if ((STD_ON == ECUM_CHECK_UNINIT) || (STD_ON == ECUM_CHECK_USER_PARAMETER))
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(uint8 ApiId, EcuM_UserType User_t, uint8 mask_u8);
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(uint8 ApiId, EcuM_UserType User_t, uint8 mask_u8);
#else
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(EcuM_UserType User_t, uint8 mask_u8);
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(EcuM_UserType User_t, uint8 mask_u8);
#endif

/* Function for run request timeout handling */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_IsKillAllInProgress(void);

/* Function which notifies the mode switch event */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
STATIC FUNC(void, ECUM_CODE)EcuM_NotifyModeSwitch(uint8 modeEvent_u8);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_InternalClearWakeupEvents(EcuM_WakeupSourceType wakeupSource);
STATIC FUNC(void, ECUM_CODE) EcuM_InternalDisableWakeupSources(void);

/* *************** PARAMETER CHECK FUNCTIONS  ************************************************************************/
#if (STD_ON == ECUM_CHECK_USER_PARAMETER)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckUserParameter(uint8 ApiId, EcuM_UserType user, uint8 mask);
#endif

#if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckWKSourceParameter(uint8 ApiId, EcuM_WakeupSourceType sources);
#endif

#if (STD_ON == ECUM_CHECK_UNINIT)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckInitStartupTwo(uint8 ApiId);
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckInit(uint8 ApiId);
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

/* *************** CONSTANTS FOR STATE MACHINE ***********************************************************************/
/* Table which stores the function pointer of the Action functions */
#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

#if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)

CONST(uint32, ECUM_CONST) SYSSERVICE_ASRECUM_LIB_SYMBOL = (uint32)SYSSERVICE_ASRECUM_LIB_VERSION;

#endif /* V_SUPPRESS_EXTENDED_VERSION_CHECK */

STATIC CONST(EcuM_StateChangeActionType, ECUM_CONST) EcuM_ActionTable_ap[] = /* PRQA S 3218 *//* MISRA-C:2004 Rule 8.7: In exceptional cases deviations are possible if an efficient implementation with local variables is not possible. */
{
  EcuM_ActEnterRunState
  ,EcuM_ActExitRunState
  ,EcuM_ActExitPostRunState

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,EcuM_ActGoToSleep
#endif

  ,EcuM_ActPerformPrepShutdown

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,EcuM_ActEnterGoSleep
#endif

  ,EcuM_ActEnterGoOffOne
  ,EcuM_ActShutdownSystem

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,EcuM_ActPerformWakeupOne
#endif

  ,EcuM_ActPerformWakeupOne2

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,EcuM_ActCancelSleepProcess
#endif
  ,EcuM_ActPerformWakeupReactionFromStartup
  ,EcuM_ActPerformWakeupReaction
  ,EcuM_ActWaitOnNvMCancelWriteAll
  ,EcuM_ActPerformWakeSleepOp
  ,EcuM_ActPerformWakeupTwo
  ,EcuM_ActNopWithExit

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    ,EcuM_ActEnterSleepState
#endif
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
    ,EcuM_ActEcuMError
#endif
};

/* Table which stores the function pointer of the Query functions */
STATIC CONST(EcuM_StateQueryFuncType, ECUM_CONST) EcuM_QueryTable_ap[] = /* PRQA S 3218 *//* MISRA-C:2004 Rule 8.7: In exceptional cases deviations are possible if an efficient implementation with local variables is not possible. */
{
  EcuM_QryRunRequested,
  EcuM_QryPendingWakeup,
  EcuM_QryPostRunRequested,
  EcuM_QryIsShutdownTargetSleep,
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    EcuM_QryNvmPending,
    EcuM_QryIsNvMWriteAllRunning,
    EcuM_QryIsNvMOrWkUpPending,
#endif
  EcuM_QryNewValidWakeup,
  EcuM_QryIsWKACTRun,
  EcuM_QryRteWaitOnFeedback,
  EcuM_QryRunRequestedOrNewValidWakeup,
  EcuM_QryTrue,
  EcuM_QryIsShutdownTargetOff
};

/* These macros are only for a better readability they does not implement
 * any functionality these macros shall increase the readability of the
 * State Descriptor Table SDT = State Description Table
 */
#define ECUM_SDT_IF(cond1, cond2)                                     {cond1, cond2}
#define ECUM_SDT_THEN(action)                                         (action) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
#define ECUM_SDT_ELSE
#define ECUM_SDT_NEXT_STATE(state)                                    (state) /* PRQA S 3453 *//* MISRA-C:2004 Rule 19.7: Since efficiency is a primary implementation target it is necessary to use macros. */
#define ECUM_SDT_STATE_DESCRIPTION_START                              {{ /* PRQA S 3411 *//* PRQA S 3412 *//* MISRA-C:2004 Rule 19.4: Function like macros are used to increase runtime efficiency and the readability of code and braced code statements are required to avoid name clashes caused by local variables. */ 
#define ECUM_SDT_EXIT_DESCRIPTION(cond1, cond2, action, nextState)    { \
                                                                      ECUM_SDT_IF(cond1, cond2) ,\
                                                                      ECUM_SDT_THEN(action) , \
                                                                      ECUM_SDT_NEXT_STATE(nextState) }

#define ECUM_SDT_FINAL_EXIT_DESCRIPTION(action, nextState)            },{    \
                                                                      ECUM_SDT_THEN(action) ,\
                                                                      ECUM_SDT_NEXT_STATE(nextState) }} /* PRQA S 3411 *//* PRQA S 3412 *//* MISRA-C:2004 Rule 19.4: Function like macros are used to increase runtime efficiency and the readability of code and braced code statements are required to avoid name clashes caused by local variables. */ 

#define ECUM_SDT_STATE_DESCRIPTION_END

STATIC CONST(EcuM_StateDescrType, ECUM_CONST) EcuM_StateDescrTable_at[] = /* PRQA S 3218 *//* MISRA-C:2004 Rule 8.7: In exceptional cases deviations are possible if an efficient implementation with local variables is not possible. */
{
    /**********************************************************************
     * Description RUN STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RUN_REQUESTED,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_EXIT_RUN_STATE,
                                  ECUM_INT_STATE_POST_RUN),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_EXIT_RUN_STATE,
                                  ECUM_INT_STATE_POST_RUN)
    ECUM_SDT_STATE_DESCRIPTION_END,
    /**********************************************************************
     * Description POST RUN STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_POST_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RUN_REQUEST_OR_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ENTER_RUN_STATE,
                                  ECUM_INT_STATE_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_POST_RUN_REQUESTED,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_POST_RUN),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_EXIT_POST_RUN_STATE,
                                  ECUM_INT_STATE_PREP_SHUTDOWN)
    ECUM_SDT_STATE_DESCRIPTION_END,
    /**********************************************************************
     * Description PREP SHUTDOWN STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_SHTDNTRGT_SLEEP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ENTER_GO_SLEEP,
                                  ECUM_INT_STATE_GO_SLEEP),
#else
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_SHTDNTRGT_OFF,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ENTER_GO_OFF_ONE,
                                  ECUM_INT_STATE_GO_OFF_ONE),
#endif
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_SHTDNTRGT_OFF,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ENTER_GO_OFF_ONE,
                                  ECUM_INT_STATE_GO_OFF_ONE),
        /* The Target must be RESET */
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ENTER_GO_OFF_ONE,
                                  ECUM_INT_STATE_FORCE_RESET),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_ENTER_GO_OFF_ONE,
                                  ECUM_INT_STATE_FORCE_RESET)
    ECUM_SDT_STATE_DESCRIPTION_END,
    /**********************************************************************
     * Description GO_OFF_ONE STATE
     *
     * if new valid wakep existent perform a wakeup independent from NvM
     * if NvM is used and NvM_WriteAll is running, remain in this state
     * if NvM is used and wakeups are PENDING, remain in this state and 
     *                wait on its validation, PERFORM_WAKEUP_ONE_2 is
     *                not desireable because there, NvM_CanelWriteAll is 
     *                called and NvM have already been finished
     * if NvM is not used and wakeups are PENDING, perform a wakeup
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_OFF_ONE),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE_2,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_NVM_OR_WKUP_PENDING,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_OFF_ONE),
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR)
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_GO_OFF_ONE)
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/

#else /*(STD_ON == ECUM_INCLUDE_NVRAM_MGR)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_OFF_ONE),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE_2,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_TRUE,            
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE_2,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR)
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_GO_OFF_ONE)
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
#endif

    ECUM_SDT_STATE_DESCRIPTION_END,

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    /**********************************************************************
     * Description GO_SLEEP STATE
     *
     * if new valid wakep existent perform a wakeup independent from NvM
     * if NvM is used and NvM_WriteAll is running, remain in this state
     * if NvM is used and wakeups are PENDING, remain in this state and 
     *                wait on its validation, CANCEL_SLEEP_PROCESS is
     *                not desireable because there, NvM_CanelWriteAll is 
     *                called and NvM have already been finished
     * if NvM is not used and wakeups are PENDING, cancel the SLEEP process
     * ATENTION: if PENDING wakeups are existent the transition to 
     *           ECUM_INT_STATE_SLEEP is not allowed otherwise the wakeups
     *           can get lost
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
# if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_SLEEP),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_CANCEL_SLEEP_PROCESS,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_NVM_OR_WKUP_PENDING,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_SLEEP),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(
                                  ECUM_ACT_ID_ENTER_SLEEP_STATE,
                                  ECUM_INT_STATE_SLEEP)
# else /* NVRAM Manager is not configured */
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_RTEWAITONFEEDBACK,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_GO_SLEEP),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_CANCEL_SLEEP_PROCESS,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_CANCEL_SLEEP_PROCESS,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_ENTER_SLEEP_STATE,
                                  ECUM_INT_STATE_SLEEP)
# endif /* #if (STD_ON == ECUM_INCLUDE_NVRAM_MGR) */
    ECUM_SDT_STATE_DESCRIPTION_END,
#endif

    /**********************************************************************
     * Description FORCE RESET STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NVM_PENDING,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_FORCE_RESET),
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR),
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET),
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR),
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET),
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR)
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET)
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/

#else /* NVRAM Manager is not configured */
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR),
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET),
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR),
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET),
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR),
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET),
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_ERROR)
# else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_SHUTDOWN_SYSTEM,
                                  ECUM_INT_STATE_FORCE_RESET)
# endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
#endif /* #if (STD_ON == ECUM_INCLUDE_NVRAM_MGR) */
    ECUM_SDT_STATE_DESCRIPTION_END,

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    /**********************************************************************
     * Description SLEEP STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_ONE,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_GO_TO_SLEEP,
                                  ECUM_INT_STATE_SLEEP)
    ECUM_SDT_STATE_DESCRIPTION_END,
#endif
    /**********************************************************************
     * Description WAKEUP WITH POWERCTRL VALIDATION STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_REACTION_FROM_STARTUP,
                                  ECUM_INT_STATE_WAKEUP_REACTION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_WAKEUP_WITH_POWERCTRL_VALIDATION),                          
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_REACTION_FROM_STARTUP,
                                  ECUM_INT_STATE_WAKEUP_REACTION),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_PERFORM_WAKEUP_REACTION_FROM_STARTUP,
                                  ECUM_INT_STATE_WAKEUP_REACTION)
    ECUM_SDT_STATE_DESCRIPTION_END,
    /**********************************************************************
     * Description WAKEUP VALIDATION STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_REACTION,
                                  ECUM_INT_STATE_WAKEUP_REACTION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_NEW_VALID_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_REACTION,
                                  ECUM_INT_STATE_WAKEUP_REACTION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_PENDING_WAKEUP,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_NOP_WITH_EXIT,
                                  ECUM_INT_STATE_WAKEUP_VALIDATION),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_PERFORM_WAKEUP_REACTION,
                                  ECUM_INT_STATE_WAKEUP_REACTION)
    ECUM_SDT_STATE_DESCRIPTION_END,

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
    /**********************************************************************
     * Description ECUM ERROR STATE
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ECUM_ERROR,
                                  ECUM_INT_STATE_ERROR),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ECUM_ERROR,
                                  ECUM_INT_STATE_ERROR),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_ECUM_ERROR,
                                  ECUM_INT_STATE_ERROR),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_ECUM_ERROR,
                                  ECUM_INT_STATE_ERROR)
    ECUM_SDT_STATE_DESCRIPTION_END,
#endif
    /**********************************************************************
     * Description WAKEUP REACTION STATE
     * ESCAN00045114 add new transition, remain in state until NvM_WriteAll is finished
     *       if NvM_CancelWriteAll is called the waiting mechanism is important
     *       otherwise the NvM shall not be pending here
     *********************************************************************/
    ECUM_SDT_STATE_DESCRIPTION_START
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
	    ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_NVM_WRITE_ALL_RUNNING,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_WAIT_ON_NVMCANCELWRITEALL,
                                  ECUM_INT_STATE_WAKEUP_REACTION),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_WKACT_RUN,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_TWO,
                                  ECUM_INT_STATE_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP,
                                  ECUM_INT_STATE_PREP_SHUTDOWN),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP,
                                  ECUM_INT_STATE_PREP_SHUTDOWN)
# else /* NVRAM Manager is not configured */
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_IS_WKACT_RUN,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKEUP_TWO,
                                  ECUM_INT_STATE_RUN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP,
                                  ECUM_INT_STATE_PREP_SHUTDOWN),
        ECUM_SDT_EXIT_DESCRIPTION(ECUM_QRY_ID_TRUE,
                                  ECUM_QRY_ID_TRUE,
                                  ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP,
                                  ECUM_INT_STATE_PREP_SHUTDOWN),
        ECUM_SDT_FINAL_EXIT_DESCRIPTION(ECUM_ACT_ID_PERFORM_WAKE_SLEEP_OP,
                                  ECUM_INT_STATE_PREP_SHUTDOWN)
#endif
    ECUM_SDT_STATE_DESCRIPTION_END
};

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

/*********************************************************************************************************************
  GLOBAL VARIABLES
 *********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

/* Current module state: could be retrieved by EcuM_GetState() */
STATIC VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_ModuleState_t;

STATIC VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_PredecessorRteNotifState_t;

/* current selected application mode */
STATIC VAR(AppModeType, ECUM_VAR_NOINIT) EcuM_AppMode_t;

/* selected shutdown target for shutdown phase */
STATIC VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_ShutdownTarget_t;

STATIC VAR(EcuM_WakeupReactionType, ECUM_VAR_NOINIT) EcuM_WakeupReaction_t;


/* configuration pointer of the module */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
  STATIC P2CONST(EcuM_ConfigType, ECUM_VAR_NOINIT, ECUM_APPL_CONFIG) EcuM_Configuration_pt;
#endif

#if (STD_ON == ECUM_TTII_ENABLED)
  STATIC VAR(EcuM_TTII_DivisorType, ECUM_VAR_NOINIT) EcuM_TTII_Divisor_t;
#endif

/* saves all wakeup events where the validation is expired */
STATIC VAR(volatile EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ExpiredWakeups_t;

/* saves all wakeup events which are not validated yes */
STATIC VAR(volatile EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_PendingWakeups_t;

/* variable to stores the validated wakeup event which was responsible for wakeup up the ECU */
STATIC VAR(volatile EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ValidatedWakeups_t;

/* variables to track run and post run requests */
STATIC VAR(volatile EcuM_UserType, ECUM_VAR_NOINIT) EcuM_RunRequestCounter_t;
STATIC VAR(volatile EcuM_UserType, ECUM_VAR_NOINIT) EcuM_PostRunRequestCounter_t;

/* saves the last shutdown target */
STATIC VAR(volatile EcuM_DefaultShutdownTargetType, ECUM_VAR_NOINIT) EcuM_LastShutdownTarget_t;

/* Variable holds the state for the state machine */
STATIC VAR(EcuM_InternalStateType, ECUM_VAR_NOINIT) EcuM_FsmState_t;

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
/* variable holds the job status of the NVRAM Manager needed because of NvM_WriteAll(), NvM_ReadAll() */
STATIC VAR(volatile NvM_RequestResultType, ECUM_VAR_NOINIT) EcuM_NvM_JobStatus_t;
/* variable holds the status whether NvM_WriteAll is still running */
STATIC VAR(boolean, ECUM_VAR_NOINIT) EcuM_NvM_WriteAllStarted_bl;
/** 
 * stores the timeout value for waite mechanism after that the NvM_CancelWriteAll was called
 * if the timer elapsed the NvM_KillWriteAll Api is called or the mode switch into RUN is done
 * immediately 
 * NvmCancelWriteAllTimeout_u32 = (configured timeout in sec *1000)ms/number of MainFunction Cycle
 */
STATIC VAR(uint32, ECUM_VAR_NOINIT) NvmCancelWriteAllTimeout_u32;
#endif

/* variable holds the status whether DEM is initialized and usabel or not */
#if (ECUM_INCLUDE_DEM == STD_ON)
  STATIC VAR(boolean, ECUM_VAR_NOINIT) EcuM_Dem_Initialized_bl;
#endif

/* Indicates the exit of the main function */
STATIC VAR(boolean, ECUM_VAR_NOINIT)  EcuM_ExitMain_bl;


#define ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

#define ECUM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

STATIC VAR(uint8, ECUM_VAR_NOINIT)  EcuM_IntendedRestartID_One_u8;
STATIC VAR(uint8, ECUM_VAR_NOINIT)  EcuM_IntendedRestartID_Two_u8;

#if (STD_ON == ECUM_TTII_ENABLED)
  /* saves the current index into TTII tables, default is 0 */
  STATIC VAR(uint8, ECUM_VAR_NOINIT) EcuM_CurrentTTII_Index_u8;
#endif

/* is used for KillAllRunRequest handling */
STATIC VAR(volatile uint8, ECUM_VAR_NOINIT) EcuM_ModulFlags_u8;

/* Index into EcuM_SleepModeList_at, if ShutdownTarget == sleep the
 * corresponding Sleepmode will be dereferenced with it */
STATIC VAR(uint8, ECUM_VAR_NOINIT) EcuM_CurrentSleepModeIndex_u8;

STATIC VAR(uint8, ECUM_VAR_NOINIT) EcuM_ShutdownTargetSleepIndex_u8;

#define ECUM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

#define ECUM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

STATIC VAR(uint16, ECUM_VAR_NOINIT) EcuM_SelfRequestTimeout_u16;

#define ECUM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */

/***********************************************************************************************************************
 *  EcuM_CB_NfyNvMJobEnd
 **********************************************************************************************************************/
/*! \brief      Callback-function which is used to indicate the Jobend (in this case NvM_WriteAll() is relevant).
 *  \param[in]  ServiceID_u8            Service Id: NVM_READ_ALL/NVM_WRITE_ALL
 *  \param[in]  JobResult_t             result of the job: failed or OK
 *  \pre        EcuM_Init() must be called before.
 *  \context    Function could be called from interrupt level or from task level
 **********************************************************************************************************************/
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
FUNC(void, ECUM_CODE) EcuM_CB_NfyNvMJobEnd(uint8 ServiceID_u8, NvM_RequestResultType JobResult_t)
{

# if (STD_ON == ECUM_CHECK_UNINIT)
    if (EcuM_ModuleState_t < (EcuM_StateType)ECUM_STATE_STARTUP_TWO)
    {
      EcuM_Det_Errorhook(ECUM_SID_CB_NFY_NVM_JOB_END, ECUM_E_NOT_INITED);


      return;
    }
    else
    {
        /* Module is initialized */
    }
# endif /*(STD_ON == ECUM_CHECK_UNINIT) */

  if ((uint8)NVM_WRITE_ALL == ServiceID_u8)
  {
    EcuM_NvM_JobStatus_t = JobResult_t;
    /* 
     * necessary for NvM_CancelWriteAll.
     * In case of a wakeup before entering in SLEEP or OFF mode the NvM
     * in EcuM STATE WAKEUP_REACTION shall be waited until NvM_WriteAll is finished
     */
     EcuM_NvM_WriteAllStarted_bl = FALSE;
  }
  else
  {
    /* Do nothing */
  }


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

/***********************************************************************************************************************
 *  EcuM_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Returns the version information of this Module.
 *  \param[in]  versioninfo     pointer to store the version information
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
#if (STD_ON == ECUM_VERSION_INFO_API)
FUNC(void, ECUM_API_CODE) EcuM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo)
{

# if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    if (NULL_PTR == versioninfo)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_VERSION_INFO, ECUM_E_PARAM_VINFO);


      return;
    }
    else
    {
        /* nothing to be done here */
    }
# endif

  versioninfo->vendorID         = (uint16)ECUM_VENDOR_ID;
  versioninfo->moduleID         = (uint16)ECUM_MODULE_ID;
  versioninfo->instanceID       = (uint8)ECUM_INSTANCE_ID;
  versioninfo->sw_major_version = (uint8)ECUM_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = (uint8)ECUM_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = (uint8)ECUM_SW_PATCH_VERSION;


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

#endif /* (ECUM_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
 *  EcuM_Init
 **********************************************************************************************************************/
/*! \brief      Initializes the ECU State Manager Module. Executes STARTUP I activities according to SWS.
 *  \context    This function should be called within the main() function after startup.
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_Init(void)
{
  /* common index variable */
  uint8 iu8_loc;

  /**
   * EcuM_ModuleState_t is set here to the main state ECUM_STATE_STARTUP to have an defined value for error checking
   * purposes. If variables are initialized (which are used by wakeup related functions) then the state will be set
   * to ECUM_STATE_STARTUP_ONE so that wakeup related functions can be used.
   */
  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_STARTUP;

  /** 
   * initialze the Predecessor state for RTE notification
   */
  EcuM_PredecessorRteNotifState_t = (EcuM_StateType)ECUM_STATE_STARTUP;



  EcuM_AL_DriverInitZero();

  /* Get the pointer to initialization structure of the EcuM */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
    EcuM_Configuration_pt = (P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONFIG))EcuM_DeterminePbConfiguration();


# if (STD_ON == ECUM_CHECK_CONFIG_TYPE)
      if (NULL_PTR == EcuM_Configuration_pt)
      {
        EcuM_Det_Errorhook(ECUM_SID_INIT, ECUM_E_NULL_POINTER);


        return;
      }
      else
      {
        /* configPtr is not a null pointer */
      }

# endif /* (STD_ON == ECUM_CHECK_CONFIG_TYPE) */
#endif

#if ((!defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )) && (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD))
  /* Check the PBCfg Configuration */
   if (((EcuM_Configuration_pt->EcuM_GeneratorVersion & (uint32)0x00FFFF00u)!=
        (((uint32)SYSSERVICE_ASRECUM_GENTOOL_EAD_MAJOR_VERSION << 16u) |
        ((uint32)SYSSERVICE_ASRECUM_GENTOOL_EAD_MINOR_VERSION << 8u))) ||
        ((sint32)(EcuM_Configuration_pt->EcuM_GeneratorVersion & (uint32)0x000000FFu) <
        (sint32)SYSSERVICE_ASRECUM_GENTOOL_EAD_PATCH_VERSION))
    {
      /* Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
      EcuM_GeneratorCompatibilityError((uint16)ECUM_MODULE_ID, (uint8)ECUM_INSTANCE_ID);

      /* Do not continue with the initialization of the component the Application may be influenced critically. */
      return;
    }
#endif

  /* set global variables to a defined state */
  EcuM_ModulFlags_u8 = 0;

  EcuM_InternalClearWakeupEvents(ECUM_WKSOURCE_ALL_SOURCES);

  EcuM_RunRequestCounter_t = 0;
  EcuM_PostRunRequestCounter_t = 0;

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    /* Set the control variables for the notification buffering mechanism of the communication manager */
    EcuM_ComMNotifyCtrl_t.BufferCtrl_u8 = 0;
    EcuM_ComMNotifyCtrl_t.ComMInitialized_b = (boolean)FALSE;
#endif

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    EcuM_NvM_JobStatus_t = NVM_REQ_PENDING;
    EcuM_NvM_WriteAllStarted_bl = FALSE;
    NvmCancelWriteAllTimeout_u32 = 0;
#endif

  EcuM_SelfRequestTimeout_u16 = (uint16)ECUM_NO_TIMEOUT_SET;

  /* Reset the wakeup timeouts */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    for (iu8_loc = 0; iu8_loc < (uint8)ECUM_MAX_WAKEUP_SOURCES; iu8_loc++)
#else
    for (iu8_loc = 0; iu8_loc < EcuM_Configuration_pt->MaxNumberOfWakeupSources_u8; iu8_loc++)
#endif
    {
      EcuM_WakeupTimeoutTable_at[iu8_loc].EcuM_WakeupTimeoutLeft_t = (EcuM_WakeupTimeoutType)ECUM_NO_TIMEOUT_SET;
      EcuM_WakeupTimeoutTable_at[iu8_loc].EcuM_WakeupValState_u8 =(uint8)ECUM_WKS_TIMEOUT_STATE_STOPPED;
    }

  /* Clear/Set all RUN/POST RUN - Request */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    for (iu8_loc = 0; iu8_loc < (uint8)ECUM_MAX_ECUM_USER_COUNT; iu8_loc++)
#else
    for (iu8_loc = 0; iu8_loc < EcuM_Configuration_pt->MaxEcuMUsersCount_u8; iu8_loc++)
#endif
    {
      EcuM_UserTable_at[iu8_loc] = 0;
    }

  /**
   * Variables which are used by wakeup related functions are initialized until this code line.
   * So the module state could be set to ECUM_STATE_STARTUP_ONE to be checked in that wakeup related
   * functions.
   */
  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_STARTUP_ONE;

  /* call callout for initialize drivers which don't need OS support */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverInitOne(NULL_PTR);
#else
    EcuM_Configuration_pt->DriverInitListOne();
#endif

  /**
   * Retrieve the reset reason from the Mcu module and map it to an wakeup source.
   */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_ValidatedWakeups_t = EcuM_MapResetReason();
#else
    EcuM_ValidatedWakeups_t = EcuM_MapResetReason(EcuM_Configuration_pt);
#endif

  /**
   * Configure the Shutdown target
   * This call sets the global variable:EcuM_ShutdownTarget_t to default
   * value and configures the TTII protocol if enabled.
   */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_ShutdownTarget_t = ECUM_DEFAULT_SHUTDOWN_STATE;
    EcuM_ShutdownTargetSleepIndex_u8 = ECUM_DEFAULT_SHUTDOWN_SLEEP_MODE;
#else
    EcuM_ShutdownTarget_t = EcuM_Configuration_pt->DefaultShutdownTarget_t.DefaultState_t;
    EcuM_ShutdownTargetSleepIndex_u8 = EcuM_Configuration_pt->DefaultShutdownTarget_t.DefaultSleepMode_u8;
#endif


#if (STD_ON == ECUM_TTII_ENABLED)
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
      EcuM_TTII_Divisor_t = EcuM_Configuration_pt->TTII_DivisorList_pt[0u];
# else
      EcuM_TTII_Divisor_t = EcuM_TTII_DivisorList_at[0u];
# endif
#endif

  if (((uint8)ECUM_MAGIC_ONE != EcuM_IntendedRestartID_One_u8)
      && ((uint8)ECUM_MAGIC_TWO != EcuM_IntendedRestartID_Two_u8))
  {
    /* Unintended Restart: set the default AppMode */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      EcuM_AppMode_t = ECUM_DEFAULT_APP_MODE;
#else
      EcuM_AppMode_t = EcuM_Configuration_pt->DefaultAppMode_t;
#endif

    /* set the last shutdown target if the restart was NOT intended */
    EcuM_LastShutdownTarget_t.DefaultState_t = (EcuM_StateType)ECUM_STATE_OFF;
    EcuM_LastShutdownTarget_t.DefaultSleepMode_u8 = 0;
  }
  else
  {
    /* Intended Restart: don't set the default AppMode */
  }


  /* Start the AUTOSAR OS */
#if defined( VECTOR_POLYSPACE_TEST )
    /* No OS is to be called for POLYSPACE */
#else /* VECTOR_POLYSPACE_TEST */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    StartOS((AppModeType)ECUM_DEFAULT_APP_MODE);
# else
    EcuM_StartOs(EcuM_AppMode_t);
# endif
#endif /* VECTOR_POLYSPACE_TEST */

    /**
     * The EcuM_Init() function never returns, so the following code should never been executed otherwise a development
     * error will be reported.
     */
# if (STD_ON == ECUM_DEV_ERROR_DETECT)
#  if defined( VECTOR_POLYSPACE_TEST )
      /* No ErrorHook is to be called for POLYSPACE */
#  else /* VECTOR_POLYSPACE_TEST */
      EcuM_Det_Errorhook(ECUM_SID_INIT, ECUM_E_OS_NOT_STARTED_SUCCESFULLY);
#  endif /* VECTOR_POLYSPACE_TEST */
# endif

  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_Shutdown
 **********************************************************************************************************************/
/*! \brief      Typically called from the shutdown hook, this function takes over  execution control and will carry
 *              out GO OFF II activities.
 *  \context    Function should be called from the ShutdownHook of the Os.
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_Shutdown(void)
{
  EcuM_StateType EcuM_ShutdownTarget_tloc;


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_SHUTDOWN))
    {
      return;
    }
    else
    {
      /* Module is initialized */
    }
#endif

  EcuM_ModuleState_t = ECUM_STATE_GO_OFF_TWO;

  /* EcuM_ShutdownTarget_t has a defined value-> assured by EcuM */
  EcuM_ShutdownTarget_tloc = EcuM_ShutdownTarget_t;

  /* invoke callout when entering GO_OFF_TWO state */
#if (STD_ON == ECUM_ON_GO_OFF_TWO_CALLOUT)
    EcuM_OnGoOffTwo();
#endif

  /*
   * There are three possible shutdowntargets defined.
   * - ECUM_STATE_SLEEP
   * - ECUM_STATE_OFF
   * - ECUM_STATE_RESET
   * The state machine design ensures that ECUM_STATE_SLEEP is not
   * a valid value within EcuM_Shutdown(). (See. state description
   * of PREP_SHUTDOWN. So only ECUM_STATE_OFF and ECUM_STATE_RESET
   * must be handled in switch-statement.
   */
  switch (EcuM_ShutdownTarget_tloc)
  {
  case ECUM_STATE_OFF:
    /* Save last shutdowntarget for EcuM_GetLastShutdownTarget() service */
    EcuM_LastShutdownTarget_t.DefaultState_t = (EcuM_StateType)ECUM_STATE_OFF;
    EcuM_LastShutdownTarget_t.DefaultSleepMode_u8 = 0;

    /*Set the variable to zero. This is necessary if a restart of the system
     * occurred after a short time, RAM may be valid in this time
     */
    EcuM_IntendedRestartID_One_u8 = 0;
    EcuM_IntendedRestartID_Two_u8 = 0;

    /* Execute callout which should switch off the MCU */
    EcuM_AL_SwitchOff();

    /*
     * This code will be only executed if the "System Designer" does not
     * add the correct code into EcuM_AL_SwitchOff() (ECU does not switch off)
     * in this case an Development error is reported, if DET is enabled and
     * Mcu_PerformReset() will be executed to have a working System.
     */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)

      EcuM_Det_Errorhook(ECUM_SID_SHUTDOWN, ECUM_E_OFF_STATE_EXPECTED);

#endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/

# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      Mcu_PerformReset();
# else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_MCU_PERFORM_RESET]);
# endif

    break;

  case ECUM_STATE_RESET:
    /*
     * Save last shutdowntarget for EcuM_GetLastShutdownTarget() service
     */
    EcuM_LastShutdownTarget_t.DefaultState_t = (EcuM_StateType)ECUM_STATE_RESET;
    EcuM_LastShutdownTarget_t.DefaultSleepMode_u8 = 0;

    /*
     * set internal variable to remember that the restart was intended
     */
    EcuM_IntendedRestartID_One_u8 =  (uint8)ECUM_MAGIC_ONE;
    EcuM_IntendedRestartID_Two_u8 =  (uint8)ECUM_MAGIC_TWO;

    /*
     * the shutdown target must be ECUM_STATE_RESET
     */
    EcuM_ModulFlags_u8 = 0;

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      Mcu_PerformReset();
#else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_MCU_PERFORM_RESET]);
#endif


    break;

  default: /* ECUM_MODE_SLEEP */

#if (STD_ON == ECUM_DEV_ERROR_DETECT)

      EcuM_Det_Errorhook(ECUM_SID_SHUTDOWN, ECUM_E_WRONG_ECUM_USAGE);


      return;

#else /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/


      return;

#endif /*(STD_ON == ECUM_DEV_ERROR_DETECT)*/
  }
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_RequestRUN
 **********************************************************************************************************************/
/*! \brief      Places a request for the RUN state. Requests can be placed by every user known to the state manager at
 *              configuration time. In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if a User requests
 *              multiple RUN states.
 *              doxygen format is visible to the customer.
 *  \param[in]  User_t   User which requests RUN state
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_RequestRUN(EcuM_UserType User_t)
{
  return ECUM_FUNC_CALL_REQUEST_RUN(ECUM_SID_REQUEST_RUN, User_t, ECUM_USER_REQUEST_RUN_MASK);
} /* End of EcuM_RequestRUN() */

/***********************************************************************************************************************
 *  EcuM_ReleaseRUN
 **********************************************************************************************************************/
/*! \brief      Releases a RUN request previously done with a call to EcuM_RequestRUN.
 *              In Development mode the error code ECUM_E_MISMATCHED_RUN_RELEASES will
 *              be thrown if a user releases a RUN state without a matching request.
 *  \param[in]  User_t   User which releases RUN state
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_ReleaseRUN(EcuM_UserType User_t)
{
  return ECUM_FUNC_CALL_RELEASE_RUN(ECUM_SID_RELEASE_RUN, User_t, ECUM_USER_REQUEST_RUN_MASK);
} /* End of EcuM_ReleaseRUN() */

/***********************************************************************************************************************
 *  EcuM_RequestPOST_RUN
 **********************************************************************************************************************/
/*! \brief      Places a request for the POST RUN state. Requests can be placed for every user known to the state
 *              manager at configuration time. In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if a
 *              User requests multiple POST RUN states.
 *  \param[in]  User_t   User which requests POST RUN
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_RequestPOST_RUN(EcuM_UserType User_t)
{
  return ECUM_FUNC_CALL_REQUEST_RUN(ECUM_SID_REQUEST_POST_RUN, User_t, ECUM_USER_REQUEST_POST_RUN_MASK);
} /* End of EcuM_RequestPOST_RUN() */

/***********************************************************************************************************************
 *  EcuM_ReleasePOST_RUN
 **********************************************************************************************************************/
/*! \brief      Releases a POST RUN request previously done with a call to EcuM_RequestPOST_RUN(). In Development
 *              mode the error code ECUM_E_MISMATCHED_RUN_RELEASES will be thrown if a user releases a RUN  state
 *              without a matching request.
 *  \param[in]  User_t   User which releases POST RUN
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_ReleasePOST_RUN(EcuM_UserType User_t)
{
  return ECUM_FUNC_CALL_RELEASE_RUN(ECUM_SID_RELEASE_POST_RUN, User_t, ECUM_USER_REQUEST_POST_RUN_MASK);
} /* End of EcuM_ReleasePOST_RUN() */

/***********************************************************************************************************************
 *  EcuM_KillAllRUNRequests
 **********************************************************************************************************************/
/*! \brief      The consequence of a call to this service is that the shutdownsequence will be initiated. Use this
 *              function with care. Side affects may occur in the Applications.
 *  \context    Function should only be called by the communication manager
 **********************************************************************************************************************/
#if (STD_ON == ECUM_KILL_ALL_RUNREQUEST_API)
FUNC(void, ECUM_API_CODE) EcuM_KillAllRUNRequests(void)
{
  uint8 loopIndex_u8loc;


# if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_KILL_ALL_RUN_REQUESTS))
    {

      return;
    }
    else
    {
      /* Module is initialized */
    }
# endif

  EcuM_GlobalSuspend();

  /* Set internal flag-variable to indicate that KillAllRunRequest is in progress */
  EcuM_ModulFlags_u8 |= (uint8)ECUM_FLAG_KILLALL_IN_PROGRESS;

  /* Set Shutdowntarget to RESET in order to achieve a restart
   * This is not an requirement, but Shutdowntarget like OFF or SLEEP
   * wouldn't make sense
   */
  EcuM_ShutdownTarget_t = (EcuM_StateType)ECUM_STATE_RESET;

  /* Remove (Post) Run request of all users */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    for (loopIndex_u8loc = 0; loopIndex_u8loc < (uint8)ECUM_MAX_ECUM_USER_COUNT; loopIndex_u8loc++)
# else
    for (loopIndex_u8loc = 0; loopIndex_u8loc < EcuM_Configuration_pt->MaxEcuMUsersCount_u8; loopIndex_u8loc++)
# endif
    {
      EcuM_UserTable_at[loopIndex_u8loc] = 0;
    }

  EcuM_RunRequestCounter_t = 0;
  EcuM_PostRunRequestCounter_t = 0;

  EcuM_InternalClearWakeupEvents(ECUM_WKSOURCE_ALL_SOURCES);

  /* delete self run request */
  EcuM_SelfRequestTimeout_u16 = (uint16)ECUM_NO_TIMEOUT_SET;

  /* Report call to EcuM_KillAllRUNRequests() to DEM */
# if (STD_ON == ECUM_ENABLE_PROD_ERROR_REPORTING)
    EcuM_SetError(EcuM_AllRunRequestKilledError_t, DEM_EVENT_STATUS_FAILED);
# endif

  EcuM_GlobalRestore();


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to codse optimization. */
#endif

/***********************************************************************************************************************
 *  EcuM_SelectShutdownTarget
 **********************************************************************************************************************/
/*! \brief      Selects a new Shutdown Target for an intended Restart.
 *  \param[in]  EcuM_TargetState_t      target state
 *  \param[in]  sleepMode_u8            target sleep mode if target state is ECUM_STATE_SLEEP
 *  \retval     E_NOT_OK - error
 *  \retval     E_OK     - success
 *  \pre        The EcuM must be in RUN state.
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_SelectShutdownTarget(EcuM_StateType EcuM_TargetState_t, uint8 sleepMode_u8)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_SELECT_SHUTDOWN_TARGET))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

#if (STD_ON == ECUM_CHECK_STATE_PARAMETER)

    if (((EcuM_StateType)ECUM_STATE_RESET != EcuM_TargetState_t) &&
        ((EcuM_StateType)ECUM_STATE_OFF   != EcuM_TargetState_t) &&
        ((EcuM_StateType)ECUM_STATE_SLEEP != EcuM_TargetState_t))
    {
      EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_STATE_PAR_OUT_OF_RANGE);

      return E_NOT_OK;
    }

# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
    if ((EcuM_Configuration_pt->MaxSleepModes_u8 == (uint8)0) &&
        ((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_TargetState_t))
      {
        EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_STATE_PAR_OUT_OF_RANGE);

        return E_NOT_OK;
      }
# else
#  if (ECUM_MAX_SLEEP_MODES == 0u)
    if ((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_TargetState_t)
    {
      EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_STATE_PAR_OUT_OF_RANGE);

      return E_NOT_OK;
    }
#  endif
# endif
#endif

#if (STD_ON == ECUM_CHECK_SLEEP_MODE_PARAMETER)
    /* If the desired state is SLEEP check whether the sleep mode
     * in within the expected range
     */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
    if (((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_TargetState_t) &&
        (sleepMode_u8 >= EcuM_Configuration_pt->MaxSleepModes_u8))
    {
      EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_INVALID_PAR);

      return E_NOT_OK;
    }
# else
#  if (ECUM_MAX_SLEEP_MODES != 0u)
        if (((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_TargetState_t) &&
            (sleepMode_u8 >= (uint8)ECUM_MAX_SLEEP_MODES))
        {
          EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_INVALID_PAR);

          return E_NOT_OK;
        }
#  endif
# endif

#endif

  /* The selection of the shutdown target is only allowed while module is in RUN state to ensure that
   * EcuM_EnableWakeupSources() will be called correctly.
   */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
    if ((EcuM_StateType)ECUM_STATE_APP_RUN != EcuM_ModuleState_t)
    {
      EcuM_Det_Errorhook(ECUM_SID_SELECT_SHUTDOWN_TARGET, ECUM_E_MODULE_NOT_IN_RUN_STATE);


      return E_NOT_OK;
    }
    {
      /* Service executed in RUN mode, so no error must be reported */
    }
#endif

  /* Allow selecting shutdowntarget only if no KillAllRunRequest
   * is in progress, otherwise it would be possible to change
   * the Shutdowntarget to another as RESET
   */
  if (E_OK != EcuM_IsKillAllInProgress())
  {

    return E_NOT_OK;
  }
  else
  {
    /* intentionally left free */
  }

  EcuM_GlobalSuspend();

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)

    if ((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_TargetState_t)
    {
      /* Set the selected Sleepmode Index into EcuM_SleepModeList_at */
      EcuM_ShutdownTargetSleepIndex_u8 = sleepMode_u8;

      /* Configure TTII preload the TTII Divisor counter */
# if (STD_ON == ECUM_TTII_ENABLED)
        EcuM_TTII_Divisor_t = EcuM_Configuration_pt->TTII_DivisorList_pt[0u];
# endif
    }
    else
    {
      /* nothing to do */
    }
#else
# if (ECUM_MAX_SLEEP_MODES != 0u)
      /* Set the selected Sleepmode Index into EcuM_SleepModeList_at */
      EcuM_ShutdownTargetSleepIndex_u8 = sleepMode_u8;

      /* Configure TTII preload the TTII Divisor counter */
#  if (STD_ON == ECUM_TTII_ENABLED)
        EcuM_TTII_Divisor_t = EcuM_TTII_DivisorList_at[0u];
#  endif
# else
#  if (V_USE_DUMMY_STATEMENT == STD_ON)
      sleepMode_u8 = sleepMode_u8; /* PRQA S 3199 *//* MISRA-C:2004 redundancy: dummy assignment for unused parameter */
#  endif
# endif
#endif

  /* Set internal variable to TargetState */
  EcuM_ShutdownTarget_t = EcuM_TargetState_t;
  EcuM_GlobalRestore();


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_GetState
 **********************************************************************************************************************/
/*! \brief      Returns the current module state of the ECUM.
 *  \param[in]  -
 *  \param[out] Reference to the current state of the ECUM.
 *  \retval     E_OK The parameter state was not a NULL_PTR.
 *  \retval     E_NOT_OK The parameter state was a NULL_PTR.
 *  \pre        -
 *  \context    Function could be called from task level
 *  \note
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetState(P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) state)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_STATE))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

# if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    if (NULL_PTR == state)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_STATE, ECUM_E_NULL_POINTER);
      return E_NOT_OK;
    }
    else
    {
      /* parameter is valid: continue */
    }
# endif

  /* Return the internal Module state */
  *state = EcuM_ModuleState_t;


  return E_OK;

} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_GetShutdownTarget
 **********************************************************************************************************************/
/*! \brief      Returns the actual chosen shutdown target.
 *  \param[out] Target_pt                      current shutdown target
 *  \param[out] SleepMode_pu8                  current sleep mode
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetShutdownTarget
(
  P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) Target_pt,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) SleepMode_pu8
)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_SHUTDOWN_TARGET))
    {

      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif
  /* Perform parameter check if enabled */
#if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    /* Perform pointer checks */
    if (NULL_PTR == Target_pt)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_SHUTDOWN_TARGET, ECUM_E_NULL_POINTER);


      return E_NOT_OK;
    }
    else
    {
        /* Nothing to be done here */
    }

    if (NULL_PTR == SleepMode_pu8)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_SHUTDOWN_TARGET, ECUM_E_NULL_POINTER);


      return E_NOT_OK;
    }
    else
    {
        /* Nothing to be done here */
    }
#endif /*(STD_ON == ECUM_CHECK_POINTER_PARAMETER)*/

  EcuM_GlobalSuspend();

  if ((uint8)ECUM_STATE_SLEEP == EcuM_ShutdownTarget_t)
  {
   /*
    * Current selected target is SLEEP, so
    * set the sleep mode index if the current shutdowntarget
    * is  ECUM_STATE_SLEEP
    */
    *SleepMode_pu8 = EcuM_ShutdownTargetSleepIndex_u8;
  }
  else
  {
   /*
    * The current selected target is not sleep so
    * return a defined value
    */
    *SleepMode_pu8 = 0;
  }

  /* return current shutdowntarget */
  *Target_pt = EcuM_ShutdownTarget_t;
  EcuM_GlobalRestore();


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_GetLastShutdownTarget
 **********************************************************************************************************************/
/*! \brief      This function returns not the current shutdown target but the shutdown
 *              target set before the last reset.
 *  \param[out] ShutdownTarget_pt              current shutdown target
 *  \param[out] SleepMode_pu8                  current sleep mode
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetLastShutdownTarget
(
  P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) ShutdownTarget_pt,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)          SleepMode_pu8
)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_LAST_SHUTDOWN_TARGET))
    {

      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

  /* Perform parameter check if enabled */
#if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    if (NULL_PTR == ShutdownTarget_pt)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_LAST_SHUTDOWN_TARGET, ECUM_E_NULL_POINTER);


      return E_NOT_OK;
    }
    else
    {
      /* Nothing to be done here */
    }

    if (NULL_PTR == SleepMode_pu8)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_LAST_SHUTDOWN_TARGET, ECUM_E_NULL_POINTER);


      return E_NOT_OK;
    }
    else
    {
      /* Nothing to be done here */
    }
#endif /*(STD_ON == ECUM_CHECK_POINTER_PARAMETER)*/

  EcuM_GlobalSuspend();

  if ((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_LastShutdownTarget_t.DefaultState_t)

  {
    /* The last shutdown target was sleep, so return the sleepmode index */
    *SleepMode_pu8 = EcuM_LastShutdownTarget_t.DefaultSleepMode_u8;
  }
  else
  {
    /* The last shutdown target was not sleep => return a defined value */
    *SleepMode_pu8 = 0;
  }
  *ShutdownTarget_pt = EcuM_LastShutdownTarget_t.DefaultState_t;

  EcuM_GlobalRestore();


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_SetWakeupEvent
 **********************************************************************************************************************/
/*! \brief      Marks a wakeupevent as pending if validation is required.
 *              If no validation is required then EcuM_ValidateSetWakeupEvent
 *              will be called within this function.
 *  \param[in]  EcuM_WakeupSource_t     the source of the wakeup event.
 *  \context    Function could be called from interrupt level.
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupSource_t)
{
  uint8 ShiftCount_u8loc;


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInit(ECUM_SID_SET_WAKEUP_EVENT))
    {
      return;
    }
    else
    {
      /* Module is initialized */
    }
#endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

  /* Parameter checks */
#if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
  if (E_OK != EcuM_CheckWKSourceParameter(ECUM_SID_SET_WAKEUP_EVENT, WakeupSource_t))
  {
    return;
  }
  else
  {
    /* wakeup source parameter is valid */
  }
#endif /* #if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER) */

  if (E_OK != EcuM_IsKillAllInProgress())
  {
    return;
  }
  else
  {
    /* intentionally left free */
  }

  /* Get Number of Wakeup Source */
  ShiftCount_u8loc = EcuM_GetShiftCount_u8(WakeupSource_t);

  /* Set wakeupSource in internal variable, if not already set */
  EcuM_GlobalSuspend();

  if ((EcuM_WakeupSourceType)0 == (EcuM_PendingWakeups_t & WakeupSource_t))
  {
    EcuM_PendingWakeups_t |= WakeupSource_t;
    EcuM_GlobalRestore();
  }
  else
  {
    EcuM_GlobalRestore();

    return;
  }

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if (EcuM_WakeupSourceList_at[ShiftCount_u8loc].EcuM_ValidationTimeout_t > (EcuM_WakeupTimeoutType)0)
#else
  if (EcuM_Configuration_pt->WakeupSourceList_pt[ShiftCount_u8loc].EcuM_ValidationTimeout_t > (EcuM_WakeupTimeoutType)0)
#endif
  {
    /* Validation is required for this wakeupsource
     * Start Timer for this source
     */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      EcuM_WakeupTimeoutTable_at[ShiftCount_u8loc].EcuM_WakeupTimeoutLeft_t =
        EcuM_WakeupSourceList_at[ShiftCount_u8loc].EcuM_ValidationTimeout_t;
#else
      EcuM_WakeupTimeoutTable_at[ShiftCount_u8loc].EcuM_WakeupTimeoutLeft_t =
        EcuM_Configuration_pt->WakeupSourceList_pt[ShiftCount_u8loc].EcuM_ValidationTimeout_t;
#endif
  }
  else
  {
    /* No Validation is required for this source call directly
     * EcuM_ValidateWakeupSource
     */
    EcuM_ValidateWakeupEvent(WakeupSource_t);
  }


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant fors information purpose */

/***********************************************************************************************************************
 *  EcuM_GetPendingWakeupEvents
 **********************************************************************************************************************/
/*! \brief      Returns wakeup events which have been set but not yet validated
 *  \retval     EcuM_WakeupSourceType   wakeup sources where the corresponding bit are set are in pending state.
 *  \context    Function could be called from interrupt level.
 **********************************************************************************************************************/
FUNC(EcuM_WakeupSourceType, ECUM_API_CODE) EcuM_GetPendingWakeupEvents(void)
{


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInit(ECUM_SID_GET_PENDING_WAKEUP_EVENTS))
    {

      return ECUM_WKSOURCE_NONE;
    }
    else
    {
      /* Module is initialized */
    }
#endif


  /* Return Value from internal Variable */
  return EcuM_PendingWakeups_t;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_ClearWakeupEvent
 **********************************************************************************************************************/
/*! \brief      Clears all wakeup event flags which are set in parameter
 *  \param[in]  EcuM_WakeupSource_t     wakeup event(s) which should be cleared
 *  \context    Function could be called from interrupt level.
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_ClearWakeupEvent(EcuM_WakeupSourceType WakeupSource_t)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInit(ECUM_SID_CLEAR_WAKEUP_EVENT))
    {

      return;
    }
    else
    {
      /* Module is initialized */
    }
#endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

#if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
  /* Check if Parameter is (0u). (0u) is not a valid wakeup source */
  if ((EcuM_WakeupSourceType)0 == WakeupSource_t)
  {
    EcuM_Det_Errorhook(ECUM_SID_CLEAR_WAKEUP_EVENT, ECUM_E_UNKNOWN_WAKEUP_SOURCE);

    /* return without doing any action */
    return;
  }
  else
  {
      /* continue with program flow */
  }
#endif /* #if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER) */

  /* Disable Interrupts */
  EcuM_GlobalSuspend();

  /* Clear Wakeupevent from internal variable */
  EcuM_InternalClearWakeupEvents(WakeupSource_t);

  EcuM_GlobalRestore();


  /* Enable Interrupts */
  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_ValidateWakeupEvent
 **********************************************************************************************************************/
/*! \brief      After wakeup, the ECU State Manager will stop the process during the
 *              WAKEUP VALIDATION state to wait for validation of the wakeup event. The
 *              validation is carried out with a call to this API service.
 *  \param[in]  EcuM_WakeupSource_t     the wakeup source which should be validated
 *  \context    Function could be called from interrupt level.
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType WakeupSource_t)
{
  uint8 ShiftCount_u8loc;

#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    struct EcuM_WakeupSourceDefType WkSource_tloc;
#endif


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInit(ECUM_SID_VALIDATE_WAKEUP_EVENT))
    {
      return;
    }
    else
    {
      /* Module is initialized */
    }
#endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

#if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
  if (E_OK != EcuM_CheckWKSourceParameter(ECUM_SID_VALIDATE_WAKEUP_EVENT, WakeupSource_t))
  {
    return;
  }
  else
  {
    /* wakeup source parameter is valid */
  }
#endif /* #if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER) */

  /* Get Number of Wakeup Source */
  ShiftCount_u8loc = EcuM_GetShiftCount_u8(WakeupSource_t);

  EcuM_WakeupTimeoutTable_at[ShiftCount_u8loc].EcuM_WakeupTimeoutLeft_t = (EcuM_WakeupTimeoutType)ECUM_NO_TIMEOUT_SET;
  EcuM_WakeupTimeoutTable_at[ShiftCount_u8loc].EcuM_WakeupValState_u8 = (uint8)ECUM_WKS_TIMEOUT_STATE_STOPPED;

  /* Check if Wakeupevent was set before, if check failed
    * two possible reasons exists:
    * 1. Reason: Validation Timeout expired.
    * 2. Reason: calling sequence of API functions is not:
    *   1) call EcuM_SetWakeupEvent()
    *   2) call EcuM_ValidateWakeupEvent()
    */
  if ((EcuM_WakeupSourceType)0 != (EcuM_PendingWakeups_t & WakeupSource_t))
  {
#if (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE)
      if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_COMM_USED))
#endif
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
      {
        /* WakeupSource set, Validate this Wakeup event
         * look up wakeupsource from Wakeupsourcelist to determine whether
         * wakeup source is a COM Channel
         */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
          WkSource_tloc = EcuM_WakeupSourceList_at[ShiftCount_u8loc];
# else
          WkSource_tloc = EcuM_Configuration_pt->WakeupSourceList_pt[ShiftCount_u8loc];
# endif

        if (255 != WkSource_tloc.EcuM_ComMChannel_t)
        {
          /* If module is in startup two phase it is possible that communication channels report wakeup events
           * on communication channels but the Communication Manager is not initialized yet. To prevent
           * undefined behavior this request will be stored and reported after execution of init list III.
           */

          /* If communication mananger is initialized call the wakeup indication directly */
          if (TRUE == EcuM_ComMNotifyCtrl_t.ComMInitialized_b)
          {
            /* Wakeupsource is COM Channel => notify ComM */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
#  if (ECUM_INCLUDE_COMM == STD_ON)
                ComM_EcuM_WakeUpIndication((NetworkHandleType)WkSource_tloc.EcuM_ComMChannel_t);
#  endif
# else
              EcuM_ComM_WakeUpIndication(WkSource_tloc.EcuM_ComMChannel_t);
# endif
          }
          else
          {
            /* communication is not initialized, so the wakeup event must be buffered until it is assured
             * that the communication manager is initialized.
             */
            EcuM_GlobalSuspend();

            EcuM_ComMNotifyCtrl_t.ChannelNotifyBuffer_pu8[EcuM_ComMNotifyCtrl_t.BufferCtrl_u8] =
              WkSource_tloc.EcuM_ComMChannel_t;

            EcuM_ComMNotifyCtrl_t.BufferCtrl_u8++;

            EcuM_GlobalRestore();
          }
        }
        else
        {
            /* not a COM Channel: do nothing */
        }
      }
#endif

    EcuM_GlobalSuspend();

    /* Delete this wakeupsource from pending list */
    EcuM_PendingWakeups_t &= (~WakeupSource_t);

    /* Store the valid wakeup  */
    EcuM_ValidatedWakeups_t |= WakeupSource_t;

    EcuM_GlobalRestore();
  }
  else /* if (EcuM_PendingWakeups_t & WakeupSource_t) */
  {
    /* Wakeup source not set: Report an error due to wakeup validation protocol validation */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
      EcuM_Det_Errorhook(ECUM_SID_VALIDATE_WAKEUP_EVENT, ECUM_E_WAKEUP_VALIDATION_PROT_ERROR);

      return;
#endif
  }


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_GetValidatedWakeupEvents
 **********************************************************************************************************************/
/*! \brief      Return the wakeup source where the wakeup validation was successful.
 *  \retval     EcuM_WakeupSourceType     Id of the wakeup source which was responsible for the wakeup
 *  \context    Function could be called from interrupt level
 *  \note       a value will only be returned if EcuM is in RUN state
 **********************************************************************************************************************/
#if (STD_ON == ECUM_GET_VALIDATED_WAKEUP_EVENTS_API)
FUNC(EcuM_WakeupSourceType, ECUM_API_CODE) EcuM_GetValidatedWakeupEvents(void)
{

# if (STD_ON == ECUM_CHECK_UNINIT)
  if (E_OK != EcuM_CheckInit(ECUM_SID_GET_VALIDATED_WAKEUP_EVENTS))
  {

    return ECUM_WKSOURCE_NONE;
  }
  else
  {
    /* Module is initialized */
  }
# endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

  /* Return value from internal variable */

  return EcuM_ValidatedWakeups_t;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

/***********************************************************************************************************************
 *  EcuM_GetExpiredWakeupEvents
 **********************************************************************************************************************/
/*! \brief      Returns all events that have been set and for which validation has failed.
 *              Events which do not need validation must never be reported by this service
 *  \retval     EcuM_WakeupSourceType     Id's of wakeup sources which are expired in the validation process.
 *  \context    Function could be called from interrupt level
 **********************************************************************************************************************/
#if (STD_ON == ECUM_GET_EXPIRED_WAKEUP_EVENTS_API)
FUNC(EcuM_WakeupSourceType, ECUM_API_CODE) EcuM_GetExpiredWakeupEvents(void)
{

# if (STD_ON == ECUM_CHECK_UNINIT)
  if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_EXPIRED_WAKEUP_EVENTS))
  {
    return ECUM_WKSOURCE_NONE;
  }
  else
  {
    /* Module is initialized */
  }
# endif /*(STD_ON == ECUM_CHECK_UNINIT)*/


  /* return value from internal variable */
   return EcuM_ExpiredWakeups_t;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

/***********************************************************************************************************************
 *  EcuM_GetStatusOfWakeupSource
 **********************************************************************************************************************/
/*! \brief      Sum status of all wakeup sources passed in the in parameter.
 *  \param[in]  WakeupSources_t         If of the wakeup source
 *  \retval     EcuM_WakeupStatusType
 *  \context    Function could be called from interrupt level or from task level
 **********************************************************************************************************************/
#if (STD_ON == ECUM_GET_STATUS_OF_WAKEUP_SOURCE_API)
FUNC(EcuM_WakeupStatusType, ECUM_API_CODE) EcuM_GetStatusOfWakeupSource(EcuM_WakeupSourceType WakeupSources_t)
{
  /* local variable to give back the status of wakeup source */
  EcuM_WakeupStatusType wakeupStatus_tloc;


# if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInit(ECUM_SID_GET_STATUS_OF_WAKEUP_SOURCE))
    {

      return (EcuM_WakeupStatusType)ECUM_WKSTATUS_NONE;
    }
    else
    {
      /* Module is initialized */
    }
# endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

  EcuM_GlobalSuspend();

  if ((EcuM_WakeupSourceType)0 == WakeupSources_t)
  {
    wakeupStatus_tloc = (EcuM_WakeupStatusType)ECUM_WKSTATUS_NONE;
  }
  else if ((EcuM_WakeupSourceType)ECUM_WKSOURCE_ALL_SOURCES == WakeupSources_t)
  {
    wakeupStatus_tloc = EcuM_GetSumStatusOfWakeupSource();
  }
  else if (((EcuM_WakeupSourceType)WakeupSources_t >
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
        (uint32)ECUM_MAX_WAKEUP_SOURCE_VALUE) &&
# else
        (EcuM_WakeupSourceType)EcuM_Configuration_pt->MaxWakeupSourceValue_u32) &&
# endif
           ((EcuM_WakeupSourceType)0 == (EcuM_WakeupSourceType)(WakeupSources_t &
                      (EcuM_WakeupSourceType)(WakeupSources_t - (EcuM_WakeupSourceType)1u))))
  {
# if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
      EcuM_Det_Errorhook(ECUM_SID_GET_STATUS_OF_WAKEUP_SOURCE, ECUM_E_UNKNOWN_WAKEUP_SOURCE);
      /* no return here */
# endif /* (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER) */

    wakeupStatus_tloc = EcuM_GetSumStatusOfWakeupSource();
  }
  /*
   * The following else if-statement check if the user wants
   * to know the status of a dedicated wakeup source
   * must be a power of 2 value (for a detailed description
   * see EcuM_SetWakeupEvent())
   */
  else  if ((EcuM_WakeupSourceType)0 == (EcuM_WakeupSourceType)(WakeupSources_t &
                      (EcuM_WakeupSourceType)(WakeupSources_t - (EcuM_WakeupSourceType)1u)))
  {
   /* return Status of the dedicated wakeupsource
    *
    * the following if-statement has an implicit priorisation
    * this is indented due to service description of
    * EcuM_GetStatusOfWakeupSource() in SWS:
    * The sum status shall be computed according to the following
    * algorithm:
    *   - If EcuM_GetValidatedWakeupEvents returns not null then
    *     return ECUM_WKSTATUS_VALIDATED
    *   - If EcuM_GetPendingWakeupEvents returns not null then
    *     return ECUM_WKSTATUS_PENDING
    *   - If EcuM_GetExpiredWakeupEvents returns not null then
    *     return ECUM_WKSTATUS_EXPIRED
    *   - Else return ECUM_WKSTATUS_NONE
    */
    if ((EcuM_WakeupSourceType)0 != (EcuM_ValidatedWakeups_t & WakeupSources_t))
    {
      wakeupStatus_tloc = (EcuM_WakeupStatusType)ECUM_WKSTATUS_VALIDATED;
    }
    else if ((EcuM_WakeupSourceType)0 != (EcuM_PendingWakeups_t & WakeupSources_t))
    {
      wakeupStatus_tloc = (EcuM_WakeupStatusType)ECUM_WKSTATUS_PENDING;
    }
    else if ((EcuM_WakeupSourceType)0 != (EcuM_ExpiredWakeups_t & WakeupSources_t))
    {
      wakeupStatus_tloc = (EcuM_WakeupStatusType)ECUM_WKSTATUS_EXPIRED;
    }
    else
    {
      wakeupStatus_tloc = (EcuM_WakeupStatusType)ECUM_WKSTATUS_NONE;
    }
  }
  else
  {
    /* the user wants to know the status of more than one
     * wakeup source => the SWS is not clear in this point
     * but perform EcuM_GetSumStatusOfWakeupSource() is the
     * most reasonable action here in my opinion.
     */
      wakeupStatus_tloc = EcuM_GetSumStatusOfWakeupSource();
  }
  EcuM_GlobalRestore();


  return wakeupStatus_tloc;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */
#endif

/***********************************************************************************************************************
 *  EcuM_SelectApplicationMode
 **********************************************************************************************************************/
/*! \brief      Stores the application mode in a non-initialized area of RAM.
 *  \param[in]  AppMode_t               Application mode for the next restart.
 *  \retval     E_NOT_OK - error
 *  \retval     E_OK - success
 *  \context    Function could be called from interrupt level or from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_SelectApplicationMode(AppModeType AppMode_t)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_SELECT_APPLICATION_MODE))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

  EcuM_AppMode_t = AppMode_t;


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_GetApplicationMode
 **********************************************************************************************************************/
/*! \brief      Returns the current selected application mode.
 *  \param[out] AppMode_t             current selected application mode
 *  \retval     E_NOT_OK - error
 *  \retval     E_OK - success
 *  \context    Function could be called from interrupt level or from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetApplicationMode(P2VAR(AppModeType, AUTOMATIC, ECUM_APPL_DATA) AppMode_pt)
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_APPLICATION_MODE))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

  /* Perform parameter check if enabled */
#if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    if (NULL_PTR == AppMode_pt)
    {
        EcuM_Det_Errorhook(ECUM_SID_GET_APPLICATION_MODE, ECUM_E_NULL_POINTER);

        return E_NOT_OK;
    }
    else
    {
        /* Nothing to be done here */
    }
#endif

  *AppMode_pt = EcuM_AppMode_t;


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_Rte_SelectApplicationMode
 **********************************************************************************************************************/
/*! \brief      This function wraps the functionality of EcuM_SelectApplicationMode() refer to this function
 *              description.
 *  \param[in]  -
 *  \param[out] -
 *  \retval     -
 *  \pre        -
 *  \context    -
 *  \note       -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_Rte_SelectApplicationMode(EcuM_AppModeType AppMode_t)
{
  return EcuM_SelectApplicationMode((AppModeType)AppMode_t);
} /* EcuM_Rte_SelectApplicationMode() */

/***********************************************************************************************************************
 *  EcuM_Rte_GetApplicationMode
 **********************************************************************************************************************/
/*! \brief      This function wraps the functionality of EcuM_GetApplicationMode() refer to this function
 *              description.
 *  \param[in]  -
 *  \param[out] -
 *  \retval     -
 *  \pre        -
 *  \context    -
 *  \note       -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_Rte_GetApplicationMode
(
  P2VAR(EcuM_AppModeType, AUTOMATIC, ECUM_APPL_DATA) AppMode_pt
)
{
  return EcuM_GetApplicationMode((P2VAR(AppModeType, AUTOMATIC, ECUM_APPL_DATA))AppMode_pt);
} /* EcuM_Rte_GetApplicationMode() */

/***********************************************************************************************************************
 *  EcuM_SelectBootTarget
 **********************************************************************************************************************/
/*! \brief      Sets the boot target for the next boot.
 *  \param[in]  BootTarget_t
 *  \retval     E_NOT_OK - error
 *  \retval     E_OK - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_SelectBootTarget(EcuM_BootTargetType BootTarget_t)
{
  /* This function does not intentionally any uninit check -> no module internal data is set here. */

  /* Perform parameter check if enabled */
#if (STD_ON == ECUM_CHECK_BOOT_TARGET_PARAMETER)
    if (((EcuM_BootTargetType)ECUM_BOOT_TARGET_APP != BootTarget_t) &&
        ((EcuM_BootTargetType)ECUM_BOOT_TARGET_BOOTLOADER != BootTarget_t))
    {
      EcuM_Det_Errorhook(ECUM_SID_SELECT_BOOT_TARGET, ECUM_E_INVALID_PAR);
      return E_NOT_OK;
    }
    else
    {
      /* Parameter is OK */
    }
#endif /* (STD_ON == ECUM_CHECK_BOOT_TARGET_PARAMETER)*/

  return EcuM_Appl_SelectBootTarget(BootTarget_t);
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_GetBootTarget
 **********************************************************************************************************************/
/*! \brief      Returns the current selected boot target of the ECU.
 *  \param[in]  in                      Input parameter
 *  \retval     E_NOT_OK - error
 *  \retval     E_OK - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetBootTarget
  (
    P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) BootTarget_pt
  )
{
  /**
   * This function does not intentionally any uninit check -> no module internal data is set here.
   * No NULL_PTR check is intentionally performed here: The user is responsible to cover such problems in his
   * implementation.
   */

  /* Call user specified callout for retrieving the selected BootTarget */
  return EcuM_Appl_GetBootTarget(BootTarget_pt);
} /* End of EcuM_GetBootTarget() */

/***********************************************************************************************************************
 *  EcuM_MainFunction
 **********************************************************************************************************************/
/*! \brief      Implements all activities of the ECU State Manager while OS is up and
 *              running.
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_MainFunction(void)
{
  uint8 Index_u8loc;



#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_MAIN_FUNCTION))
    {

      return;
    }
    else
    {
      /* Module is initialized */
    }
#endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

  /* Check if ECUM performs Self Run Request */
  if ((uint16)ECUM_NO_TIMEOUT_SET != EcuM_SelfRequestTimeout_u16)
  {
    if ((uint16)0 == EcuM_SelfRequestTimeout_u16)
    {
      /* self run request timed out => stop self run request */
      EcuM_GlobalSuspend();

      EcuM_UserTable_at[ECUM_OWN_USER_NUMBER] &= (EcuM_UserType)(~(EcuM_UserType)ECUM_USER_REQUEST_RUN_MASK); /* PRQA S 0277 *//* MISRA-C:2004 Rule 3.1: this statement has no sideeffects and verified with tests */
      EcuM_RunRequestCounter_t--;
      EcuM_GlobalRestore();

      /* Set the SelfRequest Timeout variable to no timeout indication */
      EcuM_SelfRequestTimeout_u16 = (uint16)ECUM_NO_TIMEOUT_SET;
    }
    else
    {
      EcuM_SelfRequestTimeout_u16--;
    }
  }
  else
  {
    /* No Timeout requested */
  }

  /* Check if WakeupValidation is in Progress */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  for (Index_u8loc = 0; Index_u8loc < (uint8)ECUM_MAX_WAKEUP_SOURCES; Index_u8loc++)
#else
  for (Index_u8loc = 0; Index_u8loc < EcuM_Configuration_pt->MaxNumberOfWakeupSources_u8; Index_u8loc++)
#endif
  {
    if (EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupTimeoutLeft_t !=
       (EcuM_WakeupTimeoutType)ECUM_NO_TIMEOUT_SET)
    {

       /* Calculate the Id of the wakeup source. The current index marks the bit-position. */
      EcuM_WakeupSourceType wakeupSource_tloc = (EcuM_WakeupSourceType)(1u << Index_u8loc);

      /*
       * The wakeup timeout is set for this specific wakeup source. This means EcuM_SetWakeupEvent() has been called
       * for this wakeup source. For wakeup sources which needs validation the callout EcuM_StartWakeupSources() must
       * be executed to prepare the ECU for the following validation of the wakeup event. This callout has to be
       * executed once for each wakeup source, if the validation fails EcuM_StopWakeupSources() for this wakeup source
       * must be called.
       */

      EcuM_GlobalSuspend();
      /* EcuM_StartWakeupSources() should only executed once, check first if it was executed for that wakeup source */
      if (EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupValState_u8 != (uint8)ECUM_WKS_TIMEOUT_STATE_STARTED)
      {
        EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupValState_u8 = (uint8)ECUM_WKS_TIMEOUT_STATE_STARTED;
        EcuM_StartWakeupSources(wakeupSource_tloc);
        
      }
      else
      {
        /* EcuM_StartWakeupSources() already executed for this specific wakeup source. */
      } 
 
      /* Timeout expired without an validation => clear wakeupevent */
      if ((EcuM_WakeupTimeoutType)0 == EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupTimeoutLeft_t)
      {
        /*
         * The timeout expired for that wakeup source. Call EcuM_StopWakeupSources() to configure the ECU for
         * the following sleep (ECU sleep or e.g. Bus sleep).
         */
        EcuM_StopWakeupSources(wakeupSource_tloc);

        /* Remove wakeup from pending list */
        EcuM_PendingWakeups_t &= (EcuM_WakeupSourceType)(~wakeupSource_tloc);

        /* set wakeuptimer to default value */
        EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupTimeoutLeft_t = (EcuM_WakeupTimeoutType)ECUM_NO_TIMEOUT_SET;
        EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupValState_u8 = (uint8)ECUM_WKS_TIMEOUT_STATE_STOPPED;

        /* Add this wakeup event to the expired list */
        EcuM_ExpiredWakeups_t |= wakeupSource_tloc;
      }
      else
      {
        (EcuM_WakeupTimeoutTable_at[Index_u8loc].EcuM_WakeupTimeoutLeft_t)--;

        /* If the timeout has not expired execute callout where the wakeup validation can be performed. */
        EcuM_CheckValidation(wakeupSource_tloc);
      }
      EcuM_GlobalRestore();

    }
    else
    {
        /* No Wakeupvalidation is in progress */
    }
  }

  EcuM_ExitMain_bl = FALSE;

  do
  {
    EcuM_FsmState_t = EcuM_Fsm(EcuM_FsmState_t);

  } while (EcuM_ExitMain_bl != TRUE);


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_StartupTwo
 **********************************************************************************************************************/
/*! \brief      The function implements the startup phase where the OS running.
 *              EcuM_AL_DriverInitTwo is called within this function. This function should be
 *              scheduled by a task directly after StartOS() and only be called once.
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(void, ECUM_API_CODE) EcuM_StartupTwo(void)
{
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    uint8 loopCounter_u8;
#endif


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (EcuM_ModuleState_t != (EcuM_StateType)ECUM_STATE_STARTUP_ONE)
    {
      EcuM_Det_Errorhook(ECUM_SID_STARTUP_TWO, ECUM_E_NOT_INITED);

      return;
    }
    else
    {
      /* module is correct initialized */
    }
#endif

  /* Set Module State */
  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_STARTUP_TWO;

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_SCHM == STD_ON)
      SchM_Init();
# endif
#else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_SCHM_INIT]);
#endif

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverInitTwo(NULL_PTR);
#else
    EcuM_Configuration_pt->DriverInitListTwo();
#endif

#if (STD_ON == ECUM_ON_RTESTARTUP_CALLOUT)
    EcuM_OnRTEStartup();
#endif /*(STD_ON == ECUM_ON_RTESTARTUP_CALLOUT)*/

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_RTE == STD_ON)
      Call_Rte_Start(); /* Nxtr Edit: Perform trusted function call to allow initialization of mode ports in other applications */
# endif
#else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_RTE_START]);
#endif

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverInitThree(NULL_PTR);
#else
    EcuM_Configuration_pt->DriverInitListThree();
#endif

/* if DEM is used it shall be initialized here */
#if (ECUM_INCLUDE_DEM == STD_ON)    
   EcuM_Dem_Initialized_bl = TRUE;
#endif

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_COMM == STD_ON)
      EcuM_ComMNotifyCtrl_t.ComMInitialized_b = TRUE;

      for (loopCounter_u8 = 0; loopCounter_u8 < EcuM_ComMNotifyCtrl_t.BufferCtrl_u8; loopCounter_u8++)
      {
        ComM_EcuM_WakeUpIndication((NetworkHandleType)EcuM_ComMNotifyCtrl_t.ChannelNotifyBuffer_pu8[loopCounter_u8]);
      }
# endif
#else
    /* Set flag variable which indicates that the communication manager is initialized. After the execution of
     * DriverInitListThree the communication manager must be initialized. To ensure data consistency this section
     * must be handled as critical section (variable is read in EcuM_ValidateWakeupEvent())
     */
    EcuM_ComMNotifyCtrl_t.ComMInitialized_b = TRUE;

    /* forward wakeup events on communication channels to the communication manager. BufferCtrl_u8 has stored
     * the appearance of wakeup events on communication channels. If no communication channel is configured
     * the variable must be 0 and the for loop will never executed, so the NULL_PTR check of the buffer could
     * be omitted.
     */
    for (loopCounter_u8 = 0; loopCounter_u8 < EcuM_ComMNotifyCtrl_t.BufferCtrl_u8; loopCounter_u8++)
    {
      EcuM_ComM_WakeUpIndication(EcuM_ComMNotifyCtrl_t.ChannelNotifyBuffer_pu8[loopCounter_u8]);
    }
#endif

  /**
   * If the wakeup event which caused the controller wakeup is one of the five predefined wakeup sources
   * than transit into ECUM_STATE_APP_RUN state and indicate RUN to Rte.
   * If not transit to ECUM_STATE_WAKEUP_VALIDATION state and indicate WAKEUP VALIDATION to Rte.
   */
  if (EcuM_ValidatedWakeups_t != (EcuM_WakeupSourceType)0)
  {
    /* set Startstate of the Fsm to ECUM_INT_STATE_RUN */
    EcuM_FsmState_t = ECUM_INT_STATE_RUN;

    /* Indicate run mode change to Rte will be performed in internal function EcuM_ActEnterRunState() */
    EcuM_ActEnterRunState();
  }
  else
  {
    /* set Startstate of the Fsm to ECUM_INT_STATE_WAKEUP_WITH_POWERCTRL_VALIDATION */
    EcuM_FsmState_t = ECUM_INT_STATE_WAKEUP_WITH_POWERCTRL_VALIDATION;

    /* Set module state which can be retrieved by EcuM_GetState() API */
    EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_VALIDATION;

    /* Indicate sleep mode to Rte */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    if( EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_SLEEP )
    {
      EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_SLEEP;
      ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_SLEEP);
    }
#else
    if( EcuM_PredecessorRteNotifState_t != EcuM_ModeSleep_u8 )
    {
      EcuM_PredecessorRteNotifState_t = EcuM_ModeSleep_u8;
      EcuM_NotifyModeSwitch(EcuM_ModeSleep_u8);
    }
#endif
  }


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_ComM_RequestRUN
 **********************************************************************************************************************/
/*! \brief      This function requests run state for a communication channel. The behavior is
 *              the same as EcuM_RequestRUN.
 *  \param[in]  channel                 network channel
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))

FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_ComM_RequestRUN(NetworkHandleType channel)
{
  return ECUM_FUNC_CALL_REQUEST_RUN(ECUM_SID_COMM_REQUEST_RUN, (EcuM_UserType)channel, ECUM_COMM_CH_REQUEST_RUN_MASK);
} /* End of EcuM_ComM_RequestRUN() */

#endif

/***********************************************************************************************************************
 *  EcuM_ComM_ReleaseRUN
 **********************************************************************************************************************/
/*! \brief      This function releases run state for a communication channel. The behavior is
 *              the same as EcuM_ComM_ReleaseRUN().
 *  \param[in]  channel                 network channel
 *  \retval     E_NOT_OK  - error
 *  \retval     E_OK      - success
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))

FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_ComM_ReleaseRUN(NetworkHandleType channel)
{
  return ECUM_FUNC_CALL_RELEASE_RUN(ECUM_SID_COMM_RELEASE_RUN, (EcuM_UserType)channel, ECUM_COMM_CH_REQUEST_RUN_MASK);
} /* End of EcuM_ComM_ReleaseRUN() */
#endif

/***********************************************************************************************************************
 *  EcuM_ComM_HasRequestedRUN
 **********************************************************************************************************************/
/*! \brief      This function returns the status of the passed communication channel.
 *  \param[in]  channel                 network channel
 *  \retval     TRUE  - channel has run requested
 *  \retval     FALSE - channel has not run requested
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))

FUNC(boolean, ECUM_API_CODE) EcuM_ComM_HasRequestedRUN(NetworkHandleType channel)
{
# if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_COMM_HAS_REQUESTED_RUN))
    {
      return FALSE;
    }
    else
    {
      /* Module is initialized */
    }
# endif /*(STD_ON == ECUM_CHECK_UNINIT)*/

# if (STD_ON == ECUM_CHECK_USER_PARAMETER)
    /* Is channel parameter within the expected range */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    if ((uint8)channel >= (uint8)ECUM_MAX_COMM_USER_COUNT)
# else
    if ((uint8)channel >= EcuM_Configuration_pt->MaxComMUsersCount_u8)
# endif
    {
      EcuM_Det_Errorhook(ECUM_SID_COMM_HAS_REQUESTED_RUN, ECUM_E_INVALID_PAR);

      return FALSE;
    }
    else
    {
      /* channel parameter was in the expected range. */
    }
# endif

  /* Has this channel requested run state? */
  return (boolean)((EcuM_UserType)0 != (EcuM_UserTable_at[channel] & (EcuM_UserType)ECUM_COMM_CH_REQUEST_RUN_MASK));
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

/***********************************************************************************************************************
 *  EcuM_GetStateWrapper
 **********************************************************************************************************************/
/*! \brief      This function encapsulates the EcuM_GetState() API in a function signature which is needed by the
 *              Rte.
 *  \param[in]  user_t                user ID, only needed for the interface definition, implementation does not need
 *                                    this parameter.
 *  \param[out] state_pt              reference to the actually EcuM state.
 *  \retval     E_OK  - function call was successful
 *  \retval     E_NOT_OK - function call was not successfully
 *  \context    Function could be called from task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_API_CODE) EcuM_GetStateWrapper
(
 EcuM_UserType user_t,
 P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) state_pt
)
{
#if (V_USE_DUMMY_STATEMENT == STD_ON)
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    user_t = user_t; /* PRQA S 3199 *//* MISRA-C:2004 redundancy: dummy assignment for unused parameter */
#endif

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ECUM_SID_GET_STATE))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif /*(STD_ON == ECUM_CHECK_UNINIT)*/
#if (STD_ON == ECUM_CHECK_POINTER_PARAMETER)
    if (NULL_PTR == state_pt)
    {
      EcuM_Det_Errorhook(ECUM_SID_GET_STATE, ECUM_E_NULL_POINTER);
      return E_NOT_OK;
    }
    else
    {
      /* Not a NULL_PTR, continue */
    }
#endif

  *state_pt = EcuM_ModuleState_t;
  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Function name:    EcuM_Fsm()

------------------------------------------------------------------------------
    Function Description:
    This function executes the state machine.

------------------------------------------------------------------------------
    Parameter:        InternalState_t       actually state
    Returnvalue:      InternalState_t       new state after processing
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
STATIC FUNC(EcuM_InternalStateType, ECUM_CODE) EcuM_Fsm(EcuM_InternalStateType InternalState_t)
{
  EcuM_InternalStateType EcuM_ReturnState_tloc;

  P2CONST(EcuM_StateChangeIfDescrType, AUTOMATIC, ECUM_CONST) EcuM_CurrExit_ptloc =
    &EcuM_StateDescrTable_at[InternalState_t].ChangeConditions_at[0];


#if (3u == ECUM_NO_OF_STATE_CONDITIONS)
    if (TRUE == EcuM_FsmQuery(EcuM_CurrExit_ptloc->Queries_at))
    {
      EcuM_ReturnState_tloc = EcuM_CurrExit_ptloc->NextState_t;
      EcuM_ActionTable_ap[EcuM_CurrExit_ptloc->Action_t]();
    }
    else if (TRUE == EcuM_FsmQuery((++EcuM_CurrExit_ptloc)->Queries_at)) /* PRQA S 0489 *//* MISRA-C:2004 Rule Rule 17.4: The pointer arithmetic is required to perform state transition in the modules statemachine. The functionality is verified at component test and integration. */
    {
      EcuM_ReturnState_tloc = EcuM_CurrExit_ptloc->NextState_t;
      EcuM_ActionTable_ap[EcuM_CurrExit_ptloc->Action_t]();

    }
    else if (TRUE == EcuM_FsmQuery((++EcuM_CurrExit_ptloc)->Queries_at)) /* PRQA S 0489 *//* MISRA-C:2004 Rule Rule 17.4: The pointer arithmetic is required to perform state transition in the modules statemachine. The functionality is verified at component test and integration. */
    {
      EcuM_ReturnState_tloc = EcuM_CurrExit_ptloc->NextState_t;
      EcuM_ActionTable_ap[EcuM_CurrExit_ptloc->Action_t]();
    }
    else
    {
      EcuM_ReturnState_tloc = EcuM_StateDescrTable_at[InternalState_t].FinalCondition_t.NextState_t;
      EcuM_ActionTable_ap[EcuM_StateDescrTable_at[InternalState_t].FinalCondition_t.Action_t]();
    }
#else
# error "Only case '3 conditions (4 state exits)' is implemented"
#endif


  return EcuM_ReturnState_tloc;
}/* End of EcuM_Fsm()*/

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Function name:    EcuM_FsmQuery()

------------------------------------------------------------------------------
    Function Description:
    ---------------------
    This function executes the Queries which are necessary for a state change.

------------------------------------------------------------------------------
    Parameter:        EcuM_Query_at        array with the queries which should
                                           be interrogated
    Returnvalue:      TRUE                 all queries are TRUE
                      FALSE                one query was FALSE
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
STATIC FUNC(boolean, ECUM_CODE) EcuM_FsmQuery(EcuM_StateQueryPtrType EcuM_Query_at)
{
#if ((2u) == ECUM_NO_OF_QRY_AND)
    /* Currently there are Queries with side-effects, forcing execution in the defined order */
    if (TRUE == EcuM_QueryTable_ap[EcuM_Query_at[0]]())
    {
        return (EcuM_QueryTable_ap[EcuM_Query_at[1]]());
    }
    else
    {
      return FALSE;
    }
#else
# error "Currently two AND-associated queries per state exit are supported"
#endif
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_StartupTwo
 **********************************************************************************************************************/
/*! \brief      This function will be called whenever RUN state is entered.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterRunState(void)
{
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_COMM == STD_ON)
      uint8 loopCounter_u8loc;
# endif
#endif


  /**
   * disable the wakeup sources in case the EcuM was in POST_RUN before
   */
  if(((EcuM_StateType)ECUM_STATE_APP_POST_RUN) == EcuM_ModuleState_t)
  {
    EcuM_InternalDisableWakeupSources();
  }

  /* set the state type on RUN mode */
  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_APP_RUN;

  /* Indicate run mode to Rte */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if(EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_RUN)
  {
    EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_RUN;
    ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_RUN);
  }
#else
  if(EcuM_PredecessorRteNotifState_t != EcuM_ModeRun_u8)
  {
    EcuM_PredecessorRteNotifState_t = EcuM_ModeRun_u8;
    EcuM_NotifyModeSwitch(EcuM_ModeRun_u8);
  }
#endif

#if (STD_ON == ECUM_ON_ENTER_RUN_CALLOUT)
    EcuM_OnEnterRun();
#endif

  /* set the watchdog manager mode for the run state */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_WDGM == STD_ON)
        (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_RUN_MODE);
# endif
#else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_RUN_MODE]);
    }
    else
    {
      /* no WdgM is configured don't call the setmode function */
    }
#endif

  /* Indicate RUN State to COM Manager */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_COMM == STD_ON)
      for (loopCounter_u8loc = 0; loopCounter_u8loc < (uint8)ECUM_MAX_COMM_USER_COUNT; loopCounter_u8loc++)
      {
        ComM_EcuM_RunModeIndication((NetworkHandleType)loopCounter_u8loc);
      }
# endif
#else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_COMM_RUN_MODE_IND]);
#endif

  /* reset the TTII variables */
#if (STD_ON == ECUM_TTII_ENABLED)
    EcuM_CurrentTTII_Index_u8 = 0;

# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      EcuM_TTII_Divisor_t = EcuM_TTII_DivisorList_at[EcuM_CurrentTTII_Index_u8];
# else
      EcuM_TTII_Divisor_t = EcuM_Configuration_pt->TTII_DivisorList_pt[EcuM_CurrentTTII_Index_u8];
# endif
#endif

  /* Start RUN Self Request */
  EcuM_GlobalSuspend();
  EcuM_UserTable_at[ECUM_OWN_USER_NUMBER] |= (EcuM_UserType)ECUM_USER_REQUEST_RUN_MASK;
  EcuM_RunRequestCounter_t++;
  EcuM_GlobalRestore();

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_SelfRequestTimeout_u16 = (uint16)ECUM_SELF_REQUEST_PERIOD;
#else
    EcuM_SelfRequestTimeout_u16 = EcuM_Configuration_pt->SelfRequestPeriod_t;
#endif

  /* set flag for exiting EcuM_MainFunction() */
  EcuM_ExitMain_bl = TRUE;


  return;
} /* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_ActExitRunState
 **********************************************************************************************************************/
/*! \brief    This function is called if RUN state will be left. This function notifies the Rte about a modechange from
 *            RUN into POST RUN state.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActExitRunState(void)
{
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    uint8 loopCounter_u8loc;
#endif



#if (STD_ON == ECUM_ON_EXIT_RUN_CALLOUT)
    EcuM_OnExitRun();
#endif

  /* set the watchdog mode for the post run state */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_POST_RUN_MODE);
# endif
#else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_POST_RUN_MODE]);
    }
    else
    {
      /* no WdgM is configured, don't call this function */
    }
#endif

  /* Notify RTE about mode switch event to POST RUN */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if(EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_POST_RUN)
  {
    EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_POST_RUN;
    ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_POST_RUN);
  }
#else
  if(EcuM_PredecessorRteNotifState_t != EcuM_ModePostRun_u8)
  {
    EcuM_PredecessorRteNotifState_t = EcuM_ModePostRun_u8; 
    EcuM_NotifyModeSwitch(EcuM_ModePostRun_u8);
  }
#endif

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_APP_POST_RUN;

  /* Set NvM Jobstatus variable for the next sleep state */
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    EcuM_NvM_JobStatus_t = NVM_REQ_PENDING;
#endif

  /* Clear wakeup event variables. Prepare the system for the shutdown phase. */
  EcuM_GlobalSuspend();

  /**
   * Check if any wakeup source which is connected to a ComM channel has raised a wakeup event, if such a wakeup event
   * occurs go back to run state. It is assumed that only communication channels can raise new wakeup events while
   * exiting run state.
   */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_COMM == STD_ON)
      for (loopCounter_u8loc = 0; loopCounter_u8loc < (uint8)ECUM_MAX_WAKEUP_SOURCES; loopCounter_u8loc++)
      {
        if (
            (EcuM_WakeupSourceList_at[loopCounter_u8loc].EcuM_ComMChannel_t != 255) &&
            ((EcuM_ValidatedWakeups_t & ((EcuM_WakeupSourceType)1 << loopCounter_u8loc)) != (EcuM_WakeupSourceType)0)
           )
        {
          EcuM_GlobalRestore();
          return;
        }
      }
# endif
#else
      for (
            loopCounter_u8loc = 0;
            loopCounter_u8loc < EcuM_Configuration_pt->MaxNumberOfWakeupSources_u8;
            loopCounter_u8loc++
          )
      {
        if (
            (EcuM_Configuration_pt->WakeupSourceList_pt[loopCounter_u8loc].EcuM_ComMChannel_t != 255) &&
            ((EcuM_ValidatedWakeups_t & ((EcuM_WakeupSourceType)1 << loopCounter_u8loc)) != (EcuM_WakeupSourceType)0)
           )
        {
          EcuM_GlobalRestore();
          return;
        }
      }
#endif

  EcuM_ValidatedWakeups_t = (EcuM_WakeupSourceType)0;
  EcuM_ExpiredWakeups_t   = (EcuM_WakeupSourceType)0;
  EcuM_CurrentSleepModeIndex_u8 = EcuM_ShutdownTargetSleepIndex_u8;

  /* call callout which configures the wakeupsources */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_OFF)
    {
      EcuM_EnableWakeupSources(ECUM_WKSOURCE_ALL_SOURCES);
    }
# if (ECUM_MAX_SLEEP_MODES != 0u)
    else if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_SLEEP)
    {
        /* Enable wakeup sources configured for this sleep mode */
        EcuM_EnableWakeupSources(EcuM_SleepModeList_at[EcuM_CurrentSleepModeIndex_u8].wakeupSource);
    }
# endif
    else
    {
      /* Shutdowntarget is RESET, so don't activate Wakeupsources */
    }
#else
    if ((EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_SLEEP) &&
        ((uint8)0 != EcuM_Configuration_pt->MaxSleepModes_u8))
    {
      /* Enable wakeup sources configured for this sleep mode */
      EcuM_EnableWakeupSources(EcuM_Configuration_pt->SleepModeList_pt[EcuM_CurrentSleepModeIndex_u8].wakeupSource);
    }
    else if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_OFF)
    {
      EcuM_EnableWakeupSources(ECUM_WKSOURCE_ALL_SOURCES);
    }
    else
    {
      /* Shutdowntarget is RESET, so don't activate Wakeupsources */
    }
#endif

  /* Re-enable Interrupts */
  EcuM_GlobalRestore();


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_ActExitPostRunState
 **********************************************************************************************************************/
/*! \brief    This function is called if POST RUN state will be left.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActExitPostRunState(void)
{


#if (STD_ON == ECUM_ON_EXIT_POST_RUN_CALLOUT)
    EcuM_OnExitPostRun();
#endif

  EcuM_ActPerformPrepShutdown();


  return;
} /* End of EcuM_ActExitPostRunState() */

/***********************************************************************************************************************
 *  EcuM_ActGoToSleep
 **********************************************************************************************************************/
/*! \brief    Within this function the actually selected Sleep mode will be selected by calling Mcu_SetMode().
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
STATIC FUNC(void, ECUM_CODE) EcuM_ActGoToSleep(void)
{
  /* Get the sleep mode configuration */
  P2CONST(EcuM_SleepModeConfigType, AUTOMATIC, ECUM_CONST) currentSleepMode_tloc =
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
        &EcuM_SleepModeList_at[EcuM_CurrentSleepModeIndex_u8];
# else
        &EcuM_Configuration_pt->SleepModeList_pt[EcuM_CurrentSleepModeIndex_u8];
# endif


  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_SLEEP;

  /* Disable Interrupts and check if a new wakeup event was reported */
  EcuM_DisableAllWakeupInterrupts();

  if ((EcuM_PendingWakeups_t == (EcuM_WakeupSourceType)0u) && (EcuM_ValidatedWakeups_t == (EcuM_WakeupSourceType)0u)) /* PRQA S 3415 *//* MISRA-C:2004 Rule 12.4: No side effect - right hand is read only */
  {

    /* Set the Mcu into sleep state */
    EcuM_McuSetMode(currentSleepMode_tloc->mcuMode);

  }
  else
  {
    EcuM_EnableAllWakeupInterrupts();
  }


  return;
} /* End of EcuM_ActGoToSleep() */
#endif

/***********************************************************************************************************************
 *  EcuM_ActPerformPrepShutdown
 **********************************************************************************************************************/
/*! \brief    Executes all the activities required withing PREP SHUTDOWN state.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformPrepShutdown(void)
{

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_PREP_SHUTDOWN;

  /* callout call */
#if (STD_ON == ECUM_ON_PREP_SHUTDOWN_CALLOUT)
  EcuM_OnPrepShutdown();
#endif

  /* De-initialize DEM */
# if (ECUM_INCLUDE_DEM == STD_ON)  
 #if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  Dem_Shutdown();
 #else
  EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_DEM_SHUTDOWN]);
 #endif
  EcuM_Dem_Initialized_bl = FALSE;
#endif


  return;
} /* End of EcuM_ActPerformPrepShutdown() */

/***********************************************************************************************************************
 *  EcuM_ActEnterGoOffOne
 **********************************************************************************************************************/
/*! \brief    Executes all the activities required withing GO OFF ONE state.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterGoOffOne(void)
{

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_GO_OFF_ONE;

  /* indicate Rte about shutdown mode */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if(EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_SHUTDOWN)
  {
    EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_SHUTDOWN;
    ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_SHUTDOWN);
  }
#else
  if(EcuM_PredecessorRteNotifState_t != EcuM_ModeShutdown_u8)
  {
    EcuM_PredecessorRteNotifState_t = EcuM_ModeShutdown_u8;
    EcuM_NotifyModeSwitch(EcuM_ModeShutdown_u8);
  }
#endif

  /* call callout */
#if (STD_ON == ECUM_ON_GO_OFF_ONE_CALLOUT)
    EcuM_OnGoOffOne();
#endif /*#if (STD_ON == ECUM_ON_GO_OFF_ONE_CALLOUT)*/

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
   /**
    * If NvM_WriteAll() was already invoked, there is no need
    * to invoke NvM_WriteAll() again. A other reason of preventing
    * invoking NvM_WriteAll() again is, that the EcuM has occupied
    * the Scheduler and NvM_MainFunction will not being called.
    * A additional NvM_WriteAll() call may have the consequence,
    * that the end notification will come very late and will set
    * the EcuM_NvM_JobStatus_t to a value != NVM_REQ_PENDING which
    * will have the consequence that for the next sleep mode
    * NvM_WriteAll() will not be invoked.
    * Date of decision: 28. November, 2006: Tds, Pp, Chm
    */
    if ((NvM_RequestResultType)NVM_REQ_PENDING == EcuM_NvM_JobStatus_t)
    {
     /* This is the first call to NvM_WriteAll(). => The Scheduler
      * is not occupied yet, so NvM will get the chance to execute
      * the WriteAll request.
      */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
        NvM_WriteAll();
# else
        EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_NVM_WRITEALL]);
# endif
        /* 
         * necessary for NvM_CancelWriteAll.
         * In case of a normal SLEEP or STARTUP transition, it is not allowed to wait on NvM
         * callback notification in EcuM STATE WAKEUP_REACTION
         */
        EcuM_NvM_WriteAllStarted_bl = TRUE;
    }
    else
    {
        /* Intentionally left free */
    }
#endif /*#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR) */

  /* Set the watchdog manager mode for the shutdown phase. */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_SHUTDOWN_MODE);
# endif
#else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_SHUTDOWN_MODE]);
    }
    else
    {
      /* no WdgM is configured, don't call this function */
    }
#endif


  return;
} /* End of EcuM_ActEnterGoOffOne() */

/***********************************************************************************************************************
 *  EcuM_ActEnterGoSleep
 **********************************************************************************************************************/
/*! \brief    This function executes the activities which have to be performed in GO SLEEP state.
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterGoSleep(void)
{

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_GO_SLEEP;

  /* indicate EcuM about sleep mode */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if(EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_SLEEP)
  {
    EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_SLEEP;
    ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_SLEEP);
  }
# else
  if(EcuM_PredecessorRteNotifState_t != EcuM_ModeSleep_u8)
  {
    EcuM_PredecessorRteNotifState_t = EcuM_ModeSleep_u8;
    EcuM_NotifyModeSwitch(EcuM_ModeSleep_u8);
  }
# endif

  /* call callout */
# if (STD_ON == ECUM_ON_GO_SLEEP_CALLOUT)
    EcuM_OnGoSleep();
# endif

  /* Write back non volatile memory contents */
# if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
     /*
      * If NvM_WriteAll() was already invoked, there is no need
      * to invoke NvM_WriteAll() again. A other reason of preventing
      * invoking NvM_WriteAll() again is, that the EcuM has occupied
      * the Scheduler and NvM_MainFunction will not being called.
      * A additional NvM_WriteAll() call may have the consequence,
      * that the end notification will come very late and will set
      * the EcuM_NvM_JobStatus_t to a value != NVM_REQ_PENDING which
      * will have the consequence that for the next sleep mode
      * NvM_WriteAll() will not be invoked.
      * Date of decision: 28. November, 2006: Tds, Pp, Chm
      */
    if ((NvM_RequestResultType)NVM_REQ_PENDING == EcuM_NvM_JobStatus_t)
    {
     /* This is the first call to NvM_WriteAll(). => The Scheduler
      * is not occupied yet, so NvM will get the chance to execute
      * the WriteAll request.
      */
#  if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
        NvM_WriteAll();
#  else
        EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_NVM_WRITEALL]);
#  endif
        /* 
         * necessary for NvM_CancelWriteAll.
         * In case of a normal SLEEP or STARTUP transition, it is not allowed to wait on NvM
         * callback notification in EcuM STATE WAKEUP_REACTION
         */
        EcuM_NvM_WriteAllStarted_bl = TRUE;
    }
    else
    {
      /* Intentionally left free */
    }
# endif /*#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)*/


  return;
} /* End of EcuM_ActEnterGoSleep() */
#endif

/***********************************************************************************************************************
 *  EcuM_ActPerformWakeupOne
 **********************************************************************************************************************/
/*! \brief    This function executes action which have to performed in WAKEUP ONE state.
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupOne(void)
{
  uint8 EcuM_RamValid_u8loc;


  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_ONE;

  /* Set the watchdog manager mode for the wakeup phase */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
#  if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_WAKEUP_MODE);
#  endif
# else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_WAKEUP_MODE]);
    }
    else
    {
      /* no WdgM is configured, don't call this function */
    }
# endif

  /* Check RAM Hash */
  EcuM_RamValid_u8loc = EcuM_CheckRamHash();

  if ((uint8)0 != EcuM_RamValid_u8loc)
  {
    /* RAM content is valid Restart Drivers */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverRestart();
# else
      EcuM_Configuration_pt->DriverRestart();
# endif

#  if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      (void)ReleaseResource(RES_SCHEDULER);
#  else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_OS_RELEASE_RES_SCHEDULER]);
#  endif

    EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_VALIDATION;
  }
  else
  {
    /* Report Error to DEM */
# if (STD_ON == ECUM_ENABLE_PROD_ERROR_REPORTING)
      EcuM_SetError(EcuM_RamCheckFailedError_t, DEM_EVENT_STATUS_FAILED);
# endif /*(STD_ON == ECUM_INCLUDE_DEM)*/

    /* RAM content is not valid perform RESTART */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      Mcu_PerformReset();
# else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_MCU_PERFORM_RESET]);
# endif
  }


  return;
} /* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */
#endif

/***********************************************************************************************************************
 *  EcuM_ActPerformWakeupOne2
 **********************************************************************************************************************/
/*! \brief    This function executes action which have to performed in WAKEUP ONE state from the GO OFF I state. The
 *            activities are different to entering wakeup one from sleep state. Here no RAM hash must be generated and
 *            scheduler must not be released.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupOne2(void)
{

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_ONE;

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    /* Cancel writing of non-volatile memory */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      NvM_CancelWriteAll();
# else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_NVM_CANCEL_WRITEALL]);
# endif
    /* store the configured timeout value for NvM_WriteAll */
    NvmCancelWriteAllTimeout_u32 = EcuM_GetNvMCancelWriteAllTimeout();
#endif /*(STD_ON == ECUM_INCLUDE_NVRAM_MGR) */

  /* Set the watchdog manager mode for the wakeup phase */
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_WAKEUP_MODE);
# endif
#else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_WAKEUP_MODE]);
    }
    else
    {
      /* no WdgM is configured, don't call this function */
    }
#endif

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverRestart();
#else
    EcuM_Configuration_pt->DriverRestart();
#endif

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_VALIDATION;

  return;
} /* End of EcuM_ActPerformWakeupOne2() */

/***********************************************************************************************************************
 *  EcuM_ActCancelSleepProcess
 **********************************************************************************************************************/
/*! \brief    This function is called if a wakeup event is occurred while going into
 *            sleep state. This function cancels all write processes of the NVM and
 *            restarts the Drivers which were prepared for going into sleep state.
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
STATIC FUNC(void, ECUM_CODE) EcuM_ActCancelSleepProcess(void)
{

  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_VALIDATION;

# if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
    /* Cancel writing of non-volatile memory */
#  if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
      NvM_CancelWriteAll();
#  else
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_NVM_CANCEL_WRITEALL]);
#  endif
    /* store the configured timeout value for NvM_WriteAll */
    NvmCancelWriteAllTimeout_u32 = EcuM_GetNvMCancelWriteAllTimeout();
# endif /*(STD_ON == ECUM_INCLUDE_NVRAM_MGR) */

  /* Set the watchdog manager mode for the wakeup phase */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
#  if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)ECUM_WDGM_WAKEUP_MODE);
#  endif
# else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->WatchdogManagerModes_pau8[ECUM_WDGM_WAKEUP_MODE]);
    }
    else
    {
      /* no WdgM is configured, don't call this function */
    }
# endif

  /* Restart Drivers */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    EcuM_AL_DriverRestart();
# else
    EcuM_Configuration_pt->DriverRestart();
# endif


  return;
} /* End of EcuM_ActCancelSleepProcess() */
#endif
/***********************************************************************************************************************
 *  EcuM_ActPerformWakeupReactionFromStartup
 **********************************************************************************************************************/
/*! \brief   This service executes the actions which should invoked within WAKEUP REACTION state and some additionally
/*           actions which are necessary for a startup with integrated pwoer control.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupReactionFromStartup(void)
{
  /* check if a valid wakeup exists */
  if ((EcuM_WakeupSourceType)0 == EcuM_ValidatedWakeups_t)
  {
    /* No wakeup event was valid -> prepare SHUTDOWN, call Dem_Shutdown */
# if (ECUM_INCLUDE_DEM == STD_ON)
  #if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    Dem_Shutdown();
  #else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_DEM_SHUTDOWN]);
  #endif
    EcuM_Dem_Initialized_bl = FALSE;
#endif  
   }
   else
   {
     /* wakeup was valid -> transit into RUN state, no Dem_Shutdown necessary */
   }
   /* call EcuM_ActPerformWakeupReaction to perform a SHUTDOWN or to switch into RUN state */
   EcuM_ActPerformWakeupReaction();
   return;
}
/***********************************************************************************************************************
 *  EcuM_ActPerformWakeupReaction
 **********************************************************************************************************************/
/*! \brief   This service executes the actions which should invoked within WAKEUP REACTION state.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupReaction(void)
{

#if (STD_ON == ECUM_ON_WAKEUP_REACTION_CALLOUT)
    EcuM_WakeupReactionType TmpWakeupReaction_tloc;
#endif /*(STD_ON == ECUM_ON_WAKEUP_REACTION_CALLOUT)*/


  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_REACTION;

#if (STD_ON == ECUM_TTII_ENABLED)
    if ((EcuM_WakeupSourceType)0 == EcuM_ValidatedWakeups_t)
    {
      /* No wakeup event was valid -> continue with shutdown */
      EcuM_WakeupReaction_t = (EcuM_WakeupReactionType)ECUM_WKACT_SHUTDOWN;
    }
    else if ((EcuM_WakeupSourceType)0 !=
             (EcuM_ValidatedWakeups_t ^ (EcuM_WakeupSourceType)(ECUM_WKSOURCE_TTII_TIMER)))
    {
      /* a valid wakeup besides TTII Counter occurred, this is the more
       * important case therefore, set Wakeupreaction to RUN and ignore
       * the execution of TTII protocol */
      EcuM_WakeupReaction_t = (EcuM_WakeupReactionType)ECUM_WKACT_RUN;
    }
    else
    {
      /* ((EcuM_NewValidWakeups_t & ECUM_WAKEUP_SOURCE_TTII_TIMER) != 0u)
      * The TTII Counter was the wakeupsource
      */
      EcuM_WakeupReaction_t = (EcuM_WakeupReactionType)ECUM_WKACT_TTII;

     /* notify mode change to RTE, if Shutdowntarget is sleep: ECUM_MODE_WAKESLEEP
      * Note: Rte does not support this feature at the moment
      */
    }
#else /*(STD_ON == ECUM_TTII_ENABLED)*/
    if ((EcuM_WakeupSourceType)0 != EcuM_ValidatedWakeups_t)
    {
      EcuM_WakeupReaction_t = (EcuM_WakeupReactionType)ECUM_WKACT_RUN;
    }
    else
    {
      EcuM_WakeupReaction_t = (EcuM_WakeupReactionType)ECUM_WKACT_SHUTDOWN;
    }
#endif /* (STD_ON == ECUM_ENABLE_TTII)*/

  /* call callout */
#if (STD_ON == ECUM_ON_WAKEUP_REACTION_CALLOUT)
    TmpWakeupReaction_tloc = EcuM_OnWakeupReaction(EcuM_WakeupReaction_t);
    switch (TmpWakeupReaction_tloc)
    {
      case ECUM_WKACT_RUN:
      case ECUM_WKACT_TTII:
      case ECUM_WKACT_SHUTDOWN:
        EcuM_WakeupReaction_t = TmpWakeupReaction_tloc;
        break;
      default:
        /*
         * The user has not returned a valid wakeup reaction so
         * don't change the computed wakeup reaction from system
         */

        return;
    }
#endif /*(STD_ON == ECUM_ON_WAKEUP_REACTION_CALLOUT)*/


  return;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

/***********************************************************************************************************************
 *  EcuM_ActShutdownSystem
 **********************************************************************************************************************/
/*! \brief    Prepares the ECU for Shutdown
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActShutdownSystem(void)
{

  EcuM_GlobalSuspend();
  /* Reset the Module-flags */
  EcuM_ModulFlags_u8 = 0;

  /* Set EcuM_LastShutdownTarget_t */
  EcuM_LastShutdownTarget_t.DefaultState_t = EcuM_ShutdownTarget_t;
  EcuM_LastShutdownTarget_t.DefaultSleepMode_u8 = EcuM_CurrentSleepModeIndex_u8;

  //EcuM_GlobalRestore(); Nxtr change to correct anomaly 2097 - interrupt protection restore moved to
  //                      just below Mcu_PerformReset() to address OS tasks being allowed to run  
  //                      while alarms are in the process of being cancelled during Rte_Stop().
  //		              Date: 02/27/12 -  version: 4 - Author: BDO - CR: 4990 
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
# if (ECUM_INCLUDE_RTE == STD_ON)
      (void)Rte_Stop();
# endif
# if (ECUM_INCLUDE_COMM == STD_ON)
      ComM_DeInit();
# endif

# if defined( VECTOR_POLYSPACE_TEST )
      /* No ShutdownOS is to be called for POLYSPACE */
# else /* VECTOR_POLYSPACE_TEST */
    ShutdownOS(E_OK);
# endif /* VECTOR_POLYSPACE_TEST */

    Mcu_PerformReset();
    EcuM_GlobalRestore(); //Nxtr change to correct anomaly 2097 - add interrupt protection around shutdown preparation.
#else
    /* Stop the RTE */
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_RTE_STOP]);

    /* De-initialize COM Manager */
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_COMM_DEINIT]);

# if defined( VECTOR_POLYSPACE_TEST )
      /* No ShutdownOS is to be called for POLYSPACE */
# else /* VECTOR_POLYSPACE_TEST */
      /*  Shutdown the Operating System */
      EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_OS_SHUTDOWN_OS]);
# endif /* VECTOR_POLYSPACE_TEST */

    /* This call should never been executed, it is only inserted for security reasons
      * in the case the ShutdownOS call will not succeed. */
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_MCU_PERFORM_RESET]);
#endif


  return;
} /* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

/***********************************************************************************************************************
 *  EcuM_ActWaitOnNvMCancelWriteAll
 **********************************************************************************************************************/
/*! \brief    Waits until NvM_CancelWriteAll has stopped the NvM_WriteAll job
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActWaitOnNvMCancelWriteAll(void)
{
#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)

  if( NvmCancelWriteAllTimeout_u32 > 0)
  {
    /* decrement the waitiing counter */
    NvmCancelWriteAllTimeout_u32--;
  }
  else
  {

    /* WriteAll shall get stopped */
    EcuM_NvMKillWriteAll();
    /* set the condition for EcuM_QryIsNvMWriteAllRunning */
    EcuM_NvM_WriteAllStarted_bl = FALSE;
  }

#endif
  /* leave MainFunction */
  EcuM_ActNopWithExit();
}/* End of EcuM_QryIsStartupTwoState() */


/***********************************************************************************************************************
 *  EcuM_ActPerformWakeSleepOp
 **********************************************************************************************************************/
/*! \brief    If TTII Protocol is enabled and selected, the TTII protocol will be executed within this function.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeSleepOp(void)
{

  /**
   * According to ECUM SWS 1.2.0: EcuM shall indicate wakesleep mode AND sleep mode when transiting from
   * wakeup to shutdown.
   */

#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if(EcuM_PredecessorRteNotifState_t != ECUM_INT_MODE_WAKE_SLEEP)
  {
    EcuM_PredecessorRteNotifState_t = ECUM_INT_MODE_WAKE_SLEEP;
    ECUM_NOTIFY_MODE_SWITCH(ECUM_INT_MODE_WAKE_SLEEP);
  }
#else
  if(EcuM_PredecessorRteNotifState_t != EcuM_ModeWakeSleep_u8)
  {
    EcuM_PredecessorRteNotifState_t = EcuM_ModeWakeSleep_u8;
    EcuM_NotifyModeSwitch(EcuM_ModeWakeSleep_u8);
  }
#endif

#if (STD_ON == ECUM_TTII_ENABLED)
    if ((EcuM_WakeupReactionType)ECUM_WKACT_TTII == EcuM_WakeupReaction_t)
    {
      /* execute TTII Protocol */
      EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_TTII;

      /* Only clear the wakeup event which is connected to the TTII wakeup source. Wakeup events which are caused by
       * other wakeup source must not be cleared here else the controller will remain in sleep mode. Dependent on the
       * type of wakeup event e.g. occurs only once the controller will never wake up.
       */
      EcuM_GlobalSuspend();
      EcuM_ValidatedWakeups_t  &= ~(ECUM_WKSOURCE_TTII_TIMER);
      EcuM_GlobalRestore();

      /**
       * Check if the TTII timeout has expired:
       * - the timeout must be greater than one
       * - the maximum number of TTII sleep modes must be greater than one
       */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
        if ((EcuM_TTII_Divisor_t <= (EcuM_TTII_DivisorType)(1u)) &&
            ((EcuM_CurrentTTII_Index_u8 + 1) < (uint8)ECUM_MAX_TTII_SLEEP_MODES))
        {
          /* There are more TTII sleep modes */
          EcuM_CurrentTTII_Index_u8++;
          EcuM_CurrentSleepModeIndex_u8 = EcuM_TTII_SuccessorList_at[EcuM_CurrentTTII_Index_u8];
          EcuM_TTII_Divisor_t = EcuM_TTII_DivisorList_at[EcuM_CurrentTTII_Index_u8];
        }
# else
        if ((EcuM_TTII_Divisor_t <= (EcuM_TTII_DivisorType)(1u)) &&
            ((EcuM_CurrentTTII_Index_u8 + 1) < EcuM_Configuration_pt->Max_TTII_SleepModes_u8))
        {
          /* There are more TTII sleep modes */
          EcuM_CurrentTTII_Index_u8++;
          EcuM_CurrentSleepModeIndex_u8 = EcuM_Configuration_pt->TTII_SuccesorList_pt[EcuM_CurrentTTII_Index_u8];
          EcuM_TTII_Divisor_t = EcuM_Configuration_pt->TTII_DivisorList_pt[EcuM_CurrentTTII_Index_u8];
        }
# endif
        else
        {
          /* Adapt TTIIDivisor */
          EcuM_TTII_Divisor_t--;
        }
      }
      else
      {
        /* Set module state accordingly */
        EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_WAKESLEEP;
      }
#else /*(TRUE == ECUM_ENABLE_TTII)*/
    EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_WAKESLEEP;
#endif /*(TRUE == ECUM_ENABLE_TTII)*/


  return;
} /* End of EcuM_ActPerformWakeSleepOp() */

/***********************************************************************************************************************
 *  EcuM_ActPerformWakeupTwo
 **********************************************************************************************************************/
/*! \brief    This function executes WAKEUP TWO activities.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActPerformWakeupTwo(void)
{
  EcuM_ModuleState_t = (EcuM_StateType)ECUM_STATE_WAKEUP_TWO;

  EcuM_InternalDisableWakeupSources();

  /* Initialize Dem if configured and if it is not initializet till now 
   * check with DEM switch is in each configuration variant possible,
   * because it is generated in each case
   */
# if (ECUM_INCLUDE_DEM == STD_ON)  
  if(EcuM_Dem_Initialized_bl != TRUE)
  {
  #if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    Dem_Init();
  #else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_DEM_INIT]);
  #endif
    EcuM_Dem_Initialized_bl = TRUE;
  }
#endif

  /* Execute the Entry activities for RUN state */
  EcuM_ActEnterRunState();


  return;
} /* End of EcuM_ActPerformWakeupTwo() */

/***********************************************************************************************************************
 *  EcuM_ActNopWithExit
 **********************************************************************************************************************/
/*! \brief    This function will be called if the ECUM has nothing to do. This function exits the Main Function.
 **********************************************************************************************************************/
STATIC FUNC(void, ECUM_CODE) EcuM_ActNopWithExit(void)
{

  EcuM_ExitMain_bl = TRUE;


  return;
} /* End of EcuM_ActNopWithExit() */

/***********************************************************************************************************************
 *  EcuM_ActEnterSleepState
 **********************************************************************************************************************/
/*! \brief    This function prepares the ECU for going into sleep state. It reserves the
 *            scheduler for the ECUM to ensure that no rescheduling will take place
 *            after a wakeup event. Moreover this function generates a RAM Hash to
 *            ensure a valid RAM after a sleep phase.
 **********************************************************************************************************************/
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_MAX_SLEEP_MODES != 0u)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
STATIC FUNC(void, ECUM_CODE) EcuM_ActEnterSleepState(void)
{

  /* Set the configured watchdog mode for the following sleep mode */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
#  if (ECUM_INCLUDE_WDGM == STD_ON)
      (void)WdgM_SetMode((WdgM_ModeType)EcuM_SleepModeList_at[EcuM_CurrentSleepModeIndex_u8].WatchdogMode_u8);
#  endif
# else
    if ((uint8)0 != (EcuM_Configuration_pt->UsedModules_u8 & (uint8)ECUM_WDGM_USED))
    {
      EcuM_WdgM_SetMode(EcuM_Configuration_pt->SleepModeList_pt[EcuM_CurrentSleepModeIndex_u8].WatchdogMode_u8);
    }
    else
    {
      /* no WdgM configured don't call this function */
    }
# endif

#  if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    (void)GetResource(RES_SCHEDULER);
#  else
    EcuM_InternalCall(EcuM_Configuration_pt->CallId_au8[(uint8)ECUM_CALL_OS_GET_RES_SCHEDULER]);
#  endif

  /* Generate RAM Hash */
  EcuM_GlobalSuspend();
  EcuM_GenerateRamHash();
  EcuM_GlobalRestore();

  /* Set last shutdown target to sleep-state and its according mode. */
  EcuM_LastShutdownTarget_t.DefaultState_t = (EcuM_StateType)ECUM_STATE_SLEEP;
  EcuM_LastShutdownTarget_t.DefaultSleepMode_u8 = EcuM_CurrentSleepModeIndex_u8;


  return;
} /* End of EcuM_ActEnterSleepState() */
#endif

/***********************************************************************************************************************
 *  EcuM_ActEcuMError
 **********************************************************************************************************************/
/*! \brief    This function will be only called if after ShutdownOS() EcuM_Mainfunction is invoked => Error in OS or
 *            EcuM_Shutdown() is not used in ErrorHook.
 **********************************************************************************************************************/
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
STATIC FUNC(void, ECUM_CODE) EcuM_ActEcuMError(void)
{

  /* Report error to DET */
  EcuM_Det_Errorhook(ECUM_SID_MAIN_FUNCTION, ECUM_E_WRONG_ECUM_USAGE);
  EcuM_ExitMain_bl = TRUE;


  return;
} /* End of EcuM_ActEcuMError() */
#endif
/*********************************************************************************************************************
    IMPLEMENTATION OF PARAMETER CHECK FUNCTIONS
**********************************************************************************************************************/
#if (STD_ON == ECUM_CHECK_UNINIT)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckInitStartupTwo(uint8 ApiId)
{

  if (EcuM_ModuleState_t <= (EcuM_StateType)ECUM_STATE_STARTUP_TWO)
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_NOT_INITED);

    return E_NOT_OK;
  }
  else
  {

    return E_OK;
  }
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

#if (STD_ON == ECUM_CHECK_UNINIT)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckInit(uint8 ApiId)
{

  if (EcuM_ModuleState_t < (EcuM_StateType)ECUM_STATE_STARTUP_ONE)
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_NOT_INITED);

    return E_NOT_OK;
  }
  else
  {

    return E_OK;
  }
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

#if (STD_ON == ECUM_CHECK_USER_PARAMETER)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckUserParameter(uint8 ApiId, EcuM_UserType user, uint8 mask)
{

  /* is this a run request from the normal user list. */
  if (((EcuM_UserType)(ECUM_OWN_USER_NUMBER) == user) && (mask != (uint8)ECUM_COMM_CH_REQUEST_RUN_MASK))
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_INVALID_PAR);

    return E_NOT_OK;
  }
  else
  {
    /* Intentionally left free */
  }

  if ((mask & (uint8)ECUM_COMM_CH_REQUEST_RUN_MASK) == (uint8)0)
  {
    /* user is a normal user
     * Make sure that User is within expected range:
     * Note: normal users begins with 1, so if 5 users are configured
     * MaxUsersCount := 5 -> 5 is the last valid value.
     */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    if (user > (EcuM_UserType)ECUM_MAX_USER_COUNT)
# else
    if (user > (EcuM_UserType)EcuM_Configuration_pt->MaxUsersCount_u8)
# endif
    {
      /* User_t parameter is not in range */
      EcuM_Det_Errorhook(ApiId, ECUM_E_INVALID_PAR);

      return E_NOT_OK;
    }
    else
    {
      /* user is configured */
    }
  }
# if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
     || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  else
  {
    /* Make sure that ComM User is within expected range:
     * Note: ComM user begins with 0, so if 4 channels configured MaxComMUsersCount := 4
     * -> 3 is the last valid value.
     */
#  if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    if (user >= (EcuM_UserType)ECUM_MAX_COMM_USER_COUNT)
#  else
    if (user >= (EcuM_UserType)EcuM_Configuration_pt->MaxComMUsersCount_u8)
#  endif
    {
      /* User_t parameter is not in range */
      EcuM_Det_Errorhook(ApiId, ECUM_E_INVALID_PAR);

      return E_NOT_OK;
    }
    else
    {
      /* user is configured */
    }
  }
# endif


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

#if (STD_ON == ECUM_CHECK_WK_SOURCE_PARAMETER)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckWKSourceParameter(uint8 ApiId, EcuM_WakeupSourceType sources)
{

  /* Check if Parameter is (0u). 0 is not a valid wakeup source */
  if ((EcuM_WakeupSourceType)0 == sources)
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_UNKNOWN_WAKEUP_SOURCE);

    /* return without doing any action */
    return E_NOT_OK;
  }
  else
  {
      /* continue with program flow */
  }
  /*
  * Check if Parameter is a power of 2. All wakeupsources are bit coded,
  * this means that for each wakeup source, one bit represents a
  * wakeup source. e.g: b0001 = CAN_CHANNEL_ONE
  *                     b0010 = GPT_CHANNEL_TWO
  *                     b0100 = ICU_CHANNEL_THREE
  * invoking EcuM_SetWakeupEvent with an parameter like: b0110 is wrong
  * and must produce an errorcode. Therefore all wakeupsource are
  * numbers with power of two values. The following if statement
  * ensures that the parameter is power of two:
  *
  * For better understanding look at this example:
  * ----------------------------------------------
  * Valid example:   WakupSource_t = b00001000
  *              =>  (WakeupSource_t - 1) = b00000111
  *
  *              =>   b00001000
  *                 & b00000111
  *                 ------------
  *                   b00000000 => Valid wakeupsource
  *
  * Non Valid example: Wakeupsource = b00001100
  *               =>  (WakeupSource_t - 1) = b00001011
  *
  *               =>  b00001100
  *                 & b00001011
  *                -------------
  *                   b00001000 => not a valid wakeup source
  */
  /* is wakeup source a power of 2 value */
  if ((EcuM_WakeupSourceType)0 !=
      ((EcuM_WakeupSourceType)sources & (EcuM_WakeupSourceType)(sources - (EcuM_WakeupSourceType)1u)))
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_UNKNOWN_WAKEUP_SOURCE);

    return E_NOT_OK;
  }
  else
  {
      /* continue with program flow */
  }

  /**
   * If there are 5 Wakeup sources the max. Value which is allowed to be passed as parameter is 2^5
   */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  if (sources > (uint32)ECUM_MAX_WAKEUP_SOURCE_VALUE)
# else
  if (sources > EcuM_Configuration_pt->MaxWakeupSourceValue_u32)
# endif
  {
    EcuM_Det_Errorhook(ApiId, ECUM_E_UNKNOWN_WAKEUP_SOURCE);

    return E_NOT_OK;
  }
  else
  {
      /* continue with program flow */
  }


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif

/*********************************************************************************************************************
    IMPLEMENTATION OF HELPER FUNCTIONS
**********************************************************************************************************************/

#if ((STD_ON == ECUM_CHECK_UNINIT) || (STD_ON == ECUM_CHECK_USER_PARAMETER))
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(uint8 ApiId, EcuM_UserType User_t, uint8 mask_u8)
#else
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(EcuM_UserType User_t, uint8 mask_u8)
#endif
{

#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ApiId))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

#if (STD_ON == ECUM_CHECK_USER_PARAMETER)

    if (E_OK != EcuM_CheckUserParameter(ApiId, User_t, mask_u8))
    {
      return E_NOT_OK;
    }
    else
    {
      /* User Parameter is valid */
    }
#endif /* #if (STD_ON == ECUM_CHECK_USER_PARAMETER) */

  EcuM_GlobalSuspend();
  /* Check if User has already RUN state requested */
  if ((EcuM_UserTable_at[User_t] & (EcuM_UserType)mask_u8) != (EcuM_UserType)0)
  {
#if (STD_ON == ECUM_CHECK_USER_PARAMETER)
    /* User has already request run: report error over DET */
    EcuM_Det_Errorhook(ApiId, ECUM_E_MULTIPLE_RUN_REQUESTS);    
#endif
    EcuM_GlobalRestore();
    return E_NOT_OK;
  }
  else
  {
      /* Intentionally left free */
  }

  if (E_OK != EcuM_IsKillAllInProgress())
  {
    /* killall is in progress, don't allow new RUN requests */
    EcuM_GlobalRestore();
    return E_NOT_OK;
  }
  else
  {
      /* continue with normal program flow */
  }
  
  EcuM_UserTable_at[User_t] |= (EcuM_UserType)mask_u8;

  if ((mask_u8 & (uint8)ECUM_USER_REQUEST_RUN_MASK) != 0)
  {
    EcuM_RunRequestCounter_t++;
  }
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  else if ((mask_u8 & (uint8)ECUM_COMM_CH_REQUEST_RUN_MASK) != 0)
  {
    EcuM_RunRequestCounter_t++;
  }
#endif
  else
  {
    EcuM_PostRunRequestCounter_t++;
  }
  EcuM_GlobalRestore();


  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. *//* PRQA S 4700 *//* MISRA-C:2004 Metric threshold: MISRA metric data only relevant for information purpose */

#if ((STD_ON == ECUM_CHECK_UNINIT) || (STD_ON == ECUM_CHECK_USER_PARAMETER))
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(uint8 ApiId, EcuM_UserType User_t, uint8 mask_u8)
#else
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(EcuM_UserType User_t, uint8 mask_u8)
#endif
{
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
    uint8 loopCounter_u8loc;
#endif


#if (STD_ON == ECUM_CHECK_UNINIT)
    if (E_OK != EcuM_CheckInitStartupTwo(ApiId))
    {
      return E_NOT_OK;
    }
    else
    {
      /* Module is initialized */
    }
#endif

#if (STD_ON == ECUM_CHECK_USER_PARAMETER)
    if (E_OK != EcuM_CheckUserParameter(ApiId, User_t, mask_u8))
    {
      return E_NOT_OK;
    }
    else
    {
      /* User Parameter is valid */
    }
#endif /* #if (STD_ON == ECUM_CHECK_USER_PARAMETER) */

  EcuM_GlobalSuspend();
  /* Has the user requested run state before?  */
  if ((EcuM_UserTable_at[User_t] & (EcuM_UserType)mask_u8) == (EcuM_UserType)0)
  {
    /* User has not request run: report error over DET */
#if (STD_ON == ECUM_CHECK_USER_PARAMETER)
    EcuM_Det_Errorhook(ApiId, ECUM_E_MISMATCHED_RUN_RELEASE);
#endif
    EcuM_GlobalRestore();
    return E_NOT_OK;
  }
  else
  {
      /* Intentionally left free */
  }
  
  EcuM_UserTable_at[User_t] &= (EcuM_UserType)(~((EcuM_UserType)mask_u8));

  if ((mask_u8 & (uint8)ECUM_USER_REQUEST_RUN_MASK) != 0)
  {
    EcuM_RunRequestCounter_t--;
  }
#if (( (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE) && (ECUM_INCLUDE_COMM == STD_ON)) \
    || (ECUM_CONFIG_VARIANT != ECUM_VARIANT_PRECOMPILE))
  else if ((mask_u8 & (uint8)ECUM_COMM_CH_REQUEST_RUN_MASK) != 0)
  {
    /* Adapt the global RunRequest Counter */
    EcuM_RunRequestCounter_t--;

    /* store the shift value of the wakeup source belonging to this channel/user */
# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
    for (loopCounter_u8loc = 0; loopCounter_u8loc < (uint8)ECUM_MAX_WAKEUP_SOURCES; loopCounter_u8loc++)
    {
      if (
          (EcuM_WakeupSourceList_at[loopCounter_u8loc].EcuM_ComMChannel_t != 255) &&
          (EcuM_WakeupSourceList_at[loopCounter_u8loc].EcuM_ComMChannel_t == User_t)
         )
      {
# else
    for (
          loopCounter_u8loc = 0;
          loopCounter_u8loc < EcuM_Configuration_pt->MaxNumberOfWakeupSources_u8;
          loopCounter_u8loc++
        )
    {
      if (
          (EcuM_Configuration_pt->WakeupSourceList_pt[loopCounter_u8loc].EcuM_ComMChannel_t != 255) &&
          (EcuM_Configuration_pt->WakeupSourceList_pt[loopCounter_u8loc].EcuM_ComMChannel_t == User_t)
         )
      {
# endif
        /* It exists a mapped wakeup source to this channel (user), so clear the wakeup validated flag */
        EcuM_ValidatedWakeups_t &= (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)1 << loopCounter_u8loc));
      }
    }
  }
#endif
  else
  {
    EcuM_PostRunRequestCounter_t--;
  }

  EcuM_GlobalRestore();

  return E_OK;
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */

STATIC FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount_u8(EcuM_WakeupSourceType x)
{
  x = x - (EcuM_WakeupSourceType)1u;

  /* Counting Algorithm for 1's in a bitstring, the number of 1's is the
     number of shifts */
  x = x - ((x >> 1) & (EcuM_WakeupSourceType)0x55555555);
  x = (x & (EcuM_WakeupSourceType)0x33333333) + ((x >> 2) & (EcuM_WakeupSourceType)0x33333333);
  x = (x + (x >> 4)) & (EcuM_WakeupSourceType)0x0F0F0F0F;
  x = x + (x >> 8);
  x = x + (x >> 16);

  return (uint8)((uint32)x & 0x0000001F);
} /* End of EcuM_GetShiftCount_u8() */

#if (STD_ON == ECUM_GET_STATUS_OF_WAKEUP_SOURCE_API)
STATIC FUNC(EcuM_WakeupStatusType, ECUM_CODE)EcuM_GetSumStatusOfWakeupSource(void)
{
  if ((EcuM_WakeupSourceType)0 != EcuM_ValidatedWakeups_t)
  {
    return (EcuM_WakeupStatusType)ECUM_WKSTATUS_VALIDATED;
  }
  else if ((EcuM_WakeupSourceType)0 != EcuM_PendingWakeups_t)
  {
    return (EcuM_WakeupStatusType)ECUM_WKSTATUS_PENDING;
  }
  else if ((EcuM_WakeupSourceType)0 != EcuM_ExpiredWakeups_t)
  {
    return (EcuM_WakeupStatusType)ECUM_WKSTATUS_EXPIRED;
  }
  else
  {
    return (EcuM_WakeupStatusType)ECUM_WKSTATUS_NONE;
  }
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */
#endif /*(STD_ON == ECUM_GET_STATUS_OF_WAKEUP_SOURCE_API)*/

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_IsKillAllInProgress(void)
{

  if ((EcuM_ModulFlags_u8 & (uint8)ECUM_FLAG_KILLALL_IN_PROGRESS) != (uint8)0)
  {

    /* killall is in progress, don't allow new RUN requests */
    return E_NOT_OK;
  }
  else
  {

    /* continue with normal program flow */
    return E_OK;
  }
} /* PRQA S 2006 *//* MISRA-C:2004 redundancy: violation due to code optimization. */


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Function name: EcuM_NotifyModeSwitch

------------------------------------------------------------------------------
    Function Description:
    ---------------------
    This function notifies the RTE about mode switch events.
------------------------------------------------------------------------------
    Parameter:        modeEvent_u8 current selected mode which should be 
                      notified to RTE.
    Returnvalue:      None
    Context:          Task
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
STATIC FUNC(void, ECUM_CODE)EcuM_NotifyModeSwitch(uint8 modeEvent_u8)
{
  if (NULL_PTR != EcuM_Configuration_pt->ModeEventFunction_pt)
  {
    EcuM_Configuration_pt->ModeEventFunction_pt(modeEvent_u8);
  }
  else
  {
    /* Mode switch notification is not configured, nothing to do. */
  }
  return;
} /* End of EcuM_NotifyModeSwitch() */
#endif

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Function name: EcuM_InternalClearWakeupEvents

------------------------------------------------------------------------------
    Function Description:
    ---------------------
    Clears all wakeup events
------------------------------------------------------------------------------
    Parameter:        wakeupSource
    Returnvalue:      None
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
STATIC FUNC(void, ECUM_CODE) EcuM_InternalClearWakeupEvents(EcuM_WakeupSourceType wakeupSource)
{
  EcuM_PendingWakeups_t &= (~wakeupSource);
  EcuM_ValidatedWakeups_t &= (~wakeupSource);
  EcuM_ExpiredWakeups_t &= (~wakeupSource);
}
/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Function name: EcuM_InternalDisableWakeupSources

------------------------------------------------------------------------------
    Function Description:
    ---------------------
    Disable wakeup sources for corresponding SLEEP mode, or all in case of 
    an OFF mode. Nothing is done if shutdown target is RESET
------------------------------------------------------------------------------
    Parameter:        None
    Returnvalue:      None
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
STATIC FUNC(void, ECUM_CODE) EcuM_InternalDisableWakeupSources(void)
{
  #if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
   if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_OFF)
    {
      EcuM_DisableWakeupSources(ECUM_WKSOURCE_ALL_SOURCES);
    }
   #if (ECUM_MAX_SLEEP_MODES != 0u)
    else if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_SLEEP)
    {
        /* Disable wakeup sources configured for this sleep mode */
        EcuM_DisableWakeupSources(EcuM_SleepModeList_at[EcuM_CurrentSleepModeIndex_u8].wakeupSource);
    }
   #endif
    else
    {
      /* Shutdowntarget is RESET, so don't activate Wakeupsources */
    }
  #else
    if ((EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_SLEEP) &&
        ((uint8)0 != EcuM_Configuration_pt->MaxSleepModes_u8))
    {
      /* Disable wakeup sources configured for this sleep mode */
      EcuM_DisableWakeupSources(EcuM_Configuration_pt->SleepModeList_pt[EcuM_CurrentSleepModeIndex_u8].wakeupSource);
    }
    else if (EcuM_ShutdownTarget_t == (EcuM_StateType)ECUM_STATE_OFF)
    {
      EcuM_DisableWakeupSources(ECUM_WKSOURCE_ALL_SOURCES);
    }
    else
    {
      /* Shutdowntarget is RESET, so don't deactivate Wakeupsources */
    }
  #endif
}

/****************************************************************************
    IMPLEMENTATION OF QUERY FUNCTIONS
*****************************************************************************/

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRunRequested(void)
{
  return (boolean)(EcuM_RunRequestCounter_t != (EcuM_UserType)0);
} /* End of EcuM_QryRunRequested() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryPendingWakeup(void)
{
  return (boolean)(EcuM_PendingWakeups_t != (EcuM_WakeupSourceType)0);
}/* End of EcuM_QryPendingWakeup() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryPostRunRequested(void)
{
  return (boolean)(EcuM_PostRunRequestCounter_t != (EcuM_UserType)0);
}/* End of EcuM_QryPostRunRequested() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsShutdownTargetSleep(void)
{
  return (boolean)((EcuM_StateType)ECUM_STATE_SLEEP == EcuM_ShutdownTarget_t);
}/* End of EcuM_QryIsShutdownTargetSleep() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsShutdownTargetOff(void)
{
  return (boolean)((EcuM_StateType)ECUM_STATE_OFF == EcuM_ShutdownTarget_t);
} /* End of EcuM_QryIsShutdownTargetOff() */

#if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
/* in case EcuM_NvM_JobStatus_t == PENDING return TRUE */
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryNvmPending(void)
{
  return (boolean)(!(NVM_REQ_PENDING != EcuM_NvM_JobStatus_t));
}/* End of EcuM_QryNvmPending() */

/* in case the EcuM_ModuleState_t is not ECUM_STATE_STARTUP_TWO return TRUE */
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsNvMWriteAllRunning(void)
{
  return (boolean)((EcuM_WakeupReactionType)EcuM_NvM_WriteAllStarted_bl != FALSE);
}/* End of EcuM_QryIsStartupTwoState() */

/* in case NvM is PENDING or a wakeup is PENDING return with TRUE*/
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsNvMOrWkUpPending(void)
{
  if((EcuM_QryNvmPending()) || (EcuM_QryPendingWakeup()))
     return(TRUE);
  else
     return(FALSE);
}/* End of EcuM_QryIsStartupTwoState() */
#endif

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryNewValidWakeup(void)
{
  return (boolean)(EcuM_ValidatedWakeups_t != (EcuM_WakeupSourceType)0);
}/* End of EcuM_QryNewValidWakeup() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryIsWKACTRun(void)
{
  return (boolean)((EcuM_WakeupReactionType)ECUM_WKACT_RUN == EcuM_WakeupReaction_t);
}/* End of EcuM_QryIsWKACTRun() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRteWaitOnFeedback(void)
{
    return EcuM_ModeRteWaitOnFeedbackEvent();
}/* End of EcuM_QryRteWaitOnFeedback() */

/* in case a new valid wakeup existent or a RUN request is sent return TRUE */
STATIC FUNC(boolean, ECUM_CODE) EcuM_QryRunRequestedOrNewValidWakeup(void)
{
  if((EcuM_QryRunRequested()) || (EcuM_QryNewValidWakeup()))
     return(TRUE);
  else
     return(FALSE);
}/* End of EcuM_QryIsStartupTwoState() */

STATIC FUNC(boolean, ECUM_CODE) EcuM_QryTrue(void)
{
  return TRUE;
}/* End of EcuM_QryTrue() */



#define ECUM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MISRA-C:2004 Rule 19.1: violation due to AUTOSAR requirement for Memory Mapping */
/**********************************************************************************************************************
 *  END OF FILE: ECUM.C
 *********************************************************************************************************************/

