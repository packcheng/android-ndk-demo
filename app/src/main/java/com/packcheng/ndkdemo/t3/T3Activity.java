package com.packcheng.ndkdemo.t3;

import android.content.Context;
import android.content.Intent;

import com.packcheng.base.BaseActivity;
import com.packcheng.ndkdemo.R;
import com.packcheng.ndkdemo.databinding.ActivityT2Binding;
import com.packcheng.base.LogUtil;
import com.packcheng.ndkdemo.databinding.ActivityT3Binding;

/**
 * 异常测试
 *
 * @author packcheng
 * @date 2021/8/10 00:23
 */
public class T3Activity extends BaseActivity<ActivityT3Binding> {

    private final T3 operator = new T3();

    public static void startActivity(Context context) {
        context.startActivity(new Intent(context, T3Activity.class));
    }

    @Override
    protected int getContentResId() {
        return R.layout.activity_t3;
    }


    @Override
    protected void initView() {
        super.initView();
        mBinding.btnTestJavaException.setOnClickListener(v -> operator.callJavaThrowException());
        mBinding.btnTestNativeException.setOnClickListener(v -> {
            try {
                operator.callNativeException();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
}