cmake_minimum_required(VERSION 3.10.2)

file(GLOB get_files *.c)

add_library(get_lib
        SHARED
        ${get_files})