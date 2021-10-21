/* Kernbauer Version: 2.04 Konfiguration: TMS570SafeCtx Erzeugungsgangnummer: 633 Zweig: 1 */

/*****************************************************************************
| Project Name: OSEK 2.2 / Autosar OS 3.0
|    File Name: osek.h
|
|  General code: @Version: 5.23c@
|  Module version: $vv$=2.12
|
|  Description: contains osek prototypes and defines
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2012 Vctr Informatik GmbH          All rights reserved.
|****************************************************************************/

/* MISRA RULE 19.15 VIOLATION: The QAC-Tool states a violation of rule 19.15 with 
 * message 0883 below. Anyhow, there is a double include prevention and therefore,
 * the message is considered to be wrong. */
/* double include preventer */
#ifndef _OSEK_H      /* PRQA S 0883 EOF */ /* see MISRA comment above */
#define _OSEK_H


#define osqFunc1

osqFunc1 void SuspendAllInterrupts(void);

osqFunc1 void ResumeAllInterrupts(void);



#endif/* double include preventer */

/* END OF HEADER osek.h */

