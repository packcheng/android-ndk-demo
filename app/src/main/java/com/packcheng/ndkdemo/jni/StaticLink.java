package com.packcheng.ndkdemo.jni;

/**
 * JNI/NDK静态注册方法
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/13 5:52 PM
 */
public class StaticLink {

    public native String helloFromCPP(String name);

    public native void sayHelloToCPP(String name, int age, String[] phone);
}
