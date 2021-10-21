/* Kernbauer Version: 1.16 Konfiguration: Gw_AsrPduR Erzeugungsgangnummer: 947 */

/* STARTSINGLE_OF_MULTIPLE */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR.h
 *      Project:  Gw_AsrPduR
 *       Module:  MICROSAR PDU Router
 *    Generator:  GENy
 *
 *  Description:  Implements AUTOSAR PDU Router SWS Version: 2.2.1
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Hartmut Hoerner               HH            Vctr Informatik GmbH
 *  Gunnar de Haan                dH            Vctr Informatik GmbH
 *  Holger Birke                  Bir           Vctr Informatik GmbH
 *  Hannes Haas                   vishs         Vctr Informatik GmbH
 *  Erich Schondelmaier           visehs        Vctr Informatik GmbH
 *  Gunnar Meiss                  visms         Vctr Informatik GmbH
 *  Safiulla Shakir               visssa        Vctr Informatik GmbH
 *  Sebastian Waldvogel           visswa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version  Date        Author     Change Id       Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00  2004-10-21   HH/dH/Bir -               initial version
 *  1.01.00  2004-11-18   HH        -               rework of code inspection
 *  1.02.00  2005-07-20   HH        -               update to Autosar 1.0 spec
 *  2.00.00  2006-06-14   vishs     -               Update to Autosar 2.0 spec
 *  2.01.00  2006-06-16   vishs     -               ASR compliant header file structure
 *                        vishs     ESCAN00017204   added support for LIN_IF
 *                        vishs     ESCAN00017205   naming convention for internal names     
 *                        vishs     ESCAN00017289   code replication is not used     
 *                        vishs     ESCAN00018046   consistency check of GENy dll implementation version     
 *                        vishs     ESCAN00018049   added support for CAN_TP     
 *  2.02.00  2007-02-09   vishs     ESCAN00018027   configuration variant 3 (Post-Build) support
 *                        vishs     ESCAN00018918   Adapted multiple include protection according to impl. rules     
 *                        vishs     ESCAN00019488   Allow DCM I-PDU transmission over CAN_IF     
 *  2.03.00  2007-08-07   vishs     ESCAN00019585   Corrected assertion handing in PduR_DcmTransmit()
 *                        vishs     ESCAN00020247   Update to AUTOSAR 2.1 specification     
 *                        vishs     ESCAN00020699   Routing between DCM and FrTp and FrIf added     
 *                        vishs     ESCAN00021037   Removed magic number for link- and pre-compile configuration     
 *                        vishs     ESCAN00021608   Compiler error in systems with LinIf and Gw_PduR     
 *  2.04.00  2007-11-06   vishs     ESCAN00021825   Added interface routing for CanIf, LinIf and FrIf
 *                        vishs     ESCAN00022036   Removed non-selectable post-build configuration feature     
 *                        vishs     ESCAN00022639   Added TP layer routing for CanTp and FrTp     
 *                        vishs     ESCAN00023115   Added callout functions for IF layer routing (ASR RFC18729)
 *  2.04.01  2007-12-05   vishs     ESCAN00023555   Removed linker error within IF Gateway if used on CAN bus only
 *  2.05.00  2008-01-31   vishs     ESCAN00023614   Added J1939 support for COM
 *                        vishs     ESCAN00023615   Allow forwarding of PDUs between COM and CanTp     
 *                        vishs     ESCAN00023527   Update to AUTOSAR 2.2.1 specification (AUTOSAR Release 3.0)     
 *                                                   - Compiler and memory abstraction
 *                                                   - AR version check of used BSW modules (AUTOSAR 2.1 versions)
 *  3.00.00  2008-04-03   vishs     ESCAN00024199   TP layer gateway ring-buffer support added
 *                        vishs     ESCAN00024576   Fixed compiler warning
 *                        vishs     ESCAN00023527   AR version check of used BSW modules (AUTOSAR 3.0 versions)
 *                        vishs     ESCAN00024677   Corrected return value check of callout functions
 *                        vishs     ESCAN00024330   Renamed ComTpApi_* to Com_Tp*
 *                        vishs     ESCAN00024855   Removed compiler warning
 *                        vishs     ESCAN00025432   Support of DEM errors provided as defines
 *                        vishs     ESCAN00025460   Removed consistency chek for IF gateway configuration data
 *  3.01.00  2008-05-16   vishs     ESCAN00026211   Library consistency check
 *                        vishs     ESCAN00026291   Removed V_CRITICAL_SECTION_USE_VECTOR_COMMENT
 *                        vishs     ESCAN00026292   PduR_GetVersionInfo now exports instanceID
 *                        vishs     ESCAN00026645   Generator Version Check added
 *  3.02.00  2008-06-17   vishs     ESCAN00027250   Support for TMS320 memory model added (no changes required)
 *                        vishs     ESCAN00026645   TP Gateway Generator Version Check added
 *                        vishs     ESCAN00027223   Direct include of Vctr Informatik include files
 *  3.03.00  2008-07-14   vishs     ESCAN00027971   TP layer routing hangs in case of a buffer overflow
 *                        vishs     ESCAN00027975   Missing cast leads to generator tool compatiblity check failing
 *                        vishs     ESCAN00027978   Abort initialization after failed generator version check
 *                        vishs     ESCAN00028107   Removed compiler warning
 *                        vishs     ESCAN00027670   Allow deactivation of gateway features at pre-compile time
 *  3.04.00  2008-10-16   vishs     ESCAN00027223   Modified include structure of Vctr Informatik includes
 *                        vishs     ESCAN00029044   Loss of TP PDUs during TP layer routing
 *                        vishs     ESCAN00029134   Changed FRTP AR version compatibility check to correct version
 *                        vishs     ESCAN00029121   Corrected memory qualifiers for post-build modifiable types
 *                        vishs     ESCAN00029438   Remove unrequired call to DET in case of single frame TP routing
 *                        vishs     ESCAN00029545   Own MemCpy functions provided - activation trough user config file
 *                        vishs     ESCAN00029591   Optimized access to API forwarding routing tables
 *                        vishs     ESCAN00029773   Precompile- and link time configuration CRC check
 *                        vishs     ESCAN00029986   Application access to interface and TP layer services
 *                        vishs     ESCAN00030053   Added Dcm to FrIf API forwarding
 *  3.05.00  2008-11-13   vishs     ESCAN00031161   Wrong definition for Memmap section
 *                        vishs     ESCAN00031220   Internal TP I-PDU communication
 *  3.05.01  2009-01-08   vishs     ESCAN00032284   Changed pre-configuration
 *  3.06.00  2009-01-28   visehs    ESCAN00032637   Add IpduM Routing
 *           2009-03-27   visehs    ESCAN00033510   Compiler Warning: variable pQStart was declared but never referenced
 *           2009-03-27   visehs    ESCAN00033991   Only execute the main body of GwTp_RxIndication if this is the first call to RxIndication for the ongoing routing.
 *           2009-04-02   visehs    ESCAN00034346   Linker Error in PduR.c with PduR_Core functions
 *  3.06.01  2009-04-02   visehs    ESCAN00034423   Wrong praeprocessor directive in PduR.c for IpduM support in the Lin and Flexray API
 *           2009-04-02   visehs    ESCAN00034424   Wrong function call for IpduM TxConfirmation in the Flexray interface
 *           2009-04-02   visehs    ESCAN00034426   Typo in function calls IpduM TxConfirmation and RxConfiramtion in the Lin API
 *  3.06.02  2009-04-23   visehs    ESCAN00034709   Uninitialized struct in PduR_GwTp_RxIndication
 *  3.07.00  2009-04-09   visehs    ESCAN00035755   Add MostIf and MostTp Support
 *           2009-06-10   visehs    ESCAN00035777   Add Il_AsrIpduMIsBmwSub Support
 *           2009-06-10   visehs    ESCAN00035575   one preprocessor switch encapsulate all BAC21 features 
 *  3.08.00  2009-06-22   visms     ESCAN00035904   Support Multiple Configurations
 *  3.09.00  2009-06-29   visms     ESCAN00035624   Support LinTp
 *           2009-06-29   visehs    ESCAN00034705   Renamed J1939 as J1939Tp
 *           2009-07-09   vishs     ESCAN00033781   AUTOSAR 4.0 Style CanTp routing
 *           2009-07-16   vishs     ESCAN00034231   Remove Det Error PDUR_E_TP_BUFFER_SIZE_LIMIT
 *           2009-07-16   visms     ESCAN00034190   Pointless comparison of unsigned integer with zero in <MSN>_Init()
 *           2009-07-16   visms     ESCAN00036100   Library Preprocessor Checks
 *           2009-08-04   visms     ESCAN00036387   Intra ECU TP communication fails for Service ID 0x19
 *           2009-07-20   visehs    ESCAN00036552   Allow more than 255 routing relations for the GW use case to be configured
 *  3.09.01  2009-09-18   visms     ESCAN00037839   Support MOST Dynamic DLC Routing
 *                        visms     ESCAN00037840   Change MostTpDapHeaderType to kMostIfDapHdrLen
 *  3.09.02  2009-09-15   visehs    ESCAN00037986   PDU Routing to the wrong bus in case of LinTp in combination with FrTp
 *           2009-10-15   visehs    ESCAN00038015   Memory area could overwritten during VPB communication  
 *           2009-10-15   visehs    ESCAN00037887   Service IDs reported to DET are not matching the specification
 *  3.10.00  2009-09-09   visehs    ESCAN00037658   Support SoAdTp communication (IP Support)
 *  3.11.00  2009-09-26   visehs    ESCAN00038443   Tp messages will not be gated using the AUTOSAR 4.0 CanTp API if the Chunk Size and Buffer Size are equal
 *           2009-09-26   visehs    ESCAN00037849   Support CanNm2Com and FrNm2Com Interface
 *           2009-11-09   visms     ESCAN00037251   Support Dobt-CanTp Dispatcher
 *           2009-11-10   visms     ESCAN00038295   Compiler error: PDUR_LINTP2COM_ROUTING undefined
 *           2009-11-10   visms     ESCAN00038296   Compiler error: PDUR_DEACTIVATE_DEM_VERSION_CHECK undefined
 *           2009-11-11   visehs    ESCAN00039029   Service ID PDUR_FCT_DCMTX is reported to DET in PduR_ComTransmit
 *           2009-11-13   visms     ESCAN00038625   Support E_PENDING in as return of <Lo>Transmit
 *           2009-11-13   visehs    ESCAN00037889   Memory is overwritten with MOST
 *           2009-11-20   visehs    ESCAN00038553   Manage Remaining Chunks within the Buffer
 *  3.12.00  2010-02-02   visms     ESCAN00039221   Call CddDobt_PduRCanTpCallout only for Dobt capable CanTp Rx Pdus
 *           2010-02-19   visehs    ESCAN00040855   Tp messages will not be routed if the payload is smaller than the chunksize
 *           2010-02-25   visehs    ESCAN00041039   CanTp connections are failing to Dcm, Com and ApplTp 
 *           2010-03-01   visms     ESCAN00041272   MISRA-C:2004 Update
 *  3.13.00  2010-03-24   visehs    ESCAN00041796   Linker Error: unresolved external symbol Ipdum_TriggerTransmit
 *           2010-03-24   visehs    ESCAN00041799   Compiler Error:  'PduR_TpCnv_TxCom2LoInfo' : undeclared identifier 
 *           2010-03-24   visehs    ESCAN00040669   Compiler Warning:  'pCATx' :unused unreferenced local variable 
 *           2010-03-24   visehs    ESCAN00039668   Support Routing of 2 Consecutive CanTp Single Frames for CanTp 4.0 API
 *           2010-04-01   visehs    ESCAN00042017   Det Error occurs due to an unexpected API call
 *           2010-04-15   visehs    ESCAN00040305   Add Feature Tp Parameter Control
 *           2010-05-17   visehs    ESCAN00042972   Misra warning: Structure has fewer initializers than its declared size
 *           2010-05-17   visehs    ESCAN00042974   Null pointer assignment in function PduR_Core_CanTpProvideRxBuffer()
 *           2010-05-21   visehs    ESCAN00043076   Rename function parameter value name J1939Xxx to J1939TpXxx
 *  3.13.01  2010-06-21   visehs    ESCAN00043511   Det_ReportError is called with IpduM Module ID
 *           2010-06-21   visehs    ESCAN00043491   Add BAC30 IPDUM Compatibility Defines
 *  3.14.00  2010-06-25   visssa    ESCAN00043581   Support TP Receive Cancellation
 *           2010-07-20   visssa    ESCAN00043968   Support TP Transmit Cancellation
 *           2010-07-28   visms     ESCAN00044309   Multiple ECU: PduR_DcmChangeParameterRequest with inactive DcmRxPduId
 *           2010-07-30   visms     ESCAN00034188   Optimize ProvideBuffer, RxIndication and TxConfirmation calls in PduR_MainFunction
 *           2010-08-10   visehs    ESCAN00044523   Support Optimized Routing with FrTp
 *           2010-08-11   visehs    ESCAN00043995   Support PduRoutingPathGoups
 *           2010-08-11   visehs    ESCAN00041722   Compiler warning: unreachable code in PduR_CanTpProvideRxBuffer
 *  3.14.01  2010-08-21   visehs    ESCAN00045516   RoutingPath Groups cannot be disabled
 *           2010-08-21   visehs    ESCAN00045422   Linker Error: unresolved external symbol ApplIf_TxConfirmation
 *           2010-08-22   visehs    ESCAN00039232   Added a consistency check for the PduIdType
 *           2010-08-22   visehs    ESCAN00045553   Second FrTp consecutive frame to Dcm and ApplTp is blocked forever until watch dog reset
 *  3.14.02  2010-10-05   visehs    ESCAN00045786   ApplTp_TxConfirmation is not called
 *           2010-10-13   visehs    ESCAN00045795   RAM will be overwritten is no TP Buffers are configured
 *           2010-10-15   visms     ESCAN00045936   Notify Dem if the PduIdType Check fails
 *           2010-10-15   visms     ESCAN00045505   Routing of Functional Requests with Fan Out Stops
 *           2010-10-15   visms     ESCAN00045944   Physical Multiple ECU: ECU is blocked until Watch-Dog reset
 *           2010-10-15   visms     ESCAN00045891   PduR_<Up>CancelReceiveRequest does not work
 *           2010-10-21   visms     ESCAN00044894   Include and check PduR Headers only if the component is supported
 *           2010-10-21   visms     ESCAN00046298   Linker Error with PduR_GwTpTxConfirmation
 *  3.14.03  2010-10-21   visehs    ESCAN00046355   Compile error due to missing Define "PDUR_CANIF_SUPPORT"
 *  3.14.04  2010-10-27   visehs    ESCAN00046407   Compile error occurs if PDUR routing group support is enabled
 *  3.15.00  2010-10-19   visms     ESCAN00045920   Support Rx CanNm and FrNm
 *           2010-11-30   visms     ESCAN00046248   Perform AUTOSAR version check only for Vector
 *           2010-12-08   visms     ESCAN00040225   AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 *           2010-12-16   visehs    ESCAN00047004   Balance the Routing time of Physical TP Routings
 *           2010-12-08   visms     ESCAN00047232   Compiler warning PduR_Core_UpTpTxConfirmation declared but not used
 *           2010-12-16   visehs    ESCAN00045919   Optimize Wrap Around interaction with Lower Layer TPs and Physical TP Routings
 *           2011-01-17   visms     ESCAN00046408   Compiler Error: struct has no field "DestPduCntIndex"
 *           2011-02-22   visms     ESCAN00048509   Support CDD
 *           2011-02-22   visms     ESCAN00048088   Length of copied SDU data is not indicated in PduR_<Lo>TriggerTransmit() API
 *  3.15.01  2011-02-24   visehs    ESCAN00048899   Compiler warning occurs: zero used for undefined preprocessing identifier
 *           2011-02-24   visehs    ESCAN00048901   Compiler warning occurs:" PduR_GwIf_Init" was declared but never referenced
 *           2011-02-24   visehs    ESCAN00048903   Compiler warning: nested comment is not allowed
 *           2011-02-25   visms     ESCAN00048926   Unexpected ECU behavior on reception of a TP SDU
 *           2011-02-25   visms     ESCAN00048937   Compiler Warning: extern used with definition
 * 3.15.02   2011-03-15   visehs    ESCAN00049284   DET error occurs in function EnableRouting() and DisableRouting()
 * 3.15.03   2011-04-12   visehs    ESCAN00049366   DET error occurs in function PduR_GwIf_RxIndication()
 *           2011-04-12   visehs    ESCAN00049756   Add PDUR_SOURCE Define at the beginning of the PduR.c file
 *           2011-04-10   visehs    ESCAN00050229   Interface Layer routing with TriggerTransmit FiFo queued routing: Arbitrary value are transmitted
 *           2011-04-28   visehs    ESCAN00050402   PduR stops routing of a TP routing relation.
 *           2011-05-11   visehs    ESCAN00050818   Misra warning: possible truncation at implicit conversion to type "unsigned short"
 * 3.15.04   2011-05-17   visehs    ESCAN00050649   Some functional transport protocol requests (SF) are not routed to the upper Tp layer 
 * 3.15.05   2011-05-23   visehs    ESCAN00051055   Compiler Error occurs due to an inconsistent version number
 * 3.15.06   2011-05-30   visehs    ESCAN00051259   Rename SoAdTp to SoAd and adjust all APIs
 * 3.15.07   2011-07-28   visswa    ESCAN00052333   TP Routing buffer remains locked in case of a failed Tp transmission request
 *           2011-07-28   visswa    ESCAN00052434   TP Routing buffer remains locked after MostTp routing
 *********************************************************************************************************************/


