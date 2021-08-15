# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

# 最低支持CMAKE版本
cmake_minimum_required(VERSION 3.10.2)

# 第一步：导入头文件
include_directories("fmod")

# 批量导入所有源文件
file(GLOB allCpp *.c *.h *.cpp *.hpp)

add_library(
        my-fmode-lib  # 生成的库文件名-> libmy_fmode-lib.so
        SHARED # 生成库的类型: SHARED,动态库; STATIC,静态库
        ${allCpp} # 源文件
)

# 第二步: 导入库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

find_library(
        log-lib # 定义变量
        log) # 寻找ndk的库

# 第三步: 链接具体的库到my-fmode-lib这个库中
target_link_libraries(
        my-fmode-lib
        fmod
        fmodL
        ${log-lib}
)