cmake_minimum_required(VERSION 3.16)

project(hzip C)

set(CMAKE_C_STANDARD 11)

add_executable(
        hzip
        main.c
        file_util.c
        hzip.c
        frequency.c
        pqueue.c
)