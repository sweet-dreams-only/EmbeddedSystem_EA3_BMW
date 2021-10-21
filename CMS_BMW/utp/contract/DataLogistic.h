/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
 
 
 #define SWECLASSIFICATIONLENGTH           1u
#define SWELOGISTICIDENTIFIERLENGTH       4u
#define SWESOFTWAREVERSIONLENGTH          3u

#define SGBM_ID_LENGTH ( SWECLASSIFICATIONLENGTH +                             \
                         SWELOGISTICIDENTIFIERLENGTH +                         \
                         SWESOFTWAREVERSIONLENGTH                              \
                       )
					   
#define NUMBEROFHWESGBMIDS                2u
#define HWEDEVELOPMENTINFOLENGTH          14u
#define ECUSERIALNUMBERLENGTH       10u
#define ECUMANUFACTURINGDATALENGTH    0x03u  

#define RANDOMLENGTH             16u 
#define FINGERPRINTLENGTH             13u 
#define VINLENGTH                17u 
 
 typedef struct
{
   /* --- logistic data ----------------------------------------------------- */
   uint8 HWESgbmId[SGBM_ID_LENGTH];

   /* --- HWE development Information --------------------------------------- */
#if (HWEDEVELOPMENTINFOLENGTH > 0u)
   uint8 HWEDevelopmentInfo[HWEDEVELOPMENTINFOLENGTH + 0x01u];
                                             /* ... plus one Byte length info */
#endif
} HweTableType;
 
 typedef struct
{
   /* HardwareLogisticData                                                    */
   HweTableType HweTable[NUMBEROFHWESGBMIDS];
   /* ECUSerialNumber                                                         */
   uint8 ECUSerialNumber[ECUSERIALNUMBERLENGTH];
   /* ECUManufacturingData                                                    */
   uint8 ECUManufacturingData[ECUMANUFACTURINGDATALENGTH];
} HwDescDataType;

 
 
 extern CONST(HwDescDataType, COMMON_CONST) HwDescData;
