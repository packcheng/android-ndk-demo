package com.packcheng.ndkdemo.t3;

import com.packcheng.base.LogUtil;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/11 22:18
 */
class T3 {

    public native void callNativeException() throws IllegalStateException;
    public native void callJavaThrowException();

    public void throwException(){
        LogUtil.d("Java 层准备抛异常");
        throw new IllegalStateException("Exception throw by java");
    }
}
