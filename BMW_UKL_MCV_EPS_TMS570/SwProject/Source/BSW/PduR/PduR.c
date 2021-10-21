/* Kernbauer Version: 1.16 Konfiguration: Gw_AsrPduR Erzeugungsgangnummer: 947 */

/* STARTSINGLE_OF_MULTIPLE */

/* KB begin PduR_Prolog */
/* KB end PduR_Prolog */
/* KB begin PduR_Header */
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
 *         File:  PduR.c
 *      Project:  Gw_AsrPduR
 *       Module:  MICROSAR PDU Router
 *    Generator:  GENy
 *
 *  Description:  Implements AUTOSAR PDU Router SWS Version: 2.2.1
 *  
 *********************************************************************************************************************/
/* KB end PduR_Header */
/* KB begin PduR_History */
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

/* KB end PduR_History */

                                                        /* PRQA        S 3109 EOF *//* RULE 19.4: See justification of RULE 19.4. Due to this ";" cannot be set on a line by himself. */
                                                        /* PRQA        S 3453 EOF *//* RULE 19.7: Function like macros are used to increase runtime efficiency and the readability of code. */
                                                        /* PRQA        S 2006 EOF *//* RULE 14.7: Functions has more than 1 return path to improve the readability of code. */
#define PDUR_SOURCE
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "PduR.h"

/* KB begin PduR_ImplementationVersionDefine */
#define GW_ASRPDUR_REQ_VERSION            (0x0315u)
/* KB end PduR_ImplementationVersionDefine */
/* KB begin PduR_ImplementationReleaseVersionDefine */
#define GW_ASRPDUR_REQ_RELEASE_VERSION            (0x07u)
/* KB end PduR_ImplementationReleaseVersionDefine */
#define GW_ASRPDUR_REQ_DLL_IMPLEMENT      (0x13u)

/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_OwnModuleInclude */
/* KB end PduR_OwnModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/*---------------------------------------- FRIF import -------------------------------------------------------------*/
# if(PDUR_FRIF_SUPPORT == STD_ON)
#  include "PduR_FrIf.h"
#  include "FrIf.h"
# endif
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/*---------------------------------------- IPDUM import -------------------------------------------------------------*/
# if(PDUR_IPDUM_SUPPORT == STD_ON)
#  include "PduR_IPduM.h"
#  include "IpduM.h"
# endif
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleIncludeHeader */
/* KB end PduR_LoUpModuleIncludeHeader */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/*---------------------------------------- FRTP import -------------------------------------------------------------*/
# if(PDUR_FRTP_SUPPORT == STD_ON)
#  include "PduR_FrTp.h"
#  include "FrTp.h"
# endif
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/*---------------------------------------- DCM import -------------------------------------------------------------*/
# if(PDUR_DCM_SUPPORT == STD_ON)
#  include "PduR_Dcm.h"
#  include "Dcm_Cbk.h"
# endif
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_OwnModuleInclude */
/* KB end PduR_OwnModuleInclude */
/* KB begin PduR_OwnModuleInclude */
/* KB end PduR_OwnModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */
/* KB begin PduR_LoUpModuleInclude */
/* KB end PduR_LoUpModuleInclude */

/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/*---------------------------------------- FRIF import -------------------------------------------------------------*/
# if(PDUR_FRIF_SUPPORT == STD_ON)
#  if(   (GW_ASRPDUR_FRIF_VERSION         != GW_ASRPDUR_REQ_VERSION) \
      || (GW_ASRPDUR_FRIF_RELEASE_VERSION != GW_ASRPDUR_REQ_RELEASE_VERSION))
#   error "PduR.c: PDU Router source and header files are inconsistent. See PduR header for module FRIF."
#  endif
# endif
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/*---------------------------------------- IPDUM import -------------------------------------------------------------*/
# if(PDUR_IPDUM_SUPPORT == STD_ON)
#  if(   (GW_ASRPDUR_IPDUM_VERSION         != GW_ASRPDUR_REQ_VERSION) \
      || (GW_ASRPDUR_IPDUM_RELEASE_VERSION != GW_ASRPDUR_REQ_RELEASE_VERSION))
#   error "PduR.c: PDU Router source and header files are inconsistent. See PduR header for module IPDUM."
#  endif
# endif
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/*---------------------------------------- FRTP import -------------------------------------------------------------*/
# if(PDUR_FRTP_SUPPORT == STD_ON)
#  if(   (GW_ASRPDUR_FRTP_VERSION         != GW_ASRPDUR_REQ_VERSION) \
      || (GW_ASRPDUR_FRTP_RELEASE_VERSION != GW_ASRPDUR_REQ_RELEASE_VERSION))
#   error "PduR.c: PDU Router source and header files are inconsistent. See PduR header for module FRTP."
#  endif
# endif
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/*---------------------------------------- DCM import -------------------------------------------------------------*/
# if(PDUR_DCM_SUPPORT == STD_ON)
#  if(   (GW_ASRPDUR_DCM_VERSION         != GW_ASRPDUR_REQ_VERSION) \
      || (GW_ASRPDUR_DCM_RELEASE_VERSION != GW_ASRPDUR_REQ_RELEASE_VERSION))
#   error "PduR.c: PDU Router source and header files are inconsistent. See PduR header for module DCM."
#  endif
# endif
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */
/* KB begin PduR_LoUpModuleIncludeConsistency */
/* KB end PduR_LoUpModuleIncludeConsistency */

#if(PDUR_PROD_ERROR_DETECT == STD_ON)
# include "Dem.h"
#endif
#if((PDUR_GATEWAY_OPERATION == STD_ON) || (PDUR_VPB_SUPPORT == STD_ON))
#  include "SchM_PduR.h"
#endif
#if (!defined(V_SUPPRESS_EXTENDED_VERSION_CHECK))
# include "v_ver.h"
#endif
#if((!defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)) || (PDUR_CRC_CHECK == STD_ON))
# include "EcuM_Cbk.h"
#endif

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if(GW_ASRPDUR_VERSION != GW_ASRPDUR_REQ_VERSION)
# error "PduR.c: PduR Source and Header files are inconsistent!"
#endif
#if(GW_ASRPDUR_RELEASE_VERSION != GW_ASRPDUR_REQ_RELEASE_VERSION)
# error "PduR.c: PduR Source and Header files are inconsistent!"
#endif
#if(GW_ASRPDUR_DLL_IMPLEMENTATION != GW_ASRPDUR_REQ_DLL_IMPLEMENT)
# error "PduR.c: The GENy DLL Version is not compatible to the Embedded Sources"
#endif

/* KB begin PduR_ArVersionCheck */
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck */
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck */
# if(PDUR_FRIF_SUPPORT == STD_ON)
#  if defined (FRIF_VENDOR_ID)
#   if (FRIF_VENDOR_ID == PDUR_VENDOR_ID)
#    if defined(FRIF_AR_MAJOR_VERSION) && defined(FRIF_AR_MINOR_VERSION)
#     if((FRIF_AR_MAJOR_VERSION != 0x03u) || (FRIF_AR_MINOR_VERSION != 0x00u))
#      error "Imported module has incompatible AR version - expected FRIF version is 0x03u.0x00u \
                                                      (FRIF_AR_MAJOR_VERSION.FRIF_AR_MINOR_VERSION)."
#     endif
#    endif
#   endif
#  endif
# endif
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck3 */
# if(PDUR_IPDUM_SUPPORT == STD_ON)
#  if defined (IPDUM_VENDOR_ID)
#   if (IPDUM_VENDOR_ID == PDUR_VENDOR_ID)
#    if defined(IPDUM_AR_MAJOR_VERSION) && defined(IPDUM_AR_MINOR_VERSION)
#     if((IPDUM_AR_MAJOR_VERSION != 0x01u) || (IPDUM_AR_MINOR_VERSION != 0x02u))
#      error "Imported module has incompatible AR version - expected IPDUM version is 0x01u.0x02u \
                                                      (IPDUM_AR_MAJOR_VERSION.IPDUM_AR_MINOR_VERSION)."
