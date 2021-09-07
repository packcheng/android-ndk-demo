//
// 公共头文件
// Created by packcheng on 2021/4/13.
//

#ifndef NDKDEMO_MY_JNI_H
#define NDKDEMO_MY_JNI_H

#include <android/log.h>
#include <jni.h>

#ifndef IS_RELEASE
#define IS_RELEASE 0
#if IS_RELEASE
#define RELEASE
#else
#define DEBUG
#endif
#endif

#define TAG "PACKCHENG-NDK-Log"

#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG, __VA_ARGS__);
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO,TAG, __VA_ARGS__);
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN,TAG, __VA_ARGS__);
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR,TAG, __VA_ARGS__);

#endif //NDKDEMO_MY_JNI_H
