/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Wur.c                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : WUR (Wakeup Registration) as part modul of VSM Client         **
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
** miwe         Michael Weger              EB Automotive                      **
** dobr         Dominik Brader             EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.6.1: 12.09.2011, olho: CR71039:    Commented void casts
 * V2.6.0: 12.05.2011, thmi: CR70904:    prevent the concurrent access to shared
 *                                       resources:
 *                                       critical section in Vsm_SetWakeupReason
 *                                       -
 *                                       slimming down calculation of
 *                                       Vsm_WakeupReasonType and
 *                                       Wur_internalWakeupOccurrenceCounter
 * V2.5.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V2.5.0: 20.10.2010, olgo: CR70831:    VSM FCT id parameter is only for
 *                                       ASR 3.0 with FNM
 *         13.10.2010, olgo: CR70555:    Multiple Call to Nvm_WriteBlock()
 *         15.09.2010, olgo: CR70775:    Debouncing of additional NM-messages
 *                                       during active wakeup
 * V2.4.1: 20.09.2010, bemo: BSCVSM-193: Add compiler abstraction for wakeupTypePerUser
 *                                       and lastWakeupType
 * V2.4.0: 30.06.2010, bemo: CR70628:    Signal receive over RTE
 * V2.3.3: 23.06.2010, olgo: BSCVSM-179: Mismatch of internal vs. external
 *                                       linkage with Wur_internalWakeupType
 * V2.3.2: 22.06.2010, olgo: BSCVSM-184: CR70688: VSM/WUR: Repetition of CAN NM
 *                                       messages after active bus wakeup
 * V2.3.2: 16.06.2010, olho: CR70628:    Signal receive over RTE
 * V2.3.1: 27.05.2010, olgo: CR70668:    Vsm Fnm.c doesn't include
 *                                       VSM_ECU_ID_HEADER
 * V2.3.0: 23.04.2010, olgo: CR70613:    VSM uses non AUTOSAR conform datatype
 *                                       from Com module
 *                           BSCVSM-156: BAC3.0 LIN are activated for NM (RT23790)
 * V2.2.1: 23.03.2010, dabu: CR70415:    Module extension to 3.0 - fixed issue in
 *                                       BAC2.1 specific handling
 * V2.2.0: 26.02.2010, mani: CR70415:    Module extension to 3.0
 * V2.1.0: 22.01.2010, mani: CR70484:    avoid cyclic writing of Nv Data
 *                           CR70385:    add description to critical section usage
 * V2.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE switch
 *                           CR70307:    removed SC6 function Vsm_NotifyWakeupEvent
 *                                       removed compiler warnings
 * V1.1.1: 10.08.2009, dobr: BSCVSM-123: replaced 'ON/OFF' with 'STD_ON/STD_OFF'
 * V1.1.0: 08.05.2009, olgo: BSCVSM-113: CR70212: WUR: Use parameter wakeupType
 *                                       in Vsm_CallWakeupEvent()
 * V1.0.2: 12.02.2009, miwe: BSCVSM-106: Implemented review results
 * V1.0.1: 29.10.2008, olgo: BSCVSM-89:  solving CR61413 for BAC Vsm
 * V1.0.0: 09.07.2008, olgo: BSCVSM-41:  Updates of Nvm-Handling
 *         05.06.2008, olgo: BSCVSM-44:  remove old SC6-RTE-functionality
 *                                       from VSM
 *         04.06.2008, olgo: BSCVSM-50:  Syntax erros in Wur.c
 *                           BSCVSM-53:  Order of Com_SendSignal calls in
 *                                       Wur_SendWurMessage_SC7
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39:  Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         29.01.2008, olgo: BSCVSM-24:  Timeouts im STM
 *         28.01.2008, olgo: BSCVSM-21:  dataSendArray must be static
 *         16.01.2008, olgo: BSCVSM-12:  RTE integration
 *                           BSCVSM-25:  Includes und API-Mapping
 *         07.01.2008, olgo: BSCVSM-20:  Mapping of NVM function
 *                                       Nvm_SetBlockProtection
 *         19.12.2007, olgo: BSCVSM-12:  RTE integration
 *         27.11.2007, olgo: taken from SC6 V3.1.0 and ported to SC7
 */


