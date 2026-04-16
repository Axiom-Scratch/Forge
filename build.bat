@echo off

set BUILD_TYPE=%1
if "%BUILD_TYPE%"=="" set BUILD_TYPE=Debug

echo [INFO] Build type: %BUILD_TYPE%

if not exist build mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=%BUILD_TYPE%

cmake --build .

echo [DONE] Built mycargo