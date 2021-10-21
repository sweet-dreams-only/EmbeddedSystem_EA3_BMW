/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComOutput2_SrlComDTEST_SrlComDTEST_tx.h
 ** Mon, 08-Feb-2016, 13:57:57
 **/

/**********************************************************
 * MISRA RULE Msg(3:3210) VIOLATION:
 * Error Message : Msg(3:3210) The global identifier
 *   '<name>' is declared but is not used.
 * Justification : Library function
 **********************************************************/
/* PRQA S 3210 EOF */
#ifndef E2EPW_Ap_SrlComOutput2_SrlComDTEST_SrlComDTEST_TX_H
#define E2EPW_Ap_SrlComOutput2_SrlComDTEST_SrlComDTEST_TX_H

#include "Rte_Ap_SrlComOutput2.h"
#include "Rte_Type.h"
#include "E2E_P01.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComDTEST_DT_EST_tx ()
 * Description:   Initialize the transmission-state (eg. after
 *                an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
extern FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComDTEST_DT_EST_tx (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SrlComDTEST_DT_EST ()
 * Description:   Returns the current E2Elib transmission
 *                -state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Not required for usage. For debugging or
 *                similar reasons.
 **********************************************************/
extern FUNC ( P2VAR ( E2E_P01SenderStateType
             , AUTOMATIC
             , E2EPW_APPL_DATA
             )
     , E2EPW_CODE
     )
    E2EPW_Get_SenderState_SrlComDTEST_DT_EST (void);

/**********************************************************
 * Function name: E2EPW_Write_SrlComDTEST_DT_EST (SG_DT_EST *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, E2EPW_CODE) E2EPW_Write_SrlComDTEST_DT_EST
    (P2VAR (SG_DT_EST, AUTOMATIC, E2EPW_APPL_DATA) AppData);

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"

#endif
/*  << EOF >>  */
