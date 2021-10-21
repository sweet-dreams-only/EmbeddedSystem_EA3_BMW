/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vctr Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Bac_MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a BAC compliant extension of the MemMap.h
 *                Here all memory sections are defined, wich are used by both Application and Bootloader.
 *
 *                NO OTHER FILE THAN MEMMAP.H IS ALLOWED TO INCLUDE THIS FILE!!!
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Matthias Gette                Get           Vctr Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2009-03-02  Get                   Initial creation
 *********************************************************************************************************************/

/**************************************************************************************************************************
 * Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#8     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Const section for bootloader's sharedBootROMData table */
#if defined  (BL_START_SEC_CONST_SHARED_DATA)
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (sharedBootROMData, ".BLSharedData")
    #undef  BL_START_SEC_CONST_SHARED_DATA
    #undef  MEMMAP_ERROR
#endif

/* special section for crypto jumptable (shared) */
#if defined (CRYPTO_START_SEC_JUMPTABLE_CONST_UNSPECIFIED)
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Crypto_JumpTable, ".CCRYPJUMPT")
    #undef  CRYPTO_START_SEC_JUMPTABLE_CONST_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's SweBootTable table */
#ifdef BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (SweBootTable, ".BOOTSWEDESC")
    #undef  BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's BootFlashStatus table */
#ifdef BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (BootFlashStatus, ".BOOTSWESTAT")
    #undef  BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe1Table table */
#ifdef APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe1Table, ".SWE1DESC")
    #undef  APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe1FlashStatus table */
#ifdef APPL_START_SEC_CONST_SWE1_FLASH_STATUS
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe1FlashStatus, ".SWE1STAT")
    #undef  APPL_START_SEC_CONST_SWE1_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe2Table table */
#ifdef APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe2Table, ".SWE2DESC")
    #undef  APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe2FlashStatus table */
#ifdef APPL_START_SEC_CONST_SWE2_FLASH_STATUS
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe2FlashStatus, ".SWE2STAT")
    #undef  APPL_START_SEC_CONST_SWE2_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe3Table table */
#ifdef APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe3Table, ".SWE3DESC")
    #undef  APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe3FlashStatus table */
#ifdef APPL_START_SEC_CONST_SWE3_FLASH_STATUS
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (Swe3FlashStatus, ".SWE3STAT")
    #undef  APPL_START_SEC_CONST_SWE3_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe4Table table */
#ifdef APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
/* Create constant section SWE4DESC */
    #undef  APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe4FlashStatus table */
#ifdef APPL_START_SEC_CONST_SWE4_FLASH_STATUS
    #define CONST_SEC_OPEN
/* Create constant section SWE4STAT */
    #undef  APPL_START_SEC_CONST_SWE4_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's HwDescData table */
#ifdef BM_START_SEC_CONST_HW_DESCRIPTION_TABLE
    #define CONST_SEC_OPEN
#pragma DATA_SECTION (HwDescData, ".ossDataAp_9:noinit")
    #undef  BM_START_SEC_CONST_HW_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Var section for Boot Status */
#ifdef BM_START_SEC_VAR_NOINIT_BOOT_STATUS
    #define VAR_SEC_OPEN
/* Create variable section BOOTLOADER_FLAG */
#pragma DATA_SECTION (BootStatus, ".BOOTSTATUS")
    #undef  BM_START_SEC_VAR_NOINIT_BOOT_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Var section for IsrDispatch */
#ifdef BM_START_SEC_VAR_NOINIT_ISR_DISPATCH
    #define VAR_SEC_OPEN
/* Create variable section BOOTLOADER_FLAG */
#pragma DATA_SECTION (IsrDispatch, ".ISRDISPATCHFLG")
    #undef  BM_START_SEC_VAR_NOINIT_ISR_DISPATCH
    #undef  MEMMAP_ERROR
#endif

/* RAM section for BootloaderStartupFlag */
#ifdef BM_START_SEC_VAR_NOINIT_FLASH_FLAG
    #define VAR_SEC_OPEN
/* Create variable section BOOTLOADER_FLAG */
    #undef  BM_START_SEC_VAR_NOINIT_FLASH_FLAG
    #undef  MEMMAP_ERROR
#endif

/* RAM section for Crypto relevant DCM data */
#ifdef DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Create variable section CryDiag */
    #undef  DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* special section for SYMM variables (shared) */
#if defined (CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT)
    #define VAR_SEC_OPEN
/* Create variable section CryNoInitSymm */
    #undef  CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT
    #undef  MEMMAP_ERROR
#endif

#ifdef CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
    #define VAR_SEC_OPEN
#pragma DATA_SECTION (CR_A_s2, ".CryNoInitAsym")
    #undef  CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif
/* special section for COMM_RNG variables (shared) */
#if defined (CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT )
    #define VAR_SEC_OPEN
#pragma DATA_SECTION (CR_C_s2,".CryNoInitRng")
    #undef  CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
    #undef  MEMMAP_ERROR
#endif

/* special section for RAND_SEED variables (shared) */
#if defined (CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT)
    #define VAR_SEC_OPEN
/* Create variable section CryNoInitSeed */
    #undef  CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
    #undef  MEMMAP_ERROR
#endif

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed because MD5 is no longer used
 */
 #if 0
/* Original code - START */
/* special section for MD5 variables (shared) */
#if defined (CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED)
    #define VAR_SEC_OPEN
#pragma DATA_SECTION (CR_C_s3, ".CryNoInitMd5")
    #undef  CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/* special section for ASYM2 variables (shared) */
#if defined (CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED)
    #define VAR_SEC_OPEN
/* Create variable section CryNoInitAsym */
    #undef  CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* special section for cancel variable (shared) */
