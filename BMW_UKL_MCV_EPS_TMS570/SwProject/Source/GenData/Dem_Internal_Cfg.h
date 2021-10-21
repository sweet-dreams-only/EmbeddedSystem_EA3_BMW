

#ifndef DEM_INTERNAL_CFG_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_CFG_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the all module internal configuration declarations for
 ** the AUTOSAR module Dem that are target independent.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[includes]==============================================*/

/*------------------[callback header file inclusions]-----------------------*/

#include <Dem_Cbk.h>

/*==================[macros]================================================*/

/* macros for Dem_EventDescType */
#if (defined DEM_EVENTDESCTYPE_VAR0)
#error DEM_EVENTDESCTYPE_VAR0 already defined
#endif
#define DEM_EVENTDESCTYPE_VAR0   uint32

#if (defined DEM_EVENTDESCTYPE_VAR1)
#error DEM_EVENTDESCTYPE_VAR1 already defined
#endif
#define DEM_EVENTDESCTYPE_VAR1   uint8



/* macro to switch between runtime and ROM optimization */
#if (defined DEM_PFF_RUNTIME_OPTIMIZATION)
#error DEM_PFF_RUNTIME_OPTIMIZATION already defined
#endif
#define DEM_PFF_RUNTIME_OPTIMIZATION   STD_ON

/* macro to en-/disable global extended data class */
#if (defined DEM_USE_GLOBAL_EDCLASS)
#error DEM_USE_GLOBAL_EDCLASS already defined
#endif
#define DEM_USE_GLOBAL_EDCLASS         STD_ON

/* macro to en-/disable healing */
#if (defined DEM_USE_HEALING)
#error DEM_USE_HEALING already defined
#endif
#define DEM_USE_HEALING                STD_ON

/* macro for global healing cycle for all events */
#if (defined DEM_GLOBAL_HEALING_ALL_EVENTS)
#error DEM_GLOBAL_HEALING_ALL_EVENTS already defined
#endif
#define DEM_GLOBAL_HEALING_ALL_EVENTS  STD_OFF

/* macro to en-/disable debouncing */
#if (defined DEM_USE_DEBOUNCE)
#error DEM_USE_DEBOUNCE already defined
#endif
#define DEM_USE_DEBOUNCE               STD_OFF

/*------------------[General]-----------------------------------------------*/

#if (defined DEM_RETURNED_TRANS_FMT)
#error DEM_RETURNED_TRANS_FMT already defined
#endif
/** \brief Returned DTC translation format by Dem_GetTranslationType()
 **
 ** \note If more than one bit is set, only the first one is returned.
 **/
#define DEM_RETURNED_TRANS_FMT DEM_DTC_TRANSLATION_ISO14229_1

/*------------------[Callback macros]---------------------------------------*/

#if (defined DEM_CBK_FUNCPTR_GET_DATA_VALUE_BY_DATAID)
#error DEM_CBK_FUNCPTR_GET_DATA_VALUE_BY_DATAID already defined
#endif
/** \brief Get Data Value By Data Id function pointer for C-Callback */
#define DEM_CBK_FUNCPTR_GET_DATA_VALUE_BY_DATAID Cdc_DemGetDataValueByDataId

#if (defined DEM_CBK_FUNCPTR_GET_EXT_DATA_REC)
#error DEM_CBK_FUNCPTR_GET_EXT_DATA_REC already defined
#endif
/** \brief Get Extended Data Record function pointer for C-Callback */
#define DEM_CBK_FUNCPTR_GET_EXT_DATA_REC Cdc_DemGetExtendedDataRecord

#if (defined DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE)
#error DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE already defined
#endif
#define DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE 0U

#if (defined DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE)
#error DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE already defined
#endif
#define DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE 0U

#if (defined DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE)
#error DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE already defined
#endif
#define DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE 1U

#if (defined DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE)
#error DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE already defined
#endif
#define DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE 18U

#if (defined DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE)
#error DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE already defined
#endif
#define DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE 0U


