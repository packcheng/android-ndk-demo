//
// Created by packcheng on 2021/9/2.
//

#ifndef NDKDEMO_DPARCEL_H
#define NDKDEMO_DPARCEL_H

#include <jni.h>
#include <malloc.h>
#include "../my-jni.h"

// Native Class Ddfine
class DParcel {
private:
    char *mData = nullptr;
    int mDatePos = 0;
    jint len = 0;
    void changePosition(int pos);

public:
    DParcel();

    ~DParcel();

    void writeInt(jint);

    jint readInt();

    void setDataPosition(jint pos);
};

// Native Method Define

extern "C"
JNIEXPORT jlong JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeCreate(JNIEnv *env, jclass clazz);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeWriteInt(JNIEnv *, jclass, jlong, jint);

extern "C"
JNIEXPORT jint JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeReadInt(JNIEnv *, jclass, jlong);

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeSetDataPosition(JNIEnv *, jclass, jlong, jint);


#endif //NDKDEMO_DPARCEL_H