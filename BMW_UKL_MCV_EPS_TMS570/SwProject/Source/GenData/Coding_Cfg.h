
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Coding_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : ALL
**
**  PROJECT           : BMW Standard Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : Configuration file of coding module
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: n.a.
**
**  GENERATION TIME   : 18.01.2016 20:29:47 !!!IGNORE-LINE!!!
**
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** hauf         Andreas Hauf               EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.3: 23.08.2011, olho: CR71006: Replaced Xp.ModuleConf by
 *                                    Xp.ModuleConfAtDefRefTo
 *         23.08.2011, olho: CR71116: Changed context to referenced signal group
 * V1.3.2: 12.05.2011, olho: CR71025: Commented RTE return values
 * V1.3.1: 15.02.2011, thmi: CR70905: updated MISRA comments to MISRA 2004
 * V1.3.0: 27.09.2010, olho: CR70727: Com_ReceiveShadowSignal() shall only be
 *                                    executed if Com_ReceiveSignalGroup()
 *                                    returns E_OK
 *                           CR70784: CodingAllowed() should treat Coding
 *                                    preconditions
 * V1.2.0: 16.07.2010, bemo: CR70715: Coding_NvData.data shall be configured
 *                                    instead of Coding_NvData
 * V1.1.4  23.03.2010, olho: CR70559: Replaced VIN signal with signalgroup
 * V1.1.4  17.03.2010, olho: CR70560: Enable PIA notification via RTE
 * V1.1.3  28.10.2009, hauf: CR70347: Fixed compiler abstraction findings
 * V1.1.2: 30.06.2009, hauf: CR70247: replaced ON/OFF with STD_ON/STD_OFF
 *         26.05.2009, hauf: CR70217: Adapted calculation of signature size
 * V1.1.0: 17.03.2009, hauf: CR70090: New API Coding_GetVinCpsComparisonResult
 * V1.0.1: 09.10.2008, hauf: CR70025: Don't include Pia.h if PIA not configured
 * V1.0.0: 30.11.2007, hauf: ported from SC6.7.2 file version V4.1.0
 */

#ifndef CODING_CFG_H
#define CODING_CFG_H

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
/* Misra-C:2004 Deviation List:
  *
  * MISRA-1)  Deviated Rule: 18.4 (required)
  *   Unions shall not be used.
  *
  *   Reason:
  *   Used to align data to 32 bit
  *
  * MISRA-2)  Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   RTE-Function like macro is necessary.
  *
  */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*** Public Part (used by Coding API) *****************************************/

   #include <Std_Types.h>                   /* Standard type definitions      */

/*** Private Part (used by Coding.c only) *************************************/
#ifdef CODING_C

   #include <Dcm.h>                         /* Diagnostic control manager     */
   #include <NvM.h>                         /* Non volatile memory manager    */
   #include <Com.h>                         /* Communication module           */
   #include <Dem.h>                         /* Diagnostic event manager       */
   #include <ApplMain.h>                    /* Needed for WaitUntilNvmReady() */
   #include <sc_ee_data.h>                  /* Needed for CodingRequired()    */
   #include <sc_types.h>                    /* Needed for Make32Bit()         */
   #include <sc_target.h>                   /* Needed for Memcopy()           */
   #include <Rte_Coding.h>                  /* Coding component header file   */

#endif /* CODING_C                                                            */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*** Public Part (used by Coding API) *****************************************/

   /*
    * File version information
    */
   #define CODING_CFG_H_MAJOR_VERSION   2u
   #define CODING_CFG_H_MINOR_VERSION   2u
   #define CODING_CFG_H_PATCH_VERSION   5u

   /*
    * RTE enable flags
    */
   #define CODING_RTE_ENABLE        STD_ON
   #define CODING_RTE_API_ENABLE    STD_ON
   #define CODING_RTE_DIAG_ENABLE   STD_OFF
   #define CODING_RTE_NVM_ENABLE    STD_OFF
   #define CODING_RTE_COM_ENABLE    STD_OFF
   #define CODING_RTE_DEM_ENABLE    STD_OFF

   /*
    * Mapping of Coding_NvData to Coding_NvDataInternal
    */
   #define Coding_NvData Coding_NvDataInternal.data

   /*
    * Number of coding areas
    */
   #define CODING_NUMBER_OF_AREAS   1u

   /*
    * Number of coding blocks
    */
   #define CODING_NUMBER_OF_BLOCKS   5u

   #define CODING_NVSTATUS_IDX 1

   #define SIZEOF_ALL_BLOCKS 159


