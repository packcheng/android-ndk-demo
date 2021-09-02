package com.packcheng.ndkdemo;

import com.packcheng.base.BaseActivity;
import com.packcheng.ndkdemo.databinding.ActivityMainBinding;
import com.packcheng.ndkdemo.jni.JniRoot;
import com.packcheng.ndkdemo.t1.T1Activity;
import com.packcheng.ndkdemo.t2.T2Activity;
import com.packcheng.ndkdemo.t3.T3Activity;

/**
 * JNI/NDK练习工程
 *
 * @author packcheng
 * @date 2021/8/10 00:19
 */
public class MainActivity extends BaseActivity<ActivityMainBinding> {

    JniRoot root = new JniRoot();

    @Override
    protected int getContentResId() {
        return R.layout.activity_main;
    }

    @Override
    protected void initView() {
        super.initView();
        mBinding.btnT1.setOnClickListener(v -> T1Activity.startActivity(MainActivity.this));
        mBinding.btnT2.setOnClickListener(v -> T2Activity.startActivity(MainActivity.this));
        mBinding.btnT3.setOnClickListener(v -> T3Activity.startActivity(MainActivity.this));
    }
}