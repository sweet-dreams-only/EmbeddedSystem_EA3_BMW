/* Copyright (C) 2009 TTTech Automotive GmbH. All rights reserved
 * Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office'at'tttech-
 * automotive.com
 *
 * Name:
 *   E2E_P01.h
 *
 * Purpose:
 *   Declarations and defines of E2ELib Profile1.
 *
 */


#ifndef E2E_P01_H
#define E2E_P01_H 1

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "E2E_CRC8_1D.h"

/*****************************************************************************
 * Version & Pulished Information
 *****************************************************************************/
#define E2E_P01_VENDOR_ID                    46
#define E2E_P01_MODULE_ID                   207

#define E2E_P01_AR_MAJOR_VERSION              3
#define E2E_P01_AR_MINOR_VERSION              2
#define E2E_P01_AR_PATCH_VERSION              0

#define E2E_P01_SW_MAJOR_VERSION              0
#define E2E_P01_SW_MINOR_VERSION              1
#define E2E_P01_SW_PATCH_VERSION              2

/* The version of CRC8_1D routines with which E2Elib was tested:
*/
#define E2E_TESTED_CRC8_1D_MAJOR_VERSION      0
#define E2E_TESTED_CRC8_1D_MINOR_VERSION      1
#define E2E_TESTED_CRC8_1D_PATCH_VERSION      2

/*****************************************************************************
 * Version Check - Test that the CRC-routines are included, for which E2Elib
 * was tested for:
 *****************************************************************************/
#if !(  (E2E_CRC8_1D_SW_MAJOR_VERSION == E2E_TESTED_CRC8_1D_MAJOR_VERSION) \
     && (E2E_CRC8_1D_SW_MINOR_VERSION == E2E_TESTED_CRC8_1D_MINOR_VERSION) \
     && (E2E_CRC8_1D_SW_PATCH_VERSION == E2E_TESTED_CRC8_1D_PATCH_VERSION) \
     && (E2E_CRC8_1D_AR_MAJOR_VERSION == E2E_P01_AR_MAJOR_VERSION) \
     && (E2E_CRC8_1D_AR_MINOR_VERSION == E2E_P01_AR_MINOR_VERSION) \
     && (E2E_CRC8_1D_AR_PATCH_VERSION == E2E_P01_AR_PATCH_VERSION) \
     )
    #error "Version mismatch. Incorrect version of E2E_CRC8_1D.h"
#endif

/*****************************************************************************
 * Macros
 *****************************************************************************/
#define E2E_COUNTER_PROF1B_POS        4
#define E2E_P01_COUNTER_MSK         0x0Fu

#define E2E_PROF1_CRC_STARTVAL      0x00

#define E2E_MAX_COUNTER_PROF1_VAL   0x0E    /**< max. counter-value          */

#define E2E_MIN_PROF1_DATALENGTH    0x0010  /**< min. datalength in bits     */
#define E2E_MAX_PROF1_DATALENGTH    0x00F0  /**< max. datalength in bits
                                             **  profile1 PDU can only have
                                             **  30bytes                     */

/**
 * Return values used by E2E library functions.
 */
#ifndef E2E_E_INPUTERR_NULL
#define E2E_E_INPUTERR_NULL  0x13 /**< Error: a pointer parameter is NULL    */
#endif

#ifndef E2E_E_INPUTERR_WRONG
#define E2E_E_INPUTERR_WRONG 0x17 /**< Error: one parameter is errornous,    */
#endif

#ifndef E2E_E_INTERR
#define E2E_E_INTERR         0x19 /**< Error: internal library error         */
#endif

#ifndef E2E_E_OK
#define E2E_E_OK             0x00 /**< Function completed successfully       */
#endif

/*****************************************************************************
 * Macro definitions
 *****************************************************************************/
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:3453) A function could probably be used instead
 *                 of this function-like macro.
 * Justification : Runtime performance.                                      */
/* PRQA S 3453 1                                                             */
#define E2E_P01_UpdateCounter( _counter ) (((_counter) + 1) % 15)

/*****************************************************************************
 * Type definitions
 *****************************************************************************/
typedef enum {
    E2E_P01_DATAID_BOTH = 0, /**< use both ID bytes in CRC calculation       */
    E2E_P01_DATAID_ALT  = 1, /**< alternate ID bytes in CRC calculation      */
    E2E_P01_DATAID_LOW  = 2  /**< use only low-byte of ID in CRC calc.       */
} E2E_P01DataIDMode;

