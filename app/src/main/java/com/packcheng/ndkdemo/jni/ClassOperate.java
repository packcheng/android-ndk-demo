package com.packcheng.ndkdemo.jni;

import com.packcheng.ndkdemo.util.LogUtil;

/**
 * ndk与Java互调
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/15 4:38 PM
 */
public class ClassOperate {

    // C++修改静态属性
    private static String name = "default";

    // C++修改成员属性
    private int age = 10;

    // C++调用成员静态方法
    private int callByCPP(String ageStr, boolean isInt) {
        LogUtil.d("callByCPP, ageStr: " + ageStr + ", isInt: " + isInt);
        int age = -1;
        try {
            age = Integer.parseInt(ageStr);
        } catch (Exception e) {
            LogUtil.e("Error!!!!!!");
            e.printStackTrace();
        }
        return age;
    }

    // C++调用静态方法
    private static String callNativeByCpp(String user, int age) {
        LogUtil.d("callNativeByCpp, user: " + user + ", age: " + age);
        return user + age;
    }

    public native void callMemberMethod();

    public native static void callClassMethod();

    public native void updateMemberFiled();

    public native static void updateClassFiled();

    public static native ClassOperate create();

    public native void update(ClassOperate operate);


    public static void setName(String name) {
        ClassOperate.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "ClassOperate{" +
                "name=" + name +
                ", age=" + age +
                '}';
    }
}
