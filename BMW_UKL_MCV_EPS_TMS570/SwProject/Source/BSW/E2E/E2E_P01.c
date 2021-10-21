/* Copyright (C) 2009 TTTech Automotive GmbH. All rights reserved
 * Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office'at'tttech-
 * automotive.com
 *
 * Name:
 *   E2E_P01.c
 *
 * Purpose:
 *   Implementation of E2ELib Profile 1 - Prototype.
 *
 */

/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(6:0288) Source file  has comments containing
 * characters which are not members of the basic source character set.
 * Justification : Usual Doxygen character. Coding guidelines                */
/* PRQA S 0288 EOF                                                           */

/**
 * @metric VOCF >4  Sprachumfang: Code-structure specified by
 *                                AUTOSAR "Spec.of EndtoEnd Comm.
 *                                Prot.", #428.
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "E2E_P01.h"

/*****************************************************************************
 * Version
 *****************************************************************************/
#define E2E_P01_SRC_AR_MAJOR_VERSION   3
#define E2E_P01_SRC_AR_MINOR_VERSION   2
#define E2E_P01_SRC_AR_PATCH_VERSION   0

#define E2E_P01_SRC_SW_MAJOR_VERSION   0
#define E2E_P01_SRC_SW_MINOR_VERSION   1
#define E2E_P01_SRC_SW_PATCH_VERSION   2

/*****************************************************************************
 * Version Check
 *****************************************************************************/
#if !(  (E2E_P01_SRC_SW_MAJOR_VERSION == E2E_P01_SW_MAJOR_VERSION) \
     && (E2E_P01_SRC_SW_MINOR_VERSION == E2E_P01_SW_MINOR_VERSION) \
     && (E2E_P01_SRC_AR_MAJOR_VERSION == E2E_P01_AR_MAJOR_VERSION) \
     && (E2E_P01_SRC_AR_MINOR_VERSION == E2E_P01_AR_MINOR_VERSION) \
     && (E2E_P01_SRC_AR_PATCH_VERSION == E2E_P01_AR_PATCH_VERSION) \
     )
    #error "Version mismatch. Incorrect version of E2E_P01.h"
#endif

/*****************************************************************************
 * Externals
 *****************************************************************************/

/*****************************************************************************
 * Globals
 *****************************************************************************/

/*****************************************************************************
 * Static functions
 *****************************************************************************/
#define E2E_START_SEC_CODE_LIB
#include "MemMap.h"

/**
 * Local function to calculate CRC of an I-PDU.
 *
 * @param config_pcs    Pointer to profile configuration
 * @param data_pu8      Pointer to data to be transmitted
 * @param counter_u8    Current counter of IPDU
 *
 * @return              The calculated CRC
 */
STATIC FUNC (uint8, E2E_CODE) e2e_p01_calc_crc
(
    P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) config_pcs,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) data_pu8,
    VAR (uint8, AUTOMATIC) counter_u8
);

STATIC FUNC (uint8, E2E_CODE) e2e_p01_calc_crc
(
    P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) config_pcs,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) data_pu8,
    VAR (uint8, AUTOMATIC) counter_u8
)
{
    uint8  crc_u8;
    uint8  tmp_u8;
    uint8 len_u8;
    uint8 start_u8;

    /* Depending on DataIDMode, calculate CRC over different parts of
     * the DataID
     */
    if      (config_pcs->DataIDMode == E2E_P01_DATAID_BOTH)
    {
        /* E2E_CRC8u16 calculates CRC with low byte first: */
        crc_u8 = E2E_CRC8H1Du16(config_pcs->DataID, E2E_PROF1_CRC_STARTVAL);
    }
    else if (config_pcs->DataIDMode == E2E_P01_DATAID_LOW)
    {
        tmp_u8 = (uint8)(config_pcs->DataID & (uint8)0xFF);
        crc_u8 = E2E_CRC8H1Du8( tmp_u8, E2E_PROF1_CRC_STARTVAL );
    }
    else /* config_pcs->DataIDMode == E2E_P01_DATAID_ALT */
    {
        if ( (counter_u8 & 1) == 0)
        {
            tmp_u8 = (uint8)(config_pcs->DataID & (uint8)0xFF);
            /* include low byte in CRC if even counter */
            crc_u8 = E2E_CRC8H1Du8( tmp_u8, E2E_PROF1_CRC_STARTVAL );
        }
        else
        {
            tmp_u8 = (uint8)(config_pcs->DataID >> 8);
            /* include high byte in CRC if odd counter */
            crc_u8 = E2E_CRC8H1Du8( tmp_u8, E2E_PROF1_CRC_STARTVAL );
        }
    }

    if (config_pcs->CRCOffset >= 8)
    {
        /* calc CRC from start to byte before CRC: */
        len_u8 = (uint8)(config_pcs->CRCOffset / 8);
        crc_u8 = E2E_CRC8H1Du8Array(len_u8, &data_pu8[0], crc_u8);
    }

    if ((config_pcs->CRCOffset/8) < ((config_pcs->DataLength/8) - 1))
    {
        /* calc CRC from byte after CRC to end: */
        start_u8 = (uint8)(config_pcs->CRCOffset / 8) + 1;
        len_u8 = (uint8)( ( ( config_pcs->DataLength
                             - config_pcs->CRCOffset
                             ) / 8
                           ) - 1
                         );
        crc_u8 = E2E_CRC8H1Du8Array( len_u8, &data_pu8[start_u8], crc_u8);
    }

    return crc_u8;
}

