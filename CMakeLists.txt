cmake_minimum_required(VERSION 3.31)
project(dangun_time C)

set(CMAKE_C_STANDARD 99)

add_library(dangun_time STATIC library.c)
