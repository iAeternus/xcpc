@echo off

set "DIR_NAME=build/tests"
set "EXE_NAME=better-utils-tests.exe"

if not exist "%DIR_NAME%" (
    echo The directory "%DIR_NAME%" does not exist.
) else (
    cd "%DIR_NAME%"
    if exist "%EXE_NAME%" (
        .\%EXE_NAME%
    ) else (
        echo The executable "%EXE_NAME%" was not found in the "%DIR_NAME%" directory.
    )
)