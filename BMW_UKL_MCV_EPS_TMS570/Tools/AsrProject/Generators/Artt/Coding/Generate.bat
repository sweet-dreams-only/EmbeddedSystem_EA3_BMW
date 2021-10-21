setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt

.\artt.exe -d=%ECUCFILE% -t=..\Coding\Coding.verify.tt                  -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
 if %ERRORLEVEL% NEQ 0 goto error

.\artt.exe -d=%ECUCFILE% -t=..\Coding\Coding_Cfg.h.tt                   -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Coding\Coding_swc_interface.arxml.tt     -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Coding\Coding_swc_internal.arxml.tt      -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM delete template files
REM   del %TARGETDIR%\*.arxml

goto end

:error
ECHO Error: CODING configuration validation failed

:end

endlocal
