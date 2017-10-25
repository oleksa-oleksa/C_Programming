cmake_minimum_required(VERSION 3.7)
project(Real_Time_Programming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tasks.c
        tasks_header.h
        tasks_test.c)

add_executable(Real_Time_Programming ${SOURCE_FILES})