#if !defined(PDUR_H)
# define PDUR_H

                                                        /* PRQA        S 3453 EOF *//* RULE 19.7: Function like macros are used to increase runtime efficiency and the readability of code. */
                                                        /* PRQA        S 3109 EOF *//* RULE 19.4: See justification of RULE 19.4. Due to this ";" cannot be set on a line by himself. */
                                                        /* PRQA        S 2006 EOF *//* RULE 14.7: Functions has more than 1 return path to improve the readability of code. */
                                                        /* PRQA        S 3684 EOF *//* RULE 18.12: The size of arrays varies dependent on the configuration at post-build time and the declared size is not relevant to access arrays. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Cfg.h"
# include "PduR_Types.h"
# include "PduR_Lcfg.h"
# include "PduR_PBcfg.h"


# if (PDUR_DEV_ERROR_DETECT == STD_ON)
#  include "Det.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if (PDUR_PROD_ERROR_DETECT == STD_ON)
#  if(PDUR_LIBRARY_SUPPORT == STD_ON)
#   define PDUR_PDUR_E_INIT_FAILED        PduR_DemError_InitFailed
#   define PDUR_PDUR_E_PDU_INSTANCE_LOST  PduR_DemError_InstanceLost
#  else
#   if defined (Dem_PDUR_E_INIT_FAILED)
#    define PDUR_E_INIT_FAILED            Dem_PDUR_E_INIT_FAILED
#   endif
#   if defined (Dem_PDUR_E_PDU_INSTANCE_LOST)
#    define PDUR_E_PDU_INSTANCE_LOST      Dem_PDUR_E_PDU_INSTANCE_LOST
#   endif
#   define PDUR_PDUR_E_INIT_FAILED        PDUR_E_INIT_FAILED
#   define PDUR_PDUR_E_PDU_INSTANCE_LOST  PDUR_E_PDU_INSTANCE_LOST
#  endif/* (PDUR_LIBRARY_SUPPORT == STD_ON) */
# endif/* (PDUR_PROD_ERROR_DETECT == STD_ON) */

