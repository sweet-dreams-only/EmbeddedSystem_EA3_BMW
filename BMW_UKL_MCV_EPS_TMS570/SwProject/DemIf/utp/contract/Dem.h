#if (!defined DEM_H)
/** \brief preprocessor exclusion definition */
#define DEM_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains or includes all external identifiers of
 ** the AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem.h 2061 2010-01-18 12:10:39Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

/* 1. The following include has to be done before including header-file(s)
 *    depending on the provided RTE type definitions */
//Removed in UTP Contract version to eliminate QAC syntax error - #include <Dem_Api_Depend_Specific.h>  /* Module public API, config. depend. */

/* 2. The following include depends on RTE type definitions included before */
//Removed in UTP Contract version to eliminate QAC syntax error - #include <Dem_RteApi_Static_Specific.h> /* publ API, Dem <-> SWC,BSW I-face */
//Removed in UTP Contract version to eliminate QAC syntax error - #include <Dem_RteApi_Depend_Specific.h> /* publ API, Dem <-> SWC,BSW I-face */

typedef uint8  Dem_EventIdType;
typedef uint8 Dem_EventStatusType;
typedef uint8 Dem_ReturnControlEventUpdateType;
typedef uint32 Dem_DTCGroupType;
typedef uint8 Dem_DTCKindType;

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

extern FUNC(void, DEM_CODE) Dem_Init(void);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState);
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_DisableEventStatusUpdate(Dem_DTCGroupType DTCGroup, Dem_DTCKindType  DTCKind);
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_EnableEventStatusUpdate(Dem_DTCGroupType DTCGroup, Dem_DTCKindType  DTCKind);
extern FUNC(void, DEM_CODE) Dem_Shutdown(void);
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* if !defined( DEM_H ) */
/*==================[end of file]===========================================*/
