/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComInput2_SrlComSTCENG_SrlComSTCENG_rx.c
 ** Thu, 19-May-2016, 09:57:18
 **/

/**********************************************************
 * MISRA RULE 14.1 VIOLATION:
 * Error Message : Msg(4:1503) The function '<name>' is
 *   defined but is not used within this project.
 *   MISRA-C:2004 Rule 14.1
 * Justification : Library functions
 **********************************************************/
/* PRQA S 1503 EOF */
/**********************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a
 *   file should only be preceded by other preprocessor
 *   directives or comments. MISRA-C:2004 Rule 19.1
 * Justification : Inclusion of memmap.h is AUTOSAR
 *   specific
 **********************************************************/
/* PRQA S 5087 EOF */
/**********************************************************
 * MISRA RULE 'Metrics VOCF<=4' VIOLATION:
 * Code-structure based on by AUTOSAR 'Spec.of EndtoEnd
 * Communication Protection', R3.2.1 V1.2.0./
 * and '893.061.D_End-to-End Kommunikationsabsicherung_v1.5'
 **********************************************************/
#include "E2EPW_Marshal_Ap_SrlComInput2_SrlComSTCENG.h"
#include "E2EPW_CheckDeserial_Ap_SrlComInput2_SrlComSTCENG.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSTCENG_SrlComSTCENG_rx.h"

#define E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

STATIC VAR (E2E_P01ReceiverStateType, E2EPW_VAR)
    StateVal_SrlComSTCENG_ST_CENG =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
};

STATIC P2VAR (E2E_P01ReceiverStateType, E2EPW_VAR, E2EPW_APPL_DATA)
    State_SrlComSTCENG_ST_CENG =
        &StateVal_SrlComSTCENG_ST_CENG;

#define E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComSTCENG_ST_CENG_rx (void)
 * Description:   Initialize the E2Elib receiver-state (eg.
 *                after an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComSTCENG_ST_CENG_rx (void)
{
    State_SrlComSTCENG_ST_CENG->LastValidCounter = 0;
    State_SrlComSTCENG_ST_CENG->MaxDeltaCounter  = 0;
    State_SrlComSTCENG_ST_CENG->WaitForFirstData = TRUE;
    State_SrlComSTCENG_ST_CENG->NewDataAvailable = FALSE;
    State_SrlComSTCENG_ST_CENG->LostData         = 0;
    State_SrlComSTCENG_ST_CENG->Status           = E2E_P01STATUS_NONEWDATA;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SrlComSTCENG_ST_CENG (void)
 * Description:   Returns the current E2Elib receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status
 * Remarks:       Not required for usage. For debugging or
 *                similar reasons.
 **********************************************************/
FUNC ( P2VAR ( E2E_P01ReceiverStateType
             , AUTOMATIC
             , E2EPW_APPL_DATA
             )
     , E2EPW_CODE
     )
    E2EPW_Get_ReceiverState_SrlComSTCENG_ST_CENG (void)
{
    return State_SrlComSTCENG_ST_CENG;
}

/**********************************************************
 * Function name: E2EPW_Read_SrlComSTCENG_ST_CENG (SG_ST_CENG * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, E2EPW_CODE) E2EPW_Read_SrlComSTCENG_ST_CENG
    (P2VAR (SG_ST_CENG, AUTOMATIC, E2EPW_APPL_DATA) AppData)
{
    /* Protected PDU area: */
    STATIC VAR (uint8, AUTOMATIC)
        ppa_SrlComSTCENG_ST_CENG_au8 [8];
    VAR (uint8, AUTOMATIC) ret_u8;
    VAR (uint8, AUTOMATIC) ret_rte_u8 = RTE_E_OK;

    CONST (uint32, AUTOMATIC) status_ok_u32 =
           (0<<31)                         /* Deserial-Check */
        |  ((E2E_P01STATUS_OK & 0x7F)<<24) /* ReceiverStatus */
        |  (E2E_E_OK<<16)                  /* Protection Wrapper */
        |  (RTE_E_OK<<8)                   /* Rte_Read */
        |  (E2E_E_OK);                     /* E2E_...Check */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    STATIC CONST (E2E_P01ConfigType, AUTOMATIC)
        ConfigVal_SrlComSTCENG_ST_CENG =
    {
          64
        , 120
        , E2E_P01_DATAID_BOTH
        , 13
        , 0
        , 8
    };

    STATIC P2CONST (E2E_P01ConfigType, AUTOMATIC, E2EPW_APPL_CONST)
        Config_SrlComSTCENG_ST_CENG = &ConfigVal_SrlComSTCENG_ST_CENG;

    State_SrlComSTCENG_ST_CENG->NewDataAvailable = TRUE;

    {
        if (AppData == NULL_PTR)
        {
            ret_u8 = E2E_E_INPUTERR_NULL;
            status_u32 &= 0xFF00FFFFU;
            status_u32 |= (((uint32)ret_u8)<<16);
        }

        if (status_u32 == status_ok_u32)
        {
            /* Return-value of Rte_Read does not affect
               following workflow.
            */
            ret_rte_u8 = Rte_Read_SrlComSTCENG_ST_CENG (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_SrlComSTCENG (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_SrlComSTCENG_ST_CENG->CRCOffset/8;
            uint16 cntoffset_u16 = Config_SrlComSTCENG_ST_CENG->CounterOffset/8;
            E2EPW_Marshal_SrlComSTCENG ( AppData, ppa_SrlComSTCENG_ST_CENG_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL. MISRA-C:2004 Rule 1.2
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1 */
            ppa_SrlComSTCENG_ST_CENG_au8[crcoffset_u16]  = AppData->CRC_ST_CENG;
            ppa_SrlComSTCENG_ST_CENG_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_SrlComSTCENG_ST_CENG_au8[cntoffset_u16] |= AppData->ALIV_ST_CENG;
        }

    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_SrlComSTCENG_ST_CENG
                     , State_SrlComSTCENG_ST_CENG
                     , ppa_SrlComSTCENG_ST_CENG_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_SrlComSTCENG_ST_CENG->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"
/*  << EOF >>  */
