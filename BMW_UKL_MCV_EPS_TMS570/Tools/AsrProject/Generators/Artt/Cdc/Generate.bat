rem Gesetlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt

.\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc.verify.tt        -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
 if %ERRORLEVEL% NEQ 0 goto error

.\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc_Cfg.h.tt         -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc_Dispatcher.c.tt  -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
rem .\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc_User.c.tt        -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
rem .\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc_User.h.tt        -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Cdc\Cdc_swc.arxml.tt     -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM rename files
Rem ren    %TARGETDIR%\Cdc_User.c.c Cdc_User.c
Rem ren    %TARGETDIR%\Cdc_User.h.h Cdc_User.h

REM delete template files
REM   del %TARGETDIR%\*.arxml
REM   del %TARGETDIR%\*.verify

goto end

:error
ECHO Error: CDC configuration validation failed

:end

endlocal
