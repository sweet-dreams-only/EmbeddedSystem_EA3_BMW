/*******************************************************************************
**                                                                            **
**  SRC-MODULE: FreeTimer.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : ALL                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Free Running Timer driver                                     **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.1: 27.01.2010, gema: CR70524: Compiler switches shall have defined values
 * V1.0.0: 14.11.2007, miwe: ported from SC6.7.2 file version V1.1.0
 */


#if !defined( FREETIMER_H )
#define FREETIMER_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                      /* Autosar standard types         */
#include "FreeTimer_Cfg.h"                  /* Module configuration file      */


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

   extern void                      FreeTimer_Init( void );

#if (FREETIMER_DISABLE_MEASUREMENTAPI == STD_OFF)
   extern void                      FreeTimer_StartTimeMeasurement( void );
   extern FreeTimer_TimeInTicksType FreeTimer_GetTimeInTicks( void );
   extern FreeTimer_TimeInTicksType FreeTimer_ConvertMs2Ticks( const FreeTimer_TimeInMsType ms );
   extern FreeTimer_TimeInMsType    FreeTimer_ConvertTicks2Ms( const FreeTimer_TimeInTicksType ticks );
#endif

   extern FreeTimer_TimeInTicksType FreeTimer_CreateRandomNumber( void );

#endif /* FREETIMER_H                                                         */

/*** End of file **************************************************************/