/*********************************************************************************************************************/
/* Version                  (abcd: Main version ab Sub Version cd )                                                  */
/*********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Gw_AsrPduR CQComponent : Implementation */
# define GW_ASRPDUR_VERSION            (0x0315u)
# define GW_ASRPDUR_RELEASE_VERSION            (0x07u)

/* Implemented AUTOSAR Specification (SWS) Version */
# define PDUR_AR_VERSION           (0x0202u)
# define PDUR_AR_RELEASE_VERSION   (0x01u)

# define PDUR_AR_MAJOR_VERSION    ((PDUR_AR_VERSION >> 8) & 0x00FF)
# define PDUR_AR_MINOR_VERSION    (PDUR_AR_VERSION & 0x00FF)
# define PDUR_AR_PATCH_VERSION    (PDUR_AR_RELEASE_VERSION)
# define PDUR_SW_MAJOR_VERSION    ((GW_ASRPDUR_VERSION >> 8) & 0x00FF)
# define PDUR_SW_MINOR_VERSION    (GW_ASRPDUR_VERSION & 0x00FF)
# define PDUR_SW_PATCH_VERSION    (GW_ASRPDUR_RELEASE_VERSION)


/*********************************************************************************************************************/
/* Module Identificatiion                                                                                            */
/*********************************************************************************************************************/
# define PDUR_VENDOR_ID           (0x001Eu)
# define PDUR_MODULE_ID           (0x33u)

