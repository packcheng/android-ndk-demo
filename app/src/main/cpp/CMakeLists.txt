# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("ndkdemo")

# T工程之前备份
#add_library(
#        native-lib
#        SHARED
#        jni-root.cpp static-link.cpp my-jni.h dynamic_method.h dynamic_method.cpp class_operate.cpp native_thread.cpp product_consumer.cpp)

add_library(
        native-lib
        SHARED
        my-jni.h T1/T1.h T1/T1.cpp T2/T2.h T2/T2.cpp T3/T3.h T3/T3.cpp T4/DParcel.h T4/DParcel.cpp)

find_library(
        log-lib
        log)

target_link_libraries(
        native-lib
        ${log-lib})

# 无->重要消息
# STATUS -> 非重要消息
# WARNING -> CMake警告信息，会继续执行
# AUTHOR_WARNING -> dev警告信息，会继续执行
# SEND_ERROR -> CMake错误，会继续执行，会跳过生成步骤
# FATAL_ERROR -> CMake错误，中止执行

message("XXXXXXXXXXXXXXXXXXXXXX-NULL")
message(STATUS "XXXXXXXXXXXXXXXXXXXXXX-STATUS")
message(WARNING "XXXXXXXXXXXXXXXXXXXXXX-WARNING")
message(AUTHOR_WARNING "XXXXXXXXXXXXXXXXXXXXXX-AUTHOR_WARNING")

message("------------set-------------")
# 定义变量  set(变量名 变量值)
set(VAR_NAME 999)
message(STATUS "VAR_NAME = ${VAR_NAME}")

message("------------unset-------------")
# 移除变量
unset(VAR_NAME)
message(STATUS "VAR_NAME = ${VAR_NAME}")

message("------------list-------------")
set(list1 1 2 3 4)
message("------------list1 = ${list1}-------------")
unset(list1)

set(list2 "1;2;3;4")
message("------------list2 = ${list2}-------------")
unset(list2)

message("------------if elseif endif-------------")
# 条件判断
# true (1 ON YES TRUE Y 非0)
# false (0 OFF NO FALSE N IGNORE NOTFOUND)
set(if_tap OFF)
set(elseif_tap ON)
if (${if_tap})
    message("------------IF-------------")
elseif (${elseif_tap})
    message("------------ELSE IF-------------")
else (${if_tap})
    message("------------ELSE-------------")
endif (${if_tap})
unset(if_tap)
unset(elseif_tap)

# 循环
message("------------while-------------")
set(temp "")
while (NOT temp STREQUAL "AAA")
    set(temp "${temp}A")
endwhile ()
unset(temp)

message("------------for each-------------")
foreach (item 2 3 4)
    message("List item = ${item}")
endforeach (item)

message("------------for each RANGE-------------")
foreach (item RANGE 10)
    message("RANGE List item = ${item}")
endforeach (item)

message("------------for each RANGE STEP-------------")
foreach (item RANGE 4 10 2)
    message("RANGE STEP List item = ${item}")
endforeach (item)

message("------------for each IN LISTS-------------")
set(list_var3 12 13 14)
foreach (item IN LISTS list_var3)
    message("item in list item = ${item}")
endforeach (item)
unset(list_var3)

# 方法定义
function(tes1 v1 v2 v3)
    message("call test1 method")
    message("arg v1 = ${v1}")
    message("arg v2 = ${v2}")
    message("arg v3 = ${v3}")
    message("ARGC = ${ARGC}")
    message("arg1 = ${ARGV0} arg2 = ${ARGV1} arg3 = ${ARGV2}")
    message("all args = ${ARGV}")
endfunction(tes1)
# 方法使用
message("------------call my function-------------")
tes1(2 3 4)