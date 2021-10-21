/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Wur.h                                                         **
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
** dobr         Dominik Brader             EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.3: 17.02.2011, thmi: CR70908:   Update to MISRA 2004
 *                                      Revise or comment deviations
 * V2.1.2: 10.02.2011, olgo: CR70908:    prevent Misra warnings
 * V2.1.1: 23.06.2010, olgo: BSCVSM-179: Mismatch of internal vs. external
 *                                       linkage with Wur_internalWakeupType
 * V2.1.0: 26.02.2010, mani: CR70415:    Module extension to 3.0
 * V2.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE
 *                                       switch
 * V1.1.1: 10.08.2009, dobr: BSCVSM-123: replaced 'ON/OFF' with 'STD_ON/STD_OFF'
 * V1.1.0: 08.05.2009, olgo: BSCVSM-113: CR70212: WUR: Use parameter wakeupType
 *                                       in Vsm_CallWakeupEvent()
 * V1.1.0: 29.10.2008, olgo: BSCVSM-91:  Porting SC6 CR's to BAC2.1: CR60912,
 *                                       CR60948 - additional wakeup types,
 *                                       and additional from Spec
 * V1.0.0: 15.07.2008, olgo: BSCVSM-74:  Code Formatting
 *         04.06.2008, olgo: BSCVSM-56:  make VSM_MAX_NUM_WAKEUPS configureable
 *         03.06.2008, olgo: BSCVSM-47:  Bug in preprocessor
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39:  Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         29.01.2008, olgo: BSCVSM-24:  Timeouts im STM
 *         16.01.2008, olgo: BSCVSM-12:  RTE integration
 *                           BSCVSM-25:  Includes und API-Mapping
 *         19.12.2007, olgo: BSCVSM-12:  RTE integration
 *         27.11.2007, olgo: taken from SC6 V4.0.0 and ported to SC7
 */


#ifndef WUR_H
#define WUR_H

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

#include <ComM.h>                      /* Autosar Com Manager                 */
#include <Com.h>                       /* Include AutoSar Comunication module */


/*******************************************************************************
**                      Version Control                                       **
*******************************************************************************/

#define WUR_MAJOR_VERSION   4u
#define WUR_MINOR_VERSION   1u
#define WUR_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* delay after which a wakeup registration message is sent to the master      */
#define VSM_TMO_WAIT_SEND_WAKEUP_REGISTRATION   2000        /* in ms (0..2550)*/

/* minimal value of Klemme 15 signal, that signalize an active Klemme 15      */
#define VSM_KLEMME_15_ON_MIN_VALUE              0x09u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* return type with the possible wakeup reasons                               */
#ifndef VSM_ENABLE_RTE
   typedef enum
   {
      VSM_WACA_INVALID             = 0x3Fu,  /* invalid wakeup reason         */
      VSM_WACA_RESET               = 0x00u,  /* reset                         */
      VSM_WACA_DWA                 = 0x01u,  /* theft alarm system            */
      VSM_WACA_RSHT                = 0x02u,  /* residual heat                 */
      VSM_WACA_DETECT_CO2          = 0x03u,  /* CO2 detection                 */
      VSM_WACA_SW_EJECT            = 0x04u,  /* eject button                  */
      VSM_WACA_SWITCH_OFF_CLAMP_VA = 0x05u,  /* switch off clamp va           */
      VSM_WACA_EXTERIOR_MIRROR     = 0x06u,  /* exterior mirror               */
      VSM_WACA_REMOTE_SERVICES     = 0x07u,  /* remote_services               */
      VSM_WACA_E_CALL              = 0x08u,  /* e-call                        */
      VSM_WACA_DSW_DRD             = 0x10u,  /* door switch front left        */
      VSM_WACA_DSW_PSD             = 0x11u,  /* door switch front right       */
      VSM_WACA_DSW_DRDR            = 0x12u,  /* door switch rear left         */
      VSM_WACA_DSW_PSDR            = 0x13u,  /* door switch rear right        */
      VSM_WACA_SW_DRD              = 0x14u,  /* switch driver door (CA)       */
      VSM_WACA_SW_PSD              = 0x15u,  /* switch passenger door (CA)    */
      VSM_WACA_SW_BTL_INT_1        = 0x16u,  /* button open boot lid interior */
      VSM_WACA_SW_BTL_INT          = 0x17u,  /* button door open boot lid int */
      VSM_WACA_SW_BTL_EXT          = 0x18u,  /* button door open boot lid ext */
      VSM_WACA_CT_BTL              = 0x19u,  /* boot lid status               */
      VSM_WACA_PUBU_RSCR           = 0x1Au,  /* push button rear screen       */
      VSM_WACA_CT_BON              = 0x1Bu,  /* contact bonnet                */
      VSM_WACA_ULOK_DRD            = 0x1Cu,  /* unlock driver door            */
      VSM_WACA_LOK_DRD             = 0x1Du,  /* lock driver door              */
      VSM_WACA_SHORT_CIRCUIT_30B   = 0x1Eu,  /* Short circuit clamp 30B       */
      VSM_WACA_PUBU_STA_STOP_A     = 0x20u,  /* engine start stop button A    */
      VSM_WACA_PUBU_STA_STOP_B     = 0x21u,  /* engine start stop button B    */
      VSM_WACA_SENS_HALL_EJECT     = 0x22u,  /* hall sensor eject             */
      VSM_WACA_PUBU_CLSY           = 0x23u,  /* centre lock / unlock          */
      VSM_WACA_P_LOK               = 0x24u,  /* automatic park position       */
      VSM_WACA_SW_POLI             = 0x25u,  /* light switch on (redundant)   */
      VSM_WACA_SW_HAZW             = 0x26u,  /* switch hazard warning         */
      VSM_WACA_COLS_IDC_LH         = 0x27u,  /* column stalks indicate        */
                                             /* direction left hand           */
      VSM_WACA_COLS_IDC_RH         = 0x28u,  /* column stalks indicate        */
                                             /* direction right hand          */
      VSM_WACA_COLS_HLIF           = 0x29u,  /* column stalks headlight flash */
      VSM_WACA_SW_ITLI             = 0x2Au,  /* switch interior lighting      */
      VSM_WACA_KL_15               = 0x2Bu,  /* Klemme 15                     */
      VSM_WACA_PUBU_EMF            = 0x2Cu,  /* push button EMF               */
      VSM_WACA_PUBU_ENT            = 0x2Du,  /* push button entertainment     */
      VSM_WACA_SW_AD_STCO          = 0x2Eu,  /* steering column mod button SZL*/
      VSM_WACA_AIR_SPRING          = 0x2Fu,  /* level ctrl system-air spring  */
      VSM_WACA_RMC                 = 0x30u,  /* remote control                */
      VSM_WACA_TELEMATIC           = 0x31u,  /* telematic                     */
      VSM_WACA_SW_HOTM             = 0x32u,  /* switch hotel                  */
      VSM_WACA_SENS_BATT           = 0x33u,  /* battery sensor, via LIN       */
      VSM_WACA_PHTR                = 0x34u,  /* timer expiration park heat    */
      VSM_WACA_COMP_TEMP_EX        = 0x35u,  /* computing coolant temperature */
      VSM_WACA_KL15WUP             = 0x36u,  /* clamp15 wakeup-line           */
      VSM_WACA_SW_DRDR             = 0x37u,  /* switch unlock rear driver     */
                                             /* door (CA) CAS                 */
      VSM_WACA_SW_PSDR             = 0x38u,  /* switch unlock rear passenger  */
                                             /* door (CA) CAS                 */
      VSM_WACA_SW_DRD_CAP          = 0x39u,  /* switch unlock driver door     */
                                             /* capacitive (CA) CAS           */
      VSM_WACA_SW_PSD_CAP          = 0x3Au,  /* switch unlock passenger door  */
                                             /* capacitive (CA) CAS           */
      VSM_WACA_SW_DRDR_CAP         = 0x3Bu,  /* switch unlock rear driver     */
                                             /* door capacitive (CA) CAS      */
      VSM_WACA_SW_PSDR_CAP         = 0x3Cu,  /* switch unlock rear passenger  */
                                             /* capacitive (CA) CAS           */
      VSM_WACA_SW_STLI             = 0x3Du,  /* (stop light buttonr) CAS      */
      VSM_WACA_SW_CLT              = 0x3Eu   /* clutch button CAS             */
   } Vsm_WakeupReasonType;
