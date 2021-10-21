/*******************************************************************************
**                                                                            **
**  SRC-MODULE: ComControl.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : ComControl as sub modul of VSM Client                         **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** olgo         Oliver Gorisch             EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.2: 12.09.2011, olho: CR71039: Commented void casts
 * V1.2.1: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V1.2.0: 08.02.2011, olgo: CR70864: VSM shall support ECUs without NM
 * V1.1.0: 13.10.2010, olgo: CR70555: Multiple Call to Nvm_WriteBlock()
 * V1.0.1: 06.07.2010, bemo: CR70712: STOP_SEC_CONST code missing
 * V1.0.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 *         22.11.2009, olgo: first version
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 8.7 (required)
  *   Objects shall be defined at block scope if they are only accessed from
  *   within a single function.
  *
  *   Reason:
  *   See EB_MISRA_8_7 (EB_MISRAC2004_Compliance_Autosar.pdf).
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_C_FILE
   #define VSM_C_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */

#if defined (VSM_VERSION_BAC3x)              /* sub module ComControl only    */
                                             /* used in BAC3.0                */

/* ---- Perform version checking ------------ */
#if ( ( COMCONTROL_MAJOR_VERSION != 4u ) || \
      ( COMCONTROL_MINOR_VERSION != 1u ) )
  #error "ComControl.c: Wrong version of ComControl.h found!!"
#endif

#if ( ( COMCONTROL_CFG_MAJOR_VERSION != 4u ) || \
      ( COMCONTROL_CFG_MINOR_VERSION != 1u ))
  #error "ComControl.c: Wrong version of ComControl_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Local Constant Data                                   **
*******************************************************************************/
#if (COMCONTROL_NM_HANDLING == STD_ON)
   #define VSM_START_SEC_CONST_UNSPECIFIED
   #include <MemMap.h>

   /* Deviation MISRA-1 */
   _STATIC_ CONST(NetworkHandleType, VSM_CONST)
   ComControlNmChannels[COMCONTROL_NUM_NM_CHANNELS] = COMCONTROL_NM_CHANNEL_IDS;

   #define VSM_STOP_SEC_CONST_UNSPECIFIED
   #include <MemMap.h>
#endif /* COMCONTROL_NM_HANDLING == STD_ON                                    */


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/
#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

_STATIC_ VAR(Wur_WakeupType, VSM_VAR) comModesPerUser[VSM_NUM_COMMUSERS];

_STATIC_ VAR(uint8, VSM_VAR) stored_mode;
_STATIC_ VAR(uint8, VSM_VAR) stored_controlType;

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

