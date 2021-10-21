/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_comp_specific.h                                          **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : NECV850,                                                      **
**              ST10,                                                         **
**              ST30,                                                         **
**              HC12,                                                         **
**              S12X,                                                         **
**              PPC5554,                                                      **
**              MPC5516,                                                      **
**              PPC,                                                          **
**              TMS470,                                                       **
**              TriCore,                                                      **
**              FR50/MB91,                                                    **
**              MAC71XX,                                                      **
**              MAC7XXX,                                                      **
**              Win32x86                                                      **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : ELEKTROBIT AUTOMOTIVE                                         **
**                                                                            **
**  PURPOSE   : architecture specific types and defines                       **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: yes                                          **
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
** mani         Markus Nirschl             ELEKTROBIT AUTOMOTIVE              **
** jd           Jochen Decker              ELEKTROBIT AUTOMOTIVE              **
** mg           Matthias Galota            ELEKTROBIT AUTOMOTIVE              **
** am           Alexander Much             ELEKTROBIT AUTOMOTIVE              **
** sc           Juergen Scherg             ELEKTROBIT AUTOMOTIVE              **
** fs           Frank Stamm                ELEKTROBIT AUTOMOTIVE              **
** dobr         Dominik Brader             ELEKTROBIT AUTOMOTIVE              **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V5.0.3: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                                    defined values
 * V5.0.2: 20.03.2007,mani: porting to mpc5516, add define __ARCH_MPC5510__
 * V5.0.1: 20.12.2006, mg : CR60916: fixed signature check problems on S12X
 *         01.12.2006,dobr: added new architecture MAC7XXX
 * V5.0.0: 31.10.2006, mg : type abstraction for jumptable
 *         21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : improved formatting, changed macro syntax,added
 *                          cancelation functionality
 * V4.1.0: 22.06.2006, mg : no changes
 * V4.0.0: 03.04.2006, mg : moved configuration options to Crypto_Cfg.h, key
 *                          length configurable independently for authentication
 *                          and signature, cleaned up cr_c_hash.c,
 *                          removed compiler warnings
 *         22.02.2006, fs : added coding functions
 * V3.3.1: 11.11.2005, jd : added support for TriCore, ST30, MAC7100 and MB91
 * V3.3.0: 28.10.2005, jd : adapted to programming guidelines 1.6.1,
 *                          incorporated memory mappings of SC6.5,
 *                          added jumptable for access from application space
 * V3.2.1: 22.07.2005, mg : adapted header files for SC6
 * V3.2.0: 22.07.2005, am : changed type infrastructure from a mixed near/far
 *                          environment to a pure far API
 * V3.1.0: 03.05.2005, mg : adapted file header
 * V3.0.0: 17.02.2005, am : adopted to SC4, MISRA cleanups
 * V2.0.0: 08.10.2004, sc : Adoption from Acryl 2.1. Adapted to 16 bit CPUs.
 */

#if !defined( CR_C_COMP_SPECIFIC_H )
#define CR_C_COMP_SPECIFIC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"                                  /* a&s configuration */
#include "Std_Types.h"                                   /* standard types    */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


#if (defined __ARCH_C16X__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST _huge
   #define CR_DEF_FAR_MEMORY _far              /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_ON            /* use memcpy of A&S           */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_E500PPC__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_MPC5510__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_F2MC16L__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY __far             /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH__HC12__)

   #if (defined __HIWARE__)

      #define CR_CONST
      #define CR_JMPTCFG_CONST
      #define CR_DEF_FAR_MEMORY                /* keyword for far memory      */
      #if !defined( TriggerCOP )
         #define TriggerCOP()                  /* do not use TriggerCOP       */
      #endif

      #define CR_DEF_USE_OWN_MEMCPY STD_ON         /* use memcpy of A&S           */
      #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

   #elif (defined __COSMIC__)

      #define CR_CONST
      #define CR_JMPTCFG_CONST
      #define CR_DEF_FAR_MEMORY @far           /* keyword for far memory      */
      #if !defined( TriggerCOP )
         #define TriggerCOP()                  /* do not use TriggerCOP       */
      #endif

      #define CR_DEF_USE_OWN_MEMCPY STD_ON         /* use memcpy of A&S           */
      #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

   #else

      #error The compiler for the HC12 platform is unknown

   #endif

