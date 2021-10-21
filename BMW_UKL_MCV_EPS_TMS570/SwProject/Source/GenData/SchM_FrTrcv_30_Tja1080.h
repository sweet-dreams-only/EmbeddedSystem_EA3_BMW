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
 *          File:  SchM_FrTrcv_30_Tja1080.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for FrTrcv_30_Tja1080
 *                 Mainfunctions:
 *                 FrTrcv_30_Tja1080_MainFunction() Cycle Time 5 ms Activation Offset 3 ms
 *********************************************************************************************************************/
#ifndef SCHM_FRTRCV_30_TJA1080_H
# define SCHM_FRTRCV_30_TJA1080_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define SCHM_FRTRCV_30_TJA1080_INSTANCE_0    (0u)


# define SchM_Enter_FrTrcv_30_Tja1080(ExclusiveArea) \
   SchM_EnterHook_FrTrcv_30_Tja1080_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_FrTrcv_30_Tja1080_Return(ExclusiveArea);


# define SchM_Exit_FrTrcv_30_Tja1080(ExclusiveArea) \
   SchM_ExitHook_FrTrcv_30_Tja1080_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_FrTrcv_30_Tja1080_Return(ExclusiveArea);


#endif /* SCHM_FRTRCV_30_TJA1080_H */