#if (defined DEM_C_CALLBACK_TABLE_GET_FDC_SIZE)
#error DEM_C_CALLBACK_TABLE_GET_FDC_SIZE already defined
#endif
#define DEM_C_CALLBACK_TABLE_GET_FDC_SIZE 1U

#if (defined DEM_C_LOOKUP_TABLE_GET_FDC_SIZE)
#error DEM_C_LOOKUP_TABLE_GET_FDC_SIZE already defined
#endif
#define DEM_C_LOOKUP_TABLE_GET_FDC_SIZE 107U


#if (defined DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE)
#error DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE already defined
#endif
#define DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE 0U


#if (defined DEM_GET_DATA_VALUE_BY_DATAID_RTE_USAGE)
#error DEM_GET_DATA_VALUE_BY_DATAID_RTE_USAGE already defined
#endif
/** \brief RTE-Port for GetDataValueByDataId
**/
#define DEM_GET_DATA_VALUE_BY_DATAID_RTE_USAGE   STD_OFF

#if (defined DEM_GET_EXTENDED_DATA_VALUE_RECORD_RTE_USAGE)
#error DEM_GET_EXTENDED_DATA_VALUE_RECORD_RTE_USAGE already defined
#endif
/** \brief RTE-Port for GetExtendedDataValueRecord
**/
#define DEM_GET_EXTENDED_DATA_VALUE_RECORD_RTE_USAGE   STD_OFF
/*------------------[Operation cycles configuration]------------------------*/

#if (defined DEM_NUM_OPCYCLES)
#error DEM_NUM_OPCYCLES already defined
#endif
/** \brief Number of operation cycles */
#define DEM_NUM_OPCYCLES 4U


/*------------------[Enable conditions configuration]-----------------------*/

#if (defined DEM_NUM_ENABLECONDITIONS)
#error DEM_NUM_ENABLECONDITIONS already defined
#endif
/** \brief Number of enable conditions */
#define DEM_NUM_ENABLECONDITIONS 0U


/*------------------[DTC groups configuration]------------------------------*/

/* Symbolic names of internal DTC group indices */

#if (defined DEM_DTCGRP_IDX_EMISSION_REL_DTCS)
#error DEM_DTCGRP_IDX_EMISSION_REL_DTCS already defined
#endif
/** \brief Symbolic name of DTC group EMISSION_REL_DTCS index */
#define DEM_DTCGRP_IDX_EMISSION_REL_DTCS   0U

#if (defined DEM_DTCGRP_IDX_POWERTRAIN_DTCS)
#error DEM_DTCGRP_IDX_POWERTRAIN_DTCS already defined
#endif
/** \brief Symbolic name of DTC group POWERTRAIN_DTCS index */
#define DEM_DTCGRP_IDX_POWERTRAIN_DTCS     1U

#if (defined DEM_DTCGRP_IDX_CHASSIS_DTCS)
#error DEM_DTCGRP_IDX_CHASSIS_DTCS already defined
#endif
/** \brief Symbolic name of DTC group CHASSIS_DTCS index */
#define DEM_DTCGRP_IDX_CHASSIS_DTCS        2U

#if (defined DEM_DTCGRP_IDX_BODY_DTCS)
#error DEM_DTCGRP_IDX_BODY_DTCS already defined
#endif
/** \brief Symbolic name of DTC group BODY_DTCS index */
#define DEM_DTCGRP_IDX_BODY_DTCS           3U

#if (defined DEM_DTCGRP_IDX_NETWORK_COM_DTCS)
#error DEM_DTCGRP_IDX_NETWORK_COM_DTCS already defined
#endif
/** \brief Symbolic name of DTC group NETWORK_COM_DTCS index */
#define DEM_DTCGRP_IDX_NETWORK_COM_DTCS    4U


#if (defined DEM_NUM_DTC_GROUPS)
#error DEM_NUM_DTC_GROUPS already defined
#endif
/** \brief Number of DTC groups */
#define DEM_NUM_DTC_GROUPS 5U


