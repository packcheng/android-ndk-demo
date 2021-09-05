package com.packcheng.mylib;

public class NativeLib {

    // Used to load the 'mylib' library on application startup.
    static {
        System.loadLibrary("dynamic");
        System.loadLibrary("mylib");
    }

    /**
     * A native method that is implemented by the 'mylib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}