#     endif
#    endif
#   endif
#  endif
# endif
/* KB end PduR_ArVersionCheck3 */
/* KB begin PduR_ArVersionCheck */
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck */
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck */
/* KB end PduR_ArVersionCheck */
/* KB begin PduR_ArVersionCheck */
# if(PDUR_FRTP_SUPPORT == STD_ON)
#  if defined (FRTP_VENDOR_ID)
#   if (FRTP_VENDOR_ID == PDUR_VENDOR_ID)
#    if defined(FRTP_AR_MAJOR_VERSION) && defined(FRTP_AR_MINOR_VERSION)
#     if((FRTP_AR_MAJOR_VERSION != 0x02u) || (FRTP_AR_MINOR_VERSION != 0x02u))
#      error "Imported module has incompatible AR version - expected FRTP version is 0x02u.0x02u \
                                                      (FRTP_AR_MAJOR_VERSION.FRTP_AR_MINOR_VERSION)."
#     endif
#    endif
#   endif
#  endif
# endif
/* KB end PduR_ArVersionCheck */

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
/* KB begin PduR_ArVersionCheck2 */
# if defined (DET_VENDOR_ID)
#  if (DET_VENDOR_ID == PDUR_VENDOR_ID)
#   if defined(DET_AR_MAJOR_VERSION) && defined(DET_AR_MINOR_VERSION)
#    if((DET_AR_MAJOR_VERSION != 0x02u) || (DET_AR_MINOR_VERSION != 0x02u))
#     error "Imported module has incompatible AR version - expected DET version is 0x02u.0x02u \
                                                      (DET_AR_MAJOR_VERSION.DET_AR_MINOR_VERSION)."
#    endif
#   endif
#  endif
# endif
/* KB end PduR_ArVersionCheck2 */
#endif

#if(PDUR_PROD_ERROR_DETECT == STD_ON)
/* KB begin PduR_ArVersionCheck2 */
# if defined (DEM_VENDOR_ID)
#  if (DEM_VENDOR_ID == PDUR_VENDOR_ID)
#   if defined(DEM_AR_MAJOR_VERSION) && defined(DEM_AR_MINOR_VERSION)
#    if((DEM_AR_MAJOR_VERSION != 0x02u) || (DEM_AR_MINOR_VERSION != 0x02u))
#     error "Imported module has incompatible AR version - expected DEM version is 0x02u.0x02u \
                                                      (DEM_AR_MAJOR_VERSION.DEM_AR_MINOR_VERSION)."
#    endif
#   endif
#  endif
# endif
/* KB end PduR_ArVersionCheck2 */
#endif

#if((PDUR_GATEWAY_OPERATION == STD_ON) || (PDUR_VPB_SUPPORT == STD_ON))
/* KB begin PduR_ArVersionCheck2 */
#  if defined (SCHM_VENDOR_ID)
#   if (SCHM_VENDOR_ID == PDUR_VENDOR_ID)
#    if defined(SCHM_AR_MAJOR_VERSION) && defined(SCHM_AR_MINOR_VERSION)
#     if((SCHM_AR_MAJOR_VERSION != 0x01u) || (SCHM_AR_MINOR_VERSION != 0x01u))
#      error "Imported module has incompatible AR version - expected SCHM version is 0x01u.0x01u \
                                                      (SCHM_AR_MAJOR_VERSION.SCHM_AR_MINOR_VERSION)."
#     endif
#    endif
#   endif
#  endif
/* KB end PduR_ArVersionCheck2 */
#endif

/*********************************************************************************************************************/
/* Consistency Checks and Compatibility                                                                              */
/*********************************************************************************************************************/
# if(PDUR_DCM_SUPPORT == STD_ON)
#  if !defined(DCM_PDUR_PERIODIC_TX_TYPE2_ENABLED)
#   define DCM_PDUR_PERIODIC_TX_TYPE2_ENABLED     STD_OFF
#  endif
# endif

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
#if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
# define PDUR_MAGICNUMBER_FINAL            ((uint16)0xcafeu)
#endif /* (PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME) */
#define PDUR_GWIF_NOINITVALUE             ((uint16)0xFFFFu)

#if (PDUR_PROD_ERROR_DETECT == STD_ON)
# if(PDUR_LIBRARY_SUPPORT == STD_ON)
#  define PDUR_PDUR_E_INIT_FAILED        PduR_DemError_InitFailed
#  define PDUR_PDUR_E_PDU_INSTANCE_LOST  PduR_DemError_InstanceLost
# else
#  if defined (Dem_PDUR_E_INIT_FAILED)
#   define PDUR_E_INIT_FAILED            Dem_PDUR_E_INIT_FAILED
#  endif
#  if defined (Dem_PDUR_E_PDU_INSTANCE_LOST)
#   define PDUR_E_PDU_INSTANCE_LOST      Dem_PDUR_E_PDU_INSTANCE_LOST
#  endif
#  define PDUR_PDUR_E_INIT_FAILED        PDUR_E_INIT_FAILED
#  define PDUR_PDUR_E_PDU_INSTANCE_LOST  PDUR_E_PDU_INSTANCE_LOST
# endif /* (PDUR_LIBRARY_SUPPORT == STD_ON) */
#endif /* (PDUR_PROD_ERROR_DETECT == STD_ON) */

#if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
# define PduR_GetNumberOfRoutingGroupDestPdusCnt() (pdur_NumberOfRoutingGroupDestPdus)
#endif

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
# define PduR_Core_SetState(state) (pdur_Core_State = (state))
#else
# define PduR_Core_SetState(state)
#endif /* (PDUR_DEV_ERROR_DETECT == STD_ON) */

#if (PDUR_PROD_ERROR_DETECT == STD_ON)
# define PduR_Dem_ReportErrorStatus(EventId, EventStatus)         (void)Dem_ReportErrorStatus((EventId), (EventStatus))
#else
# define PduR_Dem_ReportErrorStatus(EventId, EventStatus)
#endif /* (PDUR_PROD_ERROR_DETECT == STD_ON) */

#if(PDUR_VSTDLIB_MEM_API == STD_ON)
# define PduR_Core_MemCpyRamToRam(d, s, l)    (VStdMemCpyRamToRam((d), (s), (l)))
# define PduR_Core_MemCpyRomToRam(d, s, l)    (VStdMemCpyRomToRam((d), (s), (l)))
# define PduR_Core_MemClr(d, l)               (VStdMemClr((d), (l)))
# define PduR_Core_MemSet(d, v, l)            (VStdMemSet((d), (v), (uint16)(l)))
#else
# define PduR_Core_MemCpy(pDest, pSrc, length)\
                            {\
                              uint16_least cnt = (uint16_least)(length);\
                              while(cnt > (uint16_least)0x00)\
                              {\
                                cnt--;\
                                (pDest)[cnt] = (pSrc)[cnt];\
                              }\
                            }
# define PduR_Core_MemSet(pDest, value, length)\
                            {\
                              uint16_least cnt = (uint16_least)(length);\
                              while(cnt > (uint16_least)0x00)\
                              {\
                                cnt--;\
                                (pDest)[cnt] = (uint8)(value);\
                              }\
                            }
# define PduR_Core_MemCpyRamToRam(d, s, l)      PduR_Core_MemCpy((d), (s), (l))
# define PduR_Core_MemCpyRomToRam(d, s, l)      PduR_Core_MemCpy((d), (s), (l))
# define PduR_Core_MemClr(d, l)                 PduR_Core_MemSet((d), 0x00, (l))
#endif /* (PDUR_VSTDLIB_MEM_API == STD_ON) */
# define PduR_Core_EnterCriticalArea() SchM_Enter_PduR(PDUR_EXCLUSIVE_AREA_0)
# define PduR_Core_LeaveCriticalArea() SchM_Exit_PduR(PDUR_EXCLUSIVE_AREA_0)


/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/*===========================================PDUR_START_SEC_CODE=====================================================*/
#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

