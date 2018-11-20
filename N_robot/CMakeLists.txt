cmake_minimum_required(VERSION 3.12)
project(N_robot C)

set(CMAKE_C_STANDARD 99)
find_package(Threads)

add_executable(N_robot main.c)
target_link_libraries(N_robot ${CMAKE_THREAD_LIBS_INIT})