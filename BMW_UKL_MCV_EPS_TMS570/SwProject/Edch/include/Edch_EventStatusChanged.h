/*
 * Edch_EventStatusChanged.h
 *
 *  Created on: May 14, 2014
 *      Author: cz7lt6
 */
#include "Std_Types.h"
#include "Rte_type.h"

#ifndef EDCH_EVENTSTATUSCHANGED_H_
#define EDCH_EVENTSTATUSCHANGED_H_

extern FUNC(Std_ReturnType, EDCH_APPL_CODE) Edch_EventStatusChanged(Edch_EventIdxType DemIdx, Dem_EventStatusExtendedType EventStatusOld,Dem_EventStatusExtendedType EventStatusNew);


#endif /* EDCH_EVENTSTATUSCHANGED_H_ */
