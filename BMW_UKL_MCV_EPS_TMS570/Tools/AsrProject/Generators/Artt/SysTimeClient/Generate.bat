setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt


.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient.verify.tt  -i=..\artt\include  -u="http://autosar.org/3.0.2"    -o=%TARGETDIR%
if %ERRORLEVEL% NEQ 0 goto error

.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient_Cfg.h.tt               -i=..\artt\include  -u="http://autosar.org/3.0.2" -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient_Wrapper.c.tt           -i=..\artt\include  -u="http://autosar.org/3.0.2" -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient_Wrapper.h.tt           -i=..\artt\include  -u="http://autosar.org/3.0.2" -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient_swc_interface.arxml.tt -i=..\artt\include  -u="http://autosar.org/3.0.2" -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\SysTimeClient\SysTimeClient_swc_internal.arxml.tt  -i=..\artt\include  -u="http://autosar.org/3.0.2" -o=%TARGETDIR%

REM delete template files
REM   del %TARGETDIR%\*.arxml

goto end

:error
ECHO Error:SYSTIMECLIENT configuration validation failed

:end

endlocal
