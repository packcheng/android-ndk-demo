package com.packcheng.cmake;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/9/7 23:10
 */
class MyNative {
    static {
        System.loadLibrary("get_lib");
        System.loadLibrary("dynamic");
        System.loadLibrary("native_lib");
    }

    public native void testMethod();
}
