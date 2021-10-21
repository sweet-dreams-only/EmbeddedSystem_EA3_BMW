/*******************************************************************************
**                                                                            **
**  SRC-MODULE: ComControl.h                                                  **
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
 * V1.1.0: 08.02.2011, olgo: CR70864: VSM shall support ECUs without NM
 * V1.0.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 *         22.11.2009, olgo: first version
 */


#ifndef COMCONTROL_H
#define COMCONTROL_H

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

#if defined (VSM_VERSION_BAC3x)              /* sub module ComControl only    */
                                             /* used in BAC3.0                */

#include <Com.h>                             /* Autosar Com Module            */

#ifdef COMCONTROL_NM_HANDLING
   #if (COMCONTROL_NM_HANDLING == STD_ON)
      #include <Nm.h>                        /* Autosar Nm Module             */
   #endif /* COMCONTROL_NM_HANDLING == STD_ON                                 */
#endif

/*******************************************************************************
**                      Version Control                                       **
*******************************************************************************/

#define COMCONTROL_MAJOR_VERSION   4u
#define COMCONTROL_MINOR_VERSION   1u
#define COMCONTROL_PATCH_VERSION   5u


/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/* controlTypes for Vsm_CommunicationControl */
#define COMM_DIAG_NORMAL_COMM_MSG           0x01u
#define COMM_DIAG_NM_COMM_MSG               0x02u
#define COMM_DIAG_NORMAL_AND_NM_COMM_MSG    0x03u

/* modes for Vsm_CommunicationControl */
#define COMM_DIAG_ENABLE_RX_AND_TX          0x00u
#define COMM_DIAG_ENABLE_RX_AND_DISABLE_TX  0x01u
#define COMM_DIAG_DISABLE_RX_AND_ENABLE_TX  0x02u
#define COMM_DIAG_DISABLE_RX_AND_TX         0x03u

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

                                         /* initialised VSM ComControl        */
extern FUNC(void, VSM_PUBLIC_CODE) ComControl_Init(void);
                                         /* main function of VSM ComControl   */
extern FUNC(void, VSM_PUBLIC_CODE) ComControl_Main(void);
                                         /* Sets the new CommunicationControl */
extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE) Vsm_CommunicationControl
                                      (
                                        uint8 mode,
                                        uint8 controlType
                                      );
#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_VERSION_BAC3x                                                   */

#endif /* COMCONTROL_H                                                        */

/*** End of file **************************************************************/