/*** Private Part (used by Coding.c only) *************************************/
#ifdef CODING_C

   /*** Coding API ************************************************************/

   /*
    * Mapping of the function to inform the application about the start of a
    * coding data change.
    * The function shall ensure that the coding data in the NVRAM mirror is not
    * used for calculations, etc. anymore
    */
   #define Coding_Call_CbkDataChange_StartNotification() \
              /* avoid RTE return value */               \
              (void)Rte_Call_CbkDataChange_StartNotification()

   /*
    * Mapping of the function to inform the application about the end of a
    * coding data change.
    * The function shall ensure that the new coding values from the NVRAM mirror
    * are used for future calculations, etc.
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_CbkDataChange_EndNotification( status ) \
              /* avoid RTE return value */                     \
              (void)Rte_Call_CbkDataChange_EndNotification( status )

   /*
    * Mapping of the function to check the content of a coding block.
    * The function shall check if the content of the coding block is valid
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_CbkBlockValid_Check( block, pData, size, error ) \
              /* avoid RTE return value */                              \
              (void)Rte_Call_CbkBlockValid_Check( block, pData, size, error )

   /*
    * Mapping of the function to receive the content of a coding block.
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_CbkBlock_Receive( block, pData, size ) \
              /* avoid RTE return value */                    \
              (void)Rte_Call_CbkBlock_Receive( block, pData, size )

   /*
    * Mapping of the function to check the coding preconditions.
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_CbkPreConditions_Check( error ) \
              /* avoid RTE return value */             \
              (void)Rte_Call_CbkPreConditions_Check( error )

   /*** Diag ******************************************************************/

   /*
    * Mapping of the function to set negative diagnostic response.
    * The function shall set the error code in the diagnostic response
    * message of the pMsgContext
    */
   /* Deviation MISRA-2 */
   #define Coding_DiagSetNegResponse( pMsgContext, errorCode ) \
              Dcm_SetNegResponse( pMsgContext, errorCode )

   /*
    * Mapping of the function to get the current diagnostic security level.
    * The function shall return the current diagnostic security level
    */
   #define Coding_DiagGetSecurityLevel() \
              Dcm_GetSecurityLevel()

   /*
    * Mapping of the function to get the current session id.
    * The function shall return the current session id
    */
   #define Coding_DiagGetSesCtrlType() \
              Dcm_GetSesCtrlType()

   /*
    * Mapping of the function to set the current session id.
    * The function shall perform a switch to the given diagnostic session
    */
   /* Deviation MISRA-2 */
   #define Coding_DiagSetSesCtrlType( session ) \
              Dcm_SetSesCtrlType( session )

   /*** NVM *******************************************************************/

   /*
    * NVM blocks
    */
   #define CODING_NVM_DATA_BLOCK     NVM_BLOCK_CODING_DATA
   #define CODING_NVM_STATUS_BLOCK   NVM_BLOCK_CODING_STATUS

   /*
    * Mapping of the functions to get the status of a NVM block.
    * The function shall return the current status of the NVM block
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_NvmBlockData_GetErrorStatus( status ) \
              Coding_NvmGetErrorStatus( NVM_BLOCK_CODING_DATA, status )
   /* Deviation MISRA-2 */
   #define Coding_Call_NvmBlockStatus_GetErrorStatus( status ) \
              Coding_NvmGetErrorStatus( NVM_BLOCK_CODING_STATUS, status )
   #define Coding_NvmGetErrorStatus( block, status ) \
              NvM_GetErrorStatus( block, status )

   /*
    * Mapping of the functions to write a NVM block.
    * The function shall write the given NVM block to NV memory
    */
   #define Coding_Call_NvmBlockData_WriteBlock() \
              Coding_NvmWriteBlock( NVM_BLOCK_CODING_DATA )
   #define Coding_Call_NvmBlockStatus_WriteBlock() \
              Coding_NvmWriteBlock( NVM_BLOCK_CODING_STATUS )
   #define Coding_NvmWriteBlock( block ) \
              NvM_WriteBlock( block, NULL_PTR )

   /*
    * Mapping of the functions to restore the defaults of a NVM block.
    * The function shall restore the default values of the given NVM block
    */
   #define Coding_Call_NvmBlockStatus_RestoreBlockDefaults() \
              Coding_NvmRestoreBlockDefaults( NVM_BLOCK_CODING_STATUS )
   #define Coding_NvmRestoreBlockDefaults( block ) \
              NvM_RestoreBlockDefaults( block, NULL_PTR )

   /*
    * Mapping of the functions to set the write protection status of a NVM block.
    * The function shall set the write protection status of the given NVM block
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_NvmBlockData_Administration_SetBlockProtection( status ) \
              Coding_NvmSetBlockProtection( NVM_BLOCK_CODING_DATA, status )
   #define Coding_NvmSetBlockProtection( block, status ) \
              NvM_SetBlockProtection( block, status )

   /*** COM *******************************************************************/

   /*
    * Mapping of function to receive any COM signal without RTE
    */
   /* Deviation MISRA-2 */
   #define Coding_ComReceiveSignal( signal, pData ) \
              Com_ReceiveSignal( signal, pData )

   /*
    * Mapping of functions to receive the VIN COM signals
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_ComSignalGroupFahrgestellnummer_ReceiveSignalGroup( pData )  \
              do                                                                \
              {                                                                 \
                if (Com_ReceiveSignalGroup( Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER ) == E_OK) {              \
	              Com_ReceiveShadowSignal( Com_NO_VECH_1__FAHRGESTELLNUMMER, (void *) &((pData)[0]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_2__FAHRGESTELLNUMMER, (void *) &((pData)[1]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_3__FAHRGESTELLNUMMER, (void *) &((pData)[2]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_4__FAHRGESTELLNUMMER, (void *) &((pData)[3]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_5__FAHRGESTELLNUMMER, (void *) &((pData)[4]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_6__FAHRGESTELLNUMMER, (void *) &((pData)[5]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_7__FAHRGESTELLNUMMER, (void *) &((pData)[6]) ); \
              }                                                               \
            } while (0)
			   /* ---- Nxtr Patch Start -----
                  Com_ReceiveShadowSignal( Com_TEMP_EX__A_TEMP, (void *) &((pData)[0]) ); \
                  Com_ReceiveShadowSignal( Com_TEMP_EX_UNFILT__A_TEMP, (void *) &((pData)[1]) ); \
                  Com_ReceiveShadowSignal( Com_ID2_0x08_Mx01_DSC_Modul__ANFRAGE_DSC_Modul, (void *) &((pData)[2]) ); \
                  Com_ReceiveShadowSignal( Com_ID_FN_INQY_DSC_Modul__ANFRAGE_DSC_Modul, (void *) &((pData)[3]) ); \
                  Com_ReceiveShadowSignal( Com_ID2_0x08_Mx01_EPS__ANFRAGE_EPS, (void *) &((pData)[4]) ); \
                  Com_ReceiveShadowSignal( Com_ID_FN_INQY_EPS__ANFRAGE_EPS, (void *) &((pData)[5]) ); \
                  Com_ReceiveShadowSignal( Com_ID2_0x08_Mx01_SAS__ANFRAGE_SAS, (void *) &((pData)[6]) ); \
                  Com_ReceiveShadowSignal( Com_ID_FN_INQY_SAS__ANFRAGE_SAS, (void *) &((pData)[7]) ); \
                  Com_ReceiveShadowSignal( Com_ID2_0x08_Mx01_ZGW__ANFRAGE_ZGW, (void *) &((pData)[8]) ); \
                  Com_ReceiveShadowSignal( Com_ID_FN_INQY_ZGW__ANFRAGE_ZGW, (void *) &((pData)[9]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_AVL_FORC_GRD__AVL_FORC_GRD, (void *) &((pData)[10]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_AVL_FORC_GRD__AVL_FORC_GRD, (void *) &((pData)[11]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_FORC_GRD_0x0C_0x04__AVL_FORC_GRD, (void *) &((pData)[12]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_FORC_GRD__AVL_FORC_GRD, (void *) &((pData)[13]) ); \
                  Com_ReceiveShadowSignal( Com_QU_AVL_FORC_GRD__AVL_FORC_GRD, (void *) &((pData)[14]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_PWR_EL_EPS_COOD__AVL_FORC_GRD, (void *) &((pData)[15]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_AVL_PO_EPS__AVL_PO_EPS, (void *) &((pData)[16]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_AVL_PO_EPS__AVL_PO_EPS, (void *) &((pData)[17]) ); \
                  Com_ReceiveShadowSignal( Com_QU_AVL_PO_EPS__AVL_PO_EPS, (void *) &((pData)[18]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_PO_EPS__AVL_PO_EPS, (void *) &((pData)[19]) ); \
                  Com_ReceiveShadowSignal( Com_OFFS_GRD_MID_EPS__AVL_PO_EPS, (void *) &((pData)[20]) ); \
                  Com_ReceiveShadowSignal( Com_UN_PO_EPS__AVL_PO_EPS, (void *) &((pData)[21]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_PO_IDX_EPS__AVL_PO_EPS, (void *) &((pData)[22]) ); \
                  Com_ReceiveShadowSignal( Com_IDX_TORQ_SEN__AVL_PO_EPS, (void *) &((pData)[23]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (void *) &((pData)[24]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (void *) &((pData)[25]) ); \
                  Com_ReceiveShadowSignal( Com_QU_HOFF_RCOG__AVL_STMOM_DV_ACT, (void *) &((pData)[26]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (void *) &((pData)[27]) ); \
                  Com_ReceiveShadowSignal( Com_QU_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (void *) &((pData)[28]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_1__FAHRGESTELLNUMMER, (void *) &((pData)[29]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_2__FAHRGESTELLNUMMER, (void *) &((pData)[30]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_3__FAHRGESTELLNUMMER, (void *) &((pData)[31]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_4__FAHRGESTELLNUMMER, (void *) &((pData)[32]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_5__FAHRGESTELLNUMMER, (void *) &((pData)[33]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_6__FAHRGESTELLNUMMER, (void *) &((pData)[34]) ); \
                  Com_ReceiveShadowSignal( Com_NO_VECH_7__FAHRGESTELLNUMMER, (void *) &((pData)[35]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_OFFS_QUAD_EPS__OFFS_QUAD_EPS, (void *) &((pData)[36]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_OFFS_QUAD_EPS__OFFS_QUAD_EPS, (void *) &((pData)[37]) ); \
                  Com_ReceiveShadowSignal( Com_ST_OFFS_QUAD_EPS__OFFS_QUAD_EPS, (void *) &((pData)[38]) ); \
                  Com_ReceiveShadowSignal( Com_OFFS_QUAD_RTR_EPS__OFFS_QUAD_EPS, (void *) &((pData)[39]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_PO_IDX_ICM__OFFS_QUAD_EPS, (void *) &((pData)[40]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_ST_EST_FTAX__ST_EST, (void *) &((pData)[41]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_ST_EST_FTAX__ST_EST, (void *) &((pData)[42]) ); \
                  Com_ReceiveShadowSignal( Com_ST_EST_0x0C_0x04__ST_EST, (void *) &((pData)[43]) ); \
                  Com_ReceiveShadowSignal( Com_QU_SER_PINA_EST_FTAX__ST_EST, (void *) &((pData)[44]) ); \
                  Com_ReceiveShadowSignal( Com_QU_SER_STMOM_DV_ACT__ST_EST, (void *) &((pData)[45]) ); \
                  Com_ReceiveShadowSignal( Com_QU_FN_EST__ST_EST, (void *) &((pData)[46]) ); \
                  Com_ReceiveShadowSignal( Com_TOT_STR_EPS__SU_EPS, (void *) &((pData)[47]) ); \
                  Com_ReceiveShadowSignal( Com_UN_TOT_STR_EPS__SU_EPS, (void *) &((pData)[48]) ); \
                  Com_ReceiveShadowSignal( Com_SU_EPS_0x0E_0x02__SU_EPS, (void *) &((pData)[49]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_SU_SW_DRDY__SU_SW_DRDY, (void *) &((pData)[50]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_SU_SW_DRDY__SU_SW_DRDY, (void *) &((pData)[51]) ); \
                  Com_ReceiveShadowSignal( Com_RQ_SU_SW_DRDY__SU_SW_DRDY, (void *) &((pData)[52]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_MOD_SW_DRDY__SU_SW_DRDY, (void *) &((pData)[53]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_MOD_SW_DRDY_DRV__SU_SW_DRDY, (void *) &((pData)[54]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_MOD_SW_DRDY_CHAS__SU_SW_DRDY, (void *) &((pData)[55]) ); \
                  Com_ReceiveShadowSignal( Com_AVL_MOD_SW_DRDY_STAB__SU_SW_DRDY, (void *) &((pData)[56]) ); \
                  Com_ReceiveShadowSignal( Com_DISP_ST_DSC__SU_SW_DRDY, (void *) &((pData)[57]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, (void *) &((pData)[58]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, (void *) &((pData)[59]) ); \
                  Com_ReceiveShadowSignal( Com_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, (void *) &((pData)[60]) ); \
                  Com_ReceiveShadowSignal( Com_QU_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, (void *) &((pData)[61]) ); \
                  Com_ReceiveShadowSignal( Com_FACT_CTRR_STMOM_FTAX__TAR_QTA_STRMOM_DV, (void *) &((pData)[62]) ); \
                  Com_ReceiveShadowSignal( Com_FACT_DMPNG_STMOM_FTAX__TAR_QTA_STRMOM_DV, (void *) &((pData)[63]) ); \
                  Com_ReceiveShadowSignal( Com_FACT_ASS_STMOM_FTAX__TAR_QTA_STRMOM_DV, (void *) &((pData)[64]) ); \
                  Com_ReceiveShadowSignal( Com_QU_TAR_FACT_STMOM_FTAX__TAR_QTA_STRMOM_DV, (void *) &((pData)[65]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, (void *) &((pData)[66]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, (void *) &((pData)[67]) ); \
                  Com_ReceiveShadowSignal( Com_UN_TARVL_PMA__TAR_STMOM_DV_ACT, (void *) &((pData)[68]) ); \
                  Com_ReceiveShadowSignal( Com_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, (void *) &((pData)[69]) ); \
                  Com_ReceiveShadowSignal( Com_QU_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, (void *) &((pData)[70]) ); \
                  Com_ReceiveShadowSignal( Com_TARVL_PMA__TAR_STMOM_DV_ACT, (void *) &((pData)[71]) ); \
                  Com_ReceiveShadowSignal( Com_QU_TARVL_PMA__TAR_STMOM_DV_ACT, (void *) &((pData)[72]) ); \
                  Com_ReceiveShadowSignal( Com_FACT_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT, (void *) &((pData)[73]) ); \
                  Com_ReceiveShadowSignal( Com_QU_TAR_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT, (void *) &((pData)[74]) ); \
                  Com_ReceiveShadowSignal( Com_ALIV_V_VEH__V_VEH, (void *) &((pData)[75]) ); \
                  Com_ReceiveShadowSignal( Com_CRC_V_VEH__V_VEH, (void *) &((pData)[76]) ); \
                  Com_ReceiveShadowSignal( Com_DVCO_VEH__V_VEH, (void *) &((pData)[77]) ); \
                  Com_ReceiveShadowSignal( Com_QU_V_VEH_COG__V_VEH, (void *) &((pData)[78]) ); \
                  Com_ReceiveShadowSignal( Com_ST_V_VEH_NSS__V_VEH, (void *) &((pData)[79]) ); \
                  Com_ReceiveShadowSignal( Com_V_VEH_0x27_0x01__V_VEH, (void *) &((pData)[80]) ); \
                  Com_ReceiveShadowSignal( Com_V_VEH_COG__V_VEH, (void *) &((pData)[81]) ); \
                }                                                               \
              } while (0)
              ---- Nxtr Patch End ---- */

   /*
    * Mapping of function to receive the SPEED COM signal
    */
   /* Deviation MISRA-2 */
