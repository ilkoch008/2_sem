cmake_minimum_required(VERSION 3.12)
project(shared_mem C)

set(CMAKE_C_STANDARD 11)

add_library(shared_mem library.c library.h)