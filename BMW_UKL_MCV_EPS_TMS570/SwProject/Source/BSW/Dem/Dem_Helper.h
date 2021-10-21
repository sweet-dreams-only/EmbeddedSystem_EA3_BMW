#ifndef DEM_HELPER_H
/** \brief preprocessor exclusion definition */
#define DEM_HELPER_H

/** \brief Convenience Header to include helper macros
 **
 ** \project AUTOSAR Standard Core
 ** \file Dem_Helper.h
 ** \author Oliver Hoeft
 ** \author Elektrobit GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Helper.h 3233 2008-10-02 15:07:53Z thga2649 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler independent
 ** \hardware independent
 **
 ** Copyright 2010 by Elektrobit GmbH
 ** All rights exclusively reserved for Elektrobit GmbH,
 ** unless expressly agreed to otherwise
 **
 **/

/**  MISRA-C:2004 Deviation List
 **
 **  MISRA-1) Deviated Rule: 19.7 (advisory)
 **   A function should be used in preference to a function-like macro.
 **
 **   Reason:
 **   As the function is called very often and consists only of a one line
 **   the macro based implmentation is more run time efficient.
 **
 **/

/** \addtogroup BSW Basic Software Module Definitions
 ** @{ */

/*==================[inclusions]=============================================*/

#include <SchM_Dem.h>              /* for the locking of the exclusive areas */

/*==================[macros]=================================================*/

#if (defined DEM_VENDOR_ID_3SOFT) /* guard to prevent double declaration */
#error DEM_VENDOR_ID_3SOFT already defined
#endif /* if (defined DEM_VENDOR_ID_3SOFT) */

/** \brief definition of the unique vendor ID
 *
 * This vendor ID is based on the vendor ID published by the HIS.
 * It should be used for each module */
#define DEM_VENDOR_ID_3SOFT 1U

/**
 * Use the symbol to avoid compiler warnings
 */
/* Deviation MISRA-1 */
#define DEM_PARAM_UNUSED(x) (void) (x)

/*------------------[TS_AtomicClearBit]--------------------------------------*/

#if (defined Dem_AtomicClearBit) /* guard to prevent double definition */
#error Dem_AtomicClearBit already defined
#endif /* if (defined TS_AtomicClearBit) */

/** \brief Clear one bit of a variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT #1: on architectures where the int type has 16 bits this macro
 ** can only be used for 8 and 16 bit types.
 ** It fails for 32 bit types!
 ** CAVEAT #2: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change
 **/
#define Dem_AtomicClearBit(Address, Bit)                              \
   do {                                                               \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) &= ~(1u << (Bit));                                   \
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  \
   } while (0)

/*------------------[TS_AtomicSetBit]----------------------------------------*/

#if (defined Dem_AtomicSetBit) /* guard to prevent double definition */
#error Dem_AtomicSetBit already defined
#endif /* if (defined TS_AtomicSetBit) */

/** \brief Set one bit of a variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT #1: on architectures where the int type has 16 bits this macro
 ** can only be used for 8 and 16 bit types.
 ** It fails for 32 bit types!
 ** Those operations should be done using the 32 bit macro below.
 **
 ** CAVEAT #2: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change
 **/
/* Deviation MISRA-1 */
#define Dem_AtomicSetBit(Address, Bit)                                \
   do {                                                               \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) |= 1u << (Bit);                                      \
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  \
   } while (0)


/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_HELPER_H */
/*==================[end of file]============================================*/
