/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Crypto_Cfg.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW AUTOSAR Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive, MB-Technology                                  **
**                                                                            **
**  PURPOSE   : Modular make environment. Contains configuration parameters   **
**              which are exclusively dedicated to the crypto module.         **
**              The crypto module is a sub component of the bootloader.       **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
**                                                                            ** 
**  DISCLAIMER:                                                               **
**  As the program is not fully tested and qualified for series production    **
**  use, the user shall not be entitled to use the program in connection      **
**  with any series production. BMW provides the user with the program only   **
**  as sample application (for testing purposes).                             **
**                                                                            ** 
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** eb           Elmar Boehler              EB Automotive                      **
** anht         Andreas Hartmann           EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** guab         Günter Abelen              MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.4: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V2.1.3: 17.11.2010,   ft: CR70786: Move Definition of CR_DEF_TELESERVICE
 *                                    from Crypto_Cfg.h to Crypto_Cfg_DEMOKEY.h/HOTKEY.h
 * V2.1.2: 09.11.2010, guab: CR70785: Separate Crypto Key Configuration Files
 * V2.1.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V2.1.0: 30.10.2009, gema: CR70436 includes added
 * V1.2.0: 25.08.2008, anht: Set 'CR_DEF_USE_INTERRUPTION' to 'STD_ON'
 *         06.08.2008, eb  : added a warning for key sizes of 2048 bit: in this
 *                           case the signature verification of the CSM may
 *                           take too much time
 * V1.1.0: 15.11.2007, miwe: integration of crypto jumptable, enabled cancel
 *                           support for Application
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V5.1.0
 */


/*************************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Oct 19 12:16:01 2011
 * %version:          EA3#12 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Thu Oct 20 10:20:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 10/20/11   7       BDO        Integrate BMW Crypto_Cfg.h file
 * 10/20/11   8       BDO        Add CRYPTO_JUMPTABLE_ADDR 0x0003FE24
 * 10/05/16	 EA3#12   ABS		 Authentication and Signature changes - 2048bit key and SHA256 hash				EA3#7986

*************************************************************************************************************************/

#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

/* Nxtr defined to avoid ifndef error below - can be removed at some point */
#define I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION

#ifndef I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
#error "the program must not be used in connection with series production"
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifdef BAC
  #include <Std_Types.h>            /* AUTOSAR Standard Types */
  #include "sc_target_arch.h"       /* memcopy functions */
#else
  #include "StandardCore_Cfg.h"          /* contains jumptable address          */
  #include "os.h"                        /* contains architecture specification */
  #include "Std_Types.h"                 /* contains the macros STD_ON and STD_OFF */
  #include "sc_target_arch.h"            /* memcopy functions                   */
#endif
#include "cr_c_comp_specific.h"        /* crypto type definitions             */
/*EP Beginn*/
#ifdef BAC
  #ifndef BOOTMANAGER
    #ifndef __BLU__
     #include "Dcm_Appl.h"       /* AUTOSAR DCM Module, needed for SC6 diag     */
	#endif 
  #endif /* Bootloader */
#endif
/*EP Ende */
/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*----------------------------------------------------------------------------*/
/* jumptable configuration                                                    */
/*----------------------------------------------------------------------------*/
                                              /* The address of the jumptable */
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Address modified because of the increase in signature size from 1024-bit to
 * 				2048-bit
 */
 #if 0
/* Original code - START */
#define CRYPTO_JUMPTABLE_ADDR 0x0003FE24
/* Original code - END */
#endif
/* Patch code  - START */
#define CRYPTO_JUMPTABLE_ADDR 0x0003FDA4
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/



