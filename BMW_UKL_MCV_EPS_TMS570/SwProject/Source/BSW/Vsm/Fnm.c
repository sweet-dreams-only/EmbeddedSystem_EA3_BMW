/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Fnm.c                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Functional network management (FNM) submodule of VSM Client   **
**                                                                            **
**  REMARKS   : The FNM in is responsible for keeping track of the function   **
**              which currently keeps the bus awake and sending the id of     **
**              this function in the User Data of the NM message              **
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.2: 07.11.2011, thmi: CR71160:    Fix wrong array index in Fnm_Main
 *         07.11.2011, thmi: CR71161:    Fix wrong usage of NmChannelId
 *                                       in Nm_SetUserData call.
 * V1.3.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V1.3.0: 20.10.2010, olgo: CR70831:    VSM FCT id parameter is only for
 *                                       ASR 3.0 with FNM
 *         15.09.2010, olgo: CR70775:    Debouncing of additional NM-messages
 *                                       during active wakeup
 * V1.2.0: 27.05.2010, olgo: CR70668:    Vsm Fnm.c doesn't include
 *                                       VSM_ECU_ID_HEADER
 * V1.1.0: 23.04.2010, olgo: BSCVSM-156: BAC3.0 LIN wir faelschlicherweise auch
 *                                       fuer Nm aktiviert (RT23790)
 *                           BSCVSM-157: CanNm_RequestBusSynchronization call
 *                                       don't working on Flexray only devices
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


#if defined (VSM_VERSION_BAC3x) && \
    defined (VSM_ENABLE_FUNC_NM)             /* sub module Fnm only           */
                                             /* used in BAC3.0                */

/* ---- Perform version checking ------------ */
#if ( ( FNM_MAJOR_VERSION != 4u ) || \
      ( FNM_MINOR_VERSION != 1u ) )
  #error "Fnm.c: Wrong version of Fnm.h found!!"
#endif

#if ( ( FNM_CFG_MAJOR_VERSION != 4u ) || \
      ( FNM_CFG_MINOR_VERSION != 1u ))
  #error "Fnm.c: Wrong version of Fnm_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

#define LOWESTFUNCTIONID_INITAL_VALUE 0xFFFFu
#define REQBUSSYNCH_REPETITIONS       3
#define REQBUSSYNCH_DEBOUNCING_TIME   100
#define USERDATA_LENGTH               8

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

typedef struct                                 /* Mapping of Vsm function id  */
{                                              /* to ComM User                */
  uint16              funcId;
  ComM_UserHandleType comMUserHandle;
} FuncIdComMUserMapType;

typedef uint8 FnmUserDataArrayType[USERDATA_LENGTH];
typedef struct                                 /* typedefiniton for NM user   */
{                                              /* data used by NM             */
   FnmUserDataArrayType UserData;
   boolean Initcall;
} FnmUserDataType;

typedef CONSTP2CONST(uint8, AUTOMATIC, NM_APPL_CONST) FnmUserDataArrayPtrType;
                                               /* typedefiniton for NM user   */
                                               /* data poiter - only used for */
                                               /* casting                     */


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/* Deviation MISRA-1 */
static const FuncIdComMUserMapType FuncIdComMUserMap[VSM_NUM_FUNCIDS] =
                                                     VSM_MAP_FUNCID_TO_COMMUSER;
             ControlReqBusSyncType ControlReqBusSync[VSM_COMM_NUM_CHANNELS];
static       FnmUserDataType       FnmUserData[VSM_COMM_NUM_CHANNELS];


