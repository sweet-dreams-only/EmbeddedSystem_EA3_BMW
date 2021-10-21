/* XcpProf.h for QAC */

  #define kXcp_Control_Disable   0x00u
  #define kXcp_Control_Enable    0x01u
  
  extern FUNC(void, XCP_CODE) XcpControl( uint8 command );