setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt


.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem.verify.tt                  -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
 if %ERRORLEVEL% NEQ 0 goto error


.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Api_Cfg.h.tt               -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Api_Cfg_Specific.h.tt      -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Cfg.c.tt                   -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Cfg_Specific.c.tt          -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Internal_Cfg.h.tt          -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_Internal_Cfg_Specific.h.tt -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_swc_interface.arxml.tt     -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\Dem\Dem_swc_internal.arxml.tt      -i=..\artt\include;..\helper -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

REM delete template files
REM   del %TARGETDIR%\*.arxml

goto end

:error
ECHO Error: DEM configuration validation failed

:end

endlocal
