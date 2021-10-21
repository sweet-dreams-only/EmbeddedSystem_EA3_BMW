/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
#ifndef DATALOGISTIC_H
#define DATALOGISTIC_H

typedef struct
{
   uint8 HWESgbmId[8];
} HweTableType;

typedef struct
{
   /* HardwareLogisticData                                                    */
   HweTableType HweTable[16];
   /* ECUSerialNumber                                                         */
   uint8 ECUSerialNumber[16];
   /* ECUManufacturingData                                                    */
   uint8 ECUManufacturingData[16];
} HwDescDataType;

extern CONST(HwDescDataType, COMMON_CONST) HwDescData;

#endif /* DATALOGISTIC_H */
