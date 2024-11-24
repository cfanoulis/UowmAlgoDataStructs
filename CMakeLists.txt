cmake_minimum_required(VERSION 3.29)
project(Ergasia1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Ergasia1 main.c
        vendor/stack.h
        vendor/stack.c
)