#ifdef BAC
  #ifndef CRYPTO_HOTKEY
   #error "Crypto_Cfg.h: CRYPTO_HOTKEY must be 0 or 1 (set in Common in Makefile.compiler depending of KEY_TYPE_APPLICATION set in Makefile.env)"
  #endif

  #if (CRYPTO_HOTKEY == 1)                    /* include hot crypto keys        */
   #include "Crypto_Cfg_HOTKEY.h"             /* contains hot key definitions   */
  #else (CRYPTO_HOTKEY == 0)                  /* include demo crypto keys       */
   #include "Crypto_Cfg_DEMOKEY.h"            /* contains demo key definitions  */
  #endif
#else
  #if (SC_CRYPTO_HOTKEY == 1)   /* include hot crypto keys */
    #include "Crypto_Cfg_hotkey.h"              /* contains hot key definitions   */
  #elif (SC_CRYPTO_HOTKEY == 0) /* include SC6 demo keys */
    #include "Crypto_Cfg_demokey.h"              /* contains hot key definitions   */
  #else
     #error "Crypto_Cfg.h: HOTKEY must be 0 or 1 (in StandardCore.mcfg)"
  #endif
#endif  

/*----------------------------------------------------------------------------*/
/* depends on setup of CR_DEF_TELESERVICE.                                    */
/*----------------------------------------------------------------------------*/
#if (CR_DEF_TELESERVICE == STD_ON)
/* AM: this is commented for some reason? */
/* #define CR_DEF_USE_LEVEL0 */     /* used by CAS-merge / CR_DEF_TELESERVICE */
#else                                         /* if (CR_DEF_TELESERVICE == STD_ON)*/
    #define  CR_DEF_USE_LEVEL0 STD_OFF
#endif                                       /* if (CR_DEF_TELESERVICE == STD_ON) */

#define CR_DEF_USE_LEVEL1 STD_OFF                           /* do not use level 1 */
#define CR_DEF_USE_LEVEL2 STD_OFF                           /* do not use level 2 */
#define CR_DEF_USE_LEVEL3 STD_ON                                   /* use level 3 */
#define CR_DEF_USE_LEVEL4 STD_ON       /* NXTR SWT */  /* use level 4 */
#define CR_DEF_USE_LEVEL5 STD_OFF                           /* do not use level 5 */

/*----------------------------------------------------------------------------*/
/* setup for symm and asymm protection                                        */
/*----------------------------------------------------------------------------*/
#define CR_DEF_STGAUTH STD_OFF                     /* controller authentification */

/*----------------------------------------------------------------------------*/
/* setup for simple random generator and padding (teleservice)                */
/*----------------------------------------------------------------------------*/
#define CR_DEF_RNG_ADV STD_OFF       /* do not use extensions of random generator */

#define CR_DEF_RNG_PAD_ZERO STD_OFF                         /* use random padding */

/*----------------------------------------------------------------------------*/
/* setup optional assymetric package                                          */
/*----------------------------------------------------------------------------*/

#define CR_DEF_FINGERPRINT STD_OFF     /* do not use opt. fingerprint subroutines */

#define CR_DEF_ENCRYPTION STD_OFF     /* do not use optional encryption routines. */

#define CR_DEF_USE_BARRETT STD_OFF                 /* do not use barret reduction */

#define CR_DEF_INT64_AVAILABLE STD_OFF        /* use int32 type in exponantiation */

/*----------------------------------------------------------------------------*/
/* setup for use of static variables and functions                            */
/*----------------------------------------------------------------------------*/
#ifdef SC6_2_ASR
   /* TS_STATIC_VAR is already defined by Autosar Base Plugin */
   #define TS_STATIC_VAR      static        /* 'static' keyword for objects */
#endif

#ifndef TS_STATIC_FUNCTION
   #define TS_STATIC_FUNCTION static        /* 'static' keyword for functions */
#endif


/*----------------------------------------------------------------------------*/
/* setup for use of DET                                                       */
/*----------------------------------------------------------------------------*/

                                /* If this macro is set to STD_ON the DET is used */
#define CR_DEV_ERROR_DETECT STD_OFF


#if (CR_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                                         /* DET for debugging */
#endif

                            /*  The module ID of the CSM for usage in the DET */