#if (PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
/**********************************************************************************************************************
  PduR_Core_CheckPbDataConsistency
**********************************************************************************************************************/
/** \brief    The function is verifies the configuration data.
    \return   boolean
              TRUE          The Configuration is valid.
              FALSE         The Configuration is invalid.
    \note     The function is called by the PduR.
**********************************************************************************************************************/
STATIC FUNC(boolean, PDUR_CODE) PduR_Core_CheckPbDataConsistency(void);
#endif





#if((PDUR_CANTPCHANGEPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPCHANGEPARAMETER_SUPPORT == STD_ON) || (PDUR_CANTPREADPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPREADPARAMETER_SUPPORT == STD_ON) || (PDUR_DCMRECEIVECANCELLATION_SUPPORT == STD_ON) || (PDUR_APPLTPRECEIVECANCELLATION_SUPPORT == STD_ON))
/**********************************************************************************************************************
  PduR_Core_GetLoTpHandleFromUpTpHandle
**********************************************************************************************************************/
/** \brief    This function will be called to find the RX lower TP module handle ID of a
              RX upper TP module handle ID of a defined port.
    \param    pDIStart          Reference to a specific Routing Table.
    \param    pDICnt            Number of elements in pDI.
    \param    UpRxPduId         RX IPDU handle ID of the upper TP module.
    \param    UpRxPduIdPort     Port of the UpRxPduId.
    \param    LoRxPduId         RX IPDU handle ID of the lower TP module.
    \return   boolean
              TRUE
              FALSE
    \pre      PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the PduR.
**********************************************************************************************************************/
STATIC FUNC(boolean, PDUR_CODE) PduR_Core_GetLoTpHandleFromUpTpHandle(PduR_Core_DestITypePtr pDIStart, PduIdType pDICnt,
                                                                      PduIdType UpRxPduIdPort, PduIdType UpRxPduId,
                                                                      P2VAR(PduIdType, AUTOMATIC,
                                                                            PDUR_APPL_DATA) LoRxPduId);
#endif

# define PduR_Core_CanTpProvideRxBuffer    PduR_CanTpProvideRxBuffer
# define PDURDOBTSTATIC

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CODE=====================================================*/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/*============================PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/
#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

#if (PDUR_SELECTABLE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) pdur_Core_PBConfigPtr = NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*=============================PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/

/*============================PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/
#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

#if(PDUR_DEV_ERROR_DETECT == STD_ON)
VAR(PduR_Core_StateType, PDUR_VAR_ZERO_INIT) pdur_Core_State = PDUR_UNINIT;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*=============================PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED===============================================*/

/*============================PDUR_START_SEC_VAR_NOINIT_BOOLEAN======================================================*/
#define PDUR_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */


/*============================PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN======================================================*/
#define PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

/*====================================PDUR_START_SEC_CONST_UNSPECIFIED===============================================*/
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

#if((PDUR_PROD_ERROR_DETECT == STD_ON) && (PDUR_LIBRARY_SUPPORT == STD_ON))
/**********************************************************************************************************************
| NAME:             PduR_DemError...
| DESCRIPTION:      Link time error codes of DEM
**********************************************************************************************************************/
extern CONST(Dem_EventIdType, PDUR_CONST) PduR_DemError_InitFailed;
extern CONST(Dem_EventIdType, PDUR_CONST) PduR_DemError_InstanceLost;
#endif /* ((PDUR_PROD_ERROR_DETECT == STD_ON) && (PDUR_LIBRARY_SUPPORT == STD_ON)) */

#if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
# if(PDUR_LIBRARY_SUPPORT == STD_ON)
CONST(uint32, PDUR_CONST) GW_ASRPDUR_LIB_SYMBOL = GW_ASRPDUR_LIB_VERSION;
# endif
#endif

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*=====================================PDUR_STOP_SEC_CONST_UNSPECIFIED===============================================*/



/*===========================================PDUR_START_SEC_CODE=====================================================*/
#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

/**********************************************************************************************************************
  GLOBAL AND LOCAL FUNCTIONS
**********************************************************************************************************************/

#if(PDUR_VERSION_INFO_API == STD_ON)
FUNC(void, PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versioninfo)
{
  PduR_Det_AssertReturnFunc(NULL_PTR != versioninfo, PDUR_FCT_VERSIONINFO, PDUR_E_DATA_PTR_INVALID);

  versioninfo->vendorID = (uint16) PDUR_VENDOR_ID;
  versioninfo->moduleID = (uint8) PDUR_MODULE_ID;
  versioninfo->instanceID = (uint8) 0x00u;
  versioninfo->sw_major_version = (uint8) PDUR_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = (uint8) PDUR_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = (uint8) PDUR_SW_PATCH_VERSION;

}                               /* End of PduR_GetVersionInfo() */
#endif


#if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
FUNC(uint32, PDUR_CODE) PduR_GetConfigurationId(void)
{
  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_CONFIGURATIONID, PDUR_E_INVALID_REQUEST,
                                 0);
  return PduR_GetCfgElement(PbConfigId);

}                               /* End of PduR_GetConfigurationId() */
#endif

/**********************************************************************************************************************
  PduR Initialization
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_PBCFG) ConfigPtr)
{
  /* ConfVariant 1, 2 do not use the ConfigPtr. This might lead to a compiler warning which can be ignored. */
  PduR_Det_AssertReturnFunc((PduR_Core_GetState() == PDUR_UNINIT), PDUR_FCT_INIT, PDUR_E_INVALID_REQUEST);

#if(PDUR_SELECTABLE_INIT_POINTER == STD_ON)
  pdur_Core_PBConfigPtr = ConfigPtr;
#else
# if (PDUR_USE_DUMMY_STATEMENT == STD_ON)
  ConfigPtr = ConfigPtr;
# endif
#endif

#if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
  /* The check tests if major and minor version of generator and library are valid */
  if (((PduR_GetCfgElement(GeneratorVersion) & (uint32) 0x00FFFF00u) !=
       (((uint32) GW_ASRPDUR_GENTOOL_GENY_MAJOR_VERSION << 16u) |
        ((uint32) GW_ASRPDUR_GENTOOL_GENY_MINOR_VERSION << 8u)))
# if defined ( GW_ASRPDUR_GENTOOL_GENY_PATCH_VERSION )
#  if ( GW_ASRPDUR_GENTOOL_GENY_PATCH_VERSION != 0)
      || ((PduR_GetCfgElement(GeneratorVersion) & (uint32) 0x000000FFu) <
          (uint32) GW_ASRPDUR_GENTOOL_GENY_PATCH_VERSION)
#  endif
# endif
    )
  {
    EcuM_GeneratorCompatibilityError((uint16) PDUR_MODULE_ID, (uint8) 0u);
    /* Abort initialization as generator is not compatible */
    return;
  }
#endif
#if(PDUR_CRC_CHECK == STD_ON)
  if (PduR_GetCfgElement(PrecompileCRC) != PDUR_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) PDUR_MODULE_ID, (uint8) 0u);
    /* Abort initialization as current configuration is not compatible with the pre-compile configuration */
    return;
  }
  if (PduR_GetCfgElement(LinktimeCRC) != PduR_LinktimeCRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) PDUR_MODULE_ID, (uint8) 0u);
    /* Abort initialization as current configuration is not compatible with the link-time configuration */
    return;
  }
#endif


#if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
  if (FALSE == PduR_Core_CheckPbDataConsistency())
  {
    PduR_Core_SetState(PDUR_UNINIT);
    PduR_Det_ReportError(PDUR_FCT_INIT, PDUR_E_CONFIG_PTR_INVALID);
    PduR_Dem_ReportErrorStatus(PDUR_PDUR_E_INIT_FAILED, DEM_EVENT_STATUS_FAILED);
    return;
  }
