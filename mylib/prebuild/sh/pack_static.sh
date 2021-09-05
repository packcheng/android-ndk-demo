#!/bin/bash

echo "准备打包生成动态库"

# 定义变量
CUR_DIR=$(pwd)
SRC_FILE=$CUR_DIR/../code/static.c

DES_FILE_O_V7=$CUR_DIR/../out/armeabi-v7a/static.o
DES_FILE_A_V7=$CUR_DIR/../out/armeabi-v7a/libstatic.a

DES_FILE_O_V8=$CUR_DIR/../out/arm64-v8a/static.o
DES_FILE_A_V8=$CUR_DIR/../out/arm64-v8a/libstatic.a

NDK_ROOT="/Users/packcheng/Library/Android/sdk/ndk/17.2.4988734"

NDK_GCC_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc"
NDK_LIB_CONFIG_V7="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/arm-linux-androideabi"
NDK_AR_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-ar"

NDK_GCC_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-gcc"
NDK_LIB_CONFIG_V8="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm64 -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/aarch64-linux-android"
NDK_AR_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-ar"

# armeabi-v7a
$NDK_GCC_V7 $NDK_LIB_CONFIG_V7 -fPIC -c $SRC_FILE -o $DES_FILE_O_V7
$NDK_AR_V7 rcs -o $DES_FILE_A_V7 $DES_FILE_O_V7

# arm64-v8a
$NDK_GCC_V8 $NDK_LIB_CONFIG_V8 -fPIC -c $SRC_FILE -o $DES_FILE_O_V8
$NDK_AR_V8 rcs -o $DES_FILE_A_V8 $DES_FILE_O_V8