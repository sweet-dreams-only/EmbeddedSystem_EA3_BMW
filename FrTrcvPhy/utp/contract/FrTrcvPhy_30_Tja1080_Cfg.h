
#ifndef FRTRCVPHY_CFG_H
#define FRTRCVPHY_CFG_H

/* Include definitions for Diagnostic Event API */
#include "Ap_DiagMgr.h"

/* Required for Dem_EventIdType def */
typedef uint8 Dem_EventIdType;

/* Dem_Api_Cfg.h */
#define FR_PHYS_FAILURE                  44U


#define FRTRCVPHY_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr9_ReportNTCStatus(event, param, status)
#define FRTRCV_TRCV_DIAGNOSIS                 STD_ON


#endif	/* FRTRCVPHY_CFG_H */