/*********************************************************************************************************************/
/* PDUR_CONFIG_VARIANT                                                                                               */
/*********************************************************************************************************************/
# define PDUR_CFGVAR_PRECOMPILETIME       1u
# define PDUR_CFGVAR_LINKTIME             2u
# define PDUR_CFGVAR_POSTBUILDTIME        3u

# define PDUR_BIT_TRUE    ((PduR_Core_BitType)0x01u)
# define PDUR_BIT_FALSE   ((PduR_Core_BitType)0x00u)

/** \defgroup DetErrorIDs DetError IDs
    \brief    Det Error IDs as reported to DET. */
/*\{*/

/** This error code is only used in conjunction with post-build configuration: An invalid post-build configuration data pointer has been handled to PduR_Init(). The error is either caused by a failed consistency check or because a null pointer was handled to PduR_Init(). */
# define PDUR_E_CONFIG_PTR_INVALID    ((uint8)0x00u)
/** An API service has been used without a call of PduR_Init() or PduR_Init() was called while the PDU Router is in any other state than PDUR_UNINIT. If your system does not use a start-up code to initialize global variables, PduR_InitMemory() can be called before PduR_Init() to avoid this problem. */
# define PDUR_E_INVALID_REQUEST       ((uint8)0x01u)
/** An invalid PDU identifier was used as parameter for a PDU Router API call. */
# define PDUR_E_PDU_ID_INVALID        ((uint8)0x02u)
/** TP Gateway was not able to transmit a TP Tx I-PDU due to an error reported by the TP layer. The gateway will abort the routing and not attempt a re-transmission. */
# define PDUR_E_TP_TX_REQ_REJECTED    ((uint8)0x03u)
/** The Data pointer (CanSduPtr, FrSduPtr, LinSduPtr or PduInfoPtr) is a NULL_PTR */
# define PDUR_E_DATA_PTR_INVALID      ((uint8)0x05u)
/** Length of requested TP buffer is larger than the maximum length of all configured TP buffer. The gateway will try to route the I-PDU using the ring-buffer mechanism. This can, however, result in a buffer overrun if the TP layer is not able to adapt the block size of the Rx connection. */
# define PDUR_E_TP_BUFFER_SIZE_LIMIT  ((uint8)0x06u)
/** The provided buffer of the upperlayer module is to small, should be minimum the size of the CanTp FF + minimum 1 byte. It is required by the CanTp */
# define PDUR_E_UL_BUFFER_UNDERRUN  ((uint8)0x07u)
/** If the routing table is invalid that is given to the PduR_EnableRouting or PduR_DisableRouting functions*/
# define PDUR_E_ROUTING_TABLE_ID_INVALID ((uint8)0x08)

