/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SrlComSGTARQTASTRMOMDV_rx.c
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
#include "E2EPW_Marshal_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV.h"
#include "E2EPW_CheckDeserial_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SrlComSGTARQTASTRMOMDV_rx.h"

#define E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

STATIC VAR (E2E_P01ReceiverStateType, E2EPW_VAR)
    StateVal_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
};

STATIC P2VAR (E2E_P01ReceiverStateType, E2EPW_VAR, E2EPW_APPL_DATA)
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV =
        &StateVal_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV;

#define E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_rx (void)
 * Description:   Initialize the E2Elib receiver-state (eg.
 *                after an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_rx (void)
{
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->LastValidCounter = 0;
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->MaxDeltaCounter  = 0;
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->WaitForFirstData = TRUE;
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->NewDataAvailable = FALSE;
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->LostData         = 0;
    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->Status           = E2E_P01STATUS_NONEWDATA;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV (void)
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
    E2EPW_Get_ReceiverState_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV (void)
{
    return State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV;
}

/**********************************************************
 * Function name: E2EPW_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV (SG_TAR_QTA_STRMOM_DV * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, E2EPW_CODE) E2EPW_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
    (P2VAR (SG_TAR_QTA_STRMOM_DV, AUTOMATIC, E2EPW_APPL_DATA) AppData)
{
    /* Protected PDU area: */
    STATIC VAR (uint8, AUTOMATIC)
        ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8 [8];
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
        ConfigVal_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV =
    {
          64
        , 109
        , E2E_P01_DATAID_BOTH
        , 13
        , 0
        , 8
    };

    STATIC P2CONST (E2E_P01ConfigType, AUTOMATIC, E2EPW_APPL_CONST)
        Config_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV = &ConfigVal_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV;

    State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->NewDataAvailable = TRUE;

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
            ret_rte_u8 = Rte_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_SrlComSGTARQTASTRMOMDV (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->CRCOffset/8;
            uint16 cntoffset_u16 = Config_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->CounterOffset/8;
            E2EPW_Marshal_SrlComSGTARQTASTRMOMDV ( AppData, ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL. MISRA-C:2004 Rule 1.2
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1 */
            ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8[crcoffset_u16]  = AppData->CRC_TAR_QTA_STMOM_DV;
            ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8[cntoffset_u16] |= AppData->ALIV_TAR_QTA_STMOM_DV;
        }

    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
                     , State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
                     , ppa_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"
/*  << EOF >>  */
