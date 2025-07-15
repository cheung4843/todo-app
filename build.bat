@echo off
REM ==== Check and create build directory ====
if not exist build (
    mkdir build
)

REM ==== Enter build directory ====
cd build

REM ==== Clean old CMake cache and files ====
IF EXIST CMakeCache.txt (
    del /Q CMakeCache.txt
)
IF EXIST CMakeFiles (
    rmdir /S /Q CMakeFiles
)

REM ==== Run CMake to generate Makefile ====
cmake .. -G "MinGW Makefiles"
IF ERRORLEVEL 1 (
    echo [ERROR] CMake configuration failed!
    cd ..
    exit /b 1
)

REM ==== Build project ====
mingw32-make
IF ERRORLEVEL 1 (
    echo [ERROR] Build failed!
    cd ..
    exit /b 1
)

REM ==== Ask to run unit test ====
set /p runTest=Do you want to run unit tests (test_todo.exe)? [y/N]:
if /i "%runTest%"=="y" (
    echo Running unit tests...
    test_todo.exe
    echo.
)

REM ==== Ask to run main program ====
set /p runMain=Do you want to run main program (todo.exe)? [y/N]:
if /i "%runMain%"=="y" (
    echo Running main program...
    todo.exe
    echo.
)

REM ==== Return to project root directory ====
cd ..
echo ===== Build process finished =====
pause
