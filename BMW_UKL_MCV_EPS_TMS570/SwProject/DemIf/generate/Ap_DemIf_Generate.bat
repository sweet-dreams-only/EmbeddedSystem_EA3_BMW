setlocal

set ECUCFILE=%1
set TARGETDIR=%2
set SERVICESWCFOLDER=%3

cd ..\artt

.\artt.exe -d=%ECUCFILE% -t=..\DemIf\Ap_DemIf_NxtrAddon.arxml.tt				  -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%
.\artt.exe -d=%ECUCFILE% -t=..\DemIf\Ap_DemIf_NxtrAddon.h.tt					  -i=..\artt\include  -u="http://autosar.org/3.0.2"  -o=%TARGETDIR%

goto end

:error
ECHO Error: DemIf configuration validation failed

:end

endlocal
