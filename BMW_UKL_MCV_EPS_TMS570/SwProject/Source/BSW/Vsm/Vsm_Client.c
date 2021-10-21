/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Vsm_Client.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : "Vehicle State Management" - client                           **
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
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.2.3: 12.09.2011, olho: CR71039: Commented void casts
 * V3.2.2: 19.05.2011, thmi: CR70970: Prevent the repeatedly block/unblock DEM
 * V3.2.1: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V3.2.0: 13.10.2010, olgo: CR70555: Multiple Call to Nvm_WriteBlock()
 *                     olgo: CR70801: Initial error blocking not released
 * V3.1.1: 16.06.2010, olgo: CR70676: Remove dead code from VSM
 * V3.1.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 * V3.0.0: 05.10.2009, hauf: CR70371: Removed SC6 variants and added RTE switch
 *         09.10.2008, hauf: CR70291: Corrected storage class of
 *                                    Vsm_NvData_Default to VSM_CONST and added
 *                                    compiler abstraction to cast of Vsm_NvData
 * V2.0.3: 08.09.2009, miwe: BSCVSM-122: using wrapper for NvM API instead of
 *                                       direct call
 * V2.0.2: 12.02.2009, miwe: BSCVSM-106: Implemented review results
 * V2.0.1: 21.01.2009, olgo: BSCVSM-104: CR70040: leerer default Zweig in
 *                                       case-Konstrukt in Vsm_Client.c
 * V2.0.0: 11.11.2008, olgo: BSCVSM-90:  CR70027: VSM: Rename FIM functions to
 *                                       avoid name clash with AUTOSAR FIM
 * V1.0.0: 21.07.2008, olgo: BSCVSM-75:  Timeout handling by COM module
 *         09.07.2008, olgo: BSCVSM-41:  Updates of Nvm-Handling
 *         24.06.2008, olgo: BSCVSM-52:  Adaptations regarding released VSM-SWS
 *         05.06.2008, olgo: BSCVSM-44:  remove old SC6-RTE-functionality
 *                                       from VSM
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39:  Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         27.11.2007, olgo: taken from  SC6 V3.1.0 and ported to SC7
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_C_FILE
   #define VSM_C_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */

#include <EcuM.h>
#include <NvM.h>

/* ---- Perform version checking ------------ */
#if ( ( VSM_CLIENT_MAJOR_VERSION != 4u ) || \
      ( VSM_CLIENT_MINOR_VERSION != 1u ) )
  #error "Vsm_Client.c: Wrong version of Vsm_Client.h found!!"
#endif

#if ( ( VSM_CLIENT_CFG_MAJOR_VERSION != 4u ) || \
      ( VSM_CLIENT_CFG_MINOR_VERSION != 1u ) )
  #error "Vsm_Client.c: Wrong version of Vsm_Client_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define VSM_START_SEC_VAR_NVDATA
#include <MemMap.h>
/*
 * Instantiation of RAM block for VSM data in application.
 * Initialized in 'appldiag.c'
 */
#ifdef VSM_ENABLE_MODE_CONTROL
VAR(Vsm_OmcNvDataType, VSM_VAR) Vsm_OmcNvData;        /* NVRAM mirror for OMC */
#endif /* VSM_ENABLE_MODE_CONTROL                                             */

#ifdef VSM_ENABLE_WAKEUP_REGISTRATION
VAR(Vsm_WurNvDataType, VSM_VAR) Vsm_WurNvData;        /* NVRAM mirror for WUR */
#endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                      */

#define VSM_STOP_SEC_VAR_NVDATA
#include <MemMap.h>

#define VSM_START_SEC_CONST_8BIT
#include <MemMap.h>
/* VSM_OMC001, VSM_WUR021 default modes after first startup                   */
/* (for Vsm_OmcNvData and Vsm_WurNvData used by NVM) of ECU in case of errors */
/* during NVRAM reading                                                       */
#ifdef VSM_ENABLE_MODE_CONTROL
CONST(Vsm_OmcNvDataType, VSM_CONST) Vsm_OmcNvData_Default =
      {  VSM_MM_MODE_NORMAL,
         VSM_MM_MODE_EXTENSION_NORMAL
      };
#endif /* VSM_ENABLE_MODE_CONTROL                                             */

