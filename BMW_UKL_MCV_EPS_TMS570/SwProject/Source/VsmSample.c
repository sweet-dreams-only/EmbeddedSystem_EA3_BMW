/*******************************************************************************
**                                                                            **
**  SRC-MODULE: VsmSample.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Example for using the coding functionality                    **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** olgo         Oliver Gorisch             EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0 : 24.08.2008, olgo: RT14502: Added configured NtfyModeChg_Xxx functions
 *          19.12.2007, olgo: ported from SC6.7.2 Appl_Vsm.c and Appl_Nm.c
 */

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                    /* AUTOSAR standard types           */

#include "Vsm_Client_Cfg.h"               /* for configuration of VSM module  */
#include "Omc.h"
#include "Com.h"
#include <os.h>                        /* AUTOSAR OS */
#include "ComM.h"                      /* ComM API                         */
#include "stm.h"				/* Nxtr Patch - Fix linker errors.

boolean netMsgControlNm_Wakeup_IndicationFlag = FALSE;
boolean netMsgControlNm_GoSleep_IndicationFlag = FALSE;




/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmSample                                                  **
**                                                                            **
** DESCRIPTION   : Runnable Entity of SW-C VsmSample                          **
**                 Polling of com signals of mode switching                   **
**                                                                            **
** PRECONDITIONS : Com is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : nothing                                                    **
**                                                                            **
** REMARKS       : Has to be called cyclic from VsmSample                     **
**                                                                            **
*******************************************************************************/
void VsmSample(void)
{
   return;
} /* end of VsmSample()                                                       */



/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyModeChange_SYSTEM_TEST                           **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode change        **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newMode - new global mode of vehicle                       **
**                                                                            **
** RETURN        : nothing                                                    **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyModeChange_SYSTEM_TEST(uint8 newMode)
{
  return;                                                   /* return nothing */

} /* end of Vsm_NotifyModeChange_SYSTEM_TEST()                                */


//#if (!defined VSM_TEST_ENABLE) || (VSM_TEST_ENABLE == OFF)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyModeChange_CLIMATE_CONTROL                       **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode change        **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newMode - new global mode of vehicle                       **
**                                                                            **
** RETURN        : nothing                                                    **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyModeChange_CLIMATE_CONTROL(uint8 newMode)
{
  return;                                                   /* return nothing */
} /* end of  Vsm_NotifyModeChange_CLIMATE_CONTROL() */
//#endif /* (VSM_TEST_ENABLE == OFF) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyModeExtensionChange_SYSTEM_TEST                  **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM exten. mode change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newMode - new global extended mode of vehicle              **
**                                                                            **
** RETURN        : nothing                                                    **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyModeExtensionChange_SYSTEM_TEST(uint8 newMode)
{
  return;                                                   /* return nothing */
} /* end of  Vsm_NotifyModeChange_SYSTEM_TEST() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyModeExtensionChange_CLIMATE_CONTROL              **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM exten. mode change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newMode - new global extended mode of vehicle              **
**                                                                            **
** RETURN        : nothing                                                    **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyModeExtensionChange_CLIMATE_CONTROL(uint8 newMode)
{
  return;                                                   /* return nothing */
} /* end of  Vsm_NotifyModeChange_CLIMATE_CONTROL() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyStateChange_SYSTEM_TEST                          **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM state change       **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newState - new global state of vehicle                     **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyStateChange_SYSTEM_TEST(uint8 newOpState)
{
  return;
} /* end of Vsm_NotifyStateChange_SYSTEM_TEST() */


//#if (!defined VSM_TEST_ENABLE) || (VSM_TEST_ENABLE == OFF)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyStateChange_CLIMATE_CONTROL                      **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM state change       **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newState - new global state of vehicle                     **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyStateChange_CLIMATE_CONTROL(uint8 newOpState)
{
  return;
} /* end of Vsm_NotifyStateChange_CLIMATE_CONTROL() */
//#endif /* (VSM_TEST_ENABLE == OFF) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyEnergyStateChange_SYSTEM_TEST                    **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM energystate change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newEnergyState - new global energy state of vehicle        **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyEnergyStateChange_SYSTEM_TEST(uint8 newEnState)
{
  return;
} /* end of Vsm_NotifyEnergyStateChange_SYSTEM_TEST() */


//#if (!defined VSM_TEST_ENABLE) || (VSM_TEST_ENABLE == OFF)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyEnergyStateChange_CLIMATE_CONTROL                **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM energystate change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newEnergyState - new global energy state of vehicle        **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyEnergyStateChange_CLIMATE_CONTROL(uint8 newEnState)
{
  return;
} /* end of Vsm_NotifyEnergyStateChange_CLIMATE_CONTROL() */
//#endif /* (VSM_TEST_ENABLE == OFF) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyCommunicationErrorLockChange_SYSTEM_TEST         **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newComErrLock - new global comm. error lock of vehicle     **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyCommunicationErrorLockChange_SYSTEM_TEST(uint8 newComErrLock)
{
  return;
} /* end of Vsm_NotifyCommunicationErrorLockChange_SYSTEM_TEST() */


