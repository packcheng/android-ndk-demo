//
// Created by packcheng on 2021/8/11.
//

#ifndef NDKDEMO_T2_H
#define NDKDEMO_T2_H

#include <jni.h>
#include "../my-jni.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t2_T2_testArrayAction(JNIEnv *, jobject, jint,
                                                 jstring, jintArray,
                                                 jobjectArray);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t2_T2_newObject(JNIEnv *, jobject);
#endif //NDKDEMO_T2_H