/*******************************************************************************
**                      Local Functions Declaration                           **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

_STATIC_ FUNC(void, VSM_PUBLIC_CODE) Fnm_NmSetUserData
(
   NetworkHandleType Channel,
   uint16            functId
);

#if defined ( USE_VSM_WITH_CAN ) || defined ( USE_VSM_WITH_FLEXRAY )
   _STATIC_ FUNC(boolean, VSM_PUBLIC_CODE) HandleNmBusSynchronization
   (
      NetworkHandleType Channel
   );
#endif /* defined USE_VSM_WITH_CAN || USE_VSM_WITH_FLEXRAY                    */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Fnm_NmSetUserData                                          **
**                                                                            **
** DESCRIPTION   : set user data of Nm via Nm_SetUserData                     **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, VSM_PUBLIC_CODE) Fnm_NmSetUserData
(
   NetworkHandleType Channel,
   uint16            functId
)
{
   uint8 lowbyte;
   uint8 highbyte;
   uint8 userDataOffset;
   Nm_ReturnType nmResult;

   if(Vsm_NmChannelComMChannelCheck[Channel] == TRUE)
   {
   /* VSM_FNM006: The user data shall consist of the following 4 bytes:       */
   /* Byte0: Least significant byte of Function Id                            */
   /* Byte1: Most significant byte of Function Id                             */
   /* Byte2: 0x00                                                             */
   /* Byte3: Ecu Id                                                           */
   if ( ( Vsm_ComMBusTypeOfChannel[Channel].nmtype ==  VSM_NM_FULL )    ||
        ( Vsm_ComMBusTypeOfChannel[Channel].nmtype ==  VSM_NM_PASSIVE )
      )
   {

      #if defined ( USE_VSM_WITH_CAN )
         if ( Vsm_ComMBusTypeOfChannel[Channel].bustype == VSM_BUS_CAN )
         {
            userDataOffset = VSM_NMSETUSERDATA_OFFSET_CAN;
         }
         else
      #endif /* USE_VSM_WITH_CAN                                              */
      #if defined ( USE_VSM_WITH_FLEXRAY )
         if ( Vsm_ComMBusTypeOfChannel[Channel].bustype == VSM_BUS_FR )
         {
            /* this part are not matched by Coverage tests                    */
            userDataOffset = VSM_NMSETUSERDATA_OFFSET_FR;
         }
         else
      #endif /* USE_VSM_WITH_FLEXRAY                                          */
      {
         /* actully not implemented                                           */
         /* this part are not matched by Coverage tests                       */
         userDataOffset = 0;
      }

      lowbyte  = (uint8) (functId & 0x00FFU);
      highbyte = (uint8)((functId & 0xFF00U) >> 8);

      if ( ( FnmUserData[Channel].UserData[0 + userDataOffset] != lowbyte  ) ||
           ( FnmUserData[Channel].UserData[1 + userDataOffset] != highbyte ) ||
           ( FnmUserData[Channel].Initcall    == FALSE    )
         )
      {
         FnmUserData[Channel].UserData[0 + userDataOffset] = lowbyte;
         FnmUserData[Channel].UserData[1 + userDataOffset] = highbyte;
         FnmUserData[Channel].UserData[2 + userDataOffset] = 0;
         FnmUserData[Channel].UserData[3 + userDataOffset] = ( VSM_ECU_ID );

         nmResult = Nm_SetUserData(
                        Vsm_NmChannelComMChannelMap[Channel],
                        (FnmUserDataArrayPtrType)FnmUserData[Channel].UserData);
         if (nmResult == NM_E_OK)
         {
            FnmUserData[Channel].Initcall = TRUE;
         }
      }
   }
   }
   return;
}


