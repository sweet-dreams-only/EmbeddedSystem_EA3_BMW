/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Ap_SrlComOutput2_SrlComAVLPOEPS_SrlComAVLPOEPS_tx.h
 ** Thu, 25-Oct-2012, 11:23:29
 **/

/**********************************************************
 * MISRA RULE Msg(3:3210) VIOLATION:
 * Error Message : Msg(3:3210) The global identifier
 *   '<name>' is declared but is not used.
 * Justification : Library function
 **********************************************************/
/* PRQA S 3210 EOF */
#ifndef E2EPW_Ap_SrlComOutput2_SrlComAVLPOEPS_SrlComAVLPOEPS_TX_H
#define E2EPW_Ap_SrlComOutput2_SrlComAVLPOEPS_SrlComAVLPOEPS_TX_H

#include "Rte_Ap_SrlComOutput2.h"
#include "Rte_Type.h"
#include "E2E_P01.h"

#define E2EPW_START_SEC_CODE
#include "Memmap.h"

/**********************************************************
 * Function name: E2EPW_Init_SrlComAVLPOEPS_AVL_PO_EPS_tx ()
 * Description:   Initialize the transmission-state (eg. after
 *                an application/communication reset.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication reset.
 **********************************************************/
extern FUNC (void, E2EPW_CODE) E2EPW_Init_SrlComAVLPOEPS_AVL_PO_EPS_tx (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SrlComAVLPOEPS_AVL_PO_EPS ()
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
    E2EPW_Get_SenderState_SrlComAVLPOEPS_AVL_PO_EPS (void);

/**********************************************************
 * Function name: E2EPW_Write_SrlComAVLPOEPS_AVL_PO_EPS (RT_SG_AVL_PO_EPS *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, E2EPW_CODE) E2EPW_Write_SrlComAVLPOEPS_AVL_PO_EPS
    (P2VAR (RT_SG_AVL_PO_EPS, AUTOMATIC, E2EPW_APPL_DATA) AppData);

#define E2EPW_STOP_SEC_CODE
#include "Memmap.h"

#endif
/*  << EOF >>  */
