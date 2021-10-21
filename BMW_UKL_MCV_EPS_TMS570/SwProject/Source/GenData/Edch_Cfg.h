

/* --------{ BMW C Source File }-------- */
/* !LINKSTO EDCH_SDD_0003, 1
 */



#ifndef EDCH_CFG_H
#define EDCH_CFG_H

/*==================[inclusions]==============================================*/

#include <Edch_NvM_Cfg.h>

/*==================[macros]==================================================*/

/* !LINKSTO EDCH_055, 1
 * !LINKSTO EDCH_SDD_0249, 1
 */
#if (defined EDCH_DEV_ERROR_DETECT)
#error EDCH_DEV_ERROR_DETECT is already defined
#endif
/**
 * \brief Activation of development error detection
 */
#define EDCH_DEV_ERROR_DETECT   STD_OFF

/* !LINKSTO EDCH_SDD_0250, 1
 */
#if (defined EDCHCRC32CALCPARTLEN)
#error EDCHCRC32CALCPARTLEN is already defined
#endif
/**
 * \brief Count of partial calculation of checksumms according EdchCrc32CalcPartLen
 */
#define EDCHCRC32CALCPARTLEN 10240U

/* !LINKSTO EDCH_028, 1
 * !LINKSTO EDCH_353, 1
 * !LINKSTO EDCH_SDD_0257, 1
 */
#if (defined EDCH_CVNTABLE_PTR)
#error EDCH_CVNTABLE_PTR is already defined
#endif
/**
 * \brief Adresse of configured EdchCvnDefinitionBlock
 */
#define EDCH_CVNTABLE_PTR {(P2CONST(Edch_CvnDefBlockType, EDCH_CONST, EDCH_APPL_CONST))&Edch_CvnDefBlock_0, \
(P2CONST(Edch_CvnDefBlockType, EDCH_CONST, EDCH_APPL_CONST))&Edch_CvnDefBlock_1, \
(P2CONST(Edch_CvnDefBlockType, EDCH_CONST, EDCH_APPL_CONST))&Edch_CvnDefBlock_2, \
}

/* !LINKSTO EDCH_SDD_0258, 1
 */
#if (defined EDCH_CVNTABLE_CRCINIT)
#error EDCH_CVNTABLE_CRCINIT is already defined
#endif
/**
 * \brief CRC-32 init values of configured EdchCvnDefinitionBlock
 */
#define EDCH_CVNTABLE_CRCINIT {4294967295U, 4294967295U, 4294967295U, }

/* !LINKSTO EDCH_SDD_0261, 1
 * !LINKSTO EDCH_147, 1
 */
#if (defined EDCH_CRC32_CALIDCVN_INITVAL)
#error EDCH_CRC32_CALIDCVN_INITVAL is already defined
#endif
/**
 * \brief Initial value for CRC32 calculation of the CAL-ID and the CVN
 */
#define EDCH_CRC32_CALIDCVN_INITVAL 4294967295U

/* !LINKSTO EDCH_SDD_0262, 1
 * !LINKSTO EDCH_147, 1
 */
#if (defined EDCH_CRC32_CODING_INITVAL)
#error EDCH_CRC32_CODING_INITVAL is already defined
#endif
/**
 * \brief Initial value for CRC32 calculation of reference/sub-CVN of OBD relevant coding data
 */
#define EDCH_CRC32_CODING_INITVAL 4294967295U

/* !LINKSTO EDCH_SDD_0263, 1
 * !LINKSTO EDCH_002, 1
 */
#if (defined EDCH_DIAGNOSTICS_COUNT)
#error EDCH_DIAGNOSTICS_COUNT is already defined
#endif
/**
 * \brief Count of configured diagnostics
 */
#define EDCH_DIAGNOSTICS_COUNT     18U

/* !LINKSTO EDCH_SDD_0264, 1
 * !LINKSTO EDCH_051, 1
 */
#if (defined EDCH_MUX_MAX)
#error EDCH_MUX_MAX is already defined
#endif
/**
 * \brief Highest EdchDiagnosticNumber of configured diagnostics
 */
#define EDCH_MUX_MAX     6U

/* !LINKSTO EDCH_SDD_0265, 1
 * !LINKSTO EDCH_002, 1
 */
