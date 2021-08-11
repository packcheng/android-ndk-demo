//
// Created by packcheng on 2021/8/10.
//

#ifndef NDKDEMO_T1_H
#define NDKDEMO_T1_H

#include <jni.h>
#include "../my-jni.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_sayHelloToNdk(JNIEnv *, jobject, jstring);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_changeName(JNIEnv *, jobject);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_changeAge(JNIEnv *, jclass);
#endif //NDKDEMO_T1_H
