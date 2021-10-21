/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM.c
 *        Config:  ECUC
 *  Generated at:  Thu Mar 23 09:54:02 2017
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Implementation of BSW Scheduler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#25 %
 * %date_modified:    Wed Feb  5 17:59:08 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date        Rev      Author         Change Description                                                        SCR #
 * --------   -------  -------  ---------------------------------------------------------------------------  ----------
 * 11/08/12		11		KJS		Added version logging, added headers for remove warnings for build, and
 *								added Dcm_RteMainFunc task in this file from Appl_Task
 * 11/10/12		12		JJW		Renamed Dcm_RteMainFunc to meet naming standards, moved ASILD SchM function to this file
 * 11/14/12		13		JJW		Moved Wdg/WdgM init to immediately before start of Rte to provide proper sequencing for 
 *								runtime alive monitoring.
 * 11/14/12		14		JJW		Correctly used trusted/nontrusted wrapper interface for Wdg function. 
 * 11/26/12		15		KJS		Modified the alarm set time in SchM_SyncTasks from 0+(SysTick) to 2ms.			CR6880 
 * 03/21/13		16		JJW		Rte Init completion notification for Nvm WaitAllReady
 * 04/03/13		17		JJW		Custom Exclusive Area handler for Xcp
 *								Addition of scheduling for EPSDiagSrvcs_Task MainFunction
 * 04/11/13		19		KJS		Added Coding_Init to Task_Init_SchM9 per anomaly 4492
 * 04/25/13		20		LWW		Added special handling for FrXcp Critical Sections
 * 02/05/14		21		KJS		Corrected anomaly 6277 or 5398
 * 12/09/14		23		AS		GliwaT1 component integration
 * 04/01/15		24		KJS		Added flags for NvM functions to be performed in the background task.
 * 03/23/17		25		ABS		Removed Coding_Init and moved to Task_InitA_9								EA3#9030
*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SchM.h"
#include "SchM_Cfg.h"

#include "Det.h"
#define SchM_DetReportError(ApiId, ErrorId)   Det_ReportError(SCHM_MODULE_ID, 0, ApiId, ErrorId)


/**
 * Version check for source and header file consistency
 */
#if (SCHM_SW_MAJOR_VERSION != 0x03u)
# error "Source and Header file are inconsistent!"
#endif

#if (SCHM_SW_MINOR_VERSION != 0x00u)
# error "Source and Header file are inconsistent!"
#endif

#if (SCHM_SW_PATCH_VERSION != 0x02u)
# error "Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "SchM_Types.h"

#include "Os.h"

#include "Adc.h"
#include "SchM_Adc.h"

#include "SchM_CMS_Common.h"

#include "Coding.h"
#include "SchM_Coding.h"

#include "Com.h"
#include "SchM_Com.h"

#include "ComM.h"
#include "SchM_ComM.h"

#include "Darh.h"
#include "SchM_Darh.h"

#include "Dcm.h"
#include "SchM_Dcm.h"

#include "Dem.h"
#include "SchM_Dem.h"

#include "Det.h"
#include "SchM_Det.h"

#include "Dio.h"
#include "SchM_Dio.h"

#include "EcuM.h"
#include "SchM_EcuM.h"

#include "Fee.h"
#include "SchM_Fee.h"

#include "Fr.h"
#include "SchM_Fr.h"

#include "FrIf.h"
#include "SchM_FrIf.h"

#include "FrSM.h"
#include "SchM_FrSM.h"

#include "FrTp.h"
#include "SchM_FrTp.h"

#include "FrTrcv_30_Tja1080.h"
#include "SchM_FrTrcv_30_Tja1080.h"

#include "FrXcp.h"
#include "SchM_FrXcp.h"

#include "Gpt.h"
#include "SchM_Gpt.h"

#include "IoHwAb.h"
#include "SchM_IoHwAb.h"

#include "IpduM.h"
#include "SchM_IpduM.h"

#include "Mcu.h"
#include "SchM_Mcu.h"

#include "NvM.h"
#include "SchM_NvM.h"

#include "SchM_NvMProxy.h"

#include "PduR.h"
#include "SchM_PduR.h"

#include "Port.h"
#include "SchM_Port.h"