#if (defined EDCH_DIAGNOSTICS_NUMBER)
#error EDCH_DIAGNOSTICS_NUMBER is already defined
#endif
/**
 * \brief List of EdchDiagnosticNumber of configured diagnostics
 */
#define EDCH_DIAGNOSTICS_NUMBER   { 8U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U }


/* !LINKSTO EDCH_SDD_0267, 1
 * !LINKSTO EDCH_054, 1
 */
#if (defined EDCH_DIAGNOSTICS_IMME)
#error EDCH_DIAGNOSTICS_IMME is already defined
#endif
/**
 * \brief All IMME are sended to the OBD Host
 */
#define EDCH_DIAGNOSTICS_IMME    {EDCH_IMME_CALID, EDCH_IMME_CVN, 4U, 5U, 6U, }

/* !LINKSTO EDCH_SDD_0268, 1
 */
#if (defined EDCH_DIAGNOSTICS_IMME_CNT)
#error EDCH_DIAGNOSTICS_IMME_CNT is already defined
#endif
/**
 * \brief Count of various IMME are sended to the OBD Host
 */
#define EDCH_DIAGNOSTICS_IMME_CNT 5U

/* !LINKSTO EDCH_SDD_0269, 1
 */
#if (defined EDCH_DIAGNOSTICS_PERIOD)
#error EDCH_DIAGNOSTICS_PERIOD is already defined
#endif
/**
 * \brief List of reporting periods of configured diagnostics
 */
#define EDCH_DIAGNOSTICS_PERIOD   { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}


/* !LINKSTO EDCH_SDD_0270, 1
 * !LINKSTO EDCH_002, 1
 */
#if (defined EDCH_DIAGNOSTICS_CONTINUOUS)
#error EDCH_DIAGNOSTICS_CONTINUOUS is already defined
#endif
/**
 * \brief List of attribute continuous of Dem-events of configured diagnostics
 */
#define EDCH_DIAGNOSTICS_CONTINUOUS {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE}

/* !LINKSTO EDCH_364, 1
 */
#if (defined EDCH_DIAGNOSTICS_MONITOR_EN_STAT)
#error EDCH_DIAGNOSTICS_MONITOR_EN_STAT is already defined
#endif
/**
 * \brief List of attribute monitor enable status (bit4) of configured diagnostics
 */
#define EDCH_DIAGNOSTICS_MONITOR_EN_STAT {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE}

/* !LINKSTO EDCH_364, 1
 */
#if (defined EDCH_DIAGNOSTICS_MONITOR_EN_API)
#error EDCH_DIAGNOSTICS_MONITOR_EN_API is already defined
#endif

/* !LINKSTO EDCH_132, 1
 */
#if (defined Edch_SetEventStatus_19)
#error Edch_SetEventStatus_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_19(a) Rte_Call_DiagnosticMonitorOUT_19_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_19)
#error Edch_ResetEventStatus_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_19() Rte_Call_DiagnosticMonitorOUT_19_ResetEventStatus()

#if (defined Edch_GetEventStatus_19)
#error Edch_GetEventStatus_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_19(a) Rte_Call_DiagnosticMonitorOUT_19_GetEventStatus(a)

#if (defined Edch_GetEventFailed_19)
#error Edch_GetEventFailed_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_19(a) Rte_Call_DiagnosticMonitorOUT_19_GetEventFailed(a)

#if (defined Edch_GetEventTested_19)
#error Edch_GetEventTested_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_19(a) Rte_Call_DiagnosticMonitorOUT_19_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_19)
#error Edch_GetDTCOfEvent_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_19(a, b, c) Rte_Call_DiagnosticMonitorOUT_19_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_19)
#error Edch_PrestoreFreezeFrame_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_19() Rte_Call_DiagnosticMonitorOUT_19_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_19)
#error Edch_ClearPrestoredFreezeFrame_19 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_19() Rte_Call_DiagnosticMonitorOUT_19_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_36)
#error Edch_SetEventStatus_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_36(a) Rte_Call_DiagnosticMonitorOUT_36_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_36)
#error Edch_ResetEventStatus_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_36() Rte_Call_DiagnosticMonitorOUT_36_ResetEventStatus()

#if (defined Edch_GetEventStatus_36)
#error Edch_GetEventStatus_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_36(a) Rte_Call_DiagnosticMonitorOUT_36_GetEventStatus(a)

