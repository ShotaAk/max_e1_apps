#!/usr/bin/bash -e

cd $(dirname $0)
DIR_MAX_E1_LIB=$(pwd)/max_e1_lib
DIR_HELLO_MAX_E1=$(pwd)/hello_max_e1

echo "Build MAX-E1 Library"
cd $DIR_MAX_E1_LIB
cmake -B build
cmake --build build
echo "Install MAX-E1 Library"
sudo cmake --install build

echo "Build hello_max_e1"
cd $DIR_HELLO_MAX_E1
cmake -B build
cmake --build build
