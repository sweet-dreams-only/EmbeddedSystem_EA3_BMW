/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Fnm.h                                                         **
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
 * V1.1.2: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V1.1.1: 10.02.2011, olgo: CR70908: prevent Misra warnings
 * V1.1.0: 20.10.2010, olgo: CR70831: VSM FCT id parameter is only for
 *                                    ASR 3.0 with FN
 *         15.09.2010, olgo: CR70775: Debouncing of additional NM-messages
 *                                    during active wakeup
 * V1.0.1: 05.06.2010, olgo: CR70708: direct include of CanNm.h in Fnm.h also
 *                                    if only FlexRay is active (#RT24491)
 * V1.0.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 *         22.11.2009, olgo: first version
 */


#ifndef FNM_H
#define FNM_H

#if defined (VSM_VERSION_BAC3x)         /* sub module FNM only used in BAC3.0 */

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

#include <ComM.h>                               /* Communication Manager      */

#if defined ( USE_VSM_WITH_CAN )
   #if ( NUM_CAN_BUSSES_WITH_NM > 0 )
      #include <CanNm.h>                        /* CAN network management     */
   #endif /* NUM_CAN_BUSSES_WITH_NM > 0                                       */
#endif /* USE_VSM_WITH_CAN                                                    */


/*******************************************************************************
**                      Version Control                                       **
*******************************************************************************/

#define FNM_MAJOR_VERSION   4u
#define FNM_MINOR_VERSION   1u
#define FNM_PATCH_VERSION   5u


/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define VSM_NM_FULL       0
#define VSM_NM_LIGHT      1
#define VSM_NM_NONE       2
#define VSM_NM_PASSIVE    3


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

typedef struct
{
   uint8  reptitions;
   uint32 debouncingtime;
} ControlReqBusSyncType;


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

extern ControlReqBusSyncType ControlReqBusSync[VSM_COMM_NUM_CHANNELS];


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

                                         /* Initalizes the FNM                */
extern FUNC(void, VSM_PUBLIC_CODE) Fnm_Init(void);
                                         /* Main function of the FNM          */
extern FUNC(void, VSM_PUBLIC_CODE) Fnm_Main(void);
                                         /* Triggers the three times call of  */
                                         /* CanNm_RequestBusSynchronization() */
extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_TriggerCanNmBusSynchronization
                                                (
	                                                NetworkHandleType Channel
                                                );
#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_VERSION_BAC3x                                                   */

#endif /* FNM_H                                                               */

/*** End of file **************************************************************/
