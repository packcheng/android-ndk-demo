#include <jni.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "my-jni.h"

//
// Java native线程与回调
// Created by packcheng on 2021/4/16.
//

// 回调对象
jobject g_native_thread;
// 回调方法
jmethodID g_native_thread_id_m_callback;


void *doThreadAction(void *args) {
    LOG_W("doThreadAction")
    JNIEnv *env = NULL;
    jint result = javaVm->AttachCurrentThread(&env, nullptr);
    if (result != 0) {
        LOG_E("Error on attach current thread")
        return nullptr;
    }

    for (int i = 0; i < 20; i++) {
        char temp[30];
        sprintf(temp, "aaa:%d", i);
        jstring arg = env->NewStringUTF(temp);
        env->CallVoidMethod(g_native_thread, g_native_thread_id_m_callback, arg);
        env->DeleteLocalRef(arg);
        usleep(1000 * 1000);
    }
    LOG_I("Done")
    env->DeleteGlobalRef(g_native_thread);
    javaVm->DetachCurrentThread();
    return nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_NativeThread_nativeInit(JNIEnv *env, jobject thiz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_NativeThread_nativeInit")
    jclass target_class = env->GetObjectClass(thiz);
    if (nullptr == target_class) {
        LOG_E("Error on get object class")
        return;
    }
    g_native_thread = env->NewGlobalRef(thiz);

    g_native_thread_id_m_callback = env->GetMethodID(target_class, "onNativeCallback",
                                                     "(Ljava/lang/String;)V");
    if (nullptr == g_native_thread_id_m_callback) {
        LOG_E("Error on get method id")
        env->DeleteGlobalRef(g_native_thread);
        return;
    }

    // 创建线程
    pthread_t pid;
    jint ret = pthread_create(&pid, NULL, doThreadAction, NULL);
    LOG_I("pthread_create")

}
