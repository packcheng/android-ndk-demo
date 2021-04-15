#include <jni.h>
#include "my-jni.h"
//
// Created by packcheng on 2021/4/14.
//

#ifndef NDKDEMO_DYNAMIC_METHOD_H
#define NDKDEMO_DYNAMIC_METHOD_H

// 需要动态注册方法的类
#define CLASS_DYNAMIC_LINK "com/packcheng/ndkdemo/jni/DynamicLink"

extern "C"
JNIEXPORT jstring
JNICALL
dynamicHelloFromCPP(JNIEnv *env, jobject thiz,
                    jstring name);

extern "C"
JNIEXPORT jboolean
JNICALL dynamicSayHelloToCpp(JNIEnv *env, jobject thiz,
                             jstring name, jdouble height);


static JNINativeMethod dynamicLinkMethods[] = {
        {"dynamicHelloFromCPP",  "(Ljava/lang/String;)Ljava/lang/String;", (void *) dynamicHelloFromCPP},
        {"dynamicSayHelloToCpp", "(Ljava/lang/String;D)Z",                 (void *) dynamicSayHelloToCpp}
};

/**
 * 动态注册方法
 * @param env
 */
void registerMethods(JNIEnv *env);

/**
 * 动态反注册方法
 * @param env
 */
void unregisterMethods(JNIEnv *env);

#endif //NDKDEMO_DYNAMIC_METHOD_H