#endif

#if defined (VSM_VERSION_BAC3x)
   typedef struct
   {
      ComM_ModeType CurrentWakeup;
      ComM_ModeType LastWakeup;
   }Wur_WakeupType;
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define VSM_START_SEC_VAR_8BIT
#include <MemMap.h>

#if ( VSM_TEST_ENABLE == STD_ON )
   extern VAR(uint8, VSM_VAR) Wur_internalWakeupType;
                                                    /* indicates internal     */
                                                    /* wakeup types           */
   extern VAR(uint8, VSM_VAR) Wur_internalWakeupOccurrenceCounter;
                                                    /* for messurement of     */
                                                    /* Occurrence             */
#endif /* VSM_TEST_ENABLE == STD_ON                                           */

#define VSM_STOP_SEC_VAR_8BIT
#include <MemMap.h>

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#if ( VSM_TEST_ENABLE == STD_ON )
                                                    /* indicates active bus   */
                                                    /* communication          */
   extern VAR(boolean, VSM_VAR) activeWakeupIndication;
                                                    /* indicates passive bus  */
                                                    /* communication          */
   extern VAR(boolean, VSM_VAR) passivWakeupIndication;
#endif /* VSM_TEST_ENABLE == STD_ON                                           */

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/* WUR initialization                                                         */
extern FUNC(void, VSM_PUBLIC_CODE) Wur_Init(void);

/* WUR scheduling                                                             */
extern FUNC(void, VSM_PUBLIC_CODE) Wur_Main(void);

#ifndef BOOTLOADER

#if defined (VSM_VERSION_BAC21)
   /* Notification from ComM that at least one bus is awake now               */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
             Vsm_CallWakeupEvent(ComM_WakeupType wakeupType );

   /* Notification from ComM that all busses have entered the sleep state     */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
             Vsm_CallGlobalSleepEvent(void);
#endif /* defined (VSM_VERSION_BAC21)                                         */

#if defined (VSM_VERSION_BAC3x)
   /* notification for WUR for passive wakeup                                 */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
             Vsm_PassiveWakeupIndication(void);
#endif /* defined (VSM_VERSION_BAC3x)                                         */

#endif

#ifndef VSM_ENABLE_RTE

   /* application interface to get system wakeup reason                       */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
            Vsm_GetWakeupReason( Vsm_WakeupReasonType *wakeupReason );

   /* application interface to set system wakeup reason                       */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
            Vsm_SetWakeupReason(
                                 Vsm_WakeupReasonType wakeupReason,
                                 boolean *maxWunExceeded
                               );

#endif /* VSM_ENABLE_RTE                                                      */

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


#endif /* WUR_H */

/*** End of file **************************************************************/
