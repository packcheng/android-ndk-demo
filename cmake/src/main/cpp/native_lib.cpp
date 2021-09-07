//
// Created by packcheng on 2021/9/7.
//

#include "my-jni.h"
#include "lib_action/action.h"

extern "C" {
#include "lib_get/get.h"
#include "./mylib/dynamic.h"
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_cmake_MyNative_testMethod(JNIEnv *env, jobject thiz) {
    int result = 0;
    result = plus_action(12, 4);
    LOG_I("12 + 4 = %d", result)
    result = subtract_action(12, 4);
    LOG_I("12 - 4 = %d", result)
    result = multiply_action(12, 4);
    LOG_I("12 * 4 = %d", result)
    result = divider_action(12, 4);
    LOG_I("12 / 4 = %d", result)
    LOG_I("-------------------------------")
    result = get_value_add_5(12);
    LOG_I("12 get_value_add_5 = %d", result)
    result = get_value_multiply_3(12);
    LOG_I("12 get_value_multiply_3 = %d", result)
    LOG_I("-------------------------------")
    result = say_hello_from_dynamic(22);
    LOG_I("22 say_hello_from_dynamic = %d", result)

}