/* Copyright (C) 2009 TTTech Automotive GmbH. All rights reserved
 * Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office'at'tttech-
 * automotive.com
 *
 * Name:
 *   e2e_crc8_1d_table.c
 *
 * Purpose:
 *   Implementation of e2e_crc8 table-approach using polynom 1D.
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
#define E2E_CRC8_1D_TABLE_SRC_AR_MAJOR_VERSION   3
#define E2E_CRC8_1D_TABLE_SRC_AR_MINOR_VERSION   2
#define E2E_CRC8_1D_TABLE_SRC_AR_PATCH_VERSION   0

#define E2E_CRC8_1D_TABLE_SRC_SW_MAJOR_VERSION   0
#define E2E_CRC8_1D_TABLE_SRC_SW_MINOR_VERSION   1
#define E2E_CRC8_1D_TABLE_SRC_SW_PATCH_VERSION   2

/*****************************************************************************
 * Version Check
 *****************************************************************************/
#if !(  (E2E_CRC8_1D_TABLE_SRC_SW_MAJOR_VERSION == E2E_CRC8_1D_SW_MAJOR_VERSION) \
     && (E2E_CRC8_1D_TABLE_SRC_SW_MINOR_VERSION == E2E_CRC8_1D_SW_MINOR_VERSION) \
     && (E2E_CRC8_1D_TABLE_SRC_AR_MAJOR_VERSION == E2E_CRC8_1D_AR_MAJOR_VERSION) \
     && (E2E_CRC8_1D_TABLE_SRC_AR_MINOR_VERSION == E2E_CRC8_1D_AR_MINOR_VERSION) \
     && (E2E_CRC8_1D_TABLE_SRC_AR_PATCH_VERSION == E2E_CRC8_1D_AR_PATCH_VERSION) \
     )
    #error "Version mismatch. Incorrect version of E2E_CRC8_1D.h"
#endif

#if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_TABLE)

/**
 * Calculates a CRC from a data-byte and a startvalue-byte.
 * @param _data         the data-byte,
 * @param _startval     the initial value-byte
 *
 * @return              the CRC calculated from _data and _startval
 */
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:3453) A function could probably be used instead
 *                 of this function-like macro.
 * Justification : Runtime performance.                                      */
/* PRQA S 3453 2                                                             */
#define E2E_CRC_CALCONEBYTE_H1D(_data, _startval)     \
    (crctab_H1D_cau8[((_data) ^ (_startval)) & 0xFF])

#define E2E_START_SEC_CONST_8BIT
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:5087) #include statements in a file should only be
 * preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                    */
/* PRQA S 5087 1                                                             */
#include "MemMap.h"

STATIC CONST (uint8, E2E_CONST) crctab_H1D_cau8[256] = {
0x00, 0x1d, 0x3a, 0x27, 0x74, 0x69, 0x4e, 0x53,
0xe8, 0xf5, 0xd2, 0xcf, 0x9c, 0x81, 0xa6, 0xbb,
0xcd, 0xd0, 0xf7, 0xea, 0xb9, 0xa4, 0x83, 0x9e,
0x25, 0x38, 0x1f, 0x02, 0x51, 0x4c, 0x6b, 0x76,
0x87, 0x9a, 0xbd, 0xa0, 0xf3, 0xee, 0xc9, 0xd4,
0x6f, 0x72, 0x55, 0x48, 0x1b, 0x06, 0x21, 0x3c,
0x4a, 0x57, 0x70, 0x6d, 0x3e, 0x23, 0x04, 0x19,
0xa2, 0xbf, 0x98, 0x85, 0xd6, 0xcb, 0xec, 0xf1,
0x13, 0x0e, 0x29, 0x34, 0x67, 0x7a, 0x5d, 0x40,
0xfb, 0xe6, 0xc1, 0xdc, 0x8f, 0x92, 0xb5, 0xa8,
0xde, 0xc3, 0xe4, 0xf9, 0xaa, 0xb7, 0x90, 0x8d,
0x36, 0x2b, 0x0c, 0x11, 0x42, 0x5f, 0x78, 0x65,
0x94, 0x89, 0xae, 0xb3, 0xe0, 0xfd, 0xda, 0xc7,
0x7c, 0x61, 0x46, 0x5b, 0x08, 0x15, 0x32, 0x2f,
0x59, 0x44, 0x63, 0x7e, 0x2d, 0x30, 0x17, 0x0a,
0xb1, 0xac, 0x8b, 0x96, 0xc5, 0xd8, 0xff, 0xe2,
0x26, 0x3b, 0x1c, 0x01, 0x52, 0x4f, 0x68, 0x75,
0xce, 0xd3, 0xf4, 0xe9, 0xba, 0xa7, 0x80, 0x9d,
0xeb, 0xf6, 0xd1, 0xcc, 0x9f, 0x82, 0xa5, 0xb8,
0x03, 0x1e, 0x39, 0x24, 0x77, 0x6a, 0x4d, 0x50,
0xa1, 0xbc, 0x9b, 0x86, 0xd5, 0xc8, 0xef, 0xf2,
0x49, 0x54, 0x73, 0x6e, 0x3d, 0x20, 0x07, 0x1a,
0x6c, 0x71, 0x56, 0x4b, 0x18, 0x05, 0x22, 0x3f,
0x84, 0x99, 0xbe, 0xa3, 0xf0, 0xed, 0xca, 0xd7,
0x35, 0x28, 0x0f, 0x12, 0x41, 0x5c, 0x7b, 0x66,
0xdd, 0xc0, 0xe7, 0xfa, 0xa9, 0xb4, 0x93, 0x8e,
0xf8, 0xe5, 0xc2, 0xdf, 0x8c, 0x91, 0xb6, 0xab,
0x10, 0x0d, 0x2a, 0x37, 0x64, 0x79, 0x5e, 0x43,
0xb2, 0xaf, 0x88, 0x95, 0xc6, 0xdb, 0xfc, 0xe1,
0x5a, 0x47, 0x60, 0x7d, 0x2e, 0x33, 0x14, 0x09,
0x7f, 0x62, 0x45, 0x58, 0x0b, 0x16, 0x31, 0x2c,
0x97, 0x8a, 0xad, 0xb0, 0xe3, 0xfe, 0xd9, 0xc4,
};

