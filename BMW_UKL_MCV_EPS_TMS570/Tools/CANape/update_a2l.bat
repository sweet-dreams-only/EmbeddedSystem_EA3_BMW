@Echo off
REM ****************************************************************************
REM * This bat-file performs the necessary a2l update steps:
REM *  1) Copy partial a2l files from various locations into partial a2l dir
REM *  2) TBC - Export single a2l file from all the partial files
REM * Written by Nxtr
REM ****************************************************************************

REM **** The output of the build process is assumed to be placed in a directory named CONFIGNAME ******
SET CONFIGNAME=%1%
SET ARTIFACT_BASENAME=%2%

REM ********* Launch refresh bat file in another command instance so that this continues on failure ********
CMD /C refresh %CONFIGNAME%

REM ********* Ensure that the Canape directory is writable to prevent errors during CANape execution ************
REM ********* CANape execution requires write access to things such as the INI files and A2l files   ************
ATTRIB -R /S


IF (%CONFIGNAME%)==(z_Metrics_CpuUsage) (
	REM ***  launch CANape passing the script and the arguments to update the A2L file ***
	REM ***  The -q "silent" mode is desired to eliminate user interaction during the build process  ***

	canape32 -o -q -bc update_a2l.cns "%CONFIGNAME% %ARTIFACT_BASENAME%"
) ELSE (
	REM *** Create Empty Metrics.a2l file for production build since none of the measurement values are present ***

	REN .\Partial_A2L\Metrics.a2l Metrics.a2l.bak
@ECHO on
	ECHO 2>.\Partial_A2L\Metrics.a2l
@ECHO off
	REM ***  launch CANape passing the script and the arguments to update the A2L file ***
	REM ***  The -q "silent" mode is desired to eliminate user interaction during the build process  ***
	
	canape32 -o -q -bc update_a2l.cns "%CONFIGNAME% %ARTIFACT_BASENAME%"
	DEL .\Partial_A2L\Metrics.a2l
	REN .\Partial_A2L\Metrics.a2l.bak Metrics.a2l	
)

pause
REM **************** END *******************************************************
