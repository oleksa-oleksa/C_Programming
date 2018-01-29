cmake_minimum_required(VERSION 3.7)
project(05_PThread_Mutex)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c what_is_with_mutex.c.cpp my_strtok.c my_selfjoin.c)
add_executable(05_PThread_Mutex ${SOURCE_FILES})