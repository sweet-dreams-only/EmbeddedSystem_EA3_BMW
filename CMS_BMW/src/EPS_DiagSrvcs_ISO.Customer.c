/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Customer.c file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains the source of functions for ISO services.
* This file is customer specific, so services will most likely change
* between programs.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#13.1.1 %
 * %derived_by:       rzmnk2 %
 * %date_modified:    Tue Jan 28 13:15:13 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/06/12 	1		KS		Initial Component Release
 * 12/06/12 	2		JJW		Include Non-Trusted/trusted function definitions
 * 12/11/12		3		KJS		Removed NtWrap.h from file. The function definitions are now included by the
 * 								extern statements in the interface header.
 * 04/12/13     5       JWJ     Added FEE1 - SVK block read/write
 * 04/12/13     6       JWJ     Added FEE0 - vehicle variant select                                             7884
 * 04/12/13		7		KJS		Added FEE2 and FEE3 serviecs
 * 01/18/14		8		KJS		Updates for QAC
 * 01/27/14		9		KJS		Added FEE4 support
 * 09/29/14		10		KJS		Added FEE5 support
 * 11/04/14		11		KJS		Added FEE6 support
 * 20/01/15		12		ABS		Added FEE7 support
 * 03/24/15		13		ABS		Added FEE8 support
 * 08/01/16   14    RMV   Updated FEE4 DID to check the range for first three bytes of Data for 2E service     6902
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "EPS_DiagSrvcs_ISO.h"
#include "EPS_DiagSrvcs_ISO.Customer.h"

#include "NvM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Source */

