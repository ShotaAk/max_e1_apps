# MAX-E1 Examples

## Build

```sh
$ cd max_e1_examples/
# Create a build tree
$ cmake -B build
# Build
$ cmake --build build
```

## Read example

MAX-E1のセンサデータ等を読み取るサンプルです。

```sh
$ export LD_LIBRARY_PATH=/usr/local/lib
$ ./build/read_example
MaxE1 init() is called.
Mode:2
Sensors init() is called.
Actuators init() is called.
Motions init() is called.

sensors->update() took 13913 microseconds.
sound_detecting_count:0
voltage:12.4
temperature:25
orientation_r:-0.39
orientation_p:-6.78
orientation_y:-7.96
gyro_x:3.84
gyro_y:-20.06
gyro_z:0.06
acc_x:0.116
acc_y:0.065
acc_z:1.017
```
