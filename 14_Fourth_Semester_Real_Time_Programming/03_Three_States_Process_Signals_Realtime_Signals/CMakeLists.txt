cmake_minimum_required(VERSION 3.7)
project(03_Three_States_Process_Signals_Realtime_Signals)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        queue.h queue.c process.c process.h tools.c tools.h processmodel.h processmodel.c process_simulation.c)

add_executable(03_Three_States_Process_Signals_Realtime_Signals ${SOURCE_FILES})