/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE0
 *
 *    PID ID:          0xFEE0
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     Variant Select
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE0 (VAR(uint8, EPSDIAGSRVCS_VAR) SubFunc_Cnt_T_u08, P2VAR(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) DataBuffer_Uls_T_u08, VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVCS_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        VAR(uint8, EPSDIAGSRVCS_VAR) VehicleVariant_Cnt_T_u08;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
            VehicleVariant_Cnt_T_u08 = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
            CmdResp_Cnt_T_u08 = CM_VehCfg_Scom_SetVariantSelect(VehicleVariant_Cnt_T_u08);
        }
        else
        {
            /* Read Service */
            CM_VehCfg_Scom_GetVariantSelect(&VehicleVariant_Cnt_T_u08);

            DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = VehicleVariant_Cnt_T_u08;
            ReturnDataIdx_Cnt_T_u16++;

            *RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16 - D_RETURNDATA_OFFSET_CNT_U16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE1
 *
 *    PID ID:          0xFEE1
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     SVK System Supplier Block
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE1 (VAR(uint8, EPSDIAGSRVCS_VAR) SubFunc_Cnt_T_u08, P2VAR(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) DataBuffer_Uls_T_u08, VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVCS_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        VAR(NvM_RequestResultType, EPSDIAGSRVCS_VAR) BlockStatus_Cnt_T_enum;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */

            /* Length check is performed in the MainHandler function so it is safe to assume 57 bytes of data here */
            (void)NvM_WriteBlock(NVM_BLOCK_SVK_SYS_SUPP, DataBuffer_Uls_T_u08);
            (void)Appl_WaitNvMReady(NVM_BLOCK_SVK_SYS_SUPP, TRUE);

            /* Check status to ensure write went okay */
            (void)NvM_GetErrorStatus(NVM_BLOCK_SVK_SYS_SUPP, &BlockStatus_Cnt_T_enum);
            if (BlockStatus_Cnt_T_enum != NVM_REQ_OK)
            {
                CmdResp_Cnt_T_u08 = D_EPSNRCCONDNOTCORRECT_CNT_U08;
            }
        }
        else
        {
            /* Read Service */
            (void)NvM_ReadBlock(NVM_BLOCK_SVK_SYS_SUPP, DataBuffer_Uls_T_u08);
            (void)Appl_WaitNvMReady(NVM_BLOCK_SVK_SYS_SUPP, TRUE);
            ReturnDataIdx_Cnt_T_u16 = RequestLen_Cnt_T_u16;

            *RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16 - D_RETURNDATA_OFFSET_CNT_U16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE2
 *
 *    PID ID:          0xFEE2
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     ECU Hardware Description Table
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE2 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        CONSTP2VAR(uint8, EPSDIAGSRVC_VAR, EPSDIAGSRVC_CONST)Buffer_T_ptr = (uint8*)(void*)(&HwDescData);
        VAR(uint16, EPSDIAGSRVC_VAR) Index_Cnt_T_u16;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
        	for (Index_Cnt_T_u16 = 0U; Index_Cnt_T_u16 < RequestLen_Cnt_T_u16; Index_Cnt_T_u16++)
        	{
        		Buffer_T_ptr[Index_Cnt_T_u16] = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        	    RequestDataIdx_Cnt_T_u16++;
        	}

        	(void)NvM_WriteBlock(NVM_BLOCK_HWDESCDATA, NULL_PTR);
        }
        else
        {
        	/* Read Service */
			for (Index_Cnt_T_u16 = 0U; Index_Cnt_T_u16 < D_HARDWAREDESCTBLPIDSIZE_CNT_U16; Index_Cnt_T_u16++)
			{
				DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = Buffer_T_ptr[Index_Cnt_T_u16];
				ReturnDataIdx_Cnt_T_u16++;
			}

			*RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
		}

		return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE3
 *
 *    PID ID:          0xFEE3
 *
 *    Configured NRCs: N/A
 *
 *    Description:     HWAP Update Service
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE3 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        VAR(uint32, EPSDIAGSRVC_VAR) HWAPDiagData_Cnt_T_u32;
        VAR(uint16, EPSDIAGSRVC_VAR) Index_Cnt_T_u16;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */

        	/* Note: This is the same service definition as Cdc_User FEE3. If any changes are made, please update both files. */

        	/* Read in data from service */
        	HWAPDiagData_Cnt_T_u32 = (uint32)((uint32)(DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16]) << 24u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16 + 1u]) << 16u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16 + 2u]) << 8u);
        	HWAPDiagData_Cnt_T_u32 |= (uint32)((uint32)(DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16 + 3u]));

        	/* Update HwDesc */
    		(void)memcpy( (uint8 *)&(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[D_HWAPSGBMNUM_CNT_U8]), (uint8 *)&(HWAPDiagData_Cnt_T_u32), D_HWAPSGBMNUMLEN_CNT_U8);
    		(void)NvM_WriteBlock(NVM_BLOCK_HWDESCDATA, NULL_PTR);
        }
        else
        {
            /* Read Service */
			for (Index_Cnt_T_u16 = D_HWAPSGBMNUM_CNT_U8; Index_Cnt_T_u16 < (D_HWAPSGBMNUMLEN_CNT_U8 + D_HWAPSGBMNUM_CNT_U8); Index_Cnt_T_u16++)
			{
				DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[Index_Cnt_T_u16];
				ReturnDataIdx_Cnt_T_u16++;
			}

            *RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE4
 *
 *    PID ID:          0xFEE4
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     Fingerprint Update Service
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE4 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
          /* Check whether the first three bytes are within the range specified (Sec 5.4 PID $FEE4 v 002A)*/ 
          if(((DataBuffer_Uls_T_u08[0] >= D_FIRSTBYTEFEE4LOWRANGE_CNT_U08) && (DataBuffer_Uls_T_u08[0] <= D_FIRSTBYTEFEE4HIGHRANGE_CNT_U08)) 	 	 
              && ((DataBuffer_Uls_T_u08[1] >= D_SECONDBYTEFEE4LOWRANGE_CNT_U08) && (DataBuffer_Uls_T_u08[1] <= D_SECONDBYTEFEE4HIGHRANGE_CNT_U08)) && 	 	 
              ((DataBuffer_Uls_T_u08[2] >= D_THIRDBYTEFEE4LOWRANGE_CNT_08) && (DataBuffer_Uls_T_u08[2] <= D_THIRDBYTEFEE4HIGHRANGE_CNT_08)))	 	 
          {
              /* Write Service */
        	  for (RequestDataIdx_Cnt_T_u16 = 0U; RequestDataIdx_Cnt_T_u16 < D_FINGERPRINTSIZE_CNT_U8; RequestDataIdx_Cnt_T_u16++)
        	  {
        	  	BootProgData.FingerPrint[RequestDataIdx_Cnt_T_u16] = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        	  }
            
        	  /* Write NvM Block */
        	  (void)NvM_WriteBlock(NVM_BLOCK_BOOT_PROG_DATA, NULL_PTR);
          }  
          else	 	 
          {	 	 
            /* Send Negative Response Request Out of Range */	 	 
            CmdResp_Cnt_T_u08 = D_EPSNRCREQOUTOFRANGE_CNT_U08;	 	 
          }
        }
        else
        {
            /* Read Service */
        	for (ReturnDataIdx_Cnt_T_u16 = 0U; ReturnDataIdx_Cnt_T_u16 < D_FINGERPRINTSIZE_CNT_U8; ReturnDataIdx_Cnt_T_u16++)
        	{
        		DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = BootProgData.FingerPrint[ReturnDataIdx_Cnt_T_u16];
        	}

        	*RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE5
 *
 *    PID ID:          0xFEE5
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     Boot Program Status Block
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE5 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) LoopCounter_Cnt_T_u08 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;

        /* While ICR 4643 called out for a fix length of 6 bytes, the memory block can vary in size depending on the configuration.
         * The code is implemented to handle any changes in size by the application, which will also impact the NvM definition to match. */

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
        	for (LoopCounter_Cnt_T_u08 = 0U; LoopCounter_Cnt_T_u08 < D_REQSIZEFLSHSEGSTATUS_CNT_U8; LoopCounter_Cnt_T_u08++)
        	{
        		BootProgStatus.FlashSegmentStatus[LoopCounter_Cnt_T_u08] = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        		RequestDataIdx_Cnt_T_u16++;
        	}

        	for (LoopCounter_Cnt_T_u08 = 0U; LoopCounter_Cnt_T_u08 < D_NUMBEROFALLSWES_CNT_U8; LoopCounter_Cnt_T_u08++)
        	{
        		BootProgStatus.SWEProgrammingStatus[LoopCounter_Cnt_T_u08] = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        		RequestDataIdx_Cnt_T_u16++;
        	}

        	BootProgStatus.lastProgrammedSegment = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];

        	/* Write NvM Block */
        	(void)NvM_WriteBlock(NVM_BLOCK_BOOT_PROG_STATUS, NULL_PTR);
        }
        else
        {
            /* Read Service */
        	for (LoopCounter_Cnt_T_u08 = 0U; LoopCounter_Cnt_T_u08 < D_REQSIZEFLSHSEGSTATUS_CNT_U8; LoopCounter_Cnt_T_u08++)
        	{
        		DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = BootProgStatus.FlashSegmentStatus[LoopCounter_Cnt_T_u08];
        		ReturnDataIdx_Cnt_T_u16++;
        	}

        	for (LoopCounter_Cnt_T_u08 = 0U; LoopCounter_Cnt_T_u08 < D_NUMBEROFALLSWES_CNT_U8; LoopCounter_Cnt_T_u08++)
        	{
        		DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = BootProgStatus.SWEProgrammingStatus[LoopCounter_Cnt_T_u08];
        		ReturnDataIdx_Cnt_T_u16++;
        	}

        	DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = BootProgStatus.lastProgrammedSegment;
        	ReturnDataIdx_Cnt_T_u16++;

        	*RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE6
 *
 *    PID ID:          0xFEE6
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     FEE Initialized Status
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE6 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        VAR(uint16, EPSDIAGSRVC_VAR) FeeInitFlg_Cnt_T_u16;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
        	Nxtr_FeeInitialized_Cnt_u8[0u] = ((DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16]));
        	Nxtr_FeeInitialized_Cnt_u8[1u] = ((DataBuffer_Uls_T_u08[(RequestDataIdx_Cnt_T_u16 + 1u)]));

            (void)NvM_WriteBlock(NVM_FEE_INITIALIZED, NULL_PTR);
        }
        else
        {
            /* Read Service */
        	DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = Nxtr_FeeInitialized_Cnt_u8[0u];
        	ReturnDataIdx_Cnt_T_u16++;
        	DataBuffer_Uls_T_u08[ReturnDataIdx_Cnt_T_u16] = Nxtr_FeeInitialized_Cnt_u8[1u];
        	ReturnDataIdx_Cnt_T_u16++;

            *RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE7
 *
 *    PID ID:          0xFEE7
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     SVK Lock Byte
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE7 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
        	if (D_SVKLOCKMAXVALUE_CNT_U08 < DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16])
        	{
        		CmdResp_Cnt_T_u08 = D_EPSNRCREQOUTOFRANGE_CNT_U08;
        	}
        	else
        	{
        		SvkHistoryMemory.SvkLockedStatus = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        		(void)NvM_WriteBlock(NVM_BLOCK_SVK_HISTORY, NULL_PTR);
        	}
        }
        else
        {
            /* Read Service */
        	DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16] = SvkHistoryMemory.SvkLockedStatus;
        	ReturnDataIdx_Cnt_T_u16++;

       		*RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/***********************************************************************************************************************
 *    Function Name:   EPSInternal_PID_FEE8
 *
 *    PID ID:          0xFEE8
 *
 *    Configured NRCs: MEC Counter Equals Zero (0xFB)
 *
 *    Description:     Motor Supplier Service
 *
 *    Inputs:          SubFunc_Cnt_T_u08    : Sub-function type - varies based on srvc type - see MainHandler function
 *                     DataBuffer_Uls_T_u08 : Buffer for request/response data
 *                     RequestLen_Cnt_T_u16 : Number of byte of request data in buffer when function is called
 *                     RespLength_Cnt_T_u16 : Variable pointer to hold the number of response bytes in buffer on return
 *
 *    Outputs:         CmdResp_Cnt_T_u08    : D_EPSNRCNOERROR_CNT_U08 if no error or appropriate NRC
 *
 **********************************************************************************************************************/
