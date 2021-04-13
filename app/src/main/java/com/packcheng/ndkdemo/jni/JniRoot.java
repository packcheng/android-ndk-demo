package com.packcheng.ndkdemo.jni;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/13 4:17 PM
 */
public class JniRoot {
    static {
        System.loadLibrary("native-lib");
    }
}