#elif (defined __ARCH_S12X__) || (defined __ARCH_S12X)

   #if (defined __HIWARE__)

      #define CR_CONST
      #define CR_JMPTCFG_CONST
      #define CR_DEF_FAR_MEMORY                /* keyword for far memory      */
      #if !defined( TriggerCOP )
         #define TriggerCOP()                  /* do not use TriggerCOP       */
      #endif

      #define CR_DEF_USE_OWN_MEMCPY STD_ON         /* use memcpy of A&S           */

      /* CodeWarrrior cannot handle 32 bit array indices in "banked" mode.    */
      /* They are silently replaced by 16 bit indices. This workaround is not */
      /* MISRA compliant.                                                     */
      #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) \
                                    (*(CR_fpc_uint8)((uint32)(array) + (index)))
   #elif (defined __COSMIC__)

      #define CR_CONST
      #define CR_JMPTCFG_CONST
      #define CR_DEF_FAR_MEMORY @far           /* keyword for far memory      */
      #if !defined( TriggerCOP )
         #define TriggerCOP()                  /* do not use TriggerCOP       */
      #endif


      #define CR_DEF_USE_OWN_MEMCPY STD_ON         /* use memcpy of A&S           */
      #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

   #else

      #error The compiler for the HC12 platform is unknown

   #endif

#elif (defined __ARCH_PPC__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_ST30__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_TMS470__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_TRICORE__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_V850__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_Win32x86__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_FR50__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_MAC71XX__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#elif (defined __ARCH_MAC7XXX__)

   #define CR_CONST
   #define CR_JMPTCFG_CONST
   #define CR_DEF_FAR_MEMORY                   /* keyword for far memory      */
   #if !defined( TriggerCOP )
      #define TriggerCOP()                     /* do not use TriggerCOP       */
   #endif

   #define CR_DEF_USE_OWN_MEMCPY STD_OFF           /* use external memcpy routine */
   #define CR_C_LARGE_BYTE_ARRAY_ACCESS(array,index) ((array)[(index)])

#else

   #error No valid architecture given

#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


               /* these are all 32-bit processors that do not need far memory */
#if (defined __ARCH_E500PPC__) || \
    (defined __ARCH_MPC5510__) || \
    (defined __ARCH_PPC__)     || \
    (defined __ARCH_ST30__)    || \
    (defined __ARCH_TMS470__)  || \
    (defined __ARCH_TRICORE__) || \
    (defined __ARCH_V850__)    || \
    (defined __ARCH_FR50__)    || \
    (defined __ARCH_MAC71XX__) || \
    (defined __ARCH_MAC7XXX__) || \
    (defined __ARCH_Win32x86__)


typedef const uint8            CR_fc_uint8;
typedef const uint16           CR_fc_uint16;
typedef const uint32           CR_fc_uint32;

typedef       uint8  *         CR_fp_uint8;
typedef       uint16 *         CR_fp_uint16;
typedef       uint32 *         CR_fp_uint32;
typedef const uint8  *         CR_fpc_uint8;
typedef const uint16 *         CR_fpc_uint16;
typedef const uint32 *         CR_fpc_uint32;

typedef const uint8  * const   CR_cfpc_uint8;
typedef const uint16 * const   CR_cfpc_uint16;
typedef const uint32 * const   CR_cfpc_uint32;

typedef const uint8  * const * CR_fpcfpc_uint8;

typedef       void   *         CR_fp_void;
typedef const void   *         CR_fpc_void;
typedef const void   * const   CR_cfpc_void;

#elif (defined __ARCH_HC12__) || \
      (defined __ARCH_S12X__) || \
      (defined __ARCH_S12X)

                             /* switch between 2 compilers: hiware and cosmic */

#if (defined __HIWARE__)

typedef const uint8    far             CR_fc_uint8;
typedef const uint16   far             CR_fc_uint16;
typedef const uint32   far             CR_fc_uint32;

typedef       uint8  * far             CR_fp_uint8;
typedef       uint16 * far             CR_fp_uint16;
typedef       uint32 * far             CR_fp_uint32;
typedef const uint8  * far             CR_fpc_uint8;
typedef const uint16 * far             CR_fpc_uint16;
typedef const uint32 * far             CR_fpc_uint32;

typedef const uint8  * far const       CR_cfpc_uint8;
typedef const uint16 * far const       CR_cfpc_uint16;
typedef const uint32 * far const       CR_cfpc_uint32;

