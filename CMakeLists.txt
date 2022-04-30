cmake_minimum_required(VERSION 3.19)
project(fixcol C)

set(CMAKE_C_STANDARD 99)

add_library(fixcol.c fixcol.h)

add_executable(fixcol fixcol.c fixcol.h)