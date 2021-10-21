/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Stm.c                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : STM (State Monitor) as part modul of VSM Client               **
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
** dabu         Daniel Buder               EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.5.1: 12.09.2011, olho: CR71039:    Commented void casts
 * V2.5.0: 19.05.2011, thmi: CR70904:    prevent the concurrent access
 *                                       to shared resources:
 *                                       Guard whole timeout handling
 *                                       in StmFse_Main by critical section(s)
 *                     thmi: CR70970:    Fix inccorect handling of error locking
 *                                       while receiving VSM_STM_CEL_UNLOCKED
 * V2.4.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V2.4.0: 10.02.2011, olgo: CR70908:    prevent Misra warnings
 * V2.3.0: 16.09.2010, olgo: CR70830:    Remove unused parameter in function
 *                                       vsm_cbk
 *                     olgo: CR70801:    Initial error blocking not released
 * V2.2.2: 16.09.2010, olgo: CR70813:    VSM_EVENT_VEHICLESTATE not entered
 *                                       correctly
 * V2.2.1: 29.06.2010, bemo: CR70628:    Signal receive over RTE
 * V2.2.0: 23.04.2010, olgo: CR70613:    VSM uses non AUTOSAR conform datatype
 *                                       of Com module
 *                     olgo: BSCVSM-163: Wrong handling of signal timeout
 *                                       supervision in Stm.c
 * V2.1.0: 22.01.2010, mani: CR70385:    add description to critical section
 *                                       usage
 * V2.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE
 *                                       switch
 *                                       removed compiler warnings
 * V1.1.1: 12.02.2009, miwe  BSCVSM-106: Implemented review results
 * V1.1.0: 04.02.2008, olgo: BSCVSM-103: CR70089: illegal error memory lock
 * V1.0.1: 29.10.2008, olgo: BSCVSM-91 : Porting SC6 CR's to BAC2.1:
 *                                       CR61393, CR61409, CR61472 (dabu)
 *                     dabu: BSCVSM-75 : error entry only after FZZSTD timeout
 * V1.0.0: 21.07.2008, olgo: BSCVSM-75 : Timeout handling by COM module
 *         09.07.2008, olgo: BSCVSM-73 : Change Timerhandling
 *         05.06.2008, olgo: BSCVSM-44 : remove old SC6-RTE-functionality
 *                                       from VSM
 *         10.04.2008, olgo: BSCVSM-46 : warning in Stm.c
 *         03.04.2008, olgo: BSCVSM-42 : Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39 : Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         08.02.2008, olgo: BSCVSM-38 : Fix Com signal usage in STM
 *         31.01.2008, olgo: BSCVSM-35 : VSM with activated RTE collides with
 *                                       other Modul es with activated RTE
 *                           BSCVSM-27 : Interrupt blocking must be done using
 *                                       the schedule manager
 *         29.01.2008, olgo: BSCVSM-24 : Timeouts im STM
 *         16.01.2008, olgo: BSCVSM-12 : RTE integration
 *                           BSCVSM-25 : Includes und API-Mapping
 *         07.01.2008, olgo: BSCVSM-19 : Mapping of OS functions
 *         19.12.2007, olgo: BSCVSM-12 : RTE integration
 *         27.11.2007, olgo: taken from SC6 V3.1.1 and ported to SC7
 */


/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   As the function is called very often and consists only of a one line
  *   the macro based implmentation is more run time efficient.
  *
  */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_C_FILE
   #define VSM_C_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */

#ifdef VSM_VERSION_BAC21 /* BAC 2.1 uses BMW specifiv ComM API to detect bus state */
#if (COMM_RTE_ENABLE == STD_ON)
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetOverallBusSleepState
(
   P2VAR(ComM_BusStateType, AUTOMATIC, COMM_APPL_DATA) BusState
);
#endif /*(COMM_RTE_ENABLE == STD_ON)*/
#endif /*VSM_VERSION_BAC21*/

/* global switch to enable or disable VSM - STM (State Monitor)               */
#ifdef VSM_ENABLE_STATE_MONITOR            /* switch on STM                   */

/* ---- Perform version checking ------------ */
#if ( ( STM_MAJOR_VERSION != 4u) || \
      ( STM_MINOR_VERSION != 1u) )
  #error "Stm.c: Wrong version of Stm.h found!!"
#endif

