/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SrlComSGTARSTMOMDVACT_rx.c
 ** Mon, 07-Jan-2013, 15:16:40
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
#include "E2EPW_Marshal_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT.h"
#include "E2EPW_CheckDeserial_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SrlComSGTARSTMOMDVACT_rx.h"

#define E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

STATIC VAR (E2E_P01ReceiverStateType, E2EPW_VAR)
    StateVal_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
};

STATIC P2VAR (E2E_P01ReceiverStateType, E2EPW_VAR, E2EPW_APPL_DATA)
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT =
        &StateVal_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT;

#define E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_rx (void)
 * Description:   Initialize the E2Elib receiver-state (eg.
 *                after an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_rx (void)
{
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->LastValidCounter = 0;
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->MaxDeltaCounter  = 0;
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->WaitForFirstData = TRUE;
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->NewDataAvailable = FALSE;
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->LostData         = 0;
    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->Status           = E2E_P01STATUS_NONEWDATA;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT (void)
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
    E2EPW_Get_ReceiverState_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT (void)
{
    return State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT;
}

/**********************************************************
 * Function name: E2EPW_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT (SG_TAR_STMOM_DV_ACT * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, E2EPW_CODE) E2EPW_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
    (P2VAR (SG_TAR_STMOM_DV_ACT, AUTOMATIC, E2EPW_APPL_DATA) AppData)
{
    /* Protected PDU area: */
    STATIC VAR (uint8, AUTOMATIC)
        ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8 [8];
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
        ConfigVal_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT =
    {
          64
        , 179
        , E2E_P01_DATAID_BOTH
        , 13
        , 0
        , 8
    };

    STATIC P2CONST (E2E_P01ConfigType, AUTOMATIC, E2EPW_APPL_CONST)
        Config_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT = &ConfigVal_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT;

    State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->NewDataAvailable = TRUE;

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
            ret_rte_u8 = Rte_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_SrlComSGTARSTMOMDVACT (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->CRCOffset/8;
            uint16 cntoffset_u16 = Config_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->CounterOffset/8;
            E2EPW_Marshal_SrlComSGTARSTMOMDVACT ( AppData, ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL. MISRA-C:2004 Rule 1.2
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1 */
            ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8[crcoffset_u16]  = AppData->CRC_TAR_STMOM_DV_ACT;
            ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8[cntoffset_u16] |= AppData->ALIV_TAR_STMOM_DV_ACT;
        }

    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
                     , State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
                     , ppa_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"
/*  << EOF >>  */
