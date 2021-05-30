#!/bin/zsh -x
cd "$(dirname "$0")" || exit
export NODE=''

source ../emsdk/emsdk_env.sh
em++ \
    -s ENVIRONMENT=web,worker \
    -s STRICT=1 \
    -s WASM=1 \
    -s ASSERTIONS=0 \
    -s FILESYSTEM=0 \
    -s SINGLE_FILE=1 \
    -s EXPORT_ES6=1 \
    -s MODULARIZE=1 \
    -std=c++20 \
    -msimd128 \
    -O3 \
    -fno-exceptions \
    -flto \
    -pthread \
    --bind \
    --no-entry \
    -o src/wasm/PthreadTest.mjs \
    pthreadtest.cpp
