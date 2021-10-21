#ifndef F021_H
#define F021_H

typedef enum
{
   Fapi_Status_Success=0,           /* Function completed successfully */
   Fapi_Status_FsmBusy,             /* FSM is Busy */
   Fapi_Status_FsmReady,            /* FSM is Ready */
   Fapi_Error_Fail,                 /* Generic Function Fail code */
   Fapi_Error_NullPointer,          /* One of the pointer parameters is a null pointer */
   Fapi_Error_InvalidCommand,       /* Command used is invalid for the function called */
   Fapi_Error_InvalidEccAddress,    /* Returned if the ECC Address given to a function is invalid for that function */
   Fapi_Error_OtpChecksumMismatch,  /* Returned if OTP checksum does not match expected value */
   Fapi_Error_InvalidHclkValue,     /* Returned if FClk is above max FClk value - FClk is a calculated from HClk and 
                                       RWAIT/EWAIT */
   Fapi_Error_InvalidBank,          /* Returned if the specified bank does not exist */
   Fapi_Error_InvalidAddress,       /* Returned if the specified Address does not exist in Flash or OTP */
   Fapi_Error_InvalidReadMode,      /* Returned if the specified read mode does not exist */
   Fapi_Error_AsyncIncorrectDataBufferLength,   /* Returned if Data buffer size specified exceeds Data bank width */
   Fapi_Error_AsyncIncorrectEccBufferLength,    /* Returned if ECC buffer size specified exceeds ECC bank width */
   Fapi_Error_AsyncDataEccBufferLengthMismatch, /* Returned if Data buffer size either is not 64bit aligned or Data
                                                   length exceeds amount ECC supplied */
   Fapi_Error_FeatureNotAvailable  /* FMC feature is not available on this device */
}  Fapi_StatusType;

Fapi_StatusType Fapi_serviceWatchdogTimer(void);

#endif  /* F021_H */