/*****************************************************************************
 * Non-static functions
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:1503) The function 'E2E_P01_GetVersionInfo' is
 *                 defined but is not used within this project.
 * Justification : Library-API-function used by application.                 */
/* PRQA S 1503 3                                                             */
FUNC (void, E2E_CODE) E2E_P01GetVersionInfo
(
    P2VAR (Std_VersionInfoType, AUTOMATIC, E2E_APPL_DATA) VersionInfo
)
{
    VersionInfo->moduleID         = E2E_P01_MODULE_ID;
    VersionInfo->vendorID         = E2E_P01_VENDOR_ID;
    VersionInfo->sw_major_version = E2E_P01_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = E2E_P01_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = E2E_P01_SW_PATCH_VERSION;
}

/**
 * @metric PATH >80  Number of Paths: Code-structure specified by
 *                                 AUTOSAR "Spec.of EndtoEnd Comm.
 *                                 Prot.", #428.
 *                                 Parameter-checks are splitted in several
 *                                 'if's, otherwise coverage-analysis is
 *                                 impossible to handle.
 */
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:1503) The function 'E2E_P01Protect' is defined
 *                 but is not used within this project.
 * Justification : Library-API-function used by application.                 */
/* PRQA S 1503 5                                                             */
FUNC (Std_ReturnType, E2E_CODE) E2E_P01Protect
(
    P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) Config,
    P2VAR (E2E_P01SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
    P2VAR (uint8, AUTOMATIC, E2E_APPL_DATA) Data
)
{
    Std_ReturnType status_t = E2E_E_OK;

    if (  (Data   == NULL_PTR)
       || (Config == NULL_PTR)
       || (State  == NULL_PTR)
      )
    {
        status_t = E2E_E_INPUTERR_NULL;
    }
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(7:0505) [U] Dereferencing pointer value that is       */
/*                 apparently NULL.
 * Justification : if-statement above guarantees that 'Config' and 'State'
 *                 and 'Data' are not NULL from this point on.               */
/* PRQA S 505 90                                                             */
    if (status_t == E2E_E_OK)
    {
        if (  (Config->DataLength       <  E2E_MIN_PROF1_DATALENGTH)
           || (Config->DataLength       >  E2E_MAX_PROF1_DATALENGTH)
           || ((Config->DataLength % 8) != 0)
           || (  (Config->DataIDMode != E2E_P01_DATAID_BOTH)
              && (Config->DataIDMode != E2E_P01_DATAID_ALT)
              && (Config->DataIDMode != E2E_P01_DATAID_LOW)
              )
           )
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        uint16 offset_delta_u16 = Config->CounterOffset - Config->CRCOffset;
        if (  (Config->CRCOffset           >  (Config->DataLength - 8))
           || ((Config->CRCOffset % 8)     != 0)
           || (Config->CounterOffset       >  (Config->DataLength - 4))
           || ((Config->CounterOffset % 4) != 0)
           || (offset_delta_u16            == 0)
           || (offset_delta_u16            == 4)
           )
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        if (State->Counter > E2E_MAX_COUNTER_PROF1_VAL)
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        uint8  cnt_byte_u8;
        uint8  crc_u8;
        uint8* cntpos_pu8;
        uint8  nibble1_u8;
        uint8  nibble2_u8;
        uint8  tmp_u8;
        uint16 tmp_u16;

        tmp_u16     = Config->CounterOffset / 8;
        cntpos_pu8  = &Data[tmp_u16];
        cnt_byte_u8 = *cntpos_pu8;

        if( (Config->CounterOffset % 8) == 0 )
        {
            nibble1_u8  = (cnt_byte_u8 & (uint8)(~E2E_P01_COUNTER_MSK));
            nibble2_u8  = (State->Counter & E2E_P01_COUNTER_MSK);
            cnt_byte_u8 = nibble1_u8 | nibble2_u8;

        }
        else
        {
            nibble1_u8  = (cnt_byte_u8 & E2E_P01_COUNTER_MSK);
            tmp_u8      = (uint8)(State->Counter << E2E_COUNTER_PROF1B_POS);
            nibble2_u8  = (tmp_u8 & (uint8)(~E2E_P01_COUNTER_MSK));
            cnt_byte_u8 = nibble1_u8 | nibble2_u8;
        }
        *cntpos_pu8 = cnt_byte_u8;

        crc_u8         = e2e_p01_calc_crc( Config, Data, State->Counter );
        tmp_u16        = Config->CRCOffset / 8;
        Data[tmp_u16]  = crc_u8;
        State->Counter = E2E_P01_UpdateCounter(State->Counter);
    }

    return(status_t);
}

