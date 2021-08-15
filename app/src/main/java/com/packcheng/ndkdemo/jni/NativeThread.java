package com.packcheng.ndkdemo.jni;

import com.packcheng.base.LogUtil;

/**
 * Native线程与回调
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/16 2:27 PM
 */
public class NativeThread {
    /**
     * 初始化
     */
    public native void nativeInit();

    /**
     * Native层回调方法
     *
     * @param msg native 回调信息
     */
    private void onNativeCallback(String msg) {
        LogUtil.d("onNativeCallback, msg: " + msg);
    }
}