/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 12.10 (required)
  *   The comma operator shall not be used, except in the control expression of
  *   a for loop.
  *
  *   Reason:
  *   This violations are caused of generated code from the RTE
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_C_FILE
   #define VSM_C_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */


/* global switch to enable or disable VSM - WUR (Wakeup Registration)         */
#ifdef VSM_ENABLE_WAKEUP_REGISTRATION        /* switch on WUR                 */

#if ( VSM_TEST_ENABLE == STD_ON )
   #include <Vsm_Test.h>                                   /* Vsm Test Header */
#endif /* ( VSM_TEST_ENABLE == STD_ON )                                       */


/*******************************************************************************
**                      Version checks                                        **
*******************************************************************************/
#if ( ( WUR_MAJOR_VERSION != 4u ) || \
      ( WUR_MINOR_VERSION != 1u ) )
  #error "Wur.c: Wrong version of Wur.h found!!"
#endif

#if ( ( WUR_CFG_MAJOR_VERSION != 4u ) || \
      ( WUR_CFG_MINOR_VERSION != 1u ) )
  #error "Wur.c: Wrong version of Wur_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Configuration checks                                  **
*******************************************************************************/

#if !defined( VSM_ECU_ID )
   #error "Wur.c: VSM_ECU_ID is not defined but required!"
#endif


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* wakeup types                                                               */
#define VSM_WAKEUP_TYPE_INVALID       0xFFu        /* invalide wakeup type    */
#if defined (VSM_VERSION_BAC3x)
   #define VSM_WAKEUP_TYPE_ACTIVE     0x0Au        /* active wakeup type      */
   #define VSM_WAKEUP_TYPE_PASSIVE    0x0Cu        /* passive wakeup type     */
#else
   #define VSM_WAKEUP_TYPE_ACTIVE     COMM_WAKEUP_ACTIVE  /* active wakeup t. */
   #define VSM_WAKEUP_TYPE_PASSIVE    COMM_WAKEUP_PASSIVE /* passive wakeup t.*/
#endif /* VSM_VERSION_BAC3x                                                   */

/* adjust timing                                                              */
#define VSM_TIMEOUT_FIRST_WAKEUP_MESSAGE                                       \
           ( (sint16)( VSM_TMO_WAIT_SEND_WAKEUP_REGISTRATION ) /               \
                     ( VSM_TIMER_CYCLIC_FREQUENCY)                             \
           )

#define VSM_TIMEOUT_CYCLIC_WAKEUP_MESSAGE                                      \
           ( (sint16)( VSM_TMO_CYCLIC_WAKEUP_REG_FREQUENCY )   /               \
                     ( VSM_TIMER_CYCLIC_FREQUENCY          )                   \
           )


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

_STATIC_ FUNC(void, VSM_PRIVATE_CODE)
            Wur_SendWurMessage_SC7( uint8 wakeup_reason );

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/
#define VSM_START_SEC_VAR_16BIT
#include <MemMap.h>

/*
 * Wakeup timer:
 * timer value >   0: timer running
 * timer value ==  0: timer elapsed - do action
 * timer value == -1: timer stopped
 */
_STATIC_ VAR(sint16, VSM_VAR) Wur_wakeupTimer;

#define VSM_STOP_SEC_VAR_16BIT
#include <MemMap.h>

#define VSM_START_SEC_VAR_8BIT
#include <MemMap.h>

/* vsm internal wakeupreason variable */
_STATIC_ VAR(uint8, VSM_VAR) Wur_internalWakeupReason;

