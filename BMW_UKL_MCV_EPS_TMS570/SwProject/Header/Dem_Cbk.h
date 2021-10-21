/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Dem_Cbk.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2009                                             **
**                                                                            **
**  TARGET    : MPC55xx Autosar v2.1                                          **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : MBtech                                                 **
**                                                                            **
**  PURPOSE   : Configuration file for Dem module Callback 				**
**		       If there are Callback-functions used, 			     	**
**		       these functions have to be declared within this file                           **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** GeMa         Markus Gerngross              MBtech                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0: 26.10.2007, GeMa: initial version
 */
 
#ifndef _DEM_CBK_H
#define _DEM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dem.h"
#include "CDD_DATA.h"		/* To include CDD_DemIdSnapshot_Cnt_G_u8 for snapshot data */


/*******************************************************************************
**                     extern Funktion declaration                                    **
*******************************************************************************/
extern FUNC(Std_ReturnType, DARH_CODE) Darh_TriggerOnErrorEntry(
   uint32 dtc,
   uint32 timestamp);
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Xxx_DemGetFaultDetectionCounter(
   Dem_EventIdType             EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC);
extern FUNC(Std_ReturnType, DEM_PUBLIC_CODE) Cdc_DemClearEventAllowed(
   Dem_EventIdType EventId,
   P2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) Allowed);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetDataValueByDataId(
   uint16 DataID,
   P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) DemDataValueByDataIdBuffer);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetExtendedDataRecord(
   uint8 ExtendedDataRecordNumber,
   P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) ExtendedDataRecord);

extern FUNC(Std_ReturnType,DARH_CODE) Darh_TriggerOnErrorEntry(uint32 dtc,uint32 timestamp);

FUNC(Std_ReturnType,DEM_CODE) Xxx_DemGetDataValueByDataIdentifier(uint16 DataID, P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);

FUNC(Std_ReturnType,DEM_CODE) Xxx_DemGetExtendedDataRecord(uint8 ExtendedDataRecordNumber, P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) ExtendedDataRecord);

#endif /* _DEM_CBK_H */

/*** End of file **************************************************************/


