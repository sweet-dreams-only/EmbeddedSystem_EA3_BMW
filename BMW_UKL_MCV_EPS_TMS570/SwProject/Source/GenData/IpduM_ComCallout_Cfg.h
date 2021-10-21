

/* --------{ EB Automotive C Source File }-------- */
#ifndef IPDUM_COMCALLOUT_CFG_H
#define IPDUM_COMCALLOUT_CFG_H

/*==================[includes]==============================================*/

#include <IpduM.h>                  /* Module interface */
#include <IpduM_Types.h>            /* Module types */

/*==================[macros]================================================*/

/* Network ordering of Global EcuId */
#define IPDUM_NETWORK_BIG_ENDIAN        STD_OFF


#define IPDUM_SERVICE_MESSAGES          STD_ON

/* Number of service message */
#define IPDUM_MAP_INFO_LENGTH           1U
/* Defines the byte position of the data field in the received message */
#define IPDUM_RX_CALLOUT_BYTEPOS        1U
/* Defines the length of the data field */
#define IPDUM_RX_CALLOUT_LENGTH         2U
/* Table for mapping of global EcuId to HandleId for requesting Pdu */
#define IPDUM_MAP_INFO_CFG \
  { \
  { 2U, 2U }, \
  }

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_COMCALLOUT_CFG_H */
/*==================[end of file]===========================================*/
