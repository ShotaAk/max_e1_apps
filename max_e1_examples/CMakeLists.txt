cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(max_e1_examples VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(read_example read_example.cpp)
target_link_libraries(read_example max_e1 dxl_x64_cpp)