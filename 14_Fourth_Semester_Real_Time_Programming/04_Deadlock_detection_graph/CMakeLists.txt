cmake_minimum_required(VERSION 3.7)
project(04_Deadlock_detection_graph)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES graph.c)
add_executable(04_Deadlock_detection_graph ${SOURCE_FILES})