typedef struct {
    uint16 DataLength;             /**< length of IPDU                       */
    uint16 DataID;                 /**< unique IPDU ID                       */
    E2E_P01DataIDMode DataIDMode;  /**< Inclusion mode of DataID in CRC
                                    **  calculation                          */
    uint8 MaxDeltaCounterInit;     /**< Inital max. allow delta between two
                                    **  consecutive received valid IPDUs     */
    uint16 CRCOffset;              /**< offset of CRC in IPDU                */
    uint16 CounterOffset;          /**< offset of sequence counter in IPDU   */
} E2E_P01ConfigType;

typedef struct {
    uint8 Counter; /**< Value for next send IPDU sequence counter */
} E2E_P01SenderStateType;

typedef enum {
    E2E_P01STATUS_NONEWDATA     = 0x01, /**< no new data received            */
    E2E_P01STATUS_WRONGCRC      = 0x02, /**< received IPDU has invalid CRC   */
    E2E_P01STATUS_INITIAL       = 0x04, /**< first IPDU received after
                                         **  initalisation, CRC ok but
                                         **  sequence counter cannot be
                                         **  verified                        */
    E2E_P01STATUS_REPEATED      = 0x08, /**< Received IPDU valid (CRC) but
                                         **  sequnce counter is identical
                                         **  with prev. received IPDU        */
    E2E_P01STATUS_OK            = 0x10, /**< CRC and sequence counter ok ->
                                         **  data valid                      */
    E2E_P01STATUS_OKSOMELOST    = 0x20, /**< CRC ok, some IPDUs lost (less/
                                         **  equal than MaxDeltaCounter)     */
    E2E_P01STATUS_WRONGSEQUENCE = 0x40  /**< CRC ok, the number of lost
                                         **  message is greater than
                                         **  MaxDeltaCounter                 */
} E2E_P01ReceiverStatusType;

typedef struct {
    uint8   LastValidCounter;         /**< Value of last valid IPDU's
                                       **  sequence counter                  */
    uint8   MaxDeltaCounter;          /**< Max. allowed difference of the
                                       **  sequence counter between 2 received
                                       **  frames ignoring possible frames
                                       **  losses which have to be detected
                                       **  by timeout supervision            */
    boolean WaitForFirstData;         /**< No IPDU has been received after
                                       **  initialisation                    */
    boolean NewDataAvailable;         /**< Indicates to the E2E-library that
                                       **  new data are available.
                                       **  Must be set by the caller         */
    uint8   LostData;                 /**< number of lost IPDUs              */
    E2E_P01ReceiverStatusType Status; /**< Result of the E2E_CheckP01()
                                       **  function.                         */
} E2E_P01ReceiverStateType;

#define E2E_START_SEC_CODE_LIB
#include "MemMap.h"
/*****************************************************************************
 * Prototypes
 *****************************************************************************/

/**
 *  Returns the version information of this module.
 *
 *  @param  *VersionInfo    Pointer to the structure which receives the
 *                          version info.
 *
 *  @return                 void
 */
extern FUNC (void, E2E_CODE) E2E_P01GetVersionInfo
(
    P2VAR (Std_VersionInfoType, AUTOMATIC, E2E_APPL_DATA) VersionInfo
);

/**
 * Protection function for profile 11
 *
 * @param Config    Pointer to profile configuration
 * @param State     Pointer to data comunication state
 * @param Data      Pointer to data to be transmitted
 *
 * @return          Status of processing
 */
extern FUNC (Std_ReturnType, E2E_CODE) E2E_P01Protect
(
    P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) Config,
    P2VAR (E2E_P01SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
    P2VAR (uint8, AUTOMATIC, E2E_APPL_DATA) Data
);

/**
 * Check function using profile 2
 *
 * @param Config    Pointer to profile configuration
 * @param State     Pointer to data comunication state
 * @param Data      Pointer to the received data
 *
 * @return          Status of processing
 */
extern FUNC (Std_ReturnType, E2E_CODE) E2E_P01Check
(
    P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) Config,
    P2VAR (E2E_P01ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
    P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) Data
);

#define E2E_STOP_SEC_CODE_LIB
/* ------------------------------------------------------------------------ */
/*                        SUPRESSED MISRA VIOLATONS                         */
/* -------------------------------------------------------------------------*/
/* Error Message : Msg(4:5087) #include statements in a file should only be
 * preceded by other preprocessor directives or comments.
 * Justification : MemMap-pragmas must be stopped here. See AUTOSAR
 *                 requirement MEMMAP003.                                   */
/* PRQA S 5087 1                                                            */
#include "MemMap.h"

#endif /* E2E_P01_H */
