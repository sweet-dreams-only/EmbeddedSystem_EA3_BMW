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
 *          File:  SchM_Fr.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for Fr
 *********************************************************************************************************************/
#ifndef SCHM_FR_H
# define SCHM_FR_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define FR_EXCLUSIVE_AREA_0   (SCHM_EA_SUSPENDALLINTERRUPTS)
# define FR_EXCLUSIVE_AREA_1   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define SCHM_FR_INSTANCE_0    (0u)


# define SchM_Enter_Fr(ExclusiveArea) \
   SchM_EnterHook_Fr_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_Fr_Return(ExclusiveArea);


# define SchM_Exit_Fr(ExclusiveArea) \
   SchM_ExitHook_Fr_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_Fr_Return(ExclusiveArea);


#endif /* SCHM_FR_H */

