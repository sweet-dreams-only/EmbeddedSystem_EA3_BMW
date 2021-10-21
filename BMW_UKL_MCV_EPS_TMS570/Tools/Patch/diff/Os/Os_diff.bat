@Echo off
REM ****************************************************************************
REM * This script updates the diff description files required by the Os_patch.bat script.
REM *	INPUTS - Original generated files:
REM *	osobjs.inc.bak
REM *	osobjs_init.inc.bak
REM *	intvect.asm.bak
REM *
REM *	INPUTS - Corrected files:
REM *	osobjs.inc
REM *	osobjs_init.inc
REM *	intvect.asm
REM *
REM *	OUTPUTS:
REM *	osobjs.inc.diff
REM *	osobjs_init.inc.diff
REM *	intvect.asm.diff
REM *
REM *  The original and corrected files must be present in the Os generation directory
REM ****************************************************************************
REM /*---------------------------------------------------------------------------
REM * Version Control:
REM * Date Created:      Wed Oct 20 16:33:22 2012
REM * %version:          3 %
REM * %derived_by:       xz0btk %
REM * %date_modified:    Sat Oct 27 09:18:50 2012 %
REM *---------------------------------------------------------------------------*/


SET GNU_PATH=%cd%\..\..\..\GnuWin32\bin
SET SRC_PATH=..\..\..\..\SwProject\Source\GenDataOS

%GNU_PATH%\diff -u %SRC_PATH%\osobjs.inc.bak %SRC_PATH%\osobjs.inc > osobjs.inc.diff
%GNU_PATH%\diff -u %SRC_PATH%\osobjs_init.inc.bak %SRC_PATH%\osobjs_init.inc > osobjs_init.inc.diff
%GNU_PATH%\diff -u %SRC_PATH%\intvect.asm.bak %SRC_PATH%\intvect.asm > intvect.asm.diff
 pause
 