/* vsm internal wakeuptype variable */
/* vsm internal wakeup occurrence counter */
#if ( VSM_TEST_ENABLE == STD_ON )
VAR(uint8, VSM_VAR) Wur_internalWakeupType;
VAR(uint8, VSM_VAR) Wur_internalWakeupOccurrenceCounter;
#else
_STATIC_ VAR(uint8, VSM_VAR) Wur_internalWakeupType;
_STATIC_ VAR(uint8, VSM_VAR) Wur_internalWakeupOccurrenceCounter;
#endif /* VSM_TEST_ENABLE == STD_ON                                           */

#define VSM_STOP_SEC_VAR_8BIT
#include <MemMap.h>

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#if ( VSM_TEST_ENABLE == STD_ON )
                                                    /* indicates active bus   */
                                                    /* communication          */
VAR(boolean, VSM_VAR) activeWakeupIndication;
                                                    /* indicates passive bus  */
                                                    /* communication          */
VAR(boolean, VSM_VAR) passivWakeupIndication;
#else
                                                    /* indicates active bus   */
                                                    /* communication          */
_STATIC_ VAR(boolean, VSM_VAR) activeWakeupIndication;
                                                    /* indicates passive bus  */
                                                    /* communication          */
_STATIC_ VAR(boolean, VSM_VAR) passivWakeupIndication;
#endif /* VSM_TEST_ENABLE == STD_ON                                           */

#if defined (VSM_VERSION_BAC3x)
_STATIC_ VAR(Wur_WakeupType, VSM_VAR) wakeupTypePerUser[VSM_NUM_COMMUSERS];
                                           /* store last wakeup type per user */

_STATIC_ VAR(ComM_ModeType, VSM_VAR) lastWakeupType;
                                           /* store last global wakeup type   */
#endif /* VSM_VERSION_BAC3x                                                   */

#if defined (VSM_VERSION_BAC21)
_STATIC_ VAR(ComM_WakeupType, VSM_VAR) wakeupTypeComM;
#endif

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Wur_SendWurMessage_SC7                                     **
**                                                                            **
** DESCRIPTION   : send wakeup reason message to master                       **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : wakeup_reason - wakeup reason of the ecu                   **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, VSM_PRIVATE_CODE)
                                   Wur_SendWurMessage_SC7( uint8 wakeup_reason )
{
   /* data-buffer for sending                                                 */
   uint8 id2data;
   uint8 ecuid;
   uint8 retVal;

   /* VSM_WUR013: set ECU_ID to Byte1                                         */
   ecuid   = ( VSM_ECU_ID );
   /* VSM_WUR013: set ID2 to 0x27                                             */
   id2data = 0x27u;

   /* VSM_WUR012: set of ID2                                                  */
   retVal = Com_SendSignal(COMSIGNAL_REQ_STDCORE_ID2,   &id2data);
   if (retVal == E_OK)
   {
      /* VSM_WUR013: set ecuid to Byte1                                       */
      retVal = Com_SendSignal(COMSIGNAL_REQ_STDCORE_BYTE1, &ecuid);
      if (retVal == E_OK)
      {
         /* VSM_WUR013: set wakeup reason to Byte2. This triggers the         */
         /* transmission of Req_StdCore-Message to vsm master                 */
         /* discard return value -> IPDU group is not stopped on other errors */
         /* a DET is reported by COM                                          */
         (void)Com_SendSignal(COMSIGNAL_REQ_STDCORE_BYTE2, &wakeup_reason);
      }
   }

   return;
} /* end of Wur_SendWurMessage_SC7()                                          */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Wur_Init                                                   **
**                                                                            **
** DESCRIPTION   : initialised VSM wakeup registration                        **
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
FUNC(void, VSM_PUBLIC_CODE) Wur_Init(void)
{
   #if defined ( VSM_VERSION_BAC3x )
      uint8                  comMUserIndex;
   #endif /* VSM_VERSION_BAC3x                                                */

   activeWakeupIndication = FALSE;
   passivWakeupIndication = FALSE;         /* VSM_WUR025                      */

   /* reset wakeup type in init function                                      */
   #if defined ( VSM_VERSION_BAC21 )
      wakeupTypeComM             = COMM_WAKEUP_PASSIVE;
   #endif /* VSM_VERSION_BAC21                                                */

   #if defined ( VSM_VERSION_BAC3x )
      lastWakeupType             = COMM_NO_COMMUNICATION;

      /* reset last wakeup reason of all ComM User that are used by WUR       */
      for ( comMUserIndex = 0;
            comMUserIndex < VSM_NUM_COMMUSERS;
            comMUserIndex++
          )
      {
         wakeupTypePerUser[comMUserIndex].LastWakeup = COMM_NO_COMMUNICATION;
      }
   #endif /* VSM_VERSION_BAC3x                                                */

   /* VSM_WUR001: init vsm internal wakeup occurrence counter with value in   */
   /* EEPROM Vsm_WurNvData will be read after Wakeup                          */
   Wur_internalWakeupOccurrenceCounter = Vsm_WurNvData.Vsm_WurOccCounter;

   /* VSM_WUR001: init wakeup reason with lastly registrated wakeup reson,    */
   /* saved in EEPROM                                                         */
   Wur_internalWakeupReason            = Vsm_WurNvData.Vsm_WurWakeupReason;

   /* VSM_WUR001: init wakeup type                                            */
   Wur_internalWakeupType   = (uint8)VSM_WAKEUP_TYPE_INVALID;

   /* init timer                                                              */
   Wur_wakeupTimer               = -1;

   return;
} /* end of Wur_Init() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Wur_Main                                                   **
**                                                                            **
** DESCRIPTION   : main function of VSM wakeup registration                   **
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
FUNC(void, VSM_PUBLIC_CODE) Wur_Main(void)
{
   uint8 retVal;
   uint8 klemme_15_val;                    /* holds local klemme_15_val       */