_STATIC_ FUNC(Std_ReturnType, VSM_PRIVATE_CODE) HandlePDUGroups
(
   uint8 mode,
   uint8 controlType
);

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                       Local Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : HandlePDUGroups                                            **
**                                                                            **
** DESCRIPTION   : handles settings of communication mode and control type    **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : mode:         communcation mode (see 8.2.2.1 in Spec V1.6) **
**                 controlType:  control type (see 8.2.2.2 in Spec V1.6)      **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(Std_ReturnType, VSM_PRIVATE_CODE) HandlePDUGroups
(
   uint8 mode,
   uint8 controlType
)
{
   VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
   VAR(Std_ReturnType, AUTOMATIC) retValComMode;
   VAR(uint32, AUTOMATIC) comMUserIndex;
   VAR(ComM_ModeType, AUTOMATIC) curComMode = COMM_NO_COMMUNICATION;

   #if (COMCONTROL_NM_HANDLING == STD_ON)
      VAR(uint32, AUTOMATIC) nmChannelIndex;
   #endif /* COMCONTROL_NM_HANDLING == STD_ON                                 */


   /* normal messages                                                         */
   if (
        ( (uint8)COMM_DIAG_NORMAL_COMM_MSG == controlType ) ||
        ( (uint8)COMM_DIAG_NORMAL_AND_NM_COMM_MSG == controlType )
      )
   {
      for( comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++ )
      {
         retValComMode = ComM_GetCurrentComMode( VsmComMUserArray[comMUserIndex].ComMUser,
                                                 &curComMode );

         if ( retValComMode == E_OK )
         {
            switch( mode )
            {
               case (uint8)COMM_DIAG_ENABLE_RX_AND_TX:
                  if ( ( curComMode == COMM_FULL_COMMUNICATION ) ||
                       ( curComMode == COMM_SILENT_COMMUNICATION ) )
                  {
                     Com_IpduGroupStart(VsmComMUserArray[comMUserIndex].RxIPdus, FALSE);
                  }

                  if ( curComMode == COMM_FULL_COMMUNICATION )
                  {
                     Com_EnableReceptionDM(VsmComMUserArray[comMUserIndex].RxIPdus);
                     Com_IpduGroupStart(VsmComMUserArray[comMUserIndex].TxIPdus, FALSE);
                  }
                  break;

               case (uint8)COMM_DIAG_ENABLE_RX_AND_DISABLE_TX:
                  if ( ( curComMode == COMM_FULL_COMMUNICATION ) ||
                       ( curComMode == COMM_SILENT_COMMUNICATION ) )
                  {
                     Com_IpduGroupStart(VsmComMUserArray[comMUserIndex].RxIPdus, FALSE);
                  }

                  if ( curComMode == COMM_FULL_COMMUNICATION )
                  {
                     Com_EnableReceptionDM(VsmComMUserArray[comMUserIndex].RxIPdus);
                  }

                  Com_IpduGroupStop(VsmComMUserArray[comMUserIndex].TxIPdus);
                  break;

               case (uint8)COMM_DIAG_DISABLE_RX_AND_ENABLE_TX:
                  Com_DisableReceptionDM(VsmComMUserArray[comMUserIndex].RxIPdus);
                  Com_IpduGroupStop(VsmComMUserArray[comMUserIndex].RxIPdus);

                  if ( curComMode == COMM_FULL_COMMUNICATION )
                  {
                     Com_IpduGroupStart(VsmComMUserArray[comMUserIndex].TxIPdus, FALSE);
                  }
                  break;

               case (uint8)COMM_DIAG_DISABLE_RX_AND_TX:
                  Com_DisableReceptionDM(VsmComMUserArray[comMUserIndex].RxIPdus);
                  Com_IpduGroupStop(VsmComMUserArray[comMUserIndex].RxIPdus);

                  Com_IpduGroupStop(VsmComMUserArray[comMUserIndex].TxIPdus);
                  break;

               default:
                  break;
            }
         }
         else
         {
            retVal = E_NOT_OK;
         }
      }
   }
   /* Nm messages                                                       */
#if (COMCONTROL_NM_HANDLING == STD_ON)
   if (
        ( (uint8)COMM_DIAG_NM_COMM_MSG == controlType ) ||
        ( (uint8)COMM_DIAG_NORMAL_AND_NM_COMM_MSG == controlType )
      )
   {
      switch( mode )
      {
         case (uint8)COMM_DIAG_DISABLE_RX_AND_ENABLE_TX:
         case (uint8)COMM_DIAG_ENABLE_RX_AND_TX:
            for( nmChannelIndex = 0; nmChannelIndex < COMCONTROL_NUM_NM_CHANNELS; nmChannelIndex++)
            {
               if( Nm_EnableCommunication(ComControlNmChannels[nmChannelIndex]) == NM_E_NOT_OK )
               {
                  retVal = E_NOT_OK;
               }
            }
            break;

         case (uint8)COMM_DIAG_ENABLE_RX_AND_DISABLE_TX:
         case (uint8)COMM_DIAG_DISABLE_RX_AND_TX:
            for( nmChannelIndex = 0; nmChannelIndex < COMCONTROL_NUM_NM_CHANNELS; nmChannelIndex++)
            {
               if( Nm_DisableCommunication(ComControlNmChannels[nmChannelIndex]) == NM_E_NOT_OK )
               {
                  retVal = E_NOT_OK;
               }
            }
            break;

         default:
            break;
      }
   }
#endif /* COMCONTROL_NM_HANDLING == STD_ON                                    */

   return retVal;
} /* end of HandlePDUGroups()                                                 */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ComControl_Init                                            **
**                                                                            **
** DESCRIPTION   : initialised VSM ComControl submodule                       **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : VSM_COC004                                                 **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) ComControl_Init(void)
{
   uint8 comMUserIndex;

   for(comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++)
   {
      comModesPerUser[comMUserIndex].LastWakeup = COMM_NO_COMMUNICATION;
      comModesPerUser[comMUserIndex].CurrentWakeup = COMM_NO_COMMUNICATION;
   }

   stored_mode        = 0;
   stored_controlType = 0;

   return;
} /* end of ComControl_Init()                                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ComControl_Main                                            **
**                                                                            **
** DESCRIPTION   : Mainfunction of ComControl sub module                      **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : Should be called cyclic and only from Vsm_MainFunction()   **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) ComControl_Main(void)
{
   ComM_ModeType                          comMMode;
   uint8                                  comMUserIndex;
   boolean                                comMModeChanged;
   Std_ReturnType                         retVal;

   /* VSM_COC005:                                                             */
   /* ComControl shall monitor in its cyclic main function whether one of     */
   /* the ComM channels has switched to FULL_COMMUNICATION since the last run */
   /* of the main function, when the persistently stored mode and control     */
   /* type demand a stop of PDU-groups. In case a switch to                   */
   /* FULL_COMMUNICATION has been indicated the ComControl shall again stop   */
   /* PDU-groups according to mode and control type settings                  */
   comMModeChanged = FALSE;

   for(comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++)
   {
      retVal = ComM_GetCurrentComMode( VsmComMUserArray[comMUserIndex].ComMUser,
                                              &comMMode );

      if ( retVal == E_OK )
      {
         if ( comMMode == COMM_FULL_COMMUNICATION )
         {
            comModesPerUser[comMUserIndex].CurrentWakeup = COMM_FULL_COMMUNICATION;

            if ( comModesPerUser[comMUserIndex].LastWakeup == COMM_NO_COMMUNICATION )
            {
               comMModeChanged = TRUE;
            }
         }
         else
         {
            comModesPerUser[comMUserIndex].CurrentWakeup = COMM_NO_COMMUNICATION;
         }
      }
   }

   /* a switch to FULL_COMMUNICATION has been indicated                       */
   if ( comMModeChanged == TRUE )
   {
      retVal = HandlePDUGroups( stored_mode, stored_controlType );
   }

   if ( retVal == E_OK )
   {
      for(comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++)
      {
         comModesPerUser[comMUserIndex].LastWakeup =
                                   comModesPerUser[comMUserIndex].CurrentWakeup;
      }
   }

   return;
} /* end of ComControl_Main()                                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_CommunicationControl                                   **
**                                                                            **
** DESCRIPTION   : Sets the new CommunicationControl. Dependant on the        **
**                 parameter values PDU-groups will be started/stopped        **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : mode:        Defines which actions shall be processed by   **
**                              the ComM(enable/disable RX and/or TX)         **
**                 controlType: Defines which message types shall be enabled  **
**                              or dis-abled                                  **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : VSM_COC001                                                 **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_CommunicationControl
(
   uint8 mode,
   uint8 controlType
)
{
   VAR(Std_ReturnType, AUTOMATIC) retVal;

   /* VSM_COC002: On call of this function the ComControl shall - depending    */
   /*             on the values of the parameters - start or stop certain      */
   /*             PDU-groups                                                   */
   stored_mode        = mode;
   stored_controlType = controlType;
   retVal      = HandlePDUGroups(mode, controlType);

   return retVal;
} /* end of Vsm_CommunicationControl()                                         */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_VERSION_BAC3x                                                   */

/*** End of file **************************************************************/
