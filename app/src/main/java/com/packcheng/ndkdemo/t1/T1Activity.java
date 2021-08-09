package com.packcheng.ndkdemo.t1;

import android.content.Context;
import android.content.Intent;

import com.packcheng.ndkdemo.BaseActivity;
import com.packcheng.ndkdemo.R;
import com.packcheng.ndkdemo.databinding.ActivityT1Binding;

/**
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
}