/** An internal PDU Router error occurred that was eventually caused by incorrect or manipulated configuration data. */
# define PDUR_E_INVALID_CFG_DATA      ((uint8)0xA0u)
/** The indicated API was called although the current PDU Router configuration and internal state does not expect a call to this API. */
# define PDUR_E_UNEXPECTED_CALL       ((uint8)0xA1u)
/** The size of PduIdType is consistent */
# define PDUR_INCONSISTENT_SIZEOFPDUIDTYPE       ((uint8)0xA2u)
/*\}*/



/** \defgroup ServiceIDs Service IDs
    \brief    Service IDs as reported to DET. */
/*\{*/

/** Service ID PduR_Init */
# define PDUR_FCT_INIT                 ((uint8)0x00u)
/** Service ID PduR_FrIfRxIndication */
#  define PDUR_FCT_FRIFRXIND            ((uint8)0x07u)
/** Service ID PduR_FrIfTxConfirmation */
#  define PDUR_FCT_FRIFTXCFM            ((uint8)0x08u)
/** Service ID PduR_FrIfTriggerTransmit */
#  define PDUR_FCT_FRIFTRGTX            ((uint8)0x09u)
/** Service ID PduR_FrTpProvideRxBuffer */
#  define PDUR_FCT_FRTPPRORX            ((uint8)0x0Au)
/** Service ID PduR_FrTpRxIndication */
#  define PDUR_FCT_FRTPRXIND            ((uint8)0x0Bu)
/** Service ID PduR_FrTpProvideTxBuffer */
#  define PDUR_FCT_FRTPPROTX            ((uint8)0x0Cu)
/** Service ID PduR_FrTpTxConfirmation */
#  define PDUR_FCT_FRTPTXCFM            ((uint8)0x0Du)
/** Service ID PduR_FrTpChangeParameterConfirmation */
#  define PDUR_FCT_FRTPCPRC             ((uint8)0x24u)
/** Service ID PduR_DcmChangeParameterRequest */
#  define PDUR_FCT_DCMCPR              ((uint8)0x1du)
/** Service ID PduR_DcmReadParameterRequest */
#  define PDUR_FCT_DCMRPR              ((uint8)0x1eu)
/** Service ID PduR_DcmCancelReceiveRequest */
#  define PDUR_FCT_DCMCRR              ((uint8)0x95u)
/** Service ID PduR_DcmTpCancelReceiveRequest */
#  define PDUR_FCT_DCMCTR              ((uint8)0x98u)
/** Service ID PduR_GetVersionInfo */
# define PDUR_FCT_VERSIONINFO          ((uint8)0x17u)
/** Service ID PduR_GetConfigurationId */
# define PDUR_FCT_CONFIGURATIONID      ((uint8)0x18u)
/** Service ID PduR_IpduMTxConfirmation */
#  define PDUR_FCT_IPDUMTXCFM           ((uint8)0x1Au)
/** Service ID PduR_IpduMRxIndication */
#  define PDUR_FCT_IPDUMRXIND           ((uint8)0x1Bu)
/* Service API IFs added by Vctr Informatik */
/** Service ID internal function */
# define PDUR_FCT_CORE_MAINFUNC        ((uint8)0x29u)
# if(PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
/** Service ID PduR_EnableRouting */
#  define PDUR_FCT_ENABLEROUTING      ((uint8)0x98u)
/** Service ID PduR_DisableRouting */
#  define PDUR_FCT_DISABLEROUTING     ((uint8)0x99u)
# endif
/*\}*/


