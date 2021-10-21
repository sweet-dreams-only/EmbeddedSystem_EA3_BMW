/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : ApplCallbacks.c
* Module Description: Definition of Application Callback Functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          62 %
* %date_modified:    Tue Jan 14 17:34:25 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
03/15/11   4.0     JJW        Initial metrics added
06/07/11   5.0     LWW        Added stack overflow and unhandled exception
                              handling to ErrorHook.
08/02/11    6      JJW        Replaced Wdg_Stub with Wdg for BAC3.0 integration
08/17/11    7      JJW        BAC3.0 Integration required Eep header file name change
08/19/11    8      JJW        BAC3.0 integration required removal of Wdg_Trigger when
                               the watchdog is disabled for the TMS570
08/28/11    9      LWW        Added SPIDriver Resource around EEP driver
08/28/11   10      LWW        Added suspend and resume interrupts around EEP driver
                              as temporary fix for DET issue
08/30/11   11      LWW        Removed suspend and resume interrupts because
                              resource locking was fixed
09/01/11   12      JJW       Removed Wdg.h bcause the safe watch dog is not yet configured/generated.
09/14/11   13      JJW       SafeContext Os integration requires placing osInitTimer()
                              in the StartUpHook per the integration manual
							 NvMWaitReady mdofified to prevent Os ErrorHook invocation
							  during Task_Init usage for Get/Release resource since the 
							  Os config does not have the Task_Init configured to access the
							  Get/Release resource
09/19/2011 13.1.1 SMW	     Added SchM_Task_ASIL_D call to schedule watchdog main function
09/19/11   14      JJW       Added Gpt timer expiration in place of Os timer init
                               so that both the Os Tick and WdgM tick can be called at the timer
							   expiration point.
09/21/11   15      JJW       Added Metrics Trace points for WdgM MainFunctin and SystemTick
10/10/11   16.1.1  LWW       Added watchdog initialization to StartupHook, added
                             Fee_MainFunction to Appl_WaitNvMReady
10/10/11   16.1.2  LWW       Added temporary RestoreEaBlocks function
10/18/11   16.1.4  LWW       Removed SvkHistory from RestoreEaBlocks function
11/02/11   17      JJW       Updated metrics for Safe Os
12/06/11   19      JJW       Removed CorrDiagFiltSV_Volt Block Eep to Fee migration logic to support HwTrq CBD
                              Integration
12/06/11   20      JJW       Remove EA_BLOCK_MTRPARMLEARNED block Eep to Fee migration logic to support ParamComp CBD
                              Integration.  Also renamed the appropriate block for the nom motor EOL data.   
04/17/12   22      JJW       Updates for multiple deprecated Ea block support
04/20/12   23      JJW       Deprecated HwTrqScale Ea block anomaly correction
05/02/12   24      JJW       Metrics v3 Integration
05/10/12   25      JJW       Deprecated Return Range Nvm/Ea block support added
05/30/12   26      JJW       Removed Ea to Fee data migration function
							 Removed Fee_MainFunction calls from Appl_WaitNvMReady
06/13/12   27      BDO       Add FlexRay Communication Error diagnostic recovery to ApplFr_ISR_CycleStart()
06/20/12   28	   KJS		 Updated NvM block name for LearnedEOT.
07/20/12   29      BDO       Removed EOLRtnRange_MtrNm_f32    CR5873
08/06/12   30	   KJS		 Added FlsTst.h 
08/17/12   31	   KJS		 Added block changes for DEM primary and secondary for snapshot changes.	
08/20/12   32	   KJS		 Added changes for old rack center block. 
08/21/12   33      BDO       Replaced hard-coded NTC $1D1 with global DTC constant NTC_Num_FlexrayCommunicationError
10/01/12   34      JJW       Os v5.04 integration
00/01/12   35      JJW  	 Remove WdgM_UpdateTickCount() call in System Tick ISR for change to WdgM 
								 hardware time base
10/26/12   38	   BDO		 Temp change - commented out Al_SrlComOutput synchronization to flexray bus
10/27/12   39	   JJW		 Al_SrlComOutput syncronization removal from ISR (moving to Task level )
11/14/12   40	   JJW		 Move WdgM init to immediately after Rte_Start completion
11/14/12   41	   JJW		 Removed Protection and Error Hooks
03/21/13   44      JJW       Appl_WaitNvMReady optimized behavior during initialization to improve 
								start-up time.
04/02/13   45      JJW       Deprecated block change to a CallBack strategy to improve start-up timing
04/06/13   47      JJW       Update src with new tasks names, see anomaly 4762
05/03/13   48      JJW       Added Appl_FlsTstCompletedNotif function to suspend FlsTst after the first test 
								interval is completed