#include "Spi.h"
#include "SchM_Spi.h"

#include "SpiNxt.h"
#include "SchM_SpiNxt.h"

#include "SchM_SrlComOutput.h"

#include "SysTimeClient.h"
#include "SchM_SysTimeClient.h"

#include "CDD_Func.h"
#include "SchM_TcFlshPrg.h"

#include "Vsm_Client.h"
#include "SchM_Vsm_Client.h"

#include "XcpProf.h"
#include "SchM_Xcp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "tcb.h"
#include "Interrupts.h"

#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "Wdg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "NtWrap.h"
#include "EPS_DiagSrvcs_ISO.Interface.h"
#include "CDD_Data.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined (OS_VENDOR_ID)
# if OS_VENDOR_ID == SCHM_VENDOR_ID
#  if defined MSEC
#   define SCHM_MSEC MSEC
#  endif
# endif
#endif

#ifndef SCHM_MSEC

# if (OSTICKDURATION < 1000)
#  error "The MICROSAR SchM does not support OSTICKDURATION < 1000 ns"
# endif

# define SCHM_TICKDURATION (OSTICKDURATION / 1000u)

# define SCHM_MSEC(val) ((TickType)SCHM_CONST_MSEC_##val)

# define SCHM_MSEC_BASE 1000UL

# if ((0) < (0xFFFFFFFFUL / SCHM_MSEC_BASE))
#  define SCHM_CONST_MSEC_0 (((uint32)(0) * SCHM_MSEC_BASE) / (uint32)SCHM_TICKDURATION)
# else
#  if (SCHM_TICKDURATION > SCHM_MSEC_BASE)
#   define SCHM_CONST_MSEC_0 ((uint32)(0) / ((uint32)SCHM_TICKDURATION / SCHM_MSEC_BASE))
#  else
#   define SCHM_CONST_MSEC_0 ((uint32)(0) * (SCHM_MSEC_BASE / (uint32)SCHM_TICKDURATION))
#  endif
# endif

# if ((1) < (0xFFFFFFFFUL / SCHM_MSEC_BASE))
#  define SCHM_CONST_MSEC_1 (((uint32)(1) * SCHM_MSEC_BASE) / (uint32)SCHM_TICKDURATION)
# else
#  if (SCHM_TICKDURATION > SCHM_MSEC_BASE)
#   define SCHM_CONST_MSEC_1 ((uint32)(1) / ((uint32)SCHM_TICKDURATION / SCHM_MSEC_BASE))
#  else
#   define SCHM_CONST_MSEC_1 ((uint32)(1) * (SCHM_MSEC_BASE / (uint32)SCHM_TICKDURATION))
#  endif
# endif

# if ((3) < (0xFFFFFFFFUL / SCHM_MSEC_BASE))
#  define SCHM_CONST_MSEC_3 (((uint32)(3) * SCHM_MSEC_BASE) / (uint32)SCHM_TICKDURATION)
# else
#  if (SCHM_TICKDURATION > SCHM_MSEC_BASE)
#   define SCHM_CONST_MSEC_3 ((uint32)(3) / ((uint32)SCHM_TICKDURATION / SCHM_MSEC_BASE))
#  else
#   define SCHM_CONST_MSEC_3 ((uint32)(3) * (SCHM_MSEC_BASE / (uint32)SCHM_TICKDURATION))
#  endif
# endif

# if ((5) < (0xFFFFFFFFUL / SCHM_MSEC_BASE))
#  define SCHM_CONST_MSEC_5 (((uint32)(5) * SCHM_MSEC_BASE) / (uint32)SCHM_TICKDURATION)
# else
#  if (SCHM_TICKDURATION > SCHM_MSEC_BASE)
#   define SCHM_CONST_MSEC_5 ((uint32)(5) / ((uint32)SCHM_TICKDURATION / SCHM_MSEC_BASE))
#  else
#   define SCHM_CONST_MSEC_5 ((uint32)(5) * (SCHM_MSEC_BASE / (uint32)SCHM_TICKDURATION))
#  endif
# endif

#endif

/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define SCHM_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

