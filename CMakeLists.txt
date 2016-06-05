cmake_minimum_required(VERSION 3.2)
project(pbt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("3rdparty/catch/include")

set(SOURCE_FILES main.cpp)
add_executable(pbt ${SOURCE_FILES})
