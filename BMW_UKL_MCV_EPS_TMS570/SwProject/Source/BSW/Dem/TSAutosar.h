
#if (!defined TS_AUTOSAR_H)
#define TS_AUTOSAR_H

/** \brief DEM extension
 **
 ** \project AUTOSAR Standard Core
 ** \file TSAutosar.h
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: $
 ** Release: 2008.a.BMW.sr1_Dem_MPC_MPC5567
 **
 ** \controller independent
 ** \compiler independent
 ** \hardware independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup BSW Basic Software Module Definitions
 ** @{ */

/*==================[inclusions]=============================================*/

/*
 * This file is a stand-alone extension to the DEM module. It provides all
 * necessary elements, regularly located in the EB Base module (common for all
 * modules). So it is possible to integrate the DEM also in Autosar stacks
 * without using the EB Base module.
 *
 * Note: If the EB Base module is used, this extension must not be installed.
 */

#include <SchM_Dem.h>              /* for the locking of the exclusive areas */

/*==================[macros]=================================================*/

#if (defined TS_VENDOR_ID_3SOFT) /* guard to prevent double declaration */
#error TS_VENDOR_ID_3SOFT already defined
#endif /* if (defined TS_VENDOR_ID_3SOFT) */

/** \brief definition of the unique vendor ID
 *
 * This vendor ID is based on the vendor ID published by the HIS.
 * It should be used for each module */
#define TS_VENDOR_ID_3SOFT 1U

/**
 * Use the symbol to avoid compiler warnings
 */
#define TS_PARAM_UNUSED(x) (void) x

/*------------------[TS_AtomicSetBit]----------------------------------------*/

#if (defined TS_AtomicSetBit) /* guard to prevent double definition */
#error TS_AtomicSetBit already defined
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
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicSetBit(Address, Bit)                                 \
   do {                                                               \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) |= 1u << (Bit);                                      \
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  \
   } while (0)

/*------------------[TS_AtomicSetBit_32]-------------------------------------*/

#if (defined TS_AtomicSetBit_32) /* guard to prevent double definition */
#error TS_AtomicSetBit already defined
#endif /* if (defined TS_AtomicSetBit_32) */

/** \brief Set one bit of a 32 bit variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT #1: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicSetBit_32(Address, Bit)                              \
   do {                                                               \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) |= (uint32)1 << (Bit);                               \
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  \
   } while (0)

/*------------------[TS_AtomicClearBit]--------------------------------------*/

#if (defined TS_AtomicClearBit) /* guard to prevent double definition */
#error TS_AtomicClearBit already defined
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
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicClearBit(Address, Bit)                         \
   do {                                                         \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) &= ~(1u << (Bit));                             \
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  \
   } while (0)

/*------------------[TS_AtomicClearBit_32]-----------------------------------*/

#if (defined TS_AtomicClearBit_32) /* guard to prevent double definition */
#error TS_AtomicClearBit already defined
#endif /* if (defined TS_AtomicClearBit_32) */

/** \brief Clear one bit of a 32 bit variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT #1: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicClearBit_32(Address, Bit)                            \
   do {                                                               \
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); \
      *(Address) &= ~((uint32)1 << (Bit));                            \
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
#endif /* if !defined( TS_AUTOSAR_H ) */
/*==================[end of file]============================================*/
