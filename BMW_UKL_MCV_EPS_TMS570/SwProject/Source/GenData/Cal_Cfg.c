/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vctr Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Cal
 *           Program: MSR BAC 4.0 (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M
 *    License Scope : The usage is restricted to CBD1500658_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cal_Cfg.c
 *   Generation Time: 2016-08-17 09:37:45
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1500658_D00
 *      Tool Version: DaVinci Configurator (beta) 5.10.26 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#define CAL_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Cal_Types.h"

/* Include of configured services */
#include "Cpl_SHA.h" 


/**********************************************************************************************************************
 *  GLOBAL CONSTANTS
 *********************************************************************************************************************/

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(Cal_HashConfigType, CAL_CONST) Cal_HashConfig[1] = 
{
  {
    0U /*  Id  */ , 
    Cpl_SHAStart /*  Start  */ , 
    Cpl_SHAUpdate /*  Update  */ , 
    Cpl_SHAFinish /*  Finish  */ , 
    &CplSHAConfig /*  Init  */ 
  }
}; /* PRQA S 3408 */ /* MD_CAL_8.8 */


#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