#if defined ( USE_VSM_WITH_CAN ) || defined ( USE_VSM_WITH_FLEXRAY )
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : HandleNmBusSynchronization                                 **
**                                                                            **
** DESCRIPTION   : handle of call to <BUS>_RequestBusSynchronization          **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : Channel:  Channel for with the Nm messages shall be sent   **
**                                                                            **
** RETURN        : boolean:  RequestBusSynch was called. Repetition counter   **
**                           has to be loaded                                 **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(boolean, VSM_PUBLIC_CODE) HandleNmBusSynchronization
(
   NetworkHandleType Channel
)
{
#if defined ( USE_VSM_WITH_CAN )

  #if ( NUM_CAN_BUSSES_WITH_NM > 0 )

    boolean retVal = FALSE;

    switch ( Vsm_ComMBusTypeOfChannel[(uint8)Channel].bustype )
    {
       case VSM_BUS_CAN:
          /* check if NM is configured to this channel                        */
          if ( ( Vsm_ComMBusTypeOfChannel[Channel].nmtype == VSM_NM_FULL ) ||
               ( Vsm_ComMBusTypeOfChannel[Channel].nmtype == VSM_NM_PASSIVE )
             )
          {
             /* call <BUS>_RequestBusSynchronization( Channel );              */
             if (CanNm_RequestBusSynchronization( Channel ) == NM_E_OK)
             {
                retVal = TRUE;
             }
          }
          break;

       default:
          /* nothing to do                                                    */
          break;
    }

    return retVal;

  #else /* NUM_CAN_BUSSES_WITH_NM > 0                                          */

    /* avoid compiler warning */
    (void) Channel;

    return FALSE;

  #endif /* NUM_CAN_BUSSES_WITH_NM > 0                                         */

#else  /* defined ( USE_VSM_WITH_CAN )                                        */

   /* avoid compiler warning */
   (void) Channel;

   return FALSE;

#endif /* defined ( USE_VSM_WITH_CAN )                                        */
}
#endif /* defined USE_VSM_WITH_CAN || USE_VSM_WITH_FLEXRAY                    */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Fnm_Init                                                   **
**                                                                            **
** DESCRIPTION   : initialised VSM FNM submodule                              **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Fnm_Init(void)
{
   uint8 iLoop;

   /* VSM_FNM003: During initialization, the FNM shall set the bytes in the   */
   /* user data reserved for the function id to 0x00 0x00.                    */
   for (iLoop=0; iLoop < VSM_COMM_NUM_CHANNELS; iLoop++)
   {
      FnmUserData[iLoop].Initcall = FALSE;
      Fnm_NmSetUserData(iLoop, 0);
      ControlReqBusSync[iLoop].reptitions = 0;
   }


   return;
} /* end of Fnm_Init()                                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Fnm_Main                                                   **
**                                                                            **
** DESCRIPTION   : Main function of the FNM. Decrements the shutdown timer    **
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
FUNC(void, VSM_PUBLIC_CODE) Fnm_Main(void)
{
   Std_ReturnType stdResult;
   ComM_UserHandleType comMUser;
   uint8 comMChannel;
   uint16 fctListIndex;
   uint16 lowestFunctionId;
   uint8 comMode;

   /* VSM_FNM029: The FNM shall check in its main function, which ComMUser    */
   /*             keeps a bus awake by calling ComM_GetRequestedComMode for   */
   /*             each configured ComMUser (see VSM_FNM028)                   */
   for (comMChannel=0; comMChannel < VSM_COMM_NUM_CHANNELS; comMChannel++)
   {
      /* VSM_FNM031: The ComMUser with the lowest Function Id that has        */
      /*             requested "FULL_COMMUNICATION" for a channel determines  */
      /*             the NM user data for that channel.                       */
      lowestFunctionId = LOWESTFUNCTIONID_INITAL_VALUE;
      for (fctListIndex = 0; fctListIndex < VSM_NUM_FUNCIDS; fctListIndex++)
      {
         comMUser = FuncIdComMUserMap[fctListIndex].comMUserHandle;

         if ( Vsm_ComMChannelUserMap[comMChannel][comMUser] == TRUE )
         {
            stdResult = ComM_GetRequestedComMode(comMUser, &comMode);
            if (   ( stdResult == E_OK )
                && ( comMode == COMM_FULL_COMMUNICATION ))
            {
               /* find lowest function id                                     */
               if ( FuncIdComMUserMap[fctListIndex].funcId < lowestFunctionId )
               {
                  lowestFunctionId = FuncIdComMUserMap[fctListIndex].funcId;
               }
            }
         }
      }
      /* VSM_FNM034: For channels where currently no FULL_COMMUNICATION mode  */
      /*             is requested the FNM shall Reset the Function Id in NM   */
      /*             user data to 0x0000.                                     */
      if ( lowestFunctionId == LOWESTFUNCTIONID_INITAL_VALUE )
      {
         lowestFunctionId = 0;
      }
      Fnm_NmSetUserData( comMChannel, lowestFunctionId );
   }

   /* VSM_FNM035: FNM shall provide an API Vsm_TriggerCanNmBusSynchronization */
   /*             with one parameter Channel of type NetworkHandleType. On    */
   /*             call of this function the FNM shall call                    */
   /*             <Bus>_RequestBusSynchronization and repeat this call 2      */
   /*             times with an debounce time of 100ms.                       */
   #if defined ( USE_VSM_WITH_CAN )
      for ( comMChannel = 0; comMChannel < VSM_COMM_NUM_CHANNELS; comMChannel++)
      {
         if ( ControlReqBusSync[comMChannel].reptitions != 0 )
         {
            ControlReqBusSync[comMChannel].debouncingtime--;

            /* check if debouncing times expired                              */
            if ( ControlReqBusSync[comMChannel].debouncingtime == 0 )
            {
               /* call to <Bus>_RequestBusSynchronization                     */
               if ( HandleNmBusSynchronization( comMChannel ) == TRUE )
               {
                  /* software timer handling                                  */
                  ControlReqBusSync[(uint8)comMChannel].reptitions--;
                  ControlReqBusSync[(uint8)comMChannel].debouncingtime =
                                         (uint32)(REQBUSSYNCH_DEBOUNCING_TIME /
                                                  VSM_TIMER_CYCLIC_FREQUENCY);
               }
            }
         }
      }
   #endif

   return;
} /* end of Fnm_Main()                                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_TriggerCanNmBusSynchronization                         **
**                                                                            **
** DESCRIPTION   : Triggers the three times call of                           **
**                 <Bus>_RequestBusSynchronization().                         **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : Channel:  Channel for with the Nm messages shall be sent   **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_TriggerCanNmBusSynchronization
                                         (
	                                         NetworkHandleType Channel
                                         )
{
   #if defined ( USE_VSM_WITH_CAN ) || defined ( USE_VSM_WITH_FLEXRAY )
      /* VSM_FNM036: A second call to Vsm_TriggerCanNmBusSynchronization while*/
      /*             repetitions of <Bus>_RequestBusSynchronization of a      */
      /*             previous call are still pending shall be ignored.        */
      if ( ControlReqBusSync[(uint8)Channel].reptitions == 0 )
      {
         /* VSM_FNM035: FNM shall provide an API                              */
         /*             Vsm_TriggerCanNmBusSynchronization with one parameter */
         /*             Channel of type NetworkHandleType. On call of this    */
         /*             function the FNM shall call                           */
         /*             <Bus>_RequestBusSynchronization and repeat this call  */
         /*             2 times with an debounce time of 100ms.               */
         if ( HandleNmBusSynchronization( Channel ) == TRUE )
         {
            ControlReqBusSync[(uint8)Channel].reptitions =
                                                    REQBUSSYNCH_REPETITIONS - 1;

            ControlReqBusSync[(uint8)Channel].debouncingtime =
                                        (uint32)( REQBUSSYNCH_DEBOUNCING_TIME /
                                                  VSM_TIMER_CYCLIC_FREQUENCY );
         }
      }
   #endif  /* defined USE_VSM_WITH_CAN || USE_VSM_WITH_FLEXRAY                */

   return E_OK;
} /* end of Vsm_TriggerCanNmBusSynchronization()                              */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_VERSION_BAC3x                                                   */

/*** End of file **************************************************************/
