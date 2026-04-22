#!/bin/bash

#Debug binary
#Clean previous build
rm -rf build
mkdir build
cd build || exit
#Build binary
cmake -DCMAKE_BUILD_TYPE=Debug  ..
make all -j"$(nproc)"

#Release binary
# #Clean previous build
# cd .. || exit
# rm -rf build-r
# mkdir build-r
# cd build-r || exit
# #Build  binary
# cmake -DCMAKE_BUILD_TYPE=Release  ..
# make all -j"$(nproc)"

#Run project executable
./Nitro