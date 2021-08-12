package com.packcheng.ndkdemo;

import android.content.Context;
import android.content.Intent;

import com.packcheng.ndkdemo.databinding.ActivityTempBinding;

/**
 * 模板
 *
 * @author packcheng
 * @date 2021/8/10 00:23
 */
public class TemperActivity extends BaseActivity<ActivityTempBinding> {

    public static void startActivity(Context context) {
        context.startActivity(new Intent(context, TemperActivity.class));
    }

    @Override
    protected int getContentResId() {
        return R.layout.activity_temp;
    }

    @Override
    protected void initView() {
        super.initView();
        mBinding.btn.setOnClickListener(v -> {
        });
    }
}