#if defined (VSM_VERSION_BAC3x)
   static boolean last_passivWakeupIndication = FALSE;
                                           /* store last passive wakeup       */
                                           /* indication                      */
   ComM_ModeType  currentWakeupType;       /* store current wakeup type       */
   ComM_ModeType  comMMode;                /* store ComM communication mode   */
   uint8          comMUserIndex;
   boolean        tmpwunExceeded;
   boolean        debouncingtime_adjusted[VSM_COMM_NUM_CHANNELS];
   uint8          iLoop;
#endif /* VSM_VERSION_BAC3x                                                   */

#ifdef VSM_ENABLE_RTE
   /* read signal from RTE module                                             */
   /* Deviation MISRA-1 */
   retVal = Rte_Read_Clamp_Port_Clamp(&klemme_15_val);
#else
   retVal = Com_ReceiveSignal( COMSIGNAL_KLEMMEN_ST_KL,
                               #if defined (VSM_VERSION_BAC3x)
                                  ( void*)                     &klemme_15_val
                               #elif defined (VSM_VERSION_BAC21)
                                  ( Com_ApplicationDataRefType)&klemme_15_val
                               #else
                                  #error "Stm.c : Not VSM ASR environment defined"
                               #endif
                             );
#endif

   if(   ( retVal == E_OK )
      && ( klemme_15_val >= VSM_KLEMME_15_ON_MIN_VALUE )
     )
   {
      /* Klemme 15 is on -> init Vsm internal wakeup occurrence counter */
      Wur_internalWakeupOccurrenceCounter = 0;
      /* Do not update Nv block if value has not changed */
      if( Vsm_WurNvData.Vsm_WurOccCounter != Wur_internalWakeupOccurrenceCounter )
      {
         /* store new occurrence counter value permanently */
         /* writing in NvRam will be executed at next MainFunction run */
         SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                                SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
         Vsm_WurNvData.Vsm_WurOccCounter = Wur_internalWakeupOccurrenceCounter;
         SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                               SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
      }
   }

