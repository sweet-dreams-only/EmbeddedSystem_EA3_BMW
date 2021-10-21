/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_FrTp.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for FrTp
 *                 Mainfunctions:
 *                 FrTp_MainFunction() Cycle Time 5 ms Activation Offset 0 ms
 *********************************************************************************************************************/
#ifndef SCHM_FRTP_H
# define SCHM_FRTP_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define FRTP_CRITICAL_SECTION_ID   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define FRTP_CRITICAL_SECTION_INSTANCE    (0u)


# define SchM_Enter_FrTp(instance, ExclusiveArea) \
   SchM_EnterHook_FrTp_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_FrTp_Return(ExclusiveArea);


# define SchM_Exit_FrTp(instance, ExclusiveArea) \
   SchM_ExitHook_FrTp_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_FrTp_Return(ExclusiveArea);


#endif /* SCHM_FRTP_H */

