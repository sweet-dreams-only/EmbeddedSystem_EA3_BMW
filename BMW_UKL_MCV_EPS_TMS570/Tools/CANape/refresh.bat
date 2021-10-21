@Echo off
REM ****************************************************************************
REM * This bat-file performs the necessary a2l update steps:
REM *  1) Copy partial a2l files from various locations into partial a2l dir
REM *  2) TBC - Export single a2l file from all the partial files
REM * Written by Nxtr
REM ****************************************************************************

SET CONFIGNAME=%1%
SET RTEA2L_GENDIR="..\..\SwProject\Source\GenDataRte"
SET DATADICTA2L_GENDIR="..\..\SwProject\Source\GenData"
SET PARTA2L_DESTDIR="Partial_A2L"

REM *************************** Copy Out File and Rename ***********************
del *.out
copy ..\..\SwProject\%CONFIGNAME%\*.out %CD%

REM *************************** Copy Partial a2l Files *************************

copy %DATADICTA2L_GENDIR%\*.a2l %PARTA2L_DESTDIR%


IF (%CONFIGNAME%)==(z_Metrics_CpuUsage) (
	copy %RTEA2L_GENDIR%\Metrics\*.a2l %PARTA2L_DESTDIR%
) ELSE (
	copy %RTEA2L_GENDIR%\Production\*.a2l %PARTA2L_DESTDIR%
)

REM **************** END *******************************************************
