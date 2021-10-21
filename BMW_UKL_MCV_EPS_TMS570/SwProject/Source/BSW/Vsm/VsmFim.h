/*******************************************************************************
**                                                                            **
**  SRC-MODULE: VsmFim.h                                                      **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : FIM (Function Inhibition Manager) as part modul of VSM Client **
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.1.1: 17.02.2011, thmi: CR70908:   Update to MISRA 2004
 *                                      Revise or comment deviations
 * V3.1.0: 10.02.2011, olgo: CR70908:   prevent Misra warnings
 * V3.0.0: 05.10.2009, hauf: CR70371:   removed SC6 variants and added RTE switch
 * V2.0.0: 11.11.2008, olgo: BSCVSM-90: CR70027: VSM: Rename FIM functions to
 *                                      avoid name clash with AUTOSAR FIM
 * V1.0.0: 15.07.2008, olgo: BSCVSM-74: Code Formatting
 *         03.04.2008, olgo: BSCVSM-42: Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39: Vsm may not include MemMap_Vsm.h but
 *                                      only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35: VSM with activated RTE collides with
 *                                      other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-12: RTE integration
 *                           BSCVSM-25: Includes und API-Mapping
 *         19.12.2007, olgo: BSCVSM-14: Vsm_ReInit is declared for all version,
 *                                      but shall only be available for
                                        VSM Version = SC6
 *         29.11.2007, olgo: taken from SC6 V3.1.0 and ported to SC7
 */


#ifndef VSM_FIM_H
#define VSM_FIM_H

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

#define FIM_MAJOR_VERSION   4u
#define FIM_MINOR_VERSION   1u
#define FIM_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* number of different opeartion modes                                        */
#define VSM_FIM_NR_OF_OP_MODES                    4
/* number of different energy states                                          */
#define VSM_FIM_NR_OF_EN_STATES                   5

/* all operational modes, symbolised by one according bit */
#define VSM_FIM_MODE_NORMAL_ARR                   0x01
#define VSM_FIM_MODE_ASSEMBLY_ARR                 0x02
#define VSM_FIM_MODE_TRANSPORT_ARR                0x04
#define VSM_FIM_MODE_BMW_FLASH_ARR                0x08

/* all fim specific operation states = index of 2. dimension of the           */
/* Vsm_FimFuncOpStateEnStateBitArray -> therefore consecutive numbering       */
#define VSM_FIM_STATE_INIT                        0x00
#define VSM_FIM_STATE_STANDBY                     0x01
#define VSM_FIM_STATE_BASICOP                     0x02
#define VSM_FIM_STATE_IGNITION                    0x03
#define VSM_FIM_STATE_DRIVE                       0x04
#define VSM_FIM_STATE_ENG_START                   0x05
#define VSM_FIM_STATE_ERROR                       0x06
#define VSM_FIM_STATE_INVALID                     0x07

/* all energy states, symbolised by one according bit                         */
#define VSM_FIM_EN_GOOD_ARR                       0x01
#define VSM_FIM_EN_OK_ARR                         0x02
#define VSM_FIM_EN_SHORTAGE_ARR                   0x04
#define VSM_FIM_EN_SEVERE_SHORTAGE_ARR            0x08
#define VSM_FIM_EN_INVALID_ARR                    0x10


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#ifndef VSM_ENABLE_RTE
   /* return type of the inhibition check - all possible return values           */
   typedef enum
   {
     VSM_FIM_APP_ENABLED               = 0x00u,
     VSM_FIM_APP_INHIBITED             = 0x01u,
     VSM_FIM_APP_INVALID               = 0xFFu
   } Vsm_InhibitionStatusType;
#endif


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

#ifndef VSM_ENABLE_RTE
   /* Interface for the application to query their lock status                */
   extern FUNC(Std_ReturnType, VSM_PUBLIC_CODE)
             Vsm_IsInhibited(
                              uint16                    functionId,
                              Vsm_InhibitionStatusType *inhibitionStatus
                            );
#endif

/* initialised VSM FIM                                                        */
extern FUNC(void, VSM_PUBLIC_CODE) VsmFim_Init(void);

/* Information from OMC about VSM mode change                                 */
extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeChangeEvent(uint8 newMode);

/* Information from FIM about VSM state change                                */
extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyStateChangeEvent(uint8 newOpState);

/* Information from FIM about VSM energystate change                          */
extern FUNC(void, VSM_PUBLIC_CODE)
            Vsm_NotifyEnergyStateChangeEvent(uint8 newEnState);

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


#endif /* VSM_FIM_H */

/*** End of file **************************************************************/
