/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Stm.h                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : STM (Status Monitor) as part modul of VSM Client              **
**              header                                                        **
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
** hauf         Andreas Hauf               EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.2.1: 17.02.2011, thmi: CR70908:   Update to MISRA 2004
 *                                      Revise or comment deviations
 * V2.2.0: 10.02.2011, olgo: CR70908:   prevent Misra warnings
 * V2.1.0: 30.06.2010, bemo: CR70628:   Signal receive over RTE
 * V2.0.0: 05.10.2009, hauf: CR70371:   removed SC6 variants and added RTE switch
 * V1.0.0: 15.07.2008, olgo: BSCVSM-74: Code Formatting
 *         03.04.2008, olgo: BSCVSM-42: Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39: Vsm may not include MemMap_Vsm.h but
 *                                      only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35: VSM with activated RTE collides with
 *                                      other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-12: RTE integration
 *                           BSCVSM-25: Includes und API-Mapping
 *         19.12.2007, olgo: BSCVSM-12: RTE integration
 *                           BSCVSM-14: Vsm_ReInit is declared for all version,
 *                                      but shall only be available for
                                        VSM Version = SC6
 *         27.11.2007, olgo: taken from SC6 V3.1.1 and ported to SC7
 */

#ifndef STM_H
#define STM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef BOOTLOADER
#ifndef VSM_H_FILE
   #define VSM_H_FILE
#endif
#include <Vsm_Client_Cfg.h>                    /* module global configuration */
                                               /* include file                */
#endif


/*******************************************************************************
**                      Version Control                                       **
*******************************************************************************/

#define STM_MAJOR_VERSION   4u
#define STM_MINOR_VERSION   1u
#define STM_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#ifndef VSM_ENABLE_RTE

/* return type of vehicle operation states - all possible return values       */
typedef enum
{
  VSM_STM_STATE_INIT                = 0x00u,
  VSM_STM_STATE_STANDBY             = 0x01u,
  VSM_STM_STATE_BASICOP             = 0x02u,
  VSM_STM_STATE_BASICOP_ROLL        = 0x03u,
  VSM_STM_STATE_15OFF_DRIVE         = 0x04u,
  VSM_STM_STATE_IGNITION            = 0x05u,
  VSM_STM_STATE_IGNITION_ROLL       = 0x06u,
  VSM_STM_STATE_ENG_IDLE            = 0x07u,
  VSM_STM_STATE_DRIVE               = 0x08u,
  VSM_STM_STATE_ENG_START_PRE       = 0x09u,
  VSM_STM_STATE_ENG_START_PRE_ROLL  = 0x0Au,
  VSM_STM_STATE_ENG_START           = 0x0Bu,
  VSM_STM_STATE_ENG_START_ROLL      = 0x0Cu,
  VSM_STM_STATE_WASH                = 0x0Du,
  VSM_STM_STATE_ERROR               = 0x0Eu,
  VSM_STM_STATE_INVALID             = 0x0Fu
} Vsm_OperatingStateType;

/* return type of energy states - all possible return values                  */
typedef enum
{
  VSM_STM_EN_GOOD                   = 0x00u,
  VSM_STM_EN_OK                     = 0x01u,
  VSM_STM_EN_SHORTAGE               = 0x02u,
  VSM_STM_EN_SEVERE_SHORTAGE        = 0x03u,
  VSM_STM_EN_INVALID                = 0x0Fu
} Vsm_EnergyStateType;

/* return type of comm. error lock states - all possible return values        */
typedef enum
{
  VSM_STM_CEL_UNLOCKED              = 0x00u,
  VSM_STM_CEL_LOCKED                = 0x01u,
  VSM_STM_CEL_INVALID               = 0x03u
} Vsm_CommunicationErrorLockType;

#else

/* controling variables for polling function                                  */
typedef enum
{
  VSM_RET_NOTHING_POLL              = 0x00u,
  VSM_RET_OPSTATE                   = 0x01u,
  VSM_RET_ENERGYSTATE               = 0x02u,
  VSM_RET_CEL                       = 0x03u
} Vsm_ReturnRequestedType;

#endif /* not VSM_ENABLE_RTE                                                  */


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/* initialised VSM state monitor                                              */
extern FUNC(void, VSM_PUBLIC_CODE) StmFse_Init(void);

/* main function of VSM state monitor                                         */
extern FUNC(void, VSM_PUBLIC_CODE) StmFse_Main(void);

/* following functions are not supported With RTE                             */
#ifndef VSM_ENABLE_RTE

   /* get current operational status        */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
               Vsm_GetState(Vsm_OperatingStateType *state );
   /* get energy status information message */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
               Vsm_GetEnergyState( Vsm_EnergyStateType *energyState );
   /* get state of communication error lock */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
               Vsm_GetCommunicationErrorLock(Vsm_CommunicationErrorLockType *comErrorLock);
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_OpStateRxNotification( void );
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_EnergyStateRxNotification( void );
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_CelRxNotification( void );
#else
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_OpStateRxNotification( void );
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_EnergyStateRxNotification( void );
   extern FUNC(void, RTE_APPL_CODE)
               Vsm_CelRxNotification( void );
#endif

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


#endif /* STM_H                                                               */

/*** End of file **************************************************************/