CONST(uint8, SCHM_CONST) COM_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;
CONST(uint8, SCHM_CONST) COM_EXCLUSIVE_AREA_1 = SCHM_EA_DISABLED;
CONST(uint8, SCHM_CONST) COM_EXCLUSIVE_AREA_2 = SCHM_EA_SUSPENDALLINTERRUPTS;
CONST(uint8, SCHM_CONST) COM_EXCLUSIVE_AREA_3 = SCHM_EA_DISABLED;
CONST(uint8, SCHM_CONST) COM_EXCLUSIVE_AREA_4 = SCHM_EA_SUSPENDALLINTERRUPTS;

CONST(uint8, SCHM_CONST) ECUM_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;
CONST(uint8, SCHM_CONST) ECUM_EXCLUSIVE_AREA_1 = SCHM_EA_DISABLED;

CONST(uint8, SCHM_CONST) FRXCP_EXCLUSIVE_AREA_0 = 10u;

CONST(uint8, SCHM_CONST) SPINXT_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;

CONST(uint8, SCHM_CONST) XCP_EXCLUSIVE_AREA_0 = 10u;

CONST(uint8, SCHM_CONST) SCHM_COM_INSTANCE_0 = 0u;
CONST(uint8, SCHM_CONST) SCHM_ECUM_INSTANCE_0 = 0u;
CONST(uint8, SCHM_CONST) SCHM_FRXCP_INSTANCE_0 = 0u;
CONST(uint8, SCHM_CONST) SCHM_SPINXT_INSTANCE_0 = 0u;
CONST(uint8, SCHM_CONST) SCHM_XCP_INSTANCE_0 = 0u;

#define SCHM_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

/**********************************************************************************************************************
 * Global variables
 *********************************************************************************************************************/

#define SCHM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

STATIC VAR(uint8, SCHM_VAR_ZERO_INIT) SchM_InitState;

#define SCHM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

#define SCHM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

STATIC VAR(uint8, SCHM_VAR_NOINIT) SchM_Timer_SchM_Task_0_10ms;
STATIC VAR(uint8, SCHM_VAR_NOINIT) SchM_Timer_SchM_Task2_0_100ms;
STATIC VAR(uint8, SCHM_VAR_NOINIT) SchM_Timer_SchM_Task2_0_10ms;
STATIC VAR(uint8, SCHM_VAR_NOINIT) SchM_Timer_SchM_Task2_0_20ms;
VAR(boolean, SCHM_VAR_NOINIT) EcuStartup_PreRteInitCmplt_lgc = FALSE; /* Referenced in ApplCallbacks */

#define SCHM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

/**********************************************************************************************************************
 * Global functions
 *********************************************************************************************************************/

#define SCHM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

/**********************************************************************************************************************
| NAME:             SchM_Enter_Com
| CALLED BY:        Com
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      enters an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Enter_Com(uint8 ExclusiveArea)
{
  SchM_EnterHook_Com_Start(ExclusiveArea);
  if (ExclusiveArea == SCHM_EA_DISABLED)
  {
    /* disabled exclusive area */
  }
  else
  {
    SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
  }
  SchM_EnterHook_Com_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Exit_Com
