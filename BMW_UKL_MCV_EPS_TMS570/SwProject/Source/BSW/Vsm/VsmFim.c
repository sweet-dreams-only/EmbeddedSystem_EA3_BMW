/*******************************************************************************
**                                                                            **
**  SRC-MODULE: VsmFim.c                                                      **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : FIM (Function Inhibition Manager) as generic part modul       **
**              of VSM Client                                                 **
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.1.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V3.1.0: 02.02.2011, olgo: CR70908:    some MISRA warnings are missing
 *                                       in the report
 * V3.0.3: 13.10.2010, olgo: CR70801:    Initial error blocking not released
 * V3.0.2: 16.06.2010, olgo: CR70676:    Remove dead code from VSM
 * V3.0.1: 05.02.2010, mani: CR70415:    Removed nested memory sections
 * V3.0.0: 05.10.2009, hauf: CR70371:    Removed SC6 variants and added RTE
 *                                       switch
 *         09.10.2009, hauf: CR70291:    Corrected storage class of local
 *                                       constants to VSM_CONST
 * V2.0.2: 12.02.2009, miwe  BSCVSM-106: Implemented review results
 * V2.0.1: 22.01.2008, olgo: BSCVSM-102: CR70071: VsmFim - inhibition state of
 *                                       Op-ModeCheck is ignored by later checks
 *                                       in Vsm_IsInhibited
 * V2.0.0: 11.11.2008, olgo: BSCVSM-90 : CR70027: VSM: Rename FIM functions to
 *                                       avoid name clash with AUTOSAR FIM
 * V1.0.0: 30.06.2008, dabu: BSCVSM-76 : Wrong default return value
 *                                       (inhibitionStatus) in Vsm_IsInhibited()
 *         05.06.2008, olgo: BSCVSM-44 : remove old SC6-RTE-functionality
 *                                       from VSM
 *         04.06.2008, olgo: BSCVSM-49 : Number of Applications in FIM wrong
 *         03.04.2008, olgo: BSCVSM-42 : Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39 : Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35 : VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         28.01.2008, olgo: BSCVSM-29 : Faulty preprocessor clause in Fim.c
 *         16.01.2008, olgo: BSCVSM-12 : RTE integration
 *                           BSCVSM-25 : Includes und API-Mapping
 *         19.12.2007, olgo: BSCVSM-14 : Vsm_ReInit is declared for all version,
 *                                       but shall only be available for
 *                                       VSM Version = SC6
 *         29.11.2007, olgo: taken from SC6 V3.1.0 and ported to SC7
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

#define VSM_FIM_ONLY_FIM_C
#define VSM_C_FILE
#include <Vsm_Client.h>



/* global switch to enable or disable VSM - FIM (Function Inhibition Manager) */
#ifdef VSM_ENABLE_FUNC_INHIB_MAN                      /* switch on FIM        */

/* ---- Perform version checking ------------ */
#if ( ( FIM_MAJOR_VERSION != 4u ) || \
      ( FIM_MINOR_VERSION != 1u ) )
  #error "VsmFim.c: Wrong version of VsmFim.h found!!"
#endif

#if ( ( FIM_CFG_MAJOR_VERSION != 4u ) || \
      ( FIM_CFG_MINOR_VERSION != 1u ) )
  #error "VsmFim.c: Wrong version of VsmFim_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* internal macros for error states                                           */
#define VSM_FIM_ERROR                             0x00
#define VSM_FIM_FUNC_NOT_FOUND                    0xFF


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE)
              VsmFim_GetFuncId_Index( uint16 funcID );
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE)
              VsmFim_GetOpModeBitArray( uint8 opMode );
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE)
              VsmFim_GetFimOpState( uint8 opState );
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE)
              VsmFim_GetEnStateBitArray( uint8 enState );
_STATIC_ FUNC(boolean, VSM_PRIVATE_CODE)
              VsmFim_IsFuncAllowedInOpMode( uint8 funcID_Idx, uint8 opMode );
_STATIC_ FUNC(boolean, VSM_PRIVATE_CODE)
              VsmFim_IsFuncAllowedInOpStateAndEnState( uint8 funcID_Idx, \
                                                       uint8 fimOpState, \
                                                       uint8 enState );

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/
#define VSM_START_SEC_CONST_8BIT
#include <MemMap.h>

