/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Base32.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the Base32 routines                           **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              Base32 algorithm.                                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 20.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Base32.h"                  /* declarations of base32 services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
#define makeMask(bit_count) \
                          ((uint8)((uint8)((uint8)1 << (bit_count)) - (uint8)1))

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

SWT_STATIC_FUNC void Swt_Base32AddBits
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   P2VAR(uint16,AUTOMATIC,SC_FAR) BitsDecoded,
   uint8 Bits
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       External Constants                                   **
*******************************************************************************/

/*******************************************************************************
**                       External Data                                        **
*******************************************************************************/

/*******************************************************************************
**                       Local Constants                                      **
*******************************************************************************/

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_Base32Decode                                        **
**                                                                            **
** DESCRIPTION    : Decoding base32 coded data.                               **
**                                                                            **
** PRECONDITIONS  : 'EncodedData' shall be a valid pointer (not checked)      **
**                  'Data' shall be a valid pointer (not checked)             **
**                  'Data' shall point to at least 'DataLen' bytes of         **
**                  writable memory (not checked)                             **
**                  'DataLength' shall be a valid pointer (not checked)       **
**                                                                            **
** POSTCONDITIONS : Data contains decoded data, DataLen holds the number of   **
**                  used bytes for decoding.                                  **
**                                                                            **
** PARAMETER      : EncodedData : Pointer to the base32 encoded data          **
**                : EncodedDataLength : Number of bytes encoded               **
**                : Data: Pointer to the decoded data                         **
**                : DataLength : Number of bytes decoded                      **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if DataLength is to small or          **
**                       EncodedData contains non valid base32 character      **
**                  Swt_RC_OK, if the decoding was successful               **
**                                                                            **
** TIMING         : The timing is proportional to the number of bytes of      **
**                  input data.                                               **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_Base32Decode
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) EncodedData,
   uint16 EncodedDataLength,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   P2VAR(uint16,AUTOMATIC,SC_FAR) DataLength
)
{
   SwtRC_t RetVal;
   uint16 BitsDecoded = 0;
   uint16 Length;
   uint16 i;

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if ( 0 == EncodedData || 0 == Data || 0 == DataLength )
   {
      RetVal = Swt_RC_BAD_PARAM;
   }
   else
   {
      RetVal = Swt_RC_OK;
   }

   if ( Swt_RC_OK == RetVal )
#endif
   {
      /* length of decoded data                                               */
      Length = (uint16)((EncodedDataLength * (uint16)5) >> 3);

      /* check if provided output buffer is large enough                      */
      if ( (Length > *DataLength) || (0 == *DataLength) )
      {
         RetVal = Swt_RC_BAD_PARAM;
      }
      else
      {
         RetVal = Swt_RC_OK;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* set data output data to zero                                         */
      for (i=0; i < Length; i++)
      {
         Data[i]=0;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      i = 0;

      while ( ( (i < EncodedDataLength)   &&
                (RetVal == Swt_RC_OK) ) &&
                (EncodedData[i] != '=') )
      {
         if ( (EncodedData[i] >= 'A') && (EncodedData[i] <= 'Z') )
         {
            Swt_Base32AddBits(Data,
                                &BitsDecoded,
                                (uint8)(EncodedData[i] - 'A'));
         }
         else if ( (EncodedData[i] >= 'a') && (EncodedData[i] <= 'z') )
         {
            Swt_Base32AddBits(Data,
                                &BitsDecoded,
                                (uint8)(EncodedData[i] - 'a'));
         }
         else if ( (EncodedData[i] >= '2') && (EncodedData[i] <= '7') )
         {
            Swt_Base32AddBits(Data,
                                &BitsDecoded,
                                (uint8)(EncodedData[i] - (uint8)24));
         }
         else
         {
            /* invalid base32 character                                       */
            RetVal = Swt_RC_BAD_PARAM;
         }

         i++;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* set decoded data length                                              */
      *DataLength = BitsDecoded >> 3;
   }

   return RetVal;
}

/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_Base32AddBits                                       **
**                                                                            **
** DESCRIPTION    : Decoding base32 coded data bytewise.                      **
**                                                                            **
** PRECONDITIONS  : 'Data' shall be a valid pointer (not checked)             **
**                  'BitsDecoded' shall be a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : Data contains decoded data, BitsDecoded holds the         **
**                  bit position of the decoded data.                         **
**                                                                            **
** PARAMETER      : Data : Pointer to the decoded data                        **
**                : BitsDecoded : bit position of the decoded data            **
**                : Bits: base32 encoded byte                                 **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_Base32AddBits
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   P2VAR(uint16,AUTOMATIC,SC_FAR) BitsDecoded,
   uint8 Bits
)
{
   uint8 BitsToFirstByte;
   uint8 BitsToSecondByte;
   uint8 ShiftCount;
   uint8 SelectedBits;
   uint8 ShiftSelect;
   uint16 Index;

   /* calculate number of shifts for first byte                               */
   ShiftCount = (uint8)8 - (uint8)(*BitsDecoded % (uint16)8);

   /* check if shift is neccessary in second byte                             */
   if (ShiftCount > (uint8)5)
   {
      BitsToFirstByte = (uint8)5;
   }
   else
   {
      BitsToFirstByte = ShiftCount;
   }

   /* calculate shift for masking data for first byte                         */
   ShiftSelect = (uint8)5 - BitsToFirstByte;

   /* bit position in output byte (first)                                     */
   ShiftCount -= BitsToFirstByte;

   /* calculate Index for byte position                                       */
   Index = *BitsDecoded >> (uint16)3;

   /* mask input bits for first byte                                          */
   SelectedBits = (uint8)( Bits &
                           (uint8)(makeMask(BitsToFirstByte) << ShiftSelect) )
                  >> ShiftSelect;

   /* join first byte                                                         */
   Data[Index] |= (uint8)(SelectedBits << ShiftCount);

   /* increase bits decoded                                                   */
   *BitsDecoded += (uint16)BitsToFirstByte;

   /* calculate shift for masking data for second byte                        */
   BitsToSecondByte = ShiftSelect;

   /* bit position in output byte (second)                                    */
   ShiftCount = (uint8)8 - BitsToSecondByte;

   /* second byte */
   Index++;

   /* mask input bits for second byte                                         */
   SelectedBits = Bits &
                  (uint8)((uint8)(makeMask(BitsToSecondByte) << ShiftSelect)
                                 >> ShiftSelect);

   /* join second byte                                                        */
   Data[Index] |= (uint8)(SelectedBits << ShiftCount);

   /* increase bits decoded                                                   */
   *BitsDecoded += (uint16)BitsToSecondByte;
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