/*------------------[Freeze frame configuration]----------------------------*/

/* Size of the freeze frame class DemFreezeFrameClass1 in bytes: 22 */

#if (defined DEM_MAXSIZE_FFCLS)
#error DEM_MAXSIZE_FFCLS already defined
#endif
/** \brief Maximum size of a freeze frame class in bytes */
#define DEM_MAXSIZE_FFCLS 22U

#if (defined DEM_MAXNUM_FFSEGS)
#error DEM_MAXNUM_FFSEGS already defined
#endif
/** \brief Maximal number of different freeze frame segments */
#define DEM_MAXNUM_FFSEGS 11U


/* Symblic names of internal freeze frame class indices */

#if (defined DEM_FFCLS_IDX_DemFreezeFrameClass1)
#error DEM_FFCLS_IDX_DemFreezeFrameClass1 already defined
#endif
/** \brief Symbolic name of freeze frame class DemFreezeFrameClass1 index */
#define DEM_FFCLS_IDX_DemFreezeFrameClass1             0U


#if (defined DEM_NUM_FFCLS)
#error DEM_NUM_FFCLS already defined
#endif
/** \brief Number of different freeze frame classes */
#define DEM_NUM_FFCLS 1U


/*------------------[Prestored freeze frame configuration]------------------*/

#if (defined DEM_PFF_ZERO_END)
#error DEM_PFF_ZERO_END already defined
#endif
/** \brief Zero value to be added to each size, whose involved patterns could
 ** be none */
#define DEM_PFF_ZERO_END                  0U

#if (defined DEM_SIZE_PFF_ENTRY_DATA)
#error DEM_SIZE_PFF_ENTRY_DATA already defined
#endif
/** Size of dynamic PFF entry data
 **
 ** All FF sizes of events with enabled prestorage are added.
 **/
#define DEM_SIZE_PFF_ENTRY_DATA       \
   (DEM_PFF_ZERO_END)


#if (defined DEM_MAXNUM_FFPEREVENT)
#error DEM_MAXNUM_FFPEREVENT already defined
#endif
/** \brief Maximum number of freeze frames per event */
#define DEM_MAXNUM_FFPEREVENT 2U


#if (defined DEM_NBR_OF_EVENTS_WITH_PFF)
#error DEM_NBR_OF_EVENTS_WITH_PFF already defined
#endif
/** \brief Number of events with prestored freeze frames enabled */
#define DEM_NBR_OF_EVENTS_WITH_PFF        0U


/*------------------[Extended data configuration]---------------------------*/
/* Size of the extended data class DemExtendedDataClass1 in bytes: 3 */

#if (defined DEM_MAXSIZE_EDCLS)
#error DEM_MAXSIZE_EDCLS already defined
#endif
/** \brief Maximum size of a extended data class in bytes */
#define DEM_MAXSIZE_EDCLS 3U

#if (defined DEM_MAXNUM_EDSEGS)
#error DEM_MAXNUM_EDSEGS already defined
#endif
/** \brief Maximal number of different extended data segments */
#define DEM_MAXNUM_EDSEGS 3U


/* Symbolic names of internal extended data class indices */

#if (defined DEM_EDCLS_IDX_DemExtendedDataClass1)
#error DEM_EDCLS_IDX_DemExtendedDataClass1 already defined
#endif
/** \brief Symbolic name of extended data class DemExtendedDataClass1 index */
#define DEM_EDCLS_IDX_DemExtendedDataClass1            0U


#if (defined DEM_NUM_EDCLS)
#error DEM_NUM_EDCLS already defined
#endif
/** \brief Number of different extended data classes */
#define DEM_NUM_EDCLS 1U


/*------------------[Memory size configuration]-----------------------------*/

/* extended data configuration, storage layout and therefore memory size
 * configuration is variant specific and therefore done in
 * Dem_Internal_Cfg_Specific.h */


/*------------------[Events configuration]----------------------------------*/

/* Configurational value width in bits used for Dem_EventDescType */

