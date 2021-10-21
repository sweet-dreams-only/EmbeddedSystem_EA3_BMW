/* The following is only part of the header that was required at the 
 * time this component was made. 
 */

#ifndef AP_DIAGMGR_H
#define AP_DIAGMGR_H

 typedef struct
{
  UInt8 NTC_Cnt_u08;
  UInt8 Param_Cnt_u08;
  UInt8 SystemState_Cnt_u08;
  UInt8 VehSpd_Kph_u8p0;
  UInt32 BlkBoxCfgData1;
  UInt32 BlkBoxCfgData2;
  UInt32 BlkBoxCfgData3;
  SInt16 HwTrq_HwNm_s4p11;
  SInt16 MtrTrq_MtrNm_s4p11;
  UInt16 IgnCtr_Cnt_u16;
} NTCBlkBoxType;

typedef NTCBlkBoxType NTCBlkBoxData[8];

 /* DiagMgr NvM Data */
extern NTCStrgArray NTCStrgArray_Cnt_str;
extern NTCBlkBoxData NTCBlackBoxData_Cnt_str;

#endif /* AP_DIAGMGR_H */