#if (defined Edch_GetEventFailed_36)
#error Edch_GetEventFailed_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_36(a) Rte_Call_DiagnosticMonitorOUT_36_GetEventFailed(a)

#if (defined Edch_GetEventTested_36)
#error Edch_GetEventTested_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_36(a) Rte_Call_DiagnosticMonitorOUT_36_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_36)
#error Edch_GetDTCOfEvent_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_36(a, b, c) Rte_Call_DiagnosticMonitorOUT_36_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_36)
#error Edch_PrestoreFreezeFrame_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_36() Rte_Call_DiagnosticMonitorOUT_36_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_36)
#error Edch_ClearPrestoredFreezeFrame_36 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_36() Rte_Call_DiagnosticMonitorOUT_36_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_37)
#error Edch_SetEventStatus_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_37(a) Rte_Call_DiagnosticMonitorOUT_37_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_37)
#error Edch_ResetEventStatus_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_37() Rte_Call_DiagnosticMonitorOUT_37_ResetEventStatus()

#if (defined Edch_GetEventStatus_37)
#error Edch_GetEventStatus_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_37(a) Rte_Call_DiagnosticMonitorOUT_37_GetEventStatus(a)

#if (defined Edch_GetEventFailed_37)
#error Edch_GetEventFailed_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_37(a) Rte_Call_DiagnosticMonitorOUT_37_GetEventFailed(a)

#if (defined Edch_GetEventTested_37)
#error Edch_GetEventTested_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_37(a) Rte_Call_DiagnosticMonitorOUT_37_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_37)
#error Edch_GetDTCOfEvent_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_37(a, b, c) Rte_Call_DiagnosticMonitorOUT_37_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_37)
#error Edch_PrestoreFreezeFrame_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_37() Rte_Call_DiagnosticMonitorOUT_37_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_37)
#error Edch_ClearPrestoredFreezeFrame_37 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_37() Rte_Call_DiagnosticMonitorOUT_37_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_41)
#error Edch_SetEventStatus_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_41(a) Rte_Call_DiagnosticMonitorOUT_41_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_41)
#error Edch_ResetEventStatus_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_41() Rte_Call_DiagnosticMonitorOUT_41_ResetEventStatus()

#if (defined Edch_GetEventStatus_41)
#error Edch_GetEventStatus_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_41(a) Rte_Call_DiagnosticMonitorOUT_41_GetEventStatus(a)

#if (defined Edch_GetEventFailed_41)
#error Edch_GetEventFailed_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_41(a) Rte_Call_DiagnosticMonitorOUT_41_GetEventFailed(a)

#if (defined Edch_GetEventTested_41)
#error Edch_GetEventTested_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_41(a) Rte_Call_DiagnosticMonitorOUT_41_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_41)
#error Edch_GetDTCOfEvent_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_41(a, b, c) Rte_Call_DiagnosticMonitorOUT_41_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_41)
#error Edch_PrestoreFreezeFrame_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_41() Rte_Call_DiagnosticMonitorOUT_41_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_41)
#error Edch_ClearPrestoredFreezeFrame_41 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_41() Rte_Call_DiagnosticMonitorOUT_41_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_38)
#error Edch_SetEventStatus_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_38(a) Rte_Call_DiagnosticMonitorOUT_38_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_38)
#error Edch_ResetEventStatus_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_38() Rte_Call_DiagnosticMonitorOUT_38_ResetEventStatus()

#if (defined Edch_GetEventStatus_38)
#error Edch_GetEventStatus_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_38(a) Rte_Call_DiagnosticMonitorOUT_38_GetEventStatus(a)

#if (defined Edch_GetEventFailed_38)
#error Edch_GetEventFailed_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_38(a) Rte_Call_DiagnosticMonitorOUT_38_GetEventFailed(a)

#if (defined Edch_GetEventTested_38)
#error Edch_GetEventTested_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_38(a) Rte_Call_DiagnosticMonitorOUT_38_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_38)
#error Edch_GetDTCOfEvent_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_38(a, b, c) Rte_Call_DiagnosticMonitorOUT_38_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_38)
#error Edch_PrestoreFreezeFrame_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_38() Rte_Call_DiagnosticMonitorOUT_38_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_38)
#error Edch_ClearPrestoredFreezeFrame_38 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_38() Rte_Call_DiagnosticMonitorOUT_38_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_40)
#error Edch_SetEventStatus_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_40(a) Rte_Call_DiagnosticMonitorOUT_40_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_40)
#error Edch_ResetEventStatus_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_40() Rte_Call_DiagnosticMonitorOUT_40_ResetEventStatus()