/**
 * @metric PATH >80  Number of Paths: Code-structure specified by
 *                                 AUTOSAR "Spec.of EndtoEnd Comm.
 *                                 Prot.", #428.
 *                                 Parameter-checks are splitted in several
 *                                 'if's, otherwise coverage-analysis is
 *                                 impossible to handle.
 */
/**
 * @metric LEVEL >4 Number of call levels: Code-structure specified by
 *                                         AUTOSAR "Spec.of EndtoEnd Comm.
 *                                         Prot.", #428,
 *                                         E2E0196. Split into sub-function
 *                                         is not wise because of performance
 *                                         reasons.
 */
/**
 * @metric v(G) >10 Number of call levels: Code-structure specified by
 *                                         AUTOSAR "Spec.of EndtoEnd Comm.
 *                                         Prot.", #428,
 *                                         E2E0196. Split into sub-function
 *                                         is not wise because of performance
 *                                         reasons.
 */
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(4:1503) The function 'E2E_P01Check' is
 *                 defined but is not used within this project.
 * Justification : Library-API-function used by application.                 */
/* PRQA S 1503 5                                                             */
FUNC (Std_ReturnType, E2E_CODE) E2E_P01Check
(
    P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) Config,
    P2VAR (E2E_P01ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
    P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) Data
)
{
    Std_ReturnType status_t = E2E_E_OK;

    if (  (Data   == NULL_PTR)
       || (Config == NULL_PTR)
       || (State  == NULL_PTR)
       )
    {
        status_t = (E2E_E_INPUTERR_NULL);
    }
/* ------------------------------------------------------------------------- */
/*                        SUPRESSED MISRA VIOLATONS                          */
/* ------------------------------------------------------------------------- */
/* Error Message : Msg(7:0505) [U] Dereferencing pointer value that is       */
/*                 apparently NULL.
 * Justification : if-statement above guarantees that 'Config' and 'State'
 *                 and 'Data' are not NULL from this point on.               */
/* PRQA S 505 130                                                            */
    if (status_t == E2E_E_OK)
    {
        if (  (Config->DataLength       <  E2E_MIN_PROF1_DATALENGTH)
           || (Config->DataLength       >  E2E_MAX_PROF1_DATALENGTH)
           || ((Config->DataLength % 8) != 0)
           || (  (Config->DataIDMode != E2E_P01_DATAID_BOTH)
              && (Config->DataIDMode != E2E_P01_DATAID_ALT)
              && (Config->DataIDMode != E2E_P01_DATAID_LOW)
              )
           )
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        uint16 offset_delta_u16 = Config->CounterOffset - Config->CRCOffset;
        if (  (Config->CRCOffset           >  (Config->DataLength - 8))
           || ((Config->CRCOffset % 8)     != 0)
           || (Config->CounterOffset       >  (Config->DataLength - 4))
           || ((Config->CounterOffset % 4) != 0)
           || (offset_delta_u16            == 0)
           || (offset_delta_u16            == 4)
           )
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        if (  (Config->MaxDeltaCounterInit >= E2E_MAX_COUNTER_PROF1_VAL)
           || (State->MaxDeltaCounter      >  E2E_MAX_COUNTER_PROF1_VAL)
           || (  (State->WaitForFirstData  != TRUE)
              && (State->WaitForFirstData  != FALSE)
              )
           || (  (State->NewDataAvailable  != TRUE)
              && (State->NewDataAvailable  != FALSE)
              )
           || (State->LastValidCounter > E2E_MAX_COUNTER_PROF1_VAL)
           )
        {
            status_t = (E2E_E_INPUTERR_WRONG);
        }
    }

    if (status_t == E2E_E_OK)
    {
        uint8 tmp_u8;
        uint8 rxcounter_u8;
        uint8 delta_rxcounter_u8;
        uint8 rxcrc_u8;
        uint8 crc_u8;

        /* MaxDeltaCounter = min(MaxDeltaCounter+1, 14) */
        tmp_u8 = State->MaxDeltaCounter + 1;
        if( tmp_u8 <= E2E_MAX_COUNTER_PROF1_VAL )
        {
            State->MaxDeltaCounter = (uint8)tmp_u8;
        }
        else
        {
            State->MaxDeltaCounter = E2E_MAX_COUNTER_PROF1_VAL;
        }

        if( State->NewDataAvailable != FALSE)
        {
            /* extract sequence counter from received PDU */
            rxcounter_u8 = Data[Config->CounterOffset / 8];
            if( (Config->CounterOffset % 8) != 0 )
            {
                rxcounter_u8 = (uint8)(rxcounter_u8 >> E2E_COUNTER_PROF1B_POS);
            }
            rxcounter_u8 &= E2E_P01_COUNTER_MSK;

            /* extract CRC from received PDU */
            rxcrc_u8 = Data[Config->CRCOffset / 8];

            /* calculate CRC over received PDU */
            crc_u8   = e2e_p01_calc_crc( Config, Data, rxcounter_u8);

            /* check crc */
            if( crc_u8 != rxcrc_u8 )
            {
                State->Status = E2E_P01STATUS_WRONGCRC;
            }
            else
            {
                /* if first PDU is received, synchonise rx counters but do
                 * not check them
                 */
                if( State->WaitForFirstData != FALSE )
                {
                    State->WaitForFirstData = FALSE;
                    State->MaxDeltaCounter  = Config->MaxDeltaCounterInit;
                    State->LastValidCounter = rxcounter_u8;

                    State->Status = E2E_P01STATUS_INITIAL;
                }
                else
                {
                    /* get difference between last valid received PDU and
                     * actual PDU
                     */
                    tmp_u8 = State->LastValidCounter;
                    delta_rxcounter_u8 =
                        (uint8)(rxcounter_u8 - tmp_u8) & E2E_P01_COUNTER_MSK;
                    if( tmp_u8 > rxcounter_u8 )
                    {
                        /* lower delta_rxcounter by 1 because counter only
                         * goes up to 14 -> diff is one less
                         */
                        delta_rxcounter_u8--;
                    }

                    if( delta_rxcounter_u8 == 0 )
                    {
                        State->Status           = E2E_P01STATUS_REPEATED;
                    }
                    else if( delta_rxcounter_u8 == 1 )
                    {
                        State->MaxDeltaCounter  = Config->MaxDeltaCounterInit;
                        State->LastValidCounter = rxcounter_u8;
                        State->LostData         = 0;
                        State->Status           = E2E_P01STATUS_OK;
                    }
                    else if( delta_rxcounter_u8 <= State->MaxDeltaCounter )
                    {
                        State->MaxDeltaCounter  = Config->MaxDeltaCounterInit;
                        State->LastValidCounter = rxcounter_u8;

                        State->LostData         = delta_rxcounter_u8 - 1;
                        State->Status           = E2E_P01STATUS_OKSOMELOST;
                    }
                    else /* delta_rxcounter_u8 > State->MaxDeltaCounter */
                    {
                        State->Status           = E2E_P01STATUS_WRONGSEQUENCE;
                    }
                }
            }
        }
        else
        {
            State->Status = E2E_P01STATUS_NONEWDATA;
        }
    }

    return(status_t);
}

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