typedef const uint8  * far const * far CR_fpcfpc_uint8;

typedef       void   * far             CR_fp_void;
typedef const void   * far             CR_fpc_void;
typedef const void   * far const       CR_cfpc_void;

#elif (defined __COSMIC__)

typedef const uint8    @far              CR_fc_uint8;
typedef const uint16   @far              CR_fc_uint16;
typedef const uint32   @far              CR_fc_uint32;

typedef       uint8  * @far              CR_fp_uint8;
typedef       uint16 * @far              CR_fp_uint16;
typedef       uint32 * @far              CR_fp_uint32;
typedef const uint8  * @far              CR_fpc_uint8;
typedef const uint16 * @far              CR_fpc_uint16;
typedef const uint32 * @far              CR_fpc_uint32;

typedef const uint8  * @far const        CR_cfpc_uint8;
typedef const uint16 * @far const        CR_cfpc_uint16;
typedef const uint32 * @far const        CR_cfpc_uint32;

typedef const uint8  * @far const * @far CR_fpcfpc_uint8;

typedef       void   * @far              CR_fp_void;
typedef const void   * @far              CR_fpc_void;
typedef const void   * @far const        CR_cfpc_void;

#else

#error No valid Compiler set for HC12/S12X architecture.

#endif                                         /* compiler switch inside HC12 */

#elif (defined __ARCH_C16X__)

                                       /* we use the tasking compiler, right? */

typedef const uint8  _huge                 CR_fc_uint8;
typedef const uint16 _huge                 CR_fc_uint16;
typedef const uint32 _huge                 CR_fc_uint32;

typedef       uint8  _huge *               CR_fp_uint8;
typedef       uint16 _huge *               CR_fp_uint16;
typedef       uint32 _huge *               CR_fp_uint32;
typedef const uint8  _huge *               CR_fpc_uint8;
typedef const uint16 _huge *               CR_fpc_uint16;
typedef const uint32 _huge *               CR_fpc_uint32;

typedef const uint8  _huge * const         CR_cfpc_uint8;
typedef const uint16 _huge * const         CR_cfpc_uint16;
typedef const uint32 _huge * const         CR_cfpc_uint32;

typedef const uint8  _huge * const _huge * CR_fpcfpc_uint8;

typedef       void   _huge *               CR_fp_void;
typedef const void   _huge *               CR_fpc_void;
typedef const void   _huge * const         CR_cfpc_void;

#elif (defined __ARCH_F2MC16L__)
                                             /* Fujitsu Softune Compiler, ok? */

typedef const uint8  __far                 CR_fc_uint8;
typedef const uint16 __far                 CR_fc_uint16;
typedef const uint32 __far                 CR_fc_uint32;

typedef       uint8  __far *               CR_fp_uint8;
typedef       uint16 __far *               CR_fp_uint16;
typedef       uint32 __far *               CR_fp_uint32;
typedef const uint8  __far *               CR_fpc_uint8;
typedef const uint16 __far *               CR_fpc_uint16;
typedef const uint32 __far *               CR_fpc_uint32;

typedef const uint8  __far * const         CR_cfpc_uint8;
typedef const uint16 __far * const         CR_cfpc_uint16;
typedef const uint32 __far * const         CR_cfpc_uint32;

typedef const uint8  __far * const __far * CR_fpcfpc_uint8;

typedef       void   __far *               CR_fp_void;
typedef const void   __far *               CR_fpc_void;
typedef const void   __far * const         CR_cfpc_void;


#else

#error No valid architecture given.

#endif               /* Architecture specific far memory and type definitions */

typedef enum {                               /* return code type              */
   CR_C_RC_OK       = 0,                     /* successfully finished         */
   CR_C_RC_NF       = 1,                     /* not yet finished              */
   CR_C_RC_EOB      = 2,                     /* end of block missing          */
   CR_C_RC_LVL      = 3,                     /* unsupported level             */
   CR_C_RC_ERR      = 4,                     /* error                         */
   CR_C_RC_ERR2     = 5,                     /* error                         */
   CR_C_RC_CANCELED = 6                      /* computation has been canceled */
} CR_C_RC_t;



                                       /* A macro describing the null pointer */
#define CR_NULL 0

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


#endif /* if !defined( CR_C_COMP_SPECIFIC_H ) */
/*** End of file **************************************************************/