#if (defined Edch_GetEventStatus_40)
#error Edch_GetEventStatus_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_40(a) Rte_Call_DiagnosticMonitorOUT_40_GetEventStatus(a)

#if (defined Edch_GetEventFailed_40)
#error Edch_GetEventFailed_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_40(a) Rte_Call_DiagnosticMonitorOUT_40_GetEventFailed(a)

#if (defined Edch_GetEventTested_40)
#error Edch_GetEventTested_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_40(a) Rte_Call_DiagnosticMonitorOUT_40_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_40)
#error Edch_GetDTCOfEvent_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_40(a, b, c) Rte_Call_DiagnosticMonitorOUT_40_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_40)
#error Edch_PrestoreFreezeFrame_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_40() Rte_Call_DiagnosticMonitorOUT_40_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_40)
#error Edch_ClearPrestoredFreezeFrame_40 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_40() Rte_Call_DiagnosticMonitorOUT_40_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_39)
#error Edch_SetEventStatus_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_39(a) Rte_Call_DiagnosticMonitorOUT_39_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_39)
#error Edch_ResetEventStatus_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_39() Rte_Call_DiagnosticMonitorOUT_39_ResetEventStatus()

#if (defined Edch_GetEventStatus_39)
#error Edch_GetEventStatus_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_39(a) Rte_Call_DiagnosticMonitorOUT_39_GetEventStatus(a)

#if (defined Edch_GetEventFailed_39)
#error Edch_GetEventFailed_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_39(a) Rte_Call_DiagnosticMonitorOUT_39_GetEventFailed(a)

#if (defined Edch_GetEventTested_39)
#error Edch_GetEventTested_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_39(a) Rte_Call_DiagnosticMonitorOUT_39_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_39)
#error Edch_GetDTCOfEvent_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_39(a, b, c) Rte_Call_DiagnosticMonitorOUT_39_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_39)
#error Edch_PrestoreFreezeFrame_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_39() Rte_Call_DiagnosticMonitorOUT_39_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_39)
#error Edch_ClearPrestoredFreezeFrame_39 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_39() Rte_Call_DiagnosticMonitorOUT_39_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_42)
#error Edch_SetEventStatus_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_42(a) Rte_Call_DiagnosticMonitorOUT_42_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_42)
#error Edch_ResetEventStatus_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_42() Rte_Call_DiagnosticMonitorOUT_42_ResetEventStatus()

#if (defined Edch_GetEventStatus_42)
#error Edch_GetEventStatus_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_42(a) Rte_Call_DiagnosticMonitorOUT_42_GetEventStatus(a)

#if (defined Edch_GetEventFailed_42)
#error Edch_GetEventFailed_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_42(a) Rte_Call_DiagnosticMonitorOUT_42_GetEventFailed(a)

#if (defined Edch_GetEventTested_42)
#error Edch_GetEventTested_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_42(a) Rte_Call_DiagnosticMonitorOUT_42_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_42)
#error Edch_GetDTCOfEvent_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_42(a, b, c) Rte_Call_DiagnosticMonitorOUT_42_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_42)
#error Edch_PrestoreFreezeFrame_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_42() Rte_Call_DiagnosticMonitorOUT_42_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_42)
#error Edch_ClearPrestoredFreezeFrame_42 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_42() Rte_Call_DiagnosticMonitorOUT_42_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_55)
#error Edch_SetEventStatus_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_55(a) Rte_Call_DiagnosticMonitorOUT_55_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_55)
#error Edch_ResetEventStatus_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_55() Rte_Call_DiagnosticMonitorOUT_55_ResetEventStatus()

#if (defined Edch_GetEventStatus_55)
#error Edch_GetEventStatus_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_55(a) Rte_Call_DiagnosticMonitorOUT_55_GetEventStatus(a)

#if (defined Edch_GetEventFailed_55)
#error Edch_GetEventFailed_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_55(a) Rte_Call_DiagnosticMonitorOUT_55_GetEventFailed(a)