/* array with the operational modes bit-masks for specified function-index */
/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) Vsm_FimOpModeFuncBitArray[VSM_FIM_NUM_APP] = \
                                              VSM_FIMOPMODEFUNCBITARRAY;

/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST)
             Vsm_FimFuncOpStateEnStateBitArray[VSM_FIM_NUM_APP][8] = \
                                              VSM_FIMFUNCOPSTATEENSTATEBITARRAY;

#define VSM_STOP_SEC_CONST_8BIT
#include <MemMap.h>

#if ( VSM_FIM_NUM_APP > 0 )    /* only if at least one function is configured */

#define VSM_START_SEC_CONST_16BIT
#include <MemMap.h>

 /* array with the internal function-indeces of the applications              */
/* Deviation MISRA-1 */
_STATIC_ CONST(uint16, VSM_CONST) Vsm_FimFuncArray[VSM_FIM_NUM_APP] = VSM_FIMFUNCARRAY;

#define VSM_STOP_SEC_CONST_16BIT
#include <MemMap.h>

#endif /* VSM_FIM_NUM_APP > 0 */

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

_STATIC_ VAR(Vsm_OperatingModeType, VSM_VAR)    VsmFim_internalOpMode;
_STATIC_ VAR(Vsm_OperatingStateType, VSM_VAR)   VsmFim_internalOperatingState;
_STATIC_ VAR(Vsm_EnergyStateType, VSM_VAR)      VsmFim_internalEnergyState;

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Local Constants                                       **
*******************************************************************************/

#define VSM_START_SEC_CONST_8BIT
#include <MemMap.h>

/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) fimOpModeArray[VSM_FIM_NR_OF_OP_MODES] =
{
   VSM_MM_MODE_NORMAL,
   VSM_MM_MODE_ASSEMBLY,
   VSM_MM_MODE_TRANSPORT,
   VSM_MM_MODE_BMW_FLASH
};

/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) fimOpModeBitArray[VSM_FIM_NR_OF_OP_MODES] =
{
   VSM_FIM_MODE_NORMAL_ARR,
   VSM_FIM_MODE_ASSEMBLY_ARR,
   VSM_FIM_MODE_TRANSPORT_ARR,
   VSM_FIM_MODE_BMW_FLASH_ARR
};

/* VSM_FIM004: Array for converting OpState -> Fim_OpState                 */
/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) Fim_OpStates[] =
{
   VSM_FIM_STATE_INIT,            /* VSM_STM_STATE_INIT                    */
   VSM_FIM_STATE_STANDBY,         /* VSM_STM_STATE_STANDBY                 */
   VSM_FIM_STATE_BASICOP,         /* VSM_STM_STATE_BASICOP                 */
   VSM_FIM_STATE_BASICOP,         /* VSM_STM_STATE_BASICOP_ROLL            */
   VSM_FIM_STATE_BASICOP,         /* VSM_STM_STATE_15OFF_DRIVE             */
   VSM_FIM_STATE_IGNITION,        /* VSM_STM_STATE_IGNITION                */
   VSM_FIM_STATE_IGNITION,        /* VSM_STM_STATE_IGNITION_ROLL           */
   VSM_FIM_STATE_DRIVE,           /* VSM_STM_STATE_ENG_IDLE                */
   VSM_FIM_STATE_DRIVE,           /* VSM_STM_STATE_DRIVE                   */
   VSM_FIM_STATE_ENG_START,       /* VSM_STM_STATE_ENG_START_PRE           */
   VSM_FIM_STATE_ENG_START,       /* VSM_STM_STATE_ENG_START_PRE_ROLL      */
   VSM_FIM_STATE_ENG_START,       /* VSM_STM_STATE_ENG_START               */
   VSM_FIM_STATE_ENG_START,       /* VSM_STM_STATE_ENG_START_ROLL          */
   VSM_FIM_STATE_IGNITION,        /* VSM_STM_STATE_WASH                    */
   VSM_FIM_STATE_ERROR,           /* VSM_STM_STATE_ERROR                   */
   VSM_FIM_STATE_INVALID,         /* VSM_STM_STATE_INVALID                 */
};

/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) fimEnStateArray[VSM_FIM_NR_OF_EN_STATES] =
{
   VSM_STM_EN_GOOD,
   VSM_STM_EN_OK,
   VSM_STM_EN_SHORTAGE,
   VSM_STM_EN_SEVERE_SHORTAGE,
   VSM_STM_EN_INVALID
};