/* Nxtr patch - The correct vehicle speed signal, Com_V_VEH_COG__V_VEH, does not appear in the drop down list when selecting the 'speed signal' using Configurator.
                   In order to generate successfully the first signal in the drop down list was used and the correct signal was added back manually here: */
   #define Coding_Call_ComSignalSpeed_ReceiveSignal( pData ) \
              Coding_ComReceiveSignal( Com_V_VEH_COG__V_VEH, pData )

   /*** DEM *******************************************************************/

   /*
    * Mapping of the function to report the status of any DEM event without RTE.
    * The function shall set the status of the given DEM event
    */
   /* Deviation MISRA-2 */
   #define Coding_DemReportErrorStatus( event, status ) \
              Dem_ReportErrorStatus( event, status )

   /*
    * Mapping of the functions to set the status of the DEM events.
    * The functions shall set the status of a specific DEM event
    */
   /* Deviation MISRA-2 */
   #define Coding_Call_DemEventNotCoded_SetEventStatus( status ) \
              Coding_DemReportErrorStatus( CODING_EVENT_NOT_CODED, status )
   /* Deviation MISRA-2 */
   #define Coding_Call_DemEventTransactionFailed_SetEventStatus( status ) \
              Coding_DemReportErrorStatus( CODING_EVENT_TRANSACTION_FAILED, status )
   /* Deviation MISRA-2 */
   #define Coding_Call_DemEventSignatureError_SetEventStatus( status ) \
              Coding_DemReportErrorStatus( CODING_EVENT_SIGNATURE_ERROR, status )
   /* Deviation MISRA-2 */
   #define Coding_Call_DemEventWrongVehicle_SetEventStatus( status ) \
              Coding_DemReportErrorStatus( CODING_EVENT_WRONG_VEHICLE, status )
   /* Deviation MISRA-2 */
   #define Coding_Call_DemEventInvalidData_SetEventStatus( status ) \
              Coding_DemReportErrorStatus( CODING_EVENT_INVALID_DATA, status )

   /*** Crypto ****************************************************************/

   /*
    * Mapping of function to perform an asymmetric signature check.
    * The function shall calculate a signature over the coding data and compare
    * it with the given signature. If ok the function shall return CR_C_RC_OK.
    * If the function was canceled it should return CR_C_RC_CANCELED.
    */
   /* Deviation MISRA-2 */
   #define Coding_CryptoCheckSignatureAsym( pData, size, pSignature ) \
              Crypto_CheckSigNCD( (uint32)1, &pData, (CR_fpc_uint32)&size, (CR_fpc_uint32)pSignature, (uint16)0, (CR_fp_uint8)NULL_PTR )

   /*
    * Mapping of function to perform a symmetric signature check.
    * The function shall calculate a signature over the <size> bytes of <pData>
    * and compare it with <pSignature>.
    * If ok the function shall return CR_C_RC_OK.
    * If the function is canceled it should return CR_C_RC_CANCELED.
    */
   /* Deviation MISRA-2 */
   #define Coding_CryptoCheckSignatureSymm( pData, size, pSignature ) \
              Crypto_CheckSigNCDSymm( (uint32 const)1, &pData, (CR_fpc_uint32)&size, pSignature )

   /*
    * Crypto methods
    */
   #define CODING_CRYPTO_METHOD_ASYM   1
   #define CODING_CRYPTO_METHOD_SYMM   0

   /*
    * Crypto method used for signature checks
    */
   #define CODING_CRYPTO_METHOD   CODING_CRYPTO_METHOD_ASYM

   /*
    * Maximum size of all signature blocks
    */
   #define CODING_CRYPTO_SIGNATURE_SIZE_MAX   132

   /*** PIA *******************************************************************/

   /*
    * Mapping of function that notifies the PIA module about new coding data
    */
   #define Coding_PiaCodingNotification()

   /*** WaitUntilNvmReady() **************************************************/

   /*
    * Mapping of function that performs a synchronous wait
    * until NvM has finished the last job on the given block.
    */
   /* Deviation MISRA-2 */
   #define Coding_NvmWaitUntilBlockIsReady( block ) \
              Appl_WaitNvMReady( block, TRUE )

   /*** Coding_Required() *****************************************************/

   /*
    * Mapping of CodingRequired function.
    * The function shall return TRUE if the ECU has been started-up the first
    * time after reprogramming the SWEs via bootloader, otherwise FALSE
    */
   #define Coding_Required() \
              (BootProgData.ApplicStartedFirst == (uint8)ISFIRSTSTARTOFAPPLICATION)

   /*** Make32Bit() ***********************************************************/

   /*
    * Mapping of Make32Bit function.
    * The function shall concat the given bytes to a 32 bit integer value
    * with correct endianess for the current ECU
    */
   #define Coding_Make32Bit() \
              (Make32Bit( hiHiByte, hiLoByte, loHiByte, loLoByte ))

   /*** Memcopy() *************************************************************/

   /*
    * Mapping of memcpy function.
    * The function shall copy <size> bytes from <pSource> in ROM
    * to <pDest> in RAM
    */
   /* Deviation MISRA-2 */
   #define Coding_Memcopy( pDest, pSource, size ) \
              SC_MEMCPY_ROM( pDest, pSource, size )