#if (defined Edch_GetEventTested_55)
#error Edch_GetEventTested_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_55(a) Rte_Call_DiagnosticMonitorOUT_55_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_55)
#error Edch_GetDTCOfEvent_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_55(a, b, c) Rte_Call_DiagnosticMonitorOUT_55_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_55)
#error Edch_PrestoreFreezeFrame_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_55() Rte_Call_DiagnosticMonitorOUT_55_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_55)
#error Edch_ClearPrestoredFreezeFrame_55 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_55() Rte_Call_DiagnosticMonitorOUT_55_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_58)
#error Edch_SetEventStatus_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_58(a) Rte_Call_DiagnosticMonitorOUT_58_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_58)
#error Edch_ResetEventStatus_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_58() Rte_Call_DiagnosticMonitorOUT_58_ResetEventStatus()

#if (defined Edch_GetEventStatus_58)
#error Edch_GetEventStatus_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_58(a) Rte_Call_DiagnosticMonitorOUT_58_GetEventStatus(a)

#if (defined Edch_GetEventFailed_58)
#error Edch_GetEventFailed_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_58(a) Rte_Call_DiagnosticMonitorOUT_58_GetEventFailed(a)

#if (defined Edch_GetEventTested_58)
#error Edch_GetEventTested_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_58(a) Rte_Call_DiagnosticMonitorOUT_58_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_58)
#error Edch_GetDTCOfEvent_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_58(a, b, c) Rte_Call_DiagnosticMonitorOUT_58_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_58)
#error Edch_PrestoreFreezeFrame_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_58() Rte_Call_DiagnosticMonitorOUT_58_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_58)
#error Edch_ClearPrestoredFreezeFrame_58 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_58() Rte_Call_DiagnosticMonitorOUT_58_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_74)
#error Edch_SetEventStatus_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_74(a) Rte_Call_DiagnosticMonitorOUT_74_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_74)
#error Edch_ResetEventStatus_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_74() Rte_Call_DiagnosticMonitorOUT_74_ResetEventStatus()

#if (defined Edch_GetEventStatus_74)
#error Edch_GetEventStatus_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_74(a) Rte_Call_DiagnosticMonitorOUT_74_GetEventStatus(a)

#if (defined Edch_GetEventFailed_74)
#error Edch_GetEventFailed_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_74(a) Rte_Call_DiagnosticMonitorOUT_74_GetEventFailed(a)

#if (defined Edch_GetEventTested_74)
#error Edch_GetEventTested_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_74(a) Rte_Call_DiagnosticMonitorOUT_74_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_74)
#error Edch_GetDTCOfEvent_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_74(a, b, c) Rte_Call_DiagnosticMonitorOUT_74_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_74)
#error Edch_PrestoreFreezeFrame_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_74() Rte_Call_DiagnosticMonitorOUT_74_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_74)
#error Edch_ClearPrestoredFreezeFrame_74 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_74() Rte_Call_DiagnosticMonitorOUT_74_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_75)
#error Edch_SetEventStatus_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_75(a) Rte_Call_DiagnosticMonitorOUT_75_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_75)
#error Edch_ResetEventStatus_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_75() Rte_Call_DiagnosticMonitorOUT_75_ResetEventStatus()

#if (defined Edch_GetEventStatus_75)
#error Edch_GetEventStatus_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_75(a) Rte_Call_DiagnosticMonitorOUT_75_GetEventStatus(a)

#if (defined Edch_GetEventFailed_75)
#error Edch_GetEventFailed_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_75(a) Rte_Call_DiagnosticMonitorOUT_75_GetEventFailed(a)

#if (defined Edch_GetEventTested_75)
#error Edch_GetEventTested_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_75(a) Rte_Call_DiagnosticMonitorOUT_75_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_75)
#error Edch_GetDTCOfEvent_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_75(a, b, c) Rte_Call_DiagnosticMonitorOUT_75_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_75)
#error Edch_PrestoreFreezeFrame_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_75() Rte_Call_DiagnosticMonitorOUT_75_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_75)
#error Edch_ClearPrestoredFreezeFrame_75 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_75() Rte_Call_DiagnosticMonitorOUT_75_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_23)
#error Edch_SetEventStatus_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_23(a) Rte_Call_DiagnosticMonitorOUT_23_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_23)
#error Edch_ResetEventStatus_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_23() Rte_Call_DiagnosticMonitorOUT_23_ResetEventStatus()

