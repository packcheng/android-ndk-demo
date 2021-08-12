package com.packcheng.ndkdemo.t2;

import com.packcheng.ndkdemo.util.LogUtil;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/11 22:18
 */
class T2 {
    private String name;
    private int age;
    private T2 member;

    /**
     * 测试数组的使用
     */
    public native void testArrayAction(int count, String info, int[] ints, String[] strings);

    public native void newObject();

    public void setMember(T2 member){
        this.member = member;
    }

    public void printArrayAction(int count, String info, int[] ints, String[] strings) {
        final StringBuilder mSb = new StringBuilder();
        mSb.delete(0, mSb.length());
        mSb.append("count:")
                .append(count)
                .append(", info:")
                .append(info)
                .append(", ints: ");
        for (int anInt : ints) {
            mSb.append(anInt)
                    .append(",");
        }
        mSb.append("strings: ");
        for (String string : strings) {
            mSb.append(string)
                    .append(",");
        }
        LogUtil.d(mSb.toString());
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "T2{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", member=" + member +
                '}';
    }
}