#endif /* CODING_C                                                            */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*** Public Part (used by NvM) ************************************************/

   /*
    * Coding nv data type
    * Used to align coding nv data RAM mirror to 32 bit
    */
   /* Deviation MISRA-1 */
   typedef union
   {
      uint32 force32BitAlignment;
      uint8  data[SIZEOF_ALL_BLOCKS];
   } Coding_NvDataType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*** Public Part (used by NvM) ************************************************/

   /*
    * Coding nv data
    * The RAM mirror of NVM_CODING_DATA_BLOCK.
    * Size = size is all blocks + 7 bytes for the Coding proof stamp (CPS)
    */
   #define CODING_START_SEC_VAR_NO_INIT_NVDATA
   #include "MemMap.h"

   /* Deviation MISRA-1 */
   extern VAR(Coding_NvDataType, CODING_VAR_NVDATA) Coding_NvDataInternal;

   #define CODING_STOP_SEC_VAR_NO_INIT_NVDATA
   #include "MemMap.h"

   /*
    * Coding nv status
    * The RAM mirror of NVM_CODING_STATUS_BLOCK.
    * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
    */
   #define CODING_START_SEC_VAR_NO_INIT_NVDATA
   #include "MemMap.h"

   extern VAR(uint8, CODING_VAR_NVDATA) Coding_NvStatus[CODING_NVSTATUS_IDX];

   #define CODING_STOP_SEC_VAR_NO_INIT_NVDATA
   #include "MemMap.h"

   #define CODING_START_SEC_CONST_8BIT
   #include "MemMap.h"

   /*
    * Coding nv data defaults
    * Coding data default values used as ROM backup of NVM_CODING_DATA_BLOCK.
    * Size = size is all blocks + 7 bytes for the Coding proof stamp (CPS)
    */
   extern CONST( uint8, CODING_CONST ) Coding_NvDataDefaults[SIZEOF_ALL_BLOCKS];

   /*
    * Coding nv status defaults
    * Coding status default values used as ROM backup of NVM_CODING_STATUS_BLOCK.
    * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
    */
   extern CONST( uint8, CODING_CONST ) Coding_NvStatusDefaults[CODING_NVSTATUS_IDX];

   #define CODING_STOP_SEC_CONST_8BIT
   #include "MemMap.h"

