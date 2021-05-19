# MAX E1 Library

## Build & Install

```sh
$ ls
CMakeLists.txt  README.md max_e1_lib.cpp
# Create a build tree
$ cmake -B build
# Build
$ cmake --build build
# Install
$ sudo cmake --install build
```

## UnInstall

```sh
$ xargs sudo rm -rf < build/install_manifest.txt
```
