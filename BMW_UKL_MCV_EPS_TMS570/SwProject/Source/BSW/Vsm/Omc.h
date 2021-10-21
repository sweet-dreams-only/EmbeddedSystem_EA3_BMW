/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Omc.h                                                         **
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
** olho         Oliver Hoeft               EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.0.2: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V3.0.1: 10.02.2011, olgo: CR70908: prevent Misra warnings
 * V3.0.0: 05.10.2009, hauf: CR70371: removed SC6 variants and added RTE switch
 * V2.0.0: 16.06.2009, olho  BSCVSM-117: CR70232: Changed return type to
 *                           Std_ReturnType for Vsm_DiagModeExtensionChange &
 *                           Vsm_DiagModeChange
 * V1.0.0: 15.07.2008, olgo: BSCVSM-74: Code Formatting
 *         03.04.2008, olgo: BSCVSM-42: Implementation of the review results
 *         31.01.2008, olgo: BSCVSM-35: VSM with activated RTE collides with
 *                           other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-12: RTE integration
 *                           BSCVSM-25: Includes und API-Mapping
 *         19.12.2007, olgo: BSCVSM-12: RTE integration
 *         27.11.2007, olgo: taken from SC6 V3.1.0 and ported to SC7
 */


#ifndef OMC_H
#define OMC_H

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

#define OMC_MAJOR_VERSION   4u
#define OMC_MINOR_VERSION   1u
#define OMC_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#ifndef VSM_ENABLE_RTE

/* return type of operation modes - all possible return values */
typedef enum
{
   VSM_MM_MODE_NORMAL     = 0x00u,
   VSM_MM_MODE_ASSEMBLY   = 0x01u,
   VSM_MM_MODE_TRANSPORT  = 0x02u,
   VSM_MM_MODE_BMW_FLASH  = 0x03u
} Vsm_OperatingModeType;

/* return type of extended operation modes - all possible return values       */
typedef enum
{
   VSM_MM_MODE_EXTENSION_NORMAL        = 0x00u,
   VSM_MM_MODE_EXTENSION_1             = 0x01u,
   VSM_MM_MODE_EXTENSION_2             = 0x02u,
   VSM_MM_MODE_EXTENSION_3             = 0x03u,
   VSM_MM_MODE_EXTENSION_4             = 0x04u,
   VSM_MM_MODE_EXTENSION_5             = 0x05u,
   VSM_MM_MODE_EXTENSION_6             = 0x06u,
   VSM_MM_MODE_EXTENSION_7             = 0x07u,
   VSM_MM_MODE_EXTENSION_8             = 0x08u,
   VSM_MM_MODE_EXTENSION_9             = 0x09u,
   VSM_MM_MODE_EXTENSION_10            = 0x0Au,
   VSM_MM_MODE_EXTENSION_11            = 0x0Bu,
   VSM_MM_MODE_EXTENSION_12            = 0x0Cu,
   VSM_MM_MODE_EXTENSION_13            = 0x0Du,
   VSM_MM_MODE_EXTENSION_14            = 0x0Eu,
   VSM_MM_MODE_EXTENSION_SAVE_ENERGY   = 0x0Fu
} Vsm_OperatingModeExtensionType;

#endif /* VSM_ENABLE_RTE                                                      */


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

                            /* initialised VSM operational mode control       */
extern FUNC( void, VSM_PUBLIC_CODE ) Omc_Init( void );

#ifndef VSM_ENABLE_RTE
                            /* get current operational mode                   */
   extern FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
             Vsm_GetMode( Vsm_OperatingModeType *mode );

                            /* get current extended op-mode                   */
   extern FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
          Vsm_GetModeExtension( Vsm_OperatingModeExtensionType *modeExtension );
#endif

                            /* callback from CDC                              */
extern FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
             Vsm_DiagModeChange(Vsm_OperatingModeType mode);

                            /* callback from CDC                              */
extern FUNC( Std_ReturnType, VSM_PUBLIC_CODE )
             Vsm_DiagModeExtensionChange
                               (Vsm_OperatingModeExtensionType extendedMode);

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


#endif /* OMC_H */

/*** End of file **************************************************************/
