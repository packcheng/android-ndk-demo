# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("ndkdemo")

add_library(
        native-lib
        SHARED
        jni-root.cpp static-link.cpp my-jni.h dynamic_method.h dynamic_method.cpp class_operate.cpp native_thread.cpp)

find_library(
        log-lib
        log)

target_link_libraries(
        native-lib
        ${log-lib})