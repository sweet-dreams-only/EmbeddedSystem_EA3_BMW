/*******************************************************************************
**                                                                            **
**  SRC-MODULE: ApplNetInterface.c                                            **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx Autosar v2.1                                          **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : This module contains all communication bus dependend          **
**              function calls, for example: module initialisation, start     **
**              and stop of communication on the supported communication      **
**              buses, reinitialisation of the communication buses.           **
**              This module within the new functions called out from the      **
**              diagnosis eliminates the communication bus dependencies.      **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/* Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/15/11   2       BDO        Correct anomaly 2066 - read KILOMETERSTAND
 * 08/03/11   3       JJW        BAC3.0 Integration changes
 * 09/29/14   5       KJS        Added memmap statements around global variables
 */
 
/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** mazw         Markus Zwickl              MB-technology GmbH                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.0: 25.11.2008, mazw: deleted wrapper for Fr,
 *							 deleted wrapper for FrIf,
 *							 deleted wrapper for FrTp
 *         20.11.2008, mazw: deleted wrapper for Nm,
 *							 deleted wrapper for Os,
 *							 deleted wrapper for Com
 * V1.0.0: 01.04.2008, olgo: BSCTEMPLATE-45: Remove unused net signal
 *                           indications from ApplNetinterface
 *         25.02.2008, miwe: added diagnostic tester Ids F0...FD
 *         20.11.2007, olgo: integration of VSM
 *         05.09.2007, miwe: ported from SC6.7.2 file version V4.0.2
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "Os.h"					  /* API for OSEK OS						  */
#include "ApplNetInterface.h"     /* module own header file                   */
//#include "ComM_Appl.h"            /* ComM API                                 */
#include "Appl_Src_Cfg.h"         /* Application configuration data           */
//#include "Appl_Nm.h"              /* ApplNm_Task                              */
#include <Dio.h>                  /* AUTOSAR DIO Driver                       */
#include "FrIf_Lcfg.h"            /* FrIf_MainFunction_0, FrIf_JobListExec_0  */

#include "Com.h"

/*******************************************************************************
**                      Local Function Declarations                           **
*******************************************************************************/

_STATIC_ void WakeUpWireHandling(void);


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define APPLNETINTERFACE_START_SEC_VAR_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint32, AUTOMATIC) netMsgMileKm = 0xFFFFFFU;

#define APPLNETINTERFACE_STOP_SEC_VAR_32
#include "MemMap.h" /* PRQA S 5087 */

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : WakeUpWireHandling                                         **
**                                                                            **
** DESCRIPTION   : This function checks for a wakeup indication on the wakeup **
**                 wire.                                                      **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
_STATIC_ void WakeUpWireHandling(void)
{
/* No wakeup wire handling is required for the UKL/MCV program */
}


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplNetInterface_Init                                      **
**                                                                            **
** DESCRIPTION   : t.b.d.                                                     **
**                                                                            **
** PRECONDITIONS : t.b.d.                                                     **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
void ApplNetInterface_Init(void)
{
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplHandleBusState                                         **
**                                                                            **
** DESCRIPTION   : This function sets the bus into sleep mode after a certain **
**                 timeout if no actions have been done on the bus.           **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This function has to be called cyclically in the same task **
**                 as the corresponding ComM main function for this channel!  **
**                 It has to be ensured that ComM actions and controller mode **
**                 changes do not occur during this function!                 **
**                                                                            **
*******************************************************************************/
void ApplHandleBusState(void)
{
}


/*******************************************************************************
**                      Message Indication Functions                          **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : KILOMETERSTAND_Rx_MILE_KM_SignalIndication                 **
**                                                                            **
** DESCRIPTION   : Indication function of Signal "MILE_KM" for CAN            **
**                 message KILOMETERSTAND with                                **
**                                                                            **
** PRECONDITIONS : no                                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : Its called from COM                                        **
**                                                                            **
*******************************************************************************/
FUNC (void, RTE_APPL_CODE) KILOMETERSTAND_Rx_MILE_KM_SignalIndication(void)
{

   uint32 temp;

   Com_ReceiveSignal( Com_MILE_KM__KILOMETERSTAND,
                      (void*)&temp ); 

   netMsgMileKm = temp;

}


/*******************************************************************************
**                      Interrupt Handlers                                    **
*******************************************************************************/

/*
 * ISR for FlexRay CC absolut timer.
 */
ISR(FlexRayInterrupt)
{
   FrIf_JobListExec_0();
}

/*** End of file **************************************************************/

