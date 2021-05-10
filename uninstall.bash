#!/usr/bin/bash -e

cd $(dirname $0)
DIR_MAX_E1_LIB=$(pwd)/max_e1_lib

echo "Uninstall MAX-E1 Library"
cd $DIR_MAX_E1_LIB
xargs sudo rm -rf < build/install_manifest.txt