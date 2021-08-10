package com.packcheng.ndkdemo.t1;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/10 00:15
 */
class T1 {
    private String name = "zbc";
    private static int age = 19;

    public native void sayHelloToNdk(String name);

    public int addCallByNdk(int a, int b) {
        return a + b;
    }
}
