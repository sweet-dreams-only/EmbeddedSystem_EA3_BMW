/*************************************************************************************
*   FILE:           T1_AppInterface.h
*
*   DESCRIPTION:    application specific interface header for T1
*
*   $Author: nick $
*
*   $Revision: 13166 $
*
*   $URL: https://gliwa.com/svn/repos/T1sandbox/trunk/TriCoreExV2/src/T1_AppInterface.h $
*
*   COPYRIGHT:      gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

#ifndef T1_APPINTERFACE_H_
#define T1_APPINTERFACE_H_ (1)

#define T1_ENABLE

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include "T1_config.h"
#include "T1_baseInterface.h"
//#define T1_COUNT_PREEMPTION  /* Enable T1.flex preemption-aware RMF */
#include "T1_scopeInterface.h"
#include "T1_modInterface.h"
#include "T1_delayInterface.h"
#define T1_CONT_DIRECT_ID_MAPPINGS
#include "T1_contInterface.h"
#include "T1_flexInterface.h"

/*----------------------------------------------------------------------------------*/
/*--- macros and inline functions --------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/* Application features */

/* @T1@ <AppFeature Name="T1_AF_TRIGGER_ERRORHOOK"> */
#define T1_AF_TRIGGER_ERRORHOOK     0x00000001uL    /* capture OS errors (ErrorHook) */
/* @T1@ </AppFeature> */

/* @T1@ <AppFeature Name="T1_AF_TRIGGER_STARTUP"> */
#define T1_AF_TRIGGER_STARTUP       0x00000002uL    /* capture the startup of the ECU */
/* @T1@ </AppFeature> */

/* @T1@ <AppFeature Name="T1_AF_TRACE_BGTASK"> */
#define T1_AF_TRACE_BGTASK          0x00000004uL    /* trace the background task */
/* @T1@ </AppFeature> */

/* @T1@ <AppFeature Name="T1_AF_ALLOW_TRIGGER"> */
#define T1_AF_ALLOW_TRIGGER         0x00000800uL
/* @T1@ </AppFeature> */

/*----------------------------------------------------------------------------------*/
/* User events */

/* @T1@ <SystemElement Name="OS Error" Type="UserEvent"> */
#define T1_OS_ERROR             0x21
/* @T1@ </SystemElement > */

/* Defined only in .t1p files to permit pretty printing of error */
#define T1_UEV_CONT_ERR         0x22

/* @T1@ <SystemElement Name="T1.cont constraint violation" Type="UserEvent"> */
#define T1_UEV_CONT_CSRN        0x24
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1.cont CPU load exceeded" Type="UserEvent"> */
#define T1_UEV_CONT_CPU         0x25
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1.cont emptied trace buffer" Type="UserEvent"> */
#define T1_CONT_EMPTIED_BUFFER  0x23
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1 overhead prep" Type="UserEvent"> */
#define T1_UEV_OVHD_PREP        0x30
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1 total overhead" Type="UserEvent"> */
#define T1_UEV_OVHD_TOTAL       0x31
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1 first overhead" Type="UserEvent"> */
#define T1_UEV_OVHD_FIRST       0x32
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1.flex overhead" Type="UserEvent"> */
#define T1_UEV_OVHD_FLEX        0x33
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1 handler error" Type="UserEvent"> */
#define T1_UEV_HANDLER_ERR      0x34
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1.flex OK" Type="UserEvent"> */
#define T1_UEV_FLEX_OK          0x3F
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1_Init result" Type="UserEvent"> */
#define T1_INIT_RESULT          0x28
/* @T1@ </SystemElement> */

/* @T1@ <SystemElement Name="T1_TxValue result" Type="UserEvent"> */
#define T1_TX_VALUE_RESULT      0x29
/* @T1@ </SystemElement> */

/*----------------------------------------------------------------------------------*/
/* Stopwatches */

/* @T1@ <SystemElement Name="Test stopwatch" Type="Stopwatch"> */
#define T1_SW_TEST              0
/* @T1@ </SystemElement > */

/*----------------------------------------------------------------------------------*/
/* Delays */

enum
{
    /* @T1@ <Delay Name="Task 2ms 9 delay" SID="3"> */
    core0_task2ms_9_DL_ID = 0,
    /* @T1@ </Delay> */

    /* @T1@ <Delay Name="Task 4ms 9 delay" SID="3"> */
    core0_task4ms_9_DL_ID   = 1,
    /* @T1@ </Delay> */

    /* @T1@ <Delay Name="Task 10ms 9 delay" SID="3"> */
    core0_task10ms_9_DL_ID   = 2,
    /* @T1@ </Delay> */

    /* @T1@ <Delay Name="Task 100ms 9 delay" SID="3"> */
    core0_task100ms_9_DL_ID   = 3,
    /* @T1@ </Delay> */

	/* To use simply add a call T1_DelayRoutine(core0_userDelay_DL_ID) where a configurable delay is desired. */
    /* @T1@ <Delay Name="Custom user delay" SID="3"> */
    core0_userDelay_DL_ID   = 4,
    /* @T1@ </Delay> */

    T1_NOF_DELAYS_CORE0         = 5
};
/*----------------------------------------------------------------------------------*/
/*--- forward declarations for global functions ------------------------------------*/
/*----------------------------------------------------------------------------------*/

void T1_CODE T1_AppInit( void );
void T1_CODE T1_AppHandler( void );
void T1_CODE T1_AppRxCallback( const T1_rawData_t *pRawData );
void T1_CODE T1_InitEventChainsCore0( void );
void T1_CODE T1_AppBgHandler(void);

#endif /* T1_APPINTERFACE_H_ */