#if (defined Edch_GetEventStatus_23)
#error Edch_GetEventStatus_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_23(a) Rte_Call_DiagnosticMonitorOUT_23_GetEventStatus(a)

#if (defined Edch_GetEventFailed_23)
#error Edch_GetEventFailed_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_23(a) Rte_Call_DiagnosticMonitorOUT_23_GetEventFailed(a)

#if (defined Edch_GetEventTested_23)
#error Edch_GetEventTested_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_23(a) Rte_Call_DiagnosticMonitorOUT_23_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_23)
#error Edch_GetDTCOfEvent_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_23(a, b, c) Rte_Call_DiagnosticMonitorOUT_23_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_23)
#error Edch_PrestoreFreezeFrame_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_23() Rte_Call_DiagnosticMonitorOUT_23_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_23)
#error Edch_ClearPrestoredFreezeFrame_23 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_23() Rte_Call_DiagnosticMonitorOUT_23_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_76)
#error Edch_SetEventStatus_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_76(a) Rte_Call_DiagnosticMonitorOUT_76_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_76)
#error Edch_ResetEventStatus_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_76() Rte_Call_DiagnosticMonitorOUT_76_ResetEventStatus()

#if (defined Edch_GetEventStatus_76)
#error Edch_GetEventStatus_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_76(a) Rte_Call_DiagnosticMonitorOUT_76_GetEventStatus(a)

#if (defined Edch_GetEventFailed_76)
#error Edch_GetEventFailed_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_76(a) Rte_Call_DiagnosticMonitorOUT_76_GetEventFailed(a)

#if (defined Edch_GetEventTested_76)
#error Edch_GetEventTested_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_76(a) Rte_Call_DiagnosticMonitorOUT_76_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_76)
#error Edch_GetDTCOfEvent_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_76(a, b, c) Rte_Call_DiagnosticMonitorOUT_76_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_76)
#error Edch_PrestoreFreezeFrame_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_76() Rte_Call_DiagnosticMonitorOUT_76_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_76)
#error Edch_ClearPrestoredFreezeFrame_76 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_76() Rte_Call_DiagnosticMonitorOUT_76_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_77)
#error Edch_SetEventStatus_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_77(a) Rte_Call_DiagnosticMonitorOUT_77_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_77)
#error Edch_ResetEventStatus_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_77() Rte_Call_DiagnosticMonitorOUT_77_ResetEventStatus()

#if (defined Edch_GetEventStatus_77)
#error Edch_GetEventStatus_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_77(a) Rte_Call_DiagnosticMonitorOUT_77_GetEventStatus(a)

#if (defined Edch_GetEventFailed_77)
#error Edch_GetEventFailed_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_77(a) Rte_Call_DiagnosticMonitorOUT_77_GetEventFailed(a)

#if (defined Edch_GetEventTested_77)
#error Edch_GetEventTested_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_77(a) Rte_Call_DiagnosticMonitorOUT_77_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_77)
#error Edch_GetDTCOfEvent_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_77(a, b, c) Rte_Call_DiagnosticMonitorOUT_77_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_77)
#error Edch_PrestoreFreezeFrame_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_77() Rte_Call_DiagnosticMonitorOUT_77_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_77)
#error Edch_ClearPrestoredFreezeFrame_77 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_77() Rte_Call_DiagnosticMonitorOUT_77_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_78)
#error Edch_SetEventStatus_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_78(a) Rte_Call_DiagnosticMonitorOUT_78_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_78)
#error Edch_ResetEventStatus_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_78() Rte_Call_DiagnosticMonitorOUT_78_ResetEventStatus()

#if (defined Edch_GetEventStatus_78)
#error Edch_GetEventStatus_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_78(a) Rte_Call_DiagnosticMonitorOUT_78_GetEventStatus(a)

#if (defined Edch_GetEventFailed_78)
#error Edch_GetEventFailed_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_78(a) Rte_Call_DiagnosticMonitorOUT_78_GetEventFailed(a)

