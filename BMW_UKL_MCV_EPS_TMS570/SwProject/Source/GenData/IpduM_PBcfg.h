
/* --------{ EB Automotive C Source File }-------- */
#ifndef IPDUM_PBCFG_H
#define IPDUM_PBCFG_H

/* This file contains all target independent public configuration declarations
 * for the AUTOSAR module IpduM. */

/*==================[inclusions]============================================*/
#include <IpduM_Cfg.h>
#include <IpduM_Types.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/
#define IPDUM_START_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/** \brief IpduM configuration
 **
 ** This is the IpduM configuration that can be given to
 ** Ipdum_Init as configuration parameter.
 ** Please note that the name of this element is configuration dependent.
 */
extern CONST(Ipdum_ConfigType, IPDUM_APPL_CONST) IPduMConfig;

#define IPDUM_STOP_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_PBCFG_H */
/*==================[end of file]===========================================*/
