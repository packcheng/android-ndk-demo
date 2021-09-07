package com.packcheng.cmake;

import com.packcheng.base.BaseActivity;
import com.packcheng.cmake.databinding.ActivityMainBinding;

public class MainActivity extends BaseActivity<ActivityMainBinding> {
    private final MyNative operator = new MyNative();

    @Override
    protected int getContentResId() {
        return R.layout.activity_main;
    }

    @Override
    protected void initView() {
        super.initView();
        mBinding.btnTest.setOnClickListener(v -> {
            operator.testMethod();
        });
    }
}