/* Copyright (C) 2009 TTTech Automotive GmbH. All rights reserved
 * Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office'at'tttech-
 * automotive.com
 *
 * Name:
 *   e2e_crc8_1d.h
 *
 * Purpose:
 *   Declaration for e2e_crc8 routines using polynom 1D.
 *   Compiler defines.
 *
 */

#ifndef E2E_CRC8_1D_H
#define E2E_CRC8_1D_H 1

#include "Std_Types.h"

/*****************************************************************************
 * Version
 *****************************************************************************/
#define E2E_CRC8_1D_AR_MAJOR_VERSION    3
#define E2E_CRC8_1D_AR_MINOR_VERSION    2
#define E2E_CRC8_1D_AR_PATCH_VERSION    0

#define E2E_CRC8_1D_SW_MAJOR_VERSION    0
#define E2E_CRC8_1D_SW_MINOR_VERSION    1
#define E2E_CRC8_1D_SW_PATCH_VERSION    2

/*****************************************************************************
 * E2E_CRC8_1D_MODE Compiler switch values.
 *****************************************************************************/
#define E2E_CRC8_1D_RUNTIME     0 /** use bitshifting CRC algorithm  */
#define E2E_CRC8_1D_TABLE       1 /** use CRC algorithm with 256byte */

/*****************************************************************************
 * Configuration of used CRC algorithm.
 *****************************************************************************/

#ifndef E2E_CRC8_1D_MODE
#define E2E_CRC8_1D_MODE E2E_CRC8_1D_TABLE
#endif

#define E2E_START_SEC_CODE_LIB
#include "MemMap.h"

/*****************************************************************************
 * Prototypes of functions
 *****************************************************************************/

/**
 * Calculates the CRC over an uint8 type with poly 0x1D.
 * @param Data              byte to be CRC-protected.
 * @param StartValue        initial value for CRC.
 *
 * @return evaluated        CRC-value over Data and StartValue.
 */
extern FUNC (uint8, E2E_CODE) E2E_CRC8H1Du8
(
    VAR (uint8, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
);

/**
 * Calculates the CRC over an uint16 type with poly 0x1D.
 * @param Data              byte to be CRC-protected.
 * @param StartValue        initial value for CRC.
 *
 * @return evaluated        CRC-value over Data and StartValue.
 */
extern FUNC (uint8, E2E_CODE) E2E_CRC8H1Du16
(
    VAR (uint16, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
);

/**
 * Calculates the CRC over an array of uint8 with poly 0x1D.
 * @param Length            number bytes in Data-array
 * @param Data              byte-array to be CRC-protected.
 * @param StartValue        initial value for CRC.
 *
 * @return evaluated CRC-value over Data-array and StartValue.
 */
extern FUNC (uint8, E2E_CODE) E2E_CRC8H1Du8Array
(
    VAR (uint16, AUTOMATIC) Length,
    P2CONST (uint8, AUTOMATIC, E2E_APPL_CONST) Data,
    uint8 StartValue
);

#define E2E_STOP_SEC_CODE_LIB
/* ------------------------------------------------------------------------ */
/*                        SUPRESSED MISRA VIOLATONS                         */
/* ------------------------------------------------------------------------ */
/* Error Message : Msg(4:5087) #include statements in a file should only be
     preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                   */
/* PRQA S 5087 1                                                            */
#include "MemMap.h"

#endif /* E2E_CRC8_1D_H */