#ifdef VSM_ENABLE_WAKEUP_REGISTRATION
CONST(Vsm_WurNvDataType, VSM_CONST) Vsm_WurNvData_Default =
      {  (uint8)0x00u,
         VSM_WACA_INVALID
      };
#endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                      */
#define VSM_STOP_SEC_CONST_8BIT
#include <MemMap.h>

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>
VAR(Vsm_StateType, VSM_VAR)  Vsm_State = VSM_UNINIT;

_STATIC_ VAR(boolean, VSM_VAR) dem_is_blocked_omc = FALSE;
_STATIC_ VAR(boolean, VSM_VAR) dem_is_blocked_stm = FALSE;
_STATIC_ VAR(boolean, VSM_VAR) dem_is_blocked_all = FALSE;

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_BlockDem                                               **
**                                                                            **
** DESCRIPTION   : Locking of DEM                                             **
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
FUNC(void, VSM_PRIVATE_CODE) Vsm_BlockDem( Vsm_DemHandlungFunctionType func )
{
   SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
   switch ( func )
   {
      case VSM_OMC_DEM_HANDLING:
         if ( dem_is_blocked_omc == FALSE )
         {
           if( dem_is_blocked_all==FALSE )
           {
              VSM_BLOCK_ERROR_MEM();
              dem_is_blocked_all = TRUE;
           }
            dem_is_blocked_omc = TRUE;
         }
         break;
      case VSM_STM_DEM_HANDLING:
         if ( dem_is_blocked_stm == FALSE )
         {
           if( dem_is_blocked_all==FALSE )
           {
              VSM_BLOCK_ERROR_MEM();
              dem_is_blocked_all = TRUE;
           }
            dem_is_blocked_stm = TRUE;
         }
         break;
      default:
         break;
   }

   SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
} /* end of Vsm_BlockDem()                                                    */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_UnBlockDem                                             **
**                                                                            **
** DESCRIPTION   : Unlocking of DEM                                           **
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
FUNC(void, VSM_PRIVATE_CODE) Vsm_UnBlockDem( Vsm_DemHandlungFunctionType func )
{
   SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

   switch ( func )
   {
      case VSM_OMC_DEM_HANDLING:
         dem_is_blocked_omc = FALSE;
         break;
      case VSM_STM_DEM_HANDLING:
         dem_is_blocked_stm = FALSE;
         break;
      default:
         break;
   }

   if ( (dem_is_blocked_all==TRUE) &&
        (dem_is_blocked_omc == FALSE) && (dem_is_blocked_stm == FALSE)
      )
   {
      VSM_UNBLOCK_ERROR_MEM();
      dem_is_blocked_all = FALSE;
   }

   SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                         SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );
} /* end of Vsm_UnBlockDem()                                                  */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_Init                                                   **
**                                                                            **
** DESCRIPTION   : initialised VSM client                                     **
**                                                                            **
** PRECONDITIONS : NVRAM manager and DEM is initialised                       **
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Vsm_Init(void)
{
   /* Try to read from Nvm_Block                                              */
   #ifdef VSM_ENABLE_MODE_CONTROL
   NvM_RequestResultType OmcNvResult;
   #endif /* VSM_ENABLE_MODE_CONTROL                                          */

   #ifdef VSM_ENABLE_WAKEUP_REGISTRATION
   NvM_RequestResultType WurNvResult;
   #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                   */

   /* VSM doesn't block error memory at this time                             */
   dem_is_blocked_omc = FALSE;
   dem_is_blocked_stm = FALSE;
   dem_is_blocked_all = FALSE;

   /* check correct status of Nv-Block                                        */
   /* NVM_REQ_OK : Was read successfully                                      */
   /* else: VSM are not able to initialize -> DET, DEM?                       */
   #ifdef VSM_ENABLE_MODE_CONTROL
   NVM_GETERRORSTATUS(VSM_OMC_NV_DATA_BLOCK, &OmcNvResult);
   #endif /* VSM_ENABLE_MODE_CONTROL                                          */

   #ifdef VSM_ENABLE_WAKEUP_REGISTRATION
   NVM_GETERRORSTATUS(VSM_WUR_NV_DATA_BLOCK, &WurNvResult);
   #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                   */

   #ifdef VSM_ENABLE_MODE_CONTROL
   if ( OmcNvResult != NVM_REQ_PENDING )
   {
   #endif /* VSM_ENABLE_MODE_CONTROL                                          */
      #ifdef VSM_ENABLE_WAKEUP_REGISTRATION
      if ( WurNvResult != NVM_REQ_PENDING )
      {
      #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                */
         #ifdef VSM_ENABLE_FUNC_NM                           /* switch on FNM */
         /* init of functional nm                                             */
         Fnm_Init();
         #endif /* VSM_ENABLE_FUNC_NM                                         */

         #ifdef VSM_ENABLE_STATE_MONITOR                     /* switch on STM */
         /* init of status monitor                                            */
         StmFse_Init();
         #endif /* VSM_ENABLE_STATE_MONITOR                                   */

         #ifdef VSM_ENABLE_MODE_CONTROL                      /* switch on OMC */
         /* init of operational mode control                                  */
         Omc_Init();
         #endif /* VSM_ENABLE_MODE_CONTROL                                    */

         #ifdef VSM_ENABLE_FUNC_INHIB_MAN                    /* switch on FIM */
         /* init of function inhibition manager                               */
         VsmFim_Init();                           /* init of fim always after */
                                                  /* init of stm and omc      */
         #endif /* VSM_ENABLE_FUNC_INHIB_MAN                                  */

         #ifdef VSM_ENABLE_COMCONTROL                 /* switch on ComControl */
         /* init of communication control                                     */
         ComControl_Init();
         #endif /* VSM_ENABLE_COMCONTROL                                      */

         #ifdef VSM_ENABLE_WAKEUP_REGISTRATION               /* switch on WUR */
         /* init of wakeup registration                                       */
         Wur_Init();
         #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                             */

         /* set VSM state machine                                             */
         Vsm_State = VSM_RUNNIG;
      #ifdef VSM_ENABLE_WAKEUP_REGISTRATION
      }
      else
      {
         /* Vsm_State remains VSM_UNINIT                                      */
         Vsm_State = VSM_UNINIT;
      }
      #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                */
   #ifdef VSM_ENABLE_MODE_CONTROL
   }
   else
   {
      /* Vsm_State remains VSM_UNINIT                                         */
      Vsm_State = VSM_UNINIT;
   }
   #endif /* VSM_ENABLE_MODE_CONTROL                                          */

   return;
} /* end of Vsm_Init()                                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_MainFunction                                           **
**                                                                            **
** DESCRIPTION   : status machine of VSM client                               **
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
FUNC(void, VSM_PUBLIC_CODE) Vsm_MainFunction(void)
{
   EcuM_StateType        ecuM_State;

   if ( Vsm_State == VSM_RUNNIG )
   {
      #if defined (VSM_VERSION_BAC3x)
         /* discard return value -> DET will be triggered from EcuM        */
         (void)EcuM_GetState(&ecuM_State);
      #elif defined (VSM_VERSION_BAC21)
         ecuM_State = EcuM_GetState();
      #else
         #error "Vsm_Client.c: Undefined VSM_VERSION"
      #endif

      if ( ecuM_State < ECUM_STATE_SHUTDOWN )
      {

      #ifdef VSM_ENABLE_WAKEUP_REGISTRATION               /* switch on WUR */
          /* main function of wakeup registration to trigger a timer       */
          /* for wakeup registration message                               */
          Wur_Main();
      #endif /* VSM_ENABLE_WAKEUP_REGISTRATION                             */

      #ifdef VSM_ENABLE_STATE_MONITOR                     /* switch on STM */
          /* main function of status monitor to look for new messages      */
          /* with new states and trigger a timer                           */
          StmFse_Main();
      #endif /* VSM_ENABLE_STATE_MONITOR                                   */

      #ifdef VSM_ENABLE_FUNC_NM
          /* main function of FNM to handle shutdown time of transceiver   */
          /* after PowerOn or Reset                                        */
          Fnm_Main();
      #endif /* VSM_ENABLE_FUNC_NM                                         */

      #ifdef VSM_ENABLE_COMCONTROL
          /* main function of ComControl to start/stop PDU-Groups          */
          ComControl_Main();
      #endif /* VSM_ENABLE_COMCONTROL                                      */

      }
   }

   return;
} /* end of Vsm_MainFunction()                                             */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

/*** End of file **************************************************************/
