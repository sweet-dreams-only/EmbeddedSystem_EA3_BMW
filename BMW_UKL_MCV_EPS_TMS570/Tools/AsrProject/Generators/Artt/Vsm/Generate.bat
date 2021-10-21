setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt


.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm.verify.tt                        -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
if %ERRORLEVEL% NEQ 0 goto error

.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm_Client_Cfg.c.tt                   -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Omc_Cfg.h.tt                          -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Stm_Cfg.h.tt                          -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm_Client_Cfg.h.tt                   -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\VsmFim_Cfg.h.tt                       -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Wur_Cfg.h.tt                          -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\ComControl_Cfg.h.tt                   -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Fnm_Cfg.h.tt                          -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm_Client_swc_interface.arxml.tt     -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm_Client_swc_internal.arxml.tt      -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Vsm\VsmSample_swc.arxml.tt                -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM delete template files
REM   del %TARGETDIR%\*.arxml

goto end

:error
ECHO Error: VSM configuration validation failed

:end

endlocal
