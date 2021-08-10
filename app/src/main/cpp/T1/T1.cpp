//
// Created by packcheng on 2021/8/10.
//

#include "T1.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_sayHelloToNdk(JNIEnv *env, jobject thiz, jstring name) {
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t1_T1_sayHelloFromNdk1")
#endif

}