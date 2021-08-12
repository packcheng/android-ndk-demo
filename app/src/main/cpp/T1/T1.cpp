//
// Created by packcheng on 2021/8/10.
//

#include "T1.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_sayHelloToNdk(JNIEnv *env, jobject thiz, jstring name) {
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t1_T1_sayHelloFromNdk")
#endif
    const char *p_name = env->GetStringUTFChars(name, 0);
    LOG_W("Hello from java by %s\n", p_name)
    
    LOG_I("Ready to call java method")
    jclass p_t1 = env->GetObjectClass(thiz);
    jmethodID p_method_id = env->GetMethodID(p_t1, "addCallByNdk", "(II)I");
    jint result = env->CallIntMethod(thiz, p_method_id, 10, 20);
    LOG_W("The result of method add(10,20) is %d\n",result)
    
    env->ReleaseStringUTFChars(name, p_name);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_changeName(JNIEnv* env, jobject thiz){
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t1_T1_changeName")
#endif
    jclass pJclass = env->GetObjectClass(thiz);
    jfieldID pId = env->GetFieldID(pJclass, "name", "Ljava/lang/String;");
    env->SetObjectField(thiz, pId, env->NewStringUTF("packcheng"));
    LOG_W("Ndk修改name为packcheng")
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t1_T1_changeAge(JNIEnv *env, jclass clazz) {
#ifdef DEBUG
    LOG_I("Java_com_packcheng_ndkdemo_t1_T1_changeAge")
#endif
    jfieldID pId = env->GetStaticFieldID(clazz, "age", "I");
    env->SetStaticIntField(clazz, pId, 10);
    LOG_W("Ndk修改age为10")
}