/*** Private Part (used by Coding.c only) *************************************/
#ifdef CODING_C

 /*
  * Coding nv data defaults
  * Coding data default values used as ROM backup of NVM_CODING_DATA_BLOCK.
  * Size = size is all blocks + 7 bytes for the Coding proof stamp (CPS)
  */
  #define CODING_NVDATADEFAULTS_INIT \
  { \
    /* Area CodingDataSet1 */ \
    0X2,0X32,0X78,0X78, \
\
    /* Area CodingDataSet2 */ \
    0X0,0X0,0X0,0X0, \
\
    /* Area CodingDataSet3 */ \
    0X0,0X0,0X0,0X0, \
\
    /* Area CafId */ \
    0x05,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
\
    /* Area Signature */ \
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,\
\
    /* Coding proof stamp */ \
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF \
  }

/*
* Coding nv status defaults
* Coding status default values used as ROM backup of NVM_CODING_STATUS_BLOCK.
* Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
*/
#define CODING_NVSTATUSDEFAULTS_INIT \
      { \
         0x00, \
      }

#endif /* CODING_C                                                            */


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*** Private Part (used by Coding.c only) *************************************/
#ifdef CODING_C

   /*
    * Coding data offset type
    * Used to access data in Coding_NvData.
    * uint8 : if Coding_NvData is smaller than 256
    * uint16: if Coding_NvData is bigger than 255
    */
   typedef uint8 Coding_DataOffsetType;

   /*
    * Coding area descriptor table type
    */
   typedef struct
   {
      Coding_DataOffsetType dataOffsetOfFirstBlock;
      Coding_DataOffsetType dataOffsetOfSignatureBlock;
   } Coding_AreaDescriptorTableType;

   /*
    * Coding block descriptor table type
    */
   typedef struct
   {
      uint16                dataIdentifier;
      Coding_DataOffsetType dataOffset;
      uint8                 dataSize;
   } Coding_BlockDescriptorTableType;

