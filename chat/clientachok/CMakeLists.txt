cmake_minimum_required(VERSION 3.12)
project(clientachok C)

set(CMAKE_C_STANDARD 11)

add_executable(clientachok main.c)
target_link_libraries(clientachok pthread)