#endif /* (PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME) */

  /*ESCAN00039232 Check consistency of BaseEnv.SizeOfPduIdType */
  if (sizeof(PduIdType) != PDUR_SIZEOFPDUIDTYPE)
  {
    PduR_Core_SetState(PDUR_UNINIT);
    PduR_Det_ReportError(PDUR_FCT_INIT, PDUR_INCONSISTENT_SIZEOFPDUIDTYPE);
    PduR_Dem_ReportErrorStatus(PDUR_PDUR_E_INIT_FAILED, DEM_EVENT_STATUS_FAILED);
    return;
  }

# if((PDUR_FRTP_SUPPORT == STD_ON) && (PDUR_FRTP_2PROVIDERXBUFFER_CALLS == STD_ON))
  PduR_Core_MemClr((P2VAR(uint8, TYPEDEF, PDUR_VAR_NOINIT)) pdur_FrTpProvide2RxBufferCallsWrapper,
                   (uint16) sizeof(PduR_Provide2RxBufferCallsWrapperType) * PduR_GetCfgElement(RxFrTpMaxCnt));
# endif
#if(PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
  {
    PduR_Core_MemClr((P2VAR(PduR_RoutingPathGroupIdType, TYPEDEF, PDUR_VAR_NOINIT)) pdur_DestPduStateCnt,
                     (PduR_RoutingPathGroupIdType) sizeof(PduR_RoutingPathGroupIdType) *
                     (PduR_GetNumberOfRoutingGroupDestPdusCnt()));
    /* The first index has to be set differently to 0. The index contains all DestPduReferences which are not assigned to a PduRRoutingPathGroup */
    pdur_DestPduStateCnt[0] = 1;
    {
      sint16_least siRPGIdx;
      for (siRPGIdx = ((sint16_least) PduR_GetCfgElement(RoutingPathGroupCnt)) - 1; siRPGIdx >= 0; siRPGIdx--)
      {
        pdur_RoutingPathGroupState[siRPGIdx] = FALSE;   /*set true after init of Acitve Routing Path Count */
        if (PduR_GetCfgElement(RoutingPathGroupStateInit)[siRPGIdx])
        {
          PduR_EnableRouting((PduR_RoutingPathGroupIdType) siRPGIdx);
        }
      }
    }
  }
#endif
  PduR_Core_SetState(PDUR_ONLINE);
}                               /* End of PduR_Init() */

#if(PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME)
STATIC FUNC(boolean, PDUR_CODE) PduR_Core_CheckPbDataConsistency(void)
{
  boolean retVal = TRUE;
  if (NULL_PTR != pdur_Core_PBConfigPtr)
  {
    if (PduR_GetCfgElement(FinalMagicNumber) != PDUR_MAGICNUMBER_FINAL)
    {
      retVal = FALSE;
    }
#  if(PDUR_FRIF_SUPPORT == STD_ON)
    if (PduR_GetCfgElement(RxFrIf2Up)[PduR_GetCfgElement(RxFrIf2UpCnt)].destPduId != PDUR_PORT_FRIF)
    {
      retVal = FALSE;
    }
    if (PduR_GetCfgElement(TxFrIf2Up)[PduR_GetCfgElement(TxFrIf2UpCnt)].destPduId != PDUR_PORT_FRIF)
    {
      retVal = FALSE;
    }
#  endif
#  if(PDUR_FRTP_SUPPORT == STD_ON)
    if (PduR_GetCfgElement(RxFrTp2Up)[PduR_GetCfgElement(RxFrTp2UpCnt)].destPduId != PDUR_PORT_FRTP)
    {
      retVal = FALSE;
    }
    if (PduR_GetCfgElement(TxFrTp2Up)[PduR_GetCfgElement(TxFrTp2UpCnt)].destPduId != PDUR_PORT_FRTP)
    {
      retVal = FALSE;
    }
#  endif
#  if(PDUR_COM_SUPPORT == STD_ON)
    if (PduR_GetCfgElement(TxCom2Lo)[PduR_GetCfgElement(TxCom2LoCnt)].destPduId != PDUR_PORT_COM)
    {
      retVal = FALSE;
    }
#  endif
#  if(PDUR_DCM_SUPPORT == STD_ON)
    if (PduR_GetCfgElement(TxDcm2Lo)[PduR_GetCfgElement(TxDcm2LoCnt)].destPduId != PDUR_PORT_DCM)
    {
      retVal = FALSE;
    }
#  endif
#  if(PDUR_IPDUM_SUPPORT == STD_ON)
    if (PduR_GetCfgElement(TxIpduM2Lo)[PduR_GetCfgElement(TxIpduM2LoCnt)].destPduId != PDUR_PORT_IPDUM)
    {
      retVal = FALSE;
    }
#  endif
#  if(PDUR_IPDUM_SUPPORT == STD_ON)
#   if(PDUR_IPDUM_OPTIMIZED == STD_OFF)
    if (PduR_GetCfgElement(TxIpduM2Up)[PduR_GetCfgElement(TxIpduM2UpCnt)].destPduId != PDUR_PORT_IPDUM)
    {
      retVal = FALSE;
    }
    if (PduR_GetCfgElement(RxIpduM2Up)[PduR_GetCfgElement(RxIpduM2UpCnt)].destPduId != PDUR_PORT_IPDUM)
    {
      retVal = FALSE;
    }
#   endif
#  endif
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}                               /* End of PduR_Core_CheckPbDataConsistency() */
#endif /* (PDUR_CONFIG_VARIANT == PDUR_CFGVAR_POSTBUILDTIME) */


FUNC(void, PDUR_CODE) PduR_InitMemory(void)
{
  PduR_Core_SetState(PDUR_UNINIT);
#if (PDUR_SELECTABLE_INIT_POINTER == STD_ON)
  pdur_Core_PBConfigPtr = NULL_PTR;
#endif
}                               /* End of PduR_InitMemory() */





/*********************************************************************************************************************/
/* NM specific functions (called by NM)                                                                              */
/*********************************************************************************************************************/




# if(PDUR_FRIF_SUPPORT == STD_ON)
/*********************************************************************************************************************/
/* FR IF specific functions (called by lower layers)                                                                 */
/*********************************************************************************************************************/
/* KB begin PduR_LoIfRxIndicationImplementation */
FUNC(void, PDUR_CODE) PduR_FrIfRxIndication(PduIdType FrIfRxPduId, PDUR_RXINDICATION_TYPE PDUR_RXINDICATION_PARA)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRIFRXIND, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(PDUR_RXINDICATION_PARA != NULL_PTR, PDUR_FCT_FRIFRXIND, PDUR_E_DATA_PTR_INVALID);
  PduR_Det_AssertReturnFunc(FrIfRxPduId < PduR_GetCfgElement(RxFrIf2UpCnt), PDUR_FCT_FRIFRXIND, PDUR_E_PDU_ID_INVALID);

  pDI = &PduR_GetCfgElement(RxFrIf2Up)[FrIfRxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
#  if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
    if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#  endif
       /* (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON) */
    {
      PduR_UpIfRxIndicationFctPtrType pUpIfRxIndicationFctPtr = PduR_Core_UpIfRxIndication[pDI->destPort];
      if (pUpIfRxIndicationFctPtr != NULL_PTR)
      {
        pUpIfRxIndicationFctPtr(pDI->destPduId, PDUR_RXINDICATION_PARA);
      }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
      else
      {
        PduR_Det_ReportError(PDUR_FCT_FRIFRXIND, PDUR_E_PDU_ID_INVALID);
      }
#  endif
    }
  }
}                               /* End of PduR_FrIfRxIndication() */

