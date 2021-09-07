cmake_minimum_required(VERSION 3.10.2)

file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/cpp/*.cpp ${CMAKE_SOURCE_DIR}/cpp/*.h)

# 导入mylib头文件
include_directories(${CMAKE_SOURCE_DIR}/cpp/mylib)

add_library(native_lib
        SHARED
        ${SOURCE})

# 批量导入库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

add_subdirectory(${CMAKE_SOURCE_DIR}/cpp/lib_action)

add_subdirectory(${CMAKE_SOURCE_DIR}/cpp/lib_get)

target_link_libraries(native_lib
        log
        dynamic
        get_lib
        action_lib)