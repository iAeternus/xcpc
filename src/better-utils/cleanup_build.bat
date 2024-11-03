@echo off

set "BUILD_DIR=build"

if exist "%DIR_NAME%" (
    rmdir /S /Q "%DIR_NAME%"
    echo The 'build' directory has been deleted.
) else (
    echo The 'build' directory does not exist.
)