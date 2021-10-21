/**********************************************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Appl_Tasks.c
* Module Description: AUTOSAR BSW Scheduler
* Product           : Gen II Plus - EA3.0
* Author            : 
**********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
* Version Control:
* Date Created:      Wed Jul 20 16:33:22 2010
* %version:          11 %
* %derived_by:       cz7lt6 %
* %date_modified:    Sat Nov 10 10:17:08 2012 %
*----------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/03/11   2.0     JJW      	Added Metrics_MainFunction
 * 05/02/12   3       JJW      	Metrics v3 Integration
 * 10/14/12   4       KJS      	Anomaly correction for 3891. Added SWT check in background task.               CR6542
 * 10/31/12   5       BDO      	Anomaly - move Dcm_RteMainFunction to separate task
 * 11/08/12   6	   	  KJS		Moved Dcm_RteMainFunction call to SchM.c and moved rev log.
 * 09/29/14   8	   	  KJS		Added memmap statements around global variables
 * 04/01/15	  10	  KJS		Added NvM 'quick' write support
 * 07/23/15   11      KJS       Added support for OS resources in NvM/Fee operations (NTC 0x31 issue fix)
 */




/*******************************************************************************
 * Includes
 *******************************************************************************/

#include "Os.h"
#include "Swt_Appl.h"
#include "Swt_Common.h"
#include "FlsTst.h"
#include "T1_AppInterface.h"
#include "CDD_Data.h"
#include "Cd_NvMProxy.h"
#include "Cd_FeeIf.h"
#include "NvM.h"
#include "osek.h"

/*******************************************************************************
 * Defines
 *******************************************************************************/

#define APPLTASKS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(SwtRC_t, AUTOMATIC) SWTStartupChk_Cnt_enum;

#define APPLTASKS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define APPLTASKS_START_SEC_VAR_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(boolean, AUTOMATIC)SWTPerChkComp_Cnt_M_lgc = FALSE;

#define APPLTASKS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define APPLTASKS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC const VAR(uint8, AUTOMATIC) swid[] = { 0x00, 0xBD, 0x00, 0x01 };

#define APPLTASKS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*******************************************************************************
 * Global variables
 *******************************************************************************/


/*******************************************************************************
 * Global functions
 *******************************************************************************/

/****************************************************************************
| NAME:             Bkgnd_Task
| CALLED BY:        OS
| PRECONDITIONS:    None
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Task to schedule a low priority background loop (i.e. no deadline )
****************************************************************************/
TASK(Task_BkgndB_9)
{
  VAR(NvM_RequestResultType, AUTOMATIC) NVMErrorStatus_Cnt_T_u8;

  for(;;)
  {
     T1_AppBgHandler();

    /* Add one time call for SWT check */
    if (SWTPerChkComp_Cnt_M_lgc == FALSE)
    {
       	SWTStartupChk_Cnt_enum = Swt_PeriodicalChecks(0x30, swid);
        SWTPerChkComp_Cnt_M_lgc = TRUE;
    }

    if(CDD_NvMFastWriteEnable_Cnt_G_lgc == TRUE)
    {
        do
        {
            GetResource(OsRes_MemStackTask);
            NvMProxy_MainFunction();
            NvM_MainFunction();
            TWrapC_Fee_MainFunction();
            ReleaseResource(OsRes_MemStackTask);

            NvMProxy_GetErrorStatus(0u, &NVMErrorStatus_Cnt_T_u8);
        }while(NVM_REQ_PENDING == NVMErrorStatus_Cnt_T_u8);
    }

  }
}


