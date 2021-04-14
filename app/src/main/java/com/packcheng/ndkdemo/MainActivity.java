package com.packcheng.ndkdemo;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.packcheng.ndkdemo.databinding.ActivityMainBinding;
import com.packcheng.ndkdemo.jni.JniRoot;
import com.packcheng.ndkdemo.jni.StaticLink;
import com.packcheng.ndkdemo.util.LogUtil;

public class MainActivity extends AppCompatActivity {

    ActivityMainBinding mBinding;

    JniRoot root = new JniRoot();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = DataBindingUtil.setContentView(this, R.layout.activity_main);

        final StaticLink staticLink = new StaticLink();
        mBinding.btnStaticLink.setOnClickListener(v -> {
            String result = staticLink.helloFromCPP("packcheng");
            LogUtil.w("hello from cpp: " + result);
            staticLink.sayHelloToCPP("packcheng", 18, new String[]{"12345", "23456", "34567"});
        });
    }

}