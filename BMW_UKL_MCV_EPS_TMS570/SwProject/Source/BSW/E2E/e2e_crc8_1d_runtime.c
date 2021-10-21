/* Copyright (C) 2009 TTTech Automotive GmbH. All rights reserved
 * Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office'at'tttech-
 * automotive.com
 *
 * Name:
 *   e2e_crc8_1d_runtime.c - for Profile 1 - Prototype
 *
 * Purpose:
 *   Implementation of e2e_crc8 runtime-approach using polynom 1D.
 *
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "E2E_CRC8_1D.h"

#ifndef E2E_CRC8_1D_MODE
#error E2E_CRC8_1D_MODE not defined !
#endif

/*****************************************************************************
 * Version
 *****************************************************************************/
#define E2E_CRC8_1D_RUNTIME_SRC_AR_MAJOR_VERSION   3
#define E2E_CRC8_1D_RUNTIME_SRC_AR_MINOR_VERSION   2
#define E2E_CRC8_1D_RUNTIME_SRC_AR_PATCH_VERSION   0

#define E2E_CRC8_1D_RUNTIME_SRC_SW_MAJOR_VERSION   0
#define E2E_CRC8_1D_RUNTIME_SRC_SW_MINOR_VERSION   1
#define E2E_CRC8_1D_RUNTIME_SRC_SW_PATCH_VERSION   2

/*****************************************************************************
 * Version Check
 *****************************************************************************/
#if !(  (E2E_CRC8_1D_RUNTIME_SRC_SW_MAJOR_VERSION == E2E_CRC8_1D_SW_MAJOR_VERSION) \
     && (E2E_CRC8_1D_RUNTIME_SRC_SW_MINOR_VERSION == E2E_CRC8_1D_SW_MINOR_VERSION) \
     && (E2E_CRC8_1D_RUNTIME_SRC_AR_MAJOR_VERSION == E2E_CRC8_1D_AR_MAJOR_VERSION) \
     && (E2E_CRC8_1D_RUNTIME_SRC_AR_MINOR_VERSION == E2E_CRC8_1D_AR_MINOR_VERSION) \
     && (E2E_CRC8_1D_RUNTIME_SRC_AR_PATCH_VERSION == E2E_CRC8_1D_AR_PATCH_VERSION) \
     )
    #error "Version mismatch. Incorrect version of E2E_CRC8_1D.h"
#endif

#if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_RUNTIME)

#define E2E_CRC_POLYNOM_H1D   0x1D

#define E2E_START_SEC_CODE_LIB
#include "MemMap.h"

/*****************************************************************************
 * Static functions
 *****************************************************************************/

/**
 * Calculate CRC-value from a data-byte using H1D-polynom.
 * @param data_u8       The data-byte to be CRC-protected.
 *
 * @return              The calculated CRC-value.
 */
STATIC FUNC (uint8, E2E_CODE) e2e_1d_crc8_calconebyte
(
    VAR (uint8, AUTOMATIC) data_u8
);

STATIC FUNC (uint8, E2E_CODE) e2e_1d_crc8_calconebyte
(
    VAR (uint8, AUTOMATIC) data_u8
)
{
    uint8 bit_u8;
    uint8 msb_u8;
    uint8 tmp_u8;

    tmp_u8 = data_u8;
    for (bit_u8=0; bit_u8 < 8; bit_u8++)
    {   /* get MSB */
        msb_u8   = (uint8)(tmp_u8 >> 7) & 0x01;
        /* shift left one bit */
        tmp_u8 <<= 1;
        /* XOR with CRC polynom if MSB != 0 */
        tmp_u8  ^= E2E_CRC_POLYNOM_H1D * msb_u8;
    }

    return (tmp_u8);
}

/*****************************************************************************
 * Non-static functions
 *****************************************************************************/

FUNC(uint8, E2E_CODE) E2E_CRC8H1Du8
(
    VAR (uint8, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint8 crc_u8;

    crc_u8 = e2e_1d_crc8_calconebyte (StartValue ^ Data);

    return crc_u8;
}

FUNC(uint8, E2E_CODE) E2E_CRC8H1Du16
(
    VAR (uint16, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint8 crc_u8;
    uint8 dataByte;

    /* CRC starts with LSB */
    dataByte = (uint8) Data;
    crc_u8   = e2e_1d_crc8_calconebyte (dataByte ^ StartValue);
    dataByte = (uint8)(Data >> 8);
    crc_u8   = e2e_1d_crc8_calconebyte (dataByte ^ crc_u8);

    return crc_u8;
}

FUNC(uint8, E2E_CODE) E2E_CRC8H1Du8Array
(
    VAR (uint16, AUTOMATIC) Length,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint16 idx_u16;
    uint8  tmp_u8;
    uint8  crc_u8;

    crc_u8 = StartValue;
    for (idx_u16 = 0; idx_u16 < Length; idx_u16++)
    {
        tmp_u8 = Data [idx_u16];
        crc_u8 = e2e_1d_crc8_calconebyte (crc_u8 ^ tmp_u8);
    }

    return crc_u8;
}

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

#endif /* #if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_RUNTIME) */