#if (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED)
    FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE8 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16)
    {
        /* Local Vars */
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) ReturnDataIdx_Cnt_T_u16 = 0U;
        VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestDataIdx_Cnt_T_u16 = 0U;
        VAR(uint8, EPSDIAGSRVC_VAR) CmdResp_Cnt_T_u08 = D_EPSNRCNOERROR_CNT_U08;
        VAR(uint8, EPSDIAGSRVC_VAR) MtrSuplrByte_Cnt_T_u8;

        if (SubFunc_Cnt_T_u08 == D_SRVCREQTYPEWRITE_CNT_U16)
        {
            /* Write Service */
        	MtrSuplrByte_Cnt_T_u8 = DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16];
        	if((MtrSuplrByte_Cnt_T_u8 == D_MTRSUPLRSERV_LETRIKA_CNT_U08) || (MtrSuplrByte_Cnt_T_u8 == D_MTRSUPLRSERV_TAIGENE_CNT_U08))
        	{
        		Nvm_MtrSuplrByte_Cnt_u8 = MtrSuplrByte_Cnt_T_u8;
        	}
        	else
        	{
        		Nvm_MtrSuplrByte_Cnt_u8 = D_MTRSUPLRSERV_DEFAULT_CNT_U08;
        	}
        	(void)NvM_WriteBlock(NVM_BLOCK_MTRSUPLR_SERVICE, NULL_PTR);
        }
        else
        {
            /* Read Service */
        	DataBuffer_Uls_T_u08[RequestDataIdx_Cnt_T_u16] = Nvm_MtrSuplrByte_Cnt_u8;
        	ReturnDataIdx_Cnt_T_u16++;

            *RespLength_Cnt_T_u16 = ReturnDataIdx_Cnt_T_u16;
        }

        return CmdResp_Cnt_T_u08;
    }
#endif /* (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/