/* Deviation MISRA-1 */
_STATIC_ CONST(uint8, VSM_CONST) fimEnStateBitArray[VSM_FIM_NR_OF_EN_STATES] =
{
   VSM_FIM_EN_GOOD_ARR,
   VSM_FIM_EN_OK_ARR,
   VSM_FIM_EN_SHORTAGE_ARR,
   VSM_FIM_EN_SEVERE_SHORTAGE_ARR,
   VSM_FIM_EN_INVALID_ARR
};

#define VSM_STOP_SEC_CONST_8BIT
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_GetFuncId_Index                                     **
**                                                                            **
** DESCRIPTION   : return the internal index-number of the application        **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : vehicle-wide unique id of the application (function)       **
**                                                                            **
** RETURN        : internal index-number of the application                   **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE) VsmFim_GetFuncId_Index( uint16 funcID )
{
#if ( VSM_FIM_NUM_APP > 0 )    /* only if at least one function is configured */

  uint8_least funcID_Idx;
  uint8 funcIdx = (uint8)VSM_FIM_FUNC_NOT_FOUND;

  /* loop through an array with all registrated application-ids               */
  for (funcID_Idx = 0; funcID_Idx < VSM_FIM_NUM_APP; funcID_Idx++)
  {
    if (Vsm_FimFuncArray[funcID_Idx] == funcID)
    {
      /* internal index-number found                                          */
      funcIdx = (uint8)funcID_Idx;

      /* break for-loop                                                       */
      break;
    }
  }

  return funcIdx;

#else

  return (uint8)VSM_FIM_FUNC_NOT_FOUND;

#endif /* VSM_FIM_NUM_APP > 0 */
} /* end of VsmFim_GetFuncId_Index() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_GetOpModeBitArray                                   **
**                                                                            **
** DESCRIPTION   : return a bit-mask with the according operation-mode        **
**                 every bit stand for a special operation mode               **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : actual operation mode                                      **
**                                                                            **
** RETURN        : uint8-value with the bit-mask of this actual op-mode       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE) VsmFim_GetOpModeBitArray( uint8 opMode )
{
   uint8 RetVal = (uint8)VSM_FIM_ERROR;
   uint8_least Idx;

   /* loop through an array with all operation modes */
   for (Idx = 0; Idx < (uint8_least)VSM_FIM_NR_OF_OP_MODES; Idx++)
   {
      if (fimOpModeArray[Idx] == opMode)
      {
         /* operation mode found --> return according bit-mask */
         RetVal = fimOpModeBitArray[Idx];

         /* break for loop */
         break;
      }
   }

   return RetVal;
} /* end of VsmFim_GetOpModeBitArray() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_GetFimOpState                                       **
**                                                                            **
** DESCRIPTION   : return the Fim specific operation-state according          **
**                 the specified vehicle operation-state                      **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : actual operation state                                     **
**                                                                            **
** RETURN        : uint8-value with the Fim specific operation-state          **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE) VsmFim_GetFimOpState( uint8 opState )
{
   uint8 RetVal;

   if ( opState >= (sizeof(Fim_OpStates) / sizeof(uint8)) )
   {
      /* invalid value of opState */
      RetVal = (uint8)VSM_FIM_STATE_INVALID;
   }
   else
   {
      RetVal = Fim_OpStates[opState];
   }

   return RetVal;
} /* end of VsmFim_GetFimOpState() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_GetEnStateBitArray                                  **
**                                                                            **
** DESCRIPTION   : return a bit-mask with the according energy-state          **
**                 every bit stand for a special energy state                 **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : actual operation state                                     **
**                                                                            **
** RETURN        : uint8-value with the bit-mask of this actual en-state      **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint8, VSM_PRIVATE_CODE) VsmFim_GetEnStateBitArray( uint8 enState )
{
   uint8 RetVal = (uint8)VSM_FIM_ERROR;
   uint8_least Idx;

   /* loop through an array with all energy states */
   for (Idx = 0; Idx < (uint8_least)VSM_FIM_NR_OF_EN_STATES; Idx++)
   {
      if (fimEnStateArray[Idx] == enState)
      {
         /* energy state found --> return according bit-mask */
         RetVal = fimEnStateBitArray[Idx];

         /* break for loop */
         break;
      }
   }

   return RetVal;
} /* end of VsmFim_GetEnStateBitArray() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_IsFuncAllowedInOpMode                               **
**                                                                            **
** DESCRIPTION   : return whether the application is allowed in the actual    **
**                 operation mode                                             **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : internal index of the application                          **
**                 actual operation mode                                      **
**                                                                            **
** RETURN        : TRUE - if the application is allowed                       **
**                 FALSE - if the application is not allowed                  **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(boolean, VSM_PRIVATE_CODE)
              VsmFim_IsFuncAllowedInOpMode( uint8 funcID_Idx, uint8 opMode )
{
#if ( VSM_FIM_NUM_APP > 0 )    /* only if at least one function is configured */

   boolean RetVal = FALSE;
   /* get the bit-mask with the according operation-mode */
   uint8 opMode_BitArr = VsmFim_GetOpModeBitArray( opMode );

   /* check, if the bit of the actual op-mode in the operation mode bit-mask
      is set for this function-id */
   if( ( (Vsm_FimOpModeFuncBitArray[funcID_Idx]) & opMode_BitArr ) > 0 )
   {
      /* op-mode bit for this function is set */
      RetVal = TRUE;
   }

   return RetVal;

