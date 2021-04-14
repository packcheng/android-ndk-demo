#include <jni.h>
#include <cstring>
#include "my-jni.h"

//
// 静态注册
// Created by packcheng on 2021/4/13.
//

extern "C"
JNIEXPORT jstring
JNICALL
Java_com_packcheng_ndkdemo_jni_StaticLink_helloFromCPP(JNIEnv *env, jobject thiz, jstring _name) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_StaticLink_helloFromCPP")

    const char *name = env->GetStringUTFChars(_name, NULL);
    if (name == nullptr) {
        LOG_E("Can't get string utf chars for name.")
        return nullptr;
    }

    char new_name[120] = {"hello, "};
    strcat(new_name, name);

    env->ReleaseStringUTFChars(_name, name);
    return env->NewStringUTF(new_name);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_StaticLink_sayHelloToCPP(JNIEnv *env, jobject thiz, jstring _name,
                                                        jint _age, jobjectArray _phone) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_StaticLink_sayHelloToCPP")
    const char *name = env->GetStringUTFChars(_name, NULL);
    if (name == nullptr) {
        LOG_E("Error on get name");
        return;
    }

    LOG_I("name=%s,age=%d", name, _age)
    jsize phone_len = env->GetArrayLength(_phone);
    if (phone_len > 0) {
        for (int i = 0; i < phone_len; ++i) {
            jstring _one_phone = static_cast<jstring>(env->GetObjectArrayElement(_phone, i));
            const char *one_phone = env->GetStringUTFChars(_one_phone, NULL);
            if (one_phone == nullptr) {
                LOG_E("Error on get phone at index:%d", i)
                continue;
            }
            LOG_I("phone%d: %s", i, one_phone)
            env->ReleaseStringUTFChars(_one_phone, one_phone);
        }
    }
    env->ReleaseStringUTFChars(_name, name);
}

