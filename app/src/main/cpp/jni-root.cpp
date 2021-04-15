#include <jni.h>
#include "my-jni.h"
#include "dynamic_method.h"
//
// Jni代码练习
// Created by packcheng on 2021/4/13.
//

JavaVM *javaVm;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOG_D("JNI_OnLoad")

    javaVm = vm;

    JNIEnv *env = nullptr;
    if(vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK){
        LOG_E("Error on getEnv")
        return JNI_ERR;
    }

    registerMethods(env);

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOG_D("JNI_OnUnLoad")

    JNIEnv *env = nullptr;
    if(vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK){
        LOG_E("Error on getEnv")
        return;
    }

    unregisterMethods(env);
}

