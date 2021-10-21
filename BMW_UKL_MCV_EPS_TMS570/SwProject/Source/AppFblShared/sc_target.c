/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_target.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Implements data and function definitions that are used both   **
**              by the bootloader and the application.                        **
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
** sc           Juergen Scherg             EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** raka         Rainer Kaufmann            EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.4.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V3.4.0: 07.09.2010,   ft: CR70748: added missing compiler abstraction
 * V3.3.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V3.3.0: 07.07.2009, dabu: CR61622: added functions to set & get the BootMode
 * V3.2.0: 03.06.2009, hauf: CR61622: added function RomAccessExceptionHandler
 * V3.1.0: 15.08.2008, masc: CR61431: changed comment
 * V3.0.0: 05.04.2006, hauf: renamed section definitions
 *                           according to BMW programming guidelines
 *         27.02.2006, ke  : replaced setpragma.h with MemMap.h
 *                     miwe: unused function 'ScUnexpectedFault' removed
 * V2.1.0: 31.10.2005, miwe: CR60215: removed compiler warnings
 * V2.01 : 21.09.2005, olgo: 'BootStatus' added
 * V2.00 : 27.06.2005, hauf: renamed 'templ_src_mcfg.h' to 'Templ_Src_Cfg.h'
 * V1.08 : 20.04.2005, miwe: unnecessary includes removed
 * V1.07 : 10.03.2005, hauf: moved function 'WaitOnIdle' to bootloader/source
 *                           changed author list
 * V1.06 : 28.09.2004, hauf: updated file header
 * V1.06 : 21.09.2004, raka: sync revision control history
 * V1.05 : 08.05.2004, ke  : move 'EcuReset' to 'sc_target_arch'
 * V1.04 : 08.04.2004, ke  : change loop counter 'i' type to 'uint32'
 * V1.03 : 06.04.2004, ke  : add phoenix support, due to lag of a WatchDog
 * V1.02 : 23.03.2004, ke  : add functions 'WaitOnIdle' and 'ScUnexpectedFault'
 * V1.01 : 18.03.2004, sc  : added comments
 * V1.00 : 11.11.2003, sc  : initial version
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>      /* AUTOSAR Standard Types                   */
#include "sc_target.h"      /* include own header file                        */
#include "sc_target_arch.h" /* include the 'sc_target' defines which are HW   */
                            /* dependant                                      */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define BM_START_SEC_VAR_NOINIT_ISR_DISPATCH
#include "MemMap.h"

                                 /* contains Flag to dispatch interrupt table */
IsrDispatchType IsrDispatch;

#define BM_STOP_SEC_VAR_NOINIT_ISR_DISPATCH

#define BM_START_SEC_VAR_NOINIT_BOOT_STATUS
#include "MemMap.h"

                                            /* contains boot mode and         */
                                            /* ECC/CRC error flags            */
#ifdef BAC
   VAR(BootStatusType, COMMON_VAR) BootStatus;
#else
BootStatusType BootStatus;
#endif /* Defined BAC */

#define BM_STOP_SEC_VAR_NOINIT_BOOT_STATUS
#include "MemMap.h"


#define BM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : RomAccessExceptionHandler                                  **
**                                                                            **
** DESCRIPTION   : On some platforms this function is called if a flash ROM   **
**                 access exception occured. If the hardware does not         **
**                 support this SC_HANDLE_ECC must not be enabled.            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** PARAMETER     : codeAddress: Code address where the ROM data was accessed  **
**                 dataAddress: ROM data address which can not be accessed    **
**                                                                            **
** RETURN        : Anything except zero will trigger a reset                  **
**                                                                            **
** REMARKS       : This function runs in interrupt context                    **
**                                                                            **
*******************************************************************************/
#if ( SC_HANDLE_ECC == STD_ON )
   #ifdef BAC
      FUNC(uint32, COMMON_CODE) RomAccessExceptionHandler
                                (
							       VAR(uint32, COMMON_APPL_DATA) codeAddress,
								   VAR(uint32, COMMON_APPL_DATA) dataAddress
							    )
   #else
uint32 RomAccessExceptionHandler( uint32 codeAddress, uint32 dataAddress )
   #endif /* Defined BAC */
{
#ifdef BOOTMANAGER
                                            /* during startup the BootManager */
                                            /* handles ECC errors => no reset */
   return 0;
#else
                                            /* reset ECU                      */
   return 1;
#endif
}
#endif /* SC_HANDLE_ECC == ON                                                 */


#if defined ( BOOTMANAGER )

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetBootMode                                                **
**                                                                            **
** DESCRIPTION   : This function reads the actual BootMode from the stored    **
**                 BootStatus and compares it with the Bootloader-BootMode    **
**                 pattern and returns whether Application or Bootloader is   **
**                 set.                                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** RETURN        : actBootMode: actual BootMode that have been set            **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
   FUNC(BmBootModeType, COMMON_CODE) GetBootMode( void )
#else
   BmBootModeType GetBootMode( void )
#endif /* Defined BAC */
{
   P2VAR(uint8, AUTOMATIC, AUTOMATIC)                  startup_flag;
   P2CONST(uint8, AUTOMATIC, SHAREDBOOTROMDATA_CONST)  bl_flag;
   uint8 i;
   BmBootModeType actBootMode = BM_BOOT_MODE_BOOTLOADER;

   startup_flag = BootStatus.BootMode;
   bl_flag      = sharedBootROMData.BootModeBootloader;
   for (i=0; (i<sizeof(BootStatus.BootMode)) && (BM_BOOT_MODE_BOOTLOADER == actBootMode); i++)
   {
     if (*startup_flag != *bl_flag) {
       actBootMode = BM_BOOT_MODE_APPLICATION;
     }

     startup_flag++;
     bl_flag++;
   }

   return actBootMode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : SetBootMode                                                **
**                                                                            **
** DESCRIPTION   : This function set the new BootMode in the BootStatus that  **
**                 will be stored permanently later.                          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** PARAMETER     : newBootMode: new BootMode that have to be set              **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
   FUNC(void, COMMON_CODE) SetBootMode
                           ( 
						      VAR(BmBootModeType, COMMON_APPL_DATA) newBootMode 
						   )
#else
   void SetBootMode( BmBootModeType newBootMode )
#endif /* Defined BAC */
{
   P2VAR(uint8, AUTOMATIC, AUTOMATIC)                  startup_flag;
   P2CONST(uint8, AUTOMATIC, SHAREDBOOTROMDATA_CONST)  bl_flag;
   uint8 i;

   startup_flag = BootStatus.BootMode;
   bl_flag      = sharedBootROMData.BootModeBootloader;
   if ( newBootMode == BM_BOOT_MODE_BOOTLOADER )
   {
      /* set BootMode to bootloader                                           */
      for (i=0; i<sizeof(BootStatus.BootMode); i++)
      {
        *startup_flag = *bl_flag;
        startup_flag++;
        bl_flag++;
      }
   }
   else
   {
      /* set BootMode to application                                          */
      for (i=0; i<BOOT_MODE_LENGTH; i++)
      {
        *startup_flag = (uint8)BOOT_MODE_APPLICATION;
        startup_flag++;
      }

   }

}

#endif /* BOOTMANAGER */

#define BM_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
