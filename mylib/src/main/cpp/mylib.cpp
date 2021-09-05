#include <jni.h>
#include <string>
#include "my-jni.h"

extern "C" {
#include "./mylib/static.h"
#include "./mylib/dynamic.h"
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_packcheng_mylib_NativeLib_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    int reslut1 = say_hello_from_dynamic(22);
    int reslut = say_hello_to_static();
    LOG_I("HJJJJJJJJJJJJJJJJJJJJJ %d - %d", reslut, reslut1)
    return env->NewStringUTF(hello.c_str());
}