/* KB end PduR_LoIfRxIndicationImplementation */
/* KB begin PduR_LoIfTxConfirmationImplementation */
FUNC(void, PDUR_CODE) PduR_FrIfTxConfirmation(PduIdType FrIfTxPduId)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFunc((PduR_Core_GetState() == PDUR_ONLINE), PDUR_FCT_FRIFTXCFM, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc((FrIfTxPduId < PduR_GetCfgElement(TxFrIf2UpCnt)), PDUR_FCT_FRIFTXCFM,
                            PDUR_E_PDU_ID_INVALID);
  PduR_Det_AssertReturnFunc((PduR_GetCfgElement(TxFrIf2Up)[FrIfTxPduId].destPort != PDUR_PORT_INVALID),
                            PDUR_FCT_FRIFTXCFM, PDUR_E_PDU_ID_INVALID);

  pDI = &PduR_GetCfgElement(TxFrIf2Up)[FrIfTxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
    PduR_UpIfTxConfirmationFctPtrType pUpIfTxConfirmationFctPtr = PduR_Core_UpIfTxConfirmation[pDI->destPort];
    if (pUpIfTxConfirmationFctPtr != NULL_PTR)
    {
      pUpIfTxConfirmationFctPtr(pDI->destPduId);
    }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
    else
    {
      PduR_Det_ReportError(PDUR_FCT_FRIFTXCFM, PDUR_E_PDU_ID_INVALID);
    }
#  endif
  }
}                               /* End of PduR_FrIfTxConfirmation() */

/* KB end PduR_LoIfTxConfirmationImplementation */
/* KB begin PduR_LoIfTriggerTransmitImplementation */
FUNC(PDUR_TRIGGERTRANSMIT_RETURN, PDUR_CODE) PduR_FrIfTriggerTransmit(PduIdType FrIfTxPduId,
                                                                      PDUR_TRIGGERTRANSMIT_TYPE
                                                                      PDUR_TRIGGERTRANSMIT_PARA)
{
  PduR_Core_DestITypePtr pDI;
#  if(PDUR_USE_PDUINFOTYPE == STD_ON)
  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRIFTRGTX, PDUR_E_INVALID_REQUEST,
                                 PDUR_TRIGGERTRANSMIT_NOK);
  PduR_Det_AssertReturnFuncValue(PDUR_TRIGGERTRANSMIT_PARA != NULL_PTR, PDUR_FCT_FRIFTRGTX, PDUR_E_DATA_PTR_INVALID,
                                 PDUR_TRIGGERTRANSMIT_NOK);
  PduR_Det_AssertReturnFuncValue(FrIfTxPduId < PduR_GetCfgElement(TxFrIf2UpCnt), PDUR_FCT_FRIFTRGTX,
                                 PDUR_E_PDU_ID_INVALID, PDUR_TRIGGERTRANSMIT_NOK);
  PduR_Det_AssertReturnFuncValue(PduR_GetCfgElement(TxFrIf2Up)[FrIfTxPduId].destPort != PDUR_PORT_INVALID,
                                 PDUR_FCT_FRIFTRGTX, PDUR_E_PDU_ID_INVALID, PDUR_TRIGGERTRANSMIT_NOK);
#  else
  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRIFTRGTX, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(PDUR_TRIGGERTRANSMIT_PARA != NULL_PTR, PDUR_FCT_FRIFTRGTX, PDUR_E_DATA_PTR_INVALID);
  PduR_Det_AssertReturnFunc(FrIfTxPduId < PduR_GetCfgElement(TxFrIf2UpCnt), PDUR_FCT_FRIFTRGTX, PDUR_E_PDU_ID_INVALID);
  PduR_Det_AssertReturnFunc(PduR_GetCfgElement(TxFrIf2Up)[FrIfTxPduId].destPort != PDUR_PORT_INVALID,
                            PDUR_FCT_FRIFTRGTX, PDUR_E_PDU_ID_INVALID);
#  endif

  pDI = &PduR_GetCfgElement(TxFrIf2Up)[FrIfTxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
    PduR_UpIfTriggerTransmitFctPtrType pUpIfTriggerTransmitFctPtr = PduR_Core_UpIfTriggerTransmit[pDI->destPort];
    if (pUpIfTriggerTransmitFctPtr != NULL_PTR)
    {
#  if(PDUR_USE_PDUINFOTYPE == STD_ON)
      return
#  endif
        pUpIfTriggerTransmitFctPtr(pDI->destPduId, PDUR_TRIGGERTRANSMIT_PARA);
    }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
    else
    {
      PduR_Det_ReportError(PDUR_FCT_FRIFTRGTX, PDUR_E_PDU_ID_INVALID);
    }
#  endif
  }
  return PDUR_TRIGGERTRANSMIT_NOK;
}                               /* End of PduR_FrIfTriggerTransmit() */

/* KB end PduR_LoIfTriggerTransmitImplementation */

# endif
# if(PDUR_FRTP_SUPPORT == STD_ON)
/*********************************************************************************************************************/
/* FR TP specific functions (called by lower layers)                                                                 */
/*********************************************************************************************************************/
/* KB begin PduR_LoTpTxConfirmationImplementation */
FUNC(void, PDUR_CODE) PduR_FrTpTxConfirmation(PduIdType FrTpTxPduId, NotifResultType Result)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRTPTXCFM, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(FrTpTxPduId < PduR_GetCfgElement(TxFrTp2UpCnt), PDUR_FCT_FRTPTXCFM, PDUR_E_PDU_ID_INVALID);
  PduR_Det_AssertReturnFunc(PduR_GetCfgElement(TxFrTp2Up)[FrTpTxPduId].destPort != PDUR_PORT_INVALID,
                            PDUR_FCT_FRTPTXCFM, PDUR_E_PDU_ID_INVALID);

  pDI = &PduR_GetCfgElement(TxFrTp2Up)[FrTpTxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
    PduR_UpTpTxConfirmationFctPtrType pUpTpTxConfirmationFctPtr = PduR_Core_UpTpTxConfirmation[pDI->destPort];
    if (pUpTpTxConfirmationFctPtr != NULL_PTR)
    {
      pUpTpTxConfirmationFctPtr(pDI->destPduId, Result);
    }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
    else
    {
      PduR_Det_ReportError(PDUR_FCT_FRTPTXCFM, PDUR_E_PDU_ID_INVALID);
    }
#  endif
  }
}                               /* End of PduR_FrTpTxConfirmation() */