#endif /* CODING_C                                                            */


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*** Private Part (used by Coding.c only) *************************************/
#ifdef CODING_C

   /*
    * Coding block descriptor table
    * The block descriptor table contains the following information for each block:
    * - diagnostic data identifier
    * - offset of the block in Coding_NvData array
    * - size of the block in bytes
    */
   #define CODING_BLOCK_DESCRIPTORTABLE_INIT \
      { \
         { /* Area CodingDataSet1 */ \
            0X3000, \
            0, \
            4 \
         }, \
         { /* Area CodingDataSet2 */ \
            0X3001, \
            4, \
            4 \
         }, \
         { /* Area CodingDataSet3 */ \
            0X3002, \
            8, \
            4 \
         }, \
         { /* Area CafId */ \
            0X3003, \
            12, \
            8 \
         }, \
         { /* Area Signature */ \
            0X3004, \
            20, \
            132 \
         }, \
         { /* Coding Proof Stamp (CPS) */ \
            0x37FE, \
            152, \
            7 \
         } \
      }

   /*
    * Coding area descriptor table
    * The area descriptor table contains the following offsets of the
    * Coding_NvData array for each area:
    * - offset of the first block
    * - offset of signature block
    */
   #define CODING_AREA_DESCRIPTORTABLE_INIT \
      { \
         { /* Area */ \
            0, \
            20 \
         }, \
      }

   /*
    * Coding nv status first write protection
    * Coding status first write protection values used for automatic write
    * protection of nv status after first writing of a coding block.
    * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
    */
   #define CODING_NVSTATUS_FIRST_WRITE_PROTECTION_INIT \
      { \
         0x00 /* b00000000 */ \
      }

#endif /* CODING_C                                                            */


#endif /* CODING_CFG_H                                                        */

/*** End of file **************************************************************/
