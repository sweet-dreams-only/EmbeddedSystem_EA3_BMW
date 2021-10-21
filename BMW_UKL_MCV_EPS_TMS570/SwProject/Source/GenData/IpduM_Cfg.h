

/* --------{ EB Automotive C Source File }-------- */


/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
 /* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   As the function is called very often and consists only of a one line
  *   the macro based implmentation is more run time efficient.
  *
  */

#ifndef IPDUM_CFG_H
#define IPDUM_CFG_H

/* This file contains all target independent public configuration declarations
 * for the AUTOSAR module IpduM. */

/*==================[inclusions]============================================*/
#include <Std_Types.h>
#include <ComStack_Types.h>

/*==================[macros]================================================*/

#if (defined IPDUM_ALTERNATIVE_PROCESSREQUEST_API) /* guard to prevent double declaration */
#error IPDUM_ALTERNATIVE_PROCESSREQUEST_API already defined
#endif /* if (defined IPDUM_ALTERNATIVE_PROCESSREQUEST_API) */

/** \brief switch, for alternative Ipdum_ProcessRequestPdu api
 *
 * This switch decides which api signatur for Ipdum_ProcessRequestPdu is used.
 * The value STD_ON defines the signatur as defined in autosar spec 2.1.
 * Is the switch set to STD_OFF an alternative signature is used, as defined
 * in autosar bugzilla entry 24551.
 */
#define IPDUM_ALTERNATIVE_PROCESSREQUEST_API STD_ON



#if (defined IPDUM_USE_RXINDICATION_NAME) /* guard to prevent double declaration */
#error IPDUM_USE_RXINDICATION_NAME already defined
#endif /* if (defined IPDUM_USE_RXINDICATION_NAME) */

/** \brief switch, for usage of rxindication as symbolic name
 *
 * This switch en-/disables the generation of symbolic name macros.
 * The defines are named by the short-name of the rxindication container, the values
 * are the handle ids of the pdu assigned to the indication.
 */
#define IPDUM_USE_RXINDICATION_NAME STD_OFF



#if (defined IPDUM_VENDOR_ID_3SOFT) /* guard to prevent double declaration */
#error IPDUM_VENDOR_ID_3SOFT already defined
#endif /* if (defined IPDUM_VENDOR_ID_3SOFT) */

/** \brief definition of the unique vendor ID
 *
 * This vendor ID is based on the vendor ID published by the HIS.
 * It should be used for each module */
#define IPDUM_VENDOR_ID_3SOFT 1U



#if (defined IPDUM_PARAM_UNUSED) /* guard to prevent double definition */
#error IPDUM_PARAM_UNUSED already defined
#endif /* (defined IPDUM_PARAM_UNUSED) */

/**
 * Use the symbol to avoid compiler warnings
 */
/* Deviation MISRA-1 */
#define IPDUM_PARAM_UNUSED(x) (void) (x)



#if (defined IpduM_AtomicAssign16) /* guard to prevent double definition */
#error IpduM_AtomicAssign16 already defined
#endif /* (defined IpduM_AtomicAssign16) */

/** \brief Assigns the 16 bit entity \p from to \p to in an atomic fashion
 **
 ** This macro assigns the 16 bit entity \p from to \p to in an atomic fashion
 **
 ** The parameters \p from and \p to thus have to be of type \p uint16 or \p sint16.
 **
 ** \param[out] to    16 bit entity which is the destionation of the assignment
 ** \param[in]  from  16 bit entity which is the source of the assignment
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
/* Deviation MISRA-1 */
#define IpduM_AtomicAssign16(to, from) \
    ((to) = (from))

/*------------------[General]-----------------------------------------------*/

#define  IPDUM_AUTOSAR_VERSION  30

#if (defined IPDUM_SCHM_WITH_INSTANCEID)
#error IPDUM_SCHM_WITH_INSTANCEID already defined
#endif

/** \brief macro to select if SchM shall be called with instance id or not */
#define IPDUM_SCHM_WITH_INSTANCEID    STD_OFF



#if (defined IPDUM_DEV_ERROR_DETECT)
#error IPDUM_DEV_ERROR_DETECT already defined
#endif

/** \brief Switch, indicating if development error detection is activated for
 ** IPDUM */
#define IPDUM_DEV_ERROR_DETECT         STD_ON



#if (defined IPDUM_VERSION_INFO_API)
#error IPDUM_VERSION_INFO_API already defined
#endif

/** \brief Switch, indicating if the version information API is activated or
 ** deactivated for IPDUM */
#define IPDUM_VERSION_INFO_API         STD_ON



#if (defined IPDUM_STATIC_PART_EXISTS)
#error IPDUM_STATIC_PART_EXISTS already defined
#endif

/** \brief Switch, indicating if a static part exists or not in an IPDU.
 ** This is to allow optimizations in case the IPduM will never
 ** be used with a static part.
 **
 ** \note This is a pre-compile option. If this is set to False then it
 ** will not be possible to add static parts after compilation.
 **/
