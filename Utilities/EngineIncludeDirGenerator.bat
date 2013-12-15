@echo off &setlocal

set DESTINATION=E:\GameDevelopment\Programming\^
StarEngine\StarEngine-downloads\Project\libs\^
StarEngine\include

robocopy %~dp0 %DESTINATION%\ *.h /mt:8
robocopy %~dp0jni\ %DESTINATION%\ *.h /s /mt:8
robocopy %~dp0jni\ %DESTINATION%\ *.inl /s /mt:8
	
del %DESTINATION%\resource.h

setlocal DisableDelayedExpansion
set "search=jni/"
set "replace="

set name=Window
set ext=.h

set file=%DESTINATION%\%name%%ext%
set fileCopy=%DESTINATION%\%name%Copy%ext%

set fileCopy=%DESTINATION%\WindowCopy.h
for /F "delims=*" %%a in ('findstr /n $ %file%') DO (
	set line=%%a
    setlocal EnableDelayedExpansion
	set "line=!line:*:=!"
	if defined line (
		>> %fileCopy% echo(!line:%search%=%replace%!
	) else (
		>> %fileCopy% echo(
	)
    endlocal
)

setlocal DisableDelayedExpansion
del %file%
setlocal EnableDelayedExpansion
ren %fileCopy% %name%%ext%