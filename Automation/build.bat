@echo off

:: check if python is installed
python --version >nul 2>&1
if %errorlevel% NEQ 0 (
    echo "Python is not installed"
    exit /b 1
)


:: check arguments
if "%~1" == "" (
    echo "Usage: build.bat clean|generate|build_debug|build_release|clang-format"
    exit /b 1
)

python Automation/Automation.py %~1

pause