#if defined (VSM_VERSION_BAC3x)

   currentWakeupType = COMM_NO_COMMUNICATION;

   /* VSM_WUR026: VSM shall call in its main function                      */
   /* ComM_GetCurrentComMode for each configured VSM ComMUser to discover  */
   /* the overall bus states                                               */
   for (comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++)
   {
      retVal = ComM_GetCurrentComMode( VsmComMUserArray[comMUserIndex].ComMUser,
                                       &comMMode );
      if ( retVal == E_OK)
      {
         if ( comMMode == COMM_FULL_COMMUNICATION )
         {
            currentWakeupType = COMM_FULL_COMMUNICATION;
            wakeupTypePerUser[comMUserIndex].CurrentWakeup = COMM_FULL_COMMUNICATION;
         }
         else
         {
            wakeupTypePerUser[comMUserIndex].CurrentWakeup = COMM_NO_COMMUNICATION;
         }
      }
   }

   /* VSM_WUR027: ... if at least one of the ComMModes ...                 */
   if ( currentWakeupType != lastWakeupType )
   {
      /* VSM_WUR027: An active wakeup exists, if at least one of the       */
      /* ComMModes switched to COMM_FULL_COMMUNICATION, while in the       */
      /* previous main function cycle all of the ComMModes were            */
      /* COMM_NO_COMMUNICATION and the passive wakeup flag is FALSE        */
      if ( ( lastWakeupType         == COMM_NO_COMMUNICATION   ) &&
           ( currentWakeupType      == COMM_FULL_COMMUNICATION )
         )
      {
         /**** Indication of an active Wakep Event                      ****/
         if ( passivWakeupIndication == FALSE )
         {
            activeWakeupIndication = TRUE;

            /* stop setting of wakeup reasons                              */
            #ifndef VSM_ENABLE_RTE
               /* discard return value -> Vsm_SetWakeupReason returns      */
               /* always 'E_OK'                                            */
               (void)Vsm_SetWakeupReason( VSM_WACA_INVALID, &tmpwunExceeded );
            #else
               Vsm_SetWakeupReason( VSM_WACA_INVALID, &tmpwunExceeded );
            #endif

            #ifndef VSM_SG_GATEWAY        /* a gateway can't transmit      */
                                          /* active wakeup reasons         */
            #ifndef USE_VSM_WITH_FLEXRAY  /* no sending of wakeup message  */
                                          /* with FlexRay                  */
               /* only on active wakeup over AUTOSAR-NM send wakeup        */
               /* message to the master after first communication request  */
               /* start timeout for first wakeup message                   */
               Wur_wakeupTimer = VSM_TIMEOUT_FIRST_WAKEUP_MESSAGE;
            #endif /* USE_VSM_WITH_FLEXRAY                                 */
            #endif /* VSM_SG_GATEWAY                                       */
         }

      }
      else if ( currentWakeupType == COMM_NO_COMMUNICATION )
      {
         /* VSM_WUR028: VSM shall reset the passive wakeup flag to FALSE   */
         /* after the ComMModes of all configured VSM ComMUser have        */
         /* switched to COMM_NO_COMMUNICATION                              */
         passivWakeupIndication = FALSE;
         activeWakeupIndication = FALSE;

         /* VSM_WUR014: If the ComM notifies the VSM that all busses are   */
         /*             in sleep state the reset reason shall be reset to  */
         /*             the initial value VSM_WAKEUP_TYPE_INVALID          */
         Wur_internalWakeupType = (uint8) VSM_WAKEUP_TYPE_INVALID;
      }
      else
      {
         /* satisfy misra */
      }

      lastWakeupType = currentWakeupType;
   }
   else
   {
     if ( ( last_passivWakeupIndication == FALSE ) &&
               ( passivWakeupIndication      == TRUE  )
             )
     {
        /* VSM_WUR006: If the wakeup type is passive, then the wakeup           */
        /*             occurrence counter shall be reset to 0.                  */
        Wur_internalWakeupOccurrenceCounter = 0;
        last_passivWakeupIndication = passivWakeupIndication;
     }
   }

   #if defined ( VSM_ENABLE_FUNC_NM )

   /* initialize debouncingtime_adjusted                                      */
   for (iLoop=0; iLoop < VSM_COMM_NUM_CHANNELS; iLoop++)
   {
      debouncingtime_adjusted[iLoop] = FALSE;
   }
   /* VSM_WUR029: In case the WUR recognized an active wakeup it shall call   */
   /* Vsm_TriggerCanNmBusSynchronization for each ComM channel that has       */
   /* switched to FULL_COMMUNICATION mode and that is of type CAN             */
   for (comMUserIndex = 0; comMUserIndex < VSM_NUM_COMMUSERS; comMUserIndex++)
   {
      Std_ReturnType stdResult;

      if ( ( wakeupTypePerUser[comMUserIndex].CurrentWakeup ==
                                                 COMM_FULL_COMMUNICATION )   &&
           ( wakeupTypePerUser[comMUserIndex].LastWakeup    ==
                                                 COMM_NO_COMMUNICATION )     &&
           ( VsmComMUserArray[comMUserIndex].BusType        == VSM_BUS_CAN ) &&
           ( activeWakeupIndication                         == TRUE )
         )
      {
         stdResult = Vsm_TriggerCanNmBusSynchronization(VsmComMUserArray[comMUserIndex].Channel);

         if ( stdResult == E_OK )
         {
            /* Remark: CR70775: Because Wur_Main is called before Fnm_Main in    */
            /* Vsm_Mainfunction the deboucing timer will be initialized with     */
            /* 1ul. Reason: In the same Vsm_Mainfunction call first the          */
            /* deboucing timer will be initialized via                           */
            /* Wur_Main->Vsm_TriggerCanNmBusSynchronization call and later in    */
            /* Fnm_Main deboucing timer will be decremented. Otherwise the       */
            /* cycle rate for second NM message are only 100ms - VsmCycleTime.   */
            if ( debouncingtime_adjusted[VsmComMUserArray[comMUserIndex].Channel] == FALSE )
            {
               ControlReqBusSync[VsmComMUserArray[comMUserIndex].Channel].debouncingtime++;
               debouncingtime_adjusted[VsmComMUserArray[comMUserIndex].Channel] = TRUE;
            }
         }
      }
      wakeupTypePerUser[comMUserIndex].LastWakeup =
                              wakeupTypePerUser[comMUserIndex].CurrentWakeup;
   }
   #endif /* VSM_ENABLE_FUNC_NM                                               */

