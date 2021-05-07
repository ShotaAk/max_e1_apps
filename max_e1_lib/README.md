# MAX E1 Library

## Build & Install

```sh
$ ls
CMakeLists.txt  README.md max_e1_lib.cpp
# ビルドツリー作成
$ cmake -B build
# ビルド
$ cmake --build build
# インストール
$ sudo cmake --install build
```

## UnInstall

```sh
$ xargs sudo rm -rf < build/install_manifest.txt
```

## Run

```sh
$ cd build
$ ./max_e1_lib
```