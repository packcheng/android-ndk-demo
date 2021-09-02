//
// 仿Android源码的Parcel
// Created by packcheng on 2021/9/2.
//

#include "DParcel.h"

DParcel::DParcel() {
    this->mData = static_cast<char *>(malloc(1024));
}

DParcel::~DParcel() {
    if (this->mData) {
        free(this->mData);
        this->mData = nullptr;

        this->mDatePos = 0;
        this->len = 0;
    }
}

void DParcel::changePosition(int pos) {
    this->mDatePos += pos;
}

void DParcel::writeInt(jint value) {
    *reinterpret_cast<int *>(this->mData + this->mDatePos) = value;
    this->changePosition(sizeof(int));
}

jint DParcel::readInt() {
    jint result = *(reinterpret_cast<int *>(this->mData + this->mDatePos));
    changePosition(sizeof(int));
    return result;
}

void DParcel::setDataPosition(jint pos) {
    this->mDatePos = pos;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeCreate(JNIEnv *env, jclass clazz) {
    auto *dParcel = new DParcel();
    return reinterpret_cast<long>(dParcel);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeWriteInt(JNIEnv *env, jclass clazz, jlong native_ptr,
                                                     jint val) {
    DParcel *dParcel = reinterpret_cast<DParcel *>(native_ptr);
    dParcel->writeInt(val);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeReadInt(JNIEnv *env, jclass clazz, jlong native_ptr) {
    DParcel *parcel = reinterpret_cast<DParcel *>(native_ptr);
    return parcel->readInt();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_t4_DParcel_nativeSetDataPosition(JNIEnv *env, jclass clazz,
                                                            jlong native_ptr, jint pos) {
    DParcel *parcel = reinterpret_cast<DParcel *>(native_ptr);
    parcel->setDataPosition(pos);
}