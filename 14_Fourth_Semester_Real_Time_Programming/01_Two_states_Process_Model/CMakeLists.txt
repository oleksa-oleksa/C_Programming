cmake_minimum_required(VERSION 3.7)
project(01_Two_states_Process_Model)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES queue.h queue.c process.c process.h queuedemo.c tools.c tools.h processmodel.h processmodel.c)
add_executable(01_Two_states_Process_Model ${SOURCE_FILES})
