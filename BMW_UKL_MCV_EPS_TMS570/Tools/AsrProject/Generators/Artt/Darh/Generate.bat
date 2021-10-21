set ECUCFILE=%1
set TARGETDIR=%2

cd ..\artt


.\artt.exe -d=%ECUCFILE% -t=..\Darh\Darh_Cfg.tt                    -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%


goto end

:error

:end

endlocal


