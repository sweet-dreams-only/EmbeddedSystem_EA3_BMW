/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 1.1.0)
 ** Module: E2EPW_Marshal_Ap_SrlComOutput2_SrlComSUEPS.c
 ** Tue, 19-Jul-2016, 13:53:18
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

#include "E2EPW_Marshal_Ap_SrlComOutput2_SrlComSUEPS.h"

#define E2EPW_START_SEC_CODE_LIB
#include "Memmap.h"

/*****************************************************************
 * Function name      : E2EPW_Marshal_SrlComSUEPS
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ****************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SrlComSUEPS
    ( P2CONST (RT_SG_SU_EPS, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_DATA) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal TOT_STR_EPS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TOT_STR_EPS);
    ppa[0]  = src[1];
    ppa[1]  = src[0] & 0x0f;

    /* packing signal UN_TOT_STR_EPS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->UN_TOT_STR_EPS);
    ppa[1] |= (src[0] << 4) & 0x30;

    /* packing signal SU_EPS_0x0E_0x20 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SU_EPS_0x0E_0x20);
    ppa[1] |= (src[3] << 6) & 0xc0;
    ppa[2]  = (src[3] >> 2) & 0x3f;
    ppa[2] |= (src[2] << 6) & 0xc0;
    ppa[3]  = (src[2] >> 2) & 0x3f;
    ppa[3] |= (src[1] << 6) & 0xc0;
    ppa[4]  = (src[1] >> 2) & 0x3f;
    ppa[4] |= (src[0] << 6) & 0xc0;
    ppa[5]  = (src[0] >> 2) & 0x3f;

    /* packing signal SU_EPS_0x2E_0x06 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SU_EPS_0x2E_0x06);
    ppa[5] |= (src[0] << 6) & 0xc0;
    ppa[6] &= 0xf0;
    ppa[6] |= (src[0] >> 2) & 0x0f;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "Memmap.h"

/*  << EOF >>  */
