/*******************************************************************************
**                                                                            **
**  SRC-MODULE: FreeTimer_Cfg.h                                               **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Configuration file for Free Running Timer driver              **
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
** miwe         Michael Weger              EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.1.1: 20.11.2008, miwe: CanTp no longer uses Gpt,
 *                           removed tester Ids F0...FD
 * V1.1.0: 25.02.2008, miwe: added diagnostic tester Ids F0...FD
 *         27.09.2007, miwe: CR61261: reworked FreeTimer integration
 * V1.0.0: 24.09.2007, miwe: ported from SC6.7.2 file version V1.1.0
 */


#ifndef FREETIMER_CFG_H
#define FREETIMER_CFG_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>           /* AUTOSAR Standard Types */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#if (SC_NRV2B_ENABLE == ON)
   /* use for timeout measurement and random number generation API */
   #define FREETIMER_DISABLE_MEASUREMENTAPI  OFF
#else
   /* use only for random number generation */
   #define FREETIMER_DISABLE_MEASUREMENTAPI  ON
#endif


/*** Private Part (used by FreeTimer.c only) **********************************/
#ifdef FREETIMER_C

/*
 * set the CPU clock frequency
 */

#define FREETIMER_BUS_FREQ_HZ                                    80000000

#endif /* FREETIMER_C                                                         */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef uint32 FreeTimer_TimeInTicksType;    /* Time in ticks type */
typedef uint32 FreeTimer_TimeInMsType;       /* Time in mS (width of timer register) */


#endif /* FREETIMER_CFG_H                                                     */

/*** End of file **************************************************************/