#define E2E_STOP_SEC_CONST_8BIT
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:5087) #include statements in a file should only be
 * preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                    */
/* PRQA S 5087 1                                                             */
#include "MemMap.h"

#endif /* #if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_TABLE) */
/*****************************************************************************
 * Static functions
 *****************************************************************************/

/*****************************************************************************
 * Non-static functions
 *****************************************************************************/
#if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_TABLE)

#define E2E_START_SEC_CODE_LIB
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:5087) #include statements in a file should only be
 * preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                    */
/* PRQA S 5087 1                                                             */
#include "MemMap.h"

FUNC(uint8, E2E_CODE) E2E_CRC8H1Du8
(
    VAR (uint8, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint8 crc_u8;

    crc_u8 = E2E_CRC_CALCONEBYTE_H1D ( Data, StartValue);

    return crc_u8;
}

FUNC(uint8, E2E_CODE) E2E_CRC8H1Du16
(
    VAR (uint16, AUTOMATIC) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint8 crc_u8;
    uint8 dataByte_u8;

    /* CRC is calculated starting from LSB (according to E2E0096)
     * to avoid endian dependency, every 8bit of Data is copied to
     * dataByte_u8 which is passed then to macro E2E_CRC_CALCONEBYTE_H1D:
     */
    crc_u8 = E2E_CRC_CALCONEBYTE_H1D ((uint8) Data, StartValue);

    dataByte_u8 = (uint8)(Data >> 8);
    crc_u8 = E2E_CRC_CALCONEBYTE_H1D ( dataByte_u8, crc_u8);

    return crc_u8;
}


FUNC(uint8, E2E_CODE) E2E_CRC8H1Du8Array
(
    VAR (uint16, AUTOMATIC) Length,
    P2CONST(uint8, E2E_VAR, E2E_APPL_DATA) Data,
    VAR (uint8, AUTOMATIC) StartValue
)
{
    uint16 idx_u16;
    uint8  tmp_u8;
    uint8  crc_u8;

    crc_u8 = StartValue;
    for (idx_u16=0; idx_u16<Length; idx_u16++)
    {
        tmp_u8 = Data [idx_u16];

        /* calculate CRC always starting from LSB */
        crc_u8 = E2E_CRC_CALCONEBYTE_H1D (tmp_u8, crc_u8);
    }

    return crc_u8;
}

#define E2E_STOP_SEC_CODE_LIB
/* ------------------------------------------------------------------------ */
/*                        SUPRESSED MISRA VIOLATONS                         */
/* ------------------------------------------------------------------------ */
/* Error Message : Msg(4:5087) #include statements in a file should only be
 * preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                   */
/* PRQA S 5087 1                                                            */
#include "MemMap.h"

#endif /* #if (E2E_CRC8_1D_MODE == E2E_CRC8_1D_TABLE) */