/* KB end PduR_LoTpTxConfirmationImplementation */
/* KB begin PduR_LoTpProvideTxBufferImplementation */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpProvideTxBuffer(PduIdType FrTpTxPduId,
                                                            P2VAR(PduInfoTypeApplPtr, AUTOMATIC,
                                                                  PDUR_APPL_DATA) PduInfoPtr, uint16 Length)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRTPPROTX, PDUR_E_INVALID_REQUEST,
                                 BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(PduInfoPtr != NULL_PTR, PDUR_FCT_FRTPPROTX, PDUR_E_DATA_PTR_INVALID, BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(FrTpTxPduId < PduR_GetCfgElement(TxFrTp2UpCnt), PDUR_FCT_FRTPPROTX,
                                 PDUR_E_PDU_ID_INVALID, BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(PduR_GetCfgElement(TxFrTp2Up)[FrTpTxPduId].destPort != PDUR_PORT_INVALID,
                                 PDUR_FCT_FRTPPROTX, PDUR_E_PDU_ID_INVALID, BUFREQ_E_NOT_OK);

  pDI = &PduR_GetCfgElement(TxFrTp2Up)[FrTpTxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
#  if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
    if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#  endif
       /* (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON) */
    {
      {
        PduR_UpTpProvideTxBufferFctPtrType pUpTpProvideTxBufferFctPtr = PduR_Core_UpTpProvideTxBuffer[pDI->destPort];
        if (pUpTpProvideTxBufferFctPtr != NULL_PTR)
        {
          return pUpTpProvideTxBufferFctPtr(pDI->destPduId, PduInfoPtr, Length);
        }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
        else
        {
          PduR_Det_ReportError(PDUR_FCT_FRTPPROTX, PDUR_E_PDU_ID_INVALID);
        }
#  endif
      }
    }
  }
  return BUFREQ_E_NOT_OK;
}                               /* End of PduR_FrTpProvideTxBuffer() */

/* KB end PduR_LoTpProvideTxBufferImplementation */
/* KB begin PduR_LoTpProvideRxBufferImplementationPrototype */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpProvideRxBuffer(PduIdType FrTpRxPduId, PduLengthType TpSduLength,
                                                            P2VAR(PduInfoTypeApplPtr, AUTOMATIC,
                                                                  PDUR_APPL_DATA) PduInfoPtr)
/* KB end PduR_LoTpProvideRxBufferImplementationPrototype */
/* KB begin PduR_LoTpProvideRxBufferImplementationContent */
{
  PduR_Core_DestITypePtr pDI;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRTPPRORX, PDUR_E_INVALID_REQUEST,
                                 BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(PduInfoPtr != NULL_PTR, PDUR_FCT_FRTPPRORX, PDUR_E_DATA_PTR_INVALID, BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(FrTpRxPduId < PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_FCT_FRTPPRORX,
                                 PDUR_E_PDU_ID_INVALID, BUFREQ_E_NOT_OK);
  PduR_Det_AssertReturnFuncValue(PduR_GetCfgElement(RxFrTp2Up)[FrTpRxPduId].destPort != PDUR_PORT_INVALID,
                                 PDUR_FCT_FRTPPRORX, PDUR_E_PDU_ID_INVALID, BUFREQ_E_NOT_OK);

  pDI = &PduR_GetCfgElement(RxFrTp2Up)[FrTpRxPduId];
  {
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
    if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
    {
#  if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
      if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#  endif
       /* (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON) */
      {
        {
#  if (PDUR_FRTP_2PROVIDERXBUFFER_CALLS == STD_ON)
          /* Start of ESCAN00044523 */
          PduR_Provide2RxBufferCallsWrapperTypePtr pProvideRxBufferCallsWrapper =
            &pdur_FrTpProvide2RxBufferCallsWrapper[FrTpRxPduId];
          {
            pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter++;
            /*emulate the second ProvideRxBuffer call of the UL */
            if (pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter == 2)
            {
              PduLengthType iSduLength = (*PduInfoPtr)->SduLength;
              /* The feature PDUR_FRTP_2PROVIDERXBUFFER_CALLS requires minimum a buffer in the UL with the size FF + 1 Byte */
              if (pProvideRxBufferCallsWrapper->ProvidedBufferLengthByUL > iSduLength)
              {
                pProvideRxBufferCallsWrapper->CopiedDataLength = iSduLength;
                (*PduInfoPtr)->SduDataPtr = (*PduInfoPtr)->SduDataPtr + iSduLength;
                (*PduInfoPtr)->SduLength = pProvideRxBufferCallsWrapper->ProvidedBufferLengthByUL - iSduLength;
                return BUFREQ_OK;
              }
              else
              {
                pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter = 0;
                PduR_Det_AssertReturnFuncValue(FALSE, PDUR_FCT_FRTPPRORX, PDUR_E_UL_BUFFER_UNDERRUN, BUFREQ_E_NOT_OK);
              }
            }
            else if (pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter == 3)
            {
              /*Reset all pointer manipulations to ensure that the upper layer module adjusts its pointer correct */
              (*PduInfoPtr)->SduDataPtr = (*PduInfoPtr)->SduDataPtr - (pProvideRxBufferCallsWrapper->CopiedDataLength);
              (*PduInfoPtr)->SduLength = pProvideRxBufferCallsWrapper->CopiedDataLength + (*PduInfoPtr)->SduLength;
            }
          }
          if (pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter != 2)
            /*End of ESCAN00044523 */
#  endif
          {
            PduR_UpTpProvideRxBufferFctPtrType pUpTpProvideRxBufferFctPtr =
              PduR_Core_UpTpProvideRxBuffer[pDI->destPort];
            if (pUpTpProvideRxBufferFctPtr != NULL_PTR)
            {
              retVal = pUpTpProvideRxBufferFctPtr(pDI->destPduId, TpSduLength, PduInfoPtr);
            }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
            else
            {
              PduR_Det_ReportError(PDUR_FCT_FRTPPRORX, PDUR_E_PDU_ID_INVALID);
            }
#  endif
#  if (PDUR_FRTP_2PROVIDERXBUFFER_CALLS == STD_ON)      /*Start ESCAN00044523 */
            if (pProvideRxBufferCallsWrapper->ProvideRxBufferCallCounter == 1)
            {
              if (retVal == BUFREQ_OK)
              {
                pProvideRxBufferCallsWrapper->ProvidedBufferLengthByUL = (*PduInfoPtr)->SduLength;
              }
              else
              {
                pdur_FrTpProvide2RxBufferCallsWrapper[FrTpRxPduId].ProvideRxBufferCallCounter = 0;
              }
            }
#  endif
       /*End ESCAN00044523 */
          }
        }
      }
    }
  }
  return retVal;
}                               /* End of PduR_FrTpProvideRxBuffer() */

/* KB end PduR_LoTpProvideRxBufferImplementationContent */
/* KB begin PduR_LoTpRxIndicationImplementation */
FUNC(void, PDUR_CODE) PduR_FrTpRxIndication(PduIdType FrTpRxPduId, NotifResultType Result)
{
  PduR_Core_DestITypePtr pDI;

  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRTPRXIND, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(FrTpRxPduId < PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_FCT_FRTPRXIND, PDUR_E_PDU_ID_INVALID);

#  if (PDUR_FRTP_2PROVIDERXBUFFER_CALLS == STD_ON)
  pdur_FrTpProvide2RxBufferCallsWrapper[FrTpRxPduId].ProvideRxBufferCallCounter = 0;
#  endif

  pDI = &PduR_GetCfgElement(RxFrTp2Up)[FrTpRxPduId];
#  if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#  endif
  {
    {
      PduR_UpTpRxIndicationFctPtrType pUpTpRxIndicationFctPtr = PduR_Core_UpTpRxIndication[pDI->destPort];
      if (pUpTpRxIndicationFctPtr != NULL_PTR)
      {
        pUpTpRxIndicationFctPtr(pDI->destPduId, Result);
      }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON)
      else
      {
        PduR_Det_ReportError(PDUR_FCT_FRTPRXIND, PDUR_E_PDU_ID_INVALID);
      }
#  endif
    }
  }
}                               /* End of PduR_FrTpRxIndication() */

/* KB end PduR_LoTpRxIndicationImplementation */
/* KB begin PduR_LoTpChangeParameterConfirmationImplementation */
#  if((PDUR_FRTP_SUPPORT == STD_ON) && (PDUR_FRTPCHANGEPARAMETER_SUPPORT == STD_ON))
FUNC(void, PDUR_CODE) PduR_FrTpChangeParameterConfirmation(PduIdType FrTpRxPduId, NotifResultType Result)
{
#   if (PDUR_DEV_ERROR_DETECT == STD_ON)
  boolean bRxPduIdValid = FALSE;
#   endif
  PduR_Core_DestITypePtr pCurRR = &PduR_GetCfgElement(RxFrTp2Up)[FrTpRxPduId];
  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_FRTPCPRC, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(FrTpRxPduId < PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_FCT_FRTPCPRC, PDUR_E_PDU_ID_INVALID);

  if (pCurRR->destPort == PDUR_PORT_DCM)
  {
    Dcm_ChangeParameterConfirmation(pCurRR->destPduId, Result);
#   if (PDUR_DEV_ERROR_DETECT == STD_ON)
    bRxPduIdValid = TRUE;
#   endif
  }
#   if(PDUR_MULTICAST_FROMTP_SUPPORT == STD_ON)
  else if (pCurRR->destPort == PDUR_PORT_MULTI)
  {
    PduIdType MultiTpRxPduId = pCurRR->destPduId;
    PduR_GwTp_RRMulDestInfoTypePtr pMRR = &PduR_GetCfgElement(TpRoutingMultRrInfo)[MultiTpRxPduId];
    while (pMRR->startId == pCurRR->destPduId)
    {
      if (pMRR->destPort == PDUR_PORT_DCM)
      {
        Dcm_ChangeParameterConfirmation(pMRR->destPduId, Result);
#    if (PDUR_DEV_ERROR_DETECT == STD_ON)
        bRxPduIdValid = TRUE;
#    endif
      }
      MultiTpRxPduId++;
      pMRR = &PduR_GetCfgElement(TpRoutingMultRrInfo)[MultiTpRxPduId];
    }
  }
#   endif
  PduR_Det_AssertReturnFunc(bRxPduIdValid == TRUE, PDUR_FCT_FRTPCPRC, PDUR_E_PDU_ID_INVALID);
}
#  endif

/* KB end PduR_LoTpChangeParameterConfirmationImplementation */
# endif
       /* defined(GW_ASRPDUR_ENABLE_FEATURE_FRTP_COMMENT) */

       /* defined(GW_ASRPDUR_ENABLE_FEATURE_LINIF_COMMENT) */



/*********************************************************************************************************************/
/* Dcm Tx Confirmation Wrapper                                                                                       */
/*********************************************************************************************************************/
# if(PDUR_DCM_SUPPORT == STD_ON)
FUNC(void, PDUR_CODE) PduR_DcmTxConfirmation(PduIdType DcmTxPduId)
{
  Dcm_TxConfirmation(DcmTxPduId, NTFRSLT_OK);
}
# endif
       /* defined(GW_ASRPDUR_ENABLE_FEATURE_DCM_COMMENT) */

/*********************************************************************************************************************/
/* Ipdum  specific functions (called by IpduM)                                                                       */
/*********************************************************************************************************************/
# if(PDUR_IPDUM_SUPPORT == STD_ON)
#  if(PDUR_IPDUM_OPTIMIZED == STD_OFF)
/* KB begin PduR_LoIfRxIndicationImplementation */
FUNC(void, PDUR_CODE) PduR_IpduMRxIndication(PduIdType IpduMRxPduId, PDUR_RXINDICATION_TYPE PDUR_RXINDICATION_PARA)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFunc(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_IPDUMRXIND, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc(PDUR_RXINDICATION_PARA != NULL_PTR, PDUR_FCT_IPDUMRXIND, PDUR_E_DATA_PTR_INVALID);
  PduR_Det_AssertReturnFunc(IpduMRxPduId < PduR_GetCfgElement(RxIpduM2UpCnt), PDUR_FCT_IPDUMRXIND,
                            PDUR_E_PDU_ID_INVALID);

  pDI = &PduR_GetCfgElement(RxIpduM2Up)[IpduMRxPduId];
#   if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#   endif
  {
#   if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
    if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#   endif
       /* (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON) */
    {
      PduR_UpIfRxIndicationFctPtrType pUpIfRxIndicationFctPtr = PduR_Core_UpIfRxIndication[pDI->destPort];
      if (pUpIfRxIndicationFctPtr != NULL_PTR)
      {
        pUpIfRxIndicationFctPtr(pDI->destPduId, PDUR_RXINDICATION_PARA);
      }
#   if (PDUR_DEV_ERROR_DETECT == STD_ON)
      else
      {
        PduR_Det_ReportError(PDUR_FCT_IPDUMRXIND, PDUR_E_PDU_ID_INVALID);
      }
#   endif
    }
  }
}                               /* End of PduR_IpduMRxIndication() */

/* KB end PduR_LoIfRxIndicationImplementation */
/* KB begin PduR_LoIfTxConfirmationImplementation */
FUNC(void, PDUR_CODE) PduR_IpduMTxConfirmation(PduIdType IpduMTxPduId)
{
  PduR_Core_DestITypePtr pDI;
  PduR_Det_AssertReturnFunc((PduR_Core_GetState() == PDUR_ONLINE), PDUR_FCT_IPDUMTXCFM, PDUR_E_INVALID_REQUEST);
  PduR_Det_AssertReturnFunc((IpduMTxPduId < PduR_GetCfgElement(TxIpduM2UpCnt)), PDUR_FCT_IPDUMTXCFM,
                            PDUR_E_PDU_ID_INVALID);
  PduR_Det_AssertReturnFunc((PduR_GetCfgElement(TxIpduM2Up)[IpduMTxPduId].destPort != PDUR_PORT_INVALID),
                            PDUR_FCT_IPDUMTXCFM, PDUR_E_PDU_ID_INVALID);

  pDI = &PduR_GetCfgElement(TxIpduM2Up)[IpduMTxPduId];
#   if (PDUR_MULTIPLE_CONFIGURATION == STD_ON)
  if (pDI->destPort != PDUR_PORT_INVALID)
#   endif
  {
    PduR_UpIfTxConfirmationFctPtrType pUpIfTxConfirmationFctPtr = PduR_Core_UpIfTxConfirmation[pDI->destPort];
    if (pUpIfTxConfirmationFctPtr != NULL_PTR)
    {
      pUpIfTxConfirmationFctPtr(pDI->destPduId);
    }
#   if (PDUR_DEV_ERROR_DETECT == STD_ON)
    else
    {
      PduR_Det_ReportError(PDUR_FCT_IPDUMTXCFM, PDUR_E_PDU_ID_INVALID);
    }
#   endif
  }
}                               /* End of PduR_IpduMTxConfirmation() */

/* KB end PduR_LoIfTxConfirmationImplementation */
#  endif
# endif
       /* defined(GW_ASRPDUR_ENABLE_FEATURE_IPDUM_COMMENT) */

       /* defined(GW_ASRPDUR_ENABLE_FEATURE_GATEWAY_COMMENT) */
    /* defined(GW_ASRPDUR_ENABLE_FEATURE_TPGATEWAY_COMMENT) */





#if ((PDUR_CANTPCHANGEPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPCHANGEPARAMETER_SUPPORT    == STD_ON) || (PDUR_CANTPREADPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPREADPARAMETER_SUPPORT    == STD_ON) || (PDUR_DCMRECEIVECANCELLATION_SUPPORT == STD_ON) || (PDUR_APPLTPRECEIVECANCELLATION_SUPPORT == STD_ON))
STATIC FUNC(boolean, PDUR_CODE) PduR_Core_GetLoTpHandleFromUpTpHandle(PduR_Core_DestITypePtr pDIStart, PduIdType pDICnt,
                                                                      PduIdType UpRxPduIdPort, PduIdType UpRxPduId,
                                                                      P2VAR(PduIdType, AUTOMATIC,
                                                                            PDUR_APPL_DATA) LoRxPduId)
{
  sint16_least sLoRxPduId;
  for (sLoRxPduId = ((sint16_least) pDICnt) - 1; sLoRxPduId >= 0; sLoRxPduId--)
  {
    PduR_Core_DestITypePtr pCurRR = &pDIStart[sLoRxPduId];
    if (pCurRR->destPort == UpRxPduIdPort)
    {
      if (pCurRR->destPduId == UpRxPduId)
      {
        *LoRxPduId = (PduIdType) sLoRxPduId;
        return TRUE;
      }
    }
# if(PDUR_MULTICAST_FROMTP_SUPPORT == STD_ON)
    else if (pCurRR->destPort == PDUR_PORT_MULTI)
    {
      PduIdType MultiTpRxPduId = pCurRR->destPduId;
      PduR_GwTp_RRMulDestInfoTypePtr pMRR = &PduR_GetCfgElement(TpRoutingMultRrInfo)[MultiTpRxPduId];
      while (pMRR->startId == pCurRR->destPduId)
      {
        if (pMRR->destPort == UpRxPduIdPort)
        {
          if (pMRR->destPduId == UpRxPduId)
          {
            *LoRxPduId = (PduIdType) sLoRxPduId;
            return TRUE;
          }
        }
        MultiTpRxPduId++;
        pMRR = &PduR_GetCfgElement(TpRoutingMultRrInfo)[MultiTpRxPduId];
      }
    }
# endif
  }
  return FALSE;
}
#endif

# if  ( PDUR_DCMCHANGEPARAMETER_SUPPORT == STD_ON)
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmChangeParameterRequest(PduIdType DcmRxPduId, TPParameterType parameter,
                                                               uint16 value)
{

  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_DCMCPR, PDUR_E_INVALID_REQUEST,
                                 E_NOT_OK);
#   if((PDUR_FRTP_SUPPORT == STD_ON) && (PDUR_FRTPCHANGEPARAMETER_SUPPORT == STD_ON))
  {
    PduIdType LoRxTpPduId;
    if (PduR_Core_GetLoTpHandleFromUpTpHandle
        (PduR_GetCfgElement(RxFrTp2Up), PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_PORT_DCM, DcmRxPduId, &LoRxTpPduId))
    {
      PduR_Core_DestITypePtr pDI = &PduR_GetCfgElement(RxFrTp2Up)[LoRxTpPduId];
      {
        return FrTp_ChangeParameterRequest(LoRxTpPduId, parameter, value);
      }
    }
  }
#   endif
  PduR_Det_ReportError(PDUR_FCT_DCMCPR, PDUR_E_PDU_ID_INVALID);
  /*ChangeParameterConfirmation must be called since a return value of E_NOT_OK is no sign for the DCM not to expect a confirmation call */
  Dcm_ChangeParameterConfirmation(DcmRxPduId, NTFRSLT_E_VALUE_NOT_OK);
  return E_NOT_OK;
}
# endif