#if ( ( STM_CFG_MAJOR_VERSION != 4u ) || \
      ( STM_CFG_MINOR_VERSION != 1u ) )
  #error "Stm.c: Wrong version of Stm_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Global Checks                                         **
*******************************************************************************/
/* NXTR PATCH: 8/21/12   BDO   anomaly 3470    CR6055
 * The DTC 0x4822A5 - VSM_EVENT_VEHICLESTATE was removed from software
 * as this event is no longer referenced in the SER or BMW's ZEDIS. However, this BSW
 * triggers a compile time error if the event is not defined or defined as zero.
 * This file has modified to remove this error and any reference to the event ID.

#if !defined ( VSM_EVENTID_VEHICLESTATE      ) || \
             ( VSM_EVENTID_VEHICLESTATE <= 0 )
#error "Stm.c: The DEM event VSM_EVENT_VEHICLESTATE is not configured in TRESOS"
#endif
*/

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* used for calculation of timeout values                                     */

#define VSM_TIMEOUT_INITIAL_ERROR_BLOCKING                                     \
          ( (sint16)( VSM_TMO_CEL_TIME_STARTUP ) /                             \
                    ( VSM_TIMER_CYCLIC_FREQUENCY )                             \
          )

#define VSM_TIMEOUT_VEHICLE_STATE_REFRESH                                      \
          ( (sint16)( VSM_TMO_VEHICLE_STATE_REFRESH ) /                        \
                    ( VSM_TIMER_CYCLIC_FREQUENCY )                             \
          )

#define VSM_TIMEOUT_OPERATION_STATE_REFRESH                                    \
          ( (sint16)( VSM_TMO_OPERATION_STATE_REFRESH ) /                      \
                    ( VSM_TIMER_CYCLIC_FREQUENCY )                             \
          )

/* Macros used for timer handline                                             */
#define VSM_DECREMENTTIMER( counter )    do { if ( (counter) > 0 ) { (counter)--; } } while (0)
#define VSM_SETTIMER( counter, value )   do{(counter) = (value);}while(0)
/* Deviation MISRA-1 */
#define VSM_CHECKTIMER( counter )        (( (counter) == 0 ) ? (TRUE) : (FALSE))
#define VSM_STOPTIMER( counter )         do{(counter) = -1;}while(0)

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/* struct of car status information */
typedef struct
{
  uint8 state;
  uint8 energyState;
  uint8 communicationErrorState;
} Stm_CarStateDataType;


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

_STATIC_ FUNC( void, VSM_PRIVATE_CODE )
               Stm_HandleOperationStateChange( void );

_STATIC_ FUNC( void, VSM_PRIVATE_CODE )
              Stm_HandleVehicleStatusChange( void );

_STATIC_ FUNC( void, VSM_PRIVATE_CODE )
              Stm_HandleComErrorState( uint8 newComErrState );

#ifdef VSM_ENABLE_RTE
_STATIC_ FUNC(void, VSM_PRIVATE_CODE)
              Vsm_LookForNewComSignal(
                                       void* Vsm_RxData,
                                       Vsm_ReturnRequestedType retReq
                                     );
#endif
#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define VSM_START_SEC_VAR_16BIT
#include <MemMap.h>
   /* timer for startup and veh. state refresh                                */
   _STATIC_ VAR(sint16, VSM_VAR) Stm_VehStateRefrTimer;
   /* timer for operation state refresh                                       */
   _STATIC_ VAR(sint16, VSM_VAR) Stm_OpStateRefrTimer;
#define VSM_STOP_SEC_VAR_16BIT
#include <MemMap.h>

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>
   /* internal state variable to check if in initial error memory blocking    */
   _STATIC_ VAR(boolean, VSM_VAR) Stm_initialErrorBlocking;
   /* store car status info                                                   */
   _STATIC_ VAR(Stm_CarStateDataType, VSM_VAR) Stm_carStateInfo;
