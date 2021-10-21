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
 *          File:  SchM_EcuM.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Header of BSW Scheduler for EcuM
 *                 Mainfunctions:
 *                 EcuM_MainFunction() Cycle Time 10 ms Activation Offset 3 ms
 *********************************************************************************************************************/
#ifndef SCHM_ECUM_H
# define SCHM_ECUM_H

# include "SchM.h"
# include "SchM_Types.h"
# include "SchM_Cfg.h"


# define SCHM_START_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

extern CONST(uint8, SCHM_CONST) ECUM_EXCLUSIVE_AREA_0;
extern CONST(uint8, SCHM_CONST) ECUM_EXCLUSIVE_AREA_1;

extern CONST(uint8, SCHM_CONST) SCHM_ECUM_INSTANCE_0;

# define SCHM_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */


# define SCHM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */

FUNC(void, SCHM_CODE) SchM_Enter_EcuM(uint8 ExclusiveArea);
FUNC(void, SCHM_CODE) SchM_Exit_EcuM(uint8 ExclusiveArea);

# define SCHM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_SCHM_19.1 */


#endif /* SCHM_ECUM_H */

