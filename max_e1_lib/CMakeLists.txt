cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(max_e1_lib VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(max_e1 SHARED
    src/max_e1_core.cpp
    src/max_e1_sensors.cpp
    src/max_e1.cpp
)

target_include_directories(max_e1
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

install(TARGETS max_e1 
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)