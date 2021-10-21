/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComOutput2_SrlComDISPCCEPS_SrlComDISPCCEPS_tx.c
 ** Sat, 06-Aug-2016, 15:31:02
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
 * MISRA RULE 13.7 VIOLATION:
 * Error Message : Msg(4:3355) The result of this logical
 *   operation is always 'true'. MISRA-C:2004 Rule 13.7
 * Justification : code-block are unified which
 *   significantly simplifies code-generation process
 *   (decreases chances of bugs)
 **********************************************************/
/* PRQA S 3355 EOF */
/**********************************************************
 * MISRA RULE 13.7 VIOLATION:
 * Error Message : Msg(4:3358) The value of this 'if'
 *   control expression is always 'true'.
 *   MISRA-C:2004 Rule 13.7
 * Justification : code-block are unified which
 *   significantly simplifies code-generation process
 *   (decreases chances of bugs)
 **********************************************************/
/* PRQA S 3358 EOF */
#include "E2EPW_Marshal_Ap_SrlComOutput2_SrlComDISPCCEPS.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComDISPCCEPS_SrlComDISPCCEPS_tx.h"

#define E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

STATIC VAR (E2E_P01SenderStateType, E2EPW_VAR)
    StateVal_SrlComDISPCCEPS_DISP_CC_EPS =
{
    0  /* Counter */
};

STATIC P2VAR (E2E_P01SenderStateType
             , E2EPW_VAR, E2EPW_APPL_DATA
             ) State_SrlComDISPCCEPS_DISP_CC_EPS =
    &StateVal_SrlComDISPCCEPS_DISP_CC_EPS;

#define E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Memmap.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComDISPCCEPS_DISP_CC_EPS_tx ()
 * Description:   Initialize the transmission-state (eg. after
 *                an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComDISPCCEPS_DISP_CC_EPS_tx (void)
{
    State_SrlComDISPCCEPS_DISP_CC_EPS->Counter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SrlComDISPCCEPS_DISP_CC_EPS ()
 * Description:   Returns the current E2Elib transmission
 *                -state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Not required for usage. For debugging or
 *                similar reasons.
 **********************************************************/
FUNC ( P2VAR ( E2E_P01SenderStateType
             , AUTOMATIC
             , E2EPW_APPL_DATA
             )
     , E2EPW_CODE
     )
    E2EPW_Get_SenderState_SrlComDISPCCEPS_DISP_CC_EPS (void)
{
    return State_SrlComDISPCCEPS_DISP_CC_EPS;
}

/**********************************************************
 * Function name: E2EPW_Write_SrlComDISPCCEPS_DISP_CC_EPS (SG_DISP_CC_EPS *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, E2EPW_CODE) E2EPW_Write_SrlComDISPCCEPS_DISP_CC_EPS
    (P2VAR (SG_DISP_CC_EPS, AUTOMATIC, E2EPW_APPL_DATA) AppData)
{
    /* Protected PDU area: */
    VAR (uint8, AUTOMATIC) ppa_au8 [5];
    VAR (uint8, AUTOMATIC) ret_u8;

    CONST (uint32, AUTOMATIC) status_ok_u32 =
          (0       <<24)  /* unused */
        | (E2E_E_OK<<16)  /* Protection Wrapper */
        | (RTE_E_OK<<8)   /* Rte_Write */
        | (E2E_E_OK);     /* E2E_..Protect */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;
    STATIC CONST (E2E_P01ConfigType, AUTOMATIC)
        ConfigVal_SrlComDISPCCEPS_DISP_CC_EPS =
    {
          40
        , 76
        , E2E_P01_DATAID_BOTH
        , 0
        , 0
        , 8
    };

    STATIC P2CONST (E2E_P01ConfigType, AUTOMATIC, E2EPW_APPL_CONST)
        Config_SrlComDISPCCEPS_DISP_CC_EPS = &ConfigVal_SrlComDISPCCEPS_DISP_CC_EPS;

    if (AppData == NULL_PTR)
    {
        ret_u8 = E2E_E_INPUTERR_NULL;
        status_u32 &= 0xFF00FFFFU;
        status_u32 |= (((uint32)ret_u8)<<16);
    }

    if (status_u32 == status_ok_u32)
    {
        E2EPW_Marshal_SrlComDISPCCEPS ( AppData, ppa_au8 );
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Protect
                     ( Config_SrlComDISPCCEPS_DISP_CC_EPS
                     , State_SrlComDISPCCEPS_DISP_CC_EPS
                     , ppa_au8
                     );
        status_u32 &= 0xFFFFFF00U;
        status_u32 |= (ret_u8);
    }

    if (status_u32 == status_ok_u32)
    {
        uint16 crcoffset_u16 = Config_SrlComDISPCCEPS_DISP_CC_EPS->CRCOffset/8;
        uint16 cntoffset_u16 = Config_SrlComDISPCCEPS_DISP_CC_EPS->CounterOffset/8;
/**********************************************************
 * MISRA RULE 9.1 VIOLATION:
 * Error Message : Msg(4:3353) The variable 'ppa_au8' is
 *   possibly unset at this point. MISRA-C:2004 Rule 9.1
 * Justification : Set in E2EPW_Marshal_<pde> ()
 **********************************************************/
/* PRQA S 3353 9 */
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL. MISRA-C:2004 Rule 1.2
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
        AppData->CRC_DISP_CC_EPS = ppa_au8[crcoffset_u16];
        AppData->ALIV_DISP_CC_EPS = (ppa_au8[cntoffset_u16] & 0x0F);
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = Rte_Write_SrlComDISPCCEPS_DISP_CC_EPS ( AppData );
        status_u32 &= 0xFFFF00FFU;
        status_u32 |= (((uint32)ret_u8)<<8);
    }

    return status_u32;
}

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"
/*  << EOF >>  */
