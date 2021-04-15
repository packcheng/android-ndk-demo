package com.packcheng.ndkdemo.jni;

/**
 * JNI/NDK动态注册方法
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/14 5:48 PM
 */
public class DynamicLink {

    public native String dynamicHelloFromCPP(String name);

    public native boolean dynamicSayHelloToCpp(String name, double height);
}
