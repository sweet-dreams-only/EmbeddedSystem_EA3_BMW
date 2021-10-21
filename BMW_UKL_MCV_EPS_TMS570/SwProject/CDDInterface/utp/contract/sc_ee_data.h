/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_ee_data.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file dedicated to file 'sc_ee_data.c'.                 **
**              Implements the data type definition 'BootProgCounterType',    **
**              'BootProgDataType', 'BootProgStatusType' and                  **
**              'SvkHistoryMemory' and external definition of struct          **
**              'BootProgStatus', 'BootProgCounter', 'BootProgData',          **
**              'SvkHistoryMemory'                                            **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
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
** olgo         Oliver Gorisch             EB Automotive                      **
** scma         Scheitterer Martin         MB-technology                      **
** ft           Florian Tausch             MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.3: 20.05.2011, anam: CR71056: SVK Read: Optimize RAM Usage 
 * V1.1.3: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.1.2: 07.09.2010,   ft: CR70748: added missing compiler abstraction
 * V1.1.1: 30.07.2009, scma: switch for SC6 diag added
 * V1.1.0: 02.09.2008, olgo: CR61431: separated bootloader and bootmanager
 * V1.1.0: 15.11.2007, miwe: NvM integration in Application:
 *                           + changed init block callback prototype
 *                           + added Vsm_NvData_Default block
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V9.0.0
 */


#ifndef SC_EE_DATA_H
#define SC_EE_DATA_H

/* KJS - Added for QAC analysis */

#define VINLENGTH                17u    /* Length of the VIN number           */
#define FINGERPRINTLENGTH             13u       /* Len of Fingerprint         */

typedef struct global_com2                         /* type for RNG registers  */
{
   uint32 reg_a[2];                                /* reg a                   */
   uint32 reg_b[2];                                /* reg b                   */
} CR_C_s2_t;

typedef enum
{
   ISFIRSTSTARTOFAPPLICATION     = 0x5Au,
   ISNOTFIRSTSTARTOFAPPLICATION  = 0x00u
} ApplicStartedFirstType;

typedef struct
{
#ifdef BOOTLOADER
   uint8     RANDOM      [RANDOMLENGTH];       /* Seed for the pseudo for SC6 */
#else
   CR_C_s2_t RANDOM;                           /* Seed for the pseudo         */
#endif
   uint8     ApplicStartedFirst;               /* Indication of first start   */
   uint8     FingerPrint [FINGERPRINTLENGTH];  /* FingerPrint                 */
   uint8     VIN         [VINLENGTH];          /* Vehicle Identification      */
} BootProgDataType;

extern VAR(BootProgDataType, COMMON_VAR) BootProgData;

/* end -- Nxtr SW */

#ifndef BOOTMANAGER
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>        /* AUTOSAR Standard Types                       */
//#include "sc_types.h"         /* include StandardCore types                   */
//#include "DataLogistic.h"     /* for FingerPrint length definition            */
//#include "Bootloader_Cfg.h"   /* include Bootloader configuration             */
#ifdef BOOTLOADER
   #include "Vsm_Client.h"    /* VSM modul specific include                   */
   #include "Boot_Crypto.h"   /* Crypto routines                              */
#else
//   #include "Appl_Crypto.h"   /* Crypto routines                              */
#endif


#endif /* BOOTMANAGER -- KS added */
#endif /* SC_EE_DATA_H                                                        */

/*** End of file **************************************************************/
