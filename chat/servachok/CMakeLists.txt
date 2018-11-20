cmake_minimum_required(VERSION 3.12)
project(servachok C)

set(CMAKE_C_STANDARD 11)

add_executable(servachok main.c)
target_link_libraries(servachok pthread)