/* DTC value */
#if (defined DEM_DTC_WIDTH)
#error DEM_DTC_WIDTH already defined
#endif
#define DEM_DTC_WIDTH    24U

#if (defined DEM_DTC_OFFSET)
#error DEM_DTC_OFFSET already defined
#endif
#define DEM_DTC_OFFSET    0U

#if (defined DEM_DTC_CONFIGFIELD)
#error DEM_DTC_CONFIGFIELD already defined
#endif
#define DEM_DTC_CONFIGFIELD    EvConfig1

/* Origin of DTC */
#if (defined DEM_DTCORIGIN_WIDTH)
#error DEM_DTCORIGIN_WIDTH already defined
#endif
#define DEM_DTCORIGIN_WIDTH    2U

#if (defined DEM_DTCORIGIN_OFFSET)
#error DEM_DTCORIGIN_OFFSET already defined
#endif
#define DEM_DTCORIGIN_OFFSET    24U

#if (defined DEM_DTCORIGIN_CONFIGFIELD)
#error DEM_DTCORIGIN_CONFIGFIELD already defined
#endif
#define DEM_DTCORIGIN_CONFIGFIELD    EvConfig1

/* Group of DTC */
#if (defined DEM_DTCGROUP_WIDTH)
#error DEM_DTCGROUP_WIDTH already defined
#endif
#define DEM_DTCGROUP_WIDTH    3U

#if (defined DEM_DTCGROUP_OFFSET)
#error DEM_DTCGROUP_OFFSET already defined
#endif
#define DEM_DTCGROUP_OFFSET    26U

#if (defined DEM_DTCGROUP_CONFIGFIELD)
#error DEM_DTCGROUP_CONFIGFIELD already defined
#endif
#define DEM_DTCGROUP_CONFIGFIELD    EvConfig1

/* Severity of DTC */
#if (defined DEM_DTCSEVERITY_WIDTH)
#error DEM_DTCSEVERITY_WIDTH already defined
#endif
#define DEM_DTCSEVERITY_WIDTH    2U

#if (defined DEM_DTCSEVERITY_OFFSET)
#error DEM_DTCSEVERITY_OFFSET already defined
#endif
#define DEM_DTCSEVERITY_OFFSET    29U

#if (defined DEM_DTCSEVERITY_CONFIGFIELD)
#error DEM_DTCSEVERITY_CONFIGFIELD already defined
#endif
#define DEM_DTCSEVERITY_CONFIGFIELD    EvConfig1

/* Healing */
#if (defined DEM_HEALINGCYCLES_WIDTH)
#error DEM_HEALINGCYCLES_WIDTH already defined
#endif
#define DEM_HEALINGCYCLES_WIDTH    1U

#if (defined DEM_HEALINGCYCLES_OFFSET)
#error DEM_HEALINGCYCLES_OFFSET already defined
#endif
#define DEM_HEALINGCYCLES_OFFSET    31U

#if (defined DEM_HEALINGCYCLES_CONFIGFIELD)
#error DEM_HEALINGCYCLES_CONFIGFIELD already defined
#endif
#define DEM_HEALINGCYCLES_CONFIGFIELD    EvConfig1

/* If all events which use healing have the same cycle count, a global value is needed */
#define DEM_GLOBAL_HEALINGCYCLES_VALUE    40U

/* Operation cycle Id */
#if (defined DEM_OPCYCLEIDX_WIDTH)
#error DEM_OPCYCLEIDX_WIDTH already defined
#endif
#define DEM_OPCYCLEIDX_WIDTH    2U

#if (defined DEM_OPCYCLEIDX_OFFSET)
#error DEM_OPCYCLEIDX_OFFSET already defined
#endif
#define DEM_OPCYCLEIDX_OFFSET    0U

#if (defined DEM_OPCYCLEIDX_CONFIGFIELD)
#error DEM_OPCYCLEIDX_CONFIGFIELD already defined
#endif
#define DEM_OPCYCLEIDX_CONFIGFIELD    EvConfig2