#define CR_DET_MODULE_ID 733U


#define CR_MEXP_NEWAAMEXP_ID           0U
#define CR_MEXP_NEWAASUB_ID            1U
#define CR_MEXP_NEWAAMODB_ID           2U

#define CR_CONTROLLER_CHECKAUTHUSTG_ID 3U
#define CR_CONTROLLER_CHECKSIGSW_ID    4U
#define CR_CONTROLLER_CHECKSIGNCD_ID   5U

#define CR_AUTH_EXTENDCHALL_ID         6U
#define CR_AUTH_AUTH_ID                7U
#define CR_AUTH_CHECKSIGSYMM_ID        8U

/*----------------------------------------------------------------------------*/
/* setup interruption for asym. routines                                      */
/*----------------------------------------------------------------------------*/

#define CR_DEF_USE_INTERRUPTION STD_ON         /* RSA-routines using interruption */

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed MD5 since the hash algorithm is not used
 */
 #if 0
/* Original code - START */
#undef CR_MD5_LEVEL_0              /* do not use level 0 interruption for md5 */
#undef CR_MD5_LEVEL_1              /* do not use level 1 interruption for md5 */
#undef CR_MD5_LEVEL_2              /* do not use level 2 interruption for md5 */
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

#undef CR_EXP_LEVEL_0   /* do not use level 0 interruption for exponentiation */
#undef CR_EXP_LEVEL_1   /* do not use level 0 interruption for exponentiation */
#undef CR_EXP_LEVEL_2   /* do not use level 0 interruption for exponentiation */

#define CR_DEF_USE_CR_C_CALLBACK_C STD_OFF             /* use callback per define */

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed MD5 since the hash algorithm is not used
 */
 #if 0
/* Original code - START */
#if (defined CR_MD5_LEVEL_0) ||                                                \
    (defined CR_MD5_LEVEL_1) ||                                                \
    (defined CR_MD5_LEVEL_2) ||                                                \
    (defined CR_EXP_LEVEL_0) ||                                                \
    (defined CR_EXP_LEVEL_1) ||                                                \
    (defined CR_EXP_LEVEL_2)

    #if (CR_DEF_USE_INTERRUPTION == STD_ON)
        #define CR_DEF_USE_TRIGGER_COP STD_ON
    #else
        #define CR_DEF_USE_TRIGGER_COP STD_OFF
    #endif                              /* if (CR_DEF_USE_INTERRUPTION == STD_ON) */
#else
    #define CR_DEF_USE_TRIGGER_COP STD_OFF
#endif                                       /* CR_MD5_LEVEL* | CR_EXP_LEVEL* */
/* Original code - END */
#endif

/* Patch code  - START */
#if (defined CR_EXP_LEVEL_0) ||                                                \
    (defined CR_EXP_LEVEL_1) ||                                                \
    (defined CR_EXP_LEVEL_2)

    #if (CR_DEF_USE_INTERRUPTION == STD_ON)
        #define CR_DEF_USE_TRIGGER_COP STD_ON
    #else
        #define CR_DEF_USE_TRIGGER_COP STD_OFF
    #endif                              /* if (CR_DEF_USE_INTERRUPTION == STD_ON) */
#else
    #define CR_DEF_USE_TRIGGER_COP STD_OFF
#endif                                       /* CR_EXP_LEVEL* */

/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/*----------------------------------------------------------------------------*/
/* setup for cancelability                                                    */
/*----------------------------------------------------------------------------*/
                                /* Are the crypto routines cancelable or not? */
#define CR_DEF_USE_CANCEL STD_ON


/*----------------------------------------------------------------------------*/
/* setup for memcpy                                                           */
/*----------------------------------------------------------------------------*/
                             /* Use the memcpy function of the standard core. */
#define CR_C_memcpy(dest, source, size) SC_MEMCPY_ROM((dest), (source), (size))

#endif /* CRYPTO_CFG_H                                                        */

/*** End of file **************************************************************/
