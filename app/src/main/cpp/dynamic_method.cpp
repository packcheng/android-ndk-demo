#include <jni.h>
#include <cstring>
#include "dynamic_method.h"
#include "my-jni.h"

//
// 动态注册方法实现
// Created by packcheng on 2021/4/14.
//


/**
 * 动态注册方法
 * @param env
 */
void registerMethods(JNIEnv *env) {
    LOG_D("registerMethods")
    jclass dynamic_class = env->FindClass(CLASS_DYNAMIC_LINK);
    if (dynamic_class == nullptr) {
        LOG_E("Class no found: %s", CLASS_DYNAMIC_LINK)
        return;
    }
    env->RegisterNatives(dynamic_class, dynamicLinkMethods,
                         sizeof(dynamicLinkMethods) / sizeof(JNINativeMethod));
}

/**
 * 动态反注册方法
 * @param env
 */
void unregisterMethods(JNIEnv *env) {
    LOG_D("registerMethods")
    jclass target_class = env->FindClass(CLASS_DYNAMIC_LINK);
    if (nullptr == target_class) {
        LOG_E("Class not found: %s", CLASS_DYNAMIC_LINK);
        return;
    }
    env->UnregisterNatives(target_class);
}

extern "C"
JNIEXPORT jstring JNICALL
dynamicHelloFromCPP(JNIEnv *env, jobject thiz,
                    jstring _name) {
    LOG_D("dynamicHelloFromCPP")

    const char *name = env->GetStringUTFChars(_name, NULL);
    if (nullptr == name) {
        LOG_E("Error on get name")
        return NULL;
    }
    char new_name[30] = "Hello, ";
    strcat(new_name, name);
    env->ReleaseStringUTFChars(_name, name);
    return env->NewStringUTF(new_name);
}

extern "C"
JNIEXPORT jboolean JNICALL
dynamicSayHelloToCpp(JNIEnv *env, jobject thiz,
                     jstring _name, jdouble _height) {
    LOG_D("dynamicSayHelloToCpp")
    const char *name = env->GetStringUTFChars(_name, NULL);
    if (nullptr == name) {
        LOG_E("Error on get name")
        return NULL;
    }
    LOG_I("Get name: %s, age: %d", name, _height)
    env->ReleaseStringUTFChars(_name, name);
    return true;
}

