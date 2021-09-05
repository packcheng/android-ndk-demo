#!/bin/bash

echo "准备打包生成动态库"
# 定义变量
CUR_DIR=$(pwd)
SRC_FILE=$CUR_DIR/../code/dynamic.c
DES_FILE_V7=$CUR_DIR/../out/armeabi-v7a/libdynamic.so
DES_FILE_V8=$CUR_DIR/../out/arm64-v8a/libdynamic.so

NDK_ROOT="/Users/packcheng/Library/Android/sdk/ndk/17.2.4988734"

NDK_GCC_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc"
NDK_LIB_CONFIG_V7="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/arm-linux-androideabi"

NDK_GCC_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-gcc"
NDK_LIB_CONFIG_V8="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm64 -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/aarch64-linux-android"

if [ -e "$DES_FILE_V7" ]; then
  echo "V7 so文件已存在，先删除"
  $(rm -rf $DES_FILE_V7)
fi

if [ -e "$DES_FILE_V8" ]; then
  echo "V8 so文件已存在，先删除"
  $(rm -rf $DES_FILE_V8)
fi

# armeabi-v7a
$NDK_GCC_V7 $NDK_LIB_CONFIG_V7 -fPIC -shared $SRC_FILE -o $DES_FILE_V7

# arm64-v8a
$NDK_GCC_V8 $NDK_LIB_CONFIG_V8 -fPIC -shared $SRC_FILE -o $DES_FILE_V8

if (($?)); then
  echo "无法生成动态库"
else
  echo "成功生成动态库："
fi