#if (defined Edch_GetEventTested_78)
#error Edch_GetEventTested_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_78(a) Rte_Call_DiagnosticMonitorOUT_78_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_78)
#error Edch_GetDTCOfEvent_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_78(a, b, c) Rte_Call_DiagnosticMonitorOUT_78_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_78)
#error Edch_PrestoreFreezeFrame_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_78() Rte_Call_DiagnosticMonitorOUT_78_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_78)
#error Edch_ClearPrestoredFreezeFrame_78 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_78() Rte_Call_DiagnosticMonitorOUT_78_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_79)
#error Edch_SetEventStatus_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_79(a) Rte_Call_DiagnosticMonitorOUT_79_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_79)
#error Edch_ResetEventStatus_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_79() Rte_Call_DiagnosticMonitorOUT_79_ResetEventStatus()

#if (defined Edch_GetEventStatus_79)
#error Edch_GetEventStatus_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_79(a) Rte_Call_DiagnosticMonitorOUT_79_GetEventStatus(a)

#if (defined Edch_GetEventFailed_79)
#error Edch_GetEventFailed_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_79(a) Rte_Call_DiagnosticMonitorOUT_79_GetEventFailed(a)

#if (defined Edch_GetEventTested_79)
#error Edch_GetEventTested_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_79(a) Rte_Call_DiagnosticMonitorOUT_79_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_79)
#error Edch_GetDTCOfEvent_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_79(a, b, c) Rte_Call_DiagnosticMonitorOUT_79_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_79)
#error Edch_PrestoreFreezeFrame_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_79() Rte_Call_DiagnosticMonitorOUT_79_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_79)
#error Edch_ClearPrestoredFreezeFrame_79 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_79() Rte_Call_DiagnosticMonitorOUT_79_ClearPrestoredFreezeFrame()
#if (defined Edch_SetEventStatus_80)
#error Edch_SetEventStatus_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_SetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_SetEventStatus_80(a) Rte_Call_DiagnosticMonitorOUT_80_SetEventStatus(a)

#if (defined Edch_ResetEventStatus_80)
#error Edch_ResetEventStatus_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ResetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ResetEventStatus_80() Rte_Call_DiagnosticMonitorOUT_80_ResetEventStatus()

#if (defined Edch_GetEventStatus_80)
#error Edch_GetEventStatus_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventStatus_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventStatus_80(a) Rte_Call_DiagnosticMonitorOUT_80_GetEventStatus(a)

#if (defined Edch_GetEventFailed_80)
#error Edch_GetEventFailed_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventFailed_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventFailed_80(a) Rte_Call_DiagnosticMonitorOUT_80_GetEventFailed(a)

#if (defined Edch_GetEventTested_80)
#error Edch_GetEventTested_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetEventTested_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetEventTested_80(a) Rte_Call_DiagnosticMonitorOUT_80_GetEventTested(a)

#if (defined Edch_GetDTCOfEvent_80)
#error Edch_GetDTCOfEvent_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_GetDTCOfEvent_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_GetDTCOfEvent_80(a, b, c) Rte_Call_DiagnosticMonitorOUT_80_GetDTCOfEvent(a, b, c)

#if (defined Edch_PrestoreFreezeFrame_80)
#error Edch_PrestoreFreezeFrame_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_PrestoreFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_PrestoreFreezeFrame_80() Rte_Call_DiagnosticMonitorOUT_80_PrestoreFreezeFrame()

#if (defined Edch_ClearPrestoredFreezeFrame_80)
#error Edch_ClearPrestoredFreezeFrame_80 is already defined
#endif
/**
 * \brief Macro for mapping all Edch_ClearPrestoredFreezeFrame_<EventId> to operation in corrsponding outgoing port
 */
#define Edch_ClearPrestoredFreezeFrame_80() Rte_Call_DiagnosticMonitorOUT_80_ClearPrestoredFreezeFrame()

#if (defined EDCH_RESETEVENTSTATUS_ALL)
#error EDCH_RESETEVENTSTATUS_ALL is already defined
#endif
/* Follow Rte-calls only return value !=E_OK, if:
 * - the DEM is not initialized
 * - the relevant event included in a group whitch is locked for update
 * All this should be checked and negated during integration phase.
 */
/**
 * \brief Macro for call ResetEventStatus on OUT Port for all configured diagnostics
 */
