@Echo Off
setlocal



set SWC=ElecPwr

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_ELECPWR=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_ELECPWR=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_ELECPWR%
mkdir %GENDEFDIR_ELECPWR%



copy ..\generate\Ap_ElecPwr_*.arxml	%BSWMDDIR_ELECPWR%
copy ..\generate\Ap_ElecPwr_*.tt	%GENDEFDIR_ELECPWR%
copy ..\generate\Ap_ElecPwr_*.bat	%GENDEFDIR_ELECPWR%


pause
:end

endlocal

