cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(hello_max_e1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(a.out main.cpp)
target_link_libraries(a.out max_e1 dxl_x64_cpp)