#endif /* VSM_VERSION_BAC3x                                                   */

   /* VSM_WUR012: timer integration support                                   */
   if (Wur_wakeupTimer > 0)
   {
      Wur_wakeupTimer--;
   }

   /* wakeup message timeout */
   if (Wur_wakeupTimer == 0)
   {
      Wur_wakeupTimer = -1;                                  /* cancel timer */

      /* inform master about wakeup reason */

      Wur_SendWurMessage_SC7(Wur_internalWakeupReason);
   }

   return;
} /* end of Wur_Main()                                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_SetWakeupReason                                        **
**                                                                            **
** DESCRIPTION   : If the application needs communication the first time      **
**                 the wakeup reason must be registered by calling            **
**                 the function.                                              **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : wakeupReason   : new wakeup reason                         **
**                 maxWunExceeded : TRUE if wakeup occurrence counter has     **
**                                    exceeded, otherwise FALSE               **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : in case of RTE integration provide server port             **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_SetWakeupReason
  (
    Vsm_WakeupReasonType wakeupReason,
    boolean *maxWunExceeded
  )
#else
FUNC(void, RTE_APPL_CODE) Vsm_SetWakeupReason
  (
    Vsm_WakeupReasonType wakeupReason,
    P2VAR(Boolean, AUTOMATIC, RTE_APPL_DATA) maxWunExceeded
  )
#endif
{
  /* VSM_WUR003: check if the wakeup registration is already done      */
  /* a passiv or activ wakeup-type has been saved in internal variable */
  if (Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_INVALID)
  {
    SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
    if (Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_INVALID)
    {
      /* WSM_WUR005: VSM_WAKEUP_TYPE_ACTIVE => the wakeup reason must be      */
      /* transmitted to the wakeup registration master                        */
      /* VSM_WAKEUP_TYPE_PASSIVE => no transmission to the master             */

      if ( wakeupReason == ((uint8)VSM_WACA_INVALID) )
      {
        /* wakeup reason = by notifyWakeupEvent from FNM -> active wakeup if */
        /* at least one application has requested communication              */
        #if defined (VSM_VERSION_BAC21)
        if ( wakeupTypeComM == COMM_WAKEUP_ACTIVE )
        #elif defined (VSM_VERSION_BAC3x)
        if ( activeWakeupIndication == TRUE )
        #endif
        {
          Wur_internalWakeupType = (uint8)VSM_WAKEUP_TYPE_ACTIVE;
        }
        else
        {
          Wur_internalWakeupType = (uint8)VSM_WAKEUP_TYPE_PASSIVE;
        }
      }
      /* get the nm communication status (wakeup type) */
      else if  ( passivWakeupIndication == TRUE )
      {
        /* wakeup reason = bus -> passive wakeup*/
        Wur_internalWakeupType = (uint8)VSM_WAKEUP_TYPE_PASSIVE;
        wakeupReason = VSM_WACA_INVALID;
      }
      else
      {
        /* other wakeup reason */
        if ( wakeupReason > ((uint8)VSM_WACA_INVALID) )
        {
          /* wakeup reason = invalid (higher than 0x3F) -> passive wakeup*/
          Wur_internalWakeupType = (uint8) VSM_WAKEUP_TYPE_PASSIVE;
          wakeupReason = VSM_WACA_INVALID;
        }
        else
        {
          /* wakeup reason = other (valid reason) -> active wakeup */
          Wur_internalWakeupType = (uint8) VSM_WAKEUP_TYPE_ACTIVE;
        }
      }

      if ( Wur_internalWakeupReason != wakeupReason )
      {
        /* VSM_WUR004: application set new wakeup reason ->                   */
        /* copy into internal variable                                        */
        Wur_internalWakeupReason = wakeupReason;

        /* VSM_WUR007: wakeupReason differs from the previous wakeupReason    */
        /* -> reset it here, following incrementing set it to 1               */
        Wur_internalWakeupOccurrenceCounter = 0;
      }

      if ( Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_PASSIVE )
      {
        /* VSM_WUR006: passive wakeup -> init vsm internal wakeup occurrence */
        /* counter                                                           */
        Wur_internalWakeupOccurrenceCounter = 0;
      }
      else /* ( Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_ACTIVE ) */
      {
        /* VSM_WUR007: increment vsm internal wakeup occurrence counter       */
        /* for the first or the repeated occurrence of this wakeup reason     */
        /* but prevent overflow ( not higher than maximum plus 1 )            */
        if ( Wur_internalWakeupOccurrenceCounter <= VSM_MAX_NUM_WAKEUPS )
        {
          Wur_internalWakeupOccurrenceCounter++;
        }

        /* VSM_WUR004: store new lastly registrated wakeup reason in NVRam    */
        /* if the wakeup type is active                                       */
        /* ( permanently writing in nvram will be executed at shutdown )      */
        Vsm_WurNvData.Vsm_WurWakeupReason = wakeupReason;
      }

      /* VSM_WUR006: store new occurrence counter value                       */
      /* ( permanently writing in nvram will be executed at shutdown )        */
      Vsm_WurNvData.Vsm_WurOccCounter = Wur_internalWakeupOccurrenceCounter;

    } /* if(Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_INVALID) */

    SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

  } /* if(Wur_internalWakeupType == (uint8) VSM_WAKEUP_TYPE_INVALID) */

  /* VSM_WUR002: wakeup occurrence counter has exceeded the max value ->      */
  /* return TRUE                                                              */
  if ( Wur_internalWakeupOccurrenceCounter >= VSM_MAX_NUM_WAKEUPS )
  {
    *maxWunExceeded = TRUE;
  }
  else
  {
    *maxWunExceeded = FALSE;
  }

