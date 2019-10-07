cmake_minimum_required(VERSION 3.10)
project(libst)

set(CMAKE_CXX_STANDARD 17)

add_library(libst INTERFACE)
add_executable(connection_state examples/connection_state.cpp)