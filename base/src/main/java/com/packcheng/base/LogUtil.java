package com.packcheng.base;

import android.util.Log;

/**
 * 日志工具
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/13 6:08 PM
 */
public class LogUtil {
    static final String TAG = "PACKCHENG-JAVA-LogUtil";

    public static void d(String msg) {
        Log.d(TAG, msg);
    }

    public static void i(String msg) {
        Log.i(TAG, msg);
    }

    public static void w(String msg) {
        Log.w(TAG, msg);
    }

    public static void e(String msg) {
        Log.e(TAG, msg);
    }
}
