#!/bin/bash

#Debug binary
#Clean previous build
rm -rf build
mkdir build
cd build || exit
#Build binary
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON ..
make all -j"$(nproc)"
make test -j
