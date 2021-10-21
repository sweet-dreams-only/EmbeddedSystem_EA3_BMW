/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Marshal_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV.c
 ** Mon, 08-Feb-2016, 13:57:57
 **/

/* ------------------------------------------------------- */
/*                 SUPRESSED MISRA VIOLATONS               */
/* ------------------------------------------------------- */
/* Error Message : Msg(4:5087) #include statements in a    */
/*   file should only be preceded by other preprocessor    */
/*   directives or comments. MISRA-C:2004 Rule 19.1        */
/* Justification : Inclusion of memmap.h is AUTOSAR        */
/*   specific.                                             */
/* PRQA S 5087 EOF                                         */

/* Error Message : Msg(4:0310) Casting to different object */
/*   pointer type. MISRA-C:2004 Rule 11.4;                 */
/*   REFERENCE - ISO-6.3.4 Cast Operators                  */
/* Justification : Marshal code works on direct byte       */
/*   access for different application types.               */
/* PRQA S 0310 EOF                                         */

/* Error Message : Msg(4:3757) Implicit conversion: int    */
/*   to unsigned char.  MISRA-C:2004 Rule 10.1             */
/* Justification : Marshal code generator ensures no loss  */
/*   of data during endianness conversion.                 */
/* PRQA S 3757 EOF                                         */

#include "E2EPW_Marshal_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV.h"

#define E2EPW_START_SEC_CODE_LIB
#include "Memmap.h"

/*****************************************************************
 * Function name      : E2EPW_Marshal_SrlComSGTARQTASTRMOMDV
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ****************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SrlComSGTARQTASTRMOMDV
    ( P2CONST (SG_TAR_QTA_STRMOM_DV, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_DATA) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal FACT_CTRR_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->FACT_CTRR_STMOM_FTAX);
    ppa[4]  = src[0];

    /* packing signal QU_TAR_FACT_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_TAR_FACT_STMOM_FTAX);
    ppa[7]  = src[0] & 0x0f;

    /* packing signal QU_TAR_QTA_STMOM_DV */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_TAR_QTA_STMOM_DV);
    ppa[3]  = (src[0] << 4) & 0xf0;

    /* packing signal FACT_ASS_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->FACT_ASS_STMOM_FTAX);
    ppa[6]  = src[0];

    /* packing signal FACT_DMPNG_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->FACT_DMPNG_STMOM_FTAX);
    ppa[5]  = src[0];

    /* packing signal TAR_QTA_STMOM_DV */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TAR_QTA_STMOM_DV);
    ppa[2]  = src[1];
    ppa[3] |= src[0] & 0x0f;

    /* packing signal CTR_DEAC_EPS_FNS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CTR_DEAC_EPS_FNS);
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* fill unused areas */
    ppa[1] |= 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "Memmap.h"

/*  << EOF >>  */
