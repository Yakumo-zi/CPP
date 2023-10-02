cmake_minimum_required(VERSION 3.21)
project(minitcmalloc)

set(CMAKE_CXX_STANDARD 17)

add_executable(minitcmalloc main.cpp ObjectPool.h)