05/30/13   49,50   JJW       Added deprecated block support for AbsHwPos blocks which were changed to add redundant storage. 
06/01/13   51	   KJS       Corrected deprecated block support for AbsHwPos to prevent MPU violations
06/27/13   52	   JJW		 Consolidated AbsHwPos Pim Nvm into a single Trim Block
06/27/13   53	   JJW		 Corrected block deprecated migration errors
09/25/13   55	   KJS		 Added HWAP support
11/20/13   56	   KJS		 Added call back support to migrate data from old SVK plant/supplier blocks to new blocks. 
01/14/13   58	   KJS		 Added support for NvMP for LearnEOT
11/05/14   59	   KJS		 Removed all depreciated support for Fee migration.
12/09/14   60	   AS		 GliwaT1 component integration.
04/24/15   61	   ABS		 EA3#610: EPS-NEX01 # Flash # Service WDBI_CPS returned a negative response.
05/05/15   62	   ABS		 EA3#1159 Duty cycle filters no reinitialized at startup.
******************************************************************************/

#include "Std_Types.h"
#include "Rte_dcm.h"
#include "NvM_Cfg.h"
#include "EcuM.h"
#include "FrIf.h"
#include "NvM.h"
#include "MemIf_Types.h"
#include "Fr_Cfg.h"
#include "Os.h"
#include "Gpt.h"
#include "Fr.h"
#include "FlsTst.h"

#include "fixmath.h"
#include "GlobalMacro.h"

#include "osek.h"
#include "Interrupts.h"
#include "RednRpdShtdn.h"
#include "Ap_DfltConfigData.h"
#include "DataLogistic.h"
#include "Ap_VehCfg.h"
#include "Cd_FeeIf.h"

extern boolean EcuStartup_PreRteInitCmplt_lgc;

/*****************************************************************************
  * Name:        StartupHook
  * Description: Required OSEK Hook function, with no functional requirements
  *               in the context of the project.
  * Called by:   OS (On start-up)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) StartupHook(void)
{	

}

/*****************************************************************************
  * Name:        ShutdownHook
  * Description: Required OSEK Hook function, to start shutdown process on OS
  *               shutdown event.
  * Called by:   OS (On shutdown)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, OSHOOK_CODE) ShutdownHook(StatusType s)
{
  EcuM_Shutdown();
}

/*****************************************************************************
  * Name:         SystemTick
  * Description: 
  * Called by:   Gpt Timer Expiration Notification
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) SystemTick(void)
{	
	/*TODO: Move System Time tick count update here or update the system time to use the full  
	 * 64 bit hardware counter to alleviate the need for maintaining an accumulator seperate from
	 * the hardware accumulator.
	 */

	CounterTriggerSystemTimer();

}

#if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)
/**************************************************************************************************
Function name    : ApplFr_ISR_CycleStart
------------------------------------------------------------------------------------------------
Description      : Application callback to handle the Cycle Start IRQ of the CC
------------------------------------------------------------------------------------------------
Called by        : vFr_DrvISR
------------------------------------------------------------------------------------------------
Parameter        : void
------------------------------------------------------------------------------------------------
Returncode       : void
------------------------------------------------------------------------------------------------
Misc             : 
**************************************************************************************************/
void ApplFr_ISR_CycleStart(void)
{
  SchM_SyncTasks();

  NxtrDiagMgr9_SetNTCStatus(NTC_Num_FlexrayCommunicationError, 0x01, NTC_STATUS_PASSED);
}
#endif

#if defined( VGEN_ENABLE_DRVFR__BASEASR )
/**************************************************************************************************
Function name    : ApplFr_ISR_Timer0
------------------------------------------------------------------------------------------------
Description      : Application callback to handle the IRQ of the CC Timer 0
------------------------------------------------------------------------------------------------
Called by        : vFr_DrvISR
------------------------------------------------------------------------------------------------
Parameter        : void
------------------------------------------------------------------------------------------------
Returncode       : void
------------------------------------------------------------------------------------------------
Misc             : 
**************************************************************************************************/
void ApplFr_ISR_Timer0(void)
{
  FrIf_JobListExec_0();
}


/**************************************************************************************************
Function name    : ApplFr_ISR_Timer1
------------------------------------------------------------------------------------------------
Description      : Application callback to handle the IRQ of the CC Timer 1
------------------------------------------------------------------------------------------------
Called by        : vFr_DrvISR
------------------------------------------------------------------------------------------------
Parameter        : void
------------------------------------------------------------------------------------------------
Returncode       : void
------------------------------------------------------------------------------------------------
Misc             : 
**************************************************************************************************/
void ApplFr_ISR_Timer1(void)
{
	/*TBD*/
}

