# MAX-E1 Applications

## Requirements

- Ubuntu 20.04
- gcc >= v5.4
- cmake >= v3.16

## Installation

### Dynamixel SDKのインストール

https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/library_setup/cpp_linux/#cpp-linux

```sh
$ sudo apt install build-essential
$ cd ~
$ git clone https://github.com/ROBOTIS-GIT/DynamixelSDK.git
$ cd ~/DynamixelSDK/c++/build/linux64
$ make
$ sudo make install
```

## References

- CMakeのチュートリアル
  - https://cmake.org/cmake/help/latest/guide/tutorial/index.html
  - ソース: https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial
  - 全然わからん

- CMakeのチュートリアル (Qiita)
  - https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
  - こっちのほうがわかりやすい！！！