/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Omc.c                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : OMC (Operational Mode Control) as part modul of VSM Client    **
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
** olho         Oliver Hoeft               EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.2.2: 12.09.2011, olho: CR71039:    Commented void casts
 * V3.2.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V3.2.0: 13.10.2010, olgo: CR70555:    Multiple Call to Nvm_WriteBlock()
 *                     olgo: CR70801:    Initial error blocking not released
 * V3.1.0: 16.09.2010, olgo: CR70830:    Remove unused parameter in function
 *                                       vsm_cbk
 * V3.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE
 *                                       switch
 * V2.0.0: 16.06.2009, olho: BSCVSM-117: CR70232: Ignore invalid extended
 *                                       operational mode and changed return
 *                                       type to Std_ReturnType for
 *                                       Vsm_DiagModeExtensionChange &
 *                                       Vsm_DiagModeChange
 * V1.0.2: 12.02.2009, miwe: BSCVSM-106: Implemented review results
 * V1.0.1: 05.11.2008, dabu: BSCVSM-91:  Porting SC6 CR's to BAC2.1: CR61472
 * V1.0.0: 09.07.2008, olgo: BSCVSM-41:  Updates of Nvm-Handling
 *         05.06.2008, olgo: BSCVSM-44:  remove old SC6-RTE-functionality
 *                                       from VSM
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39:  Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-12:  RTE integration
 *                           BSCVSM-25:  Includes und API-Mapping
 *         07.01.2008, olgo: BSCVSM-20:  Mapping of NVM function
 *                                       Nvm_SetBlockProtection
 *         19.12.2007, olgo: BSCVSM-12:  RTE integration
 *         27.11.2007, olgo:             taken from SC6 V3.1.0 and ported to SC7
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 11.4 (advisory)
  *   A cast should not be performed between a pointer to object type and a
  *   different pointer to object type.
  *
  *   Reason:
  *   NvM API requires this cast.
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_C_FILE
   #define VSM_C_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */

#include <NvM.h>                             /* Nvm header file               */

/* global switch to enable or disable VSM - OMC (operational mode control)    */
#ifdef VSM_ENABLE_MODE_CONTROL                               /* switch on OMC */

/* ---- Perform version checking ------------ */
#if ( ( OMC_MAJOR_VERSION != 4u ) || \
      ( OMC_MINOR_VERSION != 1u ) )
  #error "Omc.c: Wrong version of Omc.h found!!"
#endif

#if ( ( OMC_CFG_MAJOR_VERSION != 4u ) || \
      ( OMC_CFG_MINOR_VERSION != 1u ))
  #error "Omc.c: Wrong version of Omc_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>
/* vsm internal status variable with the default operation mode before init   */
_STATIC_ VAR(Vsm_OperatingModeType, VSM_VAR)
           Vsm_internalStatus = VSM_MM_MODE_NORMAL;
/* vsm internal status variable with the default extended op. mode before init*/
_STATIC_ VAR(Vsm_OperatingModeExtensionType, VSM_VAR)
           Vsm_internalExtendedStatus = VSM_MM_MODE_EXTENSION_NORMAL;
#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Omc_Init                                                   **
**                                                                            **
** DESCRIPTION   : initialised VSM operational mode control                   **
**                                                                            **
** PRECONDITIONS : NVRAM manager is initialised, and NVRAMReadAll() has called**
**                                                                            **
** PARAMETER     : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE) Omc_Init(void)
{
   /* VSM_OMC001: Vsm_OmcNvData will be read after Wakeup                     */
   Vsm_internalStatus         = (Vsm_OperatingModeType)Vsm_OmcNvData.Vsm_opMode;
   Vsm_internalExtendedStatus = (Vsm_OperatingModeExtensionType)
                                              Vsm_OmcNvData.Vsm_opModeExtension;

   /* block the error memory if the operation mode is not NORMAL              */
   if ( Vsm_internalStatus != (uint8)VSM_MM_MODE_NORMAL )
   {
      OMC_BLOCK_ERROR_MEM();
      /* applications needn't informed about the new error memory state       */
   }

   return;
} /* end of Omc_Init() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetMode                                                **
**                                                                            **
** DESCRIPTION   : return current operational mode                            **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : mode : operational mode                                    **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : remove in case of RTE                                      **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
   Vsm_GetMode( Vsm_OperatingModeType *mode )
#else
FUNC(void, RTE_APPL_CODE)
   Vsm_GetMode(P2VAR(Vsm_OperatingModeType, AUTOMATIC, RTE_APPL_DATA) mode)
#endif
{
   /* return internal status                                                  */
   *mode = Vsm_internalStatus;

#ifndef VSM_ENABLE_RTE
   return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetMode() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_GetModeExtension                                       **
**                                                                            **
** DESCRIPTION   : return current extended operational mode                   **
**                                                                            **
** PRECONDITIONS : VSM client is initialised                                  **
**                                                                            **
** PARAMETER     : modeExtension : extended operational mode                  **
**                                                                            **
** RETURN        : E_OK - if RTE is disabled                                  **
**                 none - if RTE is enabled E_OK will be returned by RTE      **
**                                                                            **
** REMARKS       : remove in case of RTE                                      **
**                                                                            **
*******************************************************************************/
#ifndef VSM_ENABLE_RTE
FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
           Vsm_GetModeExtension( Vsm_OperatingModeExtensionType *modeExtension )
#else
FUNC(void, RTE_APPL_CODE)
           Vsm_GetModeExtension(P2VAR(Vsm_OperatingModeExtensionType,
                                      AUTOMATIC,
                                      RTE_APPL_DATA) modeExtension )
