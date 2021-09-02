//
// Created by packcheng on 2021/9/1.
//

#include "T3.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t3_T3_callNativeException(JNIEnv *env, jobject thiz) {
    LOG_I("Native层准备抛异常")
    jclass t3_class = env->GetObjectClass(thiz);
    env->GetMethodID(t3_class, "getname","()V");

    // Native层异常处理
    jthrowable pJthrowable = env->ExceptionOccurred();
    if (pJthrowable) {
        LOG_E("Native层监测到了异常")
        env->ExceptionClear(); // 清除此异常

        jclass e = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(e, "Can't find method getname() on class");
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t3_T3_callJavaThrowException(JNIEnv *env, jobject thiz) {
    jclass t3_class = env->GetObjectClass(thiz);
    jmethodID pId = env->GetMethodID(t3_class, "throwException", "()V");
    env->DeleteLocalRef(t3_class);

    LOG_E("准备调用Java层throwException")
    env->CallVoidMethod(thiz, pId);

    // Java层异常处理
    // ******* 在出现异常后且在捕获前不能进行其他操作
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

