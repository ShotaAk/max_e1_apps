# MAX-E1 CPP Applications

![Architecture](./resources/MAX-E1LibArchitecture.png)

[ROBOTIS ENGINEER KIT 1](https://www.rt-shop.jp/index.php?main_page=product_info&products_id=3892)
の2足歩行ロボット**MAX-E1**用の
C++ライブラリとアプリケーション集です。
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

### MAX-E1 Applicationsのビルド&インストール

```sh
$ git clone https://github.com/ShotaAk/max_e1_apps
$ cd max_e1_apps
$ ./build_install.bash
```

### MAX-E1 ライブラリのアンインストール

```sh
$ cd max_e1_apps
$ ./uninstall.bash
```

## サンプルの実行

max_e1_examplesの[README](./max_e1_examples/README.md)を参照。

## LICENSE

[Apache License 2.0](./LICENSE)

## References

- [ENGINEER Kit1 - ROBOTIS e-Manual](https://emanual.robotis.com/docs/en/edu/engineer/kit1/)
- [CM-550 - ROBOTIS e-Manual](https://emanual.robotis.com/docs/en/parts/controller/cm-550/)
- [DYNAMIXEL SDK - ROBOTIS e-Manual](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/overview/)
