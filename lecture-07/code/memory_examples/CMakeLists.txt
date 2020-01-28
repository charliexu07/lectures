cmake_minimum_required(VERSION 2.8)
project(lecture-07-examples)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=gnu99")
add_executable(allocation allocation.c)
