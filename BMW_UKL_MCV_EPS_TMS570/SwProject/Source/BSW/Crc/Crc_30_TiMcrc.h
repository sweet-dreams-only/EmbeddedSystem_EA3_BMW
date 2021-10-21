/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Crc_30_TiMcrc.h
 *    Component:  DrvCrc_Tms570Timcrc01Asr
 *       Module:  Crc_30_TiMcrc
 *    Generator:  MICROSAR EAD
 *
 *  Description:  Crc module is used to calculate CRC values for data to
 *                ensure data integrity.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Martin Froschhammer           Mfr           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2009-03-03  Mfr     -             Initial Release
 **********************************************************************************************************************/

/* multiple inclusion potection */
#if !defined (CRC_30_TIMCRC_H)
#define CRC_30_TIMCRC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Crc_30_TiMcrc_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : DrvCrc_Tms570Timcrc01Asr CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
#define DRVCRC_TMS570TIMCRC01ASR_VERSION         (0x0100u)
#define DRVCRC_TMS570TIMCRC01ASR_RELEASE_VERSION (0x00u)

/* Version and module identification */
#define CRC_30_TIMCRC_VENDOR_ID               (30u)
#define CRC_30_TIMCRC_MODULE_ID               (255u)
#define CRC_30_TIMCRC_INSTANCE_ID             (0u)

/* Component Version Information */
#define CRC_30_TIMCRC_SW_MAJOR_VERSION        (DRVCRC_TMS570TIMCRC01ASR_VERSION >> 8u)
#define CRC_30_TIMCRC_SW_MINOR_VERSION        (DRVCRC_TMS570TIMCRC01ASR_VERSION & 0x00FF)
#define CRC_30_TIMCRC_SW_PATCH_VERSION        DRVCRC_TMS570TIMCRC01ASR_RELEASE_VERSION

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*!
 * \brief   pointer type for pointers to data buffers, from which the
 *          CRC value is to be calculated.
 */

typedef long long unsigned Crc_30_TiMcrc_ValueType;  

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define CRC_30_TIMCRC_START_SEC_CODE
#include "MemMap.h"

FUNC(Crc_30_TiMcrc_ValueType, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_CalculateCRC64
                (
                     P2CONST(uint8, AUTOMATIC, CRC_30_TIMCRC_APPL_DATA) Crc_DataPtr,
                     uint32 Crc_Length,
                     Crc_30_TiMcrc_ValueType  Crc_StartValue64
                );

#if (CRC_30_TIMCRC_VERSION_INFO_API == STD_ON)
    FUNC(void, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_GetVersionInfo
                (
                     P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_30_TIMCRC_APPL_DATA) versioninfo
                );
#endif

#define CRC_30_TIMCRC_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* CRC_30_TIMCRC_H */

/**********************************************************************************************************************
 *  END OF FILE: Crc_30_TiMcrc.h
 *********************************************************************************************************************/
