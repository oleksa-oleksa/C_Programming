cmake_minimum_required(VERSION 3.6)
project(termincalendar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c datastructure.h datetime.c tools.h datetime.h calendar.c calendar.h menu.c menu.h tools.c
        database.c database.h sort.c escapesequenzen.h list.c list.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(termincalendar ${SOURCE_FILES})