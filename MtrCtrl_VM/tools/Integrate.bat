@Echo Off
setlocal



set SWC=CurrentEst

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_CURRENTEST=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_CURRENTEST=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_CURRENTEST%
mkdir %GENDEFDIR_CURRENTEST%



copy ..\generate\Ap_CurrentEst_*.arxml	%BSWMDDIR_CURRENTEST%
copy ..\generate\Ap_CurrentEst_*.tt	%GENDEFDIR_CURRENTEST%
copy ..\generate\Ap_CurrentEst_*.bat	%GENDEFDIR_CURRENTEST%



set SWC=ParamComp

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PARAMCOMP=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PARAMCOMP=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PARAMCOMP%
mkdir %GENDEFDIR_PARAMCOMP%



copy ..\generate\Ap_ParamComp_*.arxml	%BSWMDDIR_PARAMCOMP%
copy ..\generate\Ap_ParamComp_*.tt	%GENDEFDIR_PARAMCOMP%
copy ..\generate\Ap_ParamComp_*.bat	%GENDEFDIR_PARAMCOMP%



set SWC=PhaseCtrl

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PHASECTRL=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PHASECTRL=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PHASECTRL%
mkdir %GENDEFDIR_PHASECTRL%



copy ..\generate\Ap_PhaseCtrl_*.arxml	%BSWMDDIR_PHASECTRL%
copy ..\generate\Ap_PhaseCtrl_*.tt	%GENDEFDIR_PHASECTRL%
copy ..\generate\Ap_PhaseCtrl_*.bat	%GENDEFDIR_PHASECTRL%



set SWC=QuadDet

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_QUADDET=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_QUADDET=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_QUADDET%
mkdir %GENDEFDIR_QUADDET%



copy ..\generate\Ap_QuadDet_*.arxml	%BSWMDDIR_QUADDET%
copy ..\generate\Ap_QuadDet_*.tt	%GENDEFDIR_QUADDET%
copy ..\generate\Ap_QuadDet_*.bat	%GENDEFDIR_QUADDET%



set SWC=TrqCmdScl

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TRQCMDSCL=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TRQCMDSCL=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TRQCMDSCL%
mkdir %GENDEFDIR_TRQCMDSCL%



copy ..\generate\Ap_TrqCmdScl_*.arxml	%BSWMDDIR_TRQCMDSCL%
copy ..\generate\Ap_TrqCmdScl_*.tt	%GENDEFDIR_TRQCMDSCL%
copy ..\generate\Ap_TrqCmdScl_*.bat	%GENDEFDIR_TRQCMDSCL%



set SWC=VltgCtrl

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_VLTGCTRL=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_VLTGCTRL=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_VLTGCTRL%
mkdir %GENDEFDIR_VLTGCTRL%



copy ..\generate\Ap_VltgCtrl_*.arxml	%BSWMDDIR_VLTGCTRL%
copy ..\generate\Ap_VltgCtrl_*.tt	%GENDEFDIR_VLTGCTRL%
copy ..\generate\Ap_VltgCtrl_*.bat	%GENDEFDIR_VLTGCTRL%


pause
:end

endlocal

