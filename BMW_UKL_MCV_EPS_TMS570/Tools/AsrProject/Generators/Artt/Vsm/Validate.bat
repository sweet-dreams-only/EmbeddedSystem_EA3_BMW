setlocal

set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt


.\artt.exe -d=%ECUCFILE% -t=..\Vsm\Vsm.verify.tt                  -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
if %ERRORLEVEL% NEQ 0 goto error


goto end

:error
ECHO Error: VSM configuration validation failed

:end

endlocal