# if ((PDUR_CANTPREADPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPREADPARAMETER_SUPPORT == STD_ON))
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmReadParameterRequest(PduIdType DcmRxPduId, TPParameterType parameter,
                                                             P2VAR(uint16, AUTOMATIC, PDUR_APPL_DATA) valuePtr)
{

  PduR_Det_AssertReturnFuncValue(PduR_Core_GetState() == PDUR_ONLINE, PDUR_FCT_DCMRPR, PDUR_E_INVALID_REQUEST,
                                 E_NOT_OK);
#   if((PDUR_FRTP_SUPPORT == STD_ON) && (PDUR_FRTPREADPARAMETER_SUPPORT == STD_ON))
  {
    PduIdType LoRxTpPduId;
    if (PduR_Core_GetLoTpHandleFromUpTpHandle
        (PduR_GetCfgElement(RxFrTp2Up), PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_PORT_DCM, DcmRxPduId, &LoRxTpPduId))
    {
      PduR_Core_DestITypePtr pDI = &PduR_GetCfgElement(RxFrTp2Up)[LoRxTpPduId];
      {
        return FrTp_ReadParameterRequest(LoRxTpPduId, parameter, valuePtr);
      }
    }
  }
#   endif
  PduR_Det_ReportError(PDUR_FCT_DCMRPR, PDUR_E_PDU_ID_INVALID);
  return E_NOT_OK;
}
# endif