#else

   return FALSE;

#endif /* VSM_FIM_NUM_APP > 0 */
} /* end of VsmFim_IsFuncAllowedInOpMode() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_IsFuncAllowedInOpStateAndEnState                    **
**                                                                            **
** DESCRIPTION   : return whether the application is allowed in the actual    **
**                 combination of vehicle operation state and energy state    **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETER     : internal index of the application                          **
**                 actual vehicle operation state                             **
**                 actual energy state                                        **
**                                                                            **
** RETURN        : TRUE - if the application is allowed                       **
**                 FALSE - if the application is not allowed                  **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(boolean, VSM_PRIVATE_CODE)
              VsmFim_IsFuncAllowedInOpStateAndEnState( uint8 funcID_Idx,
                                                       uint8 fimOpState,
                                                       uint8 enState )
{
#if ( VSM_FIM_NUM_APP > 0 )    /* only if at least one function is configured */

   boolean RetVal = FALSE;
   /* get the bit-mask with the according energy-state                        */
   uint8 enState_BitArr = VsmFim_GetEnStateBitArray( enState );

   /* check, if the bit of the actual energy state in the energy state bit-mask
      is set for this function-id and actual Fim specific operation status */
   if( ( (Vsm_FimFuncOpStateEnStateBitArray[funcID_Idx][fimOpState]) &
          enState_BitArr ) > 0
     )
   {
     /* en-state bit for this function and op-state is set */
      RetVal = TRUE;
   }

   return RetVal;

#else

   return FALSE;

