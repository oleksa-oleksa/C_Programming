cmake_minimum_required(VERSION 3.6)
project(C_Programming)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c 00_Functions_Easy_Level.c 01_Functions_Middle_Level Add_without_plus_sign.c "Amount of different chars in text.c"
        exit.c reverseString.c exam_saveDays.c)
add_executable(C_Programming ${SOURCE_FILES})