#define IPDUM_STATIC_PART_EXISTS         STD_OFF



#if (defined IPDUM_CONFIGURATION_TIME_BASE)
#error IPDUM_CONFIGURATION_TIME_BASE already defined
#endif

/** \brief The period between successive ticks of AUTOSAR COM in seconds.
 **/
#define IPDUM_CONFIGURATION_TIME_BASE 0.01



#if (defined IPDUM_ZERO_COPY)
#error IPDUM_ZERO_COPY already defined
#endif

/** \brief This indicates do not allocate memory for data in the IPduM.
**  Only pointers for static and dynamic parts will be passed.
**
** \note Zero copy is possible only in some circumstances.
 **/
#define IPDUM_ZERO_COPY         STD_OFF



#if (defined IPDUM_BYTE_COPY)
#error IPDUM_BYTE_COPY already defined
#endif

/** \brief Switch, indicating use of byte-wise copy routines. Only possible if static and
**  dynamic parts are already byte-aligned.
**/
#define IPDUM_BYTE_COPY         STD_OFF



#if (defined IPDUM_DYNAMIC_PART_QUEUE)
#error IPDUM_DYNAMIC_PART_QUEUE already defined
#endif

/** \brief This specifies if queuing is enabled for dynamic PDUs.
**/
#define IPDUM_DYNAMIC_PART_QUEUE         STD_OFF



/** \brief This specifies the number of bytes on stack used for the buffer
**  in RxIndication
**/
#define IPDUM_RECEIVE_STACK_SIZE 254U



/** \brief This specifies the number of bytes for the SDU buffer in the
**  transmission queue
**/
#define IPDUM_TX_SDU_SIZE 58U



#if (defined IPDUM_AUTOMATIC_SELECTOR)
#error IPDUM_AUTOMATIC_SELECTOR already defined
#endif

/** \brief This specifies if automatic selector setting is enabled for transmit
**  PDUs.
**/
#define IPDUM_AUTOMATIC_SELECTOR         STD_OFF



#if (IPDUM_USE_RXINDICATION_NAME==STD_ON)
   #if (defined IPduMRxIndication_SVC_DSC_Modul)
   #error IPduMRxIndication_SVC_DSC_Modul already defined
   #endif
   /** \brief The handle id for IPduMRxIndication_SVC_DSC_Modul
   **/
   #define IPduMRxIndication_SVC_DSC_Modul (0U)
#endif
#if (IPDUM_USE_RXINDICATION_NAME==STD_ON)
   #if (defined IPduMRxIndication_SVC_SAS)
   #error IPduMRxIndication_SVC_SAS already defined
   #endif
   /** \brief The handle id for IPduMRxIndication_SVC_SAS
   **/
   #define IPduMRxIndication_SVC_SAS (1U)
#endif
#if (IPDUM_USE_RXINDICATION_NAME==STD_ON)
   #if (defined IPduMRxIndication_SVC_ZGW)
   #error IPduMRxIndication_SVC_ZGW already defined
   #endif
   /** \brief The handle id for IPduMRxIndication_SVC_ZGW
   **/
   #define IPduMRxIndication_SVC_ZGW (2U)
#endif






#if (defined IPduMTxDynamicPart_DBG_EPS_BS_MOD_58_BYTE)
#error IPduMTxDynamicPart_DBG_EPS_BS_MOD_58_BYTE already defined
#endif

/** \brief The handle id for IPduMTxDynamicPart_DBG_EPS_BS_MOD_58_BYTE
**/
#define IPduMTxDynamicPart_DBG_EPS_BS_MOD_58_BYTE (0U)
#if (defined IPduMTxDynamicPart_DBG_EPS_MOD_EXT_120_BYTE)
#error IPduMTxDynamicPart_DBG_EPS_MOD_EXT_120_BYTE already defined
#endif

/** \brief The handle id for IPduMTxDynamicPart_DBG_EPS_MOD_EXT_120_BYTE
**/
#define IPduMTxDynamicPart_DBG_EPS_MOD_EXT_120_BYTE (1U)



#if (defined IPduMTxDynamicPart_ANFRAGE_EPS)
#error IPduMTxDynamicPart_ANFRAGE_EPS already defined
#endif

/** \brief The handle id for IPduMTxDynamicPart_ANFRAGE_EPS
**/
#define IPduMTxDynamicPart_ANFRAGE_EPS (2U)
#if (defined IPduMTxDynamicPart_RQ_STG_EFAN_EPS)
#error IPduMTxDynamicPart_RQ_STG_EFAN_EPS already defined
#endif

/** \brief The handle id for IPduMTxDynamicPart_RQ_STG_EFAN_EPS
**/
#define IPduMTxDynamicPart_RQ_STG_EFAN_EPS (3U)

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_CFG_H */
/*==================[end of file]===========================================*/
