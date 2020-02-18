cmake_minimum_required(VERSION 2.8)
project(lecture-12-examples)
find_package (Threads)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -g")
add_executable(producer_consumer producer_consumer.c)
add_executable(thread_struct_example thread_struct_example.c)
target_link_libraries (producer_consumer ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (thread_struct_example ${CMAKE_THREAD_LIBS_INIT})
