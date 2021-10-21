
#ifndef FRTRCVPHY_CFG_H
#define FRTRCVPHY_CFG_H

/* Include definitions for Diagnostic Event API */
#include "Ap_DiagMgr.h"


#define FRTRCVPHY_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr9_ReportNTCStatus(event, param, status)


#endif	/* FRTRCVPHY_CFG_H */
