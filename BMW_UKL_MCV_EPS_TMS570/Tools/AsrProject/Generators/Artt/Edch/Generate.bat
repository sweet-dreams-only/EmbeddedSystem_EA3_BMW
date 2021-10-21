setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt

.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch.verify.tt                  		-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
if %ERRORLEVEL% NEQ 0 goto error

REM header files
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_Cfg.h.tt                  			-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_NvM_Cfg.h.tt                   	-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM src files
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_Gen.c.tt                   		-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_Gen.c.tt                   		-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM arxml files
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_ext_interface.arxml.tt     	-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_swc_interface.arxml.tt     	-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_swc_internal.arxml.tt      	-i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Edch\Edch_Constants.arxml.tt				-i=..\artt\include	-u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM delete template files
REM   del %TARGETDIR%\*.arxml

goto end

:error
ECHO Error: Edch configuration validation failed

:end

endlocal