#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Stm_HandleOperationStateChange                             **
**                                                                            **
** DESCRIPTION   : handle change of operation status message                  **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, VSM_PRIVATE_CODE) Stm_HandleOperationStateChange(void)
{
   uint8 retVal = E_OK;
#ifdef VSM_ENABLE_RTE
   Vsm_OperatingStateType master_status_val;
#else
   uint8 master_status_val;                            /* holds local OpState */
#endif

   VSM_STOPTIMER( Stm_OpStateRefrTimer );

#ifdef VSM_ENABLE_RTE
   /* read signal from RTE module                                             */
   Vsm_LookForNewComSignal((void*)&master_status_val, VSM_RET_OPSTATE);
#else
   /* receive signal from COM module                                          */
   /* Nxtr patch START */
   /* Added: 02/09/2015 */
   /* Purpose: For F40_UKL_MCV, since the Klemmen signal no longer exists, the below code is a workaround until the module is updated */
  /* retVal = Com_ReceiveSignal( VSM_SG_KLEMMEN_ST_VEH_CON,
                               #if defined (VSM_VERSION_BAC3x)
                               ( void*)                     &master_status_val
                               #elif defined (VSM_VERSION_BAC21)
                               ( Com_ApplicationDataRefType)&master_status_val
                               #else
                                  #error "Stm.c : Not VSM ASR environment defined"
                               #endif
                             ); */

   retVal = E_OK;
   master_status_val = VSM_STM_STATE_DRIVE;
   /* Nxtr Patch END */
#endif

   if(   ( retVal == E_OK )
      && ( master_status_val != Stm_carStateInfo.state)
     )
   {
      /* switch to new state                                                  */
      Stm_carStateInfo.state = master_status_val;
      /* validity check                                                       */
      if ( Stm_carStateInfo.state > VSM_STM_STATE_INVALID )
      {
        Stm_carStateInfo.state = VSM_STM_STATE_INVALID;
      }

      /* notify application                                                   */
      Vsm_Cbk(Vsm_NotifyStateChange, Stm_carStateInfo.state);
      STM_VSM_NOTIFYSTATECHANGEEVENT(Stm_carStateInfo.state);   /* notify FIM */
   } /* OpState is up-to-date                                                 */

   /* start new supervision of operation state message                        */
   VSM_SETTIMER ( Stm_OpStateRefrTimer, VSM_TIMEOUT_OPERATION_STATE_REFRESH);

   return;
} /* end of Stm_HandleOperationStateChange()                                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Stm_HandleVehicleStatusChange                              **
**                                                                            **
** DESCRIPTION   : handle change of vehicle status message                    **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, VSM_PRIVATE_CODE) Stm_HandleVehicleStatusChange(void)
{
  uint8 retVal = E_OK;
#ifdef VSM_ENABLE_RTE
  Vsm_EnergyStateType master_engstate_val;
  Vsm_CommunicationErrorLockType master_comerrstate_val;
#else
  uint8 master_engstate_val;
  uint8 master_comerrstate_val;
#endif
  Vsm_OperatingModeType opmodetype;

  /* behavior after initial error memory blocking time */
  if( Stm_initialErrorBlocking == FALSE )
  {
     VSM_STOPTIMER( Stm_VehStateRefrTimer );
  }

#ifdef VSM_ENABLE_RTE
  /* read signal from RTE module                                              */
  Vsm_LookForNewComSignal((void*)&master_engstate_val, VSM_RET_ENERGYSTATE);
#else
  retVal = Com_ReceiveSignal( VSM_SG_FZZSTD_ST_ENERG_FZM,
                              #if defined (VSM_VERSION_BAC3x)
                              ( void*)                     &master_engstate_val
                              #elif defined (VSM_VERSION_BAC21)
                              ( Com_ApplicationDataRefType)&master_engstate_val
                              #else
                                 #error "Stm.c : Not VSM ASR environment defined"
                              #endif
                            );
