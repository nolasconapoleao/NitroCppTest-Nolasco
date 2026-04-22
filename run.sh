#!/bin/bash

#Debug binary
#Clean previous build
rm -rf build
mkdir build
cd build || exit
#Build binary
cmake -DCMAKE_BUILD_TYPE=Debug  ..
make all -j"$(nproc)"

#Run project executable
./Nitro