#if defined (CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT)
    #define VAR_SEC_OPEN
#pragma DATA_SECTION (CR_C_cancel,".CryNoInitCanc")
    #undef  CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
    #undef  MEMMAP_ERROR
#endif

/* special section for RAM mirrors of NV blocks */
#if defined (DATA_LOGISTIC_START_SEC_VAR_NO_INIT_NVM_DATA)
    #define VAR_SEC_OPEN
    #undef  DATA_LOGISTIC_START_SEC_VAR_NO_INIT_NVM_DATA
    #undef  MEMMAP_ERROR
#endif

/* special section for BootStatus flag */
#if defined (BM_START_SEC_VAR_NOINIT_BOOT_STATUS)
    #define VAR_SEC_OPEN
    #undef  BM_START_SEC_VAR_NOINIT_BOOT_STATUS
    #undef  MEMMAP_ERROR
#endif


/* Const section for bootloader's sharedBootROMData table */
#if defined  (BL_STOP_SEC_CONST_SHARED_DATA)
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  BL_STOP_SEC_CONST_SHARED_DATA
    #undef  MEMMAP_ERROR
#endif

/* special section for crypto jumptable (shared) */
#if defined (CRYPTO_STOP_SEC_JUMPTABLE_CONST_UNSPECIFIED)
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  CRYPTO_STOP_SEC_JUMPTABLE_CONST_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's SweBootTable table */
#ifdef BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's BootFlashStatus table */
#ifdef BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe1Table table */
#ifdef APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe1FlashStatus table */
#ifdef APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe2Table table */
#ifdef APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe2FlashStatus table */
#ifdef APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe3Table table */
#ifdef APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe3FlashStatus table */
#ifdef APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe4Table table */
#ifdef APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's Swe4FlashStatus table */
#ifdef APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS
    #undef  MEMMAP_ERROR
#endif

/* Const section for bootloader's HwDescData table */
#ifdef BM_STOP_SEC_CONST_HW_DESCRIPTION_TABLE
    #undef  CONST_SEC_OPEN
/* Return to default constant section */
    #undef  BM_STOP_SEC_CONST_HW_DESCRIPTION_TABLE
    #undef  MEMMAP_ERROR
#endif

/* RAM section for BootloaderStartupFlag */
#ifdef BM_STOP_SEC_VAR_NOINIT_FLASH_FLAG
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  BM_STOP_SEC_VAR_NOINIT_FLASH_FLAG
    #undef  MEMMAP_ERROR
#endif

/* RAM section for Crypto relevant DCM data */
#ifdef DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* special section for SYMM variables (shared) */
#if defined (CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT)
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT
    #undef  MEMMAP_ERROR
#endif

/* special section for COMM_RNG variables (shared) */
#if defined (CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT )
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
    #undef  MEMMAP_ERROR
#endif

/* special section for RAND_SEED variables (shared) */
#if defined (CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT)
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
    #undef  MEMMAP_ERROR
#endif

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed because MD5 is no longer used
 */
 #if 0
/* Original code - START */
/* special section for MD5 variables (shared) */
#if defined (CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED)
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/* special section for ASYM2 variables (shared) */
#if defined (CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED)
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
    #undef  MEMMAP_ERROR
#endif

/* special section for cancel variable (shared) */
#if defined (CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT)
    #undef  VAR_SEC_OPEN
/* Return to default variable section */
    #undef  CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
    #undef  MEMMAP_ERROR
#endif

/* special section for RAM mirrors of NV blocks */
#if defined (DATA_LOGISTIC_STOP_SEC_VAR_NO_INIT_NVM_DATA)
    #undef  VAR_SEC_OPEN
    #undef  DATA_LOGISTIC_STOP_SEC_VAR_NO_INIT_NVM_DATA
    #undef  MEMMAP_ERROR
#endif

/* special section for BootStatus flag */
#if defined (BM_STOP_SEC_VAR_NOINIT_BOOT_STATUS)
    #undef  VAR_SEC_OPEN
    #undef  BM_STOP_SEC_VAR_NOINIT_BOOT_STATUS
    #undef  MEMMAP_ERROR
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* code section for application */
#if defined (APPLMAIN_START_SEC_CODE)
    #define CODE_SEC_OPEN
    #undef  APPLMAIN_START_SEC_CODE
    #undef  MEMMAP_ERROR
#endif

/* code section for boot manager */
#if defined (BM_START_SEC_CODE)
    #define CODE_SEC_OPEN
    #undef  BM_START_SEC_CODE
    #undef  MEMMAP_ERROR
#endif

/* code section for sc_ee_data routines */
#if defined (DATA_LOGISTIC_START_SEC_CODE)
    #define CODE_SEC_OPEN
    #undef  DATA_LOGISTIC_START_SEC_CODE
    #undef  MEMMAP_ERROR
#endif

/* code section for application */
#if defined (APPLMAIN_STOP_SEC_CODE)
    #undef  CODE_SEC_OPEN
    #undef  APPLMAIN_STOP_SEC_CODE
    #undef  MEMMAP_ERROR
#endif

/* code section for application */
#if defined (BM_STOP_SEC_CODE)
    #undef  CODE_SEC_OPEN
    #undef  BM_STOP_SEC_CODE
    #undef  MEMMAP_ERROR
#endif

/* code section for sc_ee_data routines */
#if defined (DATA_LOGISTIC_STOP_SEC_CODE)
    #undef  CODE_SEC_OPEN
    #undef  DATA_LOGISTIC_STOP_SEC_CODE
    #undef  MEMMAP_ERROR
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/
/************   Organi, Version 3.8.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.8.0 Vector-Informatik GmbH  ************/