//#if (!defined VSM_TEST_ENABLE) || (VSM_TEST_ENABLE == OFF)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyCommunicationErrorLockChange_CLIMATE_CONTROL     **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newComErrLock - new global comm. error lock of vehicle     **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyCommunicationErrorLockChange_CLIMATE_CONTROL(uint8 newComErrLock)
{
  return;
} /* end of Vsm_NotifyCommunicationErrorLockChange_CLIMATE_CONTROL() */
//#endif /* (VSM_TEST_ENABLE == OFF) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyCommunicationChange_SYSTEM_TEST                  **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newState - new global communication error lock of vehicle  **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyCommunicationChange_SYSTEM_TEST(uint8 mode)
{
  return;
} /* end of Vsm_NotifyCommunicationChange_SYSTEM_TEST() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyCommunicationChange_CLIMATE_CONTROL              **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : newState - new global communication error lock of vehicle  **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyCommunicationChange_CLIMATE_CONTROL(uint8 mode)
{
  return;
} /* end of Vsm_NotifyCommunicationChange_CLIMATE_CONTROL() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyNetworkTimeOut_SYSTEM_TEST                       **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyNetworkTimeOut_SYSTEM_TEST(void)
{
  return;

} /* end of Vsm_NotifyNetworkTimeOut_SYSTEM_TEST() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyNetworkTimeOut_CLIMATE_CONTROL                   **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
void Vsm_NotifyNetworkTimeOut_CLIMATE_CONTROL(void)
{
  return;

} /* end of Vsm_NotifyNetworkTimeOut_CLIMATE_CONTROL() */


#define VSM_STOP_SEC_CODE
#include "MemMap.h"


/*********************** Callbacks for RTE ************************************/

#define VSM_START_SEC_CODE
#include "MemMap.h"

//#if defined ( USE_VSM_IN_SC7_WITH_RTE )
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyModeChg_SYSTEM_TEST                                   **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode change        **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : mode - new global mode of vehicle                          **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyModeChg_SYSTEM_TEST ( Vsm_OperatingModeType mode )
{
   volatile Vsm_OperatingModeType new_mode;

   new_mode = mode;

} /* NtfyModeChg_SYSTEM_TEST                                                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyModeChg_CLIMATE_CONTROL                                **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode change        **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : mode - new global mode of vehicle                          **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyModeChg_CLIMATE_CONTROL ( Vsm_OperatingModeType mode )
{
   volatile Vsm_OperatingModeType new_mode;

   new_mode = mode;

} /* NtfyModeChg_CLIMATE_CONTROL                                              */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyModeExtChg_SYSTEM_TEST                                 **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode extension     **
**                 change                                                     **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : mode extension - new global mode extension of vehicle      **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyModeExtChg_SYSTEM_TEST ( Vsm_OperatingModeExtensionType mode_ext )
{
   volatile Vsm_OperatingModeExtensionType new_mode_ext;

   new_mode_ext = mode_ext;

} /* NtfyModeExtChg_SYSTEM_TEST                                               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyModeExtChg_CLIMATE_CONTROL                             **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM mode extension     **
**                 change                                                     **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : mode extension - new global mode extension of vehicle      **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyModeExtChg_CLIMATE_CONTROL ( Vsm_OperatingModeExtensionType mode_ext )
{
   volatile Vsm_OperatingModeExtensionType new_mode_ext;

   new_mode_ext = mode_ext;

} /* NtfyModeExtChg_CLIMATE_CONTROL                                           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyStateChg_SYSTEM_TEST                                   **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM state change       **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : state - new global state of vehicle                        **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyStateChg_SYSTEM_TEST(Vsm_OperatingStateType state)
{
   volatile Vsm_OperatingStateType new_state;

   new_state = state;

} /* NtfyStateChg_SYSTEM_TEST                                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyStateChg_CLIMATE_CONTROL                               **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM state change       **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : state - new global state of vehicle                        **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyStateChg_CLIMATE_CONTROL(Vsm_OperatingStateType state)
{
   volatile Vsm_OperatingStateType new_state;

   new_state = state;

} /* NtfyStateChg_CLIMATE_CONTROL                                             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyEngStateChg_SYSTEM_TEST                                **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM energystate change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : energyState - new global energy state of vehicle           **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyEngStateChg_SYSTEM_TEST(Vsm_EnergyStateType energyState)
{
   volatile Vsm_EnergyStateType new_energyState;

   new_energyState = energyState;
} /* NtfyEngStateChg_SYSTEM_TEST                                             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NtfyEngStateChg_CLIMATE_CONTROL                            **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM energystate change **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : energyState - new global energy state of vehicle           **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NtfyEngStateChg_CLIMATE_CONTROL(Vsm_EnergyStateType energyState)
{
   volatile Vsm_EnergyStateType new_energyState;

   new_energyState = energyState;
} /* NtfyEngStateChg_CLIMATE_CONTROL                                          */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NyComErrLckChg_SYSTEM_TEST                                 **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NyComErrLckChg_SYSTEM_TEST(Vsm_CommunicationErrorLockType comErrorLock)
{
   volatile Vsm_CommunicationErrorLockType new_comErrorLock;

   new_comErrorLock = comErrorLock;
} /* NyComErrLckChg_SYSTEM_TEST                                               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : NyComErrLckChg_CLIMATE_CONTROL                             **
**                                                                            **
** DESCRIPTION   : callback - inform application about VSM                    **
**                 communication error lock change                            **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : no                                                         **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE)
   NyComErrLckChg_CLIMATE_CONTROL(Vsm_CommunicationErrorLockType comErrorLock)
{
   volatile Vsm_CommunicationErrorLockType new_comErrorLock;

   new_comErrorLock = comErrorLock;
} /* NyComErrLckChg_CLIMATE_CONTROL                                           */

//#endif /* USE_VSM_IN_SC7_WITH_RTE                                             */

#define VSM_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
