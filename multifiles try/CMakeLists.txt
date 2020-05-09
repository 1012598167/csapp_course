cmake_minimum_required(VERSION 3.12)
project(multifiles_try C)

set(CMAKE_C_STANDARD 99)

add_executable(multifiles_try main.c print.c)