# MAX-E1 Examples

## Build

```sh
$ cd max_e1_examples/
# Create a build tree
$ cmake -B build
# Build
$ cmake --build build
```

## Sensors example

MAX-E1のセンサデータを読み取るサンプルです。

```sh
$ export LD_LIBRARY_PATH=/usr/local/lib
$ ./build/sensors_example
...
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
...
```

## Actuators example

MAX-E1のアクチュエータを動かすサンプルです。

```sh
$ export LD_LIBRARY_PATH=/usr/local/lib
$ ./build/actuators_example
...
LED on: R
LED on: G
LED on: B
LED on: RG
LED on: GB
LED on: RB
LED on: RGB
LED off
Play scale 0, 3.0 seconds.
Play scale 1, 2.0 seconds.
Play scale 2, 1.0 seconds.
Play melody: 0
Play melody: 1
Play melody: 2
Play melody: 3
...
```

## Motions example

MAX-E1に書き込んだMotionを再生するサンプルです。

下記のMotion Indexを使用します

| Index | Motion |
| :---: | :---:  |
|  4 | 直立して、上半身を前後に揺らす |
| 18 | 左足を前に出す |
| 20 | 右足、左足を順番に出して正面に歩く |
| 22 | 右足を前に出して止まる |
| 23 | 左足を後に出す |
| 25 | 右足、左足を順番に出して真後に歩く |
| 27 | 右足を後に出して止まる |

```sh
$ export LD_LIBRARY_PATH=/usr/local/lib
$ ./build/motions_example
...
Move forward
Move backward
Stop a play immediately
Stop a play at keyframe
Stop a play at unit
```