/* KB begin PduR_UpTpCancelReceiveRequestImplementation */
# if((PDUR_DCMRECEIVECANCELLATION_SUPPORT == STD_ON) && (PDUR_DCM_SUPPORT == STD_ON))
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceiveRequest(PduIdType DcmRxPduId)
{
  PduIdType LoRxTpPduId;
  PduR_Det_AssertReturnFuncValue((PduR_Core_GetState() == PDUR_ONLINE), PDUR_FCT_DCMCRR, PDUR_E_INVALID_REQUEST,
                                 E_NOT_OK);
#   if((PDUR_FRTPRECEIVECANCELLATION_SUPPORT == STD_ON) && (PDUR_FRTP_SUPPORT == STD_ON))
  if (PduR_Core_GetLoTpHandleFromUpTpHandle
      (PduR_GetCfgElement(RxFrTp2Up), PduR_GetCfgElement(RxFrTp2UpCnt), PDUR_PORT_DCM, DcmRxPduId, &LoRxTpPduId))
  {
#    if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
    PduR_Core_DestITypePtr pDI = &PduR_GetCfgElement(RxFrTp2Up)[LoRxTpPduId];
    if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#    endif
    {
      return FrTp_CancelReceiveRequest(LoRxTpPduId);
    }
  }
#   endif
  PduR_Det_ReportError(PDUR_FCT_DCMCRR, PDUR_E_PDU_ID_INVALID);
  Dcm_RxIndication(DcmRxPduId, NTFRSLT_E_CANCELATION_NOT_OK);
  return E_NOT_OK;
}
# endif

/* KB end PduR_UpTpCancelReceiveRequestImplementation */


/* KB begin PduR_UpTpCancelTransmitRequestImplementation */
# if((PDUR_DCMTRANSMITCANCELLATION_SUPPORT == STD_ON) && (PDUR_DCM_SUPPORT == STD_ON))
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmitRequest(PduIdType DcmTxPduId)
{
  PduR_Det_AssertReturnFuncValue((PduR_Core_GetState() == PDUR_ONLINE), PDUR_FCT_DCMCTR, PDUR_E_INVALID_REQUEST,
                                 E_NOT_OK);

  if (DcmTxPduId < PduR_GetCfgElement(TxDcm2LoCnt))
  {
    PduR_Core_DestITypePtr pDI = &PduR_GetCfgElement(TxDcm2Lo)[DcmTxPduId];
    {
#  if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
      if (0 != pdur_DestPduStateCnt[pDI->DestPduCntIndex])
#  endif/* (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON) */
      {
#   if((PDUR_FRTPTRANSMITCANCELLATION_SUPPORT == STD_ON)&& (PDUR_FRTP_SUPPORT == STD_ON))
        if (PDUR_PORT_FRTP == pDI->destPort)
        {
          return FrTp_CancelTransmitRequest(pDI->destPduId);
        }
#   endif
      }
    }
  }
  PduR_Det_ReportError(PDUR_FCT_DCMCTR, PDUR_E_PDU_ID_INVALID);
  Dcm_TxConfirmation(DcmTxPduId, NTFRSLT_E_CANCELATION_NOT_OK);
  return E_NOT_OK;
}
# endif

/* KB end PduR_UpTpCancelTransmitRequestImplementation */


#if (PDUR_ROUTINGPATHGROUP_SUPPORT == STD_ON)
FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id)
{
  PduR_Det_AssertReturnFunc(id < PduR_GetCfgElement(RoutingPathGroupCnt), PDUR_FCT_ENABLEROUTING,
                            PDUR_E_ROUTING_TABLE_ID_INVALID);
  if (FALSE == pdur_RoutingPathGroupState[id])
  {
    uint16 PathGroupIndirectionIdx = PduR_GetCfgElement(RPG2DestPduStateCntStartIndex)[id];
    uint16 PathGroupIndirectionStopIdx = PduR_GetCfgElement(RPG2DestPduStateCntStartIndex)[id + 1];
    for (; PathGroupIndirectionIdx < PathGroupIndirectionStopIdx; PathGroupIndirectionIdx++)
    {
      pdur_DestPduStateCnt[PduR_GetCfgElement(RPG2DestPduStateCntInd)[PathGroupIndirectionIdx]]++;
    }
    pdur_RoutingPathGroupState[id] = TRUE;
  }
}

FUNC(void, PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id)
{
  PduR_Det_AssertReturnFunc(id < PduR_GetCfgElement(RoutingPathGroupCnt), PDUR_FCT_DISABLEROUTING,
                            PDUR_E_ROUTING_TABLE_ID_INVALID);
  if (TRUE == pdur_RoutingPathGroupState[id])
  {
    uint16 PathGroupIndirectionIdx = PduR_GetCfgElement(RPG2DestPduStateCntStartIndex)[id];
    uint16 PathGroupIndirectionStopIdx = PduR_GetCfgElement(RPG2DestPduStateCntStartIndex)[id + 1];
    for (; PathGroupIndirectionIdx < PathGroupIndirectionStopIdx; PathGroupIndirectionIdx++)
    {
      pdur_DestPduStateCnt[PduR_GetCfgElement(RPG2DestPduStateCntInd)[PathGroupIndirectionIdx]]--;
    }
    pdur_RoutingPathGroupState[id] = FALSE;
  }
}
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CODE=====================================================*/

/* STOPSINGLE_OF_MULTIPLE */
