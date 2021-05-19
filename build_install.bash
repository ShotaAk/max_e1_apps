#!/usr/bin/bash -e

cd $(dirname $0)
DIR_MAX_E1_LIB=$(pwd)/max_e1_lib
DIR_MAX_E1_EXAMPLES=$(pwd)/max_e1_examples

echo "Build MAX-E1 Library"
cd $DIR_MAX_E1_LIB
cmake -B build
cmake --build build
echo "Install MAX-E1 Library"
sudo cmake --install build

echo "Build MAX-E1 examples"
cd $DIR_MAX_E1_EXAMPLES
cmake -B build
cmake --build build