# if (PDUR_DEV_ERROR_DETECT == STD_ON)
#  define PduR_Det_ReportError(ApiId, ErrorCode) Det_ReportError(PDUR_MODULE_ID, 0, (ApiId), (ErrorCode))
#  define PduR_Det_Assert(Condition, ApiId, ErrorCode) \
                                   if ((Condition) == FALSE) \
                                   {\
                                     Det_ReportError(PDUR_MODULE_ID, 0, (ApiId), (ErrorCode));\
                                   }
#  define PduR_Det_AssertAlways(ApiId, ErrorCode) Det_ReportError(PDUR_MODULE_ID, 0, (ApiId), (ErrorCode))

#  define PduR_Det_AssertReturnFunc(Condition, ApiId, ErrorCode) \
                                   if ((Condition) == FALSE) \
                                   {\
                                     Det_ReportError(PDUR_MODULE_ID, 0, (ApiId), (ErrorCode));\
                                     return;\
                                   }
#  define PduR_Det_AssertReturnFuncValue(Condition, ApiId, ErrorCode, FalseRetVal) \
                                   if ((Condition) == FALSE) \
                                   {\
                                     Det_ReportError(PDUR_MODULE_ID, 0, (ApiId), (ErrorCode));\
                                     return (FalseRetVal);\
                                   }