#define EDCH_RESETEVENTSTATUS_ALL() do{ \
      (void)Rte_Call_DiagnosticMonitorOUT_19_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_36_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_37_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_41_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_38_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_40_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_39_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_42_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_55_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_58_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_74_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_75_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_23_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_76_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_77_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_78_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_79_ResetEventStatus(); \
      (void)Rte_Call_DiagnosticMonitorOUT_80_ResetEventStatus(); \
 }while(0)

#if (defined EDCH_SUBCVNDEFAULTVAL)
#error EDCH_SUBCVNDEFAULTVAL is already defined
#endif
/**
 * \brief Initiallization of default values for sub cvn resp. NvM
 */
#define EDCH_SUBCVNDEFAULTVAL { \
      0xFFFFFFFFU, \
      0xFFFFFFFFU, \
      0xFFFFFFFFU, \
 }


/*==================[type definitions]========================================*/

/**
 * \brief Type for count diagnostic period in 160msec parts
 */
typedef uint8 Edch_Diagnostics_PeriodType;

/**
 * \brief Type Diagnostic numbers with respect to their position in ST_DIAG_OBD_DATA
 */
typedef uint8 Edch_Diagnostics_NumType;

/* !LINKSTO EDCH_SDD_0313, 1
 */
/**
 * \brief Type for CVN definition block of SWE number 0
 */
typedef struct Edch_CvnDefBlockStruct_0{
  uint32 refCvn;
  /**< Pre-calculated reference CVN */
  uint32 tableCnt;
  /**< Count of checksum table blocks */
  CONSTP2CONST(uint8, TYPEDEF, EDCH_APPL_CONST) tablePtr[2];
  /**< Adresses of the first an last byte of any checksum table block */
}Edch_CvnDefBlockType_0;

/**
 * \brief Type for CVN definition block of SWE number 1
 */
typedef struct Edch_CvnDefBlockStruct_1{
  uint32 refCvn;
  /**< Pre-calculated reference CVN */
  uint32 tableCnt;
  /**< Count of checksum table blocks */
  CONSTP2CONST(uint8, TYPEDEF, EDCH_APPL_CONST) tablePtr[8];
  /**< Adresses of the first an last byte of any checksum table block */
}Edch_CvnDefBlockType_1;

/**
 * \brief Type for CVN definition block of SWE number 2
 */
typedef struct Edch_CvnDefBlockStruct_2{
  uint32 refCvn;
  /**< Pre-calculated reference CVN */
  uint32 tableCnt;
  /**< Count of checksum table blocks */
  CONSTP2CONST(uint8, TYPEDEF, EDCH_APPL_CONST) tablePtr[2];
  /**< Adresses of the first an last byte of any checksum table block */
}Edch_CvnDefBlockType_2;


/*==================[external function declarations]==========================*/

/*==================[internal function declarations]==========================*/

/*==================[external constants]======================================*/

/* !LINKSTO EDCH_SDD_0313, 1
 */
#define EDCH_START_SEC_CONST_CVNBLOCK_0
#include "MemMap.h"
/**
 * \brief CVN definition block of SWE number 0
 */
extern CONST(Edch_CvnDefBlockType_0, EDCH_APPL_CONST) 
   Edch_CvnDefBlock_0;
#define EDCH_STOP_SEC_CONST_CVNBLOCK_0
#include "MemMap.h"

#define EDCH_START_SEC_CONST_CVNBLOCK_1
#include "MemMap.h"
/**
 * \brief CVN definition block of SWE number 1
 */
extern CONST(Edch_CvnDefBlockType_1, EDCH_APPL_CONST) 
   Edch_CvnDefBlock_1;
#define EDCH_STOP_SEC_CONST_CVNBLOCK_1
#include "MemMap.h"

#define EDCH_START_SEC_CONST_CVNBLOCK_2
#include "MemMap.h"
/**
 * \brief CVN definition block of SWE number 2
 */
extern CONST(Edch_CvnDefBlockType_2, EDCH_APPL_CONST) 
   Edch_CvnDefBlock_2;
#define EDCH_STOP_SEC_CONST_CVNBLOCK_2
#include "MemMap.h"


/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

/*==================[internal function definitions]===========================*/

#endif /* if (!defined EDCH_CFG_H) */
/*==================[end of file]=============================================*/
