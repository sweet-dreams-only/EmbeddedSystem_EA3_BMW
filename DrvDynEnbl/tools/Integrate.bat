@Echo Off
setlocal



set SWC=DrvDynEnbl

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_DRVDYNENBL=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_DRVDYNENBL=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_DRVDYNENBL%
mkdir %GENDEFDIR_DRVDYNENBL%



copy ..\generate\Ap_DrvDynEnbl_*.arxml	%BSWMDDIR_DRVDYNENBL%
copy ..\generate\Ap_DrvDynEnbl_*.tt	%GENDEFDIR_DRVDYNENBL%
copy ..\generate\Ap_DrvDynEnbl_*.bat	%GENDEFDIR_DRVDYNENBL%


pause
:end

endlocal