#endif

  if(   ( retVal == E_OK )
     && ( Stm_carStateInfo.energyState != master_engstate_val )
    )
  {
     /* set to new value */
     Stm_carStateInfo.energyState = master_engstate_val;
     /* validity check */
     switch(master_engstate_val)
     {
       case VSM_STM_EN_GOOD:
       case VSM_STM_EN_OK:
       case VSM_STM_EN_SHORTAGE:
       case VSM_STM_EN_SEVERE_SHORTAGE:
       case VSM_STM_EN_INVALID:
         break;
       default:
         Stm_carStateInfo.energyState = VSM_STM_EN_INVALID;
         break;
     }

     /* application callback */
     Vsm_Cbk( Vsm_NotifyEnergyStateChange, Stm_carStateInfo.energyState );
     /* FIM callback */
     STM_VSM_NOTIFYENERGYSTATECHANGEEVENT(Stm_carStateInfo.energyState);
  }

  /**** error lock handling ****/

  /* only in op-mode NORMAL unblock error memory                              */
  STM_VSM_GETMODE( &opmodetype );
  if ( opmodetype == (uint8)VSM_MM_MODE_NORMAL )
  {
     /* check if communication error state signal has changed                 */

#ifdef VSM_ENABLE_RTE
     /* read signal from RTE module                                             */
     Vsm_LookForNewComSignal( (void*)&master_comerrstate_val, VSM_RET_CEL );
#else
     retVal = Com_ReceiveSignal( VSM_SG_FZZSTD_ST_ILK_ERRM_FZM,
                                 #if defined (VSM_VERSION_BAC3x)
                                    ( void*)            &master_comerrstate_val
                                 #elif defined (VSM_VERSION_BAC21)
                                    ( Com_ApplicationDataRefType)
                                                        &master_comerrstate_val
                                 #else
                                 #error "Stm.c : Not VSM ASR environment defined"
                                 #endif
                               );
#endif
     if (retVal == E_OK)
     {
        Stm_HandleComErrorState(master_comerrstate_val);
     }
  }

  /* behavior after initial error memory blocking time                        */
  if( Stm_initialErrorBlocking == FALSE )
  {
     /* start new supervision of vehicle state message                         */
     VSM_SETTIMER ( Stm_VehStateRefrTimer, VSM_TIMEOUT_VEHICLE_STATE_REFRESH );
  }
/* NXTR PATCH: 8/21/12   BDO   anomaly 3470    CR6055
* The DTC 0x4822A5 - VSM_EVENT_VEHICLESTATE was removed from software
* as this event is no longer referenced in the SER or BMW's ZEDIS. However, this BSW
* triggers a compile time error if the event is not defined or defined as zero.
* This file has modified to remove this error and any reference to the event ID.
*/
  /* clear an error entry - set a passed status */
//  VSM_CLEAR_DEM_EVENT(VSM_EVENTID_VEHICLESTATE);

  return;
} /* end of Stm_HandleVehicleStatusChange()                                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Stm_HandleComErrorState                                    **
**                                                                            **
** DESCRIPTION   : handle error memory signal                                 **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : signal value                                               **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC( void, VSM_PRIVATE_CODE )
               Stm_HandleComErrorState( uint8 newComErrState )
{
  /* check if communication error state signal has changed                   */
  if( Stm_carStateInfo.communicationErrorState != newComErrState)
  {
    /* validity check                                                       */
    switch( newComErrState )
    {
       case VSM_STM_CEL_UNLOCKED:
       case VSM_STM_CEL_LOCKED:
          break;
       default:
          /* VSM_STM012: set to invalid value type                          */
         newComErrState = VSM_STM_CEL_INVALID;
          break;
    }

    /* VSM_STM021: change error memory blocking                             */
    if( newComErrState == (uint8)VSM_STM_CEL_UNLOCKED )
    {
       /* unblock global error memory, if it was blocked before             */
       Vsm_UnBlockDem( VSM_STM_DEM_HANDLING );
    }
    else if( newComErrState == (uint8)VSM_STM_CEL_LOCKED )
    {
       /* block global error memory, because it was unblocked before        */
       Vsm_BlockDem( VSM_STM_DEM_HANDLING );
    }
    else
    {
      if( ( newComErrState == (uint8)VSM_STM_CEL_INVALID) &&
           ( Stm_carStateInfo.communicationErrorState == (uint8)VSM_STM_CEL_LOCKED )
        )
      {
        /* only behavior after initial error memory blocking time             */
        if( Stm_initialErrorBlocking == FALSE )
        {
          /* unblock global error memory, if it was blocked before           */
          Vsm_UnBlockDem( VSM_STM_DEM_HANDLING );
        }
      }
    }

    /* set to new value */
    Stm_carStateInfo.communicationErrorState = newComErrState;

    /* application callback                                                 */
    Vsm_Cbk( Vsm_NotifyCommunicationErrorLockChange,
             Stm_carStateInfo.communicationErrorState
           );
  }

  /* VSM_STM023 : cancel startup blocking timeout if a valid CEL status      */
  /* has received and the operating mode is equal to VSM_MM_MODE_NORMAL.     */
  if ( ( Stm_initialErrorBlocking == TRUE ) &&
      ( Stm_carStateInfo.communicationErrorState != (uint8) VSM_STM_CEL_INVALID )
    )
  {
    /* stop initial error blocking time                                     */
    Stm_initialErrorBlocking = FALSE;
  }

  return;
} /* end of Stm_HandleComErrorState                                           */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : StmFse_Init                                                **
**                                                                            **
** DESCRIPTION   : initialised VSM state monitor                              **
**                                                                            **
** PRECONDITIONS : DEM is initialised                                         **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) StmFse_Init(void)
{
   /* set internal state variables to initial value - error memory blocking   */
   Stm_initialErrorBlocking = TRUE;

   /* copy values of message to default values                                */
   Stm_carStateInfo.state                   = VSM_STM_STATE_INIT;
   Stm_carStateInfo.energyState             = VSM_STM_EN_INVALID;
   Stm_carStateInfo.communicationErrorState = VSM_STM_CEL_LOCKED;

   /* start new supervision of operation state message                        */
   VSM_SETTIMER ( Stm_OpStateRefrTimer, VSM_TIMEOUT_OPERATION_STATE_REFRESH );

   /* block error memory during startup                                       */
   Vsm_BlockDem( VSM_STM_DEM_HANDLING );

   /* start initial error blocking timeout                                    */
   VSM_SETTIMER ( Stm_VehStateRefrTimer, VSM_TIMEOUT_INITIAL_ERROR_BLOCKING );

   return;
} /* end of StmFse_Init()                                                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : StmFse_Main                                                **
**                                                                            **
** DESCRIPTION   : main function of VSM state monitor                         **
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
FUNC(void, VSM_PUBLIC_CODE) StmFse_Main(void)
{
   uint8 comMUsers;
   uint8 comMode;
   boolean busactivity = FALSE;

   /* check for bus activ mode - only in this case  decrement timer           */
   /* for supervision                                                         */
