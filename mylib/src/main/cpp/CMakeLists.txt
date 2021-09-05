# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("mylib")

# 批量导入所有源文件
file(GLOB allCPP *.c *.h *.cpp)

add_library(
        mylib
        SHARED
        ${allCPP})

# 导入静态库文件
add_library(static STATIC IMPORTED)
# 真正导入静态库文件
set_target_properties(static PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/mylib/${CMAKE_ANDROID_ARCH_ABI}/libstatic.a)

# !!! 不知道怎么，这种方式一致导入失败
# 导入动态库文件
#add_library(dynamic SHARED IMPORTED)
# 真正导入动态库文件
#set_target_properties(dynamic PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI})

# 导入动态库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

find_library(
        log-lib
        log)

target_link_libraries(
        mylib
        ${log-lib}
        static
        dynamic
)