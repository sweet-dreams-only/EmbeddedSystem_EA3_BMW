/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler
 *********************************************************************************************************************/

#ifndef SCHM_H
# define SCHM_H

# include "Std_Types.h"
# include "SchM_Cfg.h"

/* AUTOSAR BSW Scheduler version */
/* ##V_CFG_MANAGEMENT ##CQProject : SysService_AsrSchM CQComponent : Implementation    */
# define SYSSERVICE_ASRSCHM_VERSION          (0x0300u) /* BCD coded version number         */
# define SYSSERVICE_ASRSCHM_RELEASE_VERSION  (0x02u)   /* BCD coded release version number */

/**
 * Define vendor and module ID
 */
# define SCHM_VENDOR_ID         (30u) /* HIS Vendor ID for Vector                */
# define SCHM_MODULE_ID        (130u) /* SchM Module ID according to BSW Modules */

/**
 * Define AUTOSAR version
 */
# define SCHM_AR_MAJOR_VERSION  (1u)
# define SCHM_AR_MINOR_VERSION  (1u)
# define SCHM_AR_PATCH_VERSION  (0u)

/**
 * Define version for header and source file consistency
 */
# define SCHM_SW_MAJOR_VERSION  ((SYSSERVICE_ASRSCHM_VERSION & 0xFF00) >> 8)
# define SCHM_SW_MINOR_VERSION  (SYSSERVICE_ASRSCHM_VERSION & 0x00FF)
# define SCHM_SW_PATCH_VERSION  (SYSSERVICE_ASRSCHM_RELEASE_VERSION)

/**
 * Define SchM InitState
 */
# define SCHM_UNINIT (0u)
# define SCHM_INIT   (1u)


/**
 * Define error report for DET
 */
/*API IDs*/
# define SCHM_APIID_SCHM_INIT                  (0x00u)
# define SCHM_APIID_SCHM_DEINIT                (0x01u)
# define SCHM_APIID_SCHM_GETVERSIONINFO        (0x02u)
# define SCHM_APIID_SCHM_ENTER                 (0x03u)
# define SCHM_APIID_SCHM_EXIT                  (0x04u)
# define SCHM_APIID_SCHM_ACTIVATEMAINFUNCTION  (0x05u)
# define SCHM_APIID_SCHM_CANCELMAINFUNCTION    (0x06u)

# define SCHM_APIID_SCHM_100MS_TASK10           (0x10)

# define SCHM_APIID_SCHM_TASK           (0x11)

# define SCHM_APIID_SCHM_TASK2           (0x12)


/* Det Error IDs*/
# define SCHM_E_PARAM_CONFIG                   (0x01u)
# define SCHM_E_NOT_INIT                       (0x02u)    /*API call befor Init*/

/* API Return Codes */
# define SCHM_E_OK       ((SchM_ReturnType)0x00)
# define SCHM_E_LIMIT    ((SchM_ReturnType)0x04)
# define SCHM_E_NOFUNC   ((SchM_ReturnType)0x05)
# define SCHM_E_STATE    ((SchM_ReturnType)0x07)

/* Exclusive Area Defines */
# define SCHM_EA_SUSPENDALLINTERRUPTS (0u)
# define SCHM_EA_SUSPENDOSINTERRUPTS  (1u)
# define SCHM_EA_DISABLED             (2u)

# define SCHM_ENTER_EXCLUSIVE(ExclusiveArea)          \
         SuspendAllInterrupts()

# define SCHM_EXIT_EXCLUSIVE(ExclusiveArea)          \
         ResumeAllInterrupts()

/**********************************************************************************************************************
 * Global functions
 *********************************************************************************************************************/
# define SCHM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

FUNC(void, SCHM_CODE) SchM_Init( void );

/* Initialisation of global variables, call once before any other SchM function */
FUNC(void, SCHM_CODE) SchM_InitMemory( void );

FUNC(void, SCHM_CODE) SchM_Deinit( void );

FUNC(void, SCHM_CODE) SchM_SyncTasks( void );

FUNC(void, SCHM_CODE) SchM_GetVersionInfo( Std_VersionInfoType *versioninfo );

# define SCHM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

#endif /* SCHM_H */