#ifdef VSM_VERSION_BAC21 /* BAC 2.1 uses BMW specifiv ComM API to detect bus state */
   ComM_BusStateType busState = COMM_BUS_SLEEP;
   ComM_GetOverallBusSleepState(&busState);
   if ( busState != COMM_BUS_SLEEP )
   {
      busactivity = TRUE;
   }
#else /* in BAC 3.x we use standard AUTOSAR ComM, so we have to iterate over Vsm specific ComMUsers */
   for (comMUsers = 0; comMUsers < VSM_COMM_NUM_USERS; comMUsers++)
   {
      Std_ReturnType stdResult;

      stdResult = ComM_GetCurrentComMode(comMUsers, &comMode);

      if (   (stdResult == E_OK)
          && (( comMode == COMM_FULL_COMMUNICATION ) ||
              ( comMode == COMM_SILENT_COMMUNICATION ))
         )
      {
         busactivity = TRUE;
      }
   }
#endif /* VSM_VERSION_BAC21 */

#ifdef VSM_ENABLE_RTE
   /* poll rte, if new signals are available                                  */
   Vsm_LookForNewComSignal(NULL_PTR, VSM_RET_NOTHING_POLL);
#endif

   if ( busactivity == TRUE )
   {
      /* decrement timer for operation state refr. supervision                */
      VSM_DECREMENTTIMER( Stm_OpStateRefrTimer );
      /* decrement timer for startup & veh. state refr. supervision           */
      VSM_DECREMENTTIMER( Stm_VehStateRefrTimer );

   }
   else
   {
      if( Stm_initialErrorBlocking == TRUE )
      {
         /* decrement timer for startup timeout within startup timeout        */
         VSM_DECREMENTTIMER( Stm_VehStateRefrTimer );
      }
      else
      {
         /** bus is inactive after startup timeout-->stop/reset supervision  **/
         /* start new supervision of operation state message if bus is active */
         VSM_SETTIMER( Stm_OpStateRefrTimer,
                         VSM_TIMEOUT_OPERATION_STATE_REFRESH );

         /* start new supervision of vehicle state message if bus is active   */
         VSM_SETTIMER( Stm_VehStateRefrTimer,
                         VSM_TIMEOUT_VEHICLE_STATE_REFRESH );
      }
   }

   /* ####################   timeout handling   ############################# */

   /* timeout after startup which operation state is set to invalid if no     */
   /* cyclic message to refresh the operation state is received               */
  if ( VSM_CHECKTIMER( Stm_OpStateRefrTimer ) == TRUE )
  {
    /* Process timeout whithin a critical section,                            */
    /* to prevent a timer refresh takes place while a timeout tretment        */
    SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   /* Aditional check whithin critical section necessary */
   if ( VSM_CHECKTIMER( Stm_OpStateRefrTimer ) == TRUE )
   {
      VSM_STOPTIMER( Stm_OpStateRefrTimer );

      /* no valid signal from master                                          */
      Stm_carStateInfo.state = (uint8) VSM_STM_STATE_INVALID;

      /* notify application                                                   */
      Vsm_Cbk(Vsm_NotifyStateChange, Stm_carStateInfo.state);

      /* notify FIM                                                           */
      STM_VSM_NOTIFYSTATECHANGEEVENT(Stm_carStateInfo.state);
   }
    SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
  }

   /* startup error memory blocking and supervision of refresh timeout of     */
   /* cyclic vehicle state message                                            */
  if ( VSM_CHECKTIMER( Stm_VehStateRefrTimer ) == TRUE )
  {
    /* Process timeout whithin a critical section,                            */
    /* to prevent a timer refresh takes place while a timeout tretment        */
    SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   /* Aditional check whithin critical section necessary */
   if ( VSM_CHECKTIMER( Stm_VehStateRefrTimer ) == TRUE )
   {
      VSM_STOPTIMER( Stm_VehStateRefrTimer );

      /* STM021: The error memory shall also be unlocked if the error lock    */
      /* state changes to VSM_STM_CEL_INVALID and the startup error lock      */
      /* timeout has elapsed or has been stopped.                             */
      /* no valid signal from master at expiration of timeout                 */
      /* at startup or supervision -> unblock error memory after startup      */
      /* (communicationErrorState is VSM_STM_CEL_LOCKED at startup) or        */
      /* if the error memory was locked before supervision timeout expiration */
      if ( ( Stm_carStateInfo.communicationErrorState ==
                                    (uint8)VSM_STM_CEL_INVALID ) ||
           ( Stm_carStateInfo.communicationErrorState ==
                                    (uint8)VSM_STM_CEL_LOCKED  )
         )
      {
         Vsm_UnBlockDem( VSM_STM_DEM_HANDLING );
      }

      if ( Stm_initialErrorBlocking == TRUE )
      {
         /** timeout of initial error blocking time                          **/

         /* stop initial error blocking time                                  */
         Stm_initialErrorBlocking = FALSE;

         /* VSM_STM022: When the current operating mode is normal and the     */
         /* startup error lock timeout counter reaches StmCelTmStartup, the   */
         /* VSM client shall enable the error memory by calling               */
         /* Dem_EnableEventStatusUpdate and shall set the communication error */
         /* lock to VSM_STM_CEL_INVALID.                                      */
         Vsm_UnBlockDem( VSM_STM_DEM_HANDLING );
         Stm_carStateInfo.communicationErrorState = (uint8)VSM_STM_CEL_INVALID;


         /* start supervision of vehicle state message for the rest of the    */
         /* refresh timeout time                                              */
         VSM_SETTIMER( Stm_VehStateRefrTimer,
                         VSM_TIMEOUT_VEHICLE_STATE_REFRESH -
                         VSM_TIMEOUT_INITIAL_ERROR_BLOCKING
                       );
      }
      else
      {
         /** behavior after initial error memory blocking time               **/
         /* no valid signal from master                                       */
         Stm_carStateInfo.energyState = (uint8) VSM_STM_EN_INVALID;
         /* application callback                                              */
         Vsm_Cbk( Vsm_NotifyEnergyStateChange, Stm_carStateInfo.energyState );
         /* FIM callback                                                      */
         STM_VSM_NOTIFYENERGYSTATECHANGEEVENT(Stm_carStateInfo.energyState);
 /* NXTR PATCH: 8/21/12   BDO   anomaly 3470    CR6055
 * The DTC 0x4822A5 - VSM_EVENT_VEHICLESTATE was removed from software
 * as this event is no longer referenced in the SER or BMW's ZEDIS. However, this BSW
 * triggers a compile time error if the event is not defined or defined as zero.
 * This file has modified to remove this error and any reference to the event ID.
 */
         /* VSM_STM022: trigger an error entry with failed status             */
         //VSM_SET_DEM_EVENT( VSM_EVENTID_VEHICLESTATE );
      }

      /* set error memory invalid state in internal variable                  */
      Stm_carStateInfo.communicationErrorState = (uint8) VSM_STM_CEL_INVALID;
      /* application callback                                                 */
      Vsm_Cbk( Vsm_NotifyCommunicationErrorLockChange,
               Stm_carStateInfo.communicationErrorState
             );
   }
    SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
  }
   return;
} /* end of StmFse_Main()                                                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_LookForNewComSignal                                    **
**                                                                            **
** DESCRIPTION   : Search for new signals from RTE. Call notifications of     **
**                 signals, which have to be updated.                         **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : Vsm_RxData: Data pointer for requested signal              **
**               : retReq    : Control variable                               **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
#ifdef VSM_ENABLE_RTE
_STATIC_ FUNC(void, VSM_PRIVATE_CODE) Vsm_LookForNewComSignal
(
   void* Vsm_RxData,
   Vsm_ReturnRequestedType retReq
)
{
   Std_ReturnType Rte_Status;
   _STATIC_ Vsm_OperatingStateType bufferedOpState = VSM_STM_STATE_INVALID;
   _STATIC_ Vsm_EnergyStateType bufferedEnergyState = VSM_STM_EN_INVALID;
   _STATIC_ Vsm_CommunicationErrorLockType bufferedCel = VSM_STM_CEL_INVALID;

   /* check if signal or polling is requested                                 */
   switch(retReq)
   {
      case VSM_RET_OPSTATE:
         *((Vsm_OperatingStateType*)Vsm_RxData) = bufferedOpState;
         break;
      case VSM_RET_ENERGYSTATE:
         *((Vsm_EnergyStateType*)Vsm_RxData) = bufferedEnergyState;
         break;
      case VSM_RET_CEL:
         *((Vsm_CommunicationErrorLockType*)Vsm_RxData) = bufferedCel;
         break;
      default:
         /* VSM_RET_NOTHING_POLL                                              */

         /* Each signal has to be polled one time first. If Rte_Status is
          * RTE_E_NO_DATA, then there is no new element in the queue and we can
          * step to the next signal. Otherwise the while-statement will be read
          * each element from the queue until he's empty. Furthermore call the
          * rx notification of the respective signal.
          */

         Rte_Status = Rte_Receive_OpState_Port_OpState(&bufferedOpState);

         while(
               (Rte_Status == RTE_E_OK) ||
               ((Rte_Status & RTE_E_LOST_DATA) == RTE_E_LOST_DATA)
              )
         {
            Rte_Status = Rte_Receive_OpState_Port_OpState(&bufferedOpState);

            if ( Rte_Status != RTE_E_OK )
            {
               Vsm_OpStateRxNotification();
            }
         }

         Rte_Status = Rte_Receive_EnergyState_Port_EnergyState(&bufferedEnergyState);

         while(
               (Rte_Status == RTE_E_OK) ||
               ((Rte_Status & RTE_E_LOST_DATA) == RTE_E_LOST_DATA)
              )
         {
            Rte_Status = Rte_Receive_EnergyState_Port_EnergyState(&bufferedEnergyState);

            if ( Rte_Status != RTE_E_OK )
            {
               Vsm_EnergyStateRxNotification();
            }
         }

         Rte_Status = Rte_Receive_Cel_Port_Cel(&bufferedCel);

         while(
               (Rte_Status == RTE_E_OK) ||
               ((Rte_Status & RTE_E_LOST_DATA) == RTE_E_LOST_DATA)
              )
         {
            Rte_Status = Rte_Receive_Cel_Port_Cel(&bufferedCel);

            if ( Rte_Status != RTE_E_OK )
            {
               Vsm_CelRxNotification();
            }
         }
         break;
   }
}
#endif /* VSM_ENABLE_RTE                                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_OpStateRxNotification                                  **
**                                                                            **
** DESCRIPTION   : Notification for new operation state reception from KLEMMEN**
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : called from COM in SC7                                     **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE) Vsm_OpStateRxNotification(void)
{
   /*
    *  Critical section protection:
    *
    *  Reason:
    *    Provide atomic access to Com-signal VSM_SG_KLEMMEN_ST_VEH_CON
    *
    *  Necessary protection duration:
    *    - stop timer for operation state refresh
    *    - receive Com signal
    *    - update car status info
    *    - notify application about state change
    *    - notify FIM about state change
    *    - start timer for operation state refresh
    *
    *  Required protection type:
    *    Protection via disabled interrupts
    *
    */
   SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   Stm_HandleOperationStateChange();
   SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_EnergyStateRxNotification                              **
**                                                                            **
** DESCRIPTION   : Notification for new energy state reception from FZZSTD    **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : called from COM in SC7                                     **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE) Vsm_EnergyStateRxNotification(void)
{
   /*
    *  Critical section protection:
    *
    *  Reason:
    *    Provide atomic access to Com-signals VSM_SG_FZZSTD_ST_ENERG_FZM and
    *    VSM_SG_FZZSTD_ST_ILK_ERRM_FZM
    *
    *  Necessary protection duration:
    *    - stop timer for startup and vehicle state refresh
    *    - receive Com signals
    *    - update car status info
    *    - notify application about state change
    *    - notify FIM about state change
    *    - handle error memory signal in normal operation mode
    *    - start timer for startup and vehicle state refresh
    *    - clear DEM event
    *
    *  Required protection type:
    *    Protection via disabled interrupts
    *
    */
   SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   Stm_HandleVehicleStatusChange();
   SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_CelRxNotification                                      **
**                                                                            **
** DESCRIPTION   : Notification for new communication error lock reception    **
**                 from FZZSTD                                                **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : called from COM in SC7                                     **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE) Vsm_CelRxNotification(void)
{
   /*
    *  Critical section protection:
    *
    *  Reason:
    *    Provide atomic access to Com-signals VSM_SG_FZZSTD_ST_ENERG_FZM and
    *    VSM_SG_FZZSTD_ST_ILK_ERRM_FZM
    *
    *  Necessary protection duration:
    *    - stop timer for startup and vehicle state refresh
    *    - receive Com signals
    *    - update car status info
    *    - notify application about state change
    *    - notify FIM about state change
    *    - handle error memory signal in normal operation mode
    *    - stop timer for startup and vehicle state refresh
    *    - clear DEM event
    *
    *  Required protection type:
    *    Protection via disabled interrupts
    *
    */
   SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   Stm_HandleVehicleStatusChange();
   SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetState                                               **
**                                                                            **
** DESCRIPTION   : return current operational state                           **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : *state: operational state                                  **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : obsolete in case of RTE                                    **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
   Vsm_GetState(Vsm_OperatingStateType *state )
#else
FUNC(void, RTE_APPL_CODE)
   Vsm_GetState(P2VAR(Vsm_OperatingStateType, AUTOMATIC, RTE_APPL_DATA) state)
#endif
{
  *state = (Vsm_OperatingStateType)Stm_carStateInfo.state;

#ifndef VSM_ENABLE_RTE
  return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetState()                                                    */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetEnergyState                                         **
**                                                                            **
** DESCRIPTION   : return energy status information                           **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : *energyState : energy status information                   **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : obsolete in case of RTE                                    **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
   Vsm_GetEnergyState( Vsm_EnergyStateType *energyState )
#else
FUNC(void, RTE_APPL_CODE)
   Vsm_GetEnergyState( P2VAR(Vsm_EnergyStateType,
                             AUTOMATIC,
                             RTE_APPL_DATA) energyState
                     )
#endif
{
  /* return current energy status                                             */
  *energyState = (Vsm_EnergyStateType)Stm_carStateInfo.energyState;

#ifndef VSM_ENABLE_RTE
  return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetEnergyState                                                */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetCommunicationErrorLock                              **
**                                                                            **
** DESCRIPTION   : return error lock status                                   **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : comErrorLock : current error lock status                   **
**                                CEL_COM_ERROR_ENABLED                       **
**                                CEL_COM_ERROR_DISABLED                      **
**                                COM_INVALID                                 **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : obsolete in case of RTE                                    **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
       Vsm_GetCommunicationErrorLock(Vsm_CommunicationErrorLockType *comErrorLock)
#else
FUNC(void, RTE_APPL_CODE)
       Vsm_GetCommunicationErrorLock( P2VAR(Vsm_CommunicationErrorLockType,
                                            AUTOMATIC,
                                            RTE_APPL_DATA) comErrorLock
                                    )
#endif
{
  /* set current error lock status                                            */
  *comErrorLock = (Vsm_CommunicationErrorLockType)Stm_carStateInfo.
                                                        communicationErrorState;

#ifndef VSM_ENABLE_RTE
  return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetCommunicationErrorLock                                     */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_ENABLE_STATE_MONITOR */

/*** End of file **************************************************************/
