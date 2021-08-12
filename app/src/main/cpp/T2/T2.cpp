//
// Created by packcheng on 2021/8/11.
//

#include "T2.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t2_T2_testArrayAction(JNIEnv *env, jobject thiz, jint count,
                                                 jstring info, jintArray ints,
                                                 jobjectArray strings) {
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t2_T2_testArrayAction")
#endif

    int count_int = count;
    LOG_I("参数 count: %d\n", count_int)

    const char *string = env->GetStringUTFChars(info, NULL);
    LOG_I("参数 INFO: %s\n", string)

    jint *pInt = env->GetIntArrayElements(ints, NULL);
    jsize ints_size = env->GetArrayLength(ints);

    for (int i = 0; i < ints_size; ++i) {
        *(pInt + i) += 100;
        LOG_I("参数 ints: %d\n", *(pInt + i))
    }

    // 0: 释放C++层数组并刷新Java数组
    // JNI_COMMIT: 只刷新Java数组，不释放C++数组
    // JNI_ABORT: 仅释放C++数组
    env->ReleaseIntArrayElements(ints, pInt, 0);


    jsize strings_size = env->GetArrayLength(strings);
    for (int i = 0; i < strings_size; ++i) {
        jstring str = static_cast<jstring>(env->GetObjectArrayElement(strings, i));
        const char *chars = env->GetStringUTFChars(str, NULL);
        LOG_I("参数 strings: %s\n", chars)

        // 释放jstring
        env->ReleaseStringUTFChars(str, chars);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t2_T2_newObject(JNIEnv *env, jobject thiz) {
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t2_T2_newObject")
#endif
    const char *class_str = "com/packcheng/ndkdemo/t2/T2";
    jclass t2_class = env->FindClass(class_str);
    jobject t2_object = env->AllocObject(t2_class);

    jmethodID set_name_method = env->GetMethodID(t2_class, "setName", "(Ljava/lang/String;)V");
    jmethodID set_age_method = env->GetMethodID(t2_class, "setAge", "(I)V");
    env->DeleteLocalRef(t2_class);
    env->CallVoidMethod(t2_object, set_name_method, env->NewStringUTF("zbc"));
    env->CallVoidMethod(t2_object, set_age_method, 18);

    jclass this_class = env->GetObjectClass(thiz);
    jmethodID set_member_method = env->GetMethodID(this_class, "setMember",
                                                   "(Lcom/packcheng/ndkdemo/t2/T2;)V");
    env->DeleteLocalRef(this_class);
    env->CallVoidMethod(thiz, set_member_method, t2_object);
    LOG_I("成功设置Object")

    // 释放
    env->DeleteLocalRef(t2_object);
}