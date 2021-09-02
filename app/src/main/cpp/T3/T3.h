//
// Created by packcheng on 2021/9/1.
//

#ifndef NDKDEMO_T3_H
#define NDKDEMO_T3_H

#include <jni.h>
#include "../my-jni.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t3_T3_callNativeException(JNIEnv *, jobject);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t3_T3_callJavaThrowException(JNIEnv *, jobject);

#endif //NDKDEMO_T3_H