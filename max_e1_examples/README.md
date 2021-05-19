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
```