#endif
{
   *modeExtension = Vsm_internalExtendedStatus;

#ifndef VSM_ENABLE_RTE
   return E_OK;
#else
   return;
#endif
} /* end of Vsm_GetModeExtension() */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_DiagModeChange                                         **
**                                                                            **
** DESCRIPTION   : handle change of vehicle operation mode                    **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : Mode : operation mode                                      **
**                                                                            **
** RETURN        : E_OK                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
   Vsm_DiagModeChange (Vsm_OperatingModeType mode)
{
  NvM_RequestResultType NvResult;

  /* only if differs from local mode */
  if( Vsm_internalStatus != mode )
  {
    /* VSM_OMC005: validity check                                           */
    if ( mode > VSM_MM_MODE_BMW_FLASH )
    {
       mode = VSM_MM_MODE_NORMAL;
    }

    /*
     * block or unblock the error memory only if the blocking state of the
     * error memory is changed after it (prevent double blocking)
     */
    if ( ( mode               == (uint8)VSM_MM_MODE_NORMAL ) &&
         ( Vsm_internalStatus != (uint8)VSM_MM_MODE_NORMAL )
       )
    {
       /*
        * unblock the error memory if the new operation mode is NORMAL
        * and the old operation mode was not NORMAL (error memory was locked)
        */
       OMC_UNBLOCK_ERROR_MEM();
       /* applications needn't informed about the new error memory state    */
    }
    else
    {
      if ( ( mode != (uint8)VSM_MM_MODE_NORMAL ) &&
                ( Vsm_internalStatus == (uint8)VSM_MM_MODE_NORMAL )
              )
      {
         /*
          * block the error memory if the new operation mode is not NORMAL
          * and the old operation mode was NORMAL (error memory was not locked)
          */
         OMC_BLOCK_ERROR_MEM();
         /* applications needn't informed about the new error memory state */
      }
    }

    /* store new operation mode internaly */
    Vsm_internalStatus = mode;

    /* VSM_OMC008: reset extended mode to VSM_MM_MODE_EXTENSION_NORMAL      */
    Vsm_internalExtendedStatus = VSM_MM_MODE_EXTENSION_NORMAL;

    /* store new modes permanently                                          */
    SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                           SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

    Vsm_OmcNvData.Vsm_opMode          = Vsm_internalStatus;
    Vsm_OmcNvData.Vsm_opModeExtension = Vsm_internalExtendedStatus;

    SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                          SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

    NVM_GETERRORSTATUS( VSM_OMC_NV_DATA_BLOCK, &NvResult );
    if ( NVM_REQ_PENDING != NvResult )
    {
       /* Deviation MISRA-1 */
       /* discard return value -> DET will be triggered from NvM            */
       (void)NVM_WRITEBLOCK( VSM_OMC_NV_DATA_BLOCK,
                             ( P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) )
                                                               &Vsm_OmcNvData );
       VSM_WAIT_UNTIL_BLOCK_IS_READY( VSM_OMC_NV_DATA_BLOCK );
    }

    /* Callback to "FIM"                                                    */
    OMC_VSM_NOTIFYMODECHANGEEVENT(mode);

    /* Callbacks to Applikation                                             */
    Vsm_Cbk( Vsm_NotifyModeChange, mode );
    Vsm_Cbk( Vsm_NotifyModeExtensionChange, Vsm_internalExtendedStatus );
  }

  return E_OK;

} /* end of Vsm_DiagModeChange()                                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_DiagModeExtensionChange                                **
**                                                                            **
** DESCRIPTION   : handle change of extended vehicle operation mode           **
**                                                                            **
** PRECONDITIONS : VSM Client is initialised                                  **
**                                                                            **
** PARAMETER     : extendedMode : extended operation mode                     **
**                                                                            **
** RETURN        : E_OK     - if extendedMode is valid                        **
**                 E_NOT_OK - if extendedMode is invalid                      **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
     Vsm_DiagModeExtensionChange
        ( Vsm_OperatingModeExtensionType extendedMode )
{
   Std_ReturnType RetVal = E_OK;
   NvM_RequestResultType NvResult;

   /* VSM_OMC006: validity check                                              */
   if ((uint8)extendedMode <= (uint8)VSM_MM_MODE_EXTENSION_SAVE_ENERGY)
   {
      /* only if differs from local mode                                      */
      if( Vsm_internalExtendedStatus != extendedMode )
      {
         /* store internaly                                                   */
         Vsm_internalExtendedStatus = extendedMode;

         /* store new extended mode permanently                               */
         SchM_Enter_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                                SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

         Vsm_OmcNvData.Vsm_opModeExtension = Vsm_internalExtendedStatus;

         SchM_Exit_Vsm_Client( SCHM_VSM_CLIENT_INSTANCE_0,
                               SCHM_VSM_CLIENT_EXCLUSIVE_AREA_0 );

         NVM_GETERRORSTATUS( VSM_OMC_NV_DATA_BLOCK, &NvResult );
         if ( NVM_REQ_PENDING != NvResult )
         {
            /* Deviation MISRA-1 */
            /* discard return value -> DET will be triggered from NvM         */
            (void)NVM_WRITEBLOCK ( VSM_OMC_NV_DATA_BLOCK,
                                   ( P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) )
                                                               &Vsm_OmcNvData );
            VSM_WAIT_UNTIL_BLOCK_IS_READY( VSM_OMC_NV_DATA_BLOCK );
         }

         /* Callbacks to Applikation                                          */
         Vsm_Cbk( Vsm_NotifyModeExtensionChange, extendedMode );
      }
   }
   else
   {
      RetVal = E_NOT_OK;
   }

   return RetVal;

} /* end of Vsm_DiagModeExtensionChange()                                     */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_ENABLE_MODE_CONTROL */

/*** End of file **************************************************************/
