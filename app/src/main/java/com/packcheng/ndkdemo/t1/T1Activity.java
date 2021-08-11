package com.packcheng.ndkdemo.t1;

import android.content.Context;
import android.content.Intent;

import com.packcheng.ndkdemo.BaseActivity;
import com.packcheng.ndkdemo.R;
import com.packcheng.ndkdemo.databinding.ActivityT1Binding;
import com.packcheng.ndkdemo.util.LogUtil;

/**
 * Ndk与Java方法回调
 * Ndk修改Java属性和静态属性
 *
 * @author packcheng
 * @date 2021/8/10 00:23
 */
public class T1Activity extends BaseActivity<ActivityT1Binding> {

    private final T1 t1 = new T1();

    public static void startActivity(Context context) {
        context.startActivity(new Intent(context, T1Activity.class));
    }

    @Override
    protected int getContentResId() {
        return R.layout.activity_t1;
    }

    @Override
    protected void initView() {
        super.initView();
        mBinding.btnSayHelloToNdk.setOnClickListener(v -> t1.sayHelloToNdk("zbc"));

        mBinding.btnChangeFiled.setOnClickListener(v -> {
            LogUtil.d("Name before jni change: " + t1.getName());
            t1.changeName();
            LogUtil.d("Name after jni change: " + t1.getName());
        });

        mBinding.btnChangeStaticFiled.setOnClickListener(v -> {
            LogUtil.d("Age before jni change: " + T1.getAge());
            T1.changeAge();
            LogUtil.d("Age after jni change: " + T1.getAge());
        });

    }
}