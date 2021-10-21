/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_types_arch.h                                               **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : 32bit platforms                                               **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  PURPOSE   : Contains architecture dependent type definitions which are    **
**              used both by the bootloader and the application.              **
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
** ft           Florian Tausch             MB Technology                      **
** tr           Thomas Rösch               Richard Bader GmbH                 **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.3: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.0.2: 14.04.2011,   tr: CR70826 Vector Release 10 Update for all Tools
 * V1.0.1: 17.09.2010,   ft: CR70732/CR70733: removed NEAR_MEMORY, FAR_MEMORY
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V2.0.5
 */


#ifndef  SC_TYPES_ARCH_H
#define  SC_TYPES_ARCH_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define SC_FAR                         /* Defines the 'far' type         */
                                            /* qualifier, which depends on    */
                                            /* the compiler. See compiler     */
                                            /* manual.                        */
#define SC_NEAR                             /* Defines the 'near' type        */
                                            /* qualifier, which depends on    */
                                            /* the compiler. See compiler     */
                                            /* manual.                        */
#define SC_FAR_POINTER  *  SC_FAR           /* Defines a pointer to a far     */
                                            /* address, which also depends on */
                                            /* the compiler. See compiler     */
                                            /* manual.                        */
#define SC_FAR_POINTER_RAM  *               /* Defines a pointer to a far     */
                                            /* address, which also depends on */
                                            /* the compiler. See compiler     */
                                            /* manual.                        */

#endif /* SC_TYPES_ARCH_H                                                     */

/*** End of file **************************************************************/