#  define PduR_Core_GetState()      (pdur_Core_State)
# else
#  define PduR_Det_ReportError(ApiId, ErrorCode)
#  define PduR_Det_Assert(Condition, ApiId, ErrorCode)
#  define PduR_Det_AssertAlways(ApiId, ErrorCode)
#  define PduR_Det_AssertReturnFunc(Condition, ApiId, ErrorCode)
#  define PduR_Det_AssertReturnFuncValue(Condition, ApiId, ErrorCode, FalseRetVal)
#  define PduR_Core_GetState()
# endif/* (PDUR_DEV_ERROR_DETECT == STD_ON) */

/*********************************************************************************************************************/
/* Consistency Checks and Compatibility                                                                              */
/*********************************************************************************************************************/
# if defined(V_EXTENDED_BUILD_LIB_CHECK)
#  if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_PRECOMPILETIME)
#   error "The PDUR_CONFIG_VARIANT is set to PDUR_CFGVAR_PRECOMPILETIME and V_EXTENDED_BUILD_LIB_CHECK is defined. Change the Configuration Variant for a Library!"
#  endif
# endif

# define Com_TpProvideTxBuffer Com_ProvideTxBuffer
# define Com_TpProvideRxBuffer Com_ProvideRxBuffer

/*********************************************************************************************************************/
/* User Configuration File Configurable Features (can be modified using the user configuration file)                 */
/*********************************************************************************************************************/
/* Usage of VStdLib to copy data (STD_ON) or macro based routines (STD_OFF) */
# if !defined(PDUR_VSTDLIB_MEM_API)
#  define PDUR_VSTDLIB_MEM_API      STD_ON
# endif


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*================================================PDUR_START_SEC_PBCFG===============================================*/
# define PDUR_START_SEC_PBCFG
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


/*********************************************************************************************************************/
/* PduR Configuration Data                                                                                           */
/*********************************************************************************************************************/
# define PDUR_STOP_SEC_PBCFG
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*==============================================PDUR_STOP_SEC_PBCFG==================================================*/



/*=============================================PDUR_START_SEC_CONST_8BIT=============================================*/
# define PDUR_START_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


# define PDUR_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CONST_8BIT================================================*/



/*=========================================PDUR_START_SEC_CONST_UNSPECIFIED==========================================*/
# define PDUR_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


# if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
/**********************************************************************************************************************
  pdur_NumberOfRoutingGroupDestPdus
**********************************************************************************************************************/
/** \brief    This const variable provides the Array size for the pdur_DestPduStateCnt[]initialization
    \size     Number of PduRRoutingPathDestinations mapped to a PduRRoutingPathGroup
**********************************************************************************************************************/
extern CONST(uint16, PDUR_CONST) pdur_NumberOfRoutingGroupDestPdus;
# endif



# define PDUR_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*========================================PDUR_STOP_SEC_CONST_UNSPECIFIED============================================*/


/*============================================PDUR_START_SEC_CONST_32BIT================================================*/
# define PDUR_START_SEC_CONST_32BIT
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

# if(PDUR_CRC_CHECK == STD_ON )
extern CONST(uint32, PDUR_CONST) PduR_LinktimeCRC;
# endif

# define PDUR_STOP_SEC_CONST_32BIT
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CONST_32BIT=================================================*/

/*============================PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/
# define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

# if (PDUR_SELECTABLE_INIT_POINTER == STD_ON)
extern P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) pdur_Core_PBConfigPtr;
# endif

# define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*=============================PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/

/*============================PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/
# define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

# if(PDUR_DEV_ERROR_DETECT == STD_ON)
extern VAR(PduR_Core_StateType, PDUR_VAR_ZERO_INIT) pdur_Core_State;
# endif

# define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*=============================PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/

/*============================PDUR_START_SEC_VAR_NOINIT_BOOLEAN======================================================*/
# define PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


/*============================PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN======================================================*/
# define PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


/*====================================PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED==========================================*/
# define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

# if(PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
/**********************************************************************************************************************
  pdur_DestPduStateCnt
**********************************************************************************************************************/
/** \brief    Provides runtime information for the enabled state of a PduRRoutingPathDestination.
    \size     Maximum Number of PduRRoutingPathDestinations mapped to an PduRRoutingPathGroup.
**********************************************************************************************************************/
extern VAR(PduR_RoutingPathGroupIdType, PDUR_VAR_NOINIT) pdur_DestPduStateCnt[];

/**********************************************************************************************************************
  pdur_RoutingPathGroupState
**********************************************************************************************************************/
/** \brief    Provides runtime information for the enabled state of a PduRRoutingPathGroup.
    \size     Maximum Number of PduRRoutingPathGroups.
**********************************************************************************************************************/
extern VAR(boolean, PDUR_VAR_NOINIT) pdur_RoutingPathGroupState[];
# endif


