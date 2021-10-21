/*******************************************************************************
**                                                                            **
**  SRC-MODULE: BootManager_Cfg.h                                             **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Bootmanager Configuration File                                **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** olgo         Oliver Gorisch             EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.0: 07.07.2009, dabu: CR61622: mapping of external API
 * V1.1.0: 03.06.2009, hauf: CR61622: added BM_MAX_NUMBER_OF_SWES
 *                                    added BM_CLEAR_HARDWARE_ECC_ERROR_FLAG()
 *                                    corrected MISRA warnings
 * V1.0.1: 05.11.2008, miwe: CR61489: extended BootMode flag to 64 bit
 * V1.0.0: 02.09.2008, olgo: CR61431: initial version
 */


#ifndef  BOOTMANAGER_CFG_H
#define  BOOTMANAGER_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */



/*******************************************************************************
**                      Type Definitions                                      **
*******************************************************************************/

typedef enum                /* type for actual BootMode that have to be start */
{
   BM_BOOT_MODE_BOOTLOADER,
   BM_BOOT_MODE_APPLICATION
} BmBootModeType;


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * Maximum number of supported SWEs by the bootmanager (reserved)
 */
#define BM_MAX_NUMBER_OF_SWES                                              0x10u

/*
 * Use each RAM_ADDRESS_STEP byte for RAM ECC check
 * This should be equal to the micropage size in RAM
 */
#define BM_RAM_ADDRESS_STEP                                                0x08u

/*
 * Should be equal to the micropage size:
 * The value will be incremented by 1 by the BootManager (max 256 aka 255)
 */
#define BM_CRC_CALC_BLOCK_STEP_TABLE                                           \
      (uint8)(0x008u - 0x01u),                                                 \
      (uint8)(0x008u - 0x01u),                                                 \
      (uint8)(0x008u - 0x01u),                                                 \
      (uint8)(0x010u - 0x01u),                                                 \
      (uint8)(0x030u - 0x01u),                                                 \
      (uint8)(0x048u - 0x01u),                                                 \
      (uint8)(0x068u - 0x01u),                                                 \
      (uint8)(0x070u - 0x01u),                                                 \
      (uint8)(0x090u - 0x01u),                                                 \
      (uint8)(0x100u - 0x01u)

/*
 * Number of elements in BM_CRC_CALC_BLOCK_STEP_TABLE
 */
#define BM_CRC_CALC_BLOCK_STEP_TABLE_SIZE                                 0x000Au

/*
 * Number of blocks (bytes) that are checked in one Crc_CalculateCRC32 call
 */
#define BM_CRC_CALC_BLOCK_LENGTH                                          0x01u

/* checks if ECU reset reason was not a 'power on reset' */
#define BM_START_IS_WARM_START()  (TRUE)

/*
 * clear the hardware ECC error flag
 */

#endif /* BOOTMANAGER_CFG_H                                                   */

/*** End of file **************************************************************/
