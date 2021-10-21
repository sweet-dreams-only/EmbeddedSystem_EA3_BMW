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
 *          File:  SchM_Coding.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for Coding
 *********************************************************************************************************************/
#ifndef SCHM_CODING_H
# define SCHM_CODING_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define SCHM_CODING_EXCLUSIVE_AREA_0   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define SCHM_CODING_INSTANCE_0    (0u)


# define SchM_Enter_Coding(ExclusiveArea) \
   SchM_EnterHook_Coding_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_Coding_Return(ExclusiveArea);


# define SchM_Exit_Coding(ExclusiveArea) \
   SchM_ExitHook_Coding_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_Coding_Return(ExclusiveArea);


#endif /* SCHM_CODING_H */

