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
 *          File:  SchM_Dio.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for Dio
 *********************************************************************************************************************/
#ifndef SCHM_DIO_H
# define SCHM_DIO_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define DIO_EXCLUSIVE_AREA_0   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define SCHM_DIO_INSTANCE_0    (0u)


# define SchM_Enter_Dio(ExclusiveArea) \
   SchM_EnterHook_Dio_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_Dio_Return(ExclusiveArea);


# define SchM_Exit_Dio(ExclusiveArea) \
   SchM_ExitHook_Dio_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_Dio_Return(ExclusiveArea);


#endif /* SCHM_DIO_H */

