cmake_minimum_required(VERSION 3.12)
project(message_send C)

set(CMAKE_C_STANDARD 99)

add_executable(message_send main.c consts.h)