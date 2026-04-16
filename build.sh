#!/usr/bin/env bash

set -e

BUILD_TYPE=${1:-Debug}

echo "[INFO] Build type: $BUILD_TYPE"

mkdir -p build
cd build

cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE

cmake --build .

echo "[DONE] Built mycargo"