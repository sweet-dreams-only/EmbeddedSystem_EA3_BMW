@Echo Off
setlocal



set SWC=ParkAstEnbl

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PARKASTENBL=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PARKASTENBL=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PARKASTENBL%
mkdir %GENDEFDIR_PARKASTENBL%



copy ..\generate\Ap_ParkAstEnbl_*.arxml	%BSWMDDIR_PARKASTENBL%
copy ..\generate\Ap_ParkAstEnbl_*.tt	%GENDEFDIR_PARKASTENBL%
copy ..\generate\Ap_ParkAstEnbl_*.bat	%GENDEFDIR_PARKASTENBL%


pause
:end

endlocal

