package com.packcheng.ndkdemo.t1;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/10 00:15
 */
class T1 {
    private String name = "zbc";
    private static int age = 19;

    public int addCallByNdk(int a, int b) {
        return a + b;
    }

    public String getName() {
        return name;
    }

    public static int getAge() {
        return age;
    }

    public native void changeName();

    public native static void changeAge();

    public native void sayHelloToNdk(String name);
}