/* Warning indicator */
#if (defined DEM_INDICATORUSED_WIDTH)
#error DEM_INDICATORUSED_WIDTH already defined
#endif
#define DEM_INDICATORUSED_WIDTH    1U

#if (defined DEM_INDICATORUSED_OFFSET)
#error DEM_INDICATORUSED_OFFSET already defined
#endif
#define DEM_INDICATORUSED_OFFSET    2U

#if (defined DEM_INDICATORUSED_CONFIGFIELD)
#error DEM_INDICATORUSED_CONFIGFIELD already defined
#endif
#define DEM_INDICATORUSED_CONFIGFIELD    EvConfig2

/* DTC kind */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_DTCKIND_VALUE)
#error DEM_GLOBAL_DTCKIND_VALUE already defined
#endif
#define DEM_GLOBAL_DTCKIND_VALUE    DEM_DTC_KIND_ALL_DTCS

/* Prestorage */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_PRESTORAGE_VALUE)
#error DEM_GLOBAL_PRESTORAGE_VALUE already defined
#endif
#define DEM_GLOBAL_PRESTORAGE_VALUE    0U

/* Freeze frame class */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_FFCLASSIDX_VALUE)
#error DEM_GLOBAL_FFCLASSIDX_VALUE already defined
#endif
#define DEM_GLOBAL_FFCLASSIDX_VALUE    0U

/* Maximal number of freeze frames */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_MAXNUMFF_VALUE)
#error DEM_GLOBAL_MAXNUMFF_VALUE already defined
#endif
#define DEM_GLOBAL_MAXNUMFF_VALUE    2U

/* Extended data class */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_EDCLASSIDX_VALUE)
#error DEM_GLOBAL_EDCLASSIDX_VALUE already defined
#endif
#define DEM_GLOBAL_EDCLASSIDX_VALUE    0U

/* Enable condition ID */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_ENCONDID_VALUE)
#error DEM_GLOBAL_ENCONDID_VALUE already defined
#endif
#define DEM_GLOBAL_ENCONDID_VALUE    DEM_NUM_ENABLECONDITIONS

/* View ID currently NOT supported */

/* Priority currently NOT supported */

/* Event debouncing */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_DEBOUNCEALGO_VALUE)
#error DEM_GLOBAL_DEBOUNCEALGO_VALUE already defined
#endif
#define DEM_GLOBAL_DEBOUNCEALGO_VALUE    DEM_DEBOUNCE_MONITOR

/* Event debouncing class */
/* not necessary in configuration, because of global value */
#if (defined DEM_GLOBAL_DEBOUNCEIDX_VALUE)
#error DEM_GLOBAL_DEBOUNCEIDX_VALUE already defined
#endif
#define DEM_GLOBAL_DEBOUNCEIDX_VALUE    0U

/*------------------[Warning indicators configuration]----------------------*/

#if (defined DEM_NUM_INDICATOR_LINKS)
#error DEM_NUM_INDICATOR_LINKS already defined
#endif
/** \brief Number of warning indicator links */
#define DEM_NUM_INDICATOR_LINKS   27U

/*------------------[Debouncing configuration]------------------------------*/

#if (defined DEM_NUM_DEBOUNCE_COUNTER)
#error DEM_NUM_DEBOUNCE_COUNTER already defined
#endif
/** \brief Number of counter based debounced events */
#define DEM_NUM_DEBOUNCE_COUNTER   0U

#if (defined DEM_NUM_DEBOUNCE_TIME)
#error DEM_NUM_DEBOUNCE_TIME already defined
#endif
/** \brief Number of counter based debounced events */
#define DEM_NUM_DEBOUNCE_TIME      0U

#if (defined DEM_NUM_DEBOUNCE_FREQUENCY)
#error DEM_NUM_DEBOUNCE_FREQUENCY already defined
#endif
/** \brief Number of counter based debounced events */
#define DEM_NUM_DEBOUNCE_FREQUENCY 0U


/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_CFG_H */
/*==================[end of file]===========================================*/
