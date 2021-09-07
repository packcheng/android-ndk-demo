cmake_minimum_required(VERSION 3.10.2)

file(GLOB action_files *.cpp)

add_library(action_lib
        SHARED
        ${action_files})