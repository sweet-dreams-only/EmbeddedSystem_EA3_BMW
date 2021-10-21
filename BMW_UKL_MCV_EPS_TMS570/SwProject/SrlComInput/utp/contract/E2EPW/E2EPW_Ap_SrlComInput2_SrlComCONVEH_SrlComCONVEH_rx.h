/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComInput2_SrlComCONVEH_SrlComCONVEH_rx.h
 ** Mon, 08-Feb-2016, 13:57:57
 **/

/**********************************************************
 * MISRA RULE Msg(3:3210) VIOLATION:
 * Error Message : Msg(3:3210) The global identifier
 *   '<name>' is declared but is not used.
 * Justification : Library function
 **********************************************************/
/* PRQA S 3210 EOF */
#ifndef E2EPW_Ap_SrlComInput2_SrlComCONVEH_SrlComCONVEH_RX_H
#define E2EPW_Ap_SrlComInput2_SrlComCONVEH_SrlComCONVEH_RX_H

#include "Rte_Ap_SrlComInput2.h"
#include "Rte_Type.h"
#include "E2E_P01.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComCONVEH_CON_VEH_rx (void)
 * Description:   Initialize the E2Elib receiver-state (eg.
 *                after an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
extern FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComCONVEH_CON_VEH_rx (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SrlComCONVEH_CON_VEH (void)
 * Description:   Returns the current E2Elib receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status
 * Remarks:       Not required for usage. For debugging or
 *                similar reasons.
 **********************************************************/
extern FUNC ( P2VAR ( E2E_P01ReceiverStateType
             , AUTOMATIC
             , E2EPW_APPL_DATA
             )
     , E2EPW_CODE
     )
    E2EPW_Get_ReceiverState_SrlComCONVEH_CON_VEH (void);

/**********************************************************
 * Function name: E2EPW_Read_SrlComCONVEH_CON_VEH (SG_CON_VEH * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, E2EPW_CODE) E2EPW_Read_SrlComCONVEH_CON_VEH
    (P2VAR (SG_CON_VEH, AUTOMATIC, E2EPW_APPL_DATA) AppData);

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"

#endif
/*  << EOF >>  */
