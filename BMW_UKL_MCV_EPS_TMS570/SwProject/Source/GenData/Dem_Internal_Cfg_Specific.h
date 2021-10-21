#ifndef DEM_INTERNAL_CFG_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_CFG_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the all module internal configuration declarations for
 ** the AUTOSAR module Dem that are target independent, which is variant
 ** specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[includes]==============================================*/

#include <Dem_Internal_Cfg.h>                          /* Base class header */

/*==================[macros]================================================*/

/* macro to en-/disable immediate storage */
#if (defined DEM_USE_IMMSTORAGE)
#error DEM_USE_IMMSTORAGE already defined
#endif
#define DEM_USE_IMMSTORAGE         STD_ON

/* macro to use a global immediate storage flag (global flag is used if all
 * events have immediate storage enabled. */
#if (defined DEM_USE_IMMSTORAGE_GLOBAL)
#error DEM_USE_IMMSTORAGE_GLOBAL already defined
#endif
#define DEM_USE_IMMSTORAGE_GLOBAL  STD_OFF

/*------------------[Events configuration]----------------------------------*/

/* Static value width in bits used for Dem_EventDescSpecificType */

#if (defined DEM_IMMSTORAGE_WIDTH)
#error DEM_IMMSTORAGE_WIDTH already defined
#endif
#define DEM_IMMSTORAGE_WIDTH           1U

#if (defined DEM_ROEACTIVE_WIDTH)
#error DEM_ROEACTIVE_WIDTH already defined
#endif
#define DEM_ROEACTIVE_WIDTH            1U

/*------------------[RTE- / C-Callback macros]------------------------------*/

#if (defined DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE)
#error DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE already defined
#endif
#define DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE 0U

#if (defined DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
#error DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE already defined
#endif
#define DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE 1U

#if (defined DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
#error DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE already defined
#endif
#define DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE 0U

#if (defined DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE)
#error DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE already defined
#endif
#define DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE 1U

#if (defined DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE)
#error DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE already defined
#endif
#define DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE 87U

#if (defined DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE)
#error DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE already defined
#endif
#define DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE 0U

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_CFG_SPECIFIC_H */
/*==================[end of file]===========================================*/
