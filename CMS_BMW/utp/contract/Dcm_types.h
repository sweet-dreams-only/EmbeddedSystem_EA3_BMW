/* The following is only part of the header that was required at the 
 * time this component was made. 
 */

 
 typedef uint16       PduIdType;           /*The size of this global type depends on the maximum number of PDUs used within one software module.*/
   
typedef uint16       PduLengthType;       /*The size of this global type depends on the maximum length of PDUs to be sent by an ECU.*/


typedef  P2VAR(uint8, TYPEDEF, AUTOSAR_COMSTACKDATA) SduDataPtrType;
typedef struct
{
   SduDataPtrType SduDataPtr;
   PduLengthType SduLength;
}PduInfoType;
 
 
typedef uint8 Dcm_ProtocolType;

/*! \struct Dcm_MsgAddInfoType
 *  \brief  Additional information on message request
 *
 *  \param  uint8 reqType ;             physical or functional request
 *  \param  uint8 suppressPosResponse;  1 for suppression of response
 */
typedef struct{
 unsigned int reqType:1;            /* physical or functional request*/
 unsigned int suppressPosResponse:1; /* 1 for suppression*/
}Dcm_MsgAddInfoType;

/*!
* \brief Type for one message item
*/
typedef uint8             Dcm_MsgItemType;

/*!
* \brief Message type
*/
typedef P2VAR(Dcm_MsgItemType,AUTOMATIC,DCM_VAR)  Dcm_MsgType ;

/*!
* \brief Type for the message length
*/
typedef uint16            Dcm_MsgLenType;     

/*!
* \brief Type for the IdContext
*/
typedef uint8             Dcm_IdContextType;

/*! \struct Dcm_MsgContextType
 *  \brief Data structure contains all information to process a diagnostic message
 * 
 *  \param Dcm_MsgType reqData;            this contains information about the received data
 *  \param Dcm_MsgLenType   reqDataLen;      Request data length 
 *  \param Dcm_MsgType resData;            this will contain the response data
 *  \param Dcm_MsgLenType   resDataLen;      Response data length
 *  \param Dcm_MsgAddInfoType   msgAddInfo;  Additional Information
 *  \param Dcm_MsgLenType   resMaxDataLen;   Maximal length of response
 *  \param Dcm_IdContextType idContext;    Message context identifier
 *  \param PduIdType    dcmRxPduId;          Pdu identifier which request was received
 */
typedef struct{
 Dcm_MsgType        reqData;         /* Pointer to requested data*/
 Dcm_MsgLenType     reqDataLen;      /* Request data length*/
 Dcm_MsgType        resData;         /* Pointer to response data*/
 Dcm_MsgLenType     resDataLen;      /* Response data length*/
 Dcm_MsgAddInfoType msgAddInfo;      /* Additional Information*/
 Dcm_MsgLenType     resMaxDataLen;   /* Maximal length of response*/
 Dcm_IdContextType  idContext;       /* Message context identifier*/
 PduIdType          dcmRxPduId;      /* Pdu identifier which request was received*/
}Dcm_MsgContextType;
 
 
 typedef uint8 Dem_ReturnClearDTCType;
 typedef uint8 Dem_DTCOriginType;
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(
   Dem_DTCType         DTC,
   Dem_DTCKindType     DTCKind,
   Dem_DTCOriginType   DTCOrigin);