package com.packcheng.ndkdemo;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;
import androidx.databinding.ViewDataBinding;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/10 00:29
 */
public abstract class BaseActivity<V extends ViewDataBinding> extends AppCompatActivity {
    protected final String TAG = this.getClass().getSimpleName();

    protected V mBinding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = DataBindingUtil.setContentView(this, getContentResId());
        initView();
        initData();
    }

    protected void initView() {

    }

    protected void initData() {

    }

    protected abstract int getContentResId();
}
