#include <android/log.h>
#include <jni.h>
//
// 公共头文件
// Created by packcheng on 2021/4/13.
//

#ifndef NDKDEMO_MY_JNI_H
#define NDKDEMO_MY_JNI_H

#ifndef IS_RELEASE
#define IS_RELEASE true // 是否正式的环境
#if IS_RELEASE
#define RELEASE // 正式环境定义的宏
#else
#define DEBUG // debug环境定义的宏
#endif
#endif

extern JavaVM *javaVm;

#define TAG "PACKCHENG/NDK"

#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG, __VA_ARGS__);
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO,TAG, __VA_ARGS__);
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN,TAG, __VA_ARGS__);
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR,TAG, __VA_ARGS__);

#endif //NDKDEMO_MY_JNI_H
