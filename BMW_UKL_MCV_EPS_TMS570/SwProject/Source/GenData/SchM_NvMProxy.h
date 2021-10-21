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
 *          File:  SchM_NvMProxy.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for NvMProxy
 *                 Mainfunctions:
 *                 NvMProxy_MainFunction() Cycle Time 10 ms Activation Offset 3 ms
 *********************************************************************************************************************/
#ifndef SCHM_NVMPROXY_H
# define SCHM_NVMPROXY_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"

# define NVMPROXY_EXCLUSIVE_AREA_0   (SCHM_EA_SUSPENDALLINTERRUPTS)

# define SCHM_NVMPROXY_INSTANCE_0    (0u)


# define SchM_Enter_NvMProxy(ExclusiveArea) \
   SchM_EnterHook_NvMProxy_Start(ExclusiveArea); \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea); \
   SchM_EnterHook_NvMProxy_Return(ExclusiveArea);


# define SchM_Exit_NvMProxy(ExclusiveArea) \
   SchM_ExitHook_NvMProxy_Start(ExclusiveArea); \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea); \
   SchM_ExitHook_NvMProxy_Return(ExclusiveArea);


#endif /* SCHM_NVMPROXY_H */