#endif

/*Additional callbacks*/


FUNC(void, DCM_APPL_CODE) Rte_DcmResponsePendingConfirmation(Dcm_ConfirmationStatusType status)
{

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_WaitNvMReady                                          **
**                                                                            **
** DESCRIPTION   : Performs a synchronous wait until NvM has finished         **
**                 the last job                                               **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : Appl_Nv_Mode:       Idle, fast or slow mode                **
**                 Appl_NvBlockNumber: Id of NvM block to wait for            **
**                                                                            **
** PARAMETER     : blockNumber: Id of  NvM block to wait for                  **
**                 fastMode:    TRUE:  Schedule Nv stack in loop (used during **
**                                     startup or Coding)                     **
**                              FALSE: Nv stack is scheduled via cyclic tasks **
**                                     (used during normal operation)         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This function is blocking! Do not call this function       **
**                 within the context of a high priority task!!!              **
**                                                                            **
*******************************************************************************/

boolean Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode)
{
    /* TBD */
	NvM_RequestResultType Int_NvMultiBlockStatus;
	TaskType  Id = 0;
	MemIf_StatusType ModuleState;

	/* Provide a low latency loop during the initialization phase when NvM is being read and none of the 
	other tasks are actively running that use the Memory stack resource.  This is accomplished by providing
	a mainfunction call cycle which does not use the Os resource locking API's, as the API's are time consuming
	*/
	
	if(TRUE == EcuStartup_PreRteInitCmplt_lgc) {
		GetTaskID(&Id);
	}
	
    do
    {
    	if (fastMode == TRUE)
	    {
	    	/* TODO: Evaluate the resource sharing between Task_Init and the SchM and Background tasks
			 * to confirm that there are no possible conflicts and that it is ok to skip the protection
			 * for the Task_Init as it is not desirable to have a resource ceiling that is as high as
			 * the Task_Init.
			 */

    		if((Task_InitB_9 == Id) || (FALSE == EcuStartup_PreRteInitCmplt_lgc))
	    	{
		    	NvM_MainFunction();
		    	TWrapC_Fee_MainFunction();
		    }
	    	else
	    	{
		    	GetResource(OsRes_MemStackTask);
		    	NvM_MainFunction();
		    	TWrapC_Fee_MainFunction();
		      	ReleaseResource(OsRes_MemStackTask);
	    	}
	      	/*TODO: Determine if servicing the watchdog is required within the Appl_WaitNvMReady
	      	 * function. The current design does not enable the watchdog at init, so triggering it
	      	 * causes a wotchdog violation by triggering the watchdog before it is enabled. 
	      	 * At the time of this change, there was no API to query the watchdog state.
	      	 */
	      	/*Wdg_Trigger();*/
	    }

	    NvM_GetErrorStatus(blockNumber, &Int_NvMultiBlockStatus);
		ModuleState = TWrapC_Fee_GetStatus();

    }
    while((Int_NvMultiBlockStatus==NVM_REQ_PENDING)|| (ModuleState != MEMIF_IDLE));

	return TRUE;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_FlsTstCompletedNotif                                  **
**                                                                            **
** DESCRIPTION   : FlsTst configured notification that is invoked upon the    **
**					the completion of the Runtime config set.  In order to    **
**					minimize Flash bus contentions between the DMA and micro  **
**					core during EPS runtime, the Flash test is suspended      **
**					after the first test interval is completed. This strategy **
**					provides better micrprocessor throughput resulting from   **
**					less wait states caused by Flash access contentions.      **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** RETURN        : void                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, AUTOMATIC) Appl_FlsTstCompletedNotif(void)
{
	FlsTst_Suspend();
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : TRUSTED_TWrapS_StaMd_Init0                                 **
**                                                                            **
** DESCRIPTION   : Initialization function									  **
**                                                                            **
** PARAMETER     : void                                                       **
**                                                                            **
** RETURN        : void                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, AUTOMATIC) TRUSTED_TWrapS_StaMd_Init0(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	StaMd_Init0();
	return;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : TWrapC_StaMd_Init0                                  		  **
**                                                                            **
** DESCRIPTION   : Trusted function call to Server wrapper function   		  **
**                                                                            **
** PARAMETER 	 : void                                                       **
**                                                                            **
** RETURN        : void                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, AUTOMATIC) TWrapC_StaMd_Init0(void)
{
	(void)CallTrustedFunction((TrustedFunctionIndexType)TWrapS_StaMd_Init0, (TrustedFunctionParameterRefType)0);
	return;
}


