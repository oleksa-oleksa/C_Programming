cmake_minimum_required(VERSION 3.7)
project(02_Fork_Child_Parent_Zombie_Processes)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES orphan_reaping.c tools.c zombie.c my_environ.c.c)
add_executable(02_Fork_Child_Parent_Zombie_Processes ${SOURCE_FILES})