cmake_minimum_required(VERSION 3.2)
project(pbt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DCATCH_CONFIG_NOSTDOUT")

include_directories ("3rdparty/catch/include")
include_directories ("3rdparty/cpp-quick-check/include")

set(SOURCE_FILES main.cpp ebt.cpp pbt.cpp 3rdparty/cpp-quick-check/src/Arbitrary.cpp)
add_executable(pbt ${SOURCE_FILES})