| CALLED BY:        Com
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      exits an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Exit_Com(uint8 ExclusiveArea)
{
  SchM_ExitHook_Com_Start(ExclusiveArea);
  if (ExclusiveArea == SCHM_EA_DISABLED)
  {
    /* disabled exclusive area */
  }
  else
  {
    SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
  }
  SchM_ExitHook_Com_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Enter_EcuM
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      enters an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Enter_EcuM(uint8 ExclusiveArea)
{
  SchM_EnterHook_EcuM_Start(ExclusiveArea);
  if (ExclusiveArea == SCHM_EA_DISABLED)
  {
    /* disabled exclusive area */
  }
  else
  {
    SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
  }
  SchM_EnterHook_EcuM_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Exit_EcuM
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      exits an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Exit_EcuM(uint8 ExclusiveArea)
{
  SchM_ExitHook_EcuM_Start(ExclusiveArea);
  if (ExclusiveArea == SCHM_EA_DISABLED)
  {
    /* disabled exclusive area */
  }
  else
  {
    SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
  }
  SchM_ExitHook_EcuM_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Enter_FrXcp
| CALLED BY:        FrXcp
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      enters an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Enter_FrXcp(uint8 ExclusiveArea)
{
  SchM_EnterHook_FrXcp_Start(ExclusiveArea);
  if (ExclusiveArea == FRXCP_EXCLUSIVE_AREA_0)
  {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Enter_FRXCP_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/

	/* Bypass the exclusive area protection when the test mode is active */
	if ( FALSE == EnableTestMode_Cnt_lgc )
	{ 
		SuspendAllInterrupts();
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  }
  else
  {
    SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
  }
  SchM_EnterHook_FrXcp_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Exit_FrXcp
| CALLED BY:        FrXcp
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      exits an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Exit_FrXcp(uint8 ExclusiveArea)
{
  SchM_ExitHook_FrXcp_Start(ExclusiveArea);
  if (ExclusiveArea == FRXCP_EXCLUSIVE_AREA_0)
  {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Exit_FRXCP_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/

 	/* Bypass the exclusive area protection when the test mode is active */
	if ( FALSE == EnableTestMode_Cnt_lgc )
	{ 
		ResumeAllInterrupts();
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  }
  else
  {
    SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
  }
  SchM_ExitHook_FrXcp_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Enter_SpiNxt
| CALLED BY:        SpiNxt
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      enters an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Enter_SpiNxt(uint8 ExclusiveArea)
{
  SchM_EnterHook_SpiNxt_Start(ExclusiveArea);
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
  ExclusiveArea = ExclusiveArea;
# endif
#endif
  SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
  SchM_EnterHook_SpiNxt_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Exit_SpiNxt
| CALLED BY:        SpiNxt
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      exits an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Exit_SpiNxt(uint8 ExclusiveArea)
{
  SchM_ExitHook_SpiNxt_Start(ExclusiveArea);
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
  ExclusiveArea = ExclusiveArea;
# endif
#endif
  SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
  SchM_ExitHook_SpiNxt_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Enter_Xcp
| CALLED BY:        Xcp
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      enters an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Enter_Xcp(uint8 ExclusiveArea)
{
  SchM_EnterHook_Xcp_Start(ExclusiveArea);
  if (ExclusiveArea == XCP_EXCLUSIVE_AREA_0)
  {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Enter_XCP_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/

	/* Bypass the exclusive area protection when the test mode is active */
	if ( FALSE == EnableTestMode_Cnt_lgc )
	{ 
		SuspendAllInterrupts();
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  }
  else
  {
    SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
  }
  SchM_EnterHook_Xcp_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_Exit_Xcp
| CALLED BY:        Xcp
| PRECONDITIONS:    none
| INPUT PARAMETERS: exclusive area id
| RETURN VALUES:    none
| DESCRIPTION:      exits an exclusive area
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Exit_Xcp(uint8 ExclusiveArea)
{
  SchM_ExitHook_Xcp_Start(ExclusiveArea);
  if (ExclusiveArea == XCP_EXCLUSIVE_AREA_0)
  {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Exit_XCP_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/

 	/* Bypass the exclusive area protection when the test mode is active */
	if ( FALSE == EnableTestMode_Cnt_lgc )
	{ 
		ResumeAllInterrupts();
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  }
  else
  {
    SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
  }
  SchM_ExitHook_Xcp_Return(ExclusiveArea);
}

/**********************************************************************************************************************
| NAME:             SchM_InitMemory
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initializes global variables. This function has to be called
|                   before any other calls to the SchM API
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_InitMemory( void )
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_InitMemory
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  SchM_InitState = SCHM_UNINIT;
}

/**********************************************************************************************************************
| NAME:             SchM_Init
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initialize the timers for the scheduling of the main
|                   functions of the BSW modules
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Init( void )
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Init
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  SchM_Timer_SchM_Task_0_10ms = 0u;
  SchM_Timer_SchM_Task2_0_100ms = 0u;
  SchM_Timer_SchM_Task2_0_10ms = 0u;
  SchM_Timer_SchM_Task2_0_20ms = 0u;

  SchM_InitState = SCHM_INIT;
}

/**********************************************************************************************************************
| NAME:             SchM_Deinit
| CALLED BY:        EcuM
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Deinitialize the timers for the scheduling of the main
|                   functions of the BSW modules
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_Deinit( void )
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Deinit
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  if(SCHM_INIT != SchM_InitState)
  {
    SchM_DetReportError(SCHM_APIID_SCHM_DEINIT, SCHM_E_NOT_INIT);
  }
  else
  {
    (void)CancelAlarm(SchM_Task100ms_Alarm);
    (void)CancelAlarm(SchM_Alarm);
    (void)CancelAlarm(SchM_Task2_Alarm);

     SchM_InitState = SCHM_UNINIT;
  }
}

/**********************************************************************************************************************
| NAME:             SchM_100ms_Task10
| CALLED BY:        OS
| PRECONDITIONS:    SchM initialized
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      BSW Scheduler Task SchM_100ms_Task10
**********************************************************************************************************************/
TASK(SchM_100ms_Task10)
{
  EventMaskType ev;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_100ms_Task10
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

  for(;;)
  {
    (void)WaitEvent(SchM_Task100ms_Event);
    (void)GetEvent(SchM_100ms_Task10, &ev);
    (void)ClearEvent(ev);

    if(SCHM_INIT != SchM_InitState)
    {
      SchM_DetReportError(SCHM_APIID_SCHM_100MS_TASK10, SCHM_E_NOT_INIT);
    }
    else
    {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: MainFunctionList_SchM_100ms_Task10
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
     /* NXTR PATCH START
      * Added: 4/1/15
      * Reason: Added if statement to disable the SchM call when the "fast" write is enabled. Since this is a
      * generated file, this patch will need to be applied each time SchM is generated.
      */
    	if(CDD_NvMFastWriteEnable_Cnt_G_lgc == FALSE)
    	{
    		SchM_Fee_MainFunction_Start();
    		Fee_MainFunction();
    		SchM_Fee_MainFunction_Return();
    	}
    /* Nxtr Patch End */
    }
  }
}

/**********************************************************************************************************************
| NAME:             SchM_Task
| CALLED BY:        OS
| PRECONDITIONS:    SchM initialized
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      BSW Scheduler Task SchM_Task
**********************************************************************************************************************/
TASK(SchM_Task)
{
  EventMaskType ev;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Task
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* start cyclic triggering of the mainfunctions only after the system is fully initialized */
  (void)SetRelAlarm(SchM_Alarm, SCHM_MSEC(0) + (TickType)1, SCHM_MSEC(5));
  (void)SetRelAlarm(SchM_Task2_Alarm, SCHM_MSEC(3) + (TickType)1, SCHM_MSEC(5));
  (void)SetRelAlarm(SchM_Task100ms_Alarm, SCHM_MSEC(3) + (TickType)1, SCHM_MSEC(100));

  for(;;)
  {
    (void)WaitEvent(SchM_Event);
    (void)GetEvent(SchM_Task, &ev);
    (void)ClearEvent(ev);

    if(SCHM_INIT != SchM_InitState)
    {
      SchM_DetReportError(SCHM_APIID_SCHM_TASK, SCHM_E_NOT_INIT);
    }
    else
    {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: MainFunctionList_SchM_Task
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
      SchM_FrSm_MainFunction_0_Start();
      FrSm_MainFunction_0();
      SchM_FrSm_MainFunction_0_Return();

      SchM_Com_MainFunctionTx_Start();
      Com_MainFunctionTx();
      SchM_Com_MainFunctionTx_Return();

      SchM_Com_MainFunctionRx_Start();
      Com_MainFunctionRx();
      SchM_Com_MainFunctionRx_Return();

      if (0 == SchM_Timer_SchM_Task_0_10ms)
      {
        SchM_IpduM_MainFunction_Start();
        IpduM_MainFunction();
        SchM_IpduM_MainFunction_Return();
      }

      SchM_FrIf_MainFunction_0_Start();
      FrIf_MainFunction_0();
      SchM_FrIf_MainFunction_0_Return();

      SchM_FrTp_MainFunction_Start();
      FrTp_MainFunction();
      SchM_FrTp_MainFunction_Return();

      if (0 == SchM_Timer_SchM_Task_0_10ms)
      {
        SchM_FrXcp_MainFunctionTx_Start();
        FrXcp_MainFunctionTx();
        SchM_FrXcp_MainFunctionTx_Return();

        SchM_FrXcp_MainFunctionRx_Start();
        FrXcp_MainFunctionRx();
        SchM_FrXcp_MainFunctionRx_Return();

        SchM_SysTimeClient_MainFunction_Start();
        SysTimeClient_MainFunction();
        SchM_SysTimeClient_MainFunction_Return();

        SchM_Vsm_MainFunction_Start();
        Vsm_MainFunction();
        SchM_Vsm_MainFunction_Return();

        SchM_Darh_Main_Start();
        Darh_Main();
        SchM_Darh_Main_Return();

        SchM_Dcm_MainFunction_Start();
        Dcm_MainFunction();
        SchM_Dcm_MainFunction_Return();

        SchM_Timer_SchM_Task_0_10ms = 2u;
      }

      SchM_SrlComOutput_MainFunction_Start();
      SrlComOutput_MainFunction();
      SchM_SrlComOutput_MainFunction_Return();

      SchM_Timer_SchM_Task_0_10ms--;

    }
  }
}

/**********************************************************************************************************************
| NAME:             SchM_Task2
| CALLED BY:        OS
| PRECONDITIONS:    SchM initialized
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      BSW Scheduler Task SchM_Task2
**********************************************************************************************************************/
TASK(SchM_Task2)
{
  EventMaskType ev;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_Task2
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  for(;;)
  {
    (void)WaitEvent(SchM_Task2_Event);
    (void)GetEvent(SchM_Task2, &ev);
    (void)ClearEvent(ev);

    if(SCHM_INIT != SchM_InitState)
    {
      SchM_DetReportError(SCHM_APIID_SCHM_TASK2, SCHM_E_NOT_INIT);
    }
    else
    {
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of task implementation >>              DO NOT CHANGE THIS COMMENT!
 * Symbol: MainFunctionList_SchM_Task2
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of task implementation >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
      if (0 == SchM_Timer_SchM_Task2_0_10ms)
      {
        SchM_EcuM_MainFunction_Start();
        EcuM_MainFunction();
        SchM_EcuM_MainFunction_Return();
      }

      if (0 == SchM_Timer_SchM_Task2_0_20ms)
      {
        SchM_ComM_MainFunction_0_Start();
        ComM_MainFunction_0();
        SchM_ComM_MainFunction_0_Return();

        SchM_Timer_SchM_Task2_0_20ms = 4u;
      }

      if (0 == SchM_Timer_SchM_Task2_0_100ms)
      {
    	  /* NXTR PATCH START
    	  * Added: 4/1/15
    	  * Reason: Added if statement to disable the SchM call when the "fast" write is enabled. Since this is a
    	  * generated file, this patch will need to be applied each time SchM is generated.
    	  */
    	  if (CDD_NvMFastWriteEnable_Cnt_G_lgc == FALSE)
    	  {
    		  SchM_NvMProxy_MainFunction_Start();
    		  NvMProxy_MainFunction();
    		  SchM_NvMProxy_MainFunction_Return();

    		  SchM_NvM_MainFunction_Start();
    		  NvM_MainFunction();
    		  SchM_NvM_MainFunction_Return();
    	  }

        SchM_Timer_SchM_Task2_0_100ms = 20u;
      }

      SchM_Dem_MainFunction_Start();
      Dem_MainFunction();
      SchM_Dem_MainFunction_Return();

      SchM_FrTrcv_30_Tja1080_MainFunction_Start();
      FrTrcv_30_Tja1080_MainFunction();
      SchM_FrTrcv_30_Tja1080_MainFunction_Return();

      SchM_XcpBackground_Start();
      XcpBackground();
      SchM_XcpBackground_Return();

      if (0 == SchM_Timer_SchM_Task2_0_10ms)
      {
        SchM_TcFlshPrg_Per1_Start();
        TcFlshPrg_Per1();
        SchM_TcFlshPrg_Per1_Return();

        SchM_EPSDiagSrvcs_Task_Start();
        EPSDiagSrvcs_Task();
        SchM_EPSDiagSrvcs_Task_Return();

        SchM_Timer_SchM_Task2_0_10ms = 2u;
      }

      SchM_Timer_SchM_Task2_0_100ms--;
      SchM_Timer_SchM_Task2_0_10ms--;
      SchM_Timer_SchM_Task2_0_20ms--;

    }
  }
}


/**********************************************************************************************************************
| NAME:             SchM_SyncTasks
| CALLED BY:        Application
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Synchronizes the synchronous tasks to the FlexRay cycle
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_SyncTasks(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << Start of api implementation >>               DO NOT CHANGE THIS COMMENT!
 * Symbol: SchM_SyncTasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!              << End of api implementation >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  (void)CancelAlarm(SchM_Alarm);
  /* Nxtr Patch Start
   * Added: 11/26/12
   * Reason: Patch added to remove argument "SCHM_MSEC(0) + (TickType)1" and replace with SCHM_MSEC(2) to 
   *		 avoid the race condition that could potentially cause the srlcom tasks to be called twice before
   *		 the new data is ready. See CR6880 for more details. */
  (void)SetRelAlarm(SchM_Alarm, SCHM_MSEC(2), SCHM_MSEC(5));
  /* Nxtr Patch End */
}

/**********************************************************************************************************************
| NAME:             SchM_GetVersionInfo
| CALLED BY:        Application
| PRECONDITIONS:    none
| INPUT PARAMETERS: Pointer to version structure
| RETURN VALUES:    none
| DESCRIPTION:      Get version of the BSW Scheduler
**********************************************************************************************************************/
FUNC(void, SCHM_CODE) SchM_GetVersionInfo( Std_VersionInfoType *versioninfo )
{
  versioninfo->vendorID = SCHM_VENDOR_ID;
  versioninfo->moduleID = SCHM_MODULE_ID;
  versioninfo->instanceID = 0u;
  versioninfo->sw_major_version = (uint8)SCHM_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = (uint8)SCHM_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = (uint8)SCHM_SW_PATCH_VERSION;
}

#define SCHM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
| NAME:             Task_Init_SchM9
| CALLED BY:        Application
| PRECONDITIONS:    None
| INPUT PARAMETERS: None
| RETURN VALUES:    None
| DESCRIPTION:      Added via configurator to have a high priority task run the EcuM_StartTwo();
**********************************************************************************************************************/
TASK(Task_Init_SchM9)
{
	(void)GetResource(RES_SCHEDULER); /* Added to correct anomaly 5398 */
	EcuM_StartupTwo();

	/* Initialize the WdgM with the Rte configuration */
	NtWrapC_Wdg_TMS570LS3x_Init(&wdg_tms570ls3x_config);
	NtWrapC_WdgM_Init(&WdgMConfig_Mode0);

	/* Initialize WdgM Task Alarm */
	(void)SetRelAlarm(SchM_Alarm_ASIL_D, SCHM_MSEC(0) + (TickType)1, SCHM_MSEC(4));

	/* Enable Os tick interrupt source */
	Gpt_EnableNotification(SystemTime_uS);
	/* Provide notification for Appl_WaitNvMReady to indicate when the Memory stack resource locking must be 
	enabled.  A global signal is used for simplicity at this time, but a more maintainable interface may be
	desirable in the future. */
    EcuStartup_PreRteInitCmplt_lgc = TRUE;
	
    ReleaseResource(RES_SCHEDULER); /* Added to correct anomaly 5398 */
    ClearSysTickInterruptFlg();
	EnableSysTickInterrupt();


	TerminateTask();
}

/****************************************************************************
| NAME:             SchM_Task_ASIL_D
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule ASIL SchM Task
****************************************************************************/

TASK(SchM_Task_ASIL_D)
{
	WdgM_MainFunction();
	FlsTst_MainFunction();
	TerminateTask();
}

/****************************************************************************
| NAME:             Task_BkgndA_9
| CALLED BY:        OS
| PRECONDITIONS:    Low priority task that due to service execution times &
|                   cannot block DCM_Main which handles diagnostic service/session timing
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task contains the Diagnostic service request polling function
****************************************************************************/
TASK(Task_BkgndA_9)
{
		Dcm_RteMainFunction();
		TerminateTask();
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_SCHM_19.1:
     Reason: AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to select appropriate #pragma directives.
     Risk: MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.
*/