#ifndef VSM_ENABLE_RTE
  return E_OK;
#else
  return;
#endif
} /* end of Vsm_SetWakeupReason() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetWakeupReason                                        **
**                                                                            **
** DESCRIPTION   : Function to get the registered wakeup reason.              **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : wakeupReason : wakeup reason of ECU                        **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
       Vsm_GetWakeupReason( Vsm_WakeupReasonType *wakeupReason )
#else
FUNC(void, RTE_APPL_CODE)
       Vsm_GetWakeupReason( P2VAR( Vsm_WakeupReasonType,
                                   AUTOMATIC,
                                   RTE_APPL_DATA) wakeupReason
                          )
#endif
{
   /* return the internal saved wakeup registration of ECU */
   *wakeupReason = (Vsm_WakeupReasonType)Wur_internalWakeupReason;

#ifndef VSM_ENABLE_RTE
   return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetWakeupReason() */


#if defined (VSM_VERSION_BAC21)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_CallWakeupEvent                                        **
**                                                                            **
** DESCRIPTION   : Interface for notification from ComM that at least one bus **
**                 is awake now and determine the wakeup reason               **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : wakeupType: wakeup type                                    **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
   Vsm_CallWakeupEvent(ComM_WakeupType wakeupType )
{
   boolean wunExceeded;

   activeWakeupIndication = TRUE;
   wakeupTypeComM         = wakeupType;

   /* stop setting of wakeup reasons                                          */
#ifndef VSM_ENABLE_RTE
   /* discard return value -> Vsm_SetWakeupReason returns always 'E_OK'       */
   (void)Vsm_SetWakeupReason( VSM_WACA_INVALID, &wunExceeded );
#else
   Vsm_SetWakeupReason( VSM_WACA_INVALID, &wunExceeded );
#endif

#ifndef VSM_SG_GATEWAY     /* a gateway can't transmit active wakeup reasons  */
#ifndef USE_VSM_WITH_FLEXRAY /* no sending of wakeup message with FlexRay     */
   /* only on active wakeup over AUTOSAR-NM send wakeup message to the master
      after first communication request */
   if( wakeupTypeComM == (uint8) VSM_WAKEUP_TYPE_ACTIVE )
   {
      /* start timeout for first wakeup message */
      Wur_wakeupTimer = VSM_TIMEOUT_FIRST_WAKEUP_MESSAGE;
   }
#endif /* USE_VSM_WITH_FLEXRAY */
#endif /* VSM_SG_GATEWAY */

   return E_OK;
} /* Vsm_CallWakeupEvent                                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_CallGlobalSleepEvent                                   **
**                                                                            **
** DESCRIPTION   : Interface for notification from ComM that all busses have  **
**                 entered the sleep state                                    **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_CallGlobalSleepEvent(void)
{
   activeWakeupIndication = FALSE;

   /* VSM_WUR014: If the ComM notifies the VSM that all busses are in sleep   */
   /*             state the reset reason shall be reset to the initial value  */
   /*             VSM_WAKEUP_TYPE_INVALID                                     */
   Wur_internalWakeupType = (uint8) VSM_WAKEUP_TYPE_INVALID;

   return E_OK;
} /* Vsm_CallGlobalSleepEvent                                                 */
#endif /* defined (VSM_VERSION_BAC21)                                         */

#if defined (VSM_VERSION_BAC3x)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_PassiveWakeupIndication                                **
**                                                                            **
** DESCRIPTION   : Notification for WUR that a passive Wakeup (either by      **
**                 Wakeupline or by bus) has happened.                        **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_PassiveWakeupIndication(void)
{
   /* VSM_WUR024 */
   passivWakeupIndication = TRUE;

   return E_OK;
} /* Vsm_PassiveWakeupIndication                                              */

#endif /* defined (VSM_VERSION_BAC3x)                                         */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_ENABLE_WAKEUP_REGISTRATION */

/*** End of file **************************************************************/
