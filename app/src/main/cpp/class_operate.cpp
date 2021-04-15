#include "my-jni.h"
#include <jni.h>
//
// ndk与Java互调
// Created by packcheng on 2021/4/15.
//

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_updateMemberFiled(JNIEnv *env, jobject thiz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_updateMemberFiled")
    jclass target_class = env->GetObjectClass(thiz);
    if (target_class == nullptr) {
        LOG_E("Error on get class")
        return;
    }

    jfieldID id_f_age = env->GetFieldID(target_class, "age", "I");
    if (id_f_age == nullptr) {
        LOG_E("Error on get filed id")
        return;
    }

    jint old_age = env->GetIntField(thiz, id_f_age);
    LOG_I("原来的age: %d", old_age);
    env->SetIntField(thiz, id_f_age, old_age + 10);
    LOG_I("C++中跟新Filed")

    env->DeleteLocalRef(target_class);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_updateClassFiled(JNIEnv *env, jclass clazz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_updateClassFiled")

    jfieldID id_f_name = env->GetStaticFieldID(clazz, "name", "Ljava/lang/String;");
    if (id_f_name == nullptr) {
        LOG_E("Error on get filed id")
        return;
    }

    jstring new_name = env->NewStringUTF("zbc");
    env->SetStaticObjectField(clazz, id_f_name, new_name);
    LOG_I("C++中跟新Static Filed")

    env->DeleteLocalRef(new_name);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_callMemberMethod(JNIEnv *env, jobject thiz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_callMemberMethod")

    jclass target_class = env->GetObjectClass(thiz);
    if (target_class == nullptr) {
        LOG_E("Error on get class")
        return;
    }

    jmethodID id_m_call_by_cpp = env->GetMethodID(target_class, "callByCPP",
                                                  "(Ljava/lang/String;Z)I");
    if (id_m_call_by_cpp == nullptr) {
        LOG_E("Error on get method id")
        return;
    }

    jstring age = env->NewStringUTF("19");
    if (nullptr == age) {
        LOG_E("Error on new String utf")
        return;
    }

    jint age_result = env->CallIntMethod(thiz, id_m_call_by_cpp, age, true);
    LOG_I("Call member method from cpp, get age: %d", age_result)

    env->DeleteLocalRef(age);
    env->DeleteLocalRef(target_class);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_callClassMethod(JNIEnv *env, jclass clazz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_callClassMethod")

    jmethodID id_m_call_native_by_cpp = env->GetStaticMethodID(clazz, "callNativeByCpp",
                                                               "(Ljava/lang/String;I)Ljava/lang/String;");
    if (id_m_call_native_by_cpp == nullptr) {
        LOG_E("Error on get method id")
        return;
    }

    jstring name = env->NewStringUTF("packcheng");
    if (nullptr == name) {
        LOG_E("Error on new String utf")
        return;
    }

    jstring result = static_cast<jstring>(env->CallStaticObjectMethod(clazz,
                                                                      id_m_call_native_by_cpp, name,
                                                                      18));
    const char *_result = env->GetStringUTFChars(result, NULL);
    LOG_I("Call class method from cpp, result: %s", _result)

    env->ReleaseStringUTFChars(result, _result);
    env->DeleteLocalRef(name);
    env->DeleteLocalRef(clazz);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_create(JNIEnv *env, jclass clazz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_create")

    jmethodID id_m_instance = env->GetMethodID(clazz, "<init>", "()V");
    if (nullptr == id_m_instance) {
        LOG_E("Error on get constructor")
        return NULL;
    }

    jobject instance = env->NewObject(clazz, id_m_instance);
    if (nullptr == instance) {
        LOG_E("Error on new instance")
        return NULL;
    }

    return instance;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ClassOperate_update(JNIEnv *env, jobject thiz, jobject operate) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ClassOperate_update")
}