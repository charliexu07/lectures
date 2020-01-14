cmake_minimum_required(VERSION 2.8)
project(lecture-03-examples)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
add_executable(system_call system_call.c)