# define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*====================================PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED===========================================*/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# if(PDUR_CONFIG_VARIANT != PDUR_CFGVAR_POSTBUILDTIME)
#  define PduR_GetConfigurationId() ((uint32)0)
# endif


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*===========================================PDUR_START_SEC_CODE=====================================================*/
# define PDUR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

/*********************************************************************************************************************/
/* PduR Initialization                                                                                               */
/*********************************************************************************************************************/

/**********************************************************************************************************************
  PduR_Init
**********************************************************************************************************************/
/** \brief    This function initializes the PDUR and performs configuration consistency checks.
              If the initialization is performed sucessfully the PduR is in the state PDUR_ONLINE else PDUR_UNINIT.
    \param    ConfigPtr  Pointer to the PDUR configuration data, if PDUR_SELECTABLE_INIT_POINTER is defined to STD_ON.
    \return   none
    \pre      PduR_InitMemory() has been executed, if the startup code does not initialise variables.\n
              and the PduR is in the state PDUR_UNINIT\n
              and the size of PduIdType defined in ComStack_Types.h does not differ from
              the GENy preconfiguration.
    \context  The function must be called on task level and has not to be interrupted
              by other administrative function calls.
    \note     The function is used by the Ecu State Manager. 
    \warning  PduR_Init shall not pre-empt any PDUR function.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_PBCFG) ConfigPtr);

/**********************************************************************************************************************
  PduR_InitMemory
**********************************************************************************************************************/
/** \brief    The function initialises variables, which cannot be initialised with the startup code.
    \return   none
    \pre      PduR_Init() is not called yet.
    \context  The function must be called on task level.
    \note     The function is called by the Application.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_InitMemory(void);

/*********************************************************************************************************************/
/* General PduR API                                                                                                  */
/*********************************************************************************************************************/

# if(PDUR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  PduR_GetVersionInfo
**********************************************************************************************************************/
/** \brief    Returns the version information of the PDUR.
    \param    versioninfo Pointer to where to store the version information of the PDUR.
    \return   none
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the Application.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versioninfo);
# endif

# if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
/**********************************************************************************************************************
  PduR_GetConfigurationId
**********************************************************************************************************************/
/** \brief    Provides the unique identifier of the PDUR configuration.
    \return   uint32
    \pre      PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the Application.
**********************************************************************************************************************/
FUNC(uint32, PDUR_CODE) PduR_GetConfigurationId(void);
# endif


# if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
/**********************************************************************************************************************
PduR_EnableRouting
**********************************************************************************************************************/
/** \brief    This function enables a routing path group. If the routing path group does not exist or
              is already enabled, the function returns with no action.
    \param    id    Identification of the routing path group.
                    Routing path groups are defined in the PDU router configuration.
    \return   none
    \pre      PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.
    \context  The function can be called on interrupt and task level and has not to be interrupted by other
              PduR_EnableRouting or PduR_DisableRouting calls for the same id.
    \note     The function is called by the BSW Mode Manager.
              The routing of a destination PDU of a PduRRoutingPath which is contained in multiple
              PduRRoutingPathGroups start if one related PduRRoutingPathGroups is started.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);

/**********************************************************************************************************************
PduR_DisableRouting
**********************************************************************************************************************/
/** \brief    This function disables a routing path group. If the routing path group does not exist or
              is already disbled, the function returns with no action.
    \param    id    Identification of the routing path group.
                    Routing path groups are defined in the PDU router configuration.
    \return   none
    \pre      PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.
    \context  The function can be called on interrupt and task level and has not to be interrupted by other
              PduR_EnableRouting or PduR_DisableRouting calls for the same id.
    \note     The function is called by the BSW Mode Manager.
              The routing of a destination PDU of a PduRRoutingPath which is contained in multiple
              PduRRoutingPathGroups stops if all related PduRRoutingPathGroups are stopped.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id);
# endif

/**********************************************************************************************************************
PduR_DcmTxConfirmation
**********************************************************************************************************************/
/** \brief         This function is a wrapper for the UUDT communication of Dcm.
                   The communication interface confirmation will be forwarded to the TP confirmation function.
    \param[in]     DcmTxPduId        Handle ID of the transmitted Dcm I-PDU.
    \return        none
    \pre           PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.
    \context       The function can be called on interrupt and task level and has not to be interrupted by other
                   PduR_DcmTxConfirmation calls for the same MSNRxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
#  if(PDUR_DCM_SUPPORT == STD_ON)
FUNC(void, PDUR_CODE) PduR_DcmTxConfirmation(PduIdType DcmTxPduId);
#  endif
       /* defined(GW_ASRPDUR_ENABLE_FEATURE_DCM_COMMENT) */

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CODE=====================================================*/

#endif /* !defined(PDUR_H) */

/* STOPSINGLE_OF_MULTIPLE */
