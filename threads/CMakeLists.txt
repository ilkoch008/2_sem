cmake_minimum_required(VERSION 3.12)
project(threads C)

set(CMAKE_C_STANDARD 99)
find_package(Threads)
add_executable(threads main.c)

target_link_libraries(threads ${CMAKE_THREAD_LIBS_INIT})

