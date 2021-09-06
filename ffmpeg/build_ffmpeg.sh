#!/bin/bash

# 定义编译后产物的存放目录
PREFIX=./android/arm

# 2.--enable-small 优化大小 非常重要，必须优化才行的哦
# 3.--disable-programs 不编译ffmpeg程序（命令行工具），我们是需要获取静态、动态库
# 4.--disable-avdevice 关闭avdevice模块，此模块在android中无用
# 5.--disable-encoders 关闭所有编码器（播放不需要编码）
# 6.--disable-muxers 关闭所有复用器（封装器），不需要生成mp4这样的文件，所有关闭
# 7.--disable-filters 关闭所有滤镜
# 8.--enable-cross-compile 开启交叉编译（ffmpeg是跨平台的，注意：并不是所有库都有这么happy的选项）
# 9.--cross-prefix 看右边的值就知道是干嘛的，gcc的前缀..
# 10.disable-shared / enable-static 这个不写也可以，默认就是这样的，（代表关闭动态库，开启静态库）
# 11.--sysroot
# 12.--extra-cflags 会传给gcc的参数
# 13.--arch  --target-os

./configure \
--prefix=$PREFIX \
--enable-small \
--disable-programs \
--disable-avdevice \
--disable-encoders \
--disable-muxers \
--disable-filters \
--enable-cross-compile \
--cross-prefix=