#endif /* VSM_FIM_NUM_APP > 0 */
} /* end of VsmFim_IsFuncAllowedInOpStateAndEnState() */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : VsmFim_Init                                                **
**                                                                            **
** DESCRIPTION   : initialised VSM FIM                                        **
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
FUNC(void, VSM_PUBLIC_CODE) VsmFim_Init(void)
{
  /* get the actual operational status from status monitor                    */
  FIM_VSM_GETSTATE( &VsmFim_internalOperatingState );
  /* get the actual energy state from status monitor                          */
  FIM_VSM_GETENERGYSTATE( &VsmFim_internalEnergyState );
  /* get the actual operational mode from operational mode control            */
  FIM_VSM_GETMODE( &VsmFim_internalOpMode );

  return;
} /* end of VsmFim_Init() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_IsInhibited                                            **
**                                                                            **
** DESCRIPTION   : return the inhibition state of the function according the  **
**                 actual operation mode, operation state and energy state    **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** PARAMETER     : funcID : vehicle-wide unique id of the application         **
**                 inhibitionStatus : inhibition status of the application    **
**                    VSM_FIM_APP_ENABLED - function is allowed               **
**                 VSM_FIM_APP_INHIBITED - function is not allowed            **
**                 VSM_FIM_APP_INVALID - invalid states                       **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
     Vsm_IsInhibited( uint16 functionId,
                      Vsm_InhibitionStatusType *inhibitionStatus
                    )
#else
FUNC(void, RTE_APPL_CODE)
     Vsm_IsInhibited( UInt16 functionId,
                      P2VAR( Vsm_InhibitionStatusType,
                             AUTOMATIC,
                             RTE_APPL_DATA
                           ) inhibitionStatus
                     )
#endif
{
   uint8 funcID_Idx;
   uint8 fimOpState;

   /* 6. of VSM_FIM005: preset the value                                      */
   *inhibitionStatus = VSM_FIM_APP_INHIBITED;


   /* 1. and 2. of VSM_FIM005 this operational and energy states are invalid  */
   /* always VSM_FIM_APP_INVALID                                              */
   if ( ( VsmFim_internalOperatingState == VSM_STM_STATE_INIT )    ||
        ( VsmFim_internalOperatingState == VSM_STM_STATE_ERROR )   ||
        ( VsmFim_internalOperatingState == VSM_STM_STATE_INVALID ) ||
        ( VsmFim_internalEnergyState    == VSM_STM_EN_INVALID ) )
   {
      *inhibitionStatus = VSM_FIM_APP_INVALID;
   }
   else
   {

      /* get the index for this function id, and query whether its configured */
      funcID_Idx = VsmFim_GetFuncId_Index( functionId );
      if (funcID_Idx == VSM_FIM_FUNC_NOT_FOUND)
      {
         /* error occurs: this application with this funcID is not provided   */
         /* return of VSM_FIM_APP_ENABLED by default                          */
         *inhibitionStatus = VSM_FIM_APP_ENABLED;
      }

      /* 4. of VSM_FIM005: query, whether the function is allowed in this     */
      /* op-mode                                                              */
      else if ( VsmFim_IsFuncAllowedInOpMode( funcID_Idx,
                                      (uint8)VsmFim_internalOpMode ) == FALSE )
      {
         /* function is not allowed for this op-mode                          */
         *inhibitionStatus = VSM_FIM_APP_INHIBITED;
      }
      else
      {
         /* get the Fim operational status for this actual op-state           */
         fimOpState = VsmFim_GetFimOpState
                                       ( (uint8)VsmFim_internalOperatingState );
         if ( fimOpState == VSM_FIM_STATE_INVALID )
         {
            /* error occurs: for this op-state no fim-op-state is provided    */
            /* return of VSM_FIM_APP_ENABLED by default                       */
            *inhibitionStatus = VSM_FIM_APP_ENABLED;
         }

         /* 5. of VSM_FIM005: query, whether the function is allowd in this   */
         /* fim-op-state and  energy-state                                    */
         else
         {
           if ( VsmFim_IsFuncAllowedInOpStateAndEnState
                 (
                    funcID_Idx,
                    fimOpState,
                    (uint8)VsmFim_internalEnergyState
                 ) != FALSE
              )
           {
              /* function is allowed for this fim-op-state and energy-state   */
              *inhibitionStatus = VSM_FIM_APP_ENABLED;
           }
         }
      }
   }

#ifndef VSM_ENABLE_RTE
   return E_OK;
#else
   return;
#endif
} /* end of Vsm_IsInhibited() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyModeChangeEvent                                  **
**                                                                            **
** DESCRIPTION   : Information from OMC about VSM mode change                 **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** PARAMETER     : newMode - new global mode of vehicle                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeChangeEvent(uint8 newMode)
{
  /* save the actual operational mode in the internal variable */
  VsmFim_internalOpMode = (Vsm_OperatingModeType)newMode;

  return;
} /* end of Vsm_NotifyModeChangeEvent() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyStateChangeEvent                                 **
**                                                                            **
** DESCRIPTION   : Information from FIM about VSM state change.               **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** PARAMETER     : newState - new global state of vehicle                     **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyStateChangeEvent(uint8 newOpState)
{
  /* save the actual operational status in the internal variable */
  VsmFim_internalOperatingState = (Vsm_OperatingStateType)newOpState;

  return;
} /* end of Vsm_NotifyStateChangeEvent() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_NotifyEnergyStateChangeEvent                           **
**                                                                            **
** DESCRIPTION   : Information from FIM about VSM energystate change          **
**                                                                            **
** PRECONDITIONS : VSM is initialised                                         **
**                                                                            **
** PARAMETER     : newEnState - new global energy state of vehicle            **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyEnergyStateChangeEvent(uint8 newEnState)
{
  /* save the actual energy state in the internal variable */
  VsmFim_internalEnergyState = (Vsm_EnergyStateType)newEnState;

  return;
} /* end of Vsm_NotifyEnergyStateChangeEvent() */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_ENABLE_FUNC_INHIB_MAN */

